#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern OSIntMask __OSGlobalIntMask;

void __osSetGlobalIntMask(OSHWIntr mask)
{
    register u32 saveMask = __osDisableInt();
    __OSGlobalIntMask |= mask;
    __osRestoreInt(saveMask);
}
