#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038658C(Actor *this);

/* .data */
extern ActorAnimationInfo D_8038B9E0[] = {
    {0,                          0.0f},
    {ASSET_238_ANIM_LOGGO_IDLE,  0.8f},
    {ASSET_240_ANIM_LOGGO_FLUSH, 3.0f}
};

extern ActorInfo D_8038B9F8 = {
    MARKER_252_LOGGO, ACTOR_37F_LOGGO, ASSET_519_MODEL_LOGGO, 
    0x1, D_8038B9E0, 
    func_8038658C, func_80326224, func_80325888, 
    { 0x3, 0xE8}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f32 D_8038C340;

/* .code */
void func_803863F0(ActorMarker* marker) {
    Actor* sp1C = marker_getActor(marker);
    func_8028F918(2);
    func_80328B8C(sp1C, 2, 0.01, 1);
    actor_playAnimationOnce(sp1C);
    sp1C->unk60 = D_8038C340;
}

void func_8038644C(ActorMarker* caller, enum asset_e text_id, s32 arg3) {
    func_803863F0(caller);
}

void func_80386470(ActorMarker* this_marker, ActorMarker *other_marker) {
    Actor *this = marker_getActor(this_marker);
    if ((player_getTransformation() == TRANSFORM_3_PUMPKIN) && !func_8031FF1C(BKPROG_89_ENTERED_LOGGO_AS_PUMPKIN)) {
        if (func_80311480(ASSET_ADF_TEXT_ENTER_LOGGO, 0x2B, this->position, this->marker, &func_8038644C, 0) != 0) {
            actor_collisionOff(this);
            func_80320004(BKPROG_89_ENTERED_LOGGO_AS_PUMPKIN, TRUE);
        }
    } else {
        if ((player_getTransformation() == TRANSFORM_3_PUMPKIN) && func_8031FF1C(BKPROG_89_ENTERED_LOGGO_AS_PUMPKIN)) {
            actor_collisionOff(this);
            func_803863F0(this_marker);
            return;
        }
        if ((player_getTransformation() == TRANSFORM_1_BANJO) && !func_8031FF1C(BKPROG_88_TRIED_LOGGO_AS_BEAR)){
            if(func_80311480(ASSET_ADE_TEXT_LOGGO_AS_BEAR, 0x2A, this->position, NULL, NULL, NULL)) {
                func_80320004(BKPROG_88_TRIED_LOGGO_AS_BEAR, TRUE);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_0/func_8038658C.s")
