#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"

__OSEventState __osEventStateTab[OS_NUM_EVENTS] ALIGNED(0x8);
#if BUILD_VERSION >= VERSION_J
u32 __osPreNMI = FALSE;
#endif

void osSetEventMesg(OSEvent event, OSMesgQueue* mq, OSMesg msg) {
    register u32 saveMask;
    __OSEventState* es;

#ifdef _DEBUG
    if (event >= OS_NUM_EVENTS) {
        __osError(ERR_OSSETEVENTMESG, 1, event);
        return;
    }
#endif

    saveMask = __osDisableInt();

    es = &__osEventStateTab[event];

    es->messageQueue = mq;
    es->message = msg;

#if BUILD_VERSION >= VERSION_J
    if (event == OS_EVENT_PRENMI) {
        if (__osShutdown && !__osPreNMI) {
            osSendMesg(mq, msg, OS_MESG_NOBLOCK);
        }
        __osPreNMI = TRUE;
    }
#endif

    __osRestoreInt(saveMask);
}
