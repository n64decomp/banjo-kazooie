#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80354030(f32*, f32);
f32  func_8029B2E8(void);
f32 func_8029B33C(void);
void func_8029797C(f32);
void func_80297970(f32);

void baModel_setYDisplacement(f32);
void func_80297BF8(f32);
void func_802BFE50(f32, f32, f32);
void func_80299234(f32, f32);
f32 func_8029B2D0(void);
f32 func_8029B2DC(void);
f32 func_80297A64(void);
void func_802979AC(f32, f32);
void func_8028FDC8(f32);
void func_80290B40(f32);
void func_80290A6C(void);

/* .data */
f32 D_803649B0[5] = {0.38f, 0.3f, 0.24f, 0.18f, 0.14};
f32 D_803649C4[5] = {0.0f, 0.2f, 0.3f, 0.4f, 0.5f};

/* .bss */
u8 D_8037D2C0;

int bsBeeFly_inSet(s32);

void func_802A04F0(void){
    f32 player_position[3];

    _player_getPosition(player_position);
    player_position[0] += randf2(-30.0f, 30.0f);
    player_position[1] += 30.0f + randf2(0.0f, 30.0f);
    player_position[2] += randf2(-30.0f, 30.0f);
    func_803541C0(3);
    func_803541CC(0x50);
    func_80354030(player_position, 0.5f);

}

void func_802A0590(void){
    func_802A0340();
    func_8028A274(0x1df, 1.5f);
    func_8029C7F4(1,1,3,6);
    if(func_8029B2E8() != 0.0f){
        yaw_setIdeal(func_8029B33C());
    }
    func_8029797C(yaw_getIdeal());
    func_80297970(0.0f);
    gravity_set(-1200.0f);
    D_8037D2C0 = 0;
}

void func_802A0630(void){
    s32 next_state = 0;
    AnimCtrl * mvmnt; //sp1C

    mvmnt = _player_getAnimCtrlPtr();
    switch(D_8037D2C0){
        case 0:
            if(!animctrl_isAt(mvmnt, 0.266f))
                break;
            player_setYVelocity(1600.0f);
            func_8030E58C(SFX_C_TAKING_FLIGHT_LIFTOFF, 0.7f);
            D_8037D2C0 = 1;
            break;
        case 1:
            func_802A04F0();
            if(animctrl_isStopped(mvmnt))
                func_8028A010(ASSET_1DC_ANIM_BEE_FLY, 0.38f);
            if(func_80297AAC() < 0.0f)
                next_state = BS_BEE_FLY;
            break;
    }
    bs_setState(next_state);
}

void func_802A0704(void){
    func_802A02C0();
}

void func_802A0724(void){
    pitch_setAngVel(500.0f, 1.2f);
}

void func_802A0750(void){
    pitch_setAngVel(1000.0f, 2.2f);
}

void _bsbeefly_end(void){
    if(bsBeeFly_inSet(bs_getNextState()))
        return;
    baModel_setYDisplacement(0.0f);
    roll_setIdeal(0.0f);
    pitch_setIdeal(0.0f);
    func_80291548();
    gravity_reset();
    func_80297B94();
    func_8028FFBC(0);
    func_8029099C();
}

void func_802A07F8(void){
    if(bsBeeFly_inSet(bs_getPrevState()))
        return;
    baModel_setYDisplacement(65.0f);
    func_802991A8(3);
    roll_setAngularVelocity(500.0f, 2.0f);
    func_802A0724();
    gravity_set(-300.0f);
    func_80297BF8(-99.9f);
    func_8028FEF0();
    func_8028FFBC(1);
    func_802909C4();
}

void _bsBeeFly_updateYaw(void){
    f32 sp34;
    f32 sp30;
    f32 stickX;
    stickX = func_8029B2D0();
    func_802BFE50(2.0f, 2000.0f, 350.0f);
    if(button_held(BUTTON_R)){
        func_80299234(500.0f, 30.0f);
        sp34 = 6.0f;
        sp30 = 85.0f;
    }
    else{
        func_80299234(500.0f, 2.0f);
        sp34 = 3.0f;
        sp30 = 65.0f;
    }
    roll_setIdeal(ml_map_f(stickX, -1.0f, 1.0f, -sp30, sp30));
    yaw_setIdeal(mlNormalizeAngle(yaw_getIdeal() + ml_map_f(stickX, -1.0f, 1.0f, sp34, -sp34)));
}

