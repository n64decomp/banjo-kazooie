#include <ultra64.h>
#include "functions.h"
#include "variables.h"

int func_802458E0(f32 arg0[3], Actor *arg1, s32 arg2);
extern bool func_80320DB0(f32[3], f32, f32[3], u32);
extern bool func_80323240(struct56s *, f32, f32[3]);
extern f32 ml_vec3f_dot_product(f32[3], f32[3]);
extern Struct66s *func_80320B98(f32[3], f32[3], f32[3], u32);

/* .rodata */
extern f64 D_802776C8;

/* .bss */
u8 pad_D_8027EF20[0x10];
f32 D_8027EF30;

/* .code */
void func_80244CD0(f32 arg0[3], u32 arg1) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    Struct66s *temp_v0;

    ml_vec3f_copy(sp28, arg0);
    ml_vec3f_copy(sp1C, arg0);
    sp28[1] += 100.0f;
    sp1C[1] -= 500.0f;
    temp_v0 = func_80320B98(sp28, sp1C, sp34, arg1);
    if ((temp_v0 != NULL) && (!(sp34[1] < 0.0f) || (temp_v0->unk8 & 0x10000)) && (arg0[1] < sp1C[1])) {
        arg0[1] = sp1C[1];
    }
}

Struct66s *func_80244D94(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 arg3, f32 arg4) {
    f32 sp2C[3];
    f32 sp20[3];
    Struct66s *sp1C;

    ml_vec3f_copy(sp20, arg1);
    ml_vec3f_diff_copy(sp2C, sp20, arg0);
    ml_vec3f_set_length_copy(sp2C, sp2C, arg4);
    sp20[0] += sp2C[0];
    sp20[1] += sp2C[1];
    sp20[2] += sp2C[2];
    sp1C = func_80320B98(arg0, sp20, arg2, arg3);
    if (sp1C == NULL) {
        return 0;
    }
    ml_vec3f_diff(sp20, sp2C);
    ml_vec3f_copy(arg1, sp20);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80244F00.s")

void func_80244FC0(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4, u32 arg5) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 pad[2];

    sp2C[0] = arg0[0];
    sp2C[1] = arg0[1] + arg3;
    sp2C[2] = arg0[2];
    ml_vec3f_copy(arg1, arg0);
    if (func_80320DB0(sp2C, arg2, sp38, arg5)) {
        arg1[0] = arg0[0] + (sp38[0] * arg2);
        arg1[1] = arg0[1] + (sp38[1] * arg2);
        arg1[2] = arg0[2] + (sp38[2] * arg2);
        sp44[0] = arg0[0] + (sp38[0] * arg2);
        sp44[1] = arg0[1] + (sp38[1] * arg2);
        sp44[2] = arg0[2] + (sp38[2] * arg2);
        ml_vec3f_copy(arg0, sp44);
        if (arg4 != 0) {
            func_80244CD0(arg0, arg5);
        }
    }
}

void func_802450DC(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3]) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 phi_f12;

    ml_vec3f_diff_copy(sp3C, arg1, arg0);
    ml_vec3f_diff_copy(sp30, arg3, arg2);
    ml_vec3f_diff_copy(sp24, sp3C, sp30);
    phi_f12 = -ml_vec3f_dot_product(arg4, sp24);
    phi_f12 = MAX(5.0f, phi_f12);
    arg1[0] += phi_f12 * arg4[0];
    arg1[1] += phi_f12 * arg4[1];
    arg1[2] += phi_f12 * arg4[2];
}

void func_802451A4(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3], s32 arg5) {
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    s32 phi_v0;
    f32 sp28;
    f32 phi_f12;

    ml_vec3f_diff_copy(sp6C, arg1, arg0);
    ml_vec3f_diff_copy(sp60, arg3, arg2);
    ml_vec3f_diff_copy(sp54, sp6C, sp60);
    ml_vec3f_normalize_copy(sp3C, sp54);
    ml_vec3f_yaw_rotate_copy(sp30, sp3C, 90.0f);
    sp28 = ml_vec3f_dot_product(arg4, sp3C);
    if (arg5 != 0) {
        D_8027EF30 = ml_vec3f_dot_product(arg4, sp30);
    }
    phi_v0 = (D_8027EF30 < 0.0f) ? -1 : 1;
    ml_vec3f_yaw_rotate_copy(sp48, arg4,(phi_v0 * sp28) * D_802776C8);
    phi_f12 = -ml_vec3f_dot_product(&sp48, &sp54);
    phi_f12 = MAX(5.0f, phi_f12);
    arg1[0] += phi_f12 * sp48[0];
    arg1[1] += phi_f12 * sp48[1];
    arg1[2] += phi_f12 * sp48[2];
}

bool func_80245314(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4) {
    f32 sp2C[3];
    f32 sp20[3];
    bool temp_v0;

    ml_vec3f_copy(sp2C, arg0);
    ml_vec3f_copy(sp20, arg0);
    sp2C[1] += arg2;
    sp20[1] += arg3;
    temp_v0 = func_80320B98(sp2C, sp20, arg1, arg4);
    if (temp_v0 != 0) {
        arg0[1] = sp20[1];
    }
    return temp_v0;
}

bool func_802453A0(f32 arg0[3], f32 arg1[3], f32 arg2[3]){
    f32 sp24[3];
    f32 sp18[3];
    ml_vec3f_copy(sp18, arg1);
    return func_80320B98(arg0, sp18, sp24, arg2);
}

f32 func_802453DC(f32 arg0[3], f32 arg1, f32 arg2[3], s32 arg3) {
    f32 sp24[3];
    f32 phi_f0;

    func_80323240(arg0, arg1, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return arg1;
    }
    func_80323240(arg0, 1.0f, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return 1.0f;
    }

    func_80323240(arg0, 0.0f, sp24);
    if (!func_802453A0(arg2, sp24, arg3)) {
        return 0.0f;
    }
    return arg1;
}

//over_water?
int func_8024549C(f32 arg0[3], f32 arg1){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    int sp1C;

    sp20[0] = sp20[1] = sp20[2] = 0.0f;
    sp20[1] = arg1;

    ml_vec3f_diff_copy(sp2C, arg0, sp20);
    ml_vec3f_add(sp38, arg0, sp20);
    sp1C = func_80309B48(sp2C, sp38, sp44, 0xf800ff0f);
    if(sp1C){
        ml_vec3f_copy(arg0, sp38);
    }
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_80245524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024559C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024560C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_8024575C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_72B0/func_802457C4.s")

void func_8024587C(Struct60s *dst, Struct60s *src){
    dst->unk0[0] = src->unk0[0];
    dst->unk0[1] = src->unk0[1];
    dst->unk0[2] = src->unk0[2];
    dst->unk8 = src->unk8;
    dst->unk6 = src->unk6;
}

int func_802458A8(f32 arg0[3], ActorMarker *arg1, s32 arg2){
    return func_802458E0(arg0, marker_getActor(arg1), arg2);
}

int func_802458E0(f32 arg0[3], Actor *arg1, s32 arg2){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    ml_vec3f_copy(sp28, arg0);
    ml_vec3f_copy(sp1C, arg1->position);
    sp1C[1] += (f32)arg2;
    if(sp1C[1] < sp28[1])
        return FALSE;

    if(func_80320B98(sp28, sp1C, sp34, 0x25e0000)){
        return FALSE;
    }
    return TRUE;
}
