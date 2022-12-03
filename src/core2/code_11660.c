#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* .bss */
void *D_8037C5D0;

/* .code */
s32 func_802985F0(void){
    switch(_player_getTransformation())
    {
        case TRANSFORM_2_TERMITE: //80298624
            return ASSET_34F_MODEL_BANJO_TERMITE;
        case TRANSFORM_3_PUMPKIN: //8029862C
            return ASSET_36F_MODEL_BANJO_PUMPKIN;
        case TRANSFORM_5_CROC: //80298634
            return ASSET_374_MODEL_BANJO_CROC;
        case TRANSFORM_4_WALRUS: //8029863C
            return ASSET_359_MODEL_BANJO_WALRUS;
        case TRANSFORM_6_BEE: //80298644
            return ASSET_362_MODEL_BANJO_BEE;
        case TRANSFORM_7_WISHWASHY: //8029864C
            return ASSET_356_MODEL_BANJO_WISHYWASHY;
        case TRANSFORM_1_BANJO: //80298654
        default:
        {
            switch (map_get())
            {
                case MAP_20_CS_END_NOT_100:
                case MAP_7B_CS_INTRO_GL_DINGPOT_1:
                case MAP_7C_CS_INTRO_BANJOS_HOUSE_1:
                case MAP_7D_CS_SPIRAL_MOUNTAIN_1:
                case MAP_7E_CS_SPIRAL_MOUNTAIN_2:
                case MAP_81_CS_INTRO_GL_DINGPOT_2:
                case MAP_82_CS_ENTERING_GL_MACHINE_ROOM:
                case MAP_83_CS_GAME_OVER_MACHINE_ROOM:
                case MAP_84_CS_UNUSED_MACHINE_ROOM:
                case MAP_85_CS_SPIRAL_MOUNTAIN_3:
                case MAP_86_CS_SPIRAL_MOUNTAIN_4:
                case MAP_87_CS_SPIRAL_MOUNTAIN_5:
                case MAP_88_CS_SPIRAL_MOUNTAIN_6:
                case MAP_89_CS_INTRO_BANJOS_HOUSE_2:
                case MAP_8A_CS_INTRO_BANJOS_HOUSE_3:
                    return 0x34d;

                case MAP_1_SM_SPIRAL_MOUNTAIN:
                case MAP_2_MM_MUMBOS_MOUNTAIN:
                case MAP_7_TTC_TREASURE_TROVE_COVE:
                case MAP_B_CC_CLANKERS_CAVERN:
                case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
                case MAP_12_GV_GOBIS_VALLEY:
                case MAP_1B_MMM_MAD_MONSTER_MANSION:
                case MAP_27_FP_FREEZEEZY_PEAK:
                case MAP_31_RBB_RUSTY_BUCKET_BAY:
                case 0x32:
                case MAP_43_CCW_SPRING:
                case MAP_44_CCW_SUMMER:
                case MAP_45_CCW_AUTUMN:
                case MAP_46_CCW_WINTER:
                case 0x56:
                    return 0x34d;
                    
                default:
                    return 0x34e;
            }
        }
    }
}

void func_802986D0(void){
    if(D_8037C5D0){
        assetcache_release(D_8037C5D0);
    }
}

void func_80298700(void){
    s32 sp1C = func_802985F0();
    if(func_8028ADB4()){
        D_8037C5D0 = 0;
    }
    else if(sp1C){
            D_8037C5D0 = assetcache_get(sp1C);
    }
    else{
        D_8037C5D0 = NULL;
    }
}
