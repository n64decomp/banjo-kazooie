#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"

// all functions in this file are unsued

void stub_802409C0(f32 position[3], f32 speed);
void stub_80240A74(f32 position[3]);
f32 stub_80240A94(s32 time_out, f32 arg1);
void stub_80240AC8(f32 position[3], f32 speed);

static s32 sTimeout = 0;

void stub_802409C0(f32 position[3], f32 speed) {
    f32 vp_rotation[3];
    f32 delta_position[3];
    f32 joystick_data[2];
    f32 dt;
    
    dt = time_getDelta() * speed;
    controller_getJoystick(0, joystick_data);

    delta_position[0] = joystick_data[0] * dt;
    delta_position[1] = 0.0f;
    delta_position[2] = -(joystick_data[1] * dt);

    viewport_getRotation_vec3f(vp_rotation);
    ml_vec3f_yaw_rotate_copy(delta_position, delta_position, vp_rotation[1]);

    position[0] = position[0] + delta_position[0];
    position[1] = position[1] + delta_position[1];
    position[2] = position[2] + delta_position[2];
}

void stub_80240A74(f32 position[3]) {
    stub_802409C0(position, 400.0f);
}

f32 stub_80240A94(s32 time_out, f32 delta_time) {
    if (time_out > 40)
        time_out = 40;

    return delta_time + (f32) time_out * delta_time / 16;
}

void stub_80240AC8(f32 position[3], f32 speed) {
    f32 vp_rotation[3];
    f32 delta_position[3];
    f32 joystick_data[2];
    f32 dt;
    
    dt = time_getDelta() * speed;
    controller_getJoystick(0, joystick_data);

    if (0.0f != joystick_data[0] || 0.0f != joystick_data[1]) {
        sTimeout++;
        if (sTimeout > 300) 
            sTimeout = 300;
    } else {
        sTimeout = 1;
    }

    dt = stub_80240A94(sTimeout, dt);

    delta_position[0] = joystick_data[0] * dt;
    delta_position[1] = 0.0f;
    delta_position[2] = -(joystick_data[1] * dt);

    viewport_getRotation_vec3f(vp_rotation);
    ml_vec3f_yaw_rotate_copy(delta_position, delta_position, vp_rotation[1]);

    position[0] = position[0] + delta_position[0];
    position[1] = position[1] + delta_position[1];
    position[2] = position[2] + delta_position[2];
}
