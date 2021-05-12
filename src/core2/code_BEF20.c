#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8033DD9C(void);
void func_80346DB4(s32);

void func_803463D4(s32 item, s32 diff);

extern s32 D_80385F30[];
extern s32 D_80385FE8;
extern f64 D_80379100;
extern s32 D_80385FE4;



void func_80345EB0(s32 item){
    if(func_802FAFE8(item)){
        func_803463D4(item, (s32)(-func_8033DD9C()*60.0f * D_80379100));
    }else{
        func_802FACA4(item);
    }
}

void func_80345F24(s32 item){
    func_803463D4(item, 1);
}

void func_80345F44(s32 item){
    if(!func_802E4A08())
        func_803463D4(item, -1);
}

s32 item_empty(s32 item){
    return (D_80385F30[item] != 0)? 0 : 1;
}

s32 item_getCount(s32 item){
    return D_80385F30[item];
}


#if 0
/* &D_80385F30[item] saving to sp18 but should be sp1C, 
cannot access sp1C with newVal at sp18.
may be -O3 issue given func_803465DC() is null
*/ 
s32 func_80345FB4(s32 item, s32 diff, s32 arg2){
    s32 oldVal;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 newVal;

    oldVal = D_80385F30[item];

    if(func_80255D04())
        diff = 0;

    if(diff < 0){
        if( (item == ITEM_EGGS && func_803203FC(0x74))
            || (item == ITEM_LIFE && func_803203FC(0x73))
            || (item == ITEM_RED_FEATHER && func_803203FC(0x75))
            || (item == ITEM_GOLD_FEATHER && func_803203FC(0x76))
            || (item == item_air && func_803203FC(0x96))) 
            diff = 0;
    }
    (newVal = ((D_80385F30[item] + diff) < 0)? 0 : D_80385F30[item] + diff);
    D_80385F30[item] = newVal;

    sp34 = (func_8031FF1C(0xb9))? 2 : 1 ;
    D_80385F30[item_health_total] = (D_80385F30[item_health_total] > sp34*8)? sp34*8 : D_80385F30[item_health_total];

    D_80385F30[item_health]= (D_80385F30[item_health_total] < D_80385F30[item_health])? D_80385F30[item_health_total]: D_80385F30[item_health];

    D_80385F30[item_air] = (0xe10 < D_80385F30[item_air])? 0xe10 : D_80385F30[item_air];
    
    D_80385F30[item_mumbo_token_total] = D_80385F30[item_mumbo_token];

    D_80385F30[ITEM_LIFE] = (0xFF < D_80385F30[ITEM_LIFE])? 0xFF : D_80385F30[ITEM_LIFE];

    switch(item){
        case ITEM_EGGS:
            sp38 = (func_8031FF1C(0xbe))? 200 : 100;
            break;

        case ITEM_RED_FEATHER:
            sp38 = (func_8031FF1C(0xbf))? 100 : 50;
            break;

        case ITEM_GOLD_FEATHER:
            sp38 = (func_8031FF1C(0xc0))? 20 : 10;
            break;

        default:
            sp38 = 0;
            break;
    }
    if(sp38){
        D_80385F30[item] = (sp38 < D_80385F30[item])? sp38 :  D_80385F30[item];
    }
    if(!arg2){
        func_802FACA4(item); //displays item on HUD
        if(item == item_health || item == item_air)
            func_802FACA4(ITEM_LIFE);
    }

    sp3C = item_empty(item);
    if(item < 6 && sp3C)
        D_80385F30[item + 6] = 0;

    switch(item){
        case item_health:
            if(sp3C)
                D_80385FE4 = 1;
            break;
        case item_air:
            sp30 = func_80301D24(oldVal);
            sp2C = func_80301D24(newVal);
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
        case item_note:
            sp28 = func_80346F34(func_80321900());
            func_80346DB4(D_80385F30[item]);
            if(D_80385F30[item] == 100 && sp28 != 100){
                func_8025A6EC(JINGLE_100TH_NOTE_COLLECTED, 20000);
                func_80345F24(ITEM_LIFE);
            }
            break;
        case item_jiggy_total:
            D_80385F30[0x2b] += diff;
            break;
    }
    return D_80385F30[item];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80345FB4.s")
#endif

void func_803463D4(s32 item, s32 diff){
    func_80345FB4(item, diff, 0);
}

void func_803463F4(s32 item, s32 diff){
    func_80345FB4(item, diff, 1);
}

void func_80346414(s32 item, s32 val){
    func_803463D4(item, val - item_getCount(item));
}

void func_80346448(s32 item){
    func_803463D4(item, 9999999);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034646C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803464F8.s")
// void func_803464F8(s32 level){
//     s32 *tmp;
//     D_80385F30[0] = 0;
//     D_80385F30[6] = 0;
//     D_80385F30[1] = 0;
//     D_80385F30[7] = 0;
    
//     tmp = &D_80385F30[2];
//     D_80385F30[3] = 0;
//     D_80385F30[9] = 0;
//     D_80385F30[4] = 0;
//     D_80385F30[10] = 0;
//     D_80385F30[5] = 0;
//     D_80385F30[11] = 0;
//     D_80385F30[2] = 0;
//     D_80385F30[8] = 0;
//     D_80385F30[12] = 0;
//     D_80385F30[14] = jiggyscore_leveltotal(level);
//     D_80385F30[18] = 0;
//     D_80385F30[23] = 0xe10;
//     D_80385F30[24] = 0;
//     D_80385F30[25] = 0;
//     D_80385F30[35] = 0;
//     D_80385F30[26] = 0;
//     D_80385F30[27] = 0;
//     D_80385F30[31] = 0;
//     D_80385F30[32] = 0;
//     D_80385F30[33] = 0;
//     D_80385F30[34] = 0;
//     func_802FA5D0();
//     D_80385FE8 = 1;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803465BC.s")

void func_803465DC(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803465E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346DB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80346F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803470A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034717C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034722C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803476B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034774C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034789C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347958.s")

void func_80347984(void){}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_8034798C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_803479C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347A14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_BEF20/func_80347C70.s")
