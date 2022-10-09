#ifndef ENUMS_H
#define ENUMS_H

#define SPRITE_TYPE_CI4 (1 << 0)
#define SPRITE_TYPE_CI8 (1 << 2)
#define SPRITE_TYPE_I4 (1 << 5)
#define SPRITE_TYPE_I8 (1 << 6)
#define SPRITE_TYPE_IA4 (1 << 7)
#define SPRITE_TYPE_IA8 (1 << 8)
#define SPRITE_TYPE_UNKNOWN_200 (1 << 9)
#define SPRITE_TYPE_RGBA16 (1 << 10)
#define SPRITE_TYPE_RGBA32 (1 << 11)

enum bkprog_e{
    
    // BKPROG_03_ "1st Note Text"}, -- 0x00 > 3
	// BKPROG_04_ "1st Mumbo Token Text"}, -- 0x00 > 4
	// BKPROG_05_ "1st Egg Text"}, -- 0x00 > 5
	// BKPROG_06_ "1st Red Feather Text"}, -- 0x00 > 6
	// BKPROG_07_ "1st Gold Feather Text"}, -- 0x00 > 7
	// BKPROG_08_ "1st Gold Bullion Text"}, -- 0x01 > 1 (flipped, but only for this byte, no idea why)
	// BKPROG_09_ "1st Orange Text"}, -- 0x01 > 0 (flipped, but only for this byte, no idea why)
	// BKPROG_0A_ "1st Honeycomb Text"}, -- 0x01 > 2
	// BKPROG_0B_ "1st Empty Honeycomb Text"}, -- 0x01 > 3
	// BKPROG_0C_ "1st Extra Life Text"},
	// BKPROG_0D_ "1st Beehive Text"},
    BKPROG_D_BEEHIVE_TEXT = 0xD,
	BKPROG_E_JINJO_TEXT,
    BKPROG_F_HAS_TOUCHED_PIRAHANA_WATER,
	BKPROG_10_HAS_TOUCHED_SAND_EEL_SAND,
    BKPROG_11_HAS_MET_MUMBO, 
    BKPROG_12_HAS_TRANSFORMED_BEFORE,
    BKPROG_13, //something with xmas tree jiggy progress
    BKPROG_14_HAS_TOUCHED_FP_ICY_WATER,
    BKPROG_15_ENTER_MMM_TEXT,
	// {index=0x16, type="Prog", level=6, name="1st Time in Jigsaw Text"},
	// {index=0x17, type="Prog", level=6, name="1st Time Enough Pieces Jigsaw Text"},
	BKPROG_18_MM_WITCH_SWITCH_JIGGY_SPAWNED = 0x18,
	BKPROG_19_MMM_WITCH_SWITCH_JIGGY_SPAWNED,
	BKPROG_1A_TTC_WITCH_SWITCH_JIGGY_SPAWNED,
	BKPROG_1B_CC_WITCH_SWITCH_JIGGY_SPAWNED,
	BKPROG_1C_RBB_WITCH_SWITCH_JIGGY_SPAWNED,
	BKPROG_1D_MMM_DINNING_ROOM_CUTSCENE,
	// {index=0x1E, type="Prog", level=6, name="Grate to BGS Puzzle Open"},
	BKPROG_1F_CC_LOBBY_PIPE_1_RAISED = 0x1F,
    BKPROG_20_CC_LOBBY_PIPE_2_RAISED,
    BKPROG_21_CC_LOBBY_PIPE_3_RAISED,
    BKPROG_22_WATER_SWITCH_1_PRESSED,
    BKPROG_23_LAIR_WATER_LEVEL_1,
    BKPROG_24_WATER_SWITCH_2_PRESSED,
    BKPROG_25_LAIR_WATER_LEVEL_2 = 0x25,
    BKPROG_26_WATER_SWITCH_3_PRESSED,
    BKPROG_27_LAIR_WATER_LEVEL_3 = 0x27,

	BKPROG_31_MM_OPEN = 0x31,
	BKPROG_32_TTC_OPEN,
	BKPROG_33_CC_OPEN,
	BKPROG_34_BGS_OPEN,
	BKPROG_35_FP_OPEN,
	BKPROG_36_GV_OPEN,
	BKPROG_37_MMM_OPEN,
	BKPROG_38_RBB_OPEN,
	BKPROG_39_CCW_OPEN,
	BKPROG_3A_NOTE_DOOR_50_OPEN,
	BKPROG_3B_NOTE_DOOR_180_OPEN,
	BKPROG_3C_NOTE_DOOR_260_OPEN,
	BKPROG_3D_NOTE_DOOR_350_OPEN,
	BKPROG_3E_NOTE_DOOR_450_OPEN,
	BKPROG_3F_NOTE_DOOR_640_OPEN,
	BKPROG_40_NOTE_DOOR_765_OPEN,
	BKPROG_41_NOTE_DOOR_810_OPEN,
	BKPROG_42_NOTE_DOOR_828_OPEN,
	BKPROG_43_NOTE_DOOR_846_OPEN,
	BKPROG_44_NOTE_DOOR_864_OPEN,
	BKPROG_45_NOTE_DOOR_882_OPEN,
	BKPROG_46_CCW_WITCH_SWITCH_JIGGY_SPAWNED,

	// {index=0x48, type="Prog", level=6, name="FP WS Advent Door Open"},
	// {index=0x49, type="Prog", level=6, name="Pink Cauldron 1 Active"},
	// {index=0x4A, type="Prog", level=6, name="Pink Cauldron 2 Active"},
	// {index=0x4B, type="Prog", level=6, name="Green Cauldron 1 Active"},
	// {index=0x4C, type="Prog", level=6, name="Green Cauldron 2 Active"},
	// {index=0x4D, type="Prog", level=6, name="Red Cauldron 1 Active"},
	// {index=0x4E, type="Prog", level=6, name="Red Cauldron 2 Active"},
	// -- 0x4F - Unused Cauldron Pair?
	// -- 0x50 - Unused Cauldron Pair?
	// {index=0x51, type="Prog", level=6, name="Yellow Cauldron 1 Active"},
	// {index=0x52, type="Prog", level=6, name="Yellow Cauldron 2 Active"},
	// {index=0x53, type="Prog", level=6, name="CCW Puzzle Podium Switch Pressed"},
	// {index=0x54, type="Prog", level=6, name="CCW Puzzle Podium Active"},
	// {index=0x55, type="Prog", level=6, name="1st FF BK Square Text"},
	// {index=0x56, type="Prog", level=6, name="1st FF Pic Square Text"},
	// {index=0x57, type="Prog", level=6, name="1st FF Music Square Text"},
	// {index=0x58, type="Prog", level=6, name="1st FF Mini-Game Square Text"},
	// {index=0x59, type="Prog", level=6, name="1st FF Grunty Square Text"},
	// {index=0x5A, type="Prog", level=6, name="1st FF Death Square Text"},
	// {index=0x5B, type="Prog", level=6, name="1st FF Joker Square Text"},

	// {index=0x5C, type="Prog", level=6, name="??FF Pattern Set"},

	// -- Pieces places in puzzles info
	// -- TODO: Read/write these as ints?
	// {index=0x5D, type="Prog", level=6, name="Puzzle: # Pieces in MM Puzzle (2^0)"},
	// {index=0x5E, type="Prog", level=6, name="Puzzle: # Pieces in TTC Puzzle (2^0)"},
	// {index=0x5F, type="Prog", level=6, name="Puzzle: # Pieces in TTC Puzzle (2^1)"},
	// {index=0x60, type="Prog", level=6, name="Puzzle: # Pieces in CC Puzzle (2^0)"},
	// {index=0x61, type="Prog", level=6, name="Puzzle: # Pieces in CC Puzzle (2^1)"},
	// {index=0x62, type="Prog", level=6, name="Puzzle: # Pieces in CC Puzzle (2^2)"},
	// {index=0x63, type="Prog", level=6, name="Puzzle: # Pieces in BGS Puzzle (2^0)"},
	// {index=0x64, type="Prog", level=6, name="Puzzle: # Pieces in BGS Puzzle (2^1)"},
	// {index=0x65, type="Prog", level=6, name="Puzzle: # Pieces in BGS Puzzle (2^2)"},
	// {index=0x66, type="Prog", level=6, name="Puzzle: # Pieces in FP Puzzle (2^0)"},
	// {index=0x67, type="Prog", level=6, name="Puzzle: # Pieces in FP Puzzle (2^1)"},
	// {index=0x68, type="Prog", level=6, name="Puzzle: # Pieces in FP Puzzle (2^2)"},
	// {index=0x69, type="Prog", level=6, name="Puzzle: # Pieces in FP Puzzle (2^3)"},
	// {index=0x6A, type="Prog", level=6, name="Puzzle: # Pieces in GV Puzzle (2^0)"},
	// {index=0x6B, type="Prog", level=6, name="Puzzle: # Pieces in GV Puzzle (2^1)"},
	// {index=0x6C, type="Prog", level=6, name="Puzzle: # Pieces in GV Puzzle (2^2)"},
	// {index=0x6D, type="Prog", level=6, name="Puzzle: # Pieces in GV Puzzle (2^3)"},
	// {index=0x6E, type="Prog", level=6, name="Puzzle: # Pieces in MMM Puzzle (2^0)"},
	// {index=0x6F, type="Prog", level=6, name="Puzzle: # Pieces in MMM Puzzle (2^1)"},
	// {index=0x70, type="Prog", level=6, name="Puzzle: # Pieces in MMM Puzzle (2^2)"},
	// {index=0x71, type="Prog", level=6, name="Puzzle: # Pieces in MMM Puzzle (2^3)"},
	// {index=0x72, type="Prog", level=6, name="Puzzle: # Pieces in RBB Puzzle (2^0)"},
	// {index=0x73, type="Prog", level=6, name="Puzzle: # Pieces in RBB Puzzle (2^1)"},
	// {index=0x74, type="Prog", level=6, name="Puzzle: # Pieces in RBB Puzzle (2^2)"},
	// {index=0x75, type="Prog", level=6, name="Puzzle: # Pieces in RBB Puzzle (2^3)"},
	// {index=0x76, type="Prog", level=6, name="Puzzle: # Pieces in CCW Puzzle (2^0)"},
	// {index=0x77, type="Prog", level=6, name="Puzzle: # Pieces in CCW Puzzle (2^1)"},
	// {index=0x78, type="Prog", level=6, name="Puzzle: # Pieces in CCW Puzzle (2^2)"},
	// {index=0x79, type="Prog", level=6, name="Puzzle: # Pieces in CCW Puzzle (2^3)"},
	// {index=0x7A, type="Prog", level=6, name="Puzzle: # Pieces in DoG Puzzle (2^0)"},
	// {index=0x7B, type="Prog", level=6, name="Puzzle: # Pieces in DoG Puzzle (2^1)"},
	// {index=0x7C, type="Prog", level=6, name="Puzzle: # Pieces in DoG Puzzle (2^2)"},
	// {index=0x7D, type="Prog", level=6, name="Puzzle: # Pieces in DoG Puzzle (2^3)"},
	// {index=0x7E, type="Prog", level=6, name="Puzzle: # Pieces in DoG Puzzle (2^4)"},
	// {index=0x7F, type="Prog", level=6, name="Puzzle: # Pieces in Double Health Puzzle (2^0)"},
	// {index=0x80, type="Prog", level=6, name="Puzzle: # Pieces in Double Health Puzzle (2^1)"},
	// {index=0x81, type="Prog", level=6, name="Puzzle: # Pieces in Double Health Puzzle (2^2)"},

    BKPROG_83_MAGIC_GET_WEAK_TEXT = 0x83,
    BKPROG_84_MAGIC_ALL_GONE_TEXT,
	// {index=0x85, type="Prog", level=6, name="Lair Crypt Gate Open"},
    BKPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE = 0x86,

    BKPROG_88_TRIED_LOGGO_AS_BEAR = 0x88,
    BKPROG_89_ENTERED_LOGGO_AS_PUMPKIN,
    BKPROG_8A_EXITED_LOGGO,

	// {index=0x8B, type="Prog", level=8, name="CCW Spring Open"},
	// {index=0x8C, type="Prog", level=8, name="CCW Summer Open"},
	// {index=0x8D, type="Prog", level=8, name="CCW Autumn Open"},
	// {index=0x8E, type="Prog", level=8, name="CCW Winter Open"},
	// {index=0x8F, type="Prog", level=8, name="Mumbo's Magic Getting Weak Text"},
    BKPROG_90_PAID_TERMITE_COST = 0x90,
    BKPROG_91_PAID_PUMPKIN_COST,
    BKPROG_92_PAID_WALRUS_COST,
    BKPROG_93_PAID_CROC_COST,
    BKPROG_94_PAID_BEE_COST,

	// {index=0x96, type="Prog", level=6, name="1st Time Brentilda Text"},
	BKPROG_97_ENTERED_LAIR_TEXT = 0x97,
	BKPROG_98_EXITED_LEVEL_TEXT,
    BKPROG_99_PAST_50_NOTE_DOOR_TEXT,
	// {index=0x99, type="Prog", level=6, name="1st Time Past 50 ND Text"},

	// {index=0x9B, type="Prog", level=6, name="CC WS Eyes Active"},
	BKPROG_9C_LAIR_CC_WITCH_SWITCH_LEFT_EYE_PRESSED = 0x9C,
	BKPROG_9D_LAIR_CC_WITCH_SWITCH_RIGHT_EYE_PRESSED = 0x9D,
    BKPROG_9E_CRYPT_COFFIN_LID_OPEN = 0x9E,

    BKPROG_A1_STATUE_HAT_OPEN = 0xA1,
    BKPROG_A2_GV_LOBBY_COFFIN_OPEN,
    BKPROG_A3_UNKOWN, //tied to actor_244/marker_23B
    BKPROG_A4_UNKOWN, //tied to actor_244/marker_23B

    BKPROG_A6_FURNACE_FUN_COMPLETE = 0xA6,
    BKPROG_A7_NEAR_PUZZLE_PODIUM_TEXT,
    BKPROG_A8_HAS_DIED,
    BKPROG_A9_HAS_TOUCHED_RBB_OVEN,
    BKPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD,
	// {index=0xAA, type="Prog", level=8, name="1st CCW Bramble Field Text"},
	// {index=0xAB, type="Prog", level=9, name="Oily Water Surface Text"},
	// {index=0xAC, type="Prog", level=9, name="Oily Water Underwater Text"},
	// {index=0xAD, type="Prog", level=6, name="Cheato: BLUEEGGS Unlocked"},
	// {index=0xAE, type="Prog", level=6, name="Cheato: REDFEATHERS Unlocked"},
	// {index=0xAF, type="Prog", level=6, name="Cheato: GOLDFEATHERS Unlocked"},
    BKPROG_B0_HAS_ENTERED_MM = 0xb0,
	BKPROG_B1_HAS_ENTERED_BGS,
	BKPROG_B2_HAS_ENTERED_TTC,
	BKPROG_B3_HAS_ENTERED_GV,
	BKPROG_B4_HAS_ENTERED_RBB,
	BKPROG_B5_HAS_ENTERED_CCW,
	BKPROG_B6_HAS_ENTERED_FP,
	BKPROG_B7_HAS_ENTERED_MMM,
	BKPROG_B8_HAS_ENTERED_CC,
	BKPROG_B9_DOUBLE_HEALTH,
	// {index=0xBA, type="Prog", level=6, name="1st Time T. Rex"},
    BK_PROG_BB_MUMBO_MISTAKE_INDEX = 0xBB, //2 bits
    // BK_PROG_BC_MUMBO_MISTAKE_INDEX = 0xBC, //2 bits
	BKPROG_BD_ENTER_LAIR_CUTSCENE =  0xBD,
    BKPROG_BE_CHEATO_BLUEEGGS,
    BKPROG_BF_CHEATO_REDFEATHERS,
    BKPROG_C0_CHEATO_GOLDFEATHERS,

    BKPROG_C2_GRATE_TO_RBB_PUZZLE_OPEN = 0xc2,
    BKPROG_C3_ICE_BALL_TO_CHEATO_BROKEN,
    BKPROG_C4_STATUE_EYE_BROKEN,
    BKPROG_C5_RAREWARE_BOX_BROKEN,
	// {index=0xC6, type="Prog", level=6, name="Jump Pad Switch Pressed"},
	// {index=0xC7, type="Prog", level=6, name="Jump Pad Active"},
	// {index=0xC8, type="Prog", level=6, name="Wall to Wading Boots Broken"},
	// {index=0xC9, type="Prog", level=6, name="Wall to Jump Pad Switch Broken"},
	// {index=0xCA, type="Prog", level=6, name="Cobweb to Purple Cauldron Broken"},
	// {index=0xCB, type="Prog", level=6, name="Cobweb to Flight Pad Broken"},
	// {index=0xCC, type="Prog", level=6, name="Cobweb to Green Cauldron Broken"},
	BKPROG_CD_GRATE_TO_WATER_SWITCH_3_OPEN = 0xcd,
    BKPROG_CE_GRATE_TO_MMM_PUZZLE_OPEN,
    BKPROG_CF_HAS_ENTERED_FINAL_FIGHT,
    
    BKPROG_D1_HAS_ACTIVATED_A_JINJO_STATUE_IN_FINAL_FIGHT = 0xD1,
    BKPROG_D2_HAS_SPAWNED_A_JINJO_STATUE_IN_FINAL_FIGHT,
	// {index=0xD3, type="Prog", level=6, name="??FF PATTERN 2^0"},
	// {index=0xD4, type="Prog", level=6, name="??FF PATTERN 2^1"},
	// {index=0xD5, type="Prog", level=6, name="??FF PATTERN 2^2"},
	// {index=0xD6, type="Prog", level=6, name="??FF PATTERN 2^3"},
	// {index=0xD7, type="Prog", level=6, name="??FF PATTERN 2^4"},
	// {index=0xD8, type="Prog", level=6, name="??FF PATTERN 2^5"},
	// {index=0xD9, type="Prog", level=6, name="??FF PATTERN 2^6"},
	// {index=0xDA, type="Prog", level=6, name="??FF PATTERN 2^7"},

    BKPROG_DC_HAS_HAD_ENOUGH_TOKENS_BEFORE = 0xDC,
	// {index=0xDD, type="Prog", level=8, name="1st CCW Icy Water Text"},

	// {index=0xDF, type="Prog", level=6, name="Remove Puzzle Piece Text"},
	// {index=0xE0, type="Prog", level=6, name="Place All Puzzle Pieces Text"},

	// {index=0xE2, type="Prog", level=6, name="DoG Open"},
	// {index=0xE3, type="Prog", level=8, name="CCW Flower Spring"},
	// {index=0xE4, type="Prog", level=8, name="CCW Flower Summer"},
	// {index=0xE5, type="Prog", level=8, name="CCW Flower Autumn"},
    BKPROG_E6_SPRING_EYRIE_HATCHED = 0xE6,
    BKPROG_E7_SUMMER_EYRIE_FED,
	// {index=0xE7, type="Prog", level=8, name="Summer Eyrie Fed"},
	// {index=0xE8, type="Prog", level=8, name="Autumn Eyrie Fed"},

	// {index=0xF3, type="Prog", level=6, name="Talked to Dingpot"},
    BKPROG_F4_ENTER_FF_CUTSCENE = 0xF4,
	// {index=0xF4, type="Prog", level=6, name="1st Time FF Cutscene"},

	// {index=0xF6, type="Prog", level=6, name="1st Time Near DoG Puzzle Podium"},
	// {index=0xF7, type="Prog", level=10, name="Pumpkin Making Mumbo Hungry Text"},
    BKPROG_F7_HAS_TRANSFORMED_IN_CRYPT = 0xF7,
	BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE = 0xF8, //2bit
	// BKPROG_F8_KING_SANDYBUTT_PYRAMID_STATE = 0xF9, //2bit

	BKPROG_FC_DEFEAT_GRUNTY = 0xFC
};

enum unkflags_1{
    UNKFLAGS1_1F_IN_CHARACTER_PARADE = 0x1F,
    UNKFLAGS1_20_BEGIN_CHARACTER_PARADE,

    UNKFLAGS1_73_SANDCASTLE_INFINITE_LIVES = 0x73,
    UNKFLAGS1_74_SANDCASTLE_INFINITE_EGGS,
    UNKFLAGS1_75_SANDCASTLE_INFINITE_RED_FEATHERS,
    UNKFLAGS1_76_SANDCASTLE_INFINITE_GOLD_FEATHERS,

    UNKFLAGS1_78_SANDCASTLE_NO_BONUS = 0x78,

    UNKFLAGS1_7F_SANDCASTLE_OPEN_CC = 0x7F,

    UNKFLAGS1_86_SANDCASTLE_SHOCKSPRING_JUMP_UNLOCKED = 0x86,
    UNKFLAGS1_87_SANDCASTLE_OPEN_GV,//	0X87

    UNKFLAGS1_8A_SANDCASTLE_FLIGHT_UNLOCKED = 0x8A,//	0X8A
    UNKFLAGS1_8B_SANDCASTLE_OPEN_FP,//	0X8B
    UNKFLAGS1_8C_SANDCASTLE_OPEN_MMM,//	0X8C
    UNKFLAGS1_8D_SANDCASTLE_REMOVE_CRYPT_GATE,//	0X8D
    UNKFLAGS1_8E_SANDCASTLE_REMOVE_CRYPT_COFFIN_LID,//	0X8E
    UNKFLAGS1_8F_SANDCASTLE_REMOVE_GRATE_NEAR_WATER_SWITCH,//	0X8F
    UNKFLAGS1_90_SANDCASTLE_OPEN_RBB,

    UNKFLAGS1_93_SANDCASTLE_OPEN_CCW = 0x93,
    UNKFLAGS1_94_SANDCASTLE_INFINITE_HEALTH,//	0X94
    UNKFLAGS1_95_SANDCASTLE_INFINTE_MUMBO_TOKENS,//	0X95
    UNKFLAGS1_96_SANDCASTLE_INFINITE_AIR,//	0X96
    UNKFLAGS1_97_SANDCASTLE_BOTTLES_BONUS_1,//	0X97
    UNKFLAGS1_98_SANDCASTLE_BOTTLES_BONUS_2,//	0X98
    UNKFLAGS1_99_SANDCASTLE_BOTTLES_BONUS_3,//	0X99
    UNKFLAGS1_9A_SANDCASTLE_BOTTLES_BONUS_4,//	0X9A
    UNKFLAGS1_9B_SANDCASTLE_BOTTLES_BONUS_5,//	0X9B
    UNKFLAGS1_9C_SANDCASTLE_BOTTLES_BONUS_6,//	0X9C
    UNKFLAGS1_9D_SANDCASTLE_WISHY_WASHY,//	0X9D

    UNKFLAGS1_C0_BEGIN_FINAL_CHARACTER_PARADE = 0xC0,
    UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE
};

enum level_flags_e
{
    LEVEL_FLAG_0_CC_TOKEN_TOOTH_OPEN = 0,
    LEVEL_FLAG_1_CC_JIGGY_TOOTH_OPEN = 1
};

enum transformation_e
{
    unknown,
    TRANSFORM_1_BANJO,
    TRANSFORM_2_TERMITE,
    TRANSFORM_3_PUMPKIN,
    TRANSFORM_4_WALRUS,
    TRANSFORM_5_CROC,
    TRANSFORM_6_BEE,
    TRANSFORM_7_WISHWASHY
};

