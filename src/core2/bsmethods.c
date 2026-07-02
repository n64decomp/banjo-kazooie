#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "bsint.h"
#include "bs_funcs.h"
#include "core2/statetimer.h"
#include "core2/ba/physics.h"
#include "snackerctl.h"

u8 D_80363820 = 0;

bsMap bsMethodsTable[] = {
   //Banjo States                  Initialize Funcitons           Update Functions               End Functions                  Interrupt Functions
    {BS_1_IDLE,                    bsstand_init,                  bsstand_update,                bsstand_end,                   func_802B5350},
    {BS_2_WALK_SLOW,               bswalk_slow_init,              bswalk_slow_upate,             NULL,                          func_802B5350},
    {BS_3_WALK,                    bswalk_init,                   bswalk_update,                 NULL,                          func_802B5350},
    {BS_4_WALK_FAST,               bswalk_fast_init,              bswalk_fast_update,            bswalk_fast_end,               func_802B5350},
    {BS_5_JUMP,                    bsjump_init,                   bsjump_update,                 bsjump_end,                    func_80296608},
    {BS_6_CLAW,                    bsclaw_init,                   bsclaw_update,                 bsclaw_end,                    func_80296608},
    {BS_7_CROUCH,                  bscrouch_init,                 bscrouch_update,               bscrouch_end,                  func_802B5350},
    {BS_8_BTROT_JUMP,              bsbtrot_jump_init,             bsbtrot_jump_update,           bsbtrot_jump_end,              func_802B5350},
    {BS_C_SKID,                    bsturn_init,                   bsturn_update,                 bsturn_end,                    func_802B5350},
    {BS_D_TIMEOUT_TRANSFORMATION,  timeout_transformation_init,   timeout_transformation_update, timeout_transformation_end,    func_80296590},
    {BS_E_OW,                      bsow_init,                     bsow_update,                   bsow_end,                      func_80296590},
    {BS_F_BBUSTER,                 bsbbuster_init,                bsbbuster_update,              bsbbuster_end,                 func_80296608},
    {BS_10_BFLAP,                  bsbflap_init,                  bsbflap_update,                bsbflap_end,                   func_80296608},
    {BS_11_BPECK,                  bsbpeck_init,                  bsbpeck_update,                bsbpeck_end,                   func_80296608},
    {BS_12_BFLIP,                  bsbflip_init,                  bsbflip_update,                bsbflip_end,                   func_80296608},
    {BS_13_BBARGE,                 bsbarge_init,                  bsbarge_update,                bsbarge_end,                   func_80296608},
    {BS_14_BTROT_ENTER,            bsbtrot_enter_init,            bsbtrot_enter_update,          bsbtrot_enter_end,             func_802B5350},
    {BS_15_BTROT_IDLE,             bsbtrot_stand_init,            bsbtrot_stand_update,          bsbtrot_stand_end,             func_802B5350},
    {BS_16_BTROT_WALK,             bsbtrot_walk_init,             bsbtrot_walk_update,           bsbtrot_walk_end,              func_802B5350},
    {BS_17_BTROT_EXIT,             bsbtrot_exit_init,             bsbtrot_exit_update,           bsbtrot_exit_end,              func_802B5350},
    {BS_18_FLY_KNOCKBACK,          bsbfly_knockback_init,         bsbfly_knockback_update,       bsbfly_knockback_end,          func_80296608},
    {BS_1A_WONDERWING_ENTER,       bsbwhirl_enter_init,           bsbwhirl_enter_update,         bsbwhirl_enter_end,            func_80296608},
    {BS_1B_WONDERWING_IDLE,        bsbwhirl_stand_init,           bsbwhirl_stand_update,         bsbwhirl_stand_end,            func_80296608},
    {BS_1C_WONDERWING_WALK,        bsbwhirl_walk_init,            bsbwhirl_walk_update,          bsbwhirl_walk_end,             func_80296608},
    {BS_1D_WONDERWING_JUMP,        bsbwhirl_jump_init,            bsbwhirl_jump_update,          bsbwhirl_jump_end,             func_80296608},
    {BS_1E_WONDERWING_EXIT,        bsbwhirl_exit_init,            bsbwhirl_exit_update,          bsbwhirl_exit_end,             func_80296608},
    {BS_9_EGG_HEAD,                bsegghead_init,                bsegghead_update,              bsegghead_end,                 func_802B5350},
    {BS_A_EGG_ASS,                 bseggass_init,                 bseggass_update,               bseggass_end,                  func_802B5350},
    {BS_1F_WALK_CREEP,             bswalk_creep_init,             bswalk_creep_update,           NULL,                          func_802B5350},
    {BS_20_LANDING,                bsstand_landing_init,          bsstand_landing_update,        NULL,                          func_802B5350},
    {BS_21_BSHOCK_CHARGE,          bsbshock_charge_init,          bsbshock_charge_update,        bsbshock_charge_end,           func_80296608},
    {BS_22_BSHOCK_JUMP,            bsbshock_init,                 bsbshock_update,               bsbshock_end,                  func_80296608},
    {BS_23_FLY_ENTER,              bsbfly_enter_init,             bsbfly_enter_update,           bsbfly_enter_end,              func_802A505C},
    {BS_24_FLY,                    bsbfly_init,                   bsbfly_update,                 bsbfly_end,                    func_802A505C},
    {BS_25_LONGLEG_ENTER,          bsblongleg_enter_init,         bsblongleg_enter_update,       bsblongleg_enter_end,          func_802B5350},
    {BS_26_LONGLEG_IDLE,           bsblongleg_stand_enter,        bsblongleg_stand_update,       bsblongleg_stand_end,          func_802B5350},
    {BS_27_LONGLEG_WALK,           bsblongleg_walk_init,          bsblongleg_walk_update,        bsblongleg_walk_end,           func_802B5350},
    {BS_28_LONGLEG_JUMP,           bsblongleg_jump_init,          bsblongleg_jump_update,        bsblongleg_jump_end,           func_80296608},
    {BS_29_LONGLEG_EXIT,           bsblongleg_exit_init,          bsblongleg_exit_update,        bsblongleg_exit_end,           func_802B5350},
    {BS_2A_BOMB,                   bsbfly_bomb_init,              bsbfly_bomb_update,            bsbfly_bomb_end,               func_802A505C},
    {BS_2B_DIVE_IDLE,              bsbdive_idle_init,             bsbdive_idle_update,           bsbdive_idle_end,              func_80296608},
    {BS_2C_DIVE_B,                 bsbdiveb_init,                 bsbdiveb_update,               bsbdiveb_end,                  func_80296608},
    {BS_2D_SWIM_IDLE,              bsswim_idle_init,              bsswim_idle_update,            bsswim_idle_end,               func_80296608},
    {BS_2E_SWIM,                   bsswim_swim_init,              bsswim_swim_update,            bsswim_swim_end,               func_80296608},
    {BS_2F_FALL,                   bsjump_fall_init,              bsjump_fall_update,            bsjump_fall_end,               func_80296608},
    {BS_30_DIVE_ENTER,             bsSwim_dive_init,              bsSwim_dive_update,            bsSwim_dive_end,               func_80296608},
    {BS_31_ROLL,                   bstwirl_init,                  bstwirl_update,                bstwirl_end,                   func_802B5350},
    {BS_32_SLIDE,                  bsslide_init,                  bsslide_update,                bsslide_end,                   func_802B5350},
    {BS_33_WASHY_UNKNOWN,          bswashy_init,                  bswashy_update,                bswashy_end,                   func_802B9D00},
    {BS_34_JIG_NOTEDOOR,           bsjig_notedoor_init,           bsjig_notedoor_update,         bsjig_notedoor_end,            VER_SELECT(func_80296590, 0x802b0cfc, 0, 0)},
    {BS_35_ANT_IDLE,               bsant_idle_init,               bsant_idle_update,             bsant_idle_end,                func_802B5350},
    {BS_36_ANT_WALK,               bsant_walk_init,               bsant_walk_update,             bsant_walk_end,                func_802B5350},
    {BS_37_ANT_WALK,               bsant_jump_init,               bsant_jump_update,             bsant_jump_end,                func_802B5350},
    {BS_39_DIVE_A,                 bsswim_divea_init,             bsswim_divea_update,           bsswim_divea_end,              func_80296608},
    {BS_3A_CARRY_IDLE,             bscarry_idle_init,             bscarry_idle_update,           bscarry_idle_end,              bscarry_interrupt},
    {BS_3B_CARRY_WALK,             bscarry_walk_init,             bscarry_walk_update,           bscarry_walk_end,              bscarry_interrupt},
    {BS_3C_TALK,                   bstalk_init,                   bstalk_update,                 bstalk_end,                    bstalk_interrupt},
    {BS_3D_FALL_TUMBLING,          bsjump_tumble_init,            bsjump_tumble_update,          bsjump_tumble_end,             func_80296608},
    {BS_38_ANT_FALL,               bsant_fall_init,               bsant_fall_update,             bsant_fall_end,                func_80296590},
    {BS_3E_ANT_OW,                 bsant_ow_init,                 bsant_ow_update,               bsant_ow_end,                  func_80296590},
    {BS_3F_UNKNOWN,                func_802B1BF4,                 func_802B1CF8,                 func_802B1DA4,                 func_80296590},
    {BS_40_PUMPKIN_FLUSH,          bspumpkin_flush_init,          bspumpkin_flush_update,        bspumpkin_flush_end,           func_80296590},
    {BS_41_DIE,                    bsdie_init,                    bsdie_update,                  bsdie_end,                     func_80296590},
    {BS_42_DINGPOT,                bsfly_dingpotLaunch_init,      bsfly_dingpotLaunch_update,    bsfly_dingpotLaunch_end,       func_80296590},
    {BS_43_ANT_DIE,                bsant_die_init,                bsant_die_update,              bsant_die_end,                 func_80296590},
    {BS_44_JIG_JIGGY,              bsjig_jiggy_init,              bsjig_jiggy_update,            bsjig_jiggy_end,               bsjig_jiggy_interrupt},
    {BS_45_BTROT_SLIDE,            bsbtrot_slide_init,            bsbtrot_slide_update,          bsbtrot_slide_end,             func_802B5350},
    {BS_46_UNKNOWN,                func_802A2098,                 func_802A2130,                 func_802A2054,                 func_80296590},
    {BS_48_PUMPKIN_IDLE,           bspumpkin_idle_init,           bspumpkin_idle_update,         bspumpkin_idle_end,            func_802B5350},
    {BS_49_PUMPKIN_WALK,           bspumpkin_walk_init,           bspumpkin_walk_update,         bspumpkin_walk_end,            func_802B5350},
    {BS_4A_PUMPKIN_JUMP,           bspumpkin_jump_init,           bspumpkin_jump_update,         bspumpkin_jump_end,            func_802B5350},
    {BS_4B_PUMPKIN_FALL,           bspumpkin_fall_init,           bspumpkin_fall_update,         bspumpkin_fall_end,            func_802B5350},
    {BS_4C_LANDING_IN_WATER,       bsbswim_landingInWater_init,   bsbswim_landingInWater_update, bsbswim_landingInWater_end,    func_80296608},
    {BS_4D_PUMPKIN_OW,             __bspumpkin_ow_init,           __bspumpkin_ow_update,         __bspumpkin_ow_end,            func_80296590},
    {BS_4E_PUMPKIN_DIE,            bspumpkin_die_init,            bspumpkin_die_update,          bspumpkin_die_end,             func_80296590},
    {BS_4F_CLIMB_IDLE,             bsclimb_idle_init,             bsclimb_idle_update,           bsclimb_idle_end,              func_802ABD60},
    {BS_50_CLIMB_MOVE,             bsclimb_move_init,             bsclimb_move_update,           bsclimb_move_end,              func_802ABD60},
    {BS_51_CLIMB_EXIT,             bsjump_climbExit_init,         bsjump_climbExit_update,       bsjump_climbExit_end,          func_80296608},
    {BS_52_SURF,                   bssurf_init,                   bssurf_update,                 bssurf_end,                    func_802B60D8},
    {BS_53_TIMEOUT_BANJO,          timeout_banjo_init,            timeout_banjo_update,          timeout_banjo_end,             func_80296590},
    {BS_55_LONGLEG_SLIDE,          bsblongleg_slide_init,         bsblongleg_slide_update,       bsblongleg_slide_end,          func_802B5350},
    {BS_56_RECOIL,                 rebound_init,                  rebound_update,                rebound_end,                   func_80296590},
    {BS_57_BOMB_END,               bsbfly_beakbombend_init,       bsbfly_beakbombend_update,     bsbfly_beakbombend_end,        func_802A505C},
    {BS_58_BEAKBOMB_CRASH,         bsbfly_beakbomb_crash_init,    func_802A48B4,                 func_802A4A40,                 func_80296590},
    {BS_59_BFLY_UNK59,             func_802A4CD0,                 func_802A4CF0,                 func_802A4D10,                 func_802A505C},
    {BS_54_SWIM_DIE,               bsbswim_die_init,              bsbswim_die_update,            bsbswim_die_end,               func_80296590},
    {BS_5B_CARRY_THROW,            bsthrow_init,                  bsthrow_update,                bsthrow_end,                   bsthrow_interrupt},
    {BS_5E_CROC_IDLE,              bscroc_idle_init,              bscroc_idle_update,            bscroc_idle_end,               func_802B5350},
    {BS_5F_CROC_WALK,              bscroc_walk_init,              bscroc_walk_update,            bscroc_walk_end,               func_802B5350},
    {BS_60_CROC_JUMP,              bscroc_jump_init,              bscroc_jump_update,            bscroc_jump_end,               func_802B5350},
    {BS_61_CROC_FALL,              bscroc_fall_init,              bscroc_fall_update,            bscroc_fall_end,               func_802B5350},
    {BS_62_LONGLEG_LOCKED,         bsblongleg_locked_init,        bsblongleg_locked_update,      bsblongleg_locked_end,         func_80296608},
    {BS_63_CROC_OW,                bscroc_ow_init,                bscroc_ow_update,              bscroc_ow_end,                 func_80296590},
    {BS_64_CROC_DIE,               bscroc_die_init,               bscroc_die_update,             bscroc_die_end,                func_80296590},
    {BS_67_WALRUS_IDLE,            bswalrus_idle_init,            bswalrus_idle_update,          bswalrus_idle_end,             func_802B5350},
    {BS_68_WALRUS_WALK,            bswalrus_walk_init,            bswalrus_walk_update,          bswalrus_walk_end,             func_802B5350},
    {BS_69_WALRUS_JUMP,            bswalrus_jump_init,            bswalrus_jump_update,          bswalrus_jump_end,             func_802B5350},
    {BS_6A_WALRUS_FALL,            bswalrus_fall_init,            bswalrus_fall_update,          bswalrus_fall_end,             func_802B5350},
    {BS_6B_BEE_LOCKED,             bsbee_locked_init,             bsbee_locked_update,           bsbee_locked_end,              func_80296608},
    {BS_6C_WALRUS_OW,              bswalrus_ow_init,              bswalrus_ow_update,            bswalrus_ow_end,               func_80296590},
    {BS_6D_WALRUS_DIE,             bswalrus_die_init,             bswalrus_die_update,           bswalrus_die_end,              func_80296590},
    {BS_6E_CROC_BITE,              bscroc_bite_init,              bscroc_bite_update,            bscroc_bite_end,               func_802B5350},
    {BS_6F_CROC_EAT_BAD,           bscroc_eat_bad_init,           bscroc_eat_bad_update,         bscroc_eat_bad_end,            func_802B5350},
    {BS_70_CROC_EAT_GOOD,          bscroc_eat_good_init,          bscroc_eat_good_update,        bscroc_eat_good_end,           func_802B5350},
    {BS_71_BTROT_FALL,             bsbtrot_fall_init,             bsbtrot_fall_update,           bsbtrot_fall_end,              func_80296608},
    {BS_72_SPLAT,                  bssplat_init,                  bssplat_update,                bssplat_end,                   func_80296590},
    {BS_73_UNKNOWN,                bsrest_bs73unknown_init,       bsrest_bs73unknown_update,     bsrest_bs73unknown_end,        func_80296608},
    {BS_74_UNKNOWN,                bsrest_bs74unknown_init,       bsrest_bs74unknown_update,     bsrest_bs74unknown_end,        func_80296608},
    {BS_75_UNKNOWN,                bsrest_bs75unknown_init,       bsrest_bs75unknown_update,     bsrest_bs75unknown_end,        func_80296608},
    {BS_76_BFLY_LOCKED,            bsbfly_locked_init,            bsbfly_locked_update,          bsbfly_locked_end,             func_80296608},
    {BS_77_SWIM_LOOKAT_DRONE,      bsswim_lookat_init,            bsswim_lookat_update,          bsswim_lookat_end,             func_80296608},
    {BS_78_DIVE_LOOKAT_DRONE,      bsbswim_lookat_init,           bsbswim_lookat_update,         bsbswim_lookat_end,            func_80296608},
    {BS_79_BTROT_LOCKED,           bsbtrot_locked_init,           bsbtrot_locked_update,         bsbtrot_locked_end,            func_80296608},
    {BS_7A_WALK_MUD,               bswalk_mud_init,               bswalk_mud_update,             NULL,                          func_80296608},
    {BS_7B_BTROT_OW,               bsbtrot_ow_init,               bsbtrot_ow_update,             bsbtrot_ow_end,                func_80296590},
    {BS_7C_SLED,                   bssled_init,                   bssled_update,                 bssled_end,                    bssled_interrupt},
    {BS_7D_WALRUS_SLED,            bswalrus_sled_init,            bswalrus_sled_update,          bswalrus_sled_end,             func_802B98C0},
    {BS_7E_WALRUS_SLED,            bswalrus_sled_jump_init,       bswalrus_sled_jump_update,     bswalrus_sled_jump_end,        func_802B98C0},
    {BS_7F_DIVE_OW,                bsbswim_ow_init,               bsbswim_ow_update,             bsbswim_ow_end,                func_80296590},
    {BS_80_WALRUS_SLED_LOSE,       bswalrus_timeout_init,         bswalrus_timeout_update,       bswalrus_timeout_end,          func_80296590},
    {BS_81_WALRUS_SLED_LOCKED,     bswalrus_sledlocked_init,      bswalrus_sledlocked_update,    bswalrus_sledlocked_end,       func_802B98C0},
    {BS_82_WALRUS_SLED_LOSE_IN_AIR,bswalrus_sledloseinair_init,   bswalrus_sledloseinair_update, bswalrus_sledloseinair_end,    func_802B98C0},
    {BS_85_BEE_IDLE,               bsbeemain_idle_init,           bsbeemain_idle_update,         bsbeemain_idle_end,            func_802B5350},
    {BS_86_BEE_WALK,               bsbeemain_walk_init,           bsbeemain_walk_update,         bsbeemain_walk_end,            func_802B5350},
    {BS_87_BEE_JUMP,               bsbeemain_jump_init,           bsbeemain_jump_update,         bsbeemain_jump_end,            func_802B5350},
    {BS_88_BEE_FALL,               bsbeemain_fall_init,           bsbeemain_fall_update,         bsbeemain_fall_end,            func_802B5350},
    {BS_89_BEE_OW,                 bsbeemain_ow_init,             bsbeemain_ow_update,           bsbeemain_ow_end,              func_802B5350},
    {BS_8A_BEE_DIE,                bsbeemain_die_init,            bsbeemain_die_update,          bsbeemain_die_end,             func_80296590},
    {BS_8B_UNKNOWN,                bsbeefly_bs8Bunknown_init,     bsbeefly_bs8Bunknown_update,   bsbeefly_bs8Bunknown_end,      func_802B5350},
    {BS_8C_BEE_FLY,                bsbeefly_enter,                bsbeefly_update,               bsbeefly_end,                  func_802B5350},
    {BS_8D_CROC_LOCKED,            bscroc_locked_enter,           bscroc_locked_update,          bscroc_locked_end,             func_802B5350},
    {BS_8E_ANT_LOCKED,             bsant_locked_init,             bsant_locked_update,           bsant_locked_end,              func_802B5350},
    {BS_8F_PUMPKIN_LOCKED,         bspumpkin_locked_init,         bspumpkin_locked_update,       bspumpkin_locked_end,          func_802B5350},
    {BS_91_FLY_OW,                 bsbfly_ow_init,                bsbfly_ow_update,              bsbfly_ow_end,                 func_802A505C},
    {BS_92_ANT_DRONE,              bsant_drone_init,              bsant_drone_update,            bsant_drone_end,               bsdrone_interrupt},
    {BS_93_PUMPKIN_DRONE,          bspumpkin_drone_init,          bspumpkin_drone_update,        bspumpkin_drone_end,           bsdrone_interrupt},
    {BS_94_CROC_DRONE,             bscroc_drone_init,             bscroc_drone_update,           bscroc_drone_end,              bsdrone_interrupt},
    {BS_95_WALRUS_DRONE,           bswalrus_drone_init,           bswalrus_drone_update,         bswalrus_drone_end,            bsdrone_interrupt},
    {BS_96_SWIM_DRONE,             bsswim_drone_init,             bsswim_drone_update,           bsswim_drone_end,              bsdrone_interrupt},
    {BS_97_DIVE_DRONE,             bsbswim_drone_init,            bsbswim_drone_update,          bsbswim_drone_end,             bsdrone_interrupt},
    {BS_98_WALK_DRONE,             bswalk_drone_init,             bswalk_drone_update,           bswalk_drone_end,              bsdrone_interrupt},
    {BS_99_BFLY_DRONE,             bsbfly_drone_init,             bsbfly_drone_update,           bsbfly_drone_end,              bsdrone_interrupt},
    {BS_9A_BTROT_DRONE,            bsbtrot_drone_init,            bsbtrot_drone_update,          bsbtrot_drone_end,             bsdrone_interrupt},
    {BS_9B_LONGLEG_DRONE,          bsblongleg_drone_init,         bsblongleg_drone_update,       bsblongleg_drone_end,          bsdrone_interrupt},
    {BS_9C_WALRUS_SLED_DRONE,      bswalrus_sled_drone_init,      bswalrus_sled_drone_update,    bswalrus_sled_drone_end,       bsdrone_interrupt},
    {BS_9D_BEE_DRONE,              bsbee_drone_init,              bsbee_drone_update,            bsbee_drone_end,               bsdrone_interrupt},
    {BS_9E_CLIMB_LOCKED,           bsclimb_locked_init,           bsclimb_locked_update,         bsclimb_locked_end,            func_802ABD60},
    {BS_9F_ANT_BOUNCE,             bsant_bounce_init,             bsant_bounce_update,           bsant_bounce_end,              func_80296590},
    {BS_A0_ANT_BOUNCE,             bspumpkin_rebound_init,        bspumpkin_rebound_update,      bspumpkin_rebound_end,         func_80296590},
    {BS_A1_CROC_BOUNCE,            bscroc_bounce_init,            bscroc_bounce_update,          bscroc_bounce_end,             func_80296590},
    {BS_A2_WALRUS_BOUNCE,          bswalrus_bounce_init,          bswalrus_bounce_update,        bswalrus_bounce_end,           func_80296590},
    {BS_A3_BEE_BOUNCE,             bsbeemain_bounce_init,         bsbeemain_bounce_update,       bsbeemain_bounce_end,          func_80296590},
    {BS_A4_WONDERWING_DRONE,       bsbwhirl_drone_init,           bsbwhirl_drone_update,         bsbwhirl_drone_end,            func_80296608},
    {BS_A5_WONDERWING_UNKA5,       bsbwhirl_bsA5unknown_init,     bsbwhirl_bsA5unknown_update,   bsbwhirl_bsA5unknown_end,      func_80296608},
    {0}
};

