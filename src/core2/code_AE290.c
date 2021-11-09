#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
} D_803835F0;
extern ALBank * D_80383604;
extern u8 D_D846C0;
extern u8 D_D954B0;

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335220.s")
#else
void func_80335220(void){
    s32 size;
    s32 sp30;
    ALBank *bnk;
    ALBankFile * bnkf;
    
    
    size = (u32)&D_D954B0 - (u32)&D_D846C0;
    bnkf = (ALBankFile *)malloc(size);
    osWritebackDCache(bnkf, size);
    osPiStartDma(func_802405D0(), 0, 0, &D_D846C0, bnkf, size, func_802405C4());
    osRecvMesg(func_802405C4(), NULL, 1);
    alBnkfNew(bnkf, &D_D954B0);
    bnk = bnkf->bankArray[0];
    D_803835F0.unk0 = bnk->instArray[0]->soundCount;
    D_803835F0.unk4 = 0x100;
    D_803835F0.unk10 = 0x40;
    D_803835F0.unk8 = 0x18;
    D_803835F0.unkC = func_802405B8();
    func_80243070(&D_803835F0);
    D_80383604 = bnk;
}
#endif

int func_8033531C(enum sfx_e uid, struct46s *arg1){
    return func_80244608(D_80383604, (s16) (uid + 1), arg1);
}

int func_80335354(int uid, struct46s *arg1){
    return func_80244608(func_8024F758(), (s16) (uid + 1), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_803353BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_803353F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_8033543C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_803354B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_803354C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_803354EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335520.s")
