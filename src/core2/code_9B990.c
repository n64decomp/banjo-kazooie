#include <ultra64.h>
#include "functions.h"
#include "variables.h"

struct level_overlay_map_s {
    s16 level_id;
    s16 overlay_id;
};

typedef void (*level_overlay_init_callback_f)(void);
typedef void (*level_overlay_update_callback_f)(void);
typedef void (*level_overlay_release_callback_f)(void);
typedef void (*level_overlay_draw_callback_f)(Gfx **, Mtx **, Vtx **);
typedef void (*level_overlay_unk14_callback_f)(s32, s32);

struct level_overlay_callbacks_s {
    s16 overlay_id;
    u8 init_flag; // set everywhere, except for FP
    u8 release_flag; // set only for FP
    level_overlay_init_callback_f init;
    level_overlay_update_callback_f update;
    level_overlay_release_callback_f release;
    level_overlay_draw_callback_f draw;
    level_overlay_unk14_callback_f unk14;
};

struct level_overlay_active_callbacks_s {
    u8 init_flag; // set everywhere, except for FP
    u8 release_flag; // set only for FP
    u16 padding;
    level_overlay_init_callback_f init;
    level_overlay_update_callback_f update;
    level_overlay_release_callback_f release;
    level_overlay_draw_callback_f draw;
    level_overlay_unk14_callback_f unk14;
};

static void leveloverlay_MMM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_MMM_release(void); 
static void leveloverlay_MMM_init(void);
static void leveloverlay_MMM_update(void);
static void leveloverlay_MMM_unk14(s32, s32);
static void leveloverlay_CC_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_CC_release(void); 
static void leveloverlay_CC_init(void);
static void leveloverlay_CC_update(void);
static void leveloverlay_CC_unk14(s32, s32);
static void leveloverlay_GV_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_GV_release(void); 
static void leveloverlay_GV_init(void);
static void leveloverlay_GV_update(void);
static void leveloverlay_GV_unk14(s32, s32);
static void leveloverlay_TTC_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_TTC_release(void); 
static void leveloverlay_TTC_init(void);
static void leveloverlay_TTC_update(void);
static void leveloverlay_TTC_unk14(s32, s32);
static void leveloverlay_MM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_MM_release(void); 
static void leveloverlay_MM_init(void);
static void leveloverlay_MM_update(void);
static void leveloverlay_MM_unk14(s32, s32);
static void leveloverlay_BGS_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_BGS_release(void); 
static void leveloverlay_BGS_init(void);
static void leveloverlay_BGS_update(void);
static void leveloverlay_BGS_unk14(s32, s32);
static void leveloverlay_SM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_SM_release(void); 
static void leveloverlay_SM_init(void);
static void leveloverlay_SM_update(void); 
static void leveloverlay_SM_unk14(s32, s32);
static void leveloverlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_lair_release(void); 
static void leveloverlay_lair_init(void);
static void leveloverlay_lair_update(void);
static void leveloverlay_lair_unk14(s32, s32);
static void leveloverlay_fight_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_fight_release(void); 
static void leveloverlay_fight_init(void);
static void leveloverlay_fight_update(void);
static void leveloverlay_fight_unk14(s32, s32);
static void leveloverlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_intro_release(void); 
static void leveloverlay_intro_init(void);
static void leveloverlay_intro_update(void);
static void leveloverlay_intro_unk14(s32, s32);
static void leveloverlay_FP_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void leveloverlay_FP_release(void); 
static void leveloverlay_FP_init(void);
static void leveloverlay_FP_update(void);
static void leveloverlay_FP_unk14(s32, s32);

static struct level_overlay_map_s sLevelOverlayMap[] = {
    { LEVEL_3_CLANKERS_CAVERN,       OVERLAY_2_WHALE },
    { LEVEL_A_MAD_MONSTER_MANSION,   OVERLAY_3_HAUNTED },
    { LEVEL_7_GOBIS_VALLEY,          OVERLAY_4_DESERT },
    { LEVEL_2_TREASURE_TROVE_COVE,   OVERLAY_5_BEACH },
    { LEVEL_1_MUMBOS_MOUNTAIN,       OVERLAY_6_JUNGLE },
    { LEVEL_4_BUBBLEGLOOP_SWAMP,     OVERLAY_7_SWAMP },
    { LEVEL_9_RUSTY_BUCKET_BAY,      OVERLAY_8_SHIP },
    { LEVEL_5_FREEZEEZY_PEAK,        OVERLAY_9_SNOW },
    { LEVEL_8_CLICK_CLOCK_WOOD,      OVERLAY_A_TREE },
    { LEVEL_B_SPIRAL_MOUNTAIN,       OVERLAY_B_TRAINING },
    { LEVEL_D_CUTSCENE,              OVERLAY_C_INTRO },
    { LEVEL_6_LAIR,                  OVERLAY_D_WITCH },
    { LEVEL_C_BOSS,                  OVERLAY_E_BATTLE },
    { 0 }
};

