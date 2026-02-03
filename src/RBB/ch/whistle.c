#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 unk4[3];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    //u8  pad16[2];
}Struct_RBB_4C70;

typedef struct {
    Struct_RBB_4C70 *unk0;
    f32 unk4[3];
}ActorLocal_RBB_4C70;

Actor *func_8038B230(ActorMarker *marker, Gfx** gdl, Mtx** mptr, Vtx **arg3);
void func_8038B340(Actor *this);

/* .data */
Struct_RBB_4C70 D_80390950[] = {
    { 0x1C2, {-3720.0f, 800.0f, -350.0f}, 0x1, 0x136, 0x3FF},
    { 0x1C3, {-3720.0f, 800.0f, 0.0f}, 0x2, 0x135, 0x3FE},
    { 0x1C4, {-3720.0f, 800.0f, 350.0f}, 0x3, 0x134, 0x3FD},
    0
};

ActorInfo D_803909B0 = {
    MARKER_2A_WHISTLE_1_YELLOW, ACTOR_1C2_WHISTLE_1, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    func_8038B340, NULL, func_8038B230,
    0, 0, 0.0f, 0
};

ActorInfo D_803909D4 = {
    MARKER_2B_WHISTLE_2_YELLOW, ACTOR_1C3_WHISTLE_2, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    func_8038B340, NULL, func_8038B230,
    0, 0, 0.0f, 0
};

ActorInfo RBB_D_803909F8 = {
    MARKER_2C_WHISTLE_3_YELLOW, ACTOR_1C4_WHISTLE_3, ASSET_416_MODEL_WHISTLE,
    0x0, NULL,
    func_8038B340, NULL, func_8038B230,
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

/* .code */
Struct_RBB_4C70 *func_8038B060(Actor *this){
    Struct_RBB_4C70 * iPtr;
    for(iPtr = D_80390950; iPtr->unk0 != 0; iPtr++){
        if(iPtr->unk0 == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void RBB_func_8038B0B8(Actor *this, s32 arg1){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    ParticleEmitter *other;

    this->state = arg1;

    if(this->state == 2){
        skeletalAnim_set(this->unk148, local->unk0->unk12, 0.0f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        timed_playSfx(0.1f, local->unk0->unk14, 1.0f, 0x7d00);
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
        particleEmitter_setPosition(other, local->unk4);
        particleEmitter_setParticleVelocityRange(other, 
            -400.0f, 0.0f, -30.0f,
            -800.0f, 0.0f, 30.0f
        );
        particleEmitter_setScaleAndLifetimeRanges(other, &D_80390A1C);
        particleEmitter_setSpawnInterval(other, 0.5f);
    }
}

Actor *func_8038B230(ActorMarker *marker, Gfx** gdl, Mtx** mptr, Vtx **arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&actor->local;
    f32 sp3C[3];

    if(actor->state == 0)
        return actor;

    if(actor->state == 2){
        modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(actor->unk148));
    }

    sp3C[0] = actor->pitch;
    sp3C[1] = actor->yaw;
    sp3C[2] = actor->roll;
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)actor);
    func_8033A450(func_80329934());
    modelRender_draw(gdl, mptr, actor->position, sp3C, actor->scale, NULL, marker_loadModelBin(marker));
    func_8034A174(func_80329934(), 5, local->unk4);
    local->unk4[0] -= 60.0f;
    return actor;
}

void func_8038B340(Actor * this){
    ActorLocal_RBB_4C70 *local = (ActorLocal_RBB_4C70 *)&this->local;
    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        local->unk0 = func_8038B060(this);
        
        local->unk4[2] = 0.0f;
        local->unk4[1] = 0.0f;
        local->unk4[0] = 0.0f;

        this->position_x = local->unk0->unk4[0];
        this->position_y = local->unk0->unk4[1];
        this->position_z = local->unk0->unk4[2];

        this->yaw = -90.0f;
        this->scale = 0.25f;

        RBB_func_8038B0B8(this, 1);
    }//L8038B3E4

    if(this->state == 1){
        if(mapSpecificFlags_get(local->unk0->unk10))
            RBB_func_8038B0B8(this, 2);
    }

    if(this->state == 2){
        if( skeletalAnim_getLoopCount(this->unk148) > 0 )
            RBB_func_8038B0B8(this, 1);
    }
}
