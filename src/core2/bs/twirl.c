#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
f32 D_8037D5A0;
u8 D_8037D5A4;
u8 _bstwirlHitboxActive;

/* .code */
int bstwirl_hitboxActive(void){
    return _bstwirlHitboxActive;
}

void bstwirl_init(void){
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();
    animctrl_reset(aCtrl);
    animctrl_setSmoothTransition(aCtrl, 0);
    animctrl_setIndex(aCtrl, ANIM_BANJO_ROLL);
    animctrl_setDuration(aCtrl, 0.9f);
    animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_802875AC(aCtrl, "bstwirl.c", 0x46);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(3);
    func_8029797C(yaw_getIdeal());
    func_802979AC(yaw_getIdeal(), func_80297A64());
    func_802978DC(3);
    D_8037D5A0 = func_80297A64();
    func_80297970(600.0f);
    func_80299CF4(SFX_32_BANJO_EGHEE, 1.0f, 0x6590);
    _bstwirlHitboxActive = TRUE;
    func_8029E3C0(0, 0.01f);
    D_8037D5A4 = 0;
}

void bstwirl_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl = _player_getAnimCtrlPtr();

    switch(D_8037D5A4){
        case 0:
            D_8037D5A4 = 1;
            break;
        case 1:
            D_8037D5A4 = 2;
            break;
        case 2:
            if(func_8029E1A8(0)){
                func_8029AE74(0);
                func_8029E3C0(0, 0.12f);
            }
            if(animctrl_isAt(aCtrl, 0.8011f)){
                animctrl_setDuration(aCtrl, 2.5f);
                func_80297970(0.0f);
                _bstwirlHitboxActive = 0;
                D_8037D5A4 = 3;
            }
            //??? missing break
        case 3://L802B6C38
            if(animctrl_isStopped(aCtrl))
                sp1C = BS_1_IDLE;
            break;
    }//L802B6C4C

    if(button_pressed(BUTTON_A))
        sp1C = func_8029C780();

    if(0.6 < func_802877D8(aCtrl) && !func_8028B2E8())
        sp1C = BS_2F_FALL;

    if(player_inWater())
        sp1C = BS_4C_LANDING_IN_WATER;

    sp1C = func_8029CA94(sp1C);

    bs_setState(sp1C);
}

void bstwirl_end(void){
    ability_use(0xC);
    _bstwirlHitboxActive = FALSE;
}
