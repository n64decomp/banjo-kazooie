#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"



//TODO replace with bsList Count
extern bsState D_8037C700[165];

void bsList_clearAll(void){
    s32 i = 0;
    do{
        bsList_setInitMethod(i, NULL);
        bsList_setUpdateMethod(i, NULL);
        bsList_setEndMethod(i, NULL);
        bsList_setInterruptMethod(i, NULL);
        i++;
    }while(i != 0xa6);
}

void bsList_setInitMethod(s32 i, bsStateMethod func){
    D_8037C700[i].init_func = func;
}

void bsList_setUpdateMethod(s32 i, bsStateMethod func){
    D_8037C700[i].update_func = func;
}

void bsList_setEndMethod(s32 i, bsStateMethod func){
    D_8037C700[i].end_func = func;
}

void bsList_setInterruptMethod(s32 i, bsStateMethod func){
    D_8037C700[i].interrupt_func = func;
}

bsStateMethod bsList_getInitMethod(s32 i){
    return D_8037C700[i].init_func;
}

bsStateMethod bsList_getUpdateMethod(s32 i){
    return D_8037C700[i].update_func;
}

bsStateMethod bsList_getEndMethod(s32 i){
    return D_8037C700[i].end_func;
}

bsStateMethod bsList_getInterruptMethod(s32 i){
    return D_8037C700[i].interrupt_func;
}