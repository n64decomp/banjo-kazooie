#ifndef ENUMS_H
#define ENUMS_H

#define SPRITE_TYPE_CI4 (1 << 0)
#define SPRITE_TYPE_CI8 (1 << 2)
#define SPRITE_TYPE_RGBA16 (1 << 10)
#define SPRITE_TYPE_RGBA32 (1 << 11)

enum BKPROG_E{
    
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
	BKPROG_0E_JINJO_TEXT =  0xE,
	// {index=0x0F, type="Prog", level=6, name="1st Time Pirahana Text"},
	// {index=0x10, type="Prog", level=6, name="1st Sand Eel Text"}, -- 0x02 > 0
	// {index=0x11, type="Prog", level=6, name="1st Meeting Mumbo Text"}, -- 0x02 > 1
	// {index=0x12, type="Prog", level=6, name="1st Post XForm Mumbo Text"},

	// {index=0x14, type="Prog", level=6, name="1st FP Icy Water Text"},
	// {index=0x15, type="Prog", level=6, name="1st Time in Mansion Text"},
	// {index=0x16, type="Prog", level=6, name="1st Time in Jigsaw Text"},
	// {index=0x17, type="Prog", level=6, name="1st Time Enough Pieces Jigsaw Text"},
	// {index=0x18, type="Prog", level=6, name="MM WS Jiggy Spawned"},
	// {index=0x19, type="Prog", level=6, name="MMM WS Jiggy Spawned"},
	// {index=0x1A, type="Prog", level=6, name="TTC WS Jiggy Spawned"},
	// {index=0x1B, type="Prog", level=6, name="CC WS Jiggy Spawned"},
	// {index=0x1C, type="Prog", level=6, name="RBB WS Jiggy Spawned"},
	// {index=0x1D, type="Prog", level=10, name="MMM Diningroom Cutscene"},
	// {index=0x1E, type="Prog", level=6, name="Grate to BGS Puzzle Open"},
	// {index=0x1F, type="Prog", level=6, name="CC Lobby Pipe 1 Raised"},
	// {index=0x20, type="Prog", level=6, name="CC Lobby Pipe 2 Raised"},
	// {index=0x21, type="Prog", level=6, name="CC Lobby Pipe 3 Raised"},
	// {index=0x22, type="Prog", level=6, name="Water Switch 1 Pressed"},
	// {index=0x23, type="Prog", level=6, name="Lair Water Level 1"},
	// {index=0x24, type="Prog", level=6, name="Water Switch 2 Pressed"},
	// {index=0x25, type="Prog", level=6, name="Lair Water Level 2"},
	// {index=0x26, type="Prog", level=6, name="Water Switch 3 Pressed"},
	// {index=0x27, type="Prog", level=6, name="Lair Water Level 3"},

	BKPROG_31_MM_OPEN = 0x31,
	BKPROG_32_TTC_OPEN,
	BKPROG_33_CC_OPEN,
	BKPROG_34_BGS_OPEN,
	BKPROG_35_FP_OPEN,
	BKPROG_36_GV_OPEN,
	BKPROG_37_MMM_OPEN,
	BKPROG_38_RBB_OPEN,
	BKPROG_39_CCW_OPEN,
	BK_PROG_3A_NOTE_DOOR_50_OPEN,
	BK_PROG_3B_NOTE_DOOR_180_OPEN,
	BK_PROG_3C_NOTE_DOOR_260_OPEN,
	BK_PROG_3D_NOTE_DOOR_350_OPEN,
	BK_PROG_3E_NOTE_DOOR_450_OPEN,
	BK_PROG_3F_NOTE_DOOR_640_OPEN,
	BK_PROG_40_NOTE_DOOR_765_OPEN = 0x40,
	BK_PROG_41_NOTE_DOOR_810_OPEN,
	BK_PROG_42_NOTE_DOOR_828_OPEN,
	BK_PROG_43_NOTE_DOOR_846_OPEN,
	BK_PROG_44_NOTE_DOOR_864_OPEN,
	BK_PROG_45_NOTE_DOOR_882_OPEN,
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
	// {index=0x97, type="Prog", level=6, name="1st Time In Lair Text"},
	// {index=0x98, type="Prog", level=6, name="1st Time Exit Level Text"},
	// {index=0x99, type="Prog", level=6, name="1st Time Past 50 ND Text"},

	// {index=0x9B, type="Prog", level=6, name="CC WS Eyes Active"},
	// {index=0x9C, type="Prog", level=6, name="CC WS Left Eye Pressed"},
	// {index=0x9D, type="Prog", level=6, name="CC WS Right Eye Pressed"},
	// {index=0x9E, type="Prog", level=6, name="Crypt Coffin Lid Open"},

	// {index=0xA1, type="Prog", level=6, name="Statue Hat Open"},
	// {index=0xA2, type="Prog", level=6, name="GV Lobby Coffin Open"},

