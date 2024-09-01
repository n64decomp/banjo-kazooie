#include <ultra64.h>
#include "functions.h"

static f32 __playerStartPosition[3];

void ncDynamicCamF_init(void){
    f32 sp24[3];
    f32 sp12[3];

    viewport_get_position_vec3f(sp24);
    viewport_get_rotation_vec3f(sp12);
    ncDynamicCamera_setPosition(sp24);
    ncDynamicCamera_setRotation(sp12);
    player_getPosition(__playerStartPosition);
    func_80291488(5);
}

void ncDynamicCamF_end(void){}

void ncDynamicCamF_update(void){
    f32 player_position[3];
    f32 d_position[3];

    player_getPosition(player_position);
    ml_vec3f_diff_copy(d_position, __playerStartPosition, player_position);
    if( !(gu_sqrtf(d_position[0]*d_position[0] + d_position[1]*d_position[1] + d_position[2]*d_position[2]) < 2.0f)){
        func_80291488(2);
        ncDynamicCamera_setState(0xB);
        func_802BE720();
    }
}
