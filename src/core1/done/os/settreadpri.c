#include <ultra64.h>
#include "functions.h"
#include "variables.h"

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
