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
u8 D_8037D468;

/* .code */
void __bsDroneVanish_setSubstate(s32 next_state) {
    switch (next_state) {
    case 1:
        func_8029E3C0(0, 0.3f);
        break;
    case 2:
        func_8025A6CC(COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
        func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
        func_8029E3C0(0, 0.4f);
        break;
    case 3:
        gcpausemenu_returnToLair();
        baModel_setVisible(FALSE);
        comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 2000);
        func_8029E3C0(0, 2.0f);
        break;
    }
    D_8037D468 = next_state;
}

void __bsDroneVanish_emitParticles(void) {
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

void __bsDroneVanish_particleEmitInit(ParticleEmitter *p_ctrl, enum asset_e sprite_id) {
    particleEmitter_manualFree();
    particleEmitter_setSprite(p_ctrl, sprite_id);
    particleEmitter_setFade(p_ctrl, 0.3f, 0.8f);
    particleEmitter_setParticleSpawnPositionRange(p_ctrl, -45.0f, 0.0f, -45.0f, 45.0f, 0.0f, 45.0f);
    func_802EFB70(p_ctrl, 0.15f, 0.22f);
    func_802EFB84(p_ctrl, 0.03f, 0.05f);
    particleEmitter_setAngularVelocityRange(p_ctrl, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 0.55f, 0.55f);
}

void __bsDroneVanish_end(void) {
    partEmitMgr_freeEmitter(D_8037D450.unk4);
    partEmitMgr_freeEmitter(D_8037D450.unk0);
}

void __bsDroneVanish_init(void) {
    D_8037D450.unk10 = 0.0f;
    D_8037D450.unk8 = 0.0f;
    D_8037D450.unkC = 1.0f;
    D_8037D450.unk0 = partEmitMgr_newEmitter(60);
    __bsDroneVanish_particleEmitInit(D_8037D450.unk0, ASSET_716_SPRITE_SPARKLE_WHITE);
    D_8037D450.unk4 = partEmitMgr_newEmitter(60);
    __bsDroneVanish_particleEmitInit(D_8037D450.unk4, ASSET_713_SPRITE_SPARKLE_YELLOW);
}

void __bsDroneVanish_update(void) {
    D_8037D450.unk10 -= time_getDelta();
    while ( D_8037D450.unk10 < 0.0f) {
        __bsDroneVanish_emitParticles();
        D_8037D450.unk8 += 0.02 * (f64) D_8037D450.unkC;
        D_8037D450.unk10 += 0.02;
    }
}

void bsDroneVanish_init(void){
    f32 anim_duration;
    enum asset_e anim_id;

    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1,1,3,7);
    func_80294378(6);
    __bsDroneVanish_init();
    D_8037D468 = 0;
    __bsDroneVanish_setSubstate(1);
}

void bsDroneVanish_update(void) {
    s32 next_state;
    bool sp20;

    next_state = 0;
    switch (D_8037D468) {
    case 1:
        __bsDroneVanish_update();
        if (func_8029E1A8(0)) {
            __bsDroneVanish_setSubstate(2);
        }
        break;
    case 2:
        __bsDroneVanish_update();
        sp20 = func_8029E1A8(0);
        baModel_setEnvAlpha((s32) ml_map_f(func_8029E270(0), 0.0f, 0.4f, 0.0f, 255.0f));
        if (sp20) {
            __bsDroneVanish_setSubstate(3);
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

void bsDroneVanish_end(void){
    __bsDroneVanish_end();
    func_80294378(1);
    baModel_updateModel();
}
