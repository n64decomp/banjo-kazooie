#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
u8 D_8037BFE0;
f32 D_8037BFE4;
f32 D_8037BFE8[5];

/* .code */
s32 func_8028FD30(void) {
    s32 i;
    s32 cnt;

    cnt = 0;
    for(i = 0; i < 5; i++){
        if(D_8037BFE8[i] != 0.0f){
            cnt++;
        }
    }
    return cnt;
}

bool func_8028FDC8(f32 arg0) {
    s32 i;

    for(i = 0; i < 5; i++){
        if(arg0 - 0.25 < D_8037BFE8[i]){
            D_8037BFE4 = arg0;
            return FALSE;
        }
    }
    for(i = 0; i < 5; i++){
        if (D_8037BFE8[i] == 0.0f) {
            D_8037BFE8[i] = arg0;
            return TRUE;
        }
    }
    D_8037BFE4 = arg0;
    return FALSE;
}

void func_8028FEF0(void) {
    s32 i;

    for(i = 0; i < 5; i++){
        D_8037BFE8[i] = 0.0f;
    }
    D_8037BFE0 = D_8037BFE4 = 0.0f;
}

void func_8028FFBC(bool arg0){
    D_8037BFE0 = arg0;
    if(!D_8037BFE0){
        func_8028FEF0();
    }
}

void func_8028FFF0(void) {
    f32 temp_f0;
    s32 i;

    if (D_8037BFE0 != 0) {
        for(i = 0; i < 5; i++){
            func_80259430(&D_8037BFE8[i]);
        }
        if (D_8037BFE4 != 0.0f) {
            temp_f0 = D_8037BFE4;
            D_8037BFE4 = 0.0f;
            func_8028FDC8(temp_f0);
        }
    }
}

