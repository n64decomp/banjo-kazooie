#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "actor.h"
#include "prop.h"
#include "functions.h"
#include "ch/snacker.h"

void spawnQueue_unlock(void);
void spawnQueue_lock(void);

extern Actor *actor_spawnWithYaw_s16(enum actor_e id, s16 pos[3], s32 yaw);
extern Actor *actor_spawnWithYaw_s32(enum actor_e id, s32 pos[3], s32 yaw);
extern Actor *bundle_spawn_s32(enum bundle_e bundle_id, s32 position[3]);
extern Actor *bundle_spawn_f32(enum bundle_e bundle_id, f32 position[3]);


Actor *func_802D7558(s32 *, s32, ActorInfo*, u32);
Actor *func_802D75B4(s32 *, s32, ActorInfo*, u32);
Actor *func_802D7610(s32 *, s32, ActorInfo*, u32);
Actor *chBottlesBonus_new(s32 *, s32, ActorInfo*, u32);


extern ActorInfo gameSelect_banjoSleeping; //banjo.without_right_hand
extern ActorInfo gameSelect_banjoGameboy; //banjo.playing_gameboy
extern ActorInfo gameSelect_banjoCooking; //banjo.cooking
extern ActorInfo fxWadingBootsTouchSparkle;
extern ActorInfo fxTurboTrainersTouchSparkle; //turbotrainers
extern ActorInfo chExplosionRipple;
extern ActorInfo chBubble;
extern ActorInfo chBigbutt; //bigbutt
extern ActorInfo chSmallBull; //brownbull
extern ActorInfo chJiggy; //jiggy
extern ActorInfo chJigsawDance; //jigdance
extern ActorInfo D_80366340;
extern ActorInfo D_80366364;
extern ActorInfo D_80366388;
extern ActorInfo D_803663AC;
extern ActorInfo D_803663D0;
extern ActorInfo D_803663F4;
extern ActorInfo chExtraLife; //extralife
extern ActorInfo sumusicNote; //music_note
extern ActorInfo chEmptyHoneycomb; //chhoneycarrier
extern ActorInfo chHoneycomb; //chhoney
extern ActorInfo chTrainers;
extern ActorInfo D_80366EF0; //large_shadow
extern ActorInfo chShockJump; //chshockjump
extern ActorInfo chFlightPad; //flight_pad
extern ActorInfo chSnippet; //snippet
extern ActorInfo chBlackSnippet; //black_snippet
extern ActorInfo chMutieSnippet; //mutie_snippet
extern ActorInfo chBuzzbomb; //buzzbomb
extern ActorInfo D_80367160;
extern ActorInfo D_80367184;
extern ActorInfo chJinjoBlue; //jingo_blue
extern ActorInfo chJinjoGreen; //jingo_green
extern ActorInfo chJinjoYellow; //jingo_yellow
extern ActorInfo chJinjoPink; //jingo_pink
extern ActorInfo chJinjoOrange; //jingo_orange
extern ActorInfo chBeehive; //chbeehive
extern ActorInfo chBeeSwarm; //chswarm
extern ActorInfo D_80367390; //chwaterfallfx
extern ActorInfo chShrapnelDescription; //scrapnel
extern ActorInfo chGloop; //gloop
extern ActorInfo chMumbo; //mumbo
extern ActorInfo chMumboSign5; //mumbo_token_sign.5
extern ActorInfo chMumboSign10; //mumbo_toke_sign.10
extern ActorInfo chMumboSign15; //mumbo_toke_sign.15
extern ActorInfo chMumboSign20; //mumbo_toke_sign.20
extern ActorInfo chMumboSign25; //mumbo_toke_sign.25
extern ActorInfo D_803675F0;
extern ActorInfo D_80367760;
extern ActorInfo D_80367784;
extern ActorInfo chIceKey; //ice_key
extern ActorInfo chMumboSwitch; //mumbo_transform_pad
extern ActorInfo chFFTeleportPad;
extern ActorInfo chSnsEgg; //SnS_egg
extern ActorInfo gWorldExitPad; //level_entry_disk
extern ActorInfo chMMWitchSwitch; //witch_switch.mm;
extern ActorInfo chMMMWitchSwitch; //witch_switch.mmm
extern ActorInfo chTTCWitchSwitch; //witch_switch.ttc
extern ActorInfo chRBBWitchSwitch; //witch_switch.rbb
extern ActorInfo chCCWWitchSwitch; //witch_switch.ccw
extern ActorInfo chFPWitchSwitch; //witch_switch.fp
extern ActorInfo chCCWitchSwitch; //witch_switch.cc
extern ActorInfo chBGSWitchSwitch; //witch_switch.bgs
extern ActorInfo chGVWitchSwitch; //witch_switch.gv
extern ActorInfo chWadingBoots; //wading boots
extern ActorInfo chBadShad; //chbadshad
extern ActorInfo D_80367AB0;
extern ActorInfo D_80367AD4;
extern ActorInfo D_80367AF8;
extern ActorInfo D_80367B20; //chclimbbase
extern ActorInfo chOrangeCollectible; //orange
extern ActorInfo chGoldBullion; //gold_bullion
extern ActorInfo chBluePresentCollectible;
extern ActorInfo chGreenPresentCollectible;
extern ActorInfo chRedPresentCollectible;
extern ActorInfo chPiranhaWaterParticles;
extern ActorInfo fxSpentRedFeather; //spent_redfeather
extern ActorInfo fxSpentGoldFeather; //spent_goldfeather
extern ActorInfo chBlueEgg; //egg
extern ActorInfo chRedFeather; //redfeather
extern ActorInfo chGoldFeather; //goldfeather 
extern ActorInfo gChMole; //bottles
extern ActorInfo chMolehill; //chmolehill
extern ActorInfo D_80367E70;
extern ActorInfo D_80367F30;
extern ActorInfo gcGameOverSign;//GAME_OVER
extern ActorInfo gcTheEndSign;//THE_END
extern ActorInfo gcBanjoKazooieSign;//player_KAZOOIE
extern ActorInfo chOverlayCopyrightDescription;//copyright_info
extern ActorInfo chOverlayPressStart;//PRESS_START
extern ActorInfo chOverlayNoController;//NO_CONTROLLER)
extern ActorInfo chBottlesBonusDescription; //jiggy_picture
extern ActorInfo chMumbosHandWithPicture; 
extern ActorInfo D_8036838C;
extern ActorInfo chBottlesBonusCursor; //banjos_hand_BB
extern ActorInfo chFireSparkle; //fire_sparkle
extern ActorInfo chBanjoCurtains;
extern ActorInfo chBanjoHouseDoor;
extern ActorInfo chFishbowl; //roysten
extern ActorInfo chCuckooClock; //cuckoo_clock
extern ActorInfo D_80368504;
extern ActorInfo D_80368528;
extern ActorInfo D_8036854C;
extern ActorInfo D_80368570;
extern ActorInfo chMumboToken; //mumbotoken
extern ActorInfo chSnowman; //sirslush
extern ActorInfo chSnowball; //snowball
extern ActorInfo chSnowmanHat; //sir_slush_hat
extern ActorInfo D_80372810;
extern ActorInfo chGrilleChompa; //grillchompa
extern ActorInfo chClucker; //clucker
extern ActorInfo chScarabBeetle; //scarab
extern ActorInfo chMinigame; //boombox
extern ActorInfo leafEmitterCCWAutumn; //leaf_particle
extern ActorInfo leafEmitterCCWHub;
extern ActorInfo rainEmitterCCWSpring; //rain
extern ActorInfo rainEmitterCCWHub;
extern ActorInfo snowEmitterCCWWinter; //snow
extern ActorInfo snowEmitterCCWHub; 
extern ActorInfo D_80372A48; 
extern ActorInfo D_80372A6C; 
extern ActorInfo gChFireFxInfo; //fire
extern ActorInfo gChDripsInfo;//water_drops
extern ActorInfo chIcecubeA;
extern ActorInfo chIcecubeB;//ice_cube
extern ActorInfo chTeeHee; //teehee
extern ActorInfo chFlotsam; //floatsam
extern ActorInfo chSkeleton; //limbo
extern ActorInfo chSeamanGrublin; //grublin_hood
extern ActorInfo chMumMum; //mummum
extern ActorInfo chChumpFish;
extern ActorInfo chTermite; //ticker
extern ActorInfo D_80372FC0;
extern ActorInfo D_80372FE4;
extern ActorInfo gChBat; //nibbly
extern ActorInfo chWhipcrack;
extern ActorInfo chBetaVent1;
extern ActorInfo chBetaVent2;
extern ActorInfo lairBottlesDialog;
extern ActorInfo D_803732E0;
extern ActorInfo D_80373DC0;


