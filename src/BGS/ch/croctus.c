#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80387D18(ActorMarker *, u32);
Actor *func_8038860C(ActorMarker *, Gfx**, Mtx **, u32);


extern u32 bgs_D_803907B8[5];

//.rodata
extern f64 D_80390EE0;
extern f64 D_80390EE8;

void func_80387C90(Actor *arg0){
    animctrl_setDuration(arg0->animctrl, (f32)(5 - arg0->unkF4_8) * 0.25 *D_80390EE0 + D_80390EE8);
}


/* .code */
void func_80387D18(ActorMarker * arg0, u32 arg1){
    Actor* actPtr;
    Actor* nextActPtr;

    actPtr = marker_getActor(arg0);
    nextActPtr = spawn_child_actor(0x6A, &actPtr);
    nextActPtr->state = 2;
    nextActPtr->unkF4_8 = 0x8C;
    nextActPtr->unk60 = 3.0f;
    nextActPtr->unk38_31 = arg1;
    if(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/croctus/func_80387D90.s")
// void *func_80387D90(ActorMarker * arg0){
//     Actor* actPtr;
//     ActorProp *propPtr;
//     f32 spawnPos[3];
//     //if(arg0);
//     actPtr = marker_getActor(arg0);
//     //if(arg0);
//     spawnPos[0] = actPtr->position_x;
//     spawnPos[1] = actPtr->position_y;
//     spawnPos[2] = actPtr->position_z;
//     if(arg0);
//     arg0->propPtr->unk8_3 = 0;
//     func_802BAFE4(0x19);
//     jiggySpawn(0x22, spawnPos);
//     func_8025A6EC(JINGLE_PUZZLE_SOLVED_FANFARE, 0x7FFF);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/croctus/func_80387E00.s")
// void func_80387E00(ActorMarker * arg0){
//     Actor * thisActor = marker_getActor(arg0);

//     func_803262E4(thisActor);
//     if(arg0);
//     func_802C3D3C(func_80387D18, arg0, 0x1E);
    
// }

void func_80387E40(ActorMarker * arg0){
    Actor *thisActor = marker_getActor(arg0);
    func_80326310(thisActor);
    if(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/croctus/func_80387E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/croctus/func_80387FD4.s")

void bgs_func_803885DC(void){
    s32 i;
    for(i = 0; i<5; i++)
        bgs_D_803907B8[i] = 0;
}

Actor *func_8038860C(ActorMarker *this, Gfx** gdl, Mtx ** mptr, u32 arg3){
    Actor *thisActor; 
    thisActor = marker_getActor(this);
    func_8033A45C(1, thisActor->unkF4_8);
    return func_80325888(this, gdl, mptr, arg3);
}
