#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"
#include "core2/particle.h"

extern void func_80324CFC(f32, s32, s32);
extern Actor *func_80325CAC(ActorMarker*, Gfx**, Mtx**, Vtx **);
bool func_80320C94(f32 [3], f32[3], f32, f32[3], s32, u32);
f32 func_8033229C(ActorMarker *);

typedef struct chspellfireball_s {
    f32 explosion_lifetime;
} ActorLocal_SpellFireball;

/* .data */
ActorInfo chSpellFireball = { MARKER_25C_GRUNTY_SPELL_FIREBALL,     ACTOR_389_GRUNTY_SPELL_FIREBALL,     ASSET_541_SPRITE_FIREBALL_SPELL_ATTACK, 1, NULL, chSpellFireball_update, actor_update_func_80326224, actor_draw,    0, 0, 1.0f, 0 };
ActorInfo chSpellGreen =    { MARKER_280_GRUNTY_SPELL_GREEN_ATTACK, ACTOR_3AA_GRUNTY_SPELL_GREEN_ATTACK, ASSET_6C9_SPRITE_GREEN_SPELL_ATTACK,    1, NULL, chSpellFireball_update, actor_update_func_80326224, func_80325CAC, 0, 0, 1.0f, 0 };

static s32 sFightSmokeColor[3] = { 186, 186, 186 };
ParticleSettingsVelocityPosition sFightSmokeVelocityPosition = { { { -70.0f, 50.0f, -70.0f }, { 70.0f, 100.0f, 70.0f } }, { { -55.0f, 0.0f, -55.0f }, { 55.0f, 20.0f, 55.0f } } };
static f32 D_80391B84[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
static f32 D_80391B94[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
static s32 sFightExplosionStartFrameRange[2] = { 1, 9 };
static f32 sFightExplosionScaleRange[4] = { 4.5f, 4.5f, 4.5f, 4.5f };
static f32 sFightExplosionLifetimeRange[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
static f32 D_80391BCC[4] = { 0.0f, 0.0f, 0.85f, 1.35f };
static f32 sFightExplosionFadeRange[2] = { 0.6f, 0.7f };
static f32 sFightExplosionSpawnPositionRange[6] = { -130.0f, 0.0f, -130.0f, 130.0f, 0.0f, 130.0f };
static f32 D_80391BFC[4] = { 1.1f, 1.1f, 4.0f, 5.4f };
static f32 D_80391C0C[6] = { -20.0f, 0.0f, -20.0f, 20.0f, 40.0f, 20.0f };
static f32 D_80391C24[6] = { 0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f };
static f32 D_80391C3C[6] = { -420.0f, 410.0f, -420.0f, 480.0f, 860.0f, 480.0f };
static f32 D_80391C54[4] = { 0.35f, 0.65f, 0.0f, 0.0f };
static f32 D_80391C64[4] = { 0.0f, 0.01f, 2.0f, 2.3f };
static f32 D_80391C74[2] = { 0.0f, 0.35f };
static f32 D_80391C7C[6] = { 0.0f, 50.0f, 0.0f, 0.0f, 50.0f, 0.0f };
static f32 D_80391C94[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; 
static f32 D_80391CA4[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; 
static f32 D_80391CB4[2] = { 0.0f, 0.0f }; 
static f32 D_80391CBC[4] = { 0.0f, 0.0f, 0.2f, 0.25f };
static f32 D_80391DCC[2] = { 2.3f, 2.5f };
static f32 D_80391DD4[6] = { 0.0f, 0.0f, 0.34f, 0.34f, 0.7f, 0.8f };
static s32 sFightExplosionStartFrameRange2[2] = { 2, 15 };
static f32 D_80391CF4[4] = { 2.0f, 2.0f, 0.4f, 0.4f };
static f32 D_80391D04[4] = { 0.0f, 0.0f, 0.24f, 0.24f };
static f32 D_80391D14[2] = { 0.1f, 0.2f };
static f32 D_80391D1C[4] = { 0.0f, 0.0f, 0.44f, 0.44f };
static f32 D_80391D2C[2] = { 0.4f, 0.5f };
static f32 D_80391D34[6] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
static f32 sFightUnused1[6] = { -50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f };
static f32 sFightUnused2[6] = { 0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f };
static f32 sFightUnused3[6] = { -260.0f, -260.0f, -260.0f, 260.0f, 260.0f, 260.0f };
static f32 sFightUnused4[4] = { 0.15f, 0.3f, 0.0f, 0.0f }; 
static f32 sFightUnused5[4] = { 0.0f, 0.01f, 0.7f, 0.8f }; 
static f32 sFightUnused6[2] = { 0.0f, 0.65f }; 
static u8 sFightPlayerHitBySpellInPhase1;
static u8 sFightPlayerHitBySpellInPhase2;
static u8 sFightPlayerHitBySpellInPhase3;
static u8 sFightPlayerHitBySpellInPhase4;
static u8 sFightPlayerHitBySpellInPhase5;
static u8 sFightLastSpellFired; // The big green spell that Gruntilda fires before she falls off the tower

void fight_setPositionWithDisplacement(ActorMarker *marker, f32 *position) {
    Actor *actor;

    actor = marker_getActor(marker);
    actor->position_x = position[0];
    actor->position_y = position[1];
    actor->position_z = position[2];
    actor->position_y = actor->position_y + 210.0f;
}

void fight_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite, f32 position_range[6], f32 acceleration_range[6], f32 velocity_range[6], f32 scale_range[4], f32 lifetime_range[4], f32 fade[2]) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setSpawnPositionRange(pCtrl, position_range[0], position_range[1], position_range[2], position_range[3], position_range[4], position_range[5]);
    particleEmitter_setAccelerationRange(pCtrl, acceleration_range[0], acceleration_range[1], acceleration_range[2], acceleration_range[3], acceleration_range[4], acceleration_range[5]);
    particleEmitter_setParticleVelocityRange(pCtrl, velocity_range[0], velocity_range[1], velocity_range[2], velocity_range[3], velocity_range[4], velocity_range[5]);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    particleEmitter_setStartingScaleRange(pCtrl, scale_range[0], scale_range[1]);
    particleEmitter_setFinalScaleRange(pCtrl, scale_range[2], scale_range[3]);
    particleEmitter_func_802EF9F8(pCtrl, 0.5f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    particleEmitter_setSpawnIntervalRange(pCtrl, lifetime_range[0], lifetime_range[1]);
    particleEmitter_setParticleLifeTimeRange(pCtrl, lifetime_range[2], lifetime_range[3]);
    particleEmitter_setFade(pCtrl, fade[0], fade[1]);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_emitN(pCtrl, count);
}

void fight_createAnimatedSpriteParticles(f32 position[3], enum asset_e sprite, s32 count, s32 staring_frame_range[2], f32 position_range[6], f32 scale_range[4], f32 lifetime_range[4], f32 fade[2]) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite);
    particleEmitter_setStartingFrameRange(pCtrl, staring_frame_range[0], staring_frame_range[1]);
    particleEmitter_setParticleFramerateRange(pCtrl, 8.0f, 8.0f);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setSpawnPositionRange(pCtrl, position_range[0], position_range[1], position_range[2], position_range[3], position_range[4], position_range[5]);
    particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    particleEmitter_setStartingScaleRange(pCtrl, scale_range[0], scale_range[1]);
    particleEmitter_setFinalScaleRange(pCtrl, scale_range[2], scale_range[3]);
    particleEmitter_setSpawnIntervalRange(pCtrl, lifetime_range[0], lifetime_range[1]);
    particleEmitter_setParticleLifeTimeRange(pCtrl, lifetime_range[2], lifetime_range[3]);
    particleEmitter_setFade(pCtrl, fade[0], fade[1]);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_DEPTH);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_emitN(pCtrl, count);
}

void fight_createSmokeParticles(f32 position[3], s32 count, f32 *lifetime_and_spawn_range) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(pCtrl, sFightSmokeColor);
    particleEmitter_setAlpha(pCtrl, 235);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &sFightSmokeVelocityPosition);
    particleEmitter_setStartingScaleRange(pCtrl, 0.1f, 0.2f);
    particleEmitter_setFinalScaleRange(pCtrl, 3.6f, 4.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, lifetime_and_spawn_range[0], lifetime_and_spawn_range[1]);
    particleEmitter_setParticleLifeTimeRange(pCtrl, lifetime_and_spawn_range[2], lifetime_and_spawn_range[3]);
    particleEmitter_setFade(pCtrl, 0.05f, 0.1f);
    particleEmitter_setDrawMode(pCtrl, PART_EMIT_NO_DEPTH);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_emitN(pCtrl, count);
}

