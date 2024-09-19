#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038B87C(Actor *this);

/* .data */
ActorInfo D_8038F300 = {
    0x1BA, 0x2A7, 0x503,
    0x0, NULL,
    func_8038B87C, NULL, actor_draw,
    0, 0, 2.0f, 0
};

s32 D_8038F324[] = {
    SFX_97_BLUBBER_BURPS,
    SFX_3E_POOP_NOISE,
    SFX_F6_BLUBBER_TALKING_2,
    SFX_F7_BLUBBER_TALKING_3,
    SFX_F8_BLUBBER_TALKING_4,
    SFX_F5_BLUBBER_TALKING_1,
    0
};

/* .code */
void func_8038B4C0(ActorMarker *marker) {
    Actor *this;
    static s32 D_8038F340 = 0; 

    this = marker_getActor(marker);
    func_8030E878(D_8038F324[D_8038F340], randf2(1.1f, 1.2f), (s32) randf2(31000.0f, 32000.0f), this->position, 500.0f, 2500.0f);
    D_8038F340++;
    if (D_8038F324[D_8038F340] == 0) {
        D_8038F340 = 0;
    }
}

void func_8038B58C(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);
    
    func_8030E878(0x81, randf2(1.0f, 1.1f), (s32) randf2(31000.0f, 32000.0f), actor->position, 500.0f, 2500.0f);
}

void func_8038B610(ActorMarker* marker) {
    Actor* actor;
    s32 temp_s0;
    f32 sp24;
    s32 sp20;

    actor = marker_getActor(marker);
    temp_s0 = func_802F9AA8(SFX_12B_BOILING_AND_BUBBLING);
    sp24 = randf2(1.0f, 1.0f);
    sp20 = randf2(29000.0f, 32000.0f);
    func_802F9DB8(temp_s0, sp24, sp24, 0.0f);
    func_802F9EC4(temp_s0, actor->position, 0xC8, 0x7D0);
    func_802F9F80(temp_s0, 0.05f, 0.2f, 0.3f);
    func_802FA060(temp_s0, sp20, sp20, 0.0f);
}

void func_8038B6DC(ActorMarker *marker) {
    Actor *this;
    f32 phi_f20;
    int i;

    this = marker_getActor(marker);
    skeletalAnim_clearCallbacks(this->unk148);
    phi_f20 = randf2(0.1f, 0.3f);
    for(i = 0; i < 3; i++){
        skeletalAnim_setCallback_1(this->unk148, phi_f20, func_8038B610, this->marker);
        phi_f20 += randf2(0.15f, 0.3f);
        if(0.85 < phi_f20)
            break;
    }
    skeletalAnim_setCallback_1(this->unk148, 0.35f, func_8038B4C0, this->marker);
    skeletalAnim_setCallback_1(this->unk148, 0.63f, func_8038B58C, this->marker);
    skeletalAnim_setCallback_1(this->unk148, 0.9f, func_8038B6DC, this->marker);
}

void func_8038B814(Actor *this, s32 next_state) {
    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x22B, 0.2f, 11.0f);
        func_8038B6DC(this->marker);
    }
    this->state = next_state;
}

void func_8038B87C(Actor *this) {
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->is_first_encounter = FALSE;
        func_8038B814(this, 1);
    }
    if (!this->is_first_encounter && func_803292E0(this)) {
        this->is_first_encounter = TRUE;
        gcdialog_showText(0xCC9, 0, NULL, NULL, NULL, NULL);
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}
