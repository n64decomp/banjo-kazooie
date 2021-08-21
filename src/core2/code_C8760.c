#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8030DE44(u8, s32, f32);

struct {
    struct30s *unk0;
    u8 unk4;
    u8 unk5;
    u8 pad6[2];
}D_803720A0;

extern f32 D_803792F0;

void func_8034F6F0(Gfx **gdl, Mtx **mptr, s32 vptr){
    if(D_803720A0.unk0){
        func_802EF3A8(D_803720A0.unk0, gdl, mptr, vptr);
    }
}

void func_8034F734(void){
    if(D_803720A0.unk0){
        func_8030DA44(D_803720A0.unk5);
        func_802EF684(D_803720A0.unk0);
    }
}

void func_8034F774(void){
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    int s0;
    int s1;

    s0 = func_80304E24(0x2F, &sp38);
    s1 = func_80304E24(0x30, &sp2C);
    if( !s0 || !s1){
        D_803720A0.unk0 = NULL;
    }else{
        D_803720A0.unk0 = func_802EF6AC(0xA);
        func_802EF950(D_803720A0.unk0, 0x70E);
        func_802EFA90(D_803720A0.unk0, 0, 4);
        func_802EFA9C(D_803720A0.unk0, 15.0f, 30.0f);
        func_802EFE5C(D_803720A0.unk0, 0.0f, 1.0f);
        func_802EFEC0(D_803720A0.unk0, D_803792F0, D_803792F0);
        func_802EFB70(D_803720A0.unk0, 1.8f, 2.2f);
        func_802EF4AC(D_803720A0.unk0, &sp38, &sp2C, 0xA);
        func_802EFFC4(D_803720A0.unk0, 0.0f);
        D_803720A0.unk5 = func_8030D90C();

        sp44[0] = (sp38[0] + sp2C[0])/2;
        sp44[1] = (sp38[1] + sp2C[1])/2;
        sp44[2] = (sp38[2] + sp2C[2])/2;
        func_8030DA80(D_803720A0.unk5, 0x3EC);
        func_8030DD14(D_803720A0.unk5, 3);
        func_8030DFF0(D_803720A0.unk5, 1);
        func_8030DF68(D_803720A0.unk5, &sp44);
        func_8030DEB4(D_803720A0.unk5, 400.0f, 3200.0f);
        func_8030DE44(D_803720A0.unk5, 2, 0.5f);
        func_8030E2C4(D_803720A0.unk5);
    }
}

void func_8034F918(void){
    if(D_803720A0.unk0)
       func_802EFFE4(D_803720A0.unk0);
}