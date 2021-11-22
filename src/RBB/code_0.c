#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324E88(f32);

/* typedefs and declarations */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
}ActorLocal_RBB_0;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    //u8 pad3[1];
    f32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    //u8 padE[2];
}Struct_RBB_0_1;


void func_803866F4(Actor *this, s32 arg1);
void func_803868F0(Actor* this);

/* .data */
ActorInfo D_80390050 = {
    0x182, 0x172, 0x402, 0x0, NULL,
    func_803868F0, NULL, func_80325340,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};
extern Struct_RBB_0_1 D_80390074[4] = {
    {0x0, 0x2, 0x4, 3.0f,   550, 200, -300},
    {0x1, 0x4, 0x0, 4.0f,  -600,   0,    0},
    {0x2, 0x6, 0x0, 4.0f,  -700,   0,    0},
    {0x3, 0x8, 0x0, 4.0f, -1010,   0,    0}
};

/* .code */
void func_803863F0(Actor *actor, s32 arg1){
    ActorLocal_RBB_0 * local = (ActorLocal_RBB_0 *) &actor->local;
    void *temp_a0;
    f32 sp3C[3];
    f32 sp30[3];

    temp_a0 = func_8034C528(local->unk4 + 0x190);
    if(temp_a0){
        if(local->unk8 == 0){
            sp3C[2] = 0.0f;
            sp30[0] = 0.0f;
            sp30[1] = 0.0f;
            sp3C[0] = sp3C[1] = sp3C[2];
            sp30[2] = (f32) D_80390074[local->unk4].unk8;
        }
        else if(local->unk8 == 1){
            sp3C[0] = 0.0f;
            sp3C[1] = 0.0f;
            sp3C[2] = (f32) D_80390074[local->unk4].unk8;
            sp30[1] = 0.0f;
            sp30[0] = 0.0f;
            sp30[2] = (f32) D_80390074[local->unk4].unkA;
        }
        else{
            sp3C[0] = 0.0f;
            sp3C[1] = 0.0f;
            sp3C[2] = (f32) D_80390074[local->unk4].unkA;
            sp30[1] = 0.0f;
            sp30[0] = 0.0f;
            sp30[2] = (f32) D_80390074[local->unk4].unkC;

        }
        if(arg1){
            func_8034DDF0(temp_a0, &sp3C, &sp30, D_80390074[local->unk4].unk4, 1);
            func_8034E174(temp_a0);
        }
        else{
            func_8034DDF0(temp_a0, &sp3C, &sp30, 0.0f, 1);
        }
    }
}

void func_803865A4(ActorMarker *marker, s32 arg1){
    func_803866F4(marker_getActor(marker), arg1);
}

void func_803865D0(ActorMarker *marker){
    Actor* actor = marker_getActor(marker);
    ActorLocal_RBB_0 * local = (ActorLocal_RBB_0 *) &actor->local;
    func_803863F0(actor, 1);
    func_80324E60(0.0f, D_80390074[local->unk4].unk0);
    timedFunc_set_2(0.75*D_80390074[local->unk4].unk4, (TFQM2) func_803865A4, actor->marker, 4);
    func_80324E88(0.75*D_80390074[local->unk4].unk4);
    func_80324E38(0.75*D_80390074[local->unk4].unk4, 0);
    func_80324C88(D_80390074[local->unk4].unk4, 0x7f, 0.8f, 0x7fd0);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/RBB/code_0/func_803866F4.s")
#else
void func_803866F4(Actor *this, s32 arg1){
    ActorLocal_RBB_0 *local = (ActorLocal_RBB_0 *) &this->local;
    
    while(1){
        if(arg1 == 2){
            func_8025A6EC(COMUSIC_2B_DING_B, 28000);
            local = (ActorLocal_RBB_0 *) &this->local;
            local->unkC = 3;
        }
        if(arg1 == 3){
            local->unk8++;
            func_8025A6EC(COMUSIC_2B_DING_B, 28000);
            func_80324E38(0.0f, 3);
            timedFunc_set_2(0.5f, (TFQM2) func_8025A6EC, COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            timedFunc_set_1(1.0f,  (TFQM1) func_803865D0, this->marker);
        }//L803867D4
        if(arg1 == 4){
            if(local->unk8 == 1 && D_80390074[local->unk4].unk2 > 0){
                arg1 = 1;
                continue;
            }
        }
        break;
    }
    this->state = arg1;
}
#endif

void func_8038685C(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_0 *local = (ActorLocal_RBB_0 *) &actor->local;

    if(actor->state == 1){
        local->unk0++;
        if( D_80390074[local->unk4].unk1 == local->unk0 
            || D_80390074[local->unk4].unk1 + D_80390074[local->unk4].unk2 == local->unk0
        ){
            func_803866F4(actor, 3);
        }else{
            func_803866F4(actor, 2);
        }
    }
}

void func_803868F0(Actor *this){
    ActorLocal_RBB_0 *local = (ActorLocal_RBB_0 *) &this->local;

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        if(this->state == 0){
            local->unk0 = 0;
            local->unk4 = 0;
            local->unk8 = 0;
            local->unkC = 0;
            local->unk4 = (this->unk78_13 == 0x15)? 0: local->unk4;
            local->unk4 = (this->unk78_13 == 0x13)? 1: local->unk4;
            local->unk4 = (this->unk78_13 == 0x14)? 2: local->unk4;
            local->unk4 = (this->unk78_13 == 0xB)?  3: local->unk4;
            func_803866F4(this, 1);
        }
        func_803863F0(this, 0);
    }//L803869F4
    if(this->state == 2){
        if(--local->unkC <= 0){
            func_803866F4(this, 1);
        }

    }
}