void _bsBeeFly_updatePitch(void){
    f32 stickY = func_8029B2DC();
    if(stickY < 0.0f){
        pitch_setIdeal(ml_map_f(stickY, -1.0f, 0.0f, 300.0f, 360.0f));
    } else {
        pitch_setIdeal(ml_map_f(stickY, 0.0f, 1.0f, 0.0f, 80.0f));
    }
    
}

void bsbeefly_enter(void){
    s32 mvmnt;

    mvmnt = bs_getPrevState();
    func_8028A010(ASSET_1DC_ANIM_BEE_FLY, 0.38);
    func_8029C7F4(1, 1, 3, 3);
    if(miscflag_isTrue(9))
        func_80297970(0.0f);
    else
        func_80297970(600.0f);
    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_8029797C(yaw_getIdeal());
    func_802914CC(4);
    func_802A07F8();
    if(mvmnt != 0x8b){
        func_8028FDC8(1.0f);
        D_8037D2C0 = 0;
    }
    else {
        D_8037D2C0 = 1;
    }
}

void bsbeefly_update(void){
    s32 sp4C;
    AnimCtrl* sp48;
    s32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 *sp24;
    f32 sp30;
   

    sp4C = 0;
    sp48 = _player_getAnimCtrlPtr();
    _bsBeeFly_updateYaw();
    _bsBeeFly_updatePitch();
    pitch_get(); //return value never used
    if(button_pressed(BUTTON_A) && (player_getYPosition() < 7500.0)){
        func_8028FDC8(1.0f);
    }
    if(!func_8028FD30() && player_inWater()){
        func_8028FDC8(1.0f);
    }
    sp44 = func_8028FD30();
    animctrl_setDuration(sp48, D_803649B0[sp44]);
    sp24 = &D_803649C4[sp44];
    sp40 = 0.9f;
    sp40 += *sp24;
    sp3C = pitch_get();
    sp30 = 0.0f;
    if(func_80297AAC() < 0.0f){
        if(sp3C < 300.0f){
            sp30 = ml_map_f(sp3C, 0.0f, 80.0f, 0.0f, 0.23f);
        }
        if(80.0f < sp3C){
            sp30 = ml_map_f(sp3C, 300.0f, 360.0f, -0.2f, 0.0f);
        }
    }
    sp40 += sp30;
    if(!sp44 && button_held(BUTTON_B)){
        sp40 += 0.12;
    }
    func_80290B40(sp40);
    func_80290A6C();
    switch(D_8037D2C0){
        default:
            break;
        case 0:
            if((s32)sp24 != (s32)&D_803649C4)
                D_8037D2C0 = 1;
            break;
        case 1:
            sp40 = mlNormalizeAngle(pitch_getIdeal() - 30.0f);
            if(80.0f < sp40 && sp40 <300.0f)
                sp40 = 300.0f;
            pitch_setIdeal(sp40);
            func_802A0750();
            if(sp44 != 0){
                player_setYVelocity(sp44*400.0);
                func_802A04F0();
            }
            if((s32)sp24 == (s32)&D_803649C4){
                func_802A0724();
                D_8037D2C0 = 0;
            }
            break;
    }//L802A0DF0
    if(miscflag_isTrue(9)){
        func_80297BF8(0.0f);
        func_80297A0C(0);
        sp38 = 0.0f;
    }else{
        if(sp3C <= 80.0f){
            func_80297BF8(ml_map_f(sp3C, 60.0f, 80.0f, -99.9, -1266.66));
            sp38 = ml_map_f(sp3C, 60.0f, 80.0f, 600.0f, 60.0f);
        }else{
            func_80297BF8(ml_map_f(sp3C, 300.0f, 310.0f, -399.99, -99.9));
            sp38 = ml_map_f(sp3C, 300.0f, 340.0f, 0.0f, 600.0f);
        }
    }
    func_8029797C(yaw_get());
    if(button_held(9)){
        sp38 += (f64)sp38;
    }
    func_80297970(sp38);
    if(func_8028B2E8() && !player_inWater())
        sp4C = BS_85_BEE_IDLE;
    func_8028FFF0();
    bs_setState(sp4C);
}

void bsbeefly_end(void){
    _bsbeefly_end();
}

int bsBeeFly_inSet(s32 move){
    return move == 0x8C;
}
