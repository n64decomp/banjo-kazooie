#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* .bss */
struct54s D_80379BA0[40];

void func_80287A60(struct54s *arg0){
    arg0->unk4 += arg0->unk0[arg0->unkC_24].unk1*0.03333333333333333*arg0->unk8;
}

void func_80287ACC(struct54s *arg0){
    arg0->unk4 -= func_8033DD9C();
    while(arg0->unk4 <= 0.0f){
        arg0->unkC_24++;
        if(arg0->unkC_24 >= arg0->unkC_31)
            arg0->unkC_24 = 0;
        func_80287A60(arg0);
    }
}

void func_80287B84(struct54s *arg0){
    arg0->unk4 -= func_8033DD9C();
    while(arg0->unk4 <= 0.0f){
        arg0->unkC_24++;
        if(arg0->unkC_31 <= arg0->unkC_24){
            arg0->unkC_24--;
            arg0->unkC_3 = 3;
        }
        func_80287A60(arg0);
    }
}

void func_80287C58(void){
    int i;
    for(i = 0; i < 40; i++){
        D_80379BA0[i].unkC_0 = 0;
    }
}

struct54s * func_80287CA8(void){
    int i;
    for(i = 0; i < 40; i++){
        if(!D_80379BA0[i].unkC_0){
            D_80379BA0[i].unkC_0 = 1;
            D_80379BA0[i].unkC_24 = 0;
            D_80379BA0[i].unkC_3 = 0;
            D_80379BA0[i].unkC_31 = 1;
            D_80379BA0[i].unkC_17 = 0;
            D_80379BA0[i].unk0 = 0;
            D_80379BA0[i].unkC_1 = 1;
            D_80379BA0[i].unk4 = 0.0f;
            D_80379BA0[i].unk8 = 1.0f;
            D_80379BA0[i].unkC_10 = 0;
            return &D_80379BA0[i];
        }
    }
    return NULL;
}

void func_80287D60(struct54s *arg0){
    arg0->unkC_0 = 0;
}

void func_80287D70(void){
    int i;
    for(i = 0; i < 40; i++){
        if(D_80379BA0[i].unkC_0){
            func_80287D60(&D_80379BA0[i]);
        }
    }
}

void func_80287DC8(struct54s *arg0){
    switch(arg0->unkC_3){
        case 0:
            break;
        case 1:
            func_80287B84(arg0);
            arg0->unkC_10 = arg0->unk0[arg0->unkC_24].unk0;
            break;
        case 2:
            func_80287ACC(arg0);
            arg0->unkC_10 = arg0->unk0[arg0->unkC_24].unk0;
            break;
        case 3:
            break;
    }
}

void func_80287E9C(struct54s *arg0){
    arg0->unkC_24 = 0;
    arg0->unk4 = 0.0f;
    func_80287F50(arg0, 0, 1);
    func_80287FD0(arg0, 1.0f);
    func_80287FDC(arg0, 0);
    func_80287F7C(arg0, 2);
    func_80287F98(arg0, 1);
}

void func_80287F10(struct54s *arg0){
    arg0->unkC_24 = arg0->unkC_17;
    func_80287A60(arg0);
}

void func_80287F50(struct54s *arg0, struct53s *arg1, s32 arg2){
    arg0->unk0 = arg1;
    arg0->unkC_31 = arg2/2;
}

void func_80287F7C(struct54s *arg0, s32 arg1){
    arg0->unkC_3 = arg1;
}

void func_80287F98(struct54s *arg0, s32 arg1){
    arg0->unkC_1 = arg1;
}

void func_80287FB4(struct54s *arg0, s32 arg1){
    arg0->unkC_10 = arg1;
}

void func_80287FD0(struct54s *arg0, f32 arg1){
    arg0->unk8 = arg1;
}

void func_80287FDC(struct54s *arg0, s32 arg1){
    arg0->unkC_17 = arg1;
}

s32 func_80287FFC(struct54s *arg0){
    return arg0->unkC_10;
}

s32 func_8028800C(struct54s *arg0){
    return arg0->unkC_3;
}

s32 func_8028801C(struct54s *arg0){
    return arg0->unkC_1;
}

f32 func_8028802C(struct54s *arg0){
    return arg0->unk8;
}

int func_80288034(struct54s *arg0){
    return func_8028800C(arg0) == 3;
}

int func_80288058(struct54s *arg0, s32 arg1){
    return arg0->unkC_24 == arg1;
}