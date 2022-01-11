#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "save.h"

extern SaveData D_80383D20[4]; //save_data
extern s8 D_80383F00[4]; //gamenum to filenum
extern s32 D_80383F04;

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033CE40.s")

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
    func_8033BFD0(tmp_s2, 0x78);
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

int func_8033D1BC(s32 gamenum){
    s32 filenum = D_80383F00[gamenum];
    return D_80383D20[filenum].unk0 != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D1EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D2A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D2F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D5A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B5E00/func_8033D5B4.s")
