#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3BB0.s")

void func_802B3CCC(void){ 
    func_8029E070(0);
}

void func_802B3CEC(void){ 
    s32 tmp1;
    s32 tmp2;
    
    func_8029BE10(&tmp1, &tmp2);
    func_802B3AAC(tmp1, tmp2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3D1C.s")

void func_802B3D6C(void){ 
    func_802B3CCC();
}

void func_802B3D8C(void){ 
    s32 tmp1;
    s32 tmp2;
    
    func_8029BF00(&tmp1, &tmp2);
    func_802B3AAC(tmp1, tmp2);
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3DBC.s")

void func_802B3E0C(void){ 
    func_802B3CCC();
}

void func_802B3E2C(void){ 
    s32 tmp1;
    s32 tmp2;
    
    func_8029BE88(&tmp1, &tmp2);
    func_802B3AAC(tmp1, tmp2);
    func_8029C674();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bsRest/func_802B3E64.s")

void func_802B3EF4(void){
    func_802B3CCC();
    func_8029C748();
}
