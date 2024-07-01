#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef MIN
#define MIN(s,t) (((s) < t)?(s):(t))
#endif

#ifndef MAX
#define MAX(s,t) (((s) > t)?(s):(t))
#endif


typedef struct struct_1A_s{
    f32 delay;
    f32 unk4;
    u8  *str;
    s16 y;
    u8  portrait;
    u8  unkF;
}struct1As;

extern void func_803160A8(gczoombox_t *);
extern void gczoombox_close(gczoombox_t *);
extern void gczoombox_minimize(gczoombox_t *);
extern void gczoombox_maximize(gczoombox_t *);
extern void func_802C5994(void);
extern void func_802E412C(s32, s32);
void func_803204E4(s32, s32);
f32 func_8024DE1C(f32, f32, f32 *, f32 *);
void mlMtxApply(Mtx*);
void func_80310D2C(void);

s32 level_get(void);
void gczoombox_update(gczoombox_t *);
void func_8024E6E0(s32, void *);
void func_8024E60C(s32, void *);
void func_8024E71C(s32, void *);
s32 getGameMode(void);

void gczoombox_highlight(gczoombox_t *, int);
void func_802DC5B8(void);
void func_802DC560(s32, s32);
s32 func_8024E67C(s32 controller_index);
bool func_803188B4(gczoombox_t*);
bool func_803183A4(gczoombox_t*, char *);
bool fileProgressFlag_get(enum file_progress_e);
enum map_e map_get(void);
bool func_802FD2D4(void);
bool func_802FC3C4(void);
extern void func_8025A2B0(void);
extern void func_8025A430(s32, s32, s32);
extern void func_802DC528(s32,s32);
extern void func_802F5060(enum asset_e);
extern void func_802F5188(void);
extern void func_802FACA4(enum item_e);
extern void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
extern void func_80318640(gczoombox_t *, s32, f32, f32, s32);
extern void func_80318734(gczoombox_t *, f32);
extern void func_80318964(gczoombox_t *);
extern void func_8033BD20(void *);

enum gcpausemenu_state_e {
    PAUSE_STATE_0_CLOSED = 0,
    PAUSE_STATE_1_OPENING = 1
};



/* .data */
struct1As D_8036C4E0[4] = {
    {0.0f, 0.0f,  "RETURN TO GAME",         55, TALK_PIC_4_BANJO_1, 0},
    {0.3f, 0.0f,  "EXIT TO WITCH'S LAIR", -100, TALK_PIC_4_BANJO_1, 0},
    {0.1f, 0.0f,  "VIEW TOTALS",            90, TALK_PIC_6_JIGGY_1, 0},
    {0.2f, 0.0f,  "SAVE AND QUIT",         125, TALK_PIC_7_TOOTY_1, 0},
};

struct1As D_8036C520[4] = {
    {0.0f, 0.0f,  "cc999 / 999cc",  30, TALK_PIC_8_MUSIC_NOTE_1,     0},
    {0.1f, 0.0f,  "cc999 / 999cc",  66, TALK_PIC_9_JIGGY_2,          0},
    {0.2f, 0.0f,  "cc999 / 999cc", 102, TALK_PIC_A_EXTRA_HEALTH_MAX, 0},
    {0.3f, 0.0f,  "cc999 : 999cc", 138, TALK_PIC_B_CLOCK,            0},
};

struct1Bs D_8036C560[] = {
    {MAP_69_GL_MM_LOBBY,  0x2},
    {MAP_6D_GL_TTC_LOBBY, 0x4},
    {MAP_70_GL_CC_LOBBY,  0x2},
    {MAP_72_GL_BGS_LOBBY, 0x2},
    {MAP_6F_GL_FP_LOBBY,  0x6},
    {-1, -1},
    {MAP_6E_GL_GV_LOBBY,  0x3}, 
    {MAP_79_GL_CCW_LOBBY, 0x6},
    {MAP_77_GL_RBB_LOBBY, 0x2},
    {MAP_75_GL_MMM_LOBBY, 0x2},
    {MAP_69_GL_MM_LOBBY, 0x12}
};

struct1Cs_1 D_8036C58C[0xD] = {
    {0, 0x50, "GAME TOTAL"}, 
    {LEVEL_B_SPIRAL_MOUNTAIN,       0x40, "SPIRAL MOUNTAIN"},
    {LEVEL_6_LAIR,                  0x3C, "GRUNTILDA'S LAIR"},
    {LEVEL_1_MUMBOS_MOUNTAIN,       0x25, "MUMBO'S MOUNTAIN"},
    {LEVEL_2_TREASURE_TROVE_COVE,   0x1B, "TREASURE TROVE COVE"},
    {LEVEL_3_CLANKERS_CAVERN,       0x34, "CLANKER'S CAVERN"},
    {LEVEL_4_BUBBLEGLOOP_SWAMP,     0x23, "BUBBLEGLOOP SWAMP"},
    {LEVEL_5_FREEZEEZY_PEAK,        0x48, "FREEZEEZY PEAK"},
    {LEVEL_7_GOBIS_VALLEY,          0x4E, "GOBI'S VALLEY"}, 
    {LEVEL_A_MAD_MONSTER_MANSION,   0x12, "MAD MONSTER MANSION"},
    {LEVEL_9_RUSTY_BUCKET_BAY,      0x32, "RUSTY BUCKET BAY"},
    {LEVEL_8_CLICK_CLOCK_WOOD,      0x30, "CLICK CLOCK WOOD"},
    {0,                             0x48, "STOP 'N' SWOP"}
};

s8 D_8036C5F4[] = {1, 1, 1, 1, 0xb, 0x8, 0x6, 0x4, 0x3, 0x2, -1, -1, 0};
u8 D_8036C604[0x7] = {ITEM_14_HEALTH, ITEM_26_JIGGY_TOTAL, ITEM_25_MUMBO_TOKEN_TOTAL, ITEM_10_GOLD_FEATHER, ITEM_F_RED_FEATHER, ITEM_D_EGGS, ITEM_C_NOTE};
u8 D_8036C60C[0xC] = {
    0x28, 
    0x29,
    0x00,
    ITEM_3_PROPELLOR_TIMER,
    ITEM_17_AIR,
    ITEM_13_EMPTY_HONEYCOMB,
    ITEM_1B_VILE_VILE_SCORE,
    ITEM_24_TWINKLY_SCORE,
    ITEM_1D_GRUMBLIE,
    ITEM_1E_YUMBLIE,
    ITEM_E_JIGGY,
    ITEM_1A_PLAYER_VILE_SCORE
};
// const char D_8036C618[] = {0};
// extern u8 D_8036C61C[] =  {0};

