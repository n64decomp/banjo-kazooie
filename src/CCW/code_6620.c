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

Actor *func_8038CBF0(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038CC4C(Actor *this);

/* .data */
extern Struct_CCW_6620_0 D_8038F490[];
extern ActorInfo D_8038F4A8 = { 0x1BD, 0x2AA, 0x48F, 0x0, NULL, func_8038CC4C, NULL, func_8038CBF0, { 0x0, 0x0}, 0, 2.2f, { 0x0, 0x0, 0x0, 0x0}};

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
            func_802EFB70(pCtrl, 0.04f, 0.05f);
            func_802EFB84(pCtrl, 0.18f, 0.2f);
            particleEmitter_setParticleSpawnPositionRange(pCtrl, -10.0f, 0.0f, -10.0f, 10.0f, 20.0f, 10.0f);
            particleEmitter_setParticleVelocityRange(pCtrl, 0.0f, 31.0f, 0.0f, 0.0f, 37.0f, 0.0f);
            particleEmitter_emitN(pCtrl, 1);
        }
    }
}

void func_8038CB40(Actor *this, s32 next_state) {
    int i;

    if (next_state == 1) {
        func_80335924(this->unk148, 0x289, 0.2f, 1.1f);
        for(i = 0; i < 10; i++){
            func_80335800(this->unk148, randf(), func_8038CA10, this->marker);
        }
    }
    this->state = next_state;
}


Actor *func_8038CBF0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    ActorLocal_CCW_6620 *local;

    this = func_80325888(marker, gfx, mtx, vtx);
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
    if (!this->unk16C_4) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk16C_4 = TRUE;
        this->unk138_24 = FALSE;
        local->unk0 = &D_8038F490[0];
        while(local->unk0->map_id != 0 && map_get() != local->unk0->map_id){
            local->unk0++;
        }
        func_8038CB40(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
            levelSpecificFlags_set(0x25, TRUE);
        }
        if ((local->unk0->unk2 != 0) && levelSpecificFlags_get(0x25)) {
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
    if (!this->unk138_24) {
        player_getPosition(sp38);
        if (func_80256064(this->position, sp38) < 900.0f) {
            if (local->unk0->map_id != MAP_46_CCW_WINTER || func_8028F2FC()) {
                func_80311480(local->unk0->unk4, 4, NULL, NULL, NULL, NULL);
                this->unk138_24 = TRUE;
            }
        }
    }
}
