#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 D_8037C680; //roll
f32 D_8037C684; //roll_ideal
f32 D_8037C688; //roll_angular_velocity_limit
f32 D_8037C68C; //roll_ideal

static void __roll_update(f32 limit, f32 step_percent){
        f32 diff;
        f32 val;
        f32 tick = time_getDelta();
        f32 max;
        
        max = limit*tick;
        diff = D_8037C684 - D_8037C680;
        if(180.0f < mlAbsF(diff)){
            diff += (diff < 0.0f)? 360.0: -360.0;
        }

        val = diff * step_percent * tick;
        val = (val < 0) ? mlClamp_f(val, -max, -0.1f) : mlClamp_f(val, 0.1f, max);

        D_8037C680 =( mlAbsF(val) <= mlAbsF(diff)) ?  D_8037C680 + val : D_8037C684;

        if(D_8037C680 < 360.0){
            if(D_8037C680 < 0.0)
                D_8037C680 += 360.0;
        }
        else 
            D_8037C680 -= 360.0;
}

void roll_reset(void){
    D_8037C680 = 0.0f;
    D_8037C684 = 0.0f;
    roll_setAngularVelocity(700.0f, 7.5f);
}

void roll_update(void){
    __roll_update(D_8037C688, D_8037C68C);
}

void roll_setIdeal(f32 arg0){
    D_8037C684 = mlNormalizeAngle(arg0);
}

void roll_set(f32 arg0){
    D_8037C680 = mlNormalizeAngle(arg0);
}

void roll_applyIdeal(void){
    D_8037C680 = D_8037C684;
}

f32 roll_get(void){
    return D_8037C680;
}

f32 roll_getIdeal(void){
    return D_8037C684;
}

void roll_setAngularVelocity(f32 limit, f32 rate){
    D_8037C688 = limit;
    D_8037C68C = rate;
}
