#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 D_8037C300;
f32 D_8037C304;

int should_beak_barge(void){
    return button_pressed(BUTTON_B) && can_beak_barge();
}

int should_beak_bust(void){
    return button_pressed(BUTTON_Z) && can_beak_bust();
}

int func_80294F78(void){
    return button_pressed(BUTTON_C_UP) && func_8028ACD8();
}

int should_rotate_camera_left(void){
    return button_pressed(BUTTON_C_LEFT) && func_802951FC(0);
}

int should_rotate_camera_right(void){
    return button_pressed(BUTTON_C_RIGHT) && func_802951FC(1);
}

int should_zoom_out_camera(void){
    return button_pressed(BUTTON_C_DOWN) && func_802951FC(5);
}

int should_poop_egg(void){
    return button_pressed(BUTTON_C_DOWN) && can_egg();
}

int should_shoot_egg(void){
    return button_pressed(BUTTON_C_UP) && can_egg();
}

int should_flap(void){
    return button_pressed(BUTTON_A) && can_flap();
}

int should_flip(void){
    return button_pressed(BUTTON_A) && can_flip();
}

int should_peck(void){
    return button_pressed(BUTTON_B) && can_peck();
}

int should_dive(void){
    return button_pressed(BUTTON_B) && (D_8037C304 == 0.0f) && can_dive();
}

int func_802951FC(s32 arg0){
    return D_8037C300  & (1 << arg0);
}

int should_trot(void){
    return button_pressed(BUTTON_C_LEFT) && can_trot();
}

int should_wonderwing(void){
    return button_pressed(BUTTON_C_RIGHT) && can_wonderwing();
}

void func_8029528C(void){
    D_8037C300 = -1;
    D_8037C304 = 0.0f;
}

void func_802952A8(s32 arg0, int arg1){
    if(arg1)
        D_8037C300 |= (1 <<arg0);
    else
        D_8037C300 &= ~(1 <<arg0);
}

void func_802952F4(s32 arg0, s32 arg1, int arg2){
    func_802952A8(arg0, arg2);
    func_802952A8(arg1, arg2);
}

void func_80295328(int arg0, f32 arg1){
    D_8037C304 = arg1;
}

void func_8029533C(void){
    if(D_8037C304 != 0.0f){
       D_8037C304  = ml_max_f(D_8037C304 - time_getDelta(), 0.0f);
    }
}
