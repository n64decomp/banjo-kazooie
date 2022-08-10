#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8029AD68(f32, s32);
extern f32  ml_vec3f_dot_product(f32[3], f32[3]);

int func_802B81F0(enum bs_e state);

/* .data */
f32 D_80364DC0 = 30.0f;
f32 D_80364DC4 = 400.0f;
f32 D_80364DC8 = 0.6f;
f32 D_80364DCC = 0.4f;
f32 D_80364DD0 = 693.5f;
f32 D_80364DD4 = -1200.0f;
f32 D_80364DD8 = 30.0f;
f32 D_80364DDC = 700.0f;
f32 D_80364DE0 = 0.6f;
f32 D_80364DE4 = 0.44f;
f32 D_80364DE8 = 700.0f;
f32 D_80364DEC = -1200.0f;
u8 D_80364DF0 = 0;
s16 D_80364DF4[] = {SFX_54_BANJO_HOO_1, SFX_55_BANJO_HOO_2, SFX_56_BANJO_HUI}; //sfx_e

/* .bss */
f32  D_8037D5C0;
f32  D_8037D5C4;
u8   D_8037D5C8;

/* .code */
void func_802B7E00(void) {
    u8 temp_t9;

    func_8030EB00(D_80364DF4[D_80364DF0], 1.35f, 1.45f);
    D_80364DF0++;
    if (D_80364DF0 >= 3) {
        D_80364DF0 = 0;
    }
}

void func_802B7E6C(void) {
    f32 sp1C;

    sp1C = func_8029B30C();
    if (func_8029B300() == 0) {
        func_80297970(0.0f);
        return;
    }
    func_80297970(func_80257C48(sp1C, D_80364DC0, D_80364DC4));
}

void func_802B7ECC(void) {
    D_8037D5C0 = 0.0f;
    if (func_80295530(8) < 3) {
        D_8037D5C0 = 1.0f;
    }
    D_8037D5C0 = mlClamp_f(D_8037D5C0, 0.0f, 1.0f);
}

void func_802B7F28(void) {
    f32 pad44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    sp38 = D_80364DD8;
    sp3C = D_80364DDC;
    sp40 = func_8029B30C();
    func_802B7ECC();
    _get_velocity(sp20);
    sp20[1] = 0.0f;
    if (900.0 < sp20[0] * sp20[0] + sp20[1] * sp20[1] + sp20[2] * sp20[2]) {
        ml_vec3f_normalize(sp20);
        func_80294480(sp2C);
        if ( ml_vec3f_dot_product(sp20, sp2C) < -0.2) {
            sp3C += D_8037D5C0 * 350.0;
        }
    }
    if (func_8029B300() == 0) {
        func_80297970(0.0f);
        return;
    }
    func_80297970(func_80257C48(sp40, sp38, sp3C));
}

void func_802B8048(void){
    if(!func_802B81F0(bs_getNextState())){
        pitch_setIdeal(0.0f);
        roll_setIdeal(0.0f);
        func_8029B0C0();
        func_8029E070(0);
        func_8029E064(0);
        miscflag_clear(3);
        miscflag_clear(4);
        func_80293D74();
        func_8029CF48(4, 0, 0.0f);
    }
}

void func_802B80D0(void) {
    if (func_802B8190(bs_getNextState()) == 0) {
        func_802B8048();
        func_8029E0E8(0);
    }
}

void func_802B8110(void){
    func_8029CF48(4, 1, 0.15f);
}

void func_802B813C(void) {
    if (func_802B8190(bs_getPrevState()) == 0) {
        D_8037D5C0 = 0.0f;
        func_8029E0E8(1);
        func_8029CF48(4, 1, 0.15f);
    }
}

int func_802B8190(enum bs_e state){
    return state == 0x81
        || state == BS_7D_WALRUS_SLED
        || state == BS_7E_WALRUS_SLED
        || state == 0x82
        || state == 0x80
        || state == BS_9C_WALRUS_SLED_DRONE;
}

