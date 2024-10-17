#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

typedef struct bounding_box_s {
    s16 x_min;
    s16 x_max;
    s16 y_min;
    s16 y_max;
    s16 z_min;
    s16 z_max;
} BoundingBox;

static s32 D_80275C10 = -1;
static s32 D_80275C14 = 0;
static u8 D_80275C18 = FALSE;
static u8 D_80275C1C = FALSE;
static BoundingBox sBoundingBoxes[] = {
    { -6000, -1580, -9000, 9000, -6200, -1228 }, 
    { -1700,  -397, -9000, 9000, -6500, -2287 },
    { -1405,   -85, -9000, 9000, -6010, -4101 },
    { -5500, -1957, -9000, 9000, -2000,  -624 },
    {  -320,   320,  1500, 2400, -6000,  -389 },
    {  -700,  1496,  -700, 1730,  -978,   978 },
    { -6000, -1580, -9000, 9000, -6200, -1228 }
};

static s32 sUnusedCounter; // is only incremented and decremented, but not used
static bool D_802806F4;
static s32 sPlayerPosition[4];
static enum comusic_e sTrackId[4];

void core1_ce60_setChanMask(s32 chan_mask) {
    func_80250530(0, chan_mask, 3.0f);
}

void core1_ce60_setChanMaskWithValue(s32 chan_mask, f32 value) {
    func_80250530(0, chan_mask, value);
}

bool core1_ce60_isPlayerInRange(s32 x, s32 z, s32 distance) {
    return (x - sPlayerPosition[0]) * (x - sPlayerPosition[0]) + (z - sPlayerPosition[2]) * (z - sPlayerPosition[2]) < distance * distance; 
}

f32 core1_ce60_getPlayerDistance(f32 x, f32 z) {
    return gu_sqrtf((x - sPlayerPosition[0]) * (x - sPlayerPosition[0]) + (z - sPlayerPosition[2]) * (z - sPlayerPosition[2]));
}

bool core1_ce60_isPlayerInsideBoundingBox(s32 box_idx) {
    return ml_vec3w_inside_box_w(sPlayerPosition,
        sBoundingBoxes[box_idx].x_min, sBoundingBoxes[box_idx].y_min, sBoundingBoxes[box_idx].z_min,
        sBoundingBoxes[box_idx].x_max, sBoundingBoxes[box_idx].y_max, sBoundingBoxes[box_idx].z_max
    );
}

void core1_ce60_func_8024A9EC(s32 arg0) {
    if (!func_8025ADBC(sTrackId[0]) && sTrackId[2]) {
        func_8025A104(sTrackId[0], 0);
    }

    func_8025A55C(sTrackId[2], arg0 ? arg0 : 0x1f4, 4);

    if (func_8025AD7C(sTrackId[1]) || sTrackId[3]) {
        func_8025ABB8(sTrackId[1], sTrackId[3], arg0 ? arg0 : 0x1f4, 4 );
    }

    func_8025A864(sTrackId[1]);
}