enum ability_e
{
    ABILITY_0_BARGE = 0x0,
    ABILITY_1_BEAK_BOMB = 0x1,
    ABILITY_2_BEAK_BUSTER = 0x2,
    ABILITY_3_CAMERA_CONTROL = 0x3,
    ABILITY_4_BEAR_PUNCH = 0x4,
    ABILITY_5_CLIMB = 0x5,
    ABILITY_6_EGGS = 0x6,
    ABILITY_7_FLAP = 0x7,
    ABILITY_8_FLIP = 0x8,
    ABILITY_9_FLY = 0x9, 
    ABILITY_A_HOLD_A_JUMP_HIGHER = 0xA,
    ABILITY_B_RATATAT_RAP = 0xB,
    ABILITY_C_ROLL = 0xC,
    ABILITY_D_SHOCK_JUMP = 0xD,
    ABILITY_E_WADING_BOOTS = 0xE,
    ABILITY_F_DIVE = 0xF,
    ABILITY_10_TALON_TROT = 0x10,
    ABILITY_11_TURBO_TALON = 0x11,
    ABILITY_12_WONDERWING = 0x12,
    ABILITY_13_1ST_NOTEDOOR = 0x13
};

enum button_e{
    BUTTON_START = 0x0,
    BUTTON_Z = 0x1,
    BUTTON_L = 0x2,
    BUTTON_R = 0x3,
    BUTTON_D_UP = 0x4, 
    BUTTON_D_DOWN = 0x5, 
    BUTTON_D_LEFT = 0x6,
    BUTTON_D_RIGHT = 0x7,
    BUTTON_A = 0x8,
    BUTTON_B = 0x9,
    BUTTON_C_LEFT = 0xA,
    BUTTON_C_DOWN = 0xB,
    BUTTON_C_UP = 0xC,
    BUTTON_C_RIGHT = 0xD
};

#define FACE_BUTTON(button) (button - BUTTON_A)

enum joystick_e{
    JOYSTICK_X = 0x0,
    JOYSTICK_Y = 0x1
};

enum map_e
{
    MAP_1_SM_SPIRAL_MOUNTAIN = 0x01,
    MAP_2_MM_MUMBOS_MOUNTAIN,
    MAP_3_UNUSED,
    MAP_4_UNUSED,
    MAP_5_TTC_BLUBBERS_SHIP,
    MAP_6_TTC_NIPPERS_SHELL,
    MAP_7_TTC_TREASURE_TROVE_COVE,
    // Unused
    // Unused
    MAP_A_TTC_SANDCASTLE = 0x0A,
    MAP_B_CC_CLANKERS_CAVERN,
    MAP_C_MM_TICKERS_TOWER = 0x0C,
    MAP_D_BGS_BUBBLEGLOOP_SWAMP,
    MAP_E_MM_MUMBOS_SKULL,
    // Unused
    MAP_10_BGS_MR_VILE = 0x10,
    MAP_11_BGS_TIPTUP,
    MAP_12_GV_GOBIS_VALLEY,
    MAP_13_GV_MEMORY_GAME,
    MAP_14_GV_SANDYBUTTS_MAZE,
    MAP_15_GV_WATER_PYRAMID,
    MAP_16_GV_RUBEES_CHAMBER,
    // Unused
    // Unused
    // Unused
    MAP_1A_GV_INSIDE_JINXY = 0x1A,
    MAP_1B_MMM_MAD_MONSTER_MANSION = 0x1B,
    MAP_1C_MMM_CHURCH = 0x1C,
    MAP_1D_MMM_CELLAR = 0x1D,
    MAP_1E_CS_START_NINTENDO = 0x1E,
    MAP_1F_CS_START_RAREWARE = 0x1F,
    MAP_20_CS_END_NOT_100,
    MAP_21_CC_WITCH_SWITCH_ROOM,
    MAP_22_CC_INSIDE_CLANKER,
    MAP_23_CC_GOLDFEATHER_ROOM,
    MAP_24_MMM_TUMBLARS_SHED,
    MAP_25_MMM_WELL,
    MAP_26_MMM_NAPPERS_ROOM,
    MAP_27_FP_FREEZEEZY_PEAK,
    MAP_28_MMM_EGG_ROOM = 0x28,
    MAP_29_MMM_NOTE_ROOM = 0x29,
    MAP_2A_MMM_FEATHER_ROOM = 0x2A,
    MAP_2B_MMM_SECRET_CHURCH_ROOM = 0x2B,
    MAP_2C_MMM_BATHROOM = 0x2C,
    MAP_2D_MMM_BEDROOM = 0x2D,
    MAP_2E_MMM_HONEYCOMB_ROOM = 0x2E,
    MAP_2F_MMM_WATERDRAIN_BARREL = 0x2F,
    MAP_30_MMM_MUMBOS_SKULL = 0x30,
    MAP_31_RBB_RUSTY_BUCKET_BAY = 0x31,
    MAP_32_UNUSED,
    MAP_33_UNUSED,
    MAP_34_RBB_ENGINE_ROOM,
    MAP_35_RBB_WAREHOUSE,
    MAP_36_RBB_BOATHOUSE,
    MAP_37_RBB_CONTAINER_1,
    MAP_38_RBB_CONTAINER_3,
    MAP_39_RBB_CREW_CABIN,
    MAP_3A_RBB_BOSS_BOOM_BOX,
    MAP_3B_RBB_STORAGE_ROOM,
    MAP_3C_RBB_KITCHEN,
    MAP_3D_RBB_NAVIGATION_ROOM,
    MAP_3E_RBB_CONTAINER_2,
    MAP_3F_RBB_CAPTAINS_CABIN,
    MAP_40_CCW_HUB,
    MAP_41_FP_BOGGYS_IGLOO,
    // Unused
    MAP_43_CCW_SPRING = 0x43,
    MAP_44_CCW_SUMMER = 0x44,
    MAP_45_CCW_AUTUMN = 0x45,
    MAP_46_CCW_WINTER = 0x46,
    MAP_47_BGS_MUMBOS_SKULL = 0x47,
    MAP_48_FP_MUMBOS_SKULL = 0x48,
    // Unused
    MAP_4A_CCW_SPRING_MUMBOS_SKULL = 0x4A,
    MAP_4B_CCW_SUMMER_MUMBOS_SKULL = 0x4B,
    MAP_4C_CCW_AUTUMN_MUMBOS_SKULL = 0x4C,
    MAP_4D_CCW_WINTER_MUMBOS_SKULL = 0x4D,
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    MAP_53_FP_CHRISTMAS_TREE = 0x53,
    MAP_54_UNUSED,
    MAP_55_UNUSED,
    MAP_56_UNUSED,
    MAP_57_UNUSED,
    MAP_58_UNUSED,
    MAP_59_UNUSED,
    MAP_5A_CCW_SUMMER_ZUBBA_HIVE = 0x5A, // Summer & Spring are swapped here
    MAP_5B_CCW_SPRING_ZUBBA_HIVE,
    MAP_5C_CCW_AUTUMN_ZUBBA_HIVE,
    // Unused
    MAP_5E_CCW_SPRING_NABNUTS_HOUSE = 0x5E,
    MAP_5F_CCW_SUMMER_NABNUTS_HOUSE = 0x5F,
    MAP_60_CCW_AUTUMN_NABNUTS_HOUSE = 0x60,
    MAP_61_CCW_WINTER_NABNUTS_HOUSE = 0x61,
    MAP_62_CCW_WINTER_HONEYCOMB_ROOM = 0x62,
    MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY = 0x63,
    MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY = 0x64,
    MAP_65_CCW_SPRING_WHIPCRACK_ROOM = 0x65,
    MAP_66_CCW_SUMMER_WHIPCRACK_ROOM = 0x66,
    MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM = 0x67,
    MAP_68_CCW_WINTER_WHIPCRACK_ROOM = 0x68,
    MAP_69_GL_MM_LOBBY = 0x69,
    MAP_6A_GL_TTC_AND_CC_PUZZLE = 0x6A,
    MAP_6B_GL_180_NOTE_DOOR = 0x6B,
    MAP_6C_GL_RED_CAULDRON_ROOM = 0x6C,
    MAP_6D_GL_TTC_LOBBY = 0x6D,
    MAP_6E_GL_GV_LOBBY = 0x6E,
    MAP_6F_GL_FP_LOBBY = 0x6F,
    MAP_70_GL_CC_LOBBY = 0x70,
    MAP_71_GL_STATUE_ROOM,
    MAP_72_GL_BGS_LOBBY,
    // Unused
    MAP_74_GL_GV_PUZZLE = 0x74,
    MAP_75_GL_MMM_LOBBY,
    MAP_76_GL_640_NOTE_DOOR,
    MAP_77_GL_RBB_LOBBY,
    MAP_78_GL_RBB_AND_MMM_PUZZLE,
    MAP_79_GL_CCW_LOBBY,
    MAP_7A_GL_CRYPT,
    MAP_7B_CS_INTRO_GL_DINGPOT_1,
    MAP_7C_CS_INTRO_BANJOS_HOUSE_1,
    MAP_7D_CS_SPIRAL_MOUNTAIN_1,
    MAP_7E_CS_SPIRAL_MOUNTAIN_2,
    MAP_7F_FP_WOZZAS_CAVE,
    MAP_80_GL_FF_ENTRANCE,
    MAP_81_CS_INTRO_GL_DINGPOT_2,
    MAP_82_CS_ENTERING_GL_MACHINE_ROOM,
    MAP_83_CS_GAME_OVER_MACHINE_ROOM,
    MAP_84_CS_UNUSED_MACHINE_ROOM, // Klungo walks to the Controltable
    MAP_85_CS_SPIRAL_MOUNTAIN_3,
    MAP_86_CS_SPIRAL_MOUNTAIN_4,
    MAP_87_CS_SPIRAL_MOUNTAIN_5,
    MAP_88_CS_SPIRAL_MOUNTAIN_6,
    MAP_89_CS_INTRO_BANJOS_HOUSE_2,
    MAP_8A_CS_INTRO_BANJOS_HOUSE_3,
    MAP_8B_RBB_ANCHOR_ROOM,
    MAP_8C_SM_BANJOS_HOUSE,
    MAP_8D_MMM_INSIDE_LOGGO,
    MAP_8E_GL_FURNACE_FUN,
    MAP_8F_TTC_SHARKFOOD_ISLAND,
    MAP_90_GL_BATTLEMENTS,
    MAP_91_FILE_SELECT,
    MAP_92_GV_SNS_CHAMBER,
    MAP_93_GL_DINGPOT,
    MAP_94_CS_INTRO_SPIRAL_7,
    MAP_95_CS_END_ALL_100,
    MAP_96_CS_END_BEACH_1,
    MAP_97_CS_END_BEACH_2,
    MAP_98_CS_END_SPIRAL_MOUNTAIN_1,
    MAP_99_CS_END_SPIRAL_MOUNTAIN_2
};


enum comusic_e
{
    COMUSIC_0_DING_A = 0x00,
    COMUSIC_1_FINAL_BATTLE,
    COMUSIC_2_MM,
    COMUSIC_3_FP_TWINKLIES_TALKING,
    COMUSIC_4_MMM_CLOCK_VERSION,
    COMUSIC_5_TTC_VACATION_VERSION,
    COMUSIC_6_BGS,
    COMUSIC_7_CC_MUTANT_CRABS,
    COMUSIC_8_STARTUP_MUSICAL,
    COMUSIC_9_NOTE_COLLECTED,
    COMUSIC_A_JINJO_COLLECTED,
    COMUSIC_B_RED_FEATHER_COLLECTED,
    COMUSIC_C_EGG_COLLECTED,
    COMUSIC_D_JINGLE_JIGGY_COLLECTED,
    COMUSIC_E_MMM_BACKGROUND_WIND,
    COMUSIC_F_MMM_ALTERNATIVE,
    COMUSIC_10_SM,
    COMUSIC_11_SEAGULLS,
    COMUSIC_12_TTC_NIPPER,
    COMUSIC_13_INSIDE_SANDCASTLE,
    COMUSIC_14_GOLD_FEATHER_COLLECTED,
    COMUSIC_15_EXTRA_LIFE_COLLECTED,
    COMUSIC_16_HONEYCOMB_COLLECTED,
    COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED,
    COMUSIC_18_HEALTH_UPGRADE,
    COMUSIC_19_LOW_PITCH_FLUTES,
    COMUSIC_1A_DEATH,
    COMUSIC_1B_MYSTERIOUS_INDOORS,
    COMUSIC_1C_CC_ALTERNATIVE,
    COMUSIC_1D_MUMBO_TRANSFORMATION,
    COMUSIC_1E_GL_MM_VERSION,
    COMUSIC_1F_CC_INSIDE_CLANKER,
    COMUSIC_20_GV_ALTERNATIVE,
    COMUSIC_21_MMM_INSIDE_MMM_MANSION,
    COMUSIC_22_MMM,
    COMUSIC_23_MMM_INSIDE_CHURCH,
    COMUSIC_24_GV_INSIDE_PYRAMID,
    COMUSIC_25_USING_GOLD_FEATHERS,
    COMUSIC_26_GV_SANDYBUTT_DANGER,
    COMUSIC_27_GV_RUBEES_SONG,
    COMUSIC_28_SOMETHING_AQUATIC,
    COMUSIC_29_CCW_SUMMER,
    COMUSIC_2A_CCW_WINTER,
    COMUSIC_2B_DING_B,
    COMUSIC_2C_BUZZER,
    COMUSIC_2D_PUZZLE_SOLVED_FANFARE,
    COMUSIC_2E_CCW_FALL_AQUATIC,
    COMUSIC_2F_CCW_HUBROOM,
    COMUSIC_30_5TH_JINJO_COLLECTED,
    COMUSIC_31_GAME_OVER,
    COMUSIC_32_STARTUP_LOGO_SCENE,
    COMUSIC_33_RBB_ALTERNATIVE,
    COMUSIC_34_SNACKER_DANGER,
    COMUSIC_35_RBB_MASCHINE_ROOM_AQUATIC,
    COMUSIC_36_100TH_NOTE_COLLECTED,
    COMUSIC_37_DOUBLE_HEALTH_UPGRADE,
    COMUSIC_38_MOTZAND_BEATEN,
    COMUSIC_39_DK64_FUNGI_FOREST,
    COMUSIC_3A_FP_BOGGY_RACE,
    COMUSIC_3B_MINIGAME_VICTORY,
    COMUSIC_3C_MINIGAME_LOSS,
    COMUSIC_3D_JIGGY_SPAWN,
    COMUSIC_3E_SANDYBUTT_FAILURE,
    COMUSIC_3F_MAGIC_CARPET_RISING,
    COMUSIC_40_MAGIC_CARPET_SINKING,
    COMUSIC_41_MUMBOS_HUT,
    COMUSIC_42_NOTEDOOR_OPENING_FANFARE,
    COMUSIC_43_ENTER_LEVEL_GLITTER, // Looping
    COMUSIC_44_CCW_NABNUT,
    COMUSIC_45_CCW_NABNUT_ATTIC_A,
    COMUSIC_46_CCW_SPRING,
    COMUSIC_47_BGS_INSIDE_TANKTUP,
    COMUSIC_48_CCW_ALTERNATIVE_A,
    COMUSIC_49_CCW_ALTERNATIVE_QUICK,
    COMUSIC_4A_RBB_INSIDE_CONTAINER,
    COMUSIC_4B_CCW_ZUBBA_FIGHT,
    COMUSIC_4C_RBB_CREWMATE_CABIN,
    COMUSIC_4D_MUMBO_DANCE,
    COMUSIC_4E_IN_TRANSITION,
    COMUSIC_4F_OUT_TRANSITION,
    COMUSIC_50_GL_TTC_VERSION,
    COMUSIC_51_GL_CCW_VERSION,
    COMUSIC_52_GL_BGS_RBB_VERSION,
    COMUSIC_53_GL_FP_VERSION_A,
    COMUSIC_54_GL_GV_VERSION,
    COMUSIC_55_BGS_MR_VILE,
    COMUSIC_56_SM_HANGBRIDGE,
    COMUSIC_57_TURBO_TRAINERS,
    COMUSIC_58_WADING_BOOTS,
    COMUSIC_59_GL_FP_VERSION_B,
    COMUSIC_5A_FP_IGLOO_SAD,
    COMUSIC_5B_FP_IGLOO_HAPPY,
    COMUSIC_5C_BETA_GAME_OVER, // at least I guess so
    COMUSIC_5D_GL_MMM_VERSION,
    COMUSIC_5E_GL_MMM_RBB_VERSION,
    COMUSIC_5F_CCW_ALTERNATIVE_B,
    COMUSIC_60_NABNUT_ATTIC_B = 0x60,
    COMUSIC_61_XMAS_TREE_LIGHTS_UP,
    COMUSIC_62_RBB_BOOMBOX,
    COMUSIC_63_GL_FF_VERSION,
    COMUSIC_64_WORLD_OPENING_A,
    COMUSIC_65_WORLD_OPENING_B,
    COMUSIC_66_FP_INSIDE_WOZZAS_CAVE,
    COMUSIC_67_INSERTING_JIGGY,
    COMUSIC_68_TWINKLY_MINIGAME,
    COMUSIC_69_FF_WARP,
    COMUSIC_6A_MMM_TUMBLARS_SHED,
    COMUSIC_6B_FP_ALTERNATIVE,
    COMUSIC_6C_INTRO_TOWER_SCENE,
    COMUSIC_6D_CCW_GNAWTYS_HOUSE,
    COMUSIC_6E_GAME_SELECT,
    COMUSIC_6F_PAUSE_SCREEN,
    COMUSIC_70_MMM_INSIDE_LOGGO,
    COMUSIC_71_FF,
    MUSIC_BGS_FLIBBIT_FIGHT,
    COMUSIC_73_GAMEBOY,
    COMUSIC_74_GL_FINAL_SECTION,
    SFX_RED_FEATHER_REFILL,
    SFX_GOLD_FEATHER_REFILL,
    SFX_EGG_REFILL,
    JINGLE_DOOR_OF_GRUNTY_OPENED,
    COMUSIC_79_CHEATO,
    COMUSIC_7A_BRENTILDA,
    COMUSIC_7B_STEP_ON_SKULL_TILE, // Not 100% sure on these
    COMUSIC_7C_STEP_ON_GRUNTY_TILE,
    COMUSIC_7D_STEP_ON_BK_TILE,
    COMUSIC_7E_STEP_ON_MINIGAME_TILE,
    COMUSIC_7F_STEP_ON_JOKER_TILE,
    COMUSIC_80_GAME_OVER_CUTSCENE = 0x80,
    COMUSIC_81_ACTIVATING_BRENTILDA,
    SFX_REMOVE_JIGGY,
    COMUSIC_83_GV_SNS, // Not 100% sure on these
    COMUSIC_84_TTC_SNS,
    COMUSIC_85_FP_SNS,
    COMUSIC_86_MMM_SNS,
    COMUSIC_87_MMM_SNS_HAPPIER,
    COMUSIC_88_BIG_SNS_FANFARE,
    SFX_JINJO_STATUE_POWERUP,
    COMUSIC_8A_GETTING_TURBO_TRAINERS,
    COMUSIC_8B_DEACTIVATE_BRENTILDA,
    COMUSIC_8C_JINJONATOR_POWERUP,
    JINGLE_MENACING_GRUNTILDA_A,
    COMUSIC_8E_CREDITS,
    JINGLE_MENACING_GRUNTILDA_B,
    JINGLE_END_OF_INTRO = 0x90,
    COMUSIC_91_GRUNTY_FALLING,
    SFX_GRUNTY_SPELL_POWERUP,
    SFX_AIR_METER_DROPPING,
    COMUSIC_94_BBONUS,
    COMUSIC_95_BBONUS_A,
    COMUSIC_96_BBONUS_PICKUP_PIECE,
    COMUISC_97_BBONUS_DROP_PIECE,
    COMUSIC_98_BBONUS_PIECES_SHUFFLE, // Looping
    MUSIC_MUMBO_BBQ,
    COMUSIC_9A_JINJONATOR_HITS_GRUNTY_A,
    COMUSIC_9B_JINJONATOR_HITS_GRUNTY_B,
    COMUSIC_9C_JINJONATOR_HITS_GRUNTY_C,
    COMUSIC_9D_JINJONATOR_HITS_GRUNTY_D,
    COMUSIC_9E_JINJONATOR_HITS_GRUNTY_E,
    COMUSIC_9F_JINJONATOR_HITS_GRUNTY_F,
    COMUSIC_A0_JINJONATOR_HITS_GRUNTY_G = 0xA0,
    COMUSIC_A1_JINJONATOR_HITS_GRUNTY_H,
    COMUSIC_A2_JINJONATOR_HITS_GRUNTY_I,
    COMUSIC_A3_JINJONATOR_HITS_GRUNTY_J,
    JINGLE_JINJONATOR_DRUMMING_A,
    JINGLE_JINJONATOR_DRUMMING_B,
    JINGLE_JINJONATOR_DRUMMING_C,
    JINGLE_JINJONATOR_DRUMMING_D,
    COMUSIC_A8_KLUNGO_BY_FALLEN_GRUNTY,
    COMUSIC_A9_TOOTY,
    COMUSIC_AA_BEACH,
    JINGLE_JINJOATOR_FINAL_HIT,
    COMUSIC_AC_GOOD_ENDING = 0xAC
};

