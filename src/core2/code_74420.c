#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 D_80369800[9] = {11.0f, 8.0f, 6.0f, 4.5f, 3.0f, 2.0f, -1.0f, -1.0f, 0.0f};
s32 D_80369824 = 0;

/* .bss */
struct8s * D_80381530[4];

f32 func_802FB3B0(struct8s* arg0){
    int i;
    f32 f2;
    f2 = 0.0f;
    for(i = 0; i < D_80369824; i++){
        if(arg0 == (D_80381530[i])){
            return f2;
        }
        f2 += 32.5;
    }
    return 0.0f;
}

void func_802FB414(void){
    int i = 0;
    D_80369824--;
    while(i < D_80369824){
        D_80381530[i] = D_80381530[i+1];
        i++;
    }
}

void func_802FB458(struct8s *arg0) {
    s32 var_v0;
    struct8s *sp20;

    for(var_v0 = 0; var_v0 < D_80369824; var_v0++){
        if (arg0 == D_80381530[var_v0]) {
            sp20 = D_80381530[0];
            func_802FB020(D_80381530[var_v0], 1);
            if ((var_v0 == 0) || ((player_movementGroup() != BSGROUP_A_FLYING)) || (func_802FDD0C(D_80381530[var_v0]) != ITEM_F_RED_FEATHER)) {
                sp20->unk10 = 3.0f;
            }
            if (sp20->unk18 == 0) {
                sp20->unk1C = 0.0f;
            }
            return;
        }
    }
    for(var_v0 = D_80369824; var_v0> 0; var_v0--) {
        D_80381530[var_v0] = D_80381530[var_v0-1];
    }
    D_80381530[0] = arg0;
    D_80369824++;
}

void func_802FB56C(s32 arg0, struct8s *arg1){
    func_802FB458(arg1);
}

void func_802FB590(s32 arg0, struct8s *arg1){
    func_802FB414();
}

void func_802FB5B4(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
    arg1->unk1C = 0.0f;
}

void func_802FB5C8(s32 arg0, struct8s *arg1){
    s32 tmp;
    struct8s *ptr = D_80381530[0];
    if(D_80369824){
        arg1->unkC = func_802FB3B0(arg1) + ptr->unk1C;
    }
}

void func_802FB61C(s32 arg0, struct8s *arg1){
    D_80369824 = 0;
}

void func_802FB630(void) {
    f32 temp_f0;
    struct8s *temp_s2;
    s32 var_s1;

    temp_s2 = D_80381530[0];
    if (D_80369824 != 0) {
        switch (temp_s2->unk0) {
        default:
            break;
        case 1:
            temp_f0 = D_80369800[temp_s2->unk18];
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
                    for(var_s1 = 1; var_s1 < D_80369824; var_s1++){
                        func_802FB5B4(1, D_80381530[var_s1]);
                        func_802FB020(D_80381530[var_s1], temp_s2->unk0);
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
                temp_f0 = D_80369800[temp_s2->unk18];
                temp_s2->unk1C -= temp_s2->unk14 * temp_f0;
            }
            break;
        }
        for(var_s1 = 1; var_s1 < D_80369824; var_s1++){
            if (temp_s2->unk0 == 2) {
                D_80381530[var_s1]->unk0 = temp_s2->unk0;
            }
        }
    }
}
