#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s32 frameCount;
} ActorLocal_Core2_3EAD0;

void fxShoeSparkle_update(Actor *this);

/* .data */
s32 fxShoeSparkleFrames[] = {
    1, 1, 2, 2, 
    3, 4, 5, 6, 
    7, 7, 8, 8
};

#define MAX_FRAME_COUNT    12

ActorInfo fxWadingBootsTouchSparkle = {
    MARKER_58_WADING_BOOTS_TOUCH_SPARKLE, ACTOR_4E_WADING_BOOTS_TOUCH_SPARKLE, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    fxShoeSparkle_update, actor_update_func_80326224, fxTouchSparkle_draw,
    0, 0, 0.0f, 0
};

ActorInfo fxTurboTrainersTouchSparkle = {
    MARKER_59_TURBO_TRAINERS_TOUCH_SPARKLE, ACTOR_4F_TURBO_TRAINERS_TOUCH_SPARKLE, ASSET_7DE_SPRITE_SHOE_SPARKLES,
    0, NULL,
    fxShoeSparkle_update, actor_update_func_80326224, fxTouchSparkle_draw,
    0, 0, 0.0f, 0
};

/* .code */
void fxShoeSparkle_update(Actor *this){
    // Spawns a sparkle sprite when touching turbo trainers or wading boots
    ActorLocal_Core2_3EAD0 *local = (ActorLocal_Core2_3EAD0*)&this->local;
    if(!this->initialized){
        switch(this->marker->id){
            case MARKER_58_WADING_BOOTS_TOUCH_SPARKLE:
                suSetSpriteScale(this, 0.35f);
                break;
            case MARKER_59_TURBO_TRAINERS_TOUCH_SPARKLE:
                suSetSpriteScale(this, 0.4f);
                break;
        }
        this->marker->propPtr->isMirrored = 0.5 < randf();
        this->position_y += 100.0 * this->scale;
        actor_collisionOff(this);
        this->initialized = TRUE;
    }//L802C5B60
    this->marker->propPtr->frame = fxShoeSparkleFrames[local->frameCount];
    local->frameCount++;
    if(local->frameCount >= MAX_FRAME_COUNT)
        marker_despawn(this->marker);
}
