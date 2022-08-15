#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"



//TODO replace with bsList Count
bsState D_8037C700[166];

/* .code */
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

void bsList_setInitMethod(enum bs_e i, bsStateMethod func){
    D_8037C700[i].init_func = func;
}

void bsList_setUpdateMethod(enum bs_e i, bsStateMethod func){
    D_8037C700[i].update_func = func;
}

void bsList_setEndMethod(enum bs_e i, bsStateMethod func){
    D_8037C700[i].end_func = func;
}

void bsList_setInterruptMethod(enum bs_e i, bsStateMethod func){
    D_8037C700[i].interrupt_func = func;
}

bsStateMethod bsList_getInitMethod(enum bs_e i){
    return D_8037C700[i].init_func;
}

bsStateMethod bsList_getUpdateMethod(enum bs_e i){
    return D_8037C700[i].update_func;
}

bsStateMethod bsList_getEndMethod(enum bs_e i){
    return D_8037C700[i].end_func;
}

bsStateMethod bsList_getInterruptMethod(enum bs_e i){
    return D_8037C700[i].interrupt_func;
}
