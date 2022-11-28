#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* .data */
f32 D_803698C0[] = {14.0f, 10.5f, 7.5f, 5.0f, 3.0f, 2.0f, -1.0f, -1.0f, 0.0f};
s32 D_803698E4 = 0;

/* .bss */
struct8s *D_80381580[4];

/* .code */
f32 func_802FC8C0(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_803698E4; var_v0++){
        if (arg0 == D_80381580[var_v0]) {
            return var_f2;
        }
        var_f2 += 48.0f;
    }
    return 0.0f;
}

void func_802FC918(void){
    s32 i = 0;

    D_803698E4--;
    while(i < D_803698E4){
        D_80381580[i] = D_80381580[i + 1];
        i++;
    }
}

void func_802FC95C(struct8s *arg0) {
    s32 var_v0;
    struct8s *sp20;

    for(var_v0 = 0; var_v0 < D_803698E4; var_v0++){
        if (arg0 == D_80381580[var_v0]) {
            sp20 = D_80381580[0];
            func_802FB020(D_80381580[var_v0], 1);
            sp20->unk10 = 3.0f;

            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }
    for(var_v0 = D_803698E4; var_v0> 0; var_v0--) {
        D_80381580[var_v0] = D_80381580[var_v0-1];
    }
    D_80381580[0] = arg0;
    D_803698E4++;
}

void func_802FCA30(s32 arg0, struct8s *arg1){
    func_802FC95C(arg1);
}

void func_802FCA54(s32 arg0, struct8s *arg1){
    func_802FC918();
}

void func_802FCA78(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FCA8C(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0 = D_80381580[0];

    if(D_803698E4 != 0){
        arg1->unkC = func_802FC8C0(arg1) + var_v0->unk1C;
    }
}

void func_802FCAE0(s32 arg0, struct8s *arg1){
    D_803698E4 = 0;
}

void func_802FCAF4(void) {
    f32 temp_f0;
    struct8s *temp_s2;
    s32 var_s1;

    temp_s2 = D_80381580[0];
    if (D_803698E4) {
        switch (temp_s2->unk0) {
        default:
            break;

        case 1:
            temp_f0 = D_803698C0[temp_s2->unk18];
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
                    for(var_s1 = 1; var_s1 < D_803698E4; var_s1++){
                        func_802FCA78(5, D_80381580[var_s1]);
                        func_802FB020(D_80381580[var_s1], temp_s2->unk0);
                    }
                }
            }
            break;

        case 3:
            if (temp_s2->unk18 == 0) {
                func_802FB020(temp_s2, 0);
                break;
            } else {
                temp_s2->unk18 = MAX(0, temp_s2->unk18 - 1);
                temp_f0 = D_803698C0[temp_s2->unk18];
                temp_s2->unk1C -= temp_s2->unk14 * temp_f0;
            }
            break;
        }
        
        for(var_s1 = 1; var_s1 < D_803698E4; var_s1++){
            if (temp_s2->unk0 == 2) {
                D_80381580[var_s1]->unk0 = temp_s2->unk0;
            }
        }
    }
}

void func_802FCD4C(void){}

bool func_802FCD54(void){
    struct8s *var_v1 = D_80381580[0];
    if(D_803698E4 == 0)
        return 0;

    return (var_v1->unk0 == 1 || var_v1->unk0 == 2);
}

bool func_802FCD98(struct8s *arg0) {
    s32 temp_v0;

    if (arg0->unk0 == 2) {
        return TRUE;
    }
    if (arg0->unk0 == 1) {
        temp_v0 = D_803698C0[arg0->unk18];
        return (temp_v0 == 0.0);
    }
    return 0;
}
