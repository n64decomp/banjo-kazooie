#ifndef ENUMS_H
#define ENUMS_H

#define SPRITE_TYPE_CI4 (1 << 0)
#define SPRITE_TYPE_CI8 (1 << 2)
#define SPRITE_TYPE_RGBA16 (1 << 10)
#define SPRITE_TYPE_RGBA32 (1 << 11)

enum bkprog_e{
    
    // {index=0x03, type="Prog", level=6, name="1st Note Text"}, -- 0x00 > 3
	// {index=0x04, type="Prog", level=6, name="1st Mumbo Token Text"}, -- 0x00 > 4
	// {index=0x05, type="Prog", level=6, name="1st Egg Text"}, -- 0x00 > 5
	// {index=0x06, type="Prog", level=6, name="1st Red Feather Text"}, -- 0x00 > 6
	// {index=0x07, type="Prog", level=6, name="1st Gold Feather Text"}, -- 0x00 > 7
	// {index=0x08, type="Prog", level=6, name="1st Gold Bullion Text"}, -- 0x01 > 1 (flipped, but only for this byte, no idea why)
	// {index=0x09, type="Prog", level=6, name="1st Orange Text"}, -- 0x01 > 0 (flipped, but only for this byte, no idea why)
	// {index=0x0A, type="Prog", level=6, name="1st Honeycomb Text"}, -- 0x01 > 2
	// {index=0x0B, type="Prog", level=6, name="1st Empty Honeycomb Text"}, -- 0x01 > 3
	// {index=0x0C, type="Prog", level=6, name="1st Extra Life Text"},
	// {index=0x0D, type="Prog", level=6, name="1st Beehive Text"},
    BKPROG_D_BEEHIVE_TEXT = 0xD,
	BKPROG_E_JINJO_TEXT,
	// {index=0x0F, type="Prog", level=6, name="1st Time Pirahana Text"},
	// {index=0x10, type="Prog", level=6, name="1st Sand Eel Text"}, -- 0x02 > 0
	// {index=0x11, type="Prog", level=6, name="1st Meeting Mumbo Text"}, -- 0x02 > 1
	// {index=0x12, type="Prog", level=6, name="1st Post XForm Mumbo Text"},

	// {index=0x14, type="Prog", level=6, name="1st FP Icy Water Text"},
    BKPROG_15_ENTER_MMM_TEXT = 0x15,
	// {index=0x16, type="Prog", level=6, name="1st Time in Jigsaw Text"},
	// {index=0x17, type="Prog", level=6, name="1st Time Enough Pieces Jigsaw Text"},
	// {index=0x18, type="Prog", level=6, name="MM WS Jiggy Spawned"},
	// {index=0x19, type="Prog", level=6, name="MMM WS Jiggy Spawned"},
	// {index=0x1A, type="Prog", level=6, name="TTC WS Jiggy Spawned"},
	// {index=0x1B, type="Prog", level=6, name="CC WS Jiggy Spawned"},
	// {index=0x1C, type="Prog", level=6, name="RBB WS Jiggy Spawned"},
	BKPROG_1D_MMM_DINNING_ROOM_CUTSCENE = 0x1D,
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
	// {index=0x46, type="Prog", level=6, name="CCW WS Jiggy Spawned"},

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

	// {index=0x84, type="Prog", level=6, name="Mumbo's Magic All Gone Text"},
	// {index=0x85, type="Prog", level=6, name="Lair Crypt Gate Open"},
	// {index=0x86, type="Prog", level=10, name="1st Thorn Hedge Text"},

	// {index=0x88, type="Prog", level=10, name="1st Exiting Loggo Text"},

	// {index=0x8B, type="Prog", level=8, name="CCW Spring Open"},
	// {index=0x8C, type="Prog", level=8, name="CCW Summer Open"},
	// {index=0x8D, type="Prog", level=8, name="CCW Autumn Open"},
	// {index=0x8E, type="Prog", level=8, name="CCW Winter Open"},
	// {index=0x8F, type="Prog", level=8, name="Mumbo's Magic Getting Weak Text"},
	// {index=0x90, type="Prog", level=1, name="Termite Tokens Paid"},
	// {index=0x91, type="Prog", level=10, name="Pumpkin Tokens Paid"},
	// {index=0x92, type="Prog", level=5, name="Walrus Tokens Paid"},
	// {index=0x93, type="Prog", level=4, name="Croc Tokens Paid"},
	// {index=0x94, type="Prog", level=8, name="Bee Tokens Paid"},

	// {index=0x96, type="Prog", level=6, name="1st Time Brentilda Text"},
	BKPROG_97_ENTERED_LAIR_TEXT = 0x97,
	BKPROG_98_EXITED_LEVEL_TEXT,
    BKPROG_99_PAST_50_NOTE_DOOR_TEXT,
	// {index=0x99, type="Prog", level=6, name="1st Time Past 50 ND Text"},

	// {index=0x9B, type="Prog", level=6, name="CC WS Eyes Active"},
	// {index=0x9C, type="Prog", level=6, name="CC WS Left Eye Pressed"},
	// {index=0x9D, type="Prog", level=6, name="CC WS Right Eye Pressed"},
	// {index=0x9E, type="Prog", level=6, name="Crypt Coffin Lid Open"},
    BKPROG_9E_CRYPT_COFFIN_LID_OPEN = 0x9E,

	// {index=0xA1, type="Prog", level=6, name="Statue Hat Open"},
    BKPROG_A1_STATUE_HAT_OPEN = 0xA1,
    BKPROG_A2_GV_LOBBY_COFFIN_OPEN,

    BKPROG_A6_FURNACE_FUN_COMPLETE = 0xA6,
    BKPROG_A7_NEAR_PUZZLE_PODIUM_TEXT,
	// {index=0xA8, type="Prog", level=6, name="1st Death Text"},
	// {index=0xA9, type="Prog", level=9, name="1st RBB Oven Text"},
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

	// {index=0xD1, type="Prog", level=12, name="Fight 1st Jinjo Statue Activated Cutscene"},
	// {index=0xD2, type="Prog", level=12, name="Fight 1st Jinjo Statue Rising Cutscene"},
	// {index=0xD3, type="Prog", level=6, name="??FF PATTERN 2^0"},
	// {index=0xD4, type="Prog", level=6, name="??FF PATTERN 2^1"},
	// {index=0xD5, type="Prog", level=6, name="??FF PATTERN 2^2"},
	// {index=0xD6, type="Prog", level=6, name="??FF PATTERN 2^3"},
	// {index=0xD7, type="Prog", level=6, name="??FF PATTERN 2^4"},
	// {index=0xD8, type="Prog", level=6, name="??FF PATTERN 2^5"},
	// {index=0xD9, type="Prog", level=6, name="??FF PATTERN 2^6"},
	// {index=0xDA, type="Prog", level=6, name="??FF PATTERN 2^7"},

