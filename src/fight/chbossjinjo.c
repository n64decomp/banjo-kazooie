#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"
#include <core1/viewport.h>
#include "core2/particle.h"

extern void func_80324CFC(f32, enum comusic_e, s32);
extern void func_80329904(ActorMarker*, s32, f32*);

ActorAnimationInfo chBossJinjoAnimationInfo[] = {
    {0, 0.0f},
    {0x264, 1000000.0f},
    {0x264, 2.26f},
    {0x130, 1.75f},
    {0x131, 2.13333f},
    {0x262, 2.0f}
};

ActorInfo chBossJinjoOrange = { MARKER_27B_BOSS_JINJO_ORANGE, ACTOR_3A5_BOSS_JINJO_ORANGE, ASSET_3BC_MODEL_JINJO_ORANGE, 1, chBossJinjoAnimationInfo, chBossJinjo_update, chBossJinjo_update2, actor_draw, 0, 0, 1.0f, 0 };
ActorInfo chBossJinjoGreen  = { MARKER_27C_BOSS_JINJO_GREEN,  ACTOR_3A6_BOSS_JINJO_GREEN,  ASSET_3C2_MODEL_JINJO_GREEN,  1, chBossJinjoAnimationInfo, chBossJinjo_update, chBossJinjo_update2, actor_draw, 0, 0, 1.0f, 0 };
ActorInfo chBossJinjoPink   = { MARKER_27D_BOSS_JINJO_PINK,   ACTOR_3A7_BOSS_JINJO_PINK,   ASSET_3C1_MODEL_JINJO_PINK,   1, chBossJinjoAnimationInfo, chBossJinjo_update, chBossJinjo_update2, actor_draw, 0, 0, 1.0f, 0 };
ActorInfo chBossJinjoYellow = { MARKER_27E_BOSS_JINJO_YELLOW, ACTOR_3A8_BOSS_JINJO_YELLOW, ASSET_3BB_MODEL_JINJO_YELLOW, 1, chBossJinjoAnimationInfo, chBossJinjo_update, chBossJinjo_update2, actor_draw, 0, 0, 1.0f, 0 };

ParticleSettingsVelocityAccelerationPosition chBossJinjoSpriteSettings1 = { { { -420.0f, 410.0f, -420.0f }, { 480.0f, 860.0f, 480.0f } }, { { 0.0f, -1200.0f, 0.0f }, { 0.0f, -1200.0f, 0.0f } }, { { 0.0f, -20.0f, 0.0f }, { 0.0f, 20.0f, 0.0f } } };
ParticleSettingsVelocityPosition chBossJinjoSpriteSettings2 = { { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { { -80.0f, -80.0f, -80.0f }, { 80.0f, 80.0f, 80.0f } } };
f32 D_80391948[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
f32 D_80391958[4] = { 0.33f, 0.33f, 0.33f, 1.0f };
ParticleScaleAndLifetimeRanges sFightBlastParticleSettings = { { 0.1f, 0.1f }, { 10.0f, 10.0f }, { 0.0f, 0.01f }, { 0.8f, 0.8f }, 0.1f, 0.1f };

void chbossjinjo_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id, f32 scale) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setStartingScaleRange(pCtrl, scale * 0.35, scale * 0.65);
    particleEmitter_setFinalScaleRange(pCtrl, 0.0f, 0.0f);
    particleEmitter_func_802EF9F8(pCtrl, 0.5f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.0f, 3.3f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.35f);
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &chBossJinjoSpriteSettings1);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_emitN(pCtrl, count);
}

void chbossjinjo_createNonShrinkingSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id, f32 scale) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    f32 scale_adjusted = scale * 5.0;
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 9);
    particleEmitter_setParticleFramerateRange(pCtrl, 12.0f, 12.0f);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &chBossJinjoSpriteSettings2);
    particleEmitter_setStartingScaleRange(pCtrl, scale_adjusted, scale_adjusted);
    particleEmitter_setFinalScaleRange(pCtrl, scale_adjusted, scale_adjusted);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.0f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, scale * 0.5, scale * 0.5 * 1.5);
    particleEmitter_setFade(pCtrl, 0.7f, 0.8f);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_DEPTH);
    particleEmitter_emitN(pCtrl, count);
}

