#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_6AC0_0;

void func_8038CFB4(Actor *this);

/* .data */
ActorInfo D_8038F4D0 = { 
    0x1BE, 0x2AB, 0x48F,
    0x0, NULL,
    func_8038CFB4, func_8038CFB4, actor_draw,
    0, 0, 2.2f, 0
};

Struct_CCW_6AC0_0 D_8038F4F4[] = {
    {0.11f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.23f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.34f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.58f, 1.0f, SFX_4D_WET_WIGGLING,     9000},
    {0.8f,  1.0f, SFX_4D_WET_WIGGLING,     9000},
    0
};

Struct_CCW_6AC0_0 D_8038F53C[] = {
    {0.07f, 1.6f, SFX_56_BANJO_HUI,        32000},
    {0.17f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.22f, 1.6f, SFX_55_BANJO_HOO_2,      32000},
    {0.31f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.33f, 1.6f, SFX_54_BANJO_HOO_1,      32000},
    {0.45f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.49f, 1.7f, SFX_55_BANJO_HOO_2,      32600},
    {0.6f,  1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.63f, 1.7f, SFX_56_BANJO_HUI,        32600},
    {0.74f, 1.0f, SFX_10_BANJO_LANDING_07,  9000},
    {0.79f, 1.6f, SFX_54_BANJO_HOO_1,      32000},
    {0.9f,  1.0f, SFX_10_BANJO_LANDING_07,  9000},
    0
};

Struct_CCW_6AC0_0 D_8038F5D8[] = {
    {0.01f, 1.0f, SFX_10_BANJO_LANDING_07, 9000},
    {0.5f,  1.0f, SFX_10_BANJO_LANDING_07, 9000},
    0
};

/* .code */
void func_8038CEB0(Actor *this, s32 next_state) {
    ActorProp *temp_v0;

    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x1A6, 0.2f, 4.5f);
    }
    if (next_state == 2) {
        this->marker->propPtr->unk8_3 = FALSE;
        skeletalAnim_set(this->unk148, 0x1A7, 0.2f, 3.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        gcdialog_showText(0xCD0, 0x24, NULL, NULL, NULL, NULL);
    }
    if (next_state == 3) {
        skeletalAnim_set(this->unk148, 0x1A8, 0.2f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    if (next_state == 4) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void func_8038CFB4(Actor *this) {
    Struct_CCW_6AC0_0 *phi_s0;
    f32 sp70;
    f32 sp6C;
    f32 sp60[3];

    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        func_8038CEB0(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY) != 0) {
            levelSpecificFlags_set(0x25, 1);
        }
        if (levelSpecificFlags_get(0x25) != 0) {
            marker_despawn(this->marker);
        }
        return;
    } 

    if (this->state == 1) {
        phi_s0 = D_8038F4F4;
    } else if (this->state == 2) {
        phi_s0 = D_8038F53C;
    } else if (this->state == 3) {
        phi_s0 = D_8038F5D8;
    } else{
        phi_s0 = NULL;
    }

    if (phi_s0 != NULL) {
        skeletalAnim_getProgressRange(this->unk148, &sp70, &sp6C);
        while(phi_s0->unk0 > 0.0f){
            if (((sp70 < phi_s0->unk0) || (sp6C < sp70)) && (phi_s0->unk0 <= sp6C)) {
                func_8030E878(phi_s0->unk8, randf2(phi_s0->unk4 - 0.05, phi_s0->unk4 + 0.05), randi2(phi_s0->unkA - 200, phi_s0->unkA + 100), this->position, 500.0f, 1500.0f);
            }
            phi_s0++;
        }
    }

    if (this->state == 1) {
        if (!this->has_met_before) {
            player_getPosition(sp60);
            if (ml_distance_vec3f(this->position, sp60) < 900.0f) {
                gcdialog_showText(0xCCF, 4, NULL, NULL, NULL, NULL);
                this->has_met_before = TRUE;
            }
        }
        if (levelSpecificFlags_get(0x25) != 0) {
            func_8038CEB0(this, 2);
        }
    }

    if (this->state == 2){
        if((skeletalAnim_getLoopCount(this->unk148) > 0)) {
            func_8038CEB0(this, 3);
        }
    }
    
    if (this->state == 3) {
        func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            func_8038CEB0(this, 4);
        }
    }
}
