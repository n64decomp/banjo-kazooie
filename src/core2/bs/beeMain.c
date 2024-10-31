#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/physics.h"
#include "core2/ba/timer.h"

f32 func_8029B41C(void);
void func_80299628(s32);
void yaw_applyIdeal(void);
void ncDynamicCamD_func_802BF2C0(f32);

f32 baanim_getTimer(void);
void baanim_setEndAndDuration(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
f32 func_8029B30C();

/* .data */
f32 D_803649E0 = 30.0f;
f32 D_803649E4 = 375.0f;
f32 D_803649E8 = 0.6f;
f32 D_803649EC = 0.4f;
f32 D_803649F0 = 693.5f;
f32 D_803649F4 = -1200.0f;
u8  D_803649F8 = 0;
s16 D_803649FC[3] = {SFX_54_BANJO_HOO_1, SFX_55_BANJO_HOO_2, SFX_56_BANJO_HUI};

/* .bss */
f32 D_8037D2D0;
u8 D_8037D2D4;

/* .code */
void func_802A0F90(void){
    FUNC_8030E624(SFX_2F_ORANGE_SPLAT, 1.4f, 8000);

}

void func_802A0FB4(void){
    func_8030EB00(D_803649FC[D_803649F8], 1.35f, 1.45f);
    if(++D_803649F8  > 2){
        D_803649F8 = 0;
    }

}

void func_802A1020(void){
    f32 sp1c;

    sp1c = func_8029B30C();
    if(func_8029B300() == 0){
        baphysics_set_target_horizontal_velocity(0.0f);
    }
    else{
        baphysics_set_target_horizontal_velocity(ml_interpolate_f(sp1c, D_803649E0, D_803649E4));
    }
}

void func_802A1080(void){
    func_802A0340();
    baanim_playForDuration_loopSmooth(ASSET_1DE_ANIM_BEE_IDLE,3.0f);
    func_8029C7F4(1,1,1, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_802900B4();
}

void func_802A10D4(void){
    s32 s0;

    s0 = 0;
    func_80299628(0);
    if(func_8028B094())
        s0 = 0x88;

    if(should_look_first_person_camera())
        s0 = badrone_look();
    
    if(func_8029B300() > 0)
        s0 = BS_BEE_WALK;

    if(button_pressed(BUTTON_A))
        s0 = BS_BEE_JUMP;

    if(player_inWater())
        s0 = BS_BEE_FLY;

    bs_setState(func_8029CA94(s0));
}

void func_802A117C(void){
    func_802900FC();
    func_802A02C0();
}

void func_802A11A4(void){
    func_802A0340();
    baanim_playForDuration_loopSmooth(ASSET_1DD_ANIM_BEE_WALK, 0.38f);
    func_8029C7F4(2,1,1, BA_PHYSICS_NORMAL);
    baanim_setVelocityMapRanges(D_803649E0, D_803649E4, D_803649E8, D_803649EC);
    func_802900B4();
}

void func_802A1214(void){
    s32 s0;

    s0 = 0;
    func_80299628(0);
    func_802A1020();
    func_8029AD28(0.94f, 4);
    func_8029AD28(0.44f, 3);
    if(func_8029B300() == 0 && baphysics_is_slower_than(1.0f))
        s0 = BS_85_BEE_IDLE;
    
    if(func_8028B094())
        s0 = BS_88_BEE_FALL;

    if(button_pressed(BUTTON_A))
        s0 = BS_BEE_JUMP;

    if(player_inWater())
        s0 = BS_BEE_FLY;

    bs_setState(s0);
}

void func_802A12D4(void){
    func_802900FC();
    func_802A02C0();
}

void func_802A12FC(void){
    AnimCtrl * s0;

    s0 = baanim_getAnimCtrlPtr();
    func_802A0340();
    anctrl_reset(s0);
    anctrl_setSmoothTransition(s0, 0);
    anctrl_setIndex(s0, ASSET_1E2_ANIM_BEE_JUMP);
    anctrl_setSubRange(s0, 0, 0.34f);
    anctrl_setStart(s0, 0.1f);
    anctrl_setDuration(s0, 1.2f);
    anctrl_setPlaybackType(s0,  ANIMCTRL_ONCE);
    anctrl_start(s0, "bsbeemain.c", 0x15b);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    if(func_8029B2E8() != 0.0f){
        yaw_setIdeal(func_8029B33C());
    }
    baphysics_set_target_yaw(yaw_getIdeal());
    func_802A1020();
    baphysics_set_horizontal_velocity(yaw_getIdeal(), baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(D_803649F0);
    baphysics_set_gravity(D_803649F4);
    func_802A0FB4();
    D_8037D2D4 = 0;
}

void func_802A1438(void){
    s32 sp2c;
    AnimCtrl * sp28;
    f32 sp1c[3];

    sp2c = 0;
    sp28 = baanim_getAnimCtrlPtr();
    func_802A1020();
    baphysics_get_velocity(sp1c);
    if(button_released(BUTTON_A) && (0.0f < sp1c[1])){
        baphysics_reset_gravity();
    }
    switch (D_8037D2D4)
    {
    case 0:
        if(func_8028B254(130)){
            baanim_setEndAndDuration(0.715f, 0.7f);
            D_8037D2D4 = 2;
        }else{
            if(anctrl_isStopped(sp28)){
                baanim_setEndAndDuration(0.51f, 4.0f);
                D_8037D2D4 = 1;
            }
        }
        break;
    case 1:
        if(func_8028B254(130)){
            baanim_setEndAndDuration(0.715f, 1.2f);
            D_8037D2D4 = 2;
        }
        break;
    case 2:
        func_80299628(0);
        if(player_isStable()){
            func_802A0F90();
            baanim_setEndAndDuration(1.0f, 0.7f);
            D_8037D2D4 = 3;
        }
        break;
    case 3:
        func_80299628(0);
        if(anctrl_isStopped(sp28)){
            baphysics_set_target_horizontal_velocity(0.0f);
            sp2c = BS_85_BEE_IDLE;
        }
        break;
    }
    if(player_isStable()){
        if(func_8029B300() > 0)
            sp2c = BS_BEE_WALK;
        if(button_pressed(BUTTON_A)){
            sp2c = BS_BEE_JUMP;
        }
    }
    else{
        if(button_pressed(BUTTON_A)){
            sp2c = BS_BEE_FLY;
        }
    }
    if(player_inWater())
        sp2c = BS_BEE_FLY;
    bs_setState(sp2c);
}

void func_802A163C(void){
    func_802A02C0();
    baphysics_reset_gravity();
}

void func_802A1664(void){
    AnimCtrl * s0;

    s0 = baanim_getAnimCtrlPtr();
    func_802A0340();
    anctrl_reset(s0);
    anctrl_setIndex(s0, ASSET_1E2_ANIM_BEE_JUMP);
    anctrl_setStart(s0, 0.34f);
    anctrl_setDuration(s0, 8.0f);
    anctrl_setSubRange(s0, 0, 0.51f);
    anctrl_setPlaybackType(s0,  ANIMCTRL_ONCE);
    anctrl_start(s0, "bsbeemain.c", 0x1e2);
    func_8029C7F4(1,1,3, BA_PHYSICS_AIRBORN);
    D_8037D2D4 = 0;
}

void func_802A170C(void){
    s32 sp2c; //next state
    AnimCtrl * sp28;
    f32 sp1c[3];

    sp2c = 0;
    sp28 = baanim_getAnimCtrlPtr();
    func_80299628(0);
    func_802A1020();
    baphysics_get_velocity(sp1c);
    switch(D_8037D2D4){
        case 0:
            if(func_8028B254(0x82)){
                baanim_setEndAndDuration(0.715f, 0.7f);
                D_8037D2D4 = 1;
            }
            break;
        case 1:
            func_80299628(0);
            if(player_isStable()){
                func_802A0F90();
                baphysics_set_target_horizontal_velocity(0.0f);
                baanim_setEndAndDuration(1.0f, 0.7f);
                D_8037D2D4 = 2;
            }
            break;
        case 2:
            func_80299628(0);
            if(anctrl_isStopped(sp28)){
                baphysics_set_target_horizontal_velocity(0.0f);
                sp2c = BS_85_BEE_IDLE;
            }
            break;
    }
    if(player_isStable()){
        if(miscFlag_isTrue(MISC_FLAG_19)){
            sp2c = badrone_transform();
        }else{
            if(func_8029B300() > 0)
                sp2c = BS_BEE_WALK;
            if(button_pressed(BUTTON_A))
                sp2c = BS_BEE_JUMP;
            sp2c = func_8029CA94(sp2c);
        }
    }
    else{
        if(miscFlag_isFalse(MISC_FLAG_F) && button_pressed(BUTTON_A))
            sp2c = BS_BEE_FLY;
    }//L802A189C
    if(player_inWater())
        sp2c = BS_BEE_FLY;
    bs_setState(sp2c);
}

void func_802A18C8(void){
    func_802A02C0();
}

void func_802A18E8(s32 arg0){
    ///s32 sp40;
    AnimCtrl *sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    //sp40 = arg0;
    sp3C = baanim_getAnimCtrlPtr();
    func_802A0340();
    anctrl_reset(sp3C);
    anctrl_setIndex(sp3C, ASSET_1E0_ANIM_BEE_OW);
    anctrl_setDuration(sp3C, 1.0f);
    anctrl_setSubRange(sp3C, 0, 0.7518f);
    anctrl_setPlaybackType(sp3C,  ANIMCTRL_ONCE);
    anctrl_start(sp3C, "bsbeemain.c", 0x269);
    if(arg0 == 1){
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    }else{
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    }
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    baphysics_set_target_horizontal_velocity(200.0f);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    func_8029C7F4(1, 1, 2, BA_PHYSICS_LOCKED_ROTATION);
    baphysics_set_vertical_velocity(510.0f);
    baphysics_set_gravity(-1200.0f);
    baMarker_collisionOff();
    func_80292E48();
    D_8037D2D4 = 0;
}

void func_802A1A50(void){
    s32 sp1C;

    sp1C= 0;
    if(baanim_isAt(0.5f)){
        func_80292EA4();
    }
    switch(D_8037D2D4){
        case 0:
            if(func_8028B254(0x5A)){
                baanim_setEnd(1.0f);
                D_8037D2D4 = 1;
            }
            break;
        case 1:
            break;
    }
    if(player_isStable())
        sp1C = BS_85_BEE_IDLE;
    if(0.65 < baanim_getTimer() && player_inWater()){
        sp1C = 0x8C;
    }
    bs_setState(sp1C);
}

void func_802A1B28(void){
    func_80297CA8();
    baphysics_reset_gravity();
    baMarker_collisionOn();
    func_80292EA4();
    func_802A02C0();
}

void func_802A1B68(void){
    func_802A18E8(1);
}

void func_802A1B88(void){
    func_802A1A50();
}

void func_802A1BA8(void){
    func_802A1B28();
}

void func_802A1BC8(void){
    func_802A18E8(2);
}

void func_802A1BE8(void){
    func_802A1A50();
}

void func_802A1C08(void){
    func_802A1B28();
}

void bsbeemain_die_init(void){
    AnimCtrl* sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];
    
    sp3C = baanim_getAnimCtrlPtr();
    func_8029B930();
    func_802A0340();
    anctrl_reset(sp3C);
    anctrl_setSmoothTransition(sp3C, 0);
    anctrl_setIndex(sp3C, ASSET_1E1_ANIM_BEE_DIE);
    anctrl_setSubRange(sp3C, 0, 0.3966f);
    anctrl_setDuration(sp3C, 1.7f);
    anctrl_setPlaybackType(sp3C,  ANIMCTRL_ONCE);
    anctrl_start(sp3C, "bsbeemain.c", 0x2ef);
    func_8029C7F4(1,1,2, BA_PHYSICS_LOCKED_ROTATION);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    D_8037D2D0 = 250.f;
    baphysics_set_target_horizontal_velocity(D_8037D2D0);
    baphysics_set_target_yaw(sp38);
    baphysics_set_horizontal_velocity(sp38, baphysics_get_target_horizontal_velocity());
    baphysics_set_vertical_velocity(420.0f);
    baphysics_set_gravity(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    baMarker_collisionOff();
    func_80292E48();
    func_802914CC(0xd);
    ncDynamicCamD_func_802BF2C0(30.0f);
    func_8029C984();
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    batimer_set(0, 2.9f);
    D_8037D2D4 = 0;
}

void func_802A1DD8(void){
    baphysics_set_target_horizontal_velocity(D_8037D2D0);
    func_80299628(0);
    switch(D_8037D2D4){
        case 0:
            if(!player_isStable())
                break;
            baanim_setEnd(0.7453f);
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
            baphysics_set_vertical_velocity(400.0f);
            D_8037D2D4 = 1;
            break;
        case 1:
            if(!player_isStable())
                break;
            baanim_setEnd(1.0f);
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
            D_8037D2D4 = 2;
            break;
        case 2:
            D_8037D2D4 = 3;
            break;
        case 3:
            if(0.0f < D_8037D2D0){
                D_8037D2D0 = ml_max_f(0.0f, D_8037D2D0 - 10.0f);
            }
            break;
    }//L802A1EFC
    if(batimer_decrement(0))
        func_8029B890();

    bs_setState(0);

}

void func_802A1F2C(void){
    core1_ce60_incOrDecCounter(FALSE);
    baphysics_reset_gravity();
    func_80291548();
    func_80292EA4();
    func_802A02C0();
}

void func_802A1F6C(void){
    func_802A0340();
    baanim_playForDuration_loopSmooth(ASSET_1DE_ANIM_BEE_IDLE, 3.0f);
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029C674();
    func_802B3A50();
}

void func_802A1FC8(void){
    s32 sp1C;

    sp1C = 0;
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850()){
        sp1C = BS_85_BEE_IDLE;
    }
    bs_setState(sp1C);
}

void func_802A2014(void){
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_8029C748();
    func_802A02C0();
}

void func_802A2054(void){
    baMarker_collisionOn();
    func_8025A2FC(-1, 0xFA0);
    core1_ce60_incOrDecCounter(TRUE);
    func_80291548();
    func_80298A64();
}

void func_802A2098(void){
    miscFlag_clear(MISC_FLAG_1A);
    baanim_playForDuration_loopSmooth(ASSET_1DE_ANIM_BEE_IDLE, 3.0f);
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3, BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    core1_ce60_incOrDecCounter(FALSE);
    func_8025A2FC(0, 0xFA0);
    func_8025A6EC(COMUSIC_42_NOTEDOOR_OPENING_FANFARE, -1);
    func_8029151C(0xC);
    baMarker_collisionOff();
    batimer_set(0, 3.0f);
}

void func_802A2130(void){
    s32 next  = 0;
    if(batimer_decrement(0)){
        next = BS_85_BEE_IDLE;
    }
    bs_setState(next);
}
