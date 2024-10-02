#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

typedef struct {
    u8 egg_hits[4];
} ActorLocal_BossJinjonatorBase;

ActorInfo chJinjonatorBase = { MARKER_27F_JINJONATOR_STATUE_BASE, ACTOR_3A9_JINJONATOR_STATUE_BASE, ASSET_544_MODEL_JINJONATOR_STATUE_BASE, 1, NULL, chjinjonatorbase_update, actor_update_func_80326224, actor_draw, 0, 2048, 0.0f, 0 };

s32 chJinjonatorBase_SmokeColor[3] = { 200, 200, 160 };
ParticleScaleAndLifetimeRanges chJinjonatorBase_SmokeScaleAndLifetimeSettings = { {1.0f, 1.0f}, {1.7f, 2.7f}, {0.0f, 0.05f}, {2.6f, 3.4f}, 0.0f, 0.1f };
ParticleSettingsVelocityPosition chJinjonatorBase_SmokeVelocityPositionSettings = { { {-170.0f, 0.0f, -170.0f}, {170.0f, 100.0f, 170.0f} }, { {-90.0f, 0.0f, -80.0f}, {80.0f, 60.0f, 80.0f} } };

void chjinjonatorbase_spawnStoneJinjo(ActorMarker *marker) {
    Actor *actor_jinjonatorbase = marker_getActor(marker);
    Actor *actor_stonejinjo = spawn_child_actor(ACTOR_3A1_STONE_JINJO, &actor_jinjonatorbase);

    actor_stonejinjo->unkF4_8 = actor_jinjonatorbase->unkF4_8;
    actor_stonejinjo->position_y = actor_stonejinjo->position_y + 155.0f;
    actor_jinjonatorbase->unk100 = actor_stonejinjo->marker;
}

void chjinjonatorbase_createSmokeParticles(f32 position[3], s32 count) {
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setRGB(pCtrl, chJinjonatorBase_SmokeColor);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &chJinjonatorBase_SmokeVelocityPositionSettings);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &chJinjonatorBase_SmokeScaleAndLifetimeSettings);
    particleEmitter_emitN(pCtrl, count);
}

void chjinjonatorbase_func_8038E0D4(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 temp_v0 = func_8034C2C4(arg0->marker, arg1);

    if (temp_v0) {
        func_8034DE60(temp_v0, arg2, arg3, arg4, 1);
    }
}

void chjinjonatorbase_getHitByEgg(ActorMarker *this, ActorMarker *other) {
    Actor *actor_jinjonatorbase = marker_getActor(this);
    ActorLocal_BossJinjonatorBase *local = (ActorLocal_BossJinjonatorBase *) &actor_jinjonatorbase->local;
    int indx = this->unk40_31 - 1;
    s32 remaining_hits;
    f32 pad;    

    if (actor_jinjonatorbase->state != CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO) {
        if (local->egg_hits[indx]) {
            local->egg_hits[indx]--;
            comusic_playTrack(COMUSIC_2B_DING_B);
            
            if (local->egg_hits[indx] <= 0) {
                chjinjonatorbase_func_8038E0D4(actor_jinjonatorbase, indx + 0x19a, -100.0f, 0.0f, 1.2f);
                func_80324D54(1.2f, SFX_90_SWITCH_PRESS, 1.0f, 32000, actor_jinjonatorbase->position, 1000.0f, 2000.0f);
            }
        }

        remaining_hits = local->egg_hits[0] + local->egg_hits[1] + local->egg_hits[2] + local->egg_hits[3];

        if (remaining_hits <= 0) {
            chfinalboss_setBossDefeated();
            subaddie_set_state(actor_jinjonatorbase, CHBOSSJINJOBASE_STATE_3_SPAWNED_BOSS_JINJO);
            chstonejinjo_breakOpen(actor_jinjonatorbase->unk100);
        }
    }
}


void chjinjonatorbase_spawnActivator(ActorMarker *marker) {
    Actor *sp24 = marker_getActor(marker);

    func_802BB3DC(0, 18.0f, 0.92f);
    __spawnQueue_add_4((GenFunction_4) spawnQueue_actor_f32, ACTOR_3AD_JINJONATOR_STATUE_BASE_ACTIVATOR, *(u32 *)(&sp24->unk1C_x), *(u32 *)(&sp24->unk1C_y), *(u32 *)(&sp24->unk1C_z));
    chjinjonatorbase_createSmokeParticles(sp24->unk1C, 16);
}

void chjinjonatorbase_func_8038E2CC(ActorMarker *marker) {
    func_8032BB88(marker_getActor(marker), -1, 0x7FFF);
}