/* .bss */
struct{
    u8         state;
    u8         unk1;
    u8         selection; //menu page
    u8         unk3_7:1;
    u8         unk3_6:1; //busy?
    u8         unk3_5:1;
    u8         unk3_4:1;
    u8         left_joystick_visible:1;
    u8         right_joystick_visible:1;
    u8         b_button_visible:1;
    u8         unk3_0:1;
    s8          unk4;
    s8          unk5;
    u8          unk6;
    u8          unk7;
    s8          unk8; //header position
    s8          unk9;
    s8          joystick_frame;
    u8          joystick_frame_count;
    f32         unkC;
    gczoombox_t *zoombox[4];
    f32         unk20;
    BKSprite *  joystick_sprite;
    f32         unk28;
    BKSprite *  b_button_sprite;
    u8          b_button_frame;
    u8          b_button_frame_count;      //B-button total frames
    s16         b_button_alpha;      //B-button alpha
    s16         left_joystick_alpha;      //left joystick alpha
    s16         right_joystick_alpha;      //right joystick alpha
    u8          page_cnt;
    u8          unk39;
    u8          sns_visible;
    // u8  pad3B[1];
    s16         sns_alpha; //sns opacity
    s16         unk3E[7];
    s16         unk4C[7];
    // u8 pad5A[0x3];
    BKModelBin *sns_egg_model; //SnS Egg Model
    BKModelBin *ice_key_model; //Ice key model
    u8 pad64[0xC];
    u32         unk70_31:1;
    u32         unk70_30:1;
    u32         return_to_lair_disabled:1;
    u32 pad70_28:29;
}D_80383010;
s32 D_80383084;
char D_80383088[0x18];

/* public */
void gcpausemenu_803129DC(s32,s32);

/* .code */
void gcpausemenu_defrag(void){
    s32 i;
    for(i =0; i< 4; i++){
        if(D_80383010.zoombox[i]){
            func_80318C0C(D_80383010.zoombox[i]);
            D_80383010.zoombox[i] = (gczoombox_t *)defrag(D_80383010.zoombox[i]);
        }
    }
}

void gcpausemenu_zoomboxes_free(void){
    s32 i;
    for(i =0; i< 4; i++){
        gczoombox_free(D_80383010.zoombox[i]);
        D_80383010.zoombox[i] = NULL;
    }
}

void gcpausemenu_free(void){
    s32 i;
    for( i=0; i<2; i++){
        assetcache_release(D_80383010.joystick_sprite);
        D_80383010.joystick_sprite = NULL;
        assetcache_release(D_80383010.b_button_sprite);
        D_80383010.b_button_sprite = NULL;
    }
    gcpausemenu_zoomboxes_free();
    func_80311650();
}

void gcpausemenu_zoomboxes_initMainMenu(void){
    s32 i;
    for(i = 0; i<4; i++){
        D_80383010.zoombox[i] = gczoombox_new(D_8036C4E0[i].y,D_8036C4E0[i].portrait, 2, 0,gcpausemenu_803129DC);
        func_803184C8(D_80383010.zoombox[i], 60.0f, 5, 2, 0.3f, 0, 0);
        func_80318640(D_80383010.zoombox[i], 0x1C, 0.75f, 0.9f, 0);
        func_80318760(D_80383010.zoombox[i], 8000);
    }
}

void gcpausemenu_zoomboxes_initTotalsMenu(void){
    s32 i;

    for(i = 0; i<4; i++){
        D_80383010.zoombox[i] = gczoombox_new(D_8036C520[i].y,D_8036C520[i].portrait, (i == 3) ? 1 : 2 , 0,gcpausemenu_803129DC);
        func_803184C8(D_80383010.zoombox[i], 40.0f, 5, 2, 0.3f, 0, 0);
        func_80318640(D_80383010.zoombox[i], 0x46, 0.9f, 0.7f, 1);
        func_80318760(D_80383010.zoombox[i], 8000);
    }
    func_80318734(D_80383010.zoombox[3], 24.0f);
}

void gcpausemenu_80311A84(void){
    s32 i;

    itemPrint_reset();
    for(i = 0; i< 7; i++){
        func_802FACA4(D_8036C604[i]);
    }

    if(func_802FC3C4()){
        D_80383010.unk70_31 = 1;
        func_802FAD64(ITEM_12_JINJOS);
    }else{
        func_802FACA4(ITEM_12_JINJOS);
    }

    if(func_802FD2D4()){
        D_80383010.unk70_30 = 1;
        func_802FAD64(ITEM_16_LIFE);
    }else{
        func_802FACA4(ITEM_16_LIFE);
    }
}

void gcpausemenu_80311B44(void){
    s32 i;
    
    for(i = 0; i<7; i++){
        func_802FAD64(D_8036C604[i]);
    }
    func_802FAD64(ITEM_12_JINJOS);
    func_802FAD64(ITEM_16_LIFE);
}

void gcpausemenu_getLevelNoteScore(enum level_e level, s32 *valPtr, s32 *maxPtr){
    *valPtr = itemscore_noteScores_get(level);
    *maxPtr = 100;
}

void gcpausemenu_getLevelJiggyScore(enum level_e level, s32 *valPtr, s32 *maxPtr){
    *valPtr = jiggyscore_leveltotal(level);
    *maxPtr = 10;
}

void gcpausemenu_getLevelHoneycombScore(enum level_e level, s32 *valPtr, s32 *maxPtr){
    *valPtr = honeycombscore_get_level_total(level);
    *maxPtr = (level == LEVEL_B_SPIRAL_MOUNTAIN)? 6 : 2;
}

char *gcpausemenu_TimeToA(int time){
    s32 hours;
    s32 minutes;
    s32 seconds;
    
    strcpy(D_80383088, "");
    strIToA(D_80383088, time/3600);
    strcat(D_80383088, ":");
    minutes = (time/60)%60;
    if(minutes < 10){
        strcat(D_80383088, "0");
    }
    strIToA(D_80383088, minutes);
    strcat(D_80383088, ":");
    seconds = time % 60;
    if(seconds < 10){
        strcat(D_80383088, "0");
    }
    strIToA(D_80383088, seconds); 
    strcat(D_80383088, "");
    return D_80383088;
}

void gcpausemenu_printLevelTotals(enum level_e level){
    s32 val;
    s32 max;
    char empty[] = {0}; //empty

    //note ratio 2 string
    gcpausemenu_getLevelNoteScore(level, &val, &max);
    strcpy(D_8036C520[0].str, empty);
    strIToA(D_8036C520[0].str, val);
    strcat(D_8036C520[0].str, "/");
    strIToA(D_8036C520[0].str, max);
    strcat(D_8036C520[0].str, empty);

    //jiggy_ratio_2_string
    gcpausemenu_getLevelJiggyScore(level, &val, &max);
    strcpy(D_8036C520[1].str, empty);
    strIToA(D_8036C520[1].str, val);
    strcat(D_8036C520[1].str, "/");
    strIToA(D_8036C520[1].str, max);
    strcat(D_8036C520[1].str, empty);

    //honeycomb_ratio_2_string
    gcpausemenu_getLevelHoneycombScore(level, &val, &max);
    strcpy(D_8036C520[2].str, empty);
    strIToA(D_8036C520[2].str, val);
    strcat(D_8036C520[2].str, "/");
    strIToA(D_8036C520[2].str, max);
    strcat(D_8036C520[2].str, empty);

    //gametime_2_sting
    strcpy(D_8036C520[3].str, empty);
    strcat(D_8036C520[3].str, gcpausemenu_TimeToA(itemscore_timeScores_get(level)));
}

