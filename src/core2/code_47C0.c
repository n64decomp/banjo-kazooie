#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "SnS.h"

extern void func_803012F8(void);
extern f32 func_8024DDD8(f32[3], f32);
extern f32 ml_vec3f_distance_squared(f32 arg0[3], f32 arg1[3]);
extern void func_8028BA00(s32);
extern void func_802C418C(void);
extern void func_802A6388(f32);
extern f32 chwadingboots_802D6E4C(Actor *);
extern void func_80294AE8(f32);
extern f32 chtrainers_802CA748(Actor *);
extern int func_80259254(f32 vec[3], f32 x, f32 z, f32 val);
extern void func_802EE354(Actor *, s32, s32, s32, f32, f32, f32, f32 arg8[3], s32, f32 arg10[2]);
extern void func_8035644C(s32);
extern void func_8035646C(s32 arg0);
extern void func_80291634(ActorMarker *, ActorMarker *);
extern void func_80291610(ActorMarker *, ActorMarker *);
extern void func_80291AAC(void);
extern void func_8028D7B8(s32 arg0, ActorMarker *arg1, struct5Cs *collision_flags);
extern void func_802EE6CC(f32[3], s32, s32[4], s32, f32, f32, s32,s32,s32);
extern void func_80320ED8(ActorMarker *, f32, s32);


typedef struct 
{
    f32 unk0;
    f32 unk1;
    f32 unk2;
}
tmp_struct_type;

void func_8028D638(s32 arg0, s32 arg1);

/* .data */
s32 D_80363630[2] = {0x20, 0x1C};
s32 D_80363638[2] = {0x1C, 0x16};
s32 D_80363640[2] = {0x20, 0x01};
s32 D_80363648[2] = {0x1C, 0x18};
s32 D_80363650[2] = {0x20, 0x21};
s32 D_80363658[2] = {0x20, 0x28};
tmp_struct_type D_80363660 = {350.0f, 0.0f, 600.0f};
u8 D_8036366C[] = {
    0xff, 0xff, 0x00,
    0xff, 0x00, 0x00,
    0x00, 0xff, 0x00,
    0x00, 0x00, 0xff,
    0xff, 0x00, 0xff,
    0x00, 0xff, 0xff,
    0x00, 0x00
};

s32 D_80363680[4] = {0xff, 0xff, 0xff, 0xc8};

/* .bss */
ActorMarker *playerMarker;
s32 D_8037BF74;
s32 carriedObject_actorID;
s32 D_8037BF7C;
s32 D_8037BF80[2];
s32 D_8037BF88;
ActorMarker *D_8037BF8C;
u8 D_8037BF90;

/* .code */
s32 *func_8028B750(void){
    if(D_8037BF80[0]){
        return D_8037BF80;
    }
    else{
        switch(player_getTransformation()){
            case TRANSFORM_2_TERMITE: //8028B7A0
                return D_80363638; 
                break;

            case TRANSFORM_3_PUMPKIN: //8028B7AC
                return D_80363640;
                break;

            case TRANSFORM_4_WALRUS: //8028B7B8
                return D_80363650;
                break;

            case TRANSFORM_5_CROC: //8028B7C4
                return D_80363648;
                break;

            case TRANSFORM_6_BEE: //8028B7D0:
                return D_80363658;
                break;

            case TRANSFORM_1_BANJO: //8028B7DC
            default:
                return D_80363630;
                break;
        }
    }
}

void func_8028B7F4(void){
    yaw_setIdeal(func_8029B41C());
    func_802991A8(1);
    func_8029957C(3);
    func_802978DC(2);
    func_80297970(0.0f);
    func_8029151C(0xC);
}

void func_8028B848(void){
    s32 s0 = 0;
    if(map_get() == MAP_69_GL_MM_LOBBY){
        s0 = 0xf57;
    }
    else if(map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
        s0 = 0xb45;
    }

    if(s0){
        if(player_getTransformation() ==  TRANSFORM_1_BANJO){
            func_8028B7F4();
        }
        func_80311480(s0, 0x2A, NULL, NULL, NULL, 0);
    }
}

void func_8028B8DC(void){
    func_8028F918(1);
    D_8037BF88 = 1;
}

void func_8028B904(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    f32 sp1C[3];

    sp1C[0] = reinterpret_cast(s16, arg0);
    sp1C[1] = reinterpret_cast(s16, arg1);
    sp1C[2] = reinterpret_cast(s16, arg2);

    func_80296CC0(&sp1C);
    func_80296CB4(arg3);
    if(miscflag_isTrue(7)){
        func_8029CDA0();
    }
    else{
        if(bs_checkInterrupt(BS_INTR_9) == 1){
            func_8029CDA0();
        }

    }
}


