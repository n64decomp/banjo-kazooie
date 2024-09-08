#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s32 unk0;
} ActorLocal_Core2_3EAD0;

void func_802C5A60(Actor *this);

/* .data */
s32 D_80365F30[] = {
    1, 1, 2, 2, 
    3, 4, 5, 6, 
    7, 7, 8, 8
};
ActorInfo D_80365F60 = {
    0x58, 0x4E, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    func_802C5A60, func_80326224, func_80325934,
    0, 0, 0.0f, 0
};

ActorInfo D_80365F84 = {
    0x59, 0x4F, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    func_802C5A60, func_80326224, func_80325934,
    0, 0, 0.0f, 0
};

/* .code */
void func_802C5A60(Actor *this){
    // Spawns a sparkle sprite when touching turbo trainers or wading boots
    ActorLocal_Core2_3EAD0 *local = (ActorLocal_Core2_3EAD0*)&this->local;
    if(!this->initialized){
        switch(this->marker->id){
            case 0x58:
                func_8032AA58(this, 0.35f);
                break;
            case 0x59:
                func_8032AA58(this, 0.4f);
                break;
        }
        this->marker->propPtr->unk8_5 = 0.5 < randf();
        this->position_y += 100.0*this->scale;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }//L802C5B60
    this->marker->propPtr->unk8_15 = D_80365F30[local->unk0];
    local->unk0++;
    if(local->unk0 >= 0xC)
        marker_despawn(this->marker);
}
