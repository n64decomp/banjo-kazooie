#ifndef ENUMS_H
#define ENUMS_H

enum button{
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
    map_cs_start_nintendo = 0x1E,
    map_cs_start_rarware,
    map_cs_end_not100
};

enum jiggy_e
{
    jiggy_bgs_elevated_walkway = 0x20,
    jiggy_bgs_pinkegg   = 0x21,

    jiggy_bgs_huts      = 0x23,
    jiggy_bgs_flibbits  = 0x24,
    jiggy_bgs_maze      = 0x25,

    jiggy_bgs_tiptup    = 0x27
};

enum actor_e
{
    actor_mud_hut           = 0xC,
    actor_wood_demolished   = 0xD,
    actor_steam_2           = 0x4D,
    actor_leafboat          = 0xF1,
    actor_bigalligator      = 0xF6,
    actor_yumblie           = 0x139
};

enum movement_e
{
    movement_bee_idle = 0x85,
    movement_bee_walk = 0x86,
    movement_bee_jump = 0x87,
    movement_bee_fall = 0x88,

    movement_bee_fly = 0x8c
};

enum movement_direction_e
{
    mvmt_dir_forwards = 1
};

enum game_mode_e
{
    game_mode_normal = 3,
    game_mode_paused = 4,
    game_mode_file_playback = 6,
    game_mode_attract_demo = 7,
    game_mode_bottles_bonus = 8,
    game_mode_player_AND_KAZOOIE = 9,
    game_mode_SnS_picture = 10
};

enum asset_e
{
    anim_mudhut_smashing = 0x4E,

    
    anim_beeBanjo_flying    = 0x1dc,
    anim_beeBanjo_walking    = 0x1dd,
    anim_beeBanjo_idle    = 0x1de,

    anim_beeBanjo_ow        = 0x1e0,
    anim_beeBanjo_dying     = 0x1e1,
    anim_beeBanjo_jumping     = 0x1e2,
    
    model_mudhut_top = 0x7D8
};

#endif
