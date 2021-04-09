#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osVirtualToPhysical func_80003050
#define __osProbeTLB func_80003BD0

u32 osVirtualToPhysical(void *addr)
{
    if (IS_KSEG0(addr))
    {
        return K0_TO_PHYS(addr);
    }
    else if (IS_KSEG1(addr))
    {
        return K1_TO_PHYS(addr);
    }
    else
    {
        return __osProbeTLB(addr);
    }
}
