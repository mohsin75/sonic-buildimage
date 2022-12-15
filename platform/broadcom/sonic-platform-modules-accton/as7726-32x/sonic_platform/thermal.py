#!/usr/bin/env python


try:
    from sonic_platform_pddf_base.pddf_thermal import PddfThermal
    from .helper import DeviceThreshold
except ImportError as e:
    raise ImportError(str(e) + "- required module not found")


NOT_AVAILABLE = DeviceThreshold.NOT_AVAILABLE
HIGH_THRESHOLD = DeviceThreshold.HIGH_THRESHOLD
LOW_THRESHOLD = DeviceThreshold.LOW_THRESHOLD
HIGH_CRIT_THRESHOLD = DeviceThreshold.HIGH_CRIT_THRESHOLD
LOW_CRIT_THRESHOLD = DeviceThreshold.LOW_CRIT_THRESHOLD

DEFAULT_THRESHOLD = {
    'Temp sensor 1' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'Temp sensor 2' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'Temp sensor 3' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'Temp sensor 4' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'Temp sensor 5' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'Temp sensor 6' : {
        HIGH_THRESHOLD : '82.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : '104.0',
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'PSU-1 temp sensor 1' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    },
    'PSU-2 temp sensor 1' : {
        HIGH_THRESHOLD : '80.0',
        LOW_THRESHOLD : NOT_AVAILABLE,
        HIGH_CRIT_THRESHOLD : NOT_AVAILABLE,
        LOW_CRIT_THRESHOLD : NOT_AVAILABLE
    }
}

class Thermal(PddfThermal):
    """PDDF Platform-Specific Thermal class"""

    def __init__(self, index, pddf_data=None, pddf_plugin_data=None, is_psu_thermal=False, psu_index=0):
        PddfThermal.__init__(self, index, pddf_data, pddf_plugin_data, is_psu_thermal, psu_index)

        # Threshold Configuration
        self.__conf = DeviceThreshold(self.get_name())
        # Default threshold.
        self.__default_threshold = DEFAULT_THRESHOLD[self.get_name()]

    # Provide the functions/variables below for which implementation is to be overwritten
    def get_name(self):
        if self.is_psu_thermal:
            return "PSU-{0} temp sensor 1".format(self.thermals_psu_index)
        else:
            return "Temp sensor {0}".format(self.thermal_index)

    def get_status(self):
        get_temp=self.get_temperature()

        if get_temp is not None:
            return True if get_temp else False

    def set_high_threshold(self, temperature):
        try:
            value = float(temperature)
        except Exception:
            return False

        # The new value can not be more than or equal to the default value.
        default_value = self.__default_threshold[HIGH_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            if value > float(default_value):
                return False

        try:
            self.__conf.set_high_threshold(str(value))
        except Exception:
            return False

        return True

    def get_high_threshold(self):
        value = self.__conf.get_high_threshold()
        if value != NOT_AVAILABLE:
            return float(value)

        default_value = self.__default_threshold[HIGH_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            return float(default_value)

        raise NotImplementedError

    def set_low_threshold(self, temperature):
        try:
            value = float(temperature)
        except Exception:
            return False

        # The new value can not be less than or equal to the default value.
        default_value = self.__default_threshold[LOW_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            if value < float(default_value):
                return False

        try:
            self.__conf.set_low_threshold(str(value))
        except Exception:
            return False

        return True

    def get_low_threshold(self):
        value = self.__conf.get_low_threshold()
        if value != NOT_AVAILABLE:
            return float(value)

        default_value = self.__default_threshold[LOW_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            return float(default_value)

        raise NotImplementedError

    def set_high_critical_threshold(self, temperature):
        try:
            value = float(temperature)
        except Exception:
            return False

        # The new value can not be more than or equal to the default value.
        default_value = self.__default_threshold[HIGH_CRIT_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            if value > float(default_value):
                return False

        try:
            self.__conf.set_high_critical_threshold(str(value))
        except Exception:
            return False

        return True

    def get_high_critical_threshold(self):
        value = self.__conf.get_high_critical_threshold()
        if value != NOT_AVAILABLE:
            return float(value)

        default_value = self.__default_threshold[HIGH_CRIT_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            return float(default_value)

        raise NotImplementedError

    def set_low_critical_threshold(self, temperature):
        try:
            value = float(temperature)
        except Exception:
            return False

        # The new value can not be less than or equal to the default value.
        default_value = self.__default_threshold[LOW_CRIT_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            if value < float(default_value):
                return False

        try:
            self.__conf.set_low_critical_threshold(str(value))
        except Exception:
            return False

        return True

    def get_low_critical_threshold(self):
        value = self.__conf.get_low_critical_threshold()
        if value != NOT_AVAILABLE:
            return float(value)

        default_value = self.__default_threshold[LOW_CRIT_THRESHOLD]
        if default_value != NOT_AVAILABLE:
            return float(default_value)

        raise NotImplementedError
