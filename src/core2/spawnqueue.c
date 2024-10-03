#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"
#include "prop.h"
#include "functions.h"

#include "ch/snacker.h"

void spawnQueue_unlock(void);
void spawnQueue_lock(void);

Actor *func_802D7558(s32 *, s32, ActorInfo*, u32);
Actor *func_802D75B4(s32 *, s32, ActorInfo*, u32);
Actor *func_802D7610(s32 *, s32, ActorInfo*, u32);
Actor *chBottlesBonus_new(s32 *, s32, ActorInfo*, u32);

extern ActorInfo D_80365E58; //banjo.without_right_hand
extern ActorInfo D_80365EAC; //banjo.playing_gameboy
extern ActorInfo D_80365F00; //banjo.cooking
extern ActorInfo D_80365F60;
extern ActorInfo D_80365F84; //turbotrainers
extern ActorInfo D_80365FB0; //shrapnel
extern ActorInfo chBubble;
extern ActorInfo D_80366090; //bigbutt
extern ActorInfo D_803660B4; //brownbull
extern ActorInfo D_803662A8; //jiggy
extern ActorInfo chJigsawDance; //jigdance
extern ActorInfo D_80366340;
extern ActorInfo D_80366364;
extern ActorInfo D_80366388;
extern ActorInfo D_803663AC;
extern ActorInfo D_803663D0;
extern ActorInfo D_803663F4;
extern ActorInfo chExtraLife; //extralife
extern ActorInfo D_80366C50; //music_note
extern ActorInfo D_80366C80; //chhoneycarrier
extern ActorInfo D_80366CA4; //chhoney
extern ActorInfo chTrainers;
extern ActorInfo D_80366EF0; //large_shadow
extern ActorInfo chShockJump; //chshockjump
extern ActorInfo chFlightPad; //flight_pad
extern ActorInfo D_803670B8; //snippet
extern ActorInfo D_803670DC; //black_snippet
extern ActorInfo D_80367100; //mutie_snippet
extern ActorInfo D_80367130; //buzzbomb
extern ActorInfo D_80367160;
extern ActorInfo D_80367184;
extern ActorInfo chJinjoBlue; //jingo_blue
extern ActorInfo chJinjoGreen; //jingo_green
extern ActorInfo chJinjoYellow; //jingo_yellow
extern ActorInfo chJinjoPink; //jingo_pink
extern ActorInfo chJinjoOrange; //jingo_orange
extern ActorInfo chBeehive; //chbeehive
extern ActorInfo D_80367310; //chswarm
extern ActorInfo D_80367390; //chwaterfallfx
extern ActorInfo chShrapnelDescription; //scrapnel
extern ActorInfo chGloop; //gloop
extern ActorInfo D_803674E0; //mumbo
extern ActorInfo D_80367530; //mumbo_token_sign.5
extern ActorInfo D_80367554; //mumbo_toke_sign.10
extern ActorInfo D_80367578; //mumbo_toke_sign.15
extern ActorInfo D_8036759C; //mumbo_toke_sign.20
extern ActorInfo D_803675C0; //mumbo_toke_sign.25
extern ActorInfo D_803675F0;
extern ActorInfo D_80367760;
extern ActorInfo D_80367784;
extern ActorInfo D_803677A8; //ice_key
extern ActorInfo D_803677CC; //mumbo_transform_pad
extern ActorInfo D_803677F0;
extern ActorInfo D_80367814; //SnS_egg
extern ActorInfo D_80367838; //level_entry_disk
extern ActorInfo D_8036785C; //witch_switch.mm;
extern ActorInfo D_80367880; //witch_switch.mmm
extern ActorInfo D_803678A4; //witch_switch.ttc
extern ActorInfo D_803678C8; //witch_switch.rbb
extern ActorInfo D_803678EC; //witch_switch.ccw
extern ActorInfo D_80367910; //witch_switch.fp
extern ActorInfo D_80367934; //witch_switch.cc
extern ActorInfo D_80367958; //witch_switch.bgs
extern ActorInfo D_8036797C; //witch_switch.gv
extern ActorInfo D_80367A20; //wading boots
extern ActorInfo chBadShad; //chbadshad
extern ActorInfo D_80367AB0;
extern ActorInfo D_80367AD4;
extern ActorInfo D_80367AF8;
extern ActorInfo D_80367B20; //chclimbbase
extern ActorInfo D_80367B80; //orange
extern ActorInfo D_80367BA4; //gold_bullion
extern ActorInfo D_80367BC8;
extern ActorInfo D_80367BEC;
extern ActorInfo D_80367C10;
extern ActorInfo D_80367C60;
extern ActorInfo D_80367C90; //spent_redfeather
extern ActorInfo D_80367CB4; //spent_goldfeather
extern ActorInfo D_80367D00; //egg
extern ActorInfo D_80367D24; //redfeather
extern ActorInfo D_80367D48; //goldfeather 
extern ActorInfo gChMole; //bottles
extern ActorInfo D_80367E20; //chmolehill
extern ActorInfo D_80367E70;
extern ActorInfo D_80367F30;
extern ActorInfo D_8036804C;//GAME_OVER
extern ActorInfo D_8036807C;//THE_END
extern ActorInfo D_803680AC;//player_KAZOOIE
extern ActorInfo chOverlayCopyrightDescription;//copyright_info
extern ActorInfo D_80368124;//PRESS_START
extern ActorInfo D_80368174;//NO_CONTROLLER)
extern ActorInfo chBottlesBonusDescription; //jiggy_picture
extern ActorInfo D_8036833C; 
extern ActorInfo D_8036838C;
extern ActorInfo D_80368418; //banjos_hand_BB
extern ActorInfo D_80368450; //fire_sparkle
extern ActorInfo D_80368474;
extern ActorInfo D_80368498;
extern ActorInfo D_803684BC; //roysten
extern ActorInfo D_803684E0; //cuckoo_clock
extern ActorInfo D_80368504;
extern ActorInfo D_80368528;
extern ActorInfo D_8036854C;
extern ActorInfo D_80368570;
extern ActorInfo D_803685A0; //mumbotoken
extern ActorInfo chSnowman; //sirslush
extern ActorInfo chSnowball; //snowball
extern ActorInfo chSnowmanHat; //sir_slush_hat
extern ActorInfo D_80372810;
extern ActorInfo D_80372840; //grillchompa
extern ActorInfo D_80372870; //clucker
extern ActorInfo D_803728A0; //scarab
extern ActorInfo chMinigame; //boombox
extern ActorInfo D_80372970; //leaf_particle
extern ActorInfo D_80372994;
extern ActorInfo D_803729B8; //rain
extern ActorInfo D_803729DC;
extern ActorInfo D_80372A00; //snow
extern ActorInfo D_80372A24; 
extern ActorInfo D_80372A48; 
extern ActorInfo D_80372A6C; 
extern ActorInfo gChFireFxInfo; //fire
extern ActorInfo gChDripsInfo;//water_drops
extern ActorInfo D_80372B80;
extern ActorInfo D_80372BA4;//ice_cube
extern ActorInfo D_80372C18; //teehee
extern ActorInfo D_80372C80; //floatsam
extern ActorInfo D_80372D78; //limbo
extern ActorInfo D_80372DF8; //grublin_hood
extern ActorInfo D_80372E78; //mummum
extern ActorInfo D_80372EE0;
extern ActorInfo chTermite; //ticker
extern ActorInfo D_80372FC0;
extern ActorInfo D_80372FE4;
extern ActorInfo gChBat; //nibbly
extern ActorInfo D_80373100;
extern ActorInfo D_80373134;
extern ActorInfo D_80373158;
extern ActorInfo D_803731B0;
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
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 50: 15;
    spawnQueue = (FunctionQueue *) malloc(tmp * sizeof(FunctionQueue));
}

