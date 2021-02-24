#ifndef ENUMS_H
#define ENUMS_H

enum button{
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
    game_mode_BANJO_AND_KAZOOIE = 9,
    game_mode_SnS_picture = 10
};

enum asset_e
{
    anim_mudhut_smashing = 0x4E,

    model_mudhut_top = 0x7D8
};

#endif