    BKPROG_A6_FURNACE_FUN_COMPLETE = 0xA6,
    BKPROG_A7_NEAR_PUZZLE_PODIUM_TEXT = 0xA7,
	// {index=0xA8, type="Prog", level=6, name="1st Death Text"},
	// {index=0xA9, type="Prog", level=9, name="1st RBB Oven Text"},
	// {index=0xAA, type="Prog", level=8, name="1st CCW Bramble Field Text"},
	// {index=0xAB, type="Prog", level=9, name="Oily Water Surface Text"},
	// {index=0xAC, type="Prog", level=9, name="Oily Water Underwater Text"},
	// {index=0xAD, type="Prog", level=6, name="Cheato: BLUEEGGS Unlocked"},
	// {index=0xAE, type="Prog", level=6, name="Cheato: REDFEATHERS Unlocked"},
	// {index=0xAF, type="Prog", level=6, name="Cheato: GOLDFEATHERS Unlocked"},
	// {index=0xB0, type="Prog", level=1, name="Has Been in MM"},
	// {index=0xB1, type="Prog", level=4, name="Has Been in BGS"},
	// {index=0xB2, type="Prog", level=2, name="Has Been in TTC"},
	// {index=0xB3, type="Prog", level=7, name="Has Been in GV"},
	// {index=0xB4, type="Prog", level=9, name="Has Been in RBB"},
	// {index=0xB5, type="Prog", level=8, name="Has Been in CCW"},
	// {index=0xB6, type="Prog", level=5, name="Has Been in FP"},
	// {index=0xB7, type="Prog", level=10, name="Has Been in MMM"},
	// {index=0xB8, type="Prog", level=2, name="Has Been in CC"},
	BKPROG_B9_DOUBLE_HEALTH = 0xB9,
	// {index=0xBA, type="Prog", level=6, name="1st Time T. Rex"},

	BKPROG_BD_ENTER_LAIR_CUTSCENE =  0xBD,
    BKPROG_BE_CHEATO_BLUEEGGS = 0xBE,
    BKPROG_BF_CHEATO_REDFEATHERS = 0xBF,
    BKPROG_C0_CHEATO_GOLDFEATHERS = 0xC0,

	// {index=0xC2, type="Prog", level=6, name="Grate to RBB Puzzle Open"},
	// {index=0xC3, type="Prog", level=6, name="Ice Ball To Cheato Broken"},
	// {index=0xC4, type="Prog", level=6, name="Statue Eye Broken"},
	// {index=0xC5, type="Prog", level=6, name="Rareware Box Broken"},
	// {index=0xC6, type="Prog", level=6, name="Jump Pad Switch Pressed"},
	// {index=0xC7, type="Prog", level=6, name="Jump Pad Active"},
	// {index=0xC8, type="Prog", level=6, name="Wall to Wading Boots Broken"},
	// {index=0xC9, type="Prog", level=6, name="Wall to Jump Pad Switch Broken"},
	// {index=0xCA, type="Prog", level=6, name="Cobweb to Purple Cauldron Broken"},
	// {index=0xCB, type="Prog", level=6, name="Cobweb to Flight Pad Broken"},
	// {index=0xCC, type="Prog", level=6, name="Cobweb to Green Cauldron Broken"},
	// {index=0xCD, type="Prog", level=6, name="Grate to Water Switch 3 Open"},
	// {index=0xCE, type="Prog", level=6, name="Grate by MMM Puzzle Open"},

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
	// {index=0xF4, type="Prog", level=6, name="1st Time FF Cutscene"},

	// {index=0xF6, type="Prog", level=6, name="1st Time Near DoG Puzzle Podium"},
	// {index=0xF7, type="Prog", level=10, name="Pumpkin Making Mumbo Hungry Text"},
	// {index=0xF8, type="Prog", level=12, name="King Sandybutt Pyramid State (2^0)"},
	// {index=0xF9, type="Prog", level=12, name="King Sandybutt Pyramid State (2^1)"},

