#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8038FEE8(void); //rbb

typedef struct {
    u8 unk0;
    u8 unk1;
} struct_9A740;

extern u8 D_80383300;
extern u8 D_80383301;

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9A740/func_803216D0.s")
#else
void func_803216D0(enum MAP_E map){
    s32 prev_lvl = D_80383301;
    D_80383301 = map_getLevel(map);
    load_overlay(level_2_overlay(D_80383301));
    D_80383300 = 0;
    if(func_802E4A8C()){
        func_802E4A80();
    }else{
        if( D_80383301 != LEVEL_6_LAIR 
            && D_80383301 != LEVEL_C_BOSS
            && prev_lvl == LEVEL_6_LAIR
        )
            D_80383300 = 1;
    
        func_802E2E40();
        func_803464F8(D_80383301);
        jiggyscore_80320F38();
        levelSpecificFlags_clear();
        func_8029A92C();
        func_803219A8();
        if( func_80320454(0x17, 0) 
            && getGameMode() != 0
            && D_80383301 != 0xD
            && map != MAP_91_FILE_SELECT
        ){
            func_803204E4(0x18, 1);
        }

        if(D_80383301 == LEVEL_9_RUSTY_BUCKET_BAY){
            func_8038FF18();
        }

        switch(map){
            case MAP_2_MM_MUMBOS_MOUNTAIN:
                func_80386C90();
                break;
            case MAP_7_TTC_TREASURE_TROVE_COVE:
                func_80389E84();
                break;
            case MAP_1B_MMM_MAD_MONSTER_MANSION:
                func_80387260();
                break;
        }
    }
}
#endif

void func_80321854(void){
    if(!func_802E4A8C()){
        if( D_80383301 == LEVEL_9_RUSTY_BUCKET_BAY){
            func_8038FEE8();
        }

        if( D_80383301 == LEVEL_1_MUMBOS_MOUNTAIN
            && getGameMode() != 0
            && func_8031FF1C(BKPROG_31_MM_OPEN)
            && !func_8031FF1C(0xC1)
        ){
            func_803204E4(0x22, 1);
        }
        func_8029A924(); //null
        func_803465BC(); //null
        mapSavestate_clearAll();
        func_8032196C();
    }
}

enum level_e level_get(void){
    return D_80383301;
}

int func_8032190C(void){
    return D_80383300;
}

void func_80321918(int arg0){
    D_80383300 = arg0;
}

void func_80321924(void){
    if(D_80383301 == LEVEL_9_RUSTY_BUCKET_BAY){
        func_8038FF70();
    }
}
