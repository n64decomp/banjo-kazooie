#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80386FE0(Actor *this);

/* .data */
ActorInfo D_8038ABF0 = {
    0x134, 0x16E, 0,
    1, NULL,
    func_80386FE0, func_80326224, func_80325340,
    2000, 0, 0.0f, 0
};

/* .code */
void func_80386FE0(Actor *this){
    if(!this->unk16C_4){
        this->unk10_12 = 0;
        this->unk38_31 = this->unk10_12;
        this->unk16C_4 = 1;
        actor_collisionOff(this);
    }

    switch(this->state){
        case 1://L80387064
            if(this->unk38_31++ == 2){
                this->unk10_12 = func_80326F58(0x16f);
                func_80328A84(this, 2);
            }
            break;
        case 2://L803870C4
            if(this->unk10_12 == 0)
                marker_despawn(this->marker);
            break;
    }//L803870DC
}

int func_803870E8(ActorMarker * arg0){
    Actor *actor = marker_getActor(arg0);
    
    return (--actor->unk10_12)==0 ? 1 : 0;

}
