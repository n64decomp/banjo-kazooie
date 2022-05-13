#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0;
    f32 unk4;
}Struct_Core2_A600_0;

/* .bss */
Struct_Core2_A600_0 D_8037C0A0[8];

/* .code */
f32 func_80291670(s32 arg0){
    return D_8037C0A0[arg0].unk0;
}

f32 func_80291684(s32 arg0){
    return D_8037C0A0[arg0].unk4;
}

int func_80291698(s32 arg0){
    return D_8037C0A0[arg0].unk0 != 0.0f;
}

int func_802916CC(s32 arg0){
    return D_8037C0A0[arg0].unk0 == 0.0f;
}

int func_80291700(s32 arg0, f32 arg1){
    return (D_8037C0A0[arg0].unk0 < arg1) && (arg1 <= D_8037C0A0[arg0].unk4);
}

void func_8029175C(void){}

void func_80291764(void){
    int i;
    for(i = 0; i < 7; i++){
        D_8037C0A0[i].unk0 = 0.0f;
        D_8037C0A0[i].unk4 = 0.0f;
    }
}

void func_802917C4(s32 arg0){
    func_802917E4(arg0, 0.0f);
}

void func_802917E4(s32 arg0, f32 arg1){
    D_8037C0A0[arg0].unk0 = arg1;
    D_8037C0A0[arg0].unk4 = arg1;
}

void func_80291804(void){
    int i;
    f32 delta = time_getDelta();
    for(i = 0; i < 7; i++){
        D_8037C0A0[i].unk4 = D_8037C0A0[i].unk0;
        if(0.0f != D_8037C0A0[i].unk4){
            D_8037C0A0[i].unk0 -= delta;
            if(D_8037C0A0[i].unk0 < 0.0f){
                D_8037C0A0[i].unk0 = 0.0f;
            }
        }
    }
}
