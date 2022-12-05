#include <ultra64.h>
#include "functions.h"
#include "variables.h"

s32 func_80259254(f32 *, f32, f32, f32);
void func_802C2ADC(f32 *);

extern u8  D_8037DCCA;
extern u8  D_8037DCCB;
extern u8  D_8037DCCC;

/* .data */
f32 D_80363610[3] = {350.0f, 200.0f, -100.0f};
f32 D_8036361C[2] = {29.25f, 269.5f};

/* .bss */
s32 D_8037BF50;

/* .code */
//snacker_clearState
void snacker_reset(void){
    D_8037BF50 = 0;
}

//__playerWithinHorizontalDistance
s32 func_8028A41C(f32 x, f32 z, f32 dist){
    f32 player_position[3];

    _player_getPosition(player_position);
    return func_80259254(player_position, x, z, dist);
}

//_snacker_ttc_update
s32 func_8028A45C(void){
    s32 nextState = 0;
    f32 player_position[3];

    _player_getPosition(player_position);
    if(func_8028B470() || func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)){ //(swimming || ???)
        if(player_position[1] < 600.0f
            && !func_8028A41C(2478.0f, 4586.0f, 1750.0f) //within 1750 of sandcastle center
            && !func_8028A41C(-400.0, 2315.0f, 2000.0f)  //within 2000 of blubber's ship center
        ){
            nextState = 2;
        }
    }
    func_802E1A04(nextState);
    return nextState;
}

//_snacker_rbb_update
s32 func_8028A504(void){
    s32 nextState = 0;
    f32 sp18[3];
    if(func_8028B470()){
        func_8028E964(sp18);
        if(func_80309D58(sp18, 0))
            nextState = 1;
    }
    func_802E1A04(nextState);
    return nextState;
}

void func_8028A558(s32 arg0, s32 arg1, s32 arg2){
    func_8028F918(0);
}

void func_8028A584(s32 arg0, s32 arg1, s32 arg2){
    func_803219F4(3);
    func_8034B9BC(chBottlesBonus_getPuzzleIndex());
}

//snacker_update_bottlesBonusPuzzle
s32 func_8028A5C0(void){
    s32 tmp;
    f32 sp30[3];

    if(gctransition_8030BDC0() || getGameMode() != GAME_MODE_3_NORMAL)
        return 0;

    if(func_8034BB48() && chBottlesBonus_getPuzzleIndex() != 7){
        func_80311480(0xe26 + (chBottlesBonus_getPuzzleIndex() << 1), 6, &D_80363610, 0, 0, 0);
    }
    if(!func_8028F25C() && func_80321960() == 3)
        func_803219F4(1);

    if(miscflag_isTrue(0x17) && !func_8028F25C()){
        if(func_8028A41C(183.0f, -100.0f, 75.0f)){
            if(chBottlesBonus_getPuzzleIndex() == 6){
                if(!D_8037DCCC){
                    func_8028F94C(4, &D_80363610);
                    func_80311480(0xe33, 0x6, &D_80363610, 0, func_8028A584, NULL);
                }
            }//L8028A70C
            else if(chBottlesBonus_getPuzzleIndex() == 7){
                func_8028F94C(4, &D_80363610);
                func_80311480(0xe35, 0x6, &D_80363610, 0, func_8028A558, NULL);
                D_8037DCCC = 1;
            }//L8028A764
            else if(jiggyscore_isCollected(0x10)){
                func_802C2ADC(sp30);
                if( (((D_8036361C[0] <= sp30[0])? (sp30[0] - D_8036361C[0]) : -(sp30[0] - D_8036361C[0])) < 4.0f)
                    && (((D_8036361C[1] <= sp30[1])? (sp30[1] - D_8036361C[1]) : -(sp30[1] - D_8036361C[1])) < 20.0f)
                ){
                    if(!D_8037DCCA){
                        func_8028F94C(4, &D_80363610);
                        func_80311480(0xe21, 6, &D_80363610, 0, func_8028A584, NULL);
                        D_8037DCCA = 1;
                    }else{
                        func_8028A584(0,0,0);
                    }
                }
            }//L8028A86C
            else{
                if(!D_8037DCCB){
                    func_8028F94C(4, &D_80363610);
                    func_80311480(0xe20, 6, &D_80363610, 0, func_8028A558, NULL);
                    D_8037DCCB = 1;
                }
            }
        }
    }
    return 0;
}

//snacker_updateState
void func_8028A8D0(void){
    switch(map_get()){
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            D_8037BF50 = func_8028A45C();
            break;
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            D_8037BF50 = func_8028A504();
            break;
        case MAP_8C_SM_BANJOS_HOUSE:
            D_8037BF50 = func_8028A5C0();
            break;
    }
}

//snacker_getState
s32 func_8028A94C(void){
    return D_8037BF50;
}
