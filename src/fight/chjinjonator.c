#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern void func_80324CFC(f32, s32, s32);
extern void func_802F9E44(s32, f32, f32, f32, f32);

typedef struct {
    f32 velocity_move_up;
    f32 boss_scream_time;
    f32 position_finalboss[3];
    f32 sfx_volume;
    f32 sfx_volume_adjust;
    f32 boss_claw_sfx_volume;
    s32 final_attack_countdown;
    s32 hit_count;
    s32 attack_timer;
} ActorLocal_Jinjonator;

ActorAnimationInfo chJinjonatorAnimationInfo[] = {
   {0x000, 00000000},
   {0x275, 1000000.0f},
   {0x275, 3.3f},
   {0x276, 0.67f},
   {0x277, 1.167f},
   {0x27E, 2.5f},
   {0x27F, 4.0f},
   {0x262, 2.0f},
   {0x278, 1.75f},
   {0x27B, 2.25f},
   {0x27C, 0.33f},
   {0x27D, 0.8f},
   {0x280, 0.4f}  
};

ActorInfo chJinjonator = { MARKER_285_JINJONATOR, ACTOR_3AC_JINJONATOR, ASSET_551_MODEL_JINJONATOR, 1, chJinjonatorAnimationInfo, chjinjonator_update, actor_update_func_80326224, actor_draw, 0, 0, 1.0f, 0 };

s32 chJinjonatorHitYawValue[] = { 220, 150, 130, 180, 210, 170, 200, 150, 180 };
s32 chJinjonatorHitSounds[] = {
    COMUSIC_9A_JINJONATOR_HITS_GRUNTY_A,
    COMUSIC_9B_JINJONATOR_HITS_GRUNTY_B,
    COMUSIC_9C_JINJONATOR_HITS_GRUNTY_C,
    COMUSIC_9D_JINJONATOR_HITS_GRUNTY_D,
    COMUSIC_9E_JINJONATOR_HITS_GRUNTY_E,
    COMUSIC_9F_JINJONATOR_HITS_GRUNTY_F,
    COMUSIC_A0_JINJONATOR_HITS_GRUNTY_G,
    COMUSIC_A1_JINJONATOR_HITS_GRUNTY_H,
    COMUSIC_A2_JINJONATOR_HITS_GRUNTY_I
};

f32 D_80392920[3];

void chjinjonator_createSpriteParticles(f32 position[3], s32 count, enum asset_e sprite_id) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setAccelerationRange(pCtrl, 0.0f, -200.0f, 0.0f, 0.0f, -200.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -100.0f, -100.0f, -100.0f, 100.0f, 100.0f, 100.0f);
    particleEmitter_setStartingScaleRange(pCtrl, 0.5f, 0.65f);
    particleEmitter_setFinalScaleRange(pCtrl, 0.0f, 0.0f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 0.65f, 0.85f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.35f);
    particleEmitter_func_802EFA78(pCtrl, 1);
    particleEmitter_setDrawMode(pCtrl, 4);
    particleEmitter_emitN(pCtrl, count);
}

void chjinjonator_spawnSparkleParticles(Actor *this) {
    f32 position[3];
    int i;

    for (i = 0; i < 4; i++) {
        if (randf() < 0.3) {
            func_8034A174(this->marker->unk44, i + 5, position);
            chjinjonator_createSpriteParticles(position, 1, ASSET_718_SPRITE_SPARKLE_WHITE_2);
        }
    }
}

void chjinjonator_spawnAttackParticles(Actor *this, s32 hit_id){
    s32 sparkle_sprite_id;
    s32 smoke_sprite_id;
    
    switch (hit_id) {
        case 1:
        case 5:
            sparkle_sprite_id = ASSET_71B_SPRITE_SPARKLE_ORANGE_2;
            smoke_sprite_id = ASSET_6C5_SPRITE_SMOKE_ORANGE;
            break;

        case 2:
        case 6:
            sparkle_sprite_id = ASSET_719_SPRITE_SPARKLE_GREEN_2;
            smoke_sprite_id = ASSET_6C3_SPRITE_SMOKE_GREEN;
            break;

        case 3:
        case 7:
            sparkle_sprite_id = ASSET_71A_SPRITE_SPARKLE_PINK_2;
            smoke_sprite_id = ASSET_6C6_SPRITE_SMOKE_PINK;
            break;

        case 4:
        case 8:
            sparkle_sprite_id = ASSET_717_SPRITE_SPARKLE_YELLOW_2;
            smoke_sprite_id = ASSET_6C4_SPRITE_SMOKE_YELLOW;
            break;

        case 9:
        case 10:
            sparkle_sprite_id = ASSET_718_SPRITE_SPARKLE_WHITE_2;
            smoke_sprite_id = ASSET_6C2_SPRITE_SMOKE_WHITE;
            break;
    }
    chbossjinjo_spawnParticlesAtFinalBoss(this, sparkle_sprite_id, smoke_sprite_id, 2.0f);
}

