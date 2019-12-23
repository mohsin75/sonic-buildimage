from sonic_platform_base.sonic_thermal_control.thermal_condition_base import ThermalPolicyConditionBase
from sonic_platform_base.sonic_thermal_control.thermal_json_object import thermal_json_object


@thermal_json_object('fan.any.absence')
class AnyFanAbsenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import FanInfo
        if FanInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[FanInfo.INFO_NAME], FanInfo):
            fan_info_obj = thermal_info_dict[FanInfo.INFO_NAME]
            return len(fan_info_obj.get_absence_fans()) > 0
        return False


@thermal_json_object('fan.all.absence')
class AllFanAbsenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import FanInfo
        if FanInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[FanInfo.INFO_NAME], FanInfo):
            fan_info_obj = thermal_info_dict[FanInfo.INFO_NAME]
            return len(fan_info_obj.get_presence_fans()) == 0
        return False


@thermal_json_object('fan.all.presence')
class AllFanPresenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import FanInfo
        if FanInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[FanInfo.INFO_NAME], FanInfo):
            fan_info_obj = thermal_info_dict[FanInfo.INFO_NAME]
            return len(fan_info_obj.get_absence_fans()) == 0
        return False


@thermal_json_object('psu.any.absence')
class AnyPsuAbsenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import PsuInfo
        if PsuInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[PsuInfo.INFO_NAME], PsuInfo):
            psu_info_obj = thermal_info_dict[PsuInfo.INFO_NAME]
            return len(psu_info_obj.get_absence_psus()) > 0
        return False


@thermal_json_object('psu.all.absence')
class AllPsuAbsenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import PsuInfo
        if PsuInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[PsuInfo.INFO_NAME], PsuInfo):
            psu_info_obj = thermal_info_dict[PsuInfo.INFO_NAME]
            return len(psu_info_obj.get_presence_psus()) == 0
        return False


@thermal_json_object('psu.all.presence')
class AllPsuPresenceCondition(ThermalPolicyConditionBase):
    def is_match(self, thermal_info_dict):
        from .thermal_infos import PsuInfo
        if PsuInfo.INFO_NAME in thermal_info_dict and isinstance(thermal_info_dict[PsuInfo.INFO_NAME], PsuInfo):
            psu_info_obj = thermal_info_dict[PsuInfo.INFO_NAME]
            return len(psu_info_obj.get_absence_psus()) == 0
        return False
