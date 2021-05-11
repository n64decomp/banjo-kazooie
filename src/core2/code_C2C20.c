#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct demo_file_header{
    u8 pad0[0x4];
} DemoFileHeader;

extern DemoFileHeader * D_803860D4; //demo_inputs_ptr

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_80349FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/func_8034A054.s")

void demo_load(enum MAP_E map, s32 demo_id){
    if(D_803860D4)
        demo_free();
    D_803860D4 = assetcache_get(0x504 + func_8030AD48(map) + demo_id*0xD);
    func_80349FB0(D_803860D4 + 1, func_8033B678() - sizeof(DemoFileHeader), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_C2C20/demo_free.s")
