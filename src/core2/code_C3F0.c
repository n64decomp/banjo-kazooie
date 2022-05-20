#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802933FC(s32 arg0);

/*.bss */
u8 D_8037C1D0[0x1C];

/* code */
void func_80293380(void){
    int i;
    for(i = 1; i < 0x1C; i++){
        func_802933FC(i);
    }
}

int func_802933C0(s32 arg0){
    return D_8037C1D0[arg0];
}

int func_802933D0(s32 arg0){
    return !D_8037C1D0[arg0];
}

void func_802933E8(s32 arg0){
    D_8037C1D0[arg0] = TRUE;
}

void func_802933FC(s32 arg0){
    D_8037C1D0[arg0] = FALSE;
}

void func_8029340C(s32 arg0){
    if(D_8037C1D0[arg0]){
        D_8037C1D0[arg0] = FALSE;
    }
    else {
        D_8037C1D0[arg0] = TRUE;
    }
}
