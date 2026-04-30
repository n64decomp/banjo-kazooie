#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

static void __cameraNodeType2_setPosition(StaticCameraNode *this, f32 position[3]);
static void __cameraNodeType2_setPitchYawRoll(StaticCameraNode *this, f32 pitch_yaw_roll[3]);

#define STATIC_CAMERA_POSITION_INDICATOR    0x01
#define STATIC_CAMERA_ROTATION_INDICATOR    0x02
#define STATIC_CAMERA_END_INDICATOR         0x00

/* .code */
StaticCameraNode *cameraNodeType2_init() {
    StaticCameraNode *this;
    f32 sp18[3];

    this = (StaticCameraNode *)malloc(sizeof(StaticCameraNode));
    ml_vec3f_clear(sp18);
    __cameraNodeType2_setPosition(this, sp18);
    __cameraNodeType2_setPitchYawRoll(this, sp18);
    return this;
}

void cameraNodeType2_free(StaticCameraNode *this) {
    free(this);
}

void cameraNodeType2_getPosition(StaticCameraNode *this, f32 position[3]) {
    ml_vec3f_copy(position, this->position);
}

void __cameraNodeType2_setPosition(StaticCameraNode *this, f32 position[3]) {
    ml_vec3f_copy(this->position, position);
}

void cameraNodeType2_getPitchYawRoll(StaticCameraNode *this, f32 pitch_yaw_roll[3]) {\
    ml_vec3f_copy(pitch_yaw_roll, this->pitchYawRoll);
}

void __cameraNodeType2_setPitchYawRoll(StaticCameraNode *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_copy(this->pitchYawRoll, pitch_yaw_roll);
}

void cameraNodeType2_fromFile(File *file_ptr, StaticCameraNode *this) {
    while(!file_isNextByteExpected(file_ptr, STATIC_CAMERA_END_INDICATOR)) {
        if(!file_getNFloats_ifExpected(file_ptr, STATIC_CAMERA_POSITION_INDICATOR, &this->position, 3)) {
            file_getNFloats_ifExpected(file_ptr, STATIC_CAMERA_ROTATION_INDICATOR, &this->pitchYawRoll, 3);
        }
    }
}
