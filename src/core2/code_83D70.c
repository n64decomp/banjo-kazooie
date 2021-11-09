#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct map_info{
    s16 map_id;
    s16 level_id;
    u8* name;
}MapInfo;

extern u8 D_80378430[];
extern u8 D_80378434[];

extern u8 D_803823A0[];

MapInfo * func_8030AD00(enum map_e map);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AD00.s")

enum level_e map_getLevel(enum map_e map){
    return func_8030AD00(map)->level_id;
};

/* returns string containing the map name and index */
u8 *func_8030AD6C(enum map_e map){
    MapInfo *map_info = func_8030AD00(map);
    D_803823A0[0] = 0;
    strcat(D_803823A0, map_info->name);
    strcat(D_803823A0, D_80378430);
    strIToA(D_803823A0, map);
    strcat(D_803823A0, D_80378434);
    return D_803823A0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030ADD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AF58.s")

void func_8030AFA0(enum map_e arg0){
    s32 level = map_getLevel(arg0);
    if(level > 0 && level < LEVEL_C_BOSS){
        func_80332BEC(arg0);
    }
}

void func_8030AFD8(s32 arg0){
    s32 sp1C = level_get();
    func_80321918(0);
    if(arg0){
        func_802C5994();
    }
    if(sp1C > 0 && sp1C < 0xC){
        func_8033301C();
    }
    func_8034789C();
    func_80250FC0(); //stop controller motor
    func_80314B24();
    func_80347A70();
}