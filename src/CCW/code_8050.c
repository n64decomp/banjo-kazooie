#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_8050/func_8038E440.s")

void func_8038E4C0(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    
    func_80328B8C(actor, 5, 0.0f, 1);
    actor_playAnimationOnce(actor);
    func_8030E8B4(0x7FFF40C2, actor->position, 0x09C404E2);
    func_8038E440(partEmitList_pushNew(1U), actor, 0x52D);
    func_802C3F04(func_802C4140, 0x4C, reinterpret_cast(s32,actor->position_x), reinterpret_cast(s32,actor->position_y), reinterpret_cast(s32,actor->position_z));
    actor_collisionOff(actor);
    actor->unk138_24 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_8050/func_8038E56C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_8050/func_8038E868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_8050/func_8038E8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_8050/func_8038E964.s")
