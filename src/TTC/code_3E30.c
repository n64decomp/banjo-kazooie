#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 *unk0;
    u8 unk4[2];
    s16 unk6;
} struct_ttc_3e30_s;

extern s32 D_8038C980;

extern struct_ttc_3e30_s D_8038CA6C[];

extern u8 D_8038CF0C[] = "j4663n86pink";
extern u8 D_8038CF1C[] = "knip68n3664j";


extern struct{
    s32 unk0;
    s32 unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  padB[1];
    f32 unkC;
    s8  unk10;
} D_8038D720;

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A220.s")

void func_8038A23C();
#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A328.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038A7DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038AA2C.s")

void func_8038AB44(void){
    D_8038C980 = func_8038B600();
}

u32 func_8038AB68(s32 arg0){
    if(func_8031FF1C(0xAC + arg0)){
        return 1 << arg0;
    }
    return 0;
}

void func_8038ABA0(u32 arg0){
    int i;
    func_80356520(0xC2);
    if(arg0 & 0x400){
        func_80356560(0xC5);
    }
    func_803204E4(0x78, 0);
    for(i = 4; i < 0xb; i++){
        if( arg0 & (1 << i)){
            func_803204E4(0x93 + i, TRUE);
            func_803204E4(0x78, TRUE);
        }
        else{
            func_803204E4(0x93 + i, FALSE);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038AC48.s")

void func_8038AFC8(void){
    struct_ttc_3e30_s *iPtr;

    for(iPtr = D_8038CA6C; iPtr->unk0 != NULL; iPtr++){
        iPtr->unk6 = 0;
    }

    if(func_803203FC(2))
        strcpy(D_8038CA6C[0].unk0, D_8038CF0C);
    else
        strcpy(D_8038CA6C[0].unk0, D_8038CF1C);

    func_8038B5B4();
}

void func_8038B04C(void){
    if(D_8038D720.unk0){
        func_8038A258(0);
        func_8030DA44(D_8038D720.unk9);
        func_8030DA44(D_8038D720.unkA);
    }
}

void func_8038B094(void){
    void *sp2C;
    void *sp28;

    if( map_get() == MAP_7_TTC_TREASURE_TROVE_COVE
        && levelSpecificFlags_get(0x2)
    ){
        sp2C = func_8034C5AC(0x12C);
        if(sp2C){
            func_8034E71C(sp2C, -600, 0.0f);
        }
    }
    D_8038D720.unk0 = 0;
    if(map_get() != MAP_A_TTC_SANDCASTLE){
        func_8038AB44();
    }
    else{
        sp2C = func_8034C5AC(0x131);
        sp28 = func_8034C5AC(0x12C);
        if(levelSpecificFlags_get(5)){
            func_8034E71C(sp2C, -500, 10.0f);
            func_80324E38(0.0f, 3);
            func_80324E60(0.0f, 1);
            func_80324E88(2.0f);
            func_80324E38(2.0f, 0);
            func_803228D8();
            timedFunc_set_3(2.0f, (TFQM3) func_802E4078, MAP_7_TTC_TREASURE_TROVE_COVE, 1, 0);
        }
        else if(levelSpecificFlags_get(2) || func_803203FC(2)){
            func_8034E71C(sp2C, -500, 0.0f);
        }
        else{
            func_8034E71C(sp28, -500, 0.0f);
        }//L8038B1EC

        D_8038D720.unk0 = func_80309744(0);
        D_8038D720.unk4 = func_80309744(1);
        D_8038D720.unk8 = 0;
        D_8038D720.unk10 = 0;
        D_8038D720.unkC = 0.0f;

        D_8038D720.unk9 = func_8030D90C();
        func_8030DBB4(D_8038D720.unk9, 0.1f);
        func_8030DA80(D_8038D720.unk9, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(D_8038D720.unk9, 3);
        func_8030DABC(D_8038D720.unk9, 28000);

        D_8038D720.unkA = func_8030D90C();
        func_8030DA80(D_8038D720.unkA, SFX_3_DULL_CANNON_SHOT);
        func_8030DD14(D_8038D720.unkA, 3);
        func_8030DABC(D_8038D720.unkA, 0x7fff);
        func_8038A328();
        func_8038AFC8();

        if( jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE)
            && !func_803203FC(2)
        ){
            func_8033F120(D_8038D720.unk4, 0x3C, func_8038A23C, 0);
            D_8038D720.unk8 = 3;
        }//L8038B2CC
        func_8038AB44();
        func_8038B5B4();
    }//L8038B2E0
}

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B5B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038B800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038BB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038BBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038BD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/TTC/code_3E30/func_8038BF68.s")

int ttc_func_8038BF8C(void){
    return func_8038B600() == D_8038C980;
}
