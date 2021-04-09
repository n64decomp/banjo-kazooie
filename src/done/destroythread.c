#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define osDestroyThread func_80003AD0
#define __osDisableInt func_80003FC0
#define __osRunningThread D_80005130
#define __osDequeueThread func_80003100
#define __osActiveQueue D_8000512C
#define __osDispatchThread func_800029E4
#define __osRestoreInt func_80003FE0

extern OSThread *__osRunningThread;
extern OSThread *__osActiveQueue;

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
        succ = pred->tlnext;
        while (succ)
        {
            if (succ == t)
            {
                pred->tlnext = t->tlnext;
                break;
            }
            pred = succ;
            succ = pred->tlnext;
        }
    }
    if (t == __osRunningThread)
    {
        __osDispatchThread();
    }
    __osRestoreInt(saveMask);
}