void chjinjonator_803903C4(Actor *this) {
    animctrl_setSmoothTransition(this->animctrl, FALSE);
    subaddie_set_state_with_direction(this, JINJONATOR_STATE_7_ATTACK_END, 0.001f, 1);
    actor_loopAnimation(this);
}

void chjinjonator_8039040C(Actor *this) {
    ActorLocal_Jinjonator *local = (ActorLocal_Jinjonator *) &this->local;
    f32 tick = time_getDelta();
    
    local->sfx_volume = MIN(1.99, local->sfx_volume + local->sfx_volume_adjust * tick);
    sfxsource_playSfxAtVolume(this->unk44_31, local->sfx_volume);

    if (func_8030E3FC(this->unk44_31) == 0)
        func_8030E2C4(this->unk44_31);
}

void chjinjonator_update(Actor *this){
    ActorLocal_Jinjonator *local = (ActorLocal_Jinjonator *) &this->local;
    f32 time_delta = time_getDelta();
    f32 sp54 = animctrl_getDuration(this->animctrl);
    f32 sp50;
    s32 sp4C;
    f32 sp48;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        local->sfx_volume_adjust = 0.40000000000000013 / (this->lifetime_value + 3.3);
        local->sfx_volume = 0.7f;
        func_8025A6EC(JINGLE_MENACING_GRUNTILDA_B, 20000);
        func_8025A58C(0, 0x7fff);
        this->unk44_31 = func_8030ED2C(SFX_17A_SHIPHORN, 3);
        sfxsource_setSampleRate(this->unk44_31, 25000);
        sfxsource_playSfxAtVolume(this->unk44_31, local->sfx_volume);
        func_8030E2C4(this->unk44_31);
        local->attack_timer = 12;
    }
    
    if (0.0 < local->boss_scream_time) {
        local->boss_scream_time -= time_delta;
        return;
    }
    
    switch (this->state) {
        case JINJONATOR_STATE_1_RELEASE:
            chjinjonator_8039040C(this);
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            this->lifetime_value -= time_delta;

            if (this->lifetime_value < 0.0) {
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_2_WAKE_UP, 0.001f, 1);
                actor_playAnimationOnce(this);
            }

            break;

        case JINJONATOR_STATE_2_WAKE_UP:
            chjinjonator_8039040C(this);

            if (actor_animationIsAt(this, 0.27f))
                FUNC_8030E624(SFX_D0_GRIMLET_SQUEAK, 0.7f, 29000);

            if (actor_animationIsAt(this, 0.44f)) {
                FUNC_8030E624(SFX_176_JINJONATOR_JINJOOO_1, 1.0f, 25000);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 25000);
            }

            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_3_MOVE_UPWARD, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_8030E394(this->unk44_31);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
                local->velocity_move_up = (320.0f - this->position_y) * 0.5;
                func_80324CFC(0.0f, COMUSIC_8C_JINJONATOR_POWERUP, 32000);
            }

            break;

        case JINJONATOR_STATE_3_MOVE_UPWARD:
            chjinjonator_spawnSparkleParticles(this);

            if (this->position_y < 320.0f) {
                this->position_y = MIN(320.0f, this->position_y + local->velocity_move_up * time_delta);
            }

            if (320.0f == this->position_y) {
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_4_PREPARE_SPIN_UP, 0.001f, 1);
                actor_loopAnimation(this);
                local->boss_scream_time = chfinalboss_getScreamTime();
            }

            break;

        case JINJONATOR_STATE_4_PREPARE_SPIN_UP:
            chjinjonator_spawnSparkleParticles(this);
            subaddie_set_state_with_direction(this, JINJONATOR_STATE_5_SPIN_UP, 0.001f, 1);
            actor_playAnimationOnce(this);
            break;

        case JINJONATOR_STATE_5_SPIN_UP:
            chjinjonator_spawnSparkleParticles(this);

            if (actor_animationIsAt(this, 0.998f)) {
                animctrl_setSmoothTransition(this->animctrl, FALSE);
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_6_ATTACK, 0.0001f, 1);
                actor_loopAnimation(this);

                if (this->unk44_31 == 0) {
                    local->sfx_volume_adjust = 0.1f;
                    local->sfx_volume = 0.4f;
                    this->unk44_31 = func_8030ED2C(0x416, 3);
                    sfxsource_setSampleRate(this->unk44_31, 26000);
                    sfxsource_playSfxAtVolume(this->unk44_31, local->sfx_volume);
                    func_8030E2C4(this->unk44_31);
                }

                local->boss_claw_sfx_volume = 0.5f;
            }
            break;

        case JINJONATOR_STATE_6_ATTACK:
            this->position[1] = MIN(1e+8f, this->position[1] + 80.0f * time_delta);
            animctrl_setDuration(this->animctrl, MAX(0.4, sp54 - (0.5 * time_delta)));
            chjinjonator_spawnSparkleParticles(this);
            if(actor_animationIsAt(this, 0.25f) || actor_animationIsAt(this, 0.75f)){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, local->boss_claw_sfx_volume, 26000);
                local->boss_claw_sfx_volume += 0.04;
            }
            chjinjonator_8039040C(this);
            if(actor_animationIsAt(this, 0.5f)){
                if(--local->attack_timer <= 0){
                    chjinjonator_803903C4(this);
                    FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                    func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                    if((u8)this->unk44_31){
                        func_8030E394(this->unk44_31);
                        func_8030DA44(this->unk44_31);
                        this->unk44_31 = 0;
                    }
                    func_80324D2C(0.0f, COMUSIC_8C_JINJONATOR_POWERUP);
                    func_8034A174(this->marker->unk44, 0x1f, this->position);
                    this->velocity[0] = (this->position[0] - this->unk1C[0]) / time_delta;
                    this->velocity[1] = (this->position[1] - this->unk1C[1]) / time_delta;
                    this->velocity[2] = (this->position[2] - this->unk1C[2]) / time_delta;
                }
                
            }
            else{
                func_8034A174(this->marker->unk44, 0x1f, this->unk1C);
            }
            break;

        case JINJONATOR_STATE_7_ATTACK_END:
            sp50 = local->hit_count*0.11 + 1.0;
            chjinjonator_spawnSparkleParticles(this);
            chfinalboss_getPosition(local->position_finalboss);
            local->position_finalboss[1] += 100.0f;
            chfinalboss_func_80387470(this, local->position_finalboss, sp50*2400.0f, sp50*2400.0f*4.2, 170.0f, sp50*2500.0f, 0.0f);
            break;

        case JINJONATOR_STATE_8:
            if(actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f))
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1.0f, 28000);
            
            if(actor_animationIsAt(this, 0.999f)){
                func_8034A174(this->marker->unk44, 0x1f, this->position);
                chjinjonator_803903C4(this);
                FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;
            }

            break;
        
        case JINJONATOR_STATE_9_FINAL_ATTACK_POWER_UP:
            if (actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f)) {
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1.0f, 28000);
            }

            
            if (actor_animationIsAt(this, 0.8f)) {
                sp4C = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
                func_802F9F80(sp4C, 0.0f, 5.92f, 0.0f);
                func_802F9E44(sp4C, 0.1f, 5.92f, 0.3f, 1.0f);
                func_802FA060(sp4C, 32000, 32000, 0.0f);
            }

            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_10_FINAL_ATTACK_PREPARE, 0.001f, 1);
                actor_loopAnimation(this);
                local->final_attack_countdown = 14;
            }
            break;

        case JINJONATOR_STATE_10_FINAL_ATTACK_PREPARE:
            if (actor_animationIsAt(this, 0.999f)) {
                local->final_attack_countdown--;
            }

            if (local->final_attack_countdown == 2 && actor_animationIsAt(this, 0.1f)) {
                FUNC_8030E624(SFX_176_JINJONATOR_JINJOOO_1, 1.0f, 32000);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 32000);
            }

            if (local->final_attack_countdown <= 0) {
                s32 text_id;
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_11_FINAL_ATTACK, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_802BB41C(0);
                text_id = 0x115e + randi2(0,5);
                gcdialog_showText(text_id, 0x20, 0, 0, 0, 0);
            }
            break;

        case JINJONATOR_STATE_11_FINAL_ATTACK:
            if (actor_animationIsAt(this, 0.999f)) {
                func_8034A174(this->marker->unk44, 0x1f, this->position);
                FUNC_8030E624(SFX_17B_AIRPLANE_FALLING, 1.0f, 32000);
                FUNC_8030E624(SFX_147_GRUNTY_SPELL_ATTACK_2, 1.0f, 32000);
                animctrl_setSmoothTransition(this->animctrl, 0);
                subaddie_set_state_with_direction(this, JINJONATOR_STATE_12_FINAL_ATTACK_END, 0.001f, 1);
                actor_playAnimationOnce(this);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;
            }
            
            break;

        case JINJONATOR_STATE_12_FINAL_ATTACK_END:
            sp48 = local->hit_count * 0.11 + 1.0;
            chjinjonator_spawnSparkleParticles(this);
            chfinalboss_getPosition(local->position_finalboss);
            local->position_finalboss[1] += 100.0f; 
            chfinalboss_func_80387470(this, local->position_finalboss, sp48*2400.0f, sp48*2400.0f*4.2, 170.0f, sp48*2500.0f, 0.0f);
            break;
    }

    func_8034A174(this->marker->unk44, 0x1f, D_80392920);
}

