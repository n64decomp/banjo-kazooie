#include "time.h"

#include "core1/vimgr.h"
#include "version.h"

/*.data*/
static f32 s_timeMultiplier = 1.0f;

/* .bss */
static f32 s_dTimeReal_sec;
static s32 s_dTimeReal_frames;

/* .code */
void time_reset(void){
    s_dTimeReal_sec = 0.01f;
    s_timeMultiplier = 1.0f;
    s_dTimeReal_frames = 0;
}

void time_setDeltaReal_sec(f32 d_seconds){
    if(d_seconds != 0.0f){
        s_dTimeReal_sec = MIN(d_seconds, VER_SELECT(0.05, 0.06, 0.05, 0.05));
    }
    else{
        s_dTimeReal_sec = 0.01f;
    }
}

void time_setDeltaReal_frames(s32 d_frames){
    s_dTimeReal_frames = MAX(MIN(0xf, d_frames) , 1);
    time_setDeltaReal_sec(s_dTimeReal_frames*(1.0/FRAMERATE));
}

s32 time_getDeltaReal_frames(void){
    return s_dTimeReal_frames;
}

f32 time_getDelta(void){
    return s_dTimeReal_sec*s_timeMultiplier;
}

f32 time_func_8033DDB8(void){
    return viMgr_func_8024BD94()*(1.0/FRAMERATE);
}

f32 time_getDelta_frames(void){
    return time_getDelta()*(FRAMERATE/2.0);
}

void time_setMultiplier(f32 multiplier){
    s_timeMultiplier = multiplier;
}
