#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
}Struct_Core1_8C50_s;

extern u64 D_80272590[]; // ucode
extern u64 D_802731F0[];
extern u64 D_80274620[];

extern OSTask D_80275910;
extern OSTask D_80275950;
extern s32 D_80275994;
extern s32 D_80275998;
extern s32 D_802759A0;
extern u64 D_80278E80[]; //ucode_data
extern u64 D_80279130[];
extern u64 D_80279930[];
extern OSMesgQueue D_8027FB60;
extern OSMesgQueue D_8027FBC8;
extern Struct_Core1_8C50_s *D_8027FC08;
extern s32 D_8027FC0C;
extern s32 D_8027FC10;
extern s32 D_8027FC14;
extern s32 D_8027FC18;
extern s32 D_8027FC1C;

extern Struct_Core1_8C50_s * D_802805D8[];
extern s32 D_80280628;
extern s32 D_8028062C;
extern s32 D_80280630[0x14];

extern s32 D_80280680;
extern s32 D_80280684;
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

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_802466F4.s")
#else
void func_802466F4(s32 arg0){
    if(D_80280684 != (D_80280680 + 1) % 0x14){
        D_80280630[D_80280680] = arg0;
        D_80280680 = (D_80280680 + 1) % 0x14;
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246744.s")
#else
void func_80246744(s32 arg0){
    if(D_8028062C != (D_80280628 + 1) % 0x14){
        D_802805D8[D_80280628] = arg0;
        D_80280628 = (D_80280628 + 1) % 0x14;
    }
}
#endif

void func_80246794(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275910.t.ucode_boot, &D_80275910.t.ucode_boot_size);
    D_80275910.t.ucode = D_80272590;
    D_80275910.t.ucode_data = D_80278E80;
    D_80275910.t.data_ptr = (void*) arg0->unk8;
    D_80275910.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275910.t.data_ptr , D_80275910.t.data_size);
    osWritebackDCache(&D_80275910, sizeof(OSTask));
    D_8027FC08 = arg0;
    osSpTaskLoad(&D_80275910);
    osSpTaskStartGo(&D_80275910);
    D_8027FC1C = 4;
}

void func_80246844(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275950.t.ucode_boot, &D_80275950.t.ucode_boot_size);
    D_80275950.t.ucode = D_802731F0;
    D_80275950.t.ucode_data = D_80279130;
    D_80275950.t.data_ptr = (void*) arg0->unk8;
    D_80275950.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275950.t.data_ptr , D_80275950.t.data_size);
    osWritebackDCache(&D_80275950, sizeof(OSTask));
    osSpTaskLoad(&D_80275950);
    osSpTaskStartGo(&D_80275950);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

void func_8024692C(Struct_Core1_8C50_s * arg0){
    func_80255D0C(&D_80275950.t.ucode_boot, &D_80275950.t.ucode_boot_size);
    D_80275950.t.ucode = D_80274620;
    D_80275950.t.ucode_data = D_80279930;
    D_80275950.t.data_ptr = (void*) arg0->unk8;
    D_80275950.t.data_size = (arg0->unkC - arg0->unk8) >> 3 << 3;
    osWritebackDCache(D_80275950.t.data_ptr , D_80275950.t.data_size);
    osWritebackDCache(&D_80275950, sizeof(OSTask));
    osSpTaskLoad(&D_80275950);
    osSpTaskStartGo(&D_80275950);
    D_8027FC1C = arg0->unk4 | 0x8;
    D_8027FC18 = arg0->unk4 | 0x1;
    if(!(osDpGetStatus() & DPC_STATUS_FREEZE)){
        D_8027FC14 = D_8027FC18;
        D_80275998 = 0x1e;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80246B0C.s")
// void func_80246B0C(void){
//     Struct_Core1_8C50_s * ptr;
//     func_80246744();
//     if(D_8027FC1C == 0x10 && D_8027FC10 == 0x00){
//         func_8024692C(D_802805D8[D_8028062C]);
//         D_8028062C += 1; D_8028062C %= 0x14;
//     }
// }

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

void func_802476EC(Gfx **gfx){
    gDPPipeSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_8024772C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_8C50/func_80247738.s")
