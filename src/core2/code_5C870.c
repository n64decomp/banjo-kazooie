#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include "core2/gc/transition.h"
#include "time.h"

extern void print_updateBoldLetterFontDelayedFreeing(void);
extern void func_802FA0F8(void);
extern void timedFuncQueue_update(void);
extern void func_8025A2B0(void);
extern void func_8025A430(s32, s32, s32);
extern void func_8034BB90(void);
extern void func_80321C34(void);
extern void func_8030ED0C(void);
extern void coMusicPlayer_update(void);

enum transition_e {
    TRANSITION_0_NONE
};

void func_802E3BD0(s32 frame_buffer_indx);
void game_setNextMapResettingLevel(s32 map, s32 exit);
void game_setMapChangeRequest( s32 arg0);
void game_setNextMap(s32 map, s32 exit);
void game_setMapTransition(s32 transition);
int  func_802E4A08(void);

f32 func_8033DC20(void);
extern void func_80324C58(void);

/* .data */
/* Exit 0x80 isn't in a setup file; it comes from here as 8 shorts: player x, y, z, yaw, then
 * camera x, y, z, yaw (see game_getHardcodedExitX etc.). Only exit 0x80 has real data: the
 * rest of the array is a copyright string. */
s16 sGameHardcodedExits[] = {
    0x159A, 0x02BC, 0x21C8, 0x00C8, 0x14ED, 0x03A2, 0x1951, 0x0003,
    '**', ' B', 'AN', 'JO', ' K', 'AZ', 'OO', 'IE',
    ' (', 'c)', ' R', 'AR', 'E ', 'Lt', 'd ', '19',
    '98', ' *', '*\0',   0,    0,    0,    0,    0,
 
};

/* .bss */
struct{
    s32 unk0;
    s32 game_mode; //game_mode
    f32 unk8; 
    s32 unkC; //freeze_scene_flag (used for pause menu)
    f32 unk10;
    u8 transition;           // pending request handled by game_update (1 = change map, 6/7/8/12 = demo modes, ...)
    u8 map;                  // map to change to
    u8 exit;                 // exit to arrive at
    u8 map_transition;       // passed to game_setMode after the map changes: nonzero plays a transition in
    u8 reset_level;          // reload the level state even if the new map is in the same level
    u8 map_transition_style; // style passed to gctransition_8030BEA4
    u8 unk1A;
    u8 unk1B;
    u8 keep_level_state;     // don't reset the level state on the next level change (see level_load)
} sGameState;

void func_802E3800(void){
    viewport_setPosition_f3(0.0f, 0.0f, 0.0f);
    viewport_setRotation_f3(-30.0f, 30.0f, 0.0f);
    viewport_moveAlongZAxis(3000.0f);
    viewport_update();
}

void func_802E3854(void){
    int i;

    func_8033B61C();
    dummy_func_80254464();
    for(i = 0; i < 0xF; i++){
        func_802E6820(5);
        modelRender_defrag();
        mapSavestate_defrag();
        gctransition_defrag();
        printbuffer_defrag();
        code_C9E70_defrag();
        func_802FA4E0();
        func_8033B5FC();
        timedFuncQueue_defrag();
        comusic_defrag();
    }
}

/* Loads a map. The level's code and state are only reloaded when the level changes
 * (or when reset_on_load is set). */
void game_loadMap(enum map_e map, s32 exit, s32 reset_on_load){
    if(reset_on_load || level_get() != map_getLevel(map)){
        func_8030AFD8(1);
        level_unload();
        level_load(map); //load_map_asm
        gcsection_setJiggyListForMap(map);
    }
    else{
        func_8030AFD8(1);
        gcsection_setJiggyListForMap(map);
    }
    func_802FA508();
    gsworld_set(map, exit, 0);
    func_802E3800();
    func_8033DC10();
}

void func_802E398C(s32 arg0) {
    gsworld_free();
    func_8030ED0C();
    coMusicPlayer_update();
    if (arg0 != 0) {
        func_802E3854();
    }
}