	// {index=0xDC, type="Prog", level=6, name="In Mumbo's With Enough Tokens Text"},
	// {index=0xDD, type="Prog", level=8, name="1st CCW Icy Water Text"},

	// {index=0xDF, type="Prog", level=6, name="Remove Puzzle Piece Text"},
	// {index=0xE0, type="Prog", level=6, name="Place All Puzzle Pieces Text"},

	// {index=0xE2, type="Prog", level=6, name="DoG Open"},
	// {index=0xE3, type="Prog", level=8, name="CCW Flower Spring"},
	// {index=0xE4, type="Prog", level=8, name="CCW Flower Summer"},
	// {index=0xE5, type="Prog", level=8, name="CCW Flower Autumn"},
	// {index=0xE6, type="Prog", level=8, name="Spring Eyrie Hatched"},
	// {index=0xE7, type="Prog", level=8, name="Summer Eyrie Fed"},
	// {index=0xE8, type="Prog", level=8, name="Autumn Eyrie Fed"},

	// {index=0xF3, type="Prog", level=6, name="Talked to Dingpot"},
    BKPROG_F4_ENTER_FF_CUTSCENE = 0xF4,
	// {index=0xF4, type="Prog", level=6, name="1st Time FF Cutscene"},

	// {index=0xF6, type="Prog", level=6, name="1st Time Near DoG Puzzle Podium"},
	// {index=0xF7, type="Prog", level=10, name="Pumpkin Making Mumbo Hungry Text"},
	// {index=0xF8, type="Prog", level=12, name="King Sandybutt Pyramid State (2^0)"},
	// {index=0xF9, type="Prog", level=12, name="King Sandybutt Pyramid State (2^1)"},

	BKPROG_FC_DEFEAT_GRUNTY = 0xFC
};

