#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern struct {
    f32 unk0[0x8];
    f32 unk20[0x8];
} D_8037D250;

void func_8029E180(s32 arg0, f32 arg1){
    D_8037D250.unk20[arg0] = D_8037D250.unk0[arg0];
    D_8037D250.unk0[arg0] += arg1;
}

int func_8029E1A8(s32 arg0){
    D_8037D250.unk20[arg0] = D_8037D250.unk0[arg0];
    if(0.0f == D_8037D250.unk0[arg0]){
        return 0;
    }
    D_8037D250.unk0[arg0] = max_f(0.0f, D_8037D250.unk0[arg0] - func_8033DD9C());
    return D_8037D250.unk0[arg0] == 0.0f;
}

void func_8029E22C(s32 arg0){
    D_8037D250.unk20[arg0] = D_8037D250.unk0[arg0];
    D_8037D250.unk0[arg0] += func_8033DD9C();
}

f32 func_8029E270(s32 arg0){
    return D_8037D250.unk0[arg0];
}

int func_8029E284(s32 arg0, f32 arg1){
    return D_8037D250.unk20[arg0] <= arg1 
        && arg1 < D_8037D250.unk0[arg0];
}

int func_8029E2E0(s32 arg0, f32 arg1){
    return D_8037D250.unk0[arg0] < arg1;
}

int func_8029E314(s32 arg0, f32 arg1){
    return arg1 < D_8037D250.unk0[arg0];
}

int func_8029E348(s32 arg0){
    return (0.0 != D_8037D250.unk0[arg0]);
}

int func_8029E384(s32 arg0){
    return (0.0 == D_8037D250.unk0[arg0]);
}

void func_8029E3C0(s32 arg0, f32 arg1){
    D_8037D250.unk20[arg0] = arg1;
    D_8037D250.unk0[arg0] = arg1;
}