#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

typedef struct {
    s16 x_min;
    s16 x_max;
    s16 y_min;
    s16 y_max;
    s16 z_min;
    s16 z_max;
} Struct_Core1_CE60_0s;

void func_80250530(s32, u16 chan_mask, f32);

/* .data */
s32 D_80275C10 = -1;
s32 D_80275C14 = 0;
u8  D_80275C18 = 0;
u8  D_80275C1C = 0;
Struct_Core1_CE60_0s D_80275C20[] = {
    {0xE890, 0xF9D4, 0xDCD8, 0x2328, 0xE7C8, 0xFB34}, 
    {0xF95C, 0xFE73, 0xDCD8, 0x2328, 0xE69C, 0xF711},
    {0xFA83, 0xFFAB, 0xDCD8, 0x2328, 0xE886, 0xEFFB},
    {0xEA84, 0xF85B, 0xDCD8, 0x2328, 0xF830, 0xFD90},
    {0xFEC0, 0x0140, 0x05DC, 0x0960, 0xE890, 0xFE7B},
    {0xFD44, 0x05D8, 0xFD44, 0x06C2, 0xFC2E, 0x03D2},
    {0xE890, 0xF9D4, 0xDCD8, 0x2328, 0xE7C8, 0xFB34}
};

/* .bss */
s32 D_802806F0;
int D_802806F4;
s32 D_802806F8[4];
s32 D_80280708[4];


/* .code */
void func_8024A880(s32 chan_mask){
    func_80250530(0, chan_mask, 3.0f);
}

void func_8024A8AC(s32 chan_mask, f32 arg1){
    func_80250530(0, chan_mask, arg1);
}

int func_8024A8DC(s32 arg0, s32 arg1, s32 arg2){
    return (arg0 - D_802806F8[0])*(arg0 - D_802806F8[0]) + (arg1 - D_802806F8[2])*(arg1 - D_802806F8[2]) < arg2*arg2; 
}

f32 func_8024A928(f32 arg0, f32 arg1){
    return gu_sqrtf((arg0 - D_802806F8[0])*(arg0 - D_802806F8[0]) + (arg1 - D_802806F8[2])*(arg1 - D_802806F8[2]));
}

int func_8024A984(s32 arg0){
    func_802585E0(D_802806F8, D_80275C20[arg0].x_min, D_80275C20[arg0].y_min, D_80275C20[arg0].z_min, D_80275C20[arg0].x_max, D_80275C20[arg0].y_max, D_80275C20[arg0].z_max);
}

void func_8024A9EC(s32 arg0){
    if(!func_8025ADBC(D_80280708[0]) && D_80280708[2]){
        func_8025A104(D_80280708[0], 0);
    }
    func_8025A55C(D_80280708[2], arg0 ? arg0 : 0x1f4, 4 );
    if(func_8025AD7C(D_80280708[1]) || D_80280708[3]){
        func_8025ABB8(D_80280708[1], D_80280708[3], arg0 ? arg0 : 0x1f4, 4 );
    }//L8024AA94
    func_8025A864(D_80280708[1]);
}

