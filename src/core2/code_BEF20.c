#include <ultra64.h>
#include "functions.h"
#include "variables.h"


s32 func_80345FB4(enum item_e item, s32 diff, s32 arg2){
    s32 oldVal;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    
    oldVal = D_80385F30[item];

    if(func_80255D04())
        diff = 0;

    if(diff < 0){
        if( (item == ITEM_D_EGGS && func_803203FC(UNKFLAGS1_74_SANDCASTLE_INFINITE_EGGS))
            || (item == ITEM_16_LIFE && func_803203FC(UNKFLAGS1_73_SANDCASTLE_INFINITE_LIVES))
            || (item == ITEM_F_RED_FEATHER && func_803203FC(UNKFLAGS1_75_SANDCASTLE_INFINITE_RED_FEATHERS))
            || (item == ITEM_10_GOLD_FEATHER && func_803203FC(UNKFLAGS1_76_SANDCASTLE_INFINITE_GOLD_FEATHERS))
            || (item == ITEM_17_AIR && func_803203FC(UNKFLAGS1_96_SANDCASTLE_INFINITE_AIR))
        ){
            diff = 0;
        }
    }

    sp28 =  D_80385F30[item] =  MAX(0, D_80385F30[item] + diff);
   // sp20;

    sp34 = ((func_8031FF1C(BKPROG_B9_DOUBLE_HEALTH))? 2 : 1);
    D_80385F30[ITEM_15_HEALTH_TOTAL] = MIN(sp34*8, D_80385F30[ITEM_15_HEALTH_TOTAL]);
    D_80385F30[ITEM_14_HEALTH]= MIN(D_80385F30[ITEM_15_HEALTH_TOTAL], D_80385F30[ITEM_14_HEALTH]);
    D_80385F30[ITEM_17_AIR] = MIN(3600, D_80385F30[ITEM_17_AIR]);
    D_80385F30[ITEM_25_MUMBO_TOKEN_TOTAL] = D_80385F30[ITEM_1C_MUMBO_TOKEN];
    D_80385F30[ITEM_16_LIFE] = MIN(0xFF, D_80385F30[ITEM_16_LIFE]);

    switch(item){
        case ITEM_D_EGGS:
            sp38 = (func_8031FF1C(BKPROG_BE_CHEATO_BLUEEGGS))? 200 : 100;
            break;

        case ITEM_F_RED_FEATHER:
            sp38 = (func_8031FF1C(BKPROG_BF_CHEATO_REDFEATHERS))? 100 : 50;
            break;

        case ITEM_10_GOLD_FEATHER:
            sp38 = (func_8031FF1C(BKPROG_C0_CHEATO_GOLDFEATHERS))? 20 : 10;
            break;

        default:
            sp38 = 0;
            break;
    }
    if(sp38){
        D_80385F30[item] = MIN(sp38, D_80385F30[item]);
    }
    if(!arg2){
        func_802FACA4(item); //displays item on HUD
        if(item == ITEM_14_HEALTH || item == ITEM_17_AIR)
            func_802FACA4(ITEM_16_LIFE);
    }

    sp3C = item_empty(item);
    if(item < 6 && sp3C)
        D_80385F30[item + ITEM_6_HOURGLASS] = 0;

    switch(item){
        case ITEM_14_HEALTH:
            if(sp3C)
                D_80385FE4 = 1;
            break;
        case ITEM_17_AIR:
            sp30 = func_80301D24(oldVal);
            sp2C = func_80301D24(sp28);
            if(sp3C){
                bs_checkInterrupt(0x11);
                D_80385FE4 = 1;
            }
            if(sp2C && sp30 != sp2C ){
                if(sp2C < sp30){
                    func_8025A6EC(SFX_AIR_METER_DROPPING, 28000);
                }
                else{
                    func_8030E760(0x3e9, 1.2f, 28000);
                }
            }
            break;
        case ITEM_C_NOTE:
            sp28 = itemscore_noteScores_get(level_get());
            func_80346DB4(D_80385F30[item]);
            if(D_80385F30[item] == 100 && sp28 != 100){
                func_8025A6EC(COMUSIC_36_100TH_NOTE_COLLECTED, 20000);
                item_inc(ITEM_16_LIFE);
            }
            break;
        case ITEM_26_JIGGY_TOTAL:
            D_80385F30[ITEM_2B_UNKNOWN] += diff;
            break;
    }
    return D_80385F30[item];
}