enum unkflags_1{
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
    UNKFLAGS1_9D_SANDCASTLE_WISHY_WASHY//	0X9D
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

enum ABILITY_E
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

enum map_e
{
    MAP_1_SM_SPIRAL_MOUNTAIN = 0x01,
    MAP_2_MM_MUMBOS_MOUNTAIN,
    // Unused
    // Unused
    MAP_TTC_BLUBBERS_SHIP  = 0x05,
    MAP_TTC_NIPPERS_SHELL = 0x06,
    MAP_7_TTC_TREASURE_TROVE_COVE,
    // Unused
    // Unused
    MAP_TTC_SANDCASTLE = 0x0A,
    MAP_B_CC_CLANKERS_CAVERN,
    MAP_MM_TICKERS_TOWER = 0x0C,
    MAP_D_BGS_BUBBLEGLOOP_SWAMP,
    MAP_MM_MUMBOS_SKULL = 0x0E,
    // Unused
    MAP_BGS_MR_VILE = 0x10,
    MAP_BGS_TIPTUP = 0x11,
    MAP_12_GV_GOBIS_VALLEY = 0x12,
    MAP_GV_MEMORY_GAME = 0x13,
    MAP_GV_SANDYBUTTS_MAZE = 0x14,
    MAP_GV_WATER_PYRAMID = 0x15,
    MAP_GV_RUBEES_CHAMBER = 0x16,
    // Unused
    // Unused
    // Unused
    MAP_GV_INSIDE_JINXY = 0x1A,
    MAP_1B_MMM_MAD_MONSTER_MANSION = 0x1B,
    MAP_MMM_CHURCH = 0x1C,
    MAP_MMM_CELLAR = 0x1D,
    MAP_CS_START_NINTENDO = 0x1E,
    MAP_1F_CS_START_RAREWARE = 0x1F,
    MAP_20_CS_END_NOT_100 = 0x20,
    MAP_CC_WITCH_SWITCH_ROOM = 0x21,
    MAP_CC_INSIDE_CLANKER = 0x22,
    MAP_CC_GOLDFEATHER_ROOM = 0x23,
    MAP_MMM_TUMBLARS_SHED = 0x24,
    MAP_MMM_WELL = 0x25,
    MAP_26_MMM_NAPPERS_ROOM = 0x26,
    MAP_27_FP_FREEZEEZY_PEAK = 0x27,
    MAP_MMM_EGG_ROOM = 0x28,
    MAP_MMM_NOTE_ROOM = 0x29,
    MAP_MMM_FEATHER_ROOM = 0x2A,
    MAP_MMM_SECRET_CHURCH_ROOM = 0x2B,
    MAP_MMM_BATHROOM = 0x2C,
    MAP_MMM_BEDROOM = 0x2D,
    MAP_MMM_HONEYCOMB_ROOM = 0x2E,
    MAP_MMM_WATERDRAIN_BARREL = 0x2F,
    MAP_MMM_MUMBOS_SKULL = 0x30,
    MAP_31_RBB_RUSTY_BUCKET_BAY = 0x31,
    // Unused
    // Unused
    MAP_34_RBB_ENGINE_ROOM = 0x34,
    MAP_RBB_WAREHOUSE = 0x35,
    MAP_RBB_BOATHOUSE = 0x36,
    MAP_RBB_CONTAINER_1 = 0x37,
    MAP_RBB_CONTAINER_3 = 0x38,
    MAP_RBB_CREW_CABIN = 0x39,
    MAP_RBB_BOSS_BOOM_BOX = 0x3A,
    MAP_RBB_STORAGE_ROOM = 0x3B,
    MAP_RBB_KITCHEN = 0x3C,
    MAP_RBB_NAVIGATION_ROOM = 0x3D,
    MAP_RBB_CONTAINER_2 = 0x3E,
    MAP_RBB_CAPTAINS_CABIN = 0x3F,
    MAP_40_CCW_HUB = 0x40,
    MAP_FP_BOGGYS_IGLOO = 0x41,
    // Unused
    MAP_43_CCW_SPRING = 0x43,
    MAP_44_CCW_SUMMER = 0x44,
    MAP_45_CCW_AUTUMN = 0x45,
    MAP_46_CCW_WINTER = 0x46,
    MAP_BGS_MUMBOS_SKULL = 0x47,
    MAP_FP_MUMBOS_SKULL = 0x48,
    // Unused
    MAP_CCW_SPRING_MUMBOS_SKULL = 0x4A,
    MAP_CCW_SUMMER_MUMBOS_SKULL = 0x4B,
    MAP_CCW_AUTUMN_MUMBOS_SKULL = 0x4C,
    MAP_CCW_WINTER_MUMBOS_SKULL = 0x4D,
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    MAP_FP_CHRISTMAS_TREE = 0x53,
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    // Unused
    MAP_CCW_SUMMER_ZUBBA_HIVE = 0x5A, // Summer & Spring are swapped here
    MAP_CCW_SPRING_ZUBBA_HIVE = 0x5B,
    MAP_CCW_AUTUMN_ZUBBA_HIVE = 0x5C,
    // Unused
    MAP_CCW_SPRING_NABNUTS_HOUSE = 0x5E,
    MAP_CCW_SUMMER_NABNUTS_HOUSE = 0x5F,
    MAP_CCW_AUTUMN_NABNUTS_HOUSE = 0x60,
    MAP_CCW_WINTER_NABNUTS_HOUSE = 0x61,
    MAP_CCW_WINTER_HONEYCOMB_ROOM = 0x62,
    MAP_CCW_AUTUMN_NABNUTS_WATER_SUPPLY = 0x63,
    MAP_CCW_WINTER_NABNUTS_WATER_SUPPLY = 0x64,
    MAP_CCW_SPRING_WHIPCRACK_ROOM = 0x65,
    MAP_CCW_SUMMER_WHIPCRACK_ROOM = 0x66,
    MAP_CCW_AUTUMN_WHIPCRACK_ROOM = 0x67,
    MAP_CCW_WINTER_WHIPCRACK_ROOM = 0x68,
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

// SFX      = Short Sound Effect
// JINGLE   = Short Piece of Music
// MUSIC    = Full repeating Track
enum comusic_e
{
    SFX_DING_A = 0x00,
    MUSIC_FINAL_BATTLE,
    MUSIC_MM,
    MUSIC_FP_TWINKLIES_TALKING,
    MUSIC_MMM_CLOCK_VERSION,
    MUSIC_TTC_VACATION_VERSION,
    MUSIC_BGS,
    MUSIC_CC_MUTANT_CRABS,
    MUSIC_STARTUP_MUSICAL,
    SFX_NOTE_COLLECTED,
    SFX_JINJO_COLLECTED,
    SFX_RED_FEATHER_COLLECTED,
    SFX_EGG_COLLECTED,
    JINGLE_JIGGY_COLLECTED,
    SFX_MMM_BACKGROUND_WIND,
    MUSIC_MMM_ALTERNATIVE,
    MUSIC_SM = 0x10,
    SFX_SEAGULLS,
    MUSIC_TTC_NIPPER,
    MUSIC_INSIDE_SANDCASTLE,
    SFX_GOLD_FEATHER_COLLECTED,
    COMUSIC_15_EXTRA_LIFE_COLLECTED,
    COMUSIC_16_HONEYCOMB_COLLECTED,
    COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED,
    JINGLE_HEALTH_UPGRADE,
    COMUSIC_19_LOW_PITCH_FLUTES,
    JINGLE_DEATH,
    MUSIC_MYSTERIOUS_INDOORS,
    MUSIC_CC_ALTERNATIVE,
    JINGLE_MUMBO_TRANSFORMATION,
    MUSIC_GL_MM_VERSION,
    MUSIC_CC_INSIDE_CLANKER,
    MUSIC_GV_ALTERNATIVE = 0x20,
    MUSIC_MMM_INSIDE_MMM_MANSION,
    MUSIC_MMM,
    MUSIC_MMM_INSIDE_CHURCH,
    MUSIC_GV_INSIDE_PYRAMID,
    MUSIC_USING_GOLD_FEATHERS,
    MUSIC_GV_SANDYBUTT_DANGER,
    JINGLE_GV_RUBEES_SONG,
    MUSIC_SOMETHING_AQUATIC,
    MUSIC_CCW_SUMMER,
    MUSIC_CCW_WINTER,
    COMUSIC_2B_DING_B,
    SFX_BUZZER,
    JINGLE_PUZZLE_SOLVED_FANFARE,
    MUSIC_CCW_FALL_AQUATIC,
    MUSIC_CCW_HUBROOM,
    COMUSIC_30_5TH_JINJO_COLLECTED = 0x30,
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
    MUSIC_GL_TTC_VERSION = 0x50,
    MUSIC_GL_CCW_VERSION,
    MUSIC_GL_BGS_RBB_VERSION,
    MUSIC_GL_FP_VERSION_A,
    MUSIC_GL_GV_VERSION,
    MUSIC_BGS_MR_VILE,
    MUSIC_SM_HANGBRIDGE,
    MUSIC_TURBO_TRAINERS,
    MUSIC_WADING_BOOTS,
    MUSIC_GL_FP_VERSION_B,
    MUSIC_FP_IGLOO_SAD,
    MUSIC_FP_IGLOO_HAPPY,
    MUSIC_BETA_GAME_OVER, // at least I guess so
    MUSIC_GL_MMM_VERSION,
    MUSIC_GL_MMM_RBB_VERSION,
    MUSIC_CCW_ALTERNATIVE_B,
    MUSIC_NABNUT_ATTIC_B = 0x60,
    JINGLE_CHRISTMAS_TREE_LIGHTS_UP,
    MUSIC_RBB_BOOMBOX,
    MUSIC_GL_FF_VERSION,
    COMUSIC_64_WORLD_OPENING_A,
    JINGLE_WORLD_OPENING_B,
    MUSIC_FP_INSIDE_WOZZAS_CAVE,
    SFX_INSERTING_JIGGY,
    MUSIC_TWINKLY_MINIGAME,
    SFX_FF_WARP,
    MUSIC_MMM_TUMBLARS_SHED,
    MUSIC_FP_ALTERNATIVE,
    MUSIC_INTRO_TOWER_SCENE,
    MUSIC_CCW_GNAWTYS_HOUSE,
    MUSIC_GAME_SELECT,
    COMUSIC_6F_PAUSE_SCREEN,
    MUSIC_MMM_INSIDE_LOGGO = 0x70,
    MUSIC_FF,
    MUSIC_BGS_FLIBBIT_FIGHT,
    COMUSIC_73_GAMEBOY,
    MUSIC_GL_FINAL_SECTION,
    SFX_RED_FEATHER_REFILL,
    SFX_GOLD_FEATHER_REFILL,
    SFX_EGG_REFILL,
    JINGLE_DOOR_OF_GRUNTY_OPENED,
    MUSIC_CHEATO,
    MUSIC_BRENTILDA,
    SFX_STEP_ON_SKULL_TILE, // Not 100% sure on these
    SFX_STEP_ON_GRUNTY_TILE,
    SFX_STEP_ON_BK_TILE,
    SFX_STEP_ON_MINIGAME_TILE,
    SFX_STEP_ON_JOKER_TILE,
    MUSIC_GAME_OVER_CUTSCENE = 0x80,
    SFX_ACTIVATING_BRENTILDA,
    SFX_REMOVE_JIGGY,
    MUSIC_GV_SNS, // Not 100% sure on these
    MUSIC_TTC_SNS,
    MUSIC_FP_SNS,
    MUSIC_MMM_SNS,
    MUSIC_MMM_SNS_HAPPIER,
    COMUSIC_88_BIG_SNS_FANFARE,
    SFX_JINJO_STATUE_POWERUP,
    JINGLE_GETTING_TURBO_TRAINERS,
    SFX_DEACTIVATE_BRENTILDA,
    SFX_JINJONATOR_POWERUP,
    JINGLE_MENACING_GRUNTILDA_A,
    MUSIC_CREDITS,
    JINGLE_MENACING_GRUNTILDA_B,
    JINGLE_END_OF_INTRO = 0x90,
    MUSIC_GRUNTY_FALLING,
    SFX_GRUNTY_SPELL_POWERUP,
    SFX_AIR_METER_DROPPING,
    MUSIC_BBONUS,
    JINGLE_BBONUS_A,
    SFX_BBONUS_PICKUP_PIECE,
    SFX_BBONUS_DROP_PIECE,
    JINGLE_BBONUS_PIECES_SHUFFLE, // Looping
    MUSIC_MUMBO_BBQ,
    SFX_JINJONATOR_HITS_GRUNTY_A,
    SFX_JINJONATOR_HITS_GRUNTY_B,
    SFX_JINJONATOR_HITS_GRUNTY_C,
    SFX_JINJONATOR_HITS_GRUNTY_D,
    SFX_JINJONATOR_HITS_GRUNTY_E,
    SFX_JINJONATOR_HITS_GRUNTY_F,
    SFX_JINJONATOR_HITS_GRUNTY_G = 0xA0,
    SFX_JINJONATOR_HITS_GRUNTY_H,
    SFX_JINJONATOR_HITS_GRUNTY_I,
    SFX_JINJONATOR_HITS_GRUNTY_J,
    JINGLE_JINJONATOR_DRUMMING_A,
    JINGLE_JINJONATOR_DRUMMING_B,
    JINGLE_JINJONATOR_DRUMMING_C,
    JINGLE_JINJONATOR_DRUMMING_D,
    MUSIC_KLUNGO_BY_FALLEN_GRUNTY,
    MUSIC_TOOTY,
    MUSIC_BEACH,
    JINGLE_JINJOATOR_FINAL_HIT,
    JINGLE_GOOD_ENDING = 0xAC
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
    SFX_WALKING_NOISE_2,
    SFX_WALKING_NOISE_3,
    SFX_WALKING_NOISE_4,
    SFX_WALKING_NOISE_5,
    SFX_WALKING_NOISE_6,
    SFX_WALKING_NOISE_7,
    SFX_WALKING_NOISE_8,
    SFX_EAGLECRY,
    SFX_TICKER_DEATH,
    // SFX_TICKER_DEATH but higher pitch
    SFX_TERMITE_DEATH,
    SFX_ICE_BREAKING_1,
    // entering a cauldron
    SFX_CHEBOOF,
    // RBB, might be cranes aswell
    SFX_7D_ANCHOR_LIFTING,
    SFX_7E_CREAKY_DOOR_OPENING,
    SFX_7F_HEAVYDOOR_SLAM,
    SFX_80_YUMYUM_CLACK = 0x0080,
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
    SFX_SNORKEL_WAH,
    // barely noticable
    SFX_QUIET_METALLIC,
    SFX_JINXIE_SNIFFLING_1,
    SFX_JINXIE_SNIFFLING_2,
    SFX_JINXIE_SNEEZING,
    SFX_UGH,
    SFX_D7_GRABBA_DEATH,
    SFXR_CRANE,
    SFX_WOODEN_CRATE_BREAKING_1,
    SFX_WOODEN_CRATE_BREAKING_2,
    SFX_WOODEN_CRATE_BREAKING_3,
    SFX_IDLE_PADDLING,
    SFX_JINJO_TALKING,
    SFX_WOOD_SQUEAK,
    SFX_KAZOOIE_TALKING_1,
    SFX_KAZOOIE_TALKING_2 = 0x00E0,
    SFX_KAZOOIE_TALKING_3,
    SFX_KAZOOIE_TALKING_4,
    SFX_KONGA_TALKING_1,
    SFX_KONGA_TALKING_2,
    SFX_KONGA_TALKING_3,
    // extra life talking ?
    SFX_MEEP_1,
    // extra life talking ?
    SFX_MEEP_2,
    SFX_TOOTY_TALKING_1,
    SFX_TOOTY_TALKING_2,
    // from enter_Lair CS
    SFX_EA_GRUNTY_LAUGH_1,
    // from Gameover CS
    SFX_GRUNTY_LAUGH_2,
    SFX_GRUNTY_TALKING_1,
    SFX_GRUNTY_TALKING_2,
    SFX_GRUNTY_TALKING_3,
    SFX_TIPTUP_TALKING,
    // pages flipping
    SFX_CHEATO_IDLE_1 = 0x00F0,
    // book closing thud
    SFX_CHEATO_IDLE_2,
    SFX_CUCKOO_CLOCK,
    SFX_TRUNKER_TALKING,
    SFX_TAP,
    SFX_BLUBBER_TALKING_1,
    SFX_BLUBBER_TALKING_2,
    SFX_BLUBBER_TALKING_3,
    SFX_BLUBBER_TALKING_4,
    SFX_GRUNTLING_NOISE_1,
    SFX_GRUNTLING_NOISE_2,
    SFX_GRUNTLING_NOISE_3,
    SFX_RUBEE_TALKING_1,
    SFX_RUBEE_TALKING_2,
    SFX_RUBEE_TALKING_3,
    SFX_TANKTUP_TALKING_1,
    SFX_TANKTUP_TALKING_2,
    SFX_TANKTUP_TALKING_3 = 0x0100,
    SFX_LOGGO_TALKING,
    SFX_ZUBBA_TALKING,
    SFX_FLOTSAM_DEATH,
    // might also be zubba wings or similar
    SFXR_PROPELLER_NOISE,
    SFX_EYRIE_YAWN,
    SFX_EYRIE_LIPSMACK,
    // full version
    SFX_CAULDRON_ACTIVATION_1,
    // abbreviated version
    SFX_CAULDRON_ACTIVATION_2,
    SFX_LOGGO_LID_CLAP,
    SFX_TUMBLAR_TALKING,
    SFX_GNAWTY_TALKING,
    SFX_MUMMY_TALKING,
    SFX_ANCIENT_ONE_TALKING,
    SFX_TWINKLY_TALKING,
    SFX_BOGGY_TALKING,
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
    SFX_AWAWAU,
    SFX_TOOTY_TALKING_3,
    // on rooftiles
    SFX_BANJO_LANDING_10,
    // shorter version
    SFX_AUDIENCE_CHEERING_1,
    // longer version
    SFX_AUDIENCE_CHEERING_2,
    SFX_126_AUDIENCE_BOOING,
    SFX_127_AUDIENCE_MIXED,
    SFX_128_FIRE_CRACKING,
    // might be skeleton grimlets riiping the painting
    SFX_SWOOSH,
    SFX_GRUNTY_AH,
    SFX_12B_BOILING_AND_BUBBLING,
    SFX_FF_QUESTION_START,
    SFX_CAMERA_ZOOM_CLOSEST,
    SFX_CAMERA_ZOOM_MEDIUM,
    SFX_FUUUCK_YOUUU,
    // from her final fall
    SFX_GRUNTY_ECHOING_CRY = 0x0130,
    SFX_GRUNTY_WEEEGH,
    SFX_GRUNTY_YOW,
    SFX_GRUNTY_OHW,
    SFX_FREEZING_SHIVER,
    // FileSelect, when Banjo's Bed ejects him
    SFX_CARTOONY_SPRING,
    SFX_GAMEBOY_STARTUP,
    SFX_GAMEBOY_BOIN,
    SFX_GAMEBOY_BOIOIN,
    SFX_GAMEBOY_GLITCH,
    SFX_GLASS_BREAKING_7,
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
    SFX_GRUNTY_LAUGH_3,
    SFX_143_BULL_DAMAGE,
    SFX_DOUBLE_CAMERA_CLICK,
    SFX_SINGLE_CAMERA_CLICK,
    // the normal attack
    SFX_GRUNTY_SPELL_ATTACK_1,
    // the homing attack
    SFX_GRUNTY_SPELL_ATTACK_2,
    SFX_GRUNTY_SPELL_LANDING,
    SFX_CHEATO_TALKING_1,
    SFX_CHEATO_TALKING_2,
    // when attacking with the broom
    SFX_GRUNTY_LAUGH_4,
    SFX_BRENTILDA_TALKING,
    SFX_BANJO_FREEZING,
    SFX_SOFT_EXPLOSION,
    // grunty's spell attacks flying
    SFX_FIREWORK_WHISTLING,
    SFX_PORCELAIN_CRASH = 0x0150,
    // FileSelect, when Banjo's Bed ejects him
    SFX_CAT_MEOW,
    // Grunty's Broom; 01-16 getting shorter, more delay
    SFX_MOTOR_BREAKDOWN_01,
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
    SFX_MOTOR_RUCKUS,
    SFX_GRUNTY_WILD_SCREAM,
    SFX_EH,
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
    SFX_MUMBO_TRANSFORMATION_04,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_05,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_06,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_07,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_08,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_09,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_10,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_11,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_12,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_13,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_14,
    SFX_EYRIE_MAMA,
    SFX_SEXY_GRUNTY_TALKING_1,
    SFX_SEXY_GRUNTY_TALKING_2,
    SFX_FREEZE_FRAME,
    SFX_GULP = 0x0190,
    SFX_STATIC,

