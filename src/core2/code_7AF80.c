#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

extern f32 func_803243D0(struct56s *arg0, f32 arg1[3]);

extern s32 D_803820B8;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80301F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80301F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80302634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80302C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803035F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030364C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803036A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303C54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F6C.s")

extern s32 D_80382148;

void func_80303D78(ActorMarker *, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80303F7C.s")
// Prop *func_80303F7C(ActorMarker *arg0, f32 arg1, s32 arg2, s32 arg3) {
//     s32 temp_v1;

//     if (arg3 == 0) {
//         func_80303D78(arg0, arg1);
//         D_80382148 = 0;
//         return 0;
//     }
//     temp_v1 = *(&D_803820B8 + D_80382148);
//     if (temp_v1 != 0) {
//         D_80382148++;
//     }
//     return temp_v1;
// }

s32 func_80303FE4(s32 arg0, f32 arg1) {
    func_80303D78(arg0, arg1);
    return D_803820B8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803040EC.s")

void func_803045CC(s32 arg0, s32 arg1){}

void func_803045D8(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803045E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803046A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803048E0.s")

s32 func_80304984(s32 arg0, u32 *arg1) {
    u16 *temp_v0;

    temp_v0 = func_803049CC(arg0, 0);
    if (temp_v0 != 0) {
        *arg1 = (u32) ((u32) temp_v0[3] >> 7);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803049CC.s")

void *func_80304C38(s32 arg0, Actor *arg1){
    s32 vec[3];
    s32 *phi_a1;

    if (arg1 != 0) {
        vec[0] = arg1->position_x;
        vec[1] = arg1->position_y;
        vec[2] = arg1->position_z;
    }
    if (arg1 == 0) {
        phi_a1 = NULL;
    } else {
        phi_a1 = vec;
    }
    return func_803049CC(arg0, phi_a1);
}

void func_80304CAC(s32 arg0, f32 *arg1) {
    s32 vec[3];

    vec[0] = arg1[0];
    vec[1] = arg1[1];
    vec[2] = arg1[2];
    func_803049CC(arg0, vec);
}

void func_80304D04(s32 arg0, s16 *arg1) {
    s32 arr[3];

    arr[0] = arg1[0];
    arr[1] = arg1[1];
    arr[2] = arg1[2];
    func_803049CC(arg0, arr);
}

u32 func_80304D3C(u16 *arg0) {
    return (u32)arg0[3] >> 7;
}

void func_80304D4C(s16 *arg0, s32 *arg1) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

void func_80304D68(s16 *arg0, f32 arg1[3]) {
    arg1[0] = arg0[0];
    arg1[1] = arg0[1];
    arg1[2] = arg0[2];
}

u32 func_80304DA8(u32 *arg0) {
    return arg0[3] >> 0x17;
}

s32 func_80304DB8(u32 *arg0) {
    return arg0[3] & 0x7FFFFF;
}

s32 func_80304DD0(s32 arg0, s32 *arg1) {
    s16 *temp_v0;

    temp_v0 = func_803049CC(arg0, 0, arg1);
    if (temp_v0 != 0) {
        arg1[0] = (s32) temp_v0[0];
        arg1[1] = (s32) temp_v0[1];
        arg1[2] = (s32) temp_v0[2];
        return 1;
    }
    return 0;
}

s32 func_80304E24(s32 arg0, f32 *arg1) {
    s32 vec[3];

    if (func_80304DD0(arg0, vec) == 0) {
        return 0;
    }
    arg1[0] = vec[0];
    arg1[1] = vec[1];
    arg1[2] = vec[2];
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80304FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030508C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030515C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030526C.s")

extern ActorInfo D_803675F0;
extern ActorInfo D_80367838;

extern s32 sSpawnableActorSize; //0x8036A9B0
extern ActorSpawn *sSpawnableActorList; //0x8036A9B4
extern struct {
    struct55s *unk0;
    u8 pad4[0x24];
    s32 unk28;
} D_80381FA0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305344.s")

void spawnableActorList_new(void){
    sSpawnableActorList = malloc(0);
    sSpawnableActorSize = 0;
}

void spawnableActorList_free(void){
    free(sSpawnableActorList);
    sSpawnableActorList = NULL;
    sSpawnableActorSize = 0;
}

void spawnableActorList_add(ActorInfo *arg0, Actor *(*arg1)(s32[3], s32, ActorInfo *, u32), u32 arg2){
    sSpawnableActorSize++;
    sSpawnableActorList = realloc(sSpawnableActorList, sSpawnableActorSize*sizeof(ActorSpawn));
    sSpawnableActorList[sSpawnableActorSize - 1].infoPtr = arg0;
    sSpawnableActorList[sSpawnableActorSize - 1].spawnFunc = arg1;
    sSpawnableActorList[sSpawnableActorSize - 1].unk8 = arg2;
}

void spawnableActorList_addIfMapVisited(ActorInfo *arg0, Actor *(*arg1)(s32[3], s32, ActorInfo *, u32), u32 arg2, enum map_e arg3){
    if( level_get() != LEVEL_6_LAIR
        || (level_get() == LEVEL_6_LAIR && func_802D6A38(arg3))
    ){
        spawnableActorList_add(arg0, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305510.s")

Actor * func_803055E0(enum actor_e arg0, s32 arg1[3], s32 arg2, s32 arg3){
    Actor *actor = func_803056FC(arg0, arg1, arg2);
    s16 *tmp;
    s32 sp34[3];
    f32 sp28[3];

    if(actor){
        tmp = func_80305510(arg3);
        if(tmp){
            func_80304D4C(tmp, sp34);
            actor->unk44_14 = func_80341D5C(arg1, sp34);
        }
        else{
            actor->unk44_14 = func_80341C78(arg1);
        }
        if(!(actor->unk44_14  < 0)){
            sp28[0] = (f32)arg1[0];
            sp28[1] = (f32)arg1[1];
            sp28[2] = (f32)arg1[2];
            actor->unk48 = func_803243D0(func_80342038(actor->unk44_14), sp28);
            actor->marker->unk2C_2 = TRUE;
        }
    }
    return actor;
}


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803056FC.s")
#else
Actor *func_803056FC(enum actor_e arg0, s32 arg1[3], s32 arg2) {
    s32 i;

    if (func_80320248() == 0) {
        arg0 = ACTOR_4_BIGBUTT;
    }
    for(i=0; i < sSpawnableActorSize; i++){
        if(arg0 == sSpawnableActorList[i].infoPtr->actorId)
            return sSpawnableActorList[i].spawnFunc(arg1, arg2, sSpawnableActorList[i].infoPtr, sSpawnableActorList[i].unk8);
    }
    return NULL;
}
#endif

void func_8030578C(void){
    int i;
    u32 sp40;
    struct55s *iPtr;
    
    if(getGameMode() != GAME_MODE_7_ATTRACT_DEMO){
        osPiReadIo(0xE38, &sp40);
        sp40 ^= 0x828A;
        if( (sp40 & 0xffff)
            && (sSpawnableActorList != NULL)
        ){
            for(i = 0; i < sSpawnableActorSize - 1; i++){
                if(sSpawnableActorList[i].infoPtr == &D_80367838){
                    sSpawnableActorList[i].infoPtr = &D_803675F0;
                    sSpawnableActorList[i].spawnFunc = actor_new;
                    sSpawnableActorList[i].unk8 = 0;
                    break;
                }
            }
        }
    }//L80305850
    for(iPtr = D_80381FA0.unk0; iPtr < D_80381FA0.unk0 + D_80381FA0.unk28; iPtr++){
        func_80330208(iPtr);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803058C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305C84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80305F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803062D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803063D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030644C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803064C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803065E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030688C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306DDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80306EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803073CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803077FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80307EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803080C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803082D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803083B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803084F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803086B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803088C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030895C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F54.s")

extern s32 D_80382360;
extern s32 D_80382364;
extern s32 D_80382368;
extern s32 D_8038236C;
extern s32 D_80382374;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80308FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803091D4.s")
// void func_803091D4(Gfx **gdl, Mtx **mptr, Vtx **vptr){
//     if( func_80320708() 
//         && levelSpecificFlags_validateCRC2() 
//         && func_80320248()
//     ){
//         if(func_8030A068() == 0x14cf){
//             func_8033A45C(1, 0);
//             func_8033A45C(2, 1);
//         }

//         switch(func_803348C0())
//         {

//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309724.s")

s32 func_80309744(s32 arg0){
    return (arg0) ? D_80382364 : D_80382360;
}

s32 func_80309764(s32 arg0){
    if(arg0 == 0)
        return D_80382368;
    if(arg0 == 1)
        return D_8038236C;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803097A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_803097AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309D58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_80309FA4.s")

void func_80309FF0(void){
    assetcache_release(D_80382368);

    if(D_8038236C)
        assetcache_release(D_8038236C);
    
    if(D_80382360)
        func_8033F5D8(D_80382360);

    if(D_80382364)
        func_8033F5D8(D_80382364);

    func_8034A2A8(D_80382374);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A2D0.s")

typedef struct{
    BKModelBin *unk0;
    s32 unk4;
    f32 unk8;
}struct_7AF80_0;

typedef struct{
    BKSprite *unk0;
    BKSpriteDisplayData *unk4;
    s32 unk8;
    f32 unkC;
}struct_7AF80_1;

s32 D_8036B800;
struct_7AF80_0 *D_80382390; //prop models ???
struct_7AF80_1 *D_80382394; //prop_sprites ???

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A350.s")

void *func_8030A428(s32 arg0){
    if(D_80382390[arg0].unk0 == NULL){
        D_80382390[arg0].unk0 = assetcache_get(0x2d1 + arg0);
    }
    D_80382390[arg0].unk4 = func_8023DB5C();
    return D_80382390[arg0].unk0;
}

BKModelBin *func_8030A4B4(s32 arg0){
    return D_80382390[arg0].unk0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A4D4.s")
#else
BKSpriteDisplayData *func_8030A4D4(s32 arg0){
    struct_7AF80_1 *ptr;
    if((ptr = D_80382394[arg0].unk0) == NULL){
        D_80382394[arg0].unk0 = func_8033B6C4(arg0 + 0x572, &ptr->unk4);
    }
    D_80382394[arg0].unk8 = func_8023DB5C();
    return D_80382394[arg0].unk4;
}
#endif

BKSprite *func_8030A55C(s32 arg0){
    func_8030A4D4(arg0);
    return D_80382394[arg0].unk0;
}

f32 func_8030A590(Prop *arg0){
    if(arg0->unk8_1){
        PropProp* propProp = &arg0->propProp;
        return D_80382390[propProp->unk0_31].unk8;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        return D_80382394[spriteProp->unk0_31].unkC;
    }
}

void func_8030A5EC(Prop *arg0, f32 arg1){
    if(arg0->unk8_1){
        PropProp* propProp = &arg0->propProp;
        D_80382390[propProp->unk0_31].unk8 = (f32)propProp->unkA*arg1/100.0f;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        D_80382394[spriteProp->unk0_31].unkC = (f32)spriteProp->unk0_9*arg1/100.0f;
    }
}

void func_8030A6B0(void){//clear
    struct_7AF80_0* iPtr;
    struct_7AF80_1* jPtr;

    for(iPtr = D_80382390; iPtr < &D_80382390[0x2A2]; iPtr++){
        if(iPtr->unk0){
            assetcache_release(iPtr->unk0);
        }
    }
    for(jPtr = D_80382394; jPtr < &D_80382394[0x168]; jPtr++){
        if(jPtr->unk0){
            func_8033B338(&jPtr->unk0, &jPtr->unk4);
        }
    }
    free(D_80382390);
    D_80382390 = NULL;
    free(D_80382394);
    D_80382394 = NULL;
}


void func_8030A78C(void){//init
    struct_7AF80_0* iPtr;
    struct_7AF80_1* jPtr;

    D_80382390 = (struct_7AF80_0 *)malloc(0x2A2 * sizeof(struct_7AF80_0));
    D_80382394 = (struct_7AF80_1 *)malloc(0x168 * sizeof(struct_7AF80_1));
    D_8036B800 = 0;
    for(iPtr = D_80382390; iPtr < &D_80382390[0x2A2]; iPtr++){
        iPtr->unk0 = NULL;
        iPtr->unk8 = 0.0f;
    }
    for(jPtr = D_80382394; jPtr < &D_80382394[0x168]; jPtr++){
        jPtr->unk0 = NULL;
        jPtr->unkC = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030A850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030AA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7AF80/func_8030ABA4.s")
