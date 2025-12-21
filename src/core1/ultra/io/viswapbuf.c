#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "assert.h"
#include "PRinternal/viint.h"













































// TODO: this comes from a header
#ident "$Revision: 1.17 $"

void osViSwapBuffer(void* frameBufPtr) {
    u32 saveMask;

#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(ERR_OSVISWAPBUFFER_VIMGR, 0);
        return;
    }

    assert(frameBufPtr != NULL);

    if ((u32)frameBufPtr & 0x3f) {
        __osError(ERR_OSVISWAPBUFFER_ADDR, 1, frameBufPtr);
        return;
    }
#endif

    saveMask = __osDisableInt();

    __osViNext->framep = frameBufPtr;
    __osViNext->state |= VI_STATE_BUFFER_UPDATED;
    __osRestoreInt(saveMask);
}