void gcpausemenu_getTotalNoteScore(s32 *dst){
    *dst = itemscore_noteScores_getTotal();
}

void gcpausemenu_getTotalJiggyScore(s32 *dst){
    *dst = jiggyscore_total();
}

void gcpausemenu_getTotalHoneycombScore(s32 *dst){
    *dst = honeycombscore_get_total();
}

void gcpausemenu_printTotals(void){
    s32 val;
    char D_8036C61C[] = {0};

    //note ratio 2 string
    gcpausemenu_getTotalNoteScore(&val);
    strcpy(D_8036C520[0].str, D_8036C61C);
    strIToA(D_8036C520[0].str, val);
    strcat(D_8036C520[0].str, D_8036C61C);

    //jiggy_ratio_2_string
    gcpausemenu_getTotalJiggyScore(&val);
    strcpy(D_8036C520[1].str, D_8036C61C);
    strIToA(D_8036C520[1].str, val);
    strcat(D_8036C520[1].str, D_8036C61C);

    //honeycomb_ratio_2_string
    gcpausemenu_getTotalHoneycombScore(&val);
    strcpy(D_8036C520[2].str, D_8036C61C);
    strIToA(D_8036C520[2].str, val);
    strcat(D_8036C520[2].str, D_8036C61C);

    //gametime_2_sting
    strcpy(D_8036C520[3].str, D_8036C61C);
    strcat(D_8036C520[3].str, gcpausemenu_TimeToA(itemscore_timeScores_getTotal()));
}

s32 gcpausemenu_levelToMenuPage(enum level_e arg0){
    switch (arg0)
    {
    case LEVEL_1_MUMBOS_MOUNTAIN:
    case LEVEL_2_TREASURE_TROVE_COVE:
    case LEVEL_3_CLANKERS_CAVERN:
    case LEVEL_4_BUBBLEGLOOP_SWAMP:
    case LEVEL_5_FREEZEEZY_PEAK:
        return arg0 + 2;

    case LEVEL_6_LAIR:
    case LEVEL_C_BOSS:
        return 2;
    case LEVEL_7_GOBIS_VALLEY:
        return 8;
    case LEVEL_8_CLICK_CLOCK_WOOD:
        return 11;
    case LEVEL_9_RUSTY_BUCKET_BAY:
        return 10;
    case LEVEL_A_MAD_MONSTER_MANSION:
        return 9;
    case LEVEL_B_SPIRAL_MOUNTAIN:
        return 1;
    default:
        return 0;
    }
}

void gcpausemenu_8031209C(struct1As *arg0, s32 arg1){
    s32 i;
    s32 j;

    for(i = 0; i < arg1; i++){//L803120B8
        arg0[i].unkF = 0;
    }
}

void gcPauseMenu_setState(enum gcpausemenu_state_e next_state){
    s32 i;
    switch(next_state){
        case 0:
            gcpausemenu_80311A84();
            D_80383010.unk1 = 0;
            D_80383010.left_joystick_visible = D_80383010.right_joystick_visible = D_80383010.unk3_7 = D_80383010.selection = D_80383010.unk4 = 0;
            break;

        case 1:
            D_80383010.unkC = D_80383010.unk3_6 = D_80383010.unk7 = 0;
            gcpausemenu_8031209C(D_8036C4E0, 4);
            
            for(i = 0; i < 4; i++){
                gczoombox_highlight(D_80383010.zoombox[i], 1);
            }
            if(D_80383010.return_to_lair_disabled){
                gczoombox_highlight(D_80383010.zoombox[1],0);
            }
            break;
        
        case 2:
            D_80383010.unk3_6 = 0;
            break;

        case 3:
            gcpausemenu_80311B44();
            D_80383010.unkC = D_80383010.unk3_6 = 0;
            D_80383010.unk5 = 3;
            gcpausemenu_8031209C(D_8036C4E0, 4);
            break;

        case 5:/* 8B334 803122C4 3C128038 */
            D_80383010.unkC = 3;
            D_80383010.unk5 = D_80383010.unk3_6 = 0;
            gcpausemenu_8031209C(D_8036C4E0, 4);
            for(i = 0; i < 4; i++){
                D_80383010.unk5 += func_803188B4(D_80383010.zoombox[i]);
            }
            break;

        case 6:/* 8B3A8 80312338 0C0C46D1 */
            gcpausemenu_80311B44();
            D_80383010.unkC = 0.0f;
            D_80383010.unk4 = D_80383010.selection = 0;
             // 0;
            for(i = 0; i < 4; i++){
                func_80318964(D_80383010.zoombox[i]);
            }
            break;

        case 7:/* 8B3F4 80312384 44803000 */
            D_80383010.unk1 = 1;
            D_80383010.b_button_visible = 1;
            D_80383010.unk20 = D_80383010.unk28 = 0.0f;
            gcpausemenu_zoomboxes_free();
            gcpausemenu_zoomboxes_initTotalsMenu();
            if(D_80383010.selection == gcpausemenu_levelToMenuPage(level_get())){
                func_802F5060(0x6e7);
            }
            if(D_80383010.selection){
                gcpausemenu_printLevelTotals(D_8036C58C[D_80383010.selection].level_id);
            }else{
                gcpausemenu_printTotals();
            }

            for(i = 0; i<4; i++){//L80312420
                if(D_8036C58C[D_80383010.selection].level_id == 6){
                    gczoombox_highlight(D_80383010.zoombox[i], (!(i == 0) && !(i == 2)));
                }
                else if(D_8036C58C[D_80383010.selection].level_id == 0xB){
                    gczoombox_highlight(D_80383010.zoombox[i], (!(i == 0) && !(i == 1)));
                }
                else{
                    gczoombox_highlight(D_80383010.zoombox[i], 1);
                }
            }
            break;

        case 8: /* 8B54C 803124DC 44809000 */
            D_80383010.unk4 = 0;
            D_80383010.unkC = 0.0f;
            gcpausemenu_8031209C(D_8036C520, 4);
            D_80383010.unk8 = -0x10;
            D_80383010.unk6 = 0xFF;
            D_80383010.unk3_5 = 1;
            break;

        case 0xA:
            D_80383010.unk3_5 = 1;
            D_80383010.unkC = 0.0f;
            D_80383010.unk5 = 4;
            if(D_80383010.unk9 != 0xC){
                D_80383010.b_button_visible = 0;
            }
            gcpausemenu_8031209C(D_8036C520, 4);
            break;

        case 0xB:
            if(D_80383010.selection && D_80383010.selection == gcpausemenu_levelToMenuPage(level_get())){
                func_802F5188();
            }
            gcpausemenu_zoomboxes_free();
            gcpausemenu_zoomboxes_initMainMenu();
            break;

        case 0xC:
            D_80383010.unk1 = 2;
            D_80383010.unk6++;
            D_80383010.unk3_5 = 1;
            D_80383010.unk5 = 0;
            for(i = 0; i<4; i++){
                D_80383010.unk5 += func_803188B4(D_80383010.zoombox[i]);
            }
            break;

        case 0xD:/* 8B694 80312624 3C128038 */
            D_80383010.unk6 = 0xFF;
            D_80383010.unk3_5 = 1;
            if(D_80383010.selection && D_80383010.selection == gcpausemenu_levelToMenuPage(level_get())){
                func_802F5188();
            }
            D_80383010.selection = D_80383010.unk9;
            if(D_80383010.selection && D_80383010.selection == gcpausemenu_levelToMenuPage(level_get())){
                func_802F5060(0x6e7);
            }
            if(D_80383010.selection)
                gcpausemenu_printLevelTotals(D_8036C58C[D_80383010.selection].level_id);
            else{
                gcpausemenu_printTotals();
            }
            for(i = 0; i < 4; i++){//L803126D8
                //L80312764
                if(D_8036C58C[D_80383010.selection].level_id == 6){
                    gczoombox_highlight(D_80383010.zoombox[i], !((i == 0) ||  (i == 2)));
                }
                else if(D_8036C58C[D_80383010.selection].level_id == 0xB){//L80312728
                    gczoombox_highlight(D_80383010.zoombox[i], (!(i == 0) && !(i == 1)));
                }
                else{
                    gczoombox_highlight(D_80383010.zoombox[i], 1);
                }
                if(func_80318604(D_80383010.zoombox[i])){
                    gczoombox_maximize(D_80383010.zoombox[i]);
                    func_803183A4( D_80383010.zoombox[i], D_8036C520[i].str);
                }
                //L8031279C
            }
            break;
        
        case 0xE:/* 8B824 803127B4 3C128038 */
            D_80383010.unk1 = 4;
            D_80383010.selection = D_80383010.unk9;
            D_80383010.unk9 = -1;
            D_80383010.sns_egg_model = assetcache_get(0x50D);
            D_80383010.ice_key_model = assetcache_get(0x50C);
            for(i = 0; i < 7; i++){
                D_80383010.unk3E[i] = randf2(0.0f, 360.0f);
                D_80383010.unk4C[i] =  ((i & 1)? -1.0: 1.0)*randf2( 60.0f, 180.0f);
            }
            break;

        case 0xF: /* 8B8FC 8031288C 3C128038 */
            D_80383010.unk8 = -0x10;
            D_80383010.unk6 = 0xff;
            D_80383010.unk3_5 = D_80383010.sns_visible =  1;
            break;

        case 0x10:
            break;

        case 0x11: /* 8B944 803128D4 3C128038 */
            D_80383010.unk3_5 = 1;
            D_80383010.sns_visible =  0;
            if(D_80383010.unk9 == -1)
                D_80383010.b_button_visible = 0;
            break;

        case 0x12: /* 8B978 80312908 3C128038 */
            D_80383010.selection = D_80383010.unk9;
            func_8033BD20(&D_80383010.sns_egg_model); //free
            func_8033BD20(&D_80383010.ice_key_model); //free
            break;

        case 0x13: /* 8B9A8 80312938 3C128038 */
            D_80383010.unk3_7 = 0;
            break;

        case 0x14: /* 8B9C0 80312950 3C128038 */
            D_80383010.unk3_7 = D_80383010.unk3_6 = 0;
            D_80383010.unkC = 0.0f;
            func_8025A430(-1, 0x7D0, 3);
            func_8025A2B0();
            func_802DC528(0,0);
            break;
        default:
            break;
    }
    D_80383010.state = next_state;
}

