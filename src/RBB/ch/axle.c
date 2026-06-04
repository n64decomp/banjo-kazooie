#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s16 unk0;
    f32 position[3];
    f32 startingRoll;
    f32 unk14;
    f32 unk18[3];
} ActorLocal_ChSpinningFlatPlatform_0;

typedef struct {
    ActorLocal_ChSpinningFlatPlatform_0 *unk0;
    f32 currentRotation[3];
    f32 nextRotation[3];
    f32 unk1C;
    u8  pad20[0x4];
    f32 unk24;
} ActorLocal_ChSpinningFlatPlatform;

void chSpinningFlatPlatform_update(Actor *this);

/* .data */
ActorLocal_ChSpinningFlatPlatform_0 chSpinningFlatPlatformTable[] = {
    {
        ACTOR_178_RBB_SPINNING_FLAT_PLATFORM_1,
        {0.0f, -60.0f, 2450.0f},
        0.0f,
        6.0f,
        {0.0f, -100.0f, 1900.0f}
    },
    {
        ACTOR_179_RBB_SPINNING_FLAT_PLATFORM_2,
        {-1600.0f, 730.0f, -700.0f},
        270.0f,
        6.0f,
        { -1600.0f, 810.0f, -1400.0f}},
    {
        ACTOR_17A_RBB_SPINNING_FLAT_PLATFORM_3,
        {1600.0f, 730.0f, -700.0f},
        270.0f,
        5.0f,
        {1600.0f,  810.0f, -1400.0f}
    },
    NULL
};

ActorInfo chSpinningFlatPlatform1 = {
    MARKER_188_RBB_SPINNING_FLAT_PLATFORM_1, ACTOR_178_RBB_SPINNING_FLAT_PLATFORM_1, ASSET_40C_MODEL_RBB_SPINNING_FLAT_PLATFORM_1, 0x0, NULL,
    chSpinningFlatPlatform_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chSpinningFlatPlatform2 = {
    MARKER_189_RBB_SPINNING_FLAT_PLATFORM_2, ACTOR_179_RBB_SPINNING_FLAT_PLATFORM_2, ASSET_40D_MODEL_RBB_SPINNING_FLAT_PLATFORM_2, 0x0, NULL,
    chSpinningFlatPlatform_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chSpinningFlatPlatform3 = {
    MARKER_18A_RBB_SPINNING_FLAT_PLATFORM_3, ACTOR_17A_RBB_SPINNING_FLAT_PLATFORM_3, ASSET_40E_MODEL_RBB_SPINNING_FLAT_PLATFORM_3, 0x0, NULL,
    chSpinningFlatPlatform_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chspinningflatplatform_state_e {
    CH_SPINNING_FLAT_PLATFORM_STATE_0_NOT_INIT,
    CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE,
    CH_SPINNING_FLAT_PLATFORM_STATE_2_ROTATING
};

/* .code */
ActorLocal_ChSpinningFlatPlatform_0 *func_80388E60(Actor *this){
    ActorLocal_ChSpinningFlatPlatform_0 * iPtr;
    for(iPtr = chSpinningFlatPlatformTable; iPtr->unk0 != 0; iPtr++){
        if(iPtr->unk0 == this->modelCacheIndex)
            return iPtr;
    }
    return NULL;
}

void chSpinningFlatPlatform_setState(Actor *this, s32 next_state){
    ActorLocal_ChSpinningFlatPlatform *local = (ActorLocal_ChSpinningFlatPlatform *)&this->local;
    s32 sp30;

    if(this->state == CH_SPINNING_FLAT_PLATFORM_STATE_2_ROTATING)
        sfx_playFadeShorthandDefault(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 32000, this->position, 1000, 2300);

    this->state = next_state;
    local->unk24 = 0.0f;

    if(this->state == CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE)
        local->unk24 = local->unk0->unk14;

    if(this->state == CH_SPINNING_FLAT_PLATFORM_STATE_2_ROTATING){
        sp30 = func_802F9AA8(SFX_94_COGS_ROTATING);
        func_802F9DB8(sp30, 1.0f, 1.0f, 0.0f);
        func_802F9EC4(sp30, &local->unk0->unk18, 1700, 2500);
        func_802F9F80(sp30, 0.3f, 3.4f, 0.3f);
        func_802FA060(sp30, 25000, 25000, 0.0f);
        this->pitch += ( 360.0f <= this->pitch) ? -360 : 0;
        this->yaw += ( 360.0f <= this->yaw) ? -360 : 0;
        this->roll += ( 360.0f <= this->roll) ? -360 : 0;
        
        local->currentRotation[0] = this->pitch;
        local->currentRotation[1] = this->yaw;
        local->currentRotation[2] = this->roll;

        local->nextRotation[0] = this->pitch;
        local->nextRotation[1] = this->yaw;
        local->nextRotation[2] = this->roll + 360.0f;

        local->unk1C = 0.0f;
        sfx_playFadeShorthandDefault(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 32000, this->position, 900, 1800);
    }//L803890A8
}

void chSpinningFlatPlatform_update(Actor *this){
    ActorLocal_ChSpinningFlatPlatform *local = (ActorLocal_ChSpinningFlatPlatform *)&this->local;
    f32 time_delta = time_getDelta();
    f32 rotation[3];

    if(!this->volatile_initialized){
        actor_collisionOff(this);
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        local->unk0 = func_80388E60(this);
        this->position[0] = local->unk0->position[0];
        this->position[1] = local->unk0->position[1];
        this->position[2] = local->unk0->position[2];
        this->roll = local->unk0->startingRoll;
        if(this->state == CH_SPINNING_FLAT_PLATFORM_STATE_0_NOT_INIT)
            chSpinningFlatPlatform_setState(this, CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE);
    }//L80389164

    if(ml_timer_update(&local->unk24, time_delta))
        chSpinningFlatPlatform_setState(this,
            (this->state == CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE) ?
                CH_SPINNING_FLAT_PLATFORM_STATE_2_ROTATING : CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE);
    //L803891A8

    if(this->state == CH_SPINNING_FLAT_PLATFORM_STATE_2_ROTATING){
        local->unk1C += 0.25 * time_delta;
        if(1.0f < local->unk1C)
            local->unk1C = 1.0f;
        ml_vec3f_interpolate_fast(rotation, local->currentRotation, local->nextRotation, local->unk1C);
        this->pitch = rotation[0];
        this->yaw = rotation[1];
        this->roll = rotation[2];
        if(local->unk1C == 1.0f)
            chSpinningFlatPlatform_setState(this, CH_SPINNING_FLAT_PLATFORM_STATE_1_IDLE);
    }//L80389264
}
