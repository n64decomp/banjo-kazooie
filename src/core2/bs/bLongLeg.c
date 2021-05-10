#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_8037D361;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A51D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A524C.s")

int bslongleg_inSet(s32 move_indx){
    return (move_indx == BS_LONGLEG_IDLE)
    || (move_indx == BS_LONGLEG_WALK)
    || (move_indx == BS_LONGLEG_JUMP)
    || (move_indx == BS_LONGLEG_EXIT)
    || (move_indx == BS_LONGLEG_SLIDE)
    || (move_indx == 0x9b)
    || (move_indx == 0x62);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A531C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A54A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5548.s")

void bsblongleg_enter_init(void){
    D_8037D361 = func_8030D90C();
    func_8030DA80(D_8037D361, 0x2C);
    func_8030E04C(D_8037D361, 0.8f, 1.9f, 1.2f);
    func_802933FC(0xe);
    if(bsbtrot_inSet(bs_getPrevState()))
        func_802A54A8();
    else
        func_802A5548();
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_802A5374();
    func_80299BD4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A587C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A589C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A592C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5A90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A5E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A611C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A624C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6368.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A63F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A6478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A64A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bLongLeg/func_802A64E0.s")
