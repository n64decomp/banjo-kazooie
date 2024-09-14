#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/file.h>

typedef struct {
    f32 position[3];
    f32 rotation[3];
} CameraNodeType2;

void ncCameraNodeType2_setPosition(CameraNodeType2 *this, f32 src[3]);
void ncCameraNodeType2_setRotation(CameraNodeType2 *this, f32 src[3]);

/* .code */
CameraNodeType2 *ncCameraNodeType2_new(void){
    CameraNodeType2 *this;
    f32 sp18[3];

    this = (CameraNodeType2 *)malloc(sizeof(CameraNodeType2));
    ml_vec3f_clear(sp18);
    ncCameraNodeType2_setPosition(this, sp18);
    ncCameraNodeType2_setRotation(this, sp18);
    return this;
}

void ncCameraNodeType2_free(CameraNodeType2 *this){
    free(this);
}

void ncCameraNodeType2_getPosition(CameraNodeType2 *this, f32 dst[3]){\
    ml_vec3f_copy(dst, this->position);
}

void ncCameraNodeType2_setPosition(CameraNodeType2 *this, f32 src[3]){
    ml_vec3f_copy(this->position, src);
}

void ncCameraNodeType2_getRotation(CameraNodeType2 *this, f32 dst[3]){\
    ml_vec3f_copy(dst, this->rotation);
}

void ncCameraNodeType2_setRotation(CameraNodeType2 *this, f32 src[3]){
    ml_vec3f_copy(this->rotation, src);
}

void ncCameraNodeType2_fromFile(File *file_ptr, CameraNodeType2 *arg1){
    while(!file_isNextByteExpected(file_ptr, 0)){
        if(!file_getNFloats_ifExpected(file_ptr, 1, arg1->position, 3)){
            file_getNFloats_ifExpected(file_ptr, 2, arg1->rotation, 3);
        }//L802BAA0C
    }
}
