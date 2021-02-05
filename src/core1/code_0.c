#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u32 D_80275618;
extern u32 D_8027A130;
extern u64 D_8027BEF0;
extern u64 D_8027A538;
extern u8 D_80286F90;


void func_8023DA20(s32 arg0){
    func_80263B40(&D_8027A130, &D_80286F90 - (u8*)&D_8027A130);
    func_80263BE0();
    func_8025B1E0();
    func_80263C10();
    func_80240BE0();
}

void func_8023DA74(void){
    func_8033BD6C();
    func_80255198();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023DA9C.s")

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
//     func_8030BEDC();
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

void func_8023DF9C(s32 arg0){
    func_8023DC0C();
    func_8025B700();
    while(1){
        func_8023DD0C();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023DFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E06C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E0C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023E148.s")
