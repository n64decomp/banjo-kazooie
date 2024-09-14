#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core1/viewport.h>


s32 D_80275860 = 0;

void func_802409C0(f32 arg0[3], f32 arg1){
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp28[2];
    f32 sp24;
    
    sp24 = time_getDelta()*arg1;
    func_8024E71C(0, sp28);

    sp30[0] = sp28[0] * sp24;
    sp30[1] = 0.0f;
    sp30[2] = -(sp28[1] * sp24);

    viewport_getRotation_vec3f(&sp3C);
    ml_vec3f_yaw_rotate_copy(sp30, sp30, sp3C[1]);

    arg0[0] = arg0[0] + sp30[0];
    arg0[1] = arg0[1] + sp30[1];
    arg0[2] = arg0[2] + sp30[2];
}

void func_80240A74(f32 arg0[3]){
    func_802409C0(arg0, 400.0f);
}

f32 func_80240A94(s32 arg0, f32 arg1){
    if(arg0 >= 0x29){
        arg0 = 0x28;
    }
    return arg1 + (f32)arg0*(arg1)/16 ;
}

void func_80240AC8(f32 arg0[3], f32 arg1){
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp28[2];
    f32 sp24;
    
    sp24 = time_getDelta()*arg1;
    func_8024E71C(0, sp28);

    if(0.0f != sp28[0] || 0.0f != sp28[1]){
        D_80275860++;
        if(D_80275860 >= 0x12D) 
            D_80275860 = 0x12C;
    }
    else{
        D_80275860 = 1;
    }

    sp24 = func_80240A94(D_80275860, sp24);
    sp30[0] = sp28[0] * sp24;
    sp30[1] = 0.0f;
    sp30[2] = -(sp28[1] * sp24);

    viewport_getRotation_vec3f(&sp3C);
    ml_vec3f_yaw_rotate_copy(sp30, sp30, sp3C[1]);

    arg0[0] = arg0[0] + sp30[0];
    arg0[1] = arg0[1] + sp30[1];
    arg0[2] = arg0[2] + sp30[2];
}