void func_8028B9A8(s32 arg0){
    s16 *tmp_v0;
    s32 ideal_yaw[3];

    tmp_v0 = func_803049CC(0x1F6, 0);
    func_80304D4C(tmp_v0, &ideal_yaw);
    func_802CA1CC(arg0);
    func_8032811C(0x47, &ideal_yaw, 0);
    func_8025A6EC(COMUSIC_2B_DING_B, 28000);
    
}

void func_8028BA00(s32 arg0){
    __spawnqueue_add_1(func_8028B9A8, arg0);
    if(arg0);
}


void func_8028BA2C(s32 arg0) {
    if (func_802FADD4(0x1B) == 0) {
        item_inc(ITEM_C_NOTE);
    } else {
        func_803463F4(ITEM_C_NOTE, 1);
    }
    if (item_getCount(ITEM_C_NOTE) < 100) {
        func_8025A6EC(COMUSIC_9_NOTE_COLLECTED, 0x3E80);
        timedFunc_set_1(0.75f, func_8035644C, 3);
    }
    func_802F379C(arg0 + 4);
}

void func_8028BAB0(enum jiggy_e jiggy_id, s32 arg1, s32 arg2, s32 arg3){
    if(jiggyscore_isCollected(jiggy_id))
        return;

    if(mapSpecificFlags_get(arg1) && mapSpecificFlags_get(arg2)){
        mapSpecificFlags_set(arg3, 1);
    }
    mapSpecificFlags_set(arg1, 1);
    func_8030E6D4(SFX_90_SWITCH_PRESS);
}

void func_8028BB1C(s32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6){
    u32 sp24;
    if(arg0 != 1)
        return;
    
    if(func_8028ECAC() == 1)
        return;

    if(arg1 & 0x400000){
        sp24 = arg1 + 0xFFC00000;
        if(!func_803203FC(sp24)){
            func_803204E4(sp24, 1);
            func_8030E6D4(SFX_90_SWITCH_PRESS);
            func_803204E4(0xBF, 1);
            func_802D6264(1.0f, arg2, arg3, arg4, arg5, arg6);
        }
    }
    else{//L8028BBB8
        if(!func_8031FF1C(arg1)){
            func_80320004(arg1, 1);
            func_8030E6D4(SFX_90_SWITCH_PRESS);
            func_803204E4(0xBF, 1);
            func_802D6264(1.0f, arg2, arg3, arg4, arg5, arg6);
        }
    }
}

int func_8028BC20(ActorMarker *marker){
    return D_8037BF90 == 1 && player_getActiveHitbox(marker) == HITBOX_5_PECK;
}

int func_8028BC60(void){
    return D_8037BF90 == 1 && player_getActiveHitbox(NULL) == HITBOX_5_PECK;
} 

