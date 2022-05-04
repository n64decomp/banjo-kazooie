#include <ultra64.h>
#include "functions.h"
#include "variables.h"



/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0120.s")

void func_802C0148(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C019C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C01BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C01DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C026C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C02B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C02D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C03BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C04B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C04F8.s")

void func_802C0550(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C0558.s")

//=============== BREAK?????
extern f32 func_8028EBA4(void);
extern f32 func_802BD51C();
extern void func_802BDB30(f32, f32*, f32*, f32, f32, f32);
extern void func_802C2264(f32);

void func_802C095C(void);

/* .rodata */
extern f64 D_80375F50;

/* .bss */
extern f32 D_8037DBA0;
extern f32 D_8037DBA4;
extern f32 D_8037DBA8;
extern f32 D_8037DBAC;
/* .code */
bool func_802C0640(void){
    return mlAbsF(mlDiffDegF(D_8037DBA4, D_8037DBA8)) < 4.0;
}

void func_802C0694(void){}

void func_802C069C(void) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_802BD384(sp34);
    func_802C02D4(sp1C);
    ml_vec3f_diff_copy(sp28, sp34, sp1C);
    D_8037DBA0 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    func_8025801C(sp28, &D_8037DBA8);
    D_8037DBAC = 0.0f;
}

void func_802C0710(void) {
    func_802BE230(5.0f, 8.0f);
    func_802BE244(8.0f, 15.0f);
    func_802C0150(6);
    func_802C2264(0.5f);
    func_802C069C();
    func_802C095C();
}

f32 func_802C0780(void){
    return func_802BD51C();
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_39190/func_802C07A0.s")
#else
void func_802C07A0(void) {
    f32 sp84[3];
    f32 sp7C[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp40;
    f32 sp34[3];
    f32 sp28[3];

    func_802BD384(sp54);
    func_802C02D4(&sp84);
    sp44 = time_getDelta();
    func_802BDB30(D_8037DBA4, &D_8037DBA8, &D_8037DBAC, 800.0f, 160.0f, 100.0f);
    ml_vec3f_diff_copy(sp6C, sp54, sp84);
    sp40 = gu_sqrtf(sp6C[0] * sp6C[0] + sp6C[2]*sp6C[2]);
    func_80256E24(sp60, 0.0f, D_8037DBA8, 0.0f, 0.0f, ((func_802BD8D4() - sp40) * sp44 * 2) + sp40);
    ml_vec3f_add(sp78, sp84, sp60);
    sp78[1] = sp54[1] + (func_802C0780() - sp54[1]) * sp44 * 2;
    func_802BD334(sp78);
    if (func_802BE60C() && func_802BC84C(0)) {
        func_802C069C();
    }
    func_802BE6FC(sp48, sp84);
    func_802BD3A8(sp34);
    sp28[0] = mlDiffDegF(sp48[0], sp34[0]);
    sp28[1] = mlDiffDegF(sp48[1], sp34[1]);
    sp28[2] = 0.0f;
    sp48[0] = sp34[0] + (sp28[0] * sp44 * 4.0f);
    func_802BD35C(sp48);
}
#endif

void func_802C095C(void){
    D_8037DBA4 = mlNormalizeAngle(func_8028EBA4() + D_80375F50);
}
