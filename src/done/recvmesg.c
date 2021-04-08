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
#define osRecvMesg func_80004D00

extern OSThread *__osRunningThread;

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flags)
{
    register u32 saveMask;
    saveMask = __osDisableInt();

    while (MQ_IS_EMPTY(mq))
    {
        if (flags == OS_MESG_NOBLOCK)
        {
            __osRestoreInt(saveMask);
            return -1;
        }
        __osRunningThread->state = OS_STATE_WAITING;
        __osEnqueueAndYield(&mq->mtqueue);
    }

    if (msg != NULL)
    {
        *msg = mq->msg[mq->first];
    }
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;
    if (mq->fullqueue->next != NULL)
    {
        osStartThread(__osPopThread(&mq->fullqueue));
    }
    __osRestoreInt(saveMask);
    return 0;
}
