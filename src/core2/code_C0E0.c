#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} struct_C0E0;

typedef struct{
    s16 unk0;
    u8  unk2;
    u8  unk3;
} struct_C0E0_1;

typedef struct{
    u8 pad0[0xC];
    struct_C0E0_1 unkC[];
} struct_C0E0_2;

void func_80293350(void);

/* .data */
struct_C0E0_2 D_803637F0 ={
    { 0x03, 0xE8, 0x00, 0x00, 
      0x05, 0xDC, 0x00, 0x00, 
      0x07, 0xD0, 0x00, 0x00
    }, 
    {
        {7000, 8, 2},  
        {6000, 7, 1}, 
        {5000, 6, 1}, 
        {4000, 5, 1}, 
        {3000, 4, 1},  
        {2000, 3, 1}, 
        {1000, 2, 1}, 
        {0, 1, 1}, 
        {-1, 0, 0}
    }, 
};

/* .bss */
f32 D_8037C1B0[3];
u8  D_8037C1BC;
struct_C0E0 D_8037C1C0;

/* .code */
s32 func_80293070(struct_C0E0 *arg0, s32 arg1, struct_C0E0_2 *arg2){
    struct_C0E0_1 *iPtr;
    for(iPtr = arg2->unkC; iPtr->unk0 >= 0; iPtr++){
        if(iPtr->unk0 + 1000 < arg1){
            arg0->unk0 = iPtr->unk2;
            return iPtr->unk3;
        }
    }
    return 0;
}

s32 func_802930C0(struct_C0E0 *arg0, s32 arg1){
    arg0->unk0 = 0;
    if(arg1 < 0)
        return 0;
    else{
        switch(func_8029A8F4()){
            case TRANSFORM_2_TERMITE: //L80293110 
                return func_80293070(arg0, arg1, &D_803637F0);
            case TRANSFORM_3_PUMPKIN: //L80293124
                return func_80293070(arg0, arg1, &D_803637F0);
            case TRANSFORM_5_CROC: //L80293138  
                return func_80293070(arg0, arg1, &D_803637F0);
            case TRANSFORM_4_WALRUS: //L8029314C
                return func_80293070(arg0, arg1, &D_803637F0);
            case TRANSFORM_6_BEE: //L80293160
                return func_80293070(arg0, arg1, &D_803637F0);
            default:
                return func_80293070(arg0, arg1, &D_803637F0);
                break;
        }
    }
}

void func_80293190(void){
    f32 sp1C[3];
    s32 temp_a1;

    player_getPosition(sp1C);
    temp_a1 = D_8037C1B0[1] - sp1C[1];
    D_8037C1C0.unk4 = func_802930C0(&D_8037C1C0, temp_a1);
}

s32 func_802931DC(s32 *arg0){
    *arg0 = D_8037C1C0.unk0;
    return D_8037C1C0.unk4;
}

f32 func_802931F4(void){
    f32 sp1C[3];
    s32 temp_v0;

    player_getPosition(sp1C);
    temp_v0 = D_8037C1B0[1] - sp1C[1];
    return temp_v0;
}

s32 func_80293234(void){
    return D_8037C1BC;
}

void func_80293240(s32 arg0){
    D_8037C1BC = arg0;
    if(D_8037C1BC == 2 || D_8037C1BC == 3)
        func_80293350();
}

void func_80293284(f32 arg0[3]){
    ml_vec3f_copy(D_8037C1B0, arg0);
}

void func_802932AC(void){
    _player_getPosition(D_8037C1B0);
    D_8037C1BC = 0;
    func_80293240(1);
    D_8037C1C0.unk0 = 0;
    D_8037C1C0.unk4 = 0;
}

void func_802932EC(void){
    s32 sp1C;
    sp1C = func_8028ECAC();
    if(func_8028B2E8() || func_8028EE84() || sp1C == 0xA){
        func_80293350();
        func_80293240(1);
    }
    func_80293190();
}

void func_80293350(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    func_80293284(sp1C);
}