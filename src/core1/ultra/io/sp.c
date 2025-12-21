#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/sptask.h"
#include "PRinternal/osint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

int __osSpDeviceBusy(void) {
    register u32 stat = IO_READ(SP_STATUS_REG);

    if (stat & (SP_STATUS_DMA_BUSY | SP_STATUS_DMA_FULL | SP_STATUS_IO_FULL)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