void chSpellFireball_func_8038F01C(void) {
    chfinalboss_func_80386654(1.0f, D_80391B94, D_80391B84);
}

void chSpellFireball_func_8038F050(void) {
    chfinalboss_func_80386654(1.0f, D_80391B84, D_80391B94);
}

void chSpellFireball_createExplosionParticles(ActorMarker *marker) {
    static f32 position[3];
    Actor *actor = marker_getActor(marker);
    ActorLocal_SpellFireball *local = (ActorLocal_SpellFireball *) &actor->local;
    
    position[0] = actor->position_x;
    position[1] = actor->position_y;
    position[2] = actor->position_z;
    position[1] += 120.0f;

    if (actor->state != SPELLFIREBALL_STATE_2_DESPAWN) {
        FUNC_8030E8B4(SFX_148_GRUNTY_SPELL_LANDING, 1.0f, 32000, actor->position, 1000, 3500);
        timedFunc_set_0(0.0f, chSpellFireball_func_8038F01C);
        timedFunc_set_0(0.3f, chSpellFireball_func_8038F050);
        actor->unk58_0 = 0;
        actor->scale *= 1.6;
        if (actor->marker->id != MARKER_280_GRUNTY_SPELL_GREEN_ATTACK) {
            fight_createSpriteParticles(actor->position, 4, ASSET_713_SPRITE_SPARKLE_YELLOW, D_80391C0C, D_80391C24, D_80391C3C, D_80391C54, D_80391C64, D_80391C74);
            fight_createSpriteParticles(actor->position, 4, ASSET_715_SPRITE_SPARKLE_RED, D_80391C0C, D_80391C24, D_80391C3C, D_80391C54, D_80391C64, D_80391C74);
            fight_createSmokeParticles(actor->position, 3, D_80391BFC);
            fight_createAnimatedSpriteParticles(position, ASSET_4A0_SPRITE_EXPLOSION, 1, sFightExplosionStartFrameRange, sFightExplosionSpawnPositionRange, sFightExplosionScaleRange,  sFightExplosionLifetimeRange, sFightExplosionFadeRange);
            position[1] -= 50.0f;
            fight_createAnimatedSpriteParticles(position, ASSET_6C1_SPRITE_SMOKE, 2, sFightExplosionStartFrameRange, sFightExplosionSpawnPositionRange, sFightExplosionScaleRange,  sFightExplosionLifetimeRange, sFightExplosionFadeRange);
        } else {
            fight_createSpriteParticles(actor->position, 4, ASSET_713_SPRITE_SPARKLE_YELLOW, D_80391C0C, D_80391C24, D_80391C3C, D_80391C54, D_80391BCC, D_80391C74);
            fight_createSmokeParticles(actor->position, 3, D_80391BFC);
            fight_createBlastParticle(actor->position, ASSET_558_MODEL_GREEN_JINJO_BLAST, 0.15f, 0.5f);
            actor->position_y += 260.0f;
            chbossjinjo_spawnParticlesAtFinalBoss(actor, 0x712, ASSET_6C3_SPRITE_SMOKE_GREEN, 1.6f);
        }
        
        local->explosion_lifetime = 0.66f;
        subaddie_set_state(actor, SPELLFIREBALL_STATE_2_DESPAWN);
    }
}

