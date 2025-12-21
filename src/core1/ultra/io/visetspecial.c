#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PR/rcp.h"
#include "PRinternal/viint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

// This value was incorrectly calculated until being fixed in 2.0J
#if BUILD_VERSION >= VERSION_J
#define OS_VI_SPECIAL_MAX                                                                                 \
    (OS_VI_GAMMA_ON | OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_ON | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | \
     OS_VI_DIVOT_OFF | OS_VI_DITHER_FILTER_ON | OS_VI_DITHER_FILTER_OFF)
#else
#define OS_VI_SPECIAL_MAX OS_VI_DITHER_FILTER_OFF
#endif

/**
 * Configures VI "special features" to be applied on the next context swap.
 *
 * "Special features" refer to the mode bits in the Video Interface control register that enable effects such as gamma
 * correction, gamma dither, dither filtering, anti-aliasing filtering and divot filtering. Configuring the same
 * setting ON and OFF in the same call will result in OFF taking precedence.
 *
 * Any unrecognized bits will be ignored. Note that this is very intentional as in early revisions of retail N64
 * hardware setting bit 5 in the `features` field of OSViContext may cause physical damage to the console once it is
 * fed to VI_CONTROL_REG on next context swap.
 *
 * @param func OS_VI_*_ON / OS_VI_*_OFF bits to enable or disable a setting.
 */
void osViSetSpecialFeatures(u32 func) {
    register u32 saveMask;

#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(ERR_OSVISETSPECIAL_VIMGR, 0);
        return;
    }

    if ((func < OS_VI_GAMMA_ON) || (func > OS_VI_SPECIAL_MAX)) {
        __osError(ERR_OSVISETSPECIAL_VALUE, 1, func);
        return;
    }
#endif

    saveMask = __osDisableInt();

    if ((func & OS_VI_GAMMA_ON) != 0) {
        __osViNext->control |= VI_CTRL_GAMMA_ON;
    }

    if ((func & OS_VI_GAMMA_OFF) != 0) {
        __osViNext->control &= ~VI_CTRL_GAMMA_ON;
    }

    if ((func & OS_VI_GAMMA_DITHER_ON) != 0) {
        __osViNext->control |= VI_CTRL_GAMMA_DITHER_ON;
    }

    if ((func & OS_VI_GAMMA_DITHER_OFF) != 0) {
        __osViNext->control &= ~VI_CTRL_GAMMA_DITHER_ON;
    }

    if ((func & OS_VI_DIVOT_ON) != 0) {
        __osViNext->control |= VI_CTRL_DIVOT_ON;
    }

    if ((func & OS_VI_DIVOT_OFF) != 0) {
        __osViNext->control &= ~VI_CTRL_DIVOT_ON;
    }

    if ((func & OS_VI_DITHER_FILTER_ON) != 0) {
        __osViNext->control |= VI_CTRL_DITHER_FILTER_ON;
        __osViNext->control &= ~VI_CTRL_ANTIALIAS_MASK;
    }

    if ((func & OS_VI_DITHER_FILTER_OFF) != 0) {
        __osViNext->control &= ~VI_CTRL_DITHER_FILTER_ON;
        __osViNext->control |= __osViNext->modep->comRegs.ctrl & VI_CTRL_ANTIALIAS_MASK;
    }

    __osViNext->state |= VI_STATE_CTRL_UPDATED;

    __osRestoreInt(saveMask);
}
