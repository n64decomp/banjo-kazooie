#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern float D_8037D3B0;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA400.s")

void func_802AA460(void){
    enum bs_e state = bs_getNextState();
    if(!( state == BS_WONDERWING_IDLE
          || state == BS_WONDERWING_WALK
          || state ==  BS_WONDERWING_JUMP
          || state == BS_WONDERWING_EXIT
          || state == BS_WONDERWING_UNKA4
          || state == BS_WONDERWING_UNKA5
        )
    ){
        func_8029B0C0();
        func_8029E070(0);
        func_8025A55C(-1, 0xfa0, 0xd);
        func_8024BD08(1);
        func_8025A7DC(0x25);
    }  
    func_80289F10(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA58C.s")

void bsbwhirl_enter_init(void){
    func_8028A274(0x22, 0.5f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    D_8037D3B0 = 0.0f;
    func_8024BD08(0);
    func_8025A55C(0, 0xfa0, 0xd);
    func_8025A6EC(0x25, 0x6d60);
    func_80299BD4();
    func_802952A8(1,0);
}

void bsbwhirl_enter_update(void){
    enum bs_e sp1C = 0;
    func_802952A8(1,1);
    if(func_802878C4(player_getAnimCtrlPtr()))
        sp1C = BS_WONDERWING_IDLE;
    bs_setState(sp1C);
}

void bsbwhirl_enter_end(void){
    func_802952A8(1,1);
    func_802AA460();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA81C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA87C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AA97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAAC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAC44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AACF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AADBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bWhirl/func_802AAE4C.s")
