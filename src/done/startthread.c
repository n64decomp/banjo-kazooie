#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osDisableInt func_80003FC0
#define __osRestoreInt func_80003FE0
#define __osEnqueueAndYield func_8000288C
#define __osRunningThread D_80005130
#define __osDisableInt func_80003FC0
#define __osRestoreInt func_80003FE0
#define osStartThread func_80004A60
#define __osPopThread func_800029D4
#define __osRunningThread D_80005130
#define __osRunQueue D_80005128
#define __osEnqueueThread func_8000298C
#define __osDispatchThread func_800029E4

extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;

void osStartThread(OSThread *t)
{
    register u32 saveMask = __osDisableInt();
    switch (t->state)
    {
    case OS_STATE_WAITING:
        t->state = OS_STATE_RUNNABLE;
        __osEnqueueThread(&__osRunQueue, t);
        break;
    case OS_STATE_STOPPED:
        if (t->queue == NULL || t->queue == &__osRunQueue)
        {
            t->state = OS_STATE_RUNNABLE;
            __osEnqueueThread(&__osRunQueue, t);
        }
        else
        {
            t->state = OS_STATE_WAITING;
            __osEnqueueThread(t->queue, t);
            __osEnqueueThread(&__osRunQueue, __osPopThread(t->queue));
        }
        break;
    }
    if (__osRunningThread == NULL)
    {
        __osDispatchThread();
    }
    else
    {
        if (__osRunningThread->priority < __osRunQueue->priority)
        {
            __osRunningThread->state = OS_STATE_RUNNABLE;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }
    __osRestoreInt(saveMask);
}
