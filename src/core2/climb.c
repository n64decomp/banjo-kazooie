#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "bsint.h"

/* .bss */
f32 climbPoleBottom[3];
f32 climbPoleTop[3];
f32 climbRadius;
f32 D_8037C580[3];
f32 climbRegrabWaitTime;
u8  isClimbingBool;
u8  D_8037C591;

/* .code */
void climb_clear(void){
    ml_vec3f_clear(climbPoleBottom);
    ml_vec3f_clear(climbPoleTop);
    isClimbingBool = 0;
    climbRegrabWaitTime = 0.0f;
}

void climb_getBottom(f32 dst[3]){
    ml_vec3f_copy(dst, climbPoleBottom);
}

f32 climb_getBottomY(void){
    return climbPoleBottom[1];
}

f32 climb_getRadius(void){
    return climbRadius;
}

u8 func_8029825C(void){ //climb_2098250
    return D_8037C591;
}

f32 climb_getTopY(void){
    return climbPoleTop[1];
}

void climb_set(f32 bottom[3], f32 top[3], f32 radius, u32 arg3){
    if( !(climbRegrabWaitTime > 0.0f) || D_8037C580[0] != bottom[0]
       || D_8037C580[1] != bottom[1] || D_8037C580[2] != bottom[2])
    {
        ml_vec3f_copy(climbPoleBottom, bottom);
        ml_vec3f_copy(climbPoleTop, top);
        climbRadius = radius;
        D_8037C591 = arg3;
        isClimbingBool = 1;
    }
}

void climb_regrab_update(void){
    climbRegrabWaitTime = ml_max_f(climbRegrabWaitTime - time_getDelta(), 0.0f);
    if(isClimbingBool && ability_hasLearned(ABILITY_5_CLIMB)){
        bs_checkInterrupt(BS_INTR_C_CLIMB);
    }
    isClimbingBool = 0;
}

void climb_release(void){
    isClimbingBool = 0;
    ml_vec3f_copy(D_8037C580, climbPoleBottom);
    climbRegrabWaitTime = 0.6f;
}