/* .bss */
void (*D_8037C3B0)();

/* .code */
void bsmethods_setMethods(void){
    s32 index;
    bsMap *iPtr;
    
    for(index = 0; bsMethodsTable[index].uid != 0; index++){
        bsList_setInitMethod(bsMethodsTable[index].uid, bsMethodsTable[index].behavior.init_func);
        bsList_setUpdateMethod(bsMethodsTable[index].uid, bsMethodsTable[index].behavior.update_func);
        bsList_setEndMethod(bsMethodsTable[index].uid, bsMethodsTable[index].behavior.end_func);
        bsList_setInterruptMethod(bsMethodsTable[index].uid, bsMethodsTable[index].behavior.interrupt_func);
    }
}

void bsmethods_reset(void){
    D_80363820 = 1;
    D_8037C3B0 = NULL;
    update_void_return_Location();
    playerPosition_init();
    snackerctl_reset();
    func_80291910();
    badrone_init();
    bafalldamage_init();
    baflag_clearAll();
    func_8028B6FC();
    func_80291590();
    bakey_reset();
    bastick_reset();
    bainput_reset();
    bsList_clearAll();
    bs_clearState();
    babounds_init();
    func_80296C30();
    baphysics_init();
    baiFrame_reset();
    pitch_reset();
    climb_clear();
    balookat_init();
    roll_reset();
    func_802992F0();
    func_80294DD8();
    func_8029CF6C();
    modelAppendages_reset();
    func_80290B6C();
    baeyes_reset();
    func_80290070();
    func_80290664();
    stateTimer_init();
    eggShatter_init();
    bacarry_init();
    func_80293DA4();
    baAnim_init();
    baModel_reset();
    baMarker_init();
    basfx_reset();
    func_8029A4D0();
    func_8029ADCC();
    hazards_reset();
    bsmethods_setMethods();
}