void spawnQueue_reset(void){
    s32 loaded_asm_file;

    loaded_asm_file = overlayManagergetLoadedId();
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
    spawnableActorList_add(&D_80366090, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25); 
    spawnableActorList_add(&D_803660B4, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_803674E0, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chBeehive, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80367310, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&D_80367390, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chJinjoYellow, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoOrange, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoBlue, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoPink, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chJinjoGreen, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&D_803662A8, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_21);
    spawnableActorList_add(&chJigsawDance, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80367C60, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80367A20, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80366C80, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_21); //chhoneycarrier
    spawnableActorList_add(&D_80366CA4, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_21); //chhoney
    spawnableActorList_add(&D_80366C50, actor_new, ACTOR_FLAG_UNKNOWN_21); //music_note
    spawnableActorList_add(&D_80367D00, actor_new, ACTOR_FLAG_UNKNOWN_21); //egg
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
    spawnableActorList_add(&D_80365F60, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&D_80365F84, actor_new, ACTOR_FLAG_UNKNOWN_2); //turbotrainers
    spawnableActorList_add(&D_80367184, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chExtraLife, actor_new, ACTOR_FLAG_UNKNOWN_21); //extralife
    spawnableActorList_add(&D_80365FB0, actor_new, ACTOR_FLAG_UNKNOWN_2); //shrapnel
    spawnableActorList_add(&chBadShad, actor_new, ACTOR_FLAG_UNKNOWN_2); //chbadshad
    spawnableActorList_add(&D_803685A0, actor_new, ACTOR_FLAG_UNKNOWN_6); //mumbotoken
    spawnableActorList_add(&D_80367F30, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chBubble, actor_new, ACTOR_FLAG_UNKNOWN_2);
    spawnableActorList_add(&chGloop, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7); //gloop
    spawnableActorList_add(&chShockJump, actor_new, ACTOR_FLAG_NONE); //chshockjump
    spawnableActorList_add(&chFlightPad, actor_new, ACTOR_FLAG_NONE); //flight_pad
    spawnableActorList_add(&D_80367D24, actor_new, ACTOR_FLAG_UNKNOWN_21); //redfeather
    spawnableActorList_add(&D_80367D48, actor_new, ACTOR_FLAG_UNKNOWN_21); //goldfeather 
    spawnableActorList_add(&D_80367C90, actor_new, ACTOR_FLAG_UNKNOWN_2); //spent_redfeather
    spawnableActorList_add(&D_80367CB4, actor_new, ACTOR_FLAG_UNKNOWN_2); //spent_goldfeather
    spawnableActorList_add(&gChMole, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8); //bottles
    spawnableActorList_add(&D_80367E20, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6); //chmolehill
    spawnableActorList_add(&D_80373DC0, actor_new, ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&D_80367E70, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&gChSnacker, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_16); //snacker
    spawnableActorList_add(&D_80366EF0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17); //large_shadow
    spawnableActorList_add(&D_80367B20, actor_new, ACTOR_FLAG_UNKNOWN_7); //chclimbbase
    spawnableActorList_add(&D_80367BA4, actor_new, ACTOR_FLAG_UNKNOWN_6); //gold_bullion
    spawnableActorList_add(&D_80367B80, actor_new, ACTOR_FLAG_UNKNOWN_1); //orange
    spawnableActorList_add(&D_80372970, actor_new, ACTOR_FLAG_UNKNOWN_7); //leaf_particle
    spawnableActorList_add(&D_80372994, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_803729B8, actor_new, ACTOR_FLAG_UNKNOWN_7); //rain
    spawnableActorList_add(&D_803729DC, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80372A00, actor_new, ACTOR_FLAG_UNKNOWN_7); //snow
    spawnableActorList_add(&D_80372A24, actor_new, ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&D_80372A48, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&D_80372A6C, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7); 
    spawnableActorList_add(&chMinigame, actor_new, ACTOR_FLAG_UNKNOWN_7); //boombox
    spawnableActorList_add(&D_803677A8, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //ice_key
    spawnableActorList_add(&D_80367814, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //SnS_egg
    spawnableActorList_add(&gChFireFxInfo, actor_new, ACTOR_FLAG_NONE); //fire
    spawnableActorList_add(&D_80367838, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15); //level_entry_disk
    spawnableActorList_add(&D_80367760, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_80367784, actor_new, ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&D_80365E58, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.without_right_hand
    spawnableActorList_add(&D_80365EAC, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.playing_gameboy
    spawnableActorList_add(&D_80365F00, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17); //banjo.cooking
    spawnableActorList_add(&D_803677CC, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);//mumbo_transform_pad
    spawnableActorList_add(&D_803677F0, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&D_803731B0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chSnowball, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_20);//snowball
    spawnableActorList_add(&chSnowmanHat, actor_new, ACTOR_FLAG_UNKNOWN_2);//sir_slush_hat
    spawnableActorList_add(&gChDripsInfo, actor_new, ACTOR_FLAG_UNKNOWN_10);//water_drops
    spawnableActorList_add(&D_80372BA4, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_25);//ice_cube
    spawnableActorList_add(&D_8036804C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//GAME_OVER
    spawnableActorList_add(&D_8036807C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//THE_END
    spawnableActorList_add(&D_803680AC, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//player_KAZOOIE
    spawnableActorList_add(&chOverlayCopyrightDescription, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//copyright_info
    spawnableActorList_add(&D_80368124, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//PRESS_START
    spawnableActorList_add(&chBottlesBonusDescription, chBottlesBonus_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//jiggy_picture
    spawnableActorList_add(&D_8036833C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);
    spawnableActorList_add(&D_8036838C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);
    spawnableActorList_add(&D_80368418, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//banjos_hand_BB
    spawnableActorList_add(&D_80368174, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15 | ACTOR_FLAG_UNKNOWN_20 | ACTOR_FLAG_UNKNOWN_22);//NO_CONTROLLER);
    spawnableActorList_add(&D_80367530, actor_new, ACTOR_FLAG_NONE);//mumbo_token_sign.5
    spawnableActorList_add(&D_80367554, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.10
    spawnableActorList_add(&D_80367578, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.15
    spawnableActorList_add(&D_8036759C, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.20
    spawnableActorList_add(&D_803675C0, actor_new, ACTOR_FLAG_NONE);//mumbo_toke_sign.25
    spawnableActorList_add(&D_8036785C, actor_new, ACTOR_FLAG_NONE);//witch_switch.mm;
    spawnableActorList_add(&D_80367880, actor_new, ACTOR_FLAG_NONE);//witch_switch.mmm
    spawnableActorList_add(&D_803678A4, actor_new, ACTOR_FLAG_NONE);//witch_switch.ttc
    spawnableActorList_add(&D_803678C8, actor_new, ACTOR_FLAG_NONE);//witch_switch.rbb
    spawnableActorList_add(&D_803678EC, actor_new, ACTOR_FLAG_NONE);//witch_switch.ccw
    spawnableActorList_add(&D_80367910, actor_new, ACTOR_FLAG_NONE);//witch_switch.fp
    spawnableActorList_add(&D_80367934, actor_new, ACTOR_FLAG_NONE);//witch_switch.cc
    spawnableActorList_add(&D_80367958, actor_new, ACTOR_FLAG_NONE);//witch_switch.bgs
    spawnableActorList_add(&D_8036797C, actor_new, ACTOR_FLAG_UNKNOWN_10);//witch_switch.gv
    spawnableActorList_add(&D_80368450, actor_new, ACTOR_FLAG_UNKNOWN_17);//fire_sparkle
    spawnableActorList_add(&D_803684BC, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);//roysten
    spawnableActorList_add(&D_803684E0, actor_new, ACTOR_FLAG_NONE);//cuckoo_clock
    spawnableActorList_add(&D_80368504, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80368528, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_8036854C, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80368570, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80368474, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&D_80368498, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_803732E0, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&D_80372810, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&D_80373100, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&D_80373134, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80373158, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&D_80372EE0, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_addIfMapVisited(&chTermite, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_2_MM_MUMBOS_MOUNTAIN); //ticker
    spawnableActorList_addIfMapVisited(&D_80372C80, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_31_RBB_RUSTY_BUCKET_BAY); //floatsam
    spawnableActorList_addIfMapVisited(&D_80372C18, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17, MAP_1B_MMM_MAD_MONSTER_MANSION); //teehee
    spawnableActorList_addIfMapVisited(&D_80372FC0, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION);
    spawnableActorList_addIfMapVisited(&D_80372FE4, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION);
    spawnableActorList_addIfMapVisited(&gChBat, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_21 |ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION); //nibbly
    spawnableActorList_addIfMapVisited(&D_80367130, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25, MAP_D_BGS_BUBBLEGLOOP_SWAMP); //buzzbomb
    spawnableActorList_addIfMapVisited(&D_80372B80, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_25, MAP_27_FP_FREEZEEZY_PEAK);
    spawnableActorList_addIfMapVisited(&chShrapnelDescription, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //scrapnel
    spawnableActorList_addIfMapVisited(&D_80372D78, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_1B_MMM_MAD_MONSTER_MANSION); //limbo
    spawnableActorList_addIfMapVisited(&D_80372DF8, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25, MAP_31_RBB_RUSTY_BUCKET_BAY); //grublin_hood
    spawnableActorList_addIfMapVisited(&D_80372E78, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_12_GV_GOBIS_VALLEY); //mummum
    spawnableActorList_addIfMapVisited(&D_80372840, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 |ACTOR_FLAG_UNKNOWN_25, MAP_B_CC_CLANKERS_CAVERN); //grillchompa
    spawnableActorList_addIfMapVisited(&D_803670B8, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //snippet
    spawnableActorList_addIfMapVisited(&D_803670DC, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //black_snippet
    spawnableActorList_addIfMapVisited(&D_80367100, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_24 | ACTOR_FLAG_UNKNOWN_25, MAP_7_TTC_TREASURE_TROVE_COVE); //mutie_snippet
    spawnableActorList_addIfMapVisited(&D_80372870, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 |ACTOR_FLAG_UNKNOWN_25, MAP_40_CCW_HUB); //clucker
    spawnableActorList_addIfMapVisited(&D_803728A0, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25, MAP_12_GV_GOBIS_VALLEY); //scarab
    spawnableActorList_addIfMapVisited(&chSnowman, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_25, MAP_27_FP_FREEZEEZY_PEAK); //sirslush
    switch(loaded_asm_file){
        default:
            break;
        case OVERLAY_D_WITCH:
            lair_func_8038A0C4();
            break;
        case OVERLAY_E_BATTLE:
            fight_func_803863F0();
            break;
        case OVERLAY_C_INTRO:
            cutscene_func_8038C4E0();
            break;
        case OVERLAY_B_TRAINING:
            SM_func_80386810();
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
            TTC_func_80388AC0();
            break;
        case OVERLAY_6_JUNGLE:
            MM_func_803888B0();
            break;
        case OVERLAY_7_SWAMP:
            BGS_func_8038F1E0();
            break;
        case OVERLAY_8_SHIP:
            RBB_func_80386C48();
            break;
        case OVERLAY_9_SNOW:
            FP_func_80391324();
            spawnableActorList_add(&D_80367BC8, actor_new, ACTOR_FLAG_UNKNOWN_3);
            spawnableActorList_add(&D_80367BEC, actor_new, ACTOR_FLAG_UNKNOWN_3);
            spawnableActorList_add(&D_80367C10, actor_new, ACTOR_FLAG_UNKNOWN_3);
            break;
        case OVERLAY_A_TREE:
            CCW_func_8038DB6C();
            break;
    }

    if(func_80255D04() == 0 || loaded_asm_file == 0 ){
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
        write_file_blocks(0, 0, 0x80749530, EEPROM_MAXBLOCKS);
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

void spawnQueue_unlock(void){
    spawnQueueLock = 0;
}

void spawnQueue_lock(void){
    spawnQueueLock = 1;
}

void __spawnQueue_add_0(void (* arg0)(void)){
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg_cnt = 0;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_1(GenFunction_1 arg0, s32 arg1){
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = (void (*)(void))arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg_cnt = 1;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_2(void (* arg0)(void), s32 arg1, s32 arg2){
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != spawnQueueLength){
        spawnQueue[spawnQueueLength].func0 = arg0;
        spawnQueue[spawnQueueLength].arg[0] = arg1;
        spawnQueue[spawnQueueLength].arg[1] = arg2;
        spawnQueue[spawnQueueLength].arg_cnt = 2;
        spawnQueueLength++;
    }
}

void __spawnQueue_add_3(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3){
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
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
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
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
    u32 tmp = (map_get() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
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
        spawnQueue = (FunctionQueue *) defrag();
    }
}
