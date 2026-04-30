#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>
#include <core2/camera.h>

static void __cameraNodeType3_setPitchYawRoll(ZoomCameraNode *this, f32 pitch_yaw_roll[3]);
static void __cameraNodeType3_setFarDistance(ZoomCameraNode *this, f32 far_distance);
static void __cameraNodeType3_setCloseDistance(ZoomCameraNode *this, f32 close_distnace);
static void __cameraNodeType3_setPosition(ZoomCameraNode *this, f32 position[3]);
static void __cameraNodeType3_setHorizontalAndVerticalSpeed(ZoomCameraNode *this, f32 horizontal_speed, f32 vertical_speed);
static void __cameraNodeType3_setRotationAndAccelaration(ZoomCameraNode *this, f32 rotation, f32 accelaration);
static void __code33310_func_802BA510(ZoomCameraNode *this, bool arg1);
static void __code33310_func_802BA530(ZoomCameraNode *this, bool arg1);

#define ZOOM_CAMERA_POSITION_INDICATOR          0x01
#define ZOOM_CAMERA_HORI_VERT_SPEED_INDICATOR   0x02
#define ZOOM_CAMERA_TURN_SPEED_INDICATOR        0x03
#define ZOOM_CAMERA_ROTATION_INDICATOR          0x04
#define ZOOM_CAMERA_UNK_5_INDICATOR             0x05
#define ZOOM_CAMERA_DISTANCE_INDICATOR          0x06
#define ZOOM_CAMERA_END_INDICATOR               0x00

/* .code */
static void __code33310_func_802BA2A0(ZoomCameraNode *this, bool arg1, s32 arg2) {
    if(arg1) {
        this->unknownFlag |= arg2;
    }
    else{
        this->unknownFlag &= ~arg2;
    }
}

bool __code33310_func_802BA2D0(ZoomCameraNode *this, s32 arg1) {
    if(this->unknownFlag & arg1)
        return TRUE;
    return FALSE;
}

ZoomCameraNode *cameraNodeType3_init() {
    ZoomCameraNode * this;
    f32 sp20[3];

    this = (ZoomCameraNode *)malloc(sizeof(ZoomCameraNode));
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

void cameraNodeType3_free(ZoomCameraNode *this) {
    free(this);
}

void cameraNodeType3_getPositionWithPitchYawRoll(ZoomCameraNode *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_add(pitch_yaw_roll, this->position, this->pitchYawRoll);
}

static void __cameraNodeType3_setPitchYawRoll(ZoomCameraNode *this, f32 pitch_yaw_roll[3]) {
    ml_vec3f_diff_copy(this->pitchYawRoll, pitch_yaw_roll, this->position);
}

f32 cameraNodeType3_getFarDistance(ZoomCameraNode *this) {
    return this->farDistance;
}

static void __cameraNodeType3_setFarDistance(ZoomCameraNode *this, f32 far_distance) {
    this->farDistance = far_distance;
}

f32 cameraNodeType3_getCloseDistance(ZoomCameraNode *this) {
    return this->closeDistance;
}

static void __cameraNodeType3_setCloseDistance(ZoomCameraNode *this, f32 close_distance) {
    this->closeDistance = close_distance;
}

void cameraNodeType3_getPosition(ZoomCameraNode *this, f32 position[3]) {
    ml_vec3f_copy(position, this->position);
}

static void __cameraNodeType3_setPosition(ZoomCameraNode *this, f32 position[3]) {
    ml_vec3f_copy(this->position, position);
}

void cameraNodeType3_getHorizontalAndVerticalSpeed(ZoomCameraNode *this, f32 *horizontal_speed, f32 *vertical_speed) {
    *horizontal_speed = this->horizontalSpeed;
    *vertical_speed = this->verticalSpeed;
}

static void __cameraNodeType3_setHorizontalAndVerticalSpeed(ZoomCameraNode *this, f32 horizontal_speed, f32 vertical_speed) {
    this->horizontalSpeed = horizontal_speed;
    this->verticalSpeed = vertical_speed;
}

void cameraNodeType3_getRotationAndAccelaration(ZoomCameraNode *this, f32 *rotation, f32 *accelaration) {
    *rotation = this->rotation;
    *accelaration = this->accelaration;
}

static void __cameraNodeType3_setRotationAndAccelaration(ZoomCameraNode *this, f32 rotation, f32 accelaration) {
    this->rotation = rotation;
    this->accelaration = accelaration;
}

bool code33310_func_802BA4D0(ZoomCameraNode *this) {
    return __code33310_func_802BA2D0(this, 4);
}

bool code33310_func_802BA4F0(ZoomCameraNode *this) {
    return __code33310_func_802BA2D0(this, 1);
}

static void __code33310_func_802BA510(ZoomCameraNode *this, bool arg1) {
    __code33310_func_802BA2A0(this, arg1, 4);
}

static void __code33310_func_802BA530(ZoomCameraNode *this, bool arg1) {
    __code33310_func_802BA2A0(this, arg1, 1);
}

void cameraNodeType3_fromFile(File *file_ptr, ZoomCameraNode *this) {
    while(!file_isNextByteExpected(file_ptr, ZOOM_CAMERA_END_INDICATOR)) {
        if(!file_getNFloats_ifExpected(file_ptr, ZOOM_CAMERA_POSITION_INDICATOR, this->position, 3)) {
            if(file_isNextByteExpected(file_ptr, ZOOM_CAMERA_HORI_VERT_SPEED_INDICATOR)) {
                file_getFloat(file_ptr, &this->horizontalSpeed);
                file_getFloat(file_ptr, &this->verticalSpeed);
            }
            else if(file_isNextByteExpected(file_ptr, ZOOM_CAMERA_TURN_SPEED_INDICATOR)) {
                file_getFloat(file_ptr, &this->rotation);
                file_getFloat(file_ptr, &this->accelaration);
            }
            else if(file_isNextByteExpected(file_ptr, ZOOM_CAMERA_DISTANCE_INDICATOR)) {
                file_getFloat(file_ptr, &this->closeDistance);
                file_getFloat(file_ptr, &this->farDistance);
            }
            else{
                if(!file_getNFloats_ifExpected(file_ptr, ZOOM_CAMERA_ROTATION_INDICATOR, this->pitchYawRoll, 3)) {
                    file_getWord_ifExpected(file_ptr, ZOOM_CAMERA_UNK_5_INDICATOR, &this->unknownFlag);
                }
            }
        }
    }
}
