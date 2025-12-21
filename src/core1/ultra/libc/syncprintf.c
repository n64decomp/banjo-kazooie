#include "stdarg.h"
#include "PR/os.h"
#include "PR/os_internal.h"
#include "PR/rdb.h"
#include "xstdio.h"
#include "PR/rcp.h"

extern void* __printfunc;

#if BUILD_VERSION <= VERSION_J

#ifndef _FINALROM
extern u32 __kmc_pt_mode;

static void* proutSyncPrintf(void* str, const char* buf, size_t n) {
    u32 sent = 0;

    while (sent < n) {
        sent += __osRdbSend(buf + sent, n - sent, RDB_TYPE_GtoH_PRINT);
    }
    return 1;
}

static volatile unsigned int* stat = (unsigned*)0xbff08004;
static volatile unsigned int* wport = (unsigned*)0xbff08000;
static volatile unsigned int* piok = (unsigned*)PHYS_TO_K1(PI_STATUS_REG);

static void rmonPutchar(char c) {
    while (*piok & (PI_STATUS_DMA_BUSY | PI_STATUS_IO_BUSY)) {
    }

    while (!(*stat & 4)) {
    }
    
    *wport = c;
}

static void* kmc_proutSyncPrintf(void* str, const char* buf, int n) {
    int i;
    char c;
    char* p;
    char* q;
    char xbuf[128];
    static int column = 0;

    p = xbuf;

    for (i = 0; i < n; i++) {
        c = *buf++;

        switch (c) {
            case '\n':
                *p++ = '\n';
                column = 0;
                break;
            case '\t':
                do {
                    *p++ = ' ';
                } while (++column % 8);
                break;
            default:
                column++;
                *p++ = c;
                break;
        }

        if (c == '\n' || (p - xbuf) > 100) {
            rmonPutchar((p - xbuf) - 1);

            q = xbuf;
            while (q != p) {
                rmonPutchar(*q++);
            }
            p = xbuf;
        }
    }
    if (p != xbuf) {
        rmonPutchar((p - xbuf) - 1);

        q = xbuf;
        while (q != p) {
            rmonPutchar(*q++);
        }
    }
    return (void*)1;
}
#endif

void osSyncPrintf(const char* fmt, ...) {
    int ans;
    va_list ap;

#ifndef _FINALROM
    va_start(ap, fmt);
    if (__kmc_pt_mode) {
        ans = _Printf(kmc_proutSyncPrintf, NULL, fmt, ap);
    } else {
        ans = _Printf(proutSyncPrintf, NULL, fmt, ap);
    }
    va_end(ap);
#endif
}

void rmonPrintf(const char* fmt, ...) {
    int ans;
    va_list ap;

#ifndef _FINALROM
    va_start(ap, fmt);
    if (__kmc_pt_mode) {
        ans = _Printf(kmc_proutSyncPrintf, NULL, fmt, ap);
    }
    va_end(ap);
#endif
}

#else

void __osSyncVPrintf(const char* fmt, va_list ap) {

    int ans;
#ifndef _FINALROM
    if (__printfunc != NULL) {
        ans = _Printf(__printfunc, NULL, fmt, ap);
    }
#endif
}

void osSyncPrintf(const char* fmt, ...) {
    int ans;
    va_list ap;

#ifndef _FINALROM
    va_start(ap, fmt);
    __osSyncVPrintf(fmt, ap);
    va_end(ap);
#endif
}

void rmonPrintf(const char* fmt, ...) {
    int ans;
    va_list ap;

#ifndef _FINALROM
    va_start(ap, fmt);
    if (__printfunc != NULL) {
        ans = _Printf(__printfunc, NULL, fmt, ap);
    }
    va_end(ap);
#endif
}

#endif
