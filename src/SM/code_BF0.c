#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void __codeBF0_draw(Actor *this);

/* .data */
ActorInfo gCodeBF0 = {
    MARKER_134_UNKNOWN, ACTOR_16E_UNKNOWN, NULL,
    1, NULL,
    __codeBF0_draw, actor_update_func_80326224, func_80325340,
    2000, 0, 0.0f, 0
};

/* .code */
static void __codeBF0_draw(Actor *this){
    if(!this->volatile_initialized){
        this->unk10_12 = 0;
        this->unk38_31 = this->unk10_12;
        this->volatile_initialized = TRUE;
        actor_collisionOff(this);
    }

    switch(this->state){
        case 1:
            if(this->unk38_31++ == 2){
                this->unk10_12 = actorArray_actorCount(ACTOR_16F_QUARRIE);
                subaddie_set_state(this, 2);
            }
            break;
        case 2:
            if(this->unk10_12 == 0)
                marker_despawn(this->marker);
            break;
    }
}

bool codeBF0_shouldSpawnQuarrieHoneyComb(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    return (--actor->unk10_12) == 0 ? TRUE : FALSE;
}
