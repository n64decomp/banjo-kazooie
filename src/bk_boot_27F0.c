#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_F37F90;
extern u8 D_FA3FD0;
extern u8 D_FA5F50;
extern u8 D_FA9150;
extern u8 D_FAE860;
extern u8 D_FB24A0;
extern u8 D_FB44E0;
extern u8 D_FB9A30;
extern u8 D_FBEBE0;
extern u8 D_FC4810;
extern u8 D_FC6F20;
extern u8 D_FC9150;
extern u8 D_FD0420;
extern u8 D_FD6190;
extern u8 D_FDAA10;

extern u32 *D_803FFE10;
extern u32 *D_803FFE14;
extern u32 *D_803FFE18;
extern u32 *D_803FFE1C;

#pragma GLOBAL_ASM("asm/nonmatchings/bk_boot_27F0/func_80001BF0.s")
// void func_80001BF0(void){
//     D_803FFE10 = &D_F37F90;
//     D_803FFE14 = &D_FA3FD0;
//     D_803FFE18 = &D_FDAA10;
//     D_803FFE1C = &D_FDAA30;
// }