#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/camera.h>
#include <core2/file.h>

static void __code33250_func_802BA23C(RandomCameraNode *this, s32 arg1);

#define RANDOM_CAMERA_UNK_1_INDICATOR    0x01
#define RANDOM_CAMERA_END_INDICATOR      0x00

/* .code */
RandomCameraNode *cameraNodeType4_init(){
    RandomCameraNode * this;
    
    this = malloc(sizeof(RandomCameraNode));
    __code33250_func_802BA23C(this, 1);
    return this;
}

void cameraNodeType4_free(RandomCameraNode *this){
    free(this);
}

s32 code33250_func_802BA234(RandomCameraNode *this){
    return this->unknownFlag;
}

static void __code33250_func_802BA23C(RandomCameraNode *this, s32 arg1){
    this->unknownFlag = arg1;
}

void cameraNodeType4_fromFile(File *file_ptr, RandomCameraNode *this){
    while(!file_isNextByteExpected(file_ptr, RANDOM_CAMERA_END_INDICATOR)){
        file_getWord_ifExpected(file_ptr, RANDOM_CAMERA_UNK_1_INDICATOR, &this->unknownFlag);
    }
}

