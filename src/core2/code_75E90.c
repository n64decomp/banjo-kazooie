#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
extern f32 D_803698F0[];
extern s32 D_80369914;

/* .bss */
struct8s *D_80381590[4];

/* .code */
f32 func_802FCE20(struct8s * arg0) {
    f32 var_f2;
    s32 var_v0;

    var_f2 = 0.0f;
    for(var_v0 = 0; var_v0 < D_80369914; var_v0++){
        if (arg0 == D_80381590[var_v0]) {
            return var_f2;
        }
        var_f2 += 40.0;
    }
    return 0.0f;
}

void func_802FCE88(void){
    s32 i = 0;

    D_80369914--;
    while(i < D_80369914){
        D_80381590[i] = D_80381590[i + 1];
        i++;
    }
}

void func_802FCECC(struct8s *arg0) {
    s32 var_v0;
    struct8s *sp20;

    for(var_v0 = 0; var_v0 < D_80369914; var_v0++){
        if (arg0 == D_80381590[var_v0]) {
            sp20 = D_80381590[0];
            func_802FB020(D_80381590[var_v0], 1);
            sp20->unk10 = 3.0f;

            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }
    for(var_v0 = D_80369914; var_v0> 0; var_v0--) {
        D_80381590[var_v0] = D_80381590[var_v0-1];
    }
    D_80381590[0] = arg0;
    D_80369914++;
}

void func_802FCFA0(s32 arg0, struct8s *arg1){
    func_802FCECC(arg1);
}

void func_802FCFC4(s32 arg0, struct8s *arg1){
    func_802FCE88();
}

void func_802FCFE8(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FCFFC(s32 arg0, struct8s *arg1){
    s32 sp1C;
    struct8s *var_v0 = D_80381590[0];

    if(D_80369914 != 0){
        arg1->unkC = func_802FCE20(arg1) + var_v0->unk1C;
    }
}

void func_802FD050(s32 arg0, struct8s *arg1){
    D_80369914 = 0;
}

void func_802FD064(void) {
    f32 temp_f0;
    struct8s *temp_s2;
    s32 var_s1;

    temp_s2 = D_80381590[0];
    if (D_80369914 == 0)
        return;

    switch (temp_s2->unk0) {
        case 1:
            temp_f0 = D_803698F0[temp_s2->unk18];
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
                    for(var_s1 = 1; var_s1 < D_80369914; var_s1++){
                        func_802FCFE8(6, D_80381590[var_s1]);
                        func_802FB020(D_80381590[var_s1], temp_s2->unk0);
                    }
                }
            }
            break;

        case 3:
            if (temp_s2->unk1C < -20.0f) {
                func_802FB020(temp_s2, 0);
                break;
            } else {
                temp_s2->unk18 = (temp_s2->unk18 - 1 < 0) ? 0 : temp_s2->unk18 - 1;
                temp_f0 = D_803698F0[temp_s2->unk18];
                temp_s2->unk1C -=  temp_s2->unk14 * temp_f0;
            }
            break;
    }
    for(var_s1 = 1; var_s1 < D_80369914; var_s1++){
        if(temp_s2->unk0 == 2){
            D_80381590[var_s1]->unk0 = temp_s2->unk0;
        }
    }
}

int func_802FD2D4(void){
    if(!D_80369914)
        return 0;
    return func_802FDD0C(D_80381590[D_80369914 - 1]) == 0x1A;
}
