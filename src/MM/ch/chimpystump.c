/*DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

/* external function declarations */
void func_80353064(f32 *, f32);
void func_802BB3DC(s32, f32, f32);
void func_80244BB0(s32, s32, s32, f32);

/* public function declarations */
void chchimpystump_update(Actor *this);

/* .data */
ActorInfo chchimpystump = { MARKER_95_CHIMPY_STUMP, ACTOR_C5_CHIMPY_STUMP, ASSET_3C8_MODEL_CHIMPY_STUMP,
    1, NULL,
    chchimpystump_update, func_80326224, func_80325E78,
    {0,0}, 0, 0.0f, {0,0,0,0}
};

void _chchimpystump_80386CA0(Actor *this){
    if(mapSpecificFlags_get(4)){
        if(this->unk10_12 == 0){
            this->unk10_12 = 1;
            func_802BB3DC(1, 3.0f, 1.0f);
            func_80244BB0(0, 0x6A, 0x7FF8, 0.2f);
        }//L80386D0C
        this->position_x = ((func_8023DB5C() & 1) * 2) ^ (s32)this->position_x;
        this->position_z = ((func_8023DB5C() & 2) * 2) ^ (s32)this->position_z;
    }
}

void chchimpystump_update(Actor *this){
    if(!this->initialized){
        actor_collisionOff(this);
        this->initialized = 1;
        this->unk28 = this->position_y;
        this->position_y -= 134.0f;
        this->marker->propPtr->unk8_3 = 1;
    }
    switch (this->state)
    {
    case 1:
        if(mapSpecificFlags_get(0))
            func_80328A84(this, 2);

        _chchimpystump_80386CA0(this);
        break;
    case 2:
        _chchimpystump_80386CA0(this);
        this->position_y += 2.5;
        if(this->unk28 <= this->position_y){
            this->position_y = this->unk28;
            func_80328A84(this, 3);
            func_802BB41C(1);
            func_80244C78(0);
        }
        if((func_8023DB5C() & 3) == 2)
            func_80353064(this->position, 40.0f);
        break;
    case 3:
        break;
    }
}
