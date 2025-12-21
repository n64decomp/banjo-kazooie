#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"

s32 osJamMesg(OSMesgQueue* mq, OSMesg msg, s32 flag) {
    register u32 saveMask;

#ifdef _DEBUG
    if ((flag != OS_MESG_NOBLOCK) && (flag != OS_MESG_BLOCK)) {
        __osError(ERR_OSJAMMESG, 1, flag);
        return -1;
    }
#endif

    saveMask = __osDisableInt();

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            __osRunningThread->state = OS_STATE_WAITING;
            __osEnqueueAndYield(&mq->fullqueue);
        } else {
            __osRestoreInt(saveMask);
            return -1;
        }
    }

    mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
    mq->msg[mq->first] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != NULL) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }

    __osRestoreInt(saveMask);
    return 0;
}
