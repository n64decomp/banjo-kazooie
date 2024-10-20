#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern void func_802BD780(f32[3], f32[3], f32, f32, f32, f32);

void ncFirstPersonCamera_setState(enum nc_first_person_state state);

/* .bss */
struct{
    f32 position[3]; //first_person_position
    f32 rotation[3];
    f32 zoomed_in_position[3];
    f32 zoomed_in_rotation[3];
    f32 zoomed_out_position[3];
    f32 zoomed_out_rotation[3];
    f32 transistion_timer;
    u8 state;
} D_8037DC60;

/* .code */
bool __ncFirstPersonCamera_fullyZoomedIn(void) {
    return (ml_vec3f_distance(D_8037DC60.position, D_8037DC60.zoomed_in_position) < 40.0f);
}

void __ncFirstPersonCamera_getPositionAndRotation_entering(f32 arg0[3], f32 arg1[3]) {
    s32 i;

    ml_sub_delta_time(&D_8037DC60.transistion_timer);
    for( i = 0; i<3; i++){
        D_8037DC60.position[i] = func_80257CF8(D_8037DC60.transistion_timer, 1.0f, 0.0f, D_8037DC60.zoomed_out_position[i], D_8037DC60.zoomed_in_position[i]);
        D_8037DC60.rotation[i] = mlNormalizeAngle(D_8037DC60.zoomed_out_rotation[i] + func_80257CF8(D_8037DC60.transistion_timer, 0.5f, 0.0f, 0.0f, mlDiffDegF(D_8037DC60.zoomed_in_rotation[i], D_8037DC60.zoomed_out_rotation[i])));
    }
    if (D_8037DC60.transistion_timer == 0.0f) {
        ncFirstPersonCamera_setState(FIRSTPERSON_STATE_2_IDLE);
    }
    if (__ncFirstPersonCamera_fullyZoomedIn() && func_8028F150()) {
        func_8028FCC8(0);
    }
    ml_vec3f_copy(arg0, D_8037DC60.position);
    ml_vec3f_copy(arg1, D_8037DC60.rotation);
}


void __ncFirstPersonCamera_getPositionAndRotation_exiting(f32 arg0[3], f32 arg1[3]) {
    s32 i;

    ml_sub_delta_time(&D_8037DC60.transistion_timer);
    for( i = 0; i<3; i++){
        D_8037DC60.position[i] = func_80257CF8(D_8037DC60.transistion_timer, 1.0f, 0.0f, D_8037DC60.zoomed_in_position[i], arg0[i]);
        D_8037DC60.rotation[i] = mlNormalizeAngle(D_8037DC60.zoomed_in_rotation[i] + func_80257CF8(D_8037DC60.transistion_timer, 1.0f, 0.5f, 0.0f, mlDiffDegF(arg1[i], D_8037DC60.zoomed_in_rotation[i])));
    }
    if (D_8037DC60.transistion_timer == 0.0f) {
        ncFirstPersonCamera_setState(FIRSTPERSON_STATE_4_DONE);
    }
    if (!__ncFirstPersonCamera_fullyZoomedIn() && !func_8028F150()) {
        func_8028FCC8(1);
    }
    ml_vec3f_copy(arg0, D_8037DC60.position);
    ml_vec3f_copy(arg1, D_8037DC60.rotation);
}


void __ncFirstPersonCamera_getPositionAndRotation_idle(f32 arg0[3], f32 arg1[3]) {
    ml_vec3f_copy(D_8037DC60.position, D_8037DC60.zoomed_in_position);
    func_802BD780(D_8037DC60.zoomed_in_rotation, D_8037DC60.rotation, 10.0f, 20.0f, 120.0f, 200.0f);
    D_8037DC60.rotation[2] = 0.0f;
    ml_vec3f_copy(arg0, D_8037DC60.position);
    ml_vec3f_copy(arg1, D_8037DC60.rotation);
}

void ncFirstPersonCamera_reset(void){
    ml_vec3f_clear(D_8037DC60.position);
    ml_vec3f_clear(D_8037DC60.rotation);
    ml_vec3f_clear(D_8037DC60.zoomed_in_position);
    ml_vec3f_clear(D_8037DC60.zoomed_in_rotation);
    ml_vec3f_clear(D_8037DC60.zoomed_out_position);
    ml_vec3f_clear(D_8037DC60.zoomed_out_rotation);
    D_8037DC60.state = 0;
}

void ncFirstPersonCamera_getPositionAndRotation(f32 position[3], f32 rotation[3]) {
    switch (D_8037DC60.state) {
    case FIRSTPERSON_STATE_1_ENTER:
        __ncFirstPersonCamera_getPositionAndRotation_entering(position, rotation);
        break;
    case FIRSTPERSON_STATE_2_IDLE:
        __ncFirstPersonCamera_getPositionAndRotation_idle(position, rotation);
        break;
    case FIRSTPERSON_STATE_3_EXIT:
        __ncFirstPersonCamera_getPositionAndRotation_exiting(position, rotation);
        /* fallthrough */
    case FIRSTPERSON_STATE_4_DONE:
        break;
    }
}

void ncFirstPersonCamera_setState(enum nc_first_person_state next_state) {
    if (next_state == FIRSTPERSON_STATE_1_ENTER) {
        if (D_8037DC60.state == FIRSTPERSON_STATE_3_EXIT) {
            ml_vec3f_copy(D_8037DC60.zoomed_out_position, D_8037DC60.position);
            ml_vec3f_copy(D_8037DC60.zoomed_out_rotation, D_8037DC60.rotation);
        } else {
            ncDynamicCamera_getPosition(D_8037DC60.position);
            ncDynamicCamera_getRotation(D_8037DC60.rotation);
            ncDynamicCamera_getPosition(D_8037DC60.zoomed_out_position);
            ncDynamicCamera_getRotation(D_8037DC60.zoomed_out_rotation);
        }
        D_8037DC60.transistion_timer = 1.0f;
    }
    if (next_state == FIRSTPERSON_STATE_3_EXIT) {
        D_8037DC60.transistion_timer = 1.0f;
    }
    D_8037DC60.state = next_state;
}

void ncFirstPersonCamera_setZoomedOutPosition(f32 src[3]){
    ml_vec3f_copy(D_8037DC60.zoomed_in_position, src);
}

void ncFirstPersonCamera_setZoomedOutRotation(f32 src[3]){
    D_8037DC60.zoomed_in_rotation[0] = mlNormalizeAngle(src[0]);
    D_8037DC60.zoomed_in_rotation[1] = mlNormalizeAngle(src[1]);
    D_8037DC60.zoomed_in_rotation[2] = mlNormalizeAngle(src[2]);
}

void ncFirstPersonCamera_getZoomedInRotation(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037DC60.zoomed_in_rotation);
}

s32 ncFirstPersonCamera_getState(void){
    return D_8037DC60.state;
}
