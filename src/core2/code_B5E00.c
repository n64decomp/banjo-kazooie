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

void func_8033CE40(void) {
    s32 i;
    s32 var_s0;
    s32 sp48[4];
    

    D_80383F04 = -1;
    sp48[3] = i = 0;
    if (sp48[3] < 3) {
        for(i = i; i < 3; i++) {
            D_80383F00[i] = -1;
            sp48[i] = 0;
            i++; i--; //do nothing
        }
    }
    // sp48[3] = 0;
    // D_80383F00[3] = -1;
    for(var_s0 = 0; var_s0 < 4; var_s0++){
        if( (func_8033CD90(var_s0) == 0) && (D_80383F00[D_80383D20[var_s0].unk1 - 1] == -1)) {
            D_80383F00[D_80383D20[var_s0].unk1 - 1] = var_s0;
            sp48[var_s0] = 1;
        } else {
            D_80383F04 = var_s0;
        }
    }
    sp48[D_80383F04] = 1;
    for(i = 0; i < 3; i++){
        for(var_s0 = 0; (var_s0 < 4) && (D_80383F00[i] == -1);  var_s0++){
            if (sp48[var_s0] == 0) {
                sp48[var_s0] = 1;
                D_80383F00[i] = var_s0;
            }
        }
    }
}

s32 func_8033CFD4(s32 gamenum){
    s32 next;
    s32 var_s3;
    u32 i = 3;
    s32 tmp_s1;
    SaveData *var_a1;


    var_s3 = D_80383F04;
    next = D_80383F00[gamenum];
    D_80383F00[gamenum] = D_80383F04;
    bcopy(&D_80383D20[next], &D_80383D20[var_s3], 0x78);
    var_a1 = D_80383D20 + var_s3;
    var_a1->unk1 = gamenum + 1;
    savedata_update_crc(var_a1, sizeof(SaveData));
    for(tmp_s1 = 1; tmp_s1 && i > 0; i--){//L8033D070
        tmp_s1 = func_8033CC98(var_s3, var_a1);
        if(!tmp_s1){
            func_8033CE14(gamenum);
        }
    }
    if(!tmp_s1){
        for(i = 3; i > 0; i--){//L8033D070
            tmp_s1 = func_8033CCD0(next);
            if(!tmp_s1)
                break;
        }
    }
    if(tmp_s1){
        D_80383F00[gamenum] = next;
    }
    else{
        D_80383F04 = next;
    }
    return tmp_s1;
}

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
