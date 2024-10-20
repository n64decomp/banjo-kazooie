#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <ultratypes.h>
#include <core2/file.h>

typedef struct {
    s32 type: 24;
    s32 valid: 8;
    s32 data_ptr;
} CameraNode;

typedef struct {
    f32 position[3];
    f32 horizontalSpeed;
    f32 verticalSpeed;
    f32 rotation;
    f32 accelaration;
    f32 pitchYawRoll[3]; // 0 = pitch, 1 = yaw, 2 = roll
    s32 unknownFlag; // unknown, some sort of flag value, is &'ed with 1, 2 and 4
} CameraNodeType1;

CameraNodeType1 *cameraNodeType1_init();
void cameraNodeType1_free(CameraNodeType1 *this);
void cameraNodeType1_fromFile(File *file_ptr, CameraNodeType1 *this);
void cameraNodeType1_getPosition(CameraNodeType1 *this, f32 position[3]);
void cameraNodeType1_getHorizontalAndVerticalSpeed(CameraNodeType1 *this, f32 *horizontal_speed, f32 *vertical_speed);
void cameraNodeType1_getRotationAndAccelaration(CameraNodeType1 *this, f32 *rotation, f32 *accelaration);

typedef struct {
    f32 position[3];
    f32 pitchYawRoll[3]; // 0 = pitch, 1 = yaw, 2 = roll
} CameraNodeType2;

CameraNodeType2 *cameraNodeType2_init();
void cameraNodeType2_free(CameraNodeType2 *this);
void cameraNodeType2_fromFile(File *file_ptr, CameraNodeType2 *this);
void cameraNodeType2_getPosition(CameraNodeType2 *this, f32 position[3]);
/*
 * Sets 0 to pitch, 1 to yaw and 2 to roll
 */
void cameraNodeType2_getPitchYawRoll(CameraNodeType2 *this, f32 pitch_yaw_roll[3]);

typedef struct {
    f32 position[3];
    f32 horizontalSpeed;
    f32 verticalSpeed;
    f32 rotation;
    f32 accelaration;
    f32 closeDistance;
    f32 farDistance;
    f32 pitchYawRoll[3]; // 0 = pitch, 1 = yaw, 2 = roll
    s32 unknownFlag;
} CameraNodeType3;
CameraNodeType3 *cameraNodeType3_init();
void cameraNodeType3_free(CameraNodeType3 *this);
void cameraNodeType3_fromFile(File *file_ptr, CameraNodeType3 *this);
void cameraNodeType3_getPosition(CameraNodeType3 *this, f32 position[3]);
void cameraNodeType3_getHorizontalAndVerticalSpeed(CameraNodeType3 *this, f32 *horizontal_speed, f32 *vertical_speed);
void cameraNodeType3_getRotationAndAccelaration(CameraNodeType3 *this, f32 *rotation, f32 *accelaration);
/*
 * Sets 0 to pitch, 1 to yaw and 2 to roll
 */
void cameraNodeType3_getPositionWithPitchYawRoll(CameraNodeType3 *this, f32 pitch_yaw_roll[3]);
f32 cameraNodeType3_getCloseDistance(CameraNodeType3 *this);
f32 cameraNodeType3_getFarDistance(CameraNodeType3 *this);

typedef struct {
    s32 unknownFlag;
} CameraNodeType4;
CameraNodeType4 *cameraNodeType4_init();
void cameraNodeType4_free(CameraNodeType4 *this);
void cameraNodeType4_fromFile(File *file_ptr, CameraNodeType4 *this);
#endif
