#include <ultra64.h>
#include "functions.h"
#include "variables.h"

ParticleEmitter * func_802EDD8C(f32[3], f32, f32);
f32 func_8024DDD8(f32[3], f32);
extern void func_80356074(f32[3], f32[3], f32, f32);

extern f32 D_8037D1A0;
extern s32 D_8037D1A4;
extern f32 D_8037D1A8[];

extern f32 D_8037D1BC;
extern f32 D_8037D1C0;
extern f32 D_8037D1C4;
extern f32 D_8037D1C8;
extern s32 D_8037D1CC;
extern s32 D_8037D1D0;
extern u8 D_8037D1D4;

extern struct {
    s32 map_id;
    s32 exit_id;
}D_8037D1E0;

/*.code */
f32 func_8029AF50(f32 arg0, f32 arg1, f32 arg2){
    return (arg0 - arg1)/(arg2 - arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029AF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B0C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B11C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B174.s")

f32 func_8029B2D0(void){
    return D_8037D1BC;
}

f32 func_8029B2DC(void){
    return D_8037D1C0;
}

f32 func_8029B2E8(void){
    return D_8037D1C8;
}

f32 func_8029B2F4(void){
    return D_8037D1C4;
}

s32 func_8029B300(void){
    return D_8037D1A4;
}

f32 func_8029B30C(void){
    return D_8037D1A0;
}

void func_8029B318(s32 arg0){
    D_8037D1D4 = arg0;
}

void func_8029B324(s32 arg0, f32 arg1){
    D_8037D1A8[arg0] = arg1;
}

f32 func_8029B33C(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    return func_8024DDD8(sp1C, func_8029B2F4());
}

s32 func_8029B370(void){
    return D_8037D1D0;
}

s32 func_8029B37C(void){
    return D_8037D1CC;
}

bool func_8029B388(void){
    return D_8037D1D0 == 1;
}

bool func_8029B39C(void){
    return D_8037D1CC == 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B3B0.s")

f32 func_8029B41C(void){
    f32 sp2C[3];
    f32 sp20[3];
    f32 sp1C;

    player_getPosition(sp2C);
    func_8024C5CC(sp20);
    func_80257F18(sp2C, sp20, &sp1C);
    return sp1C;
}

#ifndef NONMATCHING //requires .rodata
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B458.s")
#else
enum bs_e func_8029B458(void){
    enum bs_e sp1C;
    
    sp1C = bs_getState();
    switch(_player_getTransformation()){
        case TRANSFORM_2_TERMITE:
            return BS_38_ANT_FALL;

        case TRANSFORM_3_PUMPKIN:
            return BS_4B_PUMPKIN_FALL;

        case TRANSFORM_5_CROC:
            return BS_61_CROC_FALL;

        case TRANSFORM_4_WALRUS:
            if(func_802B8190())
                return BS_82_WALRUS_SLED_LOSE_IN_AIR;
            return BS_6A_WALRUS_FALL;

        case TRANSFORM_6_BEE:
            return BS_88_BEE_FALL;

        default:
            if(bsbtrot_inSet())
                return BS_71_BTROT_FALL;
            return BS_2F_FALL;
    }
}
#endif

enum bs_e func_8029B504(void){
    enum bs_e sp1C;

    if(func_802933C0(0xF))
        return 0;

    func_802933E8(0xF);
    sp1C = func_8029B458();
    if(bs_getState() != sp1C)
        return sp1C;
    return 0;

}

s32 func_8029B564(void){
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B56C.s")

void func_8029B5EC(void){
    func_802DC560(0, 0);
    func_802E412C(1, 0);
    func_802E4078(MAP_1F_CS_START_RAREWARE, 0, 1);
}

void func_8029B62C(void){
    if(item_empty(ITEM_16_LIFE)){
        if(!func_8031FF1C(BKPROG_BD_ENTER_LAIR_CUTSCENE) || func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)){
            func_8025A430(-1, 0x7D0, 3);
            func_8025A2B0();
            func_802DC528(0, 0);
            func_80324C58();
            timedFunc_set_0(5.0f, func_8029B5EC);
        }
        else{
            func_802E412C(1, 0);
            func_802E4078(MAP_83_CS_GAME_OVER_MACHINE_ROOM, 0, 1);

        }
    }
    else{
        func_802E4048(D_8037D1E0.map_id, D_8037D1E0.exit_id, 1);
    }
}

void func_8029B6F0(void){
    if(item_empty(ITEM_16_LIFE)){
        func_8029B62C();
    }
    else{
        func_802E4078(D_8037D1E0.map_id, D_8037D1E0.exit_id, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B73C.s")

void func_8029B85C(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    func_8030E6D4(SFX_EB_GRUNTY_LAUGH_2);
    func_8029B62C();
}

void func_8029B890(void){
    if(!func_8031FF1C(BKPROG_A8_HAS_DIED) && !func_803203FC(2)){
        func_803114D0();
        if(bs_getState() == 0x54){
            func_8029B62C();
            return;
        }
        func_80311480(0xf81, 7, NULL, NULL, func_8029B85C, NULL);
        func_80320004(BKPROG_A8_HAS_DIED, TRUE);
    }
    else{
        func_8029B62C();
    }
}

void func_8029B930(void){
    func_803114D0();
}

ParticleEmitter *func_8029B950(f32 pos[3],f32 arg1){
    return func_802EDD8C(pos, arg1, func_80294500());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029B9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BA44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BC60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BCAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BCF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BD90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BDBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BDE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BE10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BE5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BE88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029BF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C0D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C22C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C3E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C4E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C5E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C674.s")

extern f32 D_80374D98;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C748.s")

enum bs_e func_8029C780(void){
    if(button_held(BUTTON_Z) && can_flip())
        return BS_12_BFLIP;

    if(func_802933C0(2))
        return BS_5_JUMP;

    if(func_802933C0(1))
        return BS_23_FLY_ENTER;

    return BS_5_JUMP;
}

void func_8029C7F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    func_80289F10(arg0);
    func_802991A8(arg1);
    func_8029957C(arg2);
    func_802978DC(arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_13FC0/func_8029C848.s")

void func_8029C984(void){
    func_8025AB00();
    func_8025A2FC(0, 4000);
    func_8025A70C(COMUSIC_1A_DEATH);
    func_8024BD08(0);
}

s32 func_8029C9C0(s32 arg0){
    if(func_802933C0(0xF))
        return arg0;
    
    if(button_pressed(BUTTON_A))
        arg0 = func_8029C780();

    if(button_pressed(BUTTON_B) && can_claw())
        arg0 = BS_CLAW;

    if(button_held(BUTTON_Z) && should_beak_barge())
        arg0 = BS_BBARGE;

    if(func_80294F78())
        arg0 = func_802926C0();
    
    if(player_isSliding())
        arg0  = BS_SLIDE;

    return arg0;
}

s32 func_8029CA94(s32 arg0){
    if(func_802933C0(0x19))
        arg0 = func_80292738();
    
    if(func_802933C0(0x1A))
        arg0 = (player_getTransformation() == TRANSFORM_6_BEE) ? 0x46 : BS_JIG_NOTEDOOR;

    if(func_802933C0(0xE))
        arg0 = BS_25_LONGLEG_ENTER;

    if(func_802933C0(0x10))
        arg0 = BS_BTROT_ENTER;

    if(func_802933C0(0x6))
        arg0 = 0x53;

    if(func_802933C0(0x7))
        arg0 = BS_JIG_JIGGY;

    if(func_802933C0(0x14))
        arg0 = (player_getTransformation() == TRANSFORM_4_WALRUS) ? 0x80 : 0x53;
    
    func_802933FC(0xF);

    return arg0;
}

void func_8029CB84(void){
    pitch_setIdeal(0.0f);
    pitch_applyIdeal();

    roll_setIdeal(0.0f);
    roll_applyIdeal();
}

void func_8029CBC4(void){
    func_8025A55C(-1, 4000, 0xc);
    func_8024BD08(1);
}

void func_8029CBF4(void){
    if(item_getCount(ITEM_E_JIGGY) == 10){
        if( jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
            timedFunc_set_3(D_80374D98, func_802E4078, MAP_95_CS_END_ALL_100, 0, 1);
        }//L8029CC58

        timedFunc_set_0(4.0f, func_8029CBC4);
        func_8025A6EC(COMUSIC_42_NOTEDOOR_OPENING_FANFARE, -1);
    }//L8029CC7C
    else{
        if( jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
            func_802E4078(MAP_95_CS_END_ALL_100, 0, 1);
        }
        func_8029CBC4();
    }

}

void func_8029CCC4(void){
    if(func_802933D0(7)) return;
    if( func_802933C0(0xF)
        && func_802933D0(6)
        && func_802933D0(20)
    ){
        func_802933FC(0xF);
    }
    func_802933FC(7);
    func_802B0CD8();
    item_inc(ITEM_E_JIGGY);
    if(jiggyscore_total() == 100 && func_8031FF1C(BKPROG_FC_DEFEAT_GRUNTY)){
        func_8028F918(2);
    }
    func_8024BD08(0);
    func_8025A55C(0, 4000, 0xC);
    func_8025A6EC(COMUSIC_D_JINGLE_JIGGY_COLLECTED, -1);
    timedFunc_set_0(4.0f, func_8029CBF4);
}

void func_8029CDA0(void){
    item_inc(ITEM_E_JIGGY);
}

void func_8029CDC0(void) {
    f32 sp2C[3];
    f32 sp20[3];

    _player_getPosition(sp20);
    sp20[0] += (randf() * 90.0f) - 45.0f;
    sp20[2] += (randf() * 90.0f) - 45.0f;
    sp2C[0]  = (randf() * 20.0f) - 10.0f;
    sp2C[1]  = (randf() * 50.0f) + 120.0f;
    sp2C[2]  = (randf() * 20.0f) - 10.0f;
    func_80356074(&sp20, &sp2C, 80.0f, 220.0f);
}
