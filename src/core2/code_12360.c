#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 bastick_getX(void);

void func_8029957C(s32 arg0);

/* .bss*/
s32 D_8037C6B0;
f32 D_8037C6B4;

/* .code */
void func_802992F0(void){
    yaw_init();
    D_8037C6B4 = 0.0f;
    D_8037C6B0 = 0;
    func_8029957C(1);
}

void func_8029932C(f32 arg0){
    D_8037C6B4 = arg0;
}

void func_80299338(void){
    f32 stickX = bastick_getX();
    f32 d_yaw_deg;
    d_yaw_deg =(0.03 < (f64)mlAbsF(stickX)) ? ml_mapAbsRange_f(stickX, 0.0f, 1.0f, 1.0f, 6.0f) : 0.0f;
    yaw_setIdeal(yaw_getIdeal() + d_yaw_deg);
}

void func_802993C8(void){
    switch(D_8037C6B0){
        case 1://802993F8
            if(bastick_distance() != 0.0f){
                yaw_setIdeal(bastick_getAngleRelativeToBanjo());
            }
            yaw_update();
            break;
        case 5://80299438
            if(bastick_distance() != 0.0f){
                yaw_setIdeal(bastick_getAngleRelativeToBanjo() + 180.0f);
            }
            yaw_update();
            break; 
        case 3://80299480
            yaw_update();
            break; 
        case 6://80299490
            func_80299338();
            yaw_update();
            break; 
        case 4://802994A8
            if(bastick_distance() != 0.0f){
                yaw_setIdeal(bastick_getAngleRelativeToBanjo());
                yaw_set(yaw_getIdeal());
            }
            yaw_update();
            break;
        case 7://802994F8
            if(bastick_distance() != 0.0f){
                f32 sp1C = bastick_getAngleRelativeToBanjo();
                f32 diff = mlDiffDegF(yaw_getIdeal(), sp1C);
                if(D_8037C6B4 <= mlAbsF(diff)){
                    yaw_setIdeal(bastick_getAngleRelativeToBanjo());
                }
            }
            yaw_update();
            break;
        case 0://8029956C
        case 2:
            break; 
    }
}

void func_8029957C(s32 arg0){
    D_8037C6B0 = arg0;
}

s32 func_80299588(void){
    return D_8037C6B0;
}

void func_80299594(s32 arg0, f32 arg1){
    f32 sp2C[3];
    f32 sp20[3];
    func_80294480(sp2C);
    if(arg0){
        func_8025901C(mlNormalizeAngle(yaw_get() + 180.0f), sp2C, sp20, arg1);
    } else {
        func_8025901C(yaw_get(), sp2C, sp20, arg1);
    }
    pitch_setIdeal(sp20[0]);
    roll_setIdeal(sp20[2]);
}

void func_80299628(s32 arg0){
    func_80299594(arg0, 1.0f);
}
