#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 duration;
    u8 state;
} BaEyes;

BaEyes baEyes[4];

/* .code */
f32 baeyes_getEyePosition(s32 id){
    switch (id) {
        case 0:
            return func_8029DFC8();
        case 1:
            return func_8029DFD4();
        case 2:
            return 0.0f;
        case 3:
            return 0.0f;
        default:
            return 0.0f;
    }
}


void baeyes_setEyePosition(s32 id, f32 position){
    switch(id){
        case 0:
            func_8029E0C4(position);
            break;
        case 1:
            func_8029E0D0(position);
            break;
        case 2:
            break;
        case 3:
        default:
            break;
    }
}

void baeyes_reset(void){
    int i;
    for(i = 0; i < 4; i++){
        baEyes[i].duration = 1.0f;
        baEyes[i].state = 0;
        baeyes_setEyePosition(i, 0.0f);
    }
}

void baeyes_blinkSingleEye(s32 id, f32 arg1){
    baEyes[id].state = 1;
    baEyes[id].duration = arg1;
}

void baeyes_closeSingleEye(s32 id, f32 arg1){
    baEyes[id].state = 5;
    baEyes[id].duration = arg1;
}


void baeyes_close(void){
    baeyes_closeSingleEye(0, 0.09f);
    baeyes_closeSingleEye(1, 0.09f);
}

void baeyes_openSingleEye(s32 id, f32 arg1){
    baEyes[id].state = 4;
    baEyes[id].duration = arg1;
}

void baeyes_open(void){
    baeyes_openSingleEye(0, 0.034f);
    baeyes_openSingleEye(1, 0.034f);
}

void baeyes_update(void){
    f32 dt;
    f32 eye_position;
    int i;

    dt = time_getDelta();
    for(i = 0; i < 4; i++){
        eye_position = baeyes_getEyePosition(i);
        switch(baEyes[i].state){
            case 1://L80292F78
                eye_position += dt/baEyes[i].duration;
                if(1.0 < eye_position){
                    eye_position = 1.0f;
                    baEyes[i].state = 2;
                }
                baeyes_setEyePosition(i, eye_position);
                break; 
            case 2://L80292FB4
                baEyes[i].state = 3;
                break; 
            case 3://L80292FBC
            case 4://L80292FBC
                eye_position -= dt/baEyes[i].duration;
                if(eye_position < 0.0){
                    eye_position = 0.0f;
                    baEyes[i].state = 0;
                }
                baeyes_setEyePosition(i, eye_position);
                break; 
            case 5://L80292FF8
                eye_position += dt/baEyes[i].duration;
                if(1.0 < eye_position){
                    eye_position = 1.0f;
                    baEyes[i].state = 0;
                }
                baeyes_setEyePosition(i, eye_position);
                break;
            case 0://L8029302C
            default://L8029302C
                break; 
        }
    }
}
