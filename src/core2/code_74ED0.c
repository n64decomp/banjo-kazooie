#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern s32 D_80369884;

/* .bss */
struct8s *D_80381560[3];
s32 D_8038156C;

/* .code */
f32 func_802FBE60(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_80369884; var_v0++){
        if (arg0 == D_80381560[var_v0]) {
            return var_f2;
        }
        var_f2 += 40.0f;
    }
    return 0.0f;
}

void func_802FBEB8(void){
    s32 i = 0;

    D_80369884--;
    while(i < D_80369884){
        D_80381560[i] = D_80381560[i + 1];
        i++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74ED0/func_802FBEFC.s")

void func_802FC014(s32 arg0, struct8s * arg1){
    func_802FBEFC(arg1);
} 

void func_802FC038(s32 arg0, struct8s * arg1){
    func_802FBEB8();
} 

void func_802FC05C(s32 arg0, struct8s * arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
} 

void func_802FC070(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0;

    var_v0 = D_80381560[0];
    if(D_80369884 != 0){
        arg1->unkC = func_802FBE60(arg1) + var_v0->unk1C;
    }
}

void func_802FC0C4(s32 arg0, struct8s *arg1){
    D_80369884 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74ED0/func_802FC0D8.s")

bool func_802FC390(void){
    s32 *phi_v1 = D_80381560[0];
    if (D_80369884 == 0)
        return FALSE; 
    return *phi_v1 == 2;
}

bool func_802FC3C4(void){
    if (D_80369884 == 0)
        return FALSE; 
    return (func_802FDD0C(D_80381560[D_80369884 - 1]) == 0xE);
}
