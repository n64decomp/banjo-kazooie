#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DABA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAE40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DAFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB2AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB440.s")

void func_802DB4E0(ActorMarker *marker, s32 arg1){
    Actor * actor = marker_getActor(marker);
    func_80328B8C(actor, 9, 0.0f, 1);
    actor_playAnimationOnce(actor);
    actor_collisionOff(actor);
    actor->unk60 = randf2(3.0f, 6.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_53C10/func_802DB5A0.s")
