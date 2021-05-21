#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_8037D570;
extern char D_80375B00[0x10];

void func_802B6130(void){
    AnimCtrl *plyr_mvmt;
    f32 yaw;
    f32 plyr_pos[3];
    f32 target_pos[3];

    plyr_mvmt = player_getAnimCtrlPtr();
    animctrl_reset(plyr_mvmt);
    func_8029C848(plyr_mvmt);
    animctrl_setPlaybackType(plyr_mvmt,  ANIMCTRL_LOOP);
    func_802875AC(plyr_mvmt, D_80375B00, 0x38);
    _player_getPosition(&plyr_pos);
    func_802949F8(target_pos);
    func_80257F18(plyr_pos, target_pos, &yaw);
    yaw_setIdeal(yaw);
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(3);
    func_802978DC(2);
    func_80297970(0.0f);
    D_8037D570 = 1;
}

void func_802B61E0(void){
    s32 tmp = 0;

    if (D_8037D570 == 0)
        tmp = BS_IDLE;
    D_8037D570 = 0;
    bs_setState(tmp);
}

void func_802B6218(void){}

void func_802B6220(void){
    if(bs_getInterruptType() == 8){
        D_8037D570 = 1;
        func_8029A86C(2);
    }
    else{
        func_80296608();
    }
}