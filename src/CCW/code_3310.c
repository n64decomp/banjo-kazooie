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
    s16 unk2;
    s16 unk4;
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
void func_80389BFC(Actor *this);

/* .data */
extern Struct_CCW_3310_1 D_8038F060[];
extern Struct_CCW_3310_0 D_8038F080[];
extern ActorInfo D_8038F130 = { MARKER_1B4_EEYRIE_BABY, ACTOR_2A1_EEYRIE_BABY, ASSET_484_MODEL_EAGLE_BABY, 0x0, NULL, func_80389BFC, NULL, func_80389B24, 0, 0, 0.0f, 0};

/* .bss */
extern f32 D_8038FDE0[3];

/* .code */
void func_80389700(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    func_80324E88(0.5f);
    func_80324E38(0.5f, 0);
}

void func_80389740(ActorMarker *marker) {
    Actor *this = marker_getActor(marker);
    if (this->marker->unk14_21) {
        func_802C3F04(func_802C4140, 0x30C, reinterpret_cast(s32, D_8038FDE0[0]), reinterpret_cast(s32, D_8038FDE0[1]), reinterpret_cast(s32, D_8038FDE0[2]));
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
            func_80335924(this->unk148, local->unk0->unk6, 0.2f, 6.0f);
            func_80335A8C(this->unk148, 1);
        }
        local->unk8 = local->unk0->unk8;
    }
    if ((this->state == 1) && (next_state == 2)) {
        func_80320004(local->unk0->unk4, TRUE);
    }
    if (next_state == 5) {
        func_8028F784(1);
        func_80335924(this->unk148, local->unk0->unk26, 0.2f, 2.0f);
        func_80335A8C(this->unk148, 2);
        local->unk8 = &D_8038F060[0];
    }

    if (next_state == 2) {
        func_80335924(this->unk148, local->unk0->unkE, 0.2f, 8.0f);
        func_80335A8C(this->unk148, 2);
        func_80324E38(0.5f, 3);
        timed_setCameraToNode(0.5f, local->unk0->unk24);
        func_80324E88(16.5f);
        func_80324E38(16.5f, 0);
        local->unk8 = local->unk0->unk10;
    }
    if (next_state == 3) {
        actor_collisionOff(this);
        func_80335924(this->unk148, local->unk0->unk14, 0.5f, 8.5f);
        func_80335A8C(this->unk148, 2);
        if (local->unk0->map_id == MAP_43_CCW_SPRING) {
            func_80311480(0xCD6, 4, NULL, NULL, NULL, NULL);
            func_8033579C(this->unk148, 0x3F266666, &func_80389798);
        }
        if (local->unk0->map_id == MAP_44_CCW_SUMMER) {
            func_80311480(0xCD9, 4, NULL, NULL, NULL, NULL);
        }
        if (local->unk0->map_id == MAP_45_CCW_AUTUMN) {
            func_80311480(0xCDB, 4, NULL, NULL, NULL, NULL);
        }
        local->unk8 = local->unk0->unk18;
    }
    if (next_state == 4) {
        func_8028F784(0);
        func_80335924(this->unk148, local->unk0->unk1C, 0.2f, 6.0f);
        func_80335A8C(this->unk148, 1);
        func_80335800(this->unk148, 0.2f, func_80389740, this->marker);
        func_80335800(this->unk148, 0.3f, func_80389740, this->marker);
        func_80335800(this->unk148, 0.4f, func_80389740, this->marker);
        func_80335800(this->unk148, 0.72f, func_80389740, this->marker);
        func_80335800(this->unk148, 0.82f, func_80389740, this->marker);
        func_80335800(this->unk148, 0.92f, func_80389740, this->marker);
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
    func_80325888(marker, gfx, mtx, vtx);
    func_8034A174(func_80329934(), 5, D_8038FDE0);
    return this;
}

void func_80389BD8(f32 dst[3]){
    dst[0] = D_8038FDE0[0];
    dst[1] = D_8038FDE0[1];
    dst[2] = D_8038FDE0[2];
}

void func_80389BFC(Actor *this) {
    Struct_CCW_3310_1 *iPtr;
    ActorLocal_CCW_3310 *local;
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];

    local = (ActorLocal_CCW_3310 *)&this->local;

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk138_24 = FALSE;
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

        if ((local->unk0->unk2 != 0) && !func_8031FF1C(local->unk0->unk2)) {
            marker_despawn(this->marker);
        } else if (!func_8031FF1C(local->unk0->unk4)) {
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
        func_8033568C(this->unk148, &sp5C, &sp58);
        for(iPtr = local->unk8; iPtr->unk0 > 0.0f; iPtr ++){
            if ((sp5C < iPtr->unk0) && (iPtr->unk0 <= sp58)) {
                func_8030E878((s32) iPtr->unk4, randf2(iPtr->unk8 - 0.05, iPtr->unk8 + 0.05), iPtr->unkC, this->position, 500.0f, 2500.0f);
            }
        }
    }
    if (this->state == 1) {
        player_getPosition(sp4C);
        if( !this->unk138_24
            && (local->unkC[2] >= 6500) 
            && (sp4C[2] < 6500.0f) 
            && (local->unk0->unk28 != 0)
        ){
            this->unk138_24 = TRUE;
            func_80324E38(0.0f, 3);
            timed_setCameraToNode(0.0f, local->unk0->unk24);
            func_80324DBC(0.0f, local->unk0->unk28, 6, NULL, this->marker, func_80389700, NULL);
        }
        local->unkC[0] = (s32) sp4C[0];
        local->unkC[1] = (s32) sp4C[1];
        local->unkC[2] = (s32) sp4C[2];
        if (item_getCount(ITEM_22_CATERPILLAR) == 0) {
            func_8028F784(0);
        }
        if ((local->unk0->map_id != MAP_43_CCW_SPRING) && ((this->position[0] + 500.0f) < sp4C[0])) {
            func_8028F364(this->position, 1110.0f, 200.0f, ACTOR_2A2_CATERPILLAR, &this);
            if ((local->unk0->unkE != 0) && (carriedObj_getActorId() == ACTOR_2A2_CATERPILLAR) && (ml_vec3f_distance(this->position, sp4C) < 1010.0f) && (func_8028FC34() != 0)) {
                func_8028FA54(D_8038FDE0);
                if ((local->unk0->map_id == MAP_44_CCW_SUMMER) && (local->unk4 == 0)) {
                    func_80311480(0xCD8, 4, NULL, NULL, NULL, NULL);
                }
                local->unk4++;
                if (local->unk4 < local->unk0->unk25) {
                    func_803897B8(this, 5);
                } else {
                    func_803897B8(this, 2);
                }
            }
        }
        if (func_8031FF1C(local->unk0->unk4)) {
            func_803897B8(this, local->unk0->unkC);
        }
    }
    if ((this->state == 2) && (func_80335794(this->unk148) > 0)) {
        func_803897B8(this, 3);
    }
    if ((this->state == 3) && (func_80335794(this->unk148) > 0)) {
        func_803897B8(this, 4);
    }
    if ((this->state == 5) && (func_80335794(this->unk148) > 0)) {
        func_803897B8(this, 1);
    }
}
