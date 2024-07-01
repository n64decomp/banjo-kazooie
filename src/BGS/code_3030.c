#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s32 unk0;
    ActorMarker *tiptup_marker; //tiptup_marker
    f32 unk8;
    s32 unkC;
}ActorLocal_BGS_3030;

void func_80389668(Actor *this);
Actor *BGS_func_80389610(ActorMarker *marker, Gfx **, Mtx **, Vtx**);

/* .data */
ActorInfo D_80390880 = { MARKER_19B_CHOIR_TURTLE_YELLOW, ACTOR_27B_CHOIR_TURTLE_YELLOW, ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908A4 = { MARKER_19C_CHOIR_TURTLE_CYAN,   ACTOR_27C_CHOIR_TURTLE_CYAN,   ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908C8 = { MARKER_19D_CHOIR_TURTLE_BLUE,   ACTOR_27D_CHOIR_TURTLE_BLUE,   ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908EC = { MARKER_19E_CHOIR_TURTLE_RED,    ACTOR_27E_CHOIR_TURTLE_RED,    ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_80390910 = { MARKER_19F_CHOIR_TURTLE_PINK,   ACTOR_27F_CHOIR_TURTLE_PINK,   ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_80390934 = { MARKER_1A0_CHOIR_TURTLE_PURPLE, ACTOR_280_CHOIR_TURTLE_PURPLE, ASSET_3F9_MODEL_CHOIR_TURTLE, 0, NULL, func_80389668, NULL, BGS_func_80389610, 0, 0, 1.5f, 0};

/* .code */
void func_80389420(ActorMarker *marker) {
    Actor *this;

    this = marker_getActor(marker);
    func_8030E878(SFX_C5_TWINKLY_POP, randf2(1.0f, 1.2f), 25000, this->position, 500.0f, 3000.0f);
}

void func_80389488(Actor *this, s32 next_state) {
    ActorLocal_BGS_3030 *local;

    local = (ActorLocal_BGS_3030 *)&this->local;
    if (next_state == 1) {
        skeletalAnim_set(this->unk148, ASSET_12D_ANIM_CHOIR_TURTLE_IDLE, 0.2f, randf2(2.0f, 2.5f));
        skeletalAnim_setProgress(this->unk148, randf2(0.0f, 1.0f));
    }
    if (next_state == 2) {
        skeletalAnim_set(this->unk148, ASSET_12E_ANIM_CHOIR_TURTLE_SING, 0.1f, 1.6666666f);
        timed_playSfx(0.8333333, SFX_86_TIPTUP_CHORUS_AH, local->unk8, 0x7FFF);
    }
    if (next_state == 3) {
        func_8030E6A4(SFX_86_TIPTUP_CHORUS_AH, local->unk8, 0x7FFF);
        skeletalAnim_set(this->unk148, ASSET_12F_ANIM_CHOIR_TURTLE_HURT, 0.1f, 1.75f);
        skeletalAnim_setCallback_1(this->unk148, 0.9f, (GenFunction_1)func_80389420, (s32)this->marker);
        if (local->tiptup_marker != NULL) {
            func_80388E94(local->tiptup_marker, local->unk0);
        }
    }
    this->state = next_state;
}

void func_803895D0(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state != 3){
        func_80389488(this, 3);
    }
}

Actor *BGS_func_80389610(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    func_8033A45C(4, marker->unk14_20 - 0x19A);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_80389668(Actor *this) {
    ActorLocal_BGS_3030 *local;
    f32 sp30;
    Actor *tiptup;

    local = (ActorLocal_BGS_3030 *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_803895D0, NULL);
        local->unk0 = 1;
        local->unkC = 0;
        local->tiptup_marker = NULL;
        local->unk8 = 1.0f;
        func_80389488(this, 1);
        if (jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP) && !func_803203FC(2) && !func_803203FC(1)) {
            marker_despawn(this->marker);
        }
        return;
    }

    local->unkC++;
    if (local->unkC == 2) {
        tiptup = actorArray_findClosestActorFromActorId(this->position, ACTOR_27A_TIPTUP, -1, &sp30);
        local->tiptup_marker = (tiptup != NULL) ? tiptup->marker : NULL;
        if (local->tiptup_marker != NULL) {
            func_80388FFC(local->tiptup_marker, &local->unk0, &local->unk8);
        }
    }
    if (this->state == 1) {
        if (local->tiptup_marker != NULL && (func_80388E70(local->tiptup_marker) == local->unk0)) {
            func_80389488(this, 2);
        }
    }
    if (((this->state == 2) || (this->state == 3)) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        func_80389488(this, 1);
    }
}
