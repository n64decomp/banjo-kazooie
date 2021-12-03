#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80294404(void);

extern f32 D_80374CF0;
extern f64 D_80374CF8;
extern f64 D_80374D00;
extern f32 D_80374D08;

/*.bss*/
struct {
    u8 unk0;
    f32 unk4[3]; 
}
D_8037C6F0;

/*.code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_80299EC0.s")

void func_8029A47C(s32 arg0[3]){
    arg0[0] = (s32)(D_8037C6F0.unk4[0] + 0.5);
    arg0[1] = (s32)(D_8037C6F0.unk4[1] + 0.5);
    arg0[2] = (s32)(D_8037C6F0.unk4[2] + 0.5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_8029A4D0.s")

void func_8029A54C(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_12F30/func_8029A554.s")
