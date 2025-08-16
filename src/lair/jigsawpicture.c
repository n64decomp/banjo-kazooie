#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "jigsawpicture.h"

extern void player_walkToPosition(f32[3], f32, void(*)(ActorMarker *), ActorMarker *);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void rand_seed(s32);
extern void func_8034DF30(s32, f32[3], f32[3], f32);
extern void updateStruct6DsOpacity(s32, s32, s32,f32);

typedef struct {
    s32 placedPieces;
    s32 placedJiggyCount;
    s32 unk8;
} JigsawPictureActorData;

typedef struct {
    u8 cost;
    u8 sizeBits;
    u16 progressFlag; // enum file_progress_e
} JigsawPictureInfo;

void jigsawPicture_setState(Actor *this, s32 next_state);
void updateJigsawPictureActor(Actor *this);

/*
 * Jigsaw Podium Actors:
 *     actorTypeSpecificField: Basically an ID that corresponds to which picture it's for
 *     lifetime_value: Timeout for interacting with the picture
 */

/* .data */
// Seem to correspond to the two possible jigsaw pictures that can spawn in a map. 
// IE, in the first room, the first corresponds to MM. 
// In the second room, the first corresponds to CC and the second to TTC
ActorInfo JIGSAW_PICTURE_ACTOR = { 0x1EB, 0x3B7, 0x48B, 0x1, NULL, updateJigsawPictureActor, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};
ActorInfo JIGSAW_PICTURE_ACTOR_2 = { 0x1EB, 0x3BC, 0x538, 0x1, NULL, updateJigsawPictureActor, actor_update_func_80326224, actor_draw, 0, 0, 0.0f, 0};

JigsawPictureInfo PICTURE_INFO[0xB] ={
    { 1, 0x1, FILEPROG_5D_MM_PUZZLE_PIECES_PLACED },
    { 2, 0x2, FILEPROG_5E_TCC_PUZZLE_PIECES_PLACED },
    { 5, 0x3, FILEPROG_60_CC_PUZZLE_PIECES_PLACED },
    { 7, 0x3, FILEPROG_63_BGS_PUZZLE_PIECES_PLACED },
    { 8, 0x4, FILEPROG_66_FP_PUZZLE_PIECES_PLACED },
    { 9, 0x4, FILEPROG_6A_GV_PUZZLE_PIECES_PLACED },
    {10, 0x4, FILEPROG_6E_MMM_PUZZLE_PIECES_PLACED },
    {12, 0x4, FILEPROG_72_RBB_PUZZLE_PIECES_PLACED },
    {15, 0x4, FILEPROG_76_CCW_PUZZLE_PIECES_PLACED },
    {25, 0x5, FILEPROG_7A_DOG_PUZZLE_PIECES_PLACED },
    { 4, 0x3, FILEPROG_7F_DOUBLE_HEALTH_PUZZLE_PIECES_PLACED }
};
s32 D_80394824[3] = { 0xff, 0xff, 0 };
ParticleScaleAndLifetimeRanges D_80394830 = {
    { 0.17f, 0.24f },
    { 0.08f, 0.13f },
    { 0.0f, 0.01f },
    { 0.9f, 0.9f },
    0.0f,
    0.0f
};

/* .code */
bool jigsawPicture_isJigsawPictureComplete(s32 world) {
    return fileProgressFlag_getN(PICTURE_INFO[world - 1].progressFlag, PICTURE_INFO[world - 1].sizeBits) == PICTURE_INFO[world - 1].cost;
}

s32 getPictureCost(Actor *this) {
    // Check bounds of PICTURE_INFO
    return (this->actorTypeSpecificField != 0 && this->actorTypeSpecificField < 0xC) 
        ? PICTURE_INFO[this->actorTypeSpecificField - 1].cost : 0;
}

bool isPictureComplete(Actor *this) {
    JigsawPictureActorData *local;

    local = (JigsawPictureActorData*)&this->local;

    return getPictureCost(this) == local->placedJiggyCount;
}

s32 getLevelSpecificOpenFlag(Actor *this) {
    return this->actorTypeSpecificField + 0x1B; // MM starts at 1C
}

void activateDoubleHealth(void) {
    func_802FAFD4(ITEM_14_HEALTH, SFX_417_DOUBLE_HEALTH_UPGRADE);
    func_802FAFC0(ITEM_14_HEALTH, COMUSIC_2B_DING_B);
    fileProgressFlag_set(FILEPROG_B9_DOUBLE_HEALTH, TRUE);
    func_80347958();
    item_adjustByDiffWithHud(ITEM_14_HEALTH, 0);
    gcpausemenu_80314AC8(1);
}

