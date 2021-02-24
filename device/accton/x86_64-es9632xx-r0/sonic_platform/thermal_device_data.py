DEVICE_DATA = {
    'x86_64-es9632xx-r0': {
        'thermal': {
            'threshold_table': {
                'thermal_U31_x48': ["64:69:10", "70:75:10",   "80:85:10"],
                'thermal_U61_x49': ["62:66:10", "67:71:10",   "76:81:10"],
                'thermal_U86_x4A': ["55:59:10", "60:64:10",   "78:84:10"],
                'asic_average':    ["70:90:10", "98:105:10",  "109:115:10"]
            }
        },
        'fans': {
            'drawer_num': 4,
            'drawer_type': 'real',
            'fan_num_per_drawer': 2,
            'support_fan_direction': False,
            'hot_swappable': True
        },
        'psus': {
            'psu_num': 2,
            'fan_num_per_psu': 1,
            'hot_swappable': True,
            'led_num': 1
        }
    },
    'x86_64-es9632xq-r0': {
        'thermal': {
            'threshold_table': {
                'thermal_U31_x48': ["64:69:10", "85:91:10",   "90:96:10"],
                'thermal_U61_x49': ["62:66:10", "80:87:10",   "86:92:10"],
                'thermal_U86_x4A': ["55:59:10", "70:77:10",   "76:82:10"],
                'asic_average':    ["70:90:10", "98:105:10",  "109:115:10"]
            }
        },
        'fans': {
            'drawer_num': 4,
            'drawer_type': 'real',
            'fan_num_per_drawer': 2,
            'support_fan_direction': False,
            'hot_swappable': True
        },
        'psus': {
            'psu_num': 2,
            'fan_num_per_psu': 1,
            'hot_swappable': True,
            'led_num': 1
        }
    }
}

