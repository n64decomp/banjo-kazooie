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
}D_8037D420;
u8 D_8037D438;

/* .code */
void func_802AE4E0(s32 arg0) {
    switch (arg0) {
    case 1:
        func_8029E3C0(0, 0.2f);
        break;
    case 2:
        func_8025A6CC(COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
        func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
        func_8029E3C0(0, 0.4f);
        playerModel_setEnvAlpha(0);
        playerModel_updateModel();
        break;
    case 3:
        comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 2000);
        func_8029E3C0(0, 0.55f);
        break;
    }
    D_8037D438 = arg0;
}

void func_802AE598(void) {
    f32 plyr_pos[3];

    player_getPosition(plyr_pos);
    particleEmitter_setParticleAccelerationRange(D_8037D420.unk4, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(D_8037D420.unk4, -45.0f, -5.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(D_8037D420.unk4, plyr_pos);
    particleEmitter_emitN(D_8037D420.unk4, 1);
    particleEmitter_setParticleAccelerationRange(D_8037D420.unk0, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(D_8037D420.unk4, -45.0f, -5.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(D_8037D420.unk0, plyr_pos);
    particleEmitter_emitN(D_8037D420.unk0, 1);
    player_getPosition(plyr_pos);
    plyr_pos[1] += 130.0f;
    particleEmitter_setParticleAccelerationRange(D_8037D420.unk4, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(D_8037D420.unk4, -45.0f, -10.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(D_8037D420.unk4, plyr_pos);
    particleEmitter_emitN(D_8037D420.unk4, 1);
    particleEmitter_setParticleAccelerationRange(D_8037D420.unk0, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(D_8037D420.unk4, -45.0f, -10.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(D_8037D420.unk0, plyr_pos);
    particleEmitter_emitN(D_8037D420.unk0, 1);
}

void func_802AE7AC(ParticleEmitter *p_ctrl, enum asset_e sprite_id) {
    func_802F0D54(p_ctrl);
    particleEmitter_setSprite(p_ctrl, sprite_id);
    func_802EFA5C(p_ctrl, 0.3f, 0.8f);
    func_802EFB70(p_ctrl, 0.15f, 0.22f);
    func_802EFB84(p_ctrl, 0.03f, 0.05f);
    func_802EFE24(p_ctrl, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    func_802EFEC0(p_ctrl, 0.55f, 0.55f);
}

void func_802AE874(void) {
    func_802F0C78(D_8037D420.unk4);
    func_802F0C78(D_8037D420.unk0);
}

void func_802AE8A4(void) {
    D_8037D420.unk10 = 0.0f;
    D_8037D420.unk8 = 0.0f;
    D_8037D420.unkC = 1.0f;
    D_8037D420.unk0 = partEmitList_pushNew(60);
    func_802AE7AC(D_8037D420.unk0, ASSET_716_SPRITE_SPARKLE_WHITE);
    D_8037D420.unk4 = partEmitList_pushNew(60);
    func_802AE7AC(D_8037D420.unk4, ASSET_713_SPRITE_SPARKLE_YELLOW);
}

void func_802AE914(void) {
    D_8037D420.unk10 -= time_getDelta();
    while ( D_8037D420.unk10 < 0.0f) {
        func_802AE598();
        D_8037D420.unk8 += 0.02 * (f64) D_8037D420.unkC;
        D_8037D420.unk10 += 0.02;
    }
}

void func_802AE9C8(void) {
    f32 anim_duration;
    enum asset_e anim_id;

    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1, 1, 3, 7);
    func_80294378(6);
    func_802AE8A4();
    D_8037D438 = 0;
    func_802AE4E0(1);
}

void func_802AEA2C(void) {
    s32 next_state;
    s32 sp20;
    u8 temp_v0;

    next_state = 0;
    switch (D_8037D438) {
    case 1:
        func_802AE914();
        if (func_8029E1A8(0)) {
            func_802AE4E0(2);
        }
        break;
    case 2:
        func_802AE914();
        sp20 = func_8029E1A8(0);
        playerModel_setEnvAlpha((s32) ml_map_f(func_8029E270(0), 0.0f, 0.4f, 255.0f, 0.0f));
        if (sp20) {
            func_802AE4E0(3);
        }
        break;
    case 3:
        if (func_8029E1A8(0)) {
            next_state = bs_getIdleState();
        }
        break;
    }
    bs_setState(next_state);
}

void func_802AEB24(void){
    func_802AE874();
    func_80294378(1);
    playerModel_updateModel();
}
