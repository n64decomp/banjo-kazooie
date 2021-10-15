#include <ultra64.h>
#include "functions.h"
#include "variables.h"

u8 D_8037C060;

u8 D_8037C062;

void func_80291488(s32 arg0);
void func_802C1B20(f32);


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290D48.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290E8C.s")
int func_80290E8C(void){
    if(func_8028EE84() != 2)
        return 0;

    func_802BD0D8(3);
    func_80291488(0xB);
    if( func_803348C0() == 0xB
        && player_getYPosition() < 1201.0f
    ){
        func_802C1B20(1100.0f);
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80290F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_8029103C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_8029105C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80291108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80291154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_802911E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80291268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_802912D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80291328.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9BD0/func_80291358.s")
/* camera update */
void func_80291358(void){
    func_8029E1A8(7);
    func_80290298();
    func_8029028C(0);
    switch(D_8037C062){
        case 0x9: //L802913A0
            if(func_80290D48())
                break;
            if(D_8037C060){
                func_80291488(1);
                func_802BD0D8(D_8037C060);
            }
            else{
                func_80291488(2);
            }
            break;
        case 0x1: //L802913E8
            func_80291108();
            break;
        case 0x7: //L802913F8
            func_80291268();
            break;
        case 0x8: //L80291408
            func_802912D0();
            break;

        case 0x4: //L80291418
        case 0xc: //L80291418
            func_802911E0();
            break;
        
        case 0xa: //L80291428
            func_80291328();
            break;

        default://80291438
            if(D_8037C060){
                func_80291488(1);
                func_802BD0D8(D_8037C060);
            }
            else{
                func_80291154();
            }
            break;
        
        case 0x5: //L8029146C
        case 0x6: //L8029146C
        case 0x0: //L8029146C
            break;
    }
}

s32 func_8029147C(void){
    return D_8037C062;
}

void func_80291488(s32 arg0){
    if(D_8037C062 == 0xa && arg0 != D_8037C062){
        func_8029028C(1);
    }
    D_8037C062 = arg0;
}

void func_802914CC(s32 arg0){
    D_8037C060 = arg0;
    if(D_8037C062 != 9 && D_8037C062 != 0xa){
        func_80291488(1);
        func_802BD0D8(arg0);
    }
}

void func_8029151C(s32 arg0){
    func_80291488(6);
    func_802BD0D8(arg0);
}

void func_80291548(void){
    D_8037C060 = 0;
    if(D_8037C062 != 9 && D_8037C062 != 0xa){
        func_80291488(2);
    }
}