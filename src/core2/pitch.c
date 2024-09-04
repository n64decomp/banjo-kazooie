#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
static f32 pitch_degree;
static f32 idealPitch_degree;
static f32 pitchVelocityLimit_degreePerSec;
static f32 pitchVelocity_degreePerSec;

/* .code */
static void __pitch_update(f32 limit, f32 angVel){
    f32 diff;
    f32 val;
    f32 dt = time_getDelta();
    f32 max;
    
    max = limit*dt;
    diff = idealPitch_degree - pitch_degree;
    if(180.0f < mlAbsF(diff)){
        diff += (diff < 0.0f)? 360.0: -360.0;
    }

    val = diff * angVel * dt;
    val = (val < 0) ? ml_clamp_f(val, -max, -0.1f) : ml_clamp_f(val, 0.1f, max);

    pitch_degree =( mlAbsF(val) <= mlAbsF(diff)) ?  pitch_degree + val : idealPitch_degree;

    if(pitch_degree < 360.0){
        if(pitch_degree < 0.0)
            pitch_degree += 360.0;
    }
    else 
        pitch_degree -= 360.0;
}

void pitch_reset(void){
    pitch_degree = 0.0f;
    idealPitch_degree = 0.0f;
    pitch_setAngVel(500.0f, 0.8f);
}

void pitch_update(void){
    __pitch_update(pitchVelocityLimit_degreePerSec, pitchVelocity_degreePerSec);
}

void pitch_setIdeal(f32 ideal_pitch_deg){
    idealPitch_degree = mlNormalizeAngle(ideal_pitch_deg);
}

void pitch_set(f32 pitch_deg){
    pitch_degree = mlNormalizeAngle(pitch_deg);
}

void pitch_applyIdeal(void){
    pitch_degree = idealPitch_degree;
}

f32 pitch_get(void){
    return pitch_degree;
}

f32 pitch_getIdeal(void){
    return idealPitch_degree;
}

void pitch_setAngVel(f32 limit, f32 angVel){
    pitchVelocityLimit_degreePerSec = limit;
    pitchVelocity_degreePerSec = angVel;
}
