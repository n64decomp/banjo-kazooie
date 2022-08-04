#include <ultra64.h>
#include "functions.h"
#include "variables.h"


/* !!!!!!!!!!!!!!!!!!!!!!!!!!! BREAK??? !!!!!!!!!!!!!!!!!!!!!!!!!*/

void __overlay_mmm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322930(void); 
void func_80322960(void);
void __overlay_mmm_update(void);
void func_803229C0(s32, s32);

void __overlay_cc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322A00(void); 
void func_80322A28(void);
void __overlay_cc_update(void);
void func_80322A78(s32, s32);

void __overlay_gv_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322A94(void); 
void func_80322ACC(void);
void __overlay_gv_update(void);
void func_80322B3C(s32, s32);

void __overlay_ttc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322B58(void); 
void func_80322B78(void);
void __overlay_ttc_update(void);
void func_80322BB8(s32, s32);

void __overlay_mm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322CC8(void); 
void func_80322CD0(void);
void __overlay_mm_update(void);
void func_80322CE0(s32, s32);

void __overlay_bgs_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322D30(void); 
void func_80322D38(void);
void __overlay_bgs_update(void);
void func_80322D94(s32, s32);

void __overlay_sm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322BD4(void); 
void func_80322BDC(void);
void __overlay_sm_update(void); 
void func_80322BEC(s32, s32);

void __overlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322C18(void); 
void func_80322C38(void);
void __overlay_lair_update(void);
void func_80322C78(s32, s32);

void __overlay_fight_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322C94(void); 
void func_80322C9C(void);
void __overlay_fight_update(void);
void func_80322CAC(s32, s32);

void __overlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322CFC(void); 
void func_80322D04(void);
void __overlay_intro_update(void);
void func_80322D14(s32, s32);

void __overlay_fp_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80322DB0(void); 
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
    void (*unk4)(void);
    void (*unk8)(void);
    void (*unkC)(void);
    void (*unk10)(Gfx **, Mtx **, Vtx **);
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
    { OVERLAY_2_WHALE,    1, 0, func_80322A28, __overlay_cc_update,    func_80322A00, __overlay_cc_draw,    func_80322A78},
    { OVERLAY_3_HAUNTED,  1, 0, func_80322960, __overlay_mmm_update,   func_80322930, __overlay_mmm_draw,   func_803229C0},
    { OVERLAY_4_DESERT,   1, 0, func_80322ACC, __overlay_gv_update,    func_80322A94, __overlay_gv_draw,    func_80322B3C},
    { OVERLAY_5_BEACH,    1, 0, func_80322B78, __overlay_ttc_update,   func_80322B58, __overlay_ttc_draw,   func_80322BB8},
    { OVERLAY_6_JUNGLE,   1, 0, func_80322CD0, __overlay_mm_update,    func_80322CC8, __overlay_mm_draw,    func_80322CE0},
    { OVERLAY_7_SWAMP,    1, 0, func_80322D38, __overlay_bgs_update,   func_80322D30, __overlay_bgs_draw,   func_80322D94},
    { OVERLAY_B_TRAINING, 1, 0, func_80322BDC, __overlay_sm_update,    func_80322BD4, __overlay_sm_draw,    func_80322BEC},
    { OVERLAY_C_INTRO,    1, 0, func_80322D04, __overlay_intro_update, func_80322CFC, __overlay_intro_draw, func_80322D14},
    { OVERLAY_D_WITCH,    1, 0, func_80322C38, __overlay_lair_update,  func_80322C18, __overlay_lair_draw,  func_80322C78},
    { OVERLAY_E_BATTLE,   1, 0, func_80322C9C, __overlay_fight_update, func_80322C94, __overlay_fight_draw, func_80322CAC},
    { OVERLAY_9_SNOW,     0, 1, func_80322DE8, __overlay_fp_update,    func_80322DB0, __overlay_fp_draw,    func_80322E58},
    {0}
};

/* .bss */
struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[2];
    void (*unk4)(void);
    void (*unk8)(void);
    void (*unkC)(void);
    void (*unk10)(Gfx **, Mtx **, Vtx **);
    void (*unk14)(s32, s32);
} D_80383350;

/* .code */
void __overlay_mmm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322930(void){
    func_8038953C();
    func_80389CD8();
    func_8038A994();
}

void func_80322960(void){
    func_80389544();
    func_80389CE0();
    func_8038A9B4();
}

