#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"



/* .data */
s32 D_80363790 = 0;

/* .code */
void func_802927E0(f32 arg0, f32 arg1){
    f32 sp24[3];
    f32 sp18[3];

    arg1 *= 0.51;
    playerPosition_get(sp18);
    sp18[1] += 10.0f;
    func_802589E4(sp24, arg0, arg1);
    sp24[1] = 40.0f;
    func_80352CF4(sp18, sp24, 10.0f, 150.0f);
}

void func_80292864(f32 arg0, f32 arg1){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    ml_vec3f_assign(sp1C, 0.0f, 40.0f, 0.0f);
    playerPosition_get(sp28);
    func_802589E4(sp34, arg0, arg1);
    sp34[1] = 10.0f;
    sp28[0] += sp34[0]; sp28[1] += sp34[1]; sp28[2] += sp34[2];
    func_80352CF4(sp28, sp1C, 10.0f, 150.0f);
}

void func_80292900(f32 arg0, f32 arg1){
    f32 sp24[3];
    f32 sp18[3];

    arg1 *= 0.51;
    playerPosition_get(sp18);
    func_802589E4(sp24, arg0, arg1);
    sp24[1] = 40.0f;
    func_80352CF4(sp18, sp24, 10.0f, 150.0f);
}

void func_80292974(f32 arg0, f32 arg1, f32 arg2){
    f32 sp24[3];
    f32 sp18[3];
    arg1 *= 0.51;
    playerPosition_get(sp18);
    sp18[1] += 10.0f;
    func_802589E4(sp24, arg0, arg1);
    sp24[1] = arg2;
    func_80352CF4(sp18, sp24, 150.0f, 10.0f);
}

void func_802929F8(void){
    switch (D_80363790) {
    case 0: //L80292A2C
        func_80292864(baphysics_get_target_yaw() - 20.0f, 40.0f);
        break;
    case 1: //L80292A2C
        func_80292864(baphysics_get_target_yaw() + 20.0f, 40.0f);
        break;
    case 2: //L80292A94
        func_80292864(baphysics_get_target_yaw(), 30.0f);
        break;
    default: //L80292AC0
        break;
    }
    if(++D_80363790 >= 3)
       D_80363790 = 0; 
}
