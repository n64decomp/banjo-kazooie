#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "core2/ba/physics.h"
#include "version.h"
#include "prop.h"

#include "core2/dustemitter.h"

extern void func_803012F8(void);
extern void __baMarker_8028BA00(s32);
extern void spawnQueue_actor_s16(void);
extern void func_802A6388(f32);
extern f32 chwadingboots_802D6E4C(Actor *);
extern void set_turbo_duration(f32);
extern f32 chtrainers_getDuration(Actor *);
extern void func_802EE354(Actor *, s32, s32, s32, f32, f32, f32, f32 arg8[3], s32, f32 arg10[2]);
extern void progressDialog_showDialogMaskZero(s32);
extern void progressDialog_showDialogMaskFour(s32 arg0);
extern void func_80291634(ActorMarker *, ActorMarker *);
extern void func_80291610(ActorMarker *, ActorMarker *);
extern Actor *baModel_80291AAC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
extern void baMarker_8028D7B8(s32 arg0, ActorMarker *arg1, CollisionParams *collision_flags);
extern void func_80320ED8(ActorMarker *, f32, s32);
extern NodeProp *cubeList_findNodePropByActorIdAndPosition_s32(enum actor_e actor_id, s32 position[3]);

typedef struct 
{
    f32 unk0;
    f32 unk1;
    f32 unk2;
}
tmp_struct_type;

void baMarker_8028D638(s32 arg0, s32 arg1);

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
s32 baMarkerCarriedObjActorId;
s32 D_8037BF7C;
s32 D_8037BF80[2];
s32 D_8037BF88;
ActorMarker *D_8037BF8C;
u8 D_8037BF90;

