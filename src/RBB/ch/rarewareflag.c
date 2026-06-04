#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chRarewareFlag_update(Actor *this);

ActorInfo chRarewareFlag = {
    MARKER_198_RAREWARE_FLAG, ACTOR_1CA_RAREWARE_FLAG, ASSET_41E_MODEL_RAREWARE_FLAG,
    0x0, NULL,
    chRarewareFlag_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

void chRarewareFlag_update(Actor *this){
    if(!this->volatile_initialized){
        this->marker->propPtr->unk8_3 = 1;
        this->volatile_initialized = TRUE;
        skeletalAnim_set(this->unk148, ASSET_140_ANIM_RAREWARE_FLAG, 0.0f, 1.0f);
    }
}
