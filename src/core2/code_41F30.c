#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chextralife_update(Actor *this);

ActorInfo chExtraLife = { MARKER_61_EXTRA_LIFE,  ACTOR_49_EXTRA_LIFE, ASSET_36E_MODEL_EXTRA_LIFE, 
    0x0, NULL,
    chextralife_update, actor_update_func_80326224, func_80325934, 
    0, 0, 0.7f, 0
};

void chextralife_update(Actor *this){
    if(!this->initialized){
        func_8032AA58(this, 0.8f);
        this->initialized = TRUE;
        if(volatileFlag_get(VOLATILE_FLAG_1) || volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)){
            marker_despawn(this->marker);
        }
    }
}