void func_8024AAB0(void){
    f32 plyr_pos[3]; //sp34
    f32 sp30;

    player_getPosition_s32(&D_802806F8);
    player_getPosition(plyr_pos);
    D_80280708[0] = func_8032274C();
    D_80280708[1] = func_80322758();
    D_80280708[2] = D_80280708[3] = 0;
    if(0 <= D_80280708[0])
        D_80280708[2] = func_80250034(D_80280708[0]);
    if(0 <= D_80280708[1])
        D_80280708[3] = func_80250034(D_80280708[1]);
    switch(map_get()){
        case MAP_7_TTC_TREASURE_TROVE_COVE: //L8024ABA8
            D_80280708[2] = ml_map_f(4700 - D_802806F8[1], 0.0f, 900.0f, 0.0f, D_80280708[2]);
            D_80280708[3] = ml_map_f(4700 - D_802806F8[1], 0.0f, 900.0f, D_80280708[3], 0.0f);
            break;
        case MAP_B_CC_CLANKERS_CAVERN: //
            sp30 = func_8024A928(13909.0f, -26.0f);
            D_80280708[2] = ml_map_f(sp30, 1500.0f, 1800.0f, 0.0f, D_80280708[2]);
            D_80280708[3] = ml_map_f(sp30, 1500.0f, 1800.0f, D_80280708[3], 0.0f);
            break;
        case MAP_1_SM_SPIRAL_MOUNTAIN: //L8024ACC4
            if(func_8024A984(4))
                D_80280708[2] = 0;
            else
                D_80280708[3] = 0;
            break;
        case MAP_1B_MMM_MAD_MONSTER_MANSION: //L8024ACE4
            if(func_80309D58(plyr_pos, 1)){
                D_80280708[2] = 0;
            }
            else{
                D_80280708[3] = 0;
            }
            break;
        case MAP_41_FP_BOGGYS_IGLOO: //L8024AD08
            if( jiggyscore_isCollected(JIGGY_2E_FP_PRESENTS)
                || (levelSpecificFlags_get(LEVEL_FLAG_11_FP_UNKNOWN) && levelSpecificFlags_get(LEVEL_FLAG_12_FP_UNKNOWN) && levelSpecificFlags_get(LEVEL_FLAG_13_FP_UNKNOWN))
            ){
                D_80280708[2] = 0;
            }
            else{
                D_80280708[3] = 0;
            }
            break;
        case MAP_1D_MMM_CELLAR: //L8024AD58
            if(sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && D_802806F8[0] >= 0x23A){
                D_80280708[2] = 0;
            }
            else{
                D_80280708[3] = 0;
            }
            break;
        case MAP_7F_FP_WOZZAS_CAVE: //L8024AD8C
            if(sns_get_item_state(SNS_ITEM_ICE_KEY, 1) && func_8024A8DC(0x619, 0x97a, 0x69a)){
                D_80280708[2] = 0;
            }
            else{
                D_80280708[3] = 0;
            }
            break;
        case MAP_45_CCW_AUTUMN: //L8024ADC0
        case MAP_46_CCW_WINTER: //L8024ADC0
            if(func_8024A984(5)){
                D_80280708[2] = 0;
            }
            else{
                D_80280708[3] = 0;
            }
            break;
    }//L8024ADE0
}

void func_8024ADF0(s32 arg0){
    func_8024AAB0();
    if(arg0)
        func_8025A9D4();
    
    if(0 < D_80280708[0] && 0 < D_80280708[2])
        func_8025A104(D_80280708[0], D_80280708[2]);
    
    if(0 < D_80280708[1] && 0 < D_80280708[3])
        func_8025A6CC(D_80280708[1], D_80280708[3]);
}

void func_8024AE74(void){
    D_802806F0 = 0;
    D_80275C10 = -1;
    D_80275C14 = 0;
    D_80275C1C = D_80275C18 = func_8024A8DC(0xb43, -0x2918, 0x1950) ? 1 : 0;
}

void func_8024AED8(void){
    D_80275C10 = -1;
    D_80275C14 = 0;
    D_80275C18 = 0;
    D_80275C1C = 0;
}

void func_8024AF00(s32 arg0, s32 arg1){
    if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
        func_8024A880(arg0);
    }
    else{
        func_8024A880(arg1);
    }
}

