#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 actorId;
    f32 position[3];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    //u8  pad16[2];
} ActorLocal_ChRBBWhistleInfo;

typedef struct {
    ActorLocal_ChRBBWhistleInfo *unk0;
    f32 particlePosition[3];
}ActorLocal_RBB_4C70;

Actor *chRBBWhistle_draw(ActorMarker *marker, Gfx** gdl, Mtx** mptr, Vtx **arg3);
void chRBBWhistle_update(Actor *this);

/* .data */
ActorLocal_ChRBBWhistleInfo chRBBWhistleInfo[] = {
    { ACTOR_1C2_WHISTLE_1, {-3720.0f, 800.0f, -350.0f}, 0x1, 0x136, 0x3FF},
    { ACTOR_1C3_WHISTLE_2, {-3720.0f, 800.0f,    0.0f}, 0x2, 0x135, 0x3FE},
    { ACTOR_1C4_WHISTLE_3, {-3720.0f, 800.0f,  350.0f}, 0x3, 0x134, 0x3FD},
    NULL
};

ActorInfo chRBBWhistle1 = {
    MARKER_2A_WHISTLE_1_YELLOW, ACTOR_1C2_WHISTLE_1, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    chRBBWhistle_update, NULL, chRBBWhistle_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBWhistle2 = {
    MARKER_2B_WHISTLE_2_YELLOW, ACTOR_1C3_WHISTLE_2, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    chRBBWhistle_update, NULL, chRBBWhistle_draw,
    0, 0, 0.0f, 0
};

ActorInfo chRBBWhistle3 = {
    MARKER_2C_WHISTLE_3_YELLOW, ACTOR_1C4_WHISTLE_3, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    chRBBWhistle_update, NULL, chRBBWhistle_draw,
    0, 0, 0.0f, 0
};

ParticleScaleAndLifetimeRanges D_80390A1C = {
    { 1.0f, 2.0f},
    { 3.0f, 5.0f},
    { 0.05f, 0.1f},
    { 1.5f, 2.5f},
    0.0f, 
    0.5f
};

enum chrbbwhistle_state_e {
    CH_RBB_WHISTLE_STATE_0_NOT_INIT,
    CH_RBB_WHISTLE_STATE_1_IDLE,
    CH_RBB_WHISTLE_STATE_2_BLOWING
};

/* .code */
ActorLocal_ChRBBWhistleInfo *func_8038B060(Actor *this){
    ActorLocal_ChRBBWhistleInfo * iPtr;
    for(iPtr = chRBBWhistleInfo; iPtr->actorId != NULL; iPtr++){
        if(iPtr->actorId == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void chRBBWhistle_setState(Actor *this, s32 next_state){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    ParticleEmitter *other;

    this->state = next_state;

    if(this->state == CH_RBB_WHISTLE_STATE_2_BLOWING){
        skeletalAnim_set(this->unk148, local->unk0->unk12, 0.0f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        timed_playSfx(0.1f, local->unk0->unk14, 1.0f, 32000);
        other = partEmitMgr_newEmitter(0xa);
        particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
        particleEmitter_setAccelerationRange(other, 
            0.0f, 100.0f, 0.0f,
            0.0f, 250.0f, 0.0f
        );
        particleEmitter_setStartingFrameRange(other, 0, 7);
        particleEmitter_setSpawnPositionRange(other, 
            -5.0f, -5.0f, 0.0f,
            5.0f, 5.0f, 0.0f
        );
        particleEmitter_setPosition(other, local->particlePosition);
        particleEmitter_setParticleVelocityRange(other, 
            -400.0f, 0.0f, -30.0f,
            -800.0f, 0.0f, 30.0f
        );
        particleEmitter_setScaleAndLifetimeRanges(other, &D_80390A1C);
        particleEmitter_setSpawnInterval(other, 0.5f);
    }
}

Actor *chRBBWhistle_draw(ActorMarker *marker, Gfx** gdl, Mtx** mptr, Vtx **arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&actor->local;
    f32 actor_rotation[3];

    if(actor->state == 0)
        return actor;

    if(actor->state == 2){
        modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(actor->unk148));
    }

    actor_rotation[0] = actor->pitch;
    actor_rotation[1] = actor->yaw;
    actor_rotation[2] = actor->roll;
    modelRender_setPreDrawCallback((GenFunction_1)actor_predrawMethod, (s32)actor);
    modelRender_setRefPoints(func_80329934());
    modelRender_draw(gdl, mptr, actor->position, actor_rotation, actor->scale, NULL, marker_loadModelBin(marker));
    vec3fArray_get_vec3f(func_80329934(), 5, local->particlePosition);
    local->particlePosition[0] -= 60.0f;
    return actor;
}

void chRBBWhistle_update(Actor * this){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        local->unk0 = func_8038B060(this);
        
        local->particlePosition[2] = 0.0f;
        local->particlePosition[1] = 0.0f;
        local->particlePosition[0] = 0.0f;

        this->position_x = local->unk0->position[0];
        this->position_y = local->unk0->position[1];
        this->position_z = local->unk0->position[2];

        this->yaw = -90.0f;
        this->scale = 0.25f;

        chRBBWhistle_setState(this, CH_RBB_WHISTLE_STATE_1_IDLE);
    }//L8038B3E4

    if(this->state == CH_RBB_WHISTLE_STATE_1_IDLE){
        if(mapSpecificFlags_get(local->unk0->unk10))
            chRBBWhistle_setState(this, CH_RBB_WHISTLE_STATE_2_BLOWING);
    }

    if(this->state == CH_RBB_WHISTLE_STATE_2_BLOWING){
        if( skeletalAnim_getLoopCount(this->unk148) > 0 )
            chRBBWhistle_setState(this, CH_RBB_WHISTLE_STATE_1_IDLE);
    }
}