void chbossjinjo_func_8038C588(void) {
    chfinalboss_func_80386654(1.0f, D_80391958, D_80391948);
}

void chbossjinjo_func_8038C5BC(void) {
    chfinalboss_func_80386654(1.0f, D_80391948, D_80391958);
}

void chbossjinjo_spawnParticlesAtFinalBoss(Actor *this, enum asset_e sprite1_id, enum asset_e sprite2_id, f32 scale) {
    f32 position_finalboss[3];

    chfinalboss_getPosition(position_finalboss);
    chbossjinjo_createSpriteParticles(this->position, 32, sprite1_id, scale);
    chbossjinjo_createNonShrinkingSpriteParticles(this->position, 4, sprite2_id, scale);
    timedFunc_set_0(0.0f, chbossjinjo_func_8038C588);
    timedFunc_set_0(0.3f, chbossjinjo_func_8038C5BC);
}

void chbossjinjo_spawnAttackParticles(Actor *this) {
    s32 sparkle_sprite_id;
    s32 smoke_sprite_id;

    switch (this->marker->id) {
        default:
            sparkle_sprite_id = ASSET_718_SPRITE_SPARKLE_WHITE_2;
            smoke_sprite_id = ASSET_6C2_SPRITE_SMOKE_WHITE;
            break;

        case MARKER_27B_BOSS_JINJO_ORANGE:
            sparkle_sprite_id = ASSET_71B_SPRITE_SPARKLE_ORANGE_2;
            smoke_sprite_id = ASSET_6C5_SPRITE_SMOKE_ORANGE;
            break;

        case MARKER_27C_BOSS_JINJO_GREEN:
            sparkle_sprite_id = ASSET_719_SPRITE_SPARKLE_GREEN_2;
            smoke_sprite_id = ASSET_6C3_SPRITE_SMOKE_GREEN;
            break;

        case MARKER_27D_BOSS_JINJO_PINK:
            sparkle_sprite_id = ASSET_71A_SPRITE_SPARKLE_PINK_2;
            smoke_sprite_id = ASSET_6C6_SPRITE_SMOKE_PINK;
            break;

        case MARKER_27E_BOSS_JINJO_YELLOW:
            sparkle_sprite_id = ASSET_717_SPRITE_SPARKLE_YELLOW_2;
            smoke_sprite_id = ASSET_6C4_SPRITE_SMOKE_YELLOW;
            break;
    }

    chbossjinjo_spawnParticlesAtFinalBoss(this, sparkle_sprite_id, smoke_sprite_id, 1.0f);
}

void chbossjinjo_rotateYaw(Actor *this, s16 angle) {
    f32 old_yaw = this->yaw;

    old_yaw -= (time_getDelta() * angle) / 45.0;

    if (360.0f <= old_yaw) {
        old_yaw -= 360.0f;
    }
    else {
        if (old_yaw < 0.0f)
            old_yaw += 360.0f;
    }

    this->yaw = old_yaw;
}

void chbossjinjo_func_8038C79C(Actor *this) {
    int i;

    for (i = 0; i < 4; i++) {
        if (randf() < 0.3) {
            func_8033E73C(this->marker, i + 5, func_80329904);
            func_8033E3F0(8, this->marker->unk14_21);
        }
    }
}