	BKPROG_FC_DEFEAT_GRUNTY = 0xFC
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
    ABILITY_3_BEAK_BOMB = 0x1,
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
    ABILTIY_12_WONDERWING = 0x12,
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

enum MAP_E
{
    MAP_1_SM_SPIRAL_MOUNTAIN = 0x01,
    MAP_2_MM_MUMBOS_MOUNTAIN = 0x02,
    // Unused
    // Unused
    MAP_TTC_BLUBBERS_SHIP  = 0x05,
    MAP_TTC_NIPPERS_SHELL = 0x06,
    MAP_7_TTC_TREASURE_TROVE_COVE = 0x07,
    // Unused
    // Unused
    MAP_TTC_SANDCASTLE = 0x0A,
    MAP_B_CC_CLANKERS_CAVERN = 0x0B,
    MAP_MM_TICKERS_TOWER = 0x0C,
    MAP_D_BGS_BUBBLEGLOOP_SWAMP = 0x0D,
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
    MAP_MMM_NAPPERS_ROOM = 0x26,
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
    MAP_CCW_HUB = 0x40,
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
    MAP_GL_TTC_AND_CC_PUZZLE = 0x6A,
    MAP_GL_180_NOTE_DOOR = 0x6B,
    MAP_GL_RED_CAULDRON_ROOM = 0x6C,
    MAP_GL_TTC_LOBBY = 0x6D,
    MAP_GL_GV_LOBBY = 0x6E,
    MAP_GL_FP_LOBBY = 0x6F,
    MAP_GL_CC_LOBBY = 0x70,
    MAP_GL_STATUE_ROOM = 0x71,
    MAP_GL_BGS_LOBBY = 0x72,
    // Unused
    MAP_GL_GV_PUZZLE = 0x74,
    MAP_GL_MMM_LOBBY = 0x75,
    MAP_GL_640_NOTE_DOOR = 0x76,
    MAP_GL_RBB_LOBBY = 0x77,
    MAP_GL_RBB_AND_MMM_PUZZLE = 0x78,
    MAP_GL_CCW_LOBBY = 0x79,
    MAP_GL_CRYPT = 0x7A,
    MAP_7B_CS_INTRO_GL_DINGPOT_1 = 0x7B,
    MAP_7C_CS_INTRO_BANJOS_HOUSE_1 = 0x7C,
    MAP_7D_CS_SPIRAL_MOUNTAIN_1 = 0x7D,
    MAP_7E_CS_SPIRAL_MOUNTAIN_2 = 0x7E,
    MAP_FP_WOZZAS_CAVE = 0x7F,
    MAP_GL_FF_ENTRANCE = 0x80,
    MAP_81_CS_INTRO_GL_DINGPOT_2 = 0x81,
    MAP_82_CS_ENTERING_GL_MACHINE_ROOM = 0x82,
    MAP_83_CS_GAME_OVER_MACHINE_ROOM = 0x83,
    MAP_84_CS_UNUSED_MACHINE_ROOM = 0x84, // Klungo walks to the Controltable
    MAP_85_CS_SPIRAL_MOUNTAIN_3 = 0x85,
    MAP_86_CS_SPIRAL_MOUNTAIN_4 = 0x86,
    MAP_87_CS_SPIRAL_MOUNTAIN_5 = 0x87,
    MAP_88_CS_SPIRAL_MOUNTAIN_6 = 0x88,
    MAP_89_CS_INTRO_BANJOS_HOUSE_2 = 0x89,
    MAP_8A_CS_INTRO_BANJOS_HOUSE_3 = 0x8A,
    MAP_8B_RBB_ANCHOR_ROOM = 0x8B,
    MAP_SM_BANJOS_HOUSE = 0x8C,
    MAP_MMM_INSIDE_LOGGO = 0x8D,
    MAP_8E_GL_FURNACE_FUN = 0x8E,
    MAP_TTC_SHARKFOOD_ISLAND = 0x8F,
    MAP_90_GL_BATTLEMENTS = 0x90,
    MAP_91_FILE_SELECT = 0x91,
    MAP_GV_SNS_CHAMBER = 0x92,
    MAP_GL_DINGPOT = 0x93,
    MAP_94_CS_INTRO_SPIRAL_7 = 0x94,
    MAP_95_CS_END_ALL_100 = 0x95,
    MAP_96_CS_END_BEACH_1 = 0x96,
    MAP_97_CS_END_BEACH_2 = 0x97,
    MAP_98_CS_END_SPIRAL_MOUNTAIN_1 = 0x98,
    MAP_99_CS_END_SPIRAL_MOUNTAIN_2 = 0x99 // The same thing ?
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
    JINGLE_5TH_JINJO_COLLECTED = 0x30,
    JINGLE_GAME_OVER,
    MUSIC_STARTUP_LOGO_SCENE,
    MUSIC_RBB_ALTERNATIVE,
    MUSIC_SNACKER_DANGER,
    MUSIC_RBB_MASCHINE_ROOM_AQUATIC,
    JINGLE_100TH_NOTE_COLLECTED,
    JINGLE_DOUBLE_HEALTH_UPGRADE,
    JINGLE_MOTZAND_BEATEN,
    MUSIC_DK64_FUNGHI_FOREST,
    MUSIC_FP_BOGGY_RACE,
    JINGLE_MINIGAME_VICTORY,
    JINGLE_MINIGAME_LOSS,
    SFX_JIGGY_SPAWN,
    SFX_SANDYBUTT_FAILURE,
    SFX_MAGIC_CARPET_RISING,
    SFX_MAGIC_CARPET_SINKING = 0x40,
    MUSIC_MUMBOS_HUT,
    JINGLE_NOTEDOOR_OPENING_FANFARE,
    SFX_ENTER_MAP_GLITTER, // Looping
    MUSIC_CCW_NABNUT,
    MUSIC_CCW_NABNUT_ATTIC_A,
    MUSIC_CCW_SPRING,
    MUSIC_BGS_INSIDE_TANKTUP,
    MUSIC_CCW_ALTERNATIVE_A,
    MUSIC_CCW_ALTERNATIVE_QUICK,
    MUSIC_RBB_INSIDE_CONTAINER,
    MUSIC_CCW_ZUBBA_FIGHT,
    MUSIC_RBB_CREWMATE_CABIN,
    MUSIC_MUMBO_DANCE,
    SFX_IN_TRANSITION,
    SFX_OUT_TRANSITION,
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
    JINGLE_WORLD_OPENING_A,
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
enum SFX_E
{
    SFX_BLOOP = 0x0000,
    SFX_MUMBO_UMENAKA,
    SFX_2_CLAW_SWIPE,
    SFX_DULL_CANNON_SHOT,
    // Long Beakbarge 2nd Part
    SFX_KAZOOIE_RUUUUUH, 
    SFX_BANJO_LANDING_01,
    SFX_BANJO_LANDING_02,
    SFX_BANJO_LANDING_03, 
    SFX_BANJO_LANDING_04, 
    SFX_SQUEAKY_TOY,
    SFX_A_BANJO_LANDING_05,
    SFX_BANJO_LANDING_06,
    SFX_TAKING_FLIGHT_LIFTOFF,
    SFX_EGGSHELL_BREAKING,
    SFX_SHOCKSPRING_BOING,
    SFX_SMALL_WATER_SPLASH,
    // shallow water
    SFX_BANJO_LANDING_07 = 0x0010,
    // Blubber's Ship's Trapdoor eg.
    SFX_WOOD_BREAKING_1, 
    SFX_WATER_PADDLING_1,
    SFX_BEAKBUSTER_GROUND,
    // sounds like a muffled frying pan
    SFX_METALLIC_HIT_1,
    // less frying pan-ish
    SFX_METALLIC_HIT_2,
    // In the Opening Musical, when Mumbo's Xylophone drops
    SFX_HEAVY_FALL_VIBRATO, 
    SFX_JINJO_WHISTLE,
    // might also be sliding
    SFXR_ELECTRIC_STATIC, 
    SFX_BANJO_LANDING_08,
    SFX_BIG_THINGS_FALL_OVER,
    // from the sea-mines
    SFX_EXPLOSION_1, 
    SFXR_ALARMCLOCK,
    // hitting the Bull eg.
    SFX_HITTING_AN_ENEMY_1,
    // might also be used for breaking boulders
    SFX_1E_HITTING_AN_ENEMY_2,
    // hitting a Gruntling eg.
    SFX_HITTING_AN_ENEMY_3,
    // Cauldrons make this sound when landing
    SFX_METAL_CLANK_1 = 0x0020, 
    SFX_EGG_BOUNCE_1,
    SFX_KONGA_NOISE_1,
    SFX_KONGA_NOISE_2,
    SFX_KONGA_NOISE_3,
    // might be part of Clankers Bolt
    SFX_METAL_SLIDING_OVER_SMTH, 
    SFX_BANJO_LANDING_09,
    SFX_JINJO_HI,
    SFX_RUSTLING_NOISE,
    SFX_GRUBLIN_NYAHAHA,
    SFX_CLOCK_TIC_1,
    // passive version
    SFX_BULL_MOO_1,
    // when Trunker or the CCW plant grow eg.
    SFX_PULLING_NOISE, 
    // incomplete cauldron spitout AND Banjo pulling on Kazooies Throat in Idle Anim
    SFX_KABOING, 
    SFX_GOBI_RUNNING,
    SFX_ORANGE_SPLAT,
    SFX_MAGIC_POOF = 0x0030,
    // starting to ride the FP sled to rescue Boggy
    SFX_BANJO_OHHWAAOOO, 
    // when rolling AND when taking damage
    SFX_BANJO_EGHEE, 
    // inital Shockspring Jump
    SFX_BANJO_AHOO, 
    SFX_BANJO_AGHOAA,
    SFX_BANJO_WOAH, 
    // death inducing damage
    SFX_BANJO_DOH,
    SFX_BANJO_OHWW,
    // less intense version
    SFX_BANJO_AYE_1,
    // more intense version
    SFX_BANJO_AYE_2,
    SFX_BANJO_HOUW,
    SFX_BANJO_GAAH,
    SFX_BULL_GROWN,
    SFX_TICKER_WALKING,
    // egg pooping ?
    SFX_POOP_NOISE, 
    // higher pitch
    SFX_CAULDRON_SQEAK_1, 
    // lower pitch
    SFX_CAULDRON_SQEAK_2 = 0x0040, 
    // waking up
    SFX_MUMBO_ERGHHH, 
    // short and dull
    SFX_KAZOOIE_RAH, 
    // Short Beakbarge 2nd Part
    SFX_KAZOOIE_RUH, 
    // peeking out of the backpack
    SFX_KAZOOIE_AUW, 
    // Beakbbuster going down ?
    SFX_KAZOOIE_HUGHH, 
    // egg shot 1st Part
    SFX_KAZOOIE_CHOKING_UP, 
    // FeatherFlap exhausting
    SFX_KAZOOIE_HEUGH, 
    // TalonTrot Jump
    SFX_KAZOOIE_RUUH, 
    // TalonTrot Walking
    SFX_KAZOOIE_RA, 
    // the CCW Birds when comming out
    SFX_CLUCKER_AHH, 
    SFX_GULPING,
    // eating yumblies
    SFX_LIP_SMACK, 
    // like when a fish flops around in shallow water
    SFX_WET_WIGGLING, 
    // sounds like split-up from Tooie
    SFX_KAZOOIE_BRUIII, 
    // selecting a SaveFile
    SFX_BANJO_WAHOO, 
    // during Beakbomb
    SFX_KAZOOIE_RRRUH = 0x0050, 
    SFX_CLOCK_TIC_2,
    // starting a Beakbomb
    SFX_BANJO_YAH_OH, 
    // shockspring jump liftoff
    SFX_BANJO_HUIII,
    // jumping 
    SFX_BANJO_HOO_1,
    // jumping
    SFX_BANJO_HOO_2,
    // jumping
    SFX_BANJO_HUI,
    // egg shot 2nd part
    SFX_KAZOOIE_HEGH, 
    SFX_CHIMPY_NOISE_1,
    SFX_CHIMPY_NOISE_2,
    SFX_CHIMPY_NOISE_3,
    SFX_HEAVY_STUFF_FALLING,
    SFX_HEAVY_STUFF_FALLING_DELAYED,
    // sleeping while snoring, inhale
    SFX_BANJO_RAAOWW, 
    // sleeping while snoring, exhale
    SFX_BANJO_PHEWWW,
    // while channeling a spell
    SFXR_MUMBO_BUGABUGOW_MUFFLED,
    // in the GameOver CS when Mumbo appears
    SFX_MUMBO_SKIDDING = 0x0060,
    // in the Musical when the buzzbomb falls (slowed down)
    SFX_CARTOONY_FALL,
    // annoyed at Kazooie, Idle Animation
    SFX_BANJO_ERGHH, 
    // huge fall starts
    SFX_BANJO_UWAAAAOOH,
    // in the Musical, when the Bulls run across
    SFXR_STAMPEDE,
    SFX_METALLIC_SCRATCH,
    SFX_BIRD_AUUGHH,
    SFX_BEEHIVE_CLONK,
    SFX_CLUCKER_AAEEGHH,
    SFX_WHIPCRACK_CREAKING,
    // flagpoles during the boggy races
    SFX_FLAGPOLE_WOBBLE,
    SFX_LOCKUP_OPENING,
    SFX_LOCKUP_CLOSING,
    SFX_6D_CROC_BITE,
    SFX_VILE_EGH,
    // bottles uses this too I think
    SFX_BANJO_HEADSCRATCH,
    SFX_WALKING_NOISE_1 = 0x0070,
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
    SFX_CREAKY_DOOR_OPENING,
    SFX_HEAVYDOOR_SLAM,
    SFX_YUMYUM_CLACK = 0x0080,
    // like polishing glass
    SFX_UUU,
    // when gates are broken, and probably when clankers bolt lands
    SFX_METAL_BREAK,
    SFX_BLUBBER_CRYING,
    SFX_GOBI_CRYING,
    SFX_ROUGH_COUGH,
    SFX_TIPTUP_CHORUS_AH,
    // when beakbustering his feet
    SFX_TANKTUP_OOOHW,
    SFX_WOZZA_NOISE,
    // unsure
    SFX_PARTYTOOL,
    // unsure, sounds like tooie's
    SFX_ALTERNATIVE_EGG_SHOT,
    // when Banjo pulls on her throat in the idle anim
    SFX_KAZOOIE_RAWW,
    SFX_BOGGY_WAHEY,
    SFX_BOGGY_OHWW,
    // tooie mingy sounds super similar
    SFX_GRUNTLING_DAMAGE,
    SFX_8F_SNOWBALL_FLYING,
    SFX_90_SWITCH_PRESS = 0x0090,
    // might be clankers bolt landing
    SFX_METALLIC_SOUND,
    SFX_TOILET_FLUSH,
    // or some elevator
    SFXR_MICROWAVE,
    SFX_94_COGS_ROTATING,
    SFX_BANJO_TALKING,
    SFX_HOTSAND_EEL_HISS,
    // twinklies box maybe
    SFX_DEAF_THUD,
    SFX_METALLIC_THUD,
    // grunty fight
    SFXR_MECHANICAL_CLOSING,
    SFX_BOULDER_BREAKING_1,
    SFX_BOULDER_BREAKING_2,
    SFX_BOULDER_BREAKING_3,
    // might be enemys hitting the ground
    SFX_BOULDER_BREAKING_4,
    SFXR_GENERATOR_RUNNING,
    // Tanktup maybe
    SFX_COUGHING = 0x00A0,
    SFX_BANJO_COUGHING,
    SFX_BANJO_AHOOA,
    // from the idle anim
    SFX_BANJO_DOUBLE_COUGH,
    // from the idle anim, but only once
    SFX_BANJO_SINGLE_COUGH,
    SFX_EYRIE_CRY,
    // final part of entering a cauldron warp
    SFX_MAGICAL_FINISH,
    SFX_WOODEN_SWOSH,
    SFX_BLUBBER_DOUBLE_CRY,
    SFX_BLUBBER_SINGLE_CRY,
    // this sounds like the used version
    SFX_BGS_EGG_BREAKING_1,
    SFX_BGS_EGG_BREAKING_2,
    SFX_GOLDFEATHER_TALKING,
    SFX_CATERPILLAR_SQUEAK,
    SFX_YUMYUM_TALKING,
    SFX_BANJO_CATCHING_BREATH,
    // might be from the grunty machine's doors
    SFXR_SIZZLING_NOISE = 0x00B0,
    SFX_BOGGY_KID_CRYING,
    SFX_BOGGY_KID_HAPPY,
    SFX_ORANGE_TALKING,
    SFX_BOTTLES_TALKING_1,
    SFX_THUNDERBOLT,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_1,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_2,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_3,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_4,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_5,
    // 1-6 are getting increasingly higher in pitch
    SFX_GLASS_BREAKING_6,
    SFX_BOTTLES_TALKING_2,
    SFX_BOTTLES_TALKING_3,
    SFXR_WATERFALL,
    SFX_EYRIE_SLEEPING_1,
    SFX_EYRIE_SLEEPING_2 = 0x00C0,
    // from the opening CS
    SFX_BUZZBOMB_ATTACK,
    // death
    SFX_GRUBLIN_EGH,
    // some talking ?
    SFX_HEGH,
    SFX_TWINKLY_MUNCHER_GRR,
    SFX_TWINKLY_POP,
    // when eating the wrong yumblie
    SFX_SHAKING_MOUTH,
    // from the jinjo's flying
    SFX_SHWOOP,
    // eating twinklies
    SFX_CRUNCH,
    SFX_PAUSEMENU_ENTER,
    SFX_BANJO_DROWNING_1,
    SFX_BANJO_DROWNING_2,
    // also the scrolling sound
    SFX_CC_PAUSEMENU_ENTER_SUBMENU,
    SFX_CD_PAUSEMENU_LEAVE_SUBMENU,
    // when the page is changed
    SFX_CE_PAUSEMENU_HOIP,
    SFX_CF_PAUSEMENU_SHWOOP,
    SFX_GRIMLET_SQUEAK = 0x00D0,
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
    // extra life talking ?
    SFX_MEEP_1,
    // extra life talking ?
    SFX_MEEP_2,
    SFX_TOOTY_TALKING_1,
    SFX_TOOTY_TALKING_2,
    // from enter_Lair CS
    SFX_GRUNTY_LAUGH_1,
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
    SFX_TWINKLY_DEATH = 0x0110,
    SFX_WHIPCRACK_DEATH,
    SFX_TINKER_ATTENTION,
    SFX_PAD_APPEARS,
    SFX_BRICKWALL_BREAKING,
    SFX_BUZZBOMB_DEATH,
    SFX_DEAF_RUSTLING,
    SFX_LIMBO_COLLAPSING,
    SFX_LIMBO_REASSEMBLING,
    SFX_FISH_DEATH,
    SFX_MATROSE_GRUBLIN_AYE,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_1,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_2,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_3,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_4,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_5,
    // 1-6 are getting increasingly shorter
    SFX_TUMBLAR_DISAPPEARING_6 = 0x0120,
    // sounds like an OOT sound
    SFX_AWAWAU,
    SFX_TOOTY_TALKING_3,
    // on rooftiles
    SFX_BANJO_LANDING_10,
    // shorter version
    SFX_AUDIENCE_CHEERING_1,
    // longer version
    SFX_AUDIENCE_CHEERING_2,
    // sounds like the kickball noises from tooie
    SFX_126_AUDIENCE_BOOING = 0x0126,
    // sounds like the kickball noises from tooie
    SFX_127_AUDIENCE_MIXED = 0x0127,
    SFXR_FIRE_CRACKING,
    // might be skeleton grimlets riiping the painting
    SFX_SWOOSH,
    SFX_GRUNTY_AH,
    SFXR_BOILING_AND_BUBBLING,
    SFX_FF_QUESTION_START,
    SFX_CAMERA_ZOOM_CLOSEST,
    SFX_CAMERA_ZOOM_MEDIUM,
    SFX_FUUUCK_YOUUU,
    // from her final fall
    SFX_GRUNTY_ECHOING_CRY = 0x0130,
    SFX_GRUNTY_WEEEGH,
    SFX_GRUNTY_YOW,
    SFX_GRUNTY_OHW,
    SFXR_FREEZING_SHIVER,
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
    SFX_BULL_DAMAGE,
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
    SFX_HEAVY_THUNDERSTORM_10 = 0x0170,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_11,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_12,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_13,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_14,
    // 00-15 getting increasingly delayed and shorter
    SFX_HEAVY_THUNDERSTORM_15,
    // 1-3 are having less and less echo
    SFX_JINJONATOR_JINJOOO_1,
    // 1-3 are having less and less echo
    SFX_JINJONATOR_JINJOOO_2,
    // 1-3 are having less and less echo
    SFX_JINJONATOR_JINJOOO_3,
    SFX_GRUNTY_DAMAGE,
    SFX_SHIPHORN,
    SFX_AIRPLANE_FALLING,
    SFX_GRUNTY_FALLING_OFF_1,
    SFX_GRUNTY_FALLING_OFF_2,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_01,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_02,
    // 01-14 are getting slower and lower pitch
    SFX_MUMBO_TRANSFORMATION_03 = 0x0180,
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
    SFXR_STATIC
};


enum level_e
{
    LEVEL_1_MUMBOS_MOUNTAIN = 0x1,
    LEVEL_6_LAIR = 0x6,
    LEVEL_9_RUSTY_BUCKET_BAY = 0x9,
    LEVEL_B_SPIRAL_MOUNTAIN = 0xB,
    LEVEL_C_BOSS = 0xC,
    LEVEL_D_CUTSCENE = 0xD
};

enum jiggy_e
{
    JIGGY_MM_JUJU       = 0x04,
    jiggy_mm_huts       = 0x05,

