#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F3D8(f32[3], f32, void(*)(ActorMarker *), ActorMarker *);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void rand_seed(s32);
extern void func_8034DF30(s32, f32[3], f32[3], f32);
extern void func_8034E088(s32, s32, s32,f32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
}ActorLocal_lair_86F0;

typedef struct {
    u8 cost;
    u8 size_bits;
    u16 progress_flag; // enum file_progress_e
}Struct_lair_86F0_0;

void func_8038F350(Actor *this, s32 next_state);
void lair_func_8038F924(Actor *this);

/* .data */
ActorInfo D_803947B0 = { 0x1EB, 0x3B7, 0x48B, 0x1, NULL, lair_func_8038F924, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo D_803947D4 = { 0x1EB, 0x3BC, 0x538, 0x1, NULL, lair_func_8038F924, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
Struct_lair_86F0_0 D_803947F8[0xb] ={
    { 1, 0x1, FILEPROG_5D_MM_PUZZLE_PIECES_PLACED},
    { 2, 0x2, FILEPROG_5E_TCC_PUZZLE_PIECES_PLACED},
    { 5, 0x3, FILEPROG_60_CC_PUZZLE_PIECES_PLACED},
    { 7, 0x3, FILEPROG_63_BGS_PUZZLE_PIECES_PLACED},
    { 8, 0x4, FILEPROG_66_FP_PUZZLE_PIECES_PLACED},
    { 9, 0x4, FILEPROG_6A_GV_PUZZLE_PIECES_PLACED},
    {10, 0x4, FILEPROG_6E_MMM_PUZZLE_PIECES_PLACED},
    {12, 0x4, FILEPROG_72_RBB_PUZZLE_PIECES_PLACED},
    {15, 0x4, FILEPROG_76_CCW_PUZZLE_PIECES_PLACED},
    {25, 0x5, FILEPROG_7A_DOG_PUZZLE_PIECES_PLACED},
    { 4, 0x3, FILEPROG_7F_DOUBLE_HEALTH_PUZZLE_PIECES_PLACED}
};
s32 D_80394824[3] = {0xff, 0xff, 0};
ParticleScaleAndLifetimeRanges D_80394830 = {
    {0.17f, 0.24f},
    {0.08f, 0.13f},
    {0.0f, 0.01f},
    {0.9f, 0.9f},
    0.0f, 0.0f
};

/* .code */
bool func_8038EAE0(s32 arg0) {
    return fileProgressFlag_getN(D_803947F8[arg0 -1].progress_flag, D_803947F8[arg0 -1].size_bits) == D_803947F8[arg0 -1].cost;
}

s32 func_8038EB24(Actor *this){
    return (this->unkF4_8 != 0 && this->unkF4_8 < 0xC) ? D_803947F8[this->unkF4_8 - 1].cost : 0;
}

bool func_8038EB58(Actor *this){
    ActorLocal_lair_86F0 *local;

    local = (ActorLocal_lair_86F0*)&this->local;
    return func_8038EB24(this) == local->unk4;
}

s32 func_8038EB84(Actor *this){
    return this->unkF4_8 + 0x1B;
}

void func_8038EB94(void){
    func_802FAFD4(ITEM_14_HEALTH, 0x417);
    func_802FAFC0(ITEM_14_HEALTH, COMUSIC_2B_DING_B);
    fileProgressFlag_set(FILEPROG_B9_DOUBLE_HEALTH, TRUE);
    func_80347958();
    item_adjustByDiffWithHud(ITEM_14_HEALTH, 0);
    gcpausemenu_80314AC8(1);
}

void func_8038EBEC(ActorMarker *marker) {
    Actor *this;
    u32 temp_t6;

    this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    if (this->unkF4_8 < 0xA) {
        levelSpecificFlags_set(func_8038EB84(this), TRUE);
        return;
    }
    if (this->unkF4_8 == 0xA) {
        func_8028F918(0);
        func_8028F918(2);
        levelSpecificFlags_set(LEVEL_FLAG_3F_LAIR_UNKNOWN, TRUE);
        return;
    }
    if (this->unkF4_8 == 0xB) {
        timedFunc_set_0(1.5f, func_8038EB94);
        gcpausemenu_80314AC8(0);
    }
}

void func_8038EC94(ActorMarker *marker, ActorMarker *other_marker){
    marker->unk3E_1 = TRUE;
}

bool func_8038ECA8(ActorMarker *marker) {
    return func_8028F20C() && func_8028FB48(0x08000000) && marker->unk3E_1;
}

s32 func_8038ECFC(Actor *this, s32 arg1){
    ActorLocal_lair_86F0 *local;

    local = (ActorLocal_lair_86F0*)&this->local;
    return local->unk0 & (1 << arg1);
}

s32 func_8038ED10(Actor *this, s32 arg1){
    s32 phi_v1;
    switch (this->unkF4_8){
        case 7: 
            phi_v1 = (arg1 == 2) ? 0x1a4 : 0x190;
            break;

        case 3: 
            phi_v1 = 0x192;
            break;

        case 8: 
            phi_v1 = 0x19A;
            break;

        case 11: 
            phi_v1 = 0x1AE;
            break;
        default: 
            phi_v1 = 0x190;
            break;
    }
    return phi_v1 + arg1;
}

s32 func_8038ED88(Actor *this){
    switch (this->unkF4_8){
        case 3:
        case 8:
        case 0xb:
            return 0x1F;
    }
    return 0x1E;
}

void func_8038EDBC(Actor *this) {
    s32 sp44;
    s32 sp40;
    ActorLocal_lair_86F0 *local;
    s32 sp38;
    f32 sp34;
    f32 sp28[3];

    local = (ActorLocal_lair_86F0*)&this->local;
    sp38 = (this->modelCacheIndex == 0x3B7)? 0x190 : 0x192;
    sp44 = func_8034C2C4(this->marker, sp38);
    sp40 = func_8034C2C4(this->marker, sp38 + 1);
    if ((sp44 != 0) && (sp40 != 0) && (this->marker->unk14_21)) {
        sp28[0] = 1.0f;
        sp28[1] = 1.0f;
        sp28[2] = 1.0f;
        if (func_8038ECA8(this->marker) && local->unk8 < 0xFF) {
            local->unk8 = (local->unk8 + 8 < 0xFF) ? local->unk8 + 8 : 0xFF;
        } 
        else if (!func_8038ECA8(this->marker) && (local->unk8 > 0)) {
            local->unk8 = (local->unk8 - 8 > 0) ? local->unk8 - 8 : 0;
        }
        sp34 = (0xFF - local->unk8) / 255.0;
        func_8034DF30(sp44, sp28, sp28, 0);
        sp34 = 1.0 - sp34;
        func_8034DF30(sp40, sp28, sp28, 0);
        if(sp34);
    }
}


void func_8038EF58(ActorMarker *marker) {
    f32 sp24[3];
    Actor *this;

    this = marker_getActor(marker);
    func_8034A174(func_803097A0(), func_8038ED88(this), sp24);
    func_8028E6EC(2);
    func_8028F918(0);
    func_8028F94C(4, sp24);
    func_8038F350(this, fileProgressFlag_get(FILEPROG_17_HAS_HAD_ENOUGH_JIGSAW_PIECES) ? 4 : 3);
}

void func_8038EFD8(Actor *this) {
    s32 pad3C;
    f32 sp30[3];
    f32 sp24[3];

    this->has_met_before = FALSE;
    player_getPosition(sp30);
    sp24[0] = this->position[0];
    sp24[1] = this->position[1];
    sp24[2] = this->position[2];
    sp24[1] += 50.0f;
    func_8028F3D8(sp24, ml_distance_vec3f(sp30, sp24) / 150.0, func_8038EF58, this->marker);
}

void func_8038F078(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_8038F350(this, (text_id == 0xf58) ? 1 : 4);
}

void func_8038F0C0(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    func_8030E6D4(SFX_EA_GRUNTY_LAUGH_1);
}

s32 func_8038F0EC(Actor *this) {
    ActorLocal_lair_86F0 *local;
    s32 phi_s0;
    s32 sp34;
    s32 phi_s2;

    phi_s0 = 0;
    local = (ActorLocal_lair_86F0*)&this->local;
    rand_seed(this->unkF4_8);
    if (this->unkF4_8 >= 0xA) {
        for(phi_s2 = 0; phi_s2 < local->unk4; phi_s2++){
            sp34 = phi_s2;
            phi_s0 |= (1 << sp34);
        }
    } else {
        for(phi_s2 = 0; phi_s2 < local->unk4; phi_s2++){
            do{
                sp34 = randi2(0, func_8038EB24(this));
            }
            while(1 << sp34 & phi_s0);
            phi_s0 |= 1 << sp34;
        }
    }
    return sp34;
}


void func_8038F1EC(Actor *this, s32 arg1, bool arg2) {
    s32 temp_v0;

    temp_v0 = func_8034C528(func_8038ED10(this, arg1));
    if (temp_v0 != 0) {
        func_8034E088(temp_v0, arg2 ? 0 : 0xff, arg2 ? 0xff : 0, 1.0f);
    }
}

void func_8038F250(Actor *this){
    ActorLocal_lair_86F0 *local;

    local = (ActorLocal_lair_86F0*)&this->local;
    if( (this->unkF4_8 >= 2) 
        && (local->unk4 > 0) 
        && !func_8038EB58(this) 
        && !fileProgressFlag_get(FILEPROG_DF_CAN_REMOVE_ALL_PUZZLE_PIECES)
    ) {
        if (gcdialog_showText(0xF7C, 2, NULL, NULL, NULL, NULL)) {
            fileProgressFlag_set(FILEPROG_DF_CAN_REMOVE_ALL_PUZZLE_PIECES, TRUE);
        }
    } else if ((this->unkF4_8 >= 3) 
        && (local->unk4 >= 2) 
        && !func_8038EB58(this)
        && !fileProgressFlag_get(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES)
    ){
        if(gcdialog_showText(0xF7D, 2, NULL, NULL, NULL, NULL)) {
            fileProgressFlag_set(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES, TRUE);
        }
    }
}

void func_8038F350(Actor *this, s32 next_state){
    ActorLocal_lair_86F0 *local;
    f32 sp50[3];
    s32 sp4C;
    s32 temp_s1;
    s32 phi_s0;

    local = (ActorLocal_lair_86F0*)&this->local;
    func_8034A174(func_803097A0(), func_8038ED88(this), sp50);
    switch (next_state) {
        case 1: //L8038F3BC
            func_8028F918(0);
            break;

        case 2: //L8038F3CC
            func_8038EFD8(this);
            FUNC_8030E8B4(SFX_112_TINKER_ATTENTION, 1.0f, 32000, this->position, 500, 1000);
            break;

        case 3: //L8038F3F4
            func_803115C4(0xF7B);
            func_803115C4(0xF80);
            func_803115C4(0xF7F);
            if (item_getCount(ITEM_26_JIGGY_TOTAL) > 0) {
                gcdialog_showText(fileProgressFlag_get(FILEPROG_16_STOOD_ON_JIGSAW_PODIUM) ? 0xF5A : 0xF59, 6, sp50, this->marker, func_8038F078, NULL);
                fileProgressFlag_set(FILEPROG_17_HAS_HAD_ENOUGH_JIGSAW_PIECES, 1);
            } else {
                gcdialog_showText(0xF58, 6, sp50, this->marker, func_8038F078, NULL);
            }
            fileProgressFlag_set(FILEPROG_16_STOOD_ON_JIGSAW_PODIUM, 1);
            fileProgressFlag_set(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT, 1);
            break;

        case 8: //L8038F4AC
            if (local->unk4 > 0) {
                comusic_playTrack(SFX_REMOVE_JIGGY);
                this->lifetime_value = 1.0f;
                temp_s1 = func_8038F0EC(this);
                func_8038F1EC(this, temp_s1, 0);
                local->unk4--;
                local->unk0 &= ~(1 << temp_s1);
                fileProgressFlag_setN(D_803947F8[this->unkF4_8 - 1].progress_flag, local->unk4, D_803947F8[this->unkF4_8 - 1].size_bits);
                item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, 1);
            }
            break;

        case 5: //L8038F550
            if (local->unk4 < func_8038EB24(this)) {
                comusic_playTrack(COMUSIC_67_INSERTING_JIGGY);
                this->lifetime_value = 1.0f;
                local->unk4++;
                temp_s1 = func_8038F0EC(this);
                func_8038F1EC(this, temp_s1, 1);
                local->unk0 |= (1 << temp_s1);
                fileProgressFlag_setN(D_803947F8[this->unkF4_8 - 1].progress_flag, local->unk4, D_803947F8[this->unkF4_8 - 1].size_bits);
                item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, -1);
                func_8038F250(this);
            }
            break;

        case 6: //L8038F604
            if (local->unk4 < func_8038EB24(this)) {
                if(item_getCount(ITEM_26_JIGGY_TOTAL) > func_8038EB24(this) - local->unk4){
                    sp4C = func_8038EB24(this) - local->unk4;
                }
                else{
                    sp4C = item_getCount(ITEM_26_JIGGY_TOTAL);
                }
                comusic_playTrack(COMUSIC_67_INSERTING_JIGGY);
                this->lifetime_value = 1.0f;
                for(phi_s0 = 0; phi_s0 < sp4C; phi_s0++){
                    local->unk4++;
                    temp_s1 = func_8038F0EC(this);
                    func_8038F1EC(this, temp_s1, 1);
                    local->unk0 |= (1 << temp_s1);
                    item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, -1);
                }
                fileProgressFlag_setN(D_803947F8[this->unkF4_8 - 1].progress_flag, local->unk4, D_803947F8[this->unkF4_8 - 1].size_bits);
                func_8038F250(this);
            }
            break;

        case 7: //L8038F724
        comusic_playTrack(COMUSIC_65_WORLD_OPENING_B);
        if (this->unkF4_8 == 1) {
            func_80324DBC(1.0f, 0xF7E, 4, NULL, this->marker, func_8038F0C0, NULL);
        } else if (this->unkF4_8 == 0xA) {
            func_80324DBC(1.0f, 0xFAC, 4, NULL, this->marker, func_8038F0C0, NULL);
        }
        timedFunc_set_1(2.0f, (GenFunction_1) func_8038EBEC, (s32) this->marker);
        this->lifetime_value = 3.0f;
            break;
    }
    subaddie_set_state(this, next_state);
}


