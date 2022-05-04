#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80375F20;

/*.bss */
extern f32 D_8037DB30[3];

/* .code */
void func_802BFED0(void){
    f32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    player_getPosition(sp28);
    func_802BD384(sp1C);
    func_80257F18(sp28, sp1C, &sp34);
    D_8037DB30[2] = sp34;
    D_8037DB30[1] = 0.0f;
}

void func_802BFF1C(void) {
    func_802BE244(4.0f, 16.0f);
    func_802BE230(D_80375F20, 14.0f);
    D_8037DB30[0] = 290.0f;
    func_802BFED0();
}

void func_802BFF78(void){}

void func_802BFF80(f32 arg0){
    D_8037DB30[0] = arg0;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_38F40/func_802BFF8C.s")
#else
void func_802BFF8C(void) {
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];

    player_getPosition(sp3C);
    sp3C[1] += 160.0f;
    func_80256E24(sp30, D_8037DB30[1], D_8037DB30[2], 0.0f, 0.0f, D_8037DB30[0]);
    sp3C[0] += sp30[0];
    sp3C[1] += sp30[1];
    sp3C[2] += sp30[2];
    func_802BE190(sp3C);
    switch(map_get()){
        case MAP_B_CC_CLANKERS_CAVERN:
        case MAP_14_GV_SANDYBUTTS_MAZE:
        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_48_FP_MUMBOS_SKULL:
            if (!func_802BE834(sp3C)) {
                D_8037DB30[1] = max_f(D_8037DB30[1] - 8.0f, -75.0f);
            }
            break;
        default:
            if (func_802BC84C(1)) {
                func_802BFED0();
                return;
            }
            break;
    }
    func_802BD384(sp54);
    player_getPosition(sp3C);
    sp3C[1] += 100.0f;
    func_8025727C(sp3C[0], sp3C[1], sp3C[2], sp54[0], sp54[1], sp54[2], &sp48[0], &sp48[1]);
    sp48[0] = mlNormalizeAngle(-sp48[0]);
    func_802BD904(sp48);
}
#endif
