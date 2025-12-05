#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"

extern f32 func_802944A8(void);

/* .bss */
f32 D_8037C2A0[3]; //recoil_target_position
f32 D_8037C2B0[3]; //talk_target_position
f32 D_8037C2C0[3]; //throw_target_position
f32 s_turbo_duration;
enum transformation_e D_8037C2D0;
f32 D_8037C2D8[3];
f32 D_8037C2E4;
enum asset_e D_8037C2E8;
u8 D_8037C2EC;
u8 D_8037C2ED;

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
    return D_8037C2F0.unk0 - floor_getCurrentFloorYPosition();
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

void get_talk_target_position(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2B0);
}

void get_throw_target_position(f32 dst[3]){
    ml_vec3f_copy(dst, D_8037C2C0);
}

f32 get_turbo_duration(void){
    return s_turbo_duration;
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

void set_talk_target_position(f32 src[3])
{ ml_vec3f_copy(D_8037C2B0, src);
}

void set_throw_target_position(f32 src[3])
{ ml_vec3f_copy(D_8037C2C0, src);
}

void set_turbo_duration(f32 arg0){
    s_turbo_duration = arg0;
}

void func_80294AF4(enum transformation_e xform){
    D_8037C2D0 = xform;
}

void func_80294B00(int arg0){
    D_8037C2F0.unk8 = arg0;
}

void func_80294B0C(void){
    f32 sp1C = player_getYPosition();
    enum bsgroup_e player_movement_group = player_movementGroup();
    if( player_isStable() 
        || player_inWater() 
        || (player_movement_group == BSGROUP_A_FLYING && player_getActiveHitbox(0) != HITBOX_3_BEAK_BOMB) 
        || player_movement_group == BSGROUP_5_CLIMB
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
    BKCollisionTri *temp_v0;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;

    sp28 = time_getDelta();
    sp2C = func_802944A8();
    sp24 = func_80294660();
    if ((gsworld_get_map() == MAP_34_RBB_ENGINE_ROOM) && ((sp24 * 0x10) < 0)) {
        D_8037C2ED = 1;
    }
    if (D_8037C2ED != 0) {
        D_8037C2E4 = (sp2C > 35.0f) ? 1.0f : 0.0f;
    } else {
        sp30 = ml_map_f(sp2C, 20.0f, 60.0f, 0.6f, 1.3f);
        if (!func_80294548() && !(sp24 & 0x50)) {
            temp_v0 = func_802946F0();
            if (temp_v0) {
                if (temp_v0->flags & 0x50) {
                    sp24 = temp_v0->flags;
                }
            }
        }
        if (gsworld_get_map() == MAP_C_MM_TICKERS_TOWER) {
            sp28 *= 2.0;
        }
        if ((sp24 & 0x50) && !player_inWater()) {
            D_8037C2E4 = ml_min_f((sp28 * sp30) + D_8037C2E4, 1.0f);
        } else {
            D_8037C2E4 = 0.0f;
        }
        if (D_8037C2E4 == 1.0) {
            if (sp24 & 0x10) {
                stateTimer_set(STATE_TIMER_5_UNKNOWN, 0.18f);
            } else if (sp24 & 0x40) {
                stateTimer_set(STATE_TIMER_6_UNKNOWN, 0.18f);
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
    if(player_isStable()){
        _player_getPosition(D_8037C2D8);
    }

    if(player_isStable() || bsclimb_inSet(bs_getState())){
        baflag_clear(BA_FLAG_5_HAS_PECKED);
        baflag_clear(BA_FLAG_12_HAS_FLAPPED);
    }

    if(player_inWater()){
        baflag_clear(BA_FLAG_5_HAS_PECKED);
        baflag_clear(BA_FLAG_12_HAS_FLAPPED);
    }

    func_80294BDC();
    func_80294B0C();
}
