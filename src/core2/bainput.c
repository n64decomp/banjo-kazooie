#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u32 bainput_enableMask;
f32 bainput_diveCooldown;

int bainput_should_beak_barge(void){
    return bakey_pressed(BUTTON_B) && can_beak_barge();
}

int bainput_should_beak_bust(void){
    return bakey_pressed(BUTTON_Z) && can_beak_bust();
}

int bainput_should_look_first_person_camera(void){
    return bakey_pressed(BUTTON_C_UP) && can_view_first_person();
}

int bainput_should_rotate_camera_left(void){
    return bakey_pressed(BUTTON_C_LEFT) && bainput_isEnabled(0);
}

int bainput_should_rotate_camera_right(void){
    return bakey_pressed(BUTTON_C_RIGHT) && bainput_isEnabled(1);
}

int bainput_should_zoom_out_camera(void){
    return bakey_pressed(BUTTON_C_DOWN) && bainput_isEnabled(5);
}

int bainput_should_poop_egg(void){
    return bakey_pressed(BUTTON_C_DOWN) && can_egg();
}

int bainput_should_shoot_egg(void){
    return bakey_pressed(BUTTON_C_UP) && can_egg();
}

int bainput_should_feathery_flap(void){
    return bakey_pressed(BUTTON_A) && can_feathery_flap();
}

int bainput_should_flap_flip(void){
    return bakey_pressed(BUTTON_A) && can_flap_flip();
}

int bainput_should_peck(void){
    return bakey_pressed(BUTTON_B) && can_peck();
}

int bainput_should_dive(void){
    return bakey_pressed(BUTTON_B) && (bainput_diveCooldown == 0.0f) && can_dive();
}

int bainput_isEnabled(s32 arg0){
    return bainput_enableMask  & (1 << arg0);
}

int bainput_should_trot(void){
    return bakey_pressed(BUTTON_C_LEFT) && can_trot();
}

int bainput_should_wonderwing(void){
    return bakey_pressed(BUTTON_C_RIGHT) && can_wonderwing();
}

void bainput_reset(void){
    bainput_enableMask = -1;
    bainput_diveCooldown = 0.0f;
}

void bainput_enable(s32 arg0, int arg1){
    if(arg1)
        bainput_enableMask |= (1 <<arg0);
    else
        bainput_enableMask &= ~(1 <<arg0);
}

void bainput_enable2(s32 arg0, s32 arg1, int arg2){
    bainput_enable(arg0, arg2);
    bainput_enable(arg1, arg2);
}

void bainput_setDiveCooldown(int arg0, f32 arg1){
    bainput_diveCooldown = arg1;
}

void bainput_update(void){
    if(bainput_diveCooldown != 0.0f){
       bainput_diveCooldown  = ml_max_f(bainput_diveCooldown - time_getDelta(), 0.0f);
    }
}
