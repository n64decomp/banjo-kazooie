#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern OSDevMgr __osPiDevMgr;

OSMesgQueue *osPiGetCmdQueue(void){
    if (!__osPiDevMgr.active)
        return NULL;
    return __osPiDevMgr.cmdQueue;
        
}