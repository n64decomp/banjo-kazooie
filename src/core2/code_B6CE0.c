#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/*.data*/
f32 D_80371E20 = 1.0f;

/* .bss */
extern f32 D_80384480;
extern s32 D_80384484;

/* .code */
void func_8033DC70(void){
    D_80384480 = 0.01f;
    D_80371E20 = 1.0f;
    D_80384484 = 0;
}

void func_8033DC9C(f32 arg0){
    if(arg0 != 0.0f){
        D_80384480 = MIN(arg0, 0.05);
    }
    else{
        D_80384480 = 0.01f;
    }
}

void func_8033DD04(s32 arg0){
    D_80384484 = MAX(MIN(0xf, arg0) , 1);
    func_8033DC9C(D_80384484*(1/60.0));
}

s32 func_8033DD90(void){
    return D_80384484;
}

f32 time_getDelta(void){
    return D_80384480*D_80371E20;
}

f32 func_8033DDB8(void){
    return func_8024BD94()*(1/60.0);
}

f32 func_8033DDEC(void){
    return time_getDelta()*30.0;
}

void func_8033DE20(f32 arg0){
    D_80371E20 = arg0;
}
