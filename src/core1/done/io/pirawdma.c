#include <ultra64.h>

#ifndef WAIT_ON_IOBUSY
#define WAIT_ON_IOBUSY(stat)                                \
    stat = IO_READ(PI_STATUS_REG);                          \
    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) \
        stat = IO_READ(PI_STATUS_REG);
#endif

s32 osPiRawStartDma(s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    register u32 stat;
    WAIT_ON_IOBUSY(stat);
    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS((u32)osRomBase | devAddr));
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