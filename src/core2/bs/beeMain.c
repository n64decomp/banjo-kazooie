#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8029B41C(void);
void func_8029E3C0(s32, f32);
void func_80299628(s32);
void func_802991FC(void);
void func_8029797C(f32);
f32 func_80297A64(void);
void func_802979AC(f32, f32);
void func_802BF2C0(f32);

f32 func_80289F70(void);
void func_8028A3B8(f32, f32);
f32 func_8029B2E8(void);
f32 func_8029B33C(void);
f32 func_80257C48(f32, f32, f32);
f32 func_8029B30C();

extern f32 D_803649E0;
extern f32 D_803649E4;
extern f32 D_803649E8;
extern f32 D_803649EC;
extern f32 D_803649F0;
extern f32 D_803649F4;
extern u8  D_803649F8;
extern s16 D_803649FC[];


extern f32 D_8037D2D0;
extern u8 D_8037D2D4;

void func_802A0F90(void){
    FUNC_8030E624(SFX_2F_ORANGE_SPLAT, 0xFA, 0x598);

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
        func_80297970(0.0f);
    }
    else{
        func_80297970(func_80257C48(sp1c, D_803649E0, D_803649E4));
    }
}

void func_802A1080(void){
    func_802A0340();
    func_8028A010(ASSET_1DE_ANIM_BEE_IDLE,3.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    func_802900B4();
}

void func_802A10D4(void){
    s32 s0;

    s0 = 0;
    func_80299628(0);
    if(func_8028B094())
        s0 = 0x88;

    if(func_80294F78())
        s0 = func_802926C0();
    
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
    func_8028A010(ASSET_1DD_ANIM_BEE_WALK, 0.38f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_803649E0, D_803649E4, D_803649E8, D_803649EC);
    func_802900B4();
}

void func_802A1214(void){
    s32 s0;

    s0 = 0;
    func_80299628(0);
    func_802A1020();
    func_8029AD28(0.94f, 4);
    func_8029AD28(0.44f, 3);
    if(func_8029B300() == 0 && func_80297C04(1.0f))
        s0 = BS_BEE_IDLE;
    
    if(func_8028B094())
        s0 = BS_BEE_FALL;

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

    s0 = player_getAnimCtrlPtr();
    func_802A0340();
    animctrl_reset(s0);
    animctrl_setSmoothTransition(s0, 0);
    animctrl_setIndex(s0, ASSET_1E2_ANIM_BEE_JUMP);
    animctrl_setSubRange(s0, 0, 0.34f);
    func_8028774C(s0, 0.1f);
    animctrl_setDuration(s0, 1.2f);
    animctrl_setPlaybackType(s0,  ANIMCTRL_ONCE);
    func_802875AC(s0, "bsbeemain.c", 0x15b);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f){
        yaw_setIdeal(func_8029B33C());
    }
    func_8029797C(yaw_getIdeal());
    func_802A1020();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_803649F0);
    gravity_set(D_803649F4);
    func_802A0FB4();
    D_8037D2D4 = 0;
}

