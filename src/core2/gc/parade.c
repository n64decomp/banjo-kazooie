#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "../snackerctl.h"


extern void func_8028F918(s32);
extern void func_80311714(int);

typedef struct struct_1C_s{
    u8 map;
    s8 exit;
    s16 x;   //0x2
    char *str; //0x4
    s8 unk8;
}ParadeInfo;

enum parade_e {
    PARADE_0_POST_FURNACE_FUN,
    PARADE_1_POST_GRUNTY_BATTLE
};

enum parade_state_e {
    PARADE_STATE_0_NONE,
    PARADE_STATE_1_INIT_FF_PARADE,
    PARADE_STATE_2_INIT_FINAL_PARADE,
    PARADE_STATE_3_WARP,
    PARADE_STATE_4_NAME_APPEAR,
    PARADE_STATE_5_WAIT_ON_NAME,
    PARADE_STATE_6_NAME_DISAPPEAR,
    PARADE_STATE_7_GOTO_NEXT,
    PARADE_STATE_8_END,
};

/* .data */
ParadeInfo D_8036D9A0[0x1B] = {
    {MAP_8E_GL_FURNACE_FUN,         0x14, 90, "GRUNTILDA",         0},
    {MAP_8E_GL_FURNACE_FUN,         0x13, 110, "TOOTY",            0},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0x13, 100, "BOTTLES",          0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x2D, 130, "JINJO",            0},
    {MAP_E_MM_MUMBOS_SKULL,         0x02, 60, "MUMBO JUMBO",       0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x2F, 125, "JU-JU",            0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x2C, 115, "CONGA",            0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x2B, 110, "CHIMPY",           0},
    {MAP_74_GL_GV_PUZZLE,           0x08, 95, "BRENTILDA",         0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x22, 50, "CAPTAIN BLUBBER",   0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x23, 120, "NIPPER",           0},
    {MAP_B_CC_CLANKERS_CAVERN,      0x0B, 105, "CLANKER",          0},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,   0x23, 95, "TANKTUP",           0},
    {MAP_10_BGS_MR_VILE,            0x03, 100, "MR. VILE",         0},
    {MAP_11_BGS_TIPTUP,             0x08, 115, "TIPTUP",           0},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x3D, 115, "BOGGY",            0},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x3E, 110, "WOZZA",            0},
    {MAP_12_GV_GOBIS_VALLEY,        0x39, 100, "TRUNKER",          0},
    {MAP_12_GV_GOBIS_VALLEY,        0x38, 125, "GOBI",             0},
    {MAP_16_GV_RUBEES_CHAMBER,      0x04, 35, "RUBEE AND TOOTS",   0},
    {MAP_26_MMM_NAPPERS_ROOM,       0x06, 110, "NAPPER",           0},
    {MAP_2C_MMM_BATHROOM,           0x03, 115, "LOGGO",            0},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,   0x27, 105, "SNORKEL",          0},
    {MAP_44_CCW_SUMMER,             0x0F, 100, "GNAWTY",           0},
    {MAP_46_CCW_WINTER,             0x0C, 125, "EYRIE",            0},
    {MAP_5E_CCW_SPRING_NABNUTS_HOUSE, 0x01, 110, "NABNUT",         0},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0xFD, 20, "BANJO AND KAZOOIE", 0}
};

