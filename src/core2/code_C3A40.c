#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .code */
f32 func_8034A9D0(f32 arg0[4], f32 arg1) {
    if (arg0[1] <= arg1) {
        return 0.0f;
    }
    if (arg0[0] <= arg1) {
        return (arg0[1] - arg1) / (arg0[1] - arg0[0]);
    }
    if (arg0[3] <= arg1) {
        return 1.0f;
    }
    if (arg0[2] <= arg1) {
        return (arg1 - arg0[2]) / (arg0[3] - arg0[2]);
    }
    return 0.0f;
}


void func_8034AA70(f32 arg0[4]){
    arg0[1] = 10000.0f;
    arg0[0] = 4000.0f;
    arg0[3] = 2000.0f;
    arg0[2] = -500.0f;
}