void func_802E39D0(Gfx **gfx, Mtx **mtx, Vtx **vtx, s32 framebuffer_idx, bool arg4) {
    Mtx* mtx_start = *mtx; 
    Vtx* vtx_start = *vtx;

    setupFramebufferForGamemode(gfx, framebuffer_idx);
    sGameState.unkC = FALSE;
    gsworld_draw(gfx, mtx, vtx);

    if (!arg4) { // related to framebufferdraw_ functions
        func_802E67AC();
        func_802E3BD0(getActiveFramebuffer());
        func_802E67C4();
        func_802E5F10(gfx);
    }

    if ((sGameState.game_mode == GAME_MODE_A_SNS_PICTURE) && (sGameState.map_transition_style != 6) && (sGameState.map_transition_style != 5)) {
        gctransition_draw(gfx, mtx, vtx);
    }
    
    if ((sGameState.game_mode == GAME_MODE_8_BOTTLES_BONUS) || (sGameState.game_mode == GAME_MODE_A_SNS_PICTURE)) {
        picturebox_resetScissorBoxAndFramebuffer(gfx, mtx, vtx);
    }

    if (!game_is_frozen() && gsworld_getEnableDraw()) {
        core2_A5BC0_drawScreenOverlayMarkers(gfx, mtx, vtx);
    }

    gcpausemenu_draw(gfx, mtx, vtx);

    if (!game_is_frozen()) {
        core1_1D590_func_8025AFC0(gfx, mtx, vtx);
    }

    gcdialog_draw(gfx, mtx, vtx);

    if (!game_is_frozen()) {
        itemPrint_draw(gfx, mtx, vtx);
    }

    printbuffer_draw(gfx, mtx, vtx);

    if ((sGameState.game_mode != GAME_MODE_A_SNS_PICTURE) || (sGameState.map_transition_style == 6) || (sGameState.map_transition_style == 5)) {
        gctransition_draw(gfx, mtx, vtx);
    }

    core1_15B30_finishDList(gfx);
    osWritebackDCache(mtx_start, sizeof(Mtx) * (*mtx - mtx_start));
    osWritebackDCache(vtx_start, sizeof(Vtx) * (*vtx - vtx_start));
}

void func_802E3BD0(s32 frame_buffer_indx){
    framebufferdraw_setBufferIndex(frame_buffer_indx);
}

void func_802E3BF0(void){
    return;
}

//_set_game_mode
void game_setMode(enum game_mode_e next_mode, s32 arg1){
    s32 prev_mode = sGameState.game_mode;
    s32 sp20;
    s32 sp1C;

    if( ( ( sGameState.game_mode == GAME_MODE_3_NORMAL || func_802E4A08())
            && next_mode != GAME_MODE_4_PAUSED
          )
          || ( sGameState.game_mode == GAME_MODE_4_PAUSED && next_mode != GAME_MODE_3_NORMAL )
        ){
        func_80324C58();
    }

    if(sGameState.game_mode == GAME_MODE_4_PAUSED && next_mode != GAME_MODE_4_PAUSED ){
        gcpausemenu_free();
    }

    //L802E3C84
    if(next_mode == GAME_MODE_8_BOTTLES_BONUS || next_mode == GAME_MODE_A_SNS_PICTURE){
        picturebox_init();
    }
    else{
        picturebox_free();
    }//L802E3CB4

    sGameState.game_mode = next_mode;

    if(next_mode == 2){
        gsworld_setUnk0(3);
    }
    else if(next_mode == GAME_MODE_3_NORMAL || func_802E4A08()){
        if(prev_mode != GAME_MODE_4_PAUSED) {
            gsworld_setUnk0(2);
        }//L802E3D18
        if(arg1){
            sp20 = FALSE;
            if(next_mode == GAME_MODE_3_NORMAL){
                if(volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)){
                    sp20 = TRUE;
                    sp1C = 7;
                }
                else if(level_enteredFromLair()
                    && level_get() != LEVEL_C_BOSS
                    && level_get() != LEVEL_B_SPIRAL_MOUNTAIN
                    && level_get() != LEVEL_6_LAIR
                    && level_get() != LEVEL_D_CUTSCENE
                ){
                    sp20 = TRUE;
                    sp1C = 1;
                }
            }
            else if(func_802E4A08()){//L802E3DBC
                sp20 = TRUE;
                sp1C = func_8034BDA4(sGameState.map, sGameState.exit);
            }

            if(sp20)
                gctransition_8030BEA4(sp1C);
            else
                gctransition_8030BD4C();
        }
        func_80346CA8();
        sGameState.unk10 = 0.0f; 
    }
    else if(next_mode == GAME_MODE_4_PAUSED){//L802E3E24
        gsworld_setEnableUpdate(FALSE);
        FUNC_8030E624(SFX_C9_PAUSEMENU_ENTER, 1.1f, 32750);
        joy_update();
        func_8025A430(0, 2000, 3);
        func_8025A23C(COMUSIC_6F_PAUSE_SCREEN);
        gcpausemenu_init();
    }//L802E3E6C
}

