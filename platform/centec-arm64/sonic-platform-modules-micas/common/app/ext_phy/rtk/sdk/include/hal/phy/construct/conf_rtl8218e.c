
#if defined(CONFIG_SDK_RTL8218E)
confcode_prv_t rtl8218e_c_xsgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x4B8},
    { 0, 0x17, 0x2E01},
    { 0, 0x10, 0x8714},
    { 0, 0x12, 0x7230},
    { 0, 0x13, 0x0230},
    { 0,   31,  0x4BE},
    { 0, 0x16, 0x1000},
    { 0,   31,  0x4BF},
    { 0, 0x11, 0x1000},
    { 0,   31,  0x4BA},
    { 0, 0x13, 0x3961},
    { 0,   31,  0x4BF},
    { 0, 0x16, 0x0042},
    { 0,   31,  0x4BA},
    { 0, 0x14, 0x9D04},
    { 0,   31,  0x4B9},
    { 0, 0x14, 0x7512},

    { 0,   31,  0x4BB},
    { 0, 0x10, 0xF0E2},
    { 0,   31,  0x4BC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x4BD},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x4F0},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x33F8},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},

    { 0,   31,  0x584},
    { 0, 0x10, 0x4902},
    { 0,   31,  0x5B8},
    { 0, 0x17, 0x0001},
    { 0,   31,  0x5B9},
    { 0, 0x11, 0x0201},
    { 0, 0x14, 0x0512},
    { 0,   31,  0x5BA},
    { 0, 0x10, 0x6CF0},
    { 0,   31,  0x580},
    { 0, 0x10, 0x00D1},
    { 0, 0x12, 0x0150},
    { 0, 0x13, 0x0814},
    { 0,   30,    0x0},
};

confcode_prv_t rtl8218e_c_qsgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x4A8},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0xF28C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x4A9},
    { 0, 0x14, 0xF512},
    { 0,   31,  0x4AC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x4AD},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x4EC},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x3008},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},

    { 0,   31,  0x5A8},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0xF28C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x5A9},
    { 0, 0x14, 0xF512},
    { 0,   31,  0x5AC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x5AD},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x5EC},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x585},
    { 0, 0x11, 0x3008},
    { 0,   31,  0x584},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x500},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1403},
    { 0,   30,    0x0},
};

confcode_prv_t rtl8218e_c_ousgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x490},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0x728C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x491},
    { 0, 0x14, 0xF512},

    { 0,   31,  0x494},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x495},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x4E4},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x33F8},
    { 0,   31,  0x493},
    { 0, 0x10, 0xF0E2},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},

    { 0,   31,  0x584},
    { 0, 0x10, 0x4902},
    { 0,   31,  0x590},
    { 0, 0x17, 0x0001},
    { 0,   31,  0x591},
    { 0, 0x11, 0x0201},
    { 0, 0x14, 0x0512},
    { 0,   31,  0x592},
    { 0, 0x10, 0x6CF0},
    { 0,   31,  0x580},
    { 0, 0x10, 0x00D1},
    { 0, 0x12, 0x0150},
    { 0, 0x13, 0x0814},
    { 0,   31,  0x500},
    { 0, 0x12, 0x71D0},
    { 0,   30,    0x0},
};

