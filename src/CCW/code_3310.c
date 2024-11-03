#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    s16 unk4;
    f32 unk8;
    s16 unkC;
}Struct_CCW_3310_1;

typedef struct {
    s16 map_id;
    s16 unk2; // enum file_progress_e
    s16 unk4; // enum file_progress_e
    s16 unk6;
    Struct_CCW_3310_1 *unk8;
    s16 unkC;
    s16 unkE;
    Struct_CCW_3310_1 *unk10;
    s16 unk14;
    // u8 pad16[2];
    Struct_CCW_3310_1 *unk18;
    s16 unk1C;
    // u8 pad1E[0x2];
    Struct_CCW_3310_1 *unk20;
    u8 unk24;
    u8 unk25;
    s16 unk26;
    s16 unk28;
    // u8 pad2A[2];
}Struct_CCW_3310_0;

typedef struct {
    Struct_CCW_3310_0 *unk0;
    u8 unk4;
    //u8 pad5[3];
    Struct_CCW_3310_1 *unk8;
    s32 unkC[3];
}ActorLocal_CCW_3310;

Actor *func_80389B24(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void CCW_func_80389BFC(Actor *this);

/* .data */
Struct_CCW_3310_1 D_8038EEA0[] = {
    {0.11f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.22f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.34f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.55f, SFX_2_CLAW_SWIPE,   1.1f, 25000},
    {0.65f, SFX_2_CLAW_SWIPE,   1.0f, 26000},
    {0.77f, SFX_2_CLAW_SWIPE,   1.1f, 25000},
    {0.87f, SFX_2_CLAW_SWIPE,   1.0f, 24000},
    0
};

Struct_CCW_3310_1 D_8038EF20[] = {
    {0.1f,  SFX_80_YUMYUM_CLACK,  0.9f, 15000},
    {0.25f, SFX_4C_LIP_SMACK,     1.0f, 15000},
    {0.31f, SFX_4C_LIP_SMACK,     0.9f, 15000},
    {0.38f, SFX_4C_LIP_SMACK,     1.0f, 15000},
    {0.48f, SFX_4C_LIP_SMACK,     0.9f, 15000},
    {0.55f, SFX_97_BLUBBER_BURPS, 0.9f, 32700},
    {0.6f , SFX_2C_PULLING_NOISE, 0.7f, 25000},
    {0.73f, SFX_2C_PULLING_NOISE, 0.8f, 27000},
    {0.85f, SFX_2C_PULLING_NOISE, 0.9f, 29000},
    0
};

Struct_CCW_3310_1 D_8038EFC0[] = {
    {0.2f , SFX_105_EYRIE_YAWN,        1.1f, 25000},
    {0.27f, SFX_105_EYRIE_YAWN,        1.0f, 25000},
    {0.35f, SFX_105_EYRIE_YAWN,        0.9f, 25000},
    {0.6f , SFX_106_EYRIE_LIPSMACK,    1.0f, 25000},
    {0.66f, SFX_106_EYRIE_LIPSMACK,    0.9f, 23000},
    {0.83f, SFX_1D_HITTING_AN_ENEMY_1, 0.7f, 27000},
    0
};

Struct_CCW_3310_1 D_8038F030[] = {
    {0.2f , SFX_5D_BANJO_RAAOWW, 1.0f, 25000},
    {0.72f, SFX_5E_BANJO_PHEWWW, 1.0f, 25000},
    0
};

Struct_CCW_3310_1 D_8038F060[] = {
    {0.95f, SFX_106_EYRIE_LIPSMACK, 1.0f, 25000},
    0
};

Struct_CCW_3310_0 D_8038F080[] = {
    {MAP_43_CCW_SPRING, 0,                                FILEPROG_E6_SPRING_EYRIE_HATCHED,     0,       NULL, 3,     0,       NULL, 0x18F, D_8038EFC0, 0x190, D_8038F030, 0,   0,     0,     0},
    {MAP_44_CCW_SUMMER, FILEPROG_E6_SPRING_EYRIE_HATCHED, FILEPROG_E7_SUMMER_EYRIE_FED,     0x191, D_8038EEA0, 2, 0x192, D_8038EF20, 0x193, D_8038EFC0, 0x194, D_8038F030, 2,   5, 0x21A, 0xCD7},
    {MAP_45_CCW_AUTUMN, FILEPROG_E7_SUMMER_EYRIE_FED,     FILEPROG_E8_AUTMN_EYRIE_FED,      0x195, D_8038EEA0, 2, 0x196, D_8038EF20, 0x197, D_8038EFC0, 0x198, D_8038F030, 4, 0xA, 0x21B, 0xCDA},
    0
};

ActorInfo D_8038F130 = { MARKER_1B4_EEYRIE_BABY, ACTOR_2A1_EEYRIE_BABY, ASSET_484_MODEL_EAGLE_BABY, 0x0, NULL, CCW_func_80389BFC, NULL, func_80389B24, 0, 0, 0.0f, 0};

/* .bss */
f32 D_8038FDE0[3];

/* .code */
void func_80389700(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    timed_exitStaticCamera(0.5f);
    func_80324E38(0.5f, 0);
}

void func_80389740(ActorMarker *marker) {
    Actor *this = marker_getActor(marker);
    if (this->marker->unk14_21) {
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0x30C, reinterpret_cast(s32, D_8038FDE0[0]), reinterpret_cast(s32, D_8038FDE0[1]), reinterpret_cast(s32, D_8038FDE0[2]));
    }
}

