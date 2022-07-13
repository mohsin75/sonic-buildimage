#!/usr/bin/env python

import subprocess


try:
    from sonic_platform_base.component_base import ComponentBase
except ImportError as e:
    raise ImportError(str(e) + "- required module not found")

CPLD_ADDR_MAPPING = {
    "CPLD1": "0-0061",
    "CPLD2": "0-0062",
    "MB_FPGA": "0-0060",
    "FAN_CPLD" : "0-0066"
}

SYSFS_PATH = "/sys/bus/i2c/devices/"
GET_BMC_VER_CMD= "ipmitool mc info | grep 'Firmware Revision' | awk '{printf $4}'"
BIOS_VERSION_PATH = "/sys/class/dmi/id/bios_version"
COMPONENT_LIST= [
   ("BIOS", "Basic Input/Output System"),
   ("CPLD1", "CPLD 1"),
   ("CPLD2", "CPLD 2"),
   ("MB_FPGA", "MB FPGA"),
   ("FAN_CPLD", "FAN CPLD"),
   ("BMC", "baseboard management controller")
]

class Component(ComponentBase):
    """Platform-specific Component class"""

    DEVICE_TYPE = "component"

    def __init__(self, component_index=0):
        ComponentBase.__init__(self)
        self.index = component_index
        self.name = self.get_name()

    def __read_txt_file(self, file_path):
        try:
            with open(file_path, 'r') as fd:
                data = fd.read()
                return data.strip()
        except IOError:
            pass
        return ""

    def __get_bios_version(self):
        # Retrieves the BIOS firmware version
        try:
            with open(BIOS_VERSION_PATH, 'r') as fd:
                bios_version = fd.read()
                return bios_version.strip()
        except Exception as e:
            return None

    def __get_bmc_version(self):
        try:
            p = subprocess.Popen(GET_BMC_VER_CMD, shell=True, stdout=subprocess.PIPE)
            out, err = p.communicate()
            return out.decode().rstrip('\n')
        except Exception as e:
            print('Get exception when read bmc')
            return 'None'

    def __get_cpld_version(self):
        # Retrieves the CPLD firmware version
        cpld_version = dict()
        for cpld_name in CPLD_ADDR_MAPPING:
            try:
                cpld_path = "{}{}{}".format(SYSFS_PATH, CPLD_ADDR_MAPPING[cpld_name], '/version')
                cpld_version_raw= int(self.__read_txt_file(cpld_path), 10)
                cpld_version[cpld_name] = "{}".format(hex(cpld_version_raw))
            except Exception as e:
                print('Get exception when read cpld')
                cpld_version[cpld_name] = 'None'

        return cpld_version

    def get_name(self):
        """
        Retrieves the name of the component
         Returns:
            A string containing the name of the component
        """
        return COMPONENT_LIST[self.index][0]

    def get_description(self):
        """
        Retrieves the description of the component
            Returns:
            A string containing the description of the component
        """
        return COMPONENT_LIST[self.index][1]

    def get_firmware_version(self):
        """
        Retrieves the firmware version of module
        Returns:
            string: The firmware versions of the module
        """
        fw_version = None

        if self.name == "BIOS":
            fw_version = self.__get_bios_version()
        elif "BMC" in self.name:
            fw_version = self.__get_bmc_version()
        elif "CPLD" in self.name:
            cpld_version = self.__get_cpld_version()
            fw_version = cpld_version.get(self.name)
        elif "FPGA" in self.name:
            fpga_version = self.__get_cpld_version()
            fw_version = fpga_version.get(self.name)

        return fw_version

    def install_firmware(self, image_path):
        """
        Install firmware to module
        Args:
            image_path: A string, path to firmware image
        Returns:
            A boolean, True if install successfully, False if not
        """
        raise NotImplementedError