void func_8028BCA0(Prop *prop){
    s32 plyr_collision_type;
    s32 obj_collision_type;
    s32 plyr_hitbox_type;
    int i;
    ActorMarker *marker; //0xbc
    Actor *actor; //0xb8
    f32 spAC[3];
    f32 spA0[3];
    s32 sp9C;
    s32 sp98;
    volatile s32 sp94;
    s32 sp88[3]; //0
    s32 tmp2;
    s32 tmp3;
    s32 sp7C; //+4
    s32 sp78; //+4
    s32 tmp_v0_2;
    f32 tmp_f0;
    tmp_struct_type sp64;
    s32 tmp1;

    if(*((u32*)(((u32)prop) + 8)) & 1){
        plyr_collision_type = 0;
        obj_collision_type = 0;
        marker = prop->actorProp.marker;
        actor = NULL;
        if(marker->unk3E_0){
            actor = marker_getActor(marker);
            if(actor->despawn_flag)
                return;

            if(actor->unk10_0 && func_802C9C14(actor))
                return;
            
        }//L8028BD1C
        plyr_hitbox_type = player_getActiveHitbox(marker);
        if(func_8033D410(playerMarker, marker))
            return;
        
        switch(marker->unk14_20){
            case 0x125: //L8028BE88
            case 0x126: //L8028BE88
                obj_collision_type = 1;
                break;

            case 0x97: //L8028BE94
                plyr_collision_type = 1;
                obj_collision_type = 1;
                break;

            case 0xBA: //L8028BEA8
                if( marker->unk40_31 == 1
                    || marker->unk40_31 == 2
                    || marker->unk40_31 == 3
                    || marker->unk40_31 == 4
                    || marker->unk40_31 == 5
                    || marker->unk40_31 == 6
                ){
                    obj_collision_type = 1;
                }
                break;

            case 0xB5: //L8028BEF4
                if(func_8028BC20(marker) != HITBOX_0_NONE)
                    return;
                if(func_802D8E68(prop)){
                    marker_despawn(marker);
                }
                break;

            case 0x1E5: //L8028BF24
                if(func_8028BC20(marker))
                    return;
                
                if(func_802D8EDC(prop)){
                    marker_despawn(marker);
                }
                break;
            
            case 0x9E: //L8028BF54
            case 0xA1: //L8028BF54
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    func_802A02B4(1);
                    obj_collision_type = 2;
                }
                break;

            case 0x28: //L8028BF74
                if( plyr_hitbox_type == HITBOX_6_WONDERWING){
                    func_8030E484(SFX_20_METAL_CLANK_1);
                }
                else{
                    func_8030E6D4(SFX_65_METALLIC_SCRATCH);
                }

                if(plyr_hitbox_type != HITBOX_6_WONDERWING){
                    plyr_collision_type = 2;
                }
                break;

            case 0xF5: //L8028BFB0
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    func_8028BAB0(JIGGY_20_BGS_ELEVATED_WALKWAY, 1, 3, 7);
                break;
                
            case 0xFD: //L8028BFD4
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    func_8028BAB0(JIGGY_25_BGS_MAZE, 0xa, 0xc, 8);
                break;
                
            case 0xEC: //L8028BFF8
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    mapSpecificFlags_set(3, 1);
                    func_8030E6D4(SFX_90_SWITCH_PRESS);
                }
                break;
                
            case MARKER_F2_HONEYCOMB_SWITCH: //L8028C01C
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(!mapSpecificFlags_get(0xD)){
                        mapSpecificFlags_set(0xD, 1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                        func_802BAFE4(0x14);
                        timedFunc_set_1(1.5f, func_8028BA00, 0xB);
                    }
                }
                break;

            case 0x15F: //L8028C070
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                        func_802BAFE4(0x7E);
                        timedFunc_set_1(1.5f, func_8028BA00, 0xf);
                    }
                }
                break;

            case MARKER_F1_GV_STAR_SWITCH: //L8028C0C8
                if(func_8028ECAC() == 1)
                    return;
                if(!mapSpecificFlags_get(5)){
                    mapSpecificFlags_set(5, 1);
                    func_8030E6D4(SFX_90_SWITCH_PRESS);
                }
                break;
                
            case 0x231: //L8028C104
            case 0x244: //L8028C104
                {

                    if(func_8028ECAC() == 1)
                        return;
                    player_getPosition(spAC);
                    spAC[1] += 40.0f;
                    if(func_802458E0(spAC, actor, 0x87) == 0)
                        return;
                    func_803204E4(0x1E, 1);
                    if(func_8031FF1C(((actor->unkF4_8 - 1) ^ 1) + 0x49)){
                        actor->unk10_12 = 2;
                    }
                    else{
                        actor->unk10_12 = 1;
                    }
                }
                break;

            case MARKER_FE_MMM_CLOCK_SWITCH: //L8028C1A4
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(func_8028ECAC() == 1)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
            
            case MARKER_23F_LAIR_FLIGHT_PAD_SWITCH: //L8028C1EC
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(func_8028ECAC() == 1)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;

            case 0x110: //L8028C238
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(func_8028ECAC() == 1)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0, 1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
                
            case 0x113: //L8028C284
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(func_8028ECAC() == 1)
                        return;
                    if(!mapSpecificFlags_get(1)){
                        mapSpecificFlags_set(1,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
                
            case 0x115: //L8028C2D0
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(func_8028ECAC() == 1)
                        return;
                    if(!mapSpecificFlags_get(2)){
                        mapSpecificFlags_set(2,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;

            case 0x241: //L8028C31C
                func_8028BB1C(plyr_hitbox_type, 0xC6, 0x6E, 0x81, 0x2C, 0xA, 0xC7);
                break;

            case MARKER_23C_GV_SNS_SWITCH: //L8028C350
                func_8028BB1C(plyr_hitbox_type, 0xA3, 0x92, 0x7F, 0x1A, 0xA, 0xA4);
                break;

            case MARKER_161_GV_WITCH_SWITCH: //L8028C384
                func_8028BB1C(plyr_hitbox_type, 0x4000BE, 0x6E, 0x7D, 0x19, 0x14, 0xA0);
                break;

            case MARKER_162_BGS_WITCH_SWITCH: //L8028C3BC
                func_8028BB1C(plyr_hitbox_type, 0x4000BD, 0x71, 0x7C, 0x18, 0x14, 0x9F);
                break;
            case MARKER_166_CC_WITCH_SWITCH: //L8028C3F4
                func_8028BB1C(plyr_hitbox_type, 0x4000BC, 0x6A, 0x7A, 0x17, 0x14, 0x9A);
                break;
           
            case MARKER_22B_FP_WITCH_SWITCH: //L8028C42C
                func_8028BB1C(plyr_hitbox_type, 0x4000BB, 0x6F, 0x3A, 0x13, 0x15, 0x47);
                break;

            case MARKER_22A_CCW_WITCH_SWITCH: //L8028C464
                func_8028BB1C(plyr_hitbox_type, 0x4000BA, 0x79, 0x39, 0x12, 0x15, 0x46);
                break;

            case MARKER_103_MM_WITCH_SWITCH: //L8028C49C
                func_8028BB1C(plyr_hitbox_type, 0x4000B6, 0x69, 0x26, 1, 4, 0x18);
                break;
                
            case MARKER_104_MMM_WITCH_SWITCH: //L8028C4D4
                func_8028BB1C(plyr_hitbox_type, 0x4000B7, 0x6F, 0x27, 2, 0x14, 0x19);
                break;
                
            case MARKER_105_TTC_WITCH_SWITCH: //L8028C50C
                func_8028BB1C(plyr_hitbox_type, 0x4000B8, 0x6D, 0x28, 3, 0x14, 0x1A);
                break;
                
            case MARKER_106_RBB_WITCH_SWITCH: //L8028C544
                func_8028BB1C(plyr_hitbox_type, 0x4000B9, 0x76, 0x29, 4, 0xe, 0x1C);
                break;
                
            case MARKER_11B_WATER_LEVEL_SWITCH_1: //L8028C57C
                func_8028BB1C(plyr_hitbox_type, 0x22, 0x77, 0x2D, 5, 0xA, 0x23);
                break;
                
            case MARKER_11C_WATER_LEVEL_SWITCH_2: //L8028C5B0
                func_8028BB1C(plyr_hitbox_type, 0x24, 0x77, 0x2E, 6, 0xA, 0x25);
                break;
                
            case MARKER_11D_WATER_LEVEL_SWITCH_3: //L8028C5E4
                func_8028BB1C(plyr_hitbox_type, 0x26, 0x76, 0x2F, 0x7, 0xA, 0x27);
                break;

            case 0x232: //L8028C618
                func_8028BB1C(plyr_hitbox_type, 0x53, 0x6b, 0x3b, 0x14, 0x12, 0x54);
                break;

            case MARKER_F3_GV_KAZOOIE_TARGET: //L8028C64C
                if(plyr_hitbox_type == HITBOX_3_BEAK_BOMB){
                    mapSpecificFlags_set(6,1);
                    obj_collision_type = 1;
                }
                break;


            case MARKER_52_JIGGY: //L8028C66C
                {
                    if(func_8028BC20(marker))
                        return;
                    
                    player_getPosition(spA0);
                    sp9C = func_802C8088(actor);
                    if( sp9C != JIGGY_2F_FP_XMAS_TREE
                        || (func_8028B2E8() && !(3600.0f < ml_vec3f_distance_squared(actor->position, spA0)))
                    ){
                        jiggyscore_setCollected(sp9C, 1);
                        func_803463F4(ITEM_26_JIGGY_TOTAL, 1);
                        if(sp9C == JIGGY_20_BGS_ELEVATED_WALKWAY || sp9C == JIGGY_25_BGS_MAZE){
                            func_802D6924();
                        }
                        if(jiggyscore_total() < 3){
                            func_8028B848();
                        }

                        if(func_8025AD7C(COMUSIC_30_5TH_JINJO_COLLECTED)){
                            func_8028B8DC();
                        }

                        func_802C3F04(func_8028B904, reinterpret_cast(u32, prop->actorProp.x), reinterpret_cast(u32, prop->actorProp.y), reinterpret_cast(u32, prop->actorProp.z), sp9C);
                        marker_despawn(marker);
                    }
                }
                break;

            case MARKER_53_EMPTY_HONEYCOMB: //L8028C774
                {
                    
                    if(func_8028BC20(marker))
                        return;
                    sp98 = func_802CA1C4(marker_getActor(marker));
                    if(sp98 != HONEYCOMB_12_MMM_FLOORBOARD || player_getTransformation() == TRANSFORM_3_PUMPKIN)
                    {
                        honeycombscore_set(sp98, 1);
                        func_8025A6EC(COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED, 28000);
                        timedFunc_set_1(2.0f, func_8035644C, 0xB);
                        item_inc(ITEM_13_EMPTY_HONEYCOMB);
                        if(!(item_getCount(ITEM_13_EMPTY_HONEYCOMB) < 6)){
                            gcpausemenu_80314AC8(0);
                        }
                        func_802F36DC(&prop->actorProp.x);
                        marker_despawn(marker);
                    }
                }
                break;

            case 0x54: //L8028C820
                func_8025A6EC(COMUSIC_19_LOW_PITCH_FLUTES, 28000);
                func_803012F8();
                func_802C3F04(func_802C418C, 0x4E, reinterpret_cast(u32, prop->actorProp.x), reinterpret_cast(u32, prop->actorProp.y), reinterpret_cast(u32, prop->actorProp.z));
                marker_despawn(marker);
                break;

            case MARKER_55_HONEYCOMB: //L8028C86C
                if(func_8028BC20(marker))
                    return;
                
                if( map_get() == MAP_8E_GL_FURNACE_FUN
                    && func_803203FC(0)
                    && !func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)
                ){
                    func_80356540(BKPROG_A6_FURNACE_FUN_COMPLETE);
                    func_8030E6D4(SFX_126_AUDIENCE_BOOING);
                }  

                func_8025A6EC(COMUSIC_16_HONEYCOMB_COLLECTED, 28000);
                timedFunc_set_1(0.75f, func_8035644C, 0xA);
                item_inc(ITEM_14_HEALTH);
                func_802F373C(&prop->actorProp.x);
                marker_despawn(marker);
                break;

            case MARKER_169_SNS_EGG: //L8028C908
                { //ONLY THIS CASE DOESN'T MATCH
                    switch (map_get())
                    {
                    case MAP_1D_MMM_CELLAR: //L8028C95C
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_CYAN, 0, 1);
                        break;
                    case MAP_61_CCW_WINTER_NABNUTS_HOUSE: //L8028C974
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_YELLOW, 0, 1);
                        break;
                    case MAP_2C_MMM_BATHROOM: //L8028C988
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_GREEN, 0, 1);
                        break;
                    case MAP_3F_RBB_CAPTAINS_CABIN: //L8028C99C
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_RED, 0, 1);
                        break;
                    case MAP_92_GV_SNS_CHAMBER: //L8028C9B0
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_BLUE, 0, 1);
                        break;
                    case MAP_8F_TTC_SHARKFOOD_ISLAND: //L8028C9C4
                        sns_set_item_and_update_payload(SNS_ITEM_EGG_PINK, 0, 1);
                        break;
                    }
                    func_8025A70C(COMUSIC_88_BIG_SNS_FANFARE);
                    FUNC_8030E624(SFX_114_BRICKWALL_BREAKING, 0.8f, 15000);
                    tmp_v0_2 = 3*(actor->unkF4_8 - 1);
                    
                    tmp_f0 = 0.9f;\
                    sp64 = D_80363660;
                    //+C
                    sp78 = 0xA;
                    sp94 = 0xAA;

                    for(sp7C = 0; sp7C < 4; sp7C++){ //L8028CA4C
                        
                        for(i = 0 ; i < 3; i++){
                            sp88[i] = D_8036366C[tmp_v0_2 + i];
                        }
                        func_802EE354(actor, 0x3ED, 0x23, sp78, 0.2f, tmp_f0, 3.0f, sp88, 0, &sp64);
                        
                        for(i = 0 ; i < 3; i++){
                            sp88[i] = 0xFF;
                        }
                        func_802EE354(actor, 0x3ED, 0xe, sp78, 0.2f, tmp_f0, 3.0f, sp88, 0, &sp64);
                        
                        sp78 += 0x32;
                        tmp_f0 += -0.15;
                        if(tmp_f0 < 0.01){
                            tmp_f0 = 0.01f;
                        }
                
                        sp64.unk0 -= 50.0f;
                        sp64.unk2 += 260.0f;
                        sp94 -= 0x1e;
                    }
                
                    tmp1 = sns_get_item_state(SNS_ITEM_EGG_YELLOW, 0) + sns_get_item_state(SNS_ITEM_EGG_RED, 0) + sns_get_item_state(SNS_ITEM_EGG_GREEN, 0)
                        + sns_get_item_state(SNS_ITEM_EGG_BLUE, 0) + sns_get_item_state(SNS_ITEM_EGG_PINK, 0) + sns_get_item_state(SNS_ITEM_EGG_CYAN, 0);
                    if(tmp1 < 3){
                        func_80324DBC(2.5f, 0xDB2 + tmp1, 0x20, 0, 0, 0, 0);
                    }
                    
                    marker_despawn(marker);
                }
                break;
            case MARKER_168_ICE_KEY: //L8028CC7C
                sns_set_item_and_update_payload(SNS_ITEM_ICE_KEY, 0, 1);
                func_8025A70C(COMUSIC_88_BIG_SNS_FANFARE);
                func_80324DBC(2.5f, 0xDB5, 0x20, 0, 0, 0, 0);
                marker_despawn(marker);
                break;
            
            case MARKER_5F_MUSIC_NOTE: //L8028CCC8
                if(func_8028BC20(marker))
                    return;

                func_8028BA2C(prop);
                marker_despawn(marker);
                break;

            case 0x60: //L8028CCF0
                if(func_8028BC20(marker))
                    return;
                if(collect_egg(prop)){
                    marker_despawn(marker);
                }
                break;

            case 0x6B: //L8028CD20
                if(func_8028EE84() == BSWATERGROUP_2_UNDERWATER){
                    func_803463D4(ITEM_17_AIR, func_80301DBC(2));
                }
                break;

            case MARKER_61_EXTRA_LIFE: //L8028CD50
                if(func_8028BC20(marker))
                    return;
                if( map_get() == MAP_8E_GL_FURNACE_FUN
                    && func_803203FC(0)
                    && !func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE)
                ){
                    func_80356540(BKPROG_A7_NEAR_PUZZLE_PODIUM_TEXT);
                    func_8030E6D4(SFX_127_AUDIENCE_MIXED);
                }
                func_8025A6EC(COMUSIC_15_EXTRA_LIFE_COLLECTED, 0x7FFF);
                timedFunc_set_1(1.5f, func_8035646C, 0xC);
                func_802F3B3C(&prop->actorProp.x);
                item_inc(ITEM_16_LIFE);
                marker_despawn(marker);
                break;
            


            case 0xD4: //L8028CDEC
            case 0x242: //L8028CDEC
                if(ability_isUnlocked(ABILITY_D_SHOCK_JUMP)){
                    miscflag_set(MISC_FLAG_2_ON_SPRING_PAD);
                }else{
                    if(!func_80320454(0xC, 1)){
                        func_80311480(0xA24, 4, 0, 0, 0, 0);
                    }
                }
                break;

            case 0x45: //L8028CE3C
            case 0x240: //L8028CE3C
            case 0x261: //L8028CE3C
                if(ability_isUnlocked(ABILITY_9_FLY)){
                    miscflag_set(MISC_FLAG_1_ON_FLIGHT_PAD);
                }
                else if(! func_80320454(0xD, 1)){
                    func_80311480(0xA25, 4, 0, 0, 0, 0);
                }
                break;

            case MARKER_11_WADING_BOOTS: //L8028CE8C
                if(func_8028BC20(marker))
                    return;
                if(_player_getTransformation() != TRANSFORM_1_BANJO)
                    return;
                if(func_8028F170())
                    return;
                if(func_8028F25C())
                    return;
                if(chwadingboots_802D6E0C(actor) == 0)
                    return;
                
                miscflag_set(MISC_FLAG_E_TOUCHING_WADING_BOOTS);
                func_802A6388(chwadingboots_802D6E4C(actor));
                bs_checkInterrupt(BS_INTR_1B);
                func_802C3F04(func_802C418C, 0x4E, reinterpret_cast(u32, prop->actorProp.x), reinterpret_cast(u32, prop->actorProp.y), reinterpret_cast(u32, prop->actorProp.z));
                chwadingboots_802D6E54(actor);
                break;

            case MARKER_38_TURBO_TALON_TRAINERS: //L8028CF38
                if(func_8028BC20(marker))
                    return;

                tmp1 = _player_getTransformation();
                if(tmp1 != TRANSFORM_1_BANJO && tmp1 != TRANSFORM_5_CROC)
                    return;
                
                if(func_8028F25C())
                    return;

                if(func_8028F170())
                    return;
                
                if(chtrainers_802CA708(actor) == 0)
                    return;

                miscflag_set(MISC_FLAG_10_TOUCHING_TURBO_TRAINERS);
                func_80294AE8(chtrainers_802CA748(actor));
                bs_checkInterrupt(BS_INTR_1A);
                func_802C3F04(func_802C418C, 0x4E, reinterpret_cast(u32, prop->actorProp.x), reinterpret_cast(u32, prop->actorProp.y), reinterpret_cast(u32, prop->actorProp.z));
                chtrainers_802CA750(actor);
                break;

            case 0x1AE: //L8028CFEC
                switch(plyr_hitbox_type){
                    case HITBOX_1_BEAK_BUSTER:
                    case HITBOX_2_BEAK_BARGE:
                    case HITBOX_5_PECK:
                    case HITBOX_6_WONDERWING:
                        obj_collision_type = 2;
                        break;
                    default:
                        plyr_collision_type = 2;
                        break;
                }
                break;

            case 0x1B1: //L8028D024
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    obj_collision_type = 1;
                break;
        }//L8028D034
        if(func_80297C6C() == 3){
            plyr_collision_type = 0;
        }
        if(obj_collision_type){
            miscflag_set(8);
        }
        func_8032FFF4(playerMarker, marker, plyr_collision_type);
        func_8032FFF4(marker, playerMarker, obj_collision_type);
        if(marker->unk3E_0){
            func_8032B258(actor, obj_collision_type);
        }
    }
    else if(prop->unk8_1)//L8028D0B0 //ModelProp
    {
        tmp2 = prop->modelProp.unk0_31 + 0x2D1;
        switch (tmp2)
        {
        case 0x2E8:
            miscflag_set(MISC_FLAG_1_ON_FLIGHT_PAD); //on flight pad
            break;
        case 0x2DD: //on shock spring pad
            miscflag_set(MISC_FLAG_2_ON_SPRING_PAD);
            break;
        default:
            func_80332790(tmp2);
            break;
        }
    }
    else{//L8028D10C //SpriteProp
        tmp3 = prop->spriteProp.unk0_31 + 0x572;
        switch (tmp3)
        {
        case 0x6D6: //L8028D144
            if(!func_8028BC60()){
                prop->spriteProp.unk8_4 = 0;
                func_8028BA2C(prop);
            }
            break;
        case 0x6D7: //L8028D16C
            if(!func_8028BC60()){
                prop->spriteProp.unk8_4 = 0;
                collect_egg(prop);
            }
            break;
        case 0x580: //L8028D194
            if(!func_8028BC60()){
                prop->spriteProp.unk8_4 = 0;
                func_802D8E68(prop);
            }
            break;
        case 0x6D1: //L8028D1BC
            if(!func_8028BC60()){
                prop->spriteProp.unk8_4 = 0;
                func_802D8EDC(prop);
            }
            break;
        default:
            func_80332790(tmp3);
            break;
        }
    }
}