    JIGGY_MM_ORANGE_PADS    = 0x08,
    JIGGY_MM_CHIMPY     = 0x9,

    JIGGY_CC_CLANKER_RAISED = 0x17,

    jiggy_bgs_elevated_walkway = 0x20,
    jiggy_bgs_pinkegg   = 0x21,

    jiggy_bgs_huts      = 0x23,
    jiggy_bgs_flibbits  = 0x24,
    jiggy_bgs_maze      = 0x25,

    jiggy_bgs_tiptup    = 0x27,

    JIGGY_35_LAIR_CC_WITCH_SWITCH = 0x35,
    JIGGY_37_LAIR_BGS_WITCH_SWITCH = 0x37,

    JIGGY_RBB_SNORKEL   = 0x53,
    JIGGY_RBB_WHISTLE   = 0x54,

    JIGGY_RBB_BOSS_BOOM_BOX = 0x56
};

enum actor_e
{
    actor_grublin           = 0x6,

    actor_conga             = 0x8,
    actor_MM_hut            = 0x9,

    actor_mud_hut           = 0xC,
    actor_wood_demolished   = 0xD,

    actor_chimpy            = 0xF,
    ACTOR_JUJU_HITBOX       = 0x11,
    
    actor_orange_projectile = 0x14,

    ACTOR_004C_UNK          = 0x4C,
    actor_steam_2           = 0x4D,