/* .code */
s32 *__baMarker_8028B750(void){
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

void __baMarker_8028B7F4(void){
    yaw_setIdeal(func_8029B41C());
    yaw_setUpdateState(1);
    func_8029957C(3);
    baphysics_set_type(BA_PHYSICS_NORMAL);
    baphysics_set_target_horizontal_velocity(0.0f);
    func_8029151C(0xC);
}

void __baMarker_8028B848(void){
    s32 s0 = 0;
    if(gsworld_get_map() == MAP_69_GL_MM_LOBBY){
        s0 = ASSET_E57_DIALOG_FIRST_JIGGY;
    }
    else if(gsworld_get_map() == MAP_2_MM_MUMBOS_MOUNTAIN){
        s0 = ASSET_B45_DIALOG_JIGGY_COLLECT_10;
    }

    if(s0){
        if(player_getTransformation() ==  TRANSFORM_1_BANJO){
            __baMarker_8028B7F4();
        }
        gcdialog_showDialog(s0, 0x2A, NULL, NULL, NULL, 0);
    }
}

void __baMarker_8028B8DC(void){
    func_8028F918(1);
    D_8037BF88 = 1;
}

void __baMarker_8028B904(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    f32 sp1C[3];

    sp1C[0] = reinterpret_cast(s16, arg0);
    sp1C[1] = reinterpret_cast(s16, arg1);
    sp1C[2] = reinterpret_cast(s16, arg2);

    func_80296CC0(&sp1C);
    func_80296CB4(arg3);
    if(baflag_isTrue(BA_FLAG_7_TOUCHING_JIGGY)){
        func_8029CDA0();
    }
    else{
        if(bs_checkInterrupt(BS_INTR_9) == 1){
            func_8029CDA0();
        }

    }
}


void __baMarker_8028B9A8(s32 arg0){
    NodeProp *tmp_v0;
    s32 ideal_yaw[3];

    tmp_v0 = cubeList_findNodePropByActorIdAndPosition_s32(0x1F6, NULL);
    nodeprop_getPosition_s32(tmp_v0, &ideal_yaw);
    func_802CA1CC(arg0);
    actor_spawnWithYaw_s32(ACTOR_47_EMPTY_HONEYCOMB, &ideal_yaw, 0);
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
    
}

void __baMarker_8028BA00(s32 arg0){
    __spawnQueue_add_1((GenFunction_1)__baMarker_8028B9A8, reinterpret_cast(s32, arg0));
}


void __baMarker_resolveMusicNoteCollision(Prop *arg0) {
    if (!func_802FADD4(ITEM_1B_VILE_VILE_SCORE)) {
        item_inc(ITEM_C_NOTE);
    } else {
        item_adjustByDiffWithoutHud(ITEM_C_NOTE, 1);
    }
    if (item_getCount(ITEM_C_NOTE) < 100) {
        coMusicPlayer_playMusic(COMUSIC_9_NOTE_COLLECTED, 16000);
        timedFunc_set_1(0.75f, progressDialog_showDialogMaskZero, FILEPROG_3_MUSIC_NOTE_TEXT);
    }
    fxSparkle_musicNote(arg0->position);
}

void __baMarker_8028BAB0(enum jiggy_e jiggy_id, s32 arg1, s32 arg2, s32 arg3){
    if(jiggyscore_isCollected(jiggy_id))
        return;

    if(mapSpecificFlags_get(arg1) && mapSpecificFlags_get(arg2)){
        mapSpecificFlags_set(arg3, 1);
    }
    mapSpecificFlags_set(arg1, 1);
    func_8030E6D4(SFX_90_SWITCH_PRESS);
}

// arg1 - if bit 0x400000 is set, it's a volatile flag, else it's a file progress flag (for witch switches)
void __baMarker_8028BB1C(s32 arg0, enum file_progress_e progress_flag, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6){
    u32 sp24;
    if(arg0 != 1)
        return;
    
    if(player_movementGroup() == BSGROUP_1_INTR)
        return;

    // if bit 0x400000 of fileProgressFlag is set, it's a volatile flag, else it's a file progress flag (for witch switches)
    if(progress_flag & 0x400000){
        sp24 = progress_flag + 0xFFC00000; // weird truncing 
        if(!volatileFlag_get(sp24)){
            volatileFlag_set(sp24, 1);
            func_8030E6D4(SFX_90_SWITCH_PRESS);
            volatileFlag_set(VOLATILE_FLAG_BF, 1);
            func_802D6264(1.0f, arg2, arg3, arg4, arg5, arg6);
        }
    }
    else{//L8028BBB8
        if(!fileProgressFlag_get(progress_flag)){
            fileProgressFlag_set(progress_flag, 1);
            func_8030E6D4(SFX_90_SWITCH_PRESS);
            volatileFlag_set(VOLATILE_FLAG_BF, 1);
            func_802D6264(1.0f, arg2, arg3, arg4, arg5, arg6);
        }
    }
}

int __baMarker_8028BC20(ActorMarker *marker){
    return D_8037BF90 == 1 && player_getActiveHitbox(marker) == HITBOX_5_PECK;
}

int __baMarker_8028BC60(void){
    return D_8037BF90 == 1 && player_getActiveHitbox(NULL) == HITBOX_5_PECK;
} 

void __baMarker_resolveCollision(Prop *other_prop){
    enum marker_collision_func_type_e plyr_collision_type;
    enum marker_collision_func_type_e obj_collision_type;
    s32 plyr_hitbox_type;
    int i;
    ActorMarker *marker; //0xbc
    Actor *actor; //0xb8
    f32 spAC[3];
    f32 spA0[3];
    s32 jiggy_id;
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

    if(*((u32*)(((u32)other_prop) + 8)) & 1){
        plyr_collision_type = MARKER_COLLISION_FUNC_0;
        obj_collision_type = MARKER_COLLISION_FUNC_0;
        marker = other_prop->actorProp.marker;
        actor = NULL;
        if(marker->unk3E_0){
            actor = marker_getActor(marker);
            if(actor->despawn_flag)
                return;

            if(actor->is_bundle && func_802C9C14(actor))
                return;
            
        }//L8028BD1C
        plyr_hitbox_type = player_getActiveHitbox(marker);
        if(func_8033D410(playerMarker, marker))
            return;
        
        switch(marker->id){
            case 0x125: //L8028BE88
            case 0x126: //L8028BE88
                obj_collision_type = MARKER_COLLISION_FUNC_1;
                break;

            case MARKER_97_BOGGY_2: //L8028BE94
                plyr_collision_type = MARKER_COLLISION_FUNC_1;
                obj_collision_type = MARKER_COLLISION_FUNC_1;
                break;

            case 0xBA: //L8028BEA8
                if( marker->unk40_31 == 1
                    || marker->unk40_31 == 2
                    || marker->unk40_31 == 3
                    || marker->unk40_31 == 4
                    || marker->unk40_31 == 5
                    || marker->unk40_31 == 6
                ){
                    obj_collision_type = MARKER_COLLISION_FUNC_1;
                }
                break;

            case MARKER_B5_RED_FEATHER_COLLECTIBLE: //L8028BEF4
                if(__baMarker_8028BC20(marker) != HITBOX_0_NONE)
                    return;
                if(chCollectible_collectRedFeather(other_prop)){
                    marker_despawn(marker);
                }
                break;

            case MARKER_1E5_GOLD_FEATHER_COLLECTIBLE: //L8028BF24
                if(__baMarker_8028BC20(marker))
                    return;
                
                if(chCollectible_collectGoldFeather(other_prop)){
                    marker_despawn(marker);
                }
                break;
            
            case 0x9E: //L8028BF54
            case 0xA1: //L8028BF54
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    func_802A02B4(1);
                    obj_collision_type = MARKER_COLLISION_FUNC_2_DIE;
                }
                break;

            case 0x28: //L8028BF74
                if( plyr_hitbox_type == HITBOX_6_WONDERWING){
                    sfxsource_playHighPriority(SFX_20_METAL_CLANK_1);
                }
                else{
                    func_8030E6D4(SFX_65_METALLIC_SCRATCH);
                }

                if(plyr_hitbox_type != HITBOX_6_WONDERWING){
                    plyr_collision_type = MARKER_COLLISION_FUNC_2_DIE;
                }
                break;

            case MARKER_F5_BGS_ELEVATED_WALKWAY_SWITCH: //L8028BFB0
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    __baMarker_8028BAB0(JIGGY_20_BGS_ELEVATED_WALKWAY, BGS_SPECIFIC_FLAG_1, BGS_SPECIFIC_FLAG_WALKWAY_JIGGY_TIMER_RUNNING, BGS_SPECIFIC_FLAG_7);
                break;
                
            case MARKER_FD_BGS_MAZE_SWITCH: //L8028BFD4
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    __baMarker_8028BAB0(JIGGY_25_BGS_MAZE, BGS_SPECIFIC_FLAG_A, BGS_SPECIFIC_FLAG_MAZE_JIGGY_TIMER_RUNNING, BGS_SPECIFIC_FLAG_8);
                break;
                
            case MARKER_EC_GV_SUN_SWITCH: //L8028BFF8
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
                        gcStaticCamera_activate(0x14);
                        timedFunc_set_1(1.5f, __baMarker_8028BA00, 0xB);
                    }
                }
                break;

            case MARKER_15F_RBB_HONEYCOMB_SWITCH: //L8028C070
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                        gcStaticCamera_activate(0x7E);
                        timedFunc_set_1(1.5f, __baMarker_8028BA00, 0xf);
                    }
                }
                break;

            case MARKER_F1_GV_STAR_SWITCH: //L8028C0C8
                if(player_movementGroup() == BSGROUP_1_INTR)
                    return;
                if(!mapSpecificFlags_get(5)){
                    mapSpecificFlags_set(5, 1);
                    func_8030E6D4(SFX_90_SWITCH_PRESS);
                }
                break;
                
            case MARKER_231_WARP_CAULDRON: //L8028C104
            case MARKER_244_DINGPOT: //L8028C104
                {

                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    player_getPosition(spAC);
                    spAC[1] += 40.0f;
                    if(collisionTri_isHitFromAbove_actor(spAC, actor, 0x87) == 0)
                        return;
                    volatileFlag_set(VOLATILE_FLAG_1E, 1);
                    /**
                     * This should use the following fileprog flags:
                     * 
                     * FILEPROG_49_PINK_CAULDRON_1_ACTIVE
                     * FILEPROG_4A_PINK_CAULDRON_2_ACTIVE
                     * FILEPROG_4B_GREEN_CAULDRON_1_ACTIVE
                     * FILEPROG_4C_GREEN_CAULDRON_2_ACTIVE
                     * FILEPROG_4D_RED_CAULDRON_1_ACTIVE
                     * FILEPROG_4E_RED_CAULDRON_2_ACTIVE
                     * FILEPROG_4F_UNUSED_CAULDRON_1_ACTIVE
                     * FILEPROG_50_UNUSED_CAULDRON_2_ACTIVE
                     * FILEPROG_51_YELLOW_CAULDRON_1_ACTIVE
                     * FILEPROG_52_YELLOW_CAULDRON_2_ACTIVE
                     */
                    if(fileProgressFlag_get(((actor->actorTypeSpecificField - 1) ^ 1) + 0x49)){
                        actor->unk10_12 = 2;
                    }
                    else{
                        actor->unk10_12 = 1;
                    }
                }
                break;

            case MARKER_FE_MMM_CLOCK_SWITCH: //L8028C1A4
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
            
            case MARKER_23F_LAIR_FLIGHT_PAD_SWITCH: //L8028C1EC
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;

            case 0x110: //L8028C238
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    if(!mapSpecificFlags_get(0)){
                        mapSpecificFlags_set(0, 1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
                
            case 0x113: //L8028C284
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    if(!mapSpecificFlags_get(1)){
                        mapSpecificFlags_set(1,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;
                
            case 0x115: //L8028C2D0
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER){
                    if(player_movementGroup() == BSGROUP_1_INTR)
                        return;
                    if(!mapSpecificFlags_get(2)){
                        mapSpecificFlags_set(2,1);
                        func_8030E6D4(SFX_90_SWITCH_PRESS);
                    }
                }
                break;

            case 0x241: //L8028C31C
                __baMarker_8028BB1C(plyr_hitbox_type, 0xC6, 0x6E, 0x81, 0x2C, 0xA, 0xC7);
                break;

            case MARKER_23C_GV_SNS_SWITCH: //L8028C350
                __baMarker_8028BB1C(plyr_hitbox_type, 0xA3, 0x92, 0x7F, 0x1A, 0xA, 0xA4);
                break;

            case MARKER_161_GV_WITCH_SWITCH: //L8028C384
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_BE_WITCH_SWITCH_PRESSED_GV, 0x6E, 0x7D, 0x19, 0x14, 0xA0);
                break;

            case MARKER_162_BGS_WITCH_SWITCH: //L8028C3BC
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_BD_WITCH_SWITCH_PRESSED_BGS, 0x71, 0x7C, 0x18, 0x14, 0x9F);
                break;
            case MARKER_166_CC_WITCH_SWITCH: //L8028C3F4
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_BC_WITCH_SWITCH_PRESSED_CC, 0x6A, 0x7A, 0x17, 0x14, 0x9A);
                break;
           
            case MARKER_22B_FP_WITCH_SWITCH: //L8028C42C
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_BB_WITCH_SWITCH_PRESSED_FP, 0x6F, 0x3A, 0x13, 0x15, 0x47);
                break;

            case MARKER_22A_CCW_WITCH_SWITCH: //L8028C464
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_BA_WITCH_SWITCH_PRESSED_CCW, 0x79, 0x39, 0x12, 0x15, 0x46);
                break;

            case MARKER_103_MM_WITCH_SWITCH: //L8028C49C
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_B6_WITCH_SWITCH_PRESSED_MM, 0x69, 0x26, 1, 4, 0x18);
                break;
                
            case MARKER_104_MMM_WITCH_SWITCH: //L8028C4D4
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_B7_WITCH_SWITCH_PRESSED_MMM, 0x6F, 0x27, 2, 0x14, 0x19);
                break;
                
            case MARKER_105_TTC_WITCH_SWITCH: //L8028C50C
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_B8_WITCH_SWITCH_PRESSED_TTC, 0x6D, 0x28, 3, 0x14, 0x1A);
                break;
                
            case MARKER_106_RBB_WITCH_SWITCH: //L8028C544
                __baMarker_8028BB1C(plyr_hitbox_type, 0x400000 | VOLATILE_FLAG_B9_WITCH_SWITCH_PRESSED_RBB, 0x76, 0x29, 4, 0xe, 0x1C);
                break;
                
            case MARKER_11B_WATER_LEVEL_SWITCH_1: //L8028C57C
                __baMarker_8028BB1C(plyr_hitbox_type, 0x22, 0x77, 0x2D, 5, 0xA, 0x23);
                break;
                
            case MARKER_11C_WATER_LEVEL_SWITCH_2: //L8028C5B0
                __baMarker_8028BB1C(plyr_hitbox_type, 0x24, 0x77, 0x2E, 6, 0xA, 0x25);
                break;
                
            case MARKER_11D_WATER_LEVEL_SWITCH_3: //L8028C5E4
                __baMarker_8028BB1C(plyr_hitbox_type, 0x26, 0x76, 0x2F, 0x7, 0xA, 0x27);
                break;

            case 0x232: //L8028C618
                __baMarker_8028BB1C(plyr_hitbox_type, 0x53, 0x6b, 0x3b, 0x14, 0x12, 0x54);
                break;

            case MARKER_F3_GV_KAZOOIE_TARGET: //L8028C64C
                if(plyr_hitbox_type == HITBOX_3_BEAK_BOMB){
                    mapSpecificFlags_set(6,1);
                    obj_collision_type = MARKER_COLLISION_FUNC_1;
                }
                break;


            case MARKER_52_JIGGY: //L8028C66C
                {
                    if(__baMarker_8028BC20(marker))
                        return;
                    
                    player_getPosition(spA0);
                    jiggy_id = chjiggy_getJiggyId(actor);
                    if( jiggy_id != JIGGY_2F_FP_XMAS_TREE
                        || (player_isStable() && !(3600.0f < ml_distanceSquared_vec3f(actor->position, spA0)))
                    ){
                        jiggyscore_setCollected(jiggy_id, TRUE);
                        item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, 1);
                        if(jiggy_id == JIGGY_20_BGS_ELEVATED_WALKWAY || jiggy_id == JIGGY_25_BGS_MAZE){
                            func_802D6924();
                        }
                        if(jiggyscore_total() < 3){
                            __baMarker_8028B848();
                        }

                        if(func_8025AD7C(COMUSIC_30_5TH_JINJO_COLLECTED)){
                            __baMarker_8028B8DC();
                        }

                        __spawnQueue_add_4((GenFunction_4)__baMarker_8028B904,
                            reinterpret_cast(u32, other_prop->actorProp.position_x),
                            reinterpret_cast(u32, other_prop->actorProp.position_y),
                            reinterpret_cast(u32, other_prop->actorProp.position_z), jiggy_id);
                        marker_despawn(marker);
                    }
                }
                break;

            case MARKER_53_EMPTY_HONEYCOMB: //L8028C774
                {
                    
                    if(__baMarker_8028BC20(marker))
                        return;
                    sp98 = func_802CA1C4(marker_getActor(marker));
                    if(sp98 != HONEYCOMB_12_MMM_FLOORBOARD || player_getTransformation() == TRANSFORM_3_PUMPKIN)
                    {
                        honeycombscore_set(sp98, 1);
                        coMusicPlayer_playMusic(COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED, 28000);
                        timedFunc_set_1(2.0f, progressDialog_showDialogMaskZero, FILEPROG_B_EMPTY_HONEYCOMB_TEXT);
                        item_inc(ITEM_13_EMPTY_HONEYCOMB);
                        if(!(item_getCount(ITEM_13_EMPTY_HONEYCOMB) < 6)){
                            gcpausemenu_80314AC8(0);
                        }
                        fxSparkle_emptyHoneycomb(&other_prop->actorProp.position_x);
                        marker_despawn(marker);
                    }
                }
                break;

            case 0x54: //L8028C820
                coMusicPlayer_playMusic(COMUSIC_19_LOW_PITCH_FLUTES, 28000);
                func_803012F8();
                __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_s16, 0x4E,
                    reinterpret_cast(u32, other_prop->actorProp.position_x),
                    reinterpret_cast(u32, other_prop->actorProp.position_y),
                    reinterpret_cast(u32, other_prop->actorProp.position_z));
                marker_despawn(marker);
                break;

            case MARKER_55_HONEYCOMB: //L8028C86C
                if(__baMarker_8028BC20(marker))
                    return;
                
                if( gsworld_get_map() == MAP_8E_GL_FURNACE_FUN
                    && volatileFlag_get(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ)
                    && !fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)
                ){
                    progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A6_FF_FOUND_HONEYCOMB);
                    func_8030E6D4(SFX_126_AUDIENCE_BOOING);
                }  

                coMusicPlayer_playMusic(COMUSIC_16_HONEYCOMB_COLLECTED, 28000);
                timedFunc_set_1(0.75f, progressDialog_showDialogMaskZero, FILEPROG_A_HONEYCOMB_TEXT);
                item_inc(ITEM_14_HEALTH);
                fxSparkle_honeycomb(&other_prop->actorProp.position_x);
                marker_despawn(marker);
                break;

            case MARKER_169_SNS_EGG: //L8028C908
                { //ONLY THIS CASE DOESN'T MATCH
                    switch (gsworld_get_map())
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
                    comusic_playTrack(COMUSIC_88_BIG_SNS_FANFARE);
                    FUNC_8030E624(SFX_114_BRICKWALL_BREAKING, 0.8f, 15000);
                    tmp_v0_2 = 3*(actor->actorTypeSpecificField - 1);
                    
                    tmp_f0 = 0.9f;\
                    sp64 = D_80363660;
                    //+C
                    sp78 = 0xA;
                    sp94 = 0xAA;

                    for(sp7C = 0; sp7C < 4; sp7C++){ //L8028CA4C
                        
                        for(i = 0 ; i < 3; i++){
                            sp88[i] = D_8036366C[tmp_v0_2 + i];
                        }
                        func_802EE354(actor, 0x3ED, 0x23, sp78, 0.2f, tmp_f0, 3.0f, (f32*)sp88, 0, (f32*)&sp64);
                        
                        for(i = 0 ; i < 3; i++){
                            sp88[i] = 0xFF;
                        }
                        func_802EE354(actor, 0x3ED, 0xe, sp78, 0.2f, tmp_f0, 3.0f, (f32*)sp88, 0, (f32*)&sp64);
                        
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
                        func_80324DBC(2.5f, ASSET_DB3_DIALOG_SNS_EGG_1_TEXT + tmp1 - 1, 0x20, 0, 0, 0, 0);
                    }
                    
                    marker_despawn(marker);
                }
                break;
            case MARKER_168_ICE_KEY: //L8028CC7C
                sns_set_item_and_update_payload(SNS_ITEM_ICE_KEY, 0, 1);
                comusic_playTrack(COMUSIC_88_BIG_SNS_FANFARE);
                func_80324DBC(2.5f, ASSET_DB5_DIALOG_ICE_KEY_TEXT, 0x20, 0, 0, 0, 0);
                marker_despawn(marker);
                break;
            
            case MARKER_5F_MUSIC_NOTE: //L8028CCC8
                if(__baMarker_8028BC20(marker))
                    return;

                __baMarker_resolveMusicNoteCollision(other_prop);
                marker_despawn(marker);
                break;

            case MARKER_60_BLUE_EGG_COLLECTIBLE: //L8028CCF0
                if(__baMarker_8028BC20(marker))
                    return;
                if(chCollectible_collectEgg(other_prop)){
                    marker_despawn(marker);
                }
                break;

            case MARKER_6B_GLOOPBUBBLE: //L8028CD20
                if(player_getWaterState() == BSWATERGROUP_2_UNDERWATER){
                    item_adjustByDiffWithHud(ITEM_17_AIR, fxairscore_count_to_time(2));
                }
                break;

            case MARKER_61_EXTRA_LIFE: //L8028CD50
                if(__baMarker_8028BC20(marker))
                    return;
                if( gsworld_get_map() == MAP_8E_GL_FURNACE_FUN
                    && volatileFlag_get(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ)
                    && !fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)
                ){
                    progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A7_FF_FOUND_EXTRALIFE);
                    func_8030E6D4(SFX_127_AUDIENCE_MIXED);
                }
                coMusicPlayer_playMusic(COMUSIC_15_EXTRA_LIFE_COLLECTED, 0x7FFF);
                timedFunc_set_1(1.5f, progressDialog_showDialogMaskFour, FILEPROG_C_EXTRA_LIFE_TEXT);
                fxSparkle_extraLife(&other_prop->actorProp.position_x);
                item_inc(ITEM_16_LIFE);
                marker_despawn(marker);
                break;
            


            case MARKER_D4_SPRING_PAD: //L8028CDEC
            case 0x242: //L8028CDEC
                if(ability_isUnlocked(ABILITY_D_SHOCK_JUMP)){
                    baflag_set(BA_FLAG_2_ON_SPRING_PAD);
                }else{
                    if(!volatileFlag_getAndSet(VOLATILE_FLAG_C_HAS_SEEN_SPRING_PAD, 1)){
                        gcdialog_showDialog(ASSET_A24_DIALOG_JUMP_PAD_DISCOVERED, 4, 0, 0, 0, 0);
                    }
                }
                break;

            case MARKER_45_FLIGHT_PAD: //L8028CE3C
            case MARKER_240_LAIR_SWITCH_FLIGHT_PAD: //L8028CE3C
            case MARKER_261_FIGHT_FLIGHT_PAD: //L8028CE3C
                if(ability_isUnlocked(ABILITY_9_FLIGHT)){
                    baflag_set(BA_FLAG_1_ON_FLIGHT_PAD);
                }
                else if(! volatileFlag_getAndSet(VOLATILE_FLAG_D_HAS_SEEN_FLIGHT_PAD, 1)){
                    gcdialog_showDialog(ASSET_A25_DIALOG_FLY_DISC_DISCOVERED, 4, 0, 0, 0, 0);
                }
                break;

            case MARKER_11_WADING_BOOTS: //L8028CE8C
                if(__baMarker_8028BC20(marker))
                    return;
                if(bsStoredState_getTransformation() != TRANSFORM_1_BANJO)
                    return;
                if(func_8028F170())
                    return;
                if(func_8028F25C())
                    return;
                if(chwadingboots_802D6E0C(actor) == 0)
                    return;
                
                baflag_set(BA_FLAG_E_TOUCHING_WADING_BOOTS);
                func_802A6388(chwadingboots_802D6E4C(actor));
                bs_checkInterrupt(BS_INTR_1B);
                __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_s16, 0x4E,
                    reinterpret_cast(u32, other_prop->actorProp.position_x),
                    reinterpret_cast(u32, other_prop->actorProp.position_y),
                    reinterpret_cast(u32, other_prop->actorProp.position_z));
                chwadingboots_802D6E54(actor);
                break;

            case MARKER_38_TURBO_TALON_TRAINERS: //L8028CF38
                if(__baMarker_8028BC20(marker))
                    return;

                tmp1 = bsStoredState_getTransformation();
                if(tmp1 != TRANSFORM_1_BANJO && tmp1 != TRANSFORM_5_CROC)
                    return;
                
                if(func_8028F25C())
                    return;

                if(func_8028F170())
                    return;
                
                if(!chtrainers_canUse(actor))
                    return;

                baflag_set(BA_FLAG_10_TOUCHING_TURBO_TRAINERS);
                set_turbo_duration(chtrainers_getDuration(actor));
                bs_checkInterrupt(BS_INTR_1A);
                __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_s16, 0x4E,
                    reinterpret_cast(u32, other_prop->actorProp.position_x),
                    reinterpret_cast(u32, other_prop->actorProp.position_y),
                    reinterpret_cast(u32, other_prop->actorProp.position_z));
                chtrainers_pickup(actor);
                break;

            case MARKER_1AE_ZUBBA: //L8028CFEC
                switch(plyr_hitbox_type){
                    case HITBOX_1_BEAK_BUSTER:
                    case HITBOX_2_BEAK_BARGE:
                    case HITBOX_5_PECK:
                    case HITBOX_6_WONDERWING:
                        obj_collision_type = MARKER_COLLISION_FUNC_2_DIE;
                        break;
                    default:
                        plyr_collision_type = MARKER_COLLISION_FUNC_2_DIE;
                        break;
                }
                break;

            case MARKER_1B1_CCW_GOBI: //L8028D024
                if(plyr_hitbox_type == HITBOX_1_BEAK_BUSTER)
                    obj_collision_type = MARKER_COLLISION_FUNC_1;
                break;
        }//L8028D034
        if(baiFrame_getState() == 3){
            plyr_collision_type = MARKER_COLLISION_FUNC_0;
        }
        if(obj_collision_type){
            baflag_set(BA_FLAG_8);
        }
        marker_callCollisionFunc(playerMarker, marker, plyr_collision_type);
        marker_callCollisionFunc(marker, playerMarker, obj_collision_type);
        if(marker->unk3E_0){
            func_8032B258(actor, obj_collision_type);
        }
    }
    else if(other_prop->isModelProp)//L8028D0B0 //ModelProp
    {
        tmp2 = other_prop->modelProp.modelId + MODEL_ASSET_OFFSET;
        switch (tmp2)
        {
        case 0x2E8:
            baflag_set(BA_FLAG_1_ON_FLIGHT_PAD); //on flight pad
            break;
        case 0x2DD: //on shock spring pad
            baflag_set(BA_FLAG_2_ON_SPRING_PAD);
            break;
        default:
            func_80332790(tmp2);
            break;
        }
    }
    else{//L8028D10C //SpriteProp
        tmp3 = other_prop->spriteProp.spriteId + SPRITE_ASSET_OFFSET;
        switch (tmp3)
        {
        case ASSET_6D6_SPRITE_MUSIC_NOTE: //L8028D144
            if(!__baMarker_8028BC60()){
                other_prop->spriteProp.isNotFeatherEggOrNote = 0;
                __baMarker_resolveMusicNoteCollision(other_prop);
            }
            break;
        case ASSET_6D7_SPRITE_BLUE_EGGS: //L8028D16C
            if(!__baMarker_8028BC60()){
                other_prop->spriteProp.isNotFeatherEggOrNote = 0;
                chCollectible_collectEgg(other_prop);
            }
            break;
        case ASSET_580_SPRITE_RED_FEATHER: //L8028D194
            if(!__baMarker_8028BC60()){
                other_prop->spriteProp.isNotFeatherEggOrNote = 0;
                chCollectible_collectRedFeather(other_prop);
            }
            break;
        case ASSET_6D1_SPRITE_GOLDFEATHER: //L8028D1BC
            if(!__baMarker_8028BC60()){
                other_prop->spriteProp.isNotFeatherEggOrNote = 0;
                chCollectible_collectGoldFeather(other_prop);
            }
            break;
        default:
            func_80332790(tmp3);
            break;
        }
    }
}

