#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

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

extern u8 D_80365DC0;
extern u8 D_80365DC4;
extern FunctionQueue *D_80365DC8;

void func_802E1790(void);

void func_802C3BDC(void);
void func_802C3BE8(void);

void func_802D7558(s32 *, s32, ActorInfo*, u32);
void func_802D75B4(s32 *, s32, ActorInfo*, u32);
void func_802D7610(s32 *, s32, ActorInfo*, u32);
void func_802DEB18(s32 *, s32, ActorInfo*, u32);

extern ActorInfo D_80365F60;
extern ActorInfo D_80365F84; //turbotrainers
extern ActorInfo D_80366090; //bigbutt
extern ActorInfo D_803660B4; //brownbull
extern ActorInfo D_803662A8; //jiggy
extern ActorInfo D_80366300; //jigdance
extern ActorInfo D_80366340;
extern ActorInfo D_80366364;
extern ActorInfo D_80366388;
extern ActorInfo D_803663AC;
extern ActorInfo D_803663D0;
extern ActorInfo D_803663F4;
extern ActorInfo D_80366C50; //music_note
extern ActorInfo D_80366C80; //chhoneycarrier
extern ActorInfo D_80366CA4; //chhoney
extern ActorInfo D_80366EC0;
extern ActorInfo D_80367160;
extern ActorInfo D_80367184;
extern ActorInfo D_80367200; //jingo_blue
extern ActorInfo D_80367224; //jingo_green
extern ActorInfo D_80367248; //jingo_yellow
extern ActorInfo D_8036726C; //jingo_pink
extern ActorInfo D_80367290; //jingo_orange
extern ActorInfo D_803672E0; //chbeehive
extern ActorInfo D_80367310; //bees
extern ActorInfo D_80367390; //chwaterfallfx
extern ActorInfo D_803674E0; //mumbo
extern ActorInfo D_803675F0;
extern ActorInfo D_80367A20;//wading boots
extern ActorInfo D_80367AB0;
extern ActorInfo D_80367AD4;
extern ActorInfo D_80367AF8;
extern ActorInfo D_80367C60;
extern ActorInfo D_80367D00; //egg