    actor_orange_pad        = 0x57,

    ACTOR_JUJU              = 0x59,
    ACTOR_5A_JIGGY_IN_HAND,

    actor_chimpy_stump      = 0xC5,
    
    actor_leafboat          = 0xF1,
    actor_bigalligator      = 0xF6,

    ACTOR_124_SIR_SLUSH     = 0x124,
    ACTOR_125_SNOWBALL,
    ACTOR_126_SIR_SLUSH_HAT,

    actor_yellow_flibbit_controller = 0x136,
    actor_yumblie           = 0x139,

    ACTOR_COLLYWOBBLE_A       = 0x164,
    ACTOR_BAWL_A              = 0x165,
    ACTOR_TOPPER_A            = 0x166,
    ACTOR_ATTACK_TUTORIAL   = 0x167,

    ACTOR_1CC_GRILL_CHOMPA = 0x1CC,

    ACTOR_COLLYWOBBLE_B     = 0x36D,
    ACTOR_BAWL_B            = 0x36E,
    ACTOR_TOPPER_B          = 0x36F
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
    item_note = 0xC,
    ITEM_EGGS = 0xD,
    ITEM_JIGGY = 0xE,
    ITEM_RED_FEATHER = 0xF,
    ITEM_GOLD_FEATHER = 0x10,
    ITEM_JINJOS = 0x12,
    ITEM_13_EMPTY_HONEYCOMB = 0x13,
    ITEM_14_HEALTH = 0x14,
    ITEM_15_HEALTH_TOTAL = 0x15,
    ITEM_16_LIFE = 0x16,
    ITEM_17_AIR = 0x17,
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

