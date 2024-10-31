#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "enums.h"

/*.bss */
u8 BaFlags[0x1C];

/* code */
void baflag_clearAll(void){
    int i;
    for(i = 1; i < 0x1C; i++){
        baflag_clear(i);
    }
}

bool baflag_isTrue(enum misc_flag_e arg0){
    return BaFlags[arg0];
}

bool baflag_isFalse(enum misc_flag_e arg0){
    return !BaFlags[arg0];
}

void baflag_set(enum misc_flag_e arg0){
    BaFlags[arg0] = TRUE;
}

void baflag_clear(enum misc_flag_e arg0){
    BaFlags[arg0] = FALSE;
}

void baflag_toggle(enum misc_flag_e arg0){
    if(BaFlags[arg0]){
        BaFlags[arg0] = FALSE;
    }
    else {
        BaFlags[arg0] = TRUE;
    }
}
