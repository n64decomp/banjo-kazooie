#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osSiDeviceBusy func_800030D0
#define __osSiRawWriteIo func_80002210

s32 __osSiRawWriteIo(u32 devAddr, u32 data)
{
    if (__osSiDeviceBusy())
        return -1;
    IO_WRITE(devAddr, data);
    return 0;
}