ParadeInfo D_8036DAE4[0x3A] ={
    {MAP_93_GL_DINGPOT,             0x11, 105, "DINGPOT",           0},
    {MAP_84_CS_UNUSED_MACHINE_ROOM, 0x00, 107, "KLUNGO",            0},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0x29, 110, "TOPPER",            6},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0x27, 118, "BAWL",              7},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0x28, 75, "COLLIWOBBLE",        8},
    {MAP_1_SM_SPIRAL_MOUNTAIN,      0x2A, 100, "QUARRIE",           0},
    {MAP_71_GL_STATUE_ROOM,         0x0D, 85, "GRUNTLING",          0},
    {MAP_C_MM_TICKERS_TOWER,        0x09, 113, "TICKER",            0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x30, 105, "BIGBUTT",           0},
    {MAP_2_MM_MUMBOS_MOUNTAIN,      0x2E, 105, "GRUBLIN",           0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x24, 120, "LEAKY",             0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x25, 105, "LOCKUP",            0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x26, 67, "LITTLE LOCKUP",      0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x27, 100, "YUM-YUM",           0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x28, 110, "SNIPPET",           0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x29, 95, "SHRAPNEL",           0},
    {MAP_7_TTC_TREASURE_TROVE_COVE, 0x2A, 105, "SNACKER",          14},
    {MAP_B_CC_CLANKERS_CAVERN,      0x1A, 110, "GLOOP",             0},
    {MAP_B_CC_CLANKERS_CAVERN,      0x1B, 60, "GRILLE CHOMPA",      1},
    {MAP_B_CC_CLANKERS_CAVERN,      0x1C, 70, "MUTIE-SNIPPET",      0},
    {MAP_22_CC_INSIDE_CLANKER,      0x0B, 93, "WHIPLASH",           0},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,   0x24, 100, "CROCTUS",           0},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,   0x25, 115, "FLIBBIT",           0},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,   0x26, 90, "BUZZBOMB",           0},
    {MAP_11_BGS_TIPTUP,             0x09, 45, "THE TIPTUP CHOIR",   0},
    {MAP_41_FP_BOGGYS_IGLOO,        0x05, 105, "GROGGY",            0},
    {MAP_41_FP_BOGGYS_IGLOO,        0x06, 117, "SOGGY",             0},
    {MAP_41_FP_BOGGYS_IGLOO,        0x07, 110, "MOGGY",             0},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x3F, 65, "THE TWINKLIES",     -1},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x40, 37, "TWINKLY MUNCHER",   -2},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x41, 100, "SIR SLUSH",         0},
    {MAP_27_FP_FREEZEEZY_PEAK,      0x42, 107, "CHINKER",           0},
    {MAP_12_GV_GOBIS_VALLEY,        0x3A, 120, "JINXY",            -3},
    {MAP_12_GV_GOBIS_VALLEY,        0x3B, 40, "THE ANCIENT ONES",   0},
    {MAP_12_GV_GOBIS_VALLEY,        0x3C, 110, "GRABBA",            2},
    {MAP_12_GV_GOBIS_VALLEY,        0x3D, 110, "SCABBY",            0},
    {MAP_12_GV_GOBIS_VALLEY,        0x3E, 113, "SLAPPA",            3},
    {MAP_13_GV_MEMORY_GAME,         0x03, 90, "MUM-MUM",            0},
    {MAP_16_GV_RUBEES_CHAMBER,      0x05, 115, "HISTUP",            0},
    {MAP_1C_MMM_CHURCH,             0x05, 90, "MOTZAND",            0},
    {MAP_24_MMM_TUMBLARS_SHED,      0x02, 95, "TUMBLAR",            0},
    {MAP_28_MMM_EGG_ROOM,           0x01, 0x20, "PORTRAIT CHOMPA",  4},
    {MAP_1D_MMM_CELLAR,             0x0A, 110, "TEE-HEE",          11},
    {MAP_2C_MMM_BATHROOM,           0x04, 120, "LIMBO",             0},
    {MAP_1B_MMM_MAD_MONSTER_MANSION, 0x28, 118, "RIPPER",          12},
    {MAP_1B_MMM_MAD_MONSTER_MANSION, 0x29, 117, "NIBBLY",           0},
    {MAP_38_RBB_CONTAINER_3,        0x02, 83, "BOOM BOX",          13},
    {MAP_3A_RBB_BOSS_BOOM_BOX,      0x04, 50, "BOSS BOOM BOX",      0},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,   0x28, 105, "GRIMLET",           9},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,   0x29, 105, "FLOTSAM",           0},
    {MAP_3C_RBB_KITCHEN,            0x05, 50, "SEAMAN GRUBLIN",     0},
    {MAP_35_RBB_WAREHOUSE,          0x06, 110, "CHUMP",             0},
    {MAP_44_CCW_SUMMER,             0x10, 87, "SNAREBEAR",         10},
    {MAP_45_CCW_AUTUMN,             0x14, 85, "BIG CLUCKER",        5},
    {MAP_5B_CCW_SPRING_ZUBBA_HIVE,  0x04, 78, "THE ZUBBAS",         0},
    {MAP_46_CCW_WINTER,             0x0E, 63, "GRUBLIN HOOD",       0},
    {MAP_66_CCW_SUMMER_WHIPCRACK_ROOM, 0x06, 83, "WHIPCRACK",       0},
    {MAP_72_GL_BGS_LOBBY,           0x04, 110, "CHEATO",            0}
};
s8 D_8036DD9C[] = {1, 1, 1, 1, 11, 8, 6, 4, 3, 2, -1, -1, 0};
s32 D_8036DDAC[] = {0x379, -1};

