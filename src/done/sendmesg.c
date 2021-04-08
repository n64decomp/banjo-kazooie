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
#define osSendMesg func_80004BB0

extern OSThread *__osRunningThread;

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flags)
{
    register u32 saveMask;
    register s32 last;
    saveMask = __osDisableInt();
    while (MQ_IS_FULL(mq))
    {
        if (flags == OS_MESG_BLOCK)
        {
            __osRunningThread->state = OS_STATE_WAITING;
            __osEnqueueAndYield(&mq->fullqueue);
        }
        else
        {
            __osRestoreInt(saveMask);
            return -1;
        }
    }
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;
    if (mq->mtqueue->next != NULL)
    {
        osStartThread(__osPopThread(&mq->mtqueue));
    }
    __osRestoreInt(saveMask);
    return 0;
}
// #pragma GLOBAL_ASM("asm/nonmatchings/bk_boot_57B0/func_80004BB0.s")