// SFXR_ = Repeating SFX
enum sfx_e
{
    SFX_0_BLOOP = 0x0000,
    SFX_1_MUMBO_UMENAKA,
    SFX_2_CLAW_SWIPE,
    SFX_3_DULL_CANNON_SHOT,
    // Long Beakbarge 2nd Part
    SFX_4_KAZOOIE_RUUUUUH, 
    SFX_5_BANJO_LANDING_01,
    SFX_6_BANJO_LANDING_02,
    SFX_7_BANJO_LANDING_03, 
    SFX_8_BANJO_LANDING_04, 
    SFX_9_SQUEAKY_TOY,
    SFX_A_BANJO_LANDING_05,
    SFX_B_BANJO_LANDING_06,
    SFX_C_TAKING_FLIGHT_LIFTOFF,
    SFX_D_EGGSHELL_BREAKING,
    SFX_E_SHOCKSPRING_BOING,
    SFX_F_SMALL_WATER_SPLASH,
    // shallow water
    SFX_10_BANJO_LANDING_07,
    // Blubber's Ship's Trapdoor eg.
    SFX_11_WOOD_BREAKING_1, 
    SFX_12_WATER_PADDLING_1,
    SFX_13_BEAKBUSTER_GROUND,
    // sounds like a muffled frying pan
    SFX_14_METALLIC_HIT_1,
    // less frying pan-ish
    SFX_15_METALLIC_HIT_2,
    // In the Opening Musical, when Mumbo's Xylophone drops
    SFX_16_HEAVY_FALL_VIBRATO, 
    SFX_17_JINJO_WHISTLE,
    SFX_18_BIGBUTT_SLIDE, 
    SFX_19_BANJO_LANDING_08,
    SFX_1A_BIG_THINGS_FALL_OVER,
    // from the sea-mines
    SFX_1B_EXPLOSION_1, 
    SFX_1C_ALARMCLOCK,
    // hitting the Bull eg.
    SFX_1D_HITTING_AN_ENEMY_1,
    // might also be used for breaking boulders
    SFX_1E_HITTING_AN_ENEMY_2,
    // hitting a Gruntling eg.
    SFX_1F_HITTING_AN_ENEMY_3,
    // Cauldrons make this sound when landing
    SFX_20_METAL_CLANK_1, 
    SFX_21_EGG_BOUNCE_1,
    SFX_22_KONGA_NOISE_1,
    SFX_23_KONGA_NOISE_2,
    SFX_24_KONGA_NOISE_3,
    // might be part of Clankers Bolt
    SFX_25_METAL_SLIDING_OVER_SMTH, 
    SFX_26_BANJO_LANDING_09,
    SFX_27_JINJO_HI,
    SFX_28_RUSTLING_NOISE,
    SFX_29_GRUBLIN_NYAHAHA,
    SFX_2A_CLOCK_TIC_1,
    // passive version
    SFX_2B_BULL_MOO_1,
    // when Trunker or the CCW plant grow eg.
    SFX_2C_PULLING_NOISE, 
    // incomplete cauldron spitout AND Banjo pulling on Kazooies Throat in Idle Anim
    SFX_2D_KABOING, 
    SFX_2E_BIGBUTT_RUNNING,
    SFX_2F_ORANGE_SPLAT,
    SFX_30_MAGIC_POOF,
    // starting to ride the FP sled to rescue Boggy
    SFX_31_BANJO_OHHWAAOOO, 
    // when rolling AND when taking damage
    SFX_32_BANJO_EGHEE, 
    // inital Shockspring Jump
    SFX_33_BANJO_AHOO, 
    SFX_34_BANJO_AGHOAA,
    SFX_35_BANJO_WOAH, 
    // death inducing damage
    SFX_36_BANJO_DOH,
    SFX_37_BANJO_OHWW,
    // less intense version
    SFX_38_BANJO_AYE_1,
    // more intense version
    SFX_39_BANJO_AYE_2,
    SFX_3A_BANJO_HOUW,
    SFX_3B_BANJO_GAAH,
    SFX_3C_BULL_GROWN,
    SFX_3D_TICKER_WALKING,
    // egg pooping ?
    SFX_3E_POOP_NOISE, 
    // higher pitch
    SFX_3F_CAULDRON_SQEAK_1, 
    // lower pitch
    SFX_40_CAULDRON_SQEAK_2, 
    // waking up
    SFX_41_MUMBO_ERGHHH, 
    // short and dull
    SFX_42_KAZOOIE_RAH, 
    // Short Beakbarge 2nd Part
    SFX_43_KAZOOIE_RUH, 
    // peeking out of the backpack
    SFX_44_KAZOOIE_AUW, 
    // Beakbbuster going down ?
    SFX_45_KAZOOIE_HUGHH, 
    // egg shot 1st Part
    SFX_46_KAZOOIE_CHOKING_UP, 
    // FeatherFlap exhausting
    SFX_47_KAZOOIE_HEUGH, 
    // TalonTrot Jump
    SFX_48_KAZOOIE_RUUH, 
    // TalonTrot Walking
    SFX_49_KAZOOIE_RA, 
    // the CCW Birds when comming out
    SFX_4A_CLUCKER_AHH, 
    SFX_4B_GULPING,
    // eating yumblies
    SFX_4C_LIP_SMACK, 
    // like when a fish flops around in shallow water
    SFX_4D_WET_WIGGLING, 
    // sounds like split-up from Tooie
    SFX_4E_KAZOOIE_BRUIII, 
    // selecting a SaveFile
    SFX_4F_BANJO_WAHOO, 
    // during Beakbomb
    SFX_50_KAZOOIE_RRRUH, 
    SFX_51_CLOCK_TIC_2,
    // starting a Beakbomb
    SFX_52_BANJO_YAH_OH, 
    // shockspring jump liftoff
    SFX_53_BANJO_HUIII,
    // jumping 
    SFX_54_BANJO_HOO_1,
    // jumping
    SFX_55_BANJO_HOO_2,
    // jumping
    SFX_56_BANJO_HUI,
    // egg shot 2nd part
    SFX_57_KAZOOIE_HEGH, 
    SFX_58_CHIMPY_NOISE_1,
    SFX_59_CHIMPY_NOISE_2,
    SFX_5A_CHIMPY_NOISE_3,
    SFX_5B_HEAVY_STUFF_FALLING,
    SFX_5C_HEAVY_STUFF_FALLING_DELAYED,
    // sleeping while snoring, inhale
    SFX_5D_BANJO_RAAOWW, 
    // sleeping while snoring, exhale
    SFX_5E_BANJO_PHEWWW,
    // while channeling a spell
    SFX_5F_MUMBO_BUGABUGOW_MUFFLED,
    // in the GameOver CS when Mumbo appears
    SFX_60_MUMBO_SKIDDING,
    // in the Musical when the buzzbomb falls (slowed down)
    SFX_61_CARTOONY_FALL,
    // annoyed at Kazooie, Idle Animation
    SFX_62_BANJO_ERGHH, 
    // huge fall starts
    SFX_63_BANJO_UWAAAAOOH,
    // in the Musical, when the Bulls run across
    SFX_64_STAMPEDE,
    SFX_65_METALLIC_SCRATCH,
    SFX_66_BIRD_AUUGHH,
    SFX_67_BEEHIVE_CLONK,
    SFX_68_CLUCKER_AAEEGHH,
    SFX_69_WHIPCRACK_CREAKING,
    // flagpoles during the boggy races
    SFX_6A_FLAGPOLE_WOBBLE,
    SFX_6B_LOCKUP_OPENING,
    SFX_6C_LOCKUP_CLOSING,
    SFX_6D_CROC_BITE,
    SFX_6E_VILE_EGH,
    // bottles uses this too I think
    SFX_6F_BANJO_HEADSCRATCH,
    SFX_70_WALKING_NOISE_1,
    SFX_71_WALKING_NOISE_2,
    SFX_72_WALKING_NOISE_3,
    SFX_73_WALKING_NOISE_4,
    SFX_74_WALKING_NOISE_5,
    SFX_75_WALKING_NOISE_6,
    SFX_76_WALKING_NOISE_7,
    SFX_77_WALKING_NOISE_8,
    SFX_78_EAGLECRY,
    SFX_79_TICKER_DEATH,
    // SFX_TICKER_DEATH but higher pitch
    SFX_7A_TERMITE_DEATH,
    SFX_7B_ICE_BREAKING_1,
    // entering a cauldron
    SFX_7C_CHEBOOF,
    // RBB, might be cranes aswell
    SFX_7D_ANCHOR_LIFTING,
    SFX_7E_CREAKY_DOOR_OPENING,
    SFX_7F_HEAVYDOOR_SLAM,
    SFX_80_YUMYUM_CLACK,
    // like polishing glass
    SFX_81_UUU,
    // when gates are broken, and probably when clankers bolt lands
    SFX_82_METAL_BREAK,
    SFX_83_BLUBBER_CRYING,
    SFX_84_GOBI_CRYING,
    SFX_85_ROUGH_COUGH,
    SFX_86_TIPTUP_CHORUS_AH,
    // when beakbustering his feet
    SFX_87_TANKTUP_OOOHW,
    SFX_88_WOZZA_NOISE,
    // unsure
    SFX_89_PARTYTOOL,
    // unsure, sounds like tooie's
    SFX_8A_ALTERNATIVE_EGG_SHOT,
    // when Banjo pulls on her throat in the idle anim
    SFX_8B_KAZOOIE_RAWW,
    SFX_8C_BOGGY_WAHEY,
    SFX_8D_BOGGY_OHWW,
    // tooie mingy sounds super similar
    SFX_8E_GRUNTLING_DAMAGE,
    SFX_8F_SNOWBALL_FLYING,
    SFX_90_SWITCH_PRESS,
    // might be clankers bolt landing
    SFX_91_METALLIC_SOUND,
    SFX_92_TOILET_FLUSH,
    // or some elevator
    SFX_93_MICROWAVE,
    SFX_94_COGS_ROTATING,
    SFX_95_BANJO_TALKING,
    SFX_96_HOTSAND_EEL_HISS,
    // twinklies box maybe
    SFX_97_BLUBBER_BURPS,
    SFX_98_DEAF_THUD,
    SFX_99_METALLIC_THUD,
    // grunty fight
    SFX_9A_MECHANICAL_CLOSING,
    SFX_9B_BOULDER_BREAKING_1,
    SFX_9C_BOULDER_BREAKING_2,
    SFX_9D_BOULDER_BREAKING_3,
    // might be enemys hitting the ground
    SFX_9E_BOULDER_BREAKING_4,
    SFX_9F_GENERATOR_RUNNING,
    // Tanktup maybe
    SFX_A0_COUGHING = 0x00A0,
    SFX_A1_BANJO_COUGHING,
    SFX_A2_BANJO_AHOOA,
    // from the idle anim
    SFX_A3_BANJO_DOUBLE_COUGH,
    // from the idle anim, but only once
    SFX_A4_BANJO_SINGLE_COUGH,
    SFX_A5_EYRIE_CRY,
    // final part of entering a cauldron warp
    SFX_A6_MAGICAL_FINISH,
    SFX_A7_WOODEN_SWOSH,
    SFX_A8_BLUBBER_DOUBLE_CRY,
    SFX_A9_BLUBBER_SINGLE_CRY,
    // this sounds like the used version
    SFX_AA_BGS_EGG_BREAKING_1,
    SFX_AB_BGS_EGG_BREAKING_2,
    SFX_AC_GOLDFEATHER_TALKING,
    SFX_AD_CATERPILLAR_SQUEAK,
    SFX_AE_YUMYUM_TALKING,
    SFX_AF_BANJO_CATCHING_BREATH,
    // might be from the grunty machine's doors
    SFX_B0_SIZZLING_NOISE,
    SFX_B1_BOGGY_KID_CRYING,
    SFX_B2_BOGGY_KID_HAPPY,
    SFX_B3_ORANGE_TALKING,
    SFX_B4_BOTTLES_TALKING_1,
    SFX_B5_THUNDERBOLT,
    // 1-6 are getting increasingly higher in pitch
    SFX_B6_GLASS_BREAKING_1,
    // 1-6 are getting increasingly higher in pitch
    SFX_B7_GLASS_BREAKING_2,
    // 1-6 are getting increasingly higher in pitch
    SFX_B8_GLASS_BREAKING_3,
    // 1-6 are getting increasingly higher in pitch
    SFX_B9_GLASS_BREAKING_4,
    // 1-6 are getting increasingly higher in pitch
    SFX_BA_GLASS_BREAKING_5,
    // 1-6 are getting increasingly higher in pitch
    SFX_BB_GLASS_BREAKING_6,
    SFX_BC_BOTTLES_TALKING_2,
    SFX_BD_BOTTLES_TALKING_3,
    SFX_BE_WATERFALL,
    SFX_BF_EYRIE_SLEEPING_1,
    SFX_C0_EYRIE_SLEEPING_2,
    // from the opening CS
    SFX_C1_BUZZBOMB_ATTACK,
    // death
    SFX_C2_GRUBLIN_EGH,
    // some talking ?
    SFX_C3_HEGH,
    SFX_C4_TWINKLY_MUNCHER_GRR,
    SFX_C5_TWINKLY_POP,
    SFX_C6_SHAKING_MOUTH, //bottles leaving/entering molehill
    // from the jinjo's flying
    SFX_C7_SHWOOP,
    // eating twinklies
    SFX_C8_CRUNCH,
    SFX_C9_PAUSEMENU_ENTER,
    SFX_CA_BANJO_DROWNING_1,
    SFX_CB_BANJO_DROWNING_2,
    // also the scrolling sound
    SFX_CC_PAUSEMENU_ENTER_SUBMENU,
    SFX_CD_PAUSEMENU_LEAVE_SUBMENU,
    // when the page is changed
    SFX_CE_PAUSEMENU_HOIP,
    SFX_CF_PAUSEMENU_SHWOOP,
    SFX_D0_GRIMLET_SQUEAK,
    SFX_D1_SNORKEL_WAH,
    // barely noticable
    SFX_D2_QUIET_METALLIC,
    SFX_D3_JINXIE_SNIFFLING_1,
    SFX_D4_JINXIE_SNIFFLING_2,
    SFX_D5_JINXIE_SNEEZING,
    SFX_D6_UGH,
    SFX_D7_GRABBA_DEATH,
    SFX_D8_CRANE,
    SFX_D9_WOODEN_CRATE_BREAKING_1,
    SFX_DA_WOODEN_CRATE_BREAKING_2,
    SFX_DB_WOODEN_CRATE_BREAKING_3,
    SFX_DC_IDLE_PADDLING,
    SFX_DD_JINJO_TALKING,
    SFX_DE_WOOD_SQUEAK,
    SFX_DF_KAZOOIE_TALKING_1,
    SFX_E0_KAZOOIE_TALKING_2,
    SFX_E1_KAZOOIE_TALKING_3,
    SFX_E2_KAZOOIE_TALKING_4,
    SFX_E3_KONGA_TALKING_1,
    SFX_E4_KONGA_TALKING_2,
    SFX_E5_KONGA_TALKING_3,
    // extra life talking ?
    SFX_E6_MEEP_1,
    // extra life talking ?
    SFX_E7_MEEP_2,
    SFX_E8_TOOTY_TALKING_1,
    SFX_E9_TOOTY_TALKING_2,
    // from enter_Lair CS
    SFX_EA_GRUNTY_LAUGH_1,
    // from Gameover CS
    SFX_EB_GRUNTY_LAUGH_2,
    SFX_EC_GRUNTY_TALKING_1,
    SFX_ED_GRUNTY_TALKING_2,
    SFX_EE_GRUNTY_TALKING_3,
    SFX_EF_TIPTUP_TALKING,
    // pages flipping
    SFX_F0_CHEATO_IDLE_1 = 0x00F0,
    // book closing thud
    SFX_F1_CHEATO_IDLE_2,
    SFX_F2_CUCKOO_CLOCK,
    SFX_F3_TRUNKER_TALKING,
    SFX_F4_TAP,
    SFX_F5_BLUBBER_TALKING_1,
    SFX_F6_BLUBBER_TALKING_2,
    SFX_F7_BLUBBER_TALKING_3,
    SFX_F8_BLUBBER_TALKING_4,
    SFX_F9_GRUNTLING_NOISE_1,
    SFX_FA_GRUNTLING_NOISE_2,
    SFX_FB_GRUNTLING_NOISE_3,
    SFX_FC_RUBEE_TALKING_1,
    SFX_FD_RUBEE_TALKING_2,
    SFX_FE_TANKTUP_TALKING_1,
    SFX_FF_TANKTUP_TALKING_2,
    SFX_100_TANKTUP_TALKING_3,
    SFX_101_LOGGO_TALKING,
    SFX_102_ZUBBA_TALKING,
    SFX_103_FLOTSAM_DEATH,
    // might also be zubba wings or similar
    SFX_104_PROPELLER_NOISE,
    SFX_105_EYRIE_YAWN,
    SFX_106_EYRIE_LIPSMACK,
    // full version
    SFX_107_CAULDRON_ACTIVATION_1,
    // abbreviated version
    SFX_108_CAULDRON_ACTIVATION_2,
    SFX_109_LOGGO_LID_CLAP,
    SFX_10A_TUMBLAR_TALKING,
    SFX_10B_GNAWTY_TALKING,
    SFX_10C_MUMMY_TALKING,
    SFX_10D_ANCIENT_ONE_TALKING,
    SFX_10E_TWINKLY_TALKING,
    SFX_10F_BOGGY_TALKING,
    SFX_110_TWINKLY_DEATH = 0x0110,
    SFX_111_WHIPCRACK_DEATH,
    SFX_112_TINKER_ATTENTION,
    SFX_113_PAD_APPEARS,
    SFX_114_BRICKWALL_BREAKING,
    SFX_115_BUZZBOMB_DEATH,
    SFX_116_DEAF_RUSTLING,
    SFX_117_LIMBO_COLLAPSING,
    SFX_118_LIMBO_REASSEMBLING,
    SFX_119_FISH_DEATH,
    SFX_11A_MATROSE_GRUBLIN_AYE,
    // 1-6 are getting increasingly shorter
    SFX_11B_TUMBLAR_DISAPPEARING_1,
    // 1-6 are getting increasingly shorter
    SFX_11C_TUMBLAR_DISAPPEARING_2,
    // 1-6 are getting increasingly shorter
    SFX_11D_TUMBLAR_DISAPPEARING_3,
    // 1-6 are getting increasingly shorter
    SFX_11E_TUMBLAR_DISAPPEARING_4,
    // 1-6 are getting increasingly shorter
    SFX_11F_TUMBLAR_DISAPPEARING_5,
    // 1-6 are getting increasingly shorter
    SFX_120_TUMBLAR_DISAPPEARING_6,
    // sounds like an OOT sound
    SFX_121_AWAWAU,
    SFX_122_TOOTY_TALKING_3,
    // on rooftiles
    SFX_123_BANJO_LANDING_10,
    // shorter version
    SFX_124_AUDIENCE_CHEERING_1,
    // longer version
    SFX_125_AUDIENCE_CHEERING_2,
    SFX_126_AUDIENCE_BOOING,
    SFX_127_AUDIENCE_MIXED,
    SFX_128_FIRE_CRACKING,
    // might be skeleton grimlets riiping the painting
    SFX_129_SWOOSH,
    SFX_12A_GRUNTY_AH,
    SFX_12B_BOILING_AND_BUBBLING,
    SFX_12C_FF_QUESTION_START,
    SFX_12D_CAMERA_ZOOM_CLOSEST,
    SFX_12E_CAMERA_ZOOM_MEDIUM,
    SFX_12F_FUUUCK_YOUUU,
    // from her final fall
    SFX_130_GRUNTY_ECHOING_CRY = 0x0130,
    SFX_131_GRUNTY_WEEEGH,
    SFX_132_GRUNTY_YOW,
    SFX_133_GRUNTY_OHW,
    SFX_134_FREEZING_SHIVER,
    // FileSelect, when Banjo's Bed ejects him
    SFX_135_CARTOONY_SPRING,
    SFX_136_GAMEBOY_STARTUP,
    SFX_137_GAMEBOY_BOIN,
    SFX_138_GAMEBOY_BOIOIN,
    SFX_139_GAMEBOY_GLITCH,
    SFX_13A_GLASS_BREAKING_7,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_1,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_2,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_3,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_4,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_5,
    // 1-6 are getting increasingly distant
    SFX_GRUNTY_FINAL_SCREAM_6 = 0x0140,
    SFX_141_MECHANICAL_WINCH,
    // pretty short
    SFX_142_GRUNTY_LAUGH_3,
    SFX_143_BULL_DAMAGE,
    SFX_144_DOUBLE_CAMERA_CLICK,
    SFX_145_SINGLE_CAMERA_CLICK,
    // the normal attack
    SFX_146_GRUNTY_SPELL_ATTACK_1,
    // the homing attack
    SFX_147_GRUNTY_SPELL_ATTACK_2,
    SFX_148_GRUNTY_SPELL_LANDING,
    SFX_149_CHEATO_TALKING_1,
    SFX_14A_CHEATO_TALKING_2,
    // when attacking with the broom
    SFX_14B_GRUNTY_LAUGH_4,
    SFX_14C_BRENTILDA_TALKING,
    SFX_14D_BANJO_FREEZING,
    SFX_14E_SOFT_EXPLOSION,
    // grunty's spell attacks flying
    SFX_14F_FIREWORK_WHISTLING,
    SFX_150_PORCELAIN_CRASH,
    // FileSelect, when Banjo's Bed ejects him
    SFX_151_CAT_MEOW,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_152_MOTOR_BREAKDOWN_01,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_02,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_03,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_04,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_05,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_06,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_07,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_08,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_09,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_10,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_11,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_12,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_13,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_14,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_15 = 0x0160,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_16,
    // Grunty's Broom
    SFX_162_MOTOR_RUCKUS,
    SFX_163_GRUNTY_WILD_SCREAM,
    SFX_164_EH,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_01,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_02,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_03,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_04,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_05,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_06,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_07,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_08,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_09,
    // 00-15 getting increasingly delayed and shorter
    SFX_170_HEAVY_THUNDERSTORM_10 = 0x170,
    // 00-15 getting increasingly delayed and shorter
    SFX_171_HEAVY_THUNDERSTORM_11,
    // 00-15 getting increasingly delayed and shorter
    SFX_172_HEAVY_THUNDERSTORM_12,
    // 00-15 getting increasingly delayed and shorter
    SFX_173_HEAVY_THUNDERSTORM_13,
    // 00-15 getting increasingly delayed and shorter
    SFX_174_HEAVY_THUNDERSTORM_14,
    // 00-15 getting increasingly delayed and shorter
    SFX_175_HEAVY_THUNDERSTORM_15,
    // 1-3 are having less and less echo
    SFX_176_JINJONATOR_JINJOOO_1,
    // 1-3 are having less and less echo
    SFX_177_JINJONATOR_JINJOOO_2,
    // 1-3 are having less and less echo
    SFX_178_JINJONATOR_JINJOOO_3,
    SFX_179_GRUNTY_DAMAGE,
    SFX_17A_SHIPHORN,
    SFX_17B_AIRPLANE_FALLING,
    SFX_17C_GRUNTY_FALLING_OFF_1,
    SFX_17D_GRUNTY_FALLING_OFF_2,
    // 01-14 are getting slower and lower pitch
    SFX_17E_MUMBO_TRANSFORMATION_01,
    // 01-14 are getting slower and lower pitch
    SFX_17F_MUMBO_TRANSFORMATION_02,
    // 01-14 are getting slower and lower pitch
    SFX_180_MUMBO_TRANSFORMATION_03,
    // 01-14 are getting slower and lower pitch
    SFX_181_MUMBO_TRANSFORMATION_04,
    // 01-14 are getting slower and lower pitch
    SFX_182_MUMBO_TRANSFORMATION_05,
    // 01-14 are getting slower and lower pitch
    SFX_183_MUMBO_TRANSFORMATION_06,
    // 01-14 are getting slower and lower pitch
    SFX_184_MUMBO_TRANSFORMATION_07,
    // 01-14 are getting slower and lower pitch
    SFX_185_MUMBO_TRANSFORMATION_08,
    // 01-14 are getting slower and lower pitch
    SFX_186_MUMBO_TRANSFORMATION_09,
    // 01-14 are getting slower and lower pitch
    SFX_187_MUMBO_TRANSFORMATION_10,
    // 01-14 are getting slower and lower pitch
    SFX_188_MUMBO_TRANSFORMATION_11,
    // 01-14 are getting slower and lower pitch
    SFX_189_MUMBO_TRANSFORMATION_12,
    // 01-14 are getting slower and lower pitch
    SFX_18A_MUMBO_TRANSFORMATION_13,
    // 01-14 are getting slower and lower pitch
    SFX_18B_MUMBO_TRANSFORMATION_14,
    SFX_18C_EYRIE_MAMA,
    SFX_18D_SEXY_GRUNTY_TALKING_1,
    SFX_18E_SEXY_GRUNTY_TALKING_2,
    SFX_18F_FREEZE_FRAME,
    SFX_190_GULP = 0x0190,
    SFX_191_STATIC,

    SFX_3E9_UNKNOWN = 0x3e9, //bsbwhirl
    SFX_3EA_UNKNOWN,         //chjig
    SFX_3EB_UNKNOWN,         //bstimeout
    SFX_3EC_CCW_DOOR_OPENING,         //ccw and GV opening
    SFX_3ED,
    SFX_3EE,
    SFX_3EF,
    SFX_3F0_FLIBBIT_TALKING,
    SFX_3F1_UNKNOWN, //bsstand
    SFX_3F2_UNKNOWN, //gold_chest_ttc

