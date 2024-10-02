#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

typedef struct {
    u8 sfxsourceIdx;
} ActorLocal_BossJinjoBase;

ActorInfo chBossJinjoBase = { MARKER_27A_JINJO_STATUE_BASE, ACTOR_3A2_JINJO_STATUE_BASE, ASSET_543_MODEL_JINJO_STATUE_BASE, 1, NULL, chBossJinjoBase_update, actor_update_func_80326224, actor_draw, 0, 2048, 0.0f, 0 };

s32 chBossJinjoBase_SmokeColor[3] = { 200, 200, 160 };
ParticleScaleAndLifetimeRanges chBossJinjoBase_SmokeScaleAndLifetimeSettings = { {1.0f, 1.0f}, {1.7f, 2.7f}, {0.0f, 0.05f}, {2.6f, 3.4f}, 0.0f, 0.1f };

void chbossjinjobase_spawnStoneJinjo(ActorMarker *marker) {
    Actor *actor_bossjinjobase = marker_getActor(marker);
    Actor *childactor_stonejinjo = spawn_child_actor(ACTOR_3A1_STONE_JINJO, &actor_bossjinjobase);

    childactor_stonejinjo->unkF4_8 = actor_bossjinjobase->unkF4_8;
    childactor_stonejinjo->position_y = childactor_stonejinjo->position_y + 172.0f;
    actor_bossjinjobase->unk100 = childactor_stonejinjo->marker;
}

void chBossJinjoBase_createSmokeParticles(f32 position[3], s32 count) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(pCtrl, chBossJinjoBase_SmokeColor);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setSpawnPositionRange(pCtrl, -90.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -170.0f, 0.0f, -170.0f, 170.0f, 100.0f, 170.0f);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &chBossJinjoBase_SmokeScaleAndLifetimeSettings);
    particleEmitter_emitN(pCtrl, count);
}

void chBossJinjoBase_func_8038D3DC(Actor *this, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 tmp = func_8034C2C4(this->marker, arg1);
    
    if (tmp) {
        func_8034DE60(tmp, arg2, arg3, arg4, 1);
    }
}

void chBossJinjoBase_getHitByEgg(ActorMarker *this, ActorMarker *other) {
    Actor *actor_bossjinjobase = marker_getActor(this);

    if (actor_bossjinjobase->state != CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO) {
        comusic_playTrack(COMUSIC_2B_DING_B);
        actor_bossjinjobase->unk38_31++;

        if (actor_bossjinjobase->unk38_31 >= 3) {
            subaddie_set_state(actor_bossjinjobase, CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO);
            chstonejinjo_breakOpen(actor_bossjinjobase->unk100);
            chBossJinjoBase_func_8038D3DC(actor_bossjinjobase, 0x19A, -100.0f, 0.0f, 1.2f);
            func_80324D54(1.2f, SFX_90_SWITCH_PRESS, 1.0f, 32000, actor_bossjinjobase->position, 1000.0f, 2000.0f);
        }
    }
}

void chBossJinjoBase_free(Actor *this) {
    ActorLocal_BossJinjoBase *local = (ActorLocal_BossJinjoBase *) &this->local;

    if ((u8)this->unk44_31 != 0) {
        sfxsource_freeSfxsourceByIndex(this->unk44_31);
        this->unk44_31 = 0;
    }
    if (local->sfxsourceIdx != 0) {
        sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
        local->sfxsourceIdx = 0;
    }
}

void chBossJinjoBase_update(Actor *this) {
    ActorLocal_BossJinjoBase *local = (ActorLocal_BossJinjoBase *) &this->local;
    f32 delta_time = time_getDelta();
    u32 rumbling = globalTimer_getTime() & 0xF;
    Actor *actor_stonejinjo;
    f32 y_delta;
    f32 position_delta[3];

    this->unkF4_29 = 0;
    marker_loadModelBin(this->marker);

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chBossJinjoBase_getHitByEgg, NULL);
        marker_setFreeMethod(this->marker, chBossJinjoBase_free);
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOn(this);
        this->unk38_31 = 0;
        this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(this->unk44_31, SFX_3F9_UNKNOWN);
        func_8030DD14(this->unk44_31, 2);
        sfxsource_playSfxAtVolume(this->unk44_31, 1.4f);
        sfxsource_setSampleRate(this->unk44_31, 32000);
        local->sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(local->sfxsourceIdx, SFX_405_UNKNOWN);
        func_8030DD14(local->sfxsourceIdx, 2);
        sfxsource_playSfxAtVolume(local->sfxsourceIdx, 0.7f);
        sfxsource_setSampleRate(local->sfxsourceIdx, 12000);
        FUNC_8030E624(SFX_3F6_RUBBING, 0.6f, 20000);
        chBossJinjoBase_func_8038D3DC(this, 0x19a, 0.0f, -200.0f, 0.0f);
        TUPLE_COPY(this->unk1C, this->position);
        this->position_y = -400.0f;

        if (0.0f != this->lifetime_value)
            this->velocity_y = 400.0f / this->lifetime_value;
        else
            this->velocity_y = 100.0f;
        
        func_802BB3DC(0, 8.0f, 0.92f);
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_3AD_JINJONATOR_STATUE_BASE_ACTIVATOR, *(s32*)&this->unk1C[0], *(s32*)&this->unk1C[1], *(s32*)&this->unk1C[2]);
        chBossJinjoBase_createSmokeParticles(this->unk1C, 0x10);
        SPAWNQUEUE_ADD_1(chbossjinjobase_spawnStoneJinjo, this->marker);
    }
    else {
        if(this->state == CHBOSSJINJOBASE_STATE_1_RAISE) {
            actor_stonejinjo = marker_getActor(this->unk100);
            y_delta = this->velocity_y * delta_time;

            if(this->position_y + y_delta < this->unk1C[1]) {
                if( !fileProgressFlag_get(FILEPROG_D2_HAS_SPAWNED_A_JINJO_STATUE_IN_FINAL_FIGHT) || this->unkF4_8 == 1) {
                    func_8030E2C4(this->unk44_31);
                    func_8030E2C4(local->sfxsourceIdx);
                }
                
                position_delta[0] = (rumbling & 1) ? 3.0f : -3.0f;
                position_delta[1] = y_delta;
                position_delta[2] = (rumbling & 2) ? 3.0f : -3.0f;

                this->position_x = this->unk1C[0];
                this->position_z = this->unk1C[2];
                this->position_x = position_delta[0] + this->position_x;
                this->position_y = position_delta[1] + this->position_y;
                this->position_z = position_delta[2] + this->position_z;

                actor_stonejinjo->position_x = this->unk1C[0];
                actor_stonejinjo->position_z = this->unk1C[2];
                actor_stonejinjo->position_x = position_delta[0] + actor_stonejinjo->position_x;
                actor_stonejinjo->position_y = position_delta[1] + actor_stonejinjo->position_y;
                actor_stonejinjo->position_z = position_delta[2] + actor_stonejinjo->position_z;
            }
            else {
                subaddie_set_state(this, CHBOSSJINJOBASE_STATE_2_DEFAULT);
                sfxsource_freeSfxsourceByIndex(this->unk44_31);
                this->unk44_31 = 0;
                sfxsource_freeSfxsourceByIndex(local->sfxsourceIdx);
                local->sfxsourceIdx = 0;
                TUPLE_COPY(this->position, this->unk1C);
                TUPLE_COPY(actor_stonejinjo->position, this->unk1C);
                actor_stonejinjo->position_y += 172.0f;
            }
        }
    }
}
