#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

typedef struct {
    u8 unk0;
}ActorLocal_BossJinjoBase;

enum chBossJinjoBase_states {
    CHBOSSJINJOBASE_STATE_1_RAISE = 1,
    CHBOSSJINJOBASE_STATE_2_DEFAULT = 2,
    CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO = 3
};

void chBossJinjoBase_update(Actor *this);

/* .data */
ActorInfo chBossJinjoBase = {
    MARKER_27A_JINJO_STATUE_BASE, ACTOR_3A2_JINJO_STATUE_BASE, ASSET_543_MODEL_JINJO_STATUE_BASE,
    0x1, NULL,
    chBossJinjoBase_update, func_80326224, actor_draw,
    0, 0x800, 0.0f, 0
};

s32 chBossJinjoBase_smokeColor[3] = {0xC8, 0xC8, 0xA0};

ParticleScaleAndLifetimeRanges chBossJinjoBase_smokeSettings = {
    {1.0f, 1.0f},
    {1.7f, 2.7f},
    {0.0f, 0.05f},
    {2.6f, 3.4f},
    0.0f, 0.1f
};

/* .code */
void chbossjinjobase_spawnStoneJinjo(ActorMarker *arg0) {
    Actor *sp1C = marker_getActor(arg0);
    Actor *temp_v0 = spawn_child_actor(ACTOR_3A1_STONE_JINJO, &sp1C);

    temp_v0->unkF4_8 = sp1C->unkF4_8;
    temp_v0->position_y = temp_v0->position_y + 172.0f;
    sp1C->unk100 = temp_v0->marker;
}

