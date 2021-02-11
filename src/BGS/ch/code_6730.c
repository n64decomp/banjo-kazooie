#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void func_8038CEE8(void *);
void func_80325340(ActorMarker*, Gfx **, Mtx **);

ActorInfo D_80390AB0 = {0xC4, 0x136, 0x00, 0x00, NULL,
    func_8038CEE8, NULL, func_80325340,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

f32 D_80390AD4[3] = {1985.0f, 200.0f, -1386.0f};

void func_8038CB20(void){
    jiggySpawn(jiggy_bgs_flibbits, D_80390AD4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CC08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CEB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/ch/code_6730/func_8038CEE8.s")
