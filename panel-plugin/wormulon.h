/******************************************************************************
 *
 * wormulon.h
 *
 * application specific defines. You should never need to tune anything here
 *
 *****************************************************************************/

#ifndef _WORMULON_H

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif


#define PATH_NET_DEV "/proc/net/dev"


/* define possible options */
#define OPT_NONE		0x0000
#define OPT_MRTG		0x0001
#define OPT_FULLMRTG	0x0002
#ifdef CUSTOM_MODE
#define OPT_CUSTOM		0x0004
#endif

#endif
