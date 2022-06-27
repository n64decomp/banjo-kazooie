#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 func_8033E8D0(void);

extern f32 D_803793F0;

/* .code */
void func_803525A0(f32 arg0[3]){
    u8 sp1F;
    u8 sp1E;
    f32 *sp18;
    if(func_8033E3F0(0x11, 1) >= 0){
        sp1E = func_8033E8D0();
        sp1F = func_8033E93C();
        sp18 = func_8033E960();
        func_8033FEC8(sp1E, arg0);
        func_80344D94(sp1F, arg0);
        sp18[1] = D_803793F0;
    }

}

void func_80352614(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_8035261C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CB610/func_803526DC.s")