    ANIM_BANJO_WONDERWING_WALK = 0x11,


    ANIM_BANJO_LONGLEG_ENTER_AS_BEAR = 0x16,
    ANIM_BANJO_BFLAP = 0x17,

    ANIM_BANJO_BPECK_ENTER = 0x19,
    ANIM_BANJO_BPECK = 0x1A,
    ANIM_BANJO_WONDERWING_JUMP = 0x1B,
    ANIM_BANJO_BBARGE = 0x1C,
    ANIM_BANJO_BBUSTER = 0x1D,
    
    ANIM_BANJO_WONDERWING_EXIT = 0x22,
    ANIM_BANJO_WONDERWING_IDLE = 0x23,

    ANIM_BANJO_BTROT_IDLE = 0x26,
    ANIM_BANJO_BTROT_JUMP = 0x27,
    ANIM_TERMITE_OW = 0x28,
    ANIM_TERMITE_DIE = 0x29,
    
    ANIM_BANJO_BJIG_JIGGY = 0x2e,

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

    anim_conga_idle     = 0x51,
    anim_conga_ow       = 0x52,
    anim_conga_defeat   = 0x53,

    anim_conga_beat_chest = 0x55,
    anim_conga_raise_arms = 0x56,
    
    ANIM_BANJO_SLIDE_BACK = 0x59,
    ANIM_BANJO_SLIDE_FRONT = 0x5A,

