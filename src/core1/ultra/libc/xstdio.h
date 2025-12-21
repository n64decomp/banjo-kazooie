#ifndef _XSTDIO_H
#define _XSTDIO_H

#include "stdlib.h"
#include "stdarg.h"

#ifdef __sgi
typedef double ldouble; // IDO does not support long doubles
#else
typedef long double ldouble;
#endif

typedef struct {
    /* 0x0 */ union {
        /* 0x0 */ long long ll;
        /* 0x0 */ ldouble ld;
    } v;
    /* 0x8 */ unsigned char* s;
    /* 0xC */ int n0;
    /* 0x10 */ int nz0;
    /* 0x14 */ int n1;
    /* 0x18 */ int nz1;
    /* 0x1C */ int n2;
    /* 0x20 */ int nz2;
    /* 0x24 */ int prec;
    /* 0x28 */ int width;
    /* 0x2C */ size_t nchar;
    /* 0x30 */ unsigned int flags;
    /* 0x34 */ char qual;
} _Pft;

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16

int _Printf(void* pfn(void*,const char*,size_t), void *arg, const char *fmt, va_list ap);
void _Litob(_Pft *px, char code);
void _Ldtob(_Pft* px, char code);

#endif