void func_80295A8C(void)
{
    stateTimer_set(STATE_TIMER_2_LONGLEG, bsStoredState_getLongLegTimer());
    stateTimer_set(STATE_TIMER_3_TURBO_TALON, bsStoredState_getTurboTimer());
    if(func_8028ADB4())
        bs_setState(badrone_enter());
    else
        bs_setState(bs_getIdleState());

}

void func_80295B04(void){
    f32 longleg_timer;
    enum bs_e current_state = bs_getState();
    bool is_in_talon_trot;
    
    longleg_timer = (bslongleg_inSet(current_state)) ? stateTimer_get(STATE_TIMER_2_LONGLEG) : 0.0f;
    bsStoredState_setLongLegTimer(longleg_timer);
    longleg_timer = 0.0f;
    is_in_talon_trot = FALSE;

    if (bsbtrot_inSet(current_state)) {
        longleg_timer = stateTimer_get(STATE_TIMER_3_TURBO_TALON);
        is_in_talon_trot = TRUE;
    }

    bsStoredState_setTrot(is_in_talon_trot);
    bsStoredState_setTurboTimer(longleg_timer);
    bs_setState(BS_5A_LOADZONE);
    baMarker_free();
    func_8029065C();
    stateTimer_free();
    eggShatter_free();
    baModel_free();
    baAnim_free();
    func_80293E88();
    bacarry_end();
    basfx_free();
    func_8029A54C();
    func_8029ADA8();
    freeHazardSfxId();
    D_80363820 = 0;
}

