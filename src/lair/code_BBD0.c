#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8030E9FC(enum sfx_e, f32, f32, s32, f32[3], f32, f32);

void func_8039217C(Actor *this);
Actor *func_80391FC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80394BE0[] = {
    {0x000, 0.0f},
    {0x28A, 1000000.0f},
    {0x28A, 1.5f},
    {0x28C, 1000000.0f},
    {0x28C, 2.0f},
    {0x1D5, 1000000.0f},
    {0x1D5, 0.25},
    {0x28E, 2.0f},
    {0x1D0, 3.0f},
};
ActorInfo D_80394C28 = { MARKER_29A_FF_PRIZE, ACTOR_3C4_FF_PRIZE_WASHING_CAULDRON, ASSET_55F_MODEL_FF_PRIZE_WASHING_CAULDRON,   
    0x1, D_80394BE0, 
    func_8039217C, func_80326224, actor_draw,
    0, 0, 3.0f, 0
};
ActorInfo D_80394C4C = { MARKER_29A_FF_PRIZE, ACTOR_3C7_FF_PRIZE_GRUNTY_DOLL, ASSET_560_MODEL_FF_PRIZE_GRUNTY_DOLL,
    0x3, D_80394BE0,
    func_8039217C, func_80326224, actor_draw,
    0, 0, 1.0f, 0
};
ActorInfo D_80394C70 = { MARKER_29A_FF_PRIZE, 0x3C6, 0x34C,
    0x0, D_80394BE0,
    func_8039217C, func_80326224, actor_draw,
    0, 0, 3.0f, 0
};
ActorInfo D_80394C94 = { MARKER_29A_FF_PRIZE, ACTOR_3C8_FF_PRIZE_TOOTY, ASSET_35B_FF_PRIZE_TOOTY,
    0x5, D_80394BE0,
    func_8039217C, func_80326224, func_80391FC0,
    0, 0, 1.0f, 0
};

/* .code */
Actor *func_80391FC0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(4, 1);
    func_8033A45C(5, 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_80392014(Actor *this, enum sfx_e sfx_id, f32 arg2, f32 arg3, s32 arg4) {
    if (mapSpecificFlags_get(0xA) || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) {
        arg4 = arg4 * 0.5;
    }
    if (mapSpecificFlags_get(5)) {
        func_8030EBC8(sfx_id, arg2, arg3, arg4, arg4);
        return;
    }
    func_8030E9FC(sfx_id, arg2, arg3, arg4, this->position, 1000.0f, 2000.0f);
}

void func_803920E0(Actor *this, enum sfx_e sfx_id, f32 arg2, f32 arg3, s32 arg4, f32 arg5) {
    s32 sp1C;

    sp1C = func_802F9AA8(sfx_id);
    func_802F9F80(sp1C, 0.1f, arg5, 0.2f);
    func_802FA060(sp1C, arg4, arg4, 0.0f);
    func_802F9DB8(sp1C, arg2, arg3, 0.01f);
    if (!mapSpecificFlags_get(5)) {
        func_802F9EC4(sp1C, this->position, 1000, 2000);
    }
}

void func_8039217C(Actor *this) {
    if (!this->initialized) {
        this->initialized = TRUE;
        if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)) {
            marker_despawn(this->marker);
            return;
        }
    }
    switch(this->state){
        case 1: //L803921F4
            if (randf() < 0.01) {
                subaddie_set_state(this, 2U);
            }
            break;

        case 2: //L8039222C
            if (actor_animationIsAt(this, 0.2f)) {
                func_80392014(this, SFX_20_METAL_CLANK_1, 0.95f, 1.05f, 15000);
            }
            if (actor_animationIsAt(this, 0.45f)) {
                func_80392014(this, SFX_20_METAL_CLANK_1, 0.95f, 1.05f, 15000);
            }
            if (actor_animationIsAt(this, 0.9f)) {
                func_80392014(this, SFX_20_METAL_CLANK_1, 0.95f, 1.05f, 15000);
            }
            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state(this, 1U);
            }
            break;

        case 3: //L803922FC
            if (randf() < 0.01) {
                subaddie_set_state(this, 4U);
            }
            break;

        case 4: //L80392334
            if (actor_animationIsAt(this, 0.15f)) {
                func_80392014(this, SFX_9_SQUEAKY_TOY, 1.25f, 1.35f, 28000);
            }
            if (actor_animationIsAt(this, 0.5f)) {
                func_80392014(this, SFX_9_SQUEAKY_TOY, 1.25f, 1.35f, 28000);
            }
            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state(this, 3U);
            }
            break;

        case 5: //L803923C0
            if (func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)) {
                subaddie_set_state(this, 8U);
                break;
            }
            if (mapSpecificFlags_get(9)) {
                mapSpecificFlags_set(5, 0);
                subaddie_set_state(this, 8U);
                break;
            }
            if ((randf() < 0.1) || mapSpecificFlags_get(5)) {
                this->unk38_0 = mapSpecificFlags_get(5);
                this->unk60 = randf2(2.0f, 4.0f);
                subaddie_set_state(this, 6U);
                func_803920E0(this, SFX_134_FREEZING_SHIVER, 1.1f, 1.2f, 15000, this->unk60);
                break;
            }
            if (randf() < 0.1) {
                subaddie_set_state(this, 7U);
            }
            break;

        case 6: //L803924EC
            if (this->unk60 > 0.0f) {
                this->unk60 -= time_getDelta();
                break;
            }
            if (actor_animationIsAt(this, 0.999f) || (mapSpecificFlags_get(5) != this->unk38_0)) {
                subaddie_set_state(this, 5U);
            }
            break;

        case 7: //L8039255C
            if ((actor_animationIsAt(this, 0.999f)) || (mapSpecificFlags_get(5) != this->unk38_0)) {
                subaddie_set_state(this, 5U);
            }
            break;

        case 8: //L80392594
            break;
    }
}