    ANIM_TERMITE_IDLE = 0x5E,
    ANIM_TERMITE_WALK = 0x5F,
    ANIM_TERMITE_JUMP = 0x60,

    ANIM_GRUBLIN_DIE = 0x94,

    ASSET_108_ANIM_SIR_SLUSH_IDLE = 0x108,
    ASSET_109_ANIM_SIR_SLUSH_ATTACK,

    ANIM_BANJO_CROUCH = 0x10C,

    ANIM_BANJO_CROUCH_NOINPUT = 0x116,

    ANIM_ZOOMBOX = 0x138,

    ASSET_1DC_ANIM_BEE_FLY    = 0x1dc,
    ASSET_1DD_ANIM_BEE_WALK,
    ASSET_1DE_ANIM_BEE_IDLE,

    ASSET_1E0_ANIM_BEE_OW     = 0x1e0,
    ASSET_1E1_ANIM_BEE_DIE,
    ASSET_1E2_ANIM_BEE_JUMP,
    
    ASSET_220_ANIM_SIR_SLUSH_DIE = 0x220,

    model_orange            = 0x2d2, //projectile

    model_juju              = 0x2e6,

    model_orange_pad        = 0x2eb,

    ASSET_34F_MODEL_BANJO_TERMITE = 0x34F,

