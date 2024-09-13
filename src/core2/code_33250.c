#include <ultra64.h>
#include "functions.h"
#include "variables.h"



void func_802BA23C(s32 *arg0, s32 arg1);

/* .code */
s32 * func_802BA1E0(void){
    s32 * sp1C = malloc(4);
    func_802BA23C(sp1C, 1);
    return sp1C;
}

void func_802BA214(s32 *arg0){
    free(arg0);
}

s32 func_802BA234(s32 *arg0){
    return *arg0;
}

void func_802BA23C(s32 *arg0, s32 arg1){
    *arg0 = arg1;
}

void func_802BA244(File *file_ptr, s32 *arg1){
    while(!file_isNextByteExpected(file_ptr, 0)){
        file_getWord_ifExpected(file_ptr, 1, arg1);
    }
}

