#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_8024575C(f32[3], f32[3], f32, f32[3], s32, u32);
extern void func_8024C510(f32);
extern f32 func_80259198(f32, f32);
extern f32 func_8028E82C(void);
extern f32 func_8028EF88(void);
extern int func_80320DB0(f32[3], f32, f32[3], u32);
extern f32 ml_vec3f_dot_product(f32[3], f32[3]);

void func_802BD780(f32[3], f32[3], f32, f32, f32, f32);
f32  func_802BD8C8(void);


/* .rodata */
extern f64 D_80375E80;
extern f64 D_80375E88;

extern f64 D_80375EA8;
extern f64 D_80375EB0;

/* .bss */
extern f32 D_8037D948[3];
extern f32 D_8037D958[3];
extern f32 D_8037D968[3];
extern f32 D_8037D974;
extern f32 D_8037D978;
extern f32 D_8037D97C;
extern f32 D_8037D980;
extern f32 D_8037D984;
extern f32 D_8037D988;
extern f32 D_8037D98C;
extern f32 D_8037D990;
extern f32 D_8037D994;
extern f32 D_8037D998;
extern f32 D_8037D99C;
extern f32 D_8037D9A0;
extern f32 D_8037D9B8[3];
extern f32 D_8037D9C8[3];
extern f32 D_8037D9D4;
extern f32 D_8037D9D8;
extern f32 D_8037D9E0[3];
extern f32 D_8037D9EC;
extern f32 D_8037D9F0;
extern u8 D_8037D9F4;
extern u8 D_8037D9F5;
extern u8 D_8037D9F7;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BC640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BC84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BCEC4.s")

int func_802BD0CC(void){
    return D_8037D9F4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BD0D8.s")

void func_802BD328(s32 arg0){
    D_8037D9F5 = arg0;
}

void func_802BD334(f32 arg0[3]){
    ml_vec3f_copy(D_8037D958, arg0);
}

void func_802BD35C(f32 arg0[3]){
    ml_vec3f_copy(D_8037D968, arg0);
}

void func_802BD384(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037D958);
}

void func_802BD3A8(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037D968);
}

void func_802BD3CC(f32 arg0[3]) {
    f32 sp2C;
    f32 temp_f0;
    f32 temp_f2;

    player_getPosition(arg0);
    sp2C = func_8028E82C();
    if ((func_8028F2FC() != 0) && (func_8028EE84() != 2) && (player_getTransformation() == TRANSFORM_1_BANJO)) {
        temp_f0 = func_8028EF88();
        temp_f2 = temp_f0 - 500.0f;
        sp2C = ml_map_f(arg0[1], temp_f0 - 80.0f, temp_f2, temp_f0, temp_f2);
    }
    if ((sp2C + D_8037D974) < arg0[1]) {
        arg0[1] = (f32) (arg0[1] + (80.0f - D_8037D974));
    }
    else{
        arg0[1] = (f32) (sp2C + 80.0f);
    }
}

void func_802BD4C0(f32 arg0[3]) {
    func_802BD3CC(arg0);
    arg0[0] += D_8037D9B8[0];
    arg0[1] += D_8037D9B8[1];
    arg0[2] += D_8037D9B8[2];
}

f32 func_802BD51C(void) {
    f32 sp24[3];
    f32 sp20;
    f32 sp1C;
    
    player_getPosition(sp24);
    sp20 = func_8028E82C();
    sp1C = D_8037D9A0 + 35.0f + 20.0f;
    if (func_8028F2FC()) {
        sp20 = func_8028EF88();
    }
    if ((sp24[1] - sp20) > 130.0f) {
        D_8037D978 = sp24[1] + func_802BD8C8() - 130.0f;
    } else {
        D_8037D978 = func_802BD8C8() + sp20;
    }
    if (D_8037D978 < sp1C) {
        D_8037D978 = sp1C;
    }
    return D_8037D978;
}

