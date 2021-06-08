#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 D_80365E04[3][3];

/* .data */
//ActorAnimation D_8038AFF0[3]; //chBanjosBedAnimations
//extern ActorInfo D_8038B008; //chBanjosBed
//extern ActorInfo D_8038B044; //chBanjosChair
//extern ActorInfo D_8038B080; //chBanjosStove



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
