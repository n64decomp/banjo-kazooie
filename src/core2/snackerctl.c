#include "snackerctl.h"

#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "version.h"

#include "ch/snacker.h"

// ToDo: move to assets_e
#define SNACKER_BB_DIALOG_0 VER_SELECT(0xe26, 0xa68, 0, 0)
#define SNACKER_BB_DIALOG_1 VER_SELECT(0xe33, 0xa75, 0, 0)

s32 func_80259254(f32 *, f32, f32, f32);
void ncFirstPersonCamera_getZoomedInRotation(f32 *);

extern u8  D_8037DCCA;
extern u8  D_8037DCCB;
extern u8  D_8037DCCC;

/* .data */
f32 D_80363610[3] = {350.0f, 200.0f, -100.0f};
f32 D_8036361C[2] = {29.25f, 269.5f};

/* .bss */
SnackerCtlState s_snackerctl_state;

/* .code */
void snackerctl_reset(void){
    s_snackerctl_state = SNACKER_CTL_STATE_0_INACTIVE;
}

static s32 __snackerctl_player_within_distance(f32 x, f32 z, f32 dist){
    f32 player_position[3];

    _player_getPosition(player_position);
    return func_80259254(player_position, x, z, dist);
}

static SnackerCtlState __snackerctl_update_ttc(void){
    SnackerCtlState nextState = 0;
    f32 player_position[3];

    _player_getPosition(player_position);
    if(func_8028B470() || volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){ //(swimming || ???)
        if(player_position[1] < 600.0f
            && !__snackerctl_player_within_distance(2478.0f, 4586.0f, 1750.0f) //within 1750 of sandcastle center
            && !__snackerctl_player_within_distance(-400.0, 2315.0f, 2000.0f)  //within 2000 of blubber's ship center
        ){
            nextState = SNACKER_CTL_STATE_2_TTC;
        }
    }
    chsnacker_setControlState(nextState);
    return nextState;
}

static SnackerCtlState __snackerctl_update_rbb(void){
    SnackerCtlState nextState = 0;
    f32 sp18[3];
    if(func_8028B470()){
        func_8028E964(sp18);
        if(func_80309D58(sp18, 0))
            nextState = SNACKER_CTL_STATE_1_RBB;
    }
    chsnacker_setControlState(nextState);
    return nextState;
}

static void func_8028A558(ActorMarker *arg0, enum asset_e arg1, s32 arg2){
    func_8028F918(0);
}

static void func_8028A584(ActorMarker *arg0, enum asset_e arg1, s32 arg2){
    func_803219F4(3);
    func_8034B9BC(chBottlesBonus_getPuzzleIndex());
}

static SnackerCtlState _snackerctl_update_bottles_bonus(void){
    s32 tmp;
    f32 sp30[3];

    if(gctransition_8030BDC0() || getGameMode() != GAME_MODE_3_NORMAL)
        return 0;

    if(func_8034BB48() && chBottlesBonus_getPuzzleIndex() != 7){
        gcdialog_showText(SNACKER_BB_DIALOG_0 + (chBottlesBonus_getPuzzleIndex() << 1), 6, D_80363610, NULL, NULL, NULL);
    }
    if(!func_8028F25C() && func_80321960() == 3)
        func_803219F4(1);

    if(miscFlag_isTrue(MISC_FLAG_17_FIRST_PERSON_VIEW) && !func_8028F25C()){
        if(__snackerctl_player_within_distance(183.0f, -100.0f, 75.0f)){
            if(chBottlesBonus_getPuzzleIndex() == 6){
                if(!D_8037DCCC){
                    func_8028F94C(4, &D_80363610);
                    gcdialog_showText(SNACKER_BB_DIALOG_1, 0x6, D_80363610, NULL, func_8028A584, NULL);
                }
            }//L8028A70C
            else if(chBottlesBonus_getPuzzleIndex() == 7){
                func_8028F94C(4, &D_80363610);
                gcdialog_showText(ASSET_E35_DIALOG_BOTTLES_BONUS_REMINDER, 0x6, D_80363610, NULL, func_8028A558, NULL);
                D_8037DCCC = 1;
            }//L8028A764
            else if(jiggyscore_isCollected(0x10)){
                ncFirstPersonCamera_getZoomedInRotation(sp30);
                if( (((D_8036361C[0] <= sp30[0])? (sp30[0] - D_8036361C[0]) : -(sp30[0] - D_8036361C[0])) < 4.0f)
                    && (((D_8036361C[1] <= sp30[1])? (sp30[1] - D_8036361C[1]) : -(sp30[1] - D_8036361C[1])) < 20.0f)
                ){
                    if(!D_8037DCCA){
                        func_8028F94C(4, &D_80363610);
                        gcdialog_showText(ASSET_E21_DIALOG_BOTTLES_BONUS_DISCOVERED, 6, D_80363610, 0, func_8028A584, NULL);
                        D_8037DCCA = 1;
                    }else{
                        func_8028A584(0,0,0);
                    }
                }
            }//L8028A86C
            else{
                if(!D_8037DCCB){
                    func_8028F94C(4, &D_80363610);
                    gcdialog_showText(ASSET_E20_DIALOG_BOTTLES_BONUS_NOT_READY, 6, D_80363610, 0, func_8028A558, NULL);
                    D_8037DCCB = 1;
                }
            }
        }
    }
    return SNACKER_CTL_STATE_0_INACTIVE;
}

void snackerctl_update(void){
    switch(map_get()){
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            s_snackerctl_state = __snackerctl_update_ttc();
            break;
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            s_snackerctl_state = __snackerctl_update_rbb();
            break;
        case MAP_8C_SM_BANJOS_HOUSE:
            s_snackerctl_state = _snackerctl_update_bottles_bonus();
            break;
    }
}

SnackerCtlState snackerctl_get_state(void){
    return s_snackerctl_state;
}
