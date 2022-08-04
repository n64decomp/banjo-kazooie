#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "save.h"

/* .bss */
SaveData D_80383D20[4]; //save_data
s8 D_80383F00[4]; //gamenum to filenum
s32 D_80383F04;

/* .code */
int func_8033CD90(s32 filenum){
    int i;
    s32 tmp_v1;
    void *s2;
    s2 = &D_80383D20[filenum];
    i = 3;
    while(i != 0){
        tmp_v1 = func_8033CA2C(filenum, s2);
        if(!tmp_v1)
            break;
        i--;
    }
    if(tmp_v1)
        savedata_clear(s2);
    return tmp_v1;
}

void func_8033CE14(s32 gamenum){
    func_8033CD90(D_80383F00[gamenum]);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033CE40.s")
#else
void func_8033CE40(void) {
    s32 sp48[4];
    s32 var_s0;
    s32 var_s0_2;
    s32 i;

    sp48[3] = 0;
    D_80383F04 = -1;
    for(i = 0; i < 3; i++){
        D_80383F00[i] = -1;
        sp48[i] = 0;
    }
    for(var_s0 = 0; var_s0 < 4; var_s0++){
        if( (func_8033CD90(var_s0) == 0) 
            && (D_80383F00[D_80383D20[var_s0].unk1 - 1] == -1)) {
            D_80383F00[D_80383D20[var_s0].unk1 - 1] = var_s0;
            sp48[var_s0] = 1;
        } else {
            D_80383F04 = var_s0;
        }
    }
    for(i = 0; i < 3; i++){
        for(var_s0_2 = 0; (var_s0_2 < 4) && (D_80383F00[i] == -1);  var_s0_2++){
            if (sp48[var_s0_2] == 0) {
                sp48[var_s0_2] = 1;
                D_80383F00[i] = var_s0_2;
            }
        }
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033CFD4.s")
#else
int func_8033CFD4(s32 gamenum){
    s32 prev = D_80383F00[gamenum];
    s32 next = D_80383F04;
    u32 i;
    s32 tmp_s1;
    SaveData *tmp_s2;

    D_80383F00[gamenum] = next;
    bcopy(&D_80383D20[D_80383F00[prev]], &D_80383D20[next], 0x78);
    tmp_s2 = &D_80383D20[D_80383F04];
    tmp_s2->unk1 = gamenum + 1;
    savedata_update_crc(tmp_s2, 0x78);
    for(i = 3; i > 0; i--){//L8033D070
        tmp_s1 = func_8033CC98(next, tmp_s2);
        if(!tmp_s1){
            func_8033CE14(gamenum);
        }
        if(!tmp_s1)
            break;
    }
    if(!tmp_s1){
        for(i = 3; i > 0; i--){//L8033D070
            tmp_s1 = func_8033CCD0(prev);
            if(!tmp_s1)
                break;
        }
    }
    if(tmp_s1){
        D_80383F00[gamenum] = prev;
    }
    else{
        D_80383F04 = prev;
    }
    return tmp_s1;
}
#endif

void func_8033D0FC(s32 gamenum){
    s32 filenum = D_80383F00[gamenum];
    savedata_clear(&D_80383D20[filenum]);
}

void func_8033D13C(s32 gamenum){
    s32 filenum = D_80383F00[gamenum];
    saveData_load(&D_80383D20[filenum]);
}

void func_8033D17C(s32 gamenum){
    s32 filenum = D_80383F00[gamenum];
    saveData_create(&D_80383D20[filenum]);
}

bool func_8033D1BC(s32 gamenum){
    s32 filenum = D_80383F00[gamenum];
    return D_80383D20[filenum].unk0 != 0;
}

bool func_8033D1EC(void){
    int i;
    for(i = 0; i < 3; i++){
        if(func_8033D1BC(i))
            return TRUE;
    }
    return FALSE;
}