void core1_ce60_func_8024AAB0(void) {
    f32 player_position[3];
    f32 player_distance;

    player_getPosition_s32(sPlayerPosition);
    player_getPosition(player_position);

    sTrackId[0] = func_8032274C();
    sTrackId[1] = func_80322758();
    sTrackId[2] = sTrackId[3] = COMUSIC_0_DING_A;

    if (0 <= sTrackId[0])
        sTrackId[2] = func_80250034(sTrackId[0]);

    if (0 <= sTrackId[1])
        sTrackId[3] = func_80250034(sTrackId[1]);

    switch (map_get()) {
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            sTrackId[2] = ml_map_f(4700 - sPlayerPosition[1], 0.0f, 900.0f, 0.0f, sTrackId[2]);
            sTrackId[3] = ml_map_f(4700 - sPlayerPosition[1], 0.0f, 900.0f, sTrackId[3], 0.0f);
            break;

        case MAP_B_CC_CLANKERS_CAVERN:
            player_distance = core1_ce60_getPlayerDistance(13909.0f, -26.0f);
            sTrackId[2] = ml_map_f(player_distance, 1500.0f, 1800.0f, 0.0f, sTrackId[2]);
            sTrackId[3] = ml_map_f(player_distance, 1500.0f, 1800.0f, sTrackId[3], 0.0f);
            break;

        case MAP_1_SM_SPIRAL_MOUNTAIN:
            if (core1_ce60_isPlayerInsideBoundingBox(4)) {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;

        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            if (func_80309D58(player_position, 1)) {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;

        case MAP_41_FP_BOGGYS_IGLOO:
            if (jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS) ||
                (levelSpecificFlags_get(LEVEL_FLAG_11_FP_UNKNOWN) && levelSpecificFlags_get(LEVEL_FLAG_12_FP_UNKNOWN) && levelSpecificFlags_get(LEVEL_FLAG_13_FP_UNKNOWN)))
            {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;

        case MAP_1D_MMM_CELLAR:
            if (sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && sPlayerPosition[0] >= 0x23A) {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;

        case MAP_7F_FP_WOZZAS_CAVE:
            if (sns_get_item_state(SNS_ITEM_ICE_KEY, 1) && core1_ce60_isPlayerInRange(0x619, 0x97a, 0x69a)) {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;

        case MAP_45_CCW_AUTUMN:
        case MAP_46_CCW_WINTER:
            if (core1_ce60_isPlayerInsideBoundingBox(5)) {
                sTrackId[2] = COMUSIC_0_DING_A;
            } else {
                sTrackId[3] = COMUSIC_0_DING_A;
            }
            break;
    }
}

void core1_ce60_func_8024ADF0(bool arg0) {
    core1_ce60_func_8024AAB0();

    if (arg0)
        func_8025A9D4();
    
    if (0 < sTrackId[0] && 0 < sTrackId[2])
        func_8025A104(sTrackId[0], sTrackId[2]);
    
    if (0 < sTrackId[1] && 0 < sTrackId[3])
        func_8025A6CC(sTrackId[1], sTrackId[3]);
}

void core1_ce60_func_8024AE74(void) {
    sUnusedCounter = 0;
    D_80275C10 = -1;
    D_80275C14 = 0;
    D_80275C1C = D_80275C18 = core1_ce60_isPlayerInRange(2883, -10520, 6480) ? TRUE : FALSE;
}

void core1_ce60_resetState(void) {
    D_80275C10 = -1;
    D_80275C14 = 0;
    D_80275C18 = FALSE;
    D_80275C1C = FALSE;
}

void core1_ce60_setChanMaskFromWaterState(s32 chan_mask_underwater, s32 chan_mask_surface) {
    if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
        core1_ce60_setChanMask(chan_mask_underwater);
    } else {
        core1_ce60_setChanMask(chan_mask_surface);
    }
}

void core1_ce60_func_8024AF48(void) {
    if (!D_802806F4 ||
        volatileFlag_get(VOLATILE_FLAG_1) ||
        volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE) ||
        func_802D686C() ||
        player_isDead() ||
        gctransition_8030BDC0() ||
        getGameMode() == GAME_MODE_A_SNS_PICTURE)
    {
        return;
    }

    player_getPosition_s32(sPlayerPosition);
    core1_ce60_func_8024AAB0();

    switch(map_get()){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            if (core1_ce60_isPlayerInRange(-4450, 4550, 1900) || core1_ce60_isPlayerInRange(-6007, 6176, 620)) {
                core1_ce60_setChanMask(0x1cc0);
            } else if (core1_ce60_isPlayerInRange(4511, -1888, 2000)) {
                core1_ce60_setChanMask(0xb0c0);
            } else if (core1_ce60_isPlayerInRange(300, -858, 2200)) {
                core1_ce60_setChanMask(0x513f);
            } else {
                core1_ce60_setChanMaskFromWaterState(0x200, 0x103f);
            }
            break;

        case MAP_7_TTC_TREASURE_TROVE_COVE:
            core1_ce60_func_8024A9EC(0);

            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x600);
            } else if (core1_ce60_isPlayerInRange(-300, 1420, 2150) ||
                       (core1_ce60_isPlayerInRange(-300, 1420, 3100) &&
                        sPlayerPosition[1] < 1300 &&
                        !core1_ce60_isPlayerInRange(-73, 11331, 7180) &&
                        !core1_ce60_isPlayerInRange(1736, 3588, 455) &&
                        !core1_ce60_isPlayerInRange(1380, 3994, 400)))
            {
                core1_ce60_setChanMask(0x7800);
            } else {
                core1_ce60_setChanMask(0x60ff);
            }
            break;
            
        case MAP_B_CC_CLANKERS_CAVERN:
            core1_ce60_func_8024A9EC(0);

            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                if(!(sPlayerPosition[1] < 651)) {
                    core1_ce60_setChanMaskWithValue(0x8180, 5.0f);
                } else {
                    core1_ce60_setChanMaskWithValue(0x3e00, 5.0f);
                }
            } else {
                core1_ce60_setChanMask(0x407f);
            }
            break;

        case MAP_12_GV_GOBIS_VALLEY:
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                core1_ce60_setChanMask(0x8020);
            } else if (core1_ce60_isPlayerInRange(-3990, 5670, 3700)){
                core1_ce60_setChanMask(0x797f);
            } else {
                core1_ce60_setChanMask(0x67fe);
            }
            break;

        case MAP_3_UNUSED:
            core1_ce60_setChanMaskFromWaterState(0x1800, 0x67fe);
            break;

        case MAP_5_TTC_BLUBBERS_SHIP:
            core1_ce60_setChanMaskFromWaterState(0x600, 0x7800);
            break;

        case MAP_1_SM_SPIRAL_MOUNTAIN:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x9000);
            } else {
                if (chmole_learnedAllSpiralMountainAbilities()) {
                    core1_ce60_func_8024A9EC(0);
                }

                core1_ce60_setChanMask(0x6fff);
            }
            break;

        case MAP_21_CC_WITCH_SWITCH_ROOM:
        case MAP_22_CC_INSIDE_CLANKER:
        case MAP_23_CC_GOLDFEATHER_ROOM:
            core1_ce60_setChanMaskFromWaterState(0x3c00, 0x61ff);
            break;

        case MAP_25_MMM_WELL:
        case MAP_2F_MMM_WATERDRAIN_BARREL:
            core1_ce60_setChanMaskFromWaterState(0x1000, 0xcfff);
            break;

        case MAP_13_GV_MEMORY_GAME:
        case MAP_14_GV_SANDYBUTTS_MAZE:
        case MAP_15_GV_WATER_PYRAMID:
        case MAP_16_GV_RUBEES_CHAMBER:
        case MAP_1A_GV_INSIDE_JINXY:
            core1_ce60_setChanMaskFromWaterState(0x3ffe, 0x4ffe);
            break;

        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            if (!mapSpecificFlags_get(1) && !func_8025AD7C(COMUSIC_4_MMM_CLOCK_VERSION) && !func_8025AD7C(COMUSIC_3C_MINIGAME_LOSS)) {
                core1_ce60_func_8024A9EC(0);
            }
            
            core1_ce60_setChanMask((mapSpecificFlags_get(1) ? 0x2000 : 0) + 0xcfff);
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP: 
            if (core1_ce60_isPlayerInRange(1890, -1346, 1400) || core1_ce60_isPlayerInRange(-133, 2008, 900) || core1_ce60_isPlayerInRange(-3629, -535, 1400)) {
                core1_ce60_setChanMaskWithValue(0x2f4f, 2.0f);
            } else {
                core1_ce60_setChanMaskWithValue(0x6f4f, 2.0f);
            }
            break;

        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            if ((-4200 <= sPlayerPosition[0] && sPlayerPosition[0] < -3700) && (-900 <= sPlayerPosition[2] && sPlayerPosition[2] < 900)) {
                core1_ce60_setChanMask(0x51ff);
            } else {
                core1_ce60_setChanMaskFromWaterState(0x800, 0x71bf);
            }
            break;
            
        case MAP_35_RBB_WAREHOUSE:
        case MAP_36_RBB_BOATHOUSE:
        case MAP_37_RBB_CONTAINER_1:
        case MAP_38_RBB_CONTAINER_3:
        case MAP_3E_RBB_CONTAINER_2:
            core1_ce60_setChanMaskFromWaterState(0x800, 0xfe);
            break;
            
        case MAP_40_CCW_HUB:
            if (core1_ce60_isPlayerInRange(0, 0, 2050)) {
                core1_ce60_setChanMaskWithValue(7, 2.0f);
            } else if (1450 <= sPlayerPosition[2]){
                core1_ce60_setChanMaskWithValue(0x407, 2.0f);
            } else if (sPlayerPosition[0] < -1449) {
                core1_ce60_setChanMaskWithValue(0x707, 2.0f);
            } else if (sPlayerPosition[2] < -1449) {
                core1_ce60_setChanMaskWithValue(0x1067, 2.0f);
            } else if (1450 <= sPlayerPosition[0]) {
                core1_ce60_setChanMaskWithValue(0x7007, 2.0f);
            }
            break;

        case MAP_A_TTC_SANDCASTLE: 
            core1_ce60_setChanMaskFromWaterState(0xCE, 0x3C);
            break;

        case MAP_43_CCW_SPRING:
            core1_ce60_setChanMaskFromWaterState(0x400, 0x7bbf);
            break;

        case MAP_45_CCW_AUTUMN:
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x600);
            } else {
                core1_ce60_func_8024A9EC(0);
                core1_ce60_setChanMask(0x7BEF);
            }
            break;

        case MAP_54_UNUSED:
        case MAP_55_UNUSED:
        case MAP_57_UNUSED:
        case MAP_58_UNUSED:
        case MAP_59_UNUSED:
            core1_ce60_setChanMaskFromWaterState(0xc, 0x307b);
            break;
            
        case MAP_56_UNUSED:
            core1_ce60_setChanMaskFromWaterState(0x10, 0x4f6f);
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x400);
            } else if (mapSpecificFlags_get(0) && !jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE)) {
                core1_ce60_setChanMask(0x4bff);
            } else {
                core1_ce60_setChanMask(0x43ff);
            }
            break;
            
        case MAP_65_CCW_SPRING_WHIPCRACK_ROOM:
            core1_ce60_setChanMask(0x107);
            break;

        case MAP_66_CCW_SUMMER_WHIPCRACK_ROOM:
            core1_ce60_setChanMask(0x1C7);
            break;

        case MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM:
            core1_ce60_setChanMask(0xC07);
            break;

        case MAP_68_CCW_WINTER_WHIPCRACK_ROOM:
            core1_ce60_setChanMask(0x1407);
            break;

        case MAP_5E_CCW_SPRING_NABNUTS_HOUSE:
            core1_ce60_setChanMask(0x41fe);
            break;
            
        case MAP_5F_CCW_SUMMER_NABNUTS_HOUSE:
            core1_ce60_setChanMask(0x71fe);
            break;
            
        case MAP_60_CCW_AUTUMN_NABNUTS_HOUSE:
            core1_ce60_setChanMask(0x7fe);
            break;
            
        case MAP_61_CCW_WINTER_NABNUTS_HOUSE:
            core1_ce60_setChanMask(0xbfe);
            break;
            
        case MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY:
            core1_ce60_setChanMaskFromWaterState(1, 0x7fe);
            break;

        case MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY:
            core1_ce60_setChanMaskFromWaterState(1, 0xbfe);
            break;

        case MAP_69_GL_MM_LOBBY:
            if (core1_ce60_isPlayerInRange(3510, -1630, 1250)) {
                core1_ce60_setChanMask(0x7c00);
            } else {
                core1_ce60_setChanMask(0x41ff);
            }
            break;

        case MAP_6A_GL_TTC_AND_CC_PUZZLE:
            if (696 <= sPlayerPosition[1] && core1_ce60_isPlayerInRange(-1557, -905, 477)) {
                core1_ce60_setChanMask(0x8e40);
            } else if (core1_ce60_isPlayerInRange(1500, -890, 550) || core1_ce60_isPlayerInRange(1876, -1107, 370)) {
                core1_ce60_setChanMask(0xf040);
            } else {
                core1_ce60_setChanMask(0x81ff);
            }
            break;

        case MAP_6B_GL_180_NOTE_DOOR:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x8800);
            } else if (core1_ce60_isPlayerInRange(4331, 1269, 1840)) {
                core1_ce60_setChanMask(0x8640);
            } else if (core1_ce60_isPlayerInRange(-1318, 1911, 293) || core1_ce60_isPlayerInRange(-1301, 2168, 234)) {
                core1_ce60_setChanMask(0xf000);
            } else {
                core1_ce60_setChanMask(0x81bf);
            }

            break;

        case MAP_6C_GL_RED_CAULDRON_ROOM:
            core1_ce60_setChanMask(0x81bf);
            break;

        case MAP_6D_GL_TTC_LOBBY:
            core1_ce60_setChanMask(0xf000);
            break;

        case MAP_70_GL_CC_LOBBY:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x8100);
            } else if (core1_ce60_isPlayerInRange(-6614, -467, 1822)) {
                core1_ce60_setChanMask(0xf047);
            } else {
                core1_ce60_setChanMask(0x8e41);
            }
            break;

        case MAP_6E_GL_GV_LOBBY:
            if (core1_ce60_isPlayerInRange(0, -6550, 3650)) {
                core1_ce60_setChanMask(0xfe00);
            } else {
                core1_ce60_setChanMask(0x81ff);
            }
            break;

        case MAP_6F_GL_FP_LOBBY:
            if (3701 <= sPlayerPosition[2]){
                core1_ce60_setChanMask(0xe040);
            } else {
                core1_ce60_setChanMask(0x81bf);
            }
            break;

        case MAP_74_GL_GV_PUZZLE:
            if (core1_ce60_isPlayerInRange(-2633, -31, 515)) {
                core1_ce60_setChanMask(0xe600);
            } else {
                core1_ce60_setChanMask(0x81ff);
            }
            break;

        case MAP_75_GL_MMM_LOBBY:
        case MAP_7A_GL_CRYPT:
            core1_ce60_setChanMask(0xd800);
            break;

        case MAP_71_GL_STATUE_ROOM:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x200);
            } else if (core1_ce60_isPlayerInRange(-3854, -346, 770)) {
                core1_ce60_setChanMask(0x9c00);
            } else {
                core1_ce60_setChanMask(0x81bf);
            }
            break;

        case MAP_72_GL_BGS_LOBBY:
            if (D_80275C10 == -1 && D_80275C18 == FALSE) {
                D_80275C10 = func_802F9AA8(0x410);
                func_802F9F80(D_80275C10, 3.0f, 16777216.0f, 0.0f);
                func_802FA060(D_80275C10, 3500, 3500, 0.0f);
                
                D_80275C14 = func_802F9AA8(0x411);
                func_802F9F80(D_80275C14, 3.0f, 16777216.0f, 0.0f);
                func_802FA060(D_80275C14, 3500, 3500, 0.0f);
            }

            if (D_80275C1C != D_80275C18) {
                    D_80275C1C = D_80275C18;
                    if (D_80275C18) {
                        func_802F9FD0(D_80275C10, 0.0f, 0.0f, 3.0f);
                        func_802F9FD0(D_80275C14, 0.0f, 0.0f, 3.0f);
                        D_80275C10 = -1;
                        D_80275C14 = 0;
                    }
            }

            if (core1_ce60_isPlayerInRange(2883, -10520, 6480)) {
                D_80275C18 = TRUE;
                core1_ce60_setChanMask(0xe040);
            } else {
                D_80275C18 = FALSE;
                core1_ce60_setChanMask(0x9c00);
            }
            break;

        case MAP_76_GL_640_NOTE_DOOR:
            core1_ce60_setChanMaskFromWaterState(0x8200, 0x81bf);
            break;

        case MAP_77_GL_RBB_LOBBY:
            core1_ce60_setChanMaskFromWaterState(0x8200, 0xf000);
            break;

        case MAP_78_GL_RBB_AND_MMM_PUZZLE:
            if (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) {
                core1_ce60_setChanMask(0x8200);
            } else if (346 <= sPlayerPosition[1] && core1_ce60_isPlayerInRange(-2202, 538, 872)) {
                core1_ce60_setChanMask(0x8C00);
            } else if (core1_ce60_isPlayerInRange(-54, 20, 2652)) {
                core1_ce60_setChanMask(0x81bf);
            } else {
                core1_ce60_setChanMask(0xf000);
            }
            break;

        case MAP_79_GL_CCW_LOBBY:
            if(796 <= sPlayerPosition[1] && sPlayerPosition[1] < 1100 && core1_ce60_isPlayerInRange(28, 4553, 1073)) {
                core1_ce60_setChanMask(0x81bf);
            } else if (-4 <= sPlayerPosition[1] && sPlayerPosition[1] < 360 && core1_ce60_isPlayerInRange(135, 4979, 2156)) {
                core1_ce60_setChanMask(0x81bf);
            } else {
                core1_ce60_setChanMask(0x9e00);
            }
            break;

        case MAP_80_GL_FF_ENTRANCE:
            if(sPlayerPosition[2] < 0x4e2)
                core1_ce60_setChanMask(0xe040);
            else
                core1_ce60_setChanMask(0x9e00);
            break;

        case MAP_7F_FP_WOZZAS_CAVE:
            core1_ce60_func_8024A9EC((sns_get_item_state(SNS_ITEM_ICE_KEY, 1) && core1_ce60_isPlayerInRange(1561, 2426, 1690)) ? 0x7ff8 : 0);
            core1_ce60_setChanMaskFromWaterState(0x20, 0x1f);
            break;

        case MAP_8B_RBB_ANCHOR_ROOM:
            core1_ce60_setChanMaskFromWaterState(0x800, 0x51ff);
            break;

        case MAP_34_RBB_ENGINE_ROOM:
            core1_ce60_setChanMaskFromWaterState(0x800, 0x43fe);
            break;

        case MAP_91_FILE_SELECT:
            if (!func_802C5A30()) {
                core1_ce60_setChanMaskWithValue(0x200, 0.5f);
            } else {
                core1_ce60_setChanMaskWithValue(0x1ff, 0.5f);
            }
            break;

        case MAP_8C_SM_BANJOS_HOUSE:
            core1_ce60_setChanMaskWithValue(0x1ff, 0.5f);
            break;

        case MAP_1D_MMM_CELLAR:
            core1_ce60_func_8024A9EC((sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && !(sPlayerPosition[0] < 570)) ? 0x7ff8 : 0);
            break;

        case MAP_46_CCW_WINTER:
            core1_ce60_func_8024A9EC(0);
            break;
    }
}

void core1_ce60_incOrDecCounter(bool increment) {
    if (increment) {
        sUnusedCounter++;
    }
    else {
        sUnusedCounter--;
    }
}

void core1_ce60_func_8024BD40(s32 arg0, s32 arg1) {
    if (arg1 == 3)
        return;
    
    if (arg1 == 2) {
        D_802806F4 = TRUE;
    }
    else {
        D_802806F4 = FALSE;
    }
}