    SFX_3F5_UNKNOWN = 0x3F5, //RBB/code_5F80
    SFX_3F6_UNKNOWN, //lair/code_0 func_803880BC
    SFX_3F7_UNKNOWN, //gv/histup
    SFX_3F8_UNKNOWN, //gv/histup
    SFX_3F9_UNKNOWN, //chmole
    SFX_3FA_HONEYCOMB_TALKING,
    SFX_3FB_UNKNOWN, //conga

    SFX_405_UNKNOWN = 0x405,
    SFX_406_GOLD_BULLION_TALKING,
    SFX_407_MUMBO_TALKING_1,
    SFX_408_MUMBO_TALKING_2,
    SFX_409_MUMBO_TALKING_3,
    SFX_40A_MUMBO_TALKING_4,
    SFX_40B_MUMBO_TALKING_5,
    SFX_40C_MUSIC_NOTE_TALKING,

    SFX_40E_UNKNOWN = 0x40e,
    SFX_40F_TICKER_TALKING,

    SFX_412_FREEZING_WATER_TALKING = 0x412,
    SFX_413_WATER_RIPPLE,
    SFX_414_XMAS_GIFT_TALKING,
    SFX_415_UNKNOWN, //xmas tree
    SFX_416,
    SFX_417_UNKNOWN, //lair/func_8038EB94, double health

    SFX_419_UNKNOWN = 0x419,
    SFX_41A_UNKNOWN = 0x41a
};


enum level_e
{
    LEVEL_1_MUMBOS_MOUNTAIN = 0x1,
    LEVEL_2_TREASURE_TROVE_COVE,
    LEVEL_3_CLANKERS_CAVERN,
    LEVEL_4_BUBBLEGLOOP_SWAMP,
    LEVEL_5_FREEZEEZY_PEAK,
    LEVEL_6_LAIR,
    LEVEL_7_GOBIS_VALLEY,
    LEVEL_8_CLICK_CLOCK_WOOD,
    LEVEL_9_RUSTY_BUCKET_BAY,
    LEVEL_A_MAD_MONSTER_MANSION,
    LEVEL_B_SPIRAL_MOUNTAIN,
    LEVEL_C_BOSS,
    LEVEL_D_CUTSCENE
};

enum jiggy_e
{
    JIGGY_01_MM_JINJO = 0x1,
    JIGGY_02_MM_TICKERS_TOWER,
    JIGGY_03_MM_MUMBOS_SKULL,
    JIGGY_4_MM_JUJU,
    JIGGY_5_MM_HUTS,
    JIGGY_06_MM_RUINS,
    JIGGY_07_MM_HILL,
    JIGGY_8_MM_ORANGE_PADS,
    JIGGY_9_MM_CHIMPY,
    JIGGY_A_MM_CONGA,
    JIGGY_0B_TTC_JINJO,
    JIGGY_0C_TTC_LIGHTHOUSE,
    JIGGY_0D_TTC_ALCOVE_1,
    JIGGY_0E_TTC_ALCOVE_2,
    JIGGY_0F_TTC_POOL,
    JIGGY_10_TTC_SANDCASTLE,
    JIGGY_11_TTC_RED_X,
    JIGGY_12_TTC_NIPPER,
    JIGGY_13_TTC_LOCKUP,
    JIGGY_14_TTC_BLUBBER,
    JIGGY_15_CC_JINJO,
    JIGGY_16_CC_SNIPPETS,
    JIGGY_17_CC_CLANKER_RAISED,
    JIGGY_18_CC_BOLT,
    JIGGY_19_CC_TAIL,
    JIGGY_1A_CC_LONG_PIPE,
    JIGGY_1B_CC_TOOTH,
    JIGGY_1C_CC_RINGS,
    JIGGY_1D_CC_SLOW_SAWBLADES,
    JIGGY_1E_CC_FAST_SAWBLADES,
    JIGGY_1F_BGS_JINGO,
    JIGGY_20_BGS_ELEVATED_WALKWAY,
    JIGGY_21_BGS_PINKEGG,
    JIGGY_22_CROCTUS,
    JIGGY_23_BGS_HUTS,
    JIGGY_24_BGS_FLIBBITS,
    JIGGY_25_BGS_MAZE,
    JIGGY_26_BGS_TANKTUP,
    JIGGY_27_BGS_TIPTUP,
    JIGGY_28_BGS_MR_VILE,
    JIGGY_29_FP_JINJO,
    JIGGY_2A_FP_BOGGY_1,
    JIGGY_2B_FP_PIPE,
    JIGGY_2C_FP_BOGGY_3,
    JIGGY_2D_FP_SNOWMAN_BUTTONS,
    JIGGY_2E_FP_PRESENTS,
    JIGGY_2F_FP_XMAS_TREE,
    JIGGY_30_FP_BOGGY_2,
    JIGGY_31_FP_SIR_SLUSH,
    JIGGY_32_FP_WOZZA,
    JIGGY_33_LAIR_1ST_JIGGY,
    JIGGY_34_LAIR_MM_WITCH_SWITCH,
    JIGGY_35_LAIR_CC_WITCH_SWITCH,
    JIGGY_36_LAIR_TTC_WITCH_SWITCH,
    JIGGY_37_LAIR_BGS_WITCH_SWITCH,
    JIGGY_38_LAIR_FP_WITCH_SWITCH,
    JIGGY_39_LAIR_MMM_WITCH_SWITCH,
    JIGGY_3A_LAIR_GV_WITCH_SWITCH,
    JIGGY_3B_LAIR_RBB_WITCH_SWITCH,
    JIGGY_3C_LAIR_CCW_WITCH_SWITCH,
    JIGGY_3D_GV_JINJO,
    JIGGY_3E_GV_GRABBA,
    JIGGY_3F_GV_SHYINX,
    JIGGY_40_GV_MATCHING_GAME,
    JIGGY_41_GV_MAZE,
    JIGGY_42_GV_WATER_PYRAMID,
    JIGGY_43_GV_HISTUP,
    JIGGY_44_GV_GOBI_1,
    JIGGY_45_GV_GOBI_2,
    JIGGY_46_GV_ANCIENT_ONES,
    JIGGY_47_CCW_JINJO,
    JIGGY_48_CCW_HOUSE,
    JIGGY_49_CCW_EYRIE,
    JIGGY_4A_CCW_NABNUT,
    JIGGY_4B_CCW_GNAWTY,
    JIGGY_4C_CCW_ZUBBAS,
    JIGGY_4D_CCW_FLOWER,
    JIGGY_4E_CCW_SUMMER_LEAF_JUMPS,
    JIGGY_4F_CCW_TREE_TOP,
    JIGGY_50_CCW_TOP_ROOM,
    JIGGY_51_RBB_JINJO,
    JIGGY_52_RBB_WAREHOUSE,
    JIGGY_53_RBB_SNORKEL,
    JIGGY_54_RBB_WHISTLE,
    JIGGY_55_RBB_FUNNEL,
    JIGGY_56_RBB_BOSS_BOOM_BOX,
    JIGGY_57_RBB_PROPELLOR,
	JIGGY_58_RBB_CAPTAINS_CABIN,
	JIGGY_59_RBB_CRANE_CAGE,
	JIGGY_5A_RBB_ENGINE_ROOM,
	JIGGY_5B_MMM_JINJO,
	JIGGY_5C_MMM_WELL,
	JIGGY_5D_MMM_NAPPER,
	JIGGY_5E_MMM_CELLAR,
	JIGGY_5F_MMM_CHURCH_ROOF,
	JIGGY_60_MMM_MOTZHAND,
	JIGGY_61_MMM_RAIN_BARREL,
	JIGGY_62_MMM_TUMBLAR,
	JIGGY_63_MMM_FLOWER_POTS,
	JIGGY_64_MMM_LOGGO
};

enum honeycomb_e
{
	HONEYCOMB_1_MM_HILL = 1,
	HONEYCOMB_2_MM_JUJU,
	HONEYCOMB_3_TTC_UNDERWATER,
	HONEYCOMB_4_TTC_FLOATING_BOX,
	HONEYCOMB_5_CC_UNDERWATER,
	HONEYCOMB_6_CC_ABOVE_WATER,
	HONEYCOMB_7_BGS_MUMBOS,
	HONEYCOMB_8_BGS_TANKTUP,
	HONEYCOMB_9_FP_WOZZAS_CAVE,
	HONEYCOMB_A_FP_SIR_SLUSH,
	HONEYCOMB_B_GV_CACTUS,
	HONEYCOMB_C_GV_GOBI_3,
	HONEYCOMB_D_CCW_GNAWTYS,
	HONEYCOMB_E_CCW_NABNUTS,
	HONEYCOMB_F_RBB_BOAT_HOUSE,
	HONEYCOMB_10_RBB_ENGINE_ROOM,
	HONEYCOMB_11_MMM_CHURCH_RAFTERS,
	HONEYCOMB_12_MMM_FLOORBOARD,
	HONEYCOMB_13_SM_STUMP,
	HONEYCOMB_14_SM_WATERFALL,
	HONEYCOMB_15_SM_UNDERWATER,
	HONEYCOMB_16_SM_TREE,
	HONEYCOMB_17_SM_COLIWOBBLE,
	HONEYCOMB_18_SM_QUARRIES
};

enum actor_e
{
    ACTOR_1_UNKNOWN         = 0x1,
    ACTOR_2_UNKNOWN,

    ACTOR_4_BIGBUTT         = 0x4,

    ACTOR_6_GRUBLIN           = 0x6,

    ACTOR_8_CONGA             = 0x8,
    ACTOR_9_MM_HUT,
    ACTOR_A_CHUMP_FISH,
    ACTOR_B_SHOCKSPRING_PAD,
    ACTOR_C_MUD_HUT,
    ACTOR_D_WOOD_DEMOLISHED,
    ACTOR_E_BULL_INTRO,
    ACTOR_F_CHIMPY            = 0xF,

    ACTOR_11_JUJU_CTRL       = 0x11,
    ACTOR_12_BEEHIVE,
    //ACTOR_13_SINKING_BOBBER

    ACTOR_14_ORANGE_PROJECTILE = 0x14,
    ACTOR_15_UNKNOWN,

    ACTOR_17_PLAYER_SHADOW = 0x17,

    ACTOR_1E_LEAKY = 0x1E,

    ACTOR_25_CEMETARY_POT = 0x25, 

    ACTOR_29_ORANGE_COLLECTABLE = 0x29,
    ACTOR_2A_GOLD_BULLION,
    ACTOR_2B_GOLD_BULLION_THROW_TARGET,
    ACTOR_2C_TURBO_TALON_TRAINERS,
    ACTOR_2D_MUMBO_TOKEN,

    //ACTOR_2F_WATERFALL_START
    //ACTOR_30_WATERFALL_END

    //ACTOR_37_WATER_BOBBER
    //ACTOR_38_TUNBLAR_MOVEMENT

    ACTOR_39_NAPPER = 0x39,
    ACTOR_3A_MOTZHAND,

    ACTOR_3C_CC_KEY = 0x3C,
    ACTOR_3D_CLANKER_SAWBLADE_PROPELLOR_1,
    ACTOR_3E_CLANKER_SAWBLADE_PROPELLOR_2,
    ACTOR_3F_CLANKER_SAWBLADE_PROPELLOR_3,
    ACTOR_40_CLANKER_SAWBLADE_PROPELLOR_4,
    ACTOR_41_CLANKER_SAWBLADE_PROPELLOR_5,
    ACTOR_42_CLANKER_SAWBLADE_PROPELLOR_6,
    ACTOR_43_CLACKER_SCREW,
    ACTOR_44_CLANKER_TOKEN_TOOTH_EXTERIOR,
    ACTOR_45_CLANKER_JIGGY_TOOTH_EXTERIOR,
    ACTOR_46_JIGGY,
    ACTOR_47_EMPTY_HONEYCOMB,

    ACTOR_49_EXTRA_LIFE = 0x49,

    ACTOR_4A_WOOD_EXPLOSION = 0x4A,

    ACTOR_4C_STEAM          = 0x4C,
    ACTOR_4D_STEAM_2,

    ACTOR_50_HONEYCOMB = 0x50,
    ACTOR_51_MUSIC_NOTE,
    ACTOR_52_BLUE_EGG,
    ACTOR_53_RED_ARROW,
    ACTOR_54_RED_QUESTION_MARK,
    ACTOR_55_RED_X,
    ACTOR_56_SHRAPNEL,
    ACTOR_57_ORANGE_PAD,

    ACTOR_59_JUJU              = 0x59,
    ACTOR_5A_JIGGY_IN_HAND,
    ACTOR_5B_PINK_EGG_LARGEST,

    ACTOR_62_JINJO_GREEN = 0x62,

    ACTOR_65_WADING_BOOTS = 0x65,

    ACTOR_67_SNIPPET = 0x67,

    ACTOR_69_CLAM = 0x69,

    ACTOR_6D_GV_BANJO_DOOR = 0x6D, 

    ACTOR_72_UNKNOWN = 0x72,
    ACTOR_73_UNKNOWN,
    ACTOR_74_UNKNOWN,
    ACTOR_75_UNKNOWN,
    ACTOR_76_UNKNOWN,
    ACTOR_77_UNKNOWN,
    ACTOR_78_UNKNOWN,
    ACTOR_79_UNKNOWN,
    ACTOR_7A_UNKNOWN,
    ACTOR_7B_UNKNOWN,
    ACTOR_7C_UNKNOWN,
    ACTOR_7D_UNKNOWN,
    ACTOR_7E_UNKNOWN,
    ACTOR_7F_UNKNOWN,

    ACTOR_C5_CHIMPY_STUMP      = 0xC5,
    
    ACTOR_C7_RIPPER = 0xC7,
    ACTOR_C8_BOGGY_2  = 0xC8,

    ACTOR_CA_TEEHEE = 0xCA,

    ACTOR_E4_FLIGHT_PAD     = 0xE4,

    ACTOR_E6_GLOOP          = 0xE6,
    ACTOR_E7_GLOOP_BUBBLE,
    ACTOR_E8_TANKTUP,
    ACTOR_E9_TANKTUP_LEG_FL,
    ACTOR_EA_TANKTUP_LEG_BL,
    ACTOR_EB_TANKTUP_LEG_FR,
    ACTOR_EC_TANKTUP_LEG_BR,
    ACTOR_ED_PINK_EGG_LARGE = 0xED,
    ACTOR_EE_PINK_EGG_MEDIUM,
    ACTOR_EF_PINK_EGG_SMALL,
    ACTOR_F0_PINK_EGG_SMALLEST,
    ACTOR_F1_LEAFBOAT,
    ACTOR_F2_BLACK_SNIPPET,

    ACTOR_F4_BURIED_TREASURE = 0xF4,
    ACTOR_F5_MUTIE_SNIPPET,
    ACTOR_F6_BIG_ALLIGATOR,

    ACTOR_101_CLANKER_TOKEN_TOOTH = 0x101,
    ACTOR_102_CLANKER_JIGGY_TOOTH,
    ACTOR_103_UNKNOWN,
    ACTOR_104_UNKNOWN,
    ACTOR_105_UNKNOWN,
    ACTOR_106_UNKNOWN,
    ACTOR_107_UNKNOWN,

    ACTOR_114_CHURCH_DOOR = 0x114,
    ACTOR_115_BLUBBER,
    ACTOR_116_FP_SNOWMAN_BUTTON,
    ACTOR_117_NIPPER,
    ACTOR_118_GRABBA,
    ACTOR_119_MAGIC_CARPET_1,

    ACTOR_11D_RUBEES_EGG_POT = 0x11D,

    ACTOR_11B_RUBEE = 0x11B,

    ACTOR_120_SLAPPA = 0x120,

    ACTOR_122_MAGIC_CARPET_SHADOW = 0x122,
    ACTOR_123_MAGIC_CARPET_2,
    ACTOR_124_SIR_SLUSH,
    ACTOR_125_SNOWBALL,
    ACTOR_126_SIR_SLUSH_HAT,

    ACTOR_129_RED_FEATHER = 0x129,

    ACTOR_12B_TUTORIAL_BOTTLES = 0x12B,
    ACTOR_12C_MOLEHILL,

    ACTOR_12E_GOBI_1      = 0x12E,
    ACTOR_12F_GOBI_ROPE,

    ACTOR_131_GOBI_2    = 0x131,
    ACTOR_132_TRUNKER,
    ACTOR_133_FLIBBIT_RED,
    ACTOR_134_BUZZBOMB,
    ACTOR_135_GOBI_3,
    ACTOR_136_YELLOW_FLIBBIT_CONTROLLER,
    ACTOR_137_FLIBBIT_YELLOW,
    ACTOR_138_VILE_GAME_CTRL,
    ACTOR_139_YUMBLIE,
    ACTOR_13A_MR_VILE,
    ACTOR_13B_FLOTSAM,

    ACTOR_13E_LIGHTHOUSE_DOOR = 0x13E,
    ACTOR_13F_GV_SUN_SWITCH,
    ACTOR_140_GV_SUN_DOOR,

    ACTOR_142_GV_STAR_HATCH = 0x142,
    ACTOR_143_GV_KAZOOIE_DOOR,
    ACTOR_144_GV_STAR_SWITCH,
    ACTOR_145_HONEYCOMB_SWITCH,
    ACTOR_146_GV_KAZOOIE_TARGET,
    ACTOR_147_ANCIENT_ONE,

    ACTOR_14E_BGS_ELEVATED_WALKWAY_SWITCH = 0x14E,
    ACTOR_14F_DESTROYED_JIGGY,

    ACTOR_151_LOCKUP_SLOW = 0x151,
    ACTOR_152_LOCKUP_MEDIUM,
    ACTOR_153_LOCKUP_FAST,

    ACTOR_158_UNKNOWN = 0x158,

    ACTOR_15A_UNKNOWN = 0x15A,

    ACTOR_15C_UNKNOWN = 0x15C,

    ACTOR_15F_XMAS_TREE = 0x15F,
    ACTOR_160_BOGGY_1,

    ACTOR_163_BAT = 0x163,
    ACTOR_164_COLLYWOBBLE_A,
    ACTOR_165_BAWL_A,
    ACTOR_166_TOPPER_A,
    ACTOR_167_ATTACK_TUTORIAL,

    ACTOR_16F_QUARRIE = 0x16F,

    ACTOR_172_RBB_EGG_TOLL = 0x172,

    ACTOR_175_MODEL_RUSTY_BUCKET_REAR_PROPELLER = 0x175,

    ACTOR_181_SCARF_SLED = 0x181,
    ACTOR_182_RACE_SLED = 0x182,

    ACTOR_1BB_ENGINE_ROOM_PROPELLOR_1 = 0x1bb,
    ACTOR_1BC_ENGINE_ROOM_PROPELLOR_2,
    ACTOR_1BD_ENGINE_ROOM_PROPELLOR_3,

    ACTOR_1C6_GRIMLET = 0x1C6,

    ACTOR_1CC_GRILL_CHOMPA  = 0x1CC,
    ACTOR_1CD_UNKNOWN,
    ACTOR_1CE_UNKNOWN,
    ACTOR_1CF_UNKNOWN,
    ACTOR_1D0_UNKNOWN,
    ACTOR_1D1_UNKNOWN,
    ACTOR_1D2_UNKNOWN,
    ACTOR_1D3_UNKNOWN,
    ACTOR_1D4_UNKNOWN,

    ACTOR_1DB_GAME_OVER = 0x1DB,

    ACTOR_1E4_TOOTS = 0x1E4,

    ACTOR_1E9_SNARE_BEAR = 0x1E9,
    ACTOR_1EA_POLAR_BEAR_CUB_BLUE,
    ACTOR_1EB_POLAR_BEAR_CUB_GREEN,
    ACTOR_1EC_POLAR_BEAR_CUB_RED,
    ACTOR_1ED_BLUE_PRESENT_COLLECTABLE,

    ACTOR_1EF_GREEN_PRESENT_COLLECTABLE = 0x1EF,
    
    ACTOR_1F1_RED_PRESENT_COLLECTABLE = 0x1F1,

    ACTOR_1F3_WOZZA = 0x1F3,
    ACTOR_1F4_WOZZAS_JIGGY,
    ACTOR_1F5_GV_KAZOOIE_DOOR,

    ACTOR_1F7_JINXY = 0x1F7, 

    ACTOR_1FA_CROCTUS = 0x1FA,
    ACTOR_1FB_BGS_MAZE_SWITCH = 0x1FB,

    ACTOR_204_MM_WITCH_SWITCH = 0x204,

    ACTOR_206_MMM_WITCH_SWITCH = 0x206,

    ACTOR_208_TTC_WITCH_SWITCH = 0x208,

    ACTOR_20B_RBB_WITCH_SWITCH = 0x20B,

    ACTOR_20E_MM_ENTRANCE_DOOR = 0x20E,
    ACTOR_20F_RBB_ENTRANCE_DOOR,
    ACTOR_210_BGS_ENTRANCE_DOOR,
    ACTOR_211_CHEST_LID, //CC ENTRANCE
    ACTOR_212_IRON_BARS, //TTC_ENTRANCE

    ACTOR_226_GV_ENTRANCE   = 0x226,
    ACTOR_227_GLASS_EYE,
    ACTOR_228_INVISIBLE_WALL, //MMM ENTRANCE DOOR???

    ACTOR_234_CCW_ENTRANCE_DOOR = 0x234,
    ACTOR_235_FP_ENTANCE_DOOR,

    ACTOR_237_CCW_WITCH_SWITCH = 0x237,

    ACTOR_239_FP_WITCH_SWITCH = 0x239,

    ACTOR_243_GV_SNS_CHAMBER_DOOR = 0x243,

    ACTOR_245_GV_SNS_SWITCH = 0x245,

    ACTOR_256_GV_WITCH_SWITCH = 0x256,
    ACTOR_257_BGS_WITCH_SWITCH = 0x257,

    ACTOR_25B_CC_WITCH_SWITCH = 0x25B,
    ACTOR_25C_SHARKFOOD_ISLAND,
    ACTOR_25D_ICE_KEY,
    ACTOR_25E_SNS_EGG,

    ACTOR_27A_TIPTUP = 0x27A,
    ACTOR_27B_CHOIR_TURTLE_YELLOW,
    ACTOR_27C_CHOIR_TURTLE_CYAN,
    ACTOR_27D_CHOIR_TURTLE_BLUE,
    ACTOR_27E_CHOIR_TURTLE_RED,
    ACTOR_27F_CHOIR_TURTLE_PINK,
    ACTOR_280_CHOIR_TURTLE_PURPLE,
    ACTOR_281_BOSS_BOOM_BOX_LARGEST,
    ACTOR_282_BOSS_BOOM_BOX_LARGE,
    ACTOR_283_BOSS_BOOM_BOX_MEDIUM,
    ACTOR_284_BOSS_BOOM_BOX_SMALL,

    ACTOR_28A_CLANKER_WHIPCRACK = 0x28A,
    ACTOR_28B_SOUND_SOURCE,

