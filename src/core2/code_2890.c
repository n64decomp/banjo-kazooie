#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802E4B38(void);
extern f32 func_80257BFC(f32, f32, f32, f32, f32);

void func_80289F30(void);

/* .data */
f32 D_803635E0[3] = {0.0f, 5.0f, 0.0f};
s32 D_803635EC[7] = {0x4, 0x3, 0x60, 0x18, 0x1B, 0x67, 0x80};

/* .bss */
AnimCtrl *D_8037BF20;
s32 D_8037BF24;
f32 D_8037BF28;
f32 D_8037BF2C;
struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    u8  unk14;
}D_8037BF30;
void (*D_8037BF48)(s32, s32);

/* .code */
void func_80289820(s32 arg0){
    D_8037BF24 = arg0;
}

void func_8028982C(void) {
    f32 sp2C[3];
    f32 temp_f12;
    f32 sp24;
    
    sp24 = (D_8037BF30.unk14 != 0) ? D_8037BF30.unk10 : 1.0f;
    _get_velocity(sp2C);
    temp_f12 = func_80257BFC(gu_sqrtf(sp2C[0]*sp2C[0] + sp2C[2] * sp2C[2]), D_8037BF30.unk0, D_8037BF30.unk4, D_8037BF30.unk8 * sp24, D_8037BF30.unkC * sp24);
    animctrl_setDuration(D_8037BF20, mlClamp_f(temp_f12, D_8037BF28, D_8037BF2C));
    animctrl_update(D_8037BF20);
}

void func_802898F8(void) {
    animctrl_setDuration(D_8037BF20, mlClamp_f(func_80257BFC(mlAbsF(func_80297AAC()), D_8037BF30.unk0, D_8037BF30.unk4, D_8037BF30.unk8, D_8037BF30.unkC), D_8037BF28, D_8037BF2C));
    animctrl_update(D_8037BF20);
}


void func_80289978(f32 sp2C[3], f32 arg1, f32 arg2, f32 arg3) {
    s32 phi_s0;

    for(phi_s0 = 0; phi_s0 < 3; phi_s0++){
        sp2C[phi_s0] = ((((f64) sinf((f32) ((f64) func_80257A44((f32) ( arg1 + (2.0 * ((f64) (f32) phi_s0 / 3.0))), 2.0f) * 6.2831853080000002)) * 0.5) + 0.5) * arg3) + arg2;
    };
}

void func_80289A78(s32 arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp28;
    s32 phi_s0;
    static s32 D_8037BF4C;
 

    sp28 = func_802E4B38();
    if (func_803203FC(0x78) == 0) {
        D_8037BF4C = 0;
    } else {
        for(phi_s0 = 0; phi_s0 < 7; phi_s0++){
            if (func_803203FC(phi_s0 + 0x97)) {
                D_8037BF4C = D_803635EC[phi_s0];
            }
        }
    }
    if ((D_8037BF4C & 1)) {
        func_80289978(&sp2C, sp28, 2.0f, 1.0f);
        func_8033A928(arg0, 6, &sp2C);
        func_8033A928(arg0, 0x14, &sp2C);
    }
    if (D_8037BF4C & 2) {
        func_80289978(&sp2C, sp28, 2.0f, 1.0f);
        func_8033A928(arg0, 0x10, &sp2C);
        func_8033A928(arg0, 0x1E, &sp2C);
    }
    if (D_8037BF4C & 4) {
        func_80289978(&sp2C, sp28, 2.0f, 1.0f);
        func_8033A928(arg0, 0x12, &sp2C);
    }
    if (D_8037BF4C & 8) {
        func_80289978(&sp2C, sp28, 0.2f, 0.5f);
        func_8033A928(arg0, 0x12, &sp2C);
    }
    if (D_8037BF4C & 0x10) {
        func_8033A968(arg0, 1, &D_803635E0);
    }
    if (D_8037BF4C & 0x20) {
        func_80289978(&sp2C, sp28, 2.0f, 1.0f);
        func_8033A928(arg0, 0x6C, &sp2C);
    }
    if (D_8037BF4C & 0x40) {
        func_80289978(&sp2C, sp28, 2.0f, 1.0f);
        func_8033A928(arg0, 0x64, &sp2C);
        func_8033A928(arg0, 0x67, &sp2C);
    }
    if (map_get() == MAP_A_TTC_SANDCASTLE) {
        if ((D_8037BF4C & 0x80) && (player_getTransformation() != TRANSFORM_7_WISHWASHY)) {
            func_8028FB88(7);
        }
        if (!(D_8037BF4C & 0x80) && (player_getTransformation() == TRANSFORM_7_WISHWASHY)) {
            func_8028FB88(1);
        }
    }
    if (D_8037BF48 != NULL) {
        D_8037BF48(arg0, arg1);
    }
}