int func_802B81F0(enum bs_e state){
    return state == BS_67_WALRUS_IDLE
        || state == BS_WALRUS_WALK
        || state == BS_WALRUS_JUMP
        || state == BS_6A_WALRUS_FALL
        || state == BS_WALRUS_OW
        || state == BS_WALRUS_DIE
        || state == BS_95_WALRUS_DRONE
        || func_802B8190(state);
}

void bswalrus_idle_init(void){
    func_8028A010(0x11f, 4.0f);
    func_8029C7F4(1,1,1,2);
    func_80297970(0.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    roll_setAngularVelocity(1000.0f, 12.0f);
    func_80293D48(50.0f, 25.0f);
    miscflag_set(3);
    miscflag_set(4);
    func_802900B4();
    func_802B8110();
}

void bswalrus_idle_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);

    if(func_8028B094())
        next_state = BS_6A_WALRUS_FALL;

    if(func_80294F78())
        next_state = func_802926C0();

    if(func_8029B300() > 0)
        next_state = BS_WALRUS_WALK;

    if(button_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_idle_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_walk_init(void){
    func_8028A010(0x120, 0.8f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364DC0, D_80364DC4, D_80364DC8, D_80364DCC);
    func_802900B4();
    func_802B8110();
}

void bswalrus_walk_update(void){
    enum bs_e next_state = 0;

    func_80299628(0);
    func_802B7E6C();
    func_8029AD68(0.3f, 4);

    if(func_8029B300() == 0 && func_80297C04(1.0f))
        next_state = BS_67_WALRUS_IDLE;

    if(func_8028B094())
        next_state = BS_6A_WALRUS_FALL;

    if(button_pressed(BUTTON_A))
        next_state = BS_WALRUS_JUMP;

    bs_setState(next_state);
}

void bswalrus_walk_end(void){
    func_802B8048();
    func_802900FC();
}

void bswalrus_jump_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x121);
    animctrl_setSubRange(aCtrl, 0.0f, 0.514f);
    animctrl_setDuration(aCtrl, 1.0f);
    func_8028774C(aCtrl, 0.1);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bswalrus.c", 0x1f8);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    func_8029797C(yaw_getIdeal());
    func_802B7E6C();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364DD0);
    gravity_set(D_80364DD4);
    func_802B7E00();
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_jump_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802B7E6C();
    _get_velocity(sp1C);
    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();

    switch(D_8037D5C8){
        case 0://L802B86D8
            if(func_8028B254(0x82)){
                animctrl_setDuration(aCtrl, 0.7f);
                animctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 2;
            }
            else if(animctrl_isStopped(aCtrl)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.6734f);
                animctrl_setDuration(aCtrl, 3.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 1;
            }
            break;
        case 1://L802B876C
            if(func_8028B254(0x82)){
                animctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
                animctrl_setDuration(aCtrl, 1.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 2;
            }
            break;
        case 2://L802B87B4
            func_80299628(0);
            if(func_8028B2E8()){
                func_8029AE48();
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.0f);
                animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
                D_8037D5C8 = 3;
            }
            break;
        case 3://L802B880C
            func_80299628(0);
            if(animctrl_isStopped(aCtrl)){
                func_80297970(0.0f);
                next_state = BS_67_WALRUS_IDLE;
            }
            break;
    }//L802B8838

    if(func_8028B2E8()){
        if(func_8029B300() > 0)
            next_state = BS_WALRUS_WALK;

        if(button_pressed(BUTTON_A))
            next_state = BS_WALRUS_JUMP;
    }

    bs_setState(next_state);
}

void bswalrus_jump_end(void){
    gravity_reset();
    func_802B8048();
}

