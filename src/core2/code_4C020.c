#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "SnS.h"

extern f32 func_80258640(f32 [3], f32[3]);
extern void func_8025A788(enum comusic_e, f32, f32);
extern void func_8031CC40(enum map_e, s32);
extern void fxRipple_802F363C(f32);
extern void func_802F9D38(s32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void ml_vec3f_assign(f32[3], f32, f32, f32);
extern void func_802EE2E8(Actor *arg0, s32 arg1, s32 cnt, s32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern void func_80319EA4(void);
extern void fileProgressFlag_set(s32, bool);

void func_802D3D54(Actor *this);
void func_802D3DA4(Actor *this);
Actor *func_802D3F48(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D3FD4(Actor *this);
Actor *func_802D41C4(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4250(Actor *this);
void func_802D4388(Actor *this);
Actor *func_802D4588(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void func_802D4680(Actor *this);
void func_802D4B94(Actor *this);
void func_802D4BBC(Actor *this);
void func_802D4BE4(Actor *this);
void func_802D4C0C(Actor *this);
void func_802D4C34(Actor *this);
void func_802D4C5C(Actor *this);
void func_802D4C84(Actor *this);
void func_802D4CAC(Actor *this);
void func_802D4CD4(Actor *this);
void func_802D68F0(s32 seconds);

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
}Struct_core2_4C020_0;

/* .data */
f32 D_80367680 = 130.0f;
s32 D_80367684 = 0; //enum map_e
s32 D_80367688 = 0;
s32 D_8036768C = 0;
s32 D_80367690 = 0;
s32 D_80367694 = 0; //enum map_e
s32 D_80367698 = 0;
s32 D_8036769C = 0; //enum file_progress_e
s32 D_803676A0 = 0; //enum actor_e
f32 D_803676A4 = 0.0f;
s32 D_803676A8 = 0;
u8  D_803676AC = 0;

ActorAnimationInfo D_803676B0[] = {
    {0x000, 0.0f},
    {0x000, 0.0f},
    {0x0D4, 0.15f},
    {0x0D5, 0.5f},
    {0x000, 0.0f},
    {0x000, 0.0f},
    {0x0D4, 0.15f},
    {0x0D5, 0.5f},
    {0x0D5, 1e+8f},
    {0x1E3, 0.73f},
    {0x1E3, 1e+8f},
    {0x1F0, 1.0f},
    {0x1F1, 0.7f},
    {0x1F1, 1e+8f},
    {0x1F2, 1.0f},
    {0x1F3, 0.4f},
    {0x1F3, 1e+8f},
    {0x000, 0.0f},
    {0x217, 1e+8f},
    {0x217, 0.3f},
    {0x217, 1e+8f},
    {0x217, 0.3f}
};

ActorInfo D_80367760 = { 0x26E, 0x2D9, 0x3B4,  0x1, NULL,       func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80367784 = { 0x26F, 0x2DA, 0x3B5,  0x1, NULL,       func_802D3D54, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_803677A8 = { MARKER_168_ICE_KEY, ACTOR_25D_ICE_KEY, ASSET_50C_MODEL_ICE_KEY,  0x1, NULL,       func_802D4250, func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_803677CC = { 0x233, 0x23D, 0x4DD, 0x12, D_803676B0, func_802D4388, func_80326224, func_802D4588, 0, 0, 0.0f, 0};
ActorInfo D_803677F0 = { 0x16A, 0x242,   0x0,  0x0, NULL,       func_802D4680,          NULL, func_80325340, 0, 0, 0.0f, 0};
ActorInfo D_80367814 = { MARKER_169_SNS_EGG, ACTOR_25E_SNS_EGG, ASSET_50D_MODEL_SNS_EGG,  0x1, NULL,       func_802D3FD4,          NULL, func_802D41C4, 0, 0, 0.0f, 0};
ActorInfo D_80367838 = { 0x265, 0x2E4, 0x55A,  0x1, NULL,       func_802D3DA4,          NULL, func_802D3F48, 0, 0, 0.0f, 0};
ActorInfo D_8036785C = { MARKER_103_MM_WITCH_SWITCH, ACTOR_204_MM_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4B94, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_80367880 = { MARKER_104_MMM_WITCH_SWITCH, ACTOR_206_MMM_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C34, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_803678A4 = { MARKER_105_TTC_WITCH_SWITCH, ACTOR_208_TTC_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C5C, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_803678C8 = { MARKER_106_RBB_WITCH_SWITCH, ACTOR_20B_RBB_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C84, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_803678EC = { MARKER_22A_CCW_WITCH_SWITCH, ACTOR_237_CCW_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4CAC, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_80367910 = { MARKER_22B_FP_WITCH_SWITCH, ACTOR_239_FP_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4CD4, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_80367934 = { MARKER_166_CC_WITCH_SWITCH, ACTOR_25B_CC_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4BBC, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_80367958 = { MARKER_162_BGS_WITCH_SWITCH, ACTOR_257_BGS_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4BE4, func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_8036797C = { MARKER_161_GV_WITCH_SWITCH, ACTOR_256_GV_WITCH_SWITCH, ASSET_4DC_MODEL_WITCH_SWITCH,  0x1, D_803676B0, func_802D4C0C, func_80326224, actor_draw, 0, 0, 0.0f, 0};

s32 D_803679A0[4] = {0x87, 0x87, 0x87, 0xA0};
s16 D_803679B0[] = {0x5, 0x90, 0xA, 0x93, 0xF,0x92, 0x14, 0x91, 0x19, 0x94, -1};
Struct_core2_4C020_0 D_803679C8[] = {
    {0, 600, 1200, 1900}, 
    {-580, 0, 1550, 2200}, 
    {150, 460, 1625, 2100},
};
s16 D_803679E0[] = {-50, -100, 200};

/* .bss */
int D_8037DE00;
f32 D_8037DE04;
f32 D_8037DE08;

/* .public */
void func_802D6114(void);
void func_802D6264(f32 arg0, enum map_e arg1, s32 arg2, s32 arg3, s32 arg4, enum file_progress_e arg5);
void func_802D6344(void);
void func_802D63D4(void);
void func_802D6750(void);

/* .code */
void func_802D2FB0(Actor *this, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    f32 spA4[3];
    f32 sp98[3];
    s32 i;

    sp98[0] = this->position[0];
    sp98[2] = this->position[2];
    for(i = 0; i < arg1; i++){
        sp98[1] = this->position[1] + randf2((f32) arg2, (f32) arg3);
        spA4[1] = randf2(4.0f, 10.0f);
        spA4[0] = randf2(-8.0f, 8.0f);
        spA4[2] = randf2(-8.0f, 8.0f);
        func_802EE6CC(sp98, spA4, D_803679A0, 1, arg4, 50.0f, arg5, randi2(arg6, arg7), 0);
    }
}

// collision function if player shoots egg at spider webs
void func_802D3138(ActorMarker *marker, ActorMarker *other_marker) {
    if(marker->id == MARKER_224_BREAKABLE_FLOOR_COBWEB || marker->id == MARKER_225_BREAKABLE_WALL_COBWEB) {
        comusic_playTrack(COMUSIC_2B_DING_B);
    }
}

// called from collision die function below, set according file flag and despawns object
void func_802D317C(ActorMarker *marker, enum file_progress_e prog_flag_id) {
    fileProgressFlag_set(prog_flag_id, TRUE);
    marker_despawn(marker);
}

// collision die function for several objects in Lair
void func_802D31AC(ActorMarker *arg0, ActorMarker * arg1) {
    Actor *sp2C;

    sp2C = marker_getActor(arg0);
    arg0->collidable = FALSE;
    switch (arg0->id) {
        case 0x9F:
        case 0xA0:
        case 0xFF:
            func_8030E540(SFX_82_METAL_BREAK);
            subaddie_set_state(sp2C, 4);
            break;

        case 0x17D:
            FUNC_8030E624(SFX_82_METAL_BREAK, 0.7f, 32736);
            FUNC_8030E624(SFX_82_METAL_BREAK, 0.6f, 32736);
            func_802D2FB0(sp2C, 0x14, -0x1E, 0x190, 3.0f, 0x15E, 0x50, 0x96);
            sp2C->lifetime_value = 1.0f;
            fileProgressFlag_set(FILEPROG_A5_LAIR_CRYPT_GATE_OPEN, 1);
            break;

        case MARKER_109_BREAKABLE_BRICK_WALL:
            func_8030E6D4(SFX_114_BRICKWALL_BREAKING);
            sfxsource_play(SFX_11_WOOD_BREAKING_1, 28000);
            subaddie_set_state_looped(sp2C, 9);
            fileProgressFlag_set((sp2C->unkF4_8 == 1) ? FILEPROG_C8_LAIR_BRICKWALL_TO_WADINGBOOTS_BROKEN : FILEPROG_C9_LAIR_BRICKWALL_TO_SHOCKJUMP_PAD_BROKEN, TRUE);
            break;

        case 0x107:
            func_8030E540(SFX_82_METAL_BREAK);
            func_802EE278(sp2C, 0xE, 0xF, 0x46, 0.8f, 0.7f);
            marker_despawn(arg0);
            break;

        case MARKER_224_BREAKABLE_FLOOR_COBWEB:
            comusic_playTrack(COMUSIC_2B_DING_B);
            func_8030E6A4(SFX_129_SWOOSH, (sp2C->scale < 0.45) ? 1.0 : 0.8, 0x7FF8);
            subaddie_set_state_looped(sp2C, 0xC);
            func_802D2FB0(sp2C, 8, -0x3C, 0xC8, 2.0f, 0xFA, 0x3C, 0x64);
            fileProgressFlag_set((sp2C->unkF4_8== 1) ? FILEPROG_CB_LAIR_COBWEB_OVER_FLIGHTPAD_BROKEN : FILEPROG_CC_LAIR_COBWEB_OVER_GREEN_CAULDRON_BROKEN, 1);
            break;

        case MARKER_225_BREAKABLE_WALL_COBWEB:
            comusic_playTrack(COMUSIC_2B_DING_B);
            func_8030E540(SFX_129_SWOOSH);
            subaddie_set_state_looped(sp2C, 0xF);
            func_802D2FB0(sp2C, 0xE, -0x3C, 0xC8, 2.0f, 0xFA, 0x3C, 0x64);
            fileProgressFlag_set(FILEPROG_CA_COBWEB_BLOCKING_PURPLE_CAULDRON_BROKEN, 1);
            break;

        case 0x163:
            if (sp2C->unk10_12 == 0) {
                sp2C->unk10_12 = TRUE;
                timed_playSfx(0.5f, SFX_3F9_UNKNOWN, 1.0f, 32000);
                FUNC_8030E624(SFX_114_BRICKWALL_BREAKING, 0.8f, 32000);
            }
            break;

        case 0x9A: 
        case 0x9C: 
        case 0x9D: 
        case 0x9E: 
        case 0xA1: 
        case 0xE7: 
        case 0xEA: 
        case 0x108:
        case 0x263:
            if ((arg0->id == 0x9D) || (arg0->id == 0xE7)) {
                levelSpecificFlags_set(0x2E, 1);
            }
            if (arg0->id == 0x263) {
                levelSpecificFlags_set(0x38, 1);
            }
            func_802D2FB0(sp2C, 5, -0x28, 0xC8, 0.85f, 0xDC, 0x3C, 0x64);
            func_8030E540(SFX_D_EGGSHELL_BREAKING);
            func_8030E540(SFX_11_WOOD_BREAKING_1);
            switch (arg0->id) {
                case 0x9E:
                    func_802EE278(sp2C, 0xD, 9, 0x82, 0.34f, 1.0f);
                    break;

                case 0x9D:
                case 0xE7:
                case 0x108:
                    func_802EE278(sp2C, 7, 6, 0x32, 0.4f, 1.1f);
                    func_802EE278(sp2C, 7, 6, 0xB4, 0.4f, 1.1f);
                    break;

                case 0x9A:
                case 0x9C:
                case 0x263:
                    func_802EE278(sp2C, 7, 0xA, 0x82, 0.3f, 0.8f);
                    break;

                case 0xA1:
                    func_802EE278(sp2C, 7, 9, 0x82, 0.3f, 0.6f);
                    break;

                case 0xEA:
                    func_802EE278(sp2C, 3, 9, 0x82, 0.21f, 0.8f);
                    break;

                default:
                    func_802EE278(sp2C, 7, 0x19, 0x82, 0.17f, 0.8f);
                    break;
            }
            marker_despawn(arg0);
            break;

        case 0x11F:
            func_8030E540(SFX_D9_WOODEN_CRATE_BREAKING_1);
            func_802EE2E8(sp2C, 7, 9, 0x78, 0.43f, 1.3f, 3.0f);
            func_802EE2E8(sp2C, 3, 6, 0x78, 0.43f, 1.3f, 3.0f);
            func_802D317C(arg0, FILEPROG_C5_RAREWARE_BOX_BROKEN);
            break;

        case 0x11A:
            func_8030E540(SFX_82_METAL_BREAK);
            func_802EE278(sp2C, 0xE, 0xD, 0x32, 0.8f, 0.9f);
            func_802EE278(sp2C, 0xE, 0xD, 0xAA, 0.8f, 0.9f);
            func_802D317C(arg0, FILEPROG_C2_GRATE_TO_RBB_PUZZLE_OPEN);
            break;

        case 0x118:
            func_8030E540(SFX_82_METAL_BREAK);
            func_802EE278(sp2C, 0xE, 0xD, 0x50, 1.2f, 0.9f);
            func_802EE278(sp2C, 0xE, 0xD, 0xB4, 1.2f, 0.9f);
            func_802D317C(arg0, FILEPROG_CD_GRATE_TO_WATER_SWITCH_3_OPEN);
            break;

        case 0x119:
            func_8030E540(SFX_82_METAL_BREAK);
            func_802EE278(sp2C, 0xE, 9, 0x50,  1.2f, 0.9f);
            func_802EE278(sp2C, 0xE, 9, 0xAA,  1.2f, 0.9f);
            func_802EE278(sp2C, 0xE, 9, 0x104, 1.2f, 0.9f);
            func_802D317C(arg0, FILEPROG_CE_GRATE_TO_MMM_PUZZLE_OPEN);
            break;

        case 0x22D:
        case 0x22E:
            func_8030E540(SFX_82_METAL_BREAK);
            func_8030E540(SFX_B6_GLASS_BREAKING_1);
            func_802EE278(sp2C, 4, 0x23, 0x1E, 0.7f, 0.6f);
            marker_despawn(arg0);
            break;

        case 0x123:
        case 0x1F2:
        case 0x1F3:
        case 0x235:
        case 0x236:
        case 0x237:
        case 0x238:
        case 0x239:
            func_8030E540(SFX_13A_GLASS_BREAKING_7);
            func_802EE278(sp2C, 4, 0x2D, 0x82, 1.0f, 1.0f);
            if (arg0->id == 0x1F3) {
                func_802EE278(sp2C, 4, 0x2D, 0x104, 1.0f, 1.0f);
            }
            marker_despawn(arg0);
            break;

        case 0x11E:
            func_8030E540(SFX_B6_GLASS_BREAKING_1);
            func_802EE278(sp2C, 4, 0x32, 0x50, 1.0f, 1.4f);
            func_802EE278(sp2C, 4, 0x32, 0xA0, 1.0f, 1.4f);
            func_802EE278(sp2C, 4, 0x1E, 0xF0, 0.8f, 1.1f);
            func_802D317C(arg0, FILEPROG_C3_ICE_BALL_TO_CHEATO_BROKEN);
            break;

        case MARKER_121_GLASS_EYE:
            func_8030E540(SFX_B6_GLASS_BREAKING_1);
            func_802EE2E8(sp2C, 1, 0x32, 0x14, 1.2f, 1.4f, 2.2f);
            func_802EE2E8(sp2C, 1, 0x3C, 0x64, 1.6f, 1.8f, 2.2f);
            func_802EE2E8(sp2C, 1, 0x32, 0xB4, 1.2f, 1.4f, 2.2f);
            func_802D317C(arg0, FILEPROG_C4_STATUE_EYE_BROKEN);
            break;

        case 0x164:
        case 0x165:
            if (sp2C->unk1C[1] == sp2C->position[1]) {
                sfxsource_play(SFX_9B_BOULDER_BREAKING_1, 25000);
                sp2C->unk1C[0] = 1.0f;
            }
            break;

        default:   
            func_8030E540(SFX_D_EGGSHELL_BREAKING);
            func_8030E540(SFX_11_WOOD_BREAKING_1);
            marker_despawn(arg0);
            break;
    }
}

void func_802D3CC8(ActorMarker *marker){
    func_802D31AC(marker, NULL);
}

void func_802D3CE8(Actor *this){
    if(!this->initialized){
        marker_setCollisionScripts(this->marker, NULL, func_802D3138, func_802D31AC);
        this->marker->propPtr->unk8_3 = TRUE;
        this->initialized = TRUE;
    }
}

void func_802D3D54(Actor *this){
    func_802D3CE8(this);
}

void func_802D3D74(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
}

void func_802D3DA4(Actor *this) {
    f32 sp24[3];
    s32 phi_v0;

    if ((*(s32*)OS_PHYSICAL_TO_K1(0x22C) - 0x12600004)) {
        return;
    }

    if (!this->volatile_initialized) {

        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk38_31 = 0;
    }
    player_getPosition(sp24);
    phi_v0 = ((this->position[1] - 5.0f) <= sp24[1]) && (sp24[1] <= (this->position[1] + 30.0f))
        && (((sp24[0] - this->position[0])*(sp24[0] - this->position[0]) + (sp24[2] - this->position[2])*(sp24[2] - this->position[2])) < 3025.0f);

    if ((this->unk38_31 == 0) && (phi_v0 == 0)) {
        this->unk38_31 = 1;
    }
    if ((this->unk38_31 == 1) && (phi_v0 == 1) 
        && func_8028F20C() && (func_8028F66C(BS_INTR_37) == 2)) {
        this->unk38_31 = 2;
    }
}

Actor *func_802D3F48(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 phi_s2;
    Actor *this;
    s32 i;

    this = marker_getActor(marker);
    phi_s2 = this->unkF4_8;
    for(i = 0; i < 9; i++){
        func_8033A45C(i + 1, i+1 == phi_s2);
    }
    return actor_drawFullDepth(marker, gfx, mtx, vtx);
}

void func_802D3FD4(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        func_802D3CE8(this);
        switch(map_get()){
            case MAP_1D_MMM_CELLAR: //L802D4058
                if(sns_get_item_state(SNS_ITEM_EGG_CYAN, 1) && !sns_get_item_state(SNS_ITEM_EGG_CYAN, 0)){
                    return;
                }
                break;

            case MAP_61_CCW_WINTER_NABNUTS_HOUSE://L802D4080
                if(sns_get_item_state(SNS_ITEM_EGG_YELLOW, 1) && !sns_get_item_state(SNS_ITEM_EGG_YELLOW, 0)){
                    return;
                }
                break;

            case MAP_2C_MMM_BATHROOM: //L802D40A8
                if(sns_get_item_state(SNS_ITEM_EGG_GREEN, 1) && !sns_get_item_state(SNS_ITEM_EGG_GREEN, 0)){
                    return;
                }
                break;

            case MAP_3F_RBB_CAPTAINS_CABIN: //L802D40D0
                if(sns_get_item_state(SNS_ITEM_EGG_RED, 1) && !sns_get_item_state(SNS_ITEM_EGG_RED, 0)){
                    return;
                }
                break;

            case MAP_92_GV_SNS_CHAMBER:
                if(!sns_get_item_state(SNS_ITEM_EGG_BLUE, 0))
                    return;
                break;

            case MAP_8F_TTC_SHARKFOOD_ISLAND: //L802D4110
                if(!sns_get_item_state(SNS_ITEM_EGG_PINK, 0))
                    return;
                break;
        }//L802D4124
        marker_despawn(this->marker);
        return;
    }//L802D4134

    this->yaw += (this->unkF4_8 & 1) ? -1.4 : 1.4;
    if(this->yaw < 0.0f){
        this->yaw += 360.0f;
    }
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
}

Actor *func_802D41C4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    s32 sp2C;
    Actor *this;
    s32 i;

    this = marker_getActor(marker);
    sp2C = this->unkF4_8;
    for(i = 0; i < 6; i++){
        func_8033A45C(i+1, FALSE);
    }
    func_8033A45C(sp2C, TRUE);
    return actor_drawFullDepth(marker, gfx, mtx, vtx);
}

void func_802D4250(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        func_802D3CE8(this);
        if(sns_get_item_state(SNS_ITEM_ICE_KEY, FALSE)){
            marker_despawn(this->marker);
        }
        return;
    }
    this->yaw += 2.0;
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
}



bool func_802D42F8(Actor *this) {
    s32 i;

    for(i = 0; D_803679B0[i] != -1 && this->unkF4_8 != D_803679B0[i]; i+=2){
    }

    if (D_803679B0[i] == -1) {
        return FALSE;
    }
    else{
        return fileProgressFlag_get(D_803679B0[i + 1]);
    }
}


void func_802D4388(Actor *this){
    func_802D3CE8(this);
    this->unk38_0 = BOOL(map_get() == MAP_7A_GL_CRYPT || item_getCount(ITEM_1C_MUMBO_TOKEN) >= this->unkF4_8 || func_802D42F8(this));
    mapSpecificFlags_set(0x1F, (func_8028F20C() && func_8028FB48(0x78000000)) || func_8028ECAC() == BSGROUP_D_TRANSFORMING);
    switch(this->state){
        case 0x12: //L802D4468
            if(this->unk38_0 && mapSpecificFlags_get(0x1F)){
                subaddie_set_state_with_direction(this, 0x13, 0.0f, 1);
                actor_playAnimationOnce(this);
                func_8030E6D4(SFX_90_SWITCH_PRESS);
            }
            break;

        case 0x13: //L802D44B0
            if(0.66 <= animctrl_getAnimTimer(this->animctrl)){
                subaddie_set_state_with_direction(this, 0x14, 0.66f, 0);
            }
            break;

        case 0x14: //L802D44F0
            if(!this->unk38_0 || !mapSpecificFlags_get(0x1F)){
                subaddie_set_state_with_direction(this, 0x15, 0.66f, 0);
                actor_playAnimationOnce(this);
            }
            break;

        case 0x15: //L802D4534
             if(animctrl_getAnimTimer(this->animctrl) < 0.03){
                subaddie_set_state_with_direction(this, 0x12, 0.0f, 1);
            }
            break;
    }//L802D456C
    mapSpecificFlags_set(0x1F, FALSE);
}

Actor *func_802D4588(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 phi_a1;

    phi_a1 = (marker_getActor(marker)->unk38_0) ? ((globalTimer_getTime() & 4) != 0) ? 1 : 2 : 2;
    func_8033A45C(1, phi_a1);
    return actor_draw(marker, gfx, mtx, vtx);
}

bool func_802D4608(void){
    return D_803676AC;
}

void func_802D4614(enum map_e map_id){
    if(D_803676AC)
        return;
    D_803676AC = TRUE;
    func_8028F918(2);
    func_8025A788(COMUSIC_69_FF_WARP, 0.0f, 1.7f);
    timedFunc_set_2(1.0f, (GenFunction_2) func_8031CC40, map_id, 2);
}

void func_802D4680(Actor *this){
    f32 sp1C[3];

    player_getPosition(sp1C);
    switch(this->state){
        case 0:
            if(150.0f < func_80258640(this->position, sp1C)){
                subaddie_set_state(this, 1);
                D_803676AC = 0;
            }
            break;
        case 1:
            if(func_80258640(this->position, sp1C) < 150.0f && func_8028F20C()){
                if(func_8028ECAC() == 0 ||  func_8028ECAC() == BSGROUP_8_TROT){
                    if(map_get() == MAP_8E_GL_FURNACE_FUN){
                        volatileFlag_set(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ, 0);
                        func_802D4614(MAP_80_GL_FF_ENTRANCE);
                    }
                    else{
                        func_802D4614(MAP_8E_GL_FURNACE_FUN);
                    }
                }
            }
            break;
    }
}

void func_802D4794(Actor *this, enum sfx_e sfx_id, f32 arg2, s32 arg3, s32 arg4){
    if(this->unk44_31 != 0)
        return;

    this->unk44_31 = func_802F9AA8(sfx_id);
    func_802FA060(this->unk44_31, arg3, arg3, 0.0f);
    func_802F9DB8(this->unk44_31, arg2, arg2, 0.0f);
    func_802F9F80(this->unk44_31, (f32)arg4, 1e+09f, 0.0f);
}

void func_802D4830(Actor *this, enum sfx_e arg1, f32 arg2){
    func_802D4794(this, arg1, arg2, 32000, 0);
}

void func_802D485C(Actor *this, enum sfx_e arg1, f32 arg2, s32 arg3){
    func_802D4794(this, arg1, arg2, arg3, 0);
}

void func_802D4884(Actor *this, enum sfx_e sfx_id, f32 arg2, s32 arg3, f32 arg4){
    func_802D4794(this, sfx_id, arg2, arg3, (s32)arg4);
}

void func_802D48B8(Actor *this){
    if(this->unk44_31){
        func_802F9D38(this->unk44_31);
        this->unk44_31 = 0;
    }
}

void func_802D48F0(void){
    if(D_803676A8){
        func_802F9D38(D_803676A8);
        D_803676A8 = 0;
    }
}

void func_802D4928(Actor *this, s32 arg1, s32 arg2, s32 arg3) {
    this->marker->propPtr->unk8_3 = TRUE;
    if( ( (((arg1 & 0xC00000) == 0) && mapSpecificFlags_get(arg1 - 0)) 
          || (((arg1 & 0xC00000) == 0x800000) && fileProgressFlag_get(arg1 - 0x800000)) 
          || (((arg1 & 0xC00000) == 0x400000) && volatileFlag_get(arg1 - 0x400000))
        ) 
        && (arg2 != this->state)
    ) {
        subaddie_set_state_with_direction(this, arg2, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    if( ( (((arg1 & 0xC00000) == 0) && !mapSpecificFlags_get(arg1 - 0)) 
          || (((arg1 & 0xC00000) == 0x800000) && !fileProgressFlag_get(arg1 - 0x800000)) 
          || (((arg1 & 0xC00000) == 0x400000) && !volatileFlag_get(arg1 - 0x400000))
        ) 
        && (arg2 == this->state)
    ) {
        subaddie_set_state_with_direction(this, arg3, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
}

void func_802D4A9C(Actor *this, s32 arg1){
    func_802D4928(this, arg1, 2, 3);
}

void func_802D4AC0(Actor *this, s32 arg1, s32 arg2) {
    if (fileProgressFlag_get(arg2)) {
        if (arg1 & 0x800000) {
            fileProgressFlag_set(arg1 + 0xFF800000, 1);
        }
        if (arg1 & 0x400000) {
            volatileFlag_set(arg1 + 0xFFC00000, 1);
        }
    }
    if( (((arg1 & 0x800000) && (fileProgressFlag_get(arg1 + 0xFF800000))) || ((arg1 & 0x400000) && (volatileFlag_get(arg1 + 0xFFC00000)))) 
        && (fileProgressFlag_get(arg2)) && (this->animctrl == NULL)
    ) {
        subaddie_set_state_with_direction(this, 8, 0.0f, 1);
    }
    func_802D4A9C(this, arg1);
}


void func_802D4B94(Actor *this){
    func_802D4AC0(this, 0x4000b6, FILEPROG_18_MM_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4BBC(Actor *this){
    func_802D4AC0(this, 0x4000bc, FILEPROG_9A_CC_WITCH_SWITCH_PRESSED);
}

void func_802D4BE4(Actor *this){
    func_802D4AC0(this, 0x4000bd, FILEPROG_9F_BGS_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4C0C(Actor *this){
    func_802D4AC0(this, 0x4000be, FILEPROG_A0_GV_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4C34(Actor *this){
    func_802D4AC0(this, 0x4000b7, FILEPROG_19_MMM_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4C5C(Actor *this){
    func_802D4AC0(this, 0x4000b8, FILEPROG_1A_TTC_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4C84(Actor *this){
    func_802D4AC0(this, 0x4000b9, FILEPROG_1C_RBB_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4CAC(Actor *this){
    func_802D4AC0(this, 0x4000ba, FILEPROG_46_CCW_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4CD4(Actor *this){
    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0()){
            this->unk58_0 = FALSE;
            return;
        }//L802D4D10
        this->unk58_0 = TRUE;
    }//L802D4D1C
    func_802D4AC0(this, 0x4000bb, FILEPROG_47_FP_WITCH_SWITCH_JIGGY_PRESSED);
}

void func_802D4D3C(enum actor_e arg0, enum actor_e arg1) {
    f32 sp5C[3];
    s32 sp4C[4];
    f32 sp40[3];

    if (nodeProp_findPositionFromActorId(arg1, sp5C)) {
        codeABC00_spawnJiggyAtLocation(arg0, sp5C);
        func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7FFF);
        if (arg0 == 0x36) {
            
            sp4C[3] = 200;
            sp4C[0] = sp4C[1] = sp4C[2] = 180;\
            ml_vec3f_assign(sp40, 0.0f, 0.0f, 0.0f);
            func_802EE6CC(sp5C, sp40, sp4C, 0, 6.0f, 200.0f, 200, 100, 0);

            sp4C[3] = 230;
            sp4C[0] = sp4C[1] = sp4C[2] = 150;
            ml_vec3f_assign(sp40, 0.0f, 2.0f, 0.0f);
            func_802EE6CC(sp5C, sp40, sp4C, 0, 2.0f, 90.0f, 50, 33, 0);
          
            sp4C[3] = 150;
            sp4C[0] = sp4C[1] = sp4C[2] = 230;
            ml_vec3f_assign(sp40, -3.0f, 1.0f, 1.0f);
            func_802EE6CC(sp5C, sp40, sp4C, 0, 3.5f, 130.0f, 100, 80, 0);

            sp4C[3] = 200;
            sp4C[0] = sp4C[1] = sp4C[2] = 250;
            ml_vec3f_assign(sp40, -1.0f, 3.0f, -3.0f);
            func_802EE6CC(sp5C, sp40, sp4C, 0, 2.4f, 40.0f, 10, 120, 0);
            
            sp4C[3] = 130;
            sp4C[0] = sp4C[1] = sp4C[2] = 130;
            ml_vec3f_assign(sp40, 2.0f, -2.0f, 2.0f);
            func_802EE6CC(sp5C, sp40, sp4C, 0, 4.7f, 180.0f, 20, 160, 0);
            func_8030E6D4(SFX_1B_EXPLOSION_1);
        }
        else{
            __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM,
                reinterpret_cast(s32, sp5C[0]),
                reinterpret_cast(s32, sp5C[1]),
                reinterpret_cast(s32, sp5C[2])
            );
        }
    }
}

void func_802D5000(enum map_e map_id){
    if(map_getLevel(map_id) != level_get())
        func_802E4A70();
    func_803228D8();
    func_802E4078(D_80367684, 0x65, 0);
}

void func_802D5058(enum map_e map_id, s32 arg1, bool arg2) {
    volatileFlag_set(VOLATILE_FLAG_1, 1);
    D_80367684 = map_id;
    D_80367688 = arg1;
    if (arg2) {
        D_8036768C = 0x2D;
    } else {
        D_8036768C = 0x15;
    }
    D_80367690 = 0;
    D_80367694 = map_get();
    D_80367698 = 1;
    D_8036769C = 0;
    D_803676A0 = 0;
    if (map_id != D_80367694) {
        timedFunc_set_1(0.25f, (GenFunction_1)func_802D5000, map_id);
    } else {
        timedFunc_set_0(0.25f, func_802D63D4);
    }
    gcpausemenu_80314AC8(0);
}


void func_802D5140(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    itemscore_noteScores_get(volatileFlag_getN(VOLATILE_FLAG_19_CURRENT_LEVEL_ID, 4));
}

void func_802D5178(s32 arg0, enum file_progress_e arg1, s32 arg2, enum map_e arg3, s32 arg4, s32 arg5, enum actor_e arg6, s32 arg7){
    if(levelSpecificFlags_get(arg0) && !fileProgressFlag_get(arg1)){
        levelSpecificFlags_set(arg0, FALSE);
        fileProgressFlag_set(arg1, TRUE);
        func_802D6264(0.95f, arg3, arg2, arg4, arg5, 0);
        D_803676A0 = arg6;
        D_80367690 = arg7;
    }
}

void func_802D520C(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    if(volatileFlag_get(VOLATILE_FLAG_1) && map_get() != MAP_8E_GL_FURNACE_FUN){
        func_80319214(gfx, mtx, vtx);
    }
}

void func_802D5260(void) {
    s32 sp3C;
    s32 sp38;
    f32 sp34;
    f32 sp28[3];

    sp3C = (map_get() == MAP_76_GL_640_NOTE_DOOR) ? 0
         : (map_get() == MAP_77_GL_RBB_LOBBY) ? 1
         : (map_get() == MAP_78_GL_RBB_AND_MMM_PUZZLE) ? 2
         : -1;

    if (sp3C == -1) {
        levelSpecificFlags_set(0x3C, FALSE);
        fileProgressFlag_set(FILEPROG_26_WATER_SWITCH_3_PRESSED, FALSE);
        fileProgressFlag_set(FILEPROG_27_LAIR_WATER_LEVEL_3,     FALSE);
        levelSpecificFlags_set(0x3D, FALSE);
        return;
    }
    sp38 = func_8034C528(sp3C + 0x190);
    if( fileProgressFlag_get(FILEPROG_27_LAIR_WATER_LEVEL_3)
        && !levelSpecificFlags_get(0x3D)
        && !levelSpecificFlags_get(0x3C)
    ) {
        func_802D68F0(30);
        item_set(ITEM_6_HOURGLASS, TRUE);
        levelSpecificFlags_set(0x3D, TRUE);
    }
    if( levelSpecificFlags_get(0x3D)
        && !levelSpecificFlags_get(0x3C) 
        && item_getCount(ITEM_6_HOURGLASS) == FALSE
    ) {
        levelSpecificFlags_set(0x3C, TRUE);
        levelSpecificFlags_set(0x3D, FALSE);
        D_803676A4 = 0.0f;
    }
    if (levelSpecificFlags_get(0x3C)) {
        D_803676A4 -= 5.0;
        if (D_803676A8 == 0) {
            D_803676A8 = func_802F9AA8(SFX_3EC_CCW_DOOR_OPENING);
            func_802FA060(D_803676A8, 20000, 20000, 0.0f);
            func_802F9F80(D_803676A8, 0.0f, 1.0e8f, 0.0f);
        }
        if (D_803679C8[sp3C].unk6 + D_803676A4 <= D_803679C8[sp3C].unk4) {
            levelSpecificFlags_set(0x3C, FALSE);
            fileProgressFlag_set(FILEPROG_26_WATER_SWITCH_3_PRESSED, FALSE);
            fileProgressFlag_set(FILEPROG_27_LAIR_WATER_LEVEL_3,     FALSE);
            func_802F9D38(D_803676A8);
            D_803676A8 = 0;
        }
    }
    if (sp38 != 0) {
        if (levelSpecificFlags_get(0x3C) != 0) {
            sp34 = D_803679C8[sp3C].unk6 + D_803676A4;
        } else {
            sp34 = ((s16 *)&D_803679C8[sp3C])[(fileProgressFlag_get(FILEPROG_27_LAIR_WATER_LEVEL_3)) ? 3 
                     : (fileProgressFlag_get(FILEPROG_25_LAIR_WATER_LEVEL_2)) ? 2
                     : (fileProgressFlag_get(FILEPROG_23_LAIR_WATER_LEVEL_1)) ? 1
                     : 0];
        }
        func_8034DEB4(sp38, sp34);
        player_getPosition(sp28);
        
        fxRipple_802F363C(sp34 + ((sp3C != -1) ? (D_803679E0[sp3C] + ((sp3C == 2) ? (6600.0f < sp28[0]) ? -200 : 0 : 0)) : 0));
    }
}

void func_802D5628(void){
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp50[6];
    s32 sp4C;
    static s32 D_803679E8 = 0;
    static s32 D_803679EC = 0;
    static f32 D_803679F0 = 0.0f;

    if( map_get() != MAP_8E_GL_FURNACE_FUN
        && map_get() != MAP_80_GL_FF_ENTRANCE
    ){
        D_803676AC = 0;
    }

    if(getGameMode() != GAME_MODE_4_PAUSED){
        if( func_802BB294() == 0x82 
            && ! gctransition_8030BDC0()
        ){
            D_803679E8++;
            if(D_803679EC < D_803679E8){
                D_803679EC--;
                D_803679E8 = 0;
                if(D_803679EC < 2){
                    D_803679EC = 2;
                }
                func_8030E6A4(SFX_2_CLAW_SWIPE, MIN(2.0,D_803679F0), 20000);
                D_803679F0 += 0.05;
            }
        }
        else{//L802D5750
            D_803679F0 = 0.9f;
            D_803679EC = 0xD;
            D_803679E8 = 0;
        }
    }//L802D5774
    if(D_80367684 && map_get() == D_80367684){
        switch(D_8036768C){
            case 0x1: // L802D57C8
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (GenFunction_2) func_802D4D3C, 0x34, 0x205);
                    D_80367690++;
                }
                break;

            case 0x2: // L802D5808
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (GenFunction_2) func_802D4D3C, 0x39, 0x207);
                    D_80367690++;
                }
                break;

            case 0x3: // L802D5848
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (GenFunction_2) func_802D4D3C, 0x36, 0x20a);
                    D_80367690++;
                }   
                break;

            case 0x4: // L802D5888
                func_802D5260();
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (GenFunction_2) func_802D4D3C, 0x3b, 0x20c);
                    D_80367690++;
                }
                break;

            case 0x12: // L802D58D0
                if(!D_80367690){
                    timedFunc_set_2(0.4f, (GenFunction_2) func_802D4D3C, 0x3c, 0x238);
                    D_80367690++;
                }
                break;

            case 0x5: // L802D5910
                if(!D_80367690){
                    sp7C = func_802F9AA8(0x3EC);
                    sp78 = func_8034C528(0x191);
                    if(sp78){
                        func_8034DE60(sp78, -580.0f, 0.0f, 2.5f, 1);
                    }
                    func_802FA060(sp7C, 20000, 20000, 0.0f);
                    func_802F9F80(sp7C, 0.0f, 2.2f, 0.7f);
                    D_80367690++;
                }
                break;

            case 0x6:// L802D599C
                if(!D_80367690){
                    sp74 = func_802F9AA8(0x3EC);
                    sp70 = func_8034C528(0x191);
                     if(sp70){
                        func_8034DE60(sp70, 0.0f, 1550.0f, 6.5f, 1);
                    }
                    func_802FA060(sp74, 20000, 20000, 0.0f);
                    func_802F9F80(sp74, 0.0f, 6.2f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x7: // L802D5A28
                if(!D_80367690){
                    sp6C = func_802F9AA8(0x3EC);
                    sp68 = func_8034C528(0x190);
                     if(sp68){
                        func_8034DE60(sp68, 1200.0f, 1900.0f, 3.0f, 1);
                    }
                    func_802FA060(sp6C, 20000, 20000, 0.0f);
                    func_802F9F80(sp6C, 0.0f, 2.7f, 0.5f);
                    D_80367690++;
                }
                break;

            case 0x15:// L802D5AB4
            case 0x2d:// L802D5AB4
                if(D_80367684 && D_80367684 == map_get()){
                    func_80319EA4();
                    if(0.0f < D_8037DE08){
                        D_8037DE08 -= time_getDelta();
                    }
                    else{//L802D5B24
                        func_8024E55C(0, sp50); //get button inputs
                        if(sp50[FACE_BUTTON(BUTTON_B)] == 1){
                            func_80324C58();
                            func_802D6114();
                        }
                    }
                }
                break;

            case 0xd: // L802D5B54
                func_802D5260();
                break;
        }//L802D6078
    }
    else{//L802D5B64
        func_802D5260();
        func_802D5178(0x1C, 0x28, 0x30, MAP_69_GL_MM_LOBBY,  0x8, 0xA, ACTOR_20E_MM_ENTRANCE_DOOR, 0x28);
        func_802D5178(0x21, 0x2D, 0x31, MAP_6E_GL_GV_LOBBY,  0xA, 0xA, ACTOR_226_GV_ENTRANCE,      0x12);
        func_802D5178(0x1E, 0x2A, 0x32, MAP_70_GL_CC_LOBBY,  0xE, 0xA, ACTOR_212_CC_ENTRANCE_BARS,         0xA);
        func_802D5178(0x1D, 0x29, 0x33, MAP_6D_GL_TTC_LOBBY, 0x9, 0xB, ACTOR_211_TCC_ENTRANCE_CHEST_LID,         0xA);
        func_802D5178(0x1F, 0x2B, 0x34, MAP_72_GL_BGS_LOBBY, 0xB, 0xB, ACTOR_210_BGS_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x23, 0x2F, 0x35, MAP_77_GL_RBB_LOBBY, 0xD, 0x5, ACTOR_20F_RBB_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x22, 0x2E, 0x36, MAP_75_GL_MMM_LOBBY, 0xC, 0x6, ACTOR_228_MMM_ENTRANCE_DOOR,    0xA);
        func_802D5178(0x24, 0x30, 0x37, MAP_79_GL_CCW_LOBBY, 0xF, 0xB, ACTOR_234_CCW_ENTRANCE_DOOR, 0xA);
        func_802D5178(0x20, 0x2C, 0x38, MAP_6F_GL_FP_LOBBY, 0x11, 0xA, ACTOR_235_FP_ENTANCE_DOOR,   0xA);
        func_802D5178(0x3F, 0xE2, 0x40, MAP_93_GL_DINGPOT,  0x10, 0xA, ACTOR_2E5_DOOR_OF_GRUNTY,   0x28);
        if(volatileFlag_get(VOLATILE_FLAG_18)){
            if(!fileProgressFlag_get(FILEPROG_99_PAST_50_NOTE_DOOR_TEXT)){
                func_80311174(0xF75, 0xE, NULL, NULL, NULL, NULL, func_802D5140);
                fileProgressFlag_set(FILEPROG_99_PAST_50_NOTE_DOOR_TEXT, TRUE);
                volatileFlag_set(VOLATILE_FLAG_18, 0);
            }
            else{//L802D5DD8
                if(!volatileFlag_get(VOLATILE_FLAG_16)){
                    func_80311174(0xF77, 0x4, NULL, NULL, NULL, NULL, func_802D5140);
                    volatileFlag_set(VOLATILE_FLAG_18, 0);
                }
            }
        }//L802D5E18
        if(level_get() == LEVEL_6_LAIR){
            if( getGameMode() == GAME_MODE_3_NORMAL
                || func_802E4A08()
            ){
                if( map_get() != MAP_8E_GL_FURNACE_FUN
                    && map_get() != MAP_90_GL_BATTLEMENTS
                    && !fileProgressFlag_get(FILEPROG_FC_DEFEAT_GRUNTY)
                ){
                    D_8037DE04 += time_getDelta();
                    if(D_80367680 < D_8037DE04 && !volatileFlag_get(VOLATILE_FLAG_16)){
                        if(fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)){
                            sp4C = 0xF9D;
                        }
                        else{
                            sp4C = 0xFA5;
                        }

                        if(!D_8037DE00){
                            D_8037DE00 = randi2(0xF86, sp4C);
                        }//L802D5F1C

                        if(volatileFlag_get(VOLATILE_FLAG_22)){
                            if(gcdialog_showText(0xF82, 4, NULL, NULL, NULL, NULL)){
                                fileProgressFlag_set(FILEPROG_C1_BADDIES_ESCAPE_TEXT, TRUE);
                                volatileFlag_set(VOLATILE_FLAG_22, 0);
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                        else{//L802D5FCC
                            if(gcdialog_showText(D_8037DE00, 0, NULL, NULL, NULL, NULL)){
                                D_8037DE00++;
                                if(!(D_8037DE00 < sp4C)){
                                    D_8037DE00 = 0xF86;
                                }//L802D6018
                                D_8037DE04 = 0.0f;
                                D_80367680 += 60.0;
                                if(300.0 < D_80367680)
                                    D_80367680 = 130.0f;
                            }
                        }
                    }
                }
            }
        }//L802D607C
    }//L802D607C
}

//water_level_atleast_2;
int func_802D6088(void){
    return fileProgressFlag_get(FILEPROG_25_LAIR_WATER_LEVEL_2)
        || fileProgressFlag_get(FILEPROG_27_LAIR_WATER_LEVEL_3);
}

//water_level_atleast_1;
int func_802D60C4(void){
    return fileProgressFlag_get(FILEPROG_23_LAIR_WATER_LEVEL_1)
        || fileProgressFlag_get(FILEPROG_25_LAIR_WATER_LEVEL_2)
        || fileProgressFlag_get(FILEPROG_27_LAIR_WATER_LEVEL_3);
}

void func_802D6114(void){
    s32 sp24; 
    s32 sp20;

    sp24 =  D_80367694;\
    sp20 =  D_80367698;
    if(D_8036769C)
        fileProgressFlag_set(D_8036769C, TRUE);
    func_802D6344();
    if(map_get() != sp24){
        if(map_getLevel(sp24) != map_getLevel(map_get())){
            func_802E4A70();
        }//L802D6194
        volatileFlag_set(VOLATILE_FLAG_21, 1);
        if(sp24 != 0x1C || !func_8025ADBC(COMUSIC_23_MMM_INSIDE_CHURCH)){
            func_803228D8();
        }
        func_802E4078(sp24, sp20, 0);
    }
    else{//L802D61DC
        func_80347A14(1);
        gcpausemenu_80314AC8(1);
    }
}

void func_802D61FC(enum map_e arg0){
    if( map_getLevel(arg0) != map_getLevel(map_get()))
        func_802E4A70();
    func_803228D8();
    func_802E4078(D_80367684, 0, 0);
    func_802D6750();
}

void func_802D6264(f32 delay, enum map_e map_id, s32 arg2, s32 arg3, s32 arg4, enum file_progress_e arg5){
    D_80367684 = map_id;
    D_80367688 = arg2;
    D_8036768C = arg3;
    D_80367690 = 0;

    D_80367694 = map_get();
    D_80367698 = arg4;
    D_8036769C = arg5;
    D_803676A0 = 0;

    if(map_id != D_80367694){
        timedFunc_set_1(delay, (GenFunction_1) func_802D61FC, map_id);
    }
    else{
        timedFunc_set_0(delay, func_802D63D4);
    }
    gcpausemenu_80314AC8(0);
}

void func_802D6310(f32 delay, enum map_e map_id, s32 arg2, s32 arg3, enum file_progress_e arg4){
    func_802D6264(delay, map_id, arg2, arg3, 0x63, arg4);
    func_8028FCE8();
}

void func_802D6344(void){
    D_80367684 = 0;
    D_80367688 = 0;
    D_8036768C = 0;
    D_80367690 = 0;
    D_80367694 = 0;
    D_80367698 = 0;
    D_8036769C = 0;
    D_803676A0 = 0;
}

void func_802D6388(void){
    timedFunc_set_0(5.0f, func_802D6114);
    camera_setType(1);
    ncStaticCamera_setToNode(D_80367688);
    D_8037DE08 = 0.5f;
}

void func_802D63D4(void){
    f32 sp1C[3];

    if(D_80367684 == 0)
        return;

    if(map_get() != D_80367684)
        return;

    func_80347A14(0);
    switch(D_8036768C){
        case 0x15:  //L802D6430
            func_802D6388();
            break;
        case 0x2D: //L802D6440
            func_802D6388();
            ncStaticCamera_getPosition(sp1C);
            func_8028F85C(sp1C);
            break;
        default: //L802D6460
            func_802BAFE4(D_80367688);
            timedFuncQueue_update();
            volatileFlag_set(VOLATILE_FLAG_BF, 0);
            func_802D6750();
            break;
    }
}


void func_802D6494(void){
    if( (!D_80367684 || (D_80367684 && (map_get() == D_80367684)))
    ){
        switch(D_803676A0){
            case ACTOR_2E5_DOOR_OF_GRUNTY:
                break;
            case ACTOR_20E_MM_ENTRANCE_DOOR:// L802D6510
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_211_TCC_ENTRANCE_CHEST_LID:// L802D6530
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                break;
            case ACTOR_212_CC_ENTRANCE_BARS:// L802D6550
                if(map_get() == MAP_70_GL_CC_LOBBY && !volatileFlag_get(VOLATILE_FLAG_7F_SANDCASTLE_OPEN_CC)){
                    func_802D4830(actorArray_findActorFromActorId(ACTOR_212_CC_ENTRANCE_BARS), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_234_CCW_ENTRANCE_DOOR:// L802D65A0
                if(map_get() == MAP_79_GL_CCW_LOBBY && !volatileFlag_get(VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW)){
                    func_802D485C(actorArray_findActorFromActorId(ACTOR_234_CCW_ENTRANCE_DOOR), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_210_BGS_ENTRANCE_DOOR:// L802D65F8
                if(!volatileFlag_get(VOLATILE_FLAG_84_SANDCASTLE_OPEN_BGS)){
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_235_FP_ENTANCE_DOOR:// L802D6624
                if(map_get() == MAP_6F_GL_FP_LOBBY && !volatileFlag_get(VOLATILE_FLAG_8B_SANDCASTLE_OPEN_FP)){
                    func_802D4830(actorArray_findActorFromActorId(ACTOR_235_FP_ENTANCE_DOOR), SFX_18_BIGBUTT_SLIDE, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_226_GV_ENTRANCE:// L802D6674
                if(map_get() == MAP_6E_GL_GV_LOBBY && !volatileFlag_get(VOLATILE_FLAG_87_SANDCASTLE_OPEN_GV)){
                    func_802D485C(actorArray_findActorFromActorId(ACTOR_226_GV_ENTRANCE), SFX_3EC_CCW_DOOR_OPENING, 0.8f, 15000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_228_MMM_ENTRANCE_DOOR:// L802D66CC
                if(!volatileFlag_get(VOLATILE_FLAG_8C_SANDCASTLE_OPEN_MMM)){
                FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0.6f, 32000);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
            case ACTOR_20F_RBB_ENTRANCE_DOOR:// L802D66F8
                if(map_get() == MAP_77_GL_RBB_LOBBY && !volatileFlag_get(VOLATILE_FLAG_90_SANDCASTLE_OPEN_RBB)){
                    func_802D4830(actorArray_findActorFromActorId(ACTOR_20F_RBB_ENTRANCE_DOOR), SFX_9A_MECHANICAL_CLOSING, 0.5f);
                    func_8025A6CC(COMUSIC_64_WORLD_OPENING_A, 32000);
                }
                break;
        }
    }
}

void func_802D6750(void){
    timedFunc_set_0(0.4f, func_802D6494);
}

enum map_e func_802D677C(enum map_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367684;
    out = D_80367684;
    D_80367684 = arg0;
    return out;
}

s32 func_802D67AC(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_8036768C;
    out = D_8036768C;
    D_8036768C = arg0;
    return out;
}

enum actor_e func_802D67DC(enum actor_e arg0){
    s32 out;
    if(arg0 == -1)
        return D_803676A0;
    out = D_803676A0;
    D_803676A0 = arg0;
    return out;
}

s32 func_802D680C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367690;
    out = D_80367690;
    D_80367690 = arg0;
    return out;
}

s32 func_802D683C(s32 arg0){
    s32 out;
    if(arg0 == -1)
        return D_80367688;
    out = D_80367688;
    D_80367688 = arg0;
    return out;
}

int func_802D686C(void){
    if(volatileFlag_get(VOLATILE_FLAG_1E)){
        return FALSE;
    } 
    return map_get() == D_80367684;
}

int func_802D68B4(void){
    return func_802D686C() || volatileFlag_get(VOLATILE_FLAG_21);
}

//BREAK????

//set_hourglass_timer_seconds
void func_802D68F0(s32 seconds){
    item_set(ITEM_0_HOURGLASS_TIMER, seconds*60 - 1);
}

//hide_hourglass_timer
void func_802D6924(void){
    item_set(ITEM_6_HOURGLASS, 0);
}

//update_has_entered_level_flags
void func_802D6948(void){
    switch(map_get()){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            fileProgressFlag_set(FILEPROG_B0_HAS_ENTERED_MM, TRUE);
            break;
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            fileProgressFlag_set(FILEPROG_B2_HAS_ENTERED_TTC, TRUE);
            break;
        case MAP_B_CC_CLANKERS_CAVERN:
            fileProgressFlag_set(FILEPROG_B8_HAS_ENTERED_CC, TRUE);
            break;
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            fileProgressFlag_set(FILEPROG_B1_HAS_ENTERED_BGS, TRUE);
            break;
        case MAP_12_GV_GOBIS_VALLEY:
            fileProgressFlag_set(FILEPROG_B3_HAS_ENTERED_GV, TRUE);
            break;
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            fileProgressFlag_set(FILEPROG_B7_HAS_ENTERED_MMM, TRUE);
            break;
        case MAP_27_FP_FREEZEEZY_PEAK:
            fileProgressFlag_set(FILEPROG_B6_HAS_ENTERED_FP, TRUE);
            break;
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            fileProgressFlag_set(FILEPROG_B4_HAS_ENTERED_RBB, TRUE);
            break;
        case MAP_40_CCW_HUB:
            fileProgressFlag_set(FILEPROG_B5_HAS_ENTERED_CCW, TRUE);
            break;
    }
}

//has entered map and level
int func_802D6A38(enum map_e map_id){
    switch(map_id){
        case MAP_2_MM_MUMBOS_MOUNTAIN:
            return fileProgressFlag_get(FILEPROG_B0_HAS_ENTERED_MM);
        case MAP_7_TTC_TREASURE_TROVE_COVE:
            return fileProgressFlag_get(FILEPROG_B2_HAS_ENTERED_TTC);
        case MAP_B_CC_CLANKERS_CAVERN:
            return fileProgressFlag_get(FILEPROG_B8_HAS_ENTERED_CC);
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
            return fileProgressFlag_get(FILEPROG_B1_HAS_ENTERED_BGS);
        case MAP_12_GV_GOBIS_VALLEY:
            return fileProgressFlag_get(FILEPROG_B3_HAS_ENTERED_GV);
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
            return fileProgressFlag_get(FILEPROG_B7_HAS_ENTERED_MMM);
        case MAP_27_FP_FREEZEEZY_PEAK:
            return fileProgressFlag_get(FILEPROG_B6_HAS_ENTERED_FP);
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            return fileProgressFlag_get(FILEPROG_B4_HAS_ENTERED_RBB);
        case MAP_40_CCW_HUB:
            return fileProgressFlag_get(FILEPROG_B5_HAS_ENTERED_CCW);
    }
    return FALSE;
}
