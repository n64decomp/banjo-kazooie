#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include "ml/mtx.h"

#define LENGTH_SQ_VEC4F(v) (v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3])

/* .data */
s32 D_80371ED0[3] = {1, 2, 0};

/* .code */
//vec4f_copy
void vec4f_clone(f32 dst[4], f32 src[4]){
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

void func_80345274(f32 arg0[4], f32 arg1[3][3]) {
    f32 var_f18;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp_f12;
    f32 temp_f2;
    f32 temp_f20;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 temp_f0_2;
    f32 temp_f12_2;

    if ((arg0[0] == 0.0f) && (arg0[1] == 0.0f) && (arg0[2] == 0.0f) && (arg0[3] == 0.0f)) {
        var_f18 = 2.0f;
    } else {
        var_f18 = 2.0 / LENGTH_SQ_VEC4F(arg0);
    }
    temp_f12 = arg0[0] * var_f18;
    temp_f2  = arg0[1] * var_f18;
    temp_f20 = arg0[2] * var_f18;

    sp40 = temp_f12 * arg0[3];
    sp3C = temp_f2  * arg0[3];
    sp38 = temp_f20 * arg0[3];
    sp28 = temp_f12 * arg0[0];
    sp24 = temp_f2  * arg0[0];
    sp20 = temp_f20 * arg0[0];
    sp1C = temp_f2  * arg0[1];

    temp_f12_2 = temp_f20 * arg0[1];
    temp_f0_2 = temp_f20 * arg0[2];

    arg1[0][0] = 1.0 - (sp1C + temp_f0_2);
    arg1[0][1] = sp24 + sp38;
    arg1[0][2] = sp20 - sp3C;

    arg1[1][0] = sp24 - sp38;
    arg1[1][1] = 1.0 - (sp28 + temp_f0_2);
    arg1[1][2] = temp_f12_2 + sp40;
    
    arg1[2][0] = sp20 + sp3C;
    arg1[2][1] = temp_f12_2 - sp40;
    arg1[2][2] = 1.0 - (sp28 + sp1C);
}

bool vec4f_isZero(f32 arg0[4]){
    return ((arg0[0] == 0.0f) 
        && (arg0[1] == 0.0f)
        && (arg0[2] == 0.0f)
        && (arg0[3] == 1.0f));
}

bool vec4f_isAlmostZero(f32 arg0[4]) {
    return (((0.0f <= arg0[0]) ? arg0[0] : - arg0[0]) < 0.01)
        && (((0.0f <= arg0[1]) ? arg0[1] : - arg0[1]) < 0.01)
        && (((0.0f <= arg0[1]) ? arg0[1] : - arg0[1]) < 0.01)
        && (((0.0f <= arg0[3]) ? arg0[3] : - arg0[3]) < 1.01)
        && (((0.0f <= arg0[3]) ? arg0[3] : - arg0[3]) > 0.99);
}

void vec4f_zero(f32 arg0[4]){
    arg0[0] = arg0[1] = arg0[2] = 0.0f;
    arg0[3] = 1.0f;
}

void func_80345650(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3) {
    f32 temp_f12;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;

    temp_f12 =  (arg1[0]*arg2[0]) + (arg1[1]*arg2[1]) + (arg1[2]*arg2[2]) + (arg1[3]*arg2[3]);
    if (0.00001 < (1.0 + temp_f12)) {
        if (0.00001 < (1.0 - temp_f12)) {
            sp3C = (BAD_PI/180.0) * ml_acosf_deg(temp_f12);
            sp40 = sinf(sp3C);
            if (0.0f != sp40) {
                sp48 = sinf((1.0 - arg3) * sp3C) / sp40;
                sp48 = sp48;
                sp44 = sinf(arg3 * sp3C) / sp40;
            } else {
                sp44 = arg3;
                sp48 = 1.0 - arg3;
            }
        } else {
            sp44 = arg3;
            sp48 = 1.0 - arg3;
        }
        arg0[0] = sp48*arg1[0] + sp44*arg2[0];
        arg0[1] = sp48*arg1[1] + sp44*arg2[1];
        arg0[2] = sp48*arg1[2] + sp44*arg2[2];
        arg0[3] = sp48*arg1[3] + sp44*arg2[3];
    }
    else{

        arg0[0] = -arg1[1];
        arg0[1] = arg1[0];
        arg0[2] = -arg1[3];
        arg0[3] = arg1[2];

        sp48 = sinf((1.0 - arg3) * (BAD_PI/2.0f));
        sp44 = sinf(arg3 * (BAD_PI/2.0f));
        arg0[0] = sp48*arg1[0] + sp44*arg0[0];
        arg0[1] = sp48*arg1[1] + sp44*arg0[1];
        arg0[2] = sp48*arg1[2] + sp44*arg0[2];

    }
}

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

void func_80345A44(f32 arg0[4], MtxF* arg1) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_a0;
    s32 temp_a2;
    s32 var_a0;


    temp_f0 = arg1->m[0][0] + arg1->m[1][1] + arg1->m[2][2];
    if (temp_f0 > 0.0) {
        temp_f2 = gu_sqrtf(temp_f0 + 1.0);
        arg0[3] = temp_f2 * 0.5;
        temp_f2 = (0.5 / temp_f2);
        arg0[0] = (arg1->m[1][2] - arg1->m[2][1]) * temp_f2;
        arg0[1] = (arg1->m[2][0] - arg1->m[0][2]) * temp_f2;
        arg0[2] = (arg1->m[0][1] - arg1->m[1][0]) * temp_f2;
    }
    else{
        var_a0 = 0;
        if (arg1->m[var_a0][var_a0] < arg1->m[1][1]) {
            var_a0 = 1;
        }
        if (arg1->m[var_a0][var_a0] < arg1->m[2][2]) {
            var_a0 = 2;
        }
        temp_a0 = D_80371ED0[var_a0];
        temp_a2 = D_80371ED0[temp_a0];

        temp_f2 = gu_sqrtf((arg1->m[var_a0][var_a0] - (arg1->m[temp_a0][temp_a0] + arg1->m[temp_a2][temp_a2])) + 1.0);
        arg0[var_a0] = temp_f2 * 0.5;
        temp_f2 = (0.5 / temp_f2);
        arg0[3] = (arg1->m[temp_a0][temp_a2] - arg1->m[temp_a2][temp_a0]) * temp_f2;
        arg0[temp_a0] = (arg1->m[var_a0][temp_a0] + arg1->m[temp_a0][var_a0]) * temp_f2;
        arg0[temp_a2] = (arg1->m[var_a0][temp_a2] + arg1->m[temp_a2][var_a0]) * temp_f2;
    }
}

void func_80345C78(f32 arg0[4], f32 arg1[3]) {
    mlMtxIdent();
    mlMtxRotYaw(arg1[1]);
    mlMtxRotPitch(arg1[0]);
    mlMtxRotRoll(arg1[2]);
    func_80345A44(arg0, mlMtx_get_stack_pointer());
}

void func_80345CD4(f32 arg0[4], f32 arg1[4]){
    mlMtxIdent();
    mlMtxRotRoll(arg1[2]);
    mlMtxRotYaw(arg1[1]);
    mlMtxRotPitch(arg1[0]);
    func_80345A44(arg0, mlMtx_get_stack_pointer());
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
