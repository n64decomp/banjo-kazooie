#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_80365E04[3][3];

void func_8038A3B0(Actor *this);

/* .data */
ActorAnimationInfo D_8038AFF0[] = {
    {0, 0.0f},
    {0x248, 1.816f},
    {0x248, 9e+09f},
};//chBanjosBedAnimations

ActorInfo D_8038B008 = { 
    0xE1, 0x198, 0x530,
    2, D_8038AFF0,
    func_8038A3B0, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};//chBanjosBed

ActorAnimationInfo D_8038B02C[] = {
    {0, 0.0f},
    {0x247, 3.0f},
    {0x247, 9e+09f},
};//chBanjosChairAnimations

ActorInfo D_8038B044 ={
    0xE2, 0x199, 0x52F,
    2, D_8038B02C,
    func_8038A3B0, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};//chBanjosChair

ActorAnimationInfo D_8038B068[] = {
    {0, 0.0f},
    {0x249, 1.0f},
    {0x249, 9e+09f},
};//chBanjosStoveAnimations

ActorInfo D_8038B080 ={
    0xE3, 0x19A, 0x337,
    2, D_8038B068,
    func_8038A3B0, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};//chBanjosStove


/* .code */
void func_8038A3B0(Actor *this){
    s32 sp24 = this->marker->unk14_20 - 0xe1;

    if(this->marker->unk14_21)
        func_8034A174(this->marker->unk44, 0x1f, D_80365E04[sp24]);

    actor_collisionOff(this);
    if(this->state == 2 && levelSpecificFlags_get(sp24 + 0x35)){
        func_80328A84(this, 1);
        actor_playAnimationOnce(this);
    }

}
