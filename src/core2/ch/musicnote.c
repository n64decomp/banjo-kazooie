#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void musicNote_update(Actor* this);

/* .data */
ActorInfo sumusicNote = { 
    MARKER_5F_MUSIC_NOTE, 
    ACTOR_51_MUSIC_NOTE,
    ASSET_6D6_MODEL_MUSIC_NOTE,
    0,
    NULL,
    musicNote_update,
    actor_update_func_80326224,
    fxTouchSparkle_draw,
    0,
    0,
    0.6f,
    0
};

/* .code */
void musicNote_update(Actor* this){
    this->scale = 0.42857143f;
}
