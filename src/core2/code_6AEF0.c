#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Mtx D_80380A18;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F1E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F1EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F1EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F1FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F283C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2EC0.s")

void func_802F2ED0(Struct64s *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Struct65s *phi_s0;
    f32 sp38[3];

    if (arg0 != NULL && arg0->unk4) {
        func_8024C764(sp38);
        mlMtxIdent();
        mlMtxRotPitch(-sp38[0]);
        mlMtxRotYaw(-sp38[1]);
        func_802513B0(&D_80380A18);
        for(phi_s0 = arg0->unk0; phi_s0 < arg0->unk0 + arg0->unk4; phi_s0++){
            if (phi_s0->unk23_0) {
                func_802F1FC0(phi_s0, gfx, mtx, vtx);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F2FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F32C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F35B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F35D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F35FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F363C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F36DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F373C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F379C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F38F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F39D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3AC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_6AEF0/func_802F3C84.s")