    SFX_3E9_UNKNOWN = 0x3e9, //bsbwhirl
    SFX_3EA_UNKNOWN,         //chjig
    SFX_3EB_UNKNOWN,         //bstimeout
    SFX_3EC_CCW_DOOR_OPENING,         //ccw and GV opening

    SFX_3F1_UNKNOWN = 0x3f1, //bsstand
    SFX_3F2_UNKNOWN, //gold_chest_ttc

    SFX_3F6_UNKNOWN = 0x3f6, //lair/code_0 func_803880BC

    SFX_3F9_UNKNOWN = 0x3f9, //chmole

    SFX_3FB_UNKNOWN = 0x3fb, //conga

    SFX_413_UNKNOWN = 0x413 //water ripple?
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
    JIGGY_MM_JUJU       = 0x04,
    jiggy_mm_huts       = 0x05,

    JIGGY_8_MM_ORANGE_PADS    = 0x08,
    JIGGY_9_MM_CHIMPY,
    JIGGY_A_MM_CONGA,

    JIGGY_11_TTC_RED_X = 0x11,
    JIGGY_12_TTC_NIPPER,
    JIGGY_13_TTC_LOCKUP,

    JIGGY_17_CC_CLANKER_RAISED = 0x17,

    JIGGY_1C_CC_RINGS   = 0x1C,
    JIGGY_1D_CC_SLOW_SAWBLADES ,

