#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CD8(f32);
extern Actor *func_8032813C(enum actor_e, f32[3], s32);

Actor *func_8038CED0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038D6C8(Actor *this);

/* .data */
extern ActorAnimationInfo D_803920C0[];

extern ActorInfo D_803920E8 = { 0x204, 0x336, 0x442,
    0x1, D_803920C0,
    func_8038D6C8, func_80326224, func_8038CED0,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};
extern f32 D_80392354[3];
extern f32 D_80392360[3];
extern enum actor_e D_8039236C[];
extern f32 D_8039237C[3];

/* .rodata */
extern f32 D_80392E00;
extern f32 D_80392E04;
extern f32 D_80392E08;
extern f32 D_80392E0C;
extern f32 D_80392E10;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038CF54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D0A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D208.s")

void func_8038D294(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D294.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D324.s")

void func_8038D3B0(UNK_TYPE(s32) arg0){
    item_set(ITEM_6_HOURGLASS, FALSE);
}

void func_8038D3D8(void){
    comusic_8025AB44(COMUSIC_68_TWINKLY_MINIGAME, 0, 4000);
    func_8025AABC(COMUSIC_68_TWINKLY_MINIGAME);
    func_8025A58C(-1, 4000);
    func_8024BD08(1);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D41C.s")
#else
void func_8038D41C(ActorMarker *marker){
    ActorMarker *_marker = reinterpret_cast(ActorMarker *, marker);
    Actor *actor;
    
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392354, 170);
    actor->unk100 = _marker;
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392360, 170);
    actor->unk100 = _marker;
}
#endif

void func_8038D474(ActorMarker *marker){
    Actor *actor  = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    Actor *child;
    s32 pad;

    if((s32)actor->unk1C[0] >= 3){
        actor->unk1C[0] = -1.0f;
    }
    actor->unk1C[0] += 1.0;
    child = spawn_child_actor(D_8039236C[(s32)actor->unk1C[0]], &actor);
    child->unk100 = actor->marker;
}

void func_8038D51C(Actor *marker){
    Actor *this = marker_getActor(marker);
    
    item_set(ITEM_6_HOURGLASS, FALSE);
    func_80320004(BKPROG_13, TRUE);
    FUNC_8030E624(SFX_416, 1000, 0x332);
    func_8028F8F8(7, 0);
    this->unk1C[1] = 1.0f;
    func_80324E88(D_80392E00);
    func_80324E38(D_80392E04, 0);
    timedFunc_set_1(D_80392E08, (TFQM1)func_8038D294, (s32)this->marker);
    this->velocity[1] = 1.0f;
}

#ifndef NONMATCHING
//matches once .rodata defined
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D5C8.s")
#else
void func_8038D5C8(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);

    if(this->state == 1 || this->state == 2){
        actor_collisionOff(this);
        timed_setCameraToNode(0.0f, 0xa);
        func_80324CD8(D_80392E0C);
        func_8028F784(1);
        func_8028F490(D_8039237C);
        func_8028F8F8(7, 1);
        this->unk1C[1] = 0.0f;
        func_8025A6EC(COMUSIC_68_TWINKLY_MINIGAME, 25000);
        func_8025A58C(0, 4000);
        func_8024BD08(0);
        this->unk1C[2] = D_80392E10; //428571.0f;
        func_8025AEA0(0x68, (s32)this->unk1C[2]);
        func_80328B8C(this, 3, 0.001f, 1);
        actor_playAnimationOnce(this);
        this->velocity[0] = 1.0f;
    }//L8038D6B8
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_6AE0/func_8038D6C8.s")

bool func_8038DD14(void){
    return mapSpecificFlags_get(0xD);
}

bool func_8038DD34(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    if(func_80329530(this, 800))
        return TRUE;
    return FALSE;
}