    ACTOR_290_CLANKER_SAWBLADE_PROPELLOR_7 = 0x290,
    ACTOR_291_CLANKER_SAWBLADE_PROPELLOR_8,
    ACTOR_292_CLANKER_SAWBLADE_PROPELLOR_9,
    ACTOR_293_CLANKER_SAWBLADE_PROPELLOR_10,
    ACTOR_294_CLANKER_SAWBLADE_PROPELLOR_11,
    ACTOR_295_CLANKER_SAWBLADE_PROPELLOR_12,

    ACTOR_29B_ZUBBA = 0x29B,

    ACTOR_29F_CLUCKER = 0x29F,

    ACTOR_2A1_EEYRIE_BABY = 0x2A1,
    ACTOR_2A2_CATERPILLAR,

    ACTOR_2A4_BOOM_BOX_SLOW = 0x2A4,

    ACTOR_2A8_NABNUT = 0x2A8,
    ACTOR_2A9_ACORN,

    ACTOR_2E5_WOODEN_DOOR   = 0x2e5,

    ACTOR_30D_BOOM_BOX_FAST = 0x30D,

    ACTOR_30F_WHIPCRACK     = 0x30f,

    ACTOR_319_GV_MAZE_CTRL  = 0x319,

    ACTOR_31D_SANDYBUTT_PYRAMID = 0x31D,
    ACTOR_31E_PALM_TREE,
    
    ACTOR_32B_UNKNOWN = 0x32B, //something with Tanktup

    ACTOR_332_TWINKLY_BLUE = 0x332,
    ACTOR_333_TWINKLY_GREEN,
    ACTOR_334_TWINKLY_ORANGE,
    ACTOR_335_TWINKLY_RED,

    ACTOR_337_TWINKLY_MUNCHER = 0x337,
    ACTOR_338_XMAS_TREE_SWITCH,

    ACTOR_33A_BLUE_PRESENT  = 0x33A,
    ACTOR_33B_GREEN_PRESENT,
    ACTOR_33C_RED_PRESENT,

    ACTOR_33F_WOZZA_IN_CAVE         = 0x33F,

    ACTOR_34D_BEE_SWARM     = 0x34D,
    ACTOR_34E_LIMBO,
    ACTOR_34F_MUMMUM,
    ACTOR_350_SEAMAN_GRUBLIN,

    ACTOR_353_XMAS_TREE_EGG_TOLL = 0x353,
    ACTOR_354_DRIPS,

    ACTOR_367_GRUNTLING_RED = 0x367,
    ACTOR_368_5_MUMBO_TOKEN_SIGN,
    ACTOR_369_20_MUMBO_TOKEN_SIGN,
    ACTOR_36A_15_MUMBO_TOKEN_SIGN,
    ACTOR_36B_10_MUMBO_TOKEN_SIGN,
    ACTOR_36C_25_MUMBO_TOKEN_SIGN,

    ACTOR_COLLYWOBBLE_B     = 0x36D,
    ACTOR_BAWL_B            = 0x36E,
    ACTOR_TOPPER_B          = 0x36F,

    ACTOR_375_GRUBLIN_HOOD  = 0x375,

    ACTOR_379_UNKNOWN = 0x379,
    ACTOR_37A_BOTTLES,

    ACTOR_37D_ICECUBE_A = 0x37d,

    ACTOR_37F_LOGGO         = 0x37F,
    ACTOR_380_SCARAB_BEETLE,
    ACTOR_381_PORTRAIT_CHOMPA,
    ACTOR_382_PORTRAIT_OF_GRUNTY,
    ACTOR_383_FIRE_FX,
    ACTOR_384_PORTRAIT_OF_BLACKEYE,
    ACTOR_385_PORTRAIT_OF_TOWER,
    ACTOR_386_PORTRAIT_OF_TREE_AND_MOON,
    ACTOR_387_PORTRAIT_OF_TEEHEE,
    ACTOR_388_PORTRAIT_OF_MINION,
    ACTOR_389_GRUNTY_SPELL_FIREBALL,

    ACTOR_38B_GRUNTILDA_FINAL_BOSS = 0x38B,

    ACTOR_39F_FIGHT_FLIGHT_PAD = 0x39F,
    ACTOR_3A0_ICECUBE_B,
    ACTOR_3A1_STONE_JINJO = 0x3A1,
    ACTOR_3A2_JINJO_STATUE_BASE = 0x3A2,

    ACTOR_3A5_BOSS_JINJO_ORANGE = 0x3A5,
    ACTOR_3A6_BOSS_JINJO_GREEN,
    ACTOR_3A7_BOSS_JINJO_PINK,
    ACTOR_3A8_BOSS_JINJO_YELLOW,
    ACTOR_3A9_JINJONATOR_STATUE_BASE = 0x3A9,

    ACTOR_3AA_GRUNTY_SPELL_GREEN_ATTACK = 0x3AA,
    ACTOR_3AB_GRUNTY_SPELL_BARRIER,
    ACTOR_3AC_JINJONATOR,

    ACTOR_3AF_GRUNTY_SHADOW = 0x3AF,

    ACTOR_3BA_UNKOWN        = 0x3ba,

    ACTOR_3BF_GRUNTLING_BLUE = 0x3bf,
    ACTOR_3C0_GRUNTLING_BLACK,
    ACTOR_3C1_PURPLE_TEEHEE,
    ACTOR_3C2_GIANT_RIPPER,

    ACTOR_3C4_FF_PRIZE_WASHING_CAULDRON = 0x3C4,

    ACTOR_3C7_FF_PRIZE_GRUNTY_DOLL = 0x3C7,
    ACTOR_3C8_FF_PRIZE_TOOTY = 0x3C8,

    ACTOR_3CA_ROCK_TRAPPING_GRUNTY = 0x3CA
};

enum bs_e
{
    BS_1_IDLE = 0x1,
    BS_2_WALK_SLOW,
    BS_WALK = 0x3,
    BS_WALK_FAST = 0x4,
    BS_5_JUMP,
    BS_CLAW = 0x6,
    BS_CROUCH = 0x7,
    BS_8_BTROT_JUMP,
    BS_9_EGG_HEAD,
    BS_A_EGG_ASS,
    BS_B_UNKOWN,
    BS_SKID = 0xC,
    BS_D_TIMEOUT,
    BS_E_OW,
    BS_F_BBUSTER,
    BS_BFLAP = 0x10,
    BS_11_BPECK,
    BS_12_BFLIP,
    BS_BBARGE = 0x13, 
    BS_14_BTROT_ENTER,
    BS_15_BTROT_IDLE,
    BS_16_BTROT_WALK,
    BS_17_BTROT_EXIT ,
    BS_18_FLY_KNOCKBACK,

    BS_1A_WONDERWING_ENTER = 0x1A,
    BS_1B_WONDERWING_IDLE,
    BS_1C_WONDERWING_WALK,
    BS_1D_WONDERWING_JUMP,
    BS_1E_WONDERWING_EXIT,
    BS_WALK_CREEP = 0x1F,
    BS_20_LANDING = 0x20,
    BS_BSHOCK_CHARGE = 0x21,
    BS_BSHOCK_JUMP = 0x22,
    BS_23_FLY_ENTER,
    BS_24_FLY,
    BS_25_LONGLEG_ENTER,
    BS_26_LONGLEG_IDLE = 0x26,
    BS_LONGLEG_WALK = 0x27,
    BS_LONGLEG_JUMP = 0x28,
    BS_LONGLEG_EXIT = 0x29,
    BS_BOMB = 0x2A,
    BS_2B_DIVE_IDLE = 0x2B,
    BS_2C_DIVE_B = 0x2C,
    BS_2D_SWIM_IDLE = 0x2D,
    BS_2E_SWIM = 0x2E,
    BS_2F_FALL = 0x2F,
    BS_30_DIVE_ENTER = 0x30,
    BS_ROLL = 0x31,
    BS_SLIDE = 0x32,
    //unk33,
    BS_34_JIG_NOTEDOOR = 0x34,
    BS_35_ANT_IDLE,
    BS_ANT_WALK = 0x36,
    BS_ANT_JUMP = 0x37,
    BS_38_ANT_FALL,
    BS_39_DIVE_A,
    BS_3A_CARRY_IDLE,
    BS_CARRY_WALK = 0x3B,
    BS_3C,
    BS_3D_FALL_TUMBLING,
    BS_3E_ANT_OW,
    BS_3F,
    BS_40_PUMPKIN_FLUSH,
    BS_41_DIE,
    BS_42_DINGPOT,
    BS_43_ANT_DIE,
    BS_44_JIG_JIGGY,
    BS_45_BTROT_SLIDE,
    //unk46
    //unk47
    BS_48_PUMPKIN_IDLE = 0x48,
    BS_49_PUMPKIN_WALK = 0x49,
    BS_4A_PUMPKIN_JUMP = 0x4A,
    BS_4B_PUMPKIN_FALL = 0x4B,
    BS_4C_LANDING_IN_WATER = 0x4c,
    BS_4D_PUMPKIN_OW = 0x4D,
    BS_4E_PUMPKIN_DIE = 0x4E,
    BS_4F_CLIMB_IDLE,
    BS_50_CLIMB_MOVE,
    BS_51_CLIMB_EXIT,
    //unk52 //tumblar??? a.k.a bssurf
    BS_53_TIMEOUT = 0x53,    
    BS_54_SWIM_DIE = 0x54,
    BS_LONGLEG_SLIDE = 0x55,
    BS_56_RECOIL = 0x56,
    BS_57_BOMB_END = 0x57,
    BS_58,
    BS_59_BFLY_UNK59 = 0x59,
    BS_5A_LOADZONE = 0x5A,
    BS_CARRY_THROW = 0x5B,
    
    BS_5E_CROC_IDLE = 0x5E,
    BS_CROC_WALK = 0x5F,
    BS_CROC_JUMP = 0x60,
    BS_61_CROC_FALL = 0x61,
    BS_62_LONGLEG_LOCKED = 0x62,
    BS_CROC_OW   = 0x63,
    BS_CROC_DIE = 0x64, 


    BS_67_WALRUS_IDLE = 0x67,
    BS_WALRUS_WALK = 0x68,
    BS_WALRUS_JUMP = 0x69,
    BS_6A_WALRUS_FALL = 0x6A,
    BS_6B_BEE_LOCKED,
    //unk0x6B //[107] = "Locked", -- Bee, Mumbo Transform Cutscene
    BS_WALRUS_OW = 0x6C,
    BS_WALRUS_DIE = 0x6D,
    BS_6E_CROC_BITE = 0x6E,
    BS_CROC_EAT_BAD = 0x6F,
    BS_70_CROC_EAT_GOOD = 0x70,
    BS_71_BTROT_FALL = 0x71,
    BS_SPLAT    = 0x72, //get up after fall damage
    BS_73_UNKNOWN = 0x73,
    BS_74_UNKNOWN = 0x74,
    BS_75_UNKNOWN = 0x75,
    //0x73 locked_cutscene
    //0x74 locked jiggypad, xform, bottles
    //0x75 locked bottles
    BS_76_BFLY_LOCKED = 0x76,
    BS_77_SWIM_LOCKED = 0x77, //0x77 locked swim
    BS_78_DIVE_LOCKED = 0x78,//0x78 locked dive
    BS_79_BTROT_LOCKED,
    BS_WALK_MUD,
    BS_BTROT_OW,
    BS_7C_SLED,
    BS_7D_WALRUS_SLED,
    BS_7E_WALRUS_SLED,
    BS_7F_DIVE_OW = 0x7F,
    BS_80_WALRUS_SLED_LOSE,
    BS_81_WALRUS_SLED_LOCKED = 0x81,
    BS_82_WALRUS_SLED_LOSE_IN_AIR,

    BS_85_BEE_IDLE = 0x85,
    BS_BEE_WALK = 0x86,
    BS_BEE_JUMP = 0x87,
    BS_88_BEE_FALL = 0x88,
    BS_BEE_OW = 0x89,
    BS_BEE_DIE = 0x8A,

    BS_BEE_FLY = 0x8c,
    BS_8D_CROC_LOCKED = 0x8D,
    BS_8E_ANT_LOCKED = 0x8E, //"Locked", -- Jiggy podium, Bottles' text outside Mumbo's
    BS_8F_PUMPKIN_LOCKED = 0x8F,
    
    BS_FLY_OW = 0x91,
    BS_92_ANT_DRONE,
    BS_93_PUMPKIN_DRONE,
    BS_94_CROC_DRONE,
    BS_95_WALRUS_DRONE,
    BS_96_SWIM_LOCKED,
    BS_97_DIVE_LOCKED,
    BS_98_WALK_DRONE,
	BS_99_BFLY_DRONE,
    BS_9A_BTROT_DRONE,
	BS_9B_LONGLEG_DRONE = 0x9B,
    BS_9C_WALRUS_SLED_DRONE = 0x9C,
    BS_9D_BEE_DRONE = 0x9D,
	BS_9E_CLIMB_LOCKED,
    BS_ANT_BOUNCE = 0x9F,
    BS_PUMPKIN_BOUNCE = 0xA0,
    BS_CROC_BOUNCE = 0xA1,
    BS_WALRUS_BOUNCE = 0xA2,
	BS_BEE_BOUNCE = 0xA3,
    BS_A4_WONDERWING_DRONE = 0xA4,
    BS_A5_WONDERWING_UNKA5
};

enum map_flags_e
{
    mapflag_mm_main_hit_with_orange = 8
};

enum item_e
{
    ITEM_0_HOURGLASS_TIMER = 0x0,
    ITEM_1_SKULL_HOURGLASS_TIMER,

    ITEM_3_PROPELLOR_TIMER = 0x3,

    ITEM_5_XMAS_TREE_TIMER = 0x5,
    ITEM_6_HOURGLASS,
    ITEM_7_SKULL_HOURGLASS,


    ITEM_9_PROPELLOR = 0x9,

    ITEM_B_XMAS_TREE = 0xb,
    ITEM_C_NOTE = 0xC,
    ITEM_D_EGGS,
    ITEM_E_JIGGY,
    ITEM_F_RED_FEATHER,
    ITEM_10_GOLD_FEATHER,

    ITEM_12_JINJOS = 0x12,
    ITEM_13_EMPTY_HONEYCOMB,
    ITEM_14_HEALTH,
    ITEM_15_HEALTH_TOTAL,
    ITEM_16_LIFE,
    ITEM_17_AIR,
    ITEM_18_GOLD_BULLIONS,
    ITEM_19_ORANGE,
    ITEM_1A_PLAYER_VILE_SCORE,
    ITEM_1B_VILE_VILE_SCORE,
    ITEM_1C_MUMBO_TOKEN,
    ITEM_1D_GRUMBLIE,
    ITEM_1E_YUMBLIE,
    ITEM_1F_GREEN_PRESENT,
    ITEM_20_BLUE_PRESENT,
    ITEM_21_RED_PRESENT,
    ITEM_22_CATERPILLAR,
    ITEM_23_ACORNS,
    ITEM_24_TWINKLY_SCORE,
    ITEM_25_MUMBO_TOKEN_TOTAL,
    ITEM_26_JIGGY_TOTAL,
    ITEM_27_JOKER_CARD,

    ITEM_2B_UNKNOWN = 0x2B //uses jiggy model
};

enum animctrl_direction_e
{
    mvmt_dir_forwards = 1
};

enum game_mode_e
{
    GAME_MODE_1_UNKNOWN = 1,
    GAME_MODE_2_UNKNOWN,
    GAME_MODE_3_NORMAL,
    GAME_MODE_4_PAUSED,
    GAME_MODE_5_UNKNOWN,
    GAME_MODE_6_FILE_PLAYBACK,
    GAME_MODE_7_ATTRACT_DEMO,
    GAME_MODE_8_BOTTLES_BONUS,
    GAME_MODE_9_BANJO_AND_KAZOOIE,
    GAME_MODE_A_SNS_PICTURE
};

enum asset_e
{
    ANIM_BANJO_CROUCH_ENTER = 0x1,
    ANIM_BANJO_WALK_CREEP = 0x2,
    ASSET_3_ANIM_BANJO_WALK = 0x3,

    ANIM_BANJO_BTROT_EXIT = 0x7,
    ANIM_BANJO_JUMP = 0x8,
    ASSET_9_ANIM_BANJO_DIE = 0x9,
    ASSET_A_ANIM_BANJO_CLIMB_MOVE,
    ANIM_BANJO_WALK_MUD,
    ANIM_BANJO_RUN,

    ANIM_BANJO_TURN = 0xe,

    ASSET_10_ANIM_BIGBUTT_RUN = 0x10,
    ASSET_11_ANIM_BSWONDERWING_WALK,

    ANIM_15_ANIM_BTROT_WALK = 0x15,
    ANIM_BANJO_LONGLEG_ENTER_AS_BEAR,
    ANIM_BANJO_BFLAP = 0x17,

    ANIM_BANJO_BPECK_ENTER = 0x19,
    ANIM_BANJO_BPECK = 0x1A,
    ANIM_BANJO_WONDERWING_JUMP = 0x1B,
    ANIM_BANJO_BBARGE = 0x1C,
    ANIM_BANJO_BBUSTER = 0x1D,
    
    ASSET_21_ANIM_BIGBUTT_SLIDE = 0x21,
    ANIM_BANJO_WONDERWING_EXIT = 0x22,
    ASSET_23_ANIM_BSWONDERWING_IDLE,

    ASSET_26_ANIM_BTROT_IDLE = 0x26,
    ANIM_BANJO_BTROT_JUMP = 0x27,
    ANIM_TERMITE_OW = 0x28,
    ANIM_TERMITE_DIE = 0x29,
    
    ANIM_BANJO_BJIG_JIGGY = 0x2e,

    ASSET_32_ANIM_BIGBUTT_ATTACK = 0x32,
    ASSET_33_ANIM_BIGBUTT_EAT,
    ASSET_34_ANIM_BIGBUTT_DIE,
    ASSET_35_ANIM_BIGBUTT_ALERT,
    ASSET_36_ANIM_BIGBUTT_WALK,

    ASSET_38_BANJO_FLY = 0x38,
    ASSET_39_ANIM_BSSWIM_SWIM,

    ANIM_BANJO_LONGLEG_JUMP     = 0x3D,

    ANIM_BANJO_LONGLEG_ENTER_AS_BIRD = 0x40,
    ASSET_41_ANIM_BSLONGLEG_IDLE,
    ASSET_42_ANIM_BSLONGLEG_WALK,
    ASSET_43_ANIM_BANJO_BEAKBOMB_START,

    ANIM_BANJO_FLY_ENTER        = 0x45,

    ANIM_BANJO_BSHOCK_CHARGE    = 0x48,
    ANIM_BANJO_BSHOCK_JUMP      = 0x49,

    ANIM_BANJO_BFLIP    = 0x4B,

    ANIM_BANJO_OW = 0x4D,
    anim_mudhut_smashing = 0x4E,
    ANIM_BANJO_ROLL = 0x4F,

    ASSET_51_ANIM_CONGA_IDLE     = 0x51,
    ASSET_52_ANIM_CONGA_OW,
    ASSET_53_ANIM_CONGA_DEFEAT,
    ASSET_54_ANIM_CONGA_THROW,
    ASSET_55_ANIM_CONGA_BEAT_CHEST,
    ASSET_56_ANIM_CONGA_RAISE_ARMS,
    ASSET_57_ANIM_BSSWIM_IDLE,
    
    ANIM_BANJO_SLIDE_BACK = 0x59,
    ANIM_BANJO_SLIDE_FRONT = 0x5A,

    ASSET_5E_ANIM_BSANT_IDLE = 0x5E,
    ASSET_5F_ANIM_BSANT_WALK = 0x5F,
    ANIM_TERMITE_JUMP = 0x60,

    ASSET_65_ANIM_BEEHIVE_DIE = 0x65,

    ASSET_6F_ANIM_BSSTAND_IDLE = 0x6F,
    ASSET_70_ANIM_BANJO_DIVE_IDLE,
    ASSET_71_ANIM_BANJO_BSDIVE_SWIM_SLOW,

    ASSET_94_ANIM_GRUBLIN_DIE = 0x94,

    ASSET_9E_ANIM_TEEHEE_IDLE = 0x9E,
    ASSET_9F_ANIM_TEEHEE_ALERTED,
    ASSET_A0_ANIM_BSPUMPKIN_WALK,

    ASSET_A3_ANIM_NAPPER_SLEEPING = 0xA3,
    ASSET_A4_ANIM_NAPPER_AWAKE,

    ASSET_A9_ANIM_FLOWER_POT = 0xA9,

    ASSET_AC_ANIM_TEEHEE_CHASE = 0xAC,

    ASSET_B1_ANIM_BSCLIMB_IDLE_1 = 0xb1,
    ASSET_B2_ANIM_BSCLIMB_IDLE_2,

    ASSET_C3_ANIM_CLANKER_IDLE = 0xC3,
    ASSET_C4_ANIM_CLANKER_BITE,
    ASSET_C5_ANIM_GRABBA_APPEAR,
    ASSET_C6_ANIM_GRABBA_HIDE,
    ASSET_C7_ANIM_GRABBA_IDLE,
    ASSET_C8_ANIM_GRABBA_DEFEATED,

    ASSET_CA_ANIM_GLOOP_SWIMMING    = 0xCA,
    ASSET_CB_ANIM_GLOOP_BLOWING_BUBBLE,
    ASSET_CC_ANIM_BANJO_BEAKBOMB_END,

    ASSET_D2_ANIM_BANJO_GETTING_UP = 0xD2,

    ASSET_D4_ANIM_SWITCH_DOWN = 0xD4,
    ASSET_D5_ANIM_SWITCH_UP,
    ASSET_D6_ANIM_TURBO_TALON_TRAINERS,

    ASSET_DB_ANIM_FLIBBIT_HOP = 0xDB,
    ASSET_DC_ANIM_GOBI_ROPE_PULLING,
    ASSET_DD_ANIM_GOBI_ROPE,

    ASSET_E0_ANIM_BSCROC_WALK = 0xE0,
    ASSET_E1_ANIM_BSCROC_IDLE = 0xE1,

    // ASSET_E5_ANIM_SLAPPA_APPEAR = 0xE5,
    // ASSET_E6_ANIM_SLAPPA_IDLE,
    // ASSET_E7_ANIM_SLAPPA_HIDE,
    // ASSET_E8_ANIM_SLAPPA_DIE,

    ASSET_ED_ANIM_ANCIENT_ONE = 0xED,

    ASSET_F0_ANIM_MINI_SHPYNX_EATING = 0xF0,
    ASSET_F1_ANIM_MAGIC_CARPET,

    ASSET_F4_ANIM_GOBI_IDLE = 0xF4,

    ASSET_F8_ANIM_GOBI_RUNNING = 0xF8,

    ASSET_FA_ANIM_FLIBBIT_IDLE = 0xFA,
    ASSET_FB_ANIM_FLIBBIT_TURN,
    ASSET_FC_ANIM_GOBI_SPITTING,
    ASSET_FD_ANIM_GOBI2_GETTING_UP,
    ASSET_FE_ANIM_TRUCKER_SHORT,
    ASSET_FF_ANIM_TRUCKER_GROW,

    ASSET_100_ANIM_GOBI_SPIT = 0x100,

    ASSET_108_ANIM_SIR_SLUSH_IDLE = 0x108,
    ASSET_109_ANIM_SIR_SLUSH_ATTACK,

    ANIM_BANJO_CROUCH = 0x10C,

    ASSET_112_ANIM_FLIBBIT_DIE = 0x112,
    ASSET_113_ANIM_FLIBBIT_DEAD,

    ANIM_BANJO_CROUCH_NOINPUT = 0x116,

