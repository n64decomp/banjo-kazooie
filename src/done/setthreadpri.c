#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osSetThreadPri func_800043A0
#define __osDisableInt func_80003FC0
#define __osRunningThread D_80005130
#define __osDequeueThread func_80003100
#define __osEnqueueThread func_8000298C
#define __osEnqueueAndYield func_8000288C
#define __osRestoreInt func_80003FE0
#define __osRunQueue D_80005128

extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;

void osSetThreadPri(OSThread *t, OSPri pri)
{
    register u32 saveMask = __osDisableInt();
    if (t == NULL)
        t = __osRunningThread;
    if (t->priority != pri)
    {
        t->priority = pri;
        if (t != __osRunningThread && t->state != OS_STATE_STOPPED)
        {
            __osDequeueThread(t->queue, t);
            __osEnqueueThread(t->queue, t);
        }
        if (__osRunningThread->priority < __osRunQueue->priority)
        {
            __osRunningThread->state = OS_STATE_RUNNABLE;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }
    __osRestoreInt(saveMask);
}
