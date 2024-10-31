#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"
#include "core2/yaw.h"

/* .bss */
bool  bsTalkStayInState;

/* .code */
void bstalk_init(void){
    AnimCtrl *player_anim_ctrl;
    f32 yaw;
    f32 plyr_pos[3];
    f32 target_pos[3];

    player_anim_ctrl = baanim_getAnimCtrlPtr();
    anctrl_reset(player_anim_ctrl);
    func_8029C848(player_anim_ctrl);
    anctrl_setPlaybackType(player_anim_ctrl,  ANIMCTRL_LOOP);
    anctrl_start(player_anim_ctrl, "bstalk.c", 0x38);
    _player_getPosition(plyr_pos);
    get_talk_target_position(target_pos);
    func_80257F18(plyr_pos, target_pos, &yaw);
    yaw_setIdeal(yaw);
    baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    yaw_setUpdateState(YAW_STATE_1_DEFAULT);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
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
