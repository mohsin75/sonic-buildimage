#############################################################################
# Edgecore
#
# Module contains an implementation of SONiC Platform Base API and
# provides the fan status which are available in the platform
#
#############################################################################


try:
    from sonic_platform_base.fan_base import FanBase
    from .helper import APIHelper
except ImportError as e:
    raise ImportError(str(e) + "- required module not found")

PSU_FAN_MAX_RPM = 25500

CPLD_I2C_PATH = "/sys/devices/platform/as7926_40xfb_fan/fan"
PSU_HWMON_I2C_PATH ="/sys/devices/platform/as7926_40xfb_psu/psu{}"

class Fan(FanBase):
    """Platform-specific Fan class"""

    def __init__(self, fan_tray_index, fan_index=0, is_psu_fan=False, psu_index=0):
        self._api_helper=APIHelper()
        self.fan_index = fan_index
        self.fan_tray_index = fan_tray_index
        self.is_psu_fan = is_psu_fan
        if self.is_psu_fan:
            self.psu_index = psu_index
            self.psu_hwmon_path = PSU_HWMON_I2C_PATH.format(self.psu_index+1)

        FanBase.__init__(self)


    def get_direction(self):
        """
        Retrieves the direction of fan
        Returns:
            A string, either FAN_DIRECTION_INTAKE or FAN_DIRECTION_EXHAUST
            depending on fan direction
        """


        if not self.is_psu_fan:
            dir_str = "{}{}{}".format(CPLD_I2C_PATH, self.fan_tray_index+1, '_dir')
            val = self._api_helper.read_txt_file(dir_str)
            if val is not None:
                if val == 'F2B': #F2B
                    direction = self.FAN_DIRECTION_EXHAUST
                else:
                    direction = self.FAN_DIRECTION_INTAKE
            else:
                direction = self.FAN_DIRECTION_EXHAUST

        else: #For PSU
            direction = self.FAN_DIRECTION_EXHAUST

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
            psu_fan_path = "{}{}".format(self.psu_hwmon_path, '_fan1_input')
            fan_speed_rpm = self._api_helper.read_txt_file(psu_fan_path)
            if fan_speed_rpm is not None:
                speed = (int(fan_speed_rpm, 10)) * 100 / PSU_FAN_MAX_RPM
                if speed > 100:
                    speed = 100
            else:
                return 0

        elif self.get_presence():
            speed_path = "{}{}{}".format(CPLD_I2C_PATH, self.fan_tray_index+1, '_pwm')
            speed = self._api_helper.read_txt_file(speed_path)
            if speed is None:
                return 0

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
        return False #Not supported

    def get_speed_tolerance(self):
        """
        Retrieves the speed tolerance of the fan
        Returns:
            An integer, the percentage of variance from target speed which is
                 considered tolerable
        """
        return False #Not supported

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
            speed_path = "{}{}{}".format(CPLD_I2C_PATH, self.fan_tray_index+1, '_pwm')
            return self._api_helper.write_txt_file(speed_path, int(speed))

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

    def get_presence(self):
        """
        Retrieves the presence of the FAN
        Returns:
            bool: True if FAN is present, False if not
        """
        present_path = "{}{}{}".format(CPLD_I2C_PATH, self.fan_tray_index+1, '_present')
        val=self._api_helper.read_txt_file(present_path)

        if not self.is_psu_fan:
            if val is not None:
                return int(val, 10)==1
            else:
                return False
        else:
            return True
