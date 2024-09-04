#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "version.h"


OSIoMesg D_8027E090;
struct {
    OSMesg mesg;
    OSMesgQueue queue;
} D_8027E0A8;
OSMesg D_8027E0C8[16]; //g_PimgrMesgBuffer
OSMesgQueue D_8027E108; //g_PimgrMesgQueue

void func_802405F0(u32 * arg0, s32 arg1, s32 size){
    s32 block_cnt;
    s32 block_remainder;
    s32 block_size = VER_SELECT(0x20000, 0x8000, 0, 0);
    int i;

    osWritebackDCache(arg0, size);
    block_cnt       = size / block_size;
    block_remainder = size % block_size;

    for(i = 0; i < block_cnt; i++){
        osPiStartDma(&D_8027E090, OS_MESG_PRI_NORMAL, OS_READ, arg1, arg0, VER_SELECT(0x20000, 0x8000, 0, 0), &D_8027E0A8.queue);
        osRecvMesg(&D_8027E0A8.queue, NULL, 1);
        arg1 += VER_SELECT(0x20000, 0x8000, 0, 0);
        arg0 += VER_SELECT(0x8000, 0x2000, 0, 0);
    }

    osPiStartDma(&D_8027E090,  OS_MESG_PRI_NORMAL, OS_READ, arg1, arg0, block_remainder, &D_8027E0A8.queue);
    osRecvMesg(&D_8027E0A8.queue, NULL, 1);
    osInvalDCache(arg0, size);

}

void piMgr_create(void){
    osCreateMesgQueue(&D_8027E0A8.queue, &D_8027E0A8.mesg, 1);
    osCreateMesgQueue(&D_8027E108, &D_8027E0C8[0], 16);
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_8027E108, &D_8027E0C8[0], 16);
}
