#ifndef ENUMS_H
#define ENUMS_H

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
    jiggy_bgs_pinkegg   = 0x21,
    jiggy_bgs_huts      = 0x23,
    jiggy_bgs_flibbits  = 0x24
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

#endif
