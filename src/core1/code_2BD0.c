#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern OSIoMesg D_8027E090;
extern OSMesg D_8027E0A8;
extern OSMesgQueue D_8027E0AC;
extern OSMesg D_8027E0C8[16];
extern OSMesgQueue D_8027E108;


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_2BD0/func_802405F0.s")
#else
void func_802405F0(u32 arg0, u32 arg1, s32 size){
    int i;
    s32 block_cnt;
    s32 block_remainder;
    s32 block_size = 0x20000;

    osWritebackDCache(arg0, size);
    block_cnt = size/block_size;
    for(i = 0; i < block_cnt; i++){
        osPiStartDma(&D_8027E090, OS_MESG_PRI_NORMAL, OS_READ, arg1, arg0, block_size, &D_8027E0AC);
        osRecvMesg(&D_8027E0AC, NULL, 1);
        arg0 += 0x20000;
        arg1 += 0x20000;
    }

    block_remainder = size%0x20000;
    osPiStartDma(&D_8027E090,  OS_MESG_PRI_NORMAL, OS_READ, arg1, arg0, block_remainder, &D_8027E0AC);
    osRecvMesg(&D_8027E0AC, NULL, 1);
    osInvalDCache(arg0, size);

}
#endif

void func_80240754(void){
    osCreateMesgQueue(&D_8027E0AC, &D_8027E0A8, 1);
    osCreateMesgQueue(&D_8027E108, &D_8027E0C8[0], 16);
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_8027E108, &D_8027E0C8[0], 16);
}
