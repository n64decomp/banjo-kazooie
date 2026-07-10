#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802BD51C(void);
extern f32 player_getYaw(void);
extern void func_802BD870(f32, f32, f32, f32);

void ncDynamicCam1_init(void){
    func_802BD870(12.0f, 10.0f, 120.0f, 120.0f);
}

void ncDynamicCam1_end(void){}

void ncDynamicCam1_update(void) {
    f32 sp8C[3];
    f32 new_camera_position[3];
    f32 current_camera_position[3];
    f32 dst[3];
    f32 angles[3];
    f32 sp50[3];
    f32 position_z;
    f32 phi;
    f32 time_delta;
    f32 sp40;
    f32 sp3C;

    ncDynamicCamera_getPosition(current_camera_position);
    func_802BD4C0(sp8C);
    sp3C = func_802BD8D4();
    time_delta = time_getDelta();
    ml_vec3f_diff_copy(sp50, current_camera_position, sp8C);
    position_z = sqrtf((sp50[0] * sp50[0]) + (sp50[2] * sp50[2]));
    position_z += ml_clamp_abs_f((sp3C - position_z) * time_delta * 2, time_delta * 120.0f);
    func_8025801C(sp50, &phi);
    sp40 = ml_clamp_abs_f(mlDiffDegF(mlNormalizeAngle(180.0f + player_getYaw()), phi) * (time_delta * 1), time_delta * 50.0f);
    phi = mlNormalizeAngle(phi + sp40);
    func_80256E24(dst, 0.0f, phi, 0.0f, 0.0f, position_z);
    ml_vec3f_add(new_camera_position, sp8C, dst);
    new_camera_position[1] = current_camera_position[1] + ((func_802BD51C() - current_camera_position[1]) * time_delta * 2);
    ncDynamicCamera_setPosition(new_camera_position);
    ml_horizontal_and_vertical_angles(
        sp8C[0], sp8C[1], sp8C[2],
        new_camera_position[0], new_camera_position[1], new_camera_position[2],
        &angles[0], &angles[1]);
    angles[0] = -angles[0];
    angles[2] = 0.0f;
    func_802BD720(angles);
}
