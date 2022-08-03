#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_80369830[];
extern s32 D_80369854;

struct8s *D_80381540[5];
s32 D_80381554;

/* .code */
f32 func_802FB8A0(struct8s * arg0){
    s32 i;
    f32 var_f0;
    f32 var_f2;

    var_f2 = 0.0f;
    var_f0 = 40.0f;
    for(i = 0; i < D_80369854; i++){
        if(arg0 == D_80381540[i]){
            return var_f2;
        }
        var_f2 += var_f0;
    }
    return 0.0f;
}

void func_802FB8F8(void){
    s32 i = 0;

    D_80369854--;
    while(i < D_80369854){
        D_80381540[i] = D_80381540[i + 1];
        i++;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74910/func_802FB93C.s")
#else
void func_802FB93C(struct8s *arg0) {
    void *sp18;
    s32 temp_a1;
    s32 temp_t9;
    s32 var_v1;
    void **var_v0;
    void **var_v0_2;
    void *temp_a0;
    struct8s *temp_t0;
    void *temp_v0;

    for(var_v1 = 0; var_v1 < D_80369854; var_v1++){
        if (arg0 == D_80381540[var_v1]) {
            func_802FB020(D_80381540[var_v1], 1);
            D_80381540[var_v1]->unk10 = 3.0f;
            if (D_80381540[var_v1]->unk18 == 0) {
                D_80381540[var_v1]->unk1C = 0.0f;
            }
        }
    }

    for(var_v1 = D_80369854; var_v1 > 0; var_v0--){
        D_80381540[var_v1] = D_80381540[var_v1 - 1];
        var_v1--;
    }

    D_80381540[0] = arg0;
    if ((temp_a1 != 0) && (func_802FDD0C(D_80381540[1]) == 0x2A)) {
        temp_t0 = D_80381540[1];
        D_80381540[1] = D_80381540[0];
        D_80381540[0] = temp_t0;
    }
    D_80369854++;
}
#endif

void func_802FBA54(s32 arg0, struct8s *arg1){
    func_802FB93C(arg1);
}

void func_802FBA78(s32 arg0, struct8s *arg1){
    func_802FB8F8();
}

void func_802FBA9C(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FBAB0(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0;

    var_v0 = D_80381540[0];
    if(D_80369854 != 0){
        arg1->unkC = func_802FB8A0(arg1) + var_v0->unk1C;
    }
}

void func_802FBB04(s32 arg0, struct8s *arg1){
    D_80369854 = 0;
}

void func_802FBB18(void) {
    struct8s *temp_s2;
    struct8s *var_s0;
    s32 var_s1;

    if (D_80369854 != 0) {
        temp_s2 = D_80381540[0];
        temp_s2->unk0 = 3;
        for(var_s1 = 1; var_s1 < D_80369854; var_s1++){
            func_802FBA9C(2, D_80381540[var_s1]);
            func_802FB020(D_80381540[var_s1], temp_s2->unk0);
        }
        D_80381554 = 1;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_74910/func_802FBBC0.s")
#else
void func_802FBBC0(void) {
    struct8s *sp1C;
    f32 temp_f0;
    struct8s *temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    var_a0 = D_80369854;
    sp1C = D_80381540;
    if(D_80369854 != 0){
        switch(sp1C->unk0){
            case 1:
                sp1C->unk1C += sp1C->unk14 * D_80369830[sp1C->unk18];
                if (D_80369830[sp1C->unk18] == 0.0) {
                    sp1C->unk0 = 2;
                    sp1C->unk10 = 3.0f;
                } else {
                    sp1C->unk18++;
                }
                break;

            case 2:
                sp1C->unk10 -= time_getDelta();
                if (sp1C->unk10 < 0.0f) {
                    func_802FBB18();
                }
                break;

            case 3:
                if (D_80381554 != 0) {
                    var_v1 = (sp1C->unk1C < -20.0f) ? TRUE : FALSE;
                } else {
                    var_v1 = (sp1C->unk18 == 0);
                }
                if (var_v1) {
                    D_80381554 = 0;
                    func_802FB020(sp1C, 0);
                } else {
                    temp_v0_3 = sp1C->unk18 - 1;
                    sp1C->unk18 = (temp_v0_3 < 0) ? 0 : temp_v0_3;
                    sp1C->unk1C -= sp1C->unk14 * D_80369830[sp1C->unk18];
                }
                break;
        }
    }

    for(var_v0 = 1; var_v0 < D_80369854; var_v0++){
        if (temp_a2->unk0 == 2) {
            D_80381540[var_v0]->unk0 = temp_a2->unk0;
        }
    }
}
#endif

void func_802FBDFC(void){}

bool func_802FBE04(void){
    struct8s * var_v1 = D_80381540[0];

    if(D_80369854 == 0){
        return FALSE;
    }
    
    return ((var_v1->unk0 == 1) || (var_v1->unk0 == 2));
}

bool func_802FBE48(void){
    return D_80369854 == 0;
}
