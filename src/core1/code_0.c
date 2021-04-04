#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"

extern s32 D_80275610;
extern u32 D_80275618;
extern u32 D_8027A130;
extern OSThread D_8027BD38;
extern s32 D_8027BEE8;
extern s32 D_8027BEEC;
extern u64 D_8027BEF0;
extern u64 D_8027A538;
extern u8 D_80286F90;

void func_8023DA20(s32 arg0){
    bzero(&D_8027A130, &D_80286F90 - (u8*)&D_8027A130); //bzero
    osWriteBackDCacheAll(); //osWriteBackDCacheAll
    func_8025B1E0();
    osInitialize();
    func_80240BE0();
}

void func_8023DA74(void){
    func_8033BD6C();
    func_80255198();
}

void func_8023DA9C(s32 arg0){
    func_80254008();
    func_8024C428();
    if (D_8027A130 == 4){
        func_802E3580();
    }
    if (D_8027A130 == 3){
        func_802E4170();
    }
    func_8023DA74();
    D_8027A130 = arg0;
    if (D_8027A130 == 3){
        func_802E4214(D_8027BEE8);
    }
    if (D_8027A130 == 4){
        func_802E35D0();
    }
    func_80255CD8();
}

u32 func_8023DB4C(u32 arg0){
    return D_80275618 & arg0;
}

u32 func_8023DB5C(void){
    return D_80275618;
}

void func_8023DB68(void){
    D_80275618 = 0;
}

s32 func_8023DB74(void){
    return (func_8025B810())? 0x80 : 0x91;
}

s32 func_8023DBA4(void){
    return 0x1F;
}

void func_8023E00C(s32);
void func_8023DFF0(s32);

void func_8023DBAC(void){
    func_8023E00C(func_8023DBA4());
    func_8023DFF0(3);
}

void func_8023DBDC(void){
    func_8023E00C(func_8023DB74());
    func_8023DFF0(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023DC0C.s")
// void func_8023DC0C(void){
//     func_80255C30();
//     func_8023E00C(func_8023DBA4());
//     func_8023E08C();
//     func_8024BE30();
//     func_80251308();
//     D_8027BEF0 = D_8027A538;
//     func_80254710();
//     func_80254028();
//     func_8025AFB0();
//     func_8033EF58();
//     func_8033BB84();
//     func_8024F05C();
//     func_80250C84();
//     func_8023FB1C();
//     func_8025425C();
//     func_80257424();
//     gctransition_reset();
//     D_8027A130 = 0;
//     D_80275618 = 0;
//     func_8023DA9C(3);
// }

void func_8023DCDC(void){
    D_80275618++;
}

void func_8023DCF4(void){
    D_80275618--;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023DD0C.s")

void func_8023DF9C(void *arg0){ 
    func_8023DC0C();
    func_8025B700();
    while(1){ //main loop
        func_8023DD0C();
    }
}

void func_8023DFF0(s32 arg0){
    D_80275610 = arg0 + 1;
}

s32 func_8023E000(void){
    return D_8027A130;
}

void func_8023E00C(s32 arg0){
    D_8027BEE8 = arg0;
}

void func_8023E018(void){
    // 5th argument should be a pointer to the end of an array, but the start is unknown
    // D_8027A538 is not the right symbol, but the end of the array is the important port and this is the closest symbol currently
    osCreateThread(&D_8027BD38, 6, func_8023DF9C, NULL, ((u8*)&D_8027A538) + 0x1800, 0x14);
}

OSThread *func_8023E060(void){
    return &D_8027BD38;
}

void func_8023E06C(void){
    D_8027BEEC = 1;
}