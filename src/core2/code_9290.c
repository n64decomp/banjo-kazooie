#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
s32 D_8037C010;
s32 D_8037C014;
s32 D_8037C018;
s32 D_8037C01C;
f32 D_8037C020[3];
u8  D_8037C02C;

/* .code */
void func_80290220(void){
    D_8037C010 = D_8037C014 = -1;
    D_8037C02C = 0;
    D_8037C018 = -1;
    _player_getPosition(D_8037C020);
}

void func_8029026C(s32 arg0, s32 arg1){
    func_80303F6C(arg0, arg1);
}

void func_8029028C(bool arg0){
    D_8037C02C = arg0;
}

void func_80290298(void) {
    s32 sp24;
    s32 sp30;
    s32 pad2C;
    bool is_pumpkin;

    is_pumpkin = player_getTransformation() == TRANSFORM_3_PUMPKIN;
    sp30 = (func_8028B528() && !is_pumpkin) ? 6 : 1;
    sp24 = func_8028B528() && !is_pumpkin;
    if (D_8037C02C || player_isStable() || sp24 || func_8028ECAC() == BSGROUP_5_CLIMB || bs_getState() == BS_B_UNKOWN) {
        _player_getPosition(D_8037C020);
    }

    if (func_8028ECAC() == BSGROUP_A_FLYING) {
        D_8037C018 = -1;
    }
    else if (func_803077FC(D_8037C020, &D_8037C010, &D_8037C014, 0x12C, sp30)) {
        D_8037C018 = func_80306D40(D_8037C010);
    }
    else{
        D_8037C018 = -1;
    }
}

s32 func_802903CC(void){
    return D_8037C018;
}
