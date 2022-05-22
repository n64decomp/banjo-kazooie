#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80390E28(Actor *this);

/* .data */
extern ActorInfo D_80394A80 = { 0x1EC, 0x377, 0x0, 0x0, NULL, func_80390E28, func_80326224, func_80325340, { 0xB, 0xB8}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}};

/* .rodata */
extern f32 D_803952B0; //! 0.2f
extern f32 D_803952B4; //! 0.6f
extern f32 D_803952B8;

/* .code */
void func_80391EA8(ActorMarker *, ActorMarker *, f32 [3], f32, f32, s32);


void func_80390C00(ActorMarker *marker)
{
    Actor *actor;
    Actor *newActor;
    s32    pad;

    actor    = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    newActor = spawn_child_actor(0x3BB, &actor);

    func_80391EA8(
        newActor->marker, actor->marker, actor->unk1C,
        randf2(1400, 1800),
        randf2(D_803952B0, D_803952B4),
        randf() < 0.5 ? 1 : 0
    );
}

void func_80390CB4(ActorMarker *marker)
{
    Actor *actor;
    Actor *newActor;
    s32    pad;

    actor    = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    newActor = spawn_child_actor(0x3BB, &actor);

    func_80391EA8(
        newActor->marker, actor->marker, actor->unk1C,
        randf2(1200, 1400),
        randf2(D_803952B8, 1),
        -1
    );
}

void func_80390D3C(Actor *this, s32 val)
{
    func_80328A84(this, val);

    switch (val)
    {
        case 2:
        {
            if (this->unk10_12)
            {
                s32 rand = randi2(0, this->unk10_12);

                f32 *ptr = (f32 *)&this->unk7C[rand * 0xC];

                //! Using f32 array access doesn't match?
                this->unk1C[0] = *(f32 *)((u32)ptr + 0);
                this->unk1C[1] = *(f32 *)((u32)ptr + 4);
                this->unk1C[2] = *(f32 *)((u32)ptr + 8);
            }
            else
            {
                this->unk1C[0] = this->position_x;
                this->unk1C[1] = this->position_y;
                this->unk1C[2] = this->position_z;
            }

            func_802C3C88((void *)func_80390C00, this->marker);

            break;
        }
        case 1:
        {
            this->unk1C[0] = this->position_x;
            this->unk1C[1] = this->position_y;
            this->unk1C[2] = this->position_z;

            func_802C3C88((void *)func_80390CB4, this->marker);

            break;
        }
        default:
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_A810/func_80390E28.s")
