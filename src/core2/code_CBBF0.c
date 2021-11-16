#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef void (*funcPtr)(void);

typedef struct{
    void (*unk0)(void);
    s32 unk4;
    funcPtr unk8;
    s32 unkC;
    s32 unk10;
}Struct_Core2_CBBF0_0;

void func_80352BD4(s32 arg0, funcPtr arg1, s32 arg2, funcPtr arg3, s32 arg4, s32 arg5);

/* .bss */
extern Struct_Core2_CBBF0_0 D_80386260[];


/* .code */
void func_80352B80(void){
    int i;
    for(i = 1; i < 0x12; i++){
        func_80352BD4(i, 0, 0, 0, 0, 0);
    }
}

void func_80352BD4(s32 arg0, funcPtr arg1, s32 arg2, funcPtr arg3, s32 arg4, s32 arg5){
    D_80386260[arg0].unk0 = arg1;
    D_80386260[arg0].unk4 = arg2;
    D_80386260[arg0].unk8 = arg3;
    D_80386260[arg0].unkC = arg4;
    D_80386260[arg0].unk10 = arg5;
}

funcPtr func_80352C0C(s32 arg0)
{
    return D_80386260[arg0].unk0;
}

s32 func_80352C28(s32 arg0){
    return D_80386260[arg0].unk4;
}

funcPtr func_80352C44(s32 arg0){
    return D_80386260[arg0].unk8;
}

s32 func_80352C60(s32 arg0){
    return D_80386260[arg0].unkC;
}

s32 func_80352C7C(s32 arg0){
    return D_80386260[arg0].unk10;
}
