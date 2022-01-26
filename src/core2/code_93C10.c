#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern struct{
    u8 pad0[3];
    s8 unk3;
    u8 pad4[3];
    s8 unk7;
    u8 pad8[4];
    struct1Cs *unkC;
}D_803830F0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031ABA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031ABF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031AC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031AD2C.s")

void func_8031B010(void){
    func_8031AD2C(6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B030.s")

void func_8031B070(s32 arg0){
    struct1Cs *v0 = D_803830F0.unkC;
    print_bold_overlapping(v0->x, D_803830F0.unk3, -1.2f, v0->string);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B0B0.s")

void func_8031B2F0(void){}

void func_8031B2F8(void){
    func_803204E4(0x20, FALSE);
    func_803204E4(0x1F, TRUE);
    if(func_80320454(0xC0, 0))
        func_8031AD2C(2);
    else
        func_8031AD2C(1);

}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_93C10/func_8031B354.s")

int func_8031B4CC(void){
    return (D_803830F0.unkC && D_803830F0.unkC->unk1 < 0);
}

int func_8031B4F4(void){
    return (D_803830F0.unkC) ? D_803830F0.unkC[1].unk0 : 0;
}

void func_8031B51C(void){
    if (func_803203FC(0x1F)) return;

    func_803204E4(0x20, TRUE);
    func_8031B354();
}

void func_8031B554(void){
    
    if (func_803203FC(0x1F)) return;

    func_803204E4(0x20, TRUE);
    func_803204E4(0xC0, TRUE);
    D_803830F0.unk7 = jiggyscore_total();
    func_8031B354();
}
