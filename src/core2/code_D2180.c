#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802F82F4(s32, f32, f32, f32, f32);

typedef struct {
    s16 unk0;
    //u8 pad[0x2];
    int (*unk4)(Actor *); 
} Struct_Core2_D2180_0;

typedef struct {
    Struct_Core2_D2180_0 *unk0;
} ActorLocal_core2_D2180;

int func_80359110(Actor *);
int func_8035911C(Actor *);
int func_80359110(Actor *);
int func_80359160(Actor *);
int func_80359110(Actor *);
int func_803591A4(Actor *);
void func_8035933C(Actor *this);
void func_80359424(Actor *this);
void func_80359454(Actor *this);

/* .data */
Struct_Core2_D2180_0 D_80372940[] ={
    {2, func_80359110},
    {2, func_8035911C},
    {3, func_80359110},
    {3, func_80359160},
    {4, func_80359110},
    {4, func_803591A4}
};

ActorInfo D_80372970 = { 0x1C1, 0x2AE, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_80372994 = { 0x1C1, 0x2AF, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_803729B8 = { 0x1C1, 0x2B0, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_803729DC = { 0x1C1, 0x2B1, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_80372A00 = { 0x1C1, 0x2B2, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_80372A24 = { 0x1C1, 0x2B3, 0x0, 0, NULL, func_8035933C, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_80372A48 = { 0x1C1, 0x316, 0x0, 0, NULL, func_80359424, NULL, func_80325340,  0, 0, 0.0f, 0};
ActorInfo D_80372A6C = { 0x1C1, 0x317, 0x0, 0, NULL, func_80359454, NULL, func_80325340,  0, 0, 0.0f, 0};

/* .code */
int func_80359110(Actor *this){
    return TRUE;
}

int func_8035911C(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (plyr_pos[2] < -1700.0f);
}

int func_80359160(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (1700.0f < plyr_pos[2]);
}

int func_803591A4(Actor *this){
    f32 plyr_pos[3];
    
    player_getPosition(plyr_pos);
    return (1700.0f < plyr_pos[0]);
}

void func_803591E8(Actor *this, s32 next_state){
    ActorLocal_core2_D2180 * local = (ActorLocal_core2_D2180 *) &this->local;
    s32 sp20;

    if(next_state == 2)
        func_802F8C90(func_802F7C38());
    
    if(this->state == 2)
        func_802F8CB0(func_802F7C38());

    if(next_state == 3){
        sp20 = func_802F7C7C();
        func_802F8338(sp20);
        if(local->unk0->unk4 == func_80359110)
            func_802F82F4(sp20, 5.0f, 30.0f, 5.0f, 30.0f);
    }

    if(this->state == 3)
        func_802F8358(func_802F7C7C());

    if(next_state == 4){
        func_802F7CC0();
        func_802F90F4();
    }
    if(this->state == 4){
        func_802F7CC0();
        func_802F9114();
    }


    this->state = next_state;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D2180/func_8035933C.s")
#else
void func_8035933C(Actor *this){
    ActorLocal_core2_D2180 * local = (ActorLocal_core2_D2180 *) &this->local;
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        local->unk0 = &D_80372940[(this->modelCacheIndex - 0x2AE)];
        func_803591E8(this, 1);
    }
    if(this->state == 1){
        if(local->unk0->unk4(this)){
            func_803591E8(this, local->unk0->unk0);
        }
    }
    if(this->state != 1){
        if(!local->unk0->unk4(this)){
            func_803591E8(this, 1);
        }
    }
}
#endif

void func_80359424(Actor *this){
    if(func_803292E0(this))
        func_802F7D44();
}

void func_80359454(Actor *this){
    if(func_803292E0(this))
        func_802F7DE4();
}
