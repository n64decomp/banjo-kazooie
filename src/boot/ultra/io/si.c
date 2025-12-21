#include "PR/os_internal.h"
#include "PRinternal/siint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

int __osSiDeviceBusy(void) {
    register u32 stat = IO_READ(SI_STATUS_REG);

    if (stat & (SI_STATUS_DMA_BUSY | SI_STATUS_RD_BUSY)) {
        return TRUE;
    } else {
        return FALSE;
    }
}
