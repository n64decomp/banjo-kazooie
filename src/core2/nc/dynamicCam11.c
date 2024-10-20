#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 cameraNodeType3_getFarDistance(void *);
extern f32 cameraNodeType3_getCloseDistance(void *);

/* .bss */
f32 D_8037DAC0[3];
f32 D_8037DAD0[3];
f32 D_8037DADC;
f32 D_8037DAE0;
u8  D_8037DAE4;
u8  D_8037DAE5;
f32 D_8037DAE8;
f32 D_8037DAEC;

/* .code */
void ncDynamicCam11_init(void){
    D_8037DAE5 = TRUE;
    func_802C0150(1);
}

void ncDynamicCam11_end(void){}

void ncDynamicCam11_update(void) {
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp24[3];
    f32 sp20;

    if (D_8037DAE5 == 0) {
        func_802C02D4(sp64);
        ncDynamicCamera_getPosition(sp58);
        ml_vec3f_diff_copy(sp24, sp58, sp64);
        sp24[1] = 0.0f;
        sp20 = gu_sqrtf( sp24[0]*sp24[0] + sp24[2]*sp24[2] );
        if (sp20 < D_8037DAE0) {
            sp20 = D_8037DAE0;
        }
        if (D_8037DADC < sp20) {
            sp20 = D_8037DADC;
        }
        ml_vec3f_diff_copy(sp34, D_8037DAC0, sp64);
        sp34[1] = 0.0f;
        sp30 = gu_sqrtf(sp34[0]*sp34[0] + sp34[2]*sp34[2]);
        if (sp30 < sp20) {
            sp20 = sp30;
        }
        ml_vec3f_set_length_copy(sp24, sp34, sp20);
        sp24[0] += sp64[0];
        sp24[2] += sp64[2];
        sp24[1] = D_8037DAC0[1];
        func_802BE190(sp24);
        if (D_8037DAE4) {
            func_802BE60C();
        }
        ncDynamicCamera_getPosition(sp58);
        func_802BC434(sp4C, sp64, sp58);
        func_802BC434(sp40, sp64, D_8037DAD0);
        if (sp30 < 150.0f) {
            sp4C[1] = sp40[1];
        }
        func_802BD904(sp4C);
    }
}

void func_802BF798(void) {
    f32 sp2C;
    f32 sp28;
    s32 temp_v0;

    temp_v0 = ncCameraNodeList_getCameraNodeType3();
    D_8037DAE4 = code33310_func_802BA4F0(temp_v0);
    cameraNodeType3_getPositionWithPitchYawRoll(temp_v0, &D_8037DAD0);
    cameraNodeType3_getPosition(temp_v0, &D_8037DAC0);
    cameraNodeType3_getHorizontalAndVerticalSpeed(temp_v0, &sp2C, &sp28);
    func_802BE230(sp2C, sp28);
    cameraNodeType3_getRotationAndAccelaration(temp_v0, &sp2C, &sp28);
    func_802BE244(sp2C, sp28);
    D_8037DAE8 = sp2C;
    D_8037DAEC = sp28;
    D_8037DAE0 = cameraNodeType3_getCloseDistance(temp_v0);
    D_8037DADC = cameraNodeType3_getFarDistance(temp_v0);
    D_8037DAE5 = 0;
}
