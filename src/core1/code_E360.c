#include <ultra64.h>
#include "functions.h"
#include "variables.h"



void func_8024BF94(s32 arg0);
void func_8024C2F8(void *);

extern u32 D_80000300;
extern OSViMode D_80275C80;
extern OSViMode D_80275CD0;
extern u32 D_80280720;
extern u32 D_80280724;
extern u32 D_80280728;
extern struct1 D_80280730[2];
extern OSMesgQueue D_80280770;
extern OSMesgQueue D_802807B0;
extern OSMesgQueue D_802807D0;
extern s32 D_802808D8;
extern s32 D_802808DC;
extern OSThread D_802808E0;
extern s32 D_80280E90;
extern u8 D_803A5D00[2][0x1ECC0]; //framebuffer

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024BD80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024BD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024BDA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024BDAC.s")

void func_8024BE30(void){
    s32 i;
    volatile u32 *tmp;

    func_8024C428();
    osCreateViManager(0xfe);
    if(D_80000300 != 1)
        osViSetMode(&D_80275CD0); //PAL  
    else
        osViSetMode(&D_80275C80); //NTSC
        
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSwapBuffer(&D_803A5D00);
    osCreateMesgQueue(&D_80280770, (&D_80280770 + 1), 10);
    osCreateMesgQueue(&D_802807B0, (&D_802807B0 + 1), 1);
    osCreateMesgQueue(&D_802807D0, (&D_802807D0 + 1), 0x3C);
    osViSetEvent(&D_80280770,NULL,1);
    D_80280720 = 0;
    D_80280724 = 1;
    D_80280728 = 0;
    for(i = 0; i<2; i++){
        D_80280730[i].unk8 = 0;
        D_80280730[i].unk10 = 0;
        D_80280730[i].unk18 = 0;
        D_80280730[i].unk0 = 0;
    }
    tmp = &D_802808D8;
    *tmp = 0;
    func_8024BF94(2);
    osCreateThread(&D_802808E0,0,func_8024C2F8,NULL,&D_80280E90,0x50);
    osStartThread(&D_802808E0);
}

void func_8024BF94(s32 arg0){
    D_802808DC = arg0;
}

s32 func_8024BFA0(void){
    return D_802808DC;
}

void func_8024BFAC(void){
    osSendMesg(&D_802807B0, 0, OS_MESG_NOBLOCK);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024BFD8.s")
#else
void func_8024BFD8(s32 arg0){
    osSetThreadPri(NULL, 0x7f);
    func_802408EC(0x1E);
    func_80240874();
    if(arg0){
        osRecvMesg(&D_802807B0, NULL, OS_MESG_BLOCK);
    }

    while((s32)D_802808D8 < func_8024BFA0() - D_80280E90){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_BLOCK);
    }

    while(D_802807D0.validCount){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_NOBLOCK);
    }
    
    osViSwapBuffer(D_803A5D00[D_80280720 = func_8024BD80()]);
    D_80280E90 = 0;
    while(!(osDpGetStatus() & 2) && osViGetCurrFrameBuffer() != osViGetNextFrameBuffer()){
        osRecvMesg(&D_802807D0, NULL, OS_MESG_BLOCK);
        D_80280E90++;
    }//L8024C178
    D_80280724 = D_802808D8;
    D_802808D8 = 0;
    func_802408B0();
    osSetThreadPri(NULL, 0x14);
    func_802408EC(0xA);
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C1B4.s")

void func_8024C1DC(void){
    func_8024BFD8(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C1FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C2A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_E360/func_8024C4F8.s")
