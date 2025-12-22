#include "PR/os_internal.h"
#include "PRinternal/controller.h"
#include "PRinternal/siint.h"

#if BUILD_VERSION >= VERSION_J
void __osPfsRequestOneChannel(int channel, u8 cmd);
#else
void __osPfsRequestOneChannel(int channel);
#endif
void __osPfsGetOneChannelData(int channel, OSContStatus* data);

s32 __osPfsGetStatus(OSMesgQueue* queue, int channel) {
    s32 ret = 0;
    OSMesg dummy;
#ifdef BKDIFFS
    u8 pattern;
    OSContStatus data[4];
#else
    OSContStatus data;
#endif

#if BUILD_VERSION >= VERSION_J
    __osPfsInodeCacheBank = 250;

    __osPfsRequestOneChannel(channel, CONT_CMD_REQUEST_STATUS);
#else
#ifdef BKDIFFS
    __osPfsRequestData(CONT_CMD_REQUEST_STATUS);
#else
    __osPfsRequestOneChannel(channel);
#endif
#endif

    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

    ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

#ifdef BKDIFFS
    __osPfsGetInitData(&pattern, data);

    if (((data[channel].status & CONT_CARD_ON) != 0) && ((data[channel].status & CONT_CARD_PULL) != 0)) {
        return PFS_ERR_NEW_PACK;
    } else if ((data[channel].errno != 0) || ((data[channel].status & CONT_CARD_ON) == 0)) {
        return PFS_ERR_NOPACK;
    } else if ((data[channel].status & CONT_ADDR_CRC_ER) != 0) {
        return PFS_ERR_CONTRFAIL;
    }
#else
    __osPfsGetOneChannelData(channel, &data);

    if (((data.status & CONT_CARD_ON) != 0) && ((data.status & CONT_CARD_PULL) != 0)) {
        return PFS_ERR_NEW_PACK;
    } else if ((data.errno != 0) || ((data.status & CONT_CARD_ON) == 0)) {
        return PFS_ERR_NOPACK;
    } else if ((data.status & CONT_ADDR_CRC_ER) != 0) {
        return PFS_ERR_CONTRFAIL;
    }
#endif

    return ret;
}

#ifndef BKDIFFS
#if BUILD_VERSION >= VERSION_J
void __osPfsRequestOneChannel(int channel, u8 cmd) {
#else
void __osPfsRequestOneChannel(int channel) {
#endif
    u8* ptr;
    __OSContRequesFormatShort requestformat;
    int i;

#if BUILD_VERSION >= VERSION_J
    __osContLastCmd = CONT_CMD_END;
#else
    __osContLastCmd = CONT_CMD_REQUEST_STATUS;
#endif
    __osPfsPifRam.pifstatus = CONT_CMD_READ_BUTTON;

    ptr = (u8*)&__osPfsPifRam;

    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
#if BUILD_VERSION >= VERSION_J
    requestformat.cmd = cmd;
#else
    requestformat.cmd = CONT_CMD_REQUEST_STATUS;
#endif
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;

    for (i = 0; i < channel; i++) {
        *ptr++ = CONT_CMD_REQUEST_STATUS;
    }

    *(__OSContRequesFormatShort*)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormatShort);
    *ptr = CONT_CMD_END;
}

void __osPfsGetOneChannelData(int channel, OSContStatus* data) {
    u8* ptr = (u8*)&__osPfsPifRam;
    __OSContRequesFormatShort requestformat;
    int i;

    for (i = 0; i < channel; i++) {
        ptr++;
    }

    requestformat = *(__OSContRequesFormatShort*)ptr;
    data->errno = CHNL_ERR(requestformat);

    if (data->errno != 0) {
        return;
    }

    data->type = (requestformat.typel << 8) | (requestformat.typeh);
    data->status = requestformat.status;
}
#endif