//player_initMarker
void playerMarker_init(void){
    f32 sp1C[3];
    _player_getPosition(sp1C);
    playerMarker = func_8032FBE4(sp1C, func_80291AAC, 1, 0);
    playerMarker->unk2C_1 = 1;
    marker_setCollisionScripts(playerMarker, NULL, func_80291634, func_80291610);
    func_803300B8(playerMarker, func_8028D7B8);
    miscflag_clear(MISC_FLAG_1_ON_FLIGHT_PAD);
    miscflag_clear(MISC_FLAG_2_ON_SPRING_PAD);
    miscflag_clear(8);
    func_8028D638(0,0);
    func_8033D2F4();
    D_8037BF8C = 0;
    D_8037BF90 = 0xff;
    
}

void playerMarker_free(void){
    marker_free(playerMarker);
    playerMarker = NULL;
}


void func_8028D2E4(void){
    f32 sp174[3];
    f32 sp168[3];
    s32 temp_s0;
    int i, j;
    Prop *sp58[65];
    s32 *temp_s0_2;
    s32 temp_s2;
    Prop *temp_s1;

    if ((D_8037BF88 != 0)){
        temp_s0 = func_8024FEEC(func_8025ADD4(COMUSIC_30_5TH_JINJO_COLLECTED) & 0xFF);
        if((func_80259B8C() < 4 && temp_s0 >= 0xBB9) || !func_8025AD7C(COMUSIC_30_5TH_JINJO_COLLECTED)){
            func_8028F918(0);
            D_8037BF88 = 0;
        }
    }//L8028D364
    miscflag_clear(8);
    if(playerMarker->collidable){
        temp_s0_2 = func_8028B750();
        miscflag_clear(MISC_FLAG_1_ON_FLIGHT_PAD);
        miscflag_clear(MISC_FLAG_2_ON_SPRING_PAD);
        _player_getPosition(sp168);
        func_8032F64C(sp168, playerMarker);
        for(D_8037BF8C = NULL, i = 0, temp_s2 = 0; i < 2;i++){//L8028D3DC
            D_8037BF90 = i;
            func_80292284(sp174, i); //get top of player?
            playerMarker->unk38[0] = sp174[0] - sp168[0];
            playerMarker->unk38[1] = sp174[1] - sp168[1];
            playerMarker->unk38[2] = sp174[2] - sp168[2];
            func_80320ED8(playerMarker, temp_s0_2[i], 1);
            while(temp_s1 = func_8032F528()){//L8028D480
                if(!temp_s1->unk8_2){
                    if(!D_8037BF8C && temp_s1->markerFlag && temp_s1->unk8_1){
                        D_8037BF8C = temp_s1->actorProp.marker;
                    }
                    func_8028BCA0(temp_s1);
                    temp_s1->unk8_2 = 1;
                    sp58[temp_s2] = temp_s1;
                    temp_s2++;
                }//L8028D4E0 
            }//L8028D4F0
        }
        D_8037BF90 = 0xff;

        for(j = 0; j < temp_s2; j++){//L8028D55C
            sp58[j]->unk8_2 = 0;
        }
    }
}