static struct level_overlay_callbacks_s sLevelOverlayCallbacks[] = {
    { OVERLAY_2_WHALE,    1, 0, leveloverlay_CC_init,    leveloverlay_CC_update,    leveloverlay_CC_release,    leveloverlay_CC_draw,    leveloverlay_CC_unk14 },
    { OVERLAY_3_HAUNTED,  1, 0, leveloverlay_MMM_init,   leveloverlay_MMM_update,   leveloverlay_MMM_release,   leveloverlay_MMM_draw,   leveloverlay_MMM_unk14 },
    { OVERLAY_4_DESERT,   1, 0, leveloverlay_GV_init,    leveloverlay_GV_update,    leveloverlay_GV_release,    leveloverlay_GV_draw,    leveloverlay_GV_unk14 },
    { OVERLAY_5_BEACH,    1, 0, leveloverlay_TTC_init,   leveloverlay_TTC_update,   leveloverlay_TTC_release,   leveloverlay_TTC_draw,   leveloverlay_TTC_unk14 },
    { OVERLAY_6_JUNGLE,   1, 0, leveloverlay_MM_init,    leveloverlay_MM_update,    leveloverlay_MM_release,    leveloverlay_MM_draw,    leveloverlay_MM_unk14 },
    { OVERLAY_7_SWAMP,    1, 0, leveloverlay_BGS_init,   leveloverlay_BGS_update,   leveloverlay_BGS_release,   leveloverlay_BGS_draw,   leveloverlay_BGS_unk14 },
    { OVERLAY_B_TRAINING, 1, 0, leveloverlay_SM_init,    leveloverlay_SM_update,    leveloverlay_SM_release,    leveloverlay_SM_draw,    leveloverlay_SM_unk14 },
    { OVERLAY_C_INTRO,    1, 0, leveloverlay_intro_init, leveloverlay_intro_update, leveloverlay_intro_release, leveloverlay_intro_draw, leveloverlay_intro_unk14 },
    { OVERLAY_D_WITCH,    1, 0, leveloverlay_lair_init,  leveloverlay_lair_update,  leveloverlay_lair_release,  leveloverlay_lair_draw,  leveloverlay_lair_unk14 },
    { OVERLAY_E_BATTLE,   1, 0, leveloverlay_fight_init, leveloverlay_fight_update, leveloverlay_fight_release, leveloverlay_fight_draw, leveloverlay_fight_unk14 },
    { OVERLAY_9_SNOW,     0, 1, leveloverlay_FP_init,    leveloverlay_FP_update,    leveloverlay_FP_release,    leveloverlay_FP_draw,    leveloverlay_FP_unk14 },
    { 0 }
};

static struct level_overlay_active_callbacks_s sActiveCallbacks;

static void leveloverlay_MMM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_MMM_release(void) {
    func_8038953C();
    MMM_func_80389CD8();
    func_8038A994();
}

static void leveloverlay_MMM_init(void) {
    func_80389544();
    func_80389CE0();
    func_8038A9B4();
}

static void leveloverlay_MMM_update(void) {
    func_8038966C();
    maOrgan_update();
    func_8038AA44();
}

static void leveloverlay_MMM_unk14(s32 arg0, s32 arg1) {
    code3420_handleOrganGame(arg0, arg1);
}

static void leveloverlay_CC_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) { 
    maClanker_draw(gfx, mtx, vtx);
}

static void leveloverlay_CC_release(void) {
    maClanker_release();
    maClankerRings_release();
}

static void leveloverlay_CC_init(void) {
    maClanker_init();
    maClankerRings_init();
}

static void leveloverlay_CC_update(void) {
    maClanker_update();
    maClankerRings_update();
}

static void leveloverlay_CC_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_GV_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}


static void leveloverlay_GV_release(void) {
    func_8038FF60();
    func_803900F8();
    gv_matchingGame_reset();
    gv_waterCtrl_end();
}

static void leveloverlay_GV_init(void) {
    func_8038FF68();
    func_80390100();
    gv_matchingGame_init();
    gv_waterCtrl_init();
}

static void leveloverlay_GV_update(void) {
    func_8038FFF4();
    func_80390138();
    gv_matchingGame_update();
    gv_waterCtrl_update();
}

static void leveloverlay_GV_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_TTC_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_TTC_release(void) {
    maCastle_release();
}

static void leveloverlay_TTC_init(void) {
    maCastle_init();
}

static void leveloverlay_TTC_update(void) {
    maCastle_update();
}

static void leveloverlay_TTC_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_SM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_SM_release(void) {}

static void leveloverlay_SM_init(void) {}

static void leveloverlay_SM_update(void) {}