void chBossJinjoBase_emitSmoke(f32 position[3], s32 count) {
    ParticleEmitter *p = partEmitMgr_newEmitter(count);
    
    particleEmitter_setSprite(p, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(p, chBossJinjoBase_smokeColor);
    particleEmitter_setStartingFrameRange(p, 0, 7);
    particleEmitter_setPosition(p, position);
    particleEmitter_setParticleSpawnPositionRange(p, -90.0f, 0.0f, -80.0f, 80.0f, 60.0f, 80.0f);
    particleEmitter_setParticleVelocityRange(p, -170.0f, 0.0f, -170.0f, 170.0f, 100.0f, 170.0f);
    particleEmitter_setScaleAndLifetimeRanges(p, &chBossJinjoBase_smokeSettings);
    particleEmitter_emitN(p, count);
}

void func_8038D3DC(Actor* this, s32 arg1, f32 arg2, f32 arg3, f32 arg4){
    s32 tmp = func_8034C2C4(this->marker, arg1);
    
    if(tmp){
        func_8034DE60(tmp, arg2, arg3, arg4, 1);
    }
}

void chBossJinjoBase_getHitByEgg(ActorMarker *this, ActorMarker *other) {
    Actor *actor_base;
    Actor *actor_other;

    actor_base = marker_getActor(this);

    if (actor_base->state != CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO) {
        func_8025A70C(COMUSIC_2B_DING_B);
        actor_base->unk38_31++; // hit count

        if (actor_base->unk38_31 >= 3) { // spawn Jjnjonator
            subaddie_set_state(actor_base, CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO);
            chstonejinjo_breakOpen(actor_base->unk100);
            func_8038D3DC(actor_base, 0x19A, -100.0f, 0.0f, 1.2f);
            func_80324D54(1.2f, SFX_90_SWITCH_PRESS, 1.0f, 32000, actor_base->position, 1000.0f, 2000.0f);
        }
    }
}

void fight_func_8038D510(Actor *arg0) {
    ActorLocal_BossJinjoBase *sp18 = (ActorLocal_BossJinjoBase *)&arg0->local;

    if ((u8)arg0->unk44_31 != 0) {
        func_8030DA44(arg0->unk44_31);
        arg0->unk44_31 = 0;
    }
    if (sp18->unk0 != 0) {
        func_8030DA44(sp18->unk0);
        sp18->unk0 = 0;
    }
}

void chBossJinjoBase_update(Actor *this) {
    ActorLocal_BossJinjoBase *local = (ActorLocal_BossJinjoBase *)&this->local;

    f32 delta_time = time_getDelta();
    u32 shake_noise = globalTimer_getTime() & 0xF;
    Actor *actor_stone_jinjo; //sp40
    f32 y_delta;
    f32 position_delta[3];

    this->unkF4_29 = 0;
    marker_loadModelBin(this->marker);

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chBossJinjoBase_getHitByEgg, NULL);
        marker_setFreeMethod(this->marker, fight_func_8038D510);
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOn(this);
        this->unk38_31 = 0;
        this->unk44_31 = func_8030D90C();
        sfxsource_setSfxId(this->unk44_31, SFX_3F9_UNKNOWN);
        func_8030DD14(this->unk44_31, 2);
        func_8030DBB4(this->unk44_31, 1.4f);
        sfxsource_setSampleRate(this->unk44_31, 32000);
        
        local->unk0 = func_8030D90C();
        sfxsource_setSfxId(local->unk0, SFX_405_UNKNOWN);
        func_8030DD14(local->unk0, 2);
        func_8030DBB4(local->unk0, 0.7f);
        sfxsource_setSampleRate(local->unk0, 12000);
        FUNC_8030E624(SFX_3F6_UNKNOWN, 0.6f, 20000);
        func_8038D3DC(this, 0x19a, 0.0f, -200.0f, 0.0f);
        TUPLE_COPY(this->unk1C, this->position);
        this->position_y = -400.0f;
        if(0.0f != this->lifetime_value)
            this->velocity_y = 400.0f/this->lifetime_value;
        else
            this->velocity_y = 100.0f;
        
        func_802BB3DC(0, 8.0f, 0.92f);
        __spawnQueue_add_4((GenFunction_4)func_802C4140, 0x3ad, *(s32*)&this->unk1C[0], *(s32*)&this->unk1C[1], *(s32*)&this->unk1C[2]);
        chBossJinjoBase_emitSmoke(this->unk1C, 0x10);
        SPAWNQUEUE_ADD_1(chbossjinjobase_spawnStoneJinjo, this->marker);
    }
    else{
        if(this->state == CHBOSSJINJOBASE_STATE_1_RAISE) {
            actor_stone_jinjo = marker_getActor(this->unk100);
            y_delta = this->velocity_y * delta_time;

            if(this->position_y + y_delta < this->unk1C[1]) {
                if( !fileProgressFlag_get(FILEPROG_D2_HAS_SPAWNED_A_JINJO_STATUE_IN_FINAL_FIGHT) || this->unkF4_8 == 1) {
                    func_8030E2C4(this->unk44_31);
                    func_8030E2C4(local->unk0);
                }
                
                position_delta[0] = (shake_noise & 1) ? 3.0f : -3.0f; 
                position_delta[1] = y_delta;
                position_delta[2] = (shake_noise & 2) ? 3.0f : -3.0f; 

                this->position_x = this->unk1C[0];
                this->position_z = this->unk1C[2];
                this->position_x = position_delta[0] + this->position_x;
                this->position_y = position_delta[1] + this->position_y;
                this->position_z = position_delta[2] + this->position_z;

                actor_stone_jinjo->position_x = this->unk1C[0];
                actor_stone_jinjo->position_z = this->unk1C[2];
                actor_stone_jinjo->position_x = position_delta[0] + actor_stone_jinjo->position_x;
                actor_stone_jinjo->position_y = position_delta[1] + actor_stone_jinjo->position_y;
                actor_stone_jinjo->position_z = position_delta[2] + actor_stone_jinjo->position_z;
            }
            else {
                subaddie_set_state(this, CHBOSSJINJOBASE_STATE_2_DEFAULT);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
                func_8030DA44(local->unk0);
                local->unk0 = 0;
                TUPLE_COPY(this->position, this->unk1C);
                TUPLE_COPY(actor_stone_jinjo->position, this->unk1C);
                actor_stone_jinjo->position_y += 172.0f;
            }
        }
    }//L8038D954
}
