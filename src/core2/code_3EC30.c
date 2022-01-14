#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802C5BC0(Actor *this);

/* .data */
extern ActorInfo D_80365FB0 = { 0x65, 0xF3, 0x0, 0x0, 0x0, func_802C5BC0, func_80326224, func_80325340, { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .code */
void func_802C5BC0(Actor *this){
    if(!this->initialized){
        actor_collisionOff(this);
        this->unk60 = 0.0f;
        this->pitch = 90.0f;
        func_802F3554(4, this->position);
        this->initialized = TRUE;
    }
    else{
        this->unk60 += time_getDelta();
        if(2.0 < this->unk60)
            marker_despawn(this->marker);
    }
}
