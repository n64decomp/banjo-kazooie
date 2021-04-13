#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80326224(Actor *);
Actor*  func_80325888(ActorMarker *, Gfx **, Mtx**, u32);

/* public functions */
void func_80386768(Actor *);


/* .data */
ActorInfo chorangepadInfo = { 0x66, actor_orange_pad, model_orange_pad, 0, NULL,
    func_80386768, func_80326224, func_80325888,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

/*.code */
void func_803863F0(s32 x, s32 y, s32 z){
    f32 pos[3];

    TUPLE_ASSIGN(pos, x, y, z);
    
    jiggySpawn(jiggy_mm_orange_pads, pos);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/orangepad/func_80386444.s")

void func_80386744(s32 arg0, s32 arg1) {
    func_80386444(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/orangepad/func_80386768.s")