void afterPictureComplete(ActorMarker *marker) {
    Actor *this;

    this = marker_getActor(reinterpret_cast(ActorMarker *, marker));

    // Normal world pictures
    if (this->actorTypeSpecificField < 0xA) {
        levelSpecificFlags_set(getLevelSpecificOpenFlag(this), TRUE);
        return;
    }

    // Final Grunty door
    if (this->actorTypeSpecificField == 0xA) {
        func_8028F918(0);
        func_8028F918(2);
        levelSpecificFlags_set(LEVEL_FLAG_3F_LAIR_GRUNTY_DOOR_OPEN, TRUE);
        return;
    }

    // Double health picture
    if (this->actorTypeSpecificField == 0xB) {
        timedFunc_set_0(1.5f, activateDoubleHealth);
        gcpausemenu_80314AC8(0);
    }
}

void onJigsawPodiumCollide(ActorMarker *marker, ActorMarker *_) {
    marker->isBanjoOnTop = TRUE;
}

bool isBanjoOnPodium(ActorMarker *marker) {
    return func_8028F20C() && func_8028FB48(0x08000000) && marker->isBanjoOnTop;
}

s32 isPicturePiecePlaced(Actor *this, s32 position) {
    JigsawPictureActorData *local;

    local = (JigsawPictureActorData*)&this->local;

    return local->placedPieces & (1 << position);
}

s32 jiggyPositionToID(Actor *this, s32 position) {
    s32 start;

    switch (this->actorTypeSpecificField) {
        case 7: // MMM
            start = (position == 2) ? 0x1a4 : 0x190;
            break;

        case 3: // CC
            start = 0x192;
            break;

        case 8: // RBB
            start = 0x19A;
            break;

        case 11: // Double health
            start = 0x1AE;
            break;

        default: 
            start = 0x190;
            break;
    }

    return start + position;
}

s32 getUnknownJigsawPictureIndex(Actor *this) {
    switch (this->actorTypeSpecificField) {
        case 3: // CC
        case 8: // RBB
        case 0xB: // Double health
            return 0x1F;
    }

    return 0x1E;
}

void func_8038EDBC(Actor *this) {
    s32 sp44;
    s32 sp40;
    JigsawPictureActorData *local;
    s32 sp38;
    f32 sp34;
    f32 sp28[3];

    local = (JigsawPictureActorData*)&this->local;
    sp38 = (this->modelCacheIndex == 0x3B7) ? 0x190 : 0x192;
    sp44 = func_8034C2C4(this->marker, sp38);
    sp40 = func_8034C2C4(this->marker, sp38 + 1);

    if ((sp44 != 0) && (sp40 != 0) && (this->marker->unk14_21)) {
        sp28[0] = 1.0f;
        sp28[1] = 1.0f;
        sp28[2] = 1.0f;

        if (isBanjoOnPodium(this->marker) && local->unk8 < 0xFF) {
            local->unk8 = (local->unk8 + 8 < 0xFF) ? local->unk8 + 8 : 0xFF;
        } else if (!isBanjoOnPodium(this->marker) && (local->unk8 > 0)) {
            local->unk8 = (local->unk8 - 8 > 0) ? local->unk8 - 8 : 0;
        }

        sp34 = (0xFF - local->unk8) / 255.0;
        func_8034DF30(sp44, sp28, sp28, 0);
        sp34 = 1.0 - sp34;
        func_8034DF30(sp40, sp28, sp28, 0);

        if (sp34); // Probably a debug assert
    }
}

void stoodOnPodiumCallback(ActorMarker *marker) {
    f32 camera_position[3];
    Actor *this;

    this = marker_getActor(marker);
    func_8034A174(func_803097A0(), getUnknownJigsawPictureIndex(this), camera_position);

    // Put Banjo into the idle animation
    func_8028E6EC(2);

    func_8028F918(0);
    func_8028F94C(4, camera_position);

    jigsawPicture_setState(this, 
        fileProgressFlag_get(FILEPROG_17_HAS_HAD_ENOUGH_JIGSAW_PIECES) ? JIGSAW_PICTURE_WAITING : JIGSAW_PICTURE_INSTRUCTIONS);
}