void lair_func_8038F800(Actor *this) {
    s32 temp_v0;
    s32 phi_s0;

    for(phi_s0 = 0; phi_s0 < func_8038EB24(this); phi_s0++){
        temp_v0 = func_8034C528(func_8038ED10(this, phi_s0));
        if (temp_v0 != 0) {
            func_8034E0FC(temp_v0, func_8038ECFC(this, phi_s0) ? 0xff : 0);
        }
    }
}

void lair_func_8038F894(Actor *this, s32 arg1) {
    if (item_getCount(ITEM_26_JIGGY_TOTAL) > 0) {
        func_8038F350(this, arg1);
        return;
    }
    comusic_playTrack(COMUSIC_2C_BUZZER);
    if (fileProgressFlag_get(FILEPROG_DE_USED_ALL_YOUR_PUZZLE_PIECES) != 0) {
        func_8038F350(this, 1);
        return;
    }
    gcdialog_showText(0xFBC, 4, NULL, NULL, NULL, NULL);
    fileProgressFlag_set(FILEPROG_DE_USED_ALL_YOUR_PUZZLE_PIECES, 1);
}

void lair_func_8038F924(Actor *this) {
    ActorLocal_lair_86F0 *local;
    s32 sp7C[6]; //buttons
    s32 phi_v1;
    s32 phi_a0;
    s32 sp6C[2]; //joystick
    f32 sp68;
    s32 sp64;
  

    local = (ActorLocal_lair_86F0*)&this->local;
    sp68 = time_getDelta();
    if (!this->initialized) {
        this->initialized = TRUE;
    }

    if (!this->volatile_initialized) {
        // temp_v0 = &D_803947F8[this->unkF4_8 - 1];
        sp64 = fileProgressFlag_getN(D_803947F8[this->unkF4_8 - 1].progress_flag, D_803947F8[this->unkF4_8 - 1].size_bits);
        local->unk0 = 0;
        local->unk4 = 0;
        local->unk8 = (func_8038ECA8(this->marker)) ? 0xff : 1;
        this->has_met_before = TRUE;
        for(phi_v1 = 0; phi_v1 < sp64; phi_v1 ++){
            local->unk4++;
            local->unk0 |= (1 << func_8038F0EC(this));
        }
        lair_func_8038F800(this);
        marker_setCollisionScripts(this->marker, func_8038EC94, NULL, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        if (this->unkF4_8 == 9) {
            this->unk1C[0] = 8.0f;
            if (!fileProgressFlag_get(FILEPROG_53_CCW_PUZZLE_PODIUM_SWITCH_PRESSED)) {
                marker_despawn(this->marker);
                return;
            }
            if (!fileProgressFlag_get(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE)) {
                __bundle_spawnFromFirstActor(BUNDLE_20__UNKOWN, this);
                func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
                func_80324D2C(2.1f, COMUSIC_43_ENTER_LEVEL_GLITTER);
                func_8030E6D4(SFX_113_PAD_APPEARS);
            }
        }
    }

    if ((this->unkF4_8 == 9) && !fileProgressFlag_get(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE)) {
        this->yaw += this->unk1C[0];
        while(this->yaw >= 360.0f){
            this->yaw -= 360.0f;
        }
        this->unk1C[0] -= 0.089888;
        if (this->unk1C[0] < 0.0f) {
            this->unk1C[0] = 0.0f;
        }
        if (this->marker->unk14_21) {
            s32 sp58[3] = D_80394824;
            ParticleEmitter *sp54;
            sp54 = partEmitMgr_newEmitter(6);
            particleEmitter_setSprite(sp54, ASSET_710_SPRITE_SPARKLE_PURPLE);
            particleEmitter_setAlpha(sp54, 0xFF);
            particleEmitter_setScaleAndLifetimeRanges(sp54, &D_80394830);
            particleEmitter_setPosition(sp54, this->position);
            sp58[2] = randf() * 255.0f;
            particleEmitter_setRGB(sp54, sp58);
            particleEmitter_setSpawnPositionRange(sp54, -30.0f, -40.0f, -30.0f, 30.0f, 20.0f, 30.0f);
            particleEmitter_emitN(sp54, 6);
        }
    }
    controller_copyFaceButtons(0, sp7C);
    func_8024E60C(0, sp6C);
    func_8038EDBC(this);
    switch(this->state){
        case 1://L8038FCD0
            if (!this->has_met_before && (!func_8028F20C() || !func_8028FB48(0x08000000))) {
                this->has_met_before = TRUE;
            }
            if (func_80329530(this, 300)) {
                if ((this->unkF4_8 == 0xA) && !fileProgressFlag_get(FILEPROG_F6_SEEN_DOOR_OF_GRUNTY_PUZZLE_PODIUM)) {
                    phi_a0 = (item_getCount(ITEM_26_JIGGY_TOTAL) < D_803947F8[this->unkF4_8 - 1].cost) ? 0xFAB : 0xFC0;
                    if (gcdialog_showText(phi_a0, 0, NULL, NULL, NULL, NULL)) {
                        fileProgressFlag_set(FILEPROG_F6_SEEN_DOOR_OF_GRUNTY_PUZZLE_PODIUM, TRUE);
                    }
                } else if (this->unkF4_8 == 1) {
                    func_8035644C(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT);
                }
            }
            if (func_8038ECA8(this->marker) && this->has_met_before && !func_8038EB58(this) && (func_8028ECAC() == 0 || func_8028ECAC() == BSGROUP_8_TROT)) {
                func_8038F350(this, 2);
            }
            break;

        case 4: //L8038FE28
            if ((func_803114C4() != 0xF7C) && (func_803114C4() != 0xF7D)) {
                if (sp7C[FACE_BUTTON(BUTTON_A)] == 1) {
                    lair_func_8038F894(this, 5);
                } else if (sp7C[FACE_BUTTON(BUTTON_B)] == 1) {
                    func_8038F350(this, 1);
                } else if ((sp6C[SIDE_BUTTON(BUTTON_Z)] == 1) && fileProgressFlag_get(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES)) {
                    lair_func_8038F894(this, 6);
                } else if (sp7C[FACE_BUTTON(BUTTON_C_DOWN)] == 1) {
                    if (local->unk4) {
                        func_8038F350(this, 8);
                    } else {
                        comusic_playTrack(COMUSIC_2C_BUZZER);
                        func_8038F350(this, 1);
                    }
                }
            }
            break;

        case 5: //L8038FF00
        case 6: //L8038FF00
        case 8: //L8038FF00
            if (this->lifetime_value > 0.0f) {
                this->lifetime_value -= sp68;
            } else {
                func_8038F350(this, func_8038EB58(this) ? 7 :4);
            }
            break;

        case 7: //L8038FF50
            if (this->lifetime_value > 0.0f) {
                this->lifetime_value -= sp68;
            } else {
                func_8038F350(this, 1);
            }
            break;
    }

    {
        s32 pad;
        f32 sp44[3];
        s32 pad2;
        this->marker->unk3E_1 = FALSE;
        player_getPosition(sp44);
        if (ml_distanceSquared_vec3f(sp44, this->position) < 250000.0f) {
            if (!this->unk38_0) {
                itemPrint_reset();
                this->unk38_0 = TRUE;
            }
            func_802FACA4(0x2B);
        }
        else if (this->unk38_0) {
            func_802FAD64(0x2B);
            this->unk38_0 = FALSE;
        }
    }
}
