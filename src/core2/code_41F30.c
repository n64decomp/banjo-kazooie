#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chextralife_update(Actor *this);

ActorInfo chExtraLife = { MARKER_61_EXTRA_LIFE,  ACTOR_49_EXTRA_LIFE, ASSET_36E_MODEL_EXTRA_LIFE, 
    0x0, NULL,
    chextralife_update, func_80326224, func_80325934, 
    { 0x0, 0x0}, 0, 0.7f, { 0x0, 0x0, 0x0, 0x0}
};

void chextralife_update(Actor *this){
    if(!this->initialized){
        func_8032AA58(this, 0.8f);
        this->initialized = TRUE;
        if(func_803203FC(1) || func_803203FC(2)){
            marker_despawn(this->marker);
        }
    }
}