void baMarker_init(void){
    f32 sp1C[3];
    playerPosition_get(sp1C);
    playerMarker = func_8032FBE4(sp1C, baModel_80291AAC, 1, 0);
    playerMarker->unk2C_1 = 1;
    marker_setCollisionScripts(playerMarker, NULL, func_80291634, func_80291610);
    func_803300B8(playerMarker, baMarker_8028D7B8);
    baflag_clear(BA_FLAG_1_ON_FLIGHT_PAD);
    baflag_clear(BA_FLAG_2_ON_SPRING_PAD);
    baflag_clear(BA_FLAG_8);
    baMarker_8028D638(0,0);
    func_8033D2F4();
    D_8037BF8C = 0;
    D_8037BF90 = 0xff;
    
}

void baMarker_free(void){
    marker_free(playerMarker);
    playerMarker = NULL;
}


void baMarker_update(void){
    f32 sp174[3];
    f32 sp168[3];
    s32 temp_s0;
    int i, j;
    Prop *sp58[65];
    s32 *temp_s0_2;
    s32 temp_s2;
    Prop *other_prop;

    if ((D_8037BF88 != 0)){
        temp_s0 = func_8024FEEC(func_8025ADD4(COMUSIC_30_5TH_JINJO_COLLECTED) & 0xFF);
        if((coMusicPlayer_getTrackCount() < 4 && temp_s0 >= 0xBB9) || !func_8025AD7C(COMUSIC_30_5TH_JINJO_COLLECTED)){
            func_8028F918(0);
            D_8037BF88 = 0;
        }
    }//L8028D364
    baflag_clear(BA_FLAG_8);
    if(playerMarker->collidable){
        temp_s0_2 = __baMarker_8028B750();
        baflag_clear(BA_FLAG_1_ON_FLIGHT_PAD);
        baflag_clear(BA_FLAG_2_ON_SPRING_PAD);
        playerPosition_get(sp168);
        func_8032F64C(sp168, playerMarker);
        for(D_8037BF8C = NULL, i = 0, temp_s2 = 0; i < 2;i++){//L8028D3DC
            D_8037BF90 = i;
            baModel_80292284(sp174, i); //get top of player?
            playerMarker->unk38[0] = sp174[0] - sp168[0];
            playerMarker->unk38[1] = sp174[1] - sp168[1];
            playerMarker->unk38[2] = sp174[2] - sp168[2];
            func_80320ED8(playerMarker, temp_s0_2[i], 1);
            while(other_prop = func_8032F528()){//L8028D480
                if(!other_prop->isCollisionResolved){
                    if(!D_8037BF8C && other_prop->isActorProp && other_prop->isModelProp){
                        D_8037BF8C = other_prop->actorProp.marker;
                    }
                    __baMarker_resolveCollision(other_prop);
                    other_prop->isCollisionResolved = 1;
                    sp58[temp_s2] = other_prop;
                    temp_s2++;
                }//L8028D4E0 
            }//L8028D4F0
        }
        D_8037BF90 = 0xff;

        for(j = 0; j < temp_s2; j++){//L8028D55C
            sp58[j]->isCollisionResolved = 0;
        }
    }
}

