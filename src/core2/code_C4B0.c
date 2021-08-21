#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_80258424(f32 vec[3], f32 minX, f32 minY, f32 minZ, f32 maxX, f32 maxY, f32 maxZ);
extern void func_8031C5FC(struct0 *, f32);

extern f32 D_8037C1F0[2];
extern f32 D_8037C1F8[2];

extern struct0 * D_8037C200;
extern s32 D_8037C204;
extern f32 D_8037C218[3];
extern f32 D_8037C228[3];
extern f32 D_8037C258[3];
extern f32 D_8037C268[3];
extern s32 D_8037C274;
extern u8 D_8037C278;
extern u8 D_8037C279;
extern u8 D_8037C27B;
extern u8 D_8037C27C;
extern u8 D_8037C27E;
extern u8 D_8037C27F;
extern u8 D_8037C280;

void func_80293440(void){
     f32 sp34[3];
     f32 bottomY = climbGetBottomY();
     f32 topY = climbGetTopY();
     f32 sp28;
     f32 diff;

     if(topY < D_8037C218[1]){
          D_8037C218[1] = topY;
     }
     if(D_8037C218[1] < bottomY)
          D_8037C218[1] = bottomY;

     climbGetBottom(&sp34);
     func_80257F18(&D_8037C218, &sp34, &sp28);
     diff = mlDiffDegF(sp28, yaw_get());
     diff = mlAbsF(diff);
     if(1.0f < diff){
          yaw_setIdeal(sp28);
          func_802991FC();
     }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029350C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80293668.s")

void func_80293D2C(f32 *arg0, f32 * arg1){
     *arg0 = D_8037C1F8[0];
     *arg1 = D_8037C1F8[1];
}

void func_80293D48(f32 arg0, f32 arg1){
     D_8037C1F0[0] = arg0;
     D_8037C1F0[1] = arg1;
     D_8037C1F8[0] = D_8037C1F0[0];
     D_8037C1F8[1] = D_8037C1F0[1];
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80293D74.s")
#else
void func_80293D74(void){
     func_80293D48(80.0f, 35.0f);
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80293DA4.s")
#else
void func_80293DA4(void){
     D_8037C278 = 0;
     D_8037C279 = 0;
     D_8037C27B = 0;
     D_8037C27C = 0;
     D_8037C27E = 0;
     D_8037C280 = 0;
     D_8037C200 = func_8031B9D8();
     ml_vec3f_clear(&D_8037C268);
     ml_vec3f_clear(&D_8037C218);
     ml_vec3f_clear(&D_8037C228);
     ml_vec3f_clear(&D_8037C258);
     D_8037C204 = 0;
     D_8037C27F = 0;
     func_80293D74();
     
     D_8037C1F8[0] = D_8037C1F0[0];
     D_8037C1F8[1] = D_8037C1F0[1];
     func_80294384(1);
     D_8037C274 = 0;
     func_80294378(1);
}
#endif

void func_80293E88(void){
     func_8031BA9C(D_8037C200);
}

//__clamp to_range_within_point
f32 func_80293EAC(f32 arg0, f32 arg1, f32 arg2){
     if(arg1 < arg0){
          arg1 = min_f(arg0, arg1+arg2);
     }
     else if(arg0 < arg1){
          arg1 = max_f(arg0, arg1-arg2);
     }
     return arg1;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80293F0C.s")
#else
void func_80293F0C(void){
     f32 sp44[3];
     f32 sp38[3];
     f32 sp2C[3];
     
     _player_getPosition(&sp44);
     if(func_803348C0() == 0x34 && func_80258424(&sp44, -900.0f, -940.0f, 200.0f, 900.0f, 940.0f, 800.0f)){
          func_8031C5FC(D_8037C200, 150.0f);
     } else{
          func_8031C608(D_8037C200);
     }

     D_8037C1F8 = func_80293EAC(D_8037C1F0, D_8037C1F8, 1.0f);
     D_8037C1FC = func_80293EAC(D_8037C1F4, D_8037C1FC, 1.0f);

     ml_vec3f_diff_copy(&D_8037C268, &sp38, &sp2C);
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029436C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029445C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802944A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802944D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802944F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029453C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294598.s")

u32 func_80294610(u32 mask){
     return func_8031C59C(D_8037C200) & mask;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029463C.s")

u32 func_80294660(void){
     return func_8031C59C(D_8037C200);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802946A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802946CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802946F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_802946FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_8029472C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C4B0/func_80294750.s")
