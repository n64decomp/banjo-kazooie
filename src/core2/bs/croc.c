#include <ultra64.h>
#include "functions.h"
#include "variables.h"


int bscroc_inSet(enum bs_e state);

/* .data */
const f32 D_80364B00 = 30.0f;
const f32 D_80364B04 = 375.0f;
const f32 D_80364B08 = 500.0f;
const f32 D_80364B0C = 0.5f;
const f32 D_80364B10 = 0.3f;
const f32 D_80364B14 = 0.2f;
const f32 D_80364B18 = 693.5f; //jump initial velocity
const f32 D_80364B1C = -1200.0f; //jump gravity
u8  D_80364B20 = 0;
s16 D_80364B24[] = {
    SFX_54_BANJO_HOO_1, 
    SFX_55_BANJO_HOO_2, 
    SFX_56_BANJO_HUI
};

/* .bss */
extern f32 D_8037D3E0;
extern u8 _bscrocHitboxActive; //8037D3e4
extern void *D_8037D3E8;
extern u8 D_8037D3EC;
extern f32 D_8037D3F0;
extern u8 D_8037D3F4;
extern u8 D_8037D3F5;

/* .code */
f32 func_802ABDC0(void){
    if(func_80291670(3) != 0.0f)
        return D_80364B08;
    else
        return D_80364B04;
}

void func_802ABE04(void){
    func_8030EB00(D_80364B24[D_80364B20], 1.35f, 1.45f);
    if(!(++D_80364B20 < 3))
        D_80364B20 = 0;
}

void func_802ABE70(void){
    f32 sp1C = func_80291670(3);
    func_80299650(func_80291684(3), sp1C);
    if(func_802933C0(0x10) && bs_getState() != BS_BTROT_EXIT){
        func_802933FC(0x10);
        func_802917E4(3, func_80294A40());
        func_8025A6EC(COMUSIC_8A_GETTING_TURBO_TRAINERS, -1);
        func_8029E0DC(1);
    }

    if(sp1C != 0.0f ){
        func_8029C3E8(0.0f, 30.0f);
    }

    if(func_80291700(3, 0.01f)){
        func_8029E0DC(0);
        func_8030E58C(0x3eb, 1.35f);
    }
}

void func_802ABF54(void){
    f32 sp1C = func_8029B30C();
    if(func_8029B300() == 0){
        func_80297970(0.0f);
    }
    else{
        func_80297970(func_80257C48(sp1C, D_80364B00, func_802ABDC0()));
    }
}

void func_802ABFBC(void){
    if(!bscroc_inSet(bs_getNextState())){
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        func_802933FC(3);
        func_802933FC(4);
        func_80293D74();
    }
    func_80289F10(1);
}

int bscroc_inSet(enum bs_e state){
    return state == BS_5E_CROC_IDLE
        || state == BS_CROC_WALK
        || state == BS_CROC_JUMP
        || state == BS_61_CROC_FALL
        || state == BS_CROC_OW
        || state == BS_CROC_DIE
        || state == BS_6E_CROC_BITE
        || state == BS_CROC_EAT_BAD
        || state == BS_70_CROC_EAT_GOOD
        || state == BS_CROC_LOCKED
        || state == BS_CROC_DRONE;
}

