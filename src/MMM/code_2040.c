#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorInfo D_8038BC28;
extern ActorInfo D_8038BCDC;
extern ActorInfo D_8038BC4C;
extern ActorInfo D_8038BDB4;
extern ActorInfo D_8038BDD8;
extern ActorInfo D_8038BDFC;
extern ActorInfo D_8038BC94;
extern ActorInfo D_8038BC70;
extern ActorInfo D_8038BD00;
extern ActorInfo D_8038BD24;
extern ActorInfo D_8038BD48;
extern ActorInfo D_8038BD6C;
extern ActorInfo D_8038BCB8;
extern ActorInfo D_8038BD90;
extern ActorInfo chNapper;
extern ActorInfo D_8038BA68;
extern ActorInfo chMotzhand;
extern ActorInfo chLoggo;
extern ActorInfo D_8038BAD0;
extern ActorInfo D_8038BE48;
extern ActorInfo D_8038BE6C;
extern ActorInfo D_8038BE90;
extern ActorInfo D_8038BEB4;
extern ActorInfo D_8038BED8;
extern ActorInfo D_8038BEFC;

extern ActorInfo D_80367E70;
extern ActorInfo D_80372C3C;

void func_802D3D54(Actor *this);
void func_803888B8(Actor *this);
Actor *func_80388994(ActorMarker *marker, Gfx ** gfx, Mtx **mtx, Vtx **vtx);
void func_80388BDC(Actor *this);
void func_80388FE4(Actor *this);
void func_80389004(Actor *this);
void func_80389060(Actor *this);
void func_803890B8(Actor *this);


/* .data */
extern ActorAnimationInfo D_8038BBE0[];

extern ActorInfo D_8038BC28 = {
    0x9C, 0x109, 0x3CD,
    0x1, NULL,
    func_802D3D54, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BC4C = {
    0x9E, 0x10B, 0x3CF,
    0x1, NULL,
    func_802D3D54, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BC70 = {
    0x9A,  0xCB, 0x3CC,
    0x1, NULL,
    func_802D3D54, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BC94 = {
    0xA2, 0x114, 0x3D3,
    0x1, NULL,
    func_80388BDC, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BCB8 = {
    0xE7, 0x265, 0x4DA,
    0x1, NULL,
    func_80389004, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BCDC = {
    0x9D, 0x10A, 0x3CE,
    0x1, NULL,
    func_80389004, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BD00 = {
    0xD3, 0x191, 0x50B,
    0x1, NULL,
    func_80389060, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BD24 = {
0x123, 0x2E8, 0x4C0,
    0x1, NULL,
    func_803890B8, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BD48 = {
0x1F2, 0x2E9, 0x4C1,
    0x1, NULL,
    func_803890B8, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BD6C = {
0x1F3, 0x2EA, 0x4C2,
    0x1, NULL,
    func_803890B8, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BD90 = {
    0xFE, 0x1FD, 0x43D, 
    0x1, D_8038BBE0,
    func_80388FE4, func_80326224, func_80325888,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BDB4 = {
    0x9F, 0x10C, 0x3D0,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BDD8 = {
    0xA0, 0x10D, 0x3D1,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038BDFC = {
    0xFF, 0x1FE, 0x43E,
    0x1, NULL,
    func_803888B8, func_80326224, func_80388994,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80388430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80388670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_803888B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80388994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80388B2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80388BDC.s")

void func_80388FE4(Actor *this) { 
    func_802D4A9C(this,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80389004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/MMM/code_2040/func_80389060.s")

void func_803890B8(Actor *this) {
    func_802D3D54(this);
    func_8038AC04();
}

void func_803890E0(void){
    spawnableActorList_add(&D_8038BC28, actor_new, 0);
    spawnableActorList_add(&D_8038BCDC, actor_new, 0);
    spawnableActorList_add(&D_8038BC4C, actor_new, 0);
    spawnableActorList_add(&D_8038BDB4, actor_new, 0x40);
    spawnableActorList_add(&D_8038BDD8, actor_new, 0x40);
    spawnableActorList_add(&D_8038BDFC, actor_new, 0x440);
    spawnableActorList_add(&D_8038BC94, actor_new, 0);
    spawnableActorList_add(&D_8038BC70, actor_new, 0);
    spawnableActorList_add(&D_8038BD00, actor_new, 0);
    spawnableActorList_add(&D_8038BD24, actor_new, 0x8600);
    spawnableActorList_add(&D_8038BD48, actor_new, 0x8600);
    spawnableActorList_add(&D_8038BD6C, actor_new, 0x8600);
    spawnableActorList_add(&D_8038BCB8, actor_new, 0x8600);
    spawnableActorList_add(&D_8038BD90, actor_new, 8);
    spawnableActorList_add(&chNapper, actor_new, 0x18A0);
    spawnableActorList_add(&D_8038BA68, actor_new, 0x100);
    spawnableActorList_add(&chMotzhand, actor_new, 0x20880);
    spawnableActorList_add(&D_80367E70, actor_new, 0);
    spawnableActorList_add(&chLoggo, actor_new, 0x108);
    spawnableActorList_add(&D_8038BAD0, actor_new, 0x2800960);
    spawnableActorList_add(&D_8038BE48, actor_new, 0x800040);
    spawnableActorList_add(&D_8038BE6C, actor_new, 0x800040);
    spawnableActorList_add(&D_8038BE90, actor_new, 0x800040);
    spawnableActorList_add(&D_8038BEB4, actor_new, 0x800040);
    spawnableActorList_add(&D_8038BED8, actor_new, 0x800040);
    spawnableActorList_add(&D_8038BEFC, actor_new, 0x800040);
    spawnableActorList_add(&D_80372C3C, actor_new, 0xA11A9);
}
