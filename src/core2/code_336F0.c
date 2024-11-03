#include <ultra64.h>

#include <core2/file.h>

#include "functions.h"
#include "variables.h"
#include <core2/camera.h>


static void __cameraNodeType1_setPosition(CameraNodeType1 *this, f32 position[3]);
static void __cameraNodeType1_func_802BA808(CameraNodeType1 *this, f32 arg1[3]);
static void __cameraNodeType1_setHorizontalAndVerticalSpeed(CameraNodeType1 *this, f32 horizontal_speed, f32 vertical_speed);
static void __cameraNodeType1_setRotationAndAccelaration(CameraNodeType1 *this, f32 rotation, f32 accelaration);
static void __code336F0_func_802BA8DC(CameraNodeType1 *this, s32 arg1);
static void __code336F0_func_802BA8FC(CameraNodeType1 *this, s32 arg1);
static void __code336F0_func_802BA91C(CameraNodeType1 *this, s32 arg1);

static void __code336F0_func_802BA680(CameraNodeType1 *this, s32 arg1, s32 arg2) {
    if(arg1) {
        this->unknownFlag |= arg2;
    } else{
        this->unknownFlag &= ~arg2;
    }
}

static bool __code336F0_func_802BA6B0(CameraNodeType1 *this, s32 arg1) {
    if (this->unknownFlag & arg1) 
        return TRUE;

    return FALSE;
}

CameraNodeType1 *cameraNodeType1_init() {
    CameraNodeType1 *this;
    f32 sp20[3];

    this = (CameraNodeType1 *)malloc(sizeof(CameraNodeType1));
    ml_vec3f_clear(sp20);
    __cameraNodeType1_setPosition(this, sp20);
    __cameraNodeType1_func_802BA808(this, sp20);
    __cameraNodeType1_setHorizontalAndVerticalSpeed(this, 0.7f, 2.33f);
    __cameraNodeType1_setRotationAndAccelaration(this, 4.0f, 16.0f);
    __code336F0_func_802BA8DC(this, 0);
    __code336F0_func_802BA91C(this, 1);
    __code336F0_func_802BA8FC(this, 0);
    return this;
}

void cameraNodeType1_free(CameraNodeType1 *this) {
    free(this);
}

void cameraNodeType1_getPosition(CameraNodeType1 *this, f32 position[3]) {
    ml_vec3f_copy(position, this->position);
}

static void __cameraNodeType1_setPosition(CameraNodeType1 *this, f32 position[3]) {
    ml_vec3f_copy(this->position, position);
}

void code336F0_func_802BA7D8(CameraNodeType1 *this, f32 arg1[3]) {
    ml_vec3f_add(arg1, this->position, this->pitchYawRoll);
}

static void __cameraNodeType1_func_802BA808(CameraNodeType1 *this, f32 arg1[3]) {
    ml_vec3f_diff_copy(this->pitchYawRoll, arg1, this->position);
}

void cameraNodeType1_getHorizontalAndVerticalSpeed(CameraNodeType1 *this, f32 *horizontal_speed, f32 *vertical_speed) {
    *horizontal_speed = this->horizontalSpeed;
    *vertical_speed = this->verticalSpeed;
}

static void __cameraNodeType1_setHorizontalAndVerticalSpeed(CameraNodeType1 *this, f32 horizontal_speed, f32 vertical_speed) {
    this->horizontalSpeed = horizontal_speed;
    this->verticalSpeed = vertical_speed;
}

void cameraNodeType1_getRotationAndAccelaration(CameraNodeType1 *this, f32 *rotation, f32 *accelaration) {
    *rotation = this->rotation;
    *accelaration = this->accelaration;
}

static void __cameraNodeType1_setRotationAndAccelaration(CameraNodeType1 *this, f32 rotation, f32 accelaration) {
    this->rotation = rotation;
    this->accelaration = accelaration;
}

bool code336F0_func_802BA87C(CameraNodeType1 *this) {
    return __code336F0_func_802BA6B0(this, 0x1);
}

bool code336F0_func_802BA89C(CameraNodeType1 *this) {
    return __code336F0_func_802BA6B0(this, 0x4);
}

bool code336F0_func_802BA8BC(CameraNodeType1 *this) {
    return __code336F0_func_802BA6B0(this, 0x2);
}

static void __code336F0_func_802BA8DC(CameraNodeType1 *this, s32 arg1) {
    __code336F0_func_802BA680(this, arg1, 0x1);
}

static void __code336F0_func_802BA8FC(CameraNodeType1 *this, s32 arg1) {
    __code336F0_func_802BA680(this, arg1, 0x4);
}

static void __code336F0_func_802BA91C(CameraNodeType1 *this, s32 arg1) {
    __code336F0_func_802BA680(this, arg1, 0x2);
}

void cameraNodeType1_fromFile(File *file_ptr, CameraNodeType1 *this) {
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
            else if(!file_getNFloats_ifExpected(file_ptr, 4, this->pitchYawRoll, 3)) {
                file_getWord_ifExpected(file_ptr, 5, &this->unknownFlag);
            }
        }
    }
}
