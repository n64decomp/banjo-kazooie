#include <os_internal.h>
#include "piint.h"

s32 osEPiRawWriteIo(OSPiHandle *pihandle, u32 devAddr, u32 data)
{
    register u32 stat;
    register u32 domain;

    WAIT_ON_IOBUSY(stat);

    IO_WRITE(pihandle->baseAddress | devAddr, data);
    return 0;
}
