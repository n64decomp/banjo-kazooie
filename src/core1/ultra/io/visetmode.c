#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "assert.h"
#include "PRinternal/viint.h"









































// TODO: this comes from a header
#ident "$Revision: 1.17 $"

void osViSetMode(OSViMode* modep) {
    register u32 saveMask;

#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(ERR_OSVISETMODE, 0);
        return;
    }

    assert(modep != NULL);
#endif

    saveMask = __osDisableInt();

    __osViNext->modep = modep;
    __osViNext->state = VI_STATE_MODE_UPDATED;
    __osViNext->control = __osViNext->modep->comRegs.ctrl;
    __osRestoreInt(saveMask);
}
