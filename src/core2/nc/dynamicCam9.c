#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80259198(f32, f32);
extern void func_802BD870(f32, f32, f32, f32);

/* .bss */
f32 D_8037DBB0[3];
f32 D_8037DBBC;
f32 D_8037DBC0;
f32 D_8037DBC8[3];

/* .code */
void ncDynamicCam9_init(void) {
    func_802BD870(6.0f, 10.0f, 50.0f, 120.0f);
    ncDynamicCamera_getPosition(D_8037DBC8);
}

void ncDynamicCam9_end(void){}

f32 ncDynamicCam9_func_802C09E8(void) {
    f32 d_pos[3];
    f32 player_position[3];

    player_getPosition(player_position);
    d_pos[0] = D_8037DBB0[0] - player_position[0];
    d_pos[1] = 0.0f;
    d_pos[2] = D_8037DBB0[2] - player_position[2];
    return ml_min_f(gu_sqrtf(d_pos[0]*d_pos[0] + d_pos[2]*d_pos[2]), D_8037DBBC) / D_8037DBBC;
}

void ncDynamicCam9_func_802C0A60(f32 arg0[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];

    func_802BD4C0(sp54);
    func_8025727C(sp54[0], sp54[1], sp54[2], D_8037DBB0[0], D_8037DBB0[1], D_8037DBB0[2], &sp30[0], &sp30[1]);
    sp30[1] = mlNormalizeAngle(sp30[1] - 60.0f);
    func_80256E24(sp48, 0.0f, sp30[1], 0.0f, 0.0f, D_8037DBC0);
    ml_vec3f_add(arg0, D_8037DBB0, sp48);
    ml_vec3f_diff_copy(sp3C, sp54, D_8037DBB0);
    ml_vec3f_scale(sp3C, 0.3f);
    arg0[0] += sp3C[0];
    arg0[1] += sp3C[1];
    arg0[2] += sp3C[2];
}

void ncDynamicCam9_func_802C0B70(f32 arg0[3], f32 arg1[3]) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 dt;

    dt = time_getDelta();
    ncDynamicCamera_getPosition(sp30);
    ml_vec3f_diff_copy(sp3C, arg1, sp30);
    sp3C[0] *= dt * 1.5;
    sp3C[1] *= dt * 1.0;
    sp3C[2] *= dt * 1.5;
    sp3C[0] = func_80259198(sp3C[0], dt * 1000.0);
    sp3C[1] = func_80259198(sp3C[1], dt * 1000.0);
    sp3C[2] = func_80259198(sp3C[2], dt * 1000.0);
    ml_vec3f_add(arg0, sp30, sp3C);
    ncDynamicCamera_setPosition(arg0);
}

void ncDynamicCam9_func_802C0C5C(f32 arg0[3], f32 arg1[3]) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp38;
    f32 temp_f14;

    sp38 = ncDynamicCam9_func_802C09E8();
    func_802BD4C0(sp48);
    ml_vec3f_diff_copy(sp3C, sp48, D_8037DBB0);
    ml_vec3f_scale(sp3C, ml_map_f(sp38, 0.4f, 0.75f, 0.5f, 1.0f));
    ml_vec3f_add(sp54, D_8037DBB0, sp3C);
    sp54[1] = sp48[1] + (sp54[1] - sp48[1]) * 0.4;
    func_8025727C(sp54[0], sp54[1], sp54[2], arg1[0], arg1[1], arg1[2], &arg0[0], &arg0[1]);
    arg0[0] = mlNormalizeAngle(-arg0[0]);
    arg0[2] = 0.0f;
}

void ncDynamicCam9_update(void) {
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];
    f32 temp_f0;

    ncDynamicCamera_getPosition(sp44);
    ncDynamicCamera_getRotation(sp38);
    if (ncDynamicCam9_func_802C09E8() > 0.25){
        ncDynamicCam9_func_802C0A60(sp2C);
        ncDynamicCam9_func_802C0C5C(sp20, sp2C);
        temp_f0 = mlNormalizeAngle(sp20[1] - sp38[1]);
        if((temp_f0 > 200.0f) || (temp_f0 < 160.0f)) {
            ml_vec3f_copy(D_8037DBC8, sp2C);
        }
    }
    ncDynamicCam9_func_802C0B70(sp2C, D_8037DBC8);
    ncDynamicCam9_func_802C0C5C(sp20, sp2C);
    func_802BD720(sp20);
}

void ncDynamicCam9_func_802C0E38(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4){
    D_8037DBB0[0] = arg0;
    D_8037DBB0[1] = arg1;
    D_8037DBB0[2] = arg2;
    D_8037DBBC = arg3;
    D_8037DBC0 = arg4;
}