extern ActorInfo D_80366430; //extralife
extern ActorInfo D_80365FB0; //shrapnel
extern ActorInfo D_80367A50; //chbadshad
extern ActorInfo D_803685A0; //mumbotoken
extern ActorInfo D_80367F30;
extern ActorInfo D_80365FE0;
extern ActorInfo D_80367468; //gloop
extern ActorInfo D_80366F20; //chshockjump
extern ActorInfo D_80366F44; //flight_pad
extern ActorInfo D_80367D24; //redfeather
extern ActorInfo D_80367D48; //goldfeather 
extern ActorInfo D_80367C90; //spent_redfeather
extern ActorInfo D_80367CB4; //spent_goldfeather
extern ActorInfo D_80367DA0; //bottles
extern ActorInfo D_80367E20; //chmolehill
extern ActorInfo D_80373DC0;
extern ActorInfo D_80367E70;
extern ActorInfo D_80368620; //snacker
extern ActorInfo D_80366EF0; //large_shadow
extern ActorInfo D_80367B20; //chclimbbase
extern ActorInfo D_80367BA4; //gold_bullion
extern ActorInfo D_80367B80; //orange
extern ActorInfo D_80372970; //leaf_particle
extern ActorInfo D_80372994;
extern ActorInfo D_803729B8; //rain
extern ActorInfo D_803729DC;
extern ActorInfo D_80372A00; //snow
extern ActorInfo D_80372A24; 
extern ActorInfo D_80372A48; 
extern ActorInfo D_80372A6C; 
extern ActorInfo D_8036D970; //boombox
extern ActorInfo D_803677A8; //ice_key
extern ActorInfo D_80367814; //SnS_egg
extern ActorInfo D_80372A90; //fire
extern ActorInfo D_80367838; //level_entry_disk
extern ActorInfo D_80367760;
extern ActorInfo D_80367784;
extern ActorInfo D_80365E58; //banjo.without_right_hand
extern ActorInfo D_80365EAC; //banjo.playing_gameboy
extern ActorInfo D_80365F00; //banjo.cooking
extern ActorInfo D_803677CC;//mumbo_transform_pad
extern ActorInfo D_803677F0;
extern ActorInfo D_803731B0;
extern ActorInfo D_80368710;//snowball
extern ActorInfo D_803687C0;//sir_slush_hat
extern ActorInfo D_80372AC0;//water_drops
extern ActorInfo D_80372BA4;//ice_cube
extern ActorInfo D_8036804C;//GAME_OVER
extern ActorInfo D_8036807C;//THE_END
extern ActorInfo D_803680AC;//player_KAZOOIE
extern ActorInfo D_803680DC;//copyright_info
extern ActorInfo D_80368124;//PRESS_START
extern ActorInfo D_803682D0;//jiggy_picture
extern ActorInfo D_8036833C; 
extern ActorInfo D_8036838C;
extern ActorInfo D_80368418;//banjos_hand_BB
extern ActorInfo D_80368174;//NO_CONTROLLER)
extern ActorInfo D_80367530;//mumbo_token_sign.5
extern ActorInfo D_80367554;//mumbo_toke_sign.10
extern ActorInfo D_80367578;//mumbo_toke_sign.15
extern ActorInfo D_8036759C;//mumbo_toke_sign.20
extern ActorInfo D_803675C0;//mumbo_toke_sign.25
extern ActorInfo D_8036785C;//witch_switch.mm;
extern ActorInfo D_80367880;//witch_switch.mmm
extern ActorInfo D_803678A4;//witch_switch.ttc
extern ActorInfo D_803678C8;//witch_switch.rbb
extern ActorInfo D_803678EC;//witch_switch.ccw
extern ActorInfo D_80367910;//witch_switch.fp
extern ActorInfo D_80367934;//witch_switch.cc
extern ActorInfo D_80367958;//witch_switch.bgs
extern ActorInfo D_8036797C;//witch_switch.gv
extern ActorInfo D_80368450;//fire_sparkle
extern ActorInfo D_803684BC;//roysten
extern ActorInfo D_803684E0;//cuckoo_clock
extern ActorInfo D_80368504;
extern ActorInfo D_80368528;
extern ActorInfo D_8036854C;
extern ActorInfo D_80368570;
extern ActorInfo D_80368474;
extern ActorInfo D_80368498;
extern ActorInfo D_803732E0;
extern ActorInfo D_80372810;
extern ActorInfo D_80373100;
extern ActorInfo D_80373134;
extern ActorInfo D_80373158;
extern ActorInfo D_80372EE0;

extern ActorInfo D_80372F50; //ticker
extern ActorInfo D_80372C80; //floatsam
extern ActorInfo D_80372C18; //teehee
extern ActorInfo D_80372FC0;
extern ActorInfo D_80372FE4;
extern ActorInfo D_803730D8; //nibbly
extern ActorInfo D_80367130; //buzzbomb
extern ActorInfo D_80372B80;
extern ActorInfo D_80367404; //scrapnel
extern ActorInfo D_80372D78; //limbo
extern ActorInfo D_80372DF8; //grublin_hood
extern ActorInfo D_80372E78; //mummum
extern ActorInfo D_80372840; //grillchompa
extern ActorInfo D_803670B8; //snippet
extern ActorInfo D_803670DC; //black_snippet
extern ActorInfo D_80367100; //mutie_snippet
extern ActorInfo D_80372870; //clucker
extern ActorInfo D_803728A0; //scarab
extern ActorInfo D_80368670; //sirslush

extern ActorInfo D_80367BC8;
extern ActorInfo D_80367BEC;
extern ActorInfo D_80367C10;

void func_802C2B10(void){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    D_80365DC8 = (FunctionQueue *) malloc(tmp * sizeof(FunctionQueue));
}