void __overlay_mmm_update(void){
    func_8038966C();
    func_80389FC0();
    func_8038AA44();
}

void func_803229C0(s32 arg0, s32 arg1){
    func_80389DF4(arg0, arg1);
}

void __overlay_cc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ 
    func_80388760(gfx, mtx, vtx);
}

void func_80322A00(void){
    func_80388CB4();
    func_803880D4();
}

void func_80322A28(void){
    func_80388D54();
    func_80388104();
}

void __overlay_cc_update(void){
    func_80388F4C();
    func_8038817C();
}

void func_80322A78(s32 arg0, s32 arg1){ return; }


void __overlay_gv_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }


void func_80322A94(void){
    func_8038FF60();
    func_803900F8();
    func_803903EC(); //gv_matchingGame_reset
    func_803909EC();
}

void func_80322ACC(void){
    func_8038FF68();
    func_80390100();
    func_8039040C(); //gv_matchingGame_init
    func_803909F4();
}

void __overlay_gv_update(void){
    func_8038FFF4();
    func_80390138();
    func_803904A8(); //gv_matchingGame_update
    func_80390A94();
}

void func_80322B3C(s32 arg0, s32 arg1){ return; }

void __overlay_ttc_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322B58(void){
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

void func_80322BD4(void){ return; }

void func_80322BDC(void){ return; }

void __overlay_sm_update(void){ return; }

void func_80322BEC(s32 arg0, s32 arg1){ return; }

void __overlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ 
    lair_func_8038E768(gfx, mtx, vtx); 
}

void func_80322C18(void){
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

void func_80322C94(void){ return; }

void func_80322C9C(void){ return; }

void __overlay_fight_update(void){ return; }

void func_80322CAC(s32 arg0, s32 arg1){ return; }

void __overlay_mm_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322CC8(void){ return; }

void func_80322CD0(void){ return; }

void __overlay_mm_update(void){ return; }

void func_80322CE0(s32 arg0, s32 arg1){ return; }

void __overlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322CFC(void){ return; }

void func_80322D04(void){ return; }

void __overlay_intro_update(void){ return; }

void func_80322D14(s32 arg0, s32 arg1){ return; }

void __overlay_bgs_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322D30(void){ return; }

void func_80322D38(void){
    if( map_get() == MAP_10_BGS_MR_VILE
        && func_803203FC(2)
        && func_803203FC(7)
    ){
        func_8029A95C(TRANSFORM_5_CROC);
    }
}

void __overlay_bgs_update(void){ return; }

void func_80322D94(s32 arg0, s32 arg1){ return; }

void __overlay_fp_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){ return; }

void func_80322DB0(void){
    func_8038A888();
    func_8038AA58();
    func_8038B8A8();
    func_8039195C();
}

void func_80322DE8(void){
    func_8038A7F0();
    func_8038A9C0();
    func_8038B7A4();
    func_803918C0();
}

void __overlay_fp_update(void){
    func_8038A890();
    func_8038AA60();
    func_8038B544();
    func_80391994();
}

void func_80322E58(s32 arg0, s32 arg1){ return; }

void func_80322E64(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(D_80383350.unk10)
        D_80383350.unk10(gfx, mtx, vtx);
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
    if(arg0 == D_80383350.unk1 && D_80383350.unkC){
        D_80383350.unkC();
    }
}

void func_80322F1C(int arg0){
    if(arg0 == D_80383350.unk0 && D_80383350.unk4){
        D_80383350.unk4();
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
    overlay_id = get_loaded_overlay_id();
    D_80383350.unk4 = D_80383350.unk8 = D_80383350.unkC = NULL;
    D_80383350.unk10 = NULL;
    D_80383350.unk14 = NULL;
    for(i = 0; D_8036E2F8[i].unk0 != 0; i++){
        if(overlay_id == D_8036E2F8[i].unk0){
            D_80383350.unk0 = D_8036E2F8[i].unk2;
            D_80383350.unk1 = D_8036E2F8[i].unk3;
            D_80383350.unk4 = D_8036E2F8[i].unk4;
            D_80383350.unk8 = D_8036E2F8[i].unk8;
            D_80383350.unkC = D_8036E2F8[i].unkC;
            D_80383350.unk10 = D_8036E2F8[i].unk10;
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
    if(D_80383350.unk8)
        D_80383350.unk8();
}