void chjinjonator_attack(ActorMarker *marker, s32 hit_count, bool mirrored) {
    Actor *actor_jinjonator = marker_getActor(marker);
    ActorLocal_Jinjonator *local = (ActorLocal_Jinjonator *) &actor_jinjonator->local;
    s32 pad;
    
    func_8025A6EC(chJinjonatorHitSounds[hit_count - 1], 20000);

    chjinjonator_spawnAttackParticles(actor_jinjonator, hit_count);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32000, actor_jinjonator->position, 1000, 6500);

    actor_jinjonator->velocity[2] = 0.0f;
    actor_jinjonator->velocity[1] = 0.0f;
    actor_jinjonator->velocity[0] = 0.0f;
    
    actor_jinjonator->yaw = (f32)chJinjonatorHitYawValue[hit_count - 1];
    if (mirrored) {
        actor_jinjonator->yaw = (f32) (actor_jinjonator->yaw + 180.0f);
    }

    local->hit_count = hit_count;
    animctrl_setSmoothTransition(actor_jinjonator->animctrl, 1);
    actor_playAnimationOnce(actor_jinjonator);

    if (&chJinjonatorHitYawValue[hit_count] >= chJinjonatorHitSounds) {
        subaddie_set_state_with_direction(actor_jinjonator, JINJONATOR_STATE_9_FINAL_ATTACK_POWER_UP, 0.001f, 1);
        return;
    }

    subaddie_set_state_with_direction(actor_jinjonator, JINJONATOR_STATE_8, 0.001f, 1);
    animctrl_setDuration(actor_jinjonator->animctrl, (f32) (1.75 - 0.11 * local->hit_count));
}

void chjinjonator_finalAttack(ActorMarker *marker) {
    Actor *actor = marker_getActor(marker);
    chjinjonator_spawnAttackParticles(actor, 10);
    marker_despawn(actor->marker);
}

f32 chjinjonator_80391234(void) {
    return 3.3f;
}

f32 chjinjonator_80391240(void) {
    return 2.0;
}

f32 chjinjonator_80391250(void) {
    return 4.62f;
}

bool chjinjonator_8039125C(ActorMarker *marker) {
    u32 state = (u32) (marker_getActor(marker))->state;

    if (state == JINJONATOR_STATE_7_ATTACK_END || state == JINJONATOR_STATE_12_FINAL_ATTACK_END) {
        return TRUE;
    }

    return FALSE;
}

void chjinjonator_8039129C(f32 arg0[3]) {
    arg0[0] = D_80392920[0];
    arg0[1] = D_80392920[1];
    arg0[2] = D_80392920[2];
}
