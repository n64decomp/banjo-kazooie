#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

static void __cameraNodeType3_setPitchYawRoll(CameraNodeType3 *this, f32 pitch_yaw_roll[3]);
static void __cameraNodeType3_setFarDistance(CameraNodeType3 *this, f32 far_distance);
static void __cameraNodeType3_setCloseDistance(CameraNodeType3 *this, f32 close_distnace);
static void __cameraNodeType3_setPosition(CameraNodeType3 *this, f32 position[3]);
static void __cameraNodeType3_setHorizontalAndVerticalSpeed(CameraNodeType3 *this, f32 horizontal_speed, f32 vertical_speed);
static void __cameraNodeType3_setRotationAndAccelaration(CameraNodeType3 *this, f32 rotation, f32 accelaration);
static void __code33310_func_802BA510(CameraNodeType3 *this, bool arg1);
static void __code33310_func_802BA530(CameraNodeType3 *this, bool arg1);

/* .code */
static void __code33310_func_802BA2A0(CameraNodeType3 *this, bool arg1, s32 arg2) {
    if(arg1) {
        this->unknownFlag |= arg2;
    }
    else{
        this->unknownFlag &= ~arg2;
    }
}

bool __code33310_func_802BA2D0(CameraNodeType3 *this, s32 arg1) {
    if(this->unknownFlag & arg1)
        return TRUE;
    return FALSE;
}

CameraNodeType3 *cameraNodeType3_init() {
    CameraNodeType3 * this;
    f32 sp20[3];

    this = (CameraNodeType3 *)malloc(sizeof(CameraNodeType3));
    ml_vec3f_clear(sp20);
    __cameraNodeType3_setPosition(this, sp20);
    __cameraNodeType3_setPitchYawRoll(this, sp20);
    __cameraNodeType3_setHorizontalAndVerticalSpeed(this, 2.84f, 5.68f);
    __cameraNodeType3_setRotationAndAccelaration(this, 4.0f, 16.0f);
    __cameraNodeType3_setCloseDistance(this, 1000.0f);
    __cameraNodeType3_setFarDistance(this, 1000.0f);
    __code33310_func_802BA530(this, FALSE);
    __code33310_func_802BA510(this, FALSE);
    return this;
}

void cameraNodeType3_free(CameraNodeType3 *this) {
    free(this);
}

void cameraNodeType3_getPositionWithPitchYawRoll(CameraNodeType3 *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_add(pitch_yaw_roll, this->position, this->pitchYawRoll);
}

static void __cameraNodeType3_setPitchYawRoll(CameraNodeType3 *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_diff_copy(this->pitchYawRoll, pitch_yaw_roll, this->position);
}

f32 cameraNodeType3_getFarDistance(CameraNodeType3 *this) {
    return this->farDistance;
}

static void __cameraNodeType3_setFarDistance(CameraNodeType3 *this, f32 far_distance) {
    this->farDistance = far_distance;
}

f32 cameraNodeType3_getCloseDistance(CameraNodeType3 *this) {
    return this->closeDistance;
}

static void __cameraNodeType3_setCloseDistance(CameraNodeType3 *this, f32 close_distance) {
    this->closeDistance = close_distance;
}

void cameraNodeType3_getPosition(CameraNodeType3 *this, f32 position[3]) {
    ml_vec3f_copy(position, this->position);
}

static void __cameraNodeType3_setPosition(CameraNodeType3 *this, f32 position[3]) {
    ml_vec3f_copy(this->position, position);
}

void cameraNodeType3_getHorizontalAndVerticalSpeed(CameraNodeType3 *this, f32 *horizontal_speed, f32 *vertical_speed) {
    *horizontal_speed = this->horizontalSpeed;
    *vertical_speed = this->verticalSpeed;
}

static void __cameraNodeType3_setHorizontalAndVerticalSpeed(CameraNodeType3 *this, f32 horizontal_speed, f32 vertical_speed) {
    this->horizontalSpeed = horizontal_speed;
    this->verticalSpeed = vertical_speed;
}

void cameraNodeType3_getRotationAndAccelaration(CameraNodeType3 *this, f32 *rotation, f32 *accelaration) {
    *rotation = this->rotation;
    *accelaration = this->accelaration;
}

static void __cameraNodeType3_setRotationAndAccelaration(CameraNodeType3 *this, f32 rotation, f32 accelaration) {
    this->rotation = rotation;
    this->accelaration = accelaration;
}

bool code33310_func_802BA4D0(CameraNodeType3 *this) {
    return __code33310_func_802BA2D0(this, 4);
}

bool code33310_func_802BA4F0(CameraNodeType3 *this) {
    return __code33310_func_802BA2D0(this, 1);
}

static void __code33310_func_802BA510(CameraNodeType3 *this, bool arg1) {
    __code33310_func_802BA2A0(this, arg1, 4);
}

static void __code33310_func_802BA530(CameraNodeType3 *this, bool arg1) {
    __code33310_func_802BA2A0(this, arg1, 1);
}

void cameraNodeType3_fromFile(File *file_ptr, CameraNodeType3 *this) {
    while(!file_isNextByteExpected(file_ptr, 0)) {
        if(!file_getNFloats_ifExpected(file_ptr, 1, this->position, 3)) {
            if(file_isNextByteExpected(file_ptr, 2)) {
                file_getFloat(file_ptr, &this->horizontalSpeed);
                file_getFloat(file_ptr, &this->verticalSpeed);
            }
            else if(file_isNextByteExpected(file_ptr, 3)) {
                file_getFloat(file_ptr, &this->rotation);
                file_getFloat(file_ptr, &this->accelaration);
            }
            else if(file_isNextByteExpected(file_ptr, 6)) {
                file_getFloat(file_ptr, &this->closeDistance);
                file_getFloat(file_ptr, &this->farDistance);
            }
            else{
                if(!file_getNFloats_ifExpected(file_ptr, 4, this->pitchYawRoll, 3)) {
                    file_getWord_ifExpected(file_ptr, 5, &this->unknownFlag);
                }
            }
        }
    }
}
