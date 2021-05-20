#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"
#include "save.h"



extern u32 D_80283390[]; //SnS_Packet

extern SaveSettings D_80283400;

extern s32 D_80283420; //min_value
extern s32 D_80283424; //max_value
extern s32 D_80283428; //position


void func_8025AFF0(s32 arg0, s32 arg1){
    D_80283420 = arg0;
    D_80283424 = arg1;
    D_80283428 = 0;
}

u32 func_8025B00C(void){
    while(D_80283428 < 0x1C){
        if(D_80283420 <= D_80283390[D_80283428] && D_80283390[D_80283428] <= D_80283424){
            return D_80283390[D_80283428++];
        }
        D_80283428++;
    }
    return 0;
}

void func_8025B08C(void){
    s32 i;
    for(i = 5; i != 0 && func_8033CD0C(&D_80283400); i--);
}

void func_8025B0E4(void){
    s32 i;
    u32 tmp;

    if(func_8033CA9C(&D_80283400)){
        D_80283400.unk0[0] &= ~(1 << 7);
        D_80283400.unk0[0] &= (u8)~(1 << 6);
        D_80283400.unk0[0] &= (u8)~(1 << 5);
        D_80283400.unk0[0] &= (u8)~(1 << 4);
        D_80283400.unk0[0] &= (u8)~(1 << 3);
        D_80283400.unk0[0] &= (u8)~(1 << 2);
        D_80283400.unk0[0] &= (u8)~(1 << 1);
        D_80283400.unk0[0] &= (u8)~(1 << 0);

        D_80283400.unk0[1] &= ~(1 << 7);
        D_80283400.unk0[1] &= (u8)~(1 << 6);
        D_80283400.unk0[1] &= (u8)~(1 << 5);
        D_80283400.unk0[1] &= (u8)~(1 << 4);
        D_80283400.unk0[1] &= (u8)~(1 << 3);
        D_80283400.unk0[1] &= (u8)~(1 << 2);
        tmp = ((u32*) &D_80283400.unk0)[0];
        ((u32*) &D_80283400.unk0)[0] =  ((tmp << 0xE) >> 0xE) ^ tmp;

        for(i =0; i< 0x18; i++){
            D_80283400.unk4[i] = 0;
        }
        func_8025B08C();
    }
    func_8025B69C();
    func_8025B08C();
}

void func_8025B1E0(void){
    SnSPayload *payload;
    s32 i;
    u32 val;
    u32 *ptr;
    for(i = 0 ; i < 0x1C; i++){
        D_80283390[i] = 0;
    };
    if(payload = SnSPayload_scan()){
        SnSPayload_rewind();
        i = 0;
        do{
            D_80283390[i] = SnSPayload_getWord(payload);
            i = ( D_80283390[i])? i + 1: 0x1C;
        }while(i< 0x1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B2EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B4FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B6C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B700.s")

void func_8025B808(void){}

s32 func_8025B810(void){ return 0; }


s32 func_8025B818(void){ return 1; }


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025B998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025BBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025BC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_1D5D0/func_8025BCEC.s")