/* Applies the pending map change: saves the current map's state, loads the new map and switches to `mode` */
void game_changeMap(enum game_mode_e mode){
    s32 sp34;
    s32 sp30;
    s32 map;
    s32 sp28;
    s32 prev_mode;

    core1_15B30_sendMesg3ToRenderThread();
    sp34 = sGameState.reset_level;
    sp30 = sGameState.map_transition;
    map = sGameState.map;
    sp28 = sGameState.exit;
    prev_mode = sGameState.unk0;
    game_setMode(GAME_MODE_2_UNKNOWN, 0);
    if(!volatileFlag_getAndSet(VOLATILE_FLAG_21, 0) || map_getLevel(gsworld_getMap()) == map_getLevel(sGameState.map)){
        if(!volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE))
            mapSavestate_save(gsworld_getMap());
    }
    func_802E398C(1);
    game_loadMap(map, sp28, sp34);
    mapSavestate_apply(map);
    sGameState.unk0 = prev_mode;
    game_setMode(mode, sp30);
    jiggylist_map_actors();
    func_80346CA8();
}

s32 func_802E3F80(void){
    return sGameState.unk0;
}

void game_draw(bool arg0) {
    Gfx *gfx, *gfx_start, *gfx_end;
    Mtx *mtx;
    Vtx *vtx;

    if (arg0) {
        scissorBox_setDefault();
    }

    graphicscache_swapAndGetStacks(&gfx, &mtx, &vtx);

    if (sGameState.unkC == TRUE) { // BUG: Compares explicit for integral value of TRUE, instead for true-ness
        graphicscache_swapAndGetStacks(&gfx, &mtx, &vtx);
    }

    gfx_start = gfx;
    func_802E39D0(&gfx, &mtx, &vtx, getActiveFramebuffer(), arg0);

    if (!sGameState.unkC) {
        gfx_end = gfx;
        viMgr_func_8024C1DC();
        core1_15B30_addF3DEXTaskData_40000000(gfx_start, gfx_end);

        if (arg0) {
            scissorBox_setDefault();
        }
    }
}

/* like transitionToMap, but the level state is reset even inside the same level */
void game_transitionToMapResettingLevel(s32 map, s32 exit, s32 transition){
    game_setNextMapResettingLevel(map, exit);
    game_setMapTransition(transition);
    game_setMapChangeRequest(1);
}

//take me there
void transitionToMap(enum map_e map, s32 exit, s32 transition){
    game_setNextMap(map, exit);
    game_setMapTransition(transition);
    game_setMapChangeRequest(1);
}

void game_setNextMapResettingLevel(s32 map, s32 exit){
    sGameState.reset_level = 1;
    sGameState.map = map;
    sGameState.exit = exit;
}

void game_setMapChangeRequest( s32 arg0){
    sGameState.transition = arg0;   
}

void game_setNextMap(s32 map, s32 exit){
    sGameState.reset_level = 0;
    sGameState.map = map;
    sGameState.exit = exit;
}

void game_setMapTransition(s32 transition){
    sGameState.map_transition = transition;
    sGameState.map_transition_style = 0;
    if(transition && !gctransition_8030BDC0()){
        gctransition_8030BE60();
    }
    
}

void game_setMapTransitionWithStyle(s32 arg0, s32 arg1){
    sGameState.map_transition = arg0;
    sGameState.map_transition_style = arg1;
    if(arg0 && !gctransition_8030BDC0()){
        gctransition_8030BEA4(arg1);
    }
}

void game_free(void){
    game_setMode(GAME_MODE_2_UNKNOWN,0);
    defragthread_free();
    func_802E5F68();
    if(!func_802E4A08())
        print_free();
    timedFuncQueue_free();
    func_802F9C48();
    modelRender_free();
    depthbuffer_stub();
    func_802E398C(0);
    func_8030AFD8(0);
    level_unload();
    debugScoreStates();
    animCache_free();
    coMusicPlayer_free();
    func_8030D8DC();
}