    JIGGY_20_BGS_ELEVATED_WALKWAY = 0x20,
    JIGGY_21_BGS_PINKEGG,
    JIGGY_22_CROCTUS,
    JIGGY_23_BGS_HUTS,
    JIGGY_24_BGS_FLIBBITS,
    JIGGY_25_BGS_MAZE,
    JIGGY_26_BGS_TANKTUP,
    JIGGY_27_BGS_TIPTUP,

    JIGGY_2F_FP_XMAS_TREE = 0x2f,

    JIGGY_35_LAIR_CC_WITCH_SWITCH = 0x35,
    JIGGY_36_LAIR_TTC_WITCH_SWITCH,
    JIGGY_37_LAIR_BGS_WITCH_SWITCH,

    JIGGY_3E_GV_GRABBA = 0x3e,

    JIGGY_41_GV_MAZE    = 0x41,

    JIGGY_49_CCW_EYRIE  = 0x49,

    JIGGY_4D_CCW_FLOWER = 0x4D,

    JIGGY_RBB_SNORKEL   = 0x53,
    JIGGY_RBB_WHISTLE   = 0x54,

    JIGGY_RBB_BOSS_BOOM_BOX = 0x56
};

enum actor_e
{
    ACTOR_4_BIGBUTT         = 0x4,

    ACTOR_6_GRUBLIN           = 0x6,

    ACTOR_8_CONGA             = 0x8,
    ACTOR_9_MM_HUT,

    ACTOR_C_MUD_HUT         = 0xC,
    ACTOR_D_WOOD_DEMOLISHED,
    ACTOR_E_BULL_INTRO,
    ACTOR_F_CHIMPY            = 0xF,