void func_802C2B5C(void){
    s32 loaded_asm_file;

    loaded_asm_file = get_loaded_overlay_id();
    func_802C3BE8();
    D_80365DC4 = 0;
    func_802D1724();
    func_802E1790();
    switch(loaded_asm_file){
        case OVERLAY_2_WHALE:
            cc_func_803870E0();
            break;
        case OVERLAY_4_DESERT:
            gv_func_80387118();
            break;
        case OVERLAY_5_BEACH:
            break;
        case OVERLAY_7_SWAMP:
            bgs_func_803885DC();
            break;
        default:
            break;
    }

    func_80305D38(); 
    func_803062D0();
    func_80325F8C();
    func_8030538C();
    func_803053E8(&D_80367160, actor_new, 0x0000000); //cutscene Trigger?
    func_803053E8(&D_803675F0, actor_new, 0x0000040);
    func_803053E8(&D_80366090, actor_new, 0x2010103);
    func_803053E8(&D_803660B4, actor_new, 0x0000103);
    func_803053E8(&D_803674E0, actor_new, 0x0000182);
    func_803053E8(&D_803672E0, actor_new, 0x2000108);
    func_803053E8(&D_80367310, actor_new, 0x0020001);
    func_803053E8(&D_80367390, actor_new, 0x0080084);
    func_803053E8(&D_80367248, actor_new, 0x0000140);
    func_803053E8(&D_80367290, actor_new, 0x0000140);
    func_803053E8(&D_80367200, actor_new, 0x0000140);
    func_803053E8(&D_8036726C, actor_new, 0x0000140);
    func_803053E8(&D_80367224, actor_new, 0x0000140);
    func_803053E8(&D_803662A8, actor_new, 0x02000C0);
    func_803053E8(&D_80366300, actor_new, 0x0000004);
    func_803053E8(&D_80367C60, actor_new, 0x0000004);
    func_803053E8(&D_80367A20, actor_new, 0x0000000);
    func_803053E8(&D_80366C80, actor_new, 0x0200040); //chhoneycarrier
    func_803053E8(&D_80366CA4, actor_new, 0x0200040); //chhoney
    func_803053E8(&D_80366C50, actor_new, 0x0200000); //music_note
    func_803053E8(&D_80367D00, actor_new, 0x0200000); //egg
    func_803053E8(&D_80366340, func_802C8A54, 0x0000004);
    func_803053E8(&D_80366364, func_802C8AA8, 0x0000004);
    func_803053E8(&D_80366388, func_802C8AF8, 0x0000004);
    func_803053E8(&D_803663AC, func_802C8B4C, 0x0000004);
    func_803053E8(&D_803663D0, func_802C8BA8, 0x0000004);
    func_803053E8(&D_803663F4, func_802C8C04, 0x0000004);
    func_803053E8(&D_80367AB0, func_802D7558, 0x0000004);
    func_803053E8(&D_80367AD4, func_802D75B4, 0x0000004);
    func_803053E8(&D_80367AF8, func_802D7610, 0x0000004);
    func_803053E8(&D_80366EC0, actor_new, 0x0000000);
    func_803053E8(&D_80365F60, actor_new, 0x0000004);
    func_803053E8(&D_80365F84, actor_new, 0x0000004); //turbotrainers
    func_803053E8(&D_80367184, actor_new, 0x0000000);
    func_803053E8(&D_80366430, actor_new, 0x0200000); //extralife
    func_803053E8(&D_80365FB0, actor_new, 0x0000004); //shrapnel
    func_803053E8(&D_80367A50, actor_new, 0x0000004); //chbadshad
    func_803053E8(&D_803685A0, actor_new, 0x0000040); //mumbotoken
    func_803053E8(&D_80367F30, actor_new, 0x0000400);
    func_803053E8(&D_80365FE0, actor_new, 0x0000004);
    func_803053E8(&D_80367468, actor_new, 0x000008A); //gloop
    func_803053E8(&D_80366F20, actor_new, 0x0000000); //chshockjump
    func_803053E8(&D_80366F44, actor_new, 0x0000000); //flight_pad
    func_803053E8(&D_80367D24, actor_new, 0x0200000); //redfeather
    func_803053E8(&D_80367D48, actor_new, 0x0200000); //goldfeather 
    func_803053E8(&D_80367C90, actor_new, 0x0000004); //spent_redfeather
    func_803053E8(&D_80367CB4, actor_new, 0x0000004); //spent_goldfeather
    func_803053E8(&D_80367DA0, actor_new, 0x0000180); //bottles
    func_803053E8(&D_80367E20, actor_new, 0x44); //chmolehill
    func_803053E8(&D_80373DC0, actor_new, 0x80000);
    func_803053E8(&D_80367E70, actor_new, 0x0);
    func_803053E8(&D_80368620, actor_new, 0x10004); //snacker
    func_803053E8(&D_80366EF0, actor_new, 0x20004); //large_shadow
    func_803053E8(&D_80367B20, actor_new, 0x80); //chclimbbase
    func_803053E8(&D_80367BA4, actor_new, 0x40); //gold_bullion
    func_803053E8(&D_80367B80, actor_new, 0x2); //orange
    func_803053E8(&D_80372970, actor_new, 0x80); //leaf_particle
    func_803053E8(&D_80372994, actor_new, 0x80);
    func_803053E8(&D_803729B8, actor_new, 0x80); //rain
    func_803053E8(&D_803729DC, actor_new, 0x80);
    func_803053E8(&D_80372A00, actor_new, 0x80); //snow
    func_803053E8(&D_80372A24, actor_new, 0x80); 
    func_803053E8(&D_80372A48, actor_new, 0x81); 
    func_803053E8(&D_80372A6C, actor_new, 0x81); 
    func_803053E8(&D_8036D970, actor_new, 0x80); //boombox
    func_803053E8(&D_803677A8, actor_new, 0x8600); //ice_key
    func_803053E8(&D_80367814, actor_new, 0x8600); //SnS_egg
    func_803053E8(&D_80372A90, actor_new, 0x0); //fire
    func_803053E8(&D_80367838, actor_new, 0x8600); //level_entry_disk
    func_803053E8(&D_80367760, actor_new, 0x1000);
    func_803053E8(&D_80367784, actor_new, 0x1000);
    func_803053E8(&D_80365E58, actor_new, 0x20480); //banjo.without_right_hand
    func_803053E8(&D_80365EAC, actor_new, 0x20480); //banjo.playing_gameboy
    func_803053E8(&D_80365F00, actor_new, 0x20480); //banjo.cooking
    func_803053E8(&D_803677CC, actor_new, 0x8680);//mumbo_transform_pad
    func_803053E8(&D_803677F0, actor_new, 0x8680);
    func_803053E8(&D_803731B0, actor_new, 0x0);
    func_803053E8(&D_80368710, actor_new, 0x100044);//snowball
    func_803053E8(&D_803687C0, actor_new, 0x4);//sir_slush_hat
    func_803053E8(&D_80372AC0, actor_new, 0x400);//water_drops
    func_803053E8(&D_80372BA4, actor_new, 0x2020141);//ice_cube
    func_803053E8(&D_8036804C, actor_new, 0x508604);//GAME_OVER
    func_803053E8(&D_8036807C, actor_new, 0x508604);//THE_END
    func_803053E8(&D_803680AC, actor_new, 0x508604);//player_KAZOOIE
    func_803053E8(&D_803680DC, actor_new, 0x508604);//copyright_info
    func_803053E8(&D_80368124, actor_new, 0x508604);//PRESS_START
    func_803053E8(&D_803682D0, func_802DEB18, 0x509604);//jiggy_picture
    func_803053E8(&D_8036833C, actor_new, 0x508604); 
    func_803053E8(&D_8036838C, actor_new, 0x509604);
    func_803053E8(&D_80368418, actor_new, 0x508644);//banjos_hand_BB
    func_803053E8(&D_80368174, actor_new, 0x508604);//NO_CONTROLLER);
    func_803053E8(&D_80367530, actor_new, 0x0);//mumbo_token_sign.5
    func_803053E8(&D_80367554, actor_new, 0x0);//mumbo_toke_sign.10
    func_803053E8(&D_80367578, actor_new, 0x0);//mumbo_toke_sign.15
    func_803053E8(&D_8036759C, actor_new, 0x0);//mumbo_toke_sign.20
    func_803053E8(&D_803675C0, actor_new, 0x0);//mumbo_toke_sign.25
    func_803053E8(&D_8036785C, actor_new, 0x0);//witch_switch.mm;
    func_803053E8(&D_80367880, actor_new, 0x0);//witch_switch.mmm
    func_803053E8(&D_803678A4, actor_new, 0x0);//witch_switch.ttc
    func_803053E8(&D_803678C8, actor_new, 0x0);//witch_switch.rbb
    func_803053E8(&D_803678EC, actor_new, 0x0);//witch_switch.ccw
    func_803053E8(&D_80367910, actor_new, 0x0);//witch_switch.fp
    func_803053E8(&D_80367934, actor_new, 0x0);//witch_switch.cc
    func_803053E8(&D_80367958, actor_new, 0x0);//witch_switch.bgs
    func_803053E8(&D_8036797C, actor_new, 0x400);//witch_switch.gv
    func_803053E8(&D_80368450, actor_new, 0x20000);//fire_sparkle
    func_803053E8(&D_803684BC, actor_new, 0x180);//roysten
    func_803053E8(&D_803684E0, actor_new, 0x0);//cuckoo_clock
    func_803053E8(&D_80368504, actor_new, 0x0);
    func_803053E8(&D_80368528, actor_new, 0x0);
    func_803053E8(&D_8036854C, actor_new, 0x0);
    func_803053E8(&D_80368570, actor_new, 0x0);
    func_803053E8(&D_80368474, actor_new, 0xC8);
    func_803053E8(&D_80368498, actor_new, 0x0);
    func_803053E8(&D_803732E0, actor_new, 0x0);
    func_803053E8(&D_80372810, actor_new, 0x8008A8);
    func_803053E8(&D_80373100, actor_new, 0x28008A8);
    func_803053E8(&D_80373134, actor_new, 0x880);
    func_803053E8(&D_80373158, actor_new, 0x880);
    func_803053E8(&D_80372EE0, actor_new, 0x2000141);
    func_803054A4(&D_80372F50, actor_new, 0x2010101, 2); //ticker
    func_803054A4(&D_80372C80, actor_new, 0x2010981,0x31); //floatsam
    func_803054A4(&D_80372C18, actor_new, 0x211A9,0x1B); //teehee
    func_803054A4(&D_80372FC0, actor_new, 0x2010001,0x1b);
    func_803054A4(&D_80372FE4, actor_new, 0x2010401,0x1b);
    func_803054A4(&D_803730D8, actor_new, 0x2200021,0x1b); //nibbly
    func_803054A4(&D_80367130, actor_new, 0x20009a9,0xd); //buzzbomb
    func_803054A4(&D_80372B80, actor_new, 0x2020141,0x27);
    func_803054A4(&D_80367404, actor_new, 0x2000101,7); //scrapnel
    func_803054A4(&D_80372D78, actor_new, 0x3010121,0x1b); //limbo
    func_803054A4(&D_80372DF8, actor_new, 0x2010121,0x31); //grublin_hood
    func_803054A4(&D_80372E78, actor_new, 0x3010129,0x12); //mummum
    func_803054A4(&D_80372840, actor_new, 0x2800960,0xb); //grillchompa
    func_803054A4(&D_803670B8, actor_new, 0x3000121,7); //snippet
    func_803054A4(&D_803670DC, actor_new, 0x30000a0,7); //black_snippet
    func_803054A4(&D_80367100, actor_new, 0x3001021,7); //mutie_snippet
    func_803054A4(&D_80372870, actor_new, 0x2800820,0x40); //clucker
    func_803054A4(&D_803728A0, actor_new, 0x2000981,0x12); //scarab
    func_803054A4(&D_80368670, actor_new, 0x2000460,0x27); //sirslush
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
            sm_func_80386810();
            break;
        case OVERLAY_3_HAUNTED:
            mmm_func_803890E0();
            break;
        case OVERLAY_2_WHALE:
            cc_func_80387DA0();
            break;
        case OVERLAY_4_DESERT:
            gv_func_8038F154();
            break;
        case OVERLAY_5_BEACH:
            ttc_func_80388AC0();
            break;
        case OVERLAY_6_JUNGLE:
            mm_func_803888B0();
            break;
        case OVERLAY_7_SWAMP:
            bgs_func_8038F1E0();
            break;
        case OVERLAY_8_SHIP:
            rbb_func_80386C48();
            break;
        case OVERLAY_9_SNOW:
            fp_func_80391324();
            func_803053E8(&D_80367BC8, actor_new, 0x8);
            func_803053E8(&D_80367BEC, actor_new, 0x8);
            func_803053E8(&D_80367C10, actor_new, 0x8);
            break;
        case OVERLAY_A_TREE:
            ccw_func_8038DB6C();
            break;
    }

    if(func_80255D04() == 0 || loaded_asm_file == 0 ){
        func_8030578C();
    }
    func_80305990(1);
    func_8032A5F8();
    func_802C3BDC();
}

