#ifndef _CH375_H_
#define _CH375_H_


#include "stm32f10x.h"
#include "board.h"


#define CH375_GET_IC_VER	0x01
#define CH375_SET_BAUDRATE	0x02
#define CH375_ENTER_SLEEP	0x03
#define CH375_RESET_ALL		0x05
#define CH375_CHECK_EXIST	0x06
#define CH375_GET_MAX_LUN	0x0A
#define CH375_SET_DISK_LUN	0x0B
#define CH375_SET_USB_MODE	0x15
#define CH375_TEST_CONNECT	0x16
#define CH375_ABORT_NAK		0x17
#define CH375_GET_STATUS	0x22
#define CH375_RD_USB_DATA	0x28
#define CH375_WR_USB_DATA7	0x2B
#define CH375_DISK_INIT		0x51
#define CH375_DISK_SIZE		0x53
#define CH375_DISK_READ		0x54
#define CH375_DISK_RD_GO	0x55
#define CH375_DISK_WHITE	0x56
#define CH375_DISK_WR_GO	0x57
#define CH375_DISK_INQUIRY	0x58
#define CH375_DISK_READY	0x59
#define CH375_DISK_R_SENSE	0x5A

#define CH375_CMD_RET_SUCCESS	0x51
#define CH375_CMD_RET_ABORT		0x5F





















#endif
