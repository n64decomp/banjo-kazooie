#ifndef __BS_FUNCS__
#define __BS_FUNCS__

//interrupt
void func_802B5350(void);
void func_80296608(void);
void func_80296590(void); //bsow

//bsstand
void bsstand_init(void); 
void bsstand_update(void);
void bsstand_end(void);
//bswalkslow
void bswalk_slow_init(void);
void bswalk_slow_upate(void);
//bswalk
void bswalk_init(void);
void bswalk_update(void);
//bswalkfast
void bswalk_fast_init(void);
void bswalk_fast_update(void);
void bswalk_fast_end(void);
//bsjump
void bsjump_init(void);
void bsjump_update(void);
void bsjump_end(void);
//bspunch
int bsclaw_hitboxActive(void);
void bsclaw_init(void);
void bsclaw_update(void);
void bsclaw_end(void);
//bscrouch
void bscrouch_init(void);
void bscrouch_update(void);
void bscrouch_end(void);
//bsbtrotjump
void bsbtrot_jump_init(void);
void bsbtrot_jump_update(void);
void bsbtrot_jump_end(void);
//bsskid
void bsturn_init(void);
void bsturn_update(void);
void bsturn_end(void);
//0xd
void func_802B63F8(void);
void func_802B64D0(void);
void func_802B6500(void);
//bsow
void bsow_init(void);
void bsow_update(void);
void bsow_end(void);
//bsbuster
void bsbbuster_init(void);
void bsbbuster_update(void);
void bsbbuster_end(void);
//bsflap
void bsbflap_init(void);
void bsbflap_update(void);
void bsbflap_end(void);
//bsbpeck
void bsbpeck_init(void);
void bsbpeck_update(void);
void bsbpeck_end(void);
//bsbflip
void bsbflip_init(void);
void bsbflip_update(void);
void bsbflip_end(void);
//bsbbarge
void bsbarge_init(void);
void bsbarge_update(void);
void bsbarge_end(void);
//bsbtrot_enter
void bsbtrot_enter_init(void);
void bsbtrot_enter_update(void);
void bsbtrot_enter_end(void);
//bsbtrot_idle
void bsbtrot_stand_init(void);
void bsbtrot_stand_update(void);
void bsbtrot_stand_end(void);
//bsbtrot_walk
void bsbtrot_walk_init(void);
void bsbtrot_walk_update(void);
void bsbtrot_walk_end(void);
//bsbtrot_exit
void bsbtrot_exit_init(void);
void bsbtrot_exit_update(void);
void bsbtrot_exit_end(void);
//bsfly_knockback
void func_802A4D90(void);
void func_802A4EC8(void);
void func_802A4F44(void);
//BS_1A_WONDERWING_ENTER
void bsbwhirl_enter_init(void);
void bsbwhirl_enter_update(void);
void bsbwhirl_enter_end(void);
//BS_1B_WONDERWING_IDLE
void bsbwhirl_stand_init(void);
void bsbwhirl_stand_update(void);
void bsbwhirl_stand_end(void);
//BS_1C_WONDERWING_WALK,
void bsbwhirl_walk_init(void);
void bsbwhirl_walk_update(void);
void bsbwhirl_walk_end(void);
//BS_1D_WONDERWING_JUMP
void bsbwhirl_jump_init(void);
void bsbwhirl_jump_update(void);
void bsbwhirl_jump_end(void);
//BS_1E_WONDERWING_EXIT
void bsbwhirl_exit_init(void);
void bsbwhirl_exit_update(void);
void bsbwhirl_exit_end(void);
//BS_9_EGG_HEAD
void bsegghead_init(void);
void bsegghead_update(void);
void bsegghead_end(void);
//BS_A_EGG_ASS
void bseggass_init(void);
void bseggass_update(void);
void bseggass_end(void);
//BS_WALK_CREEP(void);
void bswalk_creep_init(void);
void bswalk_creep_update(void);
//BS_20_LANDING(void);
void bsstand_landing_init(void);
void bsstand_landing_update(void);
//BS_BSHOCK_CHARGE(void);
void bsbshock_charge_init(void);
void bsbshock_charge_update(void);
void bsbshock_charge_end(void);
//BS_BSHOCK_JUMP(void);
void bsbshock_init(void);
void bsbshock_update(void);
void bsbshock_end(void);
//BS_23_FLY_ENTER(void);
void bsbfly_enter_init(void);
void bsbfly_enter_update(void);
void bsbfly_enter_end(void);
void func_802A505C(void);
//BS_FLY(void);
void bsbfly_init(void);
void bsbfly_update(void);
void func_802A3F70(void);
//BS_25_LONGLEG_ENTER(void);
void bsblongleg_enter_init(void);
void bsblongleg_enter_update(void);
void bsblongleg_enter_end(void);
//BS_26_LONGLEG_IDLE(void);
void bsblongleg_stand_enter(void);
void bsblongleg_stand_update(void);
void bsblongleg_stand_end(void);
//BS_LONGLEG_WALK(void);
void bsblongleg_walk_init(void);
void bsblongleg_walk_update(void);
void bsblongleg_walk_end(void);
//BS_LONGLEG_JUMP(void);
void bsblongleg_jump_init(void);
void bsblongleg_jump_update(void);
void bsblongleg_jump_end(void);
//BS_LONGLEG_EXIT(void);
void bsblongleg_exit_init(void);
void bsblongleg_exit_update(void);
void bsblongleg_exit_end(void);
//BS_BOMB(void);
void func_802A3F9C(void);
void func_802A411C(void);
void func_802A4404(void);
//BS_2B_DIVE_IDLE(void);
void func_802A762C(void);
void func_802A7674(void);
void func_802A7718(void);
//BS_2C_DIVE_B(void);
void func_802A7738(void);
void func_802A7838(void);
void func_802A7A2C(void);
//BS_2D_SWIM_IDLE,  
void func_802B5774(void);
void func_802B5950(void);
void func_802B5AF8(void);
//BS_2E_SWIM(void);
void func_802B5B18(void);
void func_802B5C40(void);
void func_802B5E10(void);
//BS_2F_FALL(void);
void bsjump_fall_init(void);
void bsjump_fall_update(void);
void bsjump_fall_end(void);
//BS_30_DIVE_ENTER
void bsSwim_dive_init(void);
void func_802A7E2C(void);
void func_802A7F4C(void);
//BS_ROLL(void);
int bstwirl_hitboxActive(void);
void bstwirl_init(void);
void bstwirl_update(void);
void bstwirl_end(void);
//BS_SLIDE
void bsslide_init(void);
void bsslide_update(void);
void bsslide_end(void);
//0x33(void);
void func_802B9ACC(void);
void func_802B9B14(void);
void func_802B9AAC(void);
void func_802B9D00(void);
//BS_34_JIG_NOTEDOOR(void);
void bsjig_notedoor_init(void);
void bsjig_notedoor_update(void);
void bsjig_notedoor_end(void);
//BS_35_ANT_IDLE
void bsant_idle_init(void);
void bsant_idle_update(void);
void bsant_idle_end(void);
//BS_ANT_WALK
void bsant_walk_init(void);
void bsant_walk_update(void);
void bsant_walk_end(void);
//BS_ANT_JUMP
void bsant_jump_init(void);
void bsant_jump_update(void);
void bsant_jump_end(void);
//BS_39_DIVE_A
void func_802A7A54(void);
void func_802A7AB0(void);
void func_802A7BA8(void);
//BS_3A_CARRY_IDLE(void);
void bscarry_idle_init(void);
void bscarry_idle_update(void);
void bscarry_idle_end(void);
void bscarry_interrupt(void);
//BS_3B_CARRY_WALK(void);
void bscarry_walk_init(void);
void bscarry_walk_update(void);
void bscarry_walk_end(void);
//0x3C (void);
void bstalk_init(void);
void bstalk_update(void);
void bstalk_end(void);
void bstalk_interrupt(void);
//BS_3D_FALL_TUMBLING(void);
void bsjump_tumble_init(void);
void bsjump_tumble_update(void);
void bsjump_tumble_end(void);
//BS_38_ANT_FALL(void);
void bsant_fall_init(void);
void bsant_fall_update(void);
void bsant_fall_end(void);
//BS_3E_ANT_OW
void bsant_ow_init(void);
void bsant_ow_update(void);
void bsant_ow_end(void);
    //0x3F
