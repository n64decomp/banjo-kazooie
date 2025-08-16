#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chwhipcrack_update(Actor *this);

/* .data */
ActorInfo D_80373100 = { 
    MARKER_1C5_WHIPCRACK, ACTOR_30F_WHIPCRACK, ASSET_4FD_MODEL_WHIPCRACK, 
    0, NULL, 
    chwhipcrack_update, NULL, actor_draw, 
    0, 0, 0.0f, 0
};

s32 D_80373124[3] = {0xA0, 0x6B, 0x23};

/* .code */
void __chwhipcrack_spawnPieces(Actor *this, enum asset_e model_id, s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    
    particleEmitter_setAccelerationRange(pCtrl,
        0.0f, -1000.0f, 0.0f,
        0.0f, -1000.0f, 0.0f
    );
    particleEmitter_func_802EF9F8(pCtrl, 0.7f);
    particleEmitter_func_802EFA18(pCtrl, 3);
    particleEmitter_func_802EFA20(pCtrl, 0.5f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setSpawnPositionRange(pCtrl,
        -120.0f,  50.0f, -120.0f, 
         120.0f, 300.0f,  120.0f
    );
    particleEmitter_setPosition(pCtrl, this->position);
    particleEmitter_setStartingScaleRange(pCtrl, 0.5f, 1.0f);
    particleEmitter_setAngularVelocityRange(pCtrl,
        -500.0f, -500.0f, -500.0f,
         500.0f,  500.0f,  500.0f
    );
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 4.0f, 4.0f);
    particleEmitter_setParticleVelocityRange(pCtrl,
        -300.0f, 250.0f, -300.0f,
         300.0f, 400.0f,  300.0f
    );
    particleEmitter_emitN(pCtrl, cnt);
}

void __chwhipcrack_spawnSmoke(Actor *this, s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    particleEmitter_setFade(pCtrl, 0.05f, 0.1f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, this->position);
    particleEmitter_setStartingScaleRange(pCtrl, 3.0f, 3.5f);
    particleEmitter_setFinalScaleRange(pCtrl, 4.5f, 5.5f);
    particleEmitter_setSpawnPositionRange(pCtrl,
        -50.0f,  50.0f, -50.0f, 
         50.0f, 200.0f, 50.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -30.0f, 150.0f, -30.0f,
         30.0f, 300.0f,  30.0f
    );
    particleEmitter_setRGB(pCtrl, D_80373124);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.0f, 4.0f);
    particleEmitter_emitN(pCtrl, cnt);
}

void __chwhipcrack_setState(Actor *this, s32 next_state){
    if(next_state == 1)
        skeletalAnim_set(this->unk148, ASSET_22A_ANIM_WHIPCRACK_IDLE, 0.5f, 1.0f);
    
    if(next_state == 2)
        skeletalAnim_set(this->unk148, ASSET_229_ANIM_WHIPCRACK_ATTACK, 0.5f, 1.0f);

    if(next_state == 3){
        __chwhipcrack_spawnPieces(this, ASSET_4FE_MODEL_WHIPCRACK_PART_1, 4);
        __chwhipcrack_spawnPieces(this, ASSET_4FF_MODEL_WHIPCRACK_PART_2, 4);
        __chwhipcrack_spawnPieces(this, ASSET_500_MODEL_WHIPCRACK_PART_3, 4);
        __chwhipcrack_spawnSmoke(this, 6);
        sfx_playFadeShorthandDefault(SFX_2F_ORANGE_SPLAT, 0.8f, 32200, this->position, 500, 2500);
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

void __chwhipcrack_die(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    __chwhipcrack_setState(this, 3);
}

void chwhipcrack_update(Actor *this){
    f32 plyr_pos[3];
    f32 plyr_dist;
    f32 sp44;
    f32 sp40;

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->roll = this->yaw;
        this->yaw = 0.0f;
        marker_setCollisionScripts(this->marker, NULL, NULL, __chwhipcrack_die);
        __chwhipcrack_setState(this, 1);
    }
    player_getPosition(plyr_pos);
    plyr_dist = ml_vec3f_distance(plyr_pos, this->position);
    if(this->state == 1){
        if(plyr_dist < 700.0f){
            __chwhipcrack_setState(this, 2);
        }
    }

    if(this->state == 2){
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        if((sp44 < 0.13) && (0.13 <= sp40)){
            func_8030E878(SFX_69_WHIPCRACK_CREAKING, randf2(1.05f, 1.1f), 15000, this->position, 500.0f, 1000.0f);
        }

        if((sp44 < 0.8) && (0.8 <= sp40)){
            func_8030E878(SFX_2_CLAW_SWIPE, randf2(0.9f, 1.1f), randi2(28000, 32000), this->position, 500.0f, 1000.0f);
        }

        if(800.0f < plyr_dist){
            __chwhipcrack_setState(this, 1);
        }
    }
}
