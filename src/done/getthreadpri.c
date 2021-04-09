#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osRunningThread D_80005130
#define osGetThreadPri func_80004380

extern OSThread *__osRunningThread;
OSId osGetThreadPri(OSThread *thread)
{
    if (thread == NULL)
        thread = __osRunningThread;
    return thread->priority;
}
