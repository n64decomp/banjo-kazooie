#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802BD51C(void);


void func_802C0150(s32 arg0);

/* .bss */
u8  D_8037DB40;
f32 D_8037DB48[3];
f32 D_8037DB58[3];
f32 D_8037DB70;
f32 D_8037DB78[3];
f32 D_8037DB84[3];
f32 D_8037DB90[3];
f32 D_8037DB9C;

/* .code */
void func_802C0120(void){
    D_8037DB40 = 0;
    func_802C0150(2);
}

void func_802C0148(void){}

void func_802C0150(s32 arg0) {
    D_8037DB40 = arg0;
    if (arg0 == 6) {
        func_802BD4C0(D_8037DB48);
        ml_vec3f_clear(D_8037DB58);
    }
}

s32 func_802C0190(void){
    return D_8037DB40;
}

void func_802C019C(f32 arg0[3]){
    func_802BD3CC(arg0);
}

void func_802C01BC(f32 arg0[3]){
    func_802BD4C0(arg0);
}

void func_802C01DC(f32 arg0[3]) {
    f32 sp1C[3];

    func_8028E7EC(sp1C);
    player_getPosition(arg0);
    arg0[0] = sp1C[0];
    arg0[1] += 90.0f;
    arg0[2] = sp1C[2];
}

void func_802C0234(f32 arg0[3]) {
    player_getPosition(arg0);
    arg0[1] += 60.0f;
}

void func_802C026C(f32 arg0[3]) {
    f32 sp1C[3];

    func_802BD4C0(arg0);
    player_getPosition(sp1C);
    arg0[1] = sp1C[1];
    arg0[1] += 60.0f;
}

void func_802C02B4(f32 arg0[3]){
    func_802BD4C0(arg0);
}

void func_802C02D4(f32 arg0[3]) {
    switch(D_8037DB40){
        case 1: 
            func_802C019C(arg0);
            break;

        case 2: 
            func_802C01BC(arg0);
            break;

        case 3:
            func_802C01DC(arg0);
            break;

        case 4:
            func_802C0234(arg0);
            break;

        case 5:
            func_802C026C(arg0);
            break;

        case 6:
            func_802C02B4(arg0);
            break;
    }
}


void func_802C0370(){
    func_802BD384(D_8037DB84);
}

void func_802C0394(f32 src[3]){
    ml_vec3f_copy(D_8037DB90, src);
}

void func_802C03BC(void) {
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    func_802BD384(D_8037DB78);
    ml_vec3f_diff_copy(sp20, D_8037DB90, D_8037DB84);
    ml_vec3f_diff_copy(sp2C, D_8037DB78, D_8037DB84);
    ml_vec3f_normalize(sp20);
    ml_vec3f_normalize(sp2C);
    sp1C = sp20[0]*sp2C[0] + sp20[1]*sp2C[1] + sp20[2]*sp2C[2];
    if (sp1C < 0.0f || D_8037DB9C < 0.0f) {
        func_802BD334(D_8037DB84);
    }
     D_8037DB9C = sp1C;
}

void func_802C0490(f32 arg0[3]){
    func_802C02D4(arg0);
}

void func_802C04B0(void) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_802BD384(sp34);
    func_802C0490(sp1C);
    ml_vec3f_diff_copy(sp28,sp34, &sp1C);
    func_8025801C(sp28, &D_8037DB70);
}

void func_802C04F8(void) {
    func_802BE244(5.0f, 10.0f);
    func_802BE230(3.0f, 8.0f);
    func_802C0150(2);
    func_802C04B0();
}

void func_802C0550(void){}

void func_802C0558(void) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;

    func_802C0370();
    func_802C0490(sp4C);
    func_80256E24(sp34, 0.0f, D_8037DB70, 0.0f, 0.0f, func_802BD8D4());
    ml_vec3f_add(sp40, sp4C, sp34);
    sp40[1] = func_802BD51C();
    func_802C0394(sp40);
    func_802BE190(sp40);
    sp24 = 0;
    if (func_802BE60C() != 0) {
        if (func_802BC84C(1) != 0) {
            sp24 = 1;
        } else {
            func_802C03BC();
        }
        func_802C04B0();
    }
    func_802C0490(sp4C);
    func_802BE6FC(sp28, sp4C);
    if (sp24) {
        func_802BD35C(sp28);
    }
    func_802BD904(sp28);
}
