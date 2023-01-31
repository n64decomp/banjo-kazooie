#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
bool  bsTalkStayInState;

/* .code */
void bstalk_init(void){
    AnimCtrl *player_anim_ctrl;
    f32 yaw;
    f32 plyr_pos[3];
    f32 target_pos[3];

    player_anim_ctrl = _player_getAnimCtrlPtr();
    animctrl_reset(player_anim_ctrl);
    func_8029C848(player_anim_ctrl);
    animctrl_setPlaybackType(player_anim_ctrl,  ANIMCTRL_LOOP);
    func_802875AC(player_anim_ctrl, "bstalk.c", 0x38);
    _player_getPosition(plyr_pos);
    func_802949F8(target_pos);
    func_80257F18(plyr_pos, target_pos, &yaw);
    yaw_setIdeal(yaw);
    func_80289F10(1);
    yaw_setUpdateState(1);
    func_8029957C(3);
    func_802978DC(2);
    func_80297970(0.0f);
    bsTalkStayInState = TRUE;
}

void bstalk_update(void){
    enum bs_e next_state = BS_0_NONE;

    if (!bsTalkStayInState)
        next_state = BS_1_IDLE;
    bsTalkStayInState = FALSE;
    bs_setState(next_state);
}

void bstalk_end(void){}

void bstalk_interrupt(void){
    if(bs_getInterruptType() == BS_INTR_8){
        bsTalkStayInState = TRUE;
        func_8029A86C(2);
    }
    else{
        func_80296608();
    }
}