void func_802C398C(void){
    func_803053B8();
    func_80326124();
    func_80305D94();
    free(D_80365DC8);
    D_80365DC8 = NULL;
    D_80365DC4 = 0;
    
}

void func_802C39D4(void){
    func_803268B4();
    if(!levelSpecificFlags_validateCRC2()){
        write_file_blocks(0, 0, 0x80749530, EEPROM_MAXBLOCKS);
    }
}

void func_802C3A18(void){
    func_803283BC();
}

void func_802C3A38(void){
    s32 i;

    func_802C3BE8();
    for(i = 0; i < D_80365DC4; i++){
        switch(D_80365DC8[i].arg_cnt){
            case 0:
                D_80365DC8[i].func0();
                break;
            case 1:
                D_80365DC8[i].func1(D_80365DC8[i].arg[0]);
                break;
            case 2:
                D_80365DC8[i].func2(D_80365DC8[i].arg[0], D_80365DC8[i].arg[1]);
                break;
            case 3:
                D_80365DC8[i].func3(D_80365DC8[i].arg[0], D_80365DC8[i].arg[1], D_80365DC8[i].arg[2]);
                break;
            case 4:
                D_80365DC8[i].func4(D_80365DC8[i].arg[0], D_80365DC8[i].arg[1], D_80365DC8[i].arg[2], D_80365DC8[i].arg[3]);
                break;
            case 5:
                D_80365DC8[i].func5(D_80365DC8[i].arg[0], D_80365DC8[i].arg[1], D_80365DC8[i].arg[2], D_80365DC8[i].arg[3], D_80365DC8[i].arg[4]);
                break;
            default:
                break;
        }
    }
    D_80365DC4 = 0;
    func_803283D4();
}

