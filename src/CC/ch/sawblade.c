#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
}Struct_CC_3130_0;

typedef struct {
    Struct_CC_3130_0 *unk0;
    s32 unk4;
}ActorLocal_CC_3130;

void chSawblade_update(Actor *this);

/* .data */
Struct_CC_3130_0 D_80389C30[] = {
    { -80.0f, 0.4f},
    {-160.0f, 0.6f},
    {-240.0f, 0.8f},
    {  80.0f, 0.4f},
    { 160.0f, 0.6f},
    { 240.0f, 0.8f},
    { -80.0f, 0.4f},
    {-160.0f, 0.6f},
    {-240.0f, 0.8f},
    {  80.0f, 0.4f},
    { 160.0f, 0.6f},
    { 240.0f, 0.8f}
};

ActorInfo D_80389C90 = {
    0x28, ACTOR_3D_CLANKER_SAWBLADE_PROPELLOR_1, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389CB4 = {
    0x28, ACTOR_3E_CLANKER_SAWBLADE_PROPELLOR_2, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389CD8 = {
    0x28, ACTOR_3F_CLANKER_SAWBLADE_PROPELLOR_3, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389CFC = {
    0x28, ACTOR_40_CLANKER_SAWBLADE_PROPELLOR_4, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389D20 = {
    0x28, ACTOR_41_CLANKER_SAWBLADE_PROPELLOR_5, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389D44 = {
    0x28, ACTOR_42_CLANKER_SAWBLADE_PROPELLOR_6, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389D68 = {
    0x28, ACTOR_290_CLANKER_SAWBLADE_PROPELLOR_7, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389D8C = {
    0x28, ACTOR_291_CLANKER_SAWBLADE_PROPELLOR_8, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389DB0 = {
    0x28, ACTOR_292_CLANKER_SAWBLADE_PROPELLOR_9, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389DD4 = {
    0x28, ACTOR_293_CLANKER_SAWBLADE_PROPELLOR_10, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389DF8 = {
    0x28, ACTOR_294_CLANKER_SAWBLADE_PROPELLOR_11, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

ActorInfo D_80389E1C = {
    0x28, ACTOR_295_CLANKER_SAWBLADE_PROPELLOR_12, ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR, 
    0, NULL, 
    chSawblade_update, NULL, func_80325888, 
    0, 0, 0.0f, 0
};

/* .code */
void func_80389520(ActorMarker *marker, ActorMarker *otherMarker){
    FUNC_8030E624(SFX_65_METALLIC_SCRATCH, 1.0f, 30000);
}

void func_8038954C(ActorMarker *marker, ActorMarker *otherMarker){
    Actor *actor = marker_getActor(marker);
    ActorLocal_CC_3130 *local = (ActorLocal_CC_3130 *) &actor->local;

    if(local->unk4 == 0){
        FUNC_8030E624(SFX_20_METAL_CLANK_1, 1.0f, 30000);
    }
    local->unk4 = 2;
}

void chSawblade_update(Actor *this){
    ActorLocal_CC_3130 *local = (ActorLocal_CC_3130 *)&this->local;
    f32 tmp_f2;
    f32 sp34 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->roll = this->yaw;
        this->yaw =  0.0f;
        marker_setCollisionScripts(this->marker, func_80389520, NULL, func_8038954C);
        local->unk0 = &D_80389C30[(this->modelCacheIndex < 0x43) ? this->modelCacheIndex - 0x3D : this->modelCacheIndex - 0x28A];
        local->unk4 = 0;
        func_80256C60(this->position, 100);
        if(map_get() == MAP_21_CC_WITCH_SWITCH_ROOM){
            this->position_z += 64.0f;
        }
    }//L80389660
    tmp_f2 = this->roll;
    this->roll += local->unk0->unk0 * sp34;
    this->roll += (this->roll < 0.0f)? 360 : 0;
    this->roll -= (this->roll >= 360.0f)? 360 : 0;
    if( ( tmp_f2 < 90.0f && this->roll >= 90.0f )
        || ( tmp_f2 < 270.0f && this->roll >= 270.0f ) 
        || ( 90.0f < tmp_f2 && this->roll <= 90.0f )
        || ( 270.0f < tmp_f2 && this->roll <= 270.0f )
    ){//L80389790
        func_8030E878(SFX_2_CLAW_SWIPE, local->unk0->unk4, 30000, this->position, 500.0f, 1000.0f);
    }//L803897C8
    if(local->unk4 > 0)
        local->unk4--;
}
