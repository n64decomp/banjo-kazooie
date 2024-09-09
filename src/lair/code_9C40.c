#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern bool func_80259384(f32[3], f32[3], f32);

void func_803902B8(Actor *this);
Actor *func_80390030(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80394860[] = {
    {0, 0.0f},
    {0x272, 0.8f}
};
ActorInfo D_80394870 = { 0x16D, 0x1D5, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, 2500, 0, 1.2f, 0};
ActorInfo D_80394894 = { 0x16E, 0x1D6, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, 2500, 0, 1.2f, 0};
ActorInfo D_803948B8 = { 0x16F, 0x1D7, 0x54F, 0x1, D_80394860, func_803902B8, func_80326224, func_80390030, 2500, 0, 1.2f, 0};

/* .code */
Actor *func_80390030(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(3, 1);
    func_8033A45C(4, 1);
    actor_draw(marker, gfx, mtx, vtx);
}

s32 func_80390084(void) {
    s32 phi_s0;
    s32 phi_s1;

    for(phi_s0 = 0, phi_s1 = 0; phi_s0 < 3; phi_s0++){
        if (fileProgressFlag_get(phi_s0 + 0xAD)) {
            phi_s1++;
        }
    }
    return phi_s1;
}

void lair_func_803900DC(ActorMarker *marker, enum asset_e text_id, s32 arg2){

}

void func_803900EC(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    s32 sp1C;

    sp1C =  marker->id - 0x16D;
    func_8028F918(0);
    if (!fileProgressFlag_get(sp1C + 0xAD)) {
        fileProgressFlag_set(sp1C + 0xAD, 1);
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    }
}

s32  func_80390158(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    s32 phi_v1;
    phi_v1 =  marker->id - 0x16D;
    return phi_v1;
}

void func_80390174(ActorMarker *marker, s32 arg1) {
    Actor *this;
    s32 sp28;

    this = marker_getActor(marker);
    sp28 = this->marker->id - 0x16D;
    func_8028F94C(2, this->position);
    if (fileProgressFlag_get(sp28 + 0xAD)) {
        func_80311480(sp28 + 0xF83, 0xE, this->position, this->marker, func_803900EC, lair_func_803900DC);
        return;
    }
    func_80311174(func_80390084() + 0xFA5, 0xE, this->position, this->marker, func_803900EC, lair_func_803900DC, func_80390158);
}

void func_8039024C(Actor *this){
    if(this->unk38_0){
        func_8032BB88(this, -1, 0x1f4);
        comusic_8025AB44(COMUSIC_79_CHEATO, 0, 500);
        func_8025AABC(COMUSIC_79_CHEATO);
    }
}

void func_80390298(Actor *this) {
    func_8039024C(this);
}

void func_803902B8(Actor *this) {
    f32 sp5C[3];
    s32 sp58;
    s32 sp54;
    s32 sp3C[6];

    sp54 = this->marker->id - 0x16D;
    if (!this->initialized) {
        marker_setFreeMethod(this->marker, func_80390298);
        this->unk138_24 = volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE);
        this->initialized = TRUE;
    }
    _player_getPosition(sp5C);
    sp58 = func_80259384(this->position, sp5C, 1750.0f) && !this->unk138_24;
    if (sp58 && !this->unk38_0) {
        func_8032BB88(this, 0, 0x1F4);
        func_8025A6EC(COMUSIC_79_CHEATO, 0);
        comusic_8025AB44(COMUSIC_79_CHEATO, -1, 0x1F4);
    }
    else if (!sp58 && this->unk38_0) {
        func_8039024C(this);
    }
    this->unk38_0 = sp58;
    sp58 = func_80259384(this->position, sp5C, 400.0f);
    if (fileProgressFlag_get(sp54 + 0xAD)) {
        func_8024E55C(0, sp3C);
        sp58 &= (sp3C[FACE_BUTTON(BUTTON_B)] == 1) || func_8028EC04();
    }
    if (sp58 && !*(s32 *)&this->local) {
        func_80390174(this->marker, 0);
    }
    if (actor_animationIsAt(this, 0.01f)) {
        func_8030E878(SFX_F1_CHEATO_IDLE_2, randf()*0.1 + 0.95, 20000, this->position, 200.0f, 1500.f);
    }
    if (actor_animationIsAt(this, 0.25f)) {
        func_8030E878(SFX_F0_CHEATO_IDLE_1, randf()*0.1 + 0.95, 20000, this->position, 200.0f, 1500.0f);
    }
    *(s32 *)&this->local = sp58;
}
