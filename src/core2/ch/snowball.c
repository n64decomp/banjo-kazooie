#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker *, s32, f32 *);
extern f32 func_8033229C(ActorMarker *);
extern BKCollisionTri *func_80320C94(f32[3], f32[3], f32, f32[3], s32, u32);


typedef struct{
    s32 unk0;
    s32 unk4;
}ActorLocal_chSnowball;

Actor *chSnowball_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chSnowball_update(Actor *this);

/* .data */
ActorInfo chSnowball = { 
    MARKER_B2_SNOWBALL, ACTOR_125_SNOWBALL, ASSET_378_MODEL_SNOWBALL, 
    0x1, NULL, 
    chSnowball_update, func_80326224, chSnowball_draw, 
    0, 0x800, 0.8f, 0
};

/* .bss */
f32 D_8037E640[3];

/* .code */
Actor *chSnowball_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;

    this = actor_draw(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && this->state != 2) {
        func_8033E73C(marker, 5, func_80329904);
        func_8033E3F0(0xD, marker->unk14_21);
    }
    return this;
}

void __chSnowball_spawnPieces(f32 position[3]) {
    static struct31s D_80368734 = {{0.65f, 1.1}, {0.0f, 0.0f}, {0.0f, 0.01f}, {0.8f, 0.8f}, 0.0f, 0.5f};
    static struct43s D_8036875C = {
        {{-220.0f,  210.0f, -220.0f}, {280.0f,  460.0f, 280.0f}},
        {{   0.0f, -800.0f,    0.0f}, {  0.0f, -800.0f,   0.0f}},
        {{ -20.0f,  -20.0f,  -20.0f}, { 20.0f,   20.0f,  20.0f}}
    };
    ParticleEmitter *pCtrl;

     
    pCtrl = partEmitMgr_newEmitter(8);
    particleEmitter_setModel(pCtrl, ASSET_37A_MODEL_TINY_SNOWBALL);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8036875C);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB98(pCtrl, &D_80368734);
    particleEmitter_emitN(pCtrl, 8);
}

void __chSnowball_collisionCallback(Actor *this, bool water_collision) {
    static f32 D_803687A4[4] = {0.2f, 0.3f, 1.0f, 1.2f};
    if (water_collision) {
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
        subaddie_set_state(this, 2U);
    }
    else{
        func_8030E878(SFX_2F_ORANGE_SPLAT, 1.0f, 32000, this->position, 1250.0f, 2500.0f);
        __chSnowball_spawnPieces(this->position);
        marker_despawn(this->marker);
    }
}

void __chSnowball_actorCollisionCallback(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(marker);
    __chSnowball_collisionCallback(this, 0);
}

void chSnowball_update(Actor *this) {
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    ActorLocal_chSnowball *local = (ActorLocal_chSnowball *)&this->local; 
    BKCollisionTri *temp_v0_3;
    s32 phi_a1;
    s32 i;

    if(this->unk38_31 == 0 && func_80329530(this, 500)){
        FUNC_8030E8B4(SFX_C_TAKING_FLIGHT_LIFTOFF, 0.85f, 32000, this->position, 1250, 2500);
        this->unk38_31 = 1;
    }


    if(!this->initialized){
        marker_setCollisionScripts(this->marker, NULL, NULL, __chSnowball_actorCollisionCallback);
        if(local->unk0 == 0){
            player_getPosition(this->unk1C);
            local->unk0 = 1;
            return;
        }
        this->initialized = TRUE;
        player_getPosition(sp7C);
        sp7C[1] += 1.0f;
        phi_a1 = (func_8023DB5C() & 1) ? 0x15 : 0x2B;
        for(i = 0; i < 3; i++){
            sp58[i] = sp7C[i] + (sp7C[i] - this->unk1C[i]) * phi_a1;
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
        this->position[0] = this->position[0] + this->velocity[0];
        this->position[1] = this->position[1] + this->velocity[1];
        this->position[2] = this->position[2] + this->velocity[2];
        this->velocity_y -= 2.0f;
        this->pitch += 10.0f;
        this->yaw += 10.0f;

        if(this->pitch > 360.0f){
            this->pitch -= 360.0f;
        }
        if (this->yaw > 360.0f) {
            this->yaw -= 360.0f;
        }
        if (local->unk4 >= 6) {
            temp_v0_3 = func_80320C94(sp64, this->position, func_8033229C(this->marker) * 1.2, sp70, 5, 0);
            if (temp_v0_3 != 0) {
                __chSnowball_collisionCallback(this, *((u32*)temp_v0_3 + 2) & 0x20000);
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
        this->position[0] = this->position[0] + this->velocity[0];\
        this->position[1] = this->position[1] + this->velocity[1];\
        this->position[2] = this->position[2] + this->velocity[2];
        break;
    }
}
