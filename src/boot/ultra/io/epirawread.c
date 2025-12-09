#include <os_internal.h>
#include <rcp.h>
#include "piint.h"

s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data)
{
    register u32 stat;
    register u32 domain;

    WAIT_ON_IOBUSY(stat);
    
    *data = IO_READ(pihandle->baseAddress | devAddr);
    return 0;
}