    ASSET_11F_ANIM_BSWALRUS_IDLE = 0x11F,
    ASSET_120_ANIM_BSWALRUS_WALK = 0x120,

    ASSET_125_ANIM_YUMBLIE_APPEAR = 0x125,
    ASSET_126_ANIM_YUMBLIE_HIDE,
    ASSET_127_ANIM_YUMBLIE_IDLE,
    ASSET_128_ANIM_GRUMBLIE_APPEAR,
    ASSET_129_ANIM_GRUMBLIE_HIDE,
    ASSET_12A_ANIM_GRUMBLIE_IDLE,
    ASSET_12B_ANIM_TIPTUP_IDLE,
    ASSET_12C_ANIM_TIPTUP_TAPPING,
    ASSET_12D_ANIM_CHOIR_TURTLE_IDLE,
    ASSET_12E_ANIM_CHOIR_TURTLE_SING,
    ASSET_12F_ANIM_CHOIR_TURTLE_HURT,

    ASSET_132_ANIM_FLOTSAM_MOVE = 0x132,

    ASSET_138_ANIM_ZOOMBOX = 0x138,
    ASSET_139_ANIM_BOTTLES_EXIT,
    ASSET_13A_ANIM_BOTTLES_ENTER,
    ASSET_13B_ANIM_BOTTLES_IDLE,

    ASSET_13E_ANIM_SNORKEL_SWIM = 0x13E,
    ASSET_13F_ANIM_SNORKEL_STUCK,

    ASSET_141_ANIM_ANCHOR_LOWERED = 0x141,
    ASSET_142_ANIM_ANCHOR_RISING,
    ASSET_143_ANIM_SNOWMAN_BUTTON,

    ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR = 0x146,
    ASSET_147_ANIM_BOOMBOX_MOVE,
    ASSET_148_ANIM_BOOMBOX_DIE,

    ASSET_14A_ANIM_BANJO_LISTENING = 0x14A,

    ASSET_153_ANIM_BURIED_TREASURE_APPEAR = 0x153,

    ASSET_15A_ANIM_GRILL_CHOMPA_ATTACK = 0x15A,
    ASSET_15B_ANIM_GRILL_CHOMPA_DIE,
    ASSET_15C_ANIM_CLANKER_WHIPCRACK_IDLE,
    ASSET_15D_ANIM_CLANKER_WHIPCRACK_ATTACK,

    ASSET_162_ANIM_TOOTS_IDLE = 0x162,
    
    ASSET_164_ANIM_TOOTS_SING = 0x164,
    ASSET_165_ANIM_BEEHIVE_IDLE,
    ASSET_166_ANIM_BURIED_TREASURE_BOUNCE,

    ASSET_16F_ANIM_ZUBBA_FLY_MOVE = 0x16F,
    ASSET_170_ANIM_ZUBBA_FLY_IDLE,
    ASSET_171_ANIM_ZUBBA_DIE,
    ASSET_172_ANIM_ZUBBA_LAND,

    ASSET_176_ANIM_GOBI_YAWN = 0x176,
    ASSET_177_ANIM_GOBI_SLEEP,

    ASSET_17C_ANIM_TWINKLY_IDLE = 0x17C,
    ASSET_17D_ANIM_POLAR_BEAR_CUB_HAPPY = 0x17D,
    ASSET_17E_ANIM_POLAR_BEAR_CUB_SAD,

    ASSET_184_ANIM_CLUCKER_ATTACK_SHORT = 0x184,
    ASSET_185_ANIM_CLUCKER_ATTACK_LONG,
    ASSET_186_ANIM_CLUCKER_DIE,

    ASSET_189_ANIM_FLOTSAM_DIE = 0x189,
    ASSET_18A_XMAS_GIFT,

    ASSET_18E_ANIM_CATERPILLAR_IDLE = 0x18E,

    ASSET_19B_ANIM_UNKNOWN = 0x19B,

    ASSET_19E_ANIM_BSWALRUS_SLED = 0x19E,

    ASSET_1A1_ANIM_SLED = 0x1A1,
    ASSET_1A2_ANIM_NABNUT_SLEEP,

    ASSET_1AF_ANIM_TWINKLY_MUNCHER_APPEAR = 0x1AF,
    ASSET_1B0_ANIM_TWINKLY_MUNCHER_DIE,
    ASSET_1B1_ANIM_TWINKLY_MUNCHER_IDLE,
    ASSET_1B2_ANIM_TWINKLY_MUNCHER_ATTACK,

    ASSET_1DC_ANIM_BEE_FLY    = 0x1dc,
    ASSET_1DD_ANIM_BEE_WALK,
    ASSET_1DE_ANIM_BEE_IDLE,

    ASSET_1E0_ANIM_BEE_OW     = 0x1e0,
    ASSET_1E1_ANIM_BEE_DIE,
    ASSET_1E2_ANIM_BEE_JUMP,
    
    ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES = 0x1F5,

    ASSET_220_ANIM_SIR_SLUSH_DIE = 0x220,
    ASSET_221_ANIM_WOZZA_IN_CAVE,

    ASSET_228_ANIM_BANJO_SLED = 0x228,
    ASSET_229_ANIM_WHIPCRACK_ATTACK,
    ASSET_22A_ANIM_WHIPCRACK_IDLE,
    ASSET_22B_ANIM_NABNUT_FAT,
    ASSET_22C_ANIM_NAMBUT_CRY,
    ASSET_22D_ANIM_NAMBUT_BACKFLIP,
    ASSET_22E_ANIM_NAMBUT_STAND,
    ASSET_22F_ANIM_NAMBUT_RUN,

    ASSET_233_ANIM_ICECUBE  = 0x233,

    ASSET_238_ANIM_LOGGO_IDLE = 0x238,

    ASSET_240_ANIM_LOGGO_FLUSH = 0x240,

    ASSET_242_ANIM_GOBI_RELAXING  = 0x242,

    ASSET_253_ANIM_BIGBUTT_OW   = 0x253,
    ASSET_254_ANIM_BIGBUTT_FALL,
    ASSET_255_ANIM_BIGBUTT_GET_UP,

    ASSET_25B_ANIM_ACORN_IDLE = 0x25B,

    ASSET_281_ANIM_WISHYWASHY_DOOOH = 0x281,

    ASSET_288_ANIM_FLIBBIT_OW = 0x288,

