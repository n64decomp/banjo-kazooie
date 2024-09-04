#ifndef __BANJO_KAZOOIE_VERSION_H__
#define __BANJO_KAZOOIE_VERSION_H__

//These values of `VERSION` match the values defined via the Makefile
#define VERSION_USA_1_0 0
#define VERSION_PAL     1
#define VERSION_USA_1_1 2
#define VERSION_JP      3

#if VERSION == VERSION_USA_1_0
#define USA10_EXCLUSIVE(body) body
#else
#define USA10_EXCLUSIVE(body)
#endif

#if VERSION == VERSION_PAL
#define PAL_EXCLUSIVE(body) body
#else
#define PAL_EXCLUSIVE(body)
#endif

#if VERSION == VERSION_USA_1_1
#define USA11_EXCLUSIVE(body) body
#else
#define USA11_EXCLUSIVE(body)
#endif

#if VERSION == VERSION_JP
#define JP_EXCLUSIVE(body) body
#else
#define JP_EXCLUSIVE(body)
#endif

#if VERSION == VERSION_USA_1_0
#define VER_SELECT(usa0, pal, usa1, jp) usa0
#elif VERSION == VERSION_PAL
#define VER_SELECT(usa0, pal, usa1, jp) pal
#elif VERSION == VERSION_USA_1_1
#define VER_SELECT(usa0, pal, usa1, jp) usa1
#elif VERSION == VERSION_JP
#define VER_SELECT(usa0, pal, usa1, jp) jp
#endif

#if VERSION == VERSION_PAL
#define FRAMERATE 50
#else
#define FRAMERATE 60
#endif

#endif // __BANJO_KAZOOIE_VERSION_H__