void bswalrus_fall_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x121);
    func_8028774C(aCtrl, 0.662f);
    animctrl_setDuration(aCtrl, 0.7f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bswalrus.c", 0x284);
    func_8029C7F4(1,1,3,6);
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_fall_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_80299628(0);
    func_802B7E6C();
    _get_velocity(sp1C);

    switch (D_8037D5C8)
    {
    case 0://L802B89A4
        if(func_8028B254(0x82)){
            animctrl_setSubRange(aCtrl, 0.0f, 0.8501f);
            animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
            D_8037D5C8 = 1;
        }
        break;
    case 1://L802B89E0
        if(func_8028B2E8()){
            func_8029AE48();
            func_80297970(0.0f);
            animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
            animctrl_setDuration(aCtrl, 1.0f);
            animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
            D_8037D5C8 = 2;
        }
        break;
    case 2://L802B8A38
        break;
    }//L802B8A38

    if(func_8028B2E8()){
        if( func_8029B300() > 0 
            || (D_8037D5C8 == 2 && animctrl_isStopped(aCtrl))
        ){
            if(miscflag_isTrue(0x19))
                next_state = func_80292738();
            else
                next_state = BS_67_WALRUS_IDLE;
        }
    }

    bs_setState(next_state);
}

void bswalrus_fall_end(void){
    func_802B8048();
}

static void __bswalrus_recoil_init(s32 damage){
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_80298760(func_80296560());
    func_8028A274(0x19c, 1.0f);
    if(damage == 1)
        func_8030E58C(SFX_38_BANJO_AYE_1, 1.8f);
    else
        func_8030E58C(SFX_56_BANJO_HUI, 1.8f);
    
    _player_getPosition(sp30);
    func_80294980(sp24);
    func_80257F18(sp24, sp30, &sp3C);
    yaw_setIdeal(mlNormalizeAngle(sp3C + 180.0f));
    yaw_applyIdeal();
    func_80297970(func_802987D4());
    func_8029797C(sp3C);
    func_802979AC(sp3C, func_80297A64());
    func_8029C7F4(1,1,2,3);
    player_setYVelocity(func_802987C4());
    gravity_set(func_802987E4());
    func_8028D5DC();
    func_80292E48();
    func_802B8110();
}

static void __bswalrus_recoil_update(void){
    enum bs_e next_state = 0;
    if(baanim_isAt(0.5f))
        func_80292EA4();
    
    if(func_8028B2E8())
        next_state = BS_67_WALRUS_IDLE;

    bs_setState(next_state);
}

static void __bswalrus_recoil_end(void){
    gravity_reset();
    func_8028D5F4();
    func_80292EA4();
    func_802B8048();
}

void bswalrus_ow_init(void){
    __bswalrus_recoil_init(1);
}

void bswalrus_ow_update(void){
    __bswalrus_recoil_update();
}

void bswalrus_ow_end(void){
    __bswalrus_recoil_end();
}

void bswalrus_bounce_init(void){
    __bswalrus_recoil_init(2);
}

void bswalrus_bounce_update(void){
    __bswalrus_recoil_update();
}

void bswalrus_bounce_end(void){
    __bswalrus_recoil_end();
}