    ASSET_2AB_ANIM_TEEHEE_DIE = 0x2AB,
    // 2d1 Grey House Brick (Upon Smashing MM Huts)
    ASSET_2D2_MODEL_ORANGE            = 0x2d2, //projectile
    // 2d3 MM Conga Tree
    // 2d4 (Shadow?)
    // 2d5 FP Blue Present
    // 2d6 FP Tartan Present
    // 2d7 FP Green/White Present
    // Unused
    // Unused
    // 2da TTC Palm Tree
    // 2db RBB Grey Toxic Barrel
    // 2dc RBB Yellow Toxic Barrel
    // 2dd Shock Jump Pad
    // Unused
    // 2df TTC Light Crate
    // 2e0 TTC Dark Crate
    // 2e1 TTC Light & Dark Crate
    // Unused
    // 2e3 RBB Light Pipe Opening
    // 2e4 RBB Dark Pipe Opening
    // 2e5 (Grey Pipe?)
    ASSET_2E6_MODEL_JUJU              = 0x2e6,
    // 2e7 (Grey Plank?)
    // 2e8 Flight Pad
    // 2e9 MM Orange Splat
    // Unused
    ASSET_2EB_MODEL_ORANGE_PAD        = 0x2eb,
    // Unused
    // 2ed Banjo's House Dustbin
    // 2ee Mumbo's On Vacation Sign
    // Unused
    // Unused
    // 2f1 MMM Tumblar
    // Unused
    // Unused
    // 2f4 CCW Autumn Leaf
    // 2f5 Green BK Flag Pole (Beta?)
    // 2f6 Blue BK Flag Pole (Beta?)
    // 2f7 CCW Spring Leaf
    // 2f8 RIP Tombstone
    // 2f9 Red BK Flag Pole (Beta?)
    // Unused
    // 2fb CCW Summer Leaf
    // 2fc MMM Grave Plot
    // Unused
    // Unused
    // 2ff MM Tree
    // 300 Jinxy Head
    ASSET_301_MODEL_5_MUMBO_TOKEN_SIGN = 0x301,
    ASSET_302_MODEL_10_MUMBO_TOKEN_SIGN,
    ASSET_303_MODEL_15_MUMBO_TOKEN_SIGN,
    ASSET_304_MODEL_20_MUMBO_TOKEN_SIGN,
    ASSET_305_MODEL_25_MUMBO_TOKEN_SIGN,
    // 306 (Grey Platform Red Top?)
    // Unused
    // 308 Clanker's Blue Ring
    ASSET_309_MODEL_CLANKER_TOKEN_TOOTH_EXTERIOR = 0x309,
    ASSET_30A_MODEL_CLANKER_JIGGY_TOOTH_EXTERIOR,
    // Unused
    // Unused
    ASSET_30D_MODEL_LEAFBOAT = 0x30D,
    // 30e (Wood Pipe?)
    // Unused
    // Unused
    // 311 Corn On The Cob
    // 312 Hamper
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 318 Melon
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 322 FP Present Stand Large
    // 323 FP Present Stand Small
    // 324 FP Present Ramp
    // 325 FP Icicle Large
    // 326 FP Icicle Small
    // Unused
    // Unused
    // 329 FP Stack Of Presents 1
    // Unused
    // Unused
    // Unused
    // 32d (Shadow)
    // 32e (Banjo's Pillow?)
    // 32f Corner Cobweb
    // 330 Banjo's Arm Chair
    // 331 Banjo's Towel Holder
    // 332 BGS Floating Log
    // 333 Banjo's Flower Pot
    // 334 Palm Tree
    // 335 BGS Cattail
    // 336 Banjo's Drawers
    // 337 Banjo's Kitchen
    // 338 Table And Radio
    // 339 Winter Tree
    // 33a Wall Torch
    // 33b Parasol
    // 33c GV Maze Pot
    // 33d GV Sarcophagus
    // 33e GV Rock 1 (Behind Entrance?)
    // 33f GV Rock 2 (Behind Entrance?)
    // 340 GL Beauty Stealing Machine
    // 341 GL Beauty Stealing Machine Console
    // 342 GV Short Platform
    // 343 Tooty Picture Frame
    // 344 (Wooden Block?)
    // 345 (Golden Block?)
    // 346 (Transparent Ice Floor?)
    // 347 GL Machine Room Door
    // 348 (Leaf Floor?)
    // 349 (Unknown?)
    // 34a Floor Cobweb
    // 34b Banjo's Bed
    // 34c Furnace Fun Booth
    // 34d Banjo Kazooie Low Poly Model
    // 34e Banjo Kazooie High Poly Model
    ASSET_34F_MODEL_BANJO_TERMITE = 0x34F,
    ASSET_350_MODEL_TERMITE,
    ASSET_351_MODEL_CLAM,
    ASSET_352_MODEL_SLED,
    ASSET_353_MODEL_BIGBUTT,
    ASSET_354_MODEL_BULL_INTRO,
    // 355 Concert Banjo Kazooie
    ASSET_356_MODEL_BANJO_WISHYWASHY = 0x356,
    // Unused
    // 358 TTC Snippet
    ASSET_358_SNIPPET = 0x358,
    ASSET_359_MODEL_BANJO_WALRUS,
    // 35a Concert Tooty
    ASSET_35B_FF_PRIZE_TOOTY = 0x35b,
    ASSET_35C_MODEL_CONGA,
    ASSET_35D_MODEL_CHIMPY,
    // 35e (Jiggy Podium?)
    ASSET_35F_MODEL_JIGGY = 0x35F,
    // 360 Blue Egg Fragment
    ASSET_361_MODEL_EMPTY_HONEYCOMB = 0x361,
    ASSET_362_MODEL_BANJO_BEE,
    ASSET_363_MODEL_HONEYCOMB,
    ASSET_364_MODEL_BEEHIVE,
    // Unused
    ASSET_366_MODEL_WADING_BOOTS = 0x366,
    ASSET_367_MODEL_TURBO_TALON_TRAINERS,
    // Unused
    // 369 Concert Frog
    // Unused
    ASSET_36B_CHUMP_FISH = 0x36B,
    // 36c Unused
    ASSET_36D_SPRITE_BLUE_EGG = 0x36D,
    ASSET_36E_MODEL_EXTRA_LIFE,
    ASSET_36F_MODEL_BANJO_PUMPKIN,
    ASSET_370_MODEL_BLUBBER,
    ASSET_371_MODEL_GRABBA,
    ASSET_372_MODEL_GLOOP,
    ASSET_373_MODEL_MR_VILE,
    ASSET_374_MODEL_BANJO_CROC = 0x374,
    ASSET_375_MODEL_FLIBBIT_RED,
    ASSET_376_MODEL_SLAPPA,
    ASSET_377_MODEL_SIR_SLUSH,
    ASSET_378_MODEL_SNOWBALL,
    // 379 Sir Slush Hat
    // 37a (Sir Slush Snowball?)
    // 37b Snowball Fragment
    // 37c Yum-Yum Large Shell Fragment
    // 37d Yum-Yum Eye
    // 37e Yum-Yum Small Shell Fragment
    // 37f (White Dot?)
    ASSET_380_MODEL_PINK_EGG_LARGEST = 0x380,
    ASSET_381_MODEL_PINK_EGG_LARGE,
    ASSET_382_MODEL_PINK_EGG_MEDIUM,
    ASSET_383_MODEL_PINK_EGG_SMALL,
    ASSET_384_MODEL_PINK_EGG_SMALLEST,
    // 385 Yellow Flibbit
    ASSET_385_MODEL_FLIBBIT_YELLOW = 0x385,
    // Unused
    ASSET_387_MODEL_BOTTLES = 0x387,
    ASSET_388_MODEL_MOLEHILL,
    // Unused
    ASSET_38A_MODEL_BOGGY_1 = 0x38A,
    // 38b Boggy Race Red Flag
    // 38c Snippet Claw
    // 38d Snippet Leg
    // 38e Snippet Head
    // 38f Mutie Snippet With Glow
    ASSET_38F_MODEL_MUTIE_SNIPPET = 0x38F,
    // 390 Mutie Snippet Head
    // 391 Mutie Snippet Leg
    // 392 Mutie Snippet Claw
    // 393 Ticker Leg
    // 394 Ticker Head No Eyes
    // 395 Ticker Body
    // 396 Ticker Eye
    // 397 BGS Large Alligator Head
    ASSET_397_MODEL_BIG_ALLIGATOR = 0x397,
    // 398 Concert Ant
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 3a6 Nintendo Cube
    // 3a7 Rareware Logo
    // 3a8 (Brown Triangle?)
    ASSET_3A9_MODEL_PALM_TREE = 0x3A9,
    // Unused
    // Unused
    // Unused
    // 3ad Fire Sparkle
    ASSET_3AE_MODEL_GRAVE_FLOWER_POT = 0x3AE,
    // 3af (Green Plank?)
    // 3b0 Snacker
    // 3b1 Concert Mumbo
    // 3b2 (Two Poles?)
    // 3b3 Mumbo's Hut
    // Unused
    // Unused
    // 3b6 TTC Stairs 1
    // 3b7 TTC Stairs 2
    // Unused
    // Unused
    // Unused
    ASSET_3BB_MODEL_JINJO_YELLOW = 0x3BB,
    ASSET_3BC_MODEL_JINJO_ORANGE,
    // 3bd TTC Lighthouse A
    // 3be TTC Lighthouse B
    ASSET_3BF_MODEL_PLAYER_SHADOW = 0x3BF,
    ASSET_3C0_MODEL_JINJO_BLUE,
    ASSET_3C1_MODEL_JINJO_PINK,
    ASSET_3C2_MODEL_JINJO_GREEN,
    // Unused
    // Unused
    ASSET_3C5_MODEL_GRUBLIN           = 0x3c5,
    // 3c6 Mumbo
    ASSET_3C7_MODEL_GOLD_BULLION      = 0x3c7,
    ASSET_3C8_MODEL_CHIMPY_STUMP,
    ASSET_3C9_MODEL_RIPPER,
    ASSET_3CA_MODEL_BAT,
    ASSET_3CB_MODEL_TEEHEE            = 0x3cb,
    // 3cc MMM Barrel Lid
    // 3cd MMM Tumblar Door
    // 3ce MMM Mansion Door
    // 3cf MMM Cellar Hatch
    // 3d0 MMM Locked Gate (Lock On Left)
    // 3d1 MMM Locked Gate (Lock On Right) 1
    // 3d2 TTC Blubber's Ship Top Hatch
    // 3d3 MMM Church Door
    // 3d4 Lockup
    ASSET_3D4_MODEL_LOCKUP = 0x3d4,
    ASSET_3D5_MODEL_NIPPER,
    ASSET_3D6_MODEL_LIGHTHOUSE_DOOR,
    ASSET_3D7_MODEL_STAR_SWITCH,
    ASSET_3D8_MODEL_GV_BANJO_DOOR,
    ASSET_3D9_MODEL_GV_KAZOOIE_DOOR,
    // 3da GV Sun Door
    ASSET_3DB_MODEL_GV_STAR_HATCH = 0x3db,
    ASSET_3DC_MODEL_MAGIC_CARPET,
    ASSET_3DD_MODEL_RUBEE,
    ASSET_3DE_MODEL_HISTUP,
    ASSET_3DF_MODEL_TRUNKER,
    ASSET_3E0_MODEL_GOBI,
    ASSET_3E1_MODEL_RUBEES_EGG_POT = 0x3E1,
    ASSET_3E2_MODEL_GV_KAZOOIE_TARGET = 0x3E2,
    ASSET_3E3_MODEL_GOBI_ROPE,
    // 3e4 GV Gobi's Rock
    // 3e5 GV Hand Shadow
    // 3e6 GV Jinxy Head 2
    ASSET_3E7_MODEL_MAGIC_CARPET_SHADOW = 0x3e7,
    ASSET_3E8_MODEL_ANCIENT_ONE,
    ASSET_3E9_MODEL_RED_ARROW,
    ASSET_3EA_MODEL_RED_X,
    ASSET_3EB_MODEL_RED_QUESTION_MARK,
    ASSET_3EC_MODEL_SHRAPNEL,
    ASSET_3ED_MODEL_BUZZBOMB,
    ASSET_3EE_TANKTUP,
    ASSET_3EF_MODEL_TANKTUP_LEG_FL,
    ASSET_3F0_MODEL_TANKTUP_LEG_BL,
    ASSET_3F1_MODEL_TANKTUP_LEG_FR,
    ASSET_3F2_MODEL_TANKTUP_LEG_BR,
    ASSET_3F3_MODEL_GOBI_SPIT,
    // Unused
    // 3f5 BGS Green Jiggy Switch
    ASSET_3F5_BGS_JIGGY_SWITCH = 0x3F5,
    ASSET_3F6_MODEL_YUMBLIE,
    ASSET_3F7_MODEL_GRUMBLIE,
    ASSET_3F8_MODEL_TIPTUP,
    ASSET_3F9_MODEL_CHOIR_TURTLE,
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    ASSET_3FF_MODEL_GV_SUN_DOOR = 0x3FF,
    ASSET_400_MODEL_SUN_SWITCH,
    ASSET_401_MODEL_FLOTSAM,
    ASSET_402_MODEL_EGG_TOLL,
    ASSET_403_MODEL_RUSTY_BUCKET_REAR_PROPELLER,
    // 404 RBB Green Propeller Switch (Stop Propellers)
    // 405 RBB Grey Propeller Switch (Stop Propellers)
    // 406 RBB Thin Shaft
    // 407 RBB Double Shaft 1
    // 408 RBB Double Shaft 2
    // 409 RBB Small Cog
    // 40a RBB Medium Cog
    // 40b RBB Large Cog
    // 40c RBB Spinning Platform 1
    // 40d RBB Spinning Platform 2
    // 40e RBB Spinning Platform 3
    ASSET_40F_MODEL_ENGINE_ROOM_PROPELLER_1 = 0x40f,
    ASSET_410_MODEL_ENGINE_ROOM_PROPELLER_2,
    ASSET_411_MODEL_ENGINE_ROOM_PROPELLER_3,
    // 412 RBB Grey Propeller Switch (Slow Fans)
    // 413 RBB 1 Switch
    // 414 RBB 2 Switch
    // 415 RBB 3 Switch
    // 416 RBB Whistle 1 (Yellow)
    // 417 RBB Whistle 2 (Gold)
    // 418 RBB Whistle 3 (Blue)
    ASSET_419_MODEL_GRIMLET = 0x419,
    ASSET_41A_SPRITE_MUMBO_TOKEN,
    // 41b RBB Anchor Button
    // 41c Snorkel
    // 41d RBB Anchor & Chain
    // 41e RBB Rareware Flag
    // 41f (Gruntilda's Final Battle Forcefield?)
    // 420 (Explosion 2D?)
    ASSET_421_MODEL_FP_SNOWMAN_BUTTON = 0x421,
    ASSET_422_MODEL_JINXY,
    // Unused
    // 424 GV Cactus
    ASSET_425_MODEL_CROCTUS = 0x425,
    // 426 FP Christmas Tree Star
    // 427 (Wooden Plank)
    ASSET_428_MODEL_BOSS_BOOM_BOX = 0x428,
    ASSET_429_MODEL_CC_KEY,
    // 42a (Smoke 2D?)
    // 42b (Orange Triangle?)
    ASSET_42C_MODEL_BURIED_TREASURE = 0x42C,
    ASSET_42D_MODEL_QUARRIE = 0x42D,
    // 42d SM Quarrie
    // 42e SM Quarrie Fragment
    // 42f RBB Empty Honeycomb Button
    ASSET_430_MODEL_GRILL_CHOMPA = 0x430,
    // 431 Beta Vent
    ASSET_432_MODEL_CLANKER_WHIPCRACK = 0x432,
    // Unused
    ASSET_434_MODEL_TOOTS = 0x434,
    // 435 CC Green Grate
    // 436 CC Teal Grate
    // 437 (Unknown?)
    ASSET_438_MODEL_HONEYCOMB_SWITCH = 0x438,
    // 439 (Unknown?)
    ASSET_43A_MODEL_CLANKER_SAWBLADE_PROPELLOR = 0x43A,
    // 43b RBB Bell Buoy
    // 43c RBB Row Boat
    // 43d MMM Church Clock Switch
    // 43e MMM Locked Gate (Lock On Right) 2
    // 43f (White Star?)
    ASSET_440_MODEL_SNAREBEAR = 0x440,
    // 441 (Sir Slush Snowball?)
    // 442 FP Twinklies Box
    // 443 CCW Zubba Honey Lump
    // 444 (CCW Zubba Entrance Lid?)
    // 445 (CCW Zubba Entrance Lid?)
    ASSET_446_MODEL_ZUBBA = 0x446,
    // 447 CCW Beanstalk
    ASSET_448_MODEL_TWINKLY_BLUE = 0x448,
    ASSET_449_MODEL_TWINKLY_GREEN,
    ASSET_44A_MODEL_TWINKLY_ORANGE,
    ASSET_44B_MODEL_TWINKLY_RED,
    ASSET_44C_MODEL_POLAR_BEAR_CUB_BLUE,
    ASSET_44D_MODEL_POLAR_BEAR_CUB_GREEN,
    ASSET_44E_MODEL_POLAR_BEAR_CUB_RED,
    // 44f (Green Mist?)
    // 450 Dingpot
    // 451 Gruntilda
    // 452 Gruntilda's Arms
    // 453 Dingpot Top
    // 454 Tooty Image In Dingpot
    // 455 MMM Limbo
    // 456 Gruntilda's Broomstick
    // 457 Gruntilda Riding Broomstick
    // 458 Banjo Top Half
    // 459 Banjo's Bed
    ASSET_45A_SPRITE_GREEN_GLOW     = 0x45A,
    // 45b Kazooie In Backpack Stand
    // 45c Banjo's House Curtains
    // 45d (Unknown)
    // 45e Banjo's House Door
    // 45f (Firey Rock?)
    // 460 (Kazooie Wing?)
    // 461 (Green Smog Ceiling?)
    // 462 Nabnut's Girlfriend
    // 463 Nabnut's Bed Sheet
    // 464 Nabnut's Bed
    // 465 Dead Snarebear
    // 466 (Sparkle 2D?)
    ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES = 0x467,
    // 467 (Blank Picture Frame?)
    // 468 Sexy Grunty
    // 469 Ugly Tooty
    // 46a Klungo
    // 46b Beauty Machine Room Force Field
    // 46c Jiggy Picture
    // 46d Lightning
    // 46e Roysten In Bowl
    // 46f Coocoo Clock
    // 470 Banjo's Bookshelves
    // 471 Empty Blow Picture Frame
    // 472 Blank Picture
    // 473 Mumbo The BBQ King! He Bares Coconuts!
    // 474 Roysten The Grill Master!
    // 475 (Heart 2D?)
    ASSET_476_SPRITE_BLUE_GLOW     = 0x476,
    ASSET_477_SPRITE_YELLOW_GLOW,
    // 478 (Yellow Glow?)
    // 479 Bikini Girl
    // 47a (Brown Ball?)
    ASSET_47B_MODEL_ROCK    = 0x47b,
    // 47c (Snoring Z 2D?)
    // Unused
    // Unused
    ASSET_47F_MODEL_XMAS_GIFT_BLUE = 0x47F,
    ASSET_480_MODEL_XMAS_GIFT_GREEN,
    ASSET_481_MODEL_XMAS_GIFT_RED,
    ASSET_482_MODEL_CLUCKER,
    ASSET_483_MODEL_EAGLE_EGG,
    ASSET_484_MODEL_EAGLE_BABY,
    ASSET_485_MODEL_CATERPILLAR,
    ASSET_486_MODEL_XMAS_TREE_SWITCH,
    ASSET_487_MODEL_EAGLE_ADULT,
    ASSET_488_MODEL_XMAS_TREE,
    ASSET_489_MODEL_SHOCKSPRING_PAD,
    ASSET_48A_MODEL_FLIGHT_PAD,
    ASSET_48B_MODEL_JIGGY_PODIUM,
    ASSET_48C_MODEL_BOOM_BOX,
    // 48d Nabnut Eating Acorns
    ASSET_48E_MODEL_ACORN = 0x48E,
    // 48f Gnawty
    // 490 Gnawty's Boulder
    // 491 Note Door
    // 492 (Wooden Door?)
    // 493 RBB Engine Room Door
    ASSET_494_MODEL_WOZZA = 0x494,
    ASSET_495_MODEL_WOZZAS_JIGGY,
    ASSET_496_MODEL_TWINKLY_MUNCHER,
    ASSET_497_MODEL_TWINKLY_SHARD_BLUE,
    ASSET_498_MODEL_TWINKLY_SHARD_YELLOW,
    ASSET_499_MODEL_TWINKLY_SHARD_GREEN = 0x499,
    ASSET_49A_MODLE_TWINKLY_SHARD_ORANGE,
    ASSET_49B_MODEL_TWINKLY_SHARD_RED,
    // 49c (Green & Red Area?)
    ASSET_49D_MODEL_SEAMAN_GRUBLIN = 0x49D,
    // 49e 2D Bee (Used In Swarms)
    // 49f 2D Glowing Bee (Beta)
    ASSET_4A0_SPRITE_EXPLOSION = 0x4A0,
    // 4a1 Brick Wall Near GV Entrance
    // 4a2 Mumbo's Mountain Door Entrance
    // 4a3 TTC Entrance Chest Lid
    // 4a4 Clanker's Entrance Long Pipe (Green)
    // 4a5 Clanker's Entrance Long Pipe (Blue)
    // 4a6 Clanker's Entrance Short Pipe
    // 4a7 Clanker's Entrance Iron Bars
    // 4a8 Bubblegloop Swamp Puzzle Grate
    // 4a9 Raise Pipe Switch (Path To CC)
    // 4aa Raise Pipe Switch (Path To Brentilda)
    // 4ab Raise Grate To BGS Puzzle
    // 4ac Iron Bars Under Gruntilda Statue
    // 4ad Gruntilda Statue Hat Top
    // 4ae Bubblegloop Swamp Entrance Door
    // 4af (Ice Ball?)
    // 4b0 Level 3 Water Switch
    // 4b1 Grate To Level 3 Water Switch
    // 4b2 Level 2 Water Switch
    // 4b3 Rareware Box (To Hide Water Switch?)
    // 4b4 Rusty Bucket Bay Entrance Door
    // 4b5 Level 1 Water Switch
    // 4b6 Grate Between MMM and RBB Puzzles
    // 4b7 Grate To RBB Puzzle
    // 4b8 CCW Puzzle Switch
    // 4b9 (Jiggy Switch Beta?)
    // 4ba RBB Window 1
    // 4bb RBB Window 2
    // 4bc GV Entrance Door
    ASSET_4BD_MODEL_GLASS_EYE = 0x4BD,
    // 4bd Gruntilda Head Eyeball
    // 4be MMM Entrance Door
    // 4bf GL Yellow Floor Cobweb
    // 4c0 MMM Window
    // 4c1 MMM Short Window
    // 4c2 MMM Tall Window
    // 4c3 FP House
    // 4c4 FP Frozen Mumbo Hut
    // 4c5 FP Stack Of Presents 2
    // 4c6 FP Snowy Bridge
    ASSET_4C7_MODEL_MUMMUM = 0x4C7,
    ASSET_4C8_MODEL_MUMMUM_ARM,
    ASSET_4C9_MODEL_MUMMUM_LEG,
    ASSET_4CA_MODEL_MUMMUM_HEAD,
    ASSET_4CB_MODEL_MUMMUM_BODY,
    ASSET_4CC_MODEL_LIMBO,
    ASSET_4CD_MODEL_LIMBO_ARM,
    ASSET_4CE_MODEL_LIMBO_LEG,
    ASSET_4CF_MODEL_LIMBO_HEAD,
    ASSET_4D0_MODEL_LIMBO_BONE,
    // Unused
    // 4d2 FP Christmas Tree Glass Container
    // 4d3 FP Christmas Tree Glass Container Fragment
    ASSET_4D4_MODEL_TWINKLY_BOX_PAPER_SHARD = 0x4D4,
    // 4d5 GL Yellow Wall Cobweb
    // 4d6 Click Clock Wood Entrance Door
    // 4d7 Freezeezy Peak Entrance Left Door
    // 4d8 Freezeezy Peak Entrance Right Door
    // 4d9 Freezeezy Peak Entrance Hatch Door
    // 4da (Wooden Door?)
    // 4db RBB Saftey Boat 1
    ASSET_4DC_MODEL_WITCH_SWITCH = 0x4DC,
    // 4dd Mumbo Skull Switch
    // 4de RBB Safety Boat 2
    // 4df Cauldron (Grey)
    // 4e0 CCW Season Door
    // 4e1 GL Wooden Coffin
    // 4e2 RBB Skylights (Shattered Window)
    // 4e3 CCW Dead Beanstalk
    // 4e4 Snore 'Z'
    // 4e5 FP Three Purple Ice Crystals
    // 4e6 FP Three Blue Ice Crystals
    // 4e7 FP Three Green Ice Crystals
    // 4e8 FP One Blue Ice Crystals (Large)
    // 4e9 FP One Blue Ice Crystals (Small)
    // 4ea FP Finish Banner
    // 4eb FP Start Banner
    // 4ec FP Race Rostrum
    MODEL_TOPPER            = 0x4ed,
    MODEL_COLLYWOBBLE       = 0x4ee,
    MODEL_BAWL              = 0x4ef,
    // 4f0 Colliwobble Large Stem (Upon Death)
    // 4f1 Colliwobble Small Stem (Upon Death)
    // 4f2 Colliwobble Large Leaf (Upon Death)
    // 4f3 Colliwobble Small Leaf (Upon Death)
    // 4f4 Colliwobble Stem (Upon Death)
    // 4f5 CCW Spring Switch
    // 4f6 CCW Summer Switch
    // 4f7 CCW Autumn Switch
    // 4f8 CCW Winter Switch
    // 4f9 CCW Nabnut's Window (Season?)
    // 4fa CCW Nabnut's Window (Season?)
    // 4fb CCW Nabnut's Window (Winter)
    // 4fc CCW Nabnut's Window (Season?)
    ASSET_4FD_MODEL_WHIPCRACK = 0x4fd,
    ASSET_4FE_MODEL_WHIPCRACK_PART_1,
    ASSET_4FF_MODEL_WHIPCRACK_PART_2,
    ASSET_500_MODEL_WHIPCRACK_PART_3,
    // 501 CCW Mound Of Acorns
    ASSET_502_MODEL_NABNUT = 0x502,
    // 503 Nabnut (Belly Full)
    ASSET_504_MODEL_ICECUBE       = 0x504,
    ASSET_505_MODEL_ICECUBE_CHUNK,
    // 506 CCW Dead Snarebear (Venus Flytrap)
    // 507 GL Grunty Floor Picture Eye 1
    // 508 GL Grunty Floor Picture Eye 2
    // 509 GL Jinxy Sarcophagus
    ASSET_50A_MODEL_SHARKFOOD_ISLAND = 0x50A,
    // 50B MMM Secret X-Barrel Lid
    ASSET_50C_MODEL_ICE_KEY = 0x50C,
    ASSET_50D_MODEL_SNS_EGG,
    // 511 GL Wooden Coffin Lid
    // 512 (Piece Of Glass Panel Blocking Ice Key 1?)
    // 513 (Piece Of Glass Panel Blocking Ice Key 2?)
    ASSET_514_MODEL_GV_SNS_CHAMBER_DOOR = 0x514,
    ASSET_515_MODEL_GV_SNS_SWITCH,
    // 516 (Wooden Plank?)
    // 517 Iron Gate (No Lock)
    // 518 CCW Wooden Door (To Whipcrack Room)
    ASSET_519_MODEL_LOGGO = 0x519,
    ASSET_51A_MODEL_LEAKY,
    ASSET_51B_MODEL_SCARAB_BEETLE,
    ASSET_51C_MODEL_SCARAB_BEETLE_PART_1,
    // 51d SCARAB BEETLE PART (Wing)
    ASSET_51E_MODEL_SCARAB_BEETLE_PART_2 = 0x51e,
    ASSET_51F_MODEL_SCARAB_BEETLE_PART_3,
    ASSET_520_MODEL_SCARAB_BEETLE_PART_4,
    ASSET_521_MODEL_PORTRAIT_CHOMPA,
    ASSET_522_MODEL_PORTRAIT_OF_GRUNTY,
    ASSET_523_MODEL_PORTRAIT_CHOMPA_TEETH,
    ASSET_524_MODEL_PORTRAIT_CHOMPA_HEAD,
    ASSET_525_MODEL_PORTRAIT_CHOMPA_PART,
    ASSET_526_SPRITE_FIRE,
    ASSET_527_MODEL_PORTRAIT_OF_BLACKEYE,
    ASSET_528_MODEL_PORTRAIT_OF_TOWER,
    ASSET_529_MODEL_PORTRAIT_OF_TREE_AND_MOON,
    ASSET_52A_MODEL_PORTRAIT_OF_TEEHEE,
    ASSET_52B_MODEL_PORTRAIT_OF_MINION,
    ASSET_52C_MODEL_GRUBLIN_HOOD,
    ASSET_52D_MODEL_GRUBLIN_HOOD_HAT,
    // 52e (CCW Season Door?)
    // 52f Banjo's Chair (Secret Spring)
    // 530 Banjo's Bed (Secret Spring?)
    // 531 Gnawty's Den
    // 532 Banjo & Kazooie (Gameboy/Beer/Sunglasses/Chair)
    // 533 CCW Nabnut's Door
    // 534 GL Flight Pad Switch
    // 535 Flight Pad Blue Fragment
    // 536 Flight Pad Red Fragment
    // 537 Flight Pad Yellow Fragment
    // 538 Jiggy Podium (Beta?)
    // 539 Brentilda
    ASSET_53A_MODEL_SHRAPNAL_PIECE_EYE = 0x53A,
    ASSET_53B_MODEL_SHRAPNAL_PIECE_SPIKE,
    ASSET_53C_MODEL_SHRAPNAL_PIECE_PLATE,
    ASSET_53D_MODEL_GRUNTILDA_FINAL_BOSS,
    // 53e Gnawty's Bed
    // 53f Gnawty's Shelves
    // 540 GL Shock Jump Pad Switch
    ASSET_541_SPRITE_FIREBALL_SPELL_ATTACK = 0x541,
    // 542 (Shadow?)
    ASSET_543_MODEL_JINJO_STATUE_BASE = 0x543,
    ASSET_544_MODEL_JINJONATOR_STATUE_BASE,
    ASSET_545_MODEL_STONE_JINJO,
    ASSET_546_MODEL_GRUNTY_SPELL_BARRIER = 0x546,
    // 547 GL Blue Egg Refill Pillow
    // 548 GL Red Feather Refill Pillow
    // 549 GL Gold Feather Refill Pillow
    ASSET_54A_MODEL_GRUNTLING_RED = 0x54A,
    // 54b (Big Fireball?)
    ASSET_54C_MODEL_GAME_OVER = 0x54C,
    // 54d Banjo-Kazooie Sign
    // 54e Copyright Info (Title Screen)
    // 54f Cheato
    // 550 Large Door To Final Battle
    ASSET_551_MODEL_JINJONATOR = 0x551,
    ASSET_552_MODEL_BROOMSTICK_PIECE_HEAD,
    ASSET_553_MODEL_BROOMSTICK_PIECE_SHORT,
    ASSET_554_MODEL_BROOMSTICK_PIECE_LONG,
    ASSET_555_MODEL_BROOMSTICK_PIECE_EYE,
    // 556 Blast When Yellow Jinjo Hits Gruntilda
    // 557 Blast When Orange Jinjo Hits Gruntilda
    // 558 Blast When Green Jinjo Hits Gruntilda
    // 559 Blast When Pink Jinjo Hits Gruntilda
    // 55a BK World Entry/Exit Pad
    // 55b FP Boggy's Igloo
    // 55c Press Start Sign
    // 55d No Controller Sign
    ASSET_55E_MODEL_NAPPER = 0x55E,
    ASSET_55F_MODEL_FF_PRIZE_WASHING_CAULDRON,
    ASSET_560_MODEL_FF_PRIZE_GRUNTY_DOLL,
    ASSET_561_MODEL_GRUNTLING_BLUE = 0x561,
    ASSET_562_MODEL_GRUNTLING_BLACK,
    // 563 Level Entry Signs
    ASSET_564_MODEL_PURPLE_TEEHEE = 0x564,
    // 565 Bottles Game Banjo's Hand
    ASSET_566_MODEL_BLACK_SNIPPET = 0x566,
    // 567 Black Snippet Body (Upon Death)
    // 568 Black Snippet Leg (Upon Death)
    // 569 Black Snippet Pincer (Upon Death)
    // 56a FP Chimney
    ASSET_56B_MODEL_SANDYBUTT_PYRAMID = 0x56B,
    // 56c The End Sign
    // 56d (Human Hand?)
    // 56e Hammerhead Beach Scenery
    // Unused
    // Unused
    // Unused
    // 572 Palm Tree (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    ASSET_580_SPRITE_RED_FEATHER = 0x580,
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5a9 Flower
    // Unused
    // Unused
    // 5ac Red Mushroom
    // 5ad Green Mushroom
    // 5ae Blue Mushroom
    // Unused
    // Unused
    // 5b1 Pink Mushroom
    // 5b2 Purple Mushroom
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5b8 Flower
    // 5b9 Flower
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5c2 Flower
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5cf Weed
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5d5 Tree (Intro)
    // 5d6 Tree (Intro)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 5df Tree
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 606 Red Mushroom
    // 607 Green Mushroom
    // 608 White Circle
    // 609 Mushroom (2D)
    // Unused
    // Unused
    // 60c Cattail (2D)
    // 60d Cattail (2D)
    // 60e Cattail (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 648 Orange (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 68c Grass (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 693 Seashell (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // 6b1 Weed (2D)
    // 6b2 Purple Weed (2D)
    // 6b3 White Weed (2D)
    // Unused
    // Unused
    // Unused
    // 6b7 Fire (2D)
    // 6b8 Green Glow (2D)
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    ASSET_6C1_SPRITE_SMOKE = 0x6C1,
    ASSET_6C2_SPRITE_SMOKE_WHITE,
    ASSET_6C3_SPRITE_SMOKE_GREEN,
    ASSET_6C4_SPRITE_SMOKE_YELLOW,
    ASSET_6C5_SPRITE_SMOKE_ORANGE,
    ASSET_6C6_SPRITE_SMOKE_PINK,
    ASSET_6C7_SPRITE_SMOKE_GREEN_2,
    ASSET_6C8_SPRITE_SMOKE_BLUE,
    ASSET_6C9_SPRITE_GREEN_SPELL_ATTACK,

    ASSET_6D1_SPRITE_GOLDFEATHTER = 0x6d1,

    ASSET_6D6_MODEL_MUSIC_NOTE = 0x6d6,

    ASSET_6D9_SPRITE_PROPELLOR_TIMER = 0x6d9,
    ASSET_6DA_SPRITE_HOURGLASS,
    ASSET_6DB_SPRITE_SKULL_HOURGLASS,
    ASSET_6DC_SPRITE_XMAS_TREE_TIMER,

    SPRITE_DIALOG_FONT_ALPHAMASK = 0x6eb,
    SPRITE_BOLD_FONT_LETTERS_ALPHAMASK,
    SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK,

    ASSET_700_SPRITE_DUST  = 0x700,
    ASSET_701_SPRITE_LENS_SHUTTER_MASK,
    ASSET_702_SPRITE_UNKNOWN,

    ASSET_708_SPRITE_EGG_PROJECTILE = 0x708,

    ASSET_70A_SPRITE_BUBBLE_1 = 0x70a,
    ASSET_70B_SPRITE_BUBBLE_2,
    ASSET_70C_SPRITE_RIPPLE,
    ASSET_70D_SPRITE_SMOKE_1,
    ASSET_70E_SPRITE_SMOKE_2,

    ASSET_710_SPRITE_SPARKLE_PURPLE = 0x710,
    ASSET_711_SPRITE_SPARKLE_DARK_BLUE,


    ASSET_713_SPRITE_SPARKLE_YELLOW = 0x713,

    ASSET_715_SPRITE_SPARKLE_RED = 0x715,
    ASSET_716_SPRITE_SPARKLE_WHITE,
    ASSET_717_SPRITE_SPARKLE_YELLOW_2,
    ASSET_718_SPRITE_SPARKLE_WHITE_2,
    ASSET_719_SPRITE_SPARKLE_GREEN_2,
    ASSET_71A_SPRITE_SPARKLE_PINK_2,
    ASSET_71B_SPRITE_SPARKLE_ORANGE_2,

    ASSET_7BD_MODEL_SKYBOX_MM = 0x7BD,
    ASSET_7BE_MODEL_CLOUDS_MM,
    ASSET_7BF_MODEL_SKYBOX_TTC,
    ASSET_7C0_MODEL_CLOUDS_TTC,
    ASSET_7C1_MODEL_SKYBOX_GV,
    ASSET_7C2_MODEL_SKYBOX_MMM,
    ASSET_7C3_MODEL_SKYBOX_MMM,
    ASSET_7C4_MODEL_SKYBOX_SM,
    ASSET_7C5_MODEL_SKYBOX_RBB,
    ASSET_7C6_MODEL_SKYBOX_FP,
    ASSET_7C7_MODEL_CLOUDS_FP_A,
    ASSET_7C8_MODEL_CLOUDS_FP_B,
    ASSET_7C9_MODEL_SKYBOX_INTRO_N64,
    ASSET_7CA_MODEL_SKYBOX_LAIR_MMM,
    ASSET_7CB_MODEL_CLOUDS_LAIR_MMM,
    ASSET_7CC_MODEL_SKYBOX_GRUNTYS_FALL,
    ASSET_7CD_MODEL_SKYBOX_BEACH_ENDING,

    ASSET_7CF_MODEL_TRANSITION_UNKNOWN = 0x7CF,
    ASSET_7D0_MODEL_TRANSITION_JIGGY,

    ASSET_7D4_MODEL_TRANSITION_WITCH = 0x7D4,

    ASSET_7D7_MODEL_MM_HUT     = 0x7d7,
    ASSET_7D8_MODEL_MM_HUT_TOP,
    ASSET_7D9_SPRITE_NOTE,

    ASSET_7DD_SPRITE_HEALTH = 0x7dd,

    ASSET_7E5_SPRITE_WATER_HONEYCOMB = 0x7e5,
    ASSET_7E6_SPRITE_VILE, 
    ASSET_7E7_SPRITE_CROC_BANJO,

    ASSET_7EE_JOKER_CARD = 0x7ee,
    ASSET_7EF_SPRITE_BANJO,
    ASSET_7F0_SPRITE_BOTTLES,
    ASSET_7F1_SPRITE_BLUBBER,
    ASSET_7F2_SPRITE_CONGA,
    ASSET_7F3_SPRITE_TEEHEE,
    ASSET_7F4_SPRITE_KAZOOIE,
    ASSET_7F5_SPRITE_CHIMPY,
    ASSET_7F6_SPRITE_FLIBBIT,
    ASSET_7F7_SPRITE_GOBI,
    ASSET_7F8_SPRITE_TANKTUP,
    ASSET_7F9_SPRITE_TIPTUP,
    ASSET_7FA_SPRITE_WARP_CAULDRON,
    ASSET_7FB_SPRITE_RUBEE,
    ASSET_7FC_SPRITE_MUMBO,
    ASSET_7FD_SPRITE_NIPPER,
    ASSET_7FE_SPRITE_CLANKER,
    ASSET_7FF_SPRITE_GRABBA,
    ASSET_800_SPRITE_SNIPPET,
    ASSET_801_SPRITE_TRUNKER,
    ASSET_802_SPRITE_JINJO_YELLOW,
    ASSET_803_SPRITE_JINJO_GREEN,
    ASSET_804_SPRITE_JINJO_BLUE,
    ASSET_805_SPRITE_JINJO_PINK,
    ASSET_806_SPRITE_JINJO_ORANGE,

    ASSET_808_SPRITE_LIVE_MUMBO_TOKEN = 0x808,
    ASSET_809_SPRITE_CATERPILLAR,

    ASSET_80C_SPRITE_LIVE_WADING_BOOTS = 0x80c, 
    ASSET_80D_SPRITE_LIVE_JIGGY,
    ASSET_80E_SPRITE_LIVE_EXTRA_LIFE,
    ASSET_80F_SPRITE_LIVE_GOLD_BULLION,
    ASSET_810_SPRITE_LIVE_HONEYCOMB,