void func_802BD610(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 sp24[3];

    sp24[0] = mlDiffDegF(arg0[0], arg1[0]);
    sp24[1] = mlDiffDegF(arg0[1], arg1[1]);
    sp24[0] *= 0.003333 * D_8037D984;
    sp24[1] *= 0.003333 * D_8037D988;
    sp24[0] = func_80259198(sp24[0], D_8037D98C * 0.003333);
    sp24[1] = func_80259198(sp24[1], D_8037D990 * 0.003333);
    sp24[2] = 0.0f;
    arg1[0] = mlNormalizeAngle(arg1[0] + sp24[0]);
    arg1[1] = mlNormalizeAngle(arg1[1] + sp24[1]);
}

void func_802BD720(f32 arg0[3]) {
    f32 sp24[3];

    func_802BD3A8(sp24);
    func_802BD780(arg0, sp24, D_8037D984, D_8037D988, D_8037D98C, D_8037D990);
    func_802BD35C(sp24);
}

void func_802BD780(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    s32 temp_s0;
    s32 temp_s1;
    s32 i;

    temp_s1 = func_8033DD90() * 5;
    for(i = 0; i < temp_s1; i++){
        func_802BD610(arg0, arg1, arg2, arg3, arg4, arg5);
    }
}

void func_802BD82C(f32 arg0, f32 arg1){
    D_8037D97C = arg0;
    D_8037D980 = arg1;
}

void func_802BD840(void){
    func_802BD82C(110.0f, 180.0f);
}

void func_802BD870(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_8037D984 = arg0;
    D_8037D988 = arg1;
    D_8037D98C = arg2;
    D_8037D990 = arg3;
}

void func_802BD8A4(f32 arg0, f32 arg1, f32 arg2) {
    D_8037D994 = arg0;
    D_8037D998 = arg1;
    D_8037D99C = arg2;
}

f32 func_802BD8C8(void){
    return D_8037D99C;
}

f32 func_802BD8D4(void){
    return D_8037D994;
}

f32 func_802BD8E0(void){
    return D_8037D998;
}

void func_802BD8EC(f32 arg0){
    D_8037D974 = arg0;
}

