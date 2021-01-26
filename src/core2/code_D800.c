#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern float D_8037C290;
extern float D_8037C294;
extern ActorMarker* D_8037C298;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_80294790.s")

void func_802947C4(void){}

void func_802947CC(ActorMarker*, float*, float*);// func definition
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_802947CC.s")

void func_80294828(void){
    f32 banjoPos[3];
    f32 banjoRot[3];
    
    
    banjo_getRotation(banjoRot);
    banjo_getPosition(banjoPos);
    banjoRot[1] = mlNormalizeAngle(banjoRot[1] + D_8037C294);
    banjoPos[1] += D_8037C290;
    func_802947CC(D_8037C298, banjoPos, banjoRot);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_80294890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_802948E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_802948EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_802948F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D800/func_80294924.s")
