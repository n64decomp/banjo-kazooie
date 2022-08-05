#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#define LENGTH_SQ_VEC4F(v) (v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3])
/* public */


/* .data */
extern s32 D_80371ED0[3];

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_803454D0.s")

void func_80345630(f32 arg0[4]){
    arg0[0] = arg0[1] = arg0[2] = 0.0f;
    arg0[3] = 1.0f;
}

void func_80345650(f32[4], f32[4], f32[4], f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BE2C0/func_80345650.s")


void func_803458E4(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3) {
    f32 var_f0;
    f32 var_f2;
    f32 sp20[4];

    sp20[0] = arg1[0]-arg2[0];
    sp20[1] = arg1[1]-arg2[1];
    sp20[2] = arg1[2]-arg2[2];
    sp20[3] = arg1[3]-arg2[3];
    var_f0 = LENGTH_SQ_VEC4F(sp20);

    sp20[0] = arg1[0]+arg2[0];
    sp20[1] = arg1[1]+arg2[1];
    sp20[2] = arg1[2]+arg2[2];
    sp20[3] = arg1[3]+arg2[3];
    var_f2 = LENGTH_SQ_VEC4F(sp20);

    if (var_f0 <= var_f2) {
        func_80345650(arg0, arg1, arg2, arg3);
        return;
    }
    sp20[0] = -arg2[0];
    sp20[1] = -arg2[1];
    sp20[2] = -arg2[2];
    sp20[3] = -arg2[3];
    func_80345650(arg0, arg1, sp20, arg3);

}


void func_80345A44(f32 arg0[4], f32 arg1[4][4]) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_a0;
    s32 temp_a2;
    s32 var_a0;


    temp_f0 = arg1[0][0] + arg1[1][1] + arg1[2][2];
    if (temp_f0 > 0.0) {
        temp_f2 = gu_sqrtf(temp_f0 + 1.0);
        arg0[3] = temp_f2 * 0.5;
        temp_f2 = (0.5 / temp_f2);
        arg0[0] = (arg1[1][2] - arg1[2][1]) * temp_f2;
        arg0[1] = (arg1[2][0] - arg1[0][2]) * temp_f2;
        arg0[2] = (arg1[0][1] - arg1[1][0]) * temp_f2;
    }
    else{
        var_a0 = 0;
        if (arg1[var_a0][var_a0] < arg1[1][1]) {
            var_a0 = 1;
        }
        if (arg1[var_a0][var_a0] < arg1[2][2]) {
            var_a0 = 2;
        }
        temp_a0 = D_80371ED0[var_a0];
        temp_a2 = D_80371ED0[temp_a0];

        temp_f2 = gu_sqrtf((arg1[var_a0][var_a0] - (arg1[temp_a0][temp_a0] + arg1[temp_a2][temp_a2])) + 1.0);
        arg0[var_a0] = temp_f2 * 0.5;
        temp_f2 = (0.5 / temp_f2);
        arg0[3] = (arg1[temp_a0][temp_a2] - arg1[temp_a2][temp_a0]) * temp_f2;
        arg0[temp_a0] = (arg1[var_a0][temp_a0] + arg1[temp_a0][var_a0]) * temp_f2;
        arg0[temp_a2] = (arg1[var_a0][temp_a2] + arg1[temp_a2][var_a0]) * temp_f2;
    }
}


void func_80345C78(s32 arg0, f32 arg1[3]) {
    mlMtxIdent();
    mlMtxRotYaw(arg1[1]);
    mlMtxRotPitch(arg1[0]);
    mlMtxRotRoll(arg1[2]);
    func_80345A44(arg0, func_80251488());
}


void func_80345CD4(f32 arg0[4], f32 arg1[4]){
    mlMtxIdent();
    mlMtxRotRoll(arg1[2]);
    mlMtxRotYaw(arg1[1]);
    mlMtxRotPitch(arg1[0]);
    func_80345A44(arg0, func_80251488());
}

void func_80345D30(f32 arg0[4], f32 arg1[4], f32 arg2[4]) {
    f32 sp1C[3];
    f32 sp10[3];
    f32 sp4[3];

    arg0[3] = arg1[3]*arg2[3] - (arg1[0]*arg2[0] + arg1[1]*arg2[1] + arg1[2]*arg2[2]);

    sp10[0] = arg1[0] * arg2[3];
    sp10[1] = arg1[1] * arg2[3];
    sp10[2] = arg1[2] * arg2[3];

    sp4[0] = arg2[0] * arg1[3];
    sp4[1] = arg2[1] * arg1[3];
    sp4[2] = arg2[2] * arg1[3];

    sp1C[0] = (arg1[1] * arg2[2]) - (arg1[2]*arg2[1]);
    sp1C[1] = (arg1[2] * arg2[0]) - (arg1[0]*arg2[2]);
    sp1C[2] = (arg1[0] * arg2[1]) - (arg1[1]*arg2[0]);

    arg0[0] = sp10[0] + sp4[0];
    arg0[1] = sp10[1] + sp4[1];
    arg0[2] = sp10[2] + sp4[2];

    arg0[0] = arg0[0] + sp1C[0];
    arg0[1] = arg0[1] + sp1C[1];
    arg0[2] = arg0[2] + sp1C[2];
}
