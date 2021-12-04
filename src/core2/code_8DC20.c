#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern Gfx D_8036C630[];

extern s32 D_803830A0;

extern s16 D_803A5D00[2][0xF660];

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_8DC20/func_80314BB0.s")

void func_80315084(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80335128(0);
    D_803830A0 = 2;
    func_80314BB0(gfx, mtx, vtx, func_80253540(), D_803A5D00[func_8024BDA0()]);
}

void func_80315110(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(!D_803830A0){
        if(func_803348C0() != MAP_90_GL_BATTLEMENTS){
            func_803306C8(2);
            func_8032AD7C(2);
        }
    }
    else{
        D_803830A0--;
    }
    func_80314BB0(gfx, mtx, vtx, D_803A5D00[func_8024BDA0()], func_80253540());
}

void func_803151D0(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_80335128(1);
}