typedef struct function_queue_s{
    union { 
        void (* func0)(void);
        void (* func1)(s32);
        void (* func2)(s32, s32);
        void (* func3)(s32, s32, s32);
        void (* func4)(s32, s32, s32, s32);
        void (* func5)(s32, s32, s32, s32, s32);
    };
    s32  arg[5];
    s32  arg_cnt;
}FunctionQueue;

/* .data */
u8 spawnQueueLock = 0;
u8 spawnQueueLength = 0;
FunctionQueue *spawnQueue = NULL;

/* .code */
void spawnQueue_malloc(void){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 50: 15;
    spawnQueue = (FunctionQueue *) malloc(tmp * sizeof(FunctionQueue));
}

void spawnQueue_reset(void){
    enum overlay_e loaded_asm_file = overlayManager_getLoadedID();
    spawnQueue_lock();
    spawnQueueLength = 0;
    chmumbo_func_802D1724();
    chSnacker_initialize();
    switch(loaded_asm_file){
        case OVERLAY_2_WHALE:
            CC_func_803870E0();
            break;
        case OVERLAY_4_DESERT:
            GV_func_80387118();
            break;
        case OVERLAY_5_BEACH:
            break;
        case OVERLAY_7_SWAMP:
            BGS_func_803885DC();
            break;
        default:
            break;
    }

    func_80305D38(); 
    func_803062D0();
    func_80325F8C();
    spawnableActorList_new();
    spawnableActorList_add(&D_80367160, actor_new, ACTOR_FLAG_NONE); //cutscene Trigger?
    spawnableActorList_add(&D_803675F0, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&chBigbutt, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25); 
    spawnableActorList_add(&chSmallBull, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chMumbo, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chBeehive, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&chBeeSwarm, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&D_80367390, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chJinjoYellow, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoOrange, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoBlue, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoPink, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoGreen, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJiggy, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_21);
    spawnableActorList_add(&chJigsawDance, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chPiranhaWaterParticles, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chWadingBoots, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chEmptyHoneycomb, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_21); //chhoneycarrier
    spawnableActorList_add(&chHoneycomb, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_21); //chhoney
    spawnableActorList_add(&sumusicNote, actor_new, ACTOR_FLAG_UNKNOWN_21); //music_note
    spawnableActorList_add(&chBlueEgg, actor_new, ACTOR_FLAG_UNKNOWN_21); //egg
    spawnableActorList_add(&D_80366340, func_802C8A54, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80366364, func_802C8AA8, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80366388, func_802C8AF8, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_803663AC, func_802C8B4C, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_803663D0, func_802C8BA8, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_803663F4, func_802C8C04, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80367AB0, func_802D7558, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80367AD4, func_802D75B4, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80367AF8, func_802D7610, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chTrainers, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&fxWadingBootsTouchSparkle, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&fxTurboTrainersTouchSparkle, actor_new, ACTOR_FLAG_UNKNOWN_2); //turbotrainers
    spawnableActorList_add(&D_80367184, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chExtraLife, actor_new, ACTOR_FLAG_UNKNOWN_21); //extralife
    spawnableActorList_add(&chExplosionRipple, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chBadShad, actor_new, ACTOR_FLAG_UNKNOWN_2); //chbadshad
    spawnableActorList_add(&chMumboToken, actor_new, ACTOR_FLAG_UNKNOWN_6); //mumbotoken
    spawnableActorList_add(&D_80367F30, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chBubble, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chGloop, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7); //gloop
    spawnableActorList_add(&chShockJump, actor_new, ACTOR_FLAG_NONE); //chshockjump
    spawnableActorList_add(&chFlightPad, actor_new, ACTOR_FLAG_NONE); //flight_pad
    spawnableActorList_add(&chRedFeather, actor_new, ACTOR_FLAG_UNKNOWN_21); //redfeather
    spawnableActorList_add(&chGoldFeather, actor_new, ACTOR_FLAG_UNKNOWN_21); //goldfeather 
    spawnableActorList_add(&fxSpentRedFeather, actor_new, ACTOR_FLAG_UNKNOWN_2); //spent_redfeather
    spawnableActorList_add(&fxSpentGoldFeather, actor_new, ACTOR_FLAG_UNKNOWN_2); //spent_goldfeather
    spawnableActorList_add(&gChMole, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8); //bottles
    spawnableActorList_add(&chMolehill, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6); //chmolehill
    spawnableActorList_add(&D_80373DC0, actor_new, ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_80367E70, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChSnacker, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_16); //snacker
    spawnableActorList_add(&D_80366EF0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17); //large_shadow
    spawnableActorList_add(&D_80367B20, actor_new, ACTOR_FLAG_UNKNOWN_7); //chclimbbase
    spawnableActorList_add(&chGoldBullion, actor_new, ACTOR_FLAG_UNKNOWN_6); //gold_bullion
    spawnableActorList_add(&chOrangeCollectible, actor_new, ACTOR_FLAG_UNKNOWN_1); //orange
    spawnableActorList_add(&leafEmitterCCWAutumn, actor_new, ACTOR_FLAG_UNKNOWN_7); //leaf_particle
    spawnableActorList_add(&leafEmitterCCWHub, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&rainEmitterCCWSpring, actor_new, ACTOR_FLAG_UNKNOWN_7); //rain
    spawnableActorList_add(&rainEmitterCCWHub, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&snowEmitterCCWWinter, actor_new, ACTOR_FLAG_UNKNOWN_7); //snow
    spawnableActorList_add(&snowEmitterCCWHub, actor_new, ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&D_80372A48, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&D_80372A6C, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&chMinigame, actor_new, ACTOR_FLAG_UNKNOWN_7); //boombox
    spawnableActorList_add(&chIceKey, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //ice_key
    spawnableActorList_add(&chSnsEgg, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //SnS_egg
    spawnableActorList_add(&gChFireFxInfo, actor_new, ACTOR_FLAG_NONE); //fire
    spawnableActorList_add(&gWorldExitPad, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //level_entry_disk
    spawnableActorList_add(&D_80367760, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_80367784, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&gameSelect_banjoSleeping, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.without_right_hand
    spawnableActorList_add(&gameSelect_banjoGameboy, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.playing_gameboy
    spawnableActorList_add(&gameSelect_banjoCooking, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.cooking
    spawnableActorList_add(&chMumboSwitch, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);//mumbo_transform_pad
    spawnableActorList_add(&chFFTeleportPad, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&lairBottlesDialog, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chSnowball, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_20);//snowball
    spawnableActorList_add(&chSnowmanHat, actor_new, ACTOR_FLAG_UNKNOWN_2);//sir_slush_hat
    spawnableActorList_add(&gChDripsInfo, actor_new, ACTOR_FLAG_UNKNOWN_10);//water_drops
    spawnableActorList_add(&chIcecubeB, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_25);//ice_cube
    spawnableActorList_add(&gcGameOverSign, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//GAME_OVER
    spawnableActorList_add(&gcTheEndSign, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//THE_END
    spawnableActorList_add(&gcBanjoKazooieSign, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//player_KAZOOIE
    spawnableActorList_add(&chOverlayCopyrightDescription, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//copyright_info
    spawnableActorList_add(&chOverlayPressStart, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//PRESS_START
    spawnableActorList_add(&chBottlesBonusDescription, chBottlesBonus_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//jiggy_picture
    spawnableActorList_add(&chMumbosHandWithPicture, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);
    spawnableActorList_add(&D_8036838C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);
    spawnableActorList_add(&chBottlesBonusCursor, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//banjos_hand_BB
    spawnableActorList_add(&chOverlayNoController, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//NO_CONTROLLER);
    spawnableActorList_add(&chMumboSign5, actor_new, ACTOR_FLAG_NONE);//mumbo_token_sign.5
    spawnableActorList_add(&chMumboSign10, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.10
    spawnableActorList_add(&chMumboSign15, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.15
    spawnableActorList_add(&chMumboSign20, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.20
    spawnableActorList_add(&chMumboSign25, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.25
    spawnableActorList_add(&chMMWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.mm;
    spawnableActorList_add(&chMMMWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.mmm
    spawnableActorList_add(&chTTCWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.ttc
    spawnableActorList_add(&chRBBWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.rbb
    spawnableActorList_add(&chCCWWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.ccw
    spawnableActorList_add(&chFPWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.fp
    spawnableActorList_add(&chCCWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.cc
    spawnableActorList_add(&chBGSWitchSwitch, actor_new, ACTOR_FLAG_NONE);//witch_switch.bgs
    spawnableActorList_add(&chGVWitchSwitch, actor_new, ACTOR_FLAG_UNKNOWN_10);//witch_switch.gv
    spawnableActorList_add(&chFireSparkle, actor_new, ACTOR_FLAG_UNKNOWN_17);//fire_sparkle
    spawnableActorList_add(&chFishbowl, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);//roysten
    spawnableActorList_add(&chCuckooClock, actor_new, ACTOR_FLAG_NONE);//cuckoo_clock
    spawnableActorList_add(&D_80368504, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80368528, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8036854C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80368570, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chBanjoCurtains, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chBanjoHouseDoor, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_803732E0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80372810, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chWhipcrack, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&chBetaVent1, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chBetaVent2, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chChumpFish, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_addIfMapVisited(&chTermite, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_2_MM_MUMBOS_MOUNTAIN); //ticker
    spawnableActorList_addIfMapVisited(&chFlotsam, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_31_RBB_RUSTY_BUCKET_BAY); //floatsam
    spawnableActorList_addIfMapVisited(&chTeeHee, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17, MAP_1B_MMM_MAD_MONSTER_MANSION); //teehee
    spawnableActorList_addIfMapVisited(&D_80372FC0, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION);
    spawnableActorList_addIfMapVisited(&D_80372FE4, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION);
    spawnableActorList_addIfMapVisited(&gChBat, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_21 |ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION); //nibbly
    spawnableActorList_addIfMapVisited(&chBuzzbomb, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25, MAP_D_BGS_BUBBLEGLOOP_SWAMP); //buzzbomb
    spawnableActorList_addIfMapVisited(&chIcecubeA, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_25, MAP_27_FP_FREEZEEZY_PEAK);
    spawnableActorList_addIfMapVisited(&chShrapnelDescription, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //scrapnel
    spawnableActorList_addIfMapVisited(&chSkeleton, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION); //limbo
    spawnableActorList_addIfMapVisited(&chSeamanGrublin, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_31_RBB_RUSTY_BUCKET_BAY); //grublin_hood
    spawnableActorList_addIfMapVisited(&chMumMum, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_12_GV_GOBIS_VALLEY); //mummum
    spawnableActorList_addIfMapVisited(&chGrilleChompa, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 |ACTOR_FLAG_UNKNOWN_25, MAP_B_CC_CLANKERS_CAVERN); //grillchompa
    spawnableActorList_addIfMapVisited(&chSnippet, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //snippet
    spawnableActorList_addIfMapVisited(&chBlackSnippet, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //black_snippet
    spawnableActorList_addIfMapVisited(&chMutieSnippet, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //mutie_snippet
    spawnableActorList_addIfMapVisited(&chClucker, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 |ACTOR_FLAG_UNKNOWN_25, MAP_40_CCW_HUB); //clucker
    spawnableActorList_addIfMapVisited(&chScarabBeetle, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25, MAP_12_GV_GOBIS_VALLEY); //scarab
    spawnableActorList_addIfMapVisited(&chSnowman, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_25, MAP_27_FP_FREEZEEZY_PEAK); //sirslush
    switch(loaded_asm_file){
        default:
            break;
        case OVERLAY_D_WITCH:
            lair_func_8038A0C4();
            break;
        case OVERLAY_E_BATTLE:
            fight_addSpawnableActors();
            break;
        case OVERLAY_C_INTRO:
            cutscene_func_8038C4E0();
            break;
        case OVERLAY_B_TRAINING:
            SM_resetSpawnableActors();
            break;
        case OVERLAY_3_HAUNTED:
            MMM_func_803890E0();
            break;
        case OVERLAY_2_WHALE:
            CC_func_80387DA0();
            break;
        case OVERLAY_4_DESERT:
            GV_func_8038F154();
            break;
        case OVERLAY_5_BEACH:
            code26D0_resetSpawnableActorsForTTC();
            break;
        case OVERLAY_6_JUNGLE:
            MM_func_803888B0();
            break;
        case OVERLAY_7_SWAMP:
            bgs_updateSpawnableActors();
            break;
        case OVERLAY_8_SHIP:
            RBB_func_80386C48();
            break;
        case OVERLAY_9_SNOW:
            FP_func_80391324();
            spawnableActorList_add(&chBluePresentCollectible, actor_new, ACTOR_FLAG_UNKNOWN_3);
            spawnableActorList_add(&chGreenPresentCollectible, actor_new, ACTOR_FLAG_UNKNOWN_3);
            spawnableActorList_add(&chRedPresentCollectible, actor_new, ACTOR_FLAG_UNKNOWN_3);
            break;
        case OVERLAY_A_TREE:
            CCW_func_8038DB6C();
            break;
    }

    if(ucode_stub3() == 0 || loaded_asm_file == 0 ){
        func_8030578C();
    }
    func_80305990(1);
    func_8032A5F8();
    spawnQueue_unlock();
}

void spawnQueue_free(void){
    spawnableActorList_free();
    actorArray_free();
    func_80305D94();
    free(spawnQueue);
    spawnQueue = NULL;
    spawnQueueLength = 0;
    
}

void spawnQueue_func_802C39D4(void){
    func_803268B4();
    if(!levelSpecificFlags_validateCRC2()){
        eeprom_writeBlocks(0, 0, (void *) PHYS_TO_K0(0x00749530), EEPROM_MAXBLOCKS);
    }
}

void spawnQueue_func_802C3A18(void){
    func_803283BC();
}

void spawnQueue_flush(void){
    s32 i;

    spawnQueue_lock();
    for(i = 0; i < spawnQueueLength; i++){
        switch(spawnQueue[i].arg_cnt){
            case 0:
                spawnQueue[i].func0();
                break;
            case 1:
                spawnQueue[i].func1(spawnQueue[i].arg[0]);
                break;
            case 2:
                spawnQueue[i].func2(spawnQueue[i].arg[0], spawnQueue[i].arg[1]);
                break;
            case 3:
                spawnQueue[i].func3(spawnQueue[i].arg[0], spawnQueue[i].arg[1], spawnQueue[i].arg[2]);
                break;
            case 4:
                spawnQueue[i].func4(spawnQueue[i].arg[0], spawnQueue[i].arg[1], spawnQueue[i].arg[2], spawnQueue[i].arg[3]);
                break;
            case 5:
                spawnQueue[i].func5(spawnQueue[i].arg[0], spawnQueue[i].arg[1], spawnQueue[i].arg[2], spawnQueue[i].arg[3], spawnQueue[i].arg[4]);
                break;
            default:
                break;
        }
    }
    spawnQueueLength = 0;
    func_803283D4();
}

void spawnQueue_unlock(void) {
    spawnQueueLock = FALSE;
}

void spawnQueue_lock(void) {
    spawnQueueLock = TRUE;
}

void __spawnQueue_add_0(void (* arg0)(void)){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg_cnt = 0;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_1(GenFunction_1 arg0, s32 arg1){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = (void (*)(void))arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg_cnt = 1;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_2(void (* arg0)(void), s32 arg1, s32 arg2){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg[1] = arg2;
        spawnQueue[spawnQueueLength].arg_cnt = 2;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_3(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg[1] = arg2;
        spawnQueue[spawnQueueLength].arg[2] = arg3;
        spawnQueue[spawnQueueLength].arg_cnt = 3;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_4(GenFunction_4 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = (void (*)(void))arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg[1] = arg2;
        spawnQueue[spawnQueueLength].arg[2] = arg3;
        spawnQueue[spawnQueueLength].arg[3] = arg4;
        spawnQueue[spawnQueueLength].arg_cnt = 4;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_5(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5){
    u32 tmp = (gsworld_getMap() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg[1] = arg2;
        spawnQueue[spawnQueueLength].arg[2] = arg3;
        spawnQueue[spawnQueueLength].arg[3] = arg4;
        spawnQueue[spawnQueueLength].arg[4] = arg5;
        spawnQueue[spawnQueueLength].arg_cnt = 5;
        spawnQueueLength++;
    }
}

Actor *spawnQueue_actor_f32(enum actor_e actor_id, s32 x, s32 y, s32 z) {
    f32 position[3];
    position[0] = reinterpret_cast(f32, x);
    position[1] = reinterpret_cast(f32, y);
    position[2] = reinterpret_cast(f32, z);
    return actor_spawnWithYaw_f32(reinterpret_cast(enum actor_e, actor_id), position, 0);
}

Actor *spawnQueue_actor_s16(enum actor_e actor_id, s32 x, s32 y, s32 z) {
    s16 position[3];
    position[0] = reinterpret_cast(s16, x);
    position[1] = reinterpret_cast(s16, y);
    position[2] = reinterpret_cast(s16, z);
    return actor_spawnWithYaw_s16(reinterpret_cast(enum actor_e, actor_id), position, 0);
}

Actor *spawnQueue_actor_s32(enum actor_e actor_id, s32 x, s32 y, s32 z) {
    s32 position[3];
    position[0] = reinterpret_cast(s32, x);
    position[1] = reinterpret_cast(s32, y);
    position[2] = reinterpret_cast(s32, z);
    return actor_spawnWithYaw_s32(reinterpret_cast(enum actor_e, actor_id), position, 0);
}

Actor *spawnQueue_bundle_f32(enum bundle_e bundle_id, s32 x, s32 y, s32 z) {
    f32 position[3];
    position[0] = reinterpret_cast(f32, x);
    position[1] = reinterpret_cast(f32, y);
    position[2] = reinterpret_cast(f32, z);
    return bundle_spawn_f32(reinterpret_cast(s32, bundle_id), position);
}

Actor *spawnQueue_bundleWithYaw_f32(enum bundle_e bundle_id, s32 x, s32 y, s32 z, s32 yaw) {
    f32 position[3];
    position[0] = reinterpret_cast(f32, x);
    position[1] = reinterpret_cast(f32, y);
    position[2] = reinterpret_cast(f32, z);
    bundle_setYaw(reinterpret_cast(f32, yaw));
    return bundle_spawn_f32(reinterpret_cast(s32, bundle_id), position);
}

Actor *spawnQueue_bundle_s32(enum bundle_e bundle_id, s32 x, s32 y, s32 z) {
    s32 position[3];
    position[0] = reinterpret_cast(s32, x);
    position[1] = reinterpret_cast(s32, y);
    position[2] = reinterpret_cast(s32, z);
    return bundle_spawn_s32(reinterpret_cast(s32, bundle_id), position);
}

Actor *spawnQueue_bundle_s32_2(enum bundle_e bundle_id, s32 x, s32 y, s32 z) {
    s32 position[3];
    position[0] = x;
    position[1] = y;
    position[2] = z;
    return bundle_spawn_s32(bundle_id, position);
}

void spawnQueue_defrag(FunctionQueue *arg0) {
    if ((arg0 = spawnQueue) != NULL) {
        spawnQueue = (FunctionQueue *) defrag(arg0);
    }
}
