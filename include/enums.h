#ifndef ENUMS_H
#define ENUMS_H

enum button{
    BUTTON_START = 0x0,
    button_R = 0x3,
    button_A = 0x8,
    button_B = 0x9
};

enum transformation_E
{
    unknown,
    banjo,
    termite,
    pumpkin,
    walrus,
    croc,
    bee,
    wishywashy
};

enum ABILITY_E
{
    ABILITY_BEAR_PUNCH = 0x4,

    ABILITY_RATATAT_RAP = 0xB,
    ABILITY_ROLL = 0xC
};

enum MAP_E
{
    MAP_SM_SPIRAL_MOUNTAIN = 0x01,
    MAP_MM_MUMBOS_MOUNTAIN = 0x02,
    // Unused
    // Unused
    MAP_TTC_BLUBBERS_SHIP  = 0x05,
    MAP_TTC_NIPPERS_SHELL = 0x06,
    MAP_TTC_TREASURE_TROVE_COVE = 0x07,
    // Unused
    // Unused
    MAP_TTC_SANDCASTLE = 0x0A,
    MAP_CC_CLANKERS_CAVERN = 0x0B,
    MAP_MM_TICKERS_TOWER = 0x0C,
    MAP_BGS_BUBBLEGLOOP_SWAMP = 0x0D,
    MAP_MM_MUMBOS_SKULL = 0x0E,
    // Unused
    MAP_BGS_MR_VILE = 0x10,
    MAP_BGS_TIPTUP = 0x11,
    MAP_GV_GOBIS_VALLEY = 0x12,
    MAP_GV_MEMORY_GAME = 0x13,
    MAP_GV_SANDYBUTTS_MAZE = 0x14,
    MAP_GV_WATER_PYRAMID = 0x15,
    MAP_GV_RUBEES_CHAMBER = 0x16,
    // Unused
    // Unused
    // Unused
    MAP_GV_INSIDE_JINXY = 0x1A,
    MAP_MMM_MAD_MONSTER_MANSION = 0x1B,
    MAP_MMM_CHURCH = 0x1C,
    MAP_MMM_CELLAR = 0x1D,
    MAP_CS_START_NINTENDO = 0x1E,
    MAP_CS_START_RAREWARE = 0x1F,
    MAP_CS_END_NOT_100 = 0x20,
    MAP_CC_WITCH_SWITCH_ROOM = 0x21,
    MAP_CC_INSIDE_CLANKER = 0x22,
    MAP_CC_GOLDFEATHER_ROOM = 0x23,
    MAP_MMM_TUMBLARS_SHED = 0x24,
    MAP_MMM_WELL = 0x25,
    MAP_MMM_NAPPERS_ROOM = 0x26,
    MAP_FP_FREEZEEZY_PEAK = 0x27,
    MAP_MMM_EGG_ROOM = 0x28,
    MAP_MMM_NOTE_ROOM = 0x29,
    MAP_MMM_FEATHER_ROOM = 0x2A,
    MAP_MMM_SECRET_CHURCH_ROOM = 0x2B,
    MAP_MMM_BATHROOM = 0x2C,
    MAP_MMM_BEDROOM = 0x2D,
    MAP_MMM_HONEYCOMB_ROOM = 0x2E,
    MAP_MMM_WATERDRAIN_BARREL = 0x2F,
    MAP_MMM_MUMBOS_SKULL = 0x30,
    MAP_RBB_RUSTY_BUCKET_BAY = 0x31,
    // Unused
    // Unused
    MAP_RBB_ENGINE_ROOM = 0x34,
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
    MAP_CCW_SPRING = 0x43,
    MAP_CCW_SUMMER = 0x44,
    MAP_CCW_AUTUMN = 0x45,
    MAP_CCW_WINTER = 0x46,
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
    MAP_GL_MM_LOBBY = 0x69,
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
    MAP_CS_INTRO_GL_DINGPOT_1 = 0x7B,
    MAP_CS_INTRO_BANJOS_HOUSE_1 = 0x7C,
    MAP_CS_SPIRAL_MOUNTAIN_1 = 0x7D,
    MAP_CS_SPIRAL_MOUNTAIN_2 = 0x7E,
    MAP_FP_WOZZAS_CAVE = 0x7F,
    MAP_GL_FF_ENTRANCE = 0x80,
    MAP_CS_INTRO_GL_DINGPOT_2 = 0x81,
    MAP_CS_ENTERING_GL_MACHINE_ROOM = 0x82,
    MAP_CS_GAME_OVER_MACHINE_ROOM = 0x83,
    MAP_CS_UNUSED_MACHINE_ROOM = 0x84, // Klungo walks to the Controltable
    MAP_CS_SPIRAL_MOUNTAIN_3 = 0x85,
    MAP_CS_SPIRAL_MOUNTAIN_4 = 0x86,
    MAP_CS_SPIRAL_MOUNTAIN_5 = 0x87,
    MAP_CS_SPIRAL_MOUNTAIN_6 = 0x88,
    MAP_CS_INTRO_BANJOS_HOUSE_2 = 0x89,
    MAP_CS_INTRO_BANJOS_HOUSE_3 = 0x8A,
    MAP_RBB_ANCHOR_ROOM = 0x8B,
    MAP_SM_BANJOS_HOUSE = 0x8C,
    MAP_MMM_INSIDE_LOGGO = 0x8D,
    MAP_GL_FURNACE_FUN = 0x8E,
    MAP_TTC_SHARKFOOD_ISLAND = 0x8F,
    MAP_GL_BATTLEMENTS = 0x90,
    MAP_FILE_SELECT = 0x91,
    MAP_GV_SNS_CHAMBER = 0x92,
    MAP_GL_DINGPOT = 0x93,
    MAP_CS_INTRO_SPIRAL_7 = 0x94,
    MAP_CS_END_ALL_100 = 0x95,
    MAP_CS_END_BEACH_1 = 0x96,
    MAP_CS_END_BEACH_2 = 0x97,
    MAP_CS_END_SPIRAL_MOUNTAIN_1 = 0x98,
    MAP_CS_END_SPIRAL_MOUNTAIN_2 = 0x99 // The same thing ?
};

