#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8037C540; //pitch degrees
extern f32 D_8037C544; //idealPitch degrees

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297F10.s")

void player_setIdealPitch(f32 ideal_pitch_deg){
    D_8037C544 = mlNormalizeAngle(ideal_pitch_deg);
}

void player_setPitch(f32 pitch_deg){
    D_8037C540 = mlNormalizeAngle(pitch_deg);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/player_getPitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_10DA0/func_80297FB0.s")
