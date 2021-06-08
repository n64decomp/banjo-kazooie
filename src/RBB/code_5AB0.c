#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038BF28(Actor *this);

/* .data */
ActorInfo D_80390AE0 = {
    0x31, 0x1C9, 0x41D, 0x0, NULL,
    func_8038BF28, NULL, func_80325888,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038BEA0(Actor *this, s32 arg1){
    if(arg1 == 1)
        func_80335924(this->unk148, 0x141, 0.0f, 5.5f);
    
    if(arg1 == 2){
        func_80335924(this->unk148, 0x142, 0.0f, 8.0f);
        func_80335A8C(this->unk148, 2);
    }
    this->state = arg1;
}

void func_8038BF28(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        this->position_x = -5100.0f;
        this->position_y = -2600.0f;
        this->position_z = 1460.0f;
        this->marker->propPtr->unk8_3 = 1;
        this->yaw = 0.0f;
        func_8038BEA0(this, 1);
        if(jiggyscore_80320F7C(JIGGY_RBB_SNORKEL)){
            marker_despawn(this->marker);
        }
    }
    else{
        if(this->state == 1 && mapSpecificFlags_get(8)){
            func_8038BEA0(this, 2);
        }
    }
}

