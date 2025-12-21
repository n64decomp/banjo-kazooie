#include "PR/os_internal.h"
#include "PR/ultraerror.h"
#include "PRinternal/piint.h"

s32 osPiStartDma(OSIoMesg* mb, s32 priority, s32 direction, u32 devAddr, void* dramAddr, u32 size, OSMesgQueue* mq) {
    register s32 ret;
    if (!__osPiDevMgr.active) {
#ifdef _DEBUG
        __osError(ERR_OSPISTARTDMA_PIMGR, 0);
#endif
        return -1;
    }

#ifdef _DEBUG
    if ((priority != OS_MESG_PRI_NORMAL) && (priority != OS_MESG_PRI_HIGH)) {
        __osError(ERR_OSPISTARTDMA_PRI, 1, priority);
        return -1;
    }

    if ((direction != OS_READ) && (direction != OS_WRITE)) {
        __osError(ERR_OSPISTARTDMA_DIR, 1, direction);
        return -1;
    }

    if (devAddr & 0x1) {
        __osError(ERR_OSPISTARTDMA_DEVADDR, 1, devAddr);
        return -1;
    }

    if ((u32)dramAddr & 0x7) {
        __osError(ERR_OSPISTARTDMA_ADDR, 1, dramAddr);
        return -1;
    }

    if (size & 0x1) {
        __osError(ERR_OSPISTARTDMA_SIZE, 1, size);
        return -1;
    }

    if ((size == 0) || (size > (16 * 1024 * 1024))) {
        __osError(ERR_OSPISTARTDMA_RANGE, 1, size);
        return -1;
    }
#endif

    if (direction == OS_READ) {
        mb->hdr.type = OS_MESG_TYPE_DMAREAD;
    } else {
        mb->hdr.type = OS_MESG_TYPE_DMAWRITE;
    }

    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = devAddr;
    mb->size = size;
    mb->piHandle = NULL;

    if (priority == OS_MESG_PRI_HIGH) {
        ret = osJamMesg(osPiGetCmdQueue(), (OSMesg)mb, OS_MESG_NOBLOCK);
    } else {
        ret = osSendMesg(osPiGetCmdQueue(), (OSMesg)mb, OS_MESG_NOBLOCK);
    }

    return ret;
}
