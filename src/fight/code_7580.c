#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_80326EEC();
extern void func_80328B8C(Actor*, s32, f32, s32);
extern f32 func_8038D268(void);

/* .data */
extern ActorInfo D_80391A10;

/* .code */
void func_8038D970(ActorMarker *arg0) {
    Actor *temp_v0;
    Actor *phi_v0;

    temp_v0 = marker_getActor(arg0);
    if (temp_v0->unkF4_8 == 5) {
        phi_v0 = spawn_child_actor(0x3AC, &temp_v0);
    } else {
        phi_v0 = spawn_child_actor((temp_v0->unkF4_8) + 0x3A4, &temp_v0);
    }
    phi_v0->unkF4_8 = temp_v0->unkF4_8;
    phi_v0->unk60 = temp_v0->unk1C[0];
    phi_v0->scale = temp_v0->scale;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7580/func_8038DA04.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7580/func_8038DE98.s")
#else
void func_8038DE98(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 sp38;
    f32 sp30;
    f32 sp24[3];
    
    if(actor->state != 2){
        func_80328B8C(actor, 2, 0.0f, 1);
        actor_playAnimationOnce(actor);
        animctrl_setDuration(actor->animctrl, actor->unk1C[0]);
        func_802C3C88(func_8038D970, actor->marker);
        if(!func_8031FF1C(0xD1) && actor->unkF4_8 != 5){
            sp38 = 0x30 + actor->unkF4_8*2;
            sp30 = func_8038D268() + actor->unk1C[0];
            func_8038C0DC(&sp24);
            func_8028F94C(2, &sp24);
            func_8038C27C(1);
            timed_setCameraToNode(0 * sp30, sp38);
            func_80324E88(1 * sp30);
            timed_setCameraToNode(1 * sp30, sp38 + 1);
        }
    }//L8038DF8C
}
#endif

f32 func_8038DFA0(void) {
    return func_80326EEC(0x3A1)->unk1C_x;
}
