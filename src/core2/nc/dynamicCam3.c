#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80259198(f32, f32);
extern f32 player_getYaw(void);
extern void func_802BD870(f32, f32, f32, f32);

f32 D_8037DC10;

void ncDynamicCam3_end(void){}

void ncDynamicCam3_init(void){
    func_802BD870(10.0f, 20.0f, 120.0f, 200.0f);
    func_802C0150(4);
    D_8037DC10 = 600.0f;
}

void func_802C1B20(f32 arg0){
    D_8037DC10 = arg0;
}

void ncDynamicCam3_update(void) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    

    ncDynamicCamera_getPosition(sp64);
    sp34 = D_8037DC10;
    func_802C02D4(sp7C);
    sp30 = time_getDelta();
    if (sp30);
    ml_vec3f_diff_copy(sp40, sp64, sp7C);
    sp3C = gu_sqrtf(sp40[0]*sp40[0] + sp40[2]*sp40[2]);
    sp3C += func_80259198(sp30*(sp34 - sp3C)*2 , sp30 * 800.0f);
    func_8025727C(sp7C[0], sp7C[1], sp7C[2], sp64[0], sp64[1], sp64[2], &sp4C[0], &sp4C[1]);
    sp40[1] = sp30 * 0.77 * mlDiffDegF(mlNormalizeAngle(player_getYaw() + 180.0f), sp4C[1]);
    sp40[1] = func_80259198(sp40[1], sp30 * 300.0f);
    sp4C[1] = mlNormalizeAngle(sp4C[1] + sp40[1]);
    func_80256E24(&sp58, 0.0f, sp4C[1], 0.0f, 0.0f, sp3C);
    sp70[0] = sp7C[0] + sp58[0];
    sp70[1] = sp64[1];
    sp70[2] = sp7C[2] + sp58[2];
    sp40[1] = sp7C[1] - sp64[1];
    if (mlAbsF(sp40[1]) > 200.0f) {
        sp70[1] = sp64[1] - ((sp40[1] > 0.0f) ? sp30 * (200.0f - sp40[1]) * 2 : sp30 * (-200.0f - sp40[1]) * 2);
    }
    ncDynamicCamera_setPosition(sp70);
    if (func_802BE60C()) {
        func_802BC84C(0);
    }
    func_802BE6FC(sp4C, sp7C);
    func_802BD720(sp4C);
}
