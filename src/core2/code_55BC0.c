#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80328B8C(Actor *, s32, f32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCB50.s")

void func_802DCC78(ActorMarker this, s32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCC78.s")

void func_802DCC90(Actor *this){
    if(!this->unkF4_21){
        this->unkF4_21 = 1;
        this->unk124_9 = 0;
        actor_collisionOff(this);
        func_80328B8C(this, 1, 0.0f, 1);
        func_803298AC(this);
        func_803300D8(this->marker, func_802DCC78);
    }

    if(func_802878C4(this->movement)){
        func_80328B8C(this, 2, 0.0f, 1);
        func_803298D8(this);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCD34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCDB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCDC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCF20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DCFC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD60C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DD8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE4CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DE9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEA8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEAF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEB18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_55BC0/func_802DEB80.s")
