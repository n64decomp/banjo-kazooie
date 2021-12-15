#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8033DDEC(void);

extern f64 D_80379420;
extern f32 D_80379428;
//000F 2480: 40 6E A0 00 00 00 00 00  43 B3 80 00 00 00 00 00
//000F 2490: 407670 00 00 00 00 00  443680 00


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CBD10/func_80352CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CBD10/func_80352CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CBD10/func_80352D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_CBD10/func_80352DE4.s")

void func_80352F58(void){
    f32 *sp2C = func_8033E960();
    struct54s *sp28 = func_8033E8F4();
    u8 sp27 = func_8033E8D0();
    f32 sp20 = func_8033DDEC();
    if(func_80288034(sp28)){
        func_8033E984();
    }
    else{
        sp2C[0] += sp2C[1]*sp20;
        sp2C[2] = max_f(0.0f, sp2C[2] + sp2C[3]*sp20);
        func_80352CA0(sp27, sp2C);
    }
}

void func_80352FF4(void){}

void func_80352FFC(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3){
    f32 sp1C[3];
    func_802589E4(sp1C, arg1, arg2);
    sp1C[1] = arg3;
    func_80352CF4(arg0, sp1C, randf2(380.0f, 250.0f), 4.0f);
}

void func_80353064(f32 arg0[3], f32 arg1){
    f32 tmp_f22;
    arg0[1] += arg1;
    for(tmp_f22 = 0.0f; tmp_f22 < 359.0; tmp_f22 += 60.0){
        func_80352FFC(arg0, tmp_f22, 730.0f, 120.0f);
        func_80352FFC(arg0, mlNormalizeAngle(tmp_f22 + 30.0f), 470.0f, 60.0f);
    }
    arg0[1] -= arg1; 
}
