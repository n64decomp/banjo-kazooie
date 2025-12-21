#include "PR/os_internal.h"
#include "PRinternal/piint.h"

// TODO: this comes from a header
#ident "$Revision: 1.17 $"

u32 osPiGetStatus(void) {
    return IO_READ(PI_STATUS_REG);
}
