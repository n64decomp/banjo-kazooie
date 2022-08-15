#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void miscflag_clear(enum misc_flag_e arg0);

/*.bss */
u8 D_8037C1D0[0x1C];

/* code */
void miscflag_clearAll(void){
    int i;
    for(i = 1; i < 0x1C; i++){
        miscflag_clear(i);
    }
}

bool miscflag_isTrue(enum misc_flag_e arg0){
    return D_8037C1D0[arg0];
}

bool miscflag_isFalse(enum misc_flag_e arg0){
    return !D_8037C1D0[arg0];
}

void miscflag_set(enum misc_flag_e arg0){
    D_8037C1D0[arg0] = TRUE;
}

void miscflag_clear(enum misc_flag_e arg0){
    D_8037C1D0[arg0] = FALSE;
}

void miscflag_toggle(enum misc_flag_e arg0){
    if(D_8037C1D0[arg0]){
        D_8037C1D0[arg0] = FALSE;
    }
    else {
        D_8037C1D0[arg0] = TRUE;
    }
}
