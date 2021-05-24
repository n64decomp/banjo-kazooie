#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038D970(ActorMarker *arg0) {
    Actor *temp_v0;
    Actor *phi_v0;

    temp_v0 = marker_getActor(arg0);
    if (temp_v0->unkF4_8 == 5) {
        phi_v0 = spawn_child_actor(0x3AC, (Actor *) &temp_v0);
    } else {
        phi_v0 = spawn_child_actor((temp_v0->unkF4_8) + 0x3A4, (Actor *) &temp_v0);
    }
    phi_v0->unkF4_8 = temp_v0->unkF4_8;
    phi_v0->unk60 = temp_v0->unk1C_x;
    phi_v0->scale = temp_v0->scale;
}

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7580/func_8038DA04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/fight/code_7580/func_8038DE98.s")

Actor *func_80326EEC();

f32 func_8038DFA0(void) {
    return func_80326EEC(0x3A1)->unk1C_x;
}
