#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 D_8037D410;
extern s32 D_8037D414;

int _bsdie_802ADE00(void){
    return func_8028B2E8();
}

void _bsdie_802ADE20(void){
    f32 i;

    for(i = 0.0f; i < 360.0f; i += 45.0f){
        func_80292900(i, 230.0f);
    }
}

void bsdie_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_DIE);
    func_802876CC(aCtrl, 0.0f, 0.3356f);
    animctrl_setDuration(aCtrl, 2.0f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsdie.c", 0x7e);
    func_8029B930();
    func_8030E58C(0x36, 1.0f);
    _player_getPosition(sp2C);
    func_80294980(sp20);
    func_80257F18(sp20, sp2C, &sp38);
    D_8037D410 = 250.0f;
    player_setMovingYaw(mlNormalizeAngle(sp38 + 180.0f));
    func_802991FC();
    func_80297970(D_8037D410);
    func_8029797C(sp38);
    func_802979AC(sp38, func_80297A64());
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(2);
    func_802978DC(3);
    player_setYVelocity(510.0f);
    gravity_set(-1400.0f);
    pitch_setAngVel(1000.0f, 12.0f);
    func_8029E070(1);
    func_8029151C(0xd);
    func_802BF2C0(30.0f);
    func_8029C984();
    func_8029E3C0(0,2.9f);
    D_8037D414 = 0;
    func_8028D5DC();
    func_80292E48();
}

void bsdie_update(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    enum bs_e sp28 = 0;
    func_80297970(D_8037D410);
    func_80299628(0);
    switch(D_8037D414){
        case 0://L802AE0B8
            if(_bsdie_802ADE00()){
                func_802876CC(aCtrl, 0.0f, 1.0f);
                func_80287674(aCtrl, 1);
                player_setYVelocity(400.0f);
                func_80299DB8();
                func_8030E624(0x7ff19039);
                func_80250D94(1.0f, 1.0f, 0.4f);
                _bsdie_802ADE20();
                D_8037D414 = 1;
            }
            break;
        case 1://L802AE134
            if(_bsdie_802ADE00()){
                func_80299E00();
                func_8030E624(0x7ff19038);
                func_80250D94(1.0f, 0.5f, 0.4f);
                D_8037D414 = 2;
            }
            break;
        case 2://L802AE184
            D_8037D410 = max_f(D_8037D410 - 12.0f, 0.0f);
            if(140.0f < D_8037D410)
                func_802929F8();

            if(func_802878E8(aCtrl, 0.6538f))
                animctrl_setDuration(aCtrl, 4.0f);

            if(func_802878C4(aCtrl)){
                D_8037D410 = 0.0f;
                D_8037D414 = 3;
            }
            break;
        case 3:
            break;
    }//L802AE218
    if(func_8029E1A8(0))
        func_8029B890();

    if( func_8029E270(0) != 0.0f 
        && func_80294574() 
        && ( D_8037D414
             || ( func_802878C4(aCtrl) 
                  && ( player_getYPosition() < (func_80294500() - 150.0f)) 
                )
           )
        && player_inWater()
        && 100.0f < (func_80294500() - func_80294438())
    ){
        sp28 = BS_SWIM_DIE;
    }

    bs_setState(sp28);
}

void bsdie_end(void){
    func_8024BD08(0);
    gravity_reset();
    func_8029E070(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80291548();
    func_80292EA4();
}
