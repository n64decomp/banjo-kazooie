#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8037C540; //pitch degrees
extern f32 D_8037C544; //idealPitch degrees
extern f32 D_8037C548; //pitchAngularVelocityLimit
extern f32 D_8037C54C; //PitchAngularVelocity

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297F10.s")

void player_setIdealPitch(f32 ideal_pitch_deg){
    D_8037C544 = mlNormalizeAngle(ideal_pitch_deg);
}

void player_setPitch(f32 pitch_deg){
    D_8037C540 = mlNormalizeAngle(pitch_deg);
}

void player_applyIdealPitch(void){
    D_8037C540 = D_8037C544;
}

f32 player_getPitch(void){
    return D_8037C540;
}

f32 player_getIdealPitch(void){
    return D_8037C544;
}

void player_setPitchAngVel(f32 limit, f32 angVel){
    D_8037C548 = limit;
    D_8037C54C = angVel;
}