void game_init(enum map_e map_id){
    sGameState.transition = TRANSITION_0_NONE;
    sGameState.map_transition_style = sGameState.reset_level = 0;
    sGameState.map = sGameState.exit = sGameState.map_transition = 0;
    sGameState.unk1B = sGameState.unk1A = 0;
    sGameState.unkC = FALSE;
    sGameState.keep_level_state = 0;
    savedata_init();
    sns_load_global_data();
    func_8030D86C();
    coMusicPlayer_init();
    func_80322764();
    timedFuncQueue_init();
    func_802F9CD8();
    func_8031B62C();
    if(!func_802E4A08())
        print_init();
    func_802E5F38();
    defragthread_init();
    modelRender_init();
    depthbuffer_enable(TRUE);
    animCache_init();
    viewport_reset();
    viewport_setNearAndFar(1.0f, 10000.0f);
    rand_reset();
    scissorBox_setDefault();
    func_80253FE8();
    time_reset();
    func_8033DC04();
    clearScoreStates();
    sGameState.game_mode = GAME_MODE_2_UNKNOWN;
    sGameState.unk8 = 0.0f;
    time_setDeltaReal_sec(0.0f);
    time_setDeltaReal_frames(0);
    level_load(map_id);
    gcsection_setJiggyListForMap(map_id);
    func_802E3854();
    game_loadMap(map_id, 0, 0);
    sGameState.unk0 = 0;
    game_setMode(GAME_MODE_3_NORMAL,1);
}

void func_802E4384(void){
    if(sGameState.unk8 == 0.0f){
        time_setDeltaReal_sec(0.0f);
    }
    else{
        func_8033DC18();
        ;
        time_setDeltaReal_frames((s32)(func_8033DC20()*(float)FRAMERATE + 0.5));
    }
    func_8033DC10();
    
    sGameState.unk8 += time_getDelta();
}

/* Runs one frame of the game: handles a pending map change request, then updates the world.
 * Returns whether the frame should be drawn. */
