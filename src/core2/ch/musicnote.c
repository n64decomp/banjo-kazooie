#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802C9C30(Actor* this);

/* .data */
ActorInfo D_80366C50 = { 
    MARKER_5F_MUSIC_NOTE, ACTOR_51_MUSIC_NOTE, ASSET_6D6_MODEL_MUSIC_NOTE, 0, NULL,
    func_802C9C30, actor_update_func_80326224, func_80325934,
    0, 0, 0.6f, 0
};

/* .code */
void func_802C9C30(Actor* this){
    this->scale = 0.42857143f;
}