/* .bss */
struct{
    u8 state;
    u8 indx;
    u8 count;
    s8 y_position;
    s8 scroll_frame;
    u8 unk5;
    u8 parade_id;
    u8 jiggyscore; //jiggy total
    s32 unk8;
    ParadeInfo *parade_element;
}D_803830F0;
NodeProp *D_80383100[20];

/* public */
void gcparade_beginFinalParade(void);
void gcparade_setState(enum parade_state_e next_state);

/* .code */
void gcparade_8031ABA0(void) {
    func_8031FBF8();
    func_8031FBA0();
    if (D_803830F0.unk8 != -1) {
        func_802C5A3C(D_803830F0.unk8);
        gameFile_load(D_803830F0.unk8);
        func_80347AA8();
    }
}

void gcparade_8031ABF8(void) {
    D_803830F0.unk8 = func_802C5A30();
    func_8030AFD8(1);
    mapSavestate_free_all();
    levelSpecificFlags_clear();
    func_80347A7C();
    func_8031FBF8();
    func_8031FBA0();
    volatileFlag_set(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE, 1);
    if (D_803830F0.parade_id == PARADE_1_POST_GRUNTY_BATTLE) {
        volatileFlag_set(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE, TRUE);
    }
    func_803228D8();
    func_802E4A70();
}

void gcparade_8031AC8C(void) {

    func_803228D8();
    if (map_getLevel(D_803830F0.parade_element->map) != level_get()) {
        func_802E4A70();
    }

    if (D_803830F0.parade_element->exit < 0) {
        func_8034BA7C(D_803830F0.parade_element->map, 0x5A - D_803830F0.parade_element->exit);
    } else {
        func_802E40D0(D_803830F0.parade_element->map, 0x65);
        func_802E412C(1, 8);
        func_802E40C4(9);
    }
    D_803830F0.unk5 = 1;
}

