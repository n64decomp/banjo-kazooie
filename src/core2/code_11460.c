#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
f32 player_position[3];
f32 D_8037C5B0[3];
f32 D_8037C5C0[3];

/* .code */
void func_802983F0(void){
    ml_vec3f_clear(D_8037C5C0);
    ml_vec3f_clear(player_position);
    ml_vec3f_clear(D_8037C5B0);
}

void func_8029842C(void){
    ml_vec3f_copy(D_8037C5B0, player_position);
    ml_vec3f_clear(D_8037C5C0);
}

void func_80298464(f32 arg0[3]){
    ml_vec3f_copy(player_position, arg0);
    ml_vec3f_copy(D_8037C5B0, arg0);
}

void player_setPosition(f32 arg0[3]){
    ml_vec3f_copy(player_position, arg0);
}

void player_setYPosition(f32 arg0){
    player_position[1] = arg0;
}

void _player_getPosition(f32 arg0[3]){
    ml_vec3f_copy(arg0, player_position);
}

f32 player_getYPosition(void){
    return player_position[1];
}

void func_80298504(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037C5B0);
}

void func_80298528(f32 arg0){
    player_position[1] += arg0;
}

void func_80298540(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_8037C5C0);
}

void func_80298564(f32 arg0[3]){
    ml_vec3f_copy(D_8037C5C0, arg0);
}

void func_8029858C(void){
    player_position[0] += D_8037C5C0[0];
    player_position[1] += D_8037C5C0[1];
    player_position[2] += D_8037C5C0[2];
    ml_vec3f_clear(D_8037C5C0);

}
