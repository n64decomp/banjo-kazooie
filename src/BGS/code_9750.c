#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void timed_exitStaticCamera(f32);
void timedFunc_set_2(f32, void(*)(s32, s32), s32, s32);
void func_8028E668(f32[3], f32, f32, f32);

void func_8038FBF8(Actor *);


ActorAnimationInfo D_80390C70[3] = {
    {0, 0.0f},
    {0x103, 8000000.0f},
    {0x103, 0.75f}
};

ActorInfo D_80390C88 = {MARKER_6D_TANKTUP_LEG, ACTOR_E9_TANKTUP_LEG_FL, ASSET_3EF_MODEL_TANKTUP_LEG_FL, 0x01, D_80390C70,
    func_8038FBF8, func_80326224, actor_draw,
    0, 0x166, 0.0f, 0
};
u8 pad_80390CCC[4] = {0};

ActorAnimationInfo BGS_D_80390CB0[3] = {
    {0, 0.0f},
    {0x104, 8000000.0f},
    {0x104, 0.75f}
};

ActorInfo D_80390CC8 = {MARKER_6D_TANKTUP_LEG, ACTOR_EA_TANKTUP_LEG_BL, ASSET_3F0_MODEL_TANKTUP_LEG_BL, 0x01, BGS_D_80390CB0,
    func_8038FBF8, func_80326224, actor_draw,
    0, 0x166, 0.0f, 0
};
u8 pad_80390CEC[4] = {0};

ActorAnimationInfo BGS_D_80390CF0[3] = {
    {0, 0.0f},
    {0x105, 8000000.0f},
    {0x105, 0.75f}
};

ActorInfo D_80390D08 = {MARKER_6D_TANKTUP_LEG, ACTOR_EB_TANKTUP_LEG_FR, ASSET_3F1_MODEL_TANKTUP_LEG_FR, 0x01, BGS_D_80390CF0,
    func_8038FBF8, func_80326224, actor_draw,
    0, 0x166, 0.0f, 0
};
u8 pad_80390C2C[4] = {0};

ActorAnimationInfo D_80390C30[3] = {
    {0, 0.0f},
    {0x106, 8000000.0f},
    {0x106, 0.75f}
};

ActorInfo D_80390D48 = {MARKER_6D_TANKTUP_LEG, ACTOR_EC_TANKTUP_LEG_BR, ASSET_3F2_MODEL_TANKTUP_LEG_BR, 0x01, D_80390C30,
    func_8038FBF8, func_80326224, actor_draw,
    0, 0x166, 0.0f, 0
};

/* .code */
void func_8038FB40(ActorMarker *this, s32 arg1){
    Actor * thisActor;

    thisActor = marker_getActor(this);
    subaddie_set_state(thisActor, 2);
    actor_playAnimationOnce(thisActor);
    FUNC_8030E624(SFX_A_BANJO_LANDING_05, 0.8f, 32750);
}

void BGS_func_8038FB84(ActorMarker *this, ActorMarker *other_marker){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    FUNC_8030E8B4( SFX_87_TANKTUP_OOOHW, 1.0f, 32750, thisActor->position, 1000, 3000);
    timedFunc_set_2(0.65f, (GenFunction_2) func_8038FB40, (s32) this, (s32) other_marker);
    func_8038F51C(thisActor);
    this->collidable = 0;
}

void func_8038FBF8(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, BGS_func_8038FB84);
    }
    if(this->state == 2){
        if(animctrl_isAt(this->animctrl, 0.65f)){
            func_8030E540(SFX_7C_CHEBOOF);
        }
        if(animctrl_isStopped(this->animctrl)){
            marker_despawn(this->marker);
        }
    }
}
