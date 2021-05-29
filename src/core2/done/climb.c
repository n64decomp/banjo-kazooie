#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80374A30;//timeBeforePoleRegrab 


extern f32 climbRadius;//climbRadius
extern f32 D_8037C580[3];
extern f32 D_8037C58C;
extern u8 D_8037C590; //bool climbing
extern u8 D_8037C591;

void climbClear(void){ //climbClear
    ml_vec3f_clear(&climbPoleBottom);
    ml_vec3f_clear(&climbPoleTop);
    D_8037C590 = 0;
    D_8037C58C = 0.0f;
    
}

void climbGetBottom(f32 (* dst)[3]){ //climbGetBottom
    ml_vec3f_copy(dst, &climbPoleBottom);
}

f32 climbGetBottomY(void){ //climbGetBottomY
    return climbPoleBottom[1];
}

f32 climbGetRadius(void){ //climbGetRadius
    return climbRadius;
}

u8 func_8029825C(void){ //climb_2098250
    return D_8037C591;
}

f32 climbGetTopY(void){ //climbGetTopY
    return climbPoleTop[1];
}

climbSet(f32 (* bottom)[3], f32(* top)[3], f32 radius, u32 arg3){
    if( !(D_8037C58C > 0.0f) || D_8037C580[0] != (*bottom)[0]
       || D_8037C580[1] != (*bottom)[1] || D_8037C580[2] != (*bottom)[2])
    {
        ml_vec3f_copy(&climbPoleBottom, bottom);
        ml_vec3f_copy(&climbPoleTop, top);
        climbRadius = radius;
        D_8037C591 = arg3;
        D_8037C590 = 1;
    }
}

void func_80298344(void){ //climbUpdateRegrab
    D_8037C58C = max_f(D_8037C58C - func_8033DD9C(), 0.0f);
    if(D_8037C590 &&  func_802957D8(5)){
        bs_checkInterrupt(0xC);
    }
    D_8037C590 = 0;
}

void climbRelease(void){ //climbRelease
    D_8037C590 = 0;
    ml_vec3f_copy(&D_8037C580, &climbPoleBottom);
    D_8037C58C = D_80374A30;
}
