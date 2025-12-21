#include "PR/os_internal.h"
#include "PRinternal/osint.h"

void osYieldThread(void) {
    register u32 saveMask = __osDisableInt();

    __osRunningThread->state = OS_STATE_RUNNABLE;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(saveMask);
}
