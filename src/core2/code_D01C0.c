#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8035765C(Actor *this);

/* .data */
extern ActorInfo D_80372870 = { 
    0x1B2, ACTOR_29F_CLUCKER, ASSET_482_MODEL_CLUCKER, 
    0, NULL, 
    func_8035765C, NULL, func_803575B8,
    { 0x0, 0x0, 0x0, 0x0}, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_80357150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_80357264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_80357564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_8035758C.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_803575B8.s")
Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(3, (this->state == 5) ? 0 : 1);
    func_8033A45C(4, (this->state == 0 || this->state == 1 || this->state == 6)? 0 : 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_D01C0/func_8035765C.s")
