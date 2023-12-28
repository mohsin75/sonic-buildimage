#############################################################################
# FS
#
# Module contains an implementation of SONiC Platform Base API and
# provides the fan status which are available in the platform
#
#############################################################################

try:
    from sonic_platform_base.fan_base import FanBase
    from .helper import APIHelper
    import os.path
except ImportError as e:
    raise ImportError(str(e) + "- required module not found")

FAN_MAX_RPM = 25500
PSU_FAN_MAX_RPM = 25500
CPLD_I2C_PATH = "/sys/bus/i2c/devices/11-0066/fan"
PSU_I2C_PATH = "/sys/bus/i2c/devices/{}-00{}/"
PSU_HWMON_I2C_MAPPING = {
    0: {
        "bus": 17,
        "addr": "59"
    },
    1: {
        "bus": 13,
        "addr": "5b"
    },
}

PSU_CPLD_I2C_MAPPING = {
    0: {
        "bus": 17,
        "addr": "51"
    },
    1: {
        "bus": 13,
        "addr": "53"
    },
}

FAN_NAME_LIST = ["FAN-1F", "FAN-1R", "FAN-2F", "FAN-2R",
                 "FAN-3F", "FAN-3R", "FAN-4F", "FAN-4R",
                 "FAN-5F", "FAN-5R", "FAN-6F", "FAN-6R"]

target_speed_file = "/tmp/fan_target_speed"

