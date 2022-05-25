#include <ultra64.h>
#include "functions.h"
#include "variables.h"
;

extern f32 D_80379200;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034D9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DA7C.s")

void func_8034DBB8(Struct6Ds *arg0){
    if(arg0->unk48 == 0.0f){
        arg0->unk48 = D_80379200;
    }

    if(arg0->unkC != NULL){
        arg0->unkC(arg0);
    }
}

void func_8034DC08(Struct6Ds *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4){
    arg0->unk2C[0] = arg1[0];
    arg0->unk2C[1] = arg1[1];
    arg0->unk2C[2] = arg1[2];
    arg0->unk38[0] = arg2[0];
    arg0->unk38[1] = arg2[1];
    arg0->unk38[2] = arg2[2];
    arg0->unk29 = 1;
    arg0->unk4C = 0;
    arg0->unk48 = arg3;
    arg0->unk44 = 0.0f;
    arg0->unk4E = (s16) arg4;
    func_8034DBB8(arg0);
}

s32 func_8034DC78(Struct6Ds *arg0){
    return arg0->unk4C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DC80.s")

void func_8034DD48(Struct6Ds *arg0){
    if(arg0->unk0 != 0){
        func_8030DA44(arg0->unk0);
    }
}

void func_8034DD74(Struct6Ds *arg0, s32 arg1, BKModel *arg2, s32 mesh_id) {
    arg0->unk0 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk29 = 0;
    arg0->unk28 = 0;
    arg0->unk4C = 0;
    arg0->unk4E = 0;
    arg0->unk70 = 0.0f;
    arg0->unk74 = 0.0f;
    arg0->unk9C = 0.0f;
    arg0->unk98 = 0.0f;
    arg0->unk44 = 0.0f;
    arg0->unk48 = 0.0f;
    func_8033F2B4(arg2, mesh_id, arg0->unk14, arg0->unk1A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DE60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DEB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DEE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034DFB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E0FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E1A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C62B0/func_8034E26C.s")