void bscroc_idle_init(void){
    func_8028A010(0xe1, 1.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    func_802933E8(3);
    func_802933E8(4);
    func_802900B4();
}

void bscroc_idle_update(void){
    enum bs_e next_state = 0;
    func_802ABE70();
    func_80299628(0);
    if(func_8028B094())
        next_state = BS_61_CROC_FALL;

    if(func_80294F78())
        next_state = func_802926C0();

    if(func_8029B300() > 0)
        next_state = BS_CROC_WALK;

    if(button_pressed(BUTTON_B))
        next_state = BS_6E_CROC_BITE;

    if(button_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    next_state = func_8029CA94(next_state);
    bs_setState(next_state);
    
}

void bscroc_idle_end(void){
    func_802ABFBC();
    func_802900FC();
}

void bscroc_walk_init(void){
    func_8028A100(0xe0, 0.8f, 0.4f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364B00, D_80364B04, D_80364B0C, D_80364B10);
    func_802900B4();
}

void bscroc_walk_update(void){
    enum bs_e next_state = 0;

    func_802ABE70();
    func_80299628(0);
    func_802ABF54();

    func_8029AD28(0.1f, 4);
    func_8029AD28(0.6f, 3);
    if(func_8029B300() == 0 && func_80297C04(1.0f))
        next_state = BS_5E_CROC_IDLE;

    if(func_8028B094())
        next_state = BS_61_CROC_FALL;

    if(button_pressed(BUTTON_B))
        next_state = BS_6E_CROC_BITE;

    if(button_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    bs_setState(next_state);
}

void bscroc_walk_end(void){
    func_802ABFBC();
    func_802900FC();
}

void bscroc_jump_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x11C);
    animctrl_setSubRange(aCtrl, 0.0f, 0.35f);
    animctrl_setDuration(aCtrl, 1.0f);
    func_8028774C(aCtrl, 0.1f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bscroc.c", 0x1ac);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f){
        yaw_setIdeal(func_8029B33C());
    }
    func_8029797C(yaw_getIdeal());
    func_802ABF54();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364B18);
    gravity_set(D_80364B1C);
    func_802ABE04();
    D_8037D3EC = 0;
}

void bscroc_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802ABE70();
    func_802ABF54();
    _get_velocity(&sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();

    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x82))
            {
                func_8028A3B8(0.6538f, 0.7f);
                D_8037D3EC = 2;
            }
            else if(animctrl_isStopped(aCtrl))
            {
                func_8028A3B8(0.5036f, 3.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(func_8028B254(0x82)){
                func_8028A3B8(0.6538f, 1.0f);
                D_8037D3EC = 2;
            }
            break;
        case 2:
            func_80299628(0);
            if(func_8028B2E8()){
                func_8029AE48();
                func_8028A3B8(1.0f, 1.0f);
                D_8037D3EC = 3;
            }
            break;
        case 3:
            func_80299628(0);
            if(animctrl_isStopped(aCtrl)){
                func_80297970(0.0f);
                sp2C = BS_5E_CROC_IDLE;
            }
            break;
    }//L802AC66C

    if(func_8028B2E8()){
        if(func_8029B300() > 0)
            sp2C = BS_CROC_WALK;
        
        if(button_pressed(BUTTON_A))
            sp2C = BS_CROC_JUMP;
    }

    if(button_pressed(BUTTON_B))
            sp2C = BS_6E_CROC_BITE;

    bs_setState(sp2C);
}

void bscroc_jump_end(void){
    gravity_reset();
    func_802ABFBC();
}

void bscroc_fall_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x11C);
    func_8028774C(aCtrl, 0.5036f);
    animctrl_setDuration(aCtrl, 0.7f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bscroc.c", 0x235);
    func_8029C7F4(1,1,3,6);
    D_8037D3EC = 0;
}

void bscroc_fall_update(void){
    enum bs_e next_state = 0;
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    f32 velocity[3];

    func_802ABE70();
    func_80299628(0);
    func_802ABF54();
    _get_velocity(&velocity);
    
    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x82)){
                func_8028A37C(0.6538f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(func_8028B2E8()){
                func_8029AE48();
                func_80297970(0.0f);
                func_8028A3B8(1.0f, 1.0f);
                D_8037D3EC = 2;
            }
        case 2:
            break;
    }//L802AC850

    if(func_8028B2E8()){
        if(func_8029B300() > 0 || (D_8037D3EC == 2 && animctrl_isStopped(aCtrl))){
            if(func_802933C0(0x19)){
                next_state = func_80292738();
            }else{
                next_state = BS_5E_CROC_IDLE;
            }
        }
    }//L802AC8B4

    bs_setState(next_state);
}

void bscroc_fall_end(void){
    func_802ABFBC();
}

static void __bscroc_recoil_init(s32 damage){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x11d);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.7518f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bscroc.c", 0x2a5);
    if(damage == 1)
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    else
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    
    _player_getPosition(&sp2C);
    func_80294980(&sp20);
    func_80257F18(&sp20, &sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(200.0f);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1,1,2,3);
    player_setYVelocity(510.0f);
    gravity_set(-1200.0f);
    func_8028D5DC();
    func_80292E48();
    D_8037D3EC = 0;
}

