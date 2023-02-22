#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct {
    f32 longleg_timer; //longleg_timer
    f32 turbo_timer; //turbotrot_timer
    u8  transformation; 
} bsStoredState;
u8 bsStoredStateInTrot; //in trot

/* .code */
void bsStoredState_debug(void){
    ability_debug();
}

void bsStoredState_clear(void){
    ability_clearAll();
    bsStoredState.longleg_timer = bsStoredState.turbo_timer = 0.0f;
    bsStoredState.transformation = TRANSFORM_1_BANJO;
    bsStoredStateInTrot = FALSE;
}

enum transformation_e bsStoredState_getTransformation(void){
    return bsStoredState.transformation;
}

f32 bsStoredState_getLongLegTimer(void){
    return bsStoredState.longleg_timer;
}

f32 bsStoredState_getTurboTimer(void){
    return bsStoredState.turbo_timer;
}

s32 bsStoredState_getTrotFlag(void){
    return bsStoredStateInTrot;
}

void bsStoredState_8029A924(void){}

void bsStoredState_clearTimers(void){
    bsStoredState_setLongLegTimer(0.0f);
    bsStoredState_setTurboTimer(0.0f);
}

void player_setTransformation(enum transformation_e xform_id){
    bsStoredState.transformation = xform_id;
}

void bsStoredState_setLongLegTimer(f32 arg0){
    bsStoredState.longleg_timer = arg0;
}

void bsStoredState_setTurboTimer(f32 arg0){
    bsStoredState.turbo_timer = arg0;
}

void bsStoredState_setTrot(bool arg0){
    bsStoredStateInTrot = arg0;
}
