#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8025108C(s32 arg0);

/* .bss */
s32 D_802827F0;

/* .code */
s32 func_80251060(void){
    return D_802827F0;
}

void func_8025106C(void){
    func_8025108C(0);
}

void func_8025108C(s32 arg0){
    D_802827F0 = arg0;
}