void walkToPodium(Actor *this) {
    s32 unused; // Can't remove ;.;
    f32 player_position[3];
    f32 target_position[3];

    this->has_met_before = FALSE;
    player_getPosition(player_position);
    target_position[0] = this->position[0];
    target_position[1] = this->position[1];
    target_position[2] = this->position[2];
    target_position[1] += 50.0f;

    player_walkToPosition(target_position, ml_vec3f_distance(player_position, target_position) / 150.0, stoodOnPodiumCallback, this->marker);
}

void bottlesInstructionsCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *this;

    this = marker_getActor(marker);

    // If this is the first picture, and the player has no jiggies, then force them to leave the podium
    jigsawPicture_setState(this, (text_id == ASSET_F58_DIALOG_FIRST_PICTURE_INSTRUCTION) ? JIGSAW_PICTURE_LEAVE_PODIUM : JIGSAW_PICTURE_WAITING);
}

void gruntyLaughCallback(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    func_8030E6D4(SFX_EA_GRUNTY_LAUGH_1);
}

// Deterministic-randomly returns the next piece that should be added or removed.
// 0 is the upper left continuing to 3 in the upper right, then wrapping around on the next row on the left side
s32 getPicturePiecePosition(Actor *this) {
    JigsawPictureActorData *local;
    s32 previous;
    s32 position;
    s32 i;

    previous = 0;
    local = (JigsawPictureActorData*)&this->local;

    // The places that pieces are placed is random, but it's deterministic based on the picture
    rand_seed(this->actorTypeSpecificField);

    // Final Grunty door or double health
    if (this->actorTypeSpecificField >= 0xA) {
        for (i = 0; i < local->placedJiggyCount; i++) {
            position = i;
            previous |= (1 << position);
        }
    } else {
        for (i = 0; i < local->placedJiggyCount; i++) {
            do {
                position = randi2(0, getPictureCost(this));
            } while ((1 << position) & previous);
            previous |= 1 << position; // Funny bitmath to ensure that the value is not the same as a preceding
        }
    }

    return position;
}

void addOrRemovePieceFromDisplay(Actor *this, s32 position, bool isAdd) {
    s32 piece = func_8034C528(jiggyPositionToID(this, position));

    if (piece != 0) {
        updateStruct6DsOpacity(piece, isAdd ? 0 : 0xFF, isAdd ? 0xFF : 0, 1.0f);
    }
}

void unlockAdditionalActions(Actor *this) {
    JigsawPictureActorData *local;

    local = (JigsawPictureActorData*)&this->local;
    if ((this->actorTypeSpecificField >= 2) // Trigger at TTC
        && (local->placedJiggyCount > 0) 
        && !isPictureComplete(this) 
        && !fileProgressFlag_get(FILEPROG_DF_CAN_REMOVE_ALL_PUZZLE_PIECES)) {

        if (gcdialog_showDialog(ASSET_F7C_DIALOG_BOTTLES_REMOVE_PIECE_INSTRUCTIONS, 2, NULL, NULL, NULL, NULL)) {
            fileProgressFlag_set(FILEPROG_DF_CAN_REMOVE_ALL_PUZZLE_PIECES, TRUE);
        }
    } else if ((this->actorTypeSpecificField >= 3) // Trigger at CC
        && (local->placedJiggyCount >= 2) // Trigger after the player put 2 jiggies in the picture
        && !isPictureComplete(this)
        && !fileProgressFlag_get(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES)) {

        if (gcdialog_showDialog(ASSET_F7D_DIALOG_BOTTLES_EXPLAINS_PLACE_ALL, 2, NULL, NULL, NULL, NULL)) {
            fileProgressFlag_set(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES, TRUE);
        }
    }
}

