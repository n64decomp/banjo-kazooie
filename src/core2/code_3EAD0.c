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
ActorInfo fxWadingBootsTouchSparkle = {
    MARKER_58_WADING_BOOTS_TOUCH_SPARKLE, ACTOR_4E_WADING_BOOTS_TOUCH_SPARKLE, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    func_802C5A60, actor_update_func_80326224, fxTouchSparkle_draw,
    0, 0, 0.0f, 0
};

ActorInfo fxTurboTrainersTouchSparkle = {
    MARKER_59_TURBO_TRAINERS_TOUCH_SPARKLE, ACTOR_4F_TURBO_TRAINERS_TOUCH_SPARKLE, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    func_802C5A60, actor_update_func_80326224, fxTouchSparkle_draw,
    0, 0, 0.0f, 0
};

/* .code */
void func_802C5A60(Actor *this){
    // Spawns a sparkle sprite when touching turbo trainers or wading boots
    ActorLocal_Core2_3EAD0 *local = (ActorLocal_Core2_3EAD0*)&this->local;
    if(!this->initialized){
        switch(this->marker->id){
            case 0x58:
                suSetSpriteScale(this, 0.35f);
                break;
            case 0x59:
                suSetSpriteScale(this, 0.4f);
                break;
        }
        this->marker->propPtr->isMirrored = 0.5 < randf();
        this->position_y += 100.0*this->scale;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }//L802C5B60
    this->marker->propPtr->frame = D_80365F30[local->unk0];
    local->unk0++;
    if(local->unk0 >= 0xC)
        marker_despawn(this->marker);
}
