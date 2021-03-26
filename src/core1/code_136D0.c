#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80363590;
extern u8 D_80379B90;
extern u8 D_80286F90;
extern u8 D_803863F0;
extern u8 D_F55960;
extern u8 D_1048560;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802510F0.s")

s32 func_80251170(void){return 0;}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802511C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_8025123C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_802512FC.s")

#if NONMATCHING
void func_80251308(void){
    func_802512FC();
    func_80253050(0, &D_80286F90, &D_803863F0, &D_F55960, &D_1048560, &D_80286F90, &D_80363590, &D_80363590, &D_80379B90, &D_80379B90, &D_803863F0);
    func_802511C4();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_136D0/func_80251308.s")
#endif

void func_802513A4(void){}