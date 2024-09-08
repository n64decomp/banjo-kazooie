#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_4530_0;

void func_8038A950(Actor *this, s32 next_state);
Actor *func_8038AA38(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038AA8C(Actor *this);

/* .data */
ActorInfo D_8038F190 = {
    0x1B6, 0x2A3, 0x487,
    0x0, NULL,
    func_8038AA8C, NULL, func_8038AA38,
    0, 0, 0.0f, 0
};

Struct_CCW_4530_0 D_8038F1B4[] = {
    {0.15f, 0.9f,  SFX_A5_EYRIE_CRY, 25000},
    {0.3f,  1.0f,  SFX_A5_EYRIE_CRY, 32000},
    {0.6f,  0.8f,  SFX_2_CLAW_SWIPE, 20000},
    {0.68f, 0.85f, SFX_2_CLAW_SWIPE, 23000},
    {0.75f, 0.9f,  SFX_2_CLAW_SWIPE, 28000},
    {0.8f,  0.95f, SFX_2_CLAW_SWIPE, 30000},
    {0.81f, 1.0f,  SFX_A5_EYRIE_CRY, 32000},
    {0.86f, 1.0f,  SFX_2_CLAW_SWIPE, 31000},
    {0.93f, 1.0f,  SFX_2_CLAW_SWIPE, 32000},
0
};

/* .code */
void func_8038A920(ActorMarker* marker, enum asset_e text_id, s32 arg2) {
    func_8038A950(marker_getActor(marker), 3);
}

void func_8038A950(Actor *this, s32 next_state) {
    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x199, 0.0f, 6.5f);
    }
    if (next_state == 2) {
        func_80311480(0xCDC, 0xA, this->position, this->marker, func_8038A920, NULL);
    }
    if (next_state == 3) {
        skeletalAnim_set(this->unk148, 0x19A, 0.0f, 7.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.0f, 3);
        timed_setStaticCameraToNode(0.0f, 0);
    }
    if (next_state == 4) {
        mapSpecificFlags_set(5, 1);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

Actor *func_8038AA38(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;

    this = marker_getActor(marker);
    if(this->state == 0)
        return this;
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038AA8C(Actor *this) {
    f32 sp54[3];
    f32 sp50;
    f32 sp4C;
    Struct_CCW_4530_0 *iPtr;
    f32 sp44;
    f32 sp40;

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        mapSpecificFlags_set(5, FALSE);
        if( (!fileProgressFlag_get(FILEPROG_E8_AUTMN_EYRIE_FED) || jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE))
            && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)
        ) {
            marker_despawn(this->marker);
        }
        else{
            func_8038A950(this, 1);
        }
        return;
    }

    if (this->state == 1) {
        skeletalAnim_getProgressRange(this->unk148, &sp50, &sp4C);
        if ((sp50 < 0.21) && (0.21 <= sp4C)) {
            func_8030E878(0xA5, randf2(0.9f, 1.1f), 32000, this->position, 500.0f, 2500.0f);
        }
        
        if ((sp50 < 0.56) && (0.56 <= sp4C)) {
            func_8030E878(0xA5, randf2(0.9f, 1.1f), 32000, this->position, 500.0f, 2500.0f);
        }

        player_getPosition(sp54);
        if (ml_distance_vec3f(this->position, sp54) < 850.0f) {
            func_8038A950(this, 2);
        }
    }
    if (this->state == 3) {
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        for(iPtr = &D_8038F1B4[0]; iPtr->unk0 > 0.0f; iPtr++){
             if ((sp44 < iPtr->unk0) && (iPtr->unk0 <= sp40)) {
                func_8030E878(iPtr->unk8, iPtr->unk4, iPtr->unkA, this->position, 500.0f, 2500.0f);
            }
        }
        if (skeletalAnim_getLoopCount(this->unk148) > 0) {
            func_8038A950(this, 4);
        }
    }
}
