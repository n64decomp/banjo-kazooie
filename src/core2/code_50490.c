#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void func_802EE5E8(void *);

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
s32 D_80367AA0 = 0;
f32 D_80367AA4[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_80367AB0 = {
    0x57, 0x4C, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};
ActorInfo D_80367AD4 = {
    0x57, 0x4D, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};
ActorInfo D_80367AF8 = {
    0x57, 0x58, 0x0, 
    0, NULL, 
    func_802D766C, func_80326224, func_802D745C,
    0, 0, 0.0f, 0
};

/* .code */
void func_802D7420(Actor *this){
    ActorLocal_core2_50490 * local = (ActorLocal_core2_50490 *)&this->local;

    if(local->unk0 != NULL){
        func_802EE5E8(local->unk0);
    }
    local->unk0 = NULL;
}

Actor *func_802D745C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    return marker_getActor(marker);
}

#ifdef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_50490/func_802D7484.s")
#else
Actor *func_802D7484(s32 position[3], s32 yaw, ActorInfo *arg2, u32 arg3) {
    s32 sp3C;
    ActorLocal_core2_50490 * local;
    Actor *sp34;

    sp3C = func_802EE5E0(D_80367AA0);
    sp34 = actor_new(position, yaw, arg2, arg3);
    func_802EE6CC(sp34->position, D_80367AA4, D_80367A90, 0, D_80367A80, D_80367A84, D_80367A88, D_80367A8C, D_80367AA0);
    local = (ActorLocal_core2_50490 *)&sp34->local;
    local->unk0 = sp3C;
    sp34->marker->collidable = FALSE;
    return sp34;
}
#endif

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
        func_803300D8(this->marker, func_802D7420);
        this->initialized = TRUE;
    }
    if (func_802EE5F0(local->unk0) == 0) {
        func_802D7420(this);
        marker_despawn(this->marker);
    }
}