class Fan(FanBase):
    """Platform-specific Fan class"""

    def __init__(self,
                 fan_tray_index,
                 fan_index=0,
                 is_psu_fan=False,
                 psu_index=0):
        self._api_helper = APIHelper()
        self.fan_index = fan_index
        self.fan_tray_index = fan_tray_index
        self.is_psu_fan = is_psu_fan
        self.psu_index = psu_index

        if self.is_psu_fan:
            psu_i2c_bus = PSU_HWMON_I2C_MAPPING[psu_index]["bus"]
            psu_i2c_addr = PSU_HWMON_I2C_MAPPING[psu_index]["addr"]
            self.psu_hwmon_path = PSU_I2C_PATH.format(psu_i2c_bus,
                                                      psu_i2c_addr)
            psu_i2c_bus = PSU_CPLD_I2C_MAPPING[psu_index]["bus"]
            psu_i2c_addr = PSU_CPLD_I2C_MAPPING[psu_index]["addr"]
            self.cpld_path = PSU_I2C_PATH.format(psu_i2c_bus, psu_i2c_addr)

        FanBase.__init__(self)

    def get_direction(self):
        """
        Retrieves the direction of fan
        Returns:
            A string, either FAN_DIRECTION_INTAKE or FAN_DIRECTION_EXHAUST
            depending on fan direction
        """
        if not self.is_psu_fan:
            val = self._api_helper.read_txt_file(
                CPLD_I2C_PATH + str(self.fan_tray_index+1) + "_direction")
            if val is None:
                return self.FAN_DIRECTION_EXHAUST

            direction = self.FAN_DIRECTION_EXHAUST if (
                val == "0") else self.FAN_DIRECTION_INTAKE
        else:
            val = self._api_helper.read_txt_file(self.cpld_path + "psu_power_good")
            if val is None or int(val, 10)==0:
                return self.FAN_DIRECTION_NOT_APPLICABLE

            val = self._api_helper.read_txt_file(self.psu_hwmon_path + "psu_fan_dir")
            if val is None:
                return self.FAN_DIRECTION_NOT_APPLICABLE

            direction = self.FAN_DIRECTION_EXHAUST if (
                val == "F2B") else self.FAN_DIRECTION_INTAKE
        return direction

    def get_speed(self):
        """
        Retrieves the speed of fan as a percentage of full speed
        Returns:
            An integer, the percentage of full fan speed, in the range 0 (off)
                 to 100 (full speed)

        """
        speed = 0
        if self.is_psu_fan:
            speed = self._api_helper.read_txt_file(
                self.psu_hwmon_path + "psu_fan1_speed_rpm")
            if speed is None:
                return 0
            speed = (int(speed, 10)) * 100 / PSU_FAN_MAX_RPM
            speed = 100 if (speed > 100) else speed
        elif self.get_presence():
            speed = self._api_helper.read_txt_file(CPLD_I2C_PATH + str(
                self.fan_index * 10 + self.fan_tray_index + 1) + "_input")
            if speed is None:
                return 0
            speed = (int(speed, 10)) * 100 / FAN_MAX_RPM
            speed = 100 if (speed > 100) else speed
        return int(speed)

    def get_target_speed(self):
        """
        Retrieves the target (expected) speed of the fan
        Returns:
            An integer, the percentage of full fan speed, in the range 0 (off)
                 to 100 (full speed)

        Note:
            speed_pc = pwm_target/255*100

            0   : when PWM mode is use
            pwm : when pwm mode is not use
        """
        speed = 0
        if self.is_psu_fan:
            speed = self._api_helper.read_txt_file(
                self.psu_hwmon_path + "psu_fan1_speed_rpm")
            if speed is None:
                return 0
            speed = (int(speed, 10)) * 100 / PSU_FAN_MAX_RPM
            speed = 100 if (speed > 100) else speed
        elif self.get_presence():
            if os.path.isfile(target_speed_file):
                speed=self._api_helper.read_txt_file(target_speed_file)
            else:
                speed_path = "{}{}".format(CPLD_I2C_PATH, '_duty_cycle_percentage')
                speed=self._api_helper.read_txt_file(speed_path)
            if speed is None:
                return 0
        return int(speed)

    def get_speed_tolerance(self):
        """
        Retrieves the speed tolerance of the fan
        Returns:
            An integer, the percentage of variance from target speed which is
                 considered tolerable
        """
        if self.fan_index == 1:
            # for rear
            # For as7326-56x-1 the maximum rear fan speed is 76. (100-76=24)
            return 25
        else:
            # for front
            return 25

    def set_speed(self, speed):
        """
        Sets the fan speed
        Args:
            speed: An integer, the percentage of full fan speed to set fan to,
                   in the range 0 (off) to 100 (full speed)
        Returns:
            A boolean, True if speed is set successfully, False if not

        """

        if not self.is_psu_fan and self.get_presence():
            # current fan driver of linux kernel module only takes one speed setting and apply
            # the setting to all of the fans
            ret = self._api_helper.write_txt_file(
                CPLD_I2C_PATH + "_duty_cycle_percentage", int(speed))
            if ret == True:
                self._api_helper.write_txt_file(target_speed_file, int(speed))
            return ret

        return False

    def set_status_led(self, color):
        """
        Sets the state of the fan module status LED
        Args:
            color: A string representing the color with which to set the
                   fan module status LED
        Returns:
            bool: True if status LED state is set successfully, False if not
        """
        return False #Not supported

    def get_status_led(self):
        """
        Gets the state of the fan status LED
        Returns:
            A string, one of the predefined STATUS_LED_COLOR_* strings above
        """
        status=self.get_status()
        if status is None:
            return  self.STATUS_LED_COLOR_OFF

        return {
            True: self.STATUS_LED_COLOR_GREEN,
            False: self.STATUS_LED_COLOR_RED
        }.get(status, self.STATUS_LED_COLOR_OFF)

    def get_presence(self):
        """
        Retrieves the presence of the FAN
        Returns:
            bool: True if FAN is present, False if not
        """
        if self.is_psu_fan:
            val = self._api_helper.read_txt_file(self.cpld_path + "psu_present")
        else:
            val = self._api_helper.read_txt_file(
                CPLD_I2C_PATH + str(self.fan_tray_index + 1) + "_present")

        if val is not None:
            return int(val, 10)==1
        else:
            return False

    def get_status(self):
        """
        Retrieves the operational status of the device
        Returns:
            A boolean value, True if device is operating properly, False if not
        """
        if self.is_psu_fan:
            psu_path = "{}{}".format(self.cpld_path, 'psu_power_good')
            val = self._api_helper.read_txt_file(psu_path)
            if val is None or int(val, 10)==0:
                return False

            psu_path= "{}{}".format(self.psu_hwmon_path, 'psu_fan1_fault')
            val=self._api_helper.read_txt_file(psu_path)
            if val is not None:
                return int(val, 10)==0
            else:
                return False
        else:
            sys_index = self.fan_index * 10 + self.fan_tray_index+1
            path = "{}{}{}".format(CPLD_I2C_PATH, sys_index, '_fault')
            val=self._api_helper.read_txt_file(path)
            if val is not None:
                return int(val, 10)==0
            else:
                return False

    def get_name(self):
        """
        Retrieves the name of the device
            Returns:
            string: The name of the device
        """
        fan_name = FAN_NAME_LIST[self.fan_tray_index*2 + self.fan_index] \
            if not self.is_psu_fan \
            else "PSU-{} FAN-{}".format(self.psu_index+1, self.fan_index+1)

        return fan_name

    def get_model(self):
        """
        Retrieves the model number (or part number) of the device
        Returns:
            string: Model/part number of device
        """

        return "N/A"

    def get_serial(self):
        """
        Retrieves the serial number of the device
        Returns:
            string: Serial number of device
        """
        return "N/A"

    def get_position_in_parent(self):
        """
        Retrieves 1-based relative physical position in parent device.
        If the agent cannot determine the parent-relative position
        for some reason, or if the associated value of
        entPhysicalContainedIn is'0', then the value '-1' is returned
        Returns:
            integer: The 1-based relative physical position in parent device
            or -1 if cannot determine the position
        """
        return (self.fan_index+1) \
            if not self.is_psu_fan else (self.psu_index+1)

    def is_replaceable(self):
        """
        Indicate whether this device is replaceable.
        Returns:
            bool: True if it is replaceable.
        """
        return True if not self.is_psu_fan else False

