#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msg, s32 msgCount) {

#ifdef _DEBUG
    if (msgCount <= 0) {
        __osError(ERR_OSCREATEMESGQUEUE, 1, msgCount);
        return;
    }
#endif

    mq->mtqueue = (OSThread*)&__osThreadTail.next;
    mq->fullqueue = (OSThread*)&__osThreadTail.next;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}
