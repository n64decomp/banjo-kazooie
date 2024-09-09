#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "enums.h"

/*.bss */
u8 gMiscFlags[0x1C];

/* code */
void miscFlag_clearAll(void){
    int i;
    for(i = 1; i < 0x1C; i++){
        miscFlag_clear(i);
    }
}

bool miscFlag_isTrue(enum misc_flag_e arg0){
    return gMiscFlags[arg0];
}

bool miscFlag_isFalse(enum misc_flag_e arg0){
    return !gMiscFlags[arg0];
}

void miscFlag_set(enum misc_flag_e arg0){
    gMiscFlags[arg0] = TRUE;
}

void miscFlag_clear(enum misc_flag_e arg0){
    gMiscFlags[arg0] = FALSE;
}

void miscFlag_toggle(enum misc_flag_e arg0){
    if(gMiscFlags[arg0]){
        gMiscFlags[arg0] = FALSE;
    }
    else {
        gMiscFlags[arg0] = TRUE;
    }
}
