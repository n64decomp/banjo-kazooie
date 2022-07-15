#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802BD780(f32[3], f32[3], f32, f32, f32, f32);
extern f32 func_80257CF8(f32, f32, f32, f32, f32);

void func_802C29A0(s32 arg0);

/* .bss */
struct{
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
    f32 unk30[3];
    f32 unk3C[3];
    f32 unk48;
    u8 unk4C;
} D_8037DC60;

/* .code */
bool func_802C2550(void) {
    return (ml_vec3f_distance(D_8037DC60.unk0, &D_8037DC60.unk18) < 40.0f);
}

void func_802C2598(f32 arg0[3], f32 arg1[3]) {
    s32 i;

    func_80259430(&D_8037DC60.unk48);
    for( i = 0; i<3; i++){
        D_8037DC60.unk0[i] = func_80257CF8(D_8037DC60.unk48, 1.0f, 0.0f, D_8037DC60.unk30[i], D_8037DC60.unk18[i]);
        D_8037DC60.unkC[i] = mlNormalizeAngle(D_8037DC60.unk3C[i] + func_80257CF8(D_8037DC60.unk48, 0.5f, 0.0f, 0.0f, mlDiffDegF(D_8037DC60.unk24[i], D_8037DC60.unk3C[i])));
    }
    if (D_8037DC60.unk48 == 0.0f) {
        func_802C29A0(2);
    }
    if (func_802C2550() && func_8028F150()) {
        func_8028FCC8(0);
    }
    ml_vec3f_copy(arg0, D_8037DC60.unk0);
    ml_vec3f_copy(arg1, D_8037DC60.unkC);
}


void func_802C26D8(f32 arg0[3], f32 arg1[3]) {
    s32 i;

    func_80259430(&D_8037DC60.unk48);
    for( i = 0; i<3; i++){
        D_8037DC60.unk0[i] = func_80257CF8(D_8037DC60.unk48, 1.0f, 0.0f, D_8037DC60.unk18[i], arg0[i]);
        D_8037DC60.unkC[i] = mlNormalizeAngle(D_8037DC60.unk24[i] + func_80257CF8(D_8037DC60.unk48, 1.0f, 0.5f, 0.0f, mlDiffDegF(arg1[i], D_8037DC60.unk24[i])));
    }
    if (D_8037DC60.unk48 == 0.0f) {
        func_802C29A0(4);
    }
    if (!func_802C2550() && !func_8028F150()) {
        func_8028FCC8(1);
    }
    ml_vec3f_copy(arg0, &D_8037DC60.unk0);
    ml_vec3f_copy(arg1, &D_8037DC60.unkC);
}


void func_802C2838(f32 arg0[3], f32 arg1[3]) {
    ml_vec3f_copy(D_8037DC60.unk0, D_8037DC60.unk18);
    func_802BD780(D_8037DC60.unk24, D_8037DC60.unkC, 10.0f, 20.0f, 120.0f, 200.0f);
    D_8037DC60.unkC[2] = 0.0f;
    ml_vec3f_copy(arg0, D_8037DC60.unk0);
    ml_vec3f_copy(arg1, D_8037DC60.unkC);
}

void func_802C28C8(void){
    ml_vec3f_clear(D_8037DC60.unk0);
    ml_vec3f_clear(D_8037DC60.unkC);
    ml_vec3f_clear(D_8037DC60.unk18);
    ml_vec3f_clear(D_8037DC60.unk24);
    ml_vec3f_clear(D_8037DC60.unk30);
    ml_vec3f_clear(D_8037DC60.unk3C);
    D_8037DC60.unk4C = 0;
}

void func_802C292C(f32 arg0[3], f32 arg1[3]) {
    switch (D_8037DC60.unk4C) {
    case 1:
        func_802C2598(arg0, arg1);
        break;
    case 2:
        func_802C2838(arg0, arg1);
        break;
    case 3:
        func_802C26D8(arg0, arg1);
        /* fallthrough */
    case 4:
        break;
    }
}

void func_802C29A0(s32 arg0) {
    if (arg0 == 1) {
        if (D_8037DC60.unk4C == 3) {
            ml_vec3f_copy(D_8037DC60.unk30, D_8037DC60.unk0);
            ml_vec3f_copy(D_8037DC60.unk3C, D_8037DC60.unkC);
        } else {
            func_802BD384(D_8037DC60.unk0);
            func_802BD3A8(D_8037DC60.unkC);
            func_802BD384(D_8037DC60.unk30);
            func_802BD3A8(D_8037DC60.unk3C);
        }
        D_8037DC60.unk48 = 1.0f;
    }
    if (arg0 == 3) {
        D_8037DC60.unk48 = 1.0f;
    }
    D_8037DC60.unk4C = arg0;
}

void func_802C2A64(f32 src[3]){
    ml_vec3f_copy(D_8037DC60.unk18, src);
}

void func_802C2A8C(f32 src[3]){
    D_8037DC60.unk24[0] = mlNormalizeAngle(src[0]);
    D_8037DC60.unk24[1] = mlNormalizeAngle(src[1]);
    D_8037DC60.unk24[2] = mlNormalizeAngle(src[2]);
}

void func_802C2ADC(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037DC60.unk24);
}

s32 func_802C2B00(void){
    return D_8037DC60.unk4C;
}
