#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* .bss */
static f32 s_position[3];
static f32 s_rotation[3];
static f32 s_time_remaining_s;
static f32 s_duration;
static u8  s_state;

/* .code */
void func_802C2250(void){}

void func_802C2258(void){
    s_state = 0;
}

void func_802C2264(f32 duration){
    s_duration = duration;
    s_time_remaining_s = s_duration;
    ncDynamicCamera_getPosition(s_position);
    ncDynamicCamera_getRotation(s_rotation);
    s_state = 1;
}

void func_802C22B4(void){
    s_state = 0;
}


void func_802C22C0(f32 target_position[3], f32 target_rotation[3]){
    f32 tmpf_1[3];
    f32 tmpf_2[3];
    f32 tmp;
    
    if(s_state == 0)
        return;
    
    if(s_state == 1){
        ml_vec3f_diff(s_position, target_position);
        s_rotation[0] = mlDiffDegF(s_rotation[0], target_rotation[0]);
        s_rotation[1] = mlDiffDegF(s_rotation[1], target_rotation[1]);
        s_rotation[2] = 0.0f;
        s_state = 2;
    }
    s_time_remaining_s -= time_getDelta();
    if(s_time_remaining_s <= 0.0f)
        s_state = 0;
    else {
        tmp = ml_map_f(s_time_remaining_s, 0.0f, s_duration, 0.0f, 1.0f);
        ml_vec3f_scale_copy(tmpf_1, s_position, tmp);
        ml_vec3f_scale_copy(tmpf_2, s_rotation, tmp);
        target_position[0] += tmpf_1[0];
        target_position[1] += tmpf_1[1];
        target_position[2] += tmpf_1[2];
        target_rotation[0] += tmpf_2[0];
        target_rotation[1] += tmpf_2[1];
        target_rotation[2] += tmpf_2[2];
        target_rotation[0] = mlNormalizeAngle(target_rotation[0]);
        target_rotation[1] = mlNormalizeAngle(target_rotation[1]);
        target_rotation[2] = 0.0f;
    }

}

