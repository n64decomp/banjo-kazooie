#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802FB020(struct8s *, s32);

f32 D_803697D0[] = { 
    21.0f, 17.0f, 13.0f, 10.0f, 7.0f, 
    5.0f, 3.0f, 2.0f, -1.0f, -1.0f
};

void func_802FB220(s32 arg0, struct8s *arg1){
    return;
}

void func_802FB22C(s32 arg0, struct8s *arg1){
    return;
}

void func_802FB238(s32 arg0, struct8s *arg1){
    arg1->unk18 = 0;
}

void func_802FB244(s32 arg0, struct8s *arg1){
    f32 tmp_f0;
    switch(arg1->unk0){
        case 1://L802FB27C
            tmp_f0 = D_803697D0[arg1->unk18];
            arg1->unkC = arg1->unkC + arg1->unk14*tmp_f0;
            if(0.0 == tmp_f0){
                arg1->unk10 = 3.0f;
                arg1->unk0 = 2;
            }
            else{
                arg1->unk18++;
            }
            break;
        case 2://L802FB2E4
            if(getGameMode() != GAME_MODE_4_PAUSED){
                arg1->unk10 -= time_getDelta();
                if(arg1->unk10 < 0.0f){
                    arg1->unk0 = 3;
                }
            }
            break;
        case 3://L802FB338
            if(arg1->unk18 == 0){
                func_802FB020(arg1, 0);
            }else{
                arg1->unk18--;
                tmp_f0 = D_803697D0[arg1->unk18];
                arg1->unkC = arg1->unkC - arg1->unk14*tmp_f0;
            }
            break;
    }
}

void func_802FB394(s32 arg0, struct8s *arg1){
    return;
}

void func_802FB3A0(void){}