ActorMarker *_player_getMarker(void){ //_player_getMarker
    return playerMarker;
}

void func_8028D5DC(void){ //player_collisionOff
    playerMarker->collidable = 0;
}

void func_8028D5F4(void){ //player_collisionOn
    playerMarker->collidable = 1;
}

s32 func_8028D60C(void){ //player_isCollidable
    return (playerMarker->collidable)? 1 : 0;
}

void func_8028D638(s32 arg0, s32 arg1){
    D_8037BF80[0] = arg0;
    D_8037BF80[1] = arg1;
}

void func_8028D64C(s32 arg0){
    D_8037BF74 = arg0;
}

void carriedObject_setActorID(enum actor_e arg0){
    carriedObject_actorID = arg0;
}

s32 func_8028D664(void){
    return D_8037BF74;
}

enum actor_e carriedObject_getActorID(void){
    return carriedObject_actorID;
}

void func_8028D67C(s32 arg0){
    D_8037BF7C = arg0;
}

s32 func_8028D688(void){
    return D_8037BF7C;
}

s32 func_8028D694(void) {
    s32 temp_a0;
    s32 phi_v1;

    phi_v1 = 0;
    if (D_8037BF8C != NULL) {
        temp_a0 = D_8037BF8C->unk40_31 - 0xB;
        if ((temp_a0 >= 0) && (temp_a0 < 4) && (((1 << temp_a0) & D_8037BF8C->unk40_27))) {
            phi_v1 = 0x08000000 << temp_a0;
        }
    }
    return phi_v1 | 0x400000;
}


