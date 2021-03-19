#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 player_position[3];
extern f32 D_8037C5B0[3];
extern f32 D_8037C5C0[3];

void func_802983F0(void){
    clear_vec3f(D_8037C5C0);
    clear_vec3f(player_position);
    clear_vec3f(D_8037C5B0);
}

void func_8029842C(void){
    copy_vec3f(D_8037C5B0, player_position);
    clear_vec3f(D_8037C5C0);
}

void func_80298464(f32 *arg0){
    copy_vec3f(player_position, arg0);
    copy_vec3f(D_8037C5B0, arg0);
}

void player_setPosition(f32 *arg0){
    copy_vec3f(player_position, arg0);
}

void player_setYPosition(f32 arg0){
    player_position[1] = arg0;
}

void _player_getPosition(f32 *arg0){
    copy_vec3f(arg0, player_position);
}

f32 player_getYPosition(void){
    return player_position[1];
}

void func_80298504(f32 *arg0){
    copy_vec3f(arg0, D_8037C5B0);
}

void func_80298528(f32 arg0){
    player_position[1] += arg0;
}

void func_80298540(f32 *arg0){
    copy_vec3f(arg0, D_8037C5C0);
}

void func_80298564(f32 *arg0){
    copy_vec3f(D_8037C5C0, arg0);
}

void func_8029858C(void){
    player_position[0] += D_8037C5C0[0];
    player_position[1] += D_8037C5C0[1];
    player_position[2] += D_8037C5C0[2];
    clear_vec3f(D_8037C5C0);

}