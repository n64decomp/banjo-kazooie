#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_530/func_80386920.s")

void func_80386AD0(ActorMarker *arg0, s32 arg1) {
    marker_getActor(arg0)->CC_530.unk1 = 1;
}

void func_80386AF8(Actor *arg0) {
    func_80386920(arg0, 0);
    func_8030DA44(arg0->CC_530.unk0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/CC/code_530/func_80386B28.s")
