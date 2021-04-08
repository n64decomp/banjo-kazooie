#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define __osSetGlobalIntMask func_80004F40
#define __osDisableInt func_80003FC0
#define __osRestoreInt func_80003FE0
#define __OSGlobalIntMask D_800050F0 

extern OSIntMask __OSGlobalIntMask;

void __osSetGlobalIntMask(OSHWIntr mask)
{
    register u32 saveMask = __osDisableInt();
    __OSGlobalIntMask |= mask;
    __osRestoreInt(saveMask);
}
