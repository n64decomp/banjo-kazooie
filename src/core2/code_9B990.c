#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* !!!!!!!!!!!!!!!!!!!!!!!!!!! BREAK??? !!!!!!!!!!!!!!!!!!!!!!!!!*/

void __overlay_mmm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_mmm_release(void); 
void func_80322960(void);
void __overlay_mmm_update(void);
void func_803229C0(s32, s32);

void __overlay_cc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_cc_release(void); 
void func_80322A28(void);
void __overlay_cc_update(void);
void func_80322A78(s32, s32);

void __overlay_gv_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_gv_release(void); 
void func_80322ACC(void);
void __overlay_gv_update(void);
void func_80322B3C(s32, s32);

void __overlay_ttc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_ttc_release(void); 
void func_80322B78(void);
void __overlay_ttc_update(void);
void func_80322BB8(s32, s32);

void __overlay_mm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_mm_release(void); 
void func_80322CD0(void);
void __overlay_mm_update(void);
void func_80322CE0(s32, s32);

void __overlay_bgs_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_bgs_release(void); 
void func_80322D38(void);
void __overlay_bgs_update(void);
void func_80322D94(s32, s32);

void __overlay_sm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_sm_release(void); 
void func_80322BDC(void);
void __overlay_sm_update(void); 
void func_80322BEC(s32, s32);

void __overlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_lair_release(void); 
void func_80322C38(void);
void __overlay_lair_update(void);
void func_80322C78(s32, s32);

void __overlay_fight_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_fight_release(void); 
void func_80322C9C(void);
void __overlay_fight_update(void);
void func_80322CAC(s32, s32);

void __overlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_intro_release(void); 
void func_80322D04(void);
void __overlay_intro_update(void);
void func_80322D14(s32, s32);

void __overlay_fp_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void __overlay_fp_release(void); 
void func_80322DE8(void);
void __overlay_fp_update(void);
void func_80322E58(s32, s32);

typedef struct{
    s16 level_id;
    s16 overlay_id;
}level_overlay_map_elem;

typedef struct{
    s16 unk0;
    u8  unk2;
    u8  unk3;
    void (*init)(void);
    void (*update)(void);
    void (*release)(void);
    void (*draw)(Gfx **, Mtx **, Vtx **);
    void (*unk14)(s32, s32);
} level_overlay_update_struct;

/* .data */
level_overlay_map_elem D_8036E2C0[] = {
    {LEVEL_3_CLANKERS_CAVERN,       OVERLAY_2_WHALE},
    {LEVEL_A_MAD_MONSTER_MANSION,   OVERLAY_3_HAUNTED},
    {LEVEL_7_GOBIS_VALLEY,          OVERLAY_4_DESERT},
    {LEVEL_2_TREASURE_TROVE_COVE,   OVERLAY_5_BEACH},
    {LEVEL_1_MUMBOS_MOUNTAIN,       OVERLAY_6_JUNGLE},
    {LEVEL_4_BUBBLEGLOOP_SWAMP,     OVERLAY_7_SWAMP},
    {LEVEL_9_RUSTY_BUCKET_BAY,      OVERLAY_8_SHIP},
    {LEVEL_5_FREEZEEZY_PEAK,        OVERLAY_9_SNOW},
    {LEVEL_8_CLICK_CLOCK_WOOD,      OVERLAY_A_TREE},
    {LEVEL_B_SPIRAL_MOUNTAIN,       OVERLAY_B_TRAINING},
    {LEVEL_D_CUTSCENE,              OVERLAY_C_INTRO},
    {LEVEL_6_LAIR,                  OVERLAY_D_WITCH},
    {LEVEL_C_BOSS,                  OVERLAY_E_BATTLE},
    {0}
};

