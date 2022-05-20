#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_80258424(f32 vec[3], f32 minX, f32 minY, f32 minZ, f32 maxX, f32 maxY, f32 maxZ);
extern f32 func_8031C5D4(struct0*);
extern f32 func_8031C5E4(struct0*);
extern void func_8031C5FC(struct0 *, f32);
extern f32 func_80255D70(f32 arg0);
extern s32 func_8029463C(void);


void func_80294378(s32 arg0);
void func_80294384(s32 arg0);
void func_80294390(void);

/* .bss */
extern f32 D_8037C1F0[2];
extern f32 D_8037C1F8[2];
extern struct0 * D_8037C200;
extern Struct60s * D_8037C204;
extern s32 D_8037C208;
extern f32 D_8037C218[3];
extern f32 D_8037C228[3];
extern f32 D_8037C238[3];
extern f32 D_8037C248[3];
extern f32 D_8037C258[3];
extern f32 D_8037C268[3];
extern s32 D_8037C274;
extern u8 D_8037C278;
extern u8 D_8037C279;
extern u8 D_8037C27A;
extern u8 D_8037C27B;
extern u8 D_8037C27C;
extern u8 D_8037C27D;
extern u8 D_8037C27E;
extern u8 D_8037C27F;
extern u8 D_8037C280;
extern s32 D_8037C284;

// Remove this when bss is migrated from this file
u8 code_C4B0_bss[0x8037C290 - 0x8037C1F0];

/* .code */
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
          yaw_applyIdeal();
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

void func_80293D74(void){ func_80293D48(80.0f, 35.0f);}

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
    
    _player_getPosition(sp44);
    if(map_get() == MAP_34_RBB_ENGINE_ROOM && func_80258424(sp44, -900.0f, -940.0f, 200.0f, 900.0f, 940.0f, 800.0f)){
        func_8031C5FC(D_8037C200, 150.0f);
    } else{
        func_8031C608(D_8037C200);
    }
    D_8037C27C = 0;
    D_8037C27A = 1;
    D_8037C27D = 0;
    D_8037C204 = NULL;
    D_8037C27B = D_8037C279;
    D_8037C27E = 0;
    D_8037C1F8[0] = func_80293EAC(D_8037C1F0[0], D_8037C1F8[0], 1.0f);
    D_8037C1F8[1] = func_80293EAC(D_8037C1F0[1], D_8037C1F8[1], 1.0f);

    switch(D_8037C274){//D_80374788
        case 1:
        case 3:
        case 4:
            _player_getPosition(D_8037C218);
            func_80298504(D_8037C228);
            ml_vec3f_diff_copy(D_8037C238, D_8037C218, D_8037C228);
            if ((D_8037C274 == 3) && func_8031C594(D_8037C200) && ((func_8031C5E4(D_8037C200) - 70.0f) < D_8037C218[1])) {
                D_8037C218[1] = func_8031C5E4(D_8037C200) - 70.0f;
                D_8037C27E = 1;
                player_setYVelocity(1.0f);
            }
            func_80293668();
            player_setPosition(&D_8037C218);
            break;

        case 5:
            _player_getPosition(D_8037C218);
            func_80298504(D_8037C228);
            func_80293668();
            func_80293440();
            player_setPosition(D_8037C218);
            break;

        case 2:
            break;
    }//L80294148
    if (func_8031C594(D_8037C200)) {
        D_8037C278 = (D_8037C218[1] < func_8031C5E4(D_8037C200));
    }
    ml_vec3f_diff_copy(D_8037C248, D_8037C218, D_8037C228);
    ml_vec3f_diff(D_8037C248, D_8037C238);
    if (func_80294560()) {
        D_8037C279 = 1;
    }

    if(D_8037C278 && D_8037C218[1] < (func_8031C5E4(D_8037C200) - 70.0f)){
        func_80294384(3);
        if(D_8037C279 && func_80297AAC() < 0.0f) {
            player_setYVelocity(-1.0f);
        }
    }
    else if(D_8037C279){
        func_80294390();
        if (func_80297AAC() < 0.0f) {
            player_setYVelocity(-1.0f);
        }
    } else {
        func_80294384(1);
    }

    if (D_8037C27F) {
        player_setPosition(sp44);
    }

    D_8037C27A = 0;
    
    if (D_8037C27C) {
        D_8037C280 = func_80258948(D_8037C280 + 1, 3);
    } else {
        D_8037C280 = 0;
    }
    func_80298504(sp2C);
    _player_getPosition(sp38);
    ml_vec3f_diff_copy(D_8037C268, sp38, sp2C);
    // temp_a1 = D_8037C204;
    if (D_8037C204) {
        func_8024587C(&D_8037C208, D_8037C204);
        D_8037C204 = &D_8037C208;
    }
}
#endif

