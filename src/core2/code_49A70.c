#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define ABS(s) (((s) >= 0) ? (s) : -(s))

extern f32 func_80309B24(f32[3]);

/* .h */
void func_802D10A4(Actor *this);

typedef struct {
    s32 unk0;
}ActorLocal_core2_49A70;


/* .data */
extern ActorAnimationInfo D_803673C0[];
extern ActorInfo D_80367404 = { 
    0x65, 0x56, 0x3EC,
    0x1, D_803673C0,
    func_802D10A4, func_80326224, func_80325888, 
    2500, 0x333, 0.0f, 0
};

/* .rodata */
extern f32 D_80376640;
extern f64 D_80376648;
extern f64 D_80376650;
extern f64 D_80376658;

/* .code */
void func_802D0A00(Actor *this) {
    this->unk28 = randf2(1.5f, 2.3f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0A38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0DDC.s")

extern void func_802D0F30(ActorMarker *marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D0F30.s")


void func_802D0FC8(Actor *this) {
    this->unk4C += time_getDelta();
    if (MAX(0.25, (12.0 - this->unk28) / 12.0) < this->unk4C) {
        *(s32 *)(&this->local) = NOT(*(s32 *)(&this->local));
        this->unk4C = 0.0f;
        if (*(s32 *)(&this->local)) {
            FUNC_8030E8B4(SFX_2A_CLOCK_TIC_1, 0.5f, 12000, this->position, 0x4E2, 0x9C4);
        }
        else{
            FUNC_8030E8B4(SFX_51_CLOCK_TIC_2, 0.5f, 12000, this->position, 0x4E2, 0x9C4);
        }
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_49A70/func_802D10A4.s")
#else
void func_802D10A4(Actor *this) {
    f32 tick;
    f32 player_position[3];
    f32 var_f2;

    tick = time_getDelta();
    if (!this->initialized) {
        marker_setCollisionScripts(this->marker, NULL, NULL, func_802D0F30);
        this->unk138_25 = TRUE;
        this->initialized = TRUE;
        this->unk4C = 0.0f;
    }
    func_802D0FC8(this);
    this->unk60 += tick;
    if (M_PI <= this->unk60) {
        this->unk60 -= M_PI;
    }
    this->unk1C[0] = this->position[0];
    this->unk1C[1] = this->position[1];
    this->unk1C[2] = this->position[2];
    this->unk1C[1] = func_80309B24(this->position) - 15.0f;
    this->position[1] = this->unk1C[1] - (sinf(this->unk60 * 4.0f) * 10.0f);
    _player_getPosition(player_position);
    switch (this->state) {
        case 1:
            func_802D0A38(this);
            break;

        case 2:
            this->yaw_moving = (f32) func_80329784(this);
            func_80328FB0(this, 4.0f);
            if (func_80329480(this)) {
                var_f2 = ABS(player_position[1] - this->unk1C[1]);
                if (250.0 > var_f2) {
                    func_80328A84(this, 3);
                    actor_loopAnimation(this);
                    FUNC_8030E8B4(SFX_C4_TWINKLY_MUNCHER_GRR, 0.6f, 32750, this->position, 1250, 2500);
                    this->unk28 = 4.0f;
                }
            }
            break;

        case 3:
            this->yaw_moving = (f32) func_80329784(this);
            func_80328FB0(this, this->unk28 / 2);
            this->unk28 = MIN( 50.0, (this->unk28 + tick));
            var_f2 = ABS(player_position[1] - this->unk1C[1]);
            if ((250.0 <= var_f2) || !func_80329054(this, 0)) {
                func_802D0AB8(this);
            }
            break;

        case 4:
            if (animctrl_isStopped(this->animctrl) != 0) {
                marker_despawn(this->marker);
            }
            break;
    }
}
#endif
