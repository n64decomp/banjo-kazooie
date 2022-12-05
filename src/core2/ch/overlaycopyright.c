#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chOverlayCopyright_update(Actor *this);

/* .data */
f32 D_803680D0[3] = {0.0f, 0.0f, 0.0f};
ActorInfo chOverlayCopyrightDescription = { 
    MARKER_176_COPYRIGHT_OVERLAY, ACTOR_1DD_COPYRIGHT_OVERLAY, ASSET_54E_MODEL_COPYRIGHT_OVERLAY, 
    0x1, NULL, 
    chOverlayCopyright_update, func_80326224, func_802DC7E0, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *chOverlayCopyrightMarker;

/* .code */
void chOverlayCopyright_freeMethod(Actor *this){
    chOverlayCopyrightMarker = NULL;
}

void chOverlayCopyright_update(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        actor_collisionOff(this);
        marker_setFreeMethod(this->marker, chOverlayCopyright_freeMethod);
    }
}


void __chOverlayCopyright_spawn(void) {
    Actor *actor;
    if (chOverlayCopyrightMarker == 0) {
        actor = func_8032813C(ACTOR_1DD_COPYRIGHT_OVERLAY, D_803680D0, 0);
        chOverlayCopyrightMarker = actor->marker;
    }
}

void chOverlayCopyright_spawn(s32 arg0, s32 arg1){
    if(chOverlayCopyrightMarker == NULL){
        __spawnQueue_add_0(__chOverlayCopyright_spawn);
    }
}

void chOverlayCopyright_func_802DCB0C(s32 arg0, s32 arg1) {
    ActorMarker *temp_a0;

    temp_a0 = chOverlayCopyrightMarker;
    if (temp_a0 != 0) {
        func_80326310(marker_getActor(temp_a0));
    }
}