void gcpausemenu_803129DC(s32 arg0, s32 arg1) {
    s8 var_t9;
    u8 temp_t6;

    switch (D_80383010.state) {
    case 3:
    case 10:
        if (arg1 == 6) {
            D_80383010.unk4++;
        } else if (arg1 == 4) {
            D_80383010.unk5 = (s8) (D_80383010.unk5 - 1);
        }
        break;
    case 5:
        if (arg1 == 4) {
            D_80383010.unk5 = (s8) (D_80383010.unk5 - 1);
        }
        break;
    case 1:
    case 8:
        if (arg1 == 1) {
            D_80383010.unk4 = (s8) (D_80383010.unk4 + 1);
        }
        break;
    case 12:
        if (arg1 == 4) {
            D_80383010.unk5 = (s8) (D_80383010.unk5 - 1);
        }
        break;
    case 6:
        if (arg1 == 6) {
            D_80383010.unk4++;
        }
        break;
    }
    if( (arg1 == 2) 
        && (D_80383010.unk1 == 0) 
        && (arg0 - 4 != D_80383010.selection)
    ) {
        gczoombox_highlight(D_80383010.zoombox[arg0 - 4], 0);
    }
}

s32 gcpausemenu_initLargestPageIndex(void) {
    s16 *var_s1;
    s32 var_s0;
    s32 var_s3;

    var_s3 = 0;
    if (D_80383010.unk39 != 0) {
        return 0xC; //if any SnS items collected return last page
    }
    for(var_s0 = 1; var_s0 < 0xC; var_s0++){
        if(itemscore_timeScores_get(D_8036C58C[var_s0].level_id) != 0){
            var_s3 = var_s0;
        }
    }
    return var_s3;
}

bool gcpausemenu_isReturnToLairDisabled(void){ return TRUE; }

void gcpausemenu_init(void) {
    s32 i;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 temp_v1;

    for(i = 0; i < 0xC; i++){
        func_802FAD64(D_8036C60C[i]);
    }
    func_802FBB18();
    sp24 = sns_get_item_state(6, 0);
    sp28 = sns_get_item_state(5, 0);
    sp2C = sns_get_item_state(4, 0);
    sp30 = sns_get_item_state(3, 0);
    sp34 = sns_get_item_state(2, 0);
    sp38 = sns_get_item_state(1, 0);
    D_80383010.unk39 = sp38
        + sp34
        + sp30
        + sp2C
        + sp28
        + sp24
        + sns_get_item_state(7, 0);
    D_80383010.return_to_lair_disabled = gcpausemenu_isReturnToLairDisabled();
    func_80311604();
    gcpausemenu_zoomboxes_initMainMenu();
    D_80383010.joystick_sprite = assetcache_get(0x7EB);
    D_80383010.joystick_frame_count = spriteGetFrameCount(D_80383010.joystick_sprite);
     D_80383010.left_joystick_alpha = temp_v1 = D_80383010.right_joystick_alpha =  0;
    D_80383010.joystick_frame = D_80383010.unk3_4 = temp_v1;

    D_80383010.b_button_sprite = assetcache_get(0x7ED);
    D_80383010.b_button_frame_count = spriteGetFrameCount(D_80383010.b_button_sprite);
    D_80383010.b_button_frame = D_80383010.unk3_0 = D_80383010.b_button_alpha = 0;
    D_80383010.page_cnt = gcpausemenu_initLargestPageIndex();
    D_80383010.sns_alpha = D_80383010.sns_visible = D_80383010.unk70_31 = D_80383010.unk70_30 = 0;
    rumbleManager_80250FC0();
    gcPauseMenu_setState(0);
}

