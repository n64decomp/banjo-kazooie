#include "PR/os_internal.h"
#include "PRinternal/piint.h"

OSMesgQueue* osPiGetCmdQueue(void) {
    if (!__osPiDevMgr.active) {
        return NULL;
    } else {
        return __osPiDevMgr.cmdQueue;
    }
}