    ASSET_356_MODEL_BANJO_WISHYWASHY = 0x356,

    ASSET_359_MODEL_BANJO_WALRUS = 0x359,

    model_conga             = 0x35c,
    model_chimpy            = 0x35d,


    ASSET_362_MODEL_BANJO_BEE = 0x362,

    ASSET_36F_MODEL_BANJO_PUMPKIN = 0x36f,

    ASSET_374_MODEL_BANJO_CROC = 0x374,

    ASSET_377_MODEL_SIR_SLUSH = 0x377,
    ASSET_378_MODEL_SNOWBALL,

    model_grublin           = 0x3c5,

    model_chimpy_stump      = 0x3c8,

    ASSET_430_MODEL_GRILL_CHOMPA = 0x430,

    MODEL_TOPPER            = 0x4ed,
    MODEL_COLLYWOBBLE       = 0x4ee,
    MODEL_BAWL              = 0x4ef,

    SPRITE_DIALOG_FONT_ALPHAMASK = 0x6eb,
    SPRITE_BOLD_FONT_LETTERS_ALPHAMASK = 0x6ec,
    SPRITE_BOLD_FONT_NUMBERS_ALPHAMASK = 0x6ed,

    model_MM_hut     = 0x7d7,
    model_mudhut_top = 0x7d8,

    text_conga_safe_up_here     = 0xb37,
    text_conga_defeat           = 0xb38,
    text_conga_hit_by_egg       = 0xb39,
    text_conga_hits_player      = 0xb3a,
    text_conga_orange_pad_jiggy = 0xb3b,
    text_conga_meet             = 0xb3c,

    text_conga_meet_as_termite  = 0xb3e,
    text_juju_meet              = 0xb44,
    text_jiggy_collect_10       = 0xb45, 

    text_bottles_how_to_exit_level = 0xb51,

    text_flibbits_meet   = 0xc81,
    text_flibbits_defeat = 0xc82,
    text_flibbits_return = 0xc83
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
