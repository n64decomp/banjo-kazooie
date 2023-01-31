#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void rbb_propellorCtrl_stop(void); //rbb

typedef struct {
    u8 unk0;
    u8 level;
} struct_9A740;

/* .bss */
struct {
    u8 unk0;
    u8 level;
}D_80383300;

/* .code */
void func_803216D0(enum map_e map){
    s32 prev_lvl = D_80383300.level;
    D_80383300.level = map_getLevel(map);
    overlayManagerload(level_to_overlay(D_80383300.level));
    D_80383300.unk0 = 0;
    if(func_802E4A8C()){
        func_802E4A80();
    }else{
        if( D_80383300.level != LEVEL_6_LAIR 
            && D_80383300.level != LEVEL_C_BOSS
            && prev_lvl == LEVEL_6_LAIR
        ){
            D_80383300.unk0 = 1;
        }
    
        mapSavestate_init();
        func_803464F8(D_80383300.level);
        jiggyscore_clearAllSpawned();
        levelSpecificFlags_clear();
        func_8029A92C();
        func_803219A8();
        if( func_80320454(0x17, 0) 
            && getGameMode() != 0
            && D_80383300.level != LEVEL_D_CUTSCENE
            && map != MAP_91_FILE_SELECT
        ){
            func_803204E4(0x18, TRUE);
        }

        if(D_80383300.level == LEVEL_9_RUSTY_BUCKET_BAY){
            rbb_propellorCtrl_reset();
        }

        switch(map){
            case MAP_2_MM_MUMBOS_MOUNTAIN:
                mm_resetHuts();
                break;
            case MAP_7_TTC_TREASURE_TROVE_COVE:
                ttc_resetTresureHunt();
                break;
            case MAP_1B_MMM_MAD_MONSTER_MANSION:
                mm_resetFlowerPots();
                break;
        }
    }
}

void func_80321854(void){
    if(!func_802E4A8C()){
        if( D_80383300.level == LEVEL_9_RUSTY_BUCKET_BAY){
            rbb_propellorCtrl_stop();
        }

        if( D_80383300.level == LEVEL_1_MUMBOS_MOUNTAIN
            && getGameMode() != 0
            && func_8031FF1C(BKPROG_31_MM_OPEN)
            && !func_8031FF1C(0xC1)
        ){
            func_803204E4(0x22, 1);
        }
        func_8029A924(); //null
        func_803465BC(); //null
        mapSavestate_free_all();
        func_8032196C();
    }
}

enum level_e level_get(void){
    return D_80383300.level;
}

int func_8032190C(void){
    return D_80383300.unk0;
}

void func_80321918(int arg0){
    D_80383300.unk0 = arg0;
}

void func_80321924(void){
    if(D_80383300.level == LEVEL_9_RUSTY_BUCKET_BAY){
        rbb_propellorCtrl_update();
    }
}
