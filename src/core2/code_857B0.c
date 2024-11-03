#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
s32 D_80382460;

/* .code */
void func_8030C740(void){
    f32 sp1C[3];
    D_80382460 = 1;
    if(nodeprop_findPositionFromActorId(0x16, sp1C)){
        D_80382460 = 0;
    }
}

s32 func_8030C77C(void){
    return D_80382460;
}
