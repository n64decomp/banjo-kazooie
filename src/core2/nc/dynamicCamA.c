#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32  func_802BD51C(void);
extern void func_802BDCE0(f32, f32*, f32*, f32, f32);
extern void func_802BDE88(f32*, f32*, f32, f32, f32);
extern void func_802589E4(f32[3], f32, f32);
extern void ncDynamicCamera_setState(s32);

/* .data */
f32 D_80365DA0 = 0.0f;
f32 D_80365DA4 = 0.0f;
f32 D_80365DA8 = 0.0f;
f32 D_80365DAC = 100.0f;
u8 D_80365DB0 = 0;
f32 D_80365DB4 = 0.0f;

/* .code */ 
void ncDynamicCamA_init(void){}

void ncDynamicCamA_end(void){}

bool ncDynamicCamA_func_802C1DB0(f32 arg0) {
    f32 pad4C;
    f32 camera_position[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];


    ncDynamicCamera_getPosition(camera_position);
    func_802C02D4(sp28);
    ml_vec3f_diff_copy(sp34, camera_position, sp28);
    D_80365DAC = gu_sqrtf(sp34[0]*sp34[0] + sp34[2]*sp34[2]);
    func_8025801C(sp34, &D_80365DA4);
    D_80365DA8 = 0.0f;
    D_80365DA0 = mlNormalizeAngle(D_80365DA4 + arg0);
    D_80365DB0 = 0;
    pad4C = (arg0 / 5.0);
    func_802589E4(sp1C, mlNormalizeAngle(D_80365DA4 + pad4C), D_80365DAC);
    sp1C[0] += sp28[0];
    sp1C[2] += sp28[2];
    pad4C = camera_position[1];
    sp1C[1] = pad4C;
    if (func_802BCE0C(camera_position, sp1C)) {
        ncDynamicCamera_setState(0xA);
        return TRUE;
    }
    return FALSE;
}

bool ncDynamicCamA_func_802C1EE0(void){
    return D_80365DB0;
}

f32 ncDynamicCamA_func_802C1EEC(void){
    f32 sp1C[3];

    if(func_802C0190() == 3){
        ncDynamicCamera_getPosition(sp1C);
        return sp1C[1];
    }
    else{
        return func_802BD51C();
    }
}

void ncDynamicCamA_update(void) {
    f32 spB4[3];
    f32 spA8[3];
    f32 sp9C[3];
    f32 sp90[3];
    f32 sp84[3];
    f32 sp80;
    s32 sp7C;
    s32 sp78;
    f32 sp6C[3];
    f32 sp60[3];
    f32 temp_f0;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    s32 phi_a0;

    ncDynamicCamera_getPosition(sp6C);
    ncDynamicCamera_getPosition(sp9C);
    func_802C02D4(spB4);
    sp80 = time_getDelta();

    if(D_80365DB0){
        return;
    }
    
    func_802BDCE0(D_80365DA0, &D_80365DA4, &D_80365DA8, 50.0f, 3.0f);
    D_80365DB0 = (mlAbsF(D_80365DA0 - D_80365DA4) < 0.5);
    ml_vec3f_diff_copy(sp60, sp9C, spB4);
    D_80365DAC = gu_sqrtf(sp60[0]*sp60[0] + sp60[2]*sp60[2]);
    func_802BDE88(&D_80365DB4, &D_80365DAC, func_802BD8D4(), 0.01f, 0.008f);
    func_80256E24(sp90, 0.0f, D_80365DA4, 0.0f, 0.0f, D_80365DAC);
    ml_vec3f_add(spA8, spB4, sp90);
    spA8[1] = sp9C[1] + ((ncDynamicCamA_func_802C1EEC() - sp9C[1]) * sp80 * 2);
    ncDynamicCamera_setPosition(spA8);
    sp78 = 0;
    sp7C = 0;
    if (func_802BE60C() != 0) {
        D_80365DB0 = 1;
        D_80365DB4 = 0.0f;
        sp7C = 1;
    }
    phi_a0 = (mlDiffDegF(D_80365DA0, D_80365DA4) > 0.0f) ? 2 : 3;
    if (func_802BC84C(phi_a0)) {
        D_80365DB4 = 0.0f;
        sp78 = 1;
        sp7C += 1;
    }
    func_802BE6FC(sp84, spB4);
    if (sp7C != 0) {
        ncDynamicCamera_getPosition(sp44);
        ml_vec3f_diff_copy(sp50, sp44, spB4);
        D_80365DAC = gu_sqrtf((sp50[0] * sp50[0]) + (sp50[2] * sp50[2]));
    }
    if (sp78 != 0) {
        D_80365DB0 = 1;
        ncDynamicCamera_setRotation(sp84);
        return;
    }
    ncDynamicCamera_getRotation(sp38);
    sp2C[0] = mlDiffDegF(sp84[0], sp38[0]);
    sp2C[1] = mlDiffDegF(sp84[1], sp38[1]);
    sp2C[2] = 0.0f;
    sp84[0] = sp38[0] + (sp2C[0] * sp80 * 4.0f);
    sp84[1] = sp38[1] + sp2C[1];
    ncDynamicCamera_setRotation(sp84);
    if (D_80365DB0 != 0) {
        D_80365DB4 = 0.0f;
    }
}
