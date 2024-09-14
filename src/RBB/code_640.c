#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"
#include <core1/viewport.h>


extern ActorInfo D_80390D20;
extern ActorInfo D_80390050;
extern ActorInfo D_80390200;
extern ActorInfo D_80390270;
extern ActorInfo D_80390D50;
extern ActorInfo D_803906E0;
extern ActorInfo D_80390738;
extern ActorInfo D_803907D0;
extern ActorInfo D_803907F4;
extern ActorInfo D_80390818;
extern ActorInfo D_8039083C;
extern ActorInfo D_803904C0;
extern ActorInfo D_803904E4;
extern ActorInfo D_80390508;
extern ActorInfo D_803903B0;
extern ActorInfo D_803903D4;
extern ActorInfo D_803903F8;
extern ActorInfo D_80390640;
extern ActorInfo D_80390664;
extern ActorInfo D_80390688;
extern ActorInfo D_803906B0;
extern ActorInfo D_803908C0;
extern ActorInfo D_803908E4;
extern ActorInfo D_80390908;
extern ActorInfo D_803909B0;
extern ActorInfo D_803909D4;
extern ActorInfo RBB_D_803909F8;
extern ActorInfo D_80390A50;
extern ActorInfo D_80390380;
extern ActorInfo D_80390A80; //anchorswitch
extern ActorInfo RBB_D_80390AB0; //dolphin
extern ActorInfo RBB_D_80390AE0; //anchor
extern ActorInfo RBB_D_80390B10;
extern ActorInfo D_80390B40; //rarewareflag
extern ActorInfo RBB_D_80390BD0;
extern ActorInfo D_80390BF4;
extern ActorInfo D_80390C18;
extern ActorInfo RBB_D_80390C3C;
extern ActorInfo RBB_D_80390CF0;
extern ActorInfo D_80390D88;
extern ActorInfo D_80390DAC; //TNTpart_IDStruct;
extern ActorInfo RBB_D_80390E00;
extern ActorInfo D_80390E34;
extern ActorInfo D_80390E58;
extern ActorInfo D_803900E0;
extern ActorInfo D_80390104; //captcabinwooddoor
extern ActorInfo D_80390128;
extern ActorInfo D_8039014C;
extern ActorInfo D_803901B8;
extern ActorInfo D_803901DC;
extern ActorInfo D_80390170;//skylight
extern ActorInfo D_80390194;//honeycombswitch



extern void func_802D3D54(Actor *);

void func_80386A7C(Actor *);
void func_80386BF8(Actor *arg0);
Actor *func_80386B9C(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3);


/* .data */
ActorAnimationInfo D_803900C0[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {0xD4, 0.15f},
    {0xD5, 0.5f}
};

ActorInfo D_803900E0 = {
    0x107, 0x21D, 0x493, 0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_80390104 = {
    0x108, 0x21C, 0x492, 0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_80390128 = {
    0x22D, 0x266, 0x4BA, 0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_8039014C = {
    0x22E, 0x267, 0x4BB, 0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_80390170 = {
    0x235, 0x23F, 0x4E2, 0x1, NULL,
    func_802D3D54, func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo D_80390194 = {
    0x15F, 0x18F, 0x42F, 0x1, D_803900C0,
    func_80386BF8, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_803901B8 = {
    0x22F, 0x263, 0x4DB, 0x1, NULL,
    func_80386A7C, func_80326224, func_80386B9C,
    0, 0, 0.0f, 0
};

ActorInfo D_803901DC = {
    0x230, 0x264, 0x4DE, 0x1, NULL,
    func_80386A7C, func_80326224, func_80386B9C,
    0, 0, 0.0f, 0
};


/* .code */
s32 func_80386A30(f32 (*arg0)[3]){
    s32 r; 
    
    r = ((*arg0)[0] < 0.0f)? 0 : 1;

    return (((*arg0)[2] < 0.0f)? 0 : 2) + r;
}

void func_80386A7C(Actor *this){
    f32 viewport[3];
    s32 sp28;
    s32 temp_v0;

    func_802D3D74(this);
    this->depth_mode = 1;
    viewport_getPosition_vec3f(&viewport);
    sp28 = func_80386A30(&this->position);
    temp_v0 = func_80386A30(&viewport);
    this->unk38_0 = 0;
    if(viewport[0] + 8000.0f < this->position_x || this->position_x < viewport[0] - 8000.0f)
        return;
        
    if( !(  (sp28 ^ temp_v0) & 2
            && (-5000.0f < viewport[0] && viewport[0] < 6000.0f)
            && (viewport[2] < -600.0f || 600.0f < viewport[2])
        )
        && ( sp28 ^ temp_v0) != 3
    ){
            this->unk38_0 = 1;
    }
}

Actor *func_80386B9C(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);

    return (actor->unk38_0) ? actor_drawFullDepth(marker, gdl, mptr, arg3): NULL;
}

void func_80386BF8(Actor *arg0){
    if(!mapSpecificFlags_get(0) && honeycombscore_get(HONEYCOMB_F_RBB_BOAT_HOUSE))
        mapSpecificFlags_set(0, TRUE);
    func_802D4A9C(arg0, 0);
}

void RBB_func_80386C48(void){
    spawnableActorList_add(&D_80390D20, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80390050, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80390200, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390270, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390D50, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_27);
    spawnableActorList_add(&D_803906E0, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390738, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_803907D0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803907F4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80390818, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_8039083C, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803904C0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803904E4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80390508, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803903B0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803903D4, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_803903F8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_13 | ACTOR_FLAG_UNKNOWN_14);
    spawnableActorList_add(&D_80390640, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80390664, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_80390688, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_803906B0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_803908C0, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_803908E4, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390908, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_803909B0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_803909D4, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&RBB_D_803909F8, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80390A50, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390380, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80390A80, actor_new, ACTOR_FLAG_UNKNOWN_7); //anchorswitch
    spawnableActorList_add(&RBB_D_80390AB0, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11); //dolphin
    spawnableActorList_add(&RBB_D_80390AE0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11); //anchor
    spawnableActorList_add(&RBB_D_80390B10, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390B40, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11); //rarewareflag
    spawnableActorList_add(&RBB_D_80390BD0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80390BF4, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80390C18, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&RBB_D_80390C3C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&RBB_D_80390CF0, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390D88, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80390DAC, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&RBB_D_80390E00, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390E34, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80390E58, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_803900E0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80390104, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //captcabinwooddoor
    spawnableActorList_add(&D_80390128, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8039014C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_803901B8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803901DC, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_80390170, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //skylight
    spawnableActorList_add(&D_80390194, actor_new, ACTOR_FLAG_UNKNOWN_3); //honeycombswitch
}
