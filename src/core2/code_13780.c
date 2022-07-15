#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "bsint.h"

s32 D_8037D160; //prev_state
s32 D_8037D164; //state
s32 D_8037D168; //next_state
s32 D_8037D16C; 
s32 D_8037D170;

void bs_clearState(void){
    D_8037D160 = 0;
    D_8037D164 = 0;
    D_8037D168 = 0;
}

void bs_setState(s32 state_id){

    if(state_id == 0)
        return;
    
    D_8037D168 = state_id;
    if(bsList_getEndMethod(D_8037D164) != NULL)
        bsList_getEndMethod(D_8037D164)();

    
    D_8037D160 = D_8037D164;
    D_8037D164 = D_8037D168;
    D_8037D168 = 0;

    if(bsList_getInitMethod(D_8037D164) != NULL)
        bsList_getInitMethod(D_8037D164)();
}

s32 bs_getPrevState(void){
    return D_8037D160;
}

s32 bs_getState(void){
    return D_8037D164;
}

s32 bs_getNextState(void){
    return D_8037D168;
}

void bs_updateState(void){
    if(bsList_getUpdateMethod(D_8037D164) != NULL)
        bsList_getUpdateMethod(D_8037D164)();
}

s32 bs_checkInterrupt(s32 arg0){
    D_8037D16C = arg0;
    D_8037D170 = 0;
    if(bsList_getInterruptMethod(D_8037D164) != NULL)
        bsList_getInterruptMethod(D_8037D164)();
    return D_8037D170;
}

void func_8029A86C(s32 arg0){
    D_8037D170 = arg0;
}

s32 bs_getInterruptType(void){
    return D_8037D16C;
}
