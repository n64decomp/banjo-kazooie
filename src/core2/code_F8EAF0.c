#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_802BD51C(void);


void func_802C0150(s32 arg0);

/* .bss */
u8  D_8037DB40;
f32 D_8037DB48[3];
f32 D_8037DB58[3];

/* .code */
void func_802C0120(void){
    D_8037DB40 = 0;
    func_802C0150(2);
}

void func_802C0148(void){}

void func_802C0150(s32 arg0) {
    D_8037DB40 = arg0;
    if (arg0 == 6) {
        func_802BD4C0(D_8037DB48);
        ml_vec3f_clear(D_8037DB58);
    }
}

s32 func_802C0190(void){
    return D_8037DB40;
}

void func_802C019C(f32 arg0[3]){
    func_802BD3CC(arg0);
}

void func_802C01BC(f32 arg0[3]){
    func_802BD4C0(arg0);
}

void func_802C01DC(f32 arg0[3]) {
    f32 sp1C[3];

    func_8028E7EC(sp1C);
    player_getPosition(arg0);
    arg0[0] = sp1C[0];
    arg0[1] += 90.0f;
    arg0[2] = sp1C[2];
}

void func_802C0234(f32 arg0[3]) {
    player_getPosition(arg0);
    arg0[1] += 60.0f;
}

void func_802C026C(f32 arg0[3]) {
    f32 sp1C[3];

    func_802BD4C0(arg0);
    player_getPosition(sp1C);
    arg0[1] = sp1C[1];
    arg0[1] += 60.0f;
}

void func_802C02B4(f32 arg0[3]){
    func_802BD4C0(arg0);
}

void func_802C02D4(f32 arg0[3]) {
    switch(D_8037DB40){
        case 1: 
            func_802C019C(arg0);
            break;

        case 2: 
            func_802C01BC(arg0);
            break;

        case 3:
            func_802C01DC(arg0);
            break;

        case 4:
            func_802C0234(arg0);
            break;

        case 5:
            func_802C026C(arg0);
            break;

        case 6:
            func_802C02B4(arg0);
            break;
    }
}
