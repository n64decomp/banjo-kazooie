#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osSiRawReadIo func_800021C0
#define __osSiDeviceBusy func_800030D0

s32 __osSiRawReadIo(u32 devAddr, u32 *data)
{
    if (__osSiDeviceBusy())
        return -1;
    *data = IO_READ(devAddr);
    return 0;
}