level_overlay_update_struct D_8036E2F8[] = {
    { OVERLAY_2_WHALE,    1, 0, func_80322A28, __overlay_cc_update,    __overlay_cc_release,    __overlay_cc_draw,    func_80322A78},
    { OVERLAY_3_HAUNTED,  1, 0, func_80322960, __overlay_mmm_update,   __overlay_mmm_release,   __overlay_mmm_draw,   func_803229C0},
    { OVERLAY_4_DESERT,   1, 0, func_80322ACC, __overlay_gv_update,    __overlay_gv_release,    __overlay_gv_draw,    func_80322B3C},
    { OVERLAY_5_BEACH,    1, 0, func_80322B78, __overlay_ttc_update,   __overlay_ttc_release,   __overlay_ttc_draw,   func_80322BB8},
    { OVERLAY_6_JUNGLE,   1, 0, func_80322CD0, __overlay_mm_update,    __overlay_mm_release,    __overlay_mm_draw,    func_80322CE0},
    { OVERLAY_7_SWAMP,    1, 0, func_80322D38, __overlay_bgs_update,   __overlay_bgs_release,   __overlay_bgs_draw,   func_80322D94},
    { OVERLAY_B_TRAINING, 1, 0, func_80322BDC, __overlay_sm_update,    __overlay_sm_release,    __overlay_sm_draw,    func_80322BEC},
    { OVERLAY_C_INTRO,    1, 0, func_80322D04, __overlay_intro_update, __overlay_intro_release, __overlay_intro_draw, func_80322D14},
    { OVERLAY_D_WITCH,    1, 0, func_80322C38, __overlay_lair_update,  __overlay_lair_release,  __overlay_lair_draw,  func_80322C78},
    { OVERLAY_E_BATTLE,   1, 0, func_80322C9C, __overlay_fight_update, __overlay_fight_release, __overlay_fight_draw, func_80322CAC},
    { OVERLAY_9_SNOW,     0, 1, func_80322DE8, __overlay_fp_update,    __overlay_fp_release,    __overlay_fp_draw,    func_80322E58},
    {0}
};

/* .bss */
struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    void (*init)(void);
    void (*update)(void);
    void (*release)(void);
    void (*draw)(Gfx **, Mtx **, Vtx **);
    void (*unk14)(s32, s32);
} D_80383350;

/* .code */
void __overlay_mmm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_mmm_release(void){
    func_8038953C();
    MMM_func_80389CD8();
    func_8038A994();
}

void func_80322960(void){
    func_80389544();
    func_80389CE0();
    func_8038A9B4();
}

void __overlay_mmm_update(void){
    func_8038966C();
    organMinigame_update();
    func_8038AA44();
}

void func_803229C0(s32 arg0, s32 arg1){
    func_80389DF4(arg0, arg1);
}

void __overlay_cc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ 
    CC_func_80388760(gfx, mtx, vtx);
}

void __overlay_cc_release(void){
    func_80388CB4();
    func_803880D4();
}

void func_80322A28(void){
    func_80388D54();
    func_80388104();
}

void __overlay_cc_update(void){
    CC_func_80388F4C();
    func_8038817C();
}

void func_80322A78(s32 arg0, s32 arg1){ return; }


void __overlay_gv_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }


void __overlay_gv_release(void){
    func_8038FF60();
    func_803900F8();
    gv_matchingGame_reset(); //gv_matchingGame_reset
    gv_waterCtrl_end();
}

void func_80322ACC(void){
    func_8038FF68();
    func_80390100();
    gv_matchingGame_init(); //gv_matchingGame_init
    gv_waterCtrl_init();
}

void __overlay_gv_update(void){
    func_8038FFF4();
    func_80390138();
    gv_matchingGame_update(); //gv_matchingGame_update
    gv_waterCtrl_update();
}

void func_80322B3C(s32 arg0, s32 arg1){ return; }

void __overlay_ttc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_ttc_release(void){
    func_8038B04C();
}

void func_80322B78(void){
    func_8038B094();
}

void __overlay_ttc_update(void){
    func_8038B2F0();
}

void func_80322BB8(s32 arg0, s32 arg1){ return; }

void __overlay_sm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_sm_release(void){ return; }

void func_80322BDC(void){ return; }

void __overlay_sm_update(void){ return; }

void func_80322BEC(s32 arg0, s32 arg1){ return; }

void __overlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ 
    lair_func_8038E768(gfx, mtx, vtx); 
}