void func_802C3BDC(void){
    D_80365DC0 = 0;
}

void func_802C3BE8(void){
    D_80365DC0 = 1;
}

void func_802C3BF8(void (* arg0)(void)){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg_cnt = 0;
        D_80365DC4++;
    }
}

void func_802C3C88(void (* arg0)(void), s32 arg1){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg[0] = arg1;
        D_80365DC8[D_80365DC4].arg_cnt = 1;
        D_80365DC4++;
    }
}

void func_802C3D3C(void (* arg0)(void), s32 arg1, s32 arg2){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg[0] = arg1;
        D_80365DC8[D_80365DC4].arg[1] = arg2;
        D_80365DC8[D_80365DC4].arg_cnt = 2;
        D_80365DC4++;
    }
}

void func_802C3E10(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg[0] = arg1;
        D_80365DC8[D_80365DC4].arg[1] = arg2;
        D_80365DC8[D_80365DC4].arg[2] = arg3;
        D_80365DC8[D_80365DC4].arg_cnt = 3;
        D_80365DC4++;
    }
}

void func_802C3F04(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3, s32 arg4){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg[0] = arg1;
        D_80365DC8[D_80365DC4].arg[1] = arg2;
        D_80365DC8[D_80365DC4].arg[2] = arg3;
        D_80365DC8[D_80365DC4].arg[3] = arg4;
        D_80365DC8[D_80365DC4].arg_cnt = 4;
        D_80365DC4++;
    }
}

void func_802C4014(void (* arg0)(void), s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5){
    u32 tmp = (func_803348C0() == MAP_90_GL_BATTLEMENTS)? 0x32: 0xF;
    if(tmp != D_80365DC4){
        D_80365DC8[D_80365DC4].func0 = arg0;
        D_80365DC8[D_80365DC4].arg[0] = arg1;
        D_80365DC8[D_80365DC4].arg[1] = arg2;
        D_80365DC8[D_80365DC4].arg[2] = arg3;
        D_80365DC8[D_80365DC4].arg[3] = arg4;
        D_80365DC8[D_80365DC4].arg[4] = arg5;
        D_80365DC8[D_80365DC4].arg_cnt = 5;
        D_80365DC4++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C4140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C418C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C41D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C4218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C4260.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C42B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_3BB80/func_802C42F0.s")

void func_802C4320(FunctionQueue *arg0){
    if((arg0 = D_80365DC8) != NULL)
        D_80365DC8 = (FunctionQueue *)func_802555DC();
}