void func_8029436C(s32 arg0){
     D_8037C27F = arg0;
}

void func_80294378(s32 arg0){
     D_8037C274 = arg0;
}

void func_80294384(s32 arg0){
     D_8037C284 = arg0;
}

void func_80294390(void) {
    void *sp1C;

    sp1C = func_8029463C();
    if (sp1C != 0) {
        if (func_803246B4(map_get(), ((s32*)sp1C)[2]) == 3) {
            func_80294384(4);
        }
        else{
            func_80294384(2);
        }
    }else{
          func_80294384(2);
    }
}

f32 func_80294404(void){
     return player_getYPosition() - func_8031C5D4(D_8037C200);
}

f32 func_80294438(void){
     return func_8031C5D4(D_8037C200);
}

void func_8029445C(f32 arg0[3]){
     ml_vec3f_copy(arg0, D_8037C268);
}

void func_80294480(f32 arg0[3]){
     func_8031C5AC(D_8037C200, arg0);
}

f32 func_802944A8(void){
     f32 sp1C[3];
     func_80294480(sp1C);
     return func_80255D70(sp1C[1]);
}

void func_802944D0(f32 dst[3]){
     ml_vec3f_copy(dst, D_8037C258);
}

s32 func_802944F4(void){
     return D_8037C284;
}

f32 func_80294500(void){
     return func_8031C5E4(D_8037C200);
}

s32 func_80294524(void){
     return D_8037C27E;
}

s32 func_80294530(void){
     return D_8037C27D;
}

s32 func_8029453C(void){
     return D_8037C27A;
}

s32 func_80294548(void){
     return D_8037C279;
}

s32 func_80294554(void){
     return D_8037C278;
}

int func_80294560(void){
     return D_8037C280 == 3;
}

void func_80294574(void){
     func_8031C594(D_8037C200);
}

bool func_80294598(void) {
    return (D_8037C248[0] != 0.0f) || (D_8037C248[1] != 0.0f) || (D_8037C248[2] != 0.0f);
}

u32 func_80294610(u32 mask){
     return func_8031C59C(D_8037C200) & mask;
}

s32 func_8029463C(void){
     return func_8031C5F4(D_8037C200);
}

u32 func_80294660(void){
     return func_8031C59C(D_8037C200);
}

void func_80294684(void){
     func_8031C5A4(D_8037C200);
}

void func_802946A8(void){
     func_8031C5DC(D_8037C200);
}

void func_802946CC(void){
     func_8031C5EC(D_8037C200);
}

Struct60s *func_802946F0(void){
     return D_8037C204;
}

int func_802946FC(s32 arg0, s32 arg1){
     if(arg1 == 0){
          return 0;
     }
     else{
          func_802E73C8(arg0);
          return 1;
     }
}

void func_8029472C(void){
     func_8031BA7C(D_8037C200);
}

void func_80294750(void){
     if(D_8037C200){
          D_8037C200 = defrag(D_8037C200);
     }
}