    ASSET_812_SPRITE_LIVE_EMPTY_HONEYCOMB = 0x812,
    ASSET_813_SPRITE_PIRANHA,
    ASSET_814_SPRITE_SNACKER,
    ASSET_815_SPRITE_TOOTY,
    ASSET_816_SPRITE_GRUNTILDA,
    ASSET_817_SPRITE_ANCIENT_ONE,
    ASSET_818_SPRITE_TWINKLY_CHOMPER,

    ASSET_81B_SPRITE_LIVE_MUSIC_NOTE = 0x81B,

    ASSET_81D_SPRITE_LIVE_EXTRA_HEALTH_MAX = 0x81D,
    ASSET_81E_SPRITE_LIVE_BLUE_EGG,
    ASSET_81F_SPRITE_LIVE_GOLD_FEATHER,
    ASSET_820_SPRITE_LIVE_RED_FEATHER,
    ASSET_821_SPRITE_TWINKLY,
    ASSET_822_SPRITE_XMAS_GIFT_BLUE,
    ASSET_823_SPRITE_XMAS_GIFT_GREEN,
    ASSET_824_SPRITE_XMAS_GIFT_RED,
    ASSET_825_SPRITE_LIVE_ORANGE,
    ASSET_826_SPRITE_TUMBLAR,
    ASSET_827_SPRITE_LIVE_CLOCK,
    ASSET_828_SPRITE_JUJU,

    ASSET_82A_SPRITE_LEAKY = 0x82A,
    ASSET_82B_SPRITE_KLUNGO,
    ASSET_82C_SPRITE_MUMMUM,
    ASSET_82D_SPRITE_ZUBBA,
    ASSET_82E_SPRITE_BRENTILDA,
    ASSET_82F_SPRITE_TIPTUP_CHOIR_MEMBER,
    ASSET_830_SPRITE_JINXY,
    ASSET_831_SPRITE_NABNUT,
    ASSET_832_SPRITE_LITTLE_LOCKUP,
    ASSET_833_SPRITE_DINGPOT,
    ASSET_834_SPRITE_TERMITE,
    ASSET_835_SPRITE_WOZZA,
    ASSET_836_SPRITE_GLOOP,
    ASSET_837_SPRITE_GNAWTY,
    ASSET_838_SPRITE_SNORKEL,
    ASSET_839_SPRITE_YUMYUM,
    ASSET_83A_SPRITE_CROCTUS,
    ASSET_83B_SPRITE_MOTZHAND,
    ASSET_83C_SPRITE_BOGGY,
    ASSET_83D_SPRITE_LOGGO,
    ASSET_83E_SPRITE_EEYRIE_ADULT,
    ASSET_83F_SPRITE_EEYRIE_YOUNG,
    ASSET_840_SPRITE_WORM,
    ASSET_841_SPRITE_SEXY_GRUNTY,
    ASSET_842_SPRITE_CHEATO,
    ASSET_843_SPRITE_POLAR_BEAR_CUBS,
    ASSET_844_SPRITE_UGLY_TOOTY,
    ASSET_845_SPRITE_BLACK_SNIPPET,
    ASSET_846_SPRITE_SAND_EEL,
    ASSET_847_SPRITE_BOSS_BOOM_BOX,
    ASSET_848_SPRITE_FREEZING_WATER,
    ASSET_849_SPRITE_LOCKUP,

    ASSET_88C_MODEL_MOTZHAND = 0x88c,

    ASSET_88E_MODEL_CLANKER_CHAIN = 0x88e,

    ASSET_890_MODEL_SCREW = 0x890,
    ASSET_891_MODEL_CLANKER_TOKEN_TOOTH_OPEN,
    ASSET_892_MODEL_CLANKER_TOKEN_TOOTH_CLOSED,
    ASSET_893_MODEL_CLANKER_JIGGY_TOOTH_OPEN,
    ASSET_894_MODEL_CLANKER_JIGGY_TOOTH_CLOSED,


    ASSET_896_MODEL_GOLD_ROCK = 0x896,

    ASSET_89D_ZOOMBOX_SPRITE = 0x89d,

    ASSET_8A0_SPRITE_WATER_DROP = 0x8a0,

    ASSET_A17_TEXT_BURIED_TREASURE_SPAWNED = 0xa17,

    ASSET_A6F_TEXT_CHARMER_MEET = 0xA6F,
    ASSET_A70_TEXT_CHARMER_HELPED,
    ASSET_A71_TEXT_TRUNKER_MEET,
    ASSET_A72_TEXT_TRUNKER_HELPED,
    ASSET_A73_TEXT_GOBI_MEET,
    ASSET_A74_TEXT_GOBI_HELPED,
    ASSET_A75_TEXT_GOBI2_MEET,
    ASSET_A76_TEXT_GOBI2_DONE,
    ASSET_A77_TEXT_GOBI3_DONE,
    ASSET_A78_TEXT_GRABBA_MEET,
    ASSET_A79_TEXT_GRABBA_DEFEAT,
    ASSET_A7A_TEXT_GRABBA_TOO_FAST,
    ASSET_A7B_TEXT_JINXY_MEET,
    ASSET_A7C_TEXT_JINXY_ONE_EGG,
    ASSET_A7D_TEXT_JINXY_HELPED,
    ASSET_A7E_TEXT_SAND_EELS_MEET,
    ASSET_A7F_TEXT_ANICIENT_ONES_MEET,
    ASSET_A80_TEXT_ANICIENT_ONES_DONE,
    ASSET_A81_TEXT_SANDYBUTT_ENTER,
    ASSET_A82_TEXT_SANDYBUTT_START_MAZE,
    ASSET_A83_TEXT_SANDYBUTT_DONE,

    ASSET_ADE_TEXT_LOGGO_AS_BEAR  = 0xade,
    ASSET_ADF_TEXT_ENTER_LOGGO,
    ASSET_AE0_TEXT_EXIT_LOGGO,

    ASSET_B37_TEXT_CONGA_SAFE_UP_HERE     = 0xb37,
    ASSET_B38_TEXT_CONGA_DEFEAT,
    ASSET_B39_TEXT_CONGA_HIT_BY_EGG,
    ASSET_B3A_TEXT_CONGA_HITS_PLAYER,
    ASSET_B3B_TEXT_CONGA_ORANGE_PAD_JIGGY,
    ASSET_B3C_TEXT_CONGA_MEET,

    ASSET_B3E_TEXT_CONGA_MEET_AS_TERMITE  = 0xb3e,

    ASSET_B44_TEXT_JUJU_MEET              = 0xb44,
    ASSET_B45_TEXT_JIGGY_COLLECT_10, 

    ASSET_B51_TEXT_BOTTLES_HOW_TO_EXIT_LEVEL = 0xb51,

    ASSET_C15_TEXT_TWINKLIE_MINIGAME_LOST = 0xc15,

    text_flibbits_meet   = 0xc81,
    text_flibbits_defeat = 0xc82,
    text_flibbits_return = 0xc83,

    ASSET_D34_TEXT_GLOOP_MEET = 0xd34,

    ASSET_D39_TEXT_BOTTLES_REFILL_HEALTH = 0xd39,

    ASSET_D96_TEXT_BEEHIVE = 0xd96,

    ASSET_DA6_TEXT_BEEHIVE_WITH_BEES = 0xda6

};

enum overlay_e{
    OVERLAY_1_COSHOW   = 0x1,
    OVERLAY_2_WHALE    = 0x2,
    OVERLAY_3_HAUNTED  = 0x3,
    OVERLAY_4_DESERT   = 0x4,
    OVERLAY_5_BEACH    = 0x5,
    OVERLAY_6_JUNGLE   = 0x6,
    OVERLAY_7_SWAMP    = 0x7,
    OVERLAY_8_SHIP     = 0x8,
    OVERLAY_9_SNOW     = 0x9,
    OVERLAY_A_TREE     = 0xA,
    OVERLAY_B_TRAINING = 0xB,
    OVERLAY_C_INTRO    = 0xC,
    OVERLAY_D_WITCH    = 0xD,
    OVERLAY_E_BATTLE   = 0xE
};

enum marker_e{
    MARKER_5_GRUBLIN = 0x5,

    MARKER_7_CONGA = 0x7,

    MARKER_A_CHIMPY = 0xA,

    MARKER_C_ORANGE_PROJECTILE = 0xC,

    MARKER_11_WADING_BOOTS = 0x11,

    MARKER_13_SNIPPET = 0x13,

    MARKER_15_CLAM = 0x15,

    MARKER_28_CLANKER_SAWBLADE = 0x28,

    MARKER_2E_GRIMLET = 0x2E,

    MARKER_32_PLAYER_SHADOW = 0x32,
    MARKER_33_LEAKY,
    MARKER_34_CEMETARY_POT,

    MARKER_36_ORANGE_COLLECTABLE = 0x36,
    MARKER_37_GOLD_BULLION,
    MARKER_38_TURBO_TALON_TRAINERS,
    MARKER_39_MUMBO_TOKEN,

    MARKER_3B_SCARF_SLED = 0x3B,
    MARKER_3C_RACE_SLED,

    MARKER_48_NAPPER = 0x48,
    MARKER_49_MOTZHAND,
    MARKER_4A_CC_KEY,
    MARKER_4B_CC_SCREW,
    MARKER_4C_CLANKER_TOKEN_TOOTH_EXT,
    MARKER_4D_CLANKER_JIGGY_TOOTH_EXT,

    MARKER_51_MM_HUT = 0x51,
    MARKER_52_JIGGY,
    MARKER_53_EMPTY_HONEYCOMB,

    MARKER_55_HONEYCOMB = 0x55,

    MARKER_5F_MUSIC_NOTE = 0x5F,

    MARKER_61_EXTRA_LIFE = 0x61,
    MARKER_62_RED_ARROW,
    MARKER_63_RED_QUESTION_MARK,
    MARKER_64_RED_X,
    MARKER_65_SHRAPNEL,
    MARKER_66_ORANGE_PAD,
    MARKER_67_JUJU = 0x67,

    MARKER_69_CHUMP_FISH = 0x69,
    MARKER_6A_GLOOP = 0x6A,

    MARKER_6C_TANKTUP = 0x6C,
    MARKER_6D_TANKTUP_LEG,
    MARKER_6E_PINK_EGG_LARGEST,

    MARKER_95_CHIMPY_STUMP = 0x95,
    MARKER_96_RIPPER,

    MARKER_99_TEEHEE = 0x99,

    MARKER_A3_BLUBBER = 0xA3,
    MARKER_A4_LOCKUP_SLOW,
    MARKER_A5_NIPPER,
    MARKER_A6_GRABBA,
    MARKER_A7_MAGIC_CARPET_1,

    MARKER_A9_RUBEE = 0xA9,

    MARKER_AB_RUBEES_EGG_POT = 0xAB,

    MARKER_AD_SLAPPA = 0xAD,

    MARKER_AF_MAGIC_CARPET_SHADOW = 0xAF,
    MARKER_B0_MAGIC_CARPET_2,
    MARKER_B1_SIR_SLUSH,

    MARKER_B7_TUTORIAL_BOTTLES = 0xB7,

    MARKER_B9_FP_SNOWMAN_BUTTON = 0xB9,
    MARKER_BA_XMAS_TREE,

    MARKER_BC_GOBI_1 = 0xBC,
    MARKER_BD_GOBI_ROPE,

    MARKER_BF_GOBI_2 = 0xBF,
    MARKER_C0_TRUNKER,
    MARKER_C1_FLIBBIT_RED,
    MARKER_C2_BUZZBOMB,
    MARKER_C3_GOBI_3,
    MARKER_C4_YELLOW_FLIBBIT_CTRL,
    MARKER_C5_FLIBBIT_YELLOW,
    MARKER_C6_VILE_GAME_CTRL,
    MARKER_C7_YUMBLIE,
    MARKER_C8_MR_VILE, 
    MARKER_C9_FLOTSAM,

    MARKER_D5_BGS_MUD_HUT = 0xD5,
    MARKER_D6_PINK_EGG_LARGE,
    MARKER_D7_PINK_EGG_MEDIUM,
    MARKER_D8_PINK_EGG_SMALL,
    MARKER_D9_PINK_EGG_SMALLEST,
    MARKER_DA_LEAFBOAT,
    MARKER_DB_BURIED_TREASURE,
    MARKER_DC_BIG_ALLIGATOR,
    MARKER_DD_BLACK_SNIPPET,

    MARKER_EA_LIGHTHOUSE_DOOR = 0xEA,
    MARKER_EB_GV_BANJO_DOOR,
    MARKER_EC_GV_SUN_SWITCH,
    MARKER_ED_GV_SUN_DOOR,

    MARKER_EF_GV_STAR_HATCH = 0xEF,
    MARKER_F0_GV_KAZOOIE_DOOR,
    MARKER_F1_GV_STAR_SWITCH,
    MARKER_F2_HONEYCOMB_SWITCH,
    MARKER_F3_GV_KAZOOIE_TARGET,
    MARKER_F4_ANCIENT_ONE,
    MARKER_F5_BGS_ELEVATED_WALKWAY_SWITCH,
    MARKER_F6_LOCKUP_MEDIUM,
    MARKER_F7_LOCKUP_FAST,
    MARKER_F8_GV_KAZOOIE_DOOR,
    MARKER_F9_JINXY,

    MARKER_FC_CROCTUS = 0xFC,
    MARKER_FD_BGS_MAZE_SWITCH,
    MARKER_FE_MMM_CLOCK_SWITCH,

    MARKER_103_MM_WITCH_SWITCH = 0x103,
    MARKER_104_MMM_WITCH_SWITCH,
    MARKER_105_TTC_WITCH_SWITCH,
    MARKER_106_RBB_WITCH_SWITCH,

    MARKER_11B_WATER_LEVEL_SWITCH_1 = 0x11B,
    MARKER_11C_WATER_LEVEL_SWITCH_2,
    MARKER_11D_WATER_LEVEL_SWITCH_3,

    MARKER_121_GLASS_EYE = 0x121,

    MARKER_124_BOGGY_1         = 0x124,

    MARKER_127_BAT = 0x127,
    MARKER_128_COLLYWOBBLE_A,
    MARKER_129_BAWL_A,
    MARKER_12A_TOPPER_A,
    MARKER_12B_ATTACK_TUTORIAL,

    MARKER_135_QUARRIE = 0x135,

    MARKER_161_GV_WITCH_SWITCH = 0x161,
    MARKER_162_BGS_WITCH_SWITCH,

    MARKER_166_CC_WITCH_SWITCH = 0x166,
    MARKER_167_SHARKFOOD_ISLAND,
    MARKER_168_ICE_KEY,
    MARKER_169_SNS_EGG,

    MARKER_173_CHUMP_FISH_2 = 0x173,
    MARKER_174_GAME_OVER = 0x174,

    MARKER_182_RBB_EGG_TOLL = 0x182,

    MARKER_185_MODEL_RUSTY_BUCKET_REAR_PROPELLER = 0x185,

    MARKER_191_ENGINE_ROOM_PROPELLOR_1 = 0x191,
    MARKER_192_ENGINE_ROOM_PROPELLOR_2,
    MARKER_193_ENGINE_ROOM_PROPELLOR_3,

    MARKER_19A_TIPTUP = 0x19A,
    MARKER_19B_CHOIR_TURTLE_YELLOW,
    MARKER_19C_CHOIR_TURTLE_CYAN,
    MARKER_19D_CHOIR_TURTLE_BLUE,
    MARKER_19E_CHOIR_TURTLE_RED,
    MARKER_19F_CHOIR_TURTLE_PINK,
    MARKER_1A0_CHOIR_TURTLE_PURPLE,
    MARKER_1A1_BOSS_BOOM_BOX_LARGEST,
    MARKER_1A2_BOSS_BOOM_BOX_LARGE,
    MARKER_1A3_BOSS_BOOM_BOX_MEDIUM ,
    MARKER_1A4_BOSS_BOOM_BOX_SMALL,

    MARKER_1A7_CLANKER_WHIPCRACK = 0x1A7,

    MARKER_1AE_ZUBBA = 0x1AE,

    MARKER_1B2_CLUCKER_A = 0x1B2,

    MARKER_1B4_EEYRIE_BABY = 0x1B4,
    MARKER_1B5_CATERPILLAR,

    MARKER_1B7_BOOM_BOX = 0x1B7,

    MARKER_1BB_NABNUT = 0x1BB,

    MARKER_1C5_WHIPCRACK = 0x1C5,

    MARKER_1CD_GV_MAZE_CTRL = 0x1CD,

    MARKER_1D0_CLUCKER_B = 0x1D0,
    MARKER_1D1_PORTRAIT_CHOMPA_B,

    MARKER_1D4_SANDYBUTT_PYRAMID =  0x1D4,
    MARKER_1D5_PALM_TREE,

    MARKER_1E2_GRUBLIN_HOOD =  0x1E2,

    MARKER_1E6_TOPPER_B =  0x1E6,
    MARKER_1E7_BAWL_B,
    MARKER_1E8_COLLYWOBBLE_B,
    MARKER_1E9_MUMBO_COST_SIGN,
    MARKER_1EA_GRUNTLING_RED,

    MARKER_1F1_GRUNTLING_BLACK = 0x1F1,

    MARKER_1F4_TOOTS = 0x1F4,

    MARKER_1F9_SNARE_BEAR = 0x1F9,
    MARKER_1FA_POLAR_BEAR_CUB_BLUE,
    MARKER_1FB_POLAR_BEAR_CUB_GREEN,
    MARKER_1FC_POLAR_BEAR_CUB_RED,
    MARKER_1FD_BLUE_PRESENT_COLLECTABLE,
    MARKER_1FE_GREEN_PRESENT_COLLECTABLE,
    MARKER_1FF_RED_PRESENT_COLLECTABLE,
    MARKER_200_TWINKLY_BLUE,
    MARKER_201_TWINKLY_GREEN,
    MARKER_202_TWINKLY_ORANGE,
    MARKER_203_TWINKLY_RED,

    MARKER_205_TWINKLY_MUNCHER = 0x205,

    MARKER_208_BLUE_PRESENT = 0x208,
    MARKER_209_GREEN_PRESENT,
    MARKER_20A_RED_PRESENT,
    MARKER_20B_WOZZA,
    MARKER_20C_WOZZAS_JIGGY,

    MARKER_20F_WOZZA_IN_CAVE = 0x20F,

    MARKER_218_LIMBO = 0x218,
    MARKER_219_MUMMUM,
    MARKER_21A_SEAMAN_GRUBLIN,

    MARKER_22A_CCW_WITCH_SWITCH = 0x22A,
    MARKER_22B_FP_WITCH_SWITCH,

    MARKER_23A_GV_SNS_CHAMBER_DOOR = 0x23A,

    MARKER_23C_GV_SNS_SWITCH = 0x23C,

    MARKER_23F_LAIR_FLIGHT_PAD_SWITCH = 0x23F,

    MARKER_245_XMAS_TREE_EGG_TOLL = 0x245,

    MARKER_250_ICECUBE_A = 0x250,

    MARKER_252_LOGGO = 0x252,
    MARKER_253_SCARAB_BEETLE,
    MARKER_254_PORTRAIT_CHOMPA_A,
    MARKER_255_PORTRAIT_OF_GRUNTY,
    MARKER_256_FIRE_FX,
    MARKER_257_PORTRAIT_OF_BLACKEYE,
    MARKER_258_PORTRAIT_OF_TOWER,
    MARKER_259_PORTRAIT_OF_TREE_AND_MOON,
    MARKER_25A_PORTRAIT_OF_TEEHEE,
    MARKER_25B_PORTRAIT_OF_MINION,
    MARKER_25C_GRUNTY_SPELL_FIREBALL,

    MARKER_25E_GRUNTILDA_FINAL_BOSS = 0x25E,
    MARKER_25F_ICECUBE_B = 0x25F,

    MARKER_276_STONE_JINJO = 0x276,

    MARKER_27A_JINJO_STATUE_BASE = 0x27A,
    MARKER_27B_BOSS_JINJO_ORANGE,
    MARKER_27C_BOSS_JINJO_GREEN,
    MARKER_27D_BOSS_JINJO_PINK,
    MARKER_27E_BOSS_JINJO_YELLOW,
    MARKER_27F_JINJONATOR_STATUE_BASE,

    MARKER_280_GRUNTY_SPELL_GREEN_ATTACK = 0x280,

    MARKER_284_GRUNTY_SPELL_BARRIER = 0x284,
    MARKER_285_JINJONATOR,

    MARKER_288_GRUNTY_SHADOW = 0x288,

    MARKER_295_GRUNTLING_BLUE = 0x295,
    MARKER_296_TEEHEE_PURPLE,
    MARKER_297_GIANT_RIPPER,
    MARKER_298_MUMMUM_BALL,

    MARKER_29A_FF_PRIZE = 0x29A,

    MARKER_29D_ROCK_TRAPPING_GRUNTY = 0x29D
};

enum hitbox_e{
    HITBOX_0_NONE,
    HITBOX_1_BEAK_BUSTER,
    HITBOX_2_BEAK_BARGE,
    HITBOX_3_BEAK_BOMB,
    HITBOX_4_CLAW,
    HITBOX_5_PECK,
    HITBOX_6_WONDERWING,
    HITBOX_7_ROLL,
    HITBOX_8_CLAW_DOWN,
    HITBOX_9_CROC_BITE,
    HITBOX_A_FAST_FALLING
};

enum collision_e{
    COLLISION_0_TOUCH,
    COLLISION_1_OW,
    COLLISION_2_DIE
};

enum ff_question_type_e{
    FFQT_0_TEXT,
    FFQT_1_PICTURE,
    FFQT_2_SOUND,
    FFQT_3_GRUNTY,
    FFQT_4_MINIGAME
};

enum common_particle_e{
    COMMON_PARTICLE_1_EGG_HEAD = 1,
    COMMON_PARTICLE_4_EGG_ASS = 4
};

enum bsgroup_e {
    BSGROUP_3_WONDERWING = 0x3,

    BSGROUP_5_CLIMB = 0x5,
    BSGROUP_6_TURBO_TALON_TRAINERS,
    BSGROUP_7_CROC_ATTACK,
    BSGROUP_8_TROT,
    BSGROUP_9_LONG_LEG,
    BSGROUP_A_FLYING,
    BSGROUP_B_ATTACKING,
    BSGROUP_C_WALRUS_SLED,
    BSGROUP_D_TRANSFORMING
};

enum bswatergroup_e{
    BSWATERGROUP_0_NONE,
    BSWATERGROUP_1_SURFACE,
    BSWATERGROUP_2_UNDERWATER
};

enum misc_flag_e{
    MISC_FLAG_1_ON_FLIGHT_PAD = 0x1,
    MISC_FLAG_2_ON_SPRING_PAD,

    MISC_FLAG_5_HAS_PECKED = 0x5,

    MISC_FLAG_E_TOUCHING_WADING_BOOTS = 0xE,

    MISC_FLAG_10_TOUCHING_TURBO_TRAINERS = 0x10,

    //0x12 has used flap
    MISC_FLAG_12_HAS_FLAPPED = 0x12,
    //0x13 in difficult terrain (mud)
    MISC_FLAG_14_LOSE_BOGGY_RACE = 0x14,
    //0x15 touching loadzone?

    MISC_FLAG_1B_TRANSFORMING = 0x1B
};

#endif
