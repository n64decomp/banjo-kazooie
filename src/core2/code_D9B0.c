#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8037C2A0[3]; //recoil_target_position
extern f32 D_8037C2B0[3]; //talk_target_position
extern f32 D_8037C2C0[3]; //throw_target_position
extern f32 D_8037C2CC;
extern enum transformation_e D_8037C2D0;
extern f32 D_8037C2D8[3];
extern f32 D_8037C2E4;
extern enum asset_e D_8037C2E8;
extern u8 D_8037C2ED;
extern u8 D_8037C2EC;

extern struct{
    f32 unk0;
    f32 unk4;
    u8 unk8;
}D_8037C2F0;

/* .code */
f32 func_80294940(void){
    return D_8037C2F0.unk0;
}

f32 func_8029494C(void){
    return D_8037C2F0.unk0 - func_80294500();
}

enum asset_e func_80294974(void){
    return D_8037C2E8;
}

void func_80294980(f32 (* dst)[3]){
    ml_vec3f_copy(dst, &D_8037C2A0);
}

void func_802949A4(f32 (* dst)[3]){
    ml_vec3f_copy(dst, &D_8037C2D8);
}

int func_802949C8(void){
    return D_8037C2EC;
}

f32 get_slope_timer(void){
    return D_8037C2E4 * (f64)1;
}

void func_802949F8(f32 (* dst)[3]){
    ml_vec3f_copy(dst, &D_8037C2B0);
}

void func_80294A1C(f32 (* dst)[3]){
    ml_vec3f_copy(dst, &D_8037C2C0);
}

f32 func_80294A40(void){
    return D_8037C2CC;
}

enum transformation_e func_80294A4C(void){
    return D_8037C2D0;
}

void func_80294A58(enum asset_e asset_id){
    D_8037C2E8 = asset_id;
}

void func_80294A64(f32 (* src)[3])
{ ml_vec3f_copy(&D_8037C2A0, src);
}

void func_80294A8C(int arg0){
    D_8037C2EC = arg0;
}

void func_80294A98(f32 (* src)[3])
{ ml_vec3f_copy(&D_8037C2B0, src);
}

void func_80294AC0(f32 (* src)[3])
{ ml_vec3f_copy(&D_8037C2C0, src);
}

void func_80294AE8(f32 arg0){
    D_8037C2CC = arg0;
}

void func_80294AF4(enum transformation_e xform){
    D_8037C2D0 = xform;
}

void func_80294B00(int arg0){
    D_8037C2F0.unk8 = arg0;
}

void func_80294B0C(void){
    f32 sp1C = player_getYPosition();
    int sp18 = func_8028ECAC();
    if( func_8028B2E8() 
        || player_inWater() 
        || (sp18 == 0xa && func_8028E76C(0) != 3) 
        || sp18 == 0x5
    ){////L80294B74
        func_80294B00(1);
    }
    else{
        func_80294B00(2);
    }

    if(D_8037C2F0.unk8 != 2  || !(sp1C <= D_8037C2F0.unk4)){
        D_8037C2F0.unk0 = D_8037C2F0.unk4;
        D_8037C2F0.unk4 = sp1C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D9B0/func_80294BDC.s")

void func_80294DD8(void){
    ml_vec3f_clear(&D_8037C2A0);
    ml_vec3f_clear(&D_8037C2B0);
    _player_getPosition(&D_8037C2D8);
    D_8037C2ED = 0;
    D_8037C2E4 = 0.0f;
    D_8037C2EC = 1;
    D_8037C2F0.unk8 = 0;
    D_8037C2F0.unk4 = D_8037C2F0.unk0 = player_getYPosition();
}

void func_80294E54(int arg0){
    D_8037C2ED = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D9B0/func_80294E60.s")