s32 func_8028D6F0(s32 **arg0){
    *arg0 = func_8028B750();
    return 2;
}

void func_8028D71C(void){
    f32 sp3C[3];
    f32 sp30[3];
    
    func_8028E9C4(5, sp30);
    player_getPosition(sp3C);
    sp3C[1] += (sp30[1] - sp3C[1])*0.75;
    func_802EE6CC(sp3C, 0, D_80363680, 1, 0.75f, 0.0f, 0x7d, 0xfa, 0);

}

void func_8028D7B8(s32 arg0, ActorMarker *arg1, struct5Cs *collision_flags){
    s32 sp24;
    s32 sp20 = func_8033D594(collision_flags);
    s32 sp1C = 0;
    Actor *actor = marker_getActor(arg1);
    s32 tmp_v0;

    if(func_8033D5A4(collision_flags))
        miscflag_set(8);

    if((func_80297C6C() != 3 && func_8028F1E0()) || !sp20){
        if(!func_8028F25C()){
            sp24 = func_8033D564(collision_flags);
            if(0 < sp24 && sp24 < 6){
                sp1C = 2;
                sp20 = MAX(0, sp20 - 1);
            }//L8028D884

            if(6 < sp24 && sp24 < 0xC){
                if(!(1 < func_8033D5A4(collision_flags)) || (func_8033D574(collision_flags) != -1 && actor->unk164[func_8033D574(collision_flags)])){
                    sp1C = 1;
                }//L8028D8E8
            }//L8028D8E8

            if(sp20){
                if(func_8033D594(collision_flags) == 3){
                    func_803463D4(ITEM_14_HEALTH, -item_getCount(ITEM_14_HEALTH));
                }
                else{//L8028D92C
                    func_803463D4(ITEM_14_HEALTH, -sp20);
                }
            }//L8028D948

            if(item_getCount(ITEM_14_HEALTH) == 0){
                sp1C = 2;
            }

            switch(sp1C){
                case 1://L8028D98C
                    sp24 = MAX(MIN(sp24, 0xb), 7);
                    sp24 -= 7;
                    func_8028F428(sp24 +8, arg1);
                    func_80250D94(0.8f, sp24 + 0.2, 0.3f);
                    break;
                case 2://L8028DA10
                    sp24 = MAX(MIN(sp24, 5), 1);
                    sp24--;
                    func_8028F55C(sp24 + 3, arg1);
                    func_80250D94(1.0f, sp24 + 0.3, 0.5f);
                    if(actor->unk16C_2 || actor->unk16C_1){
                        func_8028D71C();
                    }
                    break;
                case 0:
                    break;
            }
        }//L8028DAB0
    }//L8028DAB0
}