static void __bscroc_recoil_update(void){
    enum bs_e next_state = 0;
    func_802ABE70();
    if(func_80289FE8(0.5f))
        func_80292EA4();
    
    switch(D_8037D3EC){
        case 0:
            if(func_8028B254(0x5A)){
                func_8028A37C(1.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            break;
    }
    if(func_8028B2E8())
        next_state = BS_5E_CROC_IDLE;

    bs_setState(next_state);
}

void __bscroc_recoil_end(void){
    func_80297CA8();
    gravity_reset();
    func_8028D5F4();
    func_80292EA4();
    func_802ABFBC();
}

void bscroc_ow_init(void){
    __bscroc_recoil_init(1);
}

void bscroc_ow_update(void){
    __bscroc_recoil_update();
}

void bscroc_ow_end(void){
    __bscroc_recoil_end();
}

void bscroc_bounce_init(void){
    __bscroc_recoil_init(2);
}

void bscroc_bounce_update(void){
    __bscroc_recoil_update();
}

void bscroc_bounce_end(void){
    __bscroc_recoil_end();
}

void bscroc_die_init(void){
    AnimCtrl * aCtrl = _player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_8029B930();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x11e);
    animctrl_setSubRange(aCtrl, 0.0f, 0.3966f);
    animctrl_setDuration(aCtrl, 1.7f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bscroc.c", 0x32b);
    func_8029C7F4(1,1,2,3);
    _player_getPosition(&sp2C);
    func_80294980(&sp20);
    func_80257F18(&sp20, &sp2C, &sp38);
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    D_8037D3E0 = 250.0f;
    func_80297970(D_8037D3E0);
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
    D_8037D3EC = 0;
}

void bscroc_die_update(void){
    enum bs_e next_state = 0;
    func_802ABE70();
    func_80297970(D_8037D3E0);
    func_80299628(0);
    switch(D_8037D3EC){
        case 0:
            if(func_8028B2E8()){
                func_8028A37C(0.7453f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0x232, 0x332);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 0x232, 0x731);
                player_setYVelocity(400.0f);
                D_8037D3EC = 1;
            }
            break;
        case 1:
            if(func_8028B2E8()){
                func_8028A37C(1.0f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0x232, 0x332);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 0x232, 0x731);
                D_8037D3EC = 2;
            }
            break;
        case 2:
            D_8037D3EC = 3;
            break;
        case 3:
            if(0.0f < D_8037D3E0)
                D_8037D3E0 = max_f(0.0f, D_8037D3E0 - 10.0f);
            break;
    }//L802ACECC

    if(func_8029E1A8(0))
        func_8029B890();

    bs_setState(next_state);
}

void bscroc_die_end(void){
    func_8024BD08(0);
    gravity_reset();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    func_80292EA4();
}

int bscroc_hitboxActive(void){
    return _bscrocHitboxActive;
}

static void func_802ACF58(void){
    f32 sp2C;
    f32 sp20[3];
    sp2C = func_8028B2E8() ? 500.0f : 400.0f;
    func_802589E4(&sp20, yaw_get(), sp2C);
    sp20[1] = 200.0f;
    func_80297A0C(&sp20);
}

void bscroc_bite_init(void){
    func_8028A100(0x122, 0.25f, 0.2f);
    func_8029C7F4(1,1,1,3);
    func_802ACF58();
    D_8037D3F4 = 0;
    _bscrocHitboxActive = TRUE;
}

void bscroc_bite_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    func_802ABE70();
    func_80299628(0);
    if(animctrl_isAt(aCtrl, 0.99f)){
        switch(++D_8037D3F4){
            case 1:
                func_802ACF58();
                animctrl_setDuration(aCtrl, 0.28f);
                break;
            case 2:
                func_802ACF58();
                animctrl_setDuration(aCtrl, 0.32f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                break;
        }
    }
    if(animctrl_isAt(aCtrl, 0.6f)){
        func_8030EB00(SFX_6D_CROC_BITE, 1.0f, 1.1f);
    }

    if(D_8037D3F4 == 3){
        if(func_8028B094())
            next_state =  BS_61_CROC_FALL;
        else
            next_state = BS_CROC_WALK;
    }

    if(func_8028B2E8() && button_pressed(BUTTON_A))
        next_state = BS_CROC_JUMP;

    bs_setState(next_state);
}

