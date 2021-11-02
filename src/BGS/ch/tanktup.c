#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

Actor* func_8032813C(s32, f32*, s32);

void func_80324E88(f32);

void timedFunc_set_2(f32, void(*)(s32, s32), s32, s32);




void func_8038F6A4(Actor *);
void func_8038FBF8(Actor *);

/* .data */
//padding indicates seperate headers for each part ??
ActorAnimationInfo D_80390C20[] = {
    {0, 0.0f},
    {0x101, 7.5f},
    {0x102, 1.75f},
    {0x107, 1.75f}
};

ActorInfo D_80390C40 = {0x6C, 0xE8, 0x3EE, 0x01, D_80390C20,
    func_8038F6A4, func_80326224, func_80325888,
    {0,0,0,0x80}, 0.0f, {0,0,0,0}
};
u8 pad_80390C6C[0xC] = {0};


ActorAnimationInfo D_80390C70[3] = {
    {0, 0.0f},
    {0x103, 8000000.0f},
    {0x103, 0.75f}
};

ActorInfo D_80390C88 = {0x6D, 0xE9, 0x3EF, 0x01, D_80390C70,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390CCC[4] = {0};

ActorAnimationInfo D_80390CB0[3] = {
    {0, 0.0f},
    {0x104, 8000000.0f},
    {0x104, 0.75f}
};

ActorInfo D_80390CC8 = {0x6D, 0xEA, 0x3F0, 0x01, D_80390CB0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390CEC[4] = {0};

ActorAnimationInfo D_80390CF0[3] = {
    {0, 0.0f},
    {0x105, 8000000.0f},
    {0x105, 0.75f}
};

ActorInfo D_80390D08 = {0x6D, 0xEB, 0x3F1, 0x01, D_80390CF0,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};
u8 pad_80390C2C[4] = {0};

ActorAnimationInfo D_80390C30[3] = {
    {0, 0.0f},
    {0x106, 8000000.0f},
    {0x106, 0.75f}
};

ActorInfo D_80390D48 = {0x6D, 0xEC, 0x3F2, 0x01, D_80390C30,
    func_8038FBF8, func_80326224, func_80325888,
    {0,0,1,0x66}, 0.0f, {0,0,0,0}
};

/* .rodata */
extern f32 D_803911C0;

/* .code */
void func_8038F470(ActorMarker *this, s32 arg1, s32 arg2){
    Actor* thisActor;
    f32 pad;
    Actor* sp24;
    f32 sp18[3];

    thisActor = marker_getActor(this);
    sp18[0] = thisActor->position_x;
    sp18[1] = thisActor->position_y;
    sp18[2] = thisActor->position_z;
    sp18[1] += 50.0f;

    sp24 = func_8032813C(arg2 + 0xe9, sp18, (s32)thisActor->yaw);
    func_80328B8C(sp24, arg1 + 1, 0, -1);
    sp24->unk10_12 = arg2;
}

void func_8038F51C(Actor *this){
    Actor * spawnPtr;
    spawnPtr = func_80326D68(this->position, 0xe8, -1, 0);
    spawnPtr->tanktup.unk0[this->unk10_12] = 1;
    spawnPtr->tanktup.unk10 = 1;
}

s32 func_8038F570(s16 *arg0){
    f32 pos[3];
    Actor * spawnPtr;

    pos[0] = (f32)arg0[0];
    pos[1] = (f32)arg0[1];
    pos[2] = (f32)arg0[2];
    spawnPtr = func_80326D68(pos, 0xe8, -1, 0);
    return spawnPtr->state == 3;


}

void func_8038F5E4(s32 arg0, s32 arg1, s32 arg2){
    func_80324E88(0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/tanktup/func_8038F6A4.s")

//===BREAK

void func_8038FB40(ActorMarker *this, s32 arg1){
    Actor * thisActor;

    thisActor = marker_getActor(this);
    func_80328A84(thisActor, 2);
    actor_playAnimationOnce(thisActor);
    func_8030E624(0x665ff80A);
}

void func_8038FB84(ActorMarker *this, s32 arg1){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    FUNC_8030E8B4( SFX_87_TANKTUP_OOOHW, 0x7FF, 0x3FF, thisActor->position, 1000, 3000);
    timedFunc_set_2(D_803911C0, func_8038FB40, this, arg1);
    func_8038F51C(thisActor);
    this->collidable = 0;
}

void func_8038FBF8(Actor *this){
    if(!this->initialized){
        this->initialized = 1;
        this->marker->propPtr->unk8_3 = 1;
        func_803300A8(this->marker, NULL, NULL, func_8038FB84);
    }
    if(this->state == 2){
        if(animctrl_isAt(this->animctrl, 0.65f)){
            func_8030E540(0x7C);
        }
        if(animctrl_isStopped(this->animctrl)){
            marker_despawn(this->marker);
        }
    }
}