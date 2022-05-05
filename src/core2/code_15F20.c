#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8033DE30(s32);

/* .bss */
u8 D_8037D1F0[5];
f32 D_8037D1F8[5];

/* .code */
s32 func_8029CEB0(void){
    return func_802944F4();
}

f32 func_8029CED0(void) {
    s32 temp_v0;

    temp_v0 = func_8029CEB0();
    if (D_8037D1F0[temp_v0] != 0) {
        return D_8037D1F8[temp_v0];
    }
    return func_8033DE30(temp_v0);
}

bool func_8029CF20(s32 arg0) {
    return func_802944F4() == arg0;
}

void func_8029CF48(s32 arg0, s32 arg1, f32 arg2) {
    D_8037D1F0[arg0] = arg1;
    D_8037D1F8[arg0] = arg2;
}

void func_8029CF6C(void) {
    s32 i;

    for(i = 0; i < 5; i++){
        D_8037D1F0[i] = 0;
    }
}
