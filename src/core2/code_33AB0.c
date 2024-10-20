#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

static void __cameraNodeType2_setPosition(CameraNodeType2 *this, f32 position[3]);
static void __cameraNodeType2_setPitchYawRoll(CameraNodeType2 *this, f32 pitch_yaw_roll[3]);

/* .code */
CameraNodeType2 *cameraNodeType2_init() {
    CameraNodeType2 *this;
    f32 sp18[3];

    this = (CameraNodeType2 *)malloc(sizeof(CameraNodeType2));
    ml_vec3f_clear(sp18);
    __cameraNodeType2_setPosition(this, sp18);
    __cameraNodeType2_setPitchYawRoll(this, sp18);
    return this;
}

void cameraNodeType2_free(CameraNodeType2 *this) {
    free(this);
}

void cameraNodeType2_getPosition(CameraNodeType2 *this, f32 position[3]) {
    ml_vec3f_copy(position, this->position);
}

void __cameraNodeType2_setPosition(CameraNodeType2 *this, f32 position[3]) {
    ml_vec3f_copy(this->position, position);
}

void cameraNodeType2_getPitchYawRoll(CameraNodeType2 *this, f32 pitch_yaw_roll[3]) {\
    ml_vec3f_copy(pitch_yaw_roll, this->pitchYawRoll);
}

void __cameraNodeType2_setPitchYawRoll(CameraNodeType2 *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_copy(this->pitchYawRoll, pitch_yaw_roll);
}

void cameraNodeType2_fromFile(File *file_ptr, CameraNodeType2 *this) {
    while(!file_isNextByteExpected(file_ptr, 0)) {
        if(!file_getNFloats_ifExpected(file_ptr, 1, &this->position, 3)) {
            file_getNFloats_ifExpected(file_ptr, 2, &this->pitchYawRoll, 3);
        }
    }
}