void func_802A1438(void){
    s32 sp2c;
    AnimCtrl * sp28;
    f32 sp1c[3];

    sp2c = 0;
    sp28 = player_getAnimCtrlPtr();
    func_802A1020();
    _get_velocity(&sp1c);
    if(button_released(BUTTON_A) && (0.0f < sp1c[1])){
        gravity_reset();
    }
    switch (D_8037D2D4)
    {
    case 0:
        if(func_8028B254(0x82)){
            func_8028A3B8(0.715f, 0.7f);
            D_8037D2D4 = 2;
        }else{
            if(animctrl_isStopped(sp28)){
                func_8028A3B8(0.51f, 4.0f);
                D_8037D2D4 = 1;
            }
        }
        break;
    case 1:
        if(func_8028B254(0x82)){
            func_8028A3B8(0.715f, 1.2f);
            D_8037D2D4 = 2;
        }
        break;
    case 2:
        func_80299628(0);
        if(func_8028B2E8()){
            func_802A0F90();
            func_8028A3B8(1.0f, 0.7f);
            D_8037D2D4 = 3;
        }
        break;
    case 3:
        func_80299628(0);
        if(animctrl_isStopped(sp28)){
            func_80297970(0.0f);
            sp2c = BS_BEE_IDLE;
        }
        break;
    }
    if(func_8028B2E8()){
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
    gravity_reset();
}

void func_802A1664(void){
    AnimCtrl * s0;

    s0 = player_getAnimCtrlPtr();
    func_802A0340();
    animctrl_reset(s0);
    animctrl_setIndex(s0, ASSET_1E2_ANIM_BEE_JUMP);
    func_8028774C(s0, 0.34f);
    animctrl_setDuration(s0, 8.0f);
    animctrl_setSubRange(s0, 0, 0.51f);
    animctrl_setPlaybackType(s0,  ANIMCTRL_ONCE);
    func_802875AC(s0, "bsbeemain.c", 0x1e2);
    func_8029C7F4(1,1,3,6);
    D_8037D2D4 = 0;
}

void func_802A170C(void){
    s32 sp2c; //next state
    AnimCtrl * sp28;
    f32 sp1c[3];

    sp2c = 0;
    sp28 = player_getAnimCtrlPtr();
    func_80299628(0);
    func_802A1020();
    _get_velocity(&sp1c);
    switch(D_8037D2D4){
        case 0:
            if(func_8028B254(0x82)){
                func_8028A3B8(0.715f, 0.7f);
                D_8037D2D4 = 1;
            }
            break;
        case 1:
            func_80299628(0);
            if(func_8028B2E8()){
                func_802A0F90();
                func_80297970(0.0f);
                func_8028A3B8(1.0f, 0.7f);
                D_8037D2D4 = 2;
            }
            break;
        case 2:
            func_80299628(0);
            if(animctrl_isStopped(sp28)){
                func_80297970(0.0f);
                sp2c = BS_BEE_IDLE;
            }
            break;
    }
    if(func_8028B2E8()){
        if(func_802933C0(0x19)){
            sp2c = func_80292738();
        }else{
            if(func_8029B300() > 0)
                sp2c = BS_BEE_WALK;
            if(button_pressed(BUTTON_A))
                sp2c = BS_BEE_JUMP;
            sp2c = func_8029CA94(sp2c);
        }
    }
    else{
        if(func_802933D0(0xf) && button_pressed(BUTTON_A))
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
    sp3C = player_getAnimCtrlPtr();
    func_802A0340();
    animctrl_reset(sp3C);
    animctrl_setIndex(sp3C, ASSET_1E0_ANIM_BEE_OW);
    animctrl_setDuration(sp3C, 1.0f);
    animctrl_setSubRange(sp3C, 0, 0.7518f);
    animctrl_setPlaybackType(sp3C,  ANIMCTRL_ONCE);
    func_802875AC(sp3C, "bsbeemain.c", 0x269);
    if(arg0 == 1){
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    }else{
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    }
    _player_getPosition(&sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(200.0f);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1, 1, 2, 3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    func_8028D5DC();
    func_80292E48();
    D_8037D2D4 = 0;
}

void func_802A1A50(void){
    s32 sp1C;

    sp1C= 0;
    if(func_80289FE8(0.5f)){
        func_80292EA4();
    }
    switch(D_8037D2D4){
        case 0:
            if(func_8028B254(0x5A)){
                func_8028A37C(1.0f);
                D_8037D2D4 = 1;
            }
            break;
        case 1:
            break;
    }
    if(func_8028B2E8())
        sp1C = BS_BEE_IDLE;
    if(0.65 < func_80289F70() && player_inWater()){
        sp1C = 0x8C;
    }
    bs_setState(sp1C);
}

void func_802A1B28(void){
    func_80297CA8();
    gravity_reset();
    func_8028D5F4();
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
    
    sp3C = player_getAnimCtrlPtr();
    func_8029B930();
    func_802A0340();
    animctrl_reset(sp3C);
    animctrl_setSmoothTransition(sp3C, 0);
    animctrl_setIndex(sp3C, ASSET_1E1_ANIM_BEE_DIE);
    animctrl_setSubRange(sp3C, 0, 0.3966f);
    animctrl_setDuration(sp3C, 1.7f);
    animctrl_setPlaybackType(sp3C,  ANIMCTRL_ONCE);
    func_802875AC(sp3C, "bsbeemain.c", 0x2ef);
    func_8029C7F4(1,1,2,3);
    _player_getPosition(&sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    D_8037D2D0 = 250.f;
    func_80297970(D_8037D2D0);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    player_setYVelocity(420.0f);
    gravity_set(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_8028D5DC();
    func_80292E48();
    func_802914CC(0xd);
    func_802BF2C0(30.0f);
    func_8029C984();
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    func_8029E3C0(0, 2.9f);
    D_8037D2D4 = 0;
}

void func_802A1DD8(void){
    func_80297970(D_8037D2D0);
    func_80299628(0);
    switch(D_8037D2D4){
        case 0:
            if(!func_8028B2E8())
                break;
            func_8028A37C(0.7453f);
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0x232, 0x332);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 0x232, 0x731);
            player_setYVelocity(400.0f);
            D_8037D2D4 = 1;
            break;
        case 1:
            if(!func_8028B2E8())
                break;
            func_8028A37C(1.0f);
            FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0x232, 0x332);
            FUNC_8030E624(SFX_39_BANJO_AYE_2, 0x232, 0x731);
            D_8037D2D4 = 2;
            break;
        case 2:
            D_8037D2D4 = 3;
            break;
        case 3:
            if(0.0f < D_8037D2D0){
                D_8037D2D0 = max_f(0.0f, D_8037D2D0 - 10.0f);
            }
            break;
    }//L802A1EFC
    if(func_8029E1A8(0))
        func_8029B890();

    bs_setState(0);

}

void func_802A1F2C(void){
    func_8024BD08(0);
    gravity_reset();
    func_80291548();
    func_80292EA4();
    func_802A02C0();
}

void func_802A1F6C(void){
    func_802A0340();
    func_8028A010(ASSET_1DE_ANIM_BEE_IDLE, 3.0f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
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
        sp1C = BS_BEE_IDLE;
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
    func_8028D5F4();
    func_8025A2FC(-1, 0xFA0);
    func_8024BD08(1);
    func_80291548();
    func_80298A64();
}

void func_802A2098(void){
    func_802933FC(0x1A);
    func_8028A010(ASSET_1DE_ANIM_BEE_IDLE, 3.0f);
    yaw_setIdeal(func_8029B41C());
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8024BD08(0);
    func_8025A2FC(0, 0xFA0);
    func_8025A6EC(COMUSIC_42_NOTEDOOR_OPENING_FANFARE, -1);
    func_8029151C(0xC);
    func_8028D5DC();
    func_8029E3C0(0, 3.0f);
}

void func_802A2130(void){
    s32 next  = 0;
    if(func_8029E1A8(0)){
        next = BS_BEE_IDLE;
    }
    bs_setState(next);
}