void gcparade_setState(enum parade_state_e next_state) {
    switch (next_state) {
        case PARADE_STATE_1_INIT_FF_PARADE: //parade 0 init
            D_803830F0.parade_element = D_8036D9A0;
            D_803830F0.indx = 0;
            D_803830F0.parade_id = PARADE_0_POST_FURNACE_FUN;
            D_803830F0.count = 0x1B;
            func_8025A70C(COMUSIC_8E_CREDITS);
            next_state = PARADE_STATE_3_WARP;
            gcparade_8031AC8C();
            break;
        case PARADE_STATE_2_INIT_FINAL_PARADE: //parade 1 init
            volatileFlag_set(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE, TRUE);
            D_803830F0.parade_element = D_8036DAE4;
            D_803830F0.indx = 0;
            D_803830F0.parade_id = PARADE_1_POST_GRUNTY_BATTLE;
            D_803830F0.count = 0x3A;
            func_8025A55C(0, 0x1388, 0xB);
            func_8025AB00();
            func_8025A70C(COMUSIC_8E_CREDITS);
            next_state = PARADE_STATE_3_WARP;
            gcparade_8031AC8C();
            break;
        case PARADE_STATE_3_WARP:
            func_803228D8();
            if (map_getLevel(D_803830F0.parade_element->map) != level_get()) {
                func_802E4A70();
            }
            if (D_803830F0.parade_element->exit < 0) {
                func_8034BA7C(D_803830F0.parade_element->map, 0x5A - D_803830F0.parade_element->exit);
            } else {
                func_802E412C(1, 8);
                func_802E40D0(D_803830F0.parade_element->map, 0x65);
                func_802E40C4(1);
            }
            D_803830F0.unk5 = 1;
            break;
        case PARADE_STATE_4_NAME_APPEAR:
            D_803830F0.scroll_frame = -1;
            D_803830F0.y_position = -0x10;
            break;
        case PARADE_STATE_5_WAIT_ON_NAME:
            if ((D_803830F0.parade_id == 1) && (D_803830F0.parade_element->exit >= 0)) {
                timedFunc_set_1(2.0f, (GenFunction_1)gcparade_setState, PARADE_STATE_6_NAME_DISAPPEAR);// queue state transition
            }
            break;
        case PARADE_STATE_7_GOTO_NEXT:
            D_803830F0.indx++;
            D_803830F0.parade_element++;
            timedFunc_set_1(0.25f, (GenFunction_1)gcparade_setState, (D_803830F0.indx == D_803830F0.count) ? PARADE_STATE_8_END : PARADE_STATE_3_WARP);
            break;
        case PARADE_STATE_8_END:
            volatileFlag_set(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE, 0);
            volatileFlag_set(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE, FALSE);
            func_802E412C(1, 8);
            func_802E40C4(0xA);
            if (D_803830F0.parade_id == 0) {
                func_802E40D0(MAP_94_CS_INTRO_SPIRAL_7, 0);
            } else if (D_803830F0.jiggyscore < 100) {
                func_802E40D0(MAP_20_CS_END_NOT_100, 0);
            } else {
                func_802E40D0(MAP_95_CS_END_ALL_100, 0);
            }
            comusic_8025AB44(COMUSIC_8E_CREDITS, 0, 1000);
            func_8025AABC(COMUSIC_8E_CREDITS);
            break;
        default:
            break;
    }
    D_803830F0.state = next_state;
}

void func_8031B010(void){
    gcparade_setState(PARADE_STATE_6_NAME_DISAPPEAR);
}

void gcparade_textCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    if(D_803830F0.parade_element->exit >= 0){
        gcparade_setState(PARADE_STATE_6_NAME_DISAPPEAR);
    }
}

void gcparade_print(s32 index){
    ParadeInfo *v0 = D_803830F0.parade_element;
    print_bold_overlapping(v0->x, D_803830F0.y_position, -1.2f, v0->str);
}

void gcparade_update(void) {
    s32 sp34;

    if ((map_get() == MAP_96_CS_END_BEACH_1) && mapSpecificFlags_get(4)) {
        mapSpecificFlags_set(4, FALSE);
        gcparade_beginFinalParade();
        return;
    }
    if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE) != 0) {
        snackerctl_update();
        switch (D_803830F0.state) {
            case PARADE_STATE_3_WARP:
                if (D_803830F0.unk5 == 0) {
                    if (map_get() == D_803830F0.parade_element->map) {
                        if (D_803830F0.parade_id == 0) {
                            sp34 = 0xA0;
                            if (D_803830F0.parade_element->exit >= 0) 
                                sp34 = 0xA8;
                            timedFunc_set_1(1.0f, (GenFunction_1)func_80311714, 0);
                            func_80324DBC(1.0f, D_803830F0.indx + 0x11AF, sp34, NULL, NULL, gcparade_textCallback, NULL);
                            timedFunc_set_1(1.0f, (GenFunction_1)func_80311714, 1);
                        } else if (D_803830F0.parade_element->exit >= 0) {
                            func_8028F918(2);
                        }
                        timedFunc_set_1(1.0f, (GenFunction_1)gcparade_setState, PARADE_STATE_4_NAME_APPEAR);
                        D_803830F0.unk5 = 1;
                    }
                }
                break;
            case PARADE_STATE_4_NAME_APPEAR:
                gcparade_print(D_803830F0.indx);
                D_803830F0.scroll_frame++; //name scroll down on screen
                D_803830F0.y_position += D_8036DD9C[D_803830F0.scroll_frame];
                if (D_803830F0.scroll_frame == 0xC) {
                    gcparade_setState(PARADE_STATE_5_WAIT_ON_NAME);
                }
                break;
            case PARADE_STATE_5_WAIT_ON_NAME: //name on screen (wait)
                gcparade_print(D_803830F0.indx);
                break;
            case PARADE_STATE_6_NAME_DISAPPEAR:// name scroll up off screen
                gcparade_print(D_803830F0.indx);
                D_803830F0.scroll_frame--;
                D_803830F0.y_position -= D_8036DD9C[D_803830F0.scroll_frame];
                if (D_803830F0.scroll_frame == 0) {
                    gcparade_setState(PARADE_STATE_7_GOTO_NEXT);
                }
                break;
        }
    }
}

