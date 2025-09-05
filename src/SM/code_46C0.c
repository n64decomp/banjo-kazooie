#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define US_1_0 0
#define PAL 1


#if VERSION == US_1_0
int func_8038AAB0(void){return 0;}

#elif VERSION == PAL
// u8 D_8038BFC2;
// void func_8038AAB0(s32 arg0, s32 arg1){
//     if(arg1 < 0){
//         func_8031A844();
//     }
//     else{
//         D_8038BFC2 = arg1;
//         func_8038B4D0(3);
//     }
// }

// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038A8F0.s")
// void func_8038A8F0(s32 arg0) {
//     u8 temp_v0;

//     switch (arg0) {                                 /* irregular */
//     case 1:
//         D_8038BFC1 = 1;
//         func_80319400();
//         break;
//     case 2:
//         D_8038BFC8->unk0 = (s32) D_8038BD38;
//         D_8038BFC8->unk4 = (s32) D_8038BD3C;
//         D_8038BFC8->unk10 = (s32) D_8038BD40;
//         D_8038BFC8->unk20 = (s32) D_8038BD44;
//         D_8038BFC8->unk30 = (s32) D_8038BD48;
//         func_8031A5E4(&D_8038BD30, &D_8038BD34, (void *)0x8038BFC8, 0xA, &D_8038B490);
//         break;
//     case 3:
//         temp_v0 = *(u8 *)0x8038BFC2;
//         if (temp_v0 != 0) {
//             func_8031B9A4(temp_v0 - 1, 0x80390000);
//         }
//         func_802FAF44(0);
//         D_8038BFC1 = 0;
//         break;
//     }
//     D_8038BFC0 = (s8) arg0;
// }


// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038A9E4.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038AA30.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038AA64.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038AA74.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/SM/code_46C0/func_8038AAE8.s")
#endif
