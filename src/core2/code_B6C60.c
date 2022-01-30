#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .rodata */
extern f64 D_80378F80;

/* .bss */
extern s32 D_80384470;

/* .code */
f32 func_8033DBF0(void){
    return (f32)D_80384470;
}

void func_8033DC04(void){
    D_80384470 = 0;
}

void func_8033DC10(void){}

void func_8033DC18(void){}

f32 func_8033DC20(void){
    f32 out;
    D_80384470 = func_8024BD94();
    out = D_80378F80*D_80384470;
    return out;
}
