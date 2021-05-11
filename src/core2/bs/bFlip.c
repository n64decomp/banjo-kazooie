#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .data */
const f32 D_80364A20 = 920.0f;
const f32 D_80364A24 = -1200.0f;
const f32 D_80364A28 = -533.3f;
const f32 D_80364A2C = 80.0f;
const f32 D_80364A30 = 200.0f;

/* .bss */
extern u8 D_8037D310;


/* .code */
void _bsbflip_802A2D60(void){
    f32 sp1C;
    sp1C = func_8029B30C();
    if(!func_8029B300())
        func_80297970(0.0f);
    else
        func_80297970(func_80257C48(sp1C, D_80364A2C, D_80364A30));
}

void _bsbflip_802A2DC0(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp20[3];

    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BFLIP);
    animctrl_setDuration(aCtrl, 2.2f);
    func_8028774C(aCtrl, 0.8566f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbflip.c", 0x69); //nice
    func_802978DC(3);
    func_80297970(0.0f);
    clear_vec3f(sp20);
    func_80297A0C(sp20);
    func_8029C5E8();
}

void bsbflip_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_802874AC(aCtrl);
    func_80287684(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BFLIP);
    animctrl_setDuration(aCtrl, 2.3f);
    func_802876CC(aCtrl, 0.0f, 0.7866f);
    func_8028774C(aCtrl, 0.0f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbflip.c", 0x80);
    func_8029C7F4(1,1,2,3);
    func_8029B324(0, 0.03f);
    func_8029B324(1, 1.0f);
    func_8029E070(1);
    func_80299BD4();
    D_8037D310 = 0;
}

void bsbflip_update(void){
    enum bs_e sp24 = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    if( func_802878E8(aCtrl, 0.2394f)
        && func_802877B0(aCtrl) != 2
        && func_80287790(aCtrl) == 0x4B
    ){
        func_8030E760(2, 0.558f, 22000);
    }

    switch(D_8037D310){
    case 0://L802A2FD4
        if(func_802878E8(aCtrl, 0.1837f)){
            if(func_8029B2E8() != 0.0f){
                func_802991A8(2);
                func_8029957C(3);
                if(func_8029B2E8){ //!!! BUG !!!
                    player_setMovingYaw(func_8029B33C());
                }
                func_80299254(1.0f);
                func_802978DC(6);
                func_8029797C(player_getMovingYaw());
                func_80297970(200.0f);
                func_802979AC(player_getMovingYaw(), func_80297A64());
            }else{//L802A3098
                func_802978DC(6);
                func_80297970(0.0f);
            }
            player_setYVelocity(D_80364A20);
            gravity_set(D_80364A24);
            func_80297BF8(D_80364A28);
            animctrl_setDuration(aCtrl, 1.9f);
            func_8030E4E4(0x33);
            D_8037D310 = 1;
        }
        break;
    case 1://L802A30F8
        _bsbflip_802A2D60();
        if(func_802878C4(aCtrl)){
            func_802874AC(aCtrl);
            func_80287684(aCtrl, 0);
            animctrl_setIndex(aCtrl, 0x4C);
            animctrl_setDuration(aCtrl, 0.13f);
            func_80287674(aCtrl, 2);
            func_802875AC(aCtrl, "bsbflip.c", 0xd9);
            D_8037D310 = 2;
        }//L802A316C
        if(func_80294F3C()){
            sp24 =BS_BBUSTER;
        }
        break;
    case 2://L802A3184
        if(func_8028B424())
            sp24 = BS_FALL_TUMBLING;
        if(button_released(BUTTON_A)){
            func_802874AC(aCtrl);
            func_80287684(aCtrl, 0);
            animctrl_setIndex(aCtrl, 0x61);
            animctrl_setDuration(aCtrl, 0.8f);
            func_80287674(aCtrl, 1);
            func_802875AC(aCtrl, "bsbflip.c", 0xee);
            func_80297B94();
            D_8037D310 = 3;
        }//L802A320C
        if(func_8028B2E8()){
            _bsbflip_802A2DC0();
            sp24 = func_8029C9C0(sp24);
            D_8037D310 = 4;
        }
        else if(func_80294F3C()){
            sp24 = BS_BBUSTER;
        }
        break;
    case 3://L802A3258
        if(func_8028B424())
            sp24 = BS_FALL_TUMBLING;
        if(func_8028B2E8()){
            func_8029E070(0);
            _bsbflip_802A2DC0();
            sp24 = func_8029C9C0(sp24);
            D_8037D310 = 4;
        }
        else if(func_80294F3C()){
            sp24 = BS_BBUSTER;
        }
        break;
    case 4://L802A32C0
        if(func_802878C4(aCtrl))
            sp24 = BS_WALK_SLOW;
        sp24 = func_8029C9C0(sp24);
        break;
    }//L802A32E0

    if(player_inWater())
        sp24 = BS_LANDING_IN_WATER;

    bs_setState(sp24);
}

void bsbflip_end(void){
    func_80295610(2);
    gravity_reset();
    func_80297B94();
    func_8029E070(0);
    func_8029B0C0();
}