void func_802B1BF4(void);
void func_802B1CF8(void);
void func_802B1DA4(void);
    //0x40
void func_802B2BF0(void);
void func_802B2C58(void);
void func_802B2D50(void);
    //BS_41_DIE
void bsdie_init(void);
void bsdie_update(void);
void bsdie_end(void);
    //BS_42_DINGPOT
void func_802A5120(void);
void func_802A5190(void);
void func_802A51C0(void);
    //BS_43_ANT_DIE
void bsant_die_init(void);
void bsant_die_update(void);
void bsant_die_end(void);
//BS_44_JIG_JIGGY
void bsjig_jiggy_init(void);
void bsjig_jiggy_update(void);
void bsjig_jiggy_end(void);
void bsjig_jiggy_interrupt(void);
//BS_45_BTROT_SLIDE
void bsbtrot_slide_init(void);
void bsbtrot_slide_update(void);
void bsbtrot_slide_end(void);
//0x46
void func_802A2098(void);
void func_802A2130(void);
void func_802A2054(void);
//BS_48_PUMPKIN_IDLE
void bspumpkin_idle_init(void);
void bspumpkin_idle_update(void);
void bspumpkin_idle_end(void);
//BS_49_PUMPKIN_WALK
void bspumpkin_walk_init(void);
void bspumpkin_walk_update(void);
void bspumpkin_walk_end(void);
//BS_4A_PUMPKIN_JUMP
void bspumpkin_jump_init(void);
void bspumpkin_jump_update(void);
void bspumpkin_jump_end(void);
//BS_4B_PUMPKIN_FALL
void bspumpkin_fall_init(void);
void bspumpkin_fall_update(void);
void bspumpkin_fall_end(void);
//BS_4C_LANDING_IN_WATER
void func_802A846C(void);
void func_802A85EC(void);
void func_802A872C(void);
//BS_4D_PUMPKIN_OW
void __bspumpkin_ow_init(void);
void __bspumpkin_ow_update(void);
void __bspumpkin_ow_end(void);
//BS_4E_PUMPKIN_DIE
void bspumpkin_die_init(void);
void bspumpkin_die_update(void);
void bspumpkin_die_end(void);
//BS_4F_CLIMB_IDLE
void bsclimb_idle_init(void);
void bsclimb_idle_update(void);
void bsclimb_idle_end(void);
void func_802ABD60(void);
//BS_50_CLIMB_MOVE
void bsclimb_move_init(void);
void bsclimb_move_update(void);
void bsclimb_move_end(void);
//BS_51_CLIMB_EXIT
void func_802B1928(void);
void func_802B1A54(void);
void func_802B1BCC(void);
//0x52
void func_802B5FD0(void);
void func_802B6064(void);
void func_802B60D0(void);
void func_802B60D8(void);
    //0x53