void func_80295C08(void (* arg0)(void)){
    D_8037C3B0 = arg0;
}

void func_80295C14(void){
    func_802964B8();
    balookat_update();
    stateTimer_update();
    modelAppendages_kazooiesUpperHalfVisibilityTimer();
    pfsManager_update();//controller_update
    disableInput_set();
    bakey_update();
    bastick_update();
    bainput_update(); //dive_cooldown_update
    bs_updateState();
    baphysics_update();
    playerPosition_applyOffset();
    bafalldamage_update();
    func_80293F0C();
    pitch_update();
    roll_update();
    func_802993C8();//yaw update
    func_802906D8();
    baAnim_update();
    func_8029A554();
    climb_regrab_update();
    func_80290108();
    eggShatter_update();
    baeyes_update();
    baModel_update();
    playerPosition_func_8029842C();
    baMarker_update();
    bacarry_update();
    snackerctl_update();
    func_8028B71C();
    hazards_update();
    baiFrame_update();
    func_80294E60();
    cameraMode_update();
    func_802919A0();
    if(D_8037C3B0){
        D_8037C3B0();
        D_8037C3B0 = NULL;
    }
    basfx_update();
    babounds_update();//voidOut_update
}

void func_80295D74(void){
    if(D_80363820){
        baAnim_defrag();
        baModel_defrag();
        eggShatter_defrag();
        func_80294750();
        func_8029AF1C();
    }
}