static void leveloverlay_SM_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_lair_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) { 
    lair_func_8038E768(gfx, mtx, vtx); 
}

static void leveloverlay_lair_release(void) {
    lair_func_8038CD48();
}

static void leveloverlay_lair_init(void) {
    ff_init();
}

static void leveloverlay_lair_update(void) {
    lair_func_8038E0B0();
}

static void leveloverlay_lair_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_fight_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_fight_release(void) {}

static void leveloverlay_fight_init(void) {}

static void leveloverlay_fight_update(void) {}

static void leveloverlay_fight_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_MM_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_MM_release(void) {}

static void leveloverlay_MM_init(void) {}

static void leveloverlay_MM_update(void) {}

static void leveloverlay_MM_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_intro_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_intro_release(void) {}

static void leveloverlay_intro_init(void) {}

static void leveloverlay_intro_update(void) {}

static void leveloverlay_intro_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_BGS_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_BGS_release(void) {}

static void leveloverlay_BGS_init(void) {
    if (gsworld_getMap() == MAP_10_BGS_MR_VILE &&
        volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) &&
        volatileFlag_get(VOLATILE_FLAG_7_HAS_SEEN_VILE_FF_MINIGAME))
    {
        player_setTransformation(TRANSFORM_5_CROC);
    }
}

static void leveloverlay_BGS_update(void) {}

static void leveloverlay_BGS_unk14(s32 arg0, s32 arg1) {}

static void leveloverlay_FP_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {}

static void leveloverlay_FP_release(void) {
    maSnowy_end();
    maSnowButton_end();
    maSlalom_end();
    func_8039195C();
}

static void leveloverlay_FP_init(void) {
    maSnowy_init();
    maSnowButton_init();
    maSlalom_init();
    func_803918C0();
}

static void leveloverlay_FP_update(void) {
    maSnowy_update();
    maSnowButton_update();
    maSlalom_update();
    func_80391994();
}

static void leveloverlay_FP_unk14(s32 arg0, s32 arg1) {}

void leveloverlay_drawCallback(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    if (sActiveCallbacks.draw)
        sActiveCallbacks.draw(gfx, mtx, vtx);
}

enum overlay_e leveloverlay_getOverlayFromLevel(enum level_e lvl) {
    int i;
    for (i = 0; sLevelOverlayMap[i].level_id; i++) {
        if (sLevelOverlayMap[i].level_id == lvl)
            return sLevelOverlayMap[i].overlay_id;
    }
    return 0;
}

void leveloverlay_releaseCallback(bool flag) {
    if (flag == sActiveCallbacks.release_flag && sActiveCallbacks.release) {
        sActiveCallbacks.release();
    }
}

void leveloverlay_initCallback(bool flag) {
    if (flag == sActiveCallbacks.init_flag && sActiveCallbacks.init) {
        sActiveCallbacks.init();
    }
}

void leveloverlay_releaseCallback_NotFP(void) {
    leveloverlay_releaseCallback(FALSE);
}

void leveloverlay_releaseCallback_OnlyFP(void) {
    leveloverlay_releaseCallback(TRUE);
}

void leveloverlay_initCallback_OnlyFP(void) {
    leveloverlay_initCallback(FALSE);
}

void leveloverlay_initCallback_NotFP(void) {
    leveloverlay_initCallback(TRUE);
}

void leveloverlay_debug(void) {}

void leveloverlay_init(void) {
    int i;
    enum overlay_e overlay_id;

    func_80356714();
    overlay_id = overlayManager_getLoadedID();
    sActiveCallbacks.init = sActiveCallbacks.update = sActiveCallbacks.release = NULL;
    sActiveCallbacks.draw = NULL;
    sActiveCallbacks.unk14 = NULL;

    for (i = 0; sLevelOverlayCallbacks[i].overlay_id != 0; i++) {
        if(overlay_id == sLevelOverlayCallbacks[i].overlay_id) {
            sActiveCallbacks.init_flag = sLevelOverlayCallbacks[i].init_flag;
            sActiveCallbacks.release_flag = sLevelOverlayCallbacks[i].release_flag;
            sActiveCallbacks.init = sLevelOverlayCallbacks[i].init;
            sActiveCallbacks.update = sLevelOverlayCallbacks[i].update;
            sActiveCallbacks.release = sLevelOverlayCallbacks[i].release;
            sActiveCallbacks.draw = sLevelOverlayCallbacks[i].draw;
            sActiveCallbacks.unk14 = sLevelOverlayCallbacks[i].unk14;
            break;
        }
    }
}

void leveloverlay_unk14Callback(s32 arg0, s32 arg1) {
    if (sActiveCallbacks.unk14)
        sActiveCallbacks.unk14(arg0, arg1);
}

void leveloverlay_updateCallback(void) {
    if (sActiveCallbacks.update)
        sActiveCallbacks.update();
}