void func_802B6270(void);
void func_802B6314(void);
void func_802B63C8(void);

    //0x55
void bsblongleg_slide_init(void);
void bsblongleg_slide_update(void);
void bsblongleg_slide_end(void);

    //0x56
void func_802B3868(void);
void func_802B3954(void);
void func_802B3A20(void);

    //0x57
void func_802A4430(void);
void func_802A4548(void);
void func_802A4664(void);
void func_802A505C(void);
    //0x58
void bsbfly_beakbomb_crash_init(void);
void func_802A48B4(void);
void func_802A4A40(void);

    //0x59
void func_802A4CD0(void);
void func_802A4CF0(void);
void func_802A4D10(void);
void func_802A505C(void);
    //0x54
void func_802A7F6C(void);
void func_802A8098(void);
void func_802A82D4(void);

    //0x5B
void bsthrow_init(void);
void bsthrow_update(void);
void bsthrow_end(void);
void bsthrow_interrupt(void);
    //0x5E
void bscroc_idle_init(void);
void bscroc_idle_update(void);
void bscroc_idle_end(void);

    //0x5F
void bscroc_walk_init(void);
void bscroc_walk_update(void);
void bscroc_walk_end(void);

    //0x60
void bscroc_jump_init(void);
void bscroc_jump_update(void);
void bscroc_jump_end(void);

    //0x61
void bscroc_fall_init(void);
void bscroc_fall_update(void);
void bscroc_fall_end(void);

    //0x62
void func_802A6394(void);
void func_802A63F0(void);
void func_802A6450(void);
    //0x63
void bscroc_ow_init(void);
void bscroc_ow_update(void);
void bscroc_ow_end(void);

    //0x64
