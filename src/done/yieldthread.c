#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osYieldThread func_80004F90
#define __osDisableInt func_80003FC0
#define __osRestoreInt func_80003FE0
#define __osEnqueueAndYield func_8000288C
#define __osRunningThread D_80005130
#define __osRunQueue D_80005128

extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;

void osYieldThread(void){
    register u32 saveMask = __osDisableInt();
    __osRunningThread->state = OS_STATE_RUNNABLE;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(saveMask);
}
