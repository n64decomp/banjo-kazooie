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

MapInfo * func_8030AD00(enum MAP_E map);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AD00.s")

enum level_e map_getLevel(enum MAP_E map){
    return func_8030AD00(map)->level_id;
};

/* returns string containing the map name and index */
u8 *func_8030AD6C(enum MAP_E map){
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AFD8.s")