void bswalrus_die_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_8029B930();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x19d);
    animctrl_setSubRange(aCtrl, 0.0f, 0.4454f);
    animctrl_setDuration(aCtrl, 2.2f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bswalrus.c", 0x366);
    func_8030E58C(SFX_36_BANJO_DOH, 1.8f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D5C4 = 250.0f;
    yaw_setIdeal(mlNormalizeAngle(sp38 + 180.0f));
    yaw_applyIdeal();
    func_80297970(D_8037D5C4);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_8029C7F4(1,1,2,3);
    player_setYVelocity(420.0f); //B)
    gravity_set(-1200.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_802914CC(0xd);
    func_802BF2C0(30.0f);
    func_8025AB00();
    func_8025A2FC(0, 0xfa0);
    func_8025A70C(0x1A);
    func_8028D5DC();
    func_80292E48();
    func_8029E3C0(0, 1.5f);
    func_802B8110();
    D_8037D5C8 = 0;
}

void bswalrus_die_update(void){
    enum bs_e next_state = 0;

    func_80297970(D_8037D5C4);
    func_80299628(0);
    switch(D_8037D5C8){
        case 0://L802B8F54
            if(func_8028B2E8()){
                func_8028A37C(1.0f);
                FUNC_8030E624(SFX_1F_HITTING_AN_ENEMY_3, 0.8f, 18000);
                FUNC_8030E624(SFX_39_BANJO_AYE_2, 1.8f, 18000);
                player_setYVelocity(400.0f);
                D_8037D5C8 = 2;
            }
            break;
        case 2://L802B8FA8
            D_8037D5C8 = 3;
            break;
        case 3://L802B8FB0
            if(0.0f < D_8037D5C4){
                D_8037D5C4 = max_f(0.0f, D_8037D5C4 - 10.0f);
            }
            break;
    }//L802B8FE0

    if(func_8029E1A8(0))
        func_8029B890();

    bs_setState(next_state);
}

void bswalrus_die_end(void){
    func_8024BD08(0);
    gravity_reset();
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    func_80292EA4();
}

void bswalrus_drone_init(void){
    func_802B8110();
    bsdrone_init();
}

void bswalrus_drone_update(void){
    bsdrone_update();
}

void bswalrus_drone_end(void){
    bsdrone_end();
    func_802B8048();
}

void func_802B90D0(void){
    func_8028A010(0x19e, 0.8f);
    func_8029C7F4(1,1,3,2);
    func_80297970(0.0f);
    func_8029C674();
    func_802B813C();
    func_802B3A50();
}

void func_802B9130(void){
    enum bs_e next_state = 0;
    func_802B3A50();
    func_80299628(0);
    func_8029C6D0();
    if(!func_80298850())
        next_state = BS_7D_WALRUS_SLED;

    bs_setState(next_state);
}

void func_802B917C(void){
    func_8029C748();
    func_802B80D0();
}

void bswalrus_sled_init(void){
    func_8028A010(0x19e, 0.8f);
    func_8029C7F4(2,1,1,2);
    func_80289EC8(D_80364DC0, D_80364DC4, D_80364DE0, D_80364DE4);
    func_802900B4();
    func_802B813C();
}

void bswalrus_sled_update(void){
    enum bs_e next_state = 0;
    f32 sp20[3];

    if(50.0f < func_80297AB8()){
        if(func_8023DB4C(1)){
            func_80292554(&sp20);
        }else{
            func_80292578(&sp20);
        }
        particleEmitter_emitN(func_802F1EC8(sp20), 1);
    }//L802B927C

    func_80299628(0);
    func_802B7F28();
    if(func_80294F78())
        next_state = func_802926C0();

    if(button_pressed(BUTTON_A))
        next_state = BS_7E_WALRUS_SLED;

    next_state = func_8029CA94(next_state);
    bs_setState(next_state);
}

void bswalrus_sled_end(void){
    func_802B80D0();
    func_802900FC();
}
 
void bswalrus_sled_jump_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, FALSE);
    animctrl_setIndex(aCtrl, 0x19f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.4285f);
    animctrl_setDuration(aCtrl, 1.0f);
    func_8028774C(aCtrl, 0.14f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bswalrus.c", 0x477);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f)
        yaw_setIdeal(func_8029B33C());
    func_8029797C(yaw_getIdeal());
    func_802B7F28();
    func_802979AC(yaw_getIdeal(), func_80297A64());
    player_setYVelocity(D_80364DD0);
    gravity_set(D_80364DD4);
    func_802B7E00();
    func_802B813C();
    D_8037D5C8 = 0;
}

void bswalrus_sled_jump_update(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_802B7F28();
    _get_velocity(sp1C);

    if(button_released(BUTTON_A) && 0.0f < sp1C[1])
        gravity_reset();

    switch (D_8037D5C8)
    {
    case 0:
        if(animctrl_isStopped(aCtrl)){
            func_8028A3B8(0.5058f, 7.0f);
            D_8037D5C8 = 1;
        }
        break;
    case 1://L802B94F0
        if(func_8028B254(0x82)){
            func_8028A3B8(1.0f, 1.0f);
            D_8037D5C8 = 2;
        }
        break;
    case 2://L802B951C
        if(animctrl_isStopped(aCtrl)){
            next_state = BS_7D_WALRUS_SLED;
        }
        break;
    }//L802B9530

    if(func_8028B2E8()){
        if(button_pressed(BUTTON_A))
            next_state = BS_7E_WALRUS_SLED;
        
        next_state = func_8029CA94(next_state);
    }

    bs_setState(next_state);
}

void bswalrus_sled_jump_end(void){
    gravity_reset();
    func_802B80D0();
}

void func_802B95A0(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, 0x19f);
    animctrl_setSubRange(aCtrl, 0.0f, 0.5058f);
    animctrl_setDuration(aCtrl, 1.0f);
    animctrl_setPlaybackType(aCtrl, ANIMCTRL_STOPPED);
    func_802875AC(aCtrl, "bswalrus.c", 0x4e2);
    func_8029C7F4(1,1,3,6);
    func_802B813C();
    D_8037D5C8 = 0;
}

