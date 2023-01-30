#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct {
    f32 unk0;
    f32 unk4;
    u8  xform_8;
} D_8037D180;
u8 D_8037D18C;

/* .code */
void func_8029A890(void){
    func_802957FC();
}

void func_8029A8B0(void){
    func_80295804();
    D_8037D180.unk0 = D_8037D180.unk4 = 0.0f;
    D_8037D180.xform_8 = TRANSFORM_1_BANJO;
    D_8037D18C = FALSE;
}

enum transformation_e _player_getTransformation(void){
    return D_8037D180.xform_8;
}

f32 func_8029A900(void){
    return D_8037D180.unk0;
}

f32 func_8029A90C(void){
    return D_8037D180.unk4;
}

s32 func_8029A918(void){
    return D_8037D18C;
}

void func_8029A924(void){}

void func_8029A92C(void){
    func_8029A968(0.0f);
    func_8029A974(0.0f);
}

void player_setTransformation(enum transformation_e xform_id){
    D_8037D180.xform_8 = xform_id;
}

void func_8029A968(f32 arg0){
    D_8037D180.unk0 = arg0;
}

void func_8029A974(f32 arg0){
    D_8037D180.unk4 = arg0;
}

void func_8029A980(s32 arg0){
    D_8037D18C = arg0;
}