void __overlay_lair_release(void){
    lair_func_8038CD48();
}

void func_80322C38(void){
    lair_func_8038CF18();
}

void __overlay_lair_update(void){
    lair_func_8038E0B0();
}

void func_80322C78(s32 arg0, s32 arg1){ return; }


void __overlay_fight_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_fight_release(void){ return; }

void func_80322C9C(void){ return; }

void __overlay_fight_update(void){ return; }

void func_80322CAC(s32 arg0, s32 arg1){ return; }

void __overlay_mm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_mm_release(void){ return; }

void func_80322CD0(void){ return; }

void __overlay_mm_update(void){ return; }

void func_80322CE0(s32 arg0, s32 arg1){ return; }

void __overlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_intro_release(void){ return; }

void func_80322D04(void){ return; }

void __overlay_intro_update(void){ return; }

void func_80322D14(s32 arg0, s32 arg1){ return; }

void __overlay_bgs_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_bgs_release(void){ return; }

void func_80322D38(void){
    if( map_get() == MAP_10_BGS_MR_VILE
        && volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)
        && volatileFlag_get(VOLATILE_FLAG_7_HAS_SEEN_VILE_FF_MINIGAME)
    ){
        player_setTransformation(TRANSFORM_5_CROC);
    }
}

void __overlay_bgs_update(void){ return; }

void func_80322D94(s32 arg0, s32 arg1){ return; }

void __overlay_fp_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void __overlay_fp_release(void){
    fp_sirslushgame_end();
    fp_snowmanButtonGame_end();
    func_8038B8A8();
    func_8039195C();
}

void func_80322DE8(void){
    fp_sirslushgame_init();
    fp_snowmanButtonGame_init();
    func_8038B7A4();
    func_803918C0();
}

void __overlay_fp_update(void){
    fp_sirslushgame_update();
    fp_snowmanButtonGame_update();
    func_8038B544();
    func_80391994();
}

void func_80322E58(s32 arg0, s32 arg1){ return; }

void func_80322E64(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(D_80383350.draw)
        D_80383350.draw(gfx, mtx, vtx);
}

enum overlay_e level_to_overlay(enum level_e lvl){
    int i;
    for(i = 0; D_8036E2C0[i].level_id; i++){
        if(D_8036E2C0[i].level_id == lvl)
            return D_8036E2C0[i].overlay_id;
    }
    return 0;
}

void func_80322EDC(int arg0){
    if(arg0 == D_80383350.unk1 && D_80383350.release){
        D_80383350.release();
    }
}

void func_80322F1C(int arg0){
    if(arg0 == D_80383350.unk0 && D_80383350.init){
        D_80383350.init();
    }
}

void func_80322F5C(void){
    func_80322EDC(0);
}

void func_80322F7C(void){
    func_80322EDC(1);
}

void func_80322F9C(void){
    func_80322F1C(0);
}

void func_80322FBC(void){
    func_80322F1C(1);
}

void func_80322FDC(void){ return; }

void func_80322FE4(void){
    int i;
    s32 overlay_id;
    func_80356714();
    overlay_id = overlayManagergetLoadedId();
    D_80383350.init = D_80383350.update = D_80383350.release = NULL;
    D_80383350.draw = NULL;
    D_80383350.unk14 = NULL;
    for(i = 0; D_8036E2F8[i].unk0 != 0; i++){
        if(overlay_id == D_8036E2F8[i].unk0){
            D_80383350.unk0 = D_8036E2F8[i].unk2;
            D_80383350.unk1 = D_8036E2F8[i].unk3;
            D_80383350.init = D_8036E2F8[i].init;
            D_80383350.update = D_8036E2F8[i].update;
            D_80383350.release = D_8036E2F8[i].release;
            D_80383350.draw = D_8036E2F8[i].draw;
            D_80383350.unk14 = D_8036E2F8[i].unk14;
            break;
        }
    }
}

void func_80323098(s32 arg0, s32 arg1){
    if(D_80383350.unk14)
        D_80383350.unk14(arg0, arg1);
}

void overlay_update(void){
    if(D_80383350.update)
        D_80383350.update();
}
