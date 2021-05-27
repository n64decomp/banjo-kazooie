#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_27_s{
    s16 unk0;
    u8 pad2[0x12];
}struct27s;

extern s16 * D_802758E0;

void func_80244C78(int arg0);

/* .code */
void func_80244AB0(void){
    int i;
    if(D_802758E0)
        return;

    D_802758E0 = (struct16s *) malloc(10*sizeof(s16));
    for(i = 0; i < 10; i++){
        D_802758E0[i] = 0;
    }
}

void func_80244B3C(void){
    int i;

    if(!D_802758E0)
        return;

    for(i = 0; i < 10; i++){
        if(D_802758E0[i])
            func_8030E394((u8)D_802758E0[i]);
    }
    free(D_802758E0);
    D_802758E0 = NULL;

}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_7090/func_80244BB0.s")

void func_80244C78(int arg0){
    if(D_802758E0[arg0]){
        func_8030DA44(D_802758E0[arg0]);
    }
    D_802758E0[arg0] = 0;
}