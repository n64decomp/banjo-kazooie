#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "piint.h"

#define osEPiRawReadIo func_80004EF0

s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data)
{
    register u32 stat;
    register u32 domain;

    WAIT_ON_IOBUSY(stat);
    
    *data = IO_READ(pihandle->baseAddress | devAddr);
    return 0;
}