void bscroc_die_init(void);
void bscroc_die_update(void);
void bscroc_die_end(void);

    //0x67
void bswalrus_idle_init(void);
void bswalrus_idle_update(void);
void bswalrus_idle_end(void);

    //0x68
void bswalrus_walk_init(void);
void bswalrus_walk_update(void);
void bswalrus_walk_end(void);

    //0x69
void bswalrus_jump_init(void);
void bswalrus_jump_update(void);
void bswalrus_jump_end(void);

    //0x6A
void bswalrus_fall_init(void);
void bswalrus_fall_update(void);
void bswalrus_fall_end(void);

    //0x6B
void func_802A1F6C(void);
void func_802A1FC8(void);
void func_802A2014(void);
//0x0000006C
void bswalrus_ow_init(void);
void bswalrus_ow_update(void);
void bswalrus_ow_end(void);

//0x0000006D
void bswalrus_die_init(void);
void bswalrus_die_update(void);
void bswalrus_die_end(void);

//0x0000006E
void bscroc_bite_init(void);
void bscroc_bite_update(void);
void bscroc_bite_end(void);

//0x0000006F
void bscroc_eat_bad_init(void);
void bscroc_eat_bad_update(void);
void bscroc_eat_bad_end(void);

//0x00000070
void bscroc_eat_good_init(void);
void bscroc_eat_good_update(void);
void bscroc_eat_good_end(void);

//0x00000071
void bsbtrot_fall_init(void);
void bsbtrot_fall_update(void);
void bsbtrot_fall_end(void);
//0x00000072
void bssplat_init(void);
void bssplat_update(void);
void bssplat_end(void);

//0x00000073
void func_802B3CEC(void);
void func_802B3D1C(void);
void func_802B3D6C(void);
//0x00000074
void func_802B3E2C(void);
void func_802B3E64(void);
void func_802B3EF4(void);

//0x00000075
void func_802B3D8C(void);
void func_802B3DBC(void);
void func_802B3E0C(void);

//0x00000076
void func_802A4F74(void);
void func_802A4FC8(void);
void func_802A503C(void);

//0x00000077
void func_802B5E8C(void);
void func_802B5EFC(void);
void func_802B5F38(void);

//0x00000078
void func_802A83C0(void);
void func_802A8410(void);
void func_802A844C(void);

//0x00000079
void bsbtrot_unk79_init(void);
void bsbtrot_unk79_update(void);
void bsbtrot_unk79_end(void);

//0x0000007A
void bswalk_mud_init(void);
void bswalk_mud_update(void);
//0x0000007B
void bsbtrot_ow_init(void);
void bsbtrot_ow_update(void);
void bsbtrot_ow_end(void);

//0x0000007C
void bssled_init(void);
void bssled_update(void);
void bssled_end(void);
void bssled_interrupt(void);
//0x0000007D
void bswalrus_sled_init(void);
void bswalrus_sled_update(void);
void bswalrus_sled_end(void);
void func_802B98C0(void);
//0x0000007E
void bswalrus_sled_jump_init(void);
void bswalrus_sled_jump_update(void);
void bswalrus_sled_jump_end(void);
void func_802B98C0(void);
//0x0000007F
void func_802A7BD0(void);
void func_802A7CA8(void);
void func_802A7D74(void);

//0x00000080
void bswalrus_timeout_init(void);
void func_802B9830(void);
void func_802B9880(void);

//0x00000081
void func_802B90D0(void);
void func_802B9130(void);
void func_802B917C(void);
void func_802B98C0(void);
//0x00000082
void func_802B95A0(void);
void func_802B963C(void);
void func_802B976C(void);
void func_802B98C0(void);
//0x00000085
void func_802A1080(void);
void func_802A10D4(void);
void func_802A117C(void);

//0x00000086
void func_802A11A4(void);
void func_802A1214(void);
void func_802A12D4(void);

//0x00000087
void func_802A12FC(void);
void func_802A1438(void);
void func_802A163C(void);

//0x00000088
void func_802A1664(void);
void func_802A170C(void);
void func_802A18C8(void);

//0x00000089
void func_802A1B68(void);
void func_802A1B88(void);
void func_802A1BA8(void);

//0x0000008A
void bsbeemain_die_init(void);
void func_802A1DD8(void);
void func_802A1F2C(void);

