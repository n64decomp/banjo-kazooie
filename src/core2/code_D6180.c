#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8035D3D8(Actor *this);

/* .data */ 
extern ActorAnimationInfo D_80372E20[];
extern ActorInfo D_80372E78 = { 
    0x219, 0x34F, 0x4C7, 
    0x1, D_80372E20, 
    func_8035D3D8, func_80326224, func_80325888, 
    2500, 0, 1.0f, 0
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D6180/func_8035D110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D6180/func_8035D1F0.s")

void func_8035D2C0(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    func_802DB4E0(marker, arg1);
    actor_collisionOn(actor);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D6180/func_8035D2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D6180/func_8035D3D8.s")



/* BREAK??? */
void func_8035D490(ActorMarker *marker){
    Actor *sp1C;

    if (map_get() == MAP_13_GV_MEMORY_GAME) {
        sp1C = marker_getActor(marker);
        if (func_80329530(sp1C, 250) != 0) {
            func_802C9334(0x1C, sp1C);
            func_8035D2C0(marker, 0);
        }
    }
}

void func_8035D4F0(ActorMarker *marker, s32 arg1){
    s32 pad;
    Actor *actor;
    if(map_get() == MAP_13_GV_MEMORY_GAME){
        actor = marker_getActor(marker);
        if(actor->state != 9){
            if(func_8033F3E8(func_80309744(0), actor->position, 0x190, 0x1A0) == arg1){
                func_802C9334(0x1C, actor);
                func_8035D2C0(marker, 0);
            }
        }
    }
}