void chBossJinjo_update(Actor *this){
    f32 time_delta = time_getDelta();
    f32 sp68[3];
    f32 velocity_player[3];
    f32 position_finalboss[3];
    f32 yaw_delta;
    bool inState3;
    s32 pad;
    s16 new_yaw;
    s16 old_yaw;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        func_80324CFC(0.0f, SFX_JINJO_STATUE_POWERUP, 32000);
        func_80324D2C(this->lifetime_value + 2.26, SFX_JINJO_STATUE_POWERUP);
    }

    func_8028E964(sp68);
    func_80257F18(this->position, sp68, &yaw_delta);
    old_yaw = (this->yaw * 182.04444);
    new_yaw = old_yaw - (s16) (yaw_delta * 182.04444);

    switch (this->state) {
        case BOSSJINJO_STATE_1_WAKE_UP:
            animctrl_setAnimTimer(this->animctrl, 0.0f);

            if (this->lifetime_value < 0.0) {
                subaddie_set_state_with_direction(this, BOSSJINJO_STATE_2_YAWN, 0.001f, 1);
            } else {
                this->lifetime_value -= time_delta;
            }
            
            break;

        case BOSSJINJO_STATE_2_YAWN:
            if (actor_animationIsAt(this, 0.44f)) {
                func_8030E878(SFX_105_EYRIE_YAWN, randf2(0.95f, 1.05f), 32000, this->position, 1000.0f, 5000.0f);
            }
            
            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state_with_direction(this, BOSSJINJO_STATE_3_SPIN_UP, 0.001f, 1);
                func_8030E878(0x3ee, randf2(0.95f, 1.05f), 32000, this->position, 5000.0f, 12000.0f);
            }
            break;

        case BOSSJINJO_STATE_3_SPIN_UP:
        case BOSSJINJO_STATE_4_ATTACK:
            inState3 = (this->state == BOSSJINJO_STATE_3_SPIN_UP);

            if (!inState3 || 0.1 < animctrl_getAnimTimer(this->animctrl)) {
                player_getVelocity(&velocity_player);

                velocity_player[0] *=  time_delta * 6.0f;
                velocity_player[1] *=  time_delta * 6.0f;
                velocity_player[2] *=  time_delta * 6.0f;

                velocity_player[0] = velocity_player[0] + sp68[0];
                velocity_player[1] = velocity_player[1] + sp68[1];
                velocity_player[2] = velocity_player[2] + sp68[2];

                velocity_player[0] -= this->position_x;
                velocity_player[1] -= this->position_y;
                velocity_player[2] -= this->position_z;

                velocity_player[0] *= time_delta * 3.0f;
                velocity_player[1] *= time_delta * 3.0f;
                velocity_player[2] *= time_delta * 3.0f;

                this->position_x = velocity_player[0] + this->position_x;
                this->position_y = velocity_player[1] + this->position_y;
                this->position_z = velocity_player[2] + this->position_z;

                if (inState3 ||  animctrl_getAnimTimer(this->animctrl) < 0.8) {
                    chbossjinjo_func_8038C79C(this);
                }
            }

            if (inState3) {
                if(animctrl_getAnimTimer(this->animctrl) < 0.2) {
                    chbossjinjo_rotateYaw(this, new_yaw);
                }
                
                if (actor_animationIsAt(this, 0.1f)) {
                    this->unk44_31 = func_8030ED2C(0x18, 3);
                    func_8030E2C4(this->unk44_31);
                    func_8025A6EC(COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7fff);
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 0.8f, 32750, this->position, 300, 2000);
                }

                if (actor_animationIsAt(this, 0.434f)) {
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 0.9f, 32750, this->position, 300, 2000);
                }

                if (actor_animationIsAt(this, 0.811f)) {
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 1.0f, 32750, this->position, 300, 2000);
                }
            } else {
                if (actor_animationIsAt(this, 0.214f)) {
                    FUNC_8030E8B4(SFX_C7_SHWOOP, 1.1f, 32750, this->position, 300, 2000);
                }

                if (actor_animationIsAt(this, 0.55f)) {
                    FUNC_8030E8B4(SFX_53_BANJO_HUIII, 1.5f, 32750, this->position, 300, 2000);
                }
                
                if (actor_animationIsAt(this, 0.85f)) {
                    if(func_8030E3FC(this->unk44_31)) {
                        func_8030E394(this->unk44_31);
                    }

                    sfxsource_playHighPriority(SFX_19_BANJO_LANDING_08);
                    func_8025A7DC(COMUSIC_43_ENTER_LEVEL_GLITTER);
                }
            }
            
            if (inState3) {
                if (actor_animationIsAt(this, 0.96f)) {
                    subaddie_set_state_with_direction(this, BOSSJINJO_STATE_4_ATTACK, 0.0f, -1);
                    actor_playAnimationOnce(this);
                }
            } else {
                if (actor_animationIsAt(this, 0.9f)) {
                    animctrl_setSmoothTransition(this->animctrl, FALSE);
                    subaddie_set_state_with_direction(this, BOSSJINJO_STATE_5_HIT, 0.001f, 1);
                    FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                    func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                    func_8034A174(this->marker->unk44, 0x1f, this->position);

                    this->velocity_x = (this->position_x - this->unk1C[0])/ time_delta;
                    this->velocity_y = (this->position_y - this->unk1C[1])/ time_delta;
                    this->velocity_z = (this->position_z - this->unk1C[2])/ time_delta;
                } else {
                    func_8034A174(this->marker->unk44, 0x1f, this->unk1C);
                }
            }
            break; 

        case BOSSJINJO_STATE_5_HIT:
            chfinalboss_getPosition(position_finalboss);
            position_finalboss[1] += 100.0f;
            chfinalboss_func_80387470(this, position_finalboss, 1200.0f, 3840.0f, 200.0f, 2500.0f, 70.0f);
            chbossjinjo_func_8038C79C(this);
            break;
    }
}

