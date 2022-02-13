#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_0/func_803863F0.s")

void func_80386468(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1 && map_get() == MAP_44_CCW_SUMMER) {
        func_803863F0(actor, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/CCW/code_0/func_803864B8.s")
