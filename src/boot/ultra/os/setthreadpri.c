#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"

void osSetThreadPri(OSThread* t, OSPri pri) {
    register u32 saveMask;

#ifdef _DEBUG
    if ((pri < OS_PRIORITY_IDLE) || (pri > OS_PRIORITY_MAX)) {
        __osError(ERR_OSSETTHREADPRI, 1, pri);
        return;
    }
#endif

    saveMask = __osDisableInt();

    if (t == NULL) {
        t = __osRunningThread;
    }

    if (t->priority != pri) {
        t->priority = pri;

        if (t != __osRunningThread && t->state != OS_STATE_STOPPED) {
            __osDequeueThread(t->queue, t);
            __osEnqueueThread(t->queue, t);
        }

        if (__osRunningThread->priority < __osRunQueue->priority) {
            __osRunningThread->state = OS_STATE_RUNNABLE;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }

    __osRestoreInt(saveMask);
}
