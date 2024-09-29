#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 s_active;
f32 s_flap_max_timer;
f32 s_flap_list[5];

/* .code */

/**
 * @brief returns the number of nonzero flap timers in `s_flap_list`
 * 
 * @return s32 number of active flaps
 */
s32 baflap_getCount(void) {
    s32 i;
    s32 cnt;

    cnt = 0;
    for(i = 0; i < 5; i++){
        if(s_flap_list[i] != 0.0f){
            cnt++;
        }
    }
    return cnt;
}

/**
 * @brief add a flap duration to the flap list
 * 
 * @param duration duration of flap in seconds
 * @return true if baflap duration was extended
 * @return false if baflap does not extend duration or all timers in flap queue are occupied
 */
bool baflap_add(f32 duration) {
    s32 i;

    // check that timer is far enough away from any value
    for(i = 0; i < 5; i++){
        if(duration - 0.25 < s_flap_list[i]){
            s_flap_max_timer = duration;
            return FALSE;
        }
    }
    // add to list
    for(i = 0; i < 5; i++){
        if (s_flap_list[i] == 0.0f) {
            s_flap_list[i] = duration;
            return TRUE;
        }
    }
    s_flap_max_timer = duration;
    return FALSE;
}

/**
 * @brief zeros all flap timers and sets as inactive
 * 
 */
void baflap_reset(void) {
    s32 i;

    for(i = 0; i < 5; i++){
        s_flap_list[i] = 0.0f;
    }
    s_active = s_flap_max_timer = 0.0f;
}

/**
 * @brief activates or deactivates flap timers
 * 
 * @param active false (0) or true (!0)
 */
void baflap_activate(bool active){
    s_active = active;
    if(!s_active){
        baflap_reset();
    }
}

/**
 * @brief updates flap timers if active
 * 
 */
void baflap_update(void) {
    f32 temp_f0;
    s32 i;

    if (s_active != 0) {
        //update timers
        for(i = 0; i < 5; i++){
            func_80259430(&s_flap_list[i]);
        }
        if (s_flap_max_timer != 0.0f) {
            temp_f0 = s_flap_max_timer;
            s_flap_max_timer = 0.0f;
            baflap_add(temp_f0);
        }
    }
}

