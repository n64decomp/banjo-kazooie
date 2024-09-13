#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
}ActorLocal_Core2_3ECE0;

void chBubble_update(Actor *this);
extern void func_802F32C4(s32, f32[3], f32, ActorMarker *, s32(*)(f32[3], f32, ActorMarker *));

/* .data */
ActorInfo chBubble = { 
    MARKER_6B_GLOOPBUBBLE, ACTOR_E7_GLOOP_BUBBLE, ASSET_704_SPRITE_BUBBLE, 
    0, NULL, chBubble_update, func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .code */
s32 __chBubble_func_802C5C70(f32 arg0[3], f32 arg1, ActorMarker *marker){
    s32 pad2C;
    Actor *this = marker_getActor(marker);
    ActorLocal_Core2_3ECE0 *local = (ActorLocal_Core2_3ECE0 *) &this->local;
    s32 pad20;
    s32 sp1C = local->unk0;


    this->position_x = arg0[0];
    this->position_y = arg0[1] - arg1/2;
    this->position_z = arg0[2];
    func_8032AA58(this, arg1/200.0);
    this->lifetime_value -= time_getDelta();
    if(this->lifetime_value < 0.0f){
        sp1C = 1;
    }
    if(sp1C)
        marker_despawn(marker);
    return sp1C;
}

void __chBubble_freeCallback(Actor *this){
    func_8030E988(SFX_C5_TWINKLY_POP, 1.0f, 32000, this->position, 100.0f, 3000.0f);
}

void __chBubble_collisionCallback(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_Core2_3ECE0 *local = (ActorLocal_Core2_3ECE0 *) &this->local;
    local->unk0 = 1;
    this_marker->collidable = FALSE;

}

void chBubble_update(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, __chBubble_collisionCallback, NULL, NULL);
        marker_setFreeMethod(this->marker, __chBubble_freeCallback);
        func_802F32C4(func_8032994C(), this->position, 200.0f, this->marker, __chBubble_func_802C5C70);
        this->lifetime_value = 10.0f;
    }
}
