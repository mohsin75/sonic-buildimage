# coding:utf-8


monitor = {
    "openloop": {
        "linear": {
            "name": "linear",
            "flag": 0,
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "K": 11,
            "tin_min": 38,
        },
        "curve": {
            "name": "curve",
            "flag": 0,
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "a": 0.369,
            "b": -15.657,
            "c": 289,
            "tin_min": 25,
        },
    },

    "hyst": {
        "INLET_TEMP": {
            "name": "INLET_TEMP",
            "flag": 1,
            "type": "duty",
            "hyst_min": 50,        # duty
            "hyst_max": 100,       # duty
            "last_hyst_value": 50, # duty
            "temp_min": 18,
            "temp_max": 35,
            "value": [None, None],
            "rising": {
                18: 50,
                19: 50,
                20: 50,
                21: 53,
                22: 56,
                23: 59,
                24: 62,
                25: 65,
                26: 68,
                27: 71,
                28: 74,
                29: 77,
                30: 80,
                31: 84,
                32: 88,
                33: 92,
                34: 96,
                35: 100,
            },
            "descending": {
                18: 50,
                19: 53,
                20: 56,
                21: 59,
                22: 62,
                23: 65,
                24: 68,
                25: 71,
                26: 74,
                27: 77,
                28: 80,
                29: 84,
                30: 88,
                31: 92,
                32: 96,
                33: 100,
                34: 100,
                35: 100,
            },
        }
    },

    "pid": {
        "CPU_TEMP": {
            "name": "CPU_TEMP",
            "flag": 1,
            "type": "duty",
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "Kp": 3,
            "Ki": 0.5,
            "Kd": 0.5,
            "target": 89,
            "value": [None, None, None],
        },
        "SWITCH_TEMP": {
            "name": "SWITCH_TEMP",
            "flag": 1,
            "type": "duty",
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "Kp": 3,
            "Ki": 0.3,
            "Kd": 0.3,
            "target": 90,
            "value": [None, None, None],
        },
        "OUTLET_TEMP": {
            "name": "OUTLET_TEMP",
            "flag": 0,
            "type": "duty",
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "Kp": 2,
            "Ki": 0.4,
            "Kd": 0.3,
            "target": 65,
            "value": [None, None, None],
        },
        "SFF_TEMP": {
            "name": "SFF_TEMP",
            "flag": 1,
            "type": "duty",
            "pwm_min": 0x80,
            "pwm_max": 0xff,
            "Kp": 0.1,
            "Ki": 0.4,
            "Kd": 0,
            "target": 60,
            "value": [None, None, None],
        },
    },

    "temps_threshold": {
        "SWITCH_TEMP": {"name": "SWITCH_TEMP", "warning": 99, "critical": 105, "invalid": -100000, "error": -99999},
        "INLET_TEMP": {"name": "INLET_TEMP", "warning": 35, "critical": 38, "fix": -2},
        "OUTLET_TEMP": {"name": "OUTLET_TEMP", "warning": 999, "critical": 1000, "ignore_threshold": 1,},
        "CPU_TEMP": {"name": "CPU_TEMP", "warning": 96, "critical": 99},
        "SFF_TEMP": {"name": "SFF_TEMP", "warning": 999, "critical": 1000, "ignore_threshold": 1, "invalid": -10000, "error": -9999},
    },

    "fancontrol_para": {
        "interval": 5,
        "max_pwm": 0xff,
        "min_pwm": 0x80,
        "abnormal_pwm": 0xff,
        "warning_pwm": 0xff,
        "temp_invalid_pid_pwm": 0x80,
        "temp_error_pid_pwm": 0x80,
        "temp_fail_num": 3,
        "check_temp_fail": [
            {"temp_name": "INLET_TEMP"},
            {"temp_name": "SWITCH_TEMP"},
            {"temp_name": "CPU_TEMP"},
        ],
        "temp_warning_num": 3,  # temp over warning 3 times continuously
        "temp_critical_num": 3,  # temp over critical 3 times continuously
        "temp_warning_countdown": 60,  # 5 min warning speed after not warning
        "temp_critical_countdown": 60,  # 5 min full speed after not critical
        "rotor_error_count": 6,  # fan rotor error 6 times continuously
        "inlet_mac_diff": 999,
        "check_crit_reboot_flag": 1,
        "check_crit_reboot_num": 3,
        "check_crit_sleep_time": 20,
        "psu_fan_control": 1,
        "psu_absent_fullspeed_num": 0xFF,
        "fan_absent_fullspeed_num": 1,
        "rotor_error_fullspeed_num": 1,
    },

    "ledcontrol_para": {
        "interval": 5,
        "checkpsu": 0,  # 0: sys led don't follow psu led
        "checkfan": 0,  # 0: sys led don't follow fan led
        "psu_amber_num": 1,
        "fan_amber_num": 1,
        "board_sys_led": [
            {"led_name": "FRONT_SYS_LED"},
        ],
        "board_psu_led": [
            {"led_name": "FRONT_PSU_LED"},
        ],
        "board_fan_led": [
            {"led_name": "FRONT_FAN_LED"},
        ],
        "psu_air_flow_monitor": 0,
        "fan_air_flow_monitor": 0,
        "psu_air_flow_amber_num": 0,
        "fan_air_flow_amber_num": 0,
    },

    "otp_reboot_judge_file": {
        "otp_switch_reboot_judge_file": "/etc/.otp_switch_reboot_flag",
        "otp_other_reboot_judge_file": "/etc/.otp_other_reboot_flag",
    },
}
