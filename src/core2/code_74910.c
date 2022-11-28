#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802FB020(struct8s *, s32);


f32 D_80369830[] = {14.0f, 10.5f, 7.5f, 5.0f, 3.0f, 2.0f, -1.0f, -1.0f, 0.0f};
s32 D_80369854 = 0;

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

void func_802FB93C(struct8s *arg0) {
    s32 var_v1;
    struct8s *sp20;


    for(var_v1 = 0; var_v1 < D_80369854; var_v1++){
        if (arg0 == D_80381540[var_v1]) {
            sp20 = D_80381540[0];
            func_802FB020(D_80381540[var_v1], 1);
            sp20->unk10 = 3.0f;
            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }

    for(var_v1 = D_80369854; var_v1 > 0; var_v1--){
        D_80381540[var_v1] = D_80381540[var_v1 - 1];
    }
    D_80381540[0] = arg0;

    
    if (D_80369854 && (func_802FDD0C(D_80381540[1]) == 0x2A)) {
        D_80381540[0] = D_80381540[1];
        D_80381540[1] = arg0;
    }
    D_80369854++;
}

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

void func_802FBBC0(void) {
    struct8s *sp1C;
    f32 temp_f0;
    s32 var_v0;
    bool var_v1;

    sp1C = D_80381540[0];
    if(D_80369854 != 0){
        switch(sp1C->unk0){
            default:
                break;
            case 1:
                temp_f0 = D_80369830[sp1C->unk18];
                sp1C->unk1C += sp1C->unk14 * temp_f0;
                if (temp_f0 == 0.0) {
                    sp1C->unk10 = 3.0f;
                    sp1C->unk0 = 2;
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
                var_v1 = (D_80381554 != 0) ? (sp1C->unk1C < -20.0f) : (!sp1C->unk18);
                if (var_v1) {
                    D_80381554 = 0;
                    func_802FB020(sp1C, 0);
                    break;
                }
                else{
                    sp1C->unk18 = MAX(0, sp1C->unk18 - 1);
                    temp_f0 = D_80369830[sp1C->unk18];
    
                    sp1C->unk1C -= sp1C->unk14 * temp_f0;
                }

                break;
        }
    
        for(var_v0 = 1; var_v0 < D_80369854; var_v0++){
            if (sp1C->unk0 == 2) {
                D_80381540[var_v0]->unk0 = sp1C->unk0;
            }
        }
    }    
}

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
