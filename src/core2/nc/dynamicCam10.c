#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
f32 D_8037DAA0;

/* .code */
void func_802BF0E0(f32 arg0[3]){
    if(player_movementGroup() == BSGROUP_5_CLIMB){
        func_802C0150(3);
    }
    else{
        func_802C0150(1);
    }
    func_802C02D4(arg0);
}

void func_802BF12C(void){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    ncDynamicCamera_getPosition(sp34);
    func_802BF0E0(sp1C);
    ml_vec3f_diff_copy(sp28, sp34, sp1C);
    func_8025801C(sp28, &D_8037DAA0);
}

void ncDynamicCam10_init(void){
    func_802BE244(4.0f, 16.0f);
    func_802BE230(1.1f, 14.0f);
    func_802C0150(3);
    func_802BF12C();
}

void ncDynamicCam10_end(void){}

void ncDynamicCam10_update(void){
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    s32 pad28;

    player_getVelocity(sp44);
    func_802BF0E0(sp5C);
    func_80256E24(sp38, 0.0f, D_8037DAA0, 0.0f, 0.0f,func_802BD8D4());
    ml_vec3f_add(sp50, sp5C, sp38);
    func_802BE190(sp50);
    if(func_802BE60C()){
        func_802BC84C(0);
    }
    func_802BE6FC(sp2C, sp5C);
    func_802BD904(sp2C);
}
