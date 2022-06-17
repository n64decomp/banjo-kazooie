#include <ultra64.h>
#include "functions.h"
#include "variables.h"


Actor* func_8032813C(s32, f32*, s32);
void func_80324E88(f32);
void timedFunc_set_2(f32, void(*)(s32, s32), s32, s32);
void func_8028E668(f32[3], f32, f32, f32);

void func_8038FBF8(Actor *);


ActorAnimationInfo D_80390C70[3] = {
    {0, 0.0f},
    {0x103, 8000000.0f},
    {0x103, 0.75f}
};

ActorInfo D_80390C88 = {0x6D, 0xE9, 0x3EF, 0x01, D_80390C70,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0}, 0x166, 0.0f, {0,0,0,0}
};
u8 pad_80390CCC[4] = {0};

ActorAnimationInfo D_80390CB0[3] = {
    {0, 0.0f},
    {0x104, 8000000.0f},
    {0x104, 0.75f}
};

ActorInfo D_80390CC8 = {0x6D, 0xEA, 0x3F0, 0x01, D_80390CB0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0}, 0x166, 0.0f, {0,0,0,0}
};
u8 pad_80390CEC[4] = {0};

ActorAnimationInfo D_80390CF0[3] = {
    {0, 0.0f},
    {0x105, 8000000.0f},
    {0x105, 0.75f}
};

ActorInfo D_80390D08 = {0x6D, 0xEB, 0x3F1, 0x01, D_80390CF0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0}, 0x166, 0.0f, {0,0,0,0}
};
u8 pad_80390C2C[4] = {0};

ActorAnimationInfo D_80390C30[3] = {
    {0, 0.0f},
    {0x106, 8000000.0f},
    {0x106, 0.75f}
};

ActorInfo D_80390D48 = {0x6D, 0xEC, 0x3F2, 0x01, D_80390C30,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0}, 0x166, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038FB40(ActorMarker *this, s32 arg1){
    Actor * thisActor;

    thisActor = marker_getActor(this);
    func_80328A84(thisActor, 2);
    actor_playAnimationOnce(thisActor);
    FUNC_8030E624(SFX_A_BANJO_LANDING_05, 0x3FF, 0x332);
}

void func_8038FB84(ActorMarker *this, s32 arg1){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    FUNC_8030E8B4( SFX_87_TANKTUP_OOOHW, 0x7FF, 0x3FF, thisActor->position, 1000, 3000);
    timedFunc_set_2(0.65f, func_8038FB40, this, arg1);
    func_8038F51C(thisActor);
    this->collidable = 0;
}

void func_8038FBF8(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->marker->propPtr->unk8_3 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, func_8038FB84);
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
