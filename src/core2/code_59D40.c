#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80256280(f32 [3], f32 [3]);
extern f32 func_80309B24(f32[3]);

typedef struct {
    s32 unk0;
}ActorLocal_core2_59D40;


void func_802E1168(Actor *this);

/* .data */
ActorAnimationInfo D_803685D0[] ={
    {0x000, 0.0f},
    {0x078, 2.0f},
    {0x078, 1.0f},
    {0x078, 0.4f},
    {0x078, 0.4f},
    {0x154, 1.1f},
    {0x078, 0.4f},
    {0x078, 1.0f},
    {0x273, 0.53f},
    {0x274, 1.09f}
};

ActorInfo D_80368620 = { 
    0x14, 0x68, 0x3B0,
    0x1, D_803685D0,
    func_802E1168, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern f32 D_80377050;

/* .bss */
extern ActorMarker *D_8037E620;
extern s32 D_8037E630;

/* .code */
void func_802E0CD0(Actor *this){
    this->unk28 = 4.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E0CE0.s")

bool func_802E0DC0(f32 arg0[3]){
    f32 sp2C[3];
    f32 pad0;

    player_getPosition(sp2C);
    return (D_80377050 < func_80256280(sp2C, arg0))
        || ( (arg0[1] - func_80309724(arg0) < 70.0f) && (func_80309B24(arg0) - arg0[1] < 70.0f));
}

void func_802E0E88(Actor *this){
    this->unk28 = 2.0f;
    func_80328B8C(this, 5, 0.0f, -1);
    actor_playAnimationOnce(this);
}

void func_802E0EC8(void){
    Actor *this;
    ActorLocal_core2_59D40 *local;

    this = marker_getActor(D_8037E620);
    local = (ActorLocal_core2_59D40 *)&this->local;

    actor_collisionOff(this);
    D_8037E620->propPtr->unk8_3 = FALSE;
    if(local->unk0 != 2){
        func_8032BB88(this, -1, 750);
        comusic_8025AB44(COMUSIC_34_SNACKER_DANGER, 0, 750);
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        local->unk0 = 2;
    }
}

void func_802E0F60(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    actor_collisionOff(this);
    FUNC_8030E8B4(SFX_179_GRUNTY_DAMAGE, 0x3FF, 0x265, this->position, 300, 3000);
    func_80328B8C(this, 9, 0.0f, 1);
    actor_playAnimationOnce(this);
}

void func_802E0FC4(Actor *this){
    D_8037E620 = NULL;
    D_8037E630 = this->unk166;
    if(func_8025AD7C(COMUSIC_34_SNACKER_DANGER)){
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        func_8025A7DC(COMUSIC_34_SNACKER_DANGER);
    }
}

void func_802E1010(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    func_80328B8C(this, 8, 0.0f, 1);
    actor_playAnimationOnce(this);
}

void func_802E1050(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if(level_get() == LEVEL_2_TREASURE_TROVE_COVE && !func_8028F22C()){
        func_80311480(0xA29, 0, NULL, NULL, NULL, NULL);
    }//L802E10A4

    if(this->state == 4){
        if(func_803294F0(this, 80, func_80329784(this))){
            func_802E0E88(this);
        }
    }//L802E10E0
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E10F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E1168.s")

/* BREAK??? */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E1790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E17E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_59D40/func_802E1A04.s")
