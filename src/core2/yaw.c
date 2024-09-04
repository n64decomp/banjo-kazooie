#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/yaw.h"



f32 yaw_deg; //yaw
f32 yawIdeal_deg; //yaw_ideal
s32 yawUpdateState; //yaw_update_type
f32 D_8037C69C; //yaw_update2_angular_velocity
f32 D_8037C6A0; //yaw_update3_angular_velocity_limit
f32 D_8037C6A4; //yaw_update3_angular_velocity_percentage


void __yaw_update_limitless(f32 arg0) {
    f32 dYaw_deg;
    f32 sp20;

    arg0 *= time_getDelta();
    dYaw_deg = yawIdeal_deg - yaw_deg;
    if (mlAbsF(dYaw_deg) > 180.0f) {
        dYaw_deg += (dYaw_deg < 0.0f) ? 360.0 : -360.0;
    }

    sp20 = (mlAbsF(dYaw_deg) > 180.0f) ? arg0 : ((dYaw_deg < 0.0f)? -arg0: arg0);
    
    if(mlAbsF(sp20) <= mlAbsF(dYaw_deg))
        yaw_deg += sp20;
    else
        yaw_deg = yawIdeal_deg;

    if (yaw_deg < 360.0) {
        if (yaw_deg < 0.0) {
            yaw_deg = (f32) (yaw_deg + 360.0);
        }
    } else {
        yaw_deg = (f32) (yaw_deg - 360.0);
    }
}

static void __yaw_update_limited(f32 limit_degPerSec, f32 step_percent){
        f32 dyaw_deg;
        f32 val_deg;
        f32 dt_s = time_getDelta();
        f32 max_deg;
        
        max_deg = limit_degPerSec*dt_s;
        dyaw_deg = yawIdeal_deg - yaw_deg;
        if(180.0f < mlAbsF(dyaw_deg)){
            dyaw_deg += (dyaw_deg < 0.0f)? 360.0: -360.0;
        }

        val_deg = dyaw_deg * step_percent * dt_s;
        val_deg = (val_deg < 0) ? ml_clamp_f(val_deg, -max_deg, -0.1f) : ml_clamp_f(val_deg, 0.1f, max_deg);

        yaw_deg =( mlAbsF(val_deg) <= mlAbsF(dyaw_deg)) ?  yaw_deg + val_deg : yawIdeal_deg;

        if(yaw_deg < 360.0){
            if(yaw_deg < 0.0)
                yaw_deg += 360.0;
        }
        else 
            yaw_deg -= 360.0;
}

void yaw_init(void){
    yaw_deg = 0.0f;
    yawIdeal_deg = 0.0f;
    yaw_setVelocityBounded(700.0f, 7.5f);
    yaw_setVelocityUnbounded(360.0f);
    yawUpdateState = 0;
    yaw_setUpdateState(YAW_STATE_1_DEFAULT);
}

void yaw_update(void){
    switch(yawUpdateState){
        case YAW_STATE_0_NONE:
            break;
        case YAW_STATE_1_DEFAULT:
            __yaw_update_limited(700.0f, 7.5f);
            break;
        case YAW_STATE_2_UNBOUNDED:
            __yaw_update_limitless(D_8037C69C);
            break;
        case YAW_STATE_3_BOUNDED:
            __yaw_update_limited(D_8037C6A0, D_8037C6A4);
            break;
    }
}

void yaw_setUpdateState(s32 arg0){
    yawUpdateState = arg0;
}

void yaw_setIdeal(f32 arg0){
    yawIdeal_deg = mlNormalizeAngle(arg0);
}

void yaw_set(f32 arg0){
    yaw_deg = mlNormalizeAngle(arg0);
}

void yaw_applyIdeal(void){
    yaw_deg = yawIdeal_deg;
}

s32 yaw_getUpdateState(void){
    return yawUpdateState;
}

f32 yaw_get(void){
    return yaw_deg;
}

f32 yaw_getIdeal(void){
    return yawIdeal_deg;
}

void yaw_setVelocityBounded(f32 arg0, f32 arg1){
    D_8037C6A0 = arg0;
    D_8037C6A4 = arg1;
}

void yaw_setVelocityUnbounded(f32 arg0){
    D_8037C69C = arg0;
}

void yaw_rotateTimed(f32 time_sec){
    f32 dyaw_deg = yawIdeal_deg - yaw_deg;
    if(180.0f < mlAbsF(dyaw_deg)){
        dyaw_deg += (dyaw_deg < 0.0f)? 360.0: -360.0;
    }

    D_8037C69C = mlAbsF(dyaw_deg/time_sec);
}

