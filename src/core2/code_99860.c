#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define CORE2_99860_ARRAY_SIZE 0x33

/* .bss */
extern u8* D_80383220;

/* .code */
bool func_803207F0(s32 index){
    return func_803200A4(D_80383220, index);
}

void func_80320818(void){
    free(D_80383220);
    D_80383220 = NULL;
}

void func_80320840(void){
    int i;
    D_80383220 =(u8*) malloc(CORE2_99860_ARRAY_SIZE);
    for(i = 0; i < CORE2_99860_ARRAY_SIZE; i++){
        D_80383220[i] = 0;
    }
}

void func_803208C0(s32 index, bool value){
    func_8032015C(D_80383220, index, value);
}

void func_803208F0(void){
    if(D_80383220 != NULL)
        D_80383220 = defrag(D_80383220);
}
