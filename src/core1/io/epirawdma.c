#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern OSPiHandle *__osCurrentHandle[2];

#define OS_RAMROM_STACKSIZE 1024

#ifndef WAIT_ON_IOBUSY
#define WAIT_ON_IOBUSY(stat)                                \
    stat = IO_READ(PI_STATUS_REG);                          \
    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) \
        stat = IO_READ(PI_STATUS_REG);
#endif

#define UPDATE_REG(reg, var)           \
    if (cHandle->var != pihandle->var) \
        IO_WRITE(reg, pihandle->var);

#define EPI_SYNC(pihandle, stat, domain)                  \
                                                          \
    WAIT_ON_IOBUSY(stat)                                  \
                                                          \
    domain = pihandle->domain;                            \
    if (__osCurrentHandle[domain] != pihandle)            \
    {                                                     \
        OSPiHandle *cHandle = __osCurrentHandle[domain];  \
        if (domain == PI_DOMAIN1)                         \
        {                                                 \
            UPDATE_REG(PI_BSD_DOM1_LAT_REG, latency);     \
            UPDATE_REG(PI_BSD_DOM1_PGS_REG, pageSize);    \
            UPDATE_REG(PI_BSD_DOM1_RLS_REG, relDuration); \
            UPDATE_REG(PI_BSD_DOM1_PWD_REG, pulse);       \
        }                                                 \
        else                                              \
        {                                                 \
            UPDATE_REG(PI_BSD_DOM2_LAT_REG, latency);     \
            UPDATE_REG(PI_BSD_DOM2_PGS_REG, pageSize);    \
            UPDATE_REG(PI_BSD_DOM2_RLS_REG, relDuration); \
            UPDATE_REG(PI_BSD_DOM2_PWD_REG, pulse);       \
        }                                                 \
        __osCurrentHandle[domain] = pihandle;             \
    }

s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    u32 stat;
    u32 domain;

    EPI_SYNC(pihandle, stat, domain);
    
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS(pihandle->baseAddress | devAddr));
    switch (direction)
    {
    case OS_READ:
        IO_WRITE(PI_WR_LEN_REG, size - 1);
        break;
    case OS_WRITE:
        IO_WRITE(PI_RD_LEN_REG, size - 1);
        break;
    default:
        return -1;
    }
    return 0;
}
