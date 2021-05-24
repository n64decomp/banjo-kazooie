#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8037DD90;
extern s32 D_8037DD94;
extern struct{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} D_8037DD98;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C83F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8580.s")

Actor *func_802C8A54(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    D_8037DD90 = 0xF;
    D_8037DD94 = 1;
    D_8037DD98.unk0 = 0xFA;
    D_8037DD98.unk4 = 0xFA;
    D_8037DD98.unk8 = 0xFA;
    D_8037DD98.unkC = 0x78;
    return func_802C8580(position, yaw, actorInfo, flags);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8BA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_41460/func_802C8EC0.s")
