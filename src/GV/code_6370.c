#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8038CC98(Actor *this);
Actor *func_8038CC40(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
extern ActorInfo D_803911F4 = { 0xBB, 0x285, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_80391218 = { 0xBB, 0x286, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

extern ActorInfo D_8039123C = { 0xBB, 0x287, 0x3E6, 
    0, NULL,
    func_8038CC98, func_80326224, func_8038CC40,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};


/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_6370/func_8038C760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_6370/func_8038C880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_6370/func_8038C8A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_6370/func_8038CC40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/GV/code_6370/func_8038CC98.s")