bool game_update(void) {
    s32 sp1C;
    u8 temp_v0;

    viewport_debug();
    rand_shuffle();
    if (!gctransition_8030BDC0()) {
        temp_v0 = sGameState.transition;
        sGameState.transition = TRANSITION_0_NONE;
        switch (temp_v0) {                          /* switch 1 */
            case 9:                                     /* switch 1 */
                if( (sGameState.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (sGameState.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (sGameState.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (sGameState.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                gcparade_8031ABF8();
                game_changeMap(GAME_MODE_3_NORMAL);
                return FALSE;

            case 10:                                    /* switch 1 */
                if( (sGameState.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (sGameState.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (sGameState.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (sGameState.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                gcparade_8031ABA0();
                game_changeMap(GAME_MODE_3_NORMAL);
                return FALSE;

            case 1:                                     /* switch 1 */
                if( (sGameState.game_mode == GAME_MODE_7_ATTRACT_DEMO)
                    || (sGameState.game_mode == GAME_MODE_8_BOTTLES_BONUS)
                    || (sGameState.game_mode == GAME_MODE_A_SNS_PICTURE)
                    || (sGameState.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
                ) {
                    func_8034B940();
                }
                game_changeMap(GAME_MODE_3_NORMAL);
                return FALSE;

            case 6:                                     /* switch 1 */
                func_8034B8C0(sGameState.map, sGameState.exit);
                game_changeMap(GAME_MODE_7_ATTRACT_DEMO);
                return FALSE;

            case 12:                                    /* switch 1 */
                func_8034B8C0(sGameState.map, sGameState.exit);
                game_changeMap(GAME_MODE_A_SNS_PICTURE);
                return FALSE;

            case 7:                                     /* switch 1 */
                func_8034B8C0(sGameState.map, sGameState.exit);
                game_changeMap(GAME_MODE_8_BOTTLES_BONUS);
                return FALSE;

            case 8:                                     /* switch 1 */
                func_8034B8C0(sGameState.map, sGameState.exit);
                game_changeMap(GAME_MODE_9_BANJO_AND_KAZOOIE);
                return FALSE;

            case 11:                                    /* switch 1 */
                game_changeMap(sGameState.game_mode);
                return FALSE;

            case 2:                                     /* switch 1 */
                func_8023DFF0(1);
                return FALSE;

            case 3:                                     /* switch 1 */
                func_8023DFF0(4);
                return FALSE;
            case 0:
                break;
        }
    }
    if (sGameState.unk1A != 0) {
        game_setMode(sGameState.unk1A - 1, sGameState.unk1B);
        sGameState.unk1A = 0;
    }
    sp1C = gsworld_update();
    func_80321C34();
    func_8030ED0C();
    coMusicPlayer_update();
    switch (sGameState.game_mode) {
        case GAME_MODE_8_BOTTLES_BONUS:
        case GAME_MODE_A_SNS_PICTURE:
            picturebox_spawn();
            /* fallthrough */
        case GAME_MODE_7_ATTRACT_DEMO:
        case GAME_MODE_9_BANJO_AND_KAZOOIE:
            func_8034BB90();
            if ((controller_getStartButton(0) == 1) && (sGameState.unk0 != 0)) {
                game_setMode(GAME_MODE_1_UNKNOWN, 0U);
            }
            break;
        case GAME_MODE_3_NORMAL:                                     /* switch 2 */
            sGameState.unk10 += time_getDelta();
            if( (controller_getStartButtonSafe(0) == 1)
                && func_8028F070()
                && (func_8028EC04() == 0)
                && !gctransition_8030BDC0()
                && gctransition_done()
                && (level_get() != 0)
                && (0.6 < sGameState.unk10)
                && gcpausemenu_80314B00()
                && !player_isDead()
                && volatileflag_func_8032056C()
                && levelSpecificFlags_validateCRC1()
                && volatileflag_stub2()
            ) {
                game_setMode(GAME_MODE_4_PAUSED, 0U);
            } else if ((controller_getStartButton(0) == 1) && (sGameState.unk0 != 0)) {
                game_setMode(GAME_MODE_1_UNKNOWN, 0U);
            } else if (sp1C == 0) {
                game_setMode(GAME_MODE_3_NORMAL, 1U);
            }
            break;

        case GAME_MODE_4_PAUSED:                                     /* switch 2 */
            if (gcPauseMenu_update() || cutscenetrigger_update()) {
                FUNC_8030E624(SFX_C9_PAUSEMENU_ENTER, 0.899316, 32736);
                gsworld_setEnableUpdate(TRUE);
                func_8025A430(-1, 2000, 3);
                func_8025A2B0();
                gsworld_setEnableDraw(TRUE);
                game_setMode(GAME_MODE_3_NORMAL, 0U);
            }
            break;
    }
    if ((sGameState.game_mode == GAME_MODE_3_NORMAL) || (func_802E4A08() != 0)) {
        timedFuncQueue_update();
        func_802FA0F8();
    }
    gctransition_update();
    if (func_802E4A08() == 0) {
        print_updateBoldLetterFontDelayedFreeing();
    }
    return TRUE;
}

void func_802E48B8(enum game_mode_e mode, s32 arg1){
    game_setMode(mode, arg1);
}

s32 game_defrag(void){
    func_802555C4(); //reset defragged flag in memory.c
    if( !level_get() )
        return NULL;
    
    glspline_defrag();
    animCache_defrag();
    pem_defragAll();
    ncCameraNodeList_defrag();
    modelRender_defrag();
    func_8028FB68();
    partEmitMgr_defrag();
    mapModel_defrag();
    cubeList_defrag();
    actorArray_defrag();
    spawnQueue_defrag();
    func_802F3300();
    printbuffer_defrag();
    gcdialog_defrag();
    if(sGameState.game_mode == GAME_MODE_4_PAUSED)
        gcpausemenu_defrag();
    switch(overlayManager_getLoadedID()){
        case OVERLAY_2_WHALE:
            maClanker_defrag();
            break;
        case OVERLAY_D_WITCH:
            code_C9E70_defrag();
            break;
    }
    return func_802555D0(); //returns defrag flag in memory.c
}

void func_802E49E0(void){
    sGameState.unkC = TRUE;
}

int game_is_frozen(void){
    return sGameState.unkC;
}

s32 getGameMode(void){
    return sGameState.game_mode;
}

bool func_802E4A08(void){
    return (sGameState.game_mode == GAME_MODE_6_FILE_PLAYBACK) 
        || (sGameState.game_mode == GAME_MODE_5_UNKNOWN)
        || (sGameState.game_mode == GAME_MODE_7_ATTRACT_DEMO)
        || (sGameState.game_mode == GAME_MODE_8_BOTTLES_BONUS)
        || (sGameState.game_mode == GAME_MODE_9_BANJO_AND_KAZOOIE)
        || (sGameState.game_mode == GAME_MODE_A_SNS_PICTURE);
}

void game_setKeepLevelState(void){
    sGameState.keep_level_state = 1;
}

void game_clearKeepLevelState(void){
    sGameState.keep_level_state = 0;
}

u8 game_getKeepLevelState(void){
    return sGameState.keep_level_state;
}

s32 game_getHardcodedExitX(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 0];
}

s32 game_getHardcodedExitY(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 1];
}

s32 game_getHardcodedExitZ(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 2];
}

s32 game_getHardcodedExitYaw(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 3];
}

s32 game_getHardcodedExitCameraX(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 4];
}

s32 game_getHardcodedExitCameraY(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 5];
}

s32 game_getHardcodedExitCameraZ(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 6];
}

s32 game_getHardcodedExitCameraYaw(s32 arg0){
    return sGameHardcodedExits[8*(arg0 - 0x80) + 7];
}

f32 func_802E4B38(void){
    return sGameState.unk8;
}