void chSpellFireball_collisionDie(ActorMarker *marker, ActorMarker *other) {
    if ((other->id == MARKER_276_STONE_JINJO) ||
        (other->id == MARKER_27A_JINJO_STATUE_BASE) ||
        (other->id == MARKER_27F_JINJONATOR_STATUE_BASE))
    {
        return;
    }

    chSpellFireball_createExplosionParticles(marker);

    switch(volatileFlag_getN(VOLATILE_FLAG_23_FINAL_BOSS_PHASE, 3)) {
        case FINALBOSS_PHASE_1_BROOMSTICK:
            if (!sFightPlayerHitBySpellInPhase1 && gcdialog_showText(randi2(0, 5) + ASSET_10F2_TEXT_FINALBOSS_PHASE_1_OPTION_1, 0, 0, 0, 0, 0))
            {
                sFightPlayerHitBySpellInPhase1 = TRUE;
            }
            break;

        case FINALBOSS_PHASE_2_AIR:
            if (!sFightPlayerHitBySpellInPhase2 && gcdialog_showText(randi2(0, 5) + ASSET_110B_TEXT_FINALBOSS_PHASE_2_OPTION_1, 0, 0, 0, 0, 0))
            {
                sFightPlayerHitBySpellInPhase2 = TRUE;
            }
            break;

        case FINALBOSS_PHASE_3_FLIGHT:
            if (!sFightPlayerHitBySpellInPhase3 && gcdialog_showText(randi2(0, 5) + ASSET_1122_TEXT_FINALBOSS_PHASE_3_OPTION_1, 0, 0, 0, 0, 0))
            {
                sFightPlayerHitBySpellInPhase3 = TRUE;
            }
            break;

        case FINALBOSS_PHASE_4_JINJOS:
            if (!sFightPlayerHitBySpellInPhase4 &&
                chfinalboss_isJinjoSpawned() &&
                gcdialog_showText(randi2(0, 5) + ASSET_113B_TEXT_FINALBOSS_PHASE_4_OPTION_1, 0, 0, 0, 0, 0))
            {
                sFightPlayerHitBySpellInPhase4 = TRUE;
            }
            break; 

        case FINALBOSS_PHASE_5_JINJONATOR:
            if (!sFightPlayerHitBySpellInPhase5 &&
                chfinalboss_isJinjonatorSpawned() &&
                gcdialog_showText(randi2(0, 5) + ASSET_1154_TEXT_FINALBOSS_PHASE_5_OPTION_1, 0, 0, 0, 0, 0))
            {
                sFightPlayerHitBySpellInPhase5 = TRUE;
            }
            break; 
    }
}

