#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "bsint.h"

s32 D_8037D160; //prev_state
s32 D_8037D164; //state
s32 D_8037D168; //next_state
s32 currentInterrupt; 
s32 interruptResponse;

void bs_clearState(void) {
    D_8037D160 = 0;
    D_8037D164 = 0;
    D_8037D168 = 0;
}

void bs_setState(s32 state_id) {

    if (state_id == 0) {
        return;
    }
    
    D_8037D168 = state_id;
    if (bsList_getEndMethod(D_8037D164) != NULL) {
        bsList_getEndMethod(D_8037D164)();
    }

    
    D_8037D160 = D_8037D164;
    D_8037D164 = D_8037D168;
    D_8037D168 = 0;

    if (bsList_getInitMethod(D_8037D164) != NULL) {
        bsList_getInitMethod(D_8037D164)();
    }
}

s32 bs_getPrevState(void) {
    return D_8037D160;
}

s32 bs_getState(void) {
    return D_8037D164;
}

s32 bs_getNextState(void) {
    return D_8037D168;
}

void bs_updateState(void) {
    if (bsList_getUpdateMethod(D_8037D164) != NULL) {
        bsList_getUpdateMethod(D_8037D164)();
    }
}

s32 bs_checkInterrupt(enum bs_interrupt_e interruptId) {
    currentInterrupt = interruptId;
    interruptResponse = 0;

    if (bsList_getInterruptMethod(D_8037D164) != NULL) {
        bsList_getInterruptMethod(D_8037D164)();
    }

    return interruptResponse;
}

void bs_setInterruptResponse(s32 response) {
    interruptResponse = response;
}

enum bs_interrupt_e bs_getInterruptType(void) {
    return currentInterrupt;
}
