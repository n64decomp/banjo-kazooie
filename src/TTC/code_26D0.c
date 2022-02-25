#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"

extern ActorInfo D_8038C3D0;
extern ActorInfo D_8038C510;
extern ActorInfo D_8038C580;
extern ActorInfo D_8038C5E0;
extern ActorInfo D_8038C604;
extern ActorInfo D_8038C628;
extern ActorInfo D_8038C64C;
extern ActorInfo D_8038C670;
extern ActorInfo D_8038C694;
extern ActorInfo D_8038C6B8;
extern ActorInfo D_8038C6DC;
extern ActorInfo D_8038C718;
extern ActorInfo D_8038C790;
extern ActorInfo D_8038C7B4;
extern ActorInfo D_8038C7D8;
extern ActorInfo D_8038C8B0;
extern ActorInfo D_8038C8D4;
extern ActorInfo D_8038C8F8;
extern ActorInfo gChTreasureInfo;

void func_80388C78(Actor *this);
void func_80388CB8(Actor *this);
void func_80388D34(Actor *this);
void func_802D3D54(Actor *this);
void func_80388D8C(Actor *this);

/* .data */
extern ActorInfo D_8038C5E0 = {
     0xA1, 0x10E, 0x3D2,
     0x1, NULL, 
     func_802D3D54, func_80326224, func_80325E78,
     { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C604 = {
     MARKER_EA_LIGHTHOUSE_DOOR, ACTOR_13E_LIGHTHOUSE_DOOR, ASSET_3D6_MODEL_LIGHTHOUSE_DOOR,
     0x1, NULL, 
     func_802D3D54, func_80326224, func_80325E78,
     { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C628 = {
    MARKER_167_SHARKFOOD_ISLAND, ACTOR_25C_SHARKFOOD_ISLAND, ASSET_50A_MODEL_SHARKFOOD_ISLAND,
    0x1, NULL, 
    func_80388D8C, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C64C = {
    0x267, 0x2E2, 0x3BD,
    0x1, NULL, 
    func_80388D34, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C670 = {
    0x26A, 0x2DF, 0x3BE,
    0x1, NULL, 
    func_80388C78, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C694 = {
    0x268, 0x2E0, 0x3B6,
    0x1, NULL, 
    func_80388C78, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C6B8 = {
    0x269, 0x2E1, 0x3B7,
    0x1, NULL, 
    func_80388C78, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8038C6DC = {
    MARKER_1D5_PALM_TREE, ACTOR_31E_PALM_TREE, ASSET_3A9_MODEL_PALM_TREE,
    0x1, NULL, 
    func_80388CB8, func_80326224, func_80325E78,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
void func_80388AC0(void)
{
    spawnableActorList_add(&D_8038C5E0, actor_new, 0);
    spawnableActorList_add(&D_8038C604, actor_new, 0);
    spawnableActorList_add(&D_8038C580, actor_new, 0X4100168);
    spawnableActorList_add(&D_8038C510, actor_new, 0X4000101);
    spawnableActorList_add(&D_8038C718, actor_new, 0X188);
    spawnableActorList_add(&D_8038C790, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7B4, actor_new, 0X148);
    spawnableActorList_add(&D_8038C7D8, actor_new, 0X148);
    spawnableActorList_add(&D_8038C8B0, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8D4, actor_new, 0X400);
    spawnableActorList_add(&D_8038C8F8, actor_new, 0X400);
    spawnableActorList_add(&gChTreasureInfo, actor_new, 0X2000048);
    spawnableActorList_add(&D_8038C628, actor_new, 0X8680);
    spawnableActorList_add(&D_8038C64C, actor_new, 0X400);
    spawnableActorList_add(&D_8038C670, actor_new, 0X20404);
    spawnableActorList_add(&D_8038C694, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6B8, actor_new, 0X400);
    spawnableActorList_add(&D_8038C6DC, actor_new, 0X400);
    spawnableActorList_add(&D_8038C3D0, actor_new, 0X2000041);
}

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388CB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_26D0/func_80388D8C.s")
