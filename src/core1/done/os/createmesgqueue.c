#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct __osThreadTail
{
    OSThread *next;
    OSPri priority;
} D_80277370;

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount)
{
    mq->mtqueue = (OSThread *)&D_80277370;
    mq->fullqueue = (OSThread *)&D_80277370;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}
