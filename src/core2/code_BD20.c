#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 unk0;
    u8 unk4;
    u8 pad5[3];
} struct_BD20; 

/* .bss */
struct_BD20 D_8037C190[4];

/* .code */
f32 func_80292CB0(s32 arg0){
    switch (arg0) {
        case 0:
            return func_8029DFC8();
        case 1:
            return func_8029DFD4();
        case 2:
            return 0.0f;
        case 3:
            return 0.0f;
        default:
            return 0.0f;
    }
}


void func_80292D2C(s32 arg0, f32 arg1){
    switch(arg0){
        case 0:
            func_8029E0C4(arg1);
            break;
        case 1:
            func_8029E0D0(arg1);
            break;
        case 2:
            break;
        case 3:
        default:
            break;
    }
}

void func_80292D88(void){
    int i;
    for(i = 0; i < 4; i++){
        D_8037C190[i].unk0 = 1.0f;
        D_8037C190[i].unk4 = 0;
        func_80292D2C(i, 0.0f);
    }
}

void func_80292E00(s32 arg0, f32 arg1){
    D_8037C190[arg0].unk4 = 1;
    D_8037C190[arg0].unk0 = arg1;
}

void func_80292E24(s32 arg0, f32 arg1){
    D_8037C190[arg0].unk4 = 5;
    D_8037C190[arg0].unk0 = arg1;
}


void func_80292E48(void){
    func_80292E24(0, 0.09f);
    func_80292E24(1, 0.09f);
}

void func_80292E80(s32 arg0, f32 arg1){
    D_8037C190[arg0].unk4 = 4;
    D_8037C190[arg0].unk0 = arg1;
}

void func_80292EA4(void){
    func_80292E80(0, 0.034f);
    func_80292E80(1, 0.034f);
}

void func_80292EDC(void){
    f32 temp_f22;
    f32 temp_f0;
    int i;

    temp_f22 = func_8033DD9C();
    for(i = 0; i < 4; i++){
        temp_f0 = func_80292CB0(i);
        switch(D_8037C190[i].unk4){
            case 1://L80292F78
                temp_f0 += temp_f22/D_8037C190[i].unk0;
                if(1.0 < temp_f0){
                    temp_f0 = 1.0f;
                    D_8037C190[i].unk4 = 2;
                }
                func_80292D2C(i, temp_f0);
                break; 
            case 2://L80292FB4
                D_8037C190[i].unk4 = 3;
                break; 
            case 3://L80292FBC
            case 4://L80292FBC
                temp_f0 -= temp_f22/D_8037C190[i].unk0;
                if(temp_f0 < 0.0){
                    temp_f0 = 0.0f;
                    D_8037C190[i].unk4 = 0;
                }
                func_80292D2C(i, temp_f0);
                break; 
            case 5://L80292FF8
                temp_f0 += temp_f22/D_8037C190[i].unk0;
                if(1.0 < temp_f0){
                    temp_f0 = 1.0f;
                    D_8037C190[i].unk4 = 0;
                }
                func_80292D2C(i, temp_f0);
                break;
            case 0://L8029302C
            default://L8029302C
                break; 
        }
    }
}
