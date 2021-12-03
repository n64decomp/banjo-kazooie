#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"
#include "bs_funcs.h"


u8 D_80363820 = 0;
bsMap D_80363824[] ={
    {BS_1_IDLE,       bsstand_init,       bsstand_update,     bsstand_end,        func_802B5350},
    {BS_WALK_SLOW,  bswalk_slow_init,   bswalk_slow_upate,  NULL,               func_802B5350},
    {BS_WALK,       bswalk_init,        bswalk_update,      NULL,               func_802B5350},
    {BS_WALK_FAST,  bswalk_fast_init,   bswalk_fast_update, bswalk_fast_end,    func_802B5350},
    {BS_5_JUMP,       bsjump_init,        bsjump_update,      bsjump_end,         func_80296608},
    {BS_CLAW,       bsclaw_init,        bsclaw_update,      bsclaw_end,         func_80296608},
    {BS_CROUCH,     bscrouch_init,      bscrouch_update,    bscrouch_end,       func_802B5350},
    {BS_BTROT_JUMP, bsbtrot_jump_init,  bsbtrot_jump_update,bsbtrot_jump_end,   func_802B5350},
    {BS_SKID,       bsturn_init,        bsturn_update,      bsturn_end,         func_802B5350},
    {BS_TIMEOUT,    func_802B63F8,      func_802B64D0,      func_802B6500,      func_80296590},
    {BS_OW,         bsow_init,          bsow_update,        bsow_end,           func_80296590},
    {BS_BBUSTER,    bsbbuster_init,     bsbbuster_update,   bsbbuster_end,      func_80296608},
    {BS_BFLAP,      bsbflap_init,       bsbflap_update,     bsbflap_end,        func_80296608},
    {BS_BPECK,      bsbpeck_init,       bsbpeck_update,     bsbpeck_end,        func_80296608},
    {BS_BFLIP,      bsbflip_init,       bsbflip_update,     bsbflip_end,        func_80296608},
    {BS_BBARGE,     bsbarge_init,       bsbarge_update,     bsbarge_end,        func_80296608},
    {BS_BTROT_ENTER,    bsbtrot_enter_init, bsbtrot_enter_update, bsbtrot_enter_end, func_802B5350},
    {BS_BTROT_IDLE, bsbtrot_stand_init, bsbtrot_stand_update,   bsbtrot_stand_end,  func_802B5350},
    {BS_BTROT_WALK, bsbtrot_walk_init,  bsbtrot_walk_update,    bsbtrot_walk_end,   func_802B5350},
    {BS_BTROT_EXIT, bsbtrot_exit_init,  bsbtrot_exit_update,    bsbtrot_exit_end,   func_802B5350},
    {BS_FLY_KNOCKBACK,  func_802A4D90,      func_802A4EC8, func_802A4F44, func_80296608},
    {BS_WONDERWING_ENTER,   bsbwhirl_enter_init,    bsbwhirl_enter_update,  bsbwhirl_enter_end, func_80296608},
    {BS_1B_WONDERWING_IDLE,    bsbwhirl_stand_init,    bsbwhirl_stand_update,  bsbwhirl_stand_end, func_80296608},
    {BS_WONDERWING_WALK,    bsbwhirl_walk_init,     bsbwhirl_walk_update,   bsbwhirl_walk_end,  func_80296608},
    {BS_WONDERWING_JUMP,    bsbwhirl_jump_init,     bsbwhirl_jump_update,   bsbwhirl_jump_end,  func_80296608},
    {BS_WONDERWING_EXIT,    bsbwhirl_exit_init,     bsbwhirl_exit_update,   bsbwhirl_exit_end,  func_80296608},
    {BS_EGG_HEAD,       bsegghead_init,         bsegghead_update,       bsegghead_end,  func_802B5350},
    {BS_EGG_ASS,        bseggass_init,          bseggass_update,        bseggass_end,   func_802B5350},
    {BS_WALK_CREEP,     bswalk_creep_init,      bswalk_creep_update,    NULL,           func_802B5350},  
    {BS_LANDING,        bsstand_landing_init,   bsstand_landing_update, NULL,           func_802B5350},
    {BS_BSHOCK_CHARGE,  bsbshock_charge_init,   bsbshock_charge_update, bsbshock_charge_end,    func_80296608},
    {BS_BSHOCK_JUMP,    bsbshock_init,          bsbshock_update,        bsbshock_end,           func_80296608},
    {BS_FLY_ENTER,  bsbfly_enter_init, bsbfly_enter_update, bsbfly_enter_end, func_802A505C},
    {BS_FLY,        bsbfly_init, bsbfly_update, func_802A3F70, func_802A505C},
    {BS_LONGLEG_ENTER,  bsblongleg_enter_init,  bsblongleg_enter_update, bsblongleg_enter_end, func_802B5350},
    {BS_LONGLEG_IDLE,   bsblongleg_stand_enter, bsblongleg_stand_update, bsblongleg_stand_end, func_802B5350},
    {BS_LONGLEG_WALK,   bsblongleg_walk_init, bsblongleg_walk_update, bsblongleg_walk_end, func_802B5350},
    {BS_LONGLEG_JUMP,   bsblongleg_jump_init, bsblongleg_jump_update, bsblongleg_jump_end, func_80296608},
    {BS_LONGLEG_EXIT,   bsblongleg_exit_init, bsblongleg_exit_update, bsblongleg_exit_end, func_802B5350},
    {BS_BOMB,       func_802A3F9C, func_802A411C, func_802A4404, func_802A505C},
    {BS_DIVE_IDLE,  func_802A762C, func_802A7674, func_802A7718, func_80296608},
    {BS_DIVE_B,     func_802A7738, func_802A7838, func_802A7A2C, func_80296608},
    {BS_SWIM_IDLE,  func_802B5774, func_802B5950, func_802B5AF8, func_80296608},
    {BS_SWIM,       func_802B5B18, func_802B5C40, func_802B5E10, func_80296608},
    {BS_FALL,       bsjump_fall_init, bsjump_fall_update, bsjump_fall_end, func_80296608},
    {BS_DIVE_ENTER, func_802A7DAC, func_802A7E2C, func_802A7F4C, func_80296608},
    {BS_ROLL,       bstwirl_init,   bstwirl_update, bstwirl_end, func_802B5350},
    {BS_SLIDE,      bsslide_init,   bsslide_update, bsslide_end, func_802B5350},
    {0x33,          func_802B9ACC, func_802B9B14, func_802B9AAC, func_802B9D00},
    {BS_JIG_NOTEDOOR, bsjig_notedoor_init, bsjig_notedoor_update, bsjig_notedoor_end, func_80296590},
    {BS_ANT_IDLE,   bsant_idle_init, bsant_idle_update, bsant_idle_end, func_802B5350},
    {BS_ANT_WALK,   bsant_walk_init, bsant_walk_update, bsant_walk_end, func_802B5350},
    {BS_ANT_JUMP,   bsant_jump_init, bsant_jump_update, bsant_jump_end, func_802B5350},
    {BS_DIVE_A,     func_802A7A54, func_802A7AB0, func_802A7BA8, func_80296608},
    {BS_CARRY_IDLE, bscarry_idle_init, bscarry_idle_update, bscarry_idle_end, bscarry_interrupt},
    {BS_CARRY_WALK, bscarry_walk_init, bscarry_walk_update, bscarry_walk_end, bscarry_interrupt},
    {0x3C,          func_802B6130, func_802B61E0, func_802B6218, func_802B6220},
    {BS_FALL_TUMBLING,  bsjump_tumble_init, bsjump_tumble_update, bsjump_tumble_end, func_80296608},
    {BS_ANT_FALL,   bsant_fall_init, bsant_fall_update, bsant_fall_end, func_80296590},
    {BS_3E_ANT_OW,     bsant_ow_init, bsant_ow_update, bsant_ow_end, func_80296590},
    {0x3F,          func_802B1BF4, func_802B1CF8, func_802B1DA4, func_80296590},
    {0x40,          func_802B2BF0, func_802B2C58, func_802B2D50, func_80296590},
    {BS_DIE,        bsdie_init,     bsdie_update,   bsdie_end,      func_80296590},
    {BS_42_DINGPOT,    func_802A5120, func_802A5190, func_802A51C0, func_80296590},
    {BS_43_ANT_DIE,    bsant_die_init, bsant_die_update, bsant_die_end, func_80296590},
    {BS_JIG_JIGGY,  bsjig_jiggy_init, bsjig_jiggy_update, bsjig_jiggy_end, bsjig_jiggy_interrupt},
    {BS_BTROT_SLIDE, bsbtrot_slide_init, bsbtrot_slide_update, bsbtrot_slide_end, func_802B5350},
    {0x46,          func_802A2098, func_802A2130, func_802A2054, func_80296590},
    {BS_PUMPKIN_IDLE,   func_802B2384, func_802B242C, func_802B24AC, func_802B5350},
    {BS_PUMPKIN_WALK,   func_802B24D4, func_802B2580, func_802B2610, func_802B5350},
    {BS_PUMPKIN_JUMP,   func_802B2638, func_802B2750, func_802B2990, func_802B5350},
    {BS_PUMPKIN_FALL,   func_802B29C0, func_802B2A5C, func_802B2BD0, func_802B5350},
    {BS_LANDING_IN_WATER, func_802A846C, func_802A85EC, func_802A872C, func_80296608},
    {BS_PUMPKIN_OW,     func_802B2FDC, func_802B2FFC, func_802B301C, func_80296590},
    {BS_PUMPKIN_DIE,    func_802B309C, func_802B3240, func_802B3448, func_80296590},
    {BS_4F_CLIMB_IDLE, bsclimb_idle_init, bsclimb_idle_update, bsclimb_idle_end, func_802ABD60},
    {BS_50_CLIMB_MOVE, bsclimb_move_init, bsclimb_move_update, bsclimb_move_end, func_802ABD60},
    {BS_51_CLIMB_EXIT, func_802B1928, func_802B1A54, func_802B1BCC, func_80296608},
    {0x52,          func_802B5FD0, func_802B6064, func_802B60D0, func_802B60D8},
    {BS_TIMEOUT_UNK53, func_802B6270, func_802B6314, func_802B63C8, func_80296590},
    {BS_LONGLEG_SLIDE, bsblongleg_slide_init, bsblongleg_slide_update, bsblongleg_slide_end, func_802B5350},
    {BS_56_RECOIL, func_802B3868, func_802B3954, func_802B3A20, func_80296590},
    {BS_BOMB_END, func_802A4430, func_802A4548, func_802A4664, func_802A505C},
    {0x58, func_802A4748, func_802A48B4, func_802A4A40, func_80296590},
    {0x59, func_802A4CD0, func_802A4CF0, func_802A4D10, func_802A505C},
    {BS_54_SWIM_DIE, func_802A7F6C, func_802A8098, func_802A82D4, func_80296590},
    {BS_CARRY_THROW, bsthrow_init, bsthrow_update, bsthrow_end, bsthrow_interrupt},
    {BS_CROC_IDLE, bscroc_idle_init, bscroc_idle_update, bscroc_idle_end, func_802B5350},
    {BS_CROC_WALK, bscroc_walk_init, bscroc_walk_update, bscroc_walk_end, func_802B5350},
    {BS_CROC_JUMP, bscroc_jump_init, bscroc_jump_update, bscroc_jump_end, func_802B5350},
    {BS_CROC_FALL, bscroc_fall_init, bscroc_fall_update, bscroc_fall_end, func_802B5350},
    {BS_LONGLEG_UNK62, func_802A6394, func_802A63F0, func_802A6450, func_80296608},
    {BS_CROC_OW, bscroc_ow_init, bscroc_ow_update, bscroc_ow_end, func_80296590},
    {BS_CROC_DIE, bscroc_die_init, bscroc_die_update, bscroc_die_end, func_80296590},
    {BS_WALRUS_IDLE, bswalrus_idle_init, bswalrus_idle_update, bswalrus_idle_end, func_802B5350},
    {BS_WALRUS_WALK, bswalrus_walk_init, bswalrus_walk_update, bswalrus_walk_end, func_802B5350},
    {BS_WALRUS_JUMP, bswalrus_jump_init, bswalrus_jump_update, bswalrus_jump_end, func_802B5350},
    {BS_WALRUS_FALL, bswalrus_fall_init, bswalrus_fall_update, bswalrus_fall_end, func_802B5350},
    {0x6B, func_802A1F6C, func_802A1FC8, func_802A2014, func_80296608},
    {BS_WALRUS_OW, bswalrus_ow_init, bswalrus_ow_update, bswalrus_ow_end, func_80296590},
    {BS_WALRUS_DIE, bswalrus_die_init, bswalrus_die_update, bswalrus_die_end, func_80296590},
    {BS_CROC_BITE, bscroc_bite_init, bscroc_bite_update, bscroc_bite_end, func_802B5350},
    {BS_CROC_EAT_BAD, bscroc_eat_bad_init, bscroc_eat_bad_update, bscroc_eat_bad_end, func_802B5350},
    {BS_70_CROC_EAT_GOOD, bscroc_eat_good_init, bscroc_eat_good_update, bscroc_eat_good_end, func_802B5350},
    {BS_BTROT_FALL, bsbtrot_fall_init, bsbtrot_fall_update, bsbtrot_fall_end, func_80296608},
    {BS_SPLAT,  bssplat_init, bssplat_update, bssplat_end, func_80296590},
    {0x00000073, func_802B3CEC, func_802B3D1C, func_802B3D6C, func_80296608},
    {0x00000074, func_802B3E2C, func_802B3E64, func_802B3EF4, func_80296608},
    {0x00000075, func_802B3D8C, func_802B3DBC, func_802B3E0C, func_80296608},
    {0x00000076, func_802A4F74, func_802A4FC8, func_802A503C, func_80296608},
    {0x00000077, func_802B5E8C, func_802B5EFC, func_802B5F38, func_80296608},
    {0x00000078, func_802A83C0, func_802A8410, func_802A844C, func_80296608},
    {0x00000079, bsbtrot_unk79_init, bsbtrot_unk79_update, bsbtrot_unk79_end, func_80296608},
    {BS_WALK_MUD, bswalk_mud_init, bswalk_mud_update, NULL,          func_80296608},
    {BS_BTROT_OW, bsbtrot_ow_init, bsbtrot_ow_update, bsbtrot_ow_end, func_80296590},
    {0x0000007C, func_802B3FA4, func_802B4004, func_802B4038, func_802B4080},
    {BS_7D_WALRUS_SLED, bswalrus_sled_init, bswalrus_sled_update, bswalrus_sled_end, func_802B98C0},
    {BS_7E_WALRUS_SLED, bswalrus_sled_jump_init, bswalrus_sled_jump_update, bswalrus_sled_jump_end, func_802B98C0},
    {BS_DIVE_OW, func_802A7BD0, func_802A7CA8, func_802A7D74, func_80296590},
    {0x00000080, func_802B978C, func_802B9830, func_802B9880, func_80296590},
    {0x00000081, func_802B90D0, func_802B9130, func_802B917C, func_802B98C0},
    {0x00000082, func_802B95A0, func_802B963C, func_802B976C, func_802B98C0},
    {BS_BEE_IDLE, func_802A1080, func_802A10D4, func_802A117C, func_802B5350},
    {BS_BEE_WALK, func_802A11A4, func_802A1214, func_802A12D4, func_802B5350},
    {BS_BEE_JUMP, func_802A12FC, func_802A1438, func_802A163C, func_802B5350},
    {BS_BEE_FALL, func_802A1664, func_802A170C, func_802A18C8, func_802B5350},
    {BS_BEE_OW, func_802A1B68, func_802A1B88, func_802A1BA8, func_802B5350},
    {BS_BEE_DIE, bsbeemain_die_init, func_802A1DD8, func_802A1F2C, func_80296590},
    {0x0000008B, func_802A0590, func_802A0630, func_802A0704, func_802B5350},
    {BS_BEE_FLY, bsbeefly_enter, bsbeefly_update, bsbeefly_end, func_802B5350},
    {BS_CROC_LOCKED, func_802AD56C, func_802AD5C0, func_802AD614, func_802B5350},
    {0x0000008E, func_8029F398, func_8029F3F4, func_8029F440, func_802B5350},
    {BS_PUMPKIN_LOCKED, func_802B34A0, func_802B34F8, func_802B353C, func_802B5350},
    {BS_FLY_OW, func_802A4D30, func_802A4D50, func_802A4D70, func_802A505C},
    {BS_ANT_DRONE, bsant_drone_init, bsant_drone_update, bsant_drone_end, bsdrone_interrupt},
    {0x00000093, func_802B3564, func_802B3584, func_802B35A4, bsdrone_interrupt},
    {BS_CROC_DRONE, bscroc_drone_init, bscroc_drone_update, bscroc_drone_end, bsdrone_interrupt},
    {BS_WALRUS_DRONE, bswalrus_drone_init, bswalrus_drone_update, bswalrus_drone_end, bsdrone_interrupt},
    {BS_SWIM_LOCKED, func_802B5F58, func_802B5F80, func_802B5FA0, bsdrone_interrupt},
    {BS_DIVE_LOCKED, func_802A874C, func_802A8774, func_802A8794, bsdrone_interrupt},
    {BS_WALK_DRONE, bswalk_drone_init, bswalk_drone_update, bswalk_drone_end, bsdrone_interrupt},
    {0x00000099, func_802A50B0, func_802A50D8, func_802A50F8, bsdrone_interrupt},
    {BS_BTROT_DRONE, bsbtrot_drone_init, bsbtrot_drone_update, bsbtrot_drone_end, bsdrone_interrupt},
    {BS_LONGLEG_DRONE, bsblongleg_drone_init, bsblongleg_drone_update, bsblongleg_drone_end, bsdrone_interrupt},
    {0x0000009C, bswalrus_sled_drone_init, bswalrus_sled_drone_update, bswalrus_sled_drone_end, bsdrone_interrupt},
    {BS_BEE_DRONE, bsbee_drone_init, bsbee_drone_update, bsbee_drone_end, bsdrone_interrupt},
    {0x0000009E, func_802ABCCC, func_802ABD0C, func_802ABD40, func_802ABD60},
    {BS_ANT_BOUNCE, bsant_bounce_init, bsant_bounce_update, bsant_bounce_end, func_80296590},
    {BS_PUMPKIN_BOUNCE, func_802B303C, func_802B305C, func_802B307C, func_80296590},
    {BS_CROC_BOUNCE, bscroc_bounce_init, bscroc_bounce_update, bscroc_bounce_end, func_80296590},
    {BS_WALRUS_BOUNCE, bswalrus_bounce_init, bswalrus_bounce_update, bswalrus_bounce_end, func_80296590},
    {BS_BEE_BOUNCE, func_802A1BC8, func_802A1BE8, func_802A1C08, func_80296590},
    {BS_WONDERWING_DRONE, bsbwhirl_drone_init, bsbwhirl_drone_update, bsbwhirl_drone_end, func_80296608},
    {BS_WONDERWING_UNKA5, func_802AADBC, func_802AAE08, func_802AAE4C, func_80296608},
    {0}
};

