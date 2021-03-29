#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern OSThread *__osRunningThread;
extern OSThread *__osActiveQueue;
extern void __osDispatchThread(void);

void osDestroyThread(OSThread *t)
{
    register u32 saveMask;
    register OSThread *pred;
    register OSThread *succ;
    saveMask = __osDisableInt();
    if (t == NULL)
    {
        t = __osRunningThread;
    }
    else
    {
        if (t->state != OS_STATE_STOPPED)
        {
            __osDequeueThread(t->queue, t);
        }
    }
    if (__osActiveQueue == t)
    {
        __osActiveQueue = __osActiveQueue->tlnext;
    }
    else
    {
        pred = __osActiveQueue;
        while (succ = pred->tlnext)
        {
            if (succ == t)
            {
                pred->tlnext = t->tlnext;
                break;
            }
            pred = succ;
        }
    }
    if (t == __osRunningThread)
    {
        __osDispatchThread();
    }
    __osRestoreInt(saveMask);
}