void chjinjonatorbase_update(Actor *this){
    ActorLocal_BossJinjonatorBase *local = (ActorLocal_BossJinjonatorBase *) &this->local;
    f32 delta_time = time_getDelta();
    s32 rumbling = globalTimer_getTime() & 0x0F;
    s32 temp_s0;
    int i;
    Actor *actor_jinjonator;
    f32 y_delta;
    f32 position_delta[3];

    marker_loadModelBin(this->marker);

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, chjinjonatorbase_getHitByEgg, NULL);
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOn(this);

        for (i = 0; i < 4; i++) {
            local->egg_hits[i] = 5;
            chjinjonatorbase_func_8038E0D4(this, 0x19a + i, 0.0f, -300.0f, 0.0f);
        }

        this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(this->unk44_31, 0x3f9);
        func_8030DD14(this->unk44_31, 3);
        sfxsource_playSfxAtVolume(this->unk44_31, 1.0f);
        sfxsource_setSampleRate(this->unk44_31, 26000);
        func_8030E2C4(this->unk44_31);
        temp_s0 = func_802F9AA8(0x3EC);
        func_802F9DB8(temp_s0, 0.5f, 0.5f, 0.0f);
        func_802F9EC4(temp_s0, this->position, 5000, 15000);
        func_802F9FD0(temp_s0, 0.25f, this->lifetime_value - 1.0, 1);
        func_802FA060(temp_s0, 17000, 17000, 0.0f);
        func_8025A6EC(JINGLE_MENACING_GRUNTILDA_A, 15000);
        func_8032BB88(this, 0, 0x7fff);
        timedFunc_set_1(8.0f, (GenFunction_1)chjinjonatorbase_func_8038E2CC, reinterpret_cast(s32,this->marker));
        this->unk1C[0] = this->position_x;
        this->unk1C[1] = this->position_y;
        this->unk1C[2] = this->position_z;
        this->position_y = -600.0f;
        FUNC_8030E624(SFX_3F6_RUBBING, 0.6f, 25000);

        if (0.0f != this->lifetime_value){
            this->velocity_y = 600.0f/this->lifetime_value;
        } else {
            this->velocity_y = 100.0f;
        }

        timedFunc_set_1(this->lifetime_value* 0.05, (GenFunction_1)chjinjonatorbase_spawnActivator,  reinterpret_cast(s32,this->marker));
        timedFunc_set_1(this->lifetime_value* 0.28, (GenFunction_1) chjinjonatorbase_spawnActivator, reinterpret_cast(s32,this->marker));
        timedFunc_set_1(this->lifetime_value* 0.46, (GenFunction_1) chjinjonatorbase_spawnActivator, reinterpret_cast(s32,this->marker));
        timedFunc_set_1(this->lifetime_value* 0.58, (GenFunction_1) chjinjonatorbase_spawnActivator, reinterpret_cast(s32,this->marker));
        SPAWNQUEUE_ADD_1(chjinjonatorbase_spawnStoneJinjo, this->marker);
    }
    else {
        if(this->state == CHBOSSJINJOBASE_STATE_1_RAISE) {
            actor_jinjonator = marker_getActor(this->unk100);
            y_delta = this->velocity_y * delta_time;

            if(this->position_y + y_delta < this->unk1C[1]) {
                if (!func_8030E3FC(this->unk44_31)) {
                    func_8030E2C4(this->unk44_31);
                }

                position_delta[0] = (rumbling & 1) ? 3.0f : -3.0f;
                position_delta[1] = y_delta;
                position_delta[2] = (rumbling & 2) ? 3.0f : -3.0f;

                this->position_x = this->unk1C[0];
                this->position_z = this->unk1C[2];

                this->position_x = position_delta[0] + this->position_x;
                this->position_y = position_delta[1] + this->position_y;
                this->position_z = position_delta[2] + this->position_z;

                actor_jinjonator->position_x = this->unk1C[0];
                actor_jinjonator->position_z = this->unk1C[2];

                actor_jinjonator->position_x = position_delta[0] + actor_jinjonator->position_x;
                actor_jinjonator->position_y = position_delta[1] + actor_jinjonator->position_y;
                actor_jinjonator->position_z = position_delta[2] + actor_jinjonator->position_z;
            }
            else {
                subaddie_set_state(this, CHBOSSJINJOBASE_STATE_2_DEFAULT);

                FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 32000);
                func_8030E394(this->unk44_31);
                sfxsource_freeSfxsourceByIndex(this->unk44_31);
                this->unk44_31 = 0;

                this->position_x = this->unk1C[0];
                this->position_y = this->unk1C[1];
                this->position_z = this->unk1C[2];

                actor_jinjonator->position_x = this->unk1C[0];
                actor_jinjonator->position_y = this->unk1C[1];
                actor_jinjonator->position_z = this->unk1C[2];
                actor_jinjonator->position_y += 155.0f;
            }
        }
    }
}
