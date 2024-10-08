#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker*, s32, f32*);

void func_803906A0(Actor *this);
Actor *func_80390560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_803948E0[] = {
    {0, 0.0f},
    {0x268, 1.6f},
};
ActorAnimationInfo D_803948F0[] = {
    {0, 0.0f},
    {0x269, 1.6f},
};
ActorAnimationInfo D_80394900[] = {
    {0, 0.0f},
    {0x26A, 1.6f},
};
ActorInfo D_80394910 = { 0x170, 0x1D8, 0x547, 0x1, D_803948E0, func_803906A0, actor_update_func_80326224, func_80390560, 0, 0, 0.7f, 0};
ActorInfo D_80394934 = { 0x171, 0x1D9, 0x548, 0x1, D_803948F0, func_803906A0, actor_update_func_80326224, func_80390560, 0, 0, 0.5f, 0};
ActorInfo D_80394958 = { 0x172, 0x1DA, 0x549, 0x1, D_80394900, func_803906A0, actor_update_func_80326224, func_80390560, 0, 0, 0.5f, 0};

/* .code */
Actor *func_80390560(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(3, marker->collidable);
    func_8033A45C(4, marker->collidable);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_803905CC(ActorMarker *marker, ActorMarker *other_marker){
    switch (marker->id) {
    case 0x170:
        item_setMaxCount(ITEM_D_EGGS);
        fxSparkle_giantBlueEgg(&marker->propPtr->x);
        func_8025A6EC(SFX_EGG_REFILL, -1);
        break;
    case 0x171:
        item_setMaxCount(ITEM_F_RED_FEATHER);
        fxSparkle_giantRedFeather(&marker->propPtr->x);
        func_8025A6EC(SFX_RED_FEATHER_REFILL, -1);
        break;
    case 0x172:
        item_setMaxCount(ITEM_10_GOLD_FEATHER);
        fxSparkle_giantGoldFeather(&marker->propPtr->x);
        func_8025A6EC(SFX_GOLD_FEATHER_REFILL, -1);
        break;
    }
    marker->collidable = FALSE;
}

void func_803906A0(Actor *this) {
    s32 phi_s0;
    s32 phi_s2;
    s32 phi_s4;

    if (!this->initialized) {
        marker_setCollisionScripts(this->marker, func_803905CC, NULL, NULL);
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
    }
    if (this->marker->unk14_21 && this->marker->collidable) {
        switch (this->marker->modelId) {
            default:
                break;
            case 0x547:
                phi_s2 = 4;
                phi_s4 = 8;
                break;
            case 0x548:
                phi_s2 = 4;
                phi_s4 = 8;
                break;
            case 0x549:
                phi_s2 = 4;
                phi_s4 = 8;
                break;
        }
        for(phi_s0 = 0; phi_s0 < phi_s2; phi_s0++){
            if (randf() < ((1.0 / (f64) phi_s2) / 15.0)) {
                func_8033E73C(this->marker, phi_s0 + 5, &func_80329904);
                func_8033E3F0(phi_s4, 1);
            }
        }
    }
}
