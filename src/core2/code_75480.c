#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern f32 D_80369890[];
extern s32 D_803698B4;
/* .bss */
struct8s *D_80381570[4];

/* .code */
f32 func_802FC410(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_803698B4; var_v0++){
        if (arg0 == D_80381570[var_v0]) {
            return var_f2;
        }
        var_f2 += 35.0f;
    }
    return 0.0f;
}

void func_802FC468(void){
    s32 i = 0;

    D_803698B4--;
    while(i < D_803698B4){
        D_80381570[i] = D_80381570[i + 1];
        i++;
    }
}

void func_802FC4AC(struct8s *arg0) {
    s32 var_v0;
    struct8s *sp20;

    for(var_v0 = 0; var_v0 < D_803698B4; var_v0++){
        if (arg0 == D_80381570[var_v0]) {
            sp20 = D_80381570[0];
            func_802FB020(D_80381570[var_v0], 1);
            sp20->unk10 = 3.0f;

            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }
    for(var_v0 = D_803698B4; var_v0> 0; var_v0--) {
        D_80381570[var_v0] = D_80381570[var_v0-1];
    }
    D_80381570[0] = arg0;
    D_803698B4++;
}

void func_802FC580(s32 arg0, struct8s * arg1){
    func_802FC4AC(arg1);
} 

void func_802FC5A4(s32 arg0, struct8s *arg1){
    func_802FC468();
}

void func_802FC5C8(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FC5DC(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0 = D_80381570[0];

    if(D_803698B4 != 0){
        arg1->unkC = func_802FC410(arg1) + var_v0->unk1C;
    }
}

void func_802FC630(s32 ag0, struct8s* arg1){
    D_803698B4 = 0;
}

void func_802FC644(void) {
    f32 temp_f0;
    struct8s *temp_s2;
    s32 var_s1;

    temp_s2 = D_80381570[0];
    if (D_803698B4) {
        switch (temp_s2->unk0) {
        default:
            break;

        case 1:
            temp_f0 = D_80369890[temp_s2->unk18];
            temp_s2->unk1C += temp_s2->unk14 * temp_f0;
            if (temp_f0 == 0.0) {
                temp_s2->unk10 = 3.0f;
                temp_s2->unk0 = 2;
            } else {
                temp_s2->unk18++;
            }
            break;

        case 2:
            if (getGameMode() != GAME_MODE_4_PAUSED) {
                temp_s2->unk10 -= time_getDelta();
                if (temp_s2->unk10 < 0.0f) {
                    temp_s2->unk0 = 3;
                    for(var_s1 = 1; var_s1 < D_803698B4; var_s1++){
                        func_802FC5C8(4, D_80381570[var_s1]);
                        func_802FB020(D_80381570[var_s1], temp_s2->unk0);
                    }
                }
            }
            break;

        case 3:
            if (temp_s2->unk1C < -20.0f) {
                func_802FB020(temp_s2, 0);
                break;
            } else {
                temp_s2->unk18 = MAX(0, temp_s2->unk18 - 1);
                temp_f0 = D_80369890[temp_s2->unk18];
                temp_s2->unk1C -= temp_s2->unk14 * temp_f0;
            }
            break;
        }
        
        for(var_s1 = 1; var_s1 < D_803698B4; var_s1++){
            if (temp_s2->unk0 == 2) {
                D_80381570[var_s1]->unk0 = temp_s2->unk0;
            }
        }
    }
}
