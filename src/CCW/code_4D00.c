#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80335A24(void *, s32, f32, f32);

typedef struct {
    f32 unk0;
}ActorLocal_CCW_4D00;

typedef struct {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
}Struct_CCW_4D00_0;

void func_8038B19C(Actor *this);

/* .data */
ActorInfo D_8038F270 = {
    0x1B9, 0x2A6, 0x502,
    0x0, NULL,
    func_8038B19C, NULL, func_80325888,
    0, 0, 0.0f, 0
};

Struct_CCW_4D00_0 D_8038F294[] = {
    {0.12f, 1.6f,  SFX_A7_WOODEN_SWOSH,  8000},
    {0.21f, 1.7f,  SFX_A7_WOODEN_SWOSH,  8500},
    {0.3f , 1.6f,  SFX_A7_WOODEN_SWOSH,  8000},
    {0.51f, 1.0f,  SFX_4C_LIP_SMACK,    22000},
    {0.65f, 1.05f, SFX_4C_LIP_SMACK,    23000},
    {0.76f, 1.0f,  SFX_4C_LIP_SMACK,    22000},
    {0.88f, 1.0f,  SFX_4C_LIP_SMACK,    23000},
    0
};

/* .code */
void func_8038B0F0(Actor *this, s32 next_state) {
    ActorLocal_CCW_4D00 *local = (ActorLocal_CCW_4D00 *)&this->local;

    local->unk0 = 0.0f;
    if (next_state == 1) {
        func_80335A24(this->unk148, 0x1A3, 0.2f, 11.0f);
        local->unk0 = randf2(3.0f, 10.0f);
    }
    if (next_state == 2) {
        func_80335924(this->unk148, 0x1A4, 0.2f, 3.0f);
    }
    this->state = next_state;
}

void func_8038B19C(Actor *this) {
    ActorLocal_CCW_4D00 *local;
    f32 tick;
    Struct_CCW_4D00_0 *iPtr;
    f32 sp50;
    f32 sp4C;

    local = (ActorLocal_CCW_4D00 *)&this->local;
    tick = time_getDelta();

    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->unk138_24 = FALSE;
        func_8038B0F0(this, 1);
    }

    if ((this->state == 1) && func_8025773C(&local->unk0, tick)) {
        func_8038B0F0(this, 2);
    }

    if (this->state == 2) {
        func_8033568C(this->unk148, &sp50, &sp4C);
        for(iPtr = &D_8038F294[0]; iPtr->unk0 > 0.0f; iPtr++){
            if ((sp50 < iPtr->unk0) && (iPtr->unk0 <= sp4C)) {
                func_8030E878(iPtr->unk8, randf2(iPtr->unk4 - 0.05, iPtr->unk4 + 0.05), randi2(iPtr->unkA - 0x1F4, iPtr->unkA + 0x1F4), this->position, 500.0f, 2500.0f);
            }
        }

        if ((sp50 < 0.97) && (0.97 <= sp4C)) {
            if (randf() >= 0.5) {
                func_8030E878(SFX_AE_YUMYUM_TALKING, randf2(1.8f, 1.85f), randi2(19000, 21000), this->position, 500.0f, 2500.0f);
            } else {
                func_8030E878(SFX_4B_GULPING, randf2(1.4f, 1.45f), randi2(24000, 26000), this->position, 500.0f, 2500.0f);
            }
        }
        if (func_80335794(this->unk148) > 0) {
            func_8038B0F0(this, 1);
        }
    }
    if (!this->unk138_24 && func_803292E0(this)) {
        this->unk138_24 = TRUE;
        func_80311480(0xCC8, 0, NULL, NULL, NULL, NULL);
    }
    func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
}
