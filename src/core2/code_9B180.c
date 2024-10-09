#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[2];
    s16 unk2;
}Struct_core2_9B180_1;

typedef struct struct_core2_9B180_s{
    s16 unk0;
    // u8 pad2[0x2];
    Struct_core2_9B180_1 *unk4;
    void (*unk8)(struct struct_core2_9B180_s *);
    void (*unkC)(struct struct_core2_9B180_s *);
    void (*unk10)(struct struct_core2_9B180_s *);
}Struct_core2_9B180_0;

extern void func_8024FE44(u8, f32, f32);
extern void func_8030EDAC(f32, f32);

void func_80322298(Struct_core2_9B180_0 *);
void func_803222F4(Struct_core2_9B180_0 *);
void func_80322110(Struct_core2_9B180_0 *);
void func_8032222C(Struct_core2_9B180_0 *);
void func_803221C4(Struct_core2_9B180_0 *);
void func_803221F4(Struct_core2_9B180_0 *);
void func_803222BC(Struct_core2_9B180_0 *);
void func_80322318(Struct_core2_9B180_0 *);
void func_80322130(Struct_core2_9B180_0 *);

/* .data */
Struct_core2_9B180_0 D_8036DE00[6] = {
    {0x18A, NULL, func_80322298, func_803222BC, NULL}, 
    {0x018, NULL, func_803222F4, func_80322318, NULL}, 
    {0x18B, NULL, func_80322110, func_80322130, NULL}, 
    {0x194, NULL, func_8032222C,          NULL, NULL}, 
    {0x193, NULL, func_803221C4,          NULL, NULL}, 
    {0x192, NULL, func_803221F4,          NULL, NULL}
};

u8 D_8036DE78 = 1;

/* .bss */
u8 D_80383330;
f32 D_80383334;

/* .code */
void func_80322110(Struct_core2_9B180_0 *arg0) {
    D_80383334 = (f32) arg0->unk4->unk2;
}

void func_80322130(Struct_core2_9B180_0 *arg0) {
    f32 sp1C[3];

    player_getPosition(sp1C);
    if (sp1C[1] < D_80383334) {
        if (func_8028F66C(BS_INTR_2C) == 2) {
            arg0->unk4 = 0;
            FUNC_8030E624(SFX_96_HOTSAND_EEL_HISS, 1.0f, 32000);
            FUNC_8030E624(SFX_A_BANJO_LANDING_05, 1.0f, 32000);
            return;
        }
        sp1C[1] = D_80383334;
        func_8028FAB0(sp1C);
        ncDynamicCamera_setState(6);
    }
}


void func_803221C4(Struct_core2_9B180_0 * arg0){
    func_8024FE44(0, 0.2f, 1.25f);
}

void func_803221F4(Struct_core2_9B180_0 * arg0){
    func_8030EDAC(0.50999999f, 1.0f);
    func_80244A98(0);
}

void func_8032222C(Struct_core2_9B180_0 * arg0) {
    s32 phi_s0;

    for(phi_s0 = 1; phi_s0 < 5; phi_s0++){
        func_8024FE44(phi_s0, 0.2f, 1.25f);
    }
}

void func_80322298(Struct_core2_9B180_0 *arg0){
    if(D_8036DE78){
        D_8036DE78 = 0;
        arg0 ->unk4 = 0;
    }
}

void func_803222BC(Struct_core2_9B180_0 * ag0){
    if(func_8024E698(0) == 1){
        func_8031D06C(0,0);
    }
}

void func_803222F4(Struct_core2_9B180_0 *arg0){
    if(D_8036DE78){
        D_8036DE78 = 0;
        arg0 ->unk4 = 0;
    }
}

void func_80322318(Struct_core2_9B180_0 * arg0){
    func_8031D0C0(0, 0);
}

bool func_80322340(s32 arg0) {
    f32 sp1C[3];

    if (nodeProp_findPositionFromActorId(arg0, &sp1C)) {
        return 1;
    }
    return 0;
}

void func_8032236C(s32 arg0, s32 arg1, s32 *arg2) {
    if (func_80322340(arg0) && (*arg2 == 0)) {
        *arg2 = arg1;
    }
}

void func_803223AC(void) {
    Struct_core2_9B180_0 *i_ptr;
    s32 sp28;

    func_80244A98(1);
    for(i_ptr = D_8036DE00; i_ptr != &D_8036DE00[6]; i_ptr++){
        i_ptr->unk4 = cubeList_findNodePropByActorId(i_ptr->unk0, 0);
        if(i_ptr->unk4 != 0 && i_ptr->unk8 != NULL){
            i_ptr->unk8(i_ptr);
        }
    }

    sp28 = 0;
    func_8032236C(0x19, 1, &sp28);
    func_8032236C(0x1A, 2, &sp28);
    func_8032236C(0x1B, 3, &sp28);
    func_8032236C(0x1C, 4, &sp28);
    func_8032236C(0x1D, 5, &sp28);
    sp28 = (sp28 == 0) ?  2 : sp28;
    viMgr_func_8024BF94(sp28);
}

void func_80322490(void) {
    Struct_core2_9B180_0 *i_ptr;

    if (D_80383330 != 0) {
        for(i_ptr = D_8036DE00; i_ptr != &D_8036DE00[6]; i_ptr++){
            if(i_ptr->unk4 != 0 && i_ptr->unkC != NULL){
                i_ptr->unkC(i_ptr);
            }
        }
    }
}


void func_803224FC(void) {
    s32 i;
    Struct_core2_9B180_0 *i_ptr;

    for(i_ptr = D_8036DE00; i_ptr != &D_8036DE00[6]; i_ptr++){
        if(i_ptr->unk4 != 0 && i_ptr->unk10 != NULL){
            i_ptr->unk10(i_ptr);
        }
    }
    func_8030EDAC(0.0f, 1.0f);
    func_80244A98(1);
    for(i = 0; i < 5; i++){
        func_8024FE44(i, 0.0f, 1.0f);
    }
}

void func_803225B0(s32 arg0, s32 arg1) {
    D_80383330 = BOOL(arg1 == 2);
}