void func_80289D1C(void){
    D_8037BF20 = animctrl_new(1);
    func_80287784(D_8037BF20, 0);
    animctrl_setSmoothTransition(D_8037BF20, FALSE);
    func_8028746C(D_8037BF20, func_80289A78);
    D_8037BF48 = NULL;
    func_80289F30();
    D_8037BF24 = 0;
    func_80289820(1);
    func_80289EA8(0.01f, 100.0f);
    func_80289EC8(0.0f, 1000.0f, 0.1f, 10.0f);
    D_8037BF30.unk14 = 0;
    D_8037BF30.unk10 = 1.0f;
}

void func_80289DDC(void){
    animctrl_free(D_8037BF20);
}

void func_80289E00(void){
    switch(D_8037BF24){
        case 2:
            func_8028982C();
            break;
        
        case 3:
            func_802898F8();
            break;

        case 1:
            animctrl_update(D_8037BF20);
            break;

        case 0:
            break;
    }
}

void func_80289E74(void){
    D_8037BF20 = animctrl_defrag(D_8037BF20);
}

s32 func_80289E9C(void){
    return D_8037BF24;
}

void func_80289EA8(f32 arg0, f32 arg1){
    D_8037BF28 = arg0;
    D_8037BF2C = arg1;
}

void func_80289EBC(void (*arg0)(s32, s32)){
    D_8037BF48 = arg0;
}

void func_80289EC8(f32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_8037BF30.unk0 = arg0;
    D_8037BF30.unk4 = arg1;
    D_8037BF30.unk8 = arg2;
    D_8037BF30.unkC = arg3;
    D_8037BF30.unk14 = 0;
}

void func_80289EF8(f32 arg0){
    D_8037BF30.unk10 = arg0;
    D_8037BF30.unk14 = 1;
}

void func_80289F10(s32 arg0){
    func_80289820(arg0);
}

void func_80289F30(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    func_8028781C(D_8037BF20, sp1C, 1);
}

AnimCtrl *_player_getAnimCtrlPtr(void){
    return D_8037BF20;
}

f32 func_80289F70(void){
    return animctrl_getAnimTimer(D_8037BF20);
}

bool func_80289F94(enum asset_e anim_id){
    return animctrl_getIndex(D_8037BF20) == anim_id;
}

bool baanim_isStopped(void){
    return animctrl_isStopped(D_8037BF20);
}

bool baanim_isAt(f32 time){
    return animctrl_isAt(D_8037BF20, time);
}

void func_8028A010(enum asset_e anim_id, f32 duration){
    animctrl_reset(D_8037BF20);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    animctrl_setPlaybackType(D_8037BF20, 2);
    func_802875AC(D_8037BF20, "baanim.c", 0x188);
}

void func_8028A084(enum asset_e anim_id, f32 duration){
    animctrl_reset(D_8037BF20);
    animctrl_setSmoothTransition(D_8037BF20, FALSE);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    animctrl_setPlaybackType(D_8037BF20, 2);
    func_802875AC(D_8037BF20, "baanim.c", 0x193);
}

void func_8028A100(enum asset_e anim_id, f32 duration, f32 arg2){
    animctrl_reset(D_8037BF20);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    func_8028774C(D_8037BF20, arg2);
    animctrl_setPlaybackType(D_8037BF20, 2);
    func_802875AC(D_8037BF20, "baanim.c", 0x19e);
}

void func_8028A180(enum asset_e anim_id, f32 duration){
    animctrl_reset(D_8037BF20);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    animctrl_setPlaybackType(D_8037BF20, 1);
    func_802875AC(D_8037BF20, "baanim.c", 0x1a8);
}

void func_8028A1F4(enum asset_e anim_id, f32 duration, f32 arg2){
    animctrl_reset(D_8037BF20);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    func_8028774C(D_8037BF20, arg2);
    animctrl_setPlaybackType(D_8037BF20, 1);
    func_802875AC(D_8037BF20, "baanim.c", 0x1b3);
}

void func_8028A274(enum asset_e anim_id, f32 duration){
    animctrl_reset(D_8037BF20);
    animctrl_setSmoothTransition(D_8037BF20, FALSE);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    animctrl_setPlaybackType(D_8037BF20, 1);
    func_802875AC(D_8037BF20, "baanim.c", 0x1bd);
}

void func_8028A2F0(enum asset_e anim_id, f32 duration, f32 arg2){
    animctrl_reset(D_8037BF20);
    animctrl_setSmoothTransition(D_8037BF20, FALSE);
    animctrl_setIndex(D_8037BF20, anim_id);
    animctrl_setDuration(D_8037BF20, duration);
    func_8028774C(D_8037BF20, arg2);
    animctrl_setPlaybackType(D_8037BF20, 1);
    func_802875AC(D_8037BF20, "baanim.c", 0x1c9);
}

void func_8028A37C(f32 arg0){
    animctrl_setSubRange(D_8037BF20, 0.0f, arg0);
    animctrl_setPlaybackType(D_8037BF20, 1);
}

void func_8028A3B8(f32 arg0, f32 arg1){
    animctrl_setSubRange(D_8037BF20, 0.0f, arg0);
    animctrl_setDuration(D_8037BF20, arg1);
    animctrl_setPlaybackType(D_8037BF20, 1);
}
