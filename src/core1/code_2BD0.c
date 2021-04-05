#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_2BD0/func_802405F0.s")

extern OSMesg D_8027E0A8;
extern OSMesgQueue D_8027E0AC;
extern OSMesg D_8027E0C8[16];
extern OSMesgQueue D_8027E108;

void func_80240754(void){
    osCreateMesgQueue(&D_8027E0AC, &D_8027E0A8, 1);
    osCreateMesgQueue(&D_8027E108, &D_8027E0C8[0], 16);
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_8027E108, &D_8027E0C8[0], 16);
}
