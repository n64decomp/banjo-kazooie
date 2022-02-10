#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80388028(Actor *this);
Actor *func_80387AA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_8038BAD0 = { 0x254, 0x381, 0x521, 
    0x0, NULL,
    func_80388028, NULL, func_80387AA0,
    { 0x0, 0x0}, 0x0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern struct31s D_8038BB00;
extern struct31s D_8038BB70;

extern s32 D_8038BAF4;
extern s32 D_8038BB28;
extern s32 D_8038BB98;

/* .code */
Actor *func_80387AA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor* actor = marker_getActor(marker);
    if ((actor->state == 0) || (actor->state == 1) || (actor->state == 6) || (actor->state == 2)) {
        return actor;
    }
    return func_80325888(marker, gfx, mtx, vtx);
}


#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387B14.s")

void func_80387CF4(s32 arg0, s32 arg1) {
    func_8030E6D4(0x1E);
}

void func_80387D1C(ActorMarker* arg0, s32 arg1) {
    func_80387B14(marker_getActor(arg0), 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387D48.s")

void func_80387DF8(f32 *arg0, u32 arg1, s32 arg2) {
    ParticleEmitter *temp_s0;
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(arg1);
    temp_s0 = temp_v0;
    func_802EFFA8(temp_v0, &D_8038BAF4);
    particleEmitter_setSprite(temp_s0, arg2);
    particleEmitter_setPosition(temp_s0, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_8038BB28);
    func_802EFB98(temp_s0, &D_8038BB00);
    particleEmitter_emitN(temp_s0, arg1);
}

void func_80387E84(f32 *arg0, u32 arg1, s32 arg2) {
    ParticleEmitter *temp_s0;
    ParticleEmitter *temp_v0;

    temp_v0 = partEmitList_pushNew(arg1);
    temp_s0 = temp_v0;
    particleEmitter_setModel(temp_v0, arg2);
    particleEmitter_setPosition(temp_s0, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(temp_s0, &D_8038BB98);
    func_802EFE24(temp_s0, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EF9F8(temp_s0, 0.4f);
    func_802EFA18(temp_s0, 3);
    func_802EFA20(temp_s0, 1.0f, 1.3f);
    func_802EF9EC(temp_s0, 0x2F, 0x3E80);
    func_802EFA70(temp_s0, 2);
    func_802EFB98(temp_s0, &D_8038BB70);
    particleEmitter_emitN(temp_s0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80387F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_16B0/func_80388028.s")
