#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* typedefs and declarations */
typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
    f32 unkC;
}ActorLocal_RBB_36A0;

void chPropellor_update(Actor *this);

/* .data */
ActorInfo D_803906E0 = {
    MARKER_185_MODEL_RUSTY_BUCKET_REAR_PROPELLER, ACTOR_175_MODEL_RUSTY_BUCKET_REAR_PROPELLER, ASSET_403_MODEL_RUSTY_BUCKET_REAR_PROPELLER,
    0x0, NULL,
    chPropellor_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

s32 D_80390704[4] = {0x258, 0x12C, 0x12C, 0};

/*.code */
f32 __chPropellor_getSpeed(void) {
    return (f32) D_80390704[2 * levelSpecificFlags_get(LEVEL_FLAG_27_RBB_UNKNOWN) + levelSpecificFlags_get(LEVEL_FLAG_28_RBB_UNKNOWN)];
}

void __chPropellor_setState(Actor *this, s32 arg1){
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&this->local;
    if(arg1 == 1){
        local->unkC = __chPropellor_getSpeed();
        local->unk4 = __chPropellor_getSpeed();
    }
    this->state = arg1;
}

int func_80389B44(ActorMarker* marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&actor->local;

    return (0.0f < local->unk4);
}


void func_80389B80(Actor *this, f32 arg1){
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&this->local;
    local->unk0 = func_802F9AA8(0x400);
    func_802F9DB8(local->unk0, arg1, arg1, 0.0f);
    func_802F9F80(local->unk0, 0.0f, 8999999488.0f, 0.0f);
    func_802FA060(local->unk0, 0x4650, 0x4650, 0.0f);

    if (!levelSpecificFlags_get(LEVEL_FLAG_3_RBB_UNKNOWN) && !levelSpecificFlags_get(LEVEL_FLAG_4_RBB_UNKNOWN)) {
        func_802F9EC4(local->unk0, &this->position, 0x1f4, 0x7d0);
        func_802FA0B0(local->unk0, 1);
    }
}

void __chPropellor_free(Actor *actor){
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&actor->local;
    if(func_802F9C0C(local->unk0))
        func_802F9D38(local->unk0);
}


void chPropellor_update(Actor *this){ 
    ActorLocal_RBB_36A0 * local = (ActorLocal_RBB_36A0 *)&this->local;
    f32 tmp;
    f32 sp34 = time_getDelta();

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = 1;
        this->pitch = randf2(0.0f, 300.0f);
        func_803300C0(this->marker, func_80389B44);
        marker_setFreeMethod(this->marker, __chPropellor_free);
        func_80389B80(this, 1.0f);
        if(this->unk78_13 == 0x1C){
            local->unk8 = 0;
            this->position_x = 7625.5f;
            this->position_y = -1950.0f;
            this->position_z = 300.0f;
        }
        else{//L80389D4C
            local->unk8 = 1;
            this->position_x = 7625.5f;
            this->position_y = -1950.0f;
            this->position_z = -300.0f;
        }//L80389D7C
        local->unk4 = 0.0f;
        local->unkC = 0.0f;
        __chPropellor_setState(this, 1);

        if (levelSpecificFlags_get(local->unk8 ? LEVEL_FLAG_4_RBB_UNKNOWN : LEVEL_FLAG_3_RBB_UNKNOWN)) {
            ncStaticCamera_setToNode(9);
            func_80324E38(0.0f, 3);
            timedFunc_set_2(0.1f, (GenFunction_2)levelSpecificFlags_set, local->unk8 ? 0x28 : 0x27, 1);
            timed_exitStaticCamera(4.5f);
            func_80324E38(4.5f, 0);
            timedFunc_set_2(4.5f, (GenFunction_2)levelSpecificFlags_set, local->unk8 ? 0x4 : 0x3, 0);
            timedFunc_set_3(4.5f, (GenFunction_3)func_802E4078, MAP_34_RBB_ENGINE_ROOM, !local->unk8 ? 3 : 2, 0);
            func_803228D8();
        }
    }//L80389EA8
    
    tmp = this->pitch;
    this->pitch -= local->unkC*sp34;
    if( (0.0f < tmp && this->pitch <= 0.0f)
        || (180.0f < tmp && this->pitch <= 180.0f)
    ){
        if (levelSpecificFlags_get(LEVEL_FLAG_3_RBB_UNKNOWN) || levelSpecificFlags_get(LEVEL_FLAG_4_RBB_UNKNOWN)) {
            func_8030E760(SFX_2_CLAW_SWIPE, 0.4f, 20000);
        }
        else {
            func_8030E988(SFX_2_CLAW_SWIPE, 0.4f, 20000, &this->position, 500.0f, 1000.0f);
        }
    }//L80389F94
    if(this->pitch < 0.0f)
        this->pitch += 360.0f;
    
    if(this->state == 1){
        local->unk4 = __chPropellor_getSpeed();
        if(local->unkC < local->unk4){
            local->unkC += 75*sp34;
            local->unkC = MIN(local->unk4, local->unkC);
        }//L8038A03C
        if(local->unk4 < local->unkC){
            local->unkC -= 75*sp34;
            local->unkC = MAX(local->unk4, local->unkC);
        }
    }//L8038A08C
}
