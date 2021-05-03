#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"

typedef struct{
    u8 unk0;
    bsState behavior;
} struct_drone;

extern struct_drone D_80364B30[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/drOne/func_802AE370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/drOne/func_802AE3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/drOne/func_802AE410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/drOne/func_802AE450.s")

void func_802AE490(void){
    void (* tmp)(void) = D_80364B30[func_802AE370()].behavior.interrupt_func;
    if(tmp){
        tmp();
    }
}
