#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 player_getYaw(void);
extern f32 player_getPitch(void);
extern void func_802BD870(f32, f32, f32, f32);

void ncDynamicCam4_func_802BFE50(f32 arg0, f32 arg1, f32 arg2);
void ncDynamicCam4_func_802BFE74(bool);

/* .bss */
f32 D_8037DB10;
f32 D_8037DB14;
f32 D_8037DB18;
f32 D_8037DB1C;
f32 D_8037DB20;

/* .code */
void ncDynamicCam4_init(void) {
    func_802BD870(10.0f, 20.0f, 120.0f, 200.0f);
    if (map_get() == MAP_90_GL_BATTLEMENTS) {
        ncDynamicCam4_func_802BFE50(10.0f, 800.0f, 1350.0f);
    } else {
        ncDynamicCam4_func_802BFE50(2.0f, 800.0f, 350.0f);
    }
    ncDynamicCam4_func_802BFE74(0);
}

void ncDynamicCam4_end(void){}

void ncDynamicCam4_update(void) {
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 temp_f10;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    ncDynamicCamera_getPosition(sp6C);
    func_802BD4C0(sp84);
    sp84[1] += 40.0f;
    sp34 = player_getPitch();
    if (sp34 > 180.0f) {
        sp3C = ml_map_f(sp34, 300.0f, 360.0f, 900.0f, D_8037DB18);
        sp84[1] += ml_map_f(sp34, 300.0f, 360.0f, -140.0f, 70.0f);
    } else {
        sp3C = D_8037DB18;
        sp84[1] += 70.0f;
    }
    sp38 = time_getDelta();
    ml_vec3f_diff_copy(sp48, sp6C, sp84);
    sp44 = gu_sqrtf(sp48[0]*sp48[0] + sp48[1]*sp48[1] +  sp48[2]*sp48[2]);
    temp_f10 = (sp3C - sp44) * sp38;
    sp44 += func_80259198(temp_f10 * D_8037DB10, sp38 * D_8037DB14);
    func_8025727C(sp84[0], sp84[1], sp84[2], sp6C[0], sp6C[1], sp6C[2], &sp54[0], &sp54[1]);
    if ((sp34 > 180.0f) && (sp34 < 360.0f)) {
        sp34 = ml_min_f(100.0f, (f32) ((f64) (360.0f - sp34) * 1.4));
    }
    sp48[0] = mlDiffDegF(mlNormalizeAngle(sp34), sp54[0]);
    sp48[1] = mlDiffDegF(mlNormalizeAngle(player_getYaw() + 180.0f), sp54[1]);
    sp48[2] = 0.0f;
    sp48[0] = (f32) ((f64) sp48[0] * ((f64) sp38 * 0.8));
    sp48[1] = sp48[1] * (sp38 * D_8037DB1C);
    sp48[0] = func_80259198(sp48[0], sp38 * 40.0f);
    sp48[1] = func_80259198(sp48[1], sp38 * D_8037DB20);
    sp54[0] = mlNormalizeAngle(sp54[0] + sp48[0]);
    sp54[1] = mlNormalizeAngle(sp54[1] + sp48[1]);

    func_80256E24(sp60, -sp54[0], sp54[1], 0.0f, 0.0f, sp44);
    ml_vec3f_add(sp78, sp84, sp60);
    ncDynamicCamera_setPosition(sp78);
    func_8025727C(sp84[0], sp84[1], sp84[2], sp78[0], sp78[1], sp78[2], &sp54[0], &sp54[1]);
    sp54[0] = -sp54[0];
    sp54[2] = 0.0f;
    func_802BD720(sp54);
}

void ncDynamicCam4_func_802BFE50(f32 arg0, f32 arg1, f32 arg2){
    D_8037DB10 = arg0;
    D_8037DB14 = arg1;
    D_8037DB18 = arg2;
}

void ncDynamicCam4_func_802BFE74(bool arg0) {
    if (arg0) {
        D_8037DB1C = 6.0f;
        D_8037DB20 = 270.0f;
    }
    else{
        D_8037DB1C = 2.0f;
        D_8037DB20 = 90.0f;
    }
}
