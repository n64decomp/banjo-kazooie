#include <os_internal.h>
#include <rcp.h>

s32 __osAiDeviceBusy(void)
{
    register s32 status = IO_READ(AI_STATUS_REG);
    if (status & AI_STATUS_FIFO_FULL)

        return 1;

    return 0;
}
