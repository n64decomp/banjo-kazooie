#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s32 unk0;
    ActorMarker *unk4; //tiptup_marker
    f32 unk8;
    s32 unkC;
}ActorLocal_BGS_3030;

void func_80389668(Actor *this);
Actor *func_80389610(ActorMarker *marker, Gfx **, Mtx **, Vtx**);

/* .data */
ActorInfo D_80390880 = { 0x019B, 0x27B, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908A4 = { 0x019C, 0x27C, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908C8 = { 0x019D, 0x27D, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_803908EC = { 0x019E, 0x27E, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_80390910 = { 0x019F, 0x27F, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};
ActorInfo D_80390934 = { 0x01A0, 0x280, 0x3F9, 0, NULL, func_80389668, NULL, func_80389610, 0, 0, 1.5f, 0};

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
        func_80335924(this->unk148, 0x12D, 0.2f, randf2(2.0f, 2.5f));
        func_80335A74(this->unk148, randf2(0.0f, 1.0f));
    }
    if (next_state == 2) {
        func_80335924(this->unk148, 0x12E, 0.1f, 1.6666666f);
        timed_playSfx(0.8333333, SFX_86_TIPTUP_CHORUS_AH, local->unk8, 0x7FFF);
    }
    if (next_state == 3) {
        func_8030E6A4(SFX_86_TIPTUP_CHORUS_AH, local->unk8, 0x7FFF);
        func_80335924(this->unk148, 0x12F, 0.1f, 1.75f);
        func_80335800(this->unk148, 0.9f, func_80389420, (s32)this->marker);
        if (local->unk4 != NULL) {
            func_80388E94(local->unk4, local->unk0);
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

Actor *func_80389610(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    func_8033A45C(4, marker->unk14_20 - 0x19A);
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_80389668(Actor *this) {
    ActorLocal_BGS_3030 *local;
    f32 sp30;
    Actor *temp_v0_2;

    local = (ActorLocal_BGS_3030 *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, func_803895D0, NULL);
        local->unk0 = 1;
        local->unkC = 0;
        local->unk4 = NULL;
        local->unk8 = 1.0f;
        func_80389488(this, 1);
        if (jiggyscore_isSpawned(JIGGY_27_BGS_TIPTUP) && !func_803203FC(2) && !func_803203FC(1)) {
            marker_despawn(this->marker);
        }
        return;
    }

    local->unkC++;
    if (local->unkC == 2) {
        temp_v0_2 = func_80326D68(this->position, 0x27A, -1, &sp30);
        local->unk4 = (temp_v0_2 != NULL) ? temp_v0_2->marker : NULL;
        if (local->unk4 != NULL) {
            func_80388FFC(local->unk4, &local->unk0, &local->unk8);
        }
    }
    if (this->state == 1) {
        if (local->unk4 != NULL && (func_80388E70(local->unk4) == local->unk0)) {
            func_80389488(this, 2);
        }
    }
    if (((this->state == 2) || (this->state == 3)) && (func_80335794(this->unk148) > 0)) {
        func_80389488(this, 1);
    }
}
