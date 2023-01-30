#include <ultra64.h>
#include "functions.h"
#include "variables.h"

enum bsdroneenter_state_e{
    BSDRONEENTER_SUBSTATE_0_UNINITIALIZED,
    BSDRONEENTER_SUBSTATE_1,
    BSDRONEENTER_SUBSTATE_2,
    BSDRONEENTER_SUBSTATE_3
};

/* .bss */
struct {
    ParticleEmitter *white_sparkle_emitter;
    ParticleEmitter *yellow_sparkle_emitter;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8 pad14[4];
}bsDroneEnter;
u8 bsDroneEnterSubstate;

/* .code */
void __bsDroneEnter_setSubstate(enum bsdroneenter_state_e arg0) {
    switch (arg0) {
    case 1:
        func_8029E3C0(0, 0.2f);
        break;
    case 2:
        func_8025A6CC(COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
        func_8025AABC(COMUSIC_43_ENTER_LEVEL_GLITTER);
        func_8029E3C0(0, 0.4f);
        baModel_setEnvAlpha(0);
        baModel_updateModel();
        break;
    case 3:
        comusic_8025AB44(COMUSIC_43_ENTER_LEVEL_GLITTER, 0, 2000);
        func_8029E3C0(0, 0.55f);
        break;
    }
    bsDroneEnterSubstate = arg0;
}

void __bsDroneEnter_emitParticles(void) {
    f32 plyr_pos[3];

    player_getPosition(plyr_pos);
    particleEmitter_setParticleAccelerationRange(bsDroneEnter.yellow_sparkle_emitter, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(bsDroneEnter.yellow_sparkle_emitter, -45.0f, -5.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(bsDroneEnter.yellow_sparkle_emitter, plyr_pos);
    particleEmitter_emitN(bsDroneEnter.yellow_sparkle_emitter, 1);

    particleEmitter_setParticleAccelerationRange(bsDroneEnter.white_sparkle_emitter, 0.0f, 700.0f, 0.0f, 0.0f, 1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(bsDroneEnter.yellow_sparkle_emitter, -45.0f, -5.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(bsDroneEnter.white_sparkle_emitter, plyr_pos);
    particleEmitter_emitN(bsDroneEnter.white_sparkle_emitter, 1);

    player_getPosition(plyr_pos);
    plyr_pos[1] += 130.0f;
    particleEmitter_setParticleAccelerationRange(bsDroneEnter.yellow_sparkle_emitter, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(bsDroneEnter.yellow_sparkle_emitter, -45.0f, -10.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(bsDroneEnter.yellow_sparkle_emitter, plyr_pos);
    particleEmitter_emitN(bsDroneEnter.yellow_sparkle_emitter, 1);

    particleEmitter_setParticleAccelerationRange(bsDroneEnter.white_sparkle_emitter, 0.0f, -700.0f, 0.0f, 0.0f, -1200.0f, 0.0f);
    particleEmitter_setParticleSpawnPositionRange(bsDroneEnter.yellow_sparkle_emitter, -45.0f, -10.0f, -45.0f, 45.0f, 10.0f, 45.0f);
    particleEmitter_setPosition(bsDroneEnter.white_sparkle_emitter, plyr_pos);
    particleEmitter_emitN(bsDroneEnter.white_sparkle_emitter, 1);
}

void __bsDroneEnter_initParticleTypes(ParticleEmitter *p_ctrl, enum asset_e sprite_id) {
    particleEmitter_manualFree(p_ctrl);
    particleEmitter_setSprite(p_ctrl, sprite_id);
    particleEmitter_setFade(p_ctrl, 0.3f, 0.8f);
    func_802EFB70(p_ctrl, 0.15f, 0.22f);
    func_802EFB84(p_ctrl, 0.03f, 0.05f);
    particleEmitter_setAngularVelocityRange(p_ctrl, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    particleEmitter_setParticleLifeTimeRange(p_ctrl, 0.55f, 0.55f);
}

void __bsDroneEnter_removeParticleTypes(void) {
    partEmitMgr_freeEmitter(bsDroneEnter.yellow_sparkle_emitter);
    partEmitMgr_freeEmitter(bsDroneEnter.white_sparkle_emitter);
}

void __bsDroneEnter_init(void) {
    bsDroneEnter.unk10 = 0.0f;
    bsDroneEnter.unk8 = 0.0f;
    bsDroneEnter.unkC = 1.0f;
    bsDroneEnter.white_sparkle_emitter = partEmitMgr_newEmitter(60);
    __bsDroneEnter_initParticleTypes(bsDroneEnter.white_sparkle_emitter, ASSET_716_SPRITE_SPARKLE_WHITE);
    bsDroneEnter.yellow_sparkle_emitter = partEmitMgr_newEmitter(60);
    __bsDroneEnter_initParticleTypes(bsDroneEnter.yellow_sparkle_emitter, ASSET_713_SPRITE_SPARKLE_YELLOW);
}

void func_802AE914(void) {
    bsDroneEnter.unk10 -= time_getDelta();
    while ( bsDroneEnter.unk10 < 0.0f) {
        __bsDroneEnter_emitParticles();
        bsDroneEnter.unk8 += 0.02 * (f64) bsDroneEnter.unkC;
        bsDroneEnter.unk10 += 0.02;
    }
}

void bsDroneEnter_init(void) {
    f32 anim_duration;
    enum asset_e anim_id;

    func_8029BCF8(&anim_id, &anim_duration);
    func_8028A010(anim_id, anim_duration);
    func_8029C7F4(1, 1, 3, 7);
    func_80294378(6);
    __bsDroneEnter_init();
    bsDroneEnterSubstate = BSDRONEENTER_SUBSTATE_0_UNINITIALIZED;
    __bsDroneEnter_setSubstate(BSDRONEENTER_SUBSTATE_1);
}

void bsDroneEnter_update(void) {
    s32 next_state;
    s32 sp20;
    u8 temp_v0;

    next_state = 0;
    switch (bsDroneEnterSubstate) {
    case BSDRONEENTER_SUBSTATE_1:
        func_802AE914();
        if (func_8029E1A8(0)) {
            __bsDroneEnter_setSubstate(BSDRONEENTER_SUBSTATE_2);
        }
        break;
    case BSDRONEENTER_SUBSTATE_2:
        func_802AE914();
        sp20 = func_8029E1A8(0);
        baModel_setEnvAlpha((s32) ml_map_f(func_8029E270(0), 0.0f, 0.4f, 255.0f, 0.0f));
        if (sp20) {
            __bsDroneEnter_setSubstate(BSDRONEENTER_SUBSTATE_3);
        }
        break;
    case BSDRONEENTER_SUBSTATE_3:
        if (func_8029E1A8(0)) {
            next_state = bs_getIdleState();
        }
        break;
    }
    bs_setState(next_state);
}

void bsDroneEnter_end(void){
    __bsDroneEnter_removeParticleTypes();
    func_80294378(1);
    baModel_updateModel();
}
