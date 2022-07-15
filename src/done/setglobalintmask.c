#include <os_internal.h>
#include <R4300.h>

void __osSetGlobalIntMask(OSHWIntr mask)
{
    register u32 saveMask = __osDisableInt();
    __OSGlobalIntMask |= mask;
    __osRestoreInt(saveMask);
}
