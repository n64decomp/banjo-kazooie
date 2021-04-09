#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "piint.h"

#define osEPiRawWriteIo func_80004EA0

s32 osEPiRawWriteIo(OSPiHandle *pihandle, u32 devAddr, u32 data)
{
    register u32 stat;
    register u32 domain;

    WAIT_ON_IOBUSY(stat);

    IO_WRITE(pihandle->baseAddress | devAddr, data);
    return 0;
}