//0x0000008B
void func_802A0590(void);
void func_802A0630(void);
void func_802A0704(void);

//0x0000008C
void bsbeefly_enter(void);
void bsbeefly_update(void);
void bsbeefly_end(void);

//0x0000008D
void func_802AD56C(void);
void func_802AD5C0(void);
void func_802AD614(void);

//0x0000008E
void func_8029F398(void);
void func_8029F3F4(void);
void func_8029F440(void);

//0x0000008F
void func_802B34A0(void);
void func_802B34F8(void);
void func_802B353C(void);

//0x00000091
void func_802A4D30(void);
void func_802A4D50(void);
void func_802A4D70(void);
void func_802A505C(void);
//0x00000092
void bsant_drone_init(void);
void bsant_drone_update(void);
void bsant_drone_end(void);
void bsdrone_interrupt(void);
//0x00000093
void bspumpkin_drone_init(void);
void bspumpkin_drone_update(void);
void bspumpkin_drone_end(void);
void bsdrone_interrupt(void);
//0x00000094
void bscroc_drone_init(void);
void bscroc_drone_update(void);
void bscroc_drone_end(void);
void bsdrone_interrupt(void);
//0x00000095
void bswalrus_drone_init(void);
void bswalrus_drone_update(void);
void bswalrus_drone_end(void);
void bsdrone_interrupt(void);
//0x00000096
void func_802B5F58(void);
void func_802B5F80(void);
void func_802B5FA0(void);
void bsdrone_interrupt(void);
//0x00000097
void func_802A874C(void);
void func_802A8774(void);
void func_802A8794(void);
void bsdrone_interrupt(void);
//0x00000098
void bswalk_drone_init(void);
void bswalk_drone_update(void);
void bswalk_drone_end(void);
void bsdrone_interrupt(void);
//0x00000099
void func_802A50B0(void);
void func_802A50D8(void);
void func_802A50F8(void);
void bsdrone_interrupt(void);
//0x0000009A
void bsbtrot_drone_init(void);
void bsbtrot_drone_update(void);
void bsbtrot_drone_end(void);
void bsdrone_interrupt(void);
//0x0000009B
void bsblongleg_drone_init(void);
void bsblongleg_drone_update(void);
void bsblongleg_drone_end(void);
void bsdrone_interrupt(void);
//0x0000009C
void bswalrus_sled_drone_init(void);
void bswalrus_sled_drone_update(void);
void bswalrus_sled_drone_end(void);
void bsdrone_interrupt(void);
//0x0000009D
void bsbee_drone_init(void);
void bsbee_drone_update(void);
void bsbee_drone_end(void);
void bsdrone_interrupt(void);
//0x0000009E
void func_802ABCCC(void);
void func_802ABD0C(void);
void func_802ABD40(void);
void func_802ABD60(void);
//0x0000009F
void bsant_bounce_init(void);
void bsant_bounce_update(void);
void bsant_bounce_end(void);

//0x000000A0
void bspumpkin_rebound_init(void);
void bspumpkin_rebound_update(void);
void bspumpkin_rebound_end(void);

//0x000000A1
void bscroc_bounce_init(void);
void bscroc_bounce_update(void);
void bscroc_bounce_end(void);

//0x000000A2
void bswalrus_bounce_init(void);
void bswalrus_bounce_update(void);
void bswalrus_bounce_end(void);

//0x000000A3
void func_802A1BC8(void);
void func_802A1BE8(void);
void func_802A1C08(void);

//0x000000A4
void bsbwhirl_drone_init(void);
void bsbwhirl_drone_update(void);
void bsbwhirl_drone_end(void);

//0x000000A5
void func_802AADBC(void);
void func_802AAE08(void);
void func_802AAE4C(void);

void bsDroneGoTo_init(void);
void bsDroneGoTo_update(void);
void bsDroneGoTo_end(void);
void bsDroneLook_init(void);
void bsDroneLook_update(void);
void bsDroneLook_end(void);
void bsdronexform_init(void);
void bsdronexform_update(void);
void bsdronexform_end(void);
void bsdronexform_interrupt(void);
void bsDroneEnter_init(void);
void bsDroneEnter_update(void);
void bsDroneEnter_end(void);
void bsDroneVanish_init(void);
void bsDroneVanish_update(void);
void bsDroneVanish_end(void);
#endif
