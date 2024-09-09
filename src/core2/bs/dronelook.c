#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"

extern f32 func_8029B2D0(void);

/* .code */
void __bsDroneLook_getEyePos(f32 arg0[3]) {
    func_8028E9C4(5, arg0);
}

void bsDroneLook_init(void) {
    f32 anim_duration;
    f32 eye_position[3];
    f32 eye_rotation[3];
    enum asset_e anim_id;

    func_80299D2C(SFX_12D_CAMERA_ZOOM_CLOSEST, 1.2f, 12000);
    func_8029BCF8(&anim_id, &anim_duration);
    baanim_playForDuration_loopSmooth(anim_id, anim_duration);
    func_8029C7F4(1, 1, 3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    baphysics_set_velocity(0);
    ncDynamicCamera_enterFirstPerson();
    __bsDroneLook_getEyePos(eye_position);
    ncFirstPersonCamera_setZoomedOutPosition(eye_position);
    player_getRotation(eye_rotation);
    eye_rotation[0] = 0.0f;
    eye_rotation[1] += 180.0f;
    eye_rotation[2] = 0.0f;
    ncFirstPersonCamera_setZoomedOutRotation(eye_rotation);
    miscFlag_set(MISC_FLAG_17_FIRST_PERSON_VIEW);
}

void bsDroneLook_update(void) {
    s32 next_state;
    f32 eye_rotation[3];
    f32 eye_position[3];
    f32 dt;
    s32 exit_first_person;

    next_state = 0;
    dt = time_getDelta();
    if (ncFirstPersonCamera_getState() == FIRSTPERSON_STATE_2_IDLE) {
        //camera is in "idle" state
        ncFirstPersonCamera_getZoomedInRotation(eye_rotation);
        eye_rotation[0] -= func_8029B2DC() * 90.0f * dt;
        eye_rotation[1] -= func_8029B2D0() * 90.0f * dt;
        eye_rotation[2] = 0.0f;
        eye_rotation[0] = (eye_rotation[0] > 180.0f) ? ml_max_f(305.0f, eye_rotation[0]) : ml_min_f(70.0f, eye_rotation[0]);
        ncFirstPersonCamera_setZoomedOutRotation(eye_rotation);
        yaw_setIdeal(eye_rotation[1] + 180.0f);

        exit_first_person = FALSE;
        // 1st person cancelled via input
        if (button_pressed(BUTTON_B) || button_pressed(BUTTON_A) || button_pressed(BUTTON_C_UP)) {
            exit_first_person = TRUE;
        }
        // 1st person cancelled via entering water
        if (player_inWater()) {
            if (player_getTransformation() == TRANSFORM_1_BANJO && player_getWaterState() == BSWATERGROUP_0_NONE) {
                exit_first_person += TRUE;
            }
        } else if (func_8028B254(25) == 0) {
            exit_first_person += TRUE;
        }
        if (exit_first_person) {
            next_state = func_8029BDBC();
        }
    }
    __bsDroneLook_getEyePos(eye_position);
    ncFirstPersonCamera_setZoomedOutPosition(eye_position);
    bs_setState(next_state);
}

void bsDroneLook_end(void) {
    if (func_80298850() == 0) {
        func_80299D2C(SFX_12E_CAMERA_ZOOM_MEDIUM, 1.2f, 12000);
    }
    ncDynamicCamera_exitFirstPerson();
    miscFlag_clear(MISC_FLAG_17_FIRST_PERSON_VIEW);
}