void gcparade_free(void){}

void gcparade_start(void){
    volatileFlag_set(VOLATILE_FLAG_20_BEGIN_CHARACTER_PARADE, FALSE);
    volatileFlag_set(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE, TRUE);
    if(volatileFlag_getAndSet(VOLATILE_FLAG_C0_BEGIN_FINAL_CHARACTER_PARADE, FALSE))
        gcparade_setState(PARADE_STATE_2_INIT_FINAL_PARADE);
    else
        gcparade_setState(PARADE_STATE_1_INIT_FF_PARADE);

}

void gcparade_init(void) {
    s32 var_s0;
    f32 sp40[3];
    s32 temp_v0;
    s32 var_s2;

    if (volatileFlag_get(VOLATILE_FLAG_20_BEGIN_CHARACTER_PARADE)) {
        gcparade_start();
        return;
    }
    if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
        func_80347A14(0);
        if ((D_803830F0.state == 3)){
            var_s2 = FALSE;
            D_803830F0.unk5 = 0;
            if(D_803830F0.parade_element->exit >= 0) {
                camera_setType(1);
                ncStaticCamera_setToNode(D_803830F0.parade_element->exit);
                if (D_803830F0.parade_element->unk8 > 0) {
                    temp_v0 = func_80304FC4(&D_8036DDAC, &D_80383100, 0x14);
                    for(var_s0 = 0;(var_s0 < temp_v0) && !var_s2; var_s0++ ){
                        if (nodeprop_getRadius(D_80383100[var_s0]) == D_803830F0.parade_element->unk8) {
                            nodeprop_getPosition(D_80383100[var_s0], sp40);
                            func_8028F85C(sp40);
                            var_s2 = TRUE;
                        }
                    }
                }
                if (!var_s2) {
                    ncStaticCamera_getPosition(sp40);
                    func_8028F85C(sp40);
                }
            }
        }
    } else {
        gcparade_setState(PARADE_STATE_0_NONE);
    }
}

int gcparade_8031B4CC(void){
    return ((D_803830F0.parade_element != NULL) && (D_803830F0.parade_element->exit < 0));
}

int gcparade_8031B4F4(void){
    return (D_803830F0.parade_element != NULL) ? D_803830F0.parade_element->unk8 : 0;
}

void gcparade_beginFFParade(void){
    if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) return;

    volatileFlag_set(VOLATILE_FLAG_20_BEGIN_CHARACTER_PARADE, TRUE);
    gcparade_init();
}

void gcparade_beginFinalParade(void){
    
    if (volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) return;

    volatileFlag_set(VOLATILE_FLAG_20_BEGIN_CHARACTER_PARADE, TRUE);
    volatileFlag_set(VOLATILE_FLAG_C0_BEGIN_FINAL_CHARACTER_PARADE, TRUE);
    D_803830F0.jiggyscore = jiggyscore_total();
    gcparade_init();
}
