#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802BD51C(void);
extern void func_802C0150(s32 arg0);

f32 D_8037DB70;
struct {
    f32 D_8037DB78[3];
    f32 D_8037DB84[3];
    f32 D_8037DB90[3];
}cameraStateB;

void func_802C0370(){
    ncDynamicCamera_getPosition(cameraStateB.D_8037DB84);
}

void func_802C0394(f32 src[3]){
    ml_vec3f_copy(cameraStateB.D_8037DB90, src);
}

void func_802C03BC(void) {
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;
    static f32 D_8037DB9C;


    ncDynamicCamera_getPosition(cameraStateB.D_8037DB78);
    ml_vec3f_diff_copy(sp20, cameraStateB.D_8037DB90, cameraStateB.D_8037DB84);
    ml_vec3f_diff_copy(sp2C, cameraStateB.D_8037DB78, cameraStateB.D_8037DB84);
    ml_vec3f_normalize(sp20);
    ml_vec3f_normalize(sp2C);
    sp1C = sp20[0]*sp2C[0] + sp20[1]*sp2C[1] + sp20[2]*sp2C[2];
    if (sp1C < 0.0f || D_8037DB9C < 0.0f) {
        ncDynamicCamera_setPosition(cameraStateB.D_8037DB84);
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

    ncDynamicCamera_getPosition(sp34);
    func_802C0490(sp1C);
    ml_vec3f_diff_copy(sp28,sp34, sp1C);
    func_8025801C(sp28, &D_8037DB70);
}

void ncDynamicCamB_init(void) {
    func_802BE244(5.0f, 10.0f);
    func_802BE230(3.0f, 8.0f);
    func_802C0150(2);
    func_802C04B0();
}

void ncDynamicCamB_end(void){}

void ncDynamicCamB_update(void) {
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
        ncDynamicCamera_setRotation(sp28);
    }
    func_802BD904(sp28);
}
