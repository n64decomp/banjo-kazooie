#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chgobirope_update(Actor *this);

/* .data */
ActorInfo D_80390D30 = { MARKER_BD_GOBI_ROPE, ACTOR_12F_GOBI_ROPE, ASSET_3E3_MODEL_GOBI_ROPE, 
    0, NULL, 
    chgobirope_update, func_80326224, func_80325888, 
    { 0x0, 0x0}, 0x533, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void chgobirope_setState(Actor *this, s32 next_state){
    this->state = next_state;

    if(this->state == 1){
        func_80335924(this->unk148, ASSET_DD_ANIM_GOBI_ROPE, 0.5f, 4.0f);
    }

    if(this->state == 2){
        func_80335924(this->unk148, ASSET_DC_ANIM_GOBI_ROPE_PULLING, 1.0f, 5.0f);
    }

    if(this->state == 3){
        func_80335924(this->unk148, 0xF5, 0.1f, 1.0f);
        func_80335A8C(this->unk148, 2);
    }

    if(this->state == 4){
        marker_despawn(this->marker);
    }
}

void chgobirope_update(Actor *this){
    Actor *sp2C;
    f32 sp28;
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        sp2C = func_80326D68(this->position, ACTOR_12E_GOBI_1, -1, &sp28);
        if(sp2C){
            this->position_x = sp2C->position_x;
            this->position_y = sp2C->position_y;
            this->position_z = sp2C->position_z;
        }
        chgobirope_setState(this, 1);
        if( jiggyscore_80320F7C(JIGGY_44_GV_GOBI_1)
            && !func_803203FC(1)
        ){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == 1 || this->state == 2){
            if(this->state == 1 && func_80387354()){
                chgobirope_setState(this, 2);
            }
            else{
                if(func_80387360())
                    chgobirope_setState(this, 4);
            }
        }//L80388AB4
        if(this->state == 2){
            if(func_80335794(this->unk148) > 0)
                chgobirope_setState(this, 1);
        }
        if(this->state == 3){
            if(func_80335794(this->unk148) > 0)
                chgobirope_setState(this, 4);
        }
    }
}
