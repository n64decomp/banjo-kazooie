#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "viint.h"

void *osViGetNextFramebuffer(void)
{
    register u32 saveMask;
    void *framep;
    saveMask = __osDisableInt();
    framep = __osViNext->framep;
    __osRestoreInt(saveMask);
    return framep;
}