s32 gcpausemenu_80312D78(struct1As *arg0, s32 arg1) {
    s32 var_s2;
    s32 var_s4;
    s32 var_v0;

    var_s4 = 0;
    for(var_s2 = 0; var_s2 < arg1; var_s2++){
        if (arg0[var_s2].delay <= D_80383010.unkC) {
            if (!arg0[var_s2].unkF) {
                var_v0 = func_803183A4(D_80383010.zoombox[var_s2], arg0[var_s2].str) ? TRUE : FALSE;
                arg0[var_s2].unkF = var_v0;
                if (arg0[var_s2].unkF) {
                    gczoombox_open(D_80383010.zoombox[var_s2]);
                    gczoombox_maximize(D_80383010.zoombox[var_s2]);
                }
                if (!func_80318604(D_80383010.zoombox[var_s2])) {
                    func_80318498(D_80383010.zoombox[var_s2]);
                    func_8031843C(D_80383010.zoombox[var_s2]);
                }
            }
        }
        if (arg0[var_s2].unkF) {
            var_s4++;
        }
    }
    return var_s4;
}

void gcpausemenu_80312E80(struct1As *arg0, s32 arg1) {
    f32 var_f0;
    s32 var_s1;

    for(var_s1 = 0; var_s1 < arg1; var_s1++){
        var_f0 = ((var_s1 == D_80383010.selection) && (D_80383010.unk1 == 0)) ? 0.2 :  arg0[var_s1].unk4;
            if (var_f0 <= D_80383010.unkC) {
                if (arg0[var_s1].unkF == 0) {
                    func_80318498(D_80383010.zoombox[var_s1]);
                    if (func_803188B4(D_80383010.zoombox[var_s1]) == 0) {
                        D_80383010.unk5--;
                    }
                    arg0[var_s1].unkF = 1U;
                }
            }
    }
}

void gcpausemenu_printTotalsHeader(s32 page_id){
    struct1Cs_1 *v0 = D_8036C58C + page_id;
    print_bold_overlapping(v0->x, D_80383010.unk8, -1.05f, v0->string);
}

void gcpausemenu_80312FD0(s32 arg0) {
    s32 temp_v1;
    if (D_80383010.unk3_5) {
        if (arg0 > 0) {
            D_80383010.unk6++;
            temp_v1 = D_8036C5F4[D_80383010.unk6];
            D_80383010.unk8 += temp_v1;
            if (D_80383010.unk6 == 0xC) {
                D_80383010.unk3_5 = FALSE;
            }
        } else {
            D_80383010.unk6--;
            temp_v1 = D_8036C5F4[D_80383010.unk6];
            D_80383010.unk8 -= temp_v1;
            if (D_80383010.unk6 == 0) {
                D_80383010.unk3_5 = FALSE;
            }
        }
    }
}

s32 gcpausemenu_getMaxPage(void){
    return D_80383010.page_cnt;
}

void gcpausemenu_getNextPage(s32 arg0) {
    D_80383010.unk9 = D_80383010.selection;
    do{
        D_80383010.unk9 += arg0;
        if((D_80383010.unk39 != 0) && (D_80383010.unk9 == 0xC))
                break;
    }
    while( (D_80383010.unk9 != 0) && itemscore_timeScores_get(D_8036C58C[D_80383010.unk9].level_id) == 0);
    gcPauseMenu_setState((D_80383010.unk9 == 0xC) ? 0xA : 0xC);
    D_80383010.unk7 = 6;
}

void gcpausemenu_updateBButtonAndJoystickSprites(void) {
    f32 temp_f12;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f12;
    s8 temp_a0;
    u8 temp_a0_2;
    u8 temp_t0;
    u8 temp_v0;
    u8 temp_v0_2;

    D_80383010.unk20 += time_getDelta();
    var_f0 = (D_80383010.unk3_4) ? 0.05 :  0.066666666666666666;
    while (var_f0 < D_80383010.unk20) {
        if (D_80383010.unk3_4) {
            if (D_80383010.joystick_frame-- == 0) {
                D_80383010.joystick_frame = 0;
                D_80383010.unk3_4 = FALSE;
                var_f0 = 0.066666666666666666;
            }
        } else {
            D_80383010.joystick_frame++;
            if (D_80383010.joystick_frame >= D_80383010.joystick_frame_count) {
                D_80383010.unk3_4 = TRUE;
                D_80383010.joystick_frame = D_80383010.joystick_frame_count - 1;
                var_f0 = 0.05f;
            }
        }
        D_80383010.unk20 -= var_f0;
    }
    D_80383010.left_joystick_visible = (D_80383010.selection != 0) ? TRUE : FALSE;
    D_80383010.right_joystick_visible = (gcpausemenu_getMaxPage() == D_80383010.selection) ? FALSE : TRUE;
    D_80383010.unk28 += time_getDelta();

    var_f12 = (D_80383010.unk3_0) ? 0.04 : 0.04;
    while (D_80383010.unk28 > var_f12) {
            if (D_80383010.unk3_0) {
                if (D_80383010.b_button_frame-- <= 0) {
                    D_80383010.b_button_frame = 0;
                    D_80383010.unk3_0 = FALSE;
                    var_f12 = 0.04;
                }
            } else {
                D_80383010.b_button_frame++;
                if (D_80383010.b_button_frame >= D_80383010.b_button_frame_count) {
                    D_80383010.unk3_0 = TRUE;
                    D_80383010.b_button_frame = D_80383010.b_button_frame_count - 1;
                    var_f12 = 0.04;
                }
            }
            D_80383010.unk28 -= var_f12;
            if(var_f12);
    }
}