void jigsawPicture_setState(Actor *this, s32 nextState) {
    JigsawPictureActorData *local;
    f32 position[3];
    s32 jiggy_add_count;
    s32 piece_position;
    s32 i;

    local = (JigsawPictureActorData*)&this->local;
    func_8034A174(func_803097A0(), getUnknownJigsawPictureIndex(this), position);

    switch (nextState) {
        case JIGSAW_PICTURE_LEAVE_PODIUM:
            func_8028F918(0);
            break;

        case JIGSAW_PICTURE_ENTER_PODIUM:
            walkToPodium(this);
            sfx_playFadeShorthandDefault(SFX_112_TINKER_ATTENTION, 1.0f, 32000, this->position, 500, 1000);
            break;

        case JIGSAW_PICTURE_INSTRUCTIONS:
            func_803115C4(0xF7B);
            func_803115C4(0xF80);
            func_803115C4(0xF7F);

            if (item_getCount(ITEM_26_JIGGY_TOTAL) > 0) {
                gcdialog_showDialog(
                    fileProgressFlag_get(FILEPROG_16_STOOD_ON_JIGSAW_PODIUM) 
                        ? ASSET_F5A_DIALOG_FIRST_PICTURE_FIRST_PIECE_OBTAINED_AFTER 
                        : ASSET_F59_DIALOG_FIRST_PICTURE_FIRST_PIECE_ALREADY_OBTAINED, 
                    6, 
                    position, 
                    this->marker, 
                    bottlesInstructionsCallback, 
                    NULL);
                fileProgressFlag_set(FILEPROG_17_HAS_HAD_ENOUGH_JIGSAW_PIECES, 1);
            } else {
                gcdialog_showDialog(ASSET_F58_DIALOG_FIRST_PICTURE_INSTRUCTION, 6, position, this->marker, bottlesInstructionsCallback, NULL);
            }

            fileProgressFlag_set(FILEPROG_16_STOOD_ON_JIGSAW_PODIUM, 1);
            fileProgressFlag_set(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT, 1);
            break;

        case JIGSAW_PICTURE_REMOVE_PIECE:
            if (local->placedJiggyCount > 0) {
                comusic_playTrack(SFX_REMOVE_JIGGY);
                this->lifetime_value = 1.0f;
                piece_position = getPicturePiecePosition(this);
                addOrRemovePieceFromDisplay(this, piece_position, 0);
                local->placedJiggyCount--;
                local->placedPieces &= ~(1 << piece_position);
                fileProgressFlag_setN(PICTURE_INFO[this->actorTypeSpecificField - 1].progressFlag, local->placedJiggyCount, PICTURE_INFO[this->actorTypeSpecificField - 1].sizeBits);
                item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, 1);
            }
            break;

        case JIGSAW_PICTURE_ADD_PIECE:
            if (local->placedJiggyCount < getPictureCost(this)) {
                comusic_playTrack(COMUSIC_67_INSERTING_JIGGY);
                this->lifetime_value = 1.0f;
                local->placedJiggyCount++;
                piece_position = getPicturePiecePosition(this);
                addOrRemovePieceFromDisplay(this, piece_position, 1);
                local->placedPieces |= (1 << piece_position);
                fileProgressFlag_setN(PICTURE_INFO[this->actorTypeSpecificField - 1].progressFlag, local->placedJiggyCount, PICTURE_INFO[this->actorTypeSpecificField - 1].sizeBits);
                item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, -1);
                unlockAdditionalActions(this);
            }

            break;

        case JIGSAW_PICTURE_ADD_ALL:
            if (local->placedJiggyCount < getPictureCost(this)) {

                // Does the player have enough jiggies to add all? Get the amount left or how many they have
                if (item_getCount(ITEM_26_JIGGY_TOTAL) > getPictureCost(this) - local->placedJiggyCount) {
                    jiggy_add_count = getPictureCost(this) - local->placedJiggyCount;
                } else {
                    jiggy_add_count = item_getCount(ITEM_26_JIGGY_TOTAL);
                }

                comusic_playTrack(COMUSIC_67_INSERTING_JIGGY);
                this->lifetime_value = 1.0f;

                for (i = 0; i < jiggy_add_count; i++) {
                    local->placedJiggyCount++;
                    piece_position = getPicturePiecePosition(this);
                    addOrRemovePieceFromDisplay(this, piece_position, 1);
                    local->placedPieces |= (1 << piece_position);
                    item_adjustByDiffWithoutHud(ITEM_26_JIGGY_TOTAL, -1);
                }

                fileProgressFlag_setN(PICTURE_INFO[this->actorTypeSpecificField - 1].progressFlag, local->placedJiggyCount, PICTURE_INFO[this->actorTypeSpecificField - 1].sizeBits);
                unlockAdditionalActions(this);
            }

            break;

        case JIGSAW_PICTURE_COMPLETE:
            comusic_playTrack(COMUSIC_65_WORLD_OPENING_B);

            // If MM or the last Grunty door, make her cackle
            if (this->actorTypeSpecificField == 1) {
                func_80324DBC(1.0f, 0xF7E, 4, NULL, this->marker, gruntyLaughCallback, NULL);
            } else if (this->actorTypeSpecificField == 0xA) {
                func_80324DBC(1.0f, 0xFAC, 4, NULL, this->marker, gruntyLaughCallback, NULL);
            }

            timedFunc_set_1(2.0f, (GenFunction_1) afterPictureComplete, (s32) this->marker);
            this->lifetime_value = 3.0f;
            break;
    }

    subaddie_set_state(this, nextState);
}

