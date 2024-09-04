#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80259198(f32, f32);
extern f32 func_802BD51C(void);
extern f32 player_getYaw(void);
extern void func_802BD870(f32, f32, f32, f32);

void ncDynamicCam1_init(void){
    func_802BD870(12.0f, 10.0f, 120.0f, 120.0f);
}

void ncDynamicCam1_end(void){}

void ncDynamicCam1_update(void) {
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp4C;
    f32 sp48;
    f32 temp_f20;
    f32 sp40;
    f32 sp3C;

    ncDynamicCamera_getPosition(sp74);
    func_802BD4C0(sp8C);
    sp3C = func_802BD8D4();
    temp_f20 = time_getDelta();
    ml_vec3f_diff_copy(sp50, sp74, sp8C);
    sp4C = gu_sqrtf((sp50[0] * sp50[0]) + (sp50[2] * sp50[2]));
    sp4C += func_80259198((sp3C - sp4C) * temp_f20 * 2, temp_f20 * 120.0f);
    func_8025801C(sp50, &sp48);
    sp40 = func_80259198(mlDiffDegF(mlNormalizeAngle(180.0f + player_getYaw()), sp48) * (temp_f20 * 1), temp_f20 * 50.0f);
    sp48 = mlNormalizeAngle(sp48 + sp40);
    func_80256E24(sp68, 0.0f, sp48, 0.0f, 0.0f, sp4C);
    ml_vec3f_add(sp80, sp8C, sp68);
    sp80[1] = sp74[1] + ((func_802BD51C() - sp74[1]) * temp_f20 * 2);
    ncDynamicCamera_setPosition(sp80);
    func_8025727C(sp8C[0], sp8C[1], sp8C[2], sp80[0], sp80[1], sp80[2], &sp5C[0], &sp5C[1]);
    sp5C[0] = -sp5C[0];
    sp5C[2] = 0.0f;
    func_802BD720(sp5C);
}