void fight_createBlastParticle(f32 position[3], enum asset_e model_id, f32 scale_ratio, f32 fade_in) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(1);
    f32 viewport[3];
    f32 velocity[3];

    viewport_getPosition_vec3f(viewport);
    velocity[0] = viewport[0] - position[0];
    velocity[1] = viewport[1] - position[1];
    velocity[2] = viewport[2] - position[2];
    ml_vec3f_set_length(velocity, 20.0f);
    
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleVelocityRange(pCtrl, velocity[0], velocity[1], velocity[2], velocity[0], velocity[1], velocity[2]);

    sFightBlastParticleSettings.unk20 = fade_in;
    sFightBlastParticleSettings.unk0[0] *= scale_ratio;
    sFightBlastParticleSettings.unk24 = fade_in;
    sFightBlastParticleSettings.unk0[1] *= scale_ratio;
    sFightBlastParticleSettings.unk8[0] *= scale_ratio;
    sFightBlastParticleSettings.unk8[1] *= scale_ratio;

    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &sFightBlastParticleSettings);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_DEPTH);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_emitN(pCtrl, 1);
}

void chBossJinjo_update2(Actor *this) {
    enum asset_e blast_asset;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOff(this);
        this->alpha_124_19 = 0x7d;
        actor_setOpacity(this, this->alpha_124_19);
        this->scale = (f64)this->scale + this->scale;
        subaddie_set_state_with_direction(this, BOSSJINJO_STATE_5_HIT, 0.001f, 1);
        func_80343DEC(this);
    }

    if (!chfinalboss_func_8038C298()) {
        this->unk58_0 = 0;
    } else {
        this->unk58_0 = 1;
        func_80343DEC(this);

        if (this->state == BOSSJINJO_STATE_5_HIT) {
            if(this->marker->unk14_21) {
                chbossjinjo_func_8038C79C(this);
            }

            if (0.98 < this->unk48) {
                func_8030E6A4(0x3ee, randf2(1.0f, 1.15f), 32000);
                timed_playSfx(0.1f, 0x416, 0.6f, 32000);
                marker_despawn(this->marker);

                switch (this->marker->id) {
                    case MARKER_27B_BOSS_JINJO_ORANGE:
                        blast_asset = ASSET_557_MODEL_ORANGE_JINJO_BLAST;
                        break;

                    case MARKER_27C_BOSS_JINJO_GREEN:
                        blast_asset = ASSET_558_MODEL_GREEN_JINJO_BLAST;
                        break;

                    case MARKER_27D_BOSS_JINJO_PINK:
                        blast_asset = ASSET_559_MODEL_PINK_JINJO_BLAST;
                        break;

                    case MARKER_27E_BOSS_JINJO_YELLOW:
                        blast_asset = ASSET_556_MODEL_YELLOW_JINJO_BLAST;
                        break;

                    default:
                        blast_asset = ASSET_556_MODEL_YELLOW_JINJO_BLAST;
                        break;
                }

                fight_createBlastParticle(this->position, blast_asset, 1.0f, 0.1f);
                func_802BB3DC(0, 12.0f, 0.4f);
            }
        }
    }
}

void chbossjinjo_attack(ActorMarker *marker) {
    Actor *actor_bossjinjo = marker_getActor(marker);

    chbossjinjo_spawnAttackParticles(actor_bossjinjo);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32000, actor_bossjinjo->position, 1000, 6500);
    marker_despawn(actor_bossjinjo->marker);
}

f32 chbossjinjo_getWakeUpTime(void) {
    return 2.26f;
}
