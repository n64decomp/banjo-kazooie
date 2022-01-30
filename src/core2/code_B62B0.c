#include <ultra64.h>
#include "functions.h"
#include "variables.h"



s32 func_8033D240(ActorMarker *arg0, ActorMarker *arg1){
    if(arg0){
        if(!arg0->unk14_20 && player_getActiveHitbox(arg1) == HITBOX_6_WONDERWING)
            return -1;
        return arg0->unk14_20;
    }
    return -1;
}

s32 func_8033D2A8(ActorMarker *arg0, ActorMarker *arg1){
    if(!arg0)
        return HITBOX_6_WONDERWING;
    
    if(!arg0->unk14_20)
        return player_getActiveHitbox(arg1);
    return HITBOX_0_NONE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B62B0/func_8033D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B62B0/func_8033D410.s")

s32 func_8033D564(struct5Cs *arg0){
    return arg0->unk0_15;
}

s32 func_8033D574(struct5Cs *arg0){
    return arg0->unk0_11;
}

s32 func_8033D584(struct5Cs *arg0){
    return arg0->unk0_9;
}

s32 func_8033D594(struct5Cs *arg0){
    return arg0->unk0_6;
}

s32 func_8033D5A4(struct5Cs *arg0){
    return arg0->unk0_4;
}

s32 func_8033D5B4(struct5Cs *arg0){
    return arg0->unk0_1;
}