bool chSpellFireball_isPositionOverThreshold(f32 *position, f32 distance) {
    if (((position[0] * position[0]) + (position[2] * position[2])) < distance) {
        return TRUE;
    }

    return FALSE;
}

void chSpellFireball_free(Actor *this) {
    func_80324D2C(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER);
}

void chSpellFireball_update(Actor *this) {
    static f32 old_position[3];
    static f32 D_80392908[3];
    static f32 scale_ratio;

    ActorLocal_SpellFireball *local = (ActorLocal_SpellFireball *)&this->local;
    f32 time_delta = time_getDelta();

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, chSpellFireball_collisionDie);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        this->lifetime_value = 8.0f;
        this->scale = 0.1f;

        if (this->marker->id == MARKER_280_GRUNTY_SPELL_GREEN_ATTACK) {
            actor_collisionOff(this);
            marker_setFreeMethod(this->marker, chSpellFireball_free);
            func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
            timed_playSfx(0.0f, SFX_113_PAD_APPEARS, 1.0f, 32000);
            timed_playSfx(0.75f, 0x415, 1.0f, 32000);
            timed_playSfx(2.0f, 0x415, 1.0f, 32000);
        } else {
            func_80324D54(0.26f, SFX_14F_FIREWORK_WHISTLING, 1.0f, 0x61A8, this->position, 1000.0f, 7500.0f);
            func_80324D54(0.4f, SFX_14E_SOFT_EXPLOSION, 1.0f, 0x61A8, this->position, 500.0f, 4500.0f);
        }
    }

    if (sFightLastSpellFired && this->marker->id == MARKER_280_GRUNTY_SPELL_GREEN_ATTACK) {
        ncStaticCamera_rotateToTarget(this->position);
    }

    switch(this->state) {
        case SPELLFIREBALL_STATE_1_ACTIVE:
            scale_ratio = time_delta * 1.4;
            this->scale = (this->scale + scale_ratio < 1.0) ? this->scale + scale_ratio : 1.0f;

            switch (this->marker->id) {
                case MARKER_25C_GRUNTY_SPELL_FIREBALL:
                    fight_createAnimatedSpriteParticles(this->position, ASSET_4A0_SPRITE_EXPLOSION, 1, sFightExplosionStartFrameRange2, D_80391D34, D_80391CF4, D_80391D04, D_80391D14);
                    break;

                case MARKER_280_GRUNTY_SPELL_GREEN_ATTACK:
                    fight_createAnimatedSpriteParticles(this->position, ASSET_6C9_SPRITE_GREEN_SPELL_ATTACK, 1, sFightExplosionStartFrameRange2, D_80391D34, D_80391CF4, D_80391D1C, D_80391D2C);
                    globalTimer_getTime();
                    break;
            }

            old_position[0] = this->position[0];
            old_position[1] = this->position[1];
            old_position[2] = this->position[2];

            this->position[0] +=  this->velocity_x * time_delta;
            this->position[1] +=  this->velocity_y * time_delta;
            this->position[2] +=  this->velocity_z * time_delta;

            this->velocity[0] += this->unk1C[0] * time_delta;
            this->velocity[1] += this->unk1C[1] * time_delta;
            this->velocity[2] += this->unk1C[2] * time_delta;

            this->pitch +=  200.0f * time_delta;
            this->yaw += 200.0f * time_delta;

            if ((this->position_y < -2500.0f) ||
                (5000.0f < this->position_y) ||
                (!chSpellFireball_isPositionOverThreshold(this->position, 100000000.0f)))
            {
                marker_despawn(this->marker);
            } else {
                if ((this->position_y < 300.0f) &&
                    (chSpellFireball_isPositionOverThreshold(this->position, 16000000.0f)) &&
                    (func_80320C94(old_position, this->position, func_8033229C(this->marker), D_80392908, 8, 0x40000000)))
                {
                    chSpellFireball_createExplosionParticles(this->marker);
                    return;
                }
            }
            
            if ((this->marker->id != MARKER_280_GRUNTY_SPELL_GREEN_ATTACK) && func_8028F25C()) {
                chSpellFireball_createExplosionParticles(this->marker);
            } else {
                if (0.0 <= this->lifetime_value) {
                    this->lifetime_value -= time_delta;
                } else {
                    chSpellFireball_createExplosionParticles(this->marker);
                }
            }

            break;
            
        case SPELLFIREBALL_STATE_2_DESPAWN:
            if (local->explosion_lifetime < 0.0) {
                marker_despawn(this->marker);
            } else {
                local->explosion_lifetime -= time_delta;
            }

            break;
    }
}

void chSpellFireball_func_8038FB84(ActorMarker *marker, f32 *position, f32 *velocity, f32 *arg3) {
    Actor *actor = marker_getActor(marker);

    actor->position_x = position[0];
    actor->position_y = position[1];
    actor->position_z = position[2];
    actor->velocity_x = velocity[0];
    actor->velocity_y = velocity[1];
    actor->velocity_z = velocity[2];
    actor->unk1C_x = arg3[0];
    actor->unk1C_y = arg3[1];
    actor->unk1C_z = arg3[2];
}

void chSpellFireball_resetSpellHits(void) {
    sFightPlayerHitBySpellInPhase1 = FALSE;
    sFightPlayerHitBySpellInPhase2 = FALSE;
    sFightPlayerHitBySpellInPhase3 = FALSE;
    sFightPlayerHitBySpellInPhase4 = FALSE;
    sFightPlayerHitBySpellInPhase5 = FALSE;
}

void chSpellFireball_setLastSpellFired(bool value) {
    sFightLastSpellFired = value;
}
