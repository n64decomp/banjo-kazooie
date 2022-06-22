#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802944A8(void);

/* .bss */
f32 D_8037C2A0[3]; //recoil_target_position
f32 D_8037C2B0[3]; //talk_target_position
f32 D_8037C2C0[3]; //throw_target_position
f32 D_8037C2CC;
enum transformation_e D_8037C2D0;
f32 D_8037C2D8[3];
f32 D_8037C2E4;
enum asset_e D_8037C2E8;
u8 D_8037C2ED;
u8 D_8037C2EC;

struct{
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

void func_80294980(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2A0);
}

void func_802949A4(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2D8);
}

int func_802949C8(void){
    return D_8037C2EC;
}

f32 get_slope_timer(void){
    return D_8037C2E4 * (f64)1;
}

void func_802949F8(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2B0);
}

void func_80294A1C(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2C0);
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

void func_80294A64(f32 src[3])
{ ml_vec3f_copy(D_8037C2A0, src);
}

void func_80294A8C(int arg0){
    D_8037C2EC = arg0;
}

void func_80294A98(f32 src[3])
{ ml_vec3f_copy(D_8037C2B0, src);
}

void func_80294AC0(f32 src[3])
{ ml_vec3f_copy(D_8037C2C0, src);
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
        || (sp18 == 0xa && player_getActiveHitbox(0) != HITBOX_3_BEAK_BOMB) 
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

void func_80294BDC(void) {
    Struct60s *temp_v0;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;

    sp28 = time_getDelta();
    sp2C = func_802944A8();
    sp24 = func_80294660();
    if ((map_get() == MAP_34_RBB_ENGINE_ROOM) && ((sp24 * 0x10) < 0)) {
        D_8037C2ED = 1;
    }
    if (D_8037C2ED != 0) {
        D_8037C2E4 = (sp2C > 35.0f) ? 1.0f : 0.0f;
    } else {
        sp30 = ml_map_f(sp2C, 20.0f, 60.0f, 0.6f, 1.3f);
        if (!func_80294548() && !(sp24 & 0x50)) {
            temp_v0 = func_802946F0();
            if (temp_v0) {
                if (temp_v0->unk8 & 0x50) {
                    sp24 = temp_v0->unk8;
                }
            }
        }
        if (map_get() == MAP_C_MM_TICKERS_TOWER) {
            sp28 *= 2.0;
        }
        if ((sp24 & 0x50) && !player_inWater()) {
            D_8037C2E4 = min_f((sp28 * sp30) + D_8037C2E4, 1.0f);
        } else {
            D_8037C2E4 = 0.0f;
        }
        if (D_8037C2E4 == 1.0) {
            if (sp24 & 0x10) {
                func_802917E4(5, 0.18f);
            } else if (sp24 & 0x40) {
                func_802917E4(6, 0.18f);
            }
        }
    }
    D_8037C2ED = 0;
}

void func_80294DD8(void){
    ml_vec3f_clear(D_8037C2A0);
    ml_vec3f_clear(D_8037C2B0);
    _player_getPosition(D_8037C2D8);
    D_8037C2ED = 0;
    D_8037C2E4 = 0.0f;
    D_8037C2EC = 1;
    D_8037C2F0.unk8 = 0;
    D_8037C2F0.unk4 = D_8037C2F0.unk0 = player_getYPosition();
}

void func_80294E54(int arg0){
    D_8037C2ED = arg0;
}

void func_80294E60(void){
    if(func_8028B2E8()){
        _player_getPosition(D_8037C2D8);
    }

    if(func_8028B2E8() || bsclimb_inSet(bs_getState())){
        func_802933FC(5);
        func_802933FC(0x12);
    }

    if(player_inWater()){
        func_802933FC(5);
        func_802933FC(0x12);
    }

    func_80294BDC();
    func_80294B0C();
}
