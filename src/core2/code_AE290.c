#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ALBank *func_8024F758(void);

extern struct {
    s32 unk0; //sound state cnt
    s32 unk4;
    s32 unk8; //maxSounds
    ALHeap *unkC; //heap
    s16 unk10;
} D_803835F0;
extern ALBank * D_80383604;
extern u8 D_D846C0;
extern u8 D_D954B0;

/* .code */
void func_80335220(void){
    ALBank *bnk;
    s32 size;
    ALInstrument *inst;
    ALBankFile * bnkf;
    
    
    size = &D_D954B0 - &D_D846C0;
    bnkf = (ALBankFile *)malloc(size);
    osWritebackDCache(bnkf, size);
    osPiStartDma(func_802405D0(), 0, 0, &D_D846C0, bnkf, size, func_802405C4());
    osRecvMesg(func_802405C4(), NULL, 1);
    alBnkfNew(bnkf, &D_D954B0);
    bnk = bnkf->bankArray[0];
    inst = bnk->instArray[0];
    D_803835F0.unk0 = inst->soundCount;
    D_803835F0.unk4 = 0x100;
    D_803835F0.unk10 = 0x40;
    D_803835F0.unk8 = 0x18;
    D_803835F0.unkC = func_802405B8();
    func_80243070(&D_803835F0);
    D_80383604 = bnk;
}

int func_8033531C(enum sfx_e uid, struct46s *arg1){
    return func_80244608(D_80383604, (s16) (uid + 1), arg1);
}

int func_80335354(int uid, struct46s *arg1){
    return func_80244608(func_8024F758(), (s16) (uid + 1), arg1);
}

void func_80335394(s32 arg0, f32 arg1){
    func_80244978(arg0, 0x10, reinterpret_cast(s32, arg1));
}

void func_803353BC(s32 arg0, u16 arg1){
    if(arg1 > 0x7fff)
        arg1 = 0x7fff;
    func_80244978(arg0, 0x8, arg1);
}

void func_803353F4(s32 arg0, s32 arg1){
    func_80244978(arg0, 0x100, arg1);
}

void func_80335418(s32 arg0, s32 arg1){
    func_80244978(arg0, 0x4, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_8033543C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE290/func_80335494.s")

s32 func_803354B4(void){
    return D_80383604->instArray[0]->soundCount;
}

s32 func_803354C8(void){
    return func_8024F758()->instArray[0]->soundCount;
}

bool func_803354EC(enum sfx_e sfx_id){
    return func_802445C4(D_80383604, (s16)(sfx_id + 1));
}

bool func_80335520(s32 arg0){
    return func_802445C4(func_8024F758(), (s16)(arg0 + 1));
}
