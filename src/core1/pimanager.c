#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"

#define PIMGR_MESGBUFFER_SIZE 16

OSIoMesg sPiMgrIOMesg;

struct {
    OSMesg mesg;
    OSMesgQueue queue;
} sPiMgrReadMesg;

OSMesg sPiMgrMesgBuffer[PIMGR_MESGBUFFER_SIZE];
OSMesgQueue sPiMgrMesgQueue;

void piMgr_read(void *vaddr, s32 devaddr, s32 size) {
    s32 block_cnt;
    s32 block_remainder;
    s32 block_size = VER_SELECT(0x20000, 0x8000, 0, 0);
    int i;

    osWritebackDCache(vaddr, size);
    block_cnt       = size / block_size;
    block_remainder = size % block_size;

    for(i = 0; i < block_cnt; i++){
        osPiStartDma(&sPiMgrIOMesg, OS_MESG_PRI_NORMAL, OS_READ, devaddr, vaddr, VER_SELECT(0x20000, 0x8000, 0, 0), &sPiMgrReadMesg.queue);
        osRecvMesg(&sPiMgrReadMesg.queue, NULL, 1);
        devaddr += VER_SELECT(0x20000, 0x8000, 0, 0);
        vaddr = (u32 *) vaddr + VER_SELECT(0x8000, 0x2000, 0, 0);
    }

    osPiStartDma(&sPiMgrIOMesg, OS_MESG_PRI_NORMAL, OS_READ, devaddr, vaddr, block_remainder, &sPiMgrReadMesg.queue);
    osRecvMesg(&sPiMgrReadMesg.queue, NULL, 1);
    osInvalDCache(vaddr, size);
}

void piMgr_init(void) {
    osCreateMesgQueue(&sPiMgrReadMesg.queue, &sPiMgrReadMesg.mesg, 1);
    osCreateMesgQueue(&sPiMgrMesgQueue, sPiMgrMesgBuffer, PIMGR_MESGBUFFER_SIZE);
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrMesgQueue, sPiMgrMesgBuffer, PIMGR_MESGBUFFER_SIZE);
}
