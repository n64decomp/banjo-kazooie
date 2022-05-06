#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80292048(s32, f32, f32, f32);
void func_802875AC(AnimCtrl *, char *, s32);


extern f32 D_80364A60;
extern f32 D_80364A64;

extern char D_803755E0[];
extern char D_803755EC[];
extern f32 D_803755F8;
extern f32 D_803755FC;
extern f32 D_80375600;
extern f64 D_80375608;

extern f32 D_8037D370;
extern u8 D_8037D374;
extern u8 D_8037D375;
extern u8 D_8037D376;
extern u8 D_8037D377;



s32 func_802A6510(void){
    return D_8037D376;
}

void bsbpeck_init(void){
    D_8037D377 = 0;
    switch(bs_getPrevState()){
        case BS_8_BTROT_JUMP://L802A656C
            D_8037D377++;
            break;
        case BS_5_JUMP:
        case BS_2F_FALL:
        case BS_3D_FALL_TUMBLING:
        case BS_57_BOMB_END:
            break;
    }
    if(func_80293234() == 1)
        func_80293240(2);

    func_8028A274(0x1a, 0.2f);
    func_8029C7F4(1,3,1,6);
    func_80299234(1200.0f, 10.0f);
    func_8029E070(1);
    gravity_set(D_80364A60);
    player_setYVelocity(D_80364A64);
    func_80292048(1, -38.0f, 0.0f, 105.0f);
    func_80292048(0, -38.0f, 0.0f, -7.0f);
    func_8028D638(0x23, 0x2A);
    D_8037D375 = 0;
    D_8037D374 = 0;
    D_8037D376 = 1;
}

void func_802A664C(void){
    f32 sp1C = 1.0f;
    switch(D_8037D375){
        case 0:
            sp1C = D_803755F8;
            break;
        case 1:
            sp1C = D_803755FC;
            break;
        case 2:
            sp1C = D_80375600;
            break;
    }
    func_802933E8(5);
    func_8030E58C(SFX_42_KAZOOIE_RAH, sp1C);
    player_setYVelocity(D_80364A64);
    D_8037D375++;
}

void bsbpeck_update(void){
    enum bs_e sp24 = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    func_802B6FA8();
    if(D_8037D377){
        func_80297970(func_80297A64() * D_80375608);
    }

    switch(D_8037D374){
        case 0://L802A6770
            if(animctrl_isAt(aCtrl, 0.9126f)){
                animctrl_setIndex(aCtrl, ANIM_BANJO_BPECK_ENTER);
                func_8028774C(aCtrl, 0.0f);
                animctrl_setDuration(aCtrl, 0.35f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
                func_802875AC(aCtrl, D_803755E0, 0xbd);
                D_8037D370 = 0.5f;
                D_8037D374 = 1;
            }
            break;
        case 1://L802A67E8
            if(animctrl_isAt(aCtrl, 0.1621f))
                func_802A664C();
            
            if(animctrl_isAt(aCtrl, 0.7f))
                func_802A664C();

            D_8037D370 -= time_getDelta();
            if(D_8037D370 < 0.0f){
                animctrl_reset(aCtrl);
                animctrl_setSmoothTransition(aCtrl, 0);
                animctrl_setIndex(aCtrl, ANIM_BANJO_BPECK);
                animctrl_setDirection(aCtrl, 0);
                animctrl_setDuration(aCtrl, 0.2f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
                func_802875AC(aCtrl, D_803755EC, 0xd4);
                D_8037D374 = 2;
            }
            break;
        case 2://L802A68C4
            if(animctrl_isStopped(aCtrl))
                sp24 = BS_2F_FALL;
            break;
    }//L802A68D8

    if(func_8028B2E8()){
        func_8029C5E8();
        sp24 = BS_1_IDLE;
    }

    if(player_inWater())
        sp24 = BS_4C_LANDING_IN_WATER;

    bs_setState(sp24);
}

void bsbpeck_end(void){
    D_8037D376 = 0;
    ability_use(0xa);
    func_80292048(1, 0.0f, 0.0f, 0.0f);
    func_80292048(0, 0.0f, 0.0f, 0.0f);
    func_8028D638(0, 0);
    func_8029E070(0);
    gravity_reset();
}
