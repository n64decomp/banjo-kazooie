#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/osint.h"
#include "PRinternal/viint.h"

int osStopTimer(OSTimer* t) {
    register u32 savedMask;
    OSTimer* timep;

#ifdef _DEBUG
    if (!__osViDevMgr.active) {
        __osError(ERR_OSSTOPTIMER, 0);
        return 0;
    }
#endif

    if (t->next == NULL) {
        return -1;
    }

    savedMask = __osDisableInt();
    timep = t->next;

    if (timep != __osTimerList) {
        timep->value += t->value;
    }

    t->prev->next = t->next;
    t->next->prev = t->prev;
    t->next = NULL;
    t->prev = NULL;

    if (__osTimerList->next == __osTimerList) {
        __osSetCompare(0);
    }

    __osRestoreInt(savedMask);
    return 0;
}
