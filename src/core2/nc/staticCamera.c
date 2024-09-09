#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/nc/camera.h"


extern void func_8025727C(f32, f32, f32, f32, f32, f32, f32*, f32*);

/* .bss */
static f32 ncStaticCameraPosition[3];
static f32 ncStaticCameraRotation[3];

/* .code */
void ncStaticCamera_init(void){
    ml_vec3f_clear(ncStaticCameraPosition);
    ml_vec3f_clear(ncStaticCameraRotation);
}

void ncStaticCamera_end(void){}

void ncStaticCamera_rotateToTarget(f32 target[3]){
    func_8025727C(
        target[0], target[1], target[2],
        ncStaticCameraPosition[0], ncStaticCameraPosition[1], ncStaticCameraPosition[2],
        &ncStaticCameraRotation[0], &ncStaticCameraRotation[1]
    );
    ncStaticCameraRotation[0] = mlNormalizeAngle(-ncStaticCameraRotation[0]);
    ncStaticCameraRotation[2] = 0.0f;
}

void ncStaticCamera_setPosition(f32 arg0[3]){
    ml_vec3f_copy(ncStaticCameraPosition, arg0);
}

void ncStaticCamera_update(void){
    viewport_setPosition_vec3f(ncStaticCameraPosition);
    viewport_setRotation_vec3f(ncStaticCameraRotation);
}

void __ncStaticCamera_setToNode(s32 camera_node_index){
    UNK_TYPE(s32) sp1C;

    sp1C = func_802B9E70(camera_node_index);
    ncCameraNodeType2_getPosition(sp1C, ncStaticCameraPosition);
    ncCameraNodeType2_getRotation(sp1C, ncStaticCameraRotation);
}

void ncStaticCamera_setToNode(s32 camera_node_index){
    camera_setType(CAMERA_TYPE_3_STATIC);
    __ncStaticCamera_setToNode(camera_node_index);
}

void ncStaticCamera_exit(void){
    camera_setType(CAMERA_TYPE_2_DYNAMIC);
}

void ncStaticCamera_setPositionAndRotation(f32 arg0[3], f32 arg1[3]){
    camera_setType(CAMERA_TYPE_3_STATIC);
    ml_vec3f_copy(ncStaticCameraPosition, arg0);
    ml_vec3f_copy(ncStaticCameraRotation, arg1);
}

void ncStaticCamera_setPositionAndTarget(f32 arg0[3], f32 arg1[3]){
    camera_setType(CAMERA_TYPE_3_STATIC);
    ml_vec3f_copy(ncStaticCameraPosition, arg0);
    ncStaticCamera_rotateToTarget(arg1);
}

void ncStaticCamera_getPosition(f32 dst[3]){
    dst[0] = ncStaticCameraPosition[0];
    dst[1] = ncStaticCameraPosition[1];
    dst[2] = ncStaticCameraPosition[2];
}
