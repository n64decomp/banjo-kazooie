#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/*.bss */
f32 D_8037DA00[3];
f32 D_8037DA10[3];
f32 D_8037DA20[3];
f32 D_8037DA30[3];
f32 D_8037DA40[3];

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_379B0/func_802BE940.s")

void func_802BEA4C(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3]) {
    f32 sp24[3];

    func_80256E24(sp24, arg0[0], arg0[1], 0.0f, 0.0f, -arg2);
    ml_vec3f_add(arg3, sp24, arg1);
}


void func_802BEAAC(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], f32 arg4[3], f32 arg5[3], f32 arg6[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 pitch;
    f32 yaw;

    pitch = arg0[0];
    yaw = arg0[1];
    ml_vec3f_pitch_rotate_copy(sp54, D_8037DA00, pitch);
    ml_vec3f_pitch_rotate_copy(sp48, D_8037DA10, pitch);
    ml_vec3f_pitch_rotate_copy(sp3C, D_8037DA20, pitch);
    ml_vec3f_pitch_rotate_copy(sp30, D_8037DA30, pitch);
    ml_vec3f_yaw_rotate_copy(sp54, sp54, yaw);
    ml_vec3f_yaw_rotate_copy(sp48, sp48, yaw);
    ml_vec3f_yaw_rotate_copy(sp3C, sp3C, yaw);
    ml_vec3f_yaw_rotate_copy(sp30, sp30, yaw);
    ml_vec3f_scale(sp54, arg2);
    ml_vec3f_scale(sp48, arg2);
    ml_vec3f_scale(sp3C, arg2);
    ml_vec3f_scale(sp30, arg2);
    ml_vec3f_add(arg3, arg1, sp54);
    ml_vec3f_add(arg4, arg1, sp48);
    ml_vec3f_add(arg5, arg1, sp3C);
    ml_vec3f_add(arg6, arg1, sp30);
}

void func_802BEBE8(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3]) {
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;

    sp20 = arg0[0];
    sp1C = arg0[1];

    ml_vec3f_pitch_rotate_copy(sp24, D_8037DA40, sp20);
    ml_vec3f_yaw_rotate_copy(sp24, sp24, sp1C);
    ml_vec3f_scale(sp24, arg2);
    ml_vec3f_add(arg3, arg1, sp24);
}
