#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ParticleEmitter *func_802EDD8C(f32[3], f32, f32);

typedef struct{
    s16 map_id;
    s16 unk2;
    s16 unk4;
}Struct_CCW_6620_0;

typedef struct{
    Struct_CCW_6620_0 *unk0;
    f32 unk4[3];
}ActorLocal_CCW_6620;

Actor *CCW_func_8038CBF0(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038CC4C(Actor *this);

/* .data */
Struct_CCW_6620_0 D_8038F490[] ={
    {0x43, 0, 0xCCE},
    {0x45, 1, 0xCD1},
    {0x46, 1, 0xCD3},
    0
};

ActorInfo D_8038F4A8 = { 
    0x1BD, 0x2AA, 0x48F,
    0x0, NULL,
    func_8038CC4C, NULL, CCW_func_8038CBF0,
    0, 0, 2.2f, 0
};

/* .code */
void func_8038CA10(ActorMarker *marker) {
    Actor *this;
    ActorLocal_CCW_6620 *local;
    ParticleEmitter *pCtrl;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_6620 *)&this->local;

    if (this->marker->unk14_21) {
        if (0.65 < (f64) randf()) {
            pCtrl = func_802EDD8C(local->unk4, 0.0f, this->position[1] + 500.0f);
            particleEmitter_setStartingScaleRange(pCtrl, 0.04f, 0.05f);
            particleEmitter_setFinalScaleRange(pCtrl, 0.18f, 0.2f);
            particleEmitter_setSpawnPositionRange(pCtrl, -10.0f, 0.0f, -10.0f, 10.0f, 20.0f, 10.0f);
            particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 31.0f, 0.0f, 0.0f, 37.0f, 0.0f);
            particleEmitter_emitN(pCtrl, 1);
        }
    }
}

void func_8038CB40(Actor *this, s32 next_state) {
    int i;

    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x289, 0.2f, 1.1f);
        for(i = 0; i < 10; i++){
            skeletalAnim_setCallback_1(this->unk148, randf(), func_8038CA10, (s32)this->marker);
        }
    }
    this->state = next_state;
}


Actor *CCW_func_8038CBF0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_CCW_6620 *local;

    this = actor_draw(marker, gfx, mtx, vtx);
    local = (ActorLocal_CCW_6620 *)&this->local;
    if (this->marker->unk14_21) {
        func_8034A174(func_80329934(), 5, local->unk4);
    }
    return this;
}

void func_8038CC4C(Actor *this) {
    ActorLocal_CCW_6620 *local;
    f32 sp50[3];
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp38[3];

    local = (ActorLocal_CCW_6620 *)&this->local;
    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        local->unk0 = &D_8038F490[0];
        while(local->unk0->map_id != 0 && map_get() != local->unk0->map_id){
            local->unk0++;
        }
        func_8038CB40(this, 1);

        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
            levelSpecificFlags_set(LEVEL_FLAG_25_CCW_UNKNOWN, TRUE);
        }

        if ((local->unk0->unk2 != 0) && levelSpecificFlags_get(LEVEL_FLAG_25_CCW_UNKNOWN)) {
            marker_despawn(this->marker);
        }

        return;
    } 

    if (this->state == 1 && this->marker->unk14_21) {
        player_getPosition(sp50);
        func_80258A4C(this->position, this->yaw - 90.0f, sp50, &sp4C, &sp48, &sp44);
        if (sp4C > 100.0f) {
            this->yaw += 30.0f * sp44;
        }
    }
    if (!this->has_met_before) {
        player_getPosition(sp38);
        if (ml_vec3f_distance(this->position, sp38) < 900.0f) {
            if (local->unk0->map_id != MAP_46_CCW_WINTER || func_8028F2FC()) {
                gcdialog_showText(local->unk0->unk4, 4, NULL, NULL, NULL, NULL);
                this->has_met_before = TRUE;
            }
        }
    }
}
