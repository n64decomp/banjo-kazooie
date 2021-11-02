#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802CE8D4(Actor *this);

/* .data */
extern ActorAnimationInfo D_803672C0[] ={
    {0x000, 0.0f},
    {ASSET_165_ANIM_BEEHIVE_IDLE,   0.65f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     0.5f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     1000000.0f},
};

extern ActorInfo D_803672E0 = {0x50, ACTOR_12_BEEHIVE, ASSET_364_MODEL_BEEHIVE, 
    1, &D_803672C0, 
    func_802CE8D4, func_80326224, func_80325888,
    {0,0,0x03,0x33}, 0.0f, {0,0,0,0}
}; 

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47850/func_802CE7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_47850/func_802CE8D4.s")
// void func_802CE8D4(Actor *this){

// }

