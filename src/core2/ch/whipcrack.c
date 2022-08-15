#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chwhipcrack_update(Actor *this);

/* .data */
ActorInfo D_80373100 = { 
    MARKER_1C5_WHIPCRACK, ACTOR_30F_WHIPCRACK, ASSET_4FD_MODEL_WHIPCRACK, 
    0, NULL, 
    chwhipcrack_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

s32 D_80373124[3] = {0xA0, 0x6B, 0x23};

/* .code */
void __chwhipcrack_spawnPieces(Actor *this, enum asset_e model_id, s32 cnt){
    ParticleEmitter *pCtrl = partEmitList_pushNew(cnt);
    
    particleEmitter_setParticleAccelerationRange(pCtrl,
        0.0f, -1000.0f, 0.0f,
        0.0f, -1000.0f, 0.0f
    );
    func_802EF9F8(pCtrl, 0.7f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 0.5f, 1.0f);
    func_802EF9EC(pCtrl, 0x1f, 10000);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -120.0f,  50.0f, -120.0f, 
         120.0f, 300.0f,  120.0f
    );
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 0.5f, 1.0f);
    func_802EFE24(pCtrl,
        -500.0f, -500.0f, -500.0f,
         500.0f,  500.0f,  500.0f
    );
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 4.0f, 4.0f);
    particleEmitter_setParticleVelocityRange(pCtrl,
        -300.0f, 250.0f, -300.0f,
         300.0f, 400.0f,  300.0f
    );
    particleEmitter_emitN(pCtrl, cnt);
}

void __chwhipcrack_spawnSmoke(Actor *this, s32 cnt){
    ParticleEmitter *pCtrl = partEmitList_pushNew(cnt);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(pCtrl, 0.05f, 0.1f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 3.0f, 3.5f);
    func_802EFB84(pCtrl, 4.5f, 5.5f);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -50.0f,  50.0f, -50.0f, 
         50.0f, 200.0f, 50.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -30.0f, 150.0f, -30.0f,
         30.0f, 300.0f,  30.0f
    );
    func_802EFFA8(pCtrl, D_80373124);
    func_802EFEC0(pCtrl, 3.0f, 4.0f);
    particleEmitter_emitN(pCtrl, cnt);
}

void __chwhipcrack_setState(Actor *this, s32 next_state){
    if(next_state == 1)
        func_80335924(this->unk148, ASSET_22A_ANIM_WHIPCRACK_IDLE, 0.5f, 1.0f);
    
    if(next_state == 2)
        func_80335924(this->unk148, ASSET_229_ANIM_WHIPCRACK_ATTACK, 0.5f, 1.0f);

    if(next_state == 3){
        __chwhipcrack_spawnPieces(this, ASSET_4FE_MODEL_WHIPCRACK_PART_1, 4);
        __chwhipcrack_spawnPieces(this, ASSET_4FF_MODEL_WHIPCRACK_PART_2, 4);
        __chwhipcrack_spawnPieces(this, ASSET_500_MODEL_WHIPCRACK_PART_3, 4);
        __chwhipcrack_spawnSmoke(this, 6);
        FUNC_8030E8B4(SFX_2F_ORANGE_SPLAT, 0.8f, 32200, this->position, 500, 2500);
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

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
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
        func_8033568C(this->unk148, &sp44, &sp40);
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
