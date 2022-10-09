#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_core2_25E20_0{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u8 padE[2];
    u8 pad10[0xA];
    s16 unk1A;
};

typedef struct struct_core2_25E20_1{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0xA];
    s16 unk1A;
};

void func_80263840(void){}

void func_80263848(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_25E20/func_80263850.s")

void func_802639FC(struct struct_core2_25E20_1 *arg0, struct struct_core2_25E20_0 *arg1, u32 arg2) {
    u32 var_v0;
    s32 var_s4;
    u32 var_s6;
    s16 var_s5;
    s16 sp50;
    s32 sp4C;
    s32 sp48;
    u32 sp44;
    s32 sp40;
    s16 sp3E;

    if(arg2 == 0){
        arg1->unk0 = (s32) arg0->unk4;
        arg1->unkC = 0;
        arg1->unk4 = 0U;
        arg1->unk8 = 0U;
        return;
    }

    sp4C = arg0->unk8;
    sp3E = arg0->unk1A;
    sp44 = arg0->unkC;
    arg0->unk1A = 0;
    arg0->unkC = 0;
    arg0->unk8 = arg0->unk4;

    // var_v0 = 0;
    do{
        var_s4 = arg0->unk8;
        var_s5 = arg0->unk1A;
        var_s6 = arg0->unkC;
        func_80263850(arg0, &sp50);
        if(sp50 == 4){
            var_s4 = arg0->unk8;
            var_s5 = arg0->unk1A;
            var_s6 = arg0->unkC;
            break;
        }
        // var_v0 = arg0->unkC;
    }while(arg0->unkC < arg2);

    arg1->unk0 = var_s4;
    arg1->unkC = var_s5;
    arg1->unk4 = var_s6;
    arg1->unk8 = arg0->unkC;
    
    arg0->unk8 = sp4C;
    arg0->unk1A = sp3E;
    arg0->unkC = sp44;

//     var_v0 = 0;
// loop_3:


//     if (sp50 == 4) {

//     } else {
//         var_v0 = arg0->unkC;
//         if (var_v0 < arg2) {
//             goto loop_3;
//         }
//     }

}


void func_80263B1C(void){}

void func_80263B24(void){}
