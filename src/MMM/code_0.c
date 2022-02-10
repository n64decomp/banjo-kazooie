#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8038C340;

void func_803863F0(ActorMarker* marker) {
    Actor* sp1C = marker_getActor(marker);
    func_8028F918(2);
    func_80328B8C(sp1C, 2, 0.01, 1);
    actor_playAnimationOnce(sp1C);
    sp1C->unk60 = D_8038C340;
}

void func_8038644C(void* arg1, void* arg2, void* arg3) {
    func_803863F0(arg1);
}

void func_80386470(ActorMarker* this_marker, ActorMarker *other_marker) {
    Actor *this = marker_getActor(this_marker);
    if ((player_getTransformation() == 3) && (func_8031FF1C(0x89) == 0)) {
        if (func_80311480(0xADF, 0x2B, this->position, this->marker, &func_8038644C, 0) != 0) {
            actor_collisionOff(this);
            func_80320004(0x89, 1);
        }
    } else {
        if ((player_getTransformation() == 3) && (func_8031FF1C(0x89) != 0)) {
            actor_collisionOff(this);
            func_803863F0(this_marker);
            return;
        }
        if ((player_getTransformation() == 1) && (func_8031FF1C(0x88) == 0) && (func_80311480(0xADE, 0x2A, this->position, NULL, NULL, NULL) != 0)) {
            func_80320004(0x88, 1);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_0/func_8038658C.s")
