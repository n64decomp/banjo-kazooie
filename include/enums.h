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

enum map_e
{
    map_sm_spiral_mountain = 1,
    map_mm_mumbos_mountain = 2,
    map_ttc_treasure_trove_cove = 7,

    map_cs_start_nintendo = 0x1E,
    map_cs_start_rarware = 0x1F,
    map_cs_end_not100 = 0x20,
    map_rbb_rusty_bucket_bay = 0x31,
    MAP_LAIR_FF_ENTRANCE = 0x80,
    MAP_CUTSCENE_GAMEOVER = 0x83,
    map_sm_banjos_house = 0x8C,
    MAP_LAIR_FURNACE_FUN = 0x8e,
    map_lair_battlements = 0x90
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
    actor_yumblie           = 0x139  
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
