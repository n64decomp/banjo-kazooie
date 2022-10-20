#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker *, s32, f32 *);
extern int func_80320C94(f32 (*)[3], f32(*)[3], f32, s32, s32, u32);
extern f32 func_8033229C(ActorMarker *);

typedef struct{
    s32 unk0;
    s32 unk4;
}ActorLocal_core2_5B6A0;

Actor *func_802E2630(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802E28D0(Actor *this);

/* .data */
extern ActorInfo D_80368710 = { 
    0xB2, 0x125, 0x378, 
    0x1, NULL, 
    func_802E28D0, func_80326224, func_802E2630, 
    0, 0x800, 0.8f, 0
};

extern f32 D_803687A4[4];
extern struct31s D_80368734;
extern struct43s D_8036875C;

/* .rodata */
extern f64 D_803770F0;
extern f64 D_803770F8;

/* .bss */
f32 D_8037E640[3];

/* .code */
Actor *func_802E2630(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;

    this = func_80325888(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && this->state != 2) {
        func_8033E73C(marker, 5, func_80329904);
        func_8033E3F0(0xD, marker->unk14_21);
    }
    return this;
}


void func_802E26A4(f32 position[3]) {
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(8);
    particleEmitter_setModel(pCtrl, 0x37A);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8036875C);
    func_802EFE24(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB98(pCtrl, &D_80368734);
    particleEmitter_emitN(pCtrl, 8);
}

void func_802E2748(Actor *this, s32 arg1) {
    if (arg1 != 0) {
        D_8037E640[0] = this->position[0];
        D_8037E640[1] = this->position[1];
        D_8037E640[2] = this->position[2];
        D_8037E640[1] -= 40.0f;
        func_80359A40(D_8037E640, D_803687A4, 3);
        func_802F4200(D_8037E640);
        func_802F3FE4(D_8037E640);
        func_8030E878(SFX_2F_ORANGE_SPLAT, 1.0f, 10000, this->position, 1250.0f, 2500.0f);
        func_8030E878(SFX_F_SMALL_WATER_SPLASH, randf2(0.8f, 1.2f), 32000, this->position, 1250.0f, 2500.0f);
        actor_collisionOff(this);
        func_80326310(this);
        func_80328A84(this, 2U);
    }
    else{
        func_8030E878(SFX_2F_ORANGE_SPLAT, 1.0f, 32000, this->position, 1250.0f, 2500.0f);
        func_802E26A4(this->position);
        marker_despawn(this->marker);
    }
}


void func_802E28A4(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    func_802E2748(this, 0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_5B6A0/func_802E28D0.s")
#else
void func_802E28D0(Actor *this) {
    ActorLocal_core2_5B6A0 *local;
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    Actor *phi_a1;
    u32 *temp_v0_3;
    s32 phi_a1_2;
    s32 i;

    if(this->unk38_31 == 0 && func_80329530(500)){
        FUNC_8030E8B4(SFX_C_TAKING_FLIGHT_LIFTOFF, 0.85f, 32000, this->position, 1250, 2500);
        this->unk38_31 = 1;
    }

    phi_a1 = NULL;
    local = (ActorLocal_core2_5B6A0 *)&this->local; 

    if(!this->initialized){
        marker_setCollisionScripts(this->marker, NULL, NULL, func_802E28A4);
        if(local->unk0 == 0){
            player_getPosition(this->unk1C);
            local->unk0 = 1;
            return;
        }
        this->initialized = TRUE;
        player_getPosition(sp7C);
        sp7C[1] += 1.0f;
        phi_a1_2 = (func_8023DB5C() & 1) ? 0x15 : 0x2B;
        phi_a1 = &this;
        for(i = 0; i < 3; i++){
            sp58[i] = (sp7C[i] - this->unk1C[i]) * phi_a1_2;
        }

        this->velocity[0] = (sp58[0] - this->position[0])/32;
        this->velocity[1] = (sp58[1] - this->position[1])/32 - -32.0f;
        this->velocity[2] = (sp58[2] - this->position[2])/32;
        local->unk4 = 0;
        this->unk60 = 6.0f;
    }
    switch (this->state) {
    case 1:
        sp64[0] = this->position[0];
        sp64[1] = this->position[1];
        sp64[2] = this->position[2];
        this->position[0] += this->velocity[0];
        this->position[1] += this->velocity[1];
        this->position[2] += this->velocity[2];

        this->pitch += 10.0f;
        this->velocity_y -= 2.0f;
        this->yaw += 10.0f;

        if(this->pitch > 360.0f){
            this->pitch -= 360.0f;
        }
        if (this->yaw > 360.0f) {
            this->yaw -= 360.0f;
        }
        if (local->unk4 >= 6) {
            temp_v0_3 = func_80320C94(sp64, this->position, func_8033229C(this->marker) * 1.2, &sp70, 5, 0);
            if (temp_v0_3 != 0) {
                func_802E2748(this, *((u32*)temp_v0_3 + 2) & 0x20000);
                return;
            }
        }
        local->unk4++;
        if (this->unk60 > 0.0) {
            this->unk60 -= time_getDelta();
        } else {
            marker_despawn(this->marker);
        }

        if (this->position_y < -1000.0f) {
            marker_despawn(this->marker);
        }
        break;
    case 2:
        this->marker->unk40_22 = NOT(func_8028F170());
        this->velocity[0] *= 0.7;
        this->velocity[1] *= 0.7;
        this->velocity[2] *= 0.7;
        this->position[0] += this->velocity[0];
        this->position[1] += this->velocity[1];
        this->position[2] += this->velocity[2];
        break;
    }
}
#endif