void func_802B963C(void){
    enum bs_e next_state = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    f32 sp1C[3];

    func_80299628(0);
    func_802B7E6C();
    _get_velocity(sp1C);
    switch (D_8037D5C8)
    {
        case 0://L802B9694
            if(func_8028B254(0x82)){
                func_8028A3B8(1.0f, 1.0f);
                D_8037D5C8 = 1;
            }
            break;
        case 1://L802B96C0
            if(func_8028B2E8()){
                func_8029AE48();
                func_80297970(0.0f);
                D_8037D5C8 = 2;
            }
            break;
        case 2:
            break;
    }//L802B96F0

    if(func_8028B2E8()){
        if( func_8029B300() > 0 
            || (D_8037D5C8 == 2 && animctrl_isStopped(aCtrl))
        ){
            next_state = BS_7D_WALRUS_SLED;
        }

        if(button_pressed(BUTTON_A))
            next_state = BS_7E_WALRUS_SLED;

        next_state = func_8029CA94(next_state);
    }//L802B9754


    bs_setState(next_state);
}

void func_802B976C(void){
    func_802B8048();
}

void func_802B978C(void) {
    func_8028A180(0x1A9, 3.2f);
    func_8029C7F4(1, 1, 3, 7);
    func_80297970(0.0f);
    func_802914CC(0xD);
    func_802BF2C0(60.0f);
    func_8025A58C(0, 0xFA0);
    func_8025A70C(COMUSIC_3C_MINIGAME_LOSS);
    func_8024BD08(0);
    func_8028D5DC();
    func_8029E3C0(0, 2.9f);
    func_802B813C();
    func_80292E48();
}

void func_802B9830(void) {
    yaw_setIdeal(func_8029B41C() + 35.0f);
    func_80299628(0);
    if (func_8029E1A8(0) != 0) {
        func_8029B6F0();
    }
}

void func_802B9880(void) {
    func_80291548();
    func_8024BD08(1);
    func_8025A904();
    func_80292EA4();
    func_802B80D0();
}

void func_802B98C0(void) {
    if (bs_getInterruptType() == 0x2B) {
        func_8029A86C(2);
        bs_setState(BS_67_WALRUS_IDLE);
        return;
    }
    func_80296608();
}

void bswalrus_sled_drone_init(void){
    func_802B813C();
    bsdrone_init();
}

void bswalrus_sled_drone_update(void){
    bsdrone_update();
}

void bswalrus_sled_drone_end(void){
    bsdrone_end();
    func_802B80D0();
}