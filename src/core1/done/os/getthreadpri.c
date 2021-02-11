#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern OSThread *D_80277380;

OSPri osGetThreadPri(OSThread *thread)
{
    if (thread == NULL)
        thread = D_80277380;
    return thread->priority;
}