    ACTOR_11_JUJU_CTRL       = 0x11,
    ACTOR_12_BEEHIVE,
    
    ACTOR_14_ORANGE_PROJECTILE = 0x14,

    ACTOR_46_JIGGY          = 0x46,

    ACTOR_4A_WOOD_EXPLOSION = 0x4A,

    ACTOR_4C_STEAM          = 0x4C,
    ACTOR_4D_STEAM_2,

    ACTOR_53_RED_ARROW = 0x53,
    ACTOR_54_RED_QUESTION_MARK,
    ACTOR_55_RED_X,

    ACTOR_57_ORANGE_PAD        = 0x57,

    ACTOR_59_JUJU              = 0x59,
    ACTOR_5A_JIGGY_IN_HAND,

    ACTOR_C5_CHIMPY_STUMP      = 0xC5,
    
    actor_leafboat          = 0xF1,

    ACTOR_F4_BURIED_TREASURE = 0xF4,

    actor_bigalligator      = 0xF6,

    ACTOR_124_SIR_SLUSH     = 0x124,
    ACTOR_125_SNOWBALL,
    ACTOR_126_SIR_SLUSH_HAT,

    ACTOR_12C_MOLEHILL      = 0x12C,

    actor_yellow_flibbit_controller = 0x136,
    actor_yumblie           = 0x139,

    ACTOR_14F_DESTROYED_JIGGY = 0x14f,

    ACTOR_COLLYWOBBLE_A       = 0x164,
    ACTOR_BAWL_A              = 0x165,
    ACTOR_TOPPER_A            = 0x166,
    ACTOR_ATTACK_TUTORIAL   = 0x167,

    ACTOR_1CC_GRILL_CHOMPA  = 0x1CC,

    ACTOR_20E_MM_ENTRANCE_DOOR = 0x20E,
    ACTOR_20F_RBB_ENTRANCE_DOOR,
    ACTOR_210_BGS_ENTRANCE_DOOR,
    ACTOR_211_CHEST_LID, //CC ENTRANCE
    ACTOR_212_IRON_BARS, //TTC_ENTRANCE

    ACTOR_234_CCW_ENTRANCE_DOOR = 0x234,

    ACTOR_226_GV_ENTRANCE   = 0x226,

    ACTOR_228_INVISIBLE_WALL = 0x228, //MMM ENTRANCE DOOR???

    ACTOR_235_FP_ENTANCE_DOOR = 0x235,

    ACTOR_28B_SOUND_SOURCE  = 0x28B,

    ACTOR_2E5_WOODEN_DOOR   = 0x2e5,

    ACTOR_383_FIRE_FX       = 0x383,

    ACTOR_34D_BEE_SWARM     = 0x34D,

    ACTOR_354_DRIPS         = 0x354,

    ACTOR_COLLYWOBBLE_B     = 0x36D,
    ACTOR_BAWL_B            = 0x36E,
    ACTOR_TOPPER_B          = 0x36F,

    ACTOR_37A_BOTTLES       = 0x37a,

    ACTOR_3BA_UNKOWN        = 0x3ba
};

enum bs_e
{
    BS_IDLE = 0x1,
    BS_WALK_SLOW = 0x2,
    BS_WALK = 0x3,
    BS_WALK_FAST = 0x4,
    BS_JUMP = 0x5,
    BS_CLAW = 0x6,
    BS_CROUCH = 0x7,
    BS_BTROT_JUMP = 0x8,
    BS_EGG_HEAD = 0x9,
    BS_EGG_ASS = 0xA,

    BS_SKID = 0xC,
    BS_TIMEOUT = 0xD,
    BS_OW = 0xE,
    BS_BBUSTER = 0xF,
    BS_BFLAP = 0x10,
    BS_BPECK = 0x11,
    BS_BFLIP = 0x12,
    BS_BBARGE = 0x13, 
    BS_BTROT_ENTER = 0x14,
    BS_BTROT_IDLE = 0x15,
    BS_BTROT_WALK = 0x16,
    BS_BTROT_EXIT = 0x17,
    BS_FLY_KNOCKBACK = 0x18,

    BS_WONDERWING_ENTER = 0x1A,
    BS_1B_WONDERWING_IDLE = 0x1B,
    BS_WONDERWING_WALK = 0x1C,
    BS_WONDERWING_JUMP = 0x1D,
    BS_WONDERWING_EXIT = 0x1E,
    BS_WALK_CREEP = 0x1F,
    BS_LANDING = 0x20,
    BS_BSHOCK_CHARGE = 0x21,
    BS_BSHOCK_JUMP = 0x22,
    BS_FLY_ENTER = 0x23,
    BS_FLY = 0x24,
    BS_LONGLEG_ENTER = 0x25,
    BS_LONGLEG_IDLE = 0x26,
    BS_LONGLEG_WALK = 0x27,
    BS_LONGLEG_JUMP = 0x28,
    BS_LONGLEG_EXIT = 0x29,
    BS_BOMB = 0x2A,
    BS_DIVE_IDLE = 0x2B,
    BS_DIVE_B = 0x2C,
    BS_SWIM_IDLE = 0x2D,
    BS_SWIM = 0x2E,
    BS_FALL = 0x2F,
    BS_DIVE_ENTER = 0x30,
    BS_ROLL = 0x31,
    BS_SLIDE = 0x32,
    //unk33,
    BS_JIG_NOTEDOOR = 0x34,
    BS_ANT_IDLE = 0x35,
    BS_ANT_WALK = 0x36,
    BS_ANT_JUMP = 0x37,
    BS_ANT_FALL = 0x38,
    BS_DIVE_A = 0x39,
    BS_CARRY_IDLE = 0x3A,
    BS_CARRY_WALK = 0x3B,
    //unk3C,
    BS_FALL_TUMBLING = 0x3D,
    BS_3E_ANT_OW = 0x3E,
    //unk3F
    //BS_PUMPKIN_unk40,
    BS_DIE = 0x41,
    BS_42_DINGPOT = 0x42,
    BS_43_ANT_DIE = 0x43,
    BS_JIG_JIGGY = 0x44,
    BS_BTROT_SLIDE = 0x45,
    //unk46
    //unk47
    BS_PUMPKIN_IDLE = 0x48,
    BS_PUMPKIN_WALK = 0x49,
    BS_PUMPKIN_JUMP = 0x4A,
    BS_PUMPKIN_FALL = 0x4B,
    BS_LANDING_IN_WATER = 0x4c,
    BS_PUMPKIN_OW = 0x4D,
    BS_PUMPKIN_DIE = 0x4E,
    BS_CLIMB_IDLE = 0x4f,
    BS_CLIMB_MOVE = 0x50,
    BS_CLIMB_EXIT = 0x51,
    //unk52 //tumblar??? a.k.a bssurf
    BS_TIMEOUT_UNK53 = 0x53,    
    BS_54_SWIM_DIE = 0x54,
    BS_LONGLEG_SLIDE = 0x55,
    BS_56_RECOIL = 0x56,
    BS_BOMB_END = 0x57,
    //0x58,
    BS_BFLY_UNK59 = 0x59,
    BS_5A_LOADZONE = 0x5A,
    BS_CARRY_THROW = 0x5B,
    