ActorMarker *baMarker_get(void){ //baMarker_get
    return playerMarker;
}

void baMarker_collisionOff(void){ //player_collisionOff
    playerMarker->collidable = FALSE;
}

void baMarker_collisionOn(void){ //player_collisionOn
    playerMarker->collidable = TRUE;
}

bool baMarker_isCollidable(void){ //player_isCollidable
    return BOOL(playerMarker->collidable);
}

void baMarker_8028D638(s32 arg0, s32 arg1){
    D_8037BF80[0] = arg0;
    D_8037BF80[1] = arg1;
}

void baMarker_8028D64C(s32 arg0){
    D_8037BF74 = arg0;
}

void baMarker_setCarriedObject(enum actor_e actor_id){
    baMarkerCarriedObjActorId = actor_id;
}

s32 baMarker_8028D664(void){
    return D_8037BF74;
}

enum actor_e baMarker_getCarriedObjectActorId(void){
    return baMarkerCarriedObjActorId;
}

void baMarker_8028D67C(s32 arg0){
    D_8037BF7C = arg0;
}

s32 baMarker_8028D688(void){
    return D_8037BF7C;
}

s32 baMarker_8028D694(void) {
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


s32 baMarker_8028D6F0(s32 **arg0){
    *arg0 = __baMarker_8028B750();
    return 2;
}

void baMarker_8028D71C(void){
    f32 sp3C[3];
    f32 sp30[3];
    
    func_8028E9C4(5, sp30);
    player_getPosition(sp3C);
    sp3C[1] += (sp30[1] - sp3C[1])*0.75;
    dustEmitter_emit(sp3C, 0, D_80363680, 1, 0.75f, 0.0f, 0x7d, 0xfa, DUST_EMITTER_TYPE_DUST);
}

void baMarker_8028D7B8(s32 arg0, ActorMarker *arg1, CollisionParams *collision_flags){
    s32 sp24;
    s32 sp20 = collision_getDamageToPlayer(collision_flags);
    s32 sp1C = 0;
    Actor *actor = marker_getActor(arg1);
    s32 tmp_v0;

    if(collision_getHitsToTrigger(collision_flags))
        baflag_set(BA_FLAG_8);

    if((baiFrame_getState() != 3 && func_8028F1E0()) || !sp20){
        if(!func_8028F25C()){
            sp24 = collision_getPlayerInteraction(collision_flags);
            if(0 < sp24 && sp24 < 6){
                sp1C = 2;
                sp20 = MAX(0, sp20 - 1);
            }//L8028D884

            if(6 < sp24 && sp24 < 0xC){
                if(!(1 < collision_getHitsToTrigger(collision_flags)) || (collision_getNextState(collision_flags) != -1 && actor->unk164[collision_getNextState(collision_flags)])){
                    sp1C = 1;
                }//L8028D8E8
            }//L8028D8E8

            if(sp20){
                if(collision_getDamageToPlayer(collision_flags) == 3){
                    item_adjustByDiffWithHud(ITEM_14_HEALTH, -item_getCount(ITEM_14_HEALTH));
                }
                else{//L8028D92C
                    item_adjustByDiffWithHud(ITEM_14_HEALTH, -sp20);
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
                    baMotor_80250D94(0.8f, sp24 + 0.2, 0.3f);
                    break;
                case 2://L8028DA10
                    sp24 = MAX(MIN(sp24, 5), 1);
                    sp24--;
                    func_8028F55C(sp24 + 3, arg1);
                    baMotor_80250D94(1.0f, sp24 + 0.3, 0.5f);
                    if(actor->unk16C_2 || actor->unk16C_1){
                        baMarker_8028D71C();
                    }
                    break;
                case 0:
                    break;
            }
        }//L8028DAB0
    }//L8028DAB0
}
