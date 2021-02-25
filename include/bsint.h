#ifndef __BS_INT_H__
#define __BS_INT_H__

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef void (*bsStateMethod)(void);  

typedef struct bs_state_s{
    bsStateMethod init_func;
    bsStateMethod update_func;
    bsStateMethod end_func;
    bsStateMethod interrupt_func;
} bsState;

void bsList_clearAll(void);
void bsList_setInitMethod(s32 i, bsStateMethod func);
void bsList_setUpdateMethod(s32 i, bsStateMethod func);
void bsList_setEndMethod(s32 i, bsStateMethod func);
void bsList_setInterruptMethod(s32 i, bsStateMethod func);
bsStateMethod bsList_getInitMethod(s32 i);
bsStateMethod bsList_getUpdateMethod(s32 i);
bsStateMethod bsList_getEndMethod(s32 i);
bsStateMethod bsList_getInterruptMethod(s32 i);

void bs_clearState(void);
void bs_setState(s32 state_id);
s32 bs_getPrevState(void);
s32 bs_getState(void);
s32 bs_getNextState(void);
void bs_updateState(void);
s32 bs_checkInterrupt(s32 arg0);
void func_8029A86C(s32 arg0);
s32 bs_getInterruptType(void);
#endif