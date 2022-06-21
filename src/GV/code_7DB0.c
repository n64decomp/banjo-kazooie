#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038E1A0(Actor *this);
void func_8038E1A8(Actor *this);

/* .data */
ActorAnimationInfo D_80391340[] ={
    {0x00, 0.0f},
    {0xF0, 80000000.0f},
    {0xF0, 1.6f},
};

ActorInfo D_80391358 = { 0xAE, 0x121, 0x3E6, 
    0x1, D_80391340, 
    func_8038E1A0, func_8038E1A8, func_80325888, 
    2500, 0, 0.0f, 0
};

/* .code */
void func_8038E1A0(Actor *this){}

void func_8038E1A8(Actor *this){
    Actor *sp24 = func_8032A7AC();
    this->marker->propPtr->unk8_3 = TRUE;

    switch(this->state){
        case 1:
            break;
        case 2:
            if(actor_animationIsAt(this, 0.98f)){
                if(sp24){
                    sp24->velocity_y = 1.0f;
                }
                func_80328B8C(this, 1, 0.02f, 1);
            }
            else{
                if(actor_animationIsAt(this, 0.2f))
                    FUNC_8030E8B4(SFX_4C_LIP_SMACK, 1000, 0x3ff, this->position, 1250, 2500);
                
                if(actor_animationIsAt(this, 0.4f))
                    FUNC_8030E8B4(SFX_4C_LIP_SMACK, 812, 0x3ff, this->position, 1250, 2500);
                
                if(actor_animationIsAt(this, 0.6f))
                    FUNC_8030E8B4(SFX_4C_LIP_SMACK, 625, 0x3ff, this->position, 1250, 2500);

                if(actor_animationIsAt(this, 0.8f))
                    FUNC_8030E8B4(SFX_97_BLUBBER_BURPS, 1000, 0x3ff, this->position, 1250, 2500);
            }
            break;
    }//L8038E2E8
}

void func_8038E2FC(ActorMarker *this_marker){
    Actor *this = marker_getActor(this_marker);
    Actor *other = func_8032A7AC(this);
    if(other){
        func_80328B8C(this, 2, 0.02f, 1);
    }
}

int func_8038E344(ActorMarker *this_marker){
    Actor *this = marker_getActor(this_marker);
    Actor *other = func_8032A7AC(this);

    if(other){
        if(0.0f == other->velocity_y){
            if(this->state != 2)
                return 1;
        }
    }
    return 0;
}