s32 gcPauseMenu_update(void){
    s32 i;
    s32 face_button[6];
    s32 sp60[3];
    s32 sp50[4];
    f32 joystick[2];
    s32 level = level_get(); //sp44
    
    
    if(getGameMode() != GAME_MODE_4_PAUSED)
        return 0;
    
    func_8024E55C(0, face_button);
    func_8024E71C(0, joystick);
    func_8024E60C(0, sp60);
    func_8024E6E0(0, sp50);
    func_80310D2C();
    for(i = 0; i < 4; i++){
        gczoombox_update(D_80383010.zoombox[i]);//gczoombox_update;
    }

    
    D_80383010.unkC += time_getDelta();
    switch(D_80383010.state){
        case PAUSE_STATE_0_CLOSED: //closed
            gcPauseMenu_setState(PAUSE_STATE_1_OPENING); 
            break;

        case PAUSE_STATE_1_OPENING: //opening
            if(gcpausemenu_80312D78(D_8036C4E0, 4) == 4){
                if(((D_80383010.return_to_lair_disabled)? 3: 4 ) == D_80383010.unk4){
                    D_80383010.unk4 = 0;
                    gcPauseMenu_setState(2);
                }
            }
            if(func_8024E67C(0) == 1){
                gcPauseMenu_setState(6);
            }
            break;

        case 2: //open
            if(D_80383010.unk70_31 && !func_802FC3C4()){
                func_802FACA4(ITEM_12_JINJOS);
                D_80383010.unk70_31 = 0;
            }//L8031350C
            if(D_80383010.unk70_30 && !func_802FD2D4()){
                func_802FACA4(ITEM_16_LIFE);
                D_80383010.unk70_30 = 0;
            }
            if(func_8024E67C(0) == 1){
                gcPauseMenu_setState(6);
            }else if(face_button[FACE_BUTTON(BUTTON_A)] == 1){
                switch(D_80383010.selection){
                    case 1://L80313594
                        if(level > 0 && level < 0xC)
                            if(D_8036C560[level-1].map != -1)
                                gcPauseMenu_setState(5);
                        break;
                    case 3://L803135D0
                        gcPauseMenu_setState(5);
                        break;
                    default://L803135E4
                        gcPauseMenu_setState(3);
                        break;
                }
            }
            else if(face_button[FACE_BUTTON(BUTTON_B)] == 1){//L803135F8
                gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], 0);
                D_80383010.selection = 0;
                gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], 1);
                gcPauseMenu_setState(3);
            }
            else if(D_80383010.unk7 > 0) {//L8031364C
                D_80383010.unk7--;
            }//L80313664
            else {
                if( D_80383010.selection == 2 && !D_80383010.unk3_6){
                    func_803160A8(D_80383010.zoombox[D_80383010.selection]);
                    D_80383010.unk3_6 = 1;
                }
                if(0.75 < joystick[JOYSTICK_Y]){
                    if((s32)D_80383010.selection > 0){
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], FALSE);
                        D_80383010.selection--;
                        if(D_80383010.return_to_lair_disabled && D_80383010.selection == 1)
                            D_80383010.selection --;
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], TRUE);
                        func_803160A8(D_80383010.zoombox[D_80383010.selection]);
                        D_80383010.unk3_6 = 0;
                        D_80383010.unk7 = 6;
                    }
                }else if(joystick[JOYSTICK_Y] < -0.75){
                    if((s32)D_80383010.selection < 3){
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], 0);
                        D_80383010.selection++;
                        if(D_80383010.return_to_lair_disabled && D_80383010.selection == 1)
                            D_80383010.selection++;
                        gczoombox_highlight(D_80383010.zoombox[D_80383010.selection], 1);
                        func_803160A8(D_80383010.zoombox[D_80383010.selection]);
                        D_80383010.unk3_6 = 0;
                        D_80383010.unk7 = 6;
                    }
                }
            }
            if(D_80383010.selection == 2 && !D_80383010.unk3_6 && D_80383010.unk7 == 3){
                func_803160A8(D_80383010.zoombox[D_80383010.selection]);
                D_80383010.unk3_6 = 1;
            }
            break;
        
        case 3: //returning to game
            gcpausemenu_80312E80(D_8036C4E0,4);
            if(D_80383010.unk5 <= 0){
                for(i = 0; i<4; i++){
                    gczoombox_close(D_80383010.zoombox[i]);
                }
                D_80383010.unk5 = 0x7F;
            }
            if(D_80383010.unk4 == 4){
                D_80383010.unk4 = 0;
                gcPauseMenu_setState(4);
            }
            break;
        case 4:
            switch(D_80383010.selection){
                case 0://L803138FC
                    D_80383010.unk3_7 = 1;
                    break;
                case 1://L80313908 //return to lair
                    func_803204E4(0x16, 1);
                    if(map_get() == MAP_8E_GL_FURNACE_FUN){
                        func_803204E4(0,0);
                        func_802E4078(MAP_80_GL_FF_ENTRANCE, 2, 1);
                    }else{
                        func_802E4078(D_8036C560[level-1].map, D_8036C560[level-1].exit, 1);
                    }
                    gcPauseMenu_setState(0x13);
                    break;
                case 2://L80313978
                    D_80383010.selection = gcpausemenu_levelToMenuPage(level_get());
                    gcPauseMenu_setState(7);
                    break;
                case 3://L8031399C
                    func_802C5994();
                    func_803204E4(0,0);
                    if(!fileProgressFlag_get(FILEPROG_BD_ENTER_LAIR_CUTSCENE) || fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)){
                        gcPauseMenu_setState(0x14);
                    }else{
                        func_802E412C(1,0);
                        func_802E4078(MAP_83_CS_GAME_OVER_MACHINE_ROOM, 0, 1);
                        gcPauseMenu_setState(0x13);
                    }
                    break;
            }
            break;
            case 5:
                if(3.0 < D_80383010.unkC){
                    if( D_8036C4E0[D_80383010.selection].unkF){
                        gczoombox_minimize(D_80383010.zoombox[D_80383010.selection]);
                    }
                    D_80383010.unk3_6 ^= 1;
                    gczoombox_maximize(D_80383010.zoombox[D_80383010.selection]);
                    if(D_8036C4E0[D_80383010.selection].unkF = func_803183A4(D_80383010.zoombox[D_80383010.selection], (D_80383010.unk3_6)? "ARE YOU SURE?" : "A - YES, B - NO"))
                        D_80383010.unkC = 0.0;
                }//L80313AF4
                if(func_8024E67C(0) == 1){
                    gcPauseMenu_setState(6);
                }else if(face_button[FACE_BUTTON(BUTTON_B)] == 1){
                    D_80383010.unk4 = (D_80383010.return_to_lair_disabled)? 3 : 4;
                    func_803188B4(D_80383010.zoombox[D_80383010.selection]);
                    gcPauseMenu_setState(1);
                }else if(face_button[FACE_BUTTON(BUTTON_A)] == 1){//L80313B68
                    gcPauseMenu_setState(3);
                }
                break;

            case 6://80313B80
                if(D_80383010.unk4 == 4){
                    if(0.2 < D_80383010.unkC){
                        D_80383010.unk4 = 0;
                        gcPauseMenu_setState(4);
                    }
                }
                break;
            
            case 7:
                gcPauseMenu_setState(8);
                break;
            case 8:
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(1);
                gcpausemenu_80312D78(D_8036C520,4);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(D_80383010.unk4 == 4){
                    D_80383010.unk4 = 0;
                    gcPauseMenu_setState(9);
                }
                break;
            case 9:
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(1);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(func_8024E67C(0) == 1){
                    D_80383010.unk1 = 3;
                    gcPauseMenu_setState(0xA);
                }else if(face_button[FACE_BUTTON(BUTTON_B)] == 1){
                    gcPauseMenu_setState(0xA);
                }else if(0.75 < joystick[JOYSTICK_X]){
                    if((s32)D_80383010.selection < gcpausemenu_getMaxPage())
                        gcpausemenu_getNextPage(1);
                }else if(joystick[JOYSTICK_X] < -0.75){//L80313CCC
                    if((s32)D_80383010.selection > 0){
                        gcpausemenu_getNextPage(-1);
                    }
                }
                break;
            
            case 0xA://80313D00
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(-1);
                gcpausemenu_80312E80(D_8036C520, 4);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(D_80383010.unk9 != 0xC){
                    D_80383010.left_joystick_visible = 0;
                    D_80383010.right_joystick_visible = 0;
                }//L80313D50
                if(!D_80383010.unk5){
                    for(i = 0; i < 4; i++){
                        gczoombox_close(D_80383010.zoombox[i]);
                    }
                    D_80383010.unk5 = 1;
                }//L80313D8C
                if( D_80383010.unk4 == 4){
                     D_80383010.unk4 = 0;
                    gcPauseMenu_setState(0xB);
                }
                break;
            
            case 0xB:
                if(D_80383010.unk1 == 3){
                    D_80383010.unk3_7 = 1;
                }
                else{
                    gcPauseMenu_setState((D_80383010.unk9 == 0xC)? 0xE : 0);
                }
                break;

            case 0xC: //Flip to Sns Total page
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(-1);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(D_80383010.unk5 == 0 && !D_80383010.unk3_5){
                    gcPauseMenu_setState(0xd);
                }
                break;
            
            case 0xD: //Open SnS Total Page
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(1);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(D_80383010.unk7 > 0)
                    D_80383010.unk7--;
                else
                   gcPauseMenu_setState(9);
                break;

            case 0xE:
                gcPauseMenu_setState(0xF);
                break;

            case 0xF:
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(1);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(!D_80383010.unk3_5){
                    gcPauseMenu_setState(0x10);
                }
                break;
            
            case 0x10:
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(func_8024E67C(0) == 1){
                    D_80383010.unk1 = 3;
                    gcPauseMenu_setState(0x11);
                }//L80313EFC
                else if(face_button[FACE_BUTTON(BUTTON_B)] == 1){
                    gcPauseMenu_setState(0x11);
                }
                else if(joystick[JOYSTICK_X] < -0.75){
                    gcpausemenu_getNextPage(-1);
                    gcPauseMenu_setState(0x11);
                }
                break;

            case 0x11:
                gcpausemenu_printTotalsHeader(D_80383010.selection);
                gcpausemenu_80312FD0(-1);
                gcpausemenu_updateBButtonAndJoystickSprites();
                if(D_80383010.unk9 == -1){
                    D_80383010.left_joystick_visible = 0;
                    D_80383010.right_joystick_visible = 0;
                }
                if(D_80383010.sns_alpha == 0){
                    gcPauseMenu_setState(0x12);
                }
                break;

            case 0x12:
                if(D_80383010.unk1 == 3){
                    D_80383010.unk3_7 = 1;
                }else{
                    gcPauseMenu_setState((D_80383010.unk9 != -1)?7:0);
                }
                break;

            case 0x14:
                func_802DC5B8();
                if( 5.0 < D_80383010.unkC){
                    if(!D_80383010.unk3_6){
                        func_802DC560(0,0);
                        func_802E412C(1,0);
                        func_802E4078(0x1f, 0, 1);
                        D_80383010.unk3_6 = 1;
                    }
                }
                break;

    }
    return D_80383010.unk3_7;
}

