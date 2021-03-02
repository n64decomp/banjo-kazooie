#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8028EBA4();
f32 func_802877D8(ActorMovement*);
void func_8028774C(ActorMovement*, f32);
void func_80328A84(Actor*, u32);

//TODO move data

Actor *func_802C80C0(ActorMarker *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    Actor *thisActor = marker_getActor(this);

    if(!thisActor->unkF4_21){
        thisActor->unkF4_21 = 1;
        return thisActor;
    }
    else{
        return func_80325888(this, gdl, mptr, arg3);
    }
}

void func_802C811C(Actor * this){
    ActorMovement *plyrMvmt;

    this->marker->collidable = 0;
    switch(this->unk10_31){
        case 1:
            break;
        case 2:
            func_8028E9A4(&this->position_x);
            this->yaw = func_8028EBA4();
            plyrMvmt = func_8028E78C();
            func_80287684(this->movement, 0);
            movement_setIndex(this->movement, func_80287790(plyrMvmt));
            func_8028774C(this->movement,func_802877D8(plyrMvmt));
            movement_setDuration(this->movement, 1000.0f);
            func_802875AC(this->movement, "chjigsawdance.c", 0x59);
            break;
        case 3:
            plyrMvmt = func_8028E78C();
            func_80287684(this->movement, 0);
            func_8028774C(this->movement,func_802877D8(plyrMvmt));
            movement_setDuration(this->movement, 1000.0f);
            func_802875AC(this->movement, "chjigsawdance.c", 0x62);
            break;
        case 4:
            func_8028E9A4(&this->position_x);
            this->yaw = func_8028EBA4();
            plyrMvmt = func_8028E78C();
            func_80287684(this->movement, 0);
            func_8028774C(this->movement,func_802877D8(plyrMvmt));
            movement_setDuration(this->movement, 1000.0f);
            func_802875AC(this->movement, "chjigsawdance.c", 0x6e);
            break;
        case 5:
            this->marker->propPtr->unk8_4 = 0;
            break;
    }
}

void func_802C82C0(Actor * this, u32 arg1){
    switch(arg1){
        case 3:
            if(this->unk10_31 == 1){
                func_80328A84(this, 2);
                func_80287674(this->movement, 1);
            }
            break;
        case 2:
            func_80328A84(this, 3);
            break;
        case 1:
            func_80328A84(this, 4);
            break;
        case 4:
            func_8028E9A4(&this->position_x);
            this->yaw = func_8028EBA4();
            func_80287684(this->movement, 0);
            func_8028774C(this->movement, func_802877D8(func_8028E78C()));
            movement_setDuration(this->movement, 1000.0f);
            func_802875AC(this->movement, "chjigsawdance.c", 0x97);
            break;
        case 5:
            func_80328A84(this, 5);
            this->marker->propPtr->unk8_4 = 0;
            break;
    }
}