extern void (*D_8037C3B0)();

void func_802958A0(void){
    s32 i;
    bsMap *iPtr;
    
    for(i = 0; D_80363824[i].uid != 0; i++){
        bsList_setInitMethod(D_80363824[i].uid, D_80363824[i].behavior.init_func);
        bsList_setUpdateMethod(D_80363824[i].uid, D_80363824[i].behavior.update_func);
        bsList_setEndMethod(D_80363824[i].uid, D_80363824[i].behavior.end_func);
        bsList_setInterruptMethod(D_80363824[i].uid, D_80363824[i].behavior.interrupt_func);
    }
}

void func_80295914(void){
    D_80363820 = 1;
    D_8037C3B0 = NULL;
    func_8029C608();
    func_802983F0();
    func_8028A410();
    func_80291910();
    func_8029279C();
    func_802932AC();
    func_80293380();
    func_8028B6FC();
    func_80291590();
    func_802953A0();
    func_8029B11C();
    func_8029528C();
    bsList_clearAll();
    bs_clearState();
    func_80295DD0();
    func_80296C30();
    func_802976E4();
    func_80297C78();
    pitch_reset();
    climbClear();
    func_8029887C();
    roll_reset();
    func_802992F0();
    func_80294DD8();
    func_8029CF6C();
    func_8029DFF8();
    func_80290B6C();
    func_80292D88();
    func_80290070();
    func_80290664();
    func_80291764();
    func_80292B3C();
    func_80294790();
    func_80293DA4();
    func_80289D1C();
    func_80291D2C();
    func_8028D1FC();
    func_80299900();
    func_8029A4D0();
    func_8029ADCC();
    func_8029D01C();
    func_802958A0();
}