void func_80389798() {
    func_8030E6D4(SFX_18C_EYRIE_MAMA);
}

void func_803897B8(Actor *this, s32 next_state) {
    ActorLocal_CCW_3310 *local;

    local = (ActorLocal_CCW_3310 *)&this->local;
    local->unk8 = NULL;
    if (next_state == 1) {
        if (local->unk0->unk6 != 0) {
            skeletalAnim_set(this->unk148, local->unk0->unk6, 0.2f, 6.0f);
            skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        }
        local->unk8 = local->unk0->unk8;
    }
    if ((this->state == 1) && (next_state == 2)) {
        fileProgressFlag_set(local->unk0->unk4, TRUE);
    }
    if (next_state == 5) {
        func_8028F784(1);
        skeletalAnim_set(this->unk148, local->unk0->unk26, 0.2f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        local->unk8 = &D_8038F060[0];
    }

    if (next_state == 2) {
        skeletalAnim_set(this->unk148, local->unk0->unkE, 0.2f, 8.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.5f, 3);
        timed_setStaticCameraToNode(0.5f, local->unk0->unk24);
        timed_exitStaticCamera(16.5f);
        func_80324E38(16.5f, 0);
        local->unk8 = local->unk0->unk10;
    }
    if (next_state == 3) {
        actor_collisionOff(this);
        skeletalAnim_set(this->unk148, local->unk0->unk14, 0.5f, 8.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        if (local->unk0->map_id == MAP_43_CCW_SPRING) {
            gcdialog_showText(0xCD6, 4, NULL, NULL, NULL, NULL);
            skeletalAnim_setCallback_0(this->unk148, 0.65f, &func_80389798);
        }
        if (local->unk0->map_id == MAP_44_CCW_SUMMER) {
            gcdialog_showText(0xCD9, 4, NULL, NULL, NULL, NULL);
        }
        if (local->unk0->map_id == MAP_45_CCW_AUTUMN) {
            gcdialog_showText(0xCDB, 4, NULL, NULL, NULL, NULL);
        }
        local->unk8 = local->unk0->unk18;
    }
    if (next_state == 4) {
        func_8028F784(0);
        skeletalAnim_set(this->unk148, local->unk0->unk1C, 0.2f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        skeletalAnim_setCallback_1(this->unk148, 0.2f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.3f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.4f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.72f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.82f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.92f, (GenFunction_1)func_80389740, (s32)this->marker);
        local->unk8 = local->unk0->unk20;
    }
    this->state = next_state;
}

Actor *func_80389B24(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_CCW_3310 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_3310 *)&this->local;
    if( (this->state == 0) 
        || ((this->state == 1) && (local->unk0->unk6 == 0))
    ) {
        return this;
    }
    func_8033A45C(3, (this->state == 4) ? 2 : 1);
    actor_draw(marker, gfx, mtx, vtx);
    func_8034A174(func_80329934(), 5, D_8038FDE0);
    return this;
}

void func_80389BD8(f32 dst[3]){
    dst[0] = D_8038FDE0[0];
    dst[1] = D_8038FDE0[1];
    dst[2] = D_8038FDE0[2];
}

void CCW_func_80389BFC(Actor *this) {
    Struct_CCW_3310_1 *iPtr;
    ActorLocal_CCW_3310 *local;
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];

    local = (ActorLocal_CCW_3310 *)&this->local;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->has_met_before = FALSE;
        this->position[0] = -4900.0f;
        this->position[1] = 4619.0f;
        this->position[2] = 0.0f;
        D_8038FDE0[0] = this->position[0];
        D_8038FDE0[1] = this->position[1];
        D_8038FDE0[2] = this->position[2];
        if (this->state == 0) {
            local->unk4 = 0U;
        }
        local->unk0 = &D_8038F080[0];
        while(local->unk0->map_id != 0 && map_get() != local->unk0->map_id){
            local->unk0++;
        }

        if ((local->unk0->unk2 != 0) && !fileProgressFlag_get(local->unk0->unk2)) {
            marker_despawn(this->marker);
        } else if (!fileProgressFlag_get(local->unk0->unk4)) {
            func_803897B8(this, 1);
        } else {
            func_803897B8(this, 4);
        }

        if (jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE) != 0) {
            marker_despawn(this->marker);
        }
        return;
    } 

    if (local->unk8) {
        skeletalAnim_getProgressRange(this->unk148, &sp5C, &sp58);
        for(iPtr = local->unk8; iPtr->unk0 > 0.0f; iPtr ++){
            if ((sp5C < iPtr->unk0) && (iPtr->unk0 <= sp58)) {
                func_8030E878((s32) iPtr->unk4, randf2(iPtr->unk8 - 0.05, iPtr->unk8 + 0.05), iPtr->unkC, this->position, 500.0f, 2500.0f);
            }
        }
    }
    if (this->state == 1) {
        player_getPosition(sp4C);
        if( !this->has_met_before
            && (local->unkC[2] >= 6500) 
            && (sp4C[2] < 6500.0f) 
            && (local->unk0->unk28 != 0)
        ){
            this->has_met_before = TRUE;
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(0.0f, local->unk0->unk24);
            func_80324DBC(0.0f, local->unk0->unk28, 6, NULL, this->marker, func_80389700, NULL);
        }
        local->unkC[0] = (s32) sp4C[0];
        local->unkC[1] = (s32) sp4C[1];
        local->unkC[2] = (s32) sp4C[2];
        if (item_getCount(ITEM_22_CATERPILLAR) == 0) {
            func_8028F784(0);
        }
        if ((local->unk0->map_id != MAP_43_CCW_SPRING) && ((this->position[0] + 500.0f) < sp4C[0])) {
            player_setCarryObjectPoseInCylinder(this->position, 1110.0f, 200.0f, ACTOR_2A2_CATERPILLAR, &this);
            if ((local->unk0->unkE != 0) && (carriedObj_getActorId() == ACTOR_2A2_CATERPILLAR) && (ml_vec3f_distance(this->position, sp4C) < 1010.0f) && (player_throwCarriedObject() != 0)) {
                player_setThrowTargetPosition(D_8038FDE0);
                if ((local->unk0->map_id == MAP_44_CCW_SUMMER) && (local->unk4 == 0)) {
                    gcdialog_showText(0xCD8, 4, NULL, NULL, NULL, NULL);
                }
                local->unk4++;
                if (local->unk4 < local->unk0->unk25) {
                    func_803897B8(this, 5);
                } else {
                    func_803897B8(this, 2);
                }
            }
        }
        if (fileProgressFlag_get(local->unk0->unk4)) {
            func_803897B8(this, local->unk0->unkC);
        }
    }
    if ((this->state == 2) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        func_803897B8(this, 3);
    }
    if ((this->state == 3) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        func_803897B8(this, 4);
    }
    if ((this->state == 5) && (skeletalAnim_getLoopCount(this->unk148) > 0)) {
        func_803897B8(this, 1);
    }
}
