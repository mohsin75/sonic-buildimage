/*
 * Copyright(c) Realtek Semiconductor Corporation, 2015
 * All rights reserved.
 *
 * Purpose : Related implementation of the RTL9302B board
 *
 * Feature : RTL9302C_2xRTL8284_2XGE demo board
 *
 */

static hwp_swDescp_t rtl9302c_2x8284_2xge_swDescp = {

    .chip_id                    = RTL9302C_CHIP_ID,
    .swcore_supported           = TRUE,
    .swcore_access_method       = HWP_SW_ACC_MEM,
    .swcore_spi_chip_select     = HWP_NOT_USED,
    .nic_supported              = TRUE,

    .port.descp = {
        { .mac_id = 16, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 0, .phy_idx = 0,        .smi = 0,        .phy_addr =  16,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 17, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 0, .phy_idx = 0,        .smi = 0,        .phy_addr =  17,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 18, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 0, .phy_idx = 0,        .smi = 0,        .phy_addr =  18,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 19, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 0, .phy_idx = 0,        .smi = 0,        .phy_addr =  19,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 20, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 1, .phy_idx = 1,        .smi = 0,        .phy_addr =  20,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 21, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 1, .phy_idx = 1,        .smi = 0,        .phy_addr =  21,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 22, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 1, .phy_idx = 1,        .smi = 0,        .phy_addr =  22,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 23, .attr = HWP_ETH,   .eth = HWP_2_5GE, .medi = HWP_COPPER, .sds_idx = 1, .phy_idx = 1,        .smi = 0,        .phy_addr =  23,        .led_c = 0,        .led_f = HWP_NONE,.led_layout = SINGLE_SET,},
        { .mac_id = 26, .attr = HWP_ETH,   .eth = HWP_XGE,   .medi = HWP_SERDES, .sds_idx = 2, .phy_idx = HWP_NONE, .smi = HWP_NONE, .phy_addr = HWP_NONE,  .led_c = 0,        .led_f = 0,       .led_layout = SINGLE_SET,},
        { .mac_id = 27, .attr = HWP_ETH,   .eth = HWP_XGE,   .medi = HWP_SERDES, .sds_idx = 3, .phy_idx = HWP_NONE, .smi = HWP_NONE, .phy_addr = HWP_NONE,  .led_c = 0,        .led_f = 0,       .led_layout = SINGLE_SET,},
        { .mac_id = 28, .attr = HWP_CPU,   .eth = HWP_NONE,  .medi = HWP_NONE,   .sds_idx = HWP_NONE, .phy_idx = HWP_NONE, .smi = HWP_NONE, .phy_addr =  HWP_NONE, .led_c = HWP_NONE, .led_f = HWP_NONE,.led_layout = HWP_NONE,  },
        { .mac_id = HWP_END },
    },  /* port.descp */

    .led.descp = {
        .led_active = LED_ACTIVE_LOW,
        .led_if_sel = LED_IF_SEL_SERIAL,
        .led_definition_set[0].led[0] = 0xA01,        /* 10Gbps link/act */
        .led_definition_set[0].led[1] = 0xA20,        /* 1000Mbps link/act */
        .led_definition_set[0].led[2] = 0xA02,        /* 5Gbps link/act */
        .led_definition_set[0].led[3] = 0xA08,        /* 2.5Gbps link/act */
        .led_definition_set[0].led[4] = HWP_LED_END,      /* None */
    },/* led.descp */

    .serdes.descp = {
        [0] = { .sds_id = 4, .mode = RTK_MII_USXGMII_10GQXGMII,  .rx_polarity = SERDES_POLARITY_NORMAL, .tx_polarity = SERDES_POLARITY_NORMAL },
        [1] = { .sds_id = 5, .mode = RTK_MII_USXGMII_10GQXGMII,  .rx_polarity = SERDES_POLARITY_NORMAL, .tx_polarity = SERDES_POLARITY_NORMAL },
        [2] = { .sds_id = 8, .mode = RTK_MII_10GR,     .rx_polarity = SERDES_POLARITY_NORMAL, .tx_polarity = SERDES_POLARITY_NORMAL },
        [3] = { .sds_id = 9, .mode = RTK_MII_10GR,     .rx_polarity = SERDES_POLARITY_NORMAL, .tx_polarity = SERDES_POLARITY_NORMAL },
        [4] = { .sds_id = HWP_END },
    }, /* serdes.descp */

    .phy.descp = {
        [0] = { .chip = RTK_PHYTYPE_NONE/* 412 */, .mac_id = 16, .phy_max = 4 },
        [1] = { .chip = RTK_PHYTYPE_NONE/* 412 */, .mac_id = 20, .phy_max = 4 },
        [4] = { .chip = HWP_END },
    },   /* .phy.descp */

};

/*
 * hardware profile
 */
static hwp_hwProfile_t rtl9302c_2x8284_2xge = {

    .identifier.name        = "RTL9302C_2xRTL8284_2XGE",
    .identifier.id          = HWP_RTL9302C_2xRTL8284_2XGE,

    .soc.swDescp_index      = 0,
    .soc.slaveInterruptPin  = HWP_NONE,

    .sw_count               = 1,
    .swDescp = {
        [0]                 = &rtl9302c_2x8284_2xge_swDescp,
    }

};
