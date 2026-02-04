#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/dustemitter.h"

typedef struct{
    s32 unk0;
}ActorLocal_core2_50490;

Actor *func_802D745C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802D766C(Actor *this);

/* .data */
f32 D_80367A80 = 0.5f;
f32 D_80367A84 = 30.0f;
f32 D_80367A88 = 150.0f;
f32 D_80367A8C = 25.0f;
s32 D_80367A90[4] = {250, 250, 250, 120};
enum dust_emitter_type_e D_80367AA0 = DUST_EMITTER_TYPE_DUST;
f32 D_80367AA4[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_80367AB0 = {
    MARKER_57_STEAM, ACTOR_4C_STEAM, 0x0, 
    0, NULL, 
    func_802D766C, actor_update_func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};
ActorInfo D_80367AD4 = {
    MARKER_57_STEAM, ACTOR_4D_STEAM_2, 0x0, 
    0, NULL, 
    func_802D766C, actor_update_func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};
ActorInfo D_80367AF8 = {
    MARKER_57_STEAM, ACTOR_58_STEAM_3, 0x0, 
    0, NULL, 
    func_802D766C, actor_update_func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};

/* .code */
void func_802D7420(Actor *this){
    ActorLocal_core2_50490 * local = (ActorLocal_core2_50490 *)&this->local;

    if(local->unk0 != NULL){
        dustEmitter_empty(local->unk0);
    }
    local->unk0 = NULL;
}

Actor *func_802D745C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    return marker_getActor(marker);
}

Actor *func_802D7484(s32 position[3], s32 yaw, ActorInfo *arg2, u32 arg3) {
    s32 sp3C;
    ActorLocal_core2_50490 * local;
    Actor *sp34;

    sp3C = dustEmitter_returnGiven(D_80367AA0);
    sp34 = actor_new(position, yaw, arg2, arg3);
    dustEmitter_emit(sp34->position, D_80367AA4, D_80367A90, 0, D_80367A80, D_80367A84, D_80367A88, D_80367A8C, D_80367AA0);
    local = (ActorLocal_core2_50490 *)&sp34->local;
    local->unk0 = sp3C;
    sp34->marker->collidable = FALSE;
    return sp34;
}

Actor * func_802D7558(s32 *arg0, s32 arg1, ActorInfo *arg2, u32 arg3) {
    D_80367A80 = 1.2f;
    D_80367A84 = 30.0f;
    D_80367A88 = 800.0f;
    D_80367A8C = 200.0f;
    return func_802D7484(arg0, arg1, arg2, arg3);
}

Actor * func_802D75B4(s32 *arg0, s32 arg1, ActorInfo *arg2, u32 arg3) {
    D_80367A80 = 1.2f;
    D_80367A84 = 30.0f;
    D_80367A88 = 800.0f;
    D_80367A8C = 200.0f;
    return func_802D7484(arg0, arg1, arg2, arg3);
}

Actor * func_802D7610(s32 *arg0, s32 arg1, ActorInfo *arg2, u32 arg3) {
    D_80367A80 = 0.75f;
    D_80367A84 = 30.0f;
    D_80367A88 = 600.0f;
    D_80367A8C = 200.0f;
    return func_802D7484(arg0, arg1, arg2, arg3);
}

void func_802D766C(Actor *this) {
    ActorLocal_core2_50490 * local = (ActorLocal_core2_50490 *)&this->local;
    if (!this->initialized) {
        marker_setFreeMethod(this->marker, func_802D7420);
        this->initialized = TRUE;
    }
    if (dustEmitter_isActive(local->unk0) == 0) {
        func_802D7420(this);
        marker_despawn(this->marker);
    }
}
