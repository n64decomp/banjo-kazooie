#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_80365E04[3][3];

void func_8038A3B0(Actor *this);

/* .data */
ActorAnimationInfo D_8038AFF0[3] = {
    {0, 0.0f},
    {0x248, 1.816f},
    {0x248, 9e+09f},
};

ActorInfo gBanjosBed = { 
    MARKER_E1_BANJOS_BED, ACTOR_198_BANJOS_BED, ASSET_530_BANJOS_BED,
    2, D_8038AFF0,
    func_8038A3B0, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};//chBanjosBed

ActorAnimationInfo D_8038B02C[3] = {
    {0, 0.0f},
    {0x247, 3.0f},
    {0x247, 9e+09f},
};//chBanjosChairAnimations

ActorInfo gBanjosChair ={
    MARKER_E2_BANJOS_CHAIR, ACTOR_199_BANJOS_CHAIR, ASSET_52F_BANJOS_CHAIR,
    2, D_8038B02C,
    func_8038A3B0, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorAnimationInfo D_8038B068[3] = {
    {0, 0.0f},
    {0x249, 1.0f},
    {0x249, 9e+09f},
};//chBanjosStoveAnimations

ActorInfo gBanjosStove ={
    MARKER_E3_BANJOS_STOVE, ACTOR_19A_BANJOS_STOVE, ASSET_337_BANJOS_STOVE,
    2, D_8038B068,
    func_8038A3B0, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};//chBanjosStove


/* .code */
void func_8038A3B0(Actor *this){
    s32 sp24 = this->marker->id - 0xe1;

    if(this->marker->unk14_21)
        func_8034A174(this->marker->unk44, 0x1f, D_80365E04[sp24]);

    actor_collisionOff(this);
    if(this->state == 2 && levelSpecificFlags_get(sp24 + 0x35)){
        subaddie_set_state(this, 1);
        actor_playAnimationOnce(this);
    }

}
