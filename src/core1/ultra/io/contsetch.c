#include <os_internal.h>
#include "controller.h"
#include "siint.h"

s32 osContSetCh(u8 ch)
{
    s32 ret;
    ret = 0;
    __osSiGetAccess();
    if (ch > MAXCONTROLLERS)
    {
        __osMaxControllers = 4;
    }
    else
    {
        __osMaxControllers = ch;
    }
    __osContLastCmd = CONT_CMD_END; //TODO: is this right?
    __osSiRelAccess();
    return ret;
}
