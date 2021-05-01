#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802915CC(f32);

extern u8 D_8037D3C0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/claw/func_802AB280.s")

void bsclaw_init(void){
    func_8028A180(5, 1.3f);
    func_8029C7F4(1,1,3,3);
    func_8029797C(player_getMovingYaw());
    func_80297970(160.0f);
    func_802915CC(80.0f);
    D_8037D3C0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/claw/func_802AB2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/claw/func_802AB58C.s")
