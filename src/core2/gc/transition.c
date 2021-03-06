#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_9_s{
    u8 pad0[0x1];
    u8 unk1;
    u8 pad2[0x12];
}struct9s;

struct{
    s32 unk0;
    s32 unk4;
    u8 unk8;
    u8 pad9[3]; //not needed
    void *unkC;
    f32 rotation;
} D_80382430;

extern struct9s D_8036C308[];

struct9s *func_8030B400(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030B778.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BD4C.s")
void func_8030BD4C(void){
    struct9s *tmp_a1;
    tmp_a1 = func_8030B400(*(u8*)(func_8030B44C(func_803348C0()) + 1));
   func_8030B498(tmp_a1->unk1, tmp_a1);
}

f32 func_8030BD88(void){
    return 300.0f;
}

int func_8030BD98(void){
    return D_80382430.unk8 == 0;
}

int func_8030BDAC(void){
    return D_80382430.unk8 != 0;
}

int func_8030BDC0(void){
    return ( D_80382430.unk8 == 0x3)
    || (( D_80382430.unk8 == 1) && (D_80382430.unk0 < 2))
    || ( D_80382430.unk8 == 5)
    || ( D_80382430.unk8 == 8)
    || (( D_80382430.unk8 == 6) && (D_80382430.unk0 < 2));
}

void func_8030BE3C(void){
    func_8030B498(0, NULL);
}


void func_8030BE60(void){
    struct9s *tmp_a1;
    tmp_a1 = func_8030B400(*(u8*)(func_8030B44C(func_803348C0()) + 2));
   func_8030C180();
   func_8030B498(tmp_a1->unk1, tmp_a1);
}

void func_8030BEA4(s32 arg0){
    func_8030B498(D_8036C308[arg0].unk1, &D_8036C308[arg0]);
}

void func_8030BEDC(void){
    D_80382430.unk4 = 0;
    D_80382430.unk8 = 0;
    D_80382430.unkC = NULL;
    D_80382430.rotation = 0.0f;
    func_8030B498(0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/gc/transition/func_8030BF1C.s")