void func_80295A8C(void){
    
    func_802917E4(2, func_8029A900());
    func_802917E4(3, func_8029A90C());
    if(func_8028ADB4())
        bs_setState(func_80292630());
    else
        bs_setState(func_8029BF78());

}

void func_80295B04(void){
    f32 sp24;
    enum bs_e sp20 = bs_getState();
    int tmp_a1;
    
    sp24 = (bslongleg_inSet(sp20)) ? func_80291670(2) : 0.0f;
    func_8029A968(sp24);
    sp24 = 0.0f;
    tmp_a1 = 0;
    if(bsbtrot_inSet(sp20)){
        sp24 = func_80291670(3);
        tmp_a1 = 1;
    }

    func_8029A980(tmp_a1);
    func_8029A974(sp24);
    bs_setState(BS_5A_LOADZONE);
    func_8028D2BC();
    func_8029065C();
    func_8029175C();
    func_80292B18();
    func_80291E88();
    func_80289DDC();
    func_80293E88();
    func_802947C4();
    func_80299A20();
    func_8029A54C();
    func_8029ADA8();
    func_8029CFF8();
    D_80363820 = 0;
}

void func_80295C08(void (* arg0)(void)){
    D_8037C3B0 = arg0;
}

void func_80295C14(void){
    func_802964B8();
    func_80298A84();
    func_80291804();
    func_8029E100();
    func_8024E7C8();//controller_update
    func_8023E06C();
    func_80295448();
    func_8029B174();
    func_8029533C(); //dive_cooldown_update
    bs_updateState();
    func_80297744();
    func_8029858C();
    func_802932EC();
    func_80293F0C();
    pitch_update();
    roll_update();
    func_802993C8();//yaw update
    func_802906D8();
    func_80289E00();
    func_8029A554();
    func_80298344(); //climb_cooldown_update
    func_80290108();
    func_80292C1C();
    func_80292EDC();
    func_80291ECC();
    func_8029842C();
    func_8028D2E4();
    func_80294890();
    func_8028A8D0();
    func_8028B71C();
    func_8029D968();
    func_80297CF8();
    func_80294E60();
    func_80291358();//camera_update
    func_802919A0();
    if(D_8037C3B0){
        D_8037C3B0();
        D_8037C3B0 = NULL;
    }
    func_80299A8C();
    func_80295E74();//voidOut_update
}

void func_80295D74(void){
    if(D_80363820){
        func_80289E74();
        func_8029259C();
        func_80292C78();
        func_80294750();
        func_8029AF1C();
    }
}