enum level_e
{
    LEVEL_MUMBOS_MOUNTAIN = 0x1,
    level_lair = 0x6,
    LEVEL_SPIRAL_MOUNTAIN = 0xB,
    level_boss = 0xC
};

enum jiggy_e
{
    JIGGY_MM_JUJU       = 0x04,
    jiggy_mm_huts       = 0x05,

    jiggy_mm_orange_pads    = 0x08,
    JIGGY_MM_CHIMPY     = 0x9,

    jiggy_bgs_elevated_walkway = 0x20,
    jiggy_bgs_pinkegg   = 0x21,

    jiggy_bgs_huts      = 0x23,
    jiggy_bgs_flibbits  = 0x24,
    jiggy_bgs_maze      = 0x25,

    jiggy_bgs_tiptup    = 0x27
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

    actor_steam_2           = 0x4D,

    actor_orange_pad        = 0x57,

    ACTOR_JUJU              = 0x59,
    
    actor_chimpy_stump      = 0xC5,
    
    actor_leafboat          = 0xF1,
    actor_bigalligator      = 0xF6,
    actor_yellow_flibbit_controller = 0x136,
    actor_yumblie           = 0x139,

    ACTOR_COLLYWOBBLE_A       = 0x164,
    ACTOR_BAWL_A              = 0x165,
    ACTOR_TOPPER_A            = 0x166,
    ACTOR_ATTACK_TUTORIAL   = 0x167,


    ACTOR_COLLYWOBBLE_B     = 0x36D,
    ACTOR_BAWL_B            = 0x36E,
    ACTOR_TOPPER_B          = 0x36F
};

enum bs_e
{
    bs_btrot_jump = 0x8,

    bs_btrot_enter = 0x14,
    bs_btrot_idle = 0x15,
    bs_btrot_walk = 0x16,
    bs_btrot_exit = 0x17,

    bs_longleg_idle = 0x26,
    bs_longleg_walk = 0x27,
    bs_longleg_jump = 0x28,
    bs_longleg_exit = 0x29,
    

    bs_ant_idle = 0x35,
    bs_ant_walk = 0x36,
    bs_ant_jump = 0x37,
    bs_ant_fall = 0x38,

    bs_pumpkin_idle = 0x48,

    bs_climb_idle = 0x4f,
    bs_climb_move = 0x50,

    bs_longleg_slip = 0x55,

    bs_bee_idle = 0x85,
    bs_bee_walk = 0x86,
    bs_bee_jump = 0x87,
    bs_bee_fall = 0x88,

    bs_bee_fly = 0x8c
};

enum map_flags_e
{
    mapflag_mm_main_hit_with_orange = 8
};

enum item_e
{
    item_note = 0xC,
    item_eggs = 0xD,
    item_red_feather = 0xF,
    item_gold_feather = 0x10,
    ITEM_JINJOS = 0x12,
    item_health = 0x14,
    item_health_total = 0x15,
    ITEM_LIFE = 0x16,
    item_air = 0x17,
    ITEM_ORANGE = 0x19,
    item_mumbo_token = 0x1C,
    item_mumbo_token_total = 0x25,
    item_jiggy_total = 0x26
};

enum movement_direction_e
{
    mvmt_dir_forwards = 1
};

enum game_mode_e
{
    game_mode_normal = 3,
    GAME_MODE_PAUSED = 4,
    game_mode_file_playback = 6,
    game_mode_attract_demo = 7,
    game_mode_bottles_bonus = 8,
    game_mode_player_AND_KAZOOIE = 9,
    game_mode_SnS_picture = 10
};

enum asset_e
{
    anim_mudhut_smashing = 0x4E,

    anim_conga_idle     = 0x51,
    anim_conga_ow       = 0x52,
    anim_conga_defeat   = 0x53,

    anim_conga_beat_chest = 0x55,
    anim_conga_raise_arms = 0x56,
    
    anim_beeBanjo_flying    = 0x1dc,
    anim_beeBanjo_walking   = 0x1dd,
    anim_beeBanjo_idle      = 0x1de,

    anim_beeBanjo_ow        = 0x1e0,
    anim_beeBanjo_dying     = 0x1e1,
    anim_beeBanjo_jumping     = 0x1e2,
    
    model_orange            = 0x2d2, //projectile

    model_juju              = 0x2e6,

    model_orange_pad        = 0x2eb,

    model_conga             = 0x35c,
    model_chimpy            = 0x35d,

    model_grublin           = 0x3c5,

    model_chimpy_stump      = 0x3c8,

    MODEL_TOPPER            = 0x4ed,
    MODEL_COLLYWOBBLE       = 0x4ee,
    MODEL_BAWL              = 0x4ef,

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

#endif
