/*
 *  This file contains the RTC driver table for the DY-4 DMV177.
 *
 *  COPYRIGHT (c) 1989, 1990, 1991, 1992, 1993, 1994, 1997.
 *  On-Line Applications Research Corporation (OAR).
 *  All rights assigned to U.S. Government, 1994.
 *
 *  $Id$
 */

#include <bsp.h>

#include <libchip/rtc.h>
#include <libchip/m48t08.h>

/*
 * Configuration specific probe routines
 *
 * NOTE:  There are no DMV177 specific configuration routines.  These
 *        routines could be written to dynamically determine what type
 *        of real-time clock is on this board.  This would be useful for
 *        a BSP supporting multiple board models.
 */

/* NONE CURRENTLY PROVIDED */

/*
 * The following table configures the RTC drivers used in this BSP.
 *
 * The first entry which, when probed, is available, will be named /dev/rtc,
 * all others being given the name indicated.
 */

rtc_tbl	RTC_Table[] = {
	{
		"/dev/rtc0",			/* sDeviceName */
                RTC_M48T08,                     /* deviceType */
		MC68681_FUNCTIONS,		/* pDeviceFns */
		rtc_probe,			/* deviceProbe */
		NULL,				/* pDeviceParams */
		DMV170_RTC_ADDRESS,		/* ulCtrlPort1 */
		NULL,				/* ulCtrlPort2 */
		NULL,				/* ulDataPort */
		m48t08_get_register,         	/* getRegister */
		m48t08_set_register,		/* setRegister */
		NULL, /* unused */		/* setData */
	}
};

/*
 *  Declare some information used by the RTC driver
 */

#define NUM_RTCS (sizeof(RTC_Table)/sizeof(rtc_tbl))

unsigned long  RTC_Count = NUM_RTCS;

rtems_device_minor_number  RTC_Minor;
