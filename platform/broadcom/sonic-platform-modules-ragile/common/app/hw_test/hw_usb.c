/**
 * Copyright(C) 2010 Ruijie Network. All rights reserved.
 */
/*
 * hw_usb.c
 * Original Author : liangeb@ruijie.com.cn, 2012-07-26
 *
 * USB HardWare test
 *
 * History
 *    v1.0    enbo liang(liangeb@ruijie.com.cn)  2012-07-26  Initial version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/stat.h>


int usb_write_main(int argc, char **argv)
{
    char tmp[128];

    snprintf(tmp, sizeof(tmp), "%s", argv[0]);
    printf("%s, %d, %d, %s\r\n", __FUNCTION__, __LINE__, argc, tmp);
    return 0;
}


int usb_read_main(int argc, char **argv)
{
    char tmp[128];

    snprintf(tmp, sizeof(tmp), "%s", argv[0]);
    printf("%s, %d, %d, %s\r\n", __FUNCTION__, __LINE__, argc, tmp);
    return 0;
}


int usb_check_main(int argc, char **argv)
{
    char tmp[128];

    snprintf(tmp, sizeof(tmp), "%s", argv[0]);
    printf("%s, %d, %d, %s\r\n", __FUNCTION__, __LINE__, argc, tmp);
    return 0;
}