void bscroc_bite_end(void){
    _bscrocHitboxActive = FALSE;
    func_802ABFBC();
}

void bscroc_eat_bad_init(void){
    func_8028A180(0x123, 2.41f);
    func_8029C7F4(1,1,2,3);
    func_80297970(0.0f);
}

void bscroc_eat_bad_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    func_802ABE70();
    func_80299628(0);
    if(animctrl_isAt(aCtrl, 0.3518f)){
        func_8030E58C(SFX_A0_COUGHING, 0.9f);
    }

    if(animctrl_isAt(aCtrl, 0.5282f)){
        func_8030E58C(SFX_A0_COUGHING, 0.85f);
    }

    if(animctrl_isAt(aCtrl, 0.6671f)){
        func_8030E484(SFX_C6_SHAKING_MOUTH);
    }

    if(animctrl_isStopped(aCtrl)){
        next_state = BS_5E_CROC_IDLE;
    }

    bs_setState(next_state);
}

void bscroc_eat_bad_end(void){
    func_802ABFBC();
}


void func_802AD2A8(Gfx **gdl, Mtx **mPtr, void *arg2){
    f32 sp34[3];
    f32 sp28[3];

    player_getRotation(&sp34);
    func_8028E9C4(2, &sp28);
    set_model_render_mode(1);
    func_803391A4(gdl, mPtr, &sp28, &sp34, D_8037D3F0, NULL, D_8037D3E8);

}

void func_802AD318(void){
    D_8037D3F5 = 1;
}

void bscroc_eat_good_init(void){
    func_8028A010(0x122, 0.25f);
    func_8029C7F4(1,1,1,2);
    func_80292188(func_802AD2A8);
    D_8037D3E8 = assetcache_get(func_80294974());
    D_8037D3F0 = 1.0f;
    D_8037D3F5 = 0;
    D_8037D3F4 = 0;
}

int func_802AD3A0(void){
    return D_8037D3F5;
}

void bscroc_eat_good_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    func_802ABE70();
    D_8037D3F0 = max_f(0.1f, D_8037D3F0 - 0.05);
    func_80299628(0);
    func_802ABF54();
    if(animctrl_isAt(aCtrl, 0.99f)){
        switch(++D_8037D3F4){
            case 1:
                animctrl_setDuration(aCtrl, 0.28f);
                break;
            case 2:
                animctrl_setDuration(aCtrl, 0.32f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                break;
            case 3:
                if(D_8037D3F5)
                    next_state = BS_CROC_EAT_BAD;
                else
                    next_state = BS_5E_CROC_IDLE;
                break;
        }
    }//L802AD4B0

    if(animctrl_isAt(aCtrl, 0.62f))
        func_8030EB00(SFX_4C_LIP_SMACK, 1.2f, 1.3f);

    if(D_8037D3F4 == 2 && animctrl_isAt(aCtrl, 0.9))
        func_8030EB00(SFX_AE_YUMYUM_TALKING, 1.45f, 1.55f);

    bs_setState(next_state);
}

void bscroc_eat_good_end(void){
    D_8037D3F5 = 0;
    assetcache_release(D_8037D3E8);
    func_80292188(0);
    func_802ABFBC();
}

void func_802AD56C(void){
    func_8028A010(0xe1, 1.0f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8029C674();
    func_802B3A50();
}

void func_802AD5C0(void){
    enum bs_e next_state = 0;
    func_802ABE70();
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850()){
        next_state = BS_5E_CROC_IDLE;
    }
    
    bs_setState(next_state);
}

void func_802AD614(void){
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_8029C748();
    func_802ABFBC();
}

void bscroc_drone_init(void){
    bsdrone_init();
}

void bscroc_drone_update(void){
    func_802ABE70();
    bsdrone_update();
}

void bscroc_drone_end(void){
    bsdrone_end();
    func_802ABFBC();
}