f32 func_802BD8F8(void){
    return D_8037D974;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BD904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BDB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BDCE0.s")

int func_802BDE10(f32 arg0, f32 arg1){
    f32 sp1C;
    sp1C = mlAbsF(arg0);
    return (mlAbsF(arg1) < sp1C) && (0.0f <= arg0*arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BDE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BDF5C.s")

void func_802BE190(f32 arg0[3]){
    f32 sp34[3];
    int i;
    int end;

    if(func_802BC428()){
        ml_vec3f_clear(D_8037D9E0);
        func_802BD334(arg0);
        return;
    }

    end = func_8033DD90()*5;
    func_802BD384(sp34);
    for(i = 0; i < end; i++){
        func_802BDF5C(arg0, sp34);
    }
    func_802BD334(sp34);
}

void func_802BE230(f32 arg0, f32 arg1){
    D_8037D9EC = arg0;
    D_8037D9F0 = arg1;
}

void func_802BE244(f32 arg0, f32 arg1){
    D_8037D9D4 = arg0;
    D_8037D9D8 = arg1;
}

#ifndef NONMATCHING
void func_802BE258(f32 arg0[3], f32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_356B0/func_802BE258.s")
#else
void func_802BE258(f32 arg0[3], f32 arg1){
    f32 sp54[3];
    int i;

    for(i = 0; func_80320DB0(arg0, arg1, sp54, 0x9e0000) && i < 1; i++){//L802BE2C0
        if((sp54[0]*sp54[0] + sp54[1]*sp54[1] + sp54[2]*sp54[2]) < D_80375EB0)
            return;
        arg0[0] += 1.5f * sp54[0];
        arg0[1] += 1.5f * sp54[1];
        arg0[2] += 1.5f * sp54[2];
    }
}
#endif

void func_802BE384(f32 arg0[3], f32 arg1[3], f32 arg2[3], f32 arg3[3], f32 arg4[3]){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    f32 dp;

    sp34[0] = arg3[0] - arg2[0];
    sp34[1] = arg3[1] - arg2[1];
    sp34[2] = arg3[2] - arg2[2];

    sp28[0] = arg1[0] - arg0[0];
    sp28[1] = arg1[1] - arg0[1];
    sp28[2] = arg1[2] - arg0[2];

    sp1C[0] = sp34[0] - sp28[0];
    sp1C[1] = sp34[1] - sp28[1];
    sp1C[2] = sp34[2] - sp28[2];
    dp = -ml_vec3f_dot_product(arg4, sp1C);
    arg3[0] += dp*arg4[0];
    arg3[1] += dp*arg4[1];
    arg3[2] += dp*arg4[2];

}

void func_802BE484(f32 arg0[3], f32 arg1[3]){
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    int sp2C;
    s32 tmp_v0;

    func_802BE258(arg0, 35.0f);
    ml_vec3f_copy(sp48, arg0);
    ml_vec3f_copy(sp3C, arg1);
    ml_vec3f_diff_copy(sp30, sp3C, sp48);
    ml_vec3f_normalize(sp30);
    ml_vec3f_scale(sp30, 35.0f);

    sp3C[0] += sp30[0];
    sp3C[1] += sp30[1];
    sp3C[2] += sp30[2];
    sp2C = func_80320B98(sp48, sp3C, sp54, 0x9e0000);
    ml_vec3f_diff(sp3C, sp30);

    tmp_v0 = func_8024575C(sp48, sp3C, 35.0f, sp54, 3, 0x9e0000);
    if(sp2C || tmp_v0){
        func_802BE384(sp48, sp3C, arg0, arg1, sp54);
        ml_vec3f_diff_copy(sp30, arg1, arg0);
        ml_vec3f_normalize(sp30);
        ml_vec3f_scale(sp30, 35.0f);
        arg1[0] += sp30[0];
        arg1[1] += sp30[1];
        arg1[2] += sp30[2];
        func_80320B98(arg0, arg1, sp54, 0x9e0000);
        ml_vec3f_diff(arg1, sp30);
    }
}

int func_802BE60C(void){
    f32 sp1C[3];

    if(func_802BC428())
        return 0;
    
    if(map_get() == MAP_91_FILE_SELECT)
        return 0;

    ml_vec3f_copy(sp1C, D_8037D958);
    func_802BE484(D_8037D948, D_8037D958);
    return !(sp1C[0] == D_8037D958[0]) || !(sp1C[1] == D_8037D958[1]) || !(sp1C[2] == D_8037D958[2]);
}

void func_802BE6FC(f32 arg0[3], f32 arg1[3]){
    func_802BC434(arg0, arg1, D_8037D958);
}

void func_802BE720(void){
    s32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    func_8024C5CC(sp28);
    func_8024C764(sp1C);
    func_802BD334(sp28);
    func_802BD35C(sp1C);

    sp34 = func_802BD0CC();
    func_802BD0D8(0);
    func_802BD0D8(sp34);
    ml_vec3f_clear(D_8037D9C8);
    ml_vec3f_clear(D_8037D9E0);
    func_802C28C8();
}

void func_802BE794(void){
    f32 sp2C[3];
    f32 sp20[3];
    if(D_8037D9F4 == 1 || D_8037D9F4 == 0xb || D_8037D9F4 == 3){
        player_getPosition(sp2C);
        sp2C[1] += 100.0f;
        player_getRotation(sp20);
        sp20[1] = mlNormalizeAngle(sp20[1] + 180.0f);
        func_8024CD88(sp2C);
        func_8024CE18(sp20);
        func_8024C510(300.0f);
        func_802BE720();
    }//L802BE828
}

int func_802BE834(f32 arg0[3]){
    s32 pad;
    f32 sp30[3];
    f32 sp24[3];
    f32 sp18[3];

    ml_vec3f_copy(sp18, arg0);
    player_getPosition(sp30);
    sp30[1] += 60.0f;
    if(func_80320B98(sp30, sp18, sp24, 0x9e0000))
        return 0;
    return 1;

}

void func_802BE894(f32 arg0[3], f32 arg1[3]){
    f32 sp1C[3];
    func_802C02D4(sp1C);
    func_802BC434(arg0, sp1C, arg1);
    arg0[2] = 0.0f;
}

void func_802BE8D8(void){
    D_8037D9F7 = 1;
    func_802C29A0(1);
    func_802C2A64(D_8037D958);
    func_802C2A8C(D_8037D968);
}

void func_802BE91C(void){
    func_802C29A0(3);
}
