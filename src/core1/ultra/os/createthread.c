#include "PR/os_internal.h"
#include "PR/R4300.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"

extern __OSThreadprofile_s thprof[];

void osCreateThread(OSThread* t, OSId id, void (*entry)(void*), void* arg, void* sp, OSPri p) {
    register u32 saveMask;
    OSIntMask mask;

#ifdef _DEBUG
    if ((u32)sp & 0x7) {
        __osError(ERR_OSCREATETHREAD_SP, 1, sp);
        return;
    }

    if ((p < OS_PRIORITY_IDLE) || (p > OS_PRIORITY_MAX)) {
        __osError(ERR_OSCREATETHREAD_PRI, 1, p);
        return;
    }
#endif

    t->id = id;
    t->priority = p;
    t->next = NULL;
    t->queue = NULL;
    t->context.pc = (u32)entry;
    t->context.a0 = (s64)(s32)arg; // Double cast gets rid of compiler warning
    t->context.sp = (s64)(s32)sp - 16;
    t->context.ra = (s64)(s32)__osCleanupThread;
    mask = OS_IM_ALL;
    t->context.sr = (mask & (SR_IMASK | SR_IE)) | SR_EXL;
    t->context.rcp = (mask & RCP_IMASK) >> RCP_IMASKSHIFT;
    t->context.fpcsr = FPCSR_FS | FPCSR_EV | FPCSR_RM_RN;
    t->fp = 0;
    t->state = OS_STATE_STOPPED;
    t->flags = 0;

#if BUILD_VERSION >= VERSION_K
#ifndef _FINALROM
    if (id < THPROF_IDMAX) {
        t->thprof = &thprof[id];
    } else {
        t->thprof = &thprof[THPROF_IDMAX - 1];
    }
#endif
#endif

    saveMask = __osDisableInt();
    t->tlnext = __osActiveQueue;
    __osActiveQueue = t;
    __osRestoreInt(saveMask);
}
