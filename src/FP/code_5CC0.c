#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038C9A0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391F50[];

extern ActorInfo D_80391F88 = { 0x200, 0x332, 0x448,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FAC = { 0x201, 0x333, 0x449,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FD0 = { 0x202, 0x334, 0x44A,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391FF4 = { 0x203, 0x335, 0x44B,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    { 0x0, 0x0}, 0, 1.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C9A0.s")