    BS_CROC_IDLE = 0x5E,
    BS_CROC_WALK = 0x5F,
    BS_CROC_JUMP = 0x60,
    BS_CROC_FALL = 0x61,
    BS_LONGLEG_UNK62 = 0x62,
    BS_CROC_OW   = 0x63,
    BS_CROC_DIE = 0x64, 


    BS_WALRUS_IDLE = 0x67,
    BS_WALRUS_WALK = 0x68,
    BS_WALRUS_JUMP = 0x69,
    BS_WALRUS_FALL = 0x6A,
    //unk0x6B //[107] = "Locked", -- Bee, Mumbo Transform Cutscene
    BS_WALRUS_OW = 0x6C,
    BS_WALRUS_DIE = 0x6D,
    BS_CROC_BITE = 0x6E,
    BS_CROC_EAT_BAD = 0x6F,
    BS_70_CROC_EAT_GOOD = 0x70,
    BS_BTROT_FALL = 0x71,
    BS_SPLAT    = 0x72, //get up after fall damage
    //0x73 locked_cutscene
    //0x74 locked jiggypad, xform, bottles
    //0x75 locked bottles
    BS_BFLY_UNK76 = 0x76,
    //0x77 locked swim
    //0x78 locked dive
    //0x79 locked holding jiggy in tt
    BS_WALK_MUD = 0x7A,
    BS_BTROT_OW = 0x7B,
    //0x7C locked FP scarf sled
    BS_7D_WALRUS_SLED = 0x7D,
    BS_7E_WALRUS_SLED = 0x7E,
    BS_DIVE_OW = 0x7F,
    //BS_7D_WALRUS_SLED_LOSE = 0x80,
    //BS_7D_WALRUS_SLED_LOCKED = 0x81,
    //BS_7D_WALRUS_SLED_LOSE_IN_AIR = 0x82,

    BS_BEE_IDLE = 0x85,
    BS_BEE_WALK = 0x86,
    BS_BEE_JUMP = 0x87,
    BS_BEE_FALL = 0x88,
    BS_BEE_OW = 0x89,
    BS_BEE_DIE = 0x8A,

    BS_BEE_FLY = 0x8c,
    BS_CROC_LOCKED = 0x8D,
    //0x8E, //[142] = "Locked", -- Jiggy podium, Bottles' text outside Mumbo's
    BS_PUMPKIN_LOCKED = 0x8F,
    BS_FLY_OW = 0x91,
    BS_ANT_DRONE = 0x92,
    //0x93 BS_PUMPKIN_LOCKED_2?
    BS_CROC_DRONE = 0x94,
    BS_WALRUS_DRONE = 0x95,
    BS_SWIM_LOCKED = 0x96,
    BS_DIVE_LOCKED = 0x97,
    BS_WALK_DRONE = 0x98,
	BS_BFLY_UNK99=  0x99,
    BS_BTROT_DRONE = 0x9A,
	BS_LONGLEG_DRONE = 0x9B,
    BS_7D_WALRUS_SLED_DRONE = 0x9C,
    BS_BEE_DRONE = 0x9D,
	// [158] = "Locked", -- Climbing
    BS_ANT_BOUNCE = 0x9F,
    BS_PUMPKIN_BOUNCE = 0xA0,
    BS_CROC_BOUNCE = 0xA1,
    BS_WALRUS_BOUNCE = 0xA2,
	BS_BEE_BOUNCE = 0xA3,
    BS_WONDERWING_DRONE = 0xA4,
    BS_WONDERWING_UNKA5 = 0xA5
};

enum map_flags_e
{
    mapflag_mm_main_hit_with_orange = 8
};

enum item_e
{
    ITEM_0_HOURGLASS_TIMER = 0x0,

    ITEM_3_PROPELLOR_TIMER = 0x3,

    ITEM_6_HOURGLASS = 0x6,

    ITEM_9_PROPELLOR = 0x9,

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
    ITEM_ORANGE = 0x19,
    item_mumbo_token = 0x1C,
    item_mumbo_token_total = 0x25,
    item_jiggy_total = 0x26
};

enum animctrl_direction_e
{
    mvmt_dir_forwards = 1
};

enum game_mode_e
{
    GAME_MODE_3_NORMAL = 3,
    GAME_MODE_4_PAUSED = 4,
    GAME_MODE_6_FILE_PLAYBACK = 6,
    GAME_MODE_7_ATTRACT_DEMO = 7,
    GAME_MODE_8_BOTTLES_BONUS = 8,
    GAME_MODE_9_BANJO_AND_KAZOOIE = 9,
    GAME_MODE_A_SNS_PICTURE = 10
};

enum asset_e
{
    ANIM_BANJO_CROUCH_ENTER = 0x1,
    ANIM_BANJO_WALK_CREEP = 0x2,
    ANIM_BANJO_WALK = 0x3,

    ANIM_BANJO_BTROT_EXIT = 0x7,
    ANIM_BANJO_JUMP = 0x8,
    ANIM_BANJO_DIE = 0x9,

    ANIM_BANJO_WALK_MUD = 0xb,
    ANIM_BANJO_RUN = 0xc,

    ANIM_BANJO_TURN = 0xe,

    ASSET_10_ANIM_BIGBUTT_RUN = 0x10,
    ANIM_BANJO_WONDERWING_WALK = 0x11,


    ANIM_BANJO_LONGLEG_ENTER_AS_BEAR = 0x16,
    ANIM_BANJO_BFLAP = 0x17,

    ANIM_BANJO_BPECK_ENTER = 0x19,
    ANIM_BANJO_BPECK = 0x1A,
    ANIM_BANJO_WONDERWING_JUMP = 0x1B,
    ANIM_BANJO_BBARGE = 0x1C,
    ANIM_BANJO_BBUSTER = 0x1D,
    