void func_8024AF48(void){
    
    if(!D_802806F4)         return;
    if(volatileFlag_get(VOLATILE_FLAG_1))    return;
    if(volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) return;
    if(func_802D686C())     return;
    if(player_isDead())     return;
    if(gctransition_8030BDC0()) return;
    if(getGameMode() == GAME_MODE_A_SNS_PICTURE) return;

    player_getPosition_s32(D_802806F8);
    func_8024AAB0();
    switch(map_get()){
        case MAP_2_MM_MUMBOS_MOUNTAIN: // L8024B000
            if(func_8024A8DC(-4450, 4550, 1900) ||func_8024A8DC(-0x1777, 0x1820, 0x26c)){
                func_8024A880(0x1cc0);
            }
            else if(func_8024A8DC(0x119F, -0x760, 0x7d0)){
                func_8024A880(0xb0c0);
            }
            else if(func_8024A8DC(0x12c, -0x35a, 0x898)){
                func_8024A880(0x513f);
            }
            else{
                func_8024AF00(0x200, 0x103f);
            }
            break;

        case MAP_7_TTC_TREASURE_TROVE_COVE: // L8024B094
            func_8024A9EC(0);
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x600);
            }
            else if(func_8024A8DC(-0x12C, 0x58c, 0x866) 
                    || (func_8024A8DC(-0x12c, 0x58c, 0xc1c)
                        && D_802806F8[1] < 0x514
                        && !func_8024A8DC(-0x49, 0x2c43, 0x1c0c)
                        && !func_8024A8DC(0x6c8, 0xe04, 0x1c7)
                        && !func_8024A8DC(0x564, 0xf9a, 0x190)
                    )
            ){
                func_8024A880(0x7800);
            }
            else{
                func_8024A880(0x60ff);
            }
            break;
            
        case MAP_B_CC_CLANKERS_CAVERN: // L8024B158
            func_8024A9EC(0);
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                if(!(D_802806F8[1] < 0x28b)){
                    func_8024A8AC(0x8180, 5.0f);
                }
                else{
                    func_8024A8AC(0x3e00, 5.0f);
                }
            }
            else{
                func_8024A880(0x407f);
            }
            break;

        case MAP_12_GV_GOBIS_VALLEY:// L8024B1BC
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x8020);
            }
            else if(func_8024A8DC(-0xf96, 0x1626, 0xe74)){
                func_8024A880(0x797f);
            }
            else{
                func_8024A880(0x67fe);
            }
            break;

        case MAP_3_UNUSED: // L8024B214
            func_8024AF00(0x1800, 0x67fe);
            break;

        case MAP_5_TTC_BLUBBERS_SHIP: // L8024B228
            func_8024AF00(0x600, 0x7800);
            break;

        case MAP_1_SM_SPIRAL_MOUNTAIN: // L8024B23C
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x9000);
            }
            else{
                if(chmole_learnedAllSpiralMountainAbilities())
                    func_8024A9EC(0);
                func_8024A880(0x6fff);
            }
            break;

        case MAP_21_CC_WITCH_SWITCH_ROOM:// L8024B288
        case MAP_22_CC_INSIDE_CLANKER:// L8024B288
        case MAP_23_CC_GOLDFEATHER_ROOM:// L8024B288
            func_8024AF00(0x3c00, 0x61ff);
            break;

        case MAP_25_MMM_WELL:// L8024B29C
        case MAP_2F_MMM_WATERDRAIN_BARREL:// L8024B29C
            func_8024AF00(0x1000, 0xcfff);
            break;

        case MAP_13_GV_MEMORY_GAME:// L8024B2B0
        case MAP_14_GV_SANDYBUTTS_MAZE:// L8024B2B0
        case MAP_15_GV_WATER_PYRAMID:// L8024B2B0
        case MAP_16_GV_RUBEES_CHAMBER:// L8024B2B0
        case MAP_1A_GV_INSIDE_JINXY:// L8024B2B0
            func_8024AF00(0x3ffe, 0x4ffe);
            break;

        case MAP_1B_MMM_MAD_MONSTER_MANSION:// L8024B2C4
            if( !mapSpecificFlags_get(1)
                && !func_8025AD7C(COMUSIC_4_MMM_CLOCK_VERSION)
                && !func_8025AD7C(COMUSIC_3C_MINIGAME_LOSS)
            ){
                func_8024A9EC(0);
            }
            
            func_8024A880((mapSpecificFlags_get(1) ? 0x2000: 0) + 0xcfff);
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP: // L8024B328
            if( func_8024A8DC(0x762, -0x542, 0x578)
                || func_8024A8DC(-0x85, 0x7d8, 0x384)
                || func_8024A8DC(-0xe2d, -0x217, 0x578)
            ){
                func_8024A8AC(0x2f4f, 2.0f);
            }
            else{
                func_8024A8AC(0x6f4f, 2.0f);
            }
            break;

        case MAP_31_RBB_RUSTY_BUCKET_BAY:// L8024B38C
            if( (-4200 <= D_802806F8[0] && D_802806F8[0] < -3700)
                && (-900 <= D_802806F8[2] && D_802806F8[2] < 900)
            ){
                func_8024A880(0x51ff);
            }
            else{
                func_8024AF00(0x800, 0x71bf);
            }
            break;
            
        case MAP_35_RBB_WAREHOUSE:// L8024B3E8
        case MAP_36_RBB_BOATHOUSE:// L8024B3E8
        case MAP_37_RBB_CONTAINER_1:// L8024B3E8
        case MAP_38_RBB_CONTAINER_3:// L8024B3E8
        case MAP_3E_RBB_CONTAINER_2:// L8024B3E8
            func_8024AF00(0x800, 0xfe);
            break;
            
        case MAP_40_CCW_HUB:// L8024B3FC
            if(func_8024A8DC(0, 0, 0x802)){
                func_8024A8AC(7, 2.0f);
            }
            else if(0x5aa <= D_802806F8[2]){
                func_8024A8AC(0x407, 2.0f);
            }
            else if(D_802806F8[0] < -0x5a9){
                func_8024A8AC(0x707, 2.0f);
            }
            else if(D_802806F8[2] < -0x5a9){
                func_8024A8AC(0x1067, 2.0f);
            }
            else if(0x5aa <= D_802806F8[0]) {
                func_8024A8AC(0x7007, 2.0f);
            }
            break;

        case MAP_A_TTC_SANDCASTLE: // L8024B4AC
            func_8024AF00(0xCE, 0x3C);
            break;

        case MAP_43_CCW_SPRING:// L8024B4C0
            func_8024AF00(0x400, 0x7bbf);
            break;

        case MAP_45_CCW_AUTUMN:// L8024B4D4
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x600);
            }
            else{
                func_8024A9EC(0);
                func_8024A880(0x7BEF);
            }
            break;

        case MAP_54_UNUSED:// L8024B510
        case MAP_55_UNUSED:// L8024B510
        case MAP_57_UNUSED:// L8024B510
        case MAP_58_UNUSED:// L8024B510
        case MAP_59_UNUSED:// L8024B510
            func_8024AF00(0xc, 0x307b);
            break;
            
        case MAP_56_UNUSED:// L8024B524
            func_8024AF00(0x10, 0x4f6f);
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:// L8024B538
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x400);
            }
            else if( mapSpecificFlags_get(0) && !jiggyscore_isCollected(JIGGY_2F_FP_XMAS_TREE)){
                func_8024A880(0x4bff);
            }
            else{
                func_8024A880(0x43ff);
            }
            break;
            
        case MAP_65_CCW_SPRING_WHIPCRACK_ROOM:// L8024B59C
            func_8024A880(0x107);
            break;

        case MAP_66_CCW_SUMMER_WHIPCRACK_ROOM:// L8024B5AC
            func_8024A880(0x1C7);
            break;

        case MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM:// L8024B5BC
            func_8024A880(0xC07);
            break;

        case MAP_68_CCW_WINTER_WHIPCRACK_ROOM:// L8024B5CC
            func_8024A880(0x1407);
            break;

        case MAP_5E_CCW_SPRING_NABNUTS_HOUSE:// L8024B5DC
            func_8024A880(0x41fe);
            break;
            
        case MAP_5F_CCW_SUMMER_NABNUTS_HOUSE:// L8024B5EC
            func_8024A880(0x71fe);
            break;
            
        case MAP_60_CCW_AUTUMN_NABNUTS_HOUSE:// L8024B5FC
            func_8024A880(0x7fe);
            break;
            
        case MAP_61_CCW_WINTER_NABNUTS_HOUSE:// L8024B60C
            func_8024A880(0xbfe);
            break;
            
        case MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY:// L8024B61C
            func_8024AF00(1, 0x7fe);
            break;

        case MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY:// L8024B630
            func_8024AF00(1, 0xbfe);
            break;

        case MAP_69_GL_MM_LOBBY:// L8024B644
            if(func_8024A8DC(0xdb6, -0x65e, 0x4e2))
                func_8024A880(0x7c00);
            else
                func_8024A880(0x41ff);
            break;

        case MAP_6A_GL_TTC_AND_CC_PUZZLE:// L8024B67C
            if(0x2b8 <= D_802806F8[1] && func_8024A8DC(-0x615, -0x389, 0x1dd)){
                func_8024A880(0x8e40);
            }
            else if(func_8024A8DC(0x5dc, -0x37a, 0x226) || func_8024A8DC(0x754, -0x453, 0x172)){
                func_8024A880(0xf040);
            }
            else{
                func_8024A880(0x81ff);
            }
            break;

        case MAP_6B_GL_180_NOTE_DOOR:// L8024B704
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x8800);
            }
            else if(func_8024A8DC(0x10eb, 0x4f5, 0x730)) {
                func_8024A880(0x8640);
            }
            else if(func_8024A8DC(-0x526, 0x777, 0x125) || func_8024A8DC(-0x515, 0x878, 0xea)){
                func_8024A880(0xf000);
            }else{
                func_8024A880(0x81bf);
            }

            break;

        case MAP_6C_GL_RED_CAULDRON_ROOM:// L8024B794
            func_8024A880(0x81bf);
            break;

        case MAP_6D_GL_TTC_LOBBY:// L8024B7A4
            func_8024A880(0xf000);
            break;

        case MAP_70_GL_CC_LOBBY:// L8024B7B4
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x8100);
            }
            else if(func_8024A8DC(-0x19d6, -0x1d3, 0x71e)){
                func_8024A880(0xf047);
            }
            else{
                func_8024A880(0x8e41);
            }
            break;

        case MAP_6E_GL_GV_LOBBY:// L8024B80C
            if(func_8024A8DC(0, -0x1996, 0xe42)){
                func_8024A880(0xfe00);
            }
            else{
                func_8024A880(0x81ff);
            }
            break;

        case MAP_6F_GL_FP_LOBBY:// L8024B844
            if(0xe75 <= D_802806F8[2]){
                func_8024A880(0xe040);
            }
            else{
                func_8024A880(0x81bf);
            }
            break;

        case MAP_74_GL_GV_PUZZLE:// L8024B878
            if(func_8024A8DC(-0xa49, -0x1f, 0x203)){
                func_8024A880(0xe600);
            }
            else{
                func_8024A880(0x81ff);
            }
            break;

        case MAP_75_GL_MMM_LOBBY:// L8024B8B0
        case MAP_7A_GL_CRYPT:// L8024B8B0
            func_8024A880(0xd800);
            break;

        case MAP_71_GL_STATUE_ROOM:// L8024B8C0
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x200);
            }
            else if(func_8024A8DC(-0xf0e, -0x15a, 0x302)){
                func_8024A880(0x9c00);
            }
            else{
                func_8024A880(0x81bf);
            }
            break;

        case MAP_72_GL_BGS_LOBBY:// L8024B918
            if(D_80275C10 == -1 && D_80275C18 == 0){
                D_80275C10 = func_802F9AA8(0x410);
                func_802F9F80(D_80275C10, 3.0f, 16777216.0f, 0.0f);
                func_802FA060(D_80275C10, 3500, 3500, 0.0f);
                
                D_80275C14 = func_802F9AA8(0x411);
                func_802F9F80(D_80275C14, 3.0f, 16777216.0f, 0.0f);
                func_802FA060(D_80275C14, 3500, 3500, 0.0f);
            }//L8024B9BC

            if(D_80275C1C != D_80275C18){
                    D_80275C1C = D_80275C18;
                    if(D_80275C18){
                        func_802F9FD0(D_80275C10, 0.0f, 0.0f, 3.0f);
                        func_802F9FD0(D_80275C14, 0.0f, 0.0f, 3.0f);
                        D_80275C10 = -1;
                        D_80275C14 = 0;
                    }
            }//L8024BA2C
            if(func_8024A8DC(0xb43, -0x2918, 0x1950)){
                D_80275C18 = 1;
                func_8024A880(0xe040);
            }
            else{
                D_80275C18 = 0;
                func_8024A880(0x9c00);
            }
            break;

        case MAP_76_GL_640_NOTE_DOOR:// L8024BA70
            func_8024AF00(0x8200, 0x81bf);
            break;

        case MAP_77_GL_RBB_LOBBY:// L8024BA84
            func_8024AF00(0x8200, 0xf000);
            break;

        case MAP_78_GL_RBB_AND_MMM_PUZZLE:// L8024BA98
            if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                func_8024A880(0x8200);
            }
            else if(0x15a <= D_802806F8[1] && func_8024A8DC(-0x89a, 0x21a, 0x368)){
                func_8024A880(0x8C00);
            }
            else if(func_8024A8DC(-0x36, 0x14, 0xa5c)){
                func_8024A880(0x81bf);
            }
            else{
                func_8024A880(0xf000);
            }
            break;

        case MAP_79_GL_CCW_LOBBY:// L8024BB2C
            if(0x31c <= D_802806F8[1] && D_802806F8[1] < 0x44c && func_8024A8DC(0x1c, 0x11c9, 0x431))
                func_8024A880(0x81bf);
            else if(-4 <= D_802806F8[1] && D_802806F8[1] < 0x168 && func_8024A8DC(0x87, 0x1373, 0x86c))
                func_8024A880(0x81bf);
            else
                func_8024A880(0x9e00);
            break;

        case MAP_80_GL_FF_ENTRANCE:// L8024BBBC
            if(D_802806F8[2] < 0x4e2)
                func_8024A880(0xe040);
            else
                func_8024A880(0x9e00);
            break;

        case MAP_7F_FP_WOZZAS_CAVE:// L8024BBF0
            func_8024A9EC((sns_get_item_state(SNS_ITEM_ICE_KEY, 1) && func_8024A8DC(0x619, 0x97a, 0x69a))? 0x7ff8 : 0);
            func_8024AF00(0x20, 0x1f);
            break;

        case MAP_8B_RBB_ANCHOR_ROOM:// L8024BC40
            func_8024AF00(0x800, 0x51ff);
            break;

        case MAP_34_RBB_ENGINE_ROOM:// L8024BC54
            func_8024AF00(0x800, 0x43fe);
            break;

        case MAP_91_FILE_SELECT:// L8024BC68
            if(!func_802C5A30()){
                func_8024A8AC(0x200, 0.5f);
            }
            else{
                func_8024A8AC(0x1ff, 0.5f);
            }
            break;

        case MAP_8C_SM_BANJOS_HOUSE:// L8024BC9C
            func_8024A8AC(0x1ff, 0.5f);
            break;

        case MAP_1D_MMM_CELLAR:// L8024BCB0
            func_8024A9EC((sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && !(D_802806F8[0] < 0x23a))? 0x7ff8 : 0);
            break;

        case MAP_46_CCW_WINTER:// L8024BCF0
            func_8024A9EC(0);
            break;
    }//L8024BCF8
}

void func_8024BD08(s32 arg0){
    if(arg0){
        D_802806F0++;
    }
    else{
        D_802806F0--;
    }
}

void func_8024BD40(s32 arg0, s32 arg1){
    if(arg1 == 3){
    }
    else{
        if(arg1 == 2){
            D_802806F4 = TRUE;
        }
        else{
            D_802806F4 = FALSE;
        }
    }
}
