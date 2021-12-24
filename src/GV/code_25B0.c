#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_803889A0(Actor *this);

/* .data */
ActorInfo D_80390D30 = { 0xBD, 0x12F, 0x3E3, 
    0, NULL, 
    func_803889A0, func_80326224, func_80325888, 
    { 0x0, 0x0, 0x5, 0x33}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_803889A0(Actor *this){
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
        func_803888C0(this, 1);
        if( jiggyscore_80320F7C(JIGGY_44_GV_GOBI_1)
            && !func_803203FC(1)
        ){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == 1 || this->state == 2){
            if(this->state == 1 && func_80387354()){
                func_803888C0(this, 2);
            }
            else{
                if(func_80387360())
                    func_803888C0(this, 4);
            }
        }//L80388AB4
        if(this->state == 2){
            if(func_80335794(this->unk148) > 0)
                func_803888C0(this, 1);
        }
        if(this->state == 3){
            if(func_80335794(this->unk148) > 0)
                func_803888C0(this, 4);
        }
    }
}