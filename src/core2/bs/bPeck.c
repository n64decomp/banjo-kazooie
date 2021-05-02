#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80292048(s32, f32, f32, f32);

extern f32 D_80364A60;
extern f32 D_80364A64;

extern u8 D_8037D374;
extern u8 D_8037D375;
extern u8 D_8037D376;
extern u8 D_8037D377;

s32 func_802A6510(void){
    return D_8037D376;
}

void bsbpeck_init(void){
    D_8037D377 = 0;
    switch(bs_getPrevState()){
        case BS_BTROT_JUMP://L802A656C
            D_8037D377++;
            break;
        case BS_JUMP:
        case BS_FALL:
        case BS_FALL_TUMBLING:
        case BS_BOMB_END:
            break;
    }
    if(func_80293234() == 1)
        func_80293240(2);

    func_8028A274(0x1a, 0.2f);
    func_8029C7F4(1,3,1,6);
    func_80299234(1200.0f, 10.0f);
    func_8029E070(1);
    func_80297BEC(D_80364A60);
    func_802979A0(D_80364A64);
    func_80292048(1, -38.0f, 0.0f, 105.0f);
    func_80292048(0, -38.0f, 0.0f, -7.0f);
    func_8028D638(0x23, 0x2A);
    D_8037D375 = 0;
    D_8037D374 = 0;
    D_8037D376 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bPeck/func_802A664C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bPeck/func_802A66F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bPeck/func_802A6928.s")
