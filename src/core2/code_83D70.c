#include <ultra64.h>
#include "functions.h"
#include "variables.h"


typedef struct {
    s16 level_id;
    s16 unk2;
    s16 unk4;
}Struct_core2_83D70_1;

typedef struct map_info{
    s16 map_id;
    s16 level_id;
    u8* name;
}MapInfo;

/* .data */
extern MapInfo D_8036B818[];
extern Struct_core2_83D70_1 D_8036BCE8[];

/* .rodata */
extern u8 D_80378430[];
extern u8 D_80378434[];

/* .bss */
extern u8 D_803823A0[];

/* .data */
#ifndef NONMATCHING
MapInfo * func_8030AD00(enum map_e map_id);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AD00.s")
#else
MapInfo * func_8030AD00(enum map_e map_id){
    MapInfo *phi_v1;

    for(phi_v1 = D_8036B818; phi_v1->map_id != 0; phi_v1++){
        if (map_id == phi_v1->map_id) {
            return phi_v1;
        }
    }
    return NULL;
}
#endif

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

s32 func_8030ADD8(enum level_e level_id) {
    Struct_core2_83D70_1 *phi_v1;

    for(phi_v1 = D_8036BCE8; phi_v1->level_id != 0; phi_v1++){
        if (level_id == phi_v1->level_id) {
            return phi_v1->unk2;
        }
    }
    return 0;
}


s32 func_8030AE24(enum level_e level_id) {
    Struct_core2_83D70_1 *phi_v1;

    for(phi_v1 = D_8036BCE8; phi_v1->level_id != 0; phi_v1++){
        if (level_id == phi_v1->level_id) {
            return phi_v1->unk4;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AE70.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_83D70/func_8030AF58.s")
#else
bool func_8030AF58(s32 arg0) {
    Struct_core2_83D70_0 *phi_v0;
    s32 i;

    for(i = 0; D_8036B818[i].unk0 != 0; i++) {
        phi_v0 = &D_8036B818[i];
        if(phi_v0->unk0 == arg0){
            return TRUE;
        }
    }
    return FALSE;
}
#endif

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