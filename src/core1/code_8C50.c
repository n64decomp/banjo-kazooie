#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80275994;
extern s32 D_80275998;
extern s32 D_802759A0;
extern OSMesgQueue D_8027FB60;
extern OSMesgQueue D_8027FBC8;
extern s32 D_8027FC0C;
extern s32 D_8027FC10;
extern s32 D_8027FC14;
extern s32 D_8027FC18;
extern s32 D_8027FC1C;
extern s32 D_802805D8[];
extern s32 D_80280628;
extern s32 D_8028062C;

extern s32 D_80280688;


void func_80246670(OSMesg arg0){
    osSendMesg(&D_8027FB60, arg0, 1);
    if((s32) arg0 == 3 ){
        D_80275994 = 0x1e;
        if(D_802759A0){
            osDpSetStatus(DPC_CLR_FREEZE);
            D_802759A0 = 0;
        }
        osRecvMesg(&D_8027FBC8, NULL, 1);
        D_80275994 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802466F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_8024692C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246B94.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246C2C.s")
#else
void func_80246C2C(void){
    if((D_8027FC14 << 1) < 0){
        osDpSetStatus(DPC_SET_FREEZE);
        D_80280688 = osViGetCurrFrameBuffer();
        func_8024BFAC();
    }
    D_8027FC18 = 2;
    D_8027FC14 = 2;
    D_80275998 = 0;
    if(D_8027FC1C == 0x10 && D_80280628 != D_8028062C && !D_8027FC10){
        func_80246A14(D_802805D8[D_8028062C]);
        D_8028062C = (D_8028062C + 1)%0x14;
    }
    else{
        if(D_8027FC0C && D_80280628 == D_8028062C && !(osDpGetStatus() & DPC_STATUS_FREEZE)){
            osSendMesg(&D_8027FBC8, NULL, 0);
            D_8027FC0C--;
        }
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802471D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802471EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_8024730C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247380.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802473B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802476DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802476EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_8024772C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247738.s")
