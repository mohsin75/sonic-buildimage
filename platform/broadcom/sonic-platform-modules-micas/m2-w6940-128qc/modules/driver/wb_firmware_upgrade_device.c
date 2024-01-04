/*
 * wb_firmware_upgrade.c
 *
 * ko for firmware device
 */
#include <linux/module.h>
#include <linux/io.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <firmware_upgrade.h>

#define GPIO_D1700_OFFSET  (275)

static int g_wb_firmware_upgrade_debug = 0;
static int g_wb_firmware_upgrade_error = 0;

module_param(g_wb_firmware_upgrade_debug, int, S_IRUGO | S_IWUSR);
module_param(g_wb_firmware_upgrade_error, int, S_IRUGO | S_IWUSR);

#define WB_FIRMWARE_UPGRADE_DEBUG_VERBOSE(fmt, args...) do {                                        \
    if (g_wb_firmware_upgrade_debug) { \
        printk(KERN_INFO "[WB_FIRMWARE_UPGRADE][VER][func:%s line:%d]\r\n"fmt, __func__, __LINE__, ## args); \
    } \
} while (0)

#define WB_FIRMWARE_UPGRADE_DEBUG_ERROR(fmt, args...) do {                                        \
    if (g_wb_firmware_upgrade_error) { \
        printk(KERN_ERR "[WB_FIRMWARE_UPGRADE][ERR][func:%s line:%d]\r\n"fmt, __func__, __LINE__, ## args); \
    } \
} while (0)

/* FPGA */
static firmware_upgrade_device_t firmware_upgrade_device_data0 = {
    .type               = "SPI_LOGIC",
    .chain              = 1,
    .chip_index         = 1,
    .upg_type.sysfs = {
        .dev_name     = "/dev/fpga0",
        .ctrl_base    = 0x400,
        .flash_base   = 0x200000,
        .test_base    = 0x7F0000,
        .test_size    = 0x10000,
    },
    .en_gpio_num        = 0,
    .en_logic_num       = 0,
};


/* bios */
static firmware_upgrade_device_t firmware_upgrade_device_data1 = {
    .type               = "MTD_DEV",
    .chain              = 2,
    .chip_index         = 1,
    .upg_type.sysfs = {
        .mtd_name     = "BIOS",
        .flash_base   = 0x3000000,
    },
    .en_gpio_num        = 0,
    .en_logic_num       = 0,
};

/* FPGA shaopian */
static firmware_upgrade_device_t firmware_upgrade_device_data2 = {
    .type               = "SPI_LOGIC",
    .chain              = 3,
    .chip_index         = 1,
    .upg_type.sysfs = {
        .dev_name     = "/dev/fpga0",
        .ctrl_base    = 0x400,
        .flash_base   = 0x0,
        .test_base    = 0x7F0000,
        .test_size    = 0x10000,
    },
    .en_gpio_num        = 0,
    .en_logic_num       = 0,
};


/* cpu cpld */
static firmware_upgrade_device_t firmware_upgrade_device_data3 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 1,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x0,
    .en_logic_en_val[0]  = 0xfe,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* BASE CPLD */
static firmware_upgrade_device_t firmware_upgrade_device_data4 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 2,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,
    .en_gpio[1]         = 48 + GPIO_D1700_OFFSET,
    .en_level[1]        = 1,

    .en_gpio_num        = 2,
    .en_logic_num       = 0,
};

/* LC CPLD */
static firmware_upgrade_device_t firmware_upgrade_device_data5 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 3,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xbb,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* MAC CPLDA */
static firmware_upgrade_device_t firmware_upgrade_device_data6 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 4,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xeb,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* MAC CPLDB */
static firmware_upgrade_device_t firmware_upgrade_device_data7 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 5,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xdb,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* FCB CPLD */
static firmware_upgrade_device_t firmware_upgrade_device_data8 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 6,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xfd,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* MISC CPLD */
static firmware_upgrade_device_t firmware_upgrade_device_data9 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 7,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xfb,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

/* PCIE CPLD */
static firmware_upgrade_device_t firmware_upgrade_device_data10 = {
    .type               = "JTAG",
    .upg_type.jtag = {
        .tdi            = 52 + GPIO_D1700_OFFSET,
        .tck            = 55 + GPIO_D1700_OFFSET,
        .tms            = 53 + GPIO_D1700_OFFSET,
        .tdo            = 54 + GPIO_D1700_OFFSET,
    },
    .chain              = 8,
    .chip_index         = 1,
    .en_gpio[0]         = 56 + GPIO_D1700_OFFSET,
    .en_level[0]        = 1,

    .en_logic_dev[0]     = "/dev/cpld1",
    .en_logic_addr[0]    = 0xf3,
    .en_logic_mask[0]    = 0x00,
    .en_logic_en_val[0]  = 0xcb,
    .en_logic_dis_val[0] = 0xff,
    .en_logic_width[0]   = 0x1,

    .en_gpio_num        = 1,
    .en_logic_num       = 1,
};

static void firmware_device_release(struct device *dev)
{
    return;
}

static struct platform_device firmware_upgrade_device[] = {
    {
        .name   = "firmware_sysfs",
        .id = 1,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data0,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_sysfs",
        .id = 2,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data1,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_sysfs",
        .id = 3,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data2,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 4,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data3,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 5,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data4,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 6,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data5,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 7,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data6,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 8,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data7,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 9,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data8,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 10,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data9,
            .release = firmware_device_release,
        },
    },
    {
        .name   = "firmware_cpld_ispvme",
        .id = 11,
        .dev    = {
            .platform_data  = &firmware_upgrade_device_data10,
            .release = firmware_device_release,
        },
    },
 };

 static int __init firmware_upgrade_device_init(void)
 {
     int i;
     int ret = 0;
     firmware_upgrade_device_t *firmware_upgrade_device_data;

     WB_FIRMWARE_UPGRADE_DEBUG_VERBOSE("enter!\n");
     for (i = 0; i < ARRAY_SIZE(firmware_upgrade_device); i++) {
         firmware_upgrade_device_data = firmware_upgrade_device[i].dev.platform_data;
         ret = platform_device_register(&firmware_upgrade_device[i]);
         if (ret < 0) {
             firmware_upgrade_device_data->device_flag = -1; /* device register failed, set flag -1 */
             printk(KERN_ERR "firmware_upgrade_device id%d register failed!\n", i + 1);
         } else {
             firmware_upgrade_device_data->device_flag = 0; /* device register suucess, set flag 0 */
         }
     }
     return 0;
 }

 static void __exit firmware_upgrade_device_exit(void)
 {
     int i;
     firmware_upgrade_device_t *firmware_upgrade_device_data;

     WB_FIRMWARE_UPGRADE_DEBUG_VERBOSE("enter!\n");
     for (i = ARRAY_SIZE(firmware_upgrade_device) - 1; i >= 0; i--) {
         firmware_upgrade_device_data = firmware_upgrade_device[i].dev.platform_data;
         if (firmware_upgrade_device_data->device_flag == 0) { /* device register success, need unregister */
             platform_device_unregister(&firmware_upgrade_device[i]);
         }
     }
 }

 module_init(firmware_upgrade_device_init);
 module_exit(firmware_upgrade_device_exit);
 MODULE_DESCRIPTION("FIRMWARE UPGRADE Devices");
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("support");
