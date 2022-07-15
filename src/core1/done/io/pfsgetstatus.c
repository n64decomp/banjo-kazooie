#include <os_internal.h>
#include "controller.h"
#include "siint.h"

OSPifRam __osPfsPifRam;
s32 __osPfsGetStatus(OSMesgQueue *queue, int channel)
{
    s32 ret;
    OSMesg dummy;
    u8 pattern;
    OSContStatus data[4];
    ret = 0;
    __osPfsRequestData(CONT_CMD_REQUEST_STATUS);
    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);
    __osPfsGetInitData(&pattern, data);
    if (((data[channel].status & CONT_CARD_ON) != 0) && ((data[channel].status & CONT_CARD_PULL) != 0))
        return PFS_ERR_NEW_PACK;
    if ((data[channel].errno != 0) || ((data[channel].status & CONT_CARD_ON) == 0))
        return PFS_ERR_NOPACK;
    if ((data[channel].status & CONT_ADDR_CRC_ER) != 0)
        return PFS_ERR_CONTRFAIL;
    return ret;
}
