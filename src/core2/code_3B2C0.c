#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 mlDiffDegF(f32, f32);


/* .bss */
f32 D_8037DC20[3];
f32 D_8037DC30[3];
f32 D_8037DC3C;
f32 D_8037DC40;
u8  D_8037DC44;

/* .code */
void func_802C2250(void){}

void func_802C2258(void){
    D_8037DC44 = 0;
}

void func_802C2264(f32 arg0){
    D_8037DC40 = arg0;
    D_8037DC3C = D_8037DC40;
    ncDynamicCamera_getPosition(D_8037DC20);
    ncDynamicCamera_getRotation(D_8037DC30);
    D_8037DC44 = 1;
}

void func_802C22B4(void){
    D_8037DC44 = 0;
}


void func_802C22C0(f32 vp_position[3], f32 vp_rotation[3]){
    f32 tmpf_1[3];
    f32 tmpf_2[3];
    f32 tmp;
    
    if(D_8037DC44 == 0)
        return;
    
    if(D_8037DC44 == 1){
        ml_vec3f_diff(D_8037DC20, vp_position);
        D_8037DC30[0] = mlDiffDegF(D_8037DC30[0], vp_rotation[0]);
        D_8037DC30[1] = mlDiffDegF(D_8037DC30[1], vp_rotation[1]);
        D_8037DC30[2] = 0.0f;
        D_8037DC44 = 2;
    }
    D_8037DC3C -= time_getDelta();
    if(D_8037DC3C <= 0.0f)
        D_8037DC44 = 0;
    else {
        tmp = ml_map_f(D_8037DC3C, 0.0f, D_8037DC40, 0.0f, 1.0f);
        ml_vec3f_scale_copy(tmpf_1, D_8037DC20, tmp);
        ml_vec3f_scale_copy(tmpf_2, D_8037DC30, tmp);
        vp_position[0] += tmpf_1[0];
        vp_position[1] += tmpf_1[1];
        vp_position[2] += tmpf_1[2];
        vp_rotation[0] += tmpf_2[0];
        vp_rotation[1] += tmpf_2[1];
        vp_rotation[2] += tmpf_2[2];
        vp_rotation[0] = mlNormalizeAngle(vp_rotation[0]);
        vp_rotation[1] = mlNormalizeAngle(vp_rotation[1]);
        vp_rotation[2] = 0.0f;
    }

}

