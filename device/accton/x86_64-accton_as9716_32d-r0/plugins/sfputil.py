# sfputil.py
#
# Platform-specific SFP transceiver interface for SONiC
#

try:
    import time
    import os
    import sys, getopt
    from ctypes import create_string_buffer
    from sonic_sfp.sfputilbase import SfpUtilBase
except ImportError as e:
    raise ImportError("%s - required module not found" % str(e))


class SfpUtil(SfpUtilBase):
    """Platform-specific SfpUtil class"""
    
    PORT_START = 0
    PORT_END = 33
    PORTS_IN_BLOCK = 34
    
    BASE_OOM_PATH = "/sys/bus/i2c/devices/{0}-0050/"
    BASE_CPLD1_PATH = "/sys/bus/i2c/devices/20-0061/"
    BASE_CPLD2_PATH = "/sys/bus/i2c/devices/21-0062/"
    
    _port_to_is_present = {}
    _port_to_lp_mode = {}

    _port_to_eeprom_mapping = {}
    _port_to_i2c_mapping = {
           0: [1, 25],
           1: [2, 26],
           2: [3, 27],
           3: [4, 28],
           4: [5, 29],
           5: [6, 30],
           6: [7, 31],
           7: [8, 32],
           8: [9, 33],
           9: [10, 34],
           10: [11, 35],
           11: [12, 36],
           12: [13, 37],
           13: [14, 38],
           14: [15, 39],
           15: [16, 40],
           16: [17, 41],
           17: [18, 42],
           18: [19, 43],
           19: [20, 44],
           20: [21, 45],
           21: [22, 46],
           22: [23, 47],
           23: [24, 48],
           24: [25, 49],
           25: [26, 50],
           26: [27, 51],
           27: [28, 52],
           28: [29, 53],
           29: [30, 54],
           30: [31, 55],
           31: [32, 56],              
           32: [33, 57], 
           33: [34, 58], 
           }

    @property
    def port_start(self):
        return self.PORT_START

    @property
    def port_end(self):
        return self.PORT_END
   
    @property
    def qsfp_ports(self):
        return range(self.PORT_START, self.PORTS_IN_BLOCK + 1)

    @property
    def port_to_eeprom_mapping(self):
        return self._port_to_eeprom_mapping

    def __init__(self):
        eeprom_path = self.BASE_OOM_PATH + "eeprom"
        
        for x in range(0, self.port_end+1):
            self.port_to_eeprom_mapping[x] = eeprom_path.format(
                self._port_to_i2c_mapping[x][1]
                )

        SfpUtilBase.__init__(self)

    def get_presence(self, port_num):
        # Check for invalid port_num
        if port_num < self.port_start or port_num > self.port_end:
            return False
        if port_num < 16 :
            present_path = self.BASE_CPLD1_PATH + "module_present_" + str(port_num+1)
        else:
            present_path = self.BASE_CPLD2_PATH + "module_present_" + str(port_num+1)
        self.__port_to_is_present = present_path

        content="0"
        try:
            val_file = open(self.__port_to_is_present)
            content = val_file.readline().rstrip()
            val_file.close()
        except IOError as e:
            print "Error: unable to access file: %s" % str(e)          
            return False

        if content == "1":
            return True

        return False

    def get_low_power_mode(self, port_num): 
        # Check for invalid port_num
        if port_num < self.port_start or port_num > self.port_end:
            return False

        try:
            eeprom = None

            if not self.get_presence(port_num):
                return False

            eeprom = open(self.port_to_eeprom_mapping[port_num], "rb")
            eeprom.seek(93)
            lpmode = ord(eeprom.read(1))

            if ((lpmode & 0x3) == 0x3):
                return True # Low Power Mode if "Power override" bit is 1 and "Power set" bit is 1
            else:
                return False # High Power Mode if one of the following conditions is matched:
                             # 1. "Power override" bit is 0
                             # 2. "Power override" bit is 1 and "Power set" bit is 0 
        except IOError as e:
            print "Error: unable to open file: %s" % str(e)
            return False
        finally:
            if eeprom is not None:
                eeprom.close()
                time.sleep(0.01)
        
    def set_low_power_mode(self, port_num, lpmode):
        # Check for invalid port_num
        if port_num < self.port_start or port_num > self.port_end:
            return False

        try:
            eeprom = None

            if not self.get_presence(port_num):
                return False # Port is not present, unable to set the eeprom

            # Fill in write buffer
            # 0x3:Low Power Mode. "Power override" bit is 1 and "Power set" bit is 1 
            # 0x9:High Power Mode. "Power override" bit is 1 ,"Power set" bit is 0 and "High Power Class Enable" bit is 1 
            regval = 0x3 if lpmode else 0x9 
            
            buffer = create_string_buffer(1)
            buffer[0] = chr(regval)

            # Write to eeprom
            eeprom = open(self.port_to_eeprom_mapping[port_num], "r+b")
            eeprom.seek(93)
            eeprom.write(buffer[0])
            return True
        except IOError as e:
            print "Error: unable to open file: %s" % str(e)
            return False
        finally:
            if eeprom is not None:
                eeprom.close()
                time.sleep(0.01)

    def reset(self, port_num):
        if port_num < self.port_start or port_num > self.port_end:
            return False
            
        if port_num < 16 :
            mod_rst_path = self.BASE_CPLD1_PATH + "module_reset_" + str(port_num+1)
        else:
            mod_rst_path = self.BASE_CPLD2_PATH + "module_reset_" + str(port_num+1)
        
        self.__port_to_mod_rst = mod_rst_path
        try:
            reg_file = open(self.__port_to_mod_rst, 'r+')
        except IOError as e:
            print "Error: unable to open file: %s" % str(e)          
            return False

        reg_value = '1'

        reg_file.write(reg_value)
        reg_file.close()
        
        return True
        
    def get_cpld_interrupt(self):
        port_dict={}
        for i in range(0,4):
            if i==0 or i==1:
                cpld_i2c_path = self.BASE_CPLD1_PATH + "cpld_intr_" + str(i+1)
            else:
                cpld_i2c_path = self.BASE_CPLD2_PATH + "cpld_intr_" +str(i+1)
            
            start_i=(i*8)
            end_i=(i*8+8)
            try:
                val_file = open(cpld_i2c_path)
            except IOError as e:
                print "Error: unable to open file: %s" % str(e)
               
                for k in range (start_i, end_i):
                    port_dict[k]=0         
                return port_dict

            status = val_file.readline().rstrip()
            val_file.close()
            status=status.strip()
            status= int(status, 16)
            
            interrupt_status = ~(status & 0xff)                
            if interrupt_status:
                port_shift=0
                for k in range (start_i, end_i):
                    if interrupt_status & (0x1<<port_shift):
                        port_dict[k]=1
                    else:
                        port_dict[k]=0
                    port_shift=port_shift+1

        return port_dict
        
    def get_transceiver_change_event(self, timeout=0):
        start_time = time.time()
        port_dict = {}
        ori_present ={}
        forever = False

        if timeout == 0:
            forever = True
        elif timeout > 0:
            timeout = timeout / float(1000) # Convert to secs
        else:
            print "get_transceiver_change_event:Invalid timeout value", timeout
            return False, {}

        end_time = start_time + timeout
        if start_time > end_time:
            print 'get_transceiver_change_event:' \
                       'time wrap / invalid timeout value', timeout

            return False, {} # Time wrap or possibly incorrect timeout
       
        #for i in range(self.port_start, self.port_end+1):
        #        ori_present[i]=self.get_presence(i)
                
        while timeout >= 0: 
            change_status=0
            
            port_dict = self.get_cpld_interrupt()
            present=0
            for key, value in port_dict.iteritems():
                if value==1:
                    present=self.get_presence(key)
                    change_status=1
                    if present:
                        port_dict[key]='1'
                    else:
                        port_dict[key]='0'
               
            if change_status:               
                return True, port_dict
            if forever:
                time.sleep(1)
            else:
                timeout = end_time - time.time()
                if timeout >= 1:
                    time.sleep(1) # We poll at 1 second granularity
                else:
                    if timeout > 0:
                        time.sleep(timeout)
                    return True, {}
        print "get_evt_change_event: Should not reach here."
        return False, {}