confcode_prv_t rtl8218e_xsgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x4B8},
    { 0, 0x17, 0x2E01},
    { 0, 0x10, 0x8714},
    { 0, 0x12, 0x7230},
    { 0, 0x13, 0x0230},
    { 0,   31,  0x4BE},
    { 0, 0x16, 0x1000},
    { 0, 0x11, 0x1001},
    { 0,   31,  0x4BF},
    { 0, 0x11, 0x7000},
    { 0,   31,  0x4BA},
    { 0, 0x13, 0x3961},
    { 0,   31,  0x4BF},
    { 0, 0x16, 0x0042},
    { 0,   31,  0x4BA},
    { 0, 0x14, 0x9D04},
    { 0,   31,  0x4B9},
    { 0, 0x14, 0x7512},
    { 0,   31,  0x4BB},
    { 0, 0x10, 0xF0E2},
    { 0,   31,  0x4BC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x4BD},
    { 0, 0x12, 0x0030},
    { 0, 0x13, 0x9E00},
    { 0, 0x14, 0x8000},
    { 0,   31,  0x4F0},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x33F8},
    { 0, 0x16, 0xF0FF},
    { 0,   31,  0x486},
    { 0, 0x10, 0x000E},
    { 0, 0x11, 0x0071},
    { 0, 0x13, 0x0E78},
    { 0, 0x14, 0x380E},
    { 0, 0x15, 0x3C0E},
    { 0, 0x16, 0x01CE},
    { 0,   31,  0x4B9},
    { 0, 0x15, 0x7F41},
    { 0,   31,  0x4BF},
    { 0, 0x15, 0x9838},
    { 0,   31,  0x4BE},
    { 0, 0x12, 0x1F00},
    { 0,   31,  0x4BD},
    { 0, 0x16, 0x0030},
    { 0,   31,  0x4F0},
    { 0, 0x16, 0x8030},
    { 0,   31,  0x4BA},
    { 0, 0x10, 0x6DF8},
    { 0,   31,  0x484},
    { 0, 0x10, 0x5902},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},

    { 0,   31,  0x584},
    { 0, 0x10, 0x4902},
    { 0,   31,  0x5B8},
    { 0, 0x17, 0x0001},
    { 0,   31,  0x5B9},
    { 0, 0x11, 0x0201},
    { 0, 0x14, 0x0512},
    { 0,   31,  0x5BA},
    { 0, 0x10, 0x6CF0},
    { 0,   31,  0x580},
    { 0, 0x10, 0x00D1},
    { 0, 0x12, 0x0150},
    { 0, 0x13, 0x0814},
    { 0,   30,    0x0},
};

confcode_prv_t rtl8218e_qsgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x4A8},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0xF28C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x4A9},
    { 0, 0x14, 0xF512},
    { 0,   31,  0x4AC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x4AD},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x4EC},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x3008},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},

    { 0,   31,  0x5A8},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0xF28C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x5A9},
    { 0, 0x14, 0xF512},
    { 0,   31,  0x5AC},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x5AD},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x5EC},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x585},
    { 0, 0x11, 0x3008},
    { 0,   31,  0x584},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},
    { 0,   31,  0x500},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1403},
    { 0,   30,    0x0},
};

confcode_prv_t rtl8218e_ousgmii_basic_perchip[] = {
    { 0,   30,    0x8},
    { 0,   31,  0x490},
    { 0, 0x17, 0x2E01},
    { 0, 0x12, 0x728C},
    { 0, 0x13, 0x028C},
    { 0,   31,  0x491},
    { 0, 0x14, 0xF512},
    { 0,   31,  0x494},
    { 0, 0x10, 0x5F3C},
    { 0, 0x12, 0x8006},
    { 0, 0x17, 0x00F0},
    { 0,   31,  0x495},
    { 0, 0x13, 0x8000},
    { 0,   31,  0x4E4},
    { 0, 0x10, 0x800C},
    { 0,   31,  0x485},
    { 0, 0x11, 0x33F8},
    { 0, 0x16, 0x00FF},
    { 0,   31,  0x493},
    { 0, 0x10, 0xF0E2},
    { 0,   31,  0x491},
    { 0, 0x15, 0xBF45},
    { 0,   31,  0x497},
    { 0, 0x15, 0x8038},
    { 0,   31,  0x496},
    { 0, 0x12, 0x3F00},
    { 0,   31,  0x495},
    { 0, 0x16, 0x0030},
    { 0,   31,  0x4E4},
    { 0, 0x16, 0x8030},
    { 0,   31,  0x400},
    { 0, 0x10, 0x1400},
    { 0, 0x10, 0x1703},
    { 0,   31,  0x484},
    { 0, 0x10, 0x7900},
    { 0, 0x10, 0x7902},

    { 0,   31,  0x584},
    { 0, 0x10, 0x4902},
    { 0,   31,  0x590},
    { 0, 0x17, 0x0001},
    { 0,   31,  0x591},
    { 0, 0x11, 0x0201},
    { 0, 0x14, 0x0512},
    { 0,   31,  0x592},
    { 0, 0x10, 0x6CF0},
    { 0,   31,  0x580},
    { 0, 0x10, 0x00D1},
    { 0, 0x12, 0x0150},
    { 0, 0x13, 0x0814},
    { 0,   30,    0x0},
};

#endif /* CONFIG_SDK_RTL8218E */
