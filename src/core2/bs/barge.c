#include <ultra64.h>
#include "functions.h"
#include "variables.h"


f32 func_80297A7C(void);
void  func_80292864(f32, f32);

extern u8 D_8037D2A4;
extern u8 D_8037D2A6;

s32 func_8029F4E0(Actor * arg0){
    return arg0->unk138_31 == 0;
}

void func_8029F4F0(void){
    u8 val;
    f32 tmp_f;
    if(func_8029E1A8(2)){
        func_8029AE74(0);
        func_8029E3C0(2,0x3df5c28f);
    }
    if( (++D_8037D2A4) >= 3)
        D_8037D2A4 = 0;

    switch(D_8037D2A4){
        case 0:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f - 70.0f, 20.0f);
            break;
        case 1:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f - 10.0f, 20.0f);
            break;
        case 2:
            tmp_f = (func_80297A7C() + 180.0f);
            func_80292864(tmp_f + 50.0f, 20.0f);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/barge/func_8029F77C.s")

void func_8029FAE8(void){
    func_80295610(5);
    func_8029E070(0);
    D_8037D2A6 = 0;
}