void setInitialJigsawPictureOpacity(Actor *this) {
    s32 piece;
    s32 i;

    for (i = 0; i < getPictureCost(this); i++) {
        piece = func_8034C528(jiggyPositionToID(this, i));
        if (piece != 0) {
            setStruct6DsOpacity(piece, isPicturePiecePlaced(this, i) ? 0xff : 0);
        }
    }
}

void addPieces(Actor *this, s32 nextState) {

    // Does the player have any jiggies?
    if (item_getCount(ITEM_26_JIGGY_TOTAL) > 0) {

        // Transition to an add state
        jigsawPicture_setState(this, nextState);
        return;
    }

    comusic_playTrack(COMUSIC_2C_BUZZER);

    if (fileProgressFlag_get(FILEPROG_DE_USED_ALL_YOUR_PUZZLE_PIECES) != 0) {
        jigsawPicture_setState(this, JIGSAW_PICTURE_LEAVE_PODIUM);
        return;
    }

    // Bottles tells the player they need more jiggies, then sets flag; on future attempts it'll kick the player out
    gcdialog_showDialog(ASSET_FBC_DIALOG_BOTTLES_OUT_OF_JIGGIES, 4, NULL, NULL, NULL, NULL);
    fileProgressFlag_set(FILEPROG_DE_USED_ALL_YOUR_PUZZLE_PIECES, TRUE);
}

