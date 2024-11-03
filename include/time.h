#ifndef __GL_TIME_H__
#define __GL_TIME_H__

#include <ultra64.h>

void time_reset(void);
void time_setDeltaReal_sec(f32 d_seconds);
void time_setDeltaReal_frames(s32 d_frames);
s32 time_getDeltaReal_frames(void);
f32 time_getDelta(void);
f32 time_func_8033DDB8(void);
f32 time_getDelta_frames(void);
void time_setMultiplier(f32 multiplier);

#endif