void __gcpausemenu_drawSprite(Gfx** gdl, Mtx** mptr, Vtx** vptr, BKSprite* sprite, s32 frame, f32 x, f32 y, f32 w, f32 h, u8 a){
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    BKSpriteFrame *_frame;
    f32 sp2C;
    f32 sp28;
    
    _frame = spriteGetFramePtr(sprite, frame);
    sp2C = _frame->w;
    sp28 = _frame->h;
    func_803382E4(5);
    func_80338338(0xFF, 0xFF, 0xFF);
    func_803382FC(a);
    func_8033837C(0);
    viewport_get_position_vec3f(sp50);
    
    sp34 = func_8024DE1C(x, y, sp5C, sp44);
    mlMtxIdent(); //matrix_stack_identity
    sp38[0] = sp5C[0] - sp50[0];
    sp38[1] = sp5C[1] - sp50[1];
    sp38[2] = sp5C[2] - sp50[2];
    mlMtxTranslate(sp38[0], sp38[1], sp38[2]); //mtx_translate
    mlMtxRotYaw(sp44[1]); //mtx_rot_yaw
    mlMtxRotPitch(sp44[0]); //mtx_rot_pitch
    mlMtxRotRoll(sp44[2]); //mtx_rot_roll
    mlMtxScale_xyz((sp34 * w)/sp2C, (sp34 * h)/sp28, sp34);
    mlMtxApply(*mptr); //add matrix;
    gSPMatrix((*gdl)++, (*mptr)++, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    func_80338308((s32)sp2C, (s32)sp28);
    spriteRender_draw(gdl, vptr, sprite, frame);
    gSPPopMatrix((*gdl)++, G_MTX_MODELVIEW);
}


void gcpausemenu_drawSprite(Gfx** gdl, Mtx** mptr, Vtx **vptr, BKSprite *sprite, s32 frame, f32 x, f32 y, s32 mirror, u8 a){
    BKSpriteFrame *_frame; 
    s32 w;
    s32 h;
    _frame = spriteGetFramePtr(sprite, frame);
    w = ((mirror)? -1 : 1) * _frame->w;
    h = _frame->h;
    __gcpausemenu_drawSprite(gdl, mptr, vptr, sprite, frame, (x - w * 0.5), (y - h * 0.5), w, h, a);
}

void gcpausemenu_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    static int D_8036C620 = 1;
    s32 var_a0;

    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp7C;
    s32 var_s0_2;
    s32 i;

    if (getGameMode() != GAME_MODE_4_PAUSED) {
        if (!D_8036C620) {
            func_803151D0(gfx, mtx, vtx);
        }
        D_8036C620 = TRUE;
        return;
    }

    if (D_8036C620) {
        func_8033B61C();
        func_80315084(gfx, mtx, vtx);
        D_8036C620 = FALSE;
    } else {
        func_80315110(gfx, mtx, vtx);
    }

    for(i = 0; i < 4; i++){
        gczoombox_draw(D_80383010.zoombox[i], gfx, mtx, vtx);
    }

    gcpausemenu_drawSprite(gfx, mtx, vtx, D_80383010.joystick_sprite, D_80383010.joystick_frame, 30.0f, 196.0f, 1, (s32) D_80383010.left_joystick_alpha);
    gcpausemenu_drawSprite(gfx, mtx, vtx, D_80383010.joystick_sprite, D_80383010.joystick_frame, (f32) (framebuffer_width - 0x1E), 196.0f, 0, (s32) D_80383010.right_joystick_alpha);
    var_a0 =((*((u32 *)&D_80383010.state) << 0x1c) >> 0x1f); //left_joystick_visible
    if ( var_a0 != 0) {
        if (D_80383010.left_joystick_alpha < 0xFF) {
            D_80383010.left_joystick_alpha = (D_80383010.left_joystick_alpha + 0xC < 0xFF) ?D_80383010.left_joystick_alpha + 0xC : 0xFF;
        }
    }
    var_a0 =((*((u32 *)&D_80383010.state) << 0x1c) >> 0x1f); //left_joystick_visible
    if (var_a0 == 0) {
        if (D_80383010.left_joystick_alpha > 0) {
            D_80383010.left_joystick_alpha = (D_80383010.left_joystick_alpha - 0xC > 0) ? D_80383010.left_joystick_alpha - 0xC :  0;
        }
    }
    if (((*((u32 *)&D_80383010.state) << 0x1d) >> 0x1f) != 0) { //right_joystick_visible
        if (D_80383010.right_joystick_alpha < 0xFF) {
            D_80383010.right_joystick_alpha = (D_80383010.right_joystick_alpha + 0xC < 0xFF) ? D_80383010.right_joystick_alpha + 0xC : 0xFF;
        }
    }
    if (((*((u32 *)&D_80383010.state) << 0x1d) >> 0x1f) == 0) {//right_joystick_visible
        if (D_80383010.right_joystick_alpha > 0) {
            D_80383010.right_joystick_alpha = (D_80383010.right_joystick_alpha - 0xC > 0) ? D_80383010.right_joystick_alpha - 0xC : 0;
        }
    }
    gcpausemenu_drawSprite(gfx, mtx, vtx, D_80383010.b_button_sprite, (s32) D_80383010.b_button_frame, framebuffer_width * 0.5, 196.0f, 0, (s32) D_80383010.b_button_alpha);
    var_a0 = ((*((u32 *)&D_80383010.state) << 0x1e) >> 0x1f);//b_button_visible
    if (var_a0 != 0) {
        if (D_80383010.b_button_alpha < 0xFF) {
            D_80383010.b_button_alpha = (D_80383010.b_button_alpha + 0xC < 0xFF) ? D_80383010.b_button_alpha + 0xC : 0xFF;

        }
    }
    
    if (var_a0 == 0) { //b_button_visible
        if (D_80383010.b_button_alpha > 0) {
            D_80383010.b_button_alpha = (D_80383010.b_button_alpha - 0xC > 0) ? D_80383010.b_button_alpha - 0xC : 0;
        }
    }

    if (D_80383010.sns_alpha != 0) {
        sp7C = time_getDelta();
        for(i = 1; i < 7; i++){
            if (sns_get_item_state(i, 0)) {
                D_80383010.unk3E[i] += (f32) D_80383010.unk4C[i] * sp7C;
                if (D_80383010.unk3E[i] > 360.0) {
                    D_80383010.unk3E[i] -= 360.0;
                }
                if (D_80383010.unk3E[i] < 0.0) {
                    D_80383010.unk3E[i] += 360.0;
                }
                func_8024E258();
                sp98[0] = ((i-1)*0.4)*360 + -360.0f;
                sp98[1] = 0.0f;
                sp98[2] = 1000.0f;

                sp8C[0] = 0.0f;
                sp8C[1] = 0.0f;
                sp8C[2] = 0.0f;
                viewport_set_position_vec3f(sp98);
                viewport_set_rotation_vec3f(sp8C);
                viewport_update();
                func_8024C904(gfx, mtx);
                sp98[0] = 0.0f;
                sp98[1] = 0.0f;
                sp98[2] = 0.0f;

                sp8C[0] = 0.0f;
                sp8C[1] = D_80383010.unk3E[i];
                sp8C[2] = 0.0f;

                sp80[0] = 0.0f;
                sp80[1] = -50.0f;
                sp80[2] = 0.0f;
                
                for(var_s0_2 = 0; var_s0_2 < 7; var_s0_2++){
                    func_8033A45C(var_s0_2 + 1, 0);
                }
                func_8033A45C(i, 1);
                modelRender_setDepthMode(MODEL_RENDER_DEPTH_NONE);
                modelRender_setAlpha(D_80383010.sns_alpha);
                modelRender_draw(gfx, mtx, sp98, sp8C, 0.8f, sp80, D_80383010.sns_egg_model);
                func_8024E2FC();
                func_8024C904(gfx, mtx);
            }
        }
        if (sns_get_item_state(7, 0)) {
            D_80383010.unk3E[0] += D_80383010.unk4C[0] * sp7C;
            if (D_80383010.unk3E[0] > 360.0) {
                D_80383010.unk3E[0] -= 360.0;
            }
            if (D_80383010.unk3E[0] < 0.0) {
                D_80383010.unk3E[0] += 360.0;
            }
            func_8024E258();

            sp98[0] = 0.0f;
            sp98[1] = 0.0f;
            sp98[2] = 1000.0f;

            sp8C[0] = 0.0f;
            sp8C[1] = 0.0f;
            sp8C[2] = 0.0f;

            viewport_set_position_vec3f(sp98);
            viewport_set_rotation_vec3f(sp8C);
            viewport_update();
            func_8024C904(gfx, mtx);

            sp98[0] = 0.0f;
            sp98[1] = 0.0f;
            sp98[2] = 0.0f;

            sp8C[0] = 0.0f;
            sp8C[1] = D_80383010.unk3E[0];
            sp8C[2] = 0.0f;

            sp80[0] = 0.0f;
            sp80[1] = 120.0f;
            sp80[2] = 0.0f;
            modelRender_setDepthMode(MODEL_RENDER_DEPTH_NONE);
            modelRender_setAlpha(D_80383010.sns_alpha);
            modelRender_draw(gfx, mtx, sp98, sp8C, 0.8f, sp80, D_80383010.ice_key_model);
            func_8024E2FC();
            func_8024C904(gfx, mtx);
        }
    }

    if (D_80383010.sns_visible != 0) {
        if (D_80383010.sns_alpha < 0xFF) {
            D_80383010.sns_alpha = (D_80383010.sns_alpha + 0xC < 0xFF) ?  D_80383010.sns_alpha + 0xC : 0xFF;
        }
    }

    if (D_80383010.sns_visible == 0) {
        if (D_80383010.sns_alpha > 0) {
            D_80383010.sns_alpha = (D_80383010.sns_alpha - 0xC > 0) ?  D_80383010.sns_alpha - 0xC : 0;
        }
    }

    if (D_80383010.state == 0x14) {
        func_802DC604(gfx, mtx, vtx);
    }
}

void gcpausemenu_80314AC8(int arg0){
    if(arg0)
        D_80383084--;
    else
        D_80383084++;
}

int gcpausemenu_80314B00(void){
    return (!D_80383084) ? 1: 0;
}

void gcpausemenu_80314B24(void){
    D_80383084 = 0;
}

void gcpausemenu_returnToLair(void){
    s32 level = level_get();
    if(0 < level && level < 0xC && D_8036C560[level-1].map != -1){
        func_803204E4(0x16, TRUE);
        func_802E4078(D_8036C560[level-1].map, D_8036C560[level-1].exit, 1);
    }
}