void updateJigsawPictureActor(Actor *this) {
    JigsawPictureActorData *local;
    s32 face_buttons[6];
    s32 i;
    s32 text_id;
    s32 side_buttons[2];
    f32 delta_time;
    s32 jiggiesPlaced;
  
    local = (JigsawPictureActorData*)&this->local;
    delta_time = time_getDelta();

    if (!this->initialized) {
        this->initialized = TRUE;
    }

    if (!this->volatile_initialized) {
        jiggiesPlaced = fileProgressFlag_getN(PICTURE_INFO[this->actorTypeSpecificField - 1].progressFlag, PICTURE_INFO[this->actorTypeSpecificField - 1].sizeBits);
        local->placedPieces = 0;
        local->placedJiggyCount = 0;
        local->unk8 = (isBanjoOnPodium(this->marker)) ? 0xFF : 1;
        this->has_met_before = TRUE;

        // Initialize which jiggies have been placed
        for (i = 0; i < jiggiesPlaced; i ++) {
            local->placedJiggyCount++;
            local->placedPieces |= (1 << getPicturePiecePosition(this));
        }

        setInitialJigsawPictureOpacity(this);
        marker_setCollisionScripts(this->marker, onJigsawPodiumCollide, NULL, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;

        // Click Clock Wood specific
        if (this->actorTypeSpecificField == 9) {
            this->unk1C[0] = 8.0f;

            // If the switch hasn't been pressed, then get rid of the podium
            if (!fileProgressFlag_get(FILEPROG_53_CCW_PUZZLE_PODIUM_SWITCH_PRESSED)) {
                marker_despawn(this->marker);
                return;
            }

            // Boring CCW podium activation
            if (!fileProgressFlag_get(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE)) {
                __bundle_spawnFromFirstActor(BUNDLE_20__UNKNOWN, this);
                func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 0x7FFF);
                func_80324D2C(2.1f, COMUSIC_43_ENTER_LEVEL_GLITTER);
                func_8030E6D4(SFX_113_PAD_APPEARS);
            }
        }
    }

    // CCW podium activation, when it's not specifically active from the sandcastle cheat
    if ((this->actorTypeSpecificField == 9) && !fileProgressFlag_get(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE)) {
        this->yaw += this->unk1C[0];

        while (this->yaw >= 360.0f) {
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

    controller_copyFaceButtons(0, face_buttons);
    controller_copySideButtons(0, side_buttons);
    func_8038EDBC(this);

    switch (this->state) {
        case JIGSAW_PICTURE_LEAVE_PODIUM:
            if (!this->has_met_before && (!func_8028F20C() || !func_8028FB48(0x08000000))) {
                this->has_met_before = TRUE;
            }

            if (subaddie_playerIsWithinSphereAndActive(this, 300)) {
                if ((this->actorTypeSpecificField == 0xA) && !fileProgressFlag_get(FILEPROG_F6_SEEN_DOOR_OF_GRUNTY_PUZZLE_PODIUM)) {
                    text_id = (item_getCount(ITEM_26_JIGGY_TOTAL) < PICTURE_INFO[this->actorTypeSpecificField - 1].cost) 
                        ? ASSET_FAB_DIALOG_GRUNTY_DOOR_NEED_JIGGIES : ASSET_FC0_DIALOG_GRUNTY_DOOR_HAVE_JIGGIES;
                    if (gcdialog_showDialog(text_id, 0, NULL, NULL, NULL, NULL)) {
                        fileProgressFlag_set(FILEPROG_F6_SEEN_DOOR_OF_GRUNTY_PUZZLE_PODIUM, TRUE);
                    }
                } else if (this->actorTypeSpecificField == 1) { // MM
                    progressDialog_showDialogMaskZero(FILEPROG_A7_NEAR_PUZZLE_PODIUM_TEXT);
                }
            }

            if (isBanjoOnPodium(this->marker) && this->has_met_before && !isPictureComplete(this) && (player_movementGroup() == BSGROUP_0_NONE || player_movementGroup() == BSGROUP_8_TROT)) {
                jigsawPicture_setState(this, JIGSAW_PICTURE_ENTER_PODIUM);
            }

            break;

        case JIGSAW_PICTURE_WAITING:
            if ((gcdialog_getCurrentTextId() != ASSET_F7C_DIALOG_BOTTLES_REMOVE_PIECE_INSTRUCTIONS) 
                && (gcdialog_getCurrentTextId() != ASSET_F7D_DIALOG_BOTTLES_EXPLAINS_PLACE_ALL)) {
                
                // Add piece
                if (face_buttons[FACE_BUTTON(BUTTON_A)] == TRUE) {
                    addPieces(this, JIGSAW_PICTURE_ADD_PIECE);

                // Leave Podium
                } else if (face_buttons[FACE_BUTTON(BUTTON_B)] == TRUE) {
                    jigsawPicture_setState(this, JIGSAW_PICTURE_LEAVE_PODIUM);

                // Add all pieces
                } else if ((side_buttons[SIDE_BUTTON(BUTTON_Z)] == TRUE) && fileProgressFlag_get(FILEPROG_E0_CAN_PLACE_ALL_PUZZLE_PIECES)) {
                    addPieces(this, JIGSAW_PICTURE_ADD_ALL);

                // Remove piece
                } else if (face_buttons[FACE_BUTTON(BUTTON_C_DOWN)] == TRUE) {
                    if (local->placedJiggyCount) {
                        jigsawPicture_setState(this, JIGSAW_PICTURE_REMOVE_PIECE);
                    } else { // No pieces to remove in picture, exit
                        comusic_playTrack(COMUSIC_2C_BUZZER);
                        jigsawPicture_setState(this, JIGSAW_PICTURE_LEAVE_PODIUM);
                    }
                }
            }
            break;

        case JIGSAW_PICTURE_ADD_PIECE:
        case JIGSAW_PICTURE_ADD_ALL:
        case JIGSAW_PICTURE_REMOVE_PIECE:
            if (this->lifetime_value > 0.0f) { // Wait for timeout
                this->lifetime_value -= delta_time;
            } else {
                jigsawPicture_setState(this, isPictureComplete(this) ? JIGSAW_PICTURE_COMPLETE : JIGSAW_PICTURE_WAITING);
            }

            break;

        case JIGSAW_PICTURE_COMPLETE:
            if (this->lifetime_value > 0.0f) { // Wait for timeout
                this->lifetime_value -= delta_time;
            } else {
                jigsawPicture_setState(this, JIGSAW_PICTURE_LEAVE_PODIUM);
            }

            break;
    }

    {
        s32 pad;
        f32 sp44[3];
        s32 pad2;
        this->marker->isBanjoOnTop = FALSE;
        player_getPosition(sp44);

        if (ml_distanceSquared_vec3f(sp44, this->position) < 250000.0f) {
            if (!this->unk38_0) {
                itemPrint_reset();
                this->unk38_0 = TRUE;
            }

            func_802FACA4(0x2B);
        } else if (this->unk38_0) {
            func_802FAD64(0x2B);
            this->unk38_0 = FALSE;
        }
    }
}
