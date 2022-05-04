#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
struct {
    ParticleEmitter *unk0;
    ParticleEmitter *unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
}D_8037D450;
extern u8 D_8037D468;

/* .code */
void func_802AF1B0(s32 arg0) {
    switch (arg0) {
    case 1:
        func_8029E3C0(0, 0.3f);
        break;
    case 2:
        func_8025A6CC(COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
        func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
        func_8029E3C0(0, 0.4f);
        break;
    case 3:
        func_80314B30();
        func_802921C8(0);
        comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 2000);
        func_8029E3C0(0, 2.0f);
        break;
    }
    D_8037D468 = arg0;
}

void func_802AF268(void) {
    f32 position[3];

    player_getPosition(position);
    particleEmitter_setParticleAccelerationRange(D_8037D450.unk4, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setPosition(D_8037D450.unk4, position);
    particleEmitter_emitN(D_8037D450.unk4, 1);
    particleEmitter_setParticleAccelerationRange(D_8037D450.unk0, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setPosition(D_8037D450.unk0, position);
    particleEmitter_emitN(D_8037D450.unk0, 1);
    position[1] += 130.0f;
    particleEmitter_setParticleAccelerationRange(D_8037D450.unk4, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setPosition(D_8037D450.unk4, position);
    particleEmitter_emitN(D_8037D450.unk4, 1);
    particleEmitter_setParticleAccelerationRange(D_8037D450.unk0, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setPosition(D_8037D450.unk0, position);
    particleEmitter_emitN(D_8037D450.unk0, 1);
}

void func_802AF3B4(ParticleEmitter *p_ctrl, enum asset_e sprite_id) {
    func_802F0D54();
    particleEmitter_setSprite(p_ctrl, sprite_id);
    func_802EFA5C(p_ctrl, 0.3f, 0.8f);
    particleEmitter_setParticleSpawnPositionRange(p_ctrl, -45.0f, 0.0f, -45.0f, 45.0f, 0.0f, 45.0f);
    func_802EFB70(p_ctrl, 0.15f, 0.22f);
    func_802EFB84(p_ctrl, 0.03f, 0.05f);
    func_802EFE24(p_ctrl, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    func_802EFEC0(p_ctrl, 0.55f, 0.55f);
}

void func_802AF4B0(void) {
    func_802F0C78(D_8037D450.unk4);
    func_802F0C78(D_8037D450.unk0);
}

void func_802AF4E0(void) {
    D_8037D450.unk10 = 0.0f;
    D_8037D450.unk8 = 0.0f;
    D_8037D450.unkC = 1.0f;
    D_8037D450.unk0 = partEmitList_pushNew(60);
    func_802AF3B4(D_8037D450.unk0, ASSET_716_SPRITE_SPARKLE_WHITE);
    D_8037D450.unk4 = partEmitList_pushNew(60);
    func_802AF3B4(D_8037D450.unk4, ASSET_713_SPRITE_SPARKLE_YELLOW);
}

void func_802AF550(void) {
    D_8037D450.unk10 -= time_getDelta();
    while ( D_8037D450.unk10 < 0.0f) {
        func_802AF268();
        D_8037D450.unk8 += 0.02 * (f64) D_8037D450.unkC;
        D_8037D450.unk10 += 0.02;
    }
}

void func_802AF604(void){
    f32 anim_duration;
    enum asset_e anim_id;

    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1,1,3,7);
    func_80294378(6);
    func_802AF4E0();
    D_8037D468 = 0;
    func_802AF1B0(1);
}

void func_802AF668(void) {
    s32 next_state;
    bool sp20;

    next_state = 0;
    switch (D_8037D468) {
    case 1:
        func_802AF550();
        if (func_8029E1A8(0)) {
            func_802AF1B0(2);
        }
        break;
    case 2:
        func_802AF550();
        sp20 = func_8029E1A8(0);
        func_80291FB8((s32) ml_map_f(func_8029E270(0), 0.0f, 0.4f, 0.0f, 255.0f));
        if (sp20) {
            func_802AF1B0(3);
        }
        break;
    case 3:
        if (func_8029E1A8(0)) {
            next_state = func_8029BF78();
        }
        break;
    }
    bs_setState(next_state);
}

void func_802AF768(void){
    func_802AF4B0();
    func_80294378(1);
    func_80291D04();
}
