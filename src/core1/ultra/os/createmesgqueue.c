#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct __osThreadTail
{
    OSThread *next;
    OSPri priority;
} __osThreadTail;

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount)
{
    mq->mtqueue = (OSThread *)&__osThreadTail;
    mq->fullqueue = (OSThread *)&__osThreadTail;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}
