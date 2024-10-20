#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core2/camera.h>
#include <core2/file.h>

static void __code33250_func_802BA23C(CameraNodeType4 *this, s32 arg1);

/* .code */
CameraNodeType4 *cameraNodeType4_init(){
    CameraNodeType4 * this;
    
    this = malloc(sizeof(CameraNodeType4));
    __code33250_func_802BA23C(this, 1);
    return this;
}

void cameraNodeType4_free(CameraNodeType4 *this){
    free(this);
}

s32 code33250_func_802BA234(CameraNodeType4 *this){
    return this->unknownFlag;
}

static void __code33250_func_802BA23C(CameraNodeType4 *this, s32 arg1){
    this->unknownFlag = arg1;
}

void cameraNodeType4_fromFile(File *file_ptr, CameraNodeType4 *this){
    while(!file_isNextByteExpected(file_ptr, 0)){
        file_getWord_ifExpected(file_ptr, 1, &this->unknownFlag);
    }
}