    ASSET_21_ANIM_BIGBUTT_SLIDE = 0x21,
    ANIM_BANJO_WONDERWING_EXIT = 0x22,
    ANIM_BANJO_WONDERWING_IDLE = 0x23,

    ANIM_BANJO_BTROT_IDLE = 0x26,
    ANIM_BANJO_BTROT_JUMP = 0x27,
    ANIM_TERMITE_OW = 0x28,
    ANIM_TERMITE_DIE = 0x29,
    
    ANIM_BANJO_BJIG_JIGGY = 0x2e,

    ASSET_32_ANIM_BIGBUTT_ATTACK = 0x32,
    ASSET_33_ANIM_BIGBUTT_EAT,
    ASSET_34_ANIM_BIGBUTT_DIE,
    ASSET_35_ANIM_BIGBUTT_ALERT,
    ASSET_36_ANIM_BIGBUTT_WALK,

    ANIM_BANJO_FLY = 0x38,

    ANIM_BANJO_LONGLEG_JUMP     = 0x3D,

    ANIM_BANJO_LONGLEG_ENTER_AS_BIRD = 0x40,
    ANIM_BANJO_LONGLEG_IDLE     = 0x41,
    ANIM_BANJO_LONGLEG_WALK     = 0x42,

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
    
    ANIM_BANJO_SLIDE_BACK = 0x59,
    ANIM_BANJO_SLIDE_FRONT = 0x5A,

    ANIM_TERMITE_IDLE = 0x5E,
    ANIM_TERMITE_WALK = 0x5F,
    ANIM_TERMITE_JUMP = 0x60,

    ASSET_65_ANIM_BEEHIVE_DIE = 0x65,

    ASSET_94_ANIM_GRUBLIN_DIE = 0x94,

    ASSET_D2_ANIM_BANJO_GETTING_UP = 0xD2,

    ASSET_108_ANIM_SIR_SLUSH_IDLE = 0x108,
    ASSET_109_ANIM_SIR_SLUSH_ATTACK,

    ANIM_BANJO_CROUCH = 0x10C,

    ANIM_BANJO_CROUCH_NOINPUT = 0x116,

    ASSET_138_ANIM_ZOOMBOX = 0x138,
    ASSET_139_ANIM_BOTTLES_EXIT,
    ASSET_13A_ANIM_BOTTLES_ENTER,
    ASSET_13B_ANIM_BOTTLES_IDLE,

    ASSET_153_ANIM_BURIED_TREASURE_APPEAR = 0x153,

    ASSET_165_ANIM_BEEHIVE_IDLE = 0x165,
    ASSET_166_ANIM_BURIED_TREASURE_BOUNCE,

    ASSET_1DC_ANIM_BEE_FLY    = 0x1dc,
    ASSET_1DD_ANIM_BEE_WALK,
    ASSET_1DE_ANIM_BEE_IDLE,

    ASSET_1E0_ANIM_BEE_OW     = 0x1e0,
    ASSET_1E1_ANIM_BEE_DIE,
    ASSET_1E2_ANIM_BEE_JUMP,
    
    ASSET_220_ANIM_SIR_SLUSH_DIE = 0x220,

    ASSET_233_ANIM_ICECUBE  = 0x233,

    ASSET_253_ANIM_BIGBUTT_OW   = 0x253,
    ASSET_254_ANIM_BIGBUTT_FALL,
    ASSET_255_ANIM_BIGBUTT_GET_UP,

    model_orange            = 0x2d2, //projectile

    model_juju              = 0x2e6,

    model_orange_pad        = 0x2eb,

    ASSET_34F_MODEL_BANJO_TERMITE = 0x34F,

    ASSET_353_MODEL_BIGBUTT = 0x353,
    ASSET_354_MODEL_BULL_INTRO,

    ASSET_356_MODEL_BANJO_WISHYWASHY = 0x356,

    ASSET_359_MODEL_BANJO_WALRUS = 0x359,

    model_conga             = 0x35c,
    model_chimpy            = 0x35d,

    ASSET_35F_MODEL_JIGGY = 0x35F,

    ASSET_362_MODEL_BANJO_BEE = 0x362,

    ASSET_364_MODEL_BEEHIVE = 0x364,

    ASSET_36F_MODEL_BANJO_PUMPKIN = 0x36f,

    ASSET_374_MODEL_BANJO_CROC = 0x374,

    ASSET_377_MODEL_SIR_SLUSH = 0x377,
    ASSET_378_MODEL_SNOWBALL,

    ASSET_387_MODEL_BOTTLES = 0x387,
    ASSET_388_MODEL_MOLEHILL,

    ASSET_3C5_MODEL_GRUBLIN           = 0x3c5,

    ASSET_3C8_MODEL_CHIMPY_STUMP      = 0x3c8,

    ASSET_3E9_MODEL_RED_ARROW         = 0x3e9,
    ASSET_3EA_MODEL_RED_X,
    ASSET_3EB_MODEL_RED_QUESTION_MARK,

    ASSET_42C_MODEL_BURIED_TREASURE = 0x42C,

    ASSET_430_MODEL_GRILL_CHOMPA = 0x430,

    ASSET_47B_MODEL_ROCK    = 0x47b,

    MODEL_TOPPER            = 0x4ed,
    MODEL_COLLYWOBBLE       = 0x4ee,
    MODEL_BAWL              = 0x4ef,

    ASSET_504_ICECUBE       = 0x504,
    ASSET_505_ICECUBE_CHUNK = 0x505,

    ASSET_526_SPRITE_FIRE   = 0x526,

    SPRITE_DIALOG_FONT_ALPHAMASK = 0x6eb,
    SPRITE_BOLD_FONT_LETTERS_ALPHAMASK = 0x6ec,
    SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK = 0x6ed,

    ASSET_700_SPRITE_DUST  = 0x700,
    ASSET_701_SPRITE_LENS_SHUTTER_MASK,
    ASSET_702_SPRITE_UNKNOWN,

    ASSET_70B_SPRITE_BUBBLE = 0x70b,
    ASSET_70C_SPRITE_RIPPLE = 0x70c,
    ASSET_70D_SPRITE_SMOKE = 0x70d,

    ASSET_713_SPRITE_SPARKLE_YELLOW = 0x713,

    model_MM_hut     = 0x7d7,
    model_mudhut_top = 0x7d8,

    ASSET_8A0_SPRITE_WATER_DROP = 0x8a0,

    ASSET_A17_TEXT_BURIED_TREASURE_SPAWNED = 0xa17,

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

    text_flibbits_meet   = 0xc81,
    text_flibbits_defeat = 0xc82,
    text_flibbits_return = 0xc83,

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

#endif
