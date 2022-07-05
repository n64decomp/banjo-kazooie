#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern bool func_80323240(struct56s *, f32, f32[3]);
extern struct56s **D_80371E70;
extern void **D_80371E74;
extern s32 D_80371E78;
extern s32 D_80371E7C;

extern void *D_803858A0;


f32 func_80340700(f32, f32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340A4C.s")
// f32 func_80340A4C(f32 arg0, s32 arg1, f32 *arg2){
//     s32 tmp_v1;
//     s32 sp30;
//     f32 sp24[3];
//     f32 f20;

//     sp30 = arg1 - 3;
//     f20 = func_80340700( arg0, 0.0f, 1.0f)*sp30;
//     tmp_v1 = f20;
//     arg1 -= 4;
//     tmp_v1 = MIN(tmp_v1, arg1);
//     arg2 += tmp_v1;
//     f20 -= tmp_v1;
//     sp24[2] = -0.5*arg2[0] +  1.5*arg2[1] + -1.5*arg2[2] +  0.5*arg2[3];
//     sp24[1] =  1.0*arg2[0] + -2.5*arg2[1] +  2.0*arg2[2] + -0.5*arg2[3];
//     sp24[0] = -0.5*arg2[0] +  0.5*arg2[2];
//     return f20*(sp24[0] + f20*(sp24[1] + f20*sp24[2])) + (f64)arg2[1];
// }

void func_80340BE4(f32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 * arg4, f32 arg5[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340BE4.s")

void func_80341180(f32 arg0, s32 arg1, s32 arg2, f32 * arg3, f32 arg4[3]){
    func_80340BE4(arg0, arg1, arg2, arg2, arg3, arg4);
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803411B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341C78.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341D5C.s")
#else
s32 func_80341D5C(s32 arg0[3], s32 arg1[3]){
    int i, j;
    struct56s *a0;
    f32  *a2;
    f32 spC[3];
    f32 sp0[3];

    spC[0] = (f32)arg0[0];
    spC[1] = (f32)arg0[1];
    spC[2] = (f32)arg0[2];

    sp0[0] = (f32)arg1[0];
    sp0[1] = (f32)arg1[1];
    sp0[2] = (f32)arg1[2];

    for(i = 0; i < D_80371E78; i++){
        a2 = D_80371E70[i]->unk8;
        for(j = 0; j < D_80371E70[i]->unk0; j++){
            if( spC[0] == a2[j*3 + 0]
                && spC[1] == a2[j*3 + 1]
                && spC[2] == a2[j*3 + 2]
                && sp0[0] == a2[j*3 + 3]
                && sp0[1] == a2[j*3 + 4]
                && sp0[2] == a2[j*3 + 5]
            ){
                return i;
            }
        }
    }
    return -1;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341FB0.s")

struct56s *func_80342038(s32 indx){
    if(indx == -1)
        return NULL;
    return D_80371E70[indx];
}

int func_80342064(s32 arg0){
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80342070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803420BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803421A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80342244.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80342260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803422AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803422D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803430B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803431D0.s")

s32 func_80343654(Actor *this){
    s32 tmp_v1;
    s32 tmp_a0;
    tmp_v1 = this->unk10_8 ? 0x800 : 0x100;
    tmp_a0 = this->unk10_7 ? 0x1000 : 0x200;
    return tmp_a0 + tmp_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80343694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803438E0.s")

int func_80343D50(Actor *this, s32 arg1, s32 arg2, s32 arg3){
    s32 s0;
    s0 = 0;
    do{
        D_80371E7C = 0; 
        s0 += func_803438E0(this, arg1, arg2, arg3);
    }while(D_80371E7C);
    return s0 ? 1 : 0;
}

void func_80343DEC(Actor *this){
    func_80343D50(this, func_80343654(this), 0x19, 0x19);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80343E20.s")

struct56s *func_80343F00(s32 indx, f32 arg1[3]){
    struct56s *out;

    out = func_80342038(indx);
    out->unk8[0][0] = arg1[0];
    out->unk8[0][1] = arg1[1];
    out->unk8[0][2] = arg1[2];
    return out;
}

void func_80343F3C(void) {
    s32 i;

    if (D_80371E70 != 0) {
        D_80371E70 = (struct56s *)defrag(D_80371E70);
    }
    if (D_80371E74 != 0) {
        D_80371E74 = defrag(D_80371E74);
    }
    if (D_803858A0 != 0) {
        D_803858A0 = defrag(D_803858A0);
    }

    for(i = 0; i < D_80371E78; i++){
        D_80371E74[i] = defrag(D_80371E74[i]);
        D_80371E70[i] = defrag(D_80371E70[i]);
    }
}

bool func_80344040(Actor *this){
    return func_80323240(D_80371E70[this->unk44_14], this->unk48, this->position);
}
