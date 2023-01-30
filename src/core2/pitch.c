#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
f32 D_8037C540; //pitch degrees
f32 D_8037C544; //idealPitch degrees
f32 D_8037C548; //pitchAngularVelocityLimit
f32 D_8037C54C; //PitchAngularVelocity

/* .code */
static void __pitch_update(f32 limit, f32 angVel){
    f32 diff;
    f32 val;
    f32 tick = time_getDelta();
    f32 max;
    
    max = limit*tick;
    diff = D_8037C544 - D_8037C540;
    if(180.0f < mlAbsF(diff)){
        diff += (diff < 0.0f)? 360.0: -360.0;
    }

    val = diff * angVel * tick;
    val = (val < 0) ? ml_clamp_f(val, -max, -0.1f) : ml_clamp_f(val, 0.1f, max);

    D_8037C540 =( mlAbsF(val) <= mlAbsF(diff)) ?  D_8037C540 + val : D_8037C544;

    if(D_8037C540 < 360.0){
        if(D_8037C540 < 0.0)
            D_8037C540 += 360.0;
    }
    else 
        D_8037C540 -= 360.0;
}

void pitch_reset(void){
    D_8037C540 = 0.0f;
    D_8037C544 = 0.0f;
    pitch_setAngVel(500.0f, 0.8f);
}

void pitch_update(void){
    __pitch_update(D_8037C548, D_8037C54C);
}

void pitch_setIdeal(f32 ideal_pitch_deg){
    D_8037C544 = mlNormalizeAngle(ideal_pitch_deg);
}

void pitch_set(f32 pitch_deg){
    D_8037C540 = mlNormalizeAngle(pitch_deg);
}

void pitch_applyIdeal(void){
    D_8037C540 = D_8037C544;
}

f32 pitch_get(void){
    return D_8037C540;
}

f32 pitch_getIdeal(void){
    return D_8037C544;
}

void pitch_setAngVel(f32 limit, f32 angVel){
    D_8037C548 = limit;
    D_8037C54C = angVel;
}
