#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"


/* extern */
extern void func_802D6310(f32, enum map_e, s32, s32, enum file_progress_e);
extern BKModel *mapModel_getModel(s32);

extern u8 gCompletedBottleBonusGames[7];

/* .h */
static void __maCastle_resetSecretCheatCodeProgress(void);
static u32 __maCastle_scrambleAddressForSecretCheatCode();

typedef struct
{
    u8 *code;
    u8 codeCharacterIdx;
    u8 id;
    s16 unk6; // unused
} SecretCheatCode;

typedef struct
{
    u8 *code; // string of code where the hex value of floor_letters_e is converted into a char
    s16 flagBitMask;
    s16 codeCharacterIdx; 
} CheatCode;

typedef struct
{
    s16 meshId;
    u8 letter; // floor_letters_e
    u8 state; // some sort of state, 1 - 5
    f32 timeDeltaSum;
} LetterFloorTile;

typedef struct
{
    s16 minId;
    s16 maxId;
} BannedCheatCodeRange;

static s32 __maCastle_getNumberOfBannedCheatCodesEntered();

/* .data */
static s32 sSecretCheatCodeRelatedValue = NULL;

enum floor_letters_e {
    FLOOR_LETTER_J = 0x70,
    FLOOR_LETTER_G = 0x35,
    FLOOR_LETTER_A = 0x6E,
    FLOOR_LETTER_L = 0x62,
    FLOOR_LETTER_V = 0x61,
    FLOOR_LETTER_E = 0x6A,
    FLOOR_LETTER_C = 0x30,
    FLOOR_LETTER_M = 0x31,
    FLOOR_LETTER_N = 0x69,
    FLOOR_LETTER_R = 0x39,
    FLOOR_LETTER_P = 0x72,
    FLOOR_LETTER_D = 0x6C,
    FLOOR_LETTER_O = 0x36,
    FLOOR_LETTER_S = 0x32,
    FLOOR_LETTER_Z = 0x33,
    FLOOR_LETTER_U = 0x67,
    FLOOR_LETTER_Y = 0x65,
    FLOOR_LETTER_I = 0x34,
    FLOOR_LETTER_X = 0x68,
    FLOOR_LETTER_T = 0x64,
    FLOOR_LETTER_F = 0x63,
    FLOOR_LETTER_W = 0x37,
    FLOOR_LETTER_H = 0x6D,
    FLOOR_LETTER_B = 0x6B,
    FLOOR_LETTER_K = 0x38
};

/**
 * The floor tiles look like this (_ being empty):
 * J _ G _ A _ L
 * _ V _ E _ C _
 * M _ N _ R _ P
 * _ D _ O _ S _
 * Z _ U _ Y _ I
 * _ X _ T _ F _
 * O _ A _ W _ O
 * _ H _ B _ K _
 */
static LetterFloorTile sLetterFloorTiles[] = {
    {0x02, FLOOR_LETTER_J, 0, 0.0f}, 
    {0x04, FLOOR_LETTER_G, 0, 0.0f}, 
    {0x06, FLOOR_LETTER_A, 0, 0.0f}, 
    {0x08, FLOOR_LETTER_L, 0, 0.0f}, 
    {0x0A, FLOOR_LETTER_V, 0, 0.0f}, 
    {0x0C, FLOOR_LETTER_E, 0, 0.0f}, 
    {0x0E, FLOOR_LETTER_C, 0, 0.0f}, 
    {0x10, FLOOR_LETTER_M, 0, 0.0f}, 
    {0x12, FLOOR_LETTER_N, 0, 0.0f}, 
    {0x14, FLOOR_LETTER_R, 0, 0.0f}, 
    {0x16, FLOOR_LETTER_P, 0, 0.0f}, 
    {0x18, FLOOR_LETTER_D, 0, 0.0f}, 
    {0x1A, FLOOR_LETTER_O, 0, 0.0f}, 
    {0x1C, FLOOR_LETTER_S, 0, 0.0f}, 
    {0x1E, FLOOR_LETTER_Z, 0, 0.0f}, 
    {0x20, FLOOR_LETTER_U, 0, 0.0f}, 
    {0x22, FLOOR_LETTER_Y, 0, 0.0f}, 
    {0x24, FLOOR_LETTER_I, 0, 0.0f}, 
    {0x26, FLOOR_LETTER_X, 0, 0.0f}, 
    {0x28, FLOOR_LETTER_T, 0, 0.0f}, 
    {0x2A, FLOOR_LETTER_F, 0, 0.0f}, 
    {0x2C, FLOOR_LETTER_O, 0, 0.0f}, 
    {0x2E, FLOOR_LETTER_A, 0, 0.0f}, 
    {0x30, FLOOR_LETTER_W, 0, 0.0f}, 
    {0x32, FLOOR_LETTER_O, 0, 0.0f}, 
    {0x34, FLOOR_LETTER_H, 0, 0.0f}, 
    {0x36, FLOOR_LETTER_B, 0, 0.0f}, 
    {0x38, FLOOR_LETTER_K, 0, 0.0f}, 
    {NULL, NULL, NULL, NULL}
};

static CheatCode sCheatCodes[0xD] = {
    {"knip68n3664j",        0x0001, 0}, // BANJOKAZOOIE
    {"kbgjj552",            0x0002, 0}, // BLUEEGGS
    {"9jlcjndmj92",         0x0004, 0}, // REDFEATHERS
    {"56blcjndmj92",        0x0008, 0}, // GOLDFEATHERS
    {"k6ddbj2k6ig26ij",     0x0010, 0}, // BOTTLESBONUSONE
    {"k6ddbj2k6ig2d76",     0x0020, 0}, // BOTTLESBONUSTWO
    {"k6ddbj2k6ig2dm9jj",   0x0040, 0}, // BOTTLESBONUSTHREE
    {"k6ddbj2k6ig2c6g9",    0x0080, 0}, // BOTTLESBONUSFOUR
    {"k6ddbj2k6ig2c4aj",    0x0100, 0}, // BOTTLESBONUSFIVE
    {"k45k6ddbj2k6ig2",     0x0200, 0}, // BIGBOTTLESBONUS
    {"742me7n2meknip6",     0x0400, 0}, // WISHYWASHYBANJO
    {"i6k6ig2",             0x0800, 0}, // NOBONUS
    NULL
};

struct
{
    BKModel *model1;
    BKModel *model2;
    u8 banjoKazooieCodeEnteredState; // 0 = BK code not entered, 2 = BK code entered, 3 = jiggy collected
    u8 doorOpeningSfxSourceIdx;
    u8 dullCannonShotSfxSourceId;
    u8 padB[1];
    f32 unkC; // time in map?
    u8 timerState; // 0 = nothing, 1 = timer running, 2 = no timer required / time trial completed
} sMapState;

/* .code */
static void __maCastle_transformMeshCallbackOverlayUpdate(s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2)
{
    vtx->v.ob[1] += 2;
}

static void __maCastle_transformMeshCallbackOverlayInit(s32 arg0, BKVtxRef *vtx_ref, Vtx *vtx, s32 arg2)
{
    vtx->v.ob[1] += 0xf0;
}

static void __maCastle_setupCheatCodeTimer(s32 new_timer_state)
{
    if (new_timer_state == 1)
    {
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        {
            // set timer to 50 seconds
            item_set(ITEM_0_HOURGLASS_TIMER, 2999);
        }
        else
        {
            // set timer to 100 seconds
            item_set(ITEM_0_HOURGLASS_TIMER, 5999);
        }

        item_set(ITEM_6_HOURGLASS, TRUE);
    }

    if (sMapState.timerState == 1)
    {
        item_set(ITEM_6_HOURGLASS, FALSE);
    }

    sMapState.timerState = new_timer_state;
}

static LetterFloorTile* __maCastle_getFloorTileForMeshId(s32 mesh_id)
{
    LetterFloorTile *i_ptr;

    for (i_ptr = sLetterFloorTiles; i_ptr->meshId != NULL; i_ptr++)
    {
        if (i_ptr->meshId == mesh_id)
        {
            return i_ptr;
        }
    }

    return NULL;
}

static void __maCastle_initFloorTiles(void)
{
    LetterFloorTile *i_ptr;

    for (i_ptr = sLetterFloorTiles; i_ptr->meshId != 0; i_ptr++)
    {
        i_ptr->state = 2;
        i_ptr->timeDeltaSum = 0.0f;
    }

    mapSpecificFlags_set(TTC_SPECIFIC_FLAG_1_UNKNOWN, FALSE);
}

static void __maCastle_meshCallbackFloorTileState_1(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3)
{
    LetterFloorTile *ptr = (LetterFloorTile *)arg3;
    f32 temp_f2;

    if (ptr->timeDeltaSum < 0.5)
    {
        temp_f2 = (ptr->timeDeltaSum / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = ref->v.v.cn[1] * temp_f2;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else
    {
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->state = 2;
    }
}

static void __maCastle_setLetterFloorTileState(LetterFloorTile *arg0, s32 arg1)
{
    s32 temp_v0;

    temp_v0 = arg0->state;
    arg0->state = arg1;
    arg0->timeDeltaSum = 0.0f;
    if ((arg1 == 1) && (temp_v0 != arg1))
    {
        func_8025A6EC(COMUSIC_2C_BUZZER, 32000);
    }
}

static void __maCastle_meshCallbackFloorTileState_3(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3)
{
    LetterFloorTile *ptr = (LetterFloorTile *)arg3;
    f32 temp_f12;

    if (ptr->timeDeltaSum <= 0.5)
    {
        temp_f12 = (ptr->timeDeltaSum / 0.5);
        dst->v.cn[0] = ref->v.v.cn[0] * (1.0f - temp_f12);
        dst->v.cn[1] = 0xFF;
        dst->v.cn[2] = ref->v.v.cn[2] * (1.0f - temp_f12);
    }
    if (ptr->timeDeltaSum >= 0.5)
    {
        ptr->state = 4;
    }
}

static void __maCastle_meshCallbackFloorTileState_5(s32 arg0, BKVtxRef *ref, Vtx *dst, s32 arg3)
{
    LetterFloorTile *ptr = (LetterFloorTile *)arg3;
    f32 temp_f2;

    if (ptr->timeDeltaSum < 0.5)
    {
        temp_f2 = (ptr->timeDeltaSum / 0.5);
        dst->v.cn[0] = (ref->v.v.cn[0] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[1] = (ref->v.v.cn[1] - 0xFF) * temp_f2 + 255.0f;
        dst->v.cn[2] = ref->v.v.cn[2] * temp_f2;
    }
    else
    {
        dst->v.cn[0] = ref->v.v.cn[0];
        dst->v.cn[1] = ref->v.v.cn[1];
        dst->v.cn[2] = ref->v.v.cn[2];
        ptr->state = 2;
    }
}

static void __maCastle_updateTimeDeltaSumForFloorTiles()
{
    f32 time_delta;
    LetterFloorTile *floor_tile;

    time_delta = time_getDelta();
    for (floor_tile = sLetterFloorTiles; floor_tile->meshId != 0; floor_tile++)
    {
        floor_tile->timeDeltaSum += time_delta;
        if (floor_tile->state == 1)
        {
            BKModel_transformMesh(sMapState.model1, floor_tile->meshId, __maCastle_meshCallbackFloorTileState_1, (s32)floor_tile);
        }
        else if (floor_tile->state == 3)
        {
            BKModel_transformMesh(sMapState.model1, floor_tile->meshId, __maCastle_meshCallbackFloorTileState_3, (s32)floor_tile);
        }
        else if (floor_tile->state == 5)
        {
            BKModel_transformMesh(sMapState.model1, floor_tile->meshId, __maCastle_meshCallbackFloorTileState_5, (s32)floor_tile);
        }
    }
}

static void __maCastle_setsecretCheatCodeRelatedValue(void)
{
    sSecretCheatCodeRelatedValue = __maCastle_scrambleAddressForSecretCheatCode();
}

static u32 __maCastle_cheatoCodeUnlocked(s32 cheato_code_index)
{
    if (fileProgressFlag_get(FILEPROG_AD_CHEATO_BLUEEGGS_UNLOCKED + cheato_code_index - 1))
    {
        return 1 << cheato_code_index;
    }

    return 0;
}

static void __maCastle_setVolatileFlags(u32 arg0)
{
    int i;
    volatileFlag_setAndTriggerDialog_0(VOLATILE_FLAG_C2_NOBONUS_TEXT);
    // wish washy banjo cheat code
    if (arg0 & 0x400)
    {
        volatileFlag_setAndTriggerDialog_E(VOLATILE_FLAG_C5_WISHYWASHYBANJO_TEXT);
    }
    volatileFlag_set(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS, 0);
    for (i = 4; i < 11; i++)
    {
        if (arg0 & (1 << i))
        {
            volatileFlag_set(VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + i, TRUE);
            volatileFlag_set(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS, TRUE);
        }
        else
        {
            volatileFlag_set(VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + i, FALSE);
        }
    }
}

static void __maCastle_checkFloorTileForRegularCheatCode(LetterFloorTile *letter_floor_tile)
{
    s32 pad0[4];

    bool floor_is_valid_or_correct;
    bool is_in_ff_minigame;
    s32 i;
    u32 var_v0;
    CheatCode *cheatcode_ptr;
    s32 unlocked_cheat_flags;
    bool is_correct_input;

    is_in_ff_minigame = volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME);
    is_correct_input = FALSE;
    floor_is_valid_or_correct = __maCastle_isFloorTileValidForSecretCheatCode(letter_floor_tile);
    for (cheatcode_ptr = sCheatCodes; cheatcode_ptr->code != NULL; cheatcode_ptr++)
    {
        unlocked_cheat_flags = (sMapState.banjoKazooieCodeEnteredState == 0) ? 1 : 0;
        if (!is_in_ff_minigame)
        {
            for (i = 1; i < 4; i++)
            {
                unlocked_cheat_flags |= __maCastle_cheatoCodeUnlocked(i);
            }

            for (i = 0; i < 7; i++)
            {
                if (gCompletedBottleBonusGames[i] != 0)
                {
                    unlocked_cheat_flags |= (0x10 << i);
                }
            };
            if (volatileFlag_get(VOLATILE_FLAG_78_SANDCASTLE_NO_BONUS))
            {
                unlocked_cheat_flags |= 0x800;
            }
        }
        if (cheatcode_ptr->flagBitMask & unlocked_cheat_flags)
        {
            if (__maCastle_isCurrentSecretCheatCodeCharacter0() && !is_in_ff_minigame)
            {
                cheatcode_ptr->codeCharacterIdx = 0;
                __maCastle_setupCheatCodeTimer(2);
            }
            if (letter_floor_tile->letter == cheatcode_ptr->code[cheatcode_ptr->codeCharacterIdx])
            {
                is_correct_input = TRUE;
                cheatcode_ptr->codeCharacterIdx++;
                if (__maCastle_isCurrentSecretCheatCodeCharacter0())
                {
                    cheatcode_ptr->codeCharacterIdx = 0;
                }
                else
                {
                    // is not banjo kazooie
                    if (cheatcode_ptr->flagBitMask & 0xFFE)
                    {
                        __maCastle_setupCheatCodeTimer(2);
                        __maCastle_setLetterFloorTileState(letter_floor_tile, 5);
                    }
                    else
                    {
                        __maCastle_setLetterFloorTileState(letter_floor_tile, 3);
                    }
                    if (cheatcode_ptr->code[cheatcode_ptr->codeCharacterIdx] == 0)
                    {
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 32000);

                        if (is_in_ff_minigame)
                        {
                            item_set(ITEM_6_HOURGLASS, FALSE);
                            volatileFlag_set(VOLATILE_FLAG_3, 0);
                            volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, 1);
                            __maCastle_setupCheatCodeTimer(2);
                        }
                        else
                        {
                            var_v0 = cheatcode_ptr->flagBitMask;
                            // banjokazooie check
                            if (var_v0 & 1)
                            {
                                sMapState.banjoKazooieCodeEnteredState = 2;
                                sMapState.unkC = 0.0f;
                                mapSpecificFlags_set(TTC_SPECIFIC_FLAG_1_UNKNOWN, TRUE);
                                fileProgressFlag_set(FILEPROG_FA_UNKNOWN, TRUE);
                                func_8030E2C4(sMapState.doorOpeningSfxSourceIdx);
                                __maCastle_setupCheatCodeTimer(2);
                            }
                            // blue eggs & red/gold feathers check
                            else if (var_v0 & 0xE)
                            {
                                // trigger dialog
                                func_8035644C((cheatcode_ptr - sCheatCodes) - 1 + FILEPROG_BE_CHEATO_BLUEEGGS);
                                switch ((cheatcode_ptr - sCheatCodes) - 1)
                                {
                                    default:
                                        break;
                                    case 0:
                                        item_setMaxCount(ITEM_D_EGGS);
                                        func_802FAFAC(ITEM_D_EGGS, COMUSIC_C_EGG_COLLECTED);
                                        break;
                                    case 1:
                                        item_setMaxCount(ITEM_F_RED_FEATHER);
                                        func_802FAFAC(ITEM_F_RED_FEATHER, COMUSIC_B_RED_FEATHER_COLLECTED);
                                        break;
                                    case 2:
                                        item_setMaxCount(ITEM_10_GOLD_FEATHER);
                                        func_802FAFAC(ITEM_10_GOLD_FEATHER, COMUSIC_14_GOLD_FEATHER_COLLECTED);
                                        break;
                                }
                            }
                            // bottle bonus / wishy washy banjo / nobonus
                            else if (var_v0 & 0xFF0)
                            {
                                __maCastle_setVolatileFlags(var_v0);
                            }
                        }
                    }
                    else
                    {
                        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
                    }
                }
            }
            else if (floor_is_valid_or_correct != FALSE)
            {
                is_correct_input = TRUE;
            }
        }
    }
    if ((__maCastle_isCurrentSecretCheatCodeCharacter0() == FALSE) && (is_correct_input == FALSE) && (sMapState.banjoKazooieCodeEnteredState == 0))
    {
        __maCastle_setLetterFloorTileState(letter_floor_tile, 1);
    }
}

static void __maCastle_resetCheatCodeProgress(void)
{
    CheatCode *iPtr;

    for (iPtr = sCheatCodes; iPtr->code != NULL; iPtr++)
    {
        iPtr->codeCharacterIdx = 0;
    }

    if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        strcpy(sCheatCodes[0].code, "j4663n86pink"); // EIOOZAKOJNAB
    else
        strcpy(sCheatCodes[0].code, "knip68n3664j"); // BANJOKAZOOIE

    __maCastle_resetSecretCheatCodeProgress();
}

void maCastle_release(void) {
    if (sMapState.model1) {
        __maCastle_setupCheatCodeTimer(0);
        sfxsource_freeSfxsourceByIndex(sMapState.doorOpeningSfxSourceIdx);
        sfxsource_freeSfxsourceByIndex(sMapState.dullCannonShotSfxSourceId);
    }
}

void maCastle_init(void)
{
    void *sp2C;
    void *sp28;

    if( map_get() == MAP_7_TTC_TREASURE_TROVE_COVE
        && levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN)
    ){
        sp2C = func_8034C5AC(0x12C);
        if (sp2C)
        {
            func_8034E71C(sp2C, -600, 0.0f);
        }
    }
    sMapState.model1 = 0;
    if (map_get() != MAP_A_TTC_SANDCASTLE)
    {
        __maCastle_setsecretCheatCodeRelatedValue();
    }
    else
    {
        sp2C = func_8034C5AC(0x131);
        sp28 = func_8034C5AC(0x12C);
        if (levelSpecificFlags_get(LEVEL_FLAG_5_TTC_UNKNOWN)) {
            func_8034E71C(sp2C, -500, 10.0f);
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(0.0f, 1);
            timed_exitStaticCamera(2.0f);
            func_80324E38(2.0f, 0);
            func_803228D8();
            timedFunc_set_3(2.0f, (GenFunction_3)func_802E4078, MAP_7_TTC_TREASURE_TROVE_COVE, 1, 0);
        }
        else if (levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN) || volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
            func_8034E71C(sp2C, -500, 0.0f);
        }
        else {
            func_8034E71C(sp28, -500, 0.0f);
        } // L8038B1EC

        sMapState.model1 = mapModel_getModel(0);
        sMapState.model2 = mapModel_getModel(1);
        sMapState.banjoKazooieCodeEnteredState = 0;
        sMapState.timerState = 0;
        sMapState.unkC = 0.0f;

        sMapState.doorOpeningSfxSourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_playSfxAtVolume(sMapState.doorOpeningSfxSourceIdx, 0.1f);
        sfxsource_setSfxId(sMapState.doorOpeningSfxSourceIdx, SFX_3EC_CCW_DOOR_OPENING);
        func_8030DD14(sMapState.doorOpeningSfxSourceIdx, 3);
        sfxsource_setSampleRate(sMapState.doorOpeningSfxSourceIdx, 28000);

        sMapState.dullCannonShotSfxSourceId = sfxsource_createSfxsourceAndReturnIndex();
        sfxsource_setSfxId(sMapState.dullCannonShotSfxSourceId, SFX_3_DULL_CANNON_SHOT);
        func_8030DD14(sMapState.dullCannonShotSfxSourceId, 3);
        sfxsource_setSampleRate(sMapState.dullCannonShotSfxSourceId, 0x7fff);
        __maCastle_initFloorTiles();
        __maCastle_resetCheatCodeProgress();

        if (jiggyscore_isCollected(JIGGY_10_TTC_SANDCASTLE) && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        {
            BKModel_transformMesh(sMapState.model2, 0x3C, __maCastle_transformMeshCallbackOverlayInit, 0);
            sMapState.banjoKazooieCodeEnteredState = 3;
        }
        __maCastle_setsecretCheatCodeRelatedValue();
        __maCastle_resetSecretCheatCodeProgress();
    }
}

void maCastle_update(void)
{
    f32 player_position[3];
    s32 mesh_id_closest_to_player;
    f32 time_delta;
    u8 temp_v0;
    LetterFloorTile *floor_tile;

    time_delta = time_getDelta();
    if (__maCastle_getNumberOfBannedCheatCodesEntered() == 3)
    {
        func_802C5A3C(-1);
    }
    if (sMapState.model1 != 0)
    {
        __maCastle_updateTimeDeltaSumForFloorTiles();
        player_getPosition(player_position);
        if ((sMapState.timerState == 0) && volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) && volatileFlag_get(VOLATILE_FLAG_3))
        {
            __maCastle_setupCheatCodeTimer(1);
        }
        // timer has run out
        if ((sMapState.timerState == 1) && item_empty(ITEM_0_HOURGLASS_TIMER))
        {
            __maCastle_setupCheatCodeTimer(2);
            if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
            {
                volatileFlag_set(VOLATILE_FLAG_3, FALSE);
                volatileFlag_set(VOLATILE_FLAG_5_FF_MINIGAME_WON, FALSE);
            }
            else
            {
                func_8028F66C(BS_INTR_F);
            }
        }
        if ((sMapState.banjoKazooieCodeEnteredState == 0) || (sMapState.banjoKazooieCodeEnteredState == 3))
        {
            if ((levelSpecificFlags_get(LEVEL_FLAG_2_TTC_UNKNOWN) || volatileFlag_get(VOLATILE_FLAG_3)) && (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) && func_8028F20C())
            {
                mesh_id_closest_to_player = func_8033F3C0(sMapState.model1, player_position);
                if (mesh_id_closest_to_player != 0)
                {
                    floor_tile = __maCastle_getFloorTileForMeshId(mesh_id_closest_to_player);
                    if ((floor_tile != NULL) && ((floor_tile->state == 2) || (sMapState.banjoKazooieCodeEnteredState == 3)))
                    {
                        __maCastle_checkFloorTileForRegularCheatCode(floor_tile);
                        if ((sMapState.banjoKazooieCodeEnteredState == 0) && (sMapState.timerState == 0) && (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) == 0))
                        {
                            __maCastle_setupCheatCodeTimer(1);
                        }
                    }
                }
            }
        }
        else if (sMapState.banjoKazooieCodeEnteredState == 2)
        {
            sMapState.unkC = (f32)(sMapState.unkC + time_delta);
            BKModel_transformMesh(sMapState.model2, 0x3C, __maCastle_transformMeshCallbackOverlayUpdate, 0);
            if (sMapState.unkC > 4.0f)
            {
                sMapState.banjoKazooieCodeEnteredState = 3;
                func_8030E2C4(sMapState.dullCannonShotSfxSourceId);
                func_8030E394(sMapState.doorOpeningSfxSourceIdx);
            }
        }
    }
}

// is used to determine whether to spawn the crab or not
bool maCastle_hasBanjoKazooieCodeBeenEntered(void)
{
    return NOT(sMapState.banjoKazooieCodeEnteredState < 2);
}

static s32 sThirdForbiddenSecretCheatCodeIndex = NULL;

#define VOLATILE_FLAG_CHEAT_OFFSET 0x14

static SecretCheatCode sSecretsCheatCodes[] = {
    // CHEAT
    {"0mjnd", 0, 0x00, 00},

    // NOW BANJO WILL BE ABLE TO SEE IT ON NABNUTS TABLE
    {"i67knip674bbkjnkbjd62jj4d6iinkigd2dnkbj", 0, 0x01, 00},

    // THIS SECRET YOULL BE GRABBIN IN THE CAPTAINS CABIN
    {"dm422j09jde6gbbkj59nkk4i4idmj0nrdn4i20nk4i", 0, 0x02, 00},

    // AMIDST THE HAUNTED GLOOM A SECRET IN THE BATHROOM
    {"n14l2ddmjmngidjl5b661n2j09jd4idmjkndm9661", 0, 0x03, 00},

    // A DESERT DOOR OPENS WIDE ANCIENT SECRETS WAIT INSIDE
    {"nlj2j9dl6696rji274ljni04jid2j09jd27n4d4i24lj", 0, 0x04, 00},

    // OUT OF THE SEA IT RISES TO REVEAL MORE SECRET PRIZES
    {"6gd6cdmj2jn4d942j2d69jajnb169j2j09jdr943j2", 0, 0x05, 00},

    // DONT YOU GO AND TELL HER ABOUT THE SECRET IN HER CELLAR
    {"l6ide6g56nildjbbmj9nk6gddmj2j09jd4imj90jbbn9", 0, 0x06, 00},

    // NOW YOU CAN SEE A NICE ICE KEY WHICH YOU CAN HAVE FOR FREE
    {"i67e6g0ni2jjni40j40j8je7m40me6g0nimnajc69c9jj", 0, 0x07, 00},

    // GO RIGHT ON THROUGH NOTE DOOR TWO
    {"56945md6idm96g5mi6djl669d76", 0, VOLATILE_FLAG_66_SANDCASTLE_OPEN_DOOR_TWO + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // NOTE DOOR THREE GET IN FOR FREE
    {"i6djl669dm9jj5jd4ic69c9jj", 0, VOLATILE_FLAG_67_SANDCASTLE_OPEN_DOOR_THREE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // TAKE A TOUR THROUGH NOTE DOOR FOUR
    {"dn8jnd6g9dm96g5mi6djl669c6g9", 0, VOLATILE_FLAG_68_SANDCASTLE_OPEN_DOOR_FOUR + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // USE THIS CHEAT NOTE DOOR FIVE IS BEAT
    {"g2jdm420mjndi6djl669c4aj42kjnd", 0, VOLATILE_FLAG_69_SANDCASTLE_OPEN_DOOR_FIVE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THIS TRICKS USED TO OPEN NOTE DOOR SIX
    {"dm42d94082g2jld66rjii6djl66924h", 0, VOLATILE_FLAG_6A_SANDCASTLE_OPEN_DOOR_SIX + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE SEVENTH NOTE DOOR IS NOW NO MORE
    {"dmj2jajidmi6djl66942i67i6169j", 0, VOLATILE_FLAG_6B_SANDCASTLE_OPEN_DOOR_SEVEN + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOU CAN GET WET FEET NOW CLANKERS JIGGY IS COMPLETE
    {"e6g0ni5jd7jdcjjdi670bni8j92p455e42061rbjdj", 0, VOLATILE_FLAG_6C_SANDCASTLE_PUZZLE_COMPLETE_CC + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE JIGGYS FULL OFF YOU STOMP IN TO DINGY BUBBLEGLOOP SWAMP
    {"dmjp455e2cgbb6cce6g2d61r4id6l4i5ekgkkbj5b66r27n1r", 0, VOLATILE_FLAG_6D_SANDCASTLE_PUZZLE_COMPLETE_BGS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE JIGGYS DONE SO OFF YOU GO INTO FREEZEEZY PEAK AND ITS SNOW
    {"dmjp455e2l6ij266cce6g564id6c9jj3jj3erjn8nil4d22i67", 0, VOLATILE_FLAG_6E_SANDCASTLE_PUZZLE_COMPLETE_FP + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // GOBIS JIGGY IS NOW DONE TREK ON IN AND GET SOME SUN
    {"56k42p455e42i67l6ijd9j86i4inil5jd261j2gi", 0, VOLATILE_FLAG_6F_SANDCASTLE_PUZZLE_COMPLETE_GV + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE JIGGYS NOW MADE WHOLE INTO THE MANSION YOU CAN STROLL
    {"dmjp455e2i671nlj7m6bj4id6dmj1ni246ie6g0ni2d96bb", 0, VOLATILE_FLAG_70_SANDCASTLE_PUZZLE_COMPLETE_MMM + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE JIGGYS DONE SO TAKE A TRIP ON TO THE RUSTY BUCKET SHIP
    {"dmjp455e2l6ij26dn8jnd94r6id6dmj9g2dekg08jd2m4r", 0, VOLATILE_FLAG_71_SANDCASTLE_PUZZLE_COMPLETE_RBB + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // CLICK CLOCK WOOD IS LOTS OF FUN GO ON IN THE JIGGYS DONE
    {"0b4080b608766l42b6d26ccgi566i4idmjp455e2l6ij", 0, VOLATILE_FLAG_72_SANDCASTLE_PUZZLE_COMPLETE_CCC + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // LOTS OF GOES WITH MANY BANJOS
    {"b6d26c56j274dm1nieknip62", 0, VOLATILE_FLAG_73_SANDCASTLE_INFINITE_LIVES + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // BANJO BEGS FOR PLENTY OF EGGS
    {"knip6kj52c69rbjide6cj552", 0, VOLATILE_FLAG_74_SANDCASTLE_INFINITE_EGGS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // NOW YOU CAN FLY HIGH IN THE SKY
    {"i67e6g0nicbem45m4idmj28e", 0, VOLATILE_FLAG_75_SANDCASTLE_INFINITE_RED_FEATHERS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // A GOLDEN GLOW TO PROTECT BANJO
    {"n56blji5b67d6r96dj0dknip6", 0, VOLATILE_FLAG_76_SANDCASTLE_INFINITE_GOLD_FEATHERS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // BOTH PIPES ARE THERE TO CLANKERS LAIR
    {"k6dmr4rj2n9jdmj9jd60bni8j92bn49", 0, VOLATILE_FLAG_7D_SANDCASTLE_RAISE_PIPES_TO_CC + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOULL CEASE TO GRIPE WHEN UP GOES A PIPE
    {"e6gbb0jn2jd6594rj7mjigr56j2nr4rj", 0, VOLATILE_FLAG_7E_SANDCASTLE_RAISE_PIPE_TO_BRENTILDA + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THERES NOWHERE DANKER THAN IN WITH CLANKER
    {"dmj9j2i67mj9jlni8j9dmni4i74dm0bni8j9", 0, VOLATILE_FLAG_7F_SANDCASTLE_OPEN_CC + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOULL BE AMAZED NOW THE SWAMP PICCY GRILLE IS RAISED
    {"e6gbbkjn1n3jli67dmj27n1rr400e594bbj429n42jl", 0, VOLATILE_FLAG_80_SANDCASTLE_REMOVE_GRILL_NEAR_BGS_JIGGY + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // DONT DESPAIR THE TREE JIGGY PODIUM IS NOW THERE
    {"l6idlj2rn49dmjd9jjp455er6l4g142i67dmj9j", 0, VOLATILE_FLAG_81_SANDCASTLE_CCC_JIGGY_PODIUM + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // SHES AN UGLY BAT SO LETS REMOVE HER GRILLE AND HAT
    {"2mj2nig5beknd26bjd29j16ajmj9594bbjnilmnd", 0, VOLATILE_FLAG_82_SANDCASTLE_REMOVE_GRILL_AND_HAT_FROM_STATUE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // ITS YOUR LUCKY DAY AS THE ICE BALL MELTS AWAY
    {"4d2e6g9bg08elnen2dmj40jknbb1jbd2n7ne", 0, VOLATILE_FLAG_83_SANDCASTLE_REMOVE_ICE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // NOW IN TO THE SWAMP YOU CAN STOMP
    {"i674id6dmj27n1re6g0ni2d61r", 0, VOLATILE_FLAG_84_SANDCASTLE_OPEN_BGS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THEY CAUSE TROUBLE BUT NOW THEYRE RUBBLE
    {"dmje0ng2jd96gkbjkgdi67dmje9j9gkkbj", 0, VOLATILE_FLAG_85_SANDCASTLE_REMOVE_BREAKABLE_WALLS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOULL BE GLAD TO SEE THE SHOCK JUMP PAD
    {"e6gbbkj5bnld62jjdmj2m608pg1rrnl", 0, VOLATILE_FLAG_86_SANDCASTLE_SHOCKSPRING_JUMP_UNLOCKED + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THIS COMES IN HANDY TO OPEN SOMEWHERE SANDY
    {"dm42061j24imniled66rji261j7mj9j2nile", 0, VOLATILE_FLAG_87_SANDCASTLE_OPEN_GV + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // WEBS STOP YOUR PLAY SO TAKE THEM AWAY
    {"7jk22d6re6g9rbne26dn8jdmj1n7ne", 0, VOLATILE_FLAG_88_SANDCASTLE_REMOVE_WEBS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // GRUNTY WILL CRY NOW YOUVE SMASHED HER EYE
    {"59gide74bb09ei67e6gaj21n2mjlmj9jej", 0, VOLATILE_FLAG_89_SANDCASTLE_REMOVE_GLASS_EYE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOU WONT BE SAD NOW YOU CAN USE THE FLY PAD
    {"e6g76idkj2nli67e6g0nig2jdmjcbernl", 0, VOLATILE_FLAG_8A_SANDCASTLE_FLIGHT_UNLOCKED + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // NOW YOU CAN GO AND TRUDGE IN THE SNOW
    {"i67e6g0ni56nild9gl5j4idmj2i67", 0, VOLATILE_FLAG_8B_SANDCASTLE_OPEN_FP + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE MANSION OF GHOSTS ARE NOW YOUR HOSTS
    {"dmj1ni246i6c5m62d2n9ji67e6g9m62d2", 0, VOLATILE_FLAG_8C_SANDCASTLE_OPEN_MMM + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // YOU WONT HAVE TO WAIT NOW THERES NO CRYPT GATE
    {"e6g76idmnajd67n4di67dmj9j2i609erd5ndj", 0, VOLATILE_FLAG_8D_SANDCASTLE_REMOVE_CRYPT_GATE + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THIS SHOULD GET RID OF THE CRYPT COFFIN LID
    {"dm422m6gbl5jd94l6cdmj09erd06cc4ib4l", 0, VOLATILE_FLAG_8E_SANDCASTLE_REMOVE_CRYPT_COFFIN_LID + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // UP YOU GO WITHOUT A HITCH UP TO THE WATER LEVEL SWITCH
    {"gre6g5674dm6gdnm4d0mgrd6dmj7ndj9bjajb274d0m", 0, VOLATILE_FLAG_8F_SANDCASTLE_REMOVE_GRATE_NEAR_WATER_SWITCH + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // WHY NOT TAKE A TRIP INSIDE GRUNTYS RUSTY SHIP
    {"7mei6ddn8jnd94r4i24lj59gide29g2de2m4r", 0, VOLATILE_FLAG_90_SANDCASTLE_OPEN_RBB + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THE GRILLE GOES BOOM TO THE SHIP PICTURE ROOM
    {"dmj594bbj56j2k661d6dmj2m4rr40dg9j9661", 0, VOLATILE_FLAG_91_SANDCASTLE_REMOVE_GRILL_NEAR_RBB_JIGGY + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // ONCE IT SHONE BUT THE LONG TUNNEL GRILLE IS GONE
    {"6i0j4d2m6ijkgddmjb6i5dgiijb594bbj4256ij", 0, VOLATILE_FLAG_92_SANDCASTLE_REMOVE_TUNNEL_GRILL_NEAR_RBB_JIGGY + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // THIS ONES GOOD AS YOU CAN ENTER THE WOOD
    {"dm426ij2566ln2e6g0nijidj9dmj766l", 0, VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // AN ENERGY BAR TO GET YOU FAR
    {"nijij95ekn9d65jde6gcn9", 0, VOLATILE_FLAG_94_SANDCASTLE_INFINITE_HEALTH + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // DONT BE A DUMBO GO SEE MUMBO
    {"l6idkjnlg1k6562jj1g1k6", 0, VOLATILE_FLAG_95_SANDCASTLE_INFINTE_MUMBO_TOKENS + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    // GIVE THE BEAR LOTS OF AIR
    {"54ajdmjkjn9b6d26cn49", 0, VOLATILE_FLAG_96_SANDCASTLE_INFINITE_AIR + VOLATILE_FLAG_CHEAT_OFFSET, 00},

    NULL
};

static u8 sLastFloorTileHitCorret = 0; // 0 = "initial", 1 = incorrect, 2 = correct
static BannedCheatCodeRange sBannedCheatCodeRanges[4] = {
    {
        VOLATILE_FLAG_66_SANDCASTLE_OPEN_DOOR_TWO + VOLATILE_FLAG_CHEAT_OFFSET,
        VOLATILE_FLAG_6B_SANDCASTLE_OPEN_DOOR_SEVEN + VOLATILE_FLAG_CHEAT_OFFSET
    },
    {
        VOLATILE_FLAG_6C_SANDCASTLE_PUZZLE_COMPLETE_CC + VOLATILE_FLAG_CHEAT_OFFSET,
        VOLATILE_FLAG_72_SANDCASTLE_PUZZLE_COMPLETE_CCC + VOLATILE_FLAG_CHEAT_OFFSET
    },
    {
        VOLATILE_FLAG_7D_SANDCASTLE_RAISE_PIPES_TO_CC + VOLATILE_FLAG_CHEAT_OFFSET,
        VOLATILE_FLAG_93_SANDCASTLE_OPEN_CCW + VOLATILE_FLAG_CHEAT_OFFSET
    },
    NULL
};

// shows the unlocked stop n swap item in a cutscene, arg3/arg4 might describe state / camera angle or something
static void __maCastle_showUnlockedSnSCode(s32 secret_cheat_code_index, s32 codeId, enum map_e map_id, s32 arg3, s32 arg4)
{
    if (codeId == sSecretsCheatCodes[secret_cheat_code_index].id)
    {
        func_802D6310(1.0f, map_id, arg3, arg4, 0);
    }
}

static void __maCastle_resetSecretCheatCodeProgress(void)
{
    SecretCheatCode *i_ptr;

    for (i_ptr = &sSecretsCheatCodes[0]; i_ptr->code != NULL; i_ptr++)
    {
        i_ptr->codeCharacterIdx = 0;
    }
    sLastFloorTileHitCorret = 0;
    __maCastle_setsecretCheatCodeRelatedValue();
}

static u32 __maCastle_scrambleAddressForSecretCheatCode()
{
    s32 addr = (s32)&sSecretsCheatCodes;
    s32 scrambled;
    SecretCheatCode *i_ptr;
    u32 var_a3;
    u32 var_v0;

    scrambled = (addr >> 8) & 0xFF0000;
    scrambled += (addr & 0xFF) << 8;
    scrambled = addr ^ scrambled;

    addr = (((scrambled & 0xFF000000) >> 8) + ((scrambled << 8) & 0xFF00)) ^ scrambled;

    i_ptr = (SecretCheatCode *)addr;
    var_a3 = 0x03148C41;
    while (i_ptr->code != NULL)
    {
        for (var_v0 = 0; var_v0 < i_ptr->codeCharacterIdx; var_v0++)
        {
            var_a3 = ((i_ptr->code[var_v0] ^ var_a3) << 5) + (var_a3 >> 0x18);
        }
        for (var_v0 = var_v0; i_ptr->code[var_v0] != 0; var_v0++)
        {
            var_a3 = (i_ptr->code[var_v0] << (var_v0 & 0xF)) ^ (var_a3 + 0xD);
        }
        i_ptr++;
    }
    return var_a3;
}

static void __maCastle_setFileProgressForSecretCheatCode(
    s32 always_0,
    s32 secret_cheat_code_index,
    enum volatile_flags_e volatile_flag,
    enum file_progress_e prog_id,
    s32 prog_val,
    s32 prog_bit_size,
    enum file_progress_e file_progress_to_mark_true
)
{
    if (
        ((volatile_flag + VOLATILE_FLAG_CHEAT_OFFSET == sSecretsCheatCodes[secret_cheat_code_index].id) && volatileFlag_get(volatile_flag))
        // This can never be true as always_0 is always 0
        || always_0 == 3
    ) {
        fileProgressFlag_setN(prog_id, prog_val, prog_bit_size);
        if (file_progress_to_mark_true)
        {
            fileProgressFlag_set(file_progress_to_mark_true, TRUE);
        }
    }
}

static void __maCastle_setNumberOfBannedCheatcodesEntered(s32 arg0)
{
    fileProgressFlag_setN(FILEPROG_FD_BANNED_CHEATCODES_ENTERED, arg0, 2);
}

static s32 __maCastle_getNumberOfBannedCheatCodesEntered()
{
    return fileProgressFlag_getN(FILEPROG_FD_BANNED_CHEATCODES_ENTERED, 2);
}

static void __maCastle_setItemForSecretCheatCode(s32 always_0, s32 secret_cheat_code_index, enum volatile_flags_e volatile_flag, enum item_e item_id, s32 always_0_2, s32 item_val)
{
    if (((volatile_flag + VOLATILE_FLAG_CHEAT_OFFSET) == sSecretsCheatCodes[secret_cheat_code_index].id) || (always_0 == 1))
    {
        if (always_0_2 != 0)
        {
            item_adjustByDiffWithHud(item_id, always_0_2);
            return;
        }
        item_set(item_id, item_val);
    }
}

static void __maCastle_checkSecretCheatCodeIndex(s32 secret_cheat_code_index)
{
    SecretCheatCode *secret_cheat_code;
    enum volatile_flags_e volaflag_cheat_id;

    secret_cheat_code = &sSecretsCheatCodes[secret_cheat_code_index];
    volaflag_cheat_id = secret_cheat_code->id - VOLATILE_FLAG_CHEAT_OFFSET;
    sns_set_item_and_update_payload(secret_cheat_code->id, 1, 1);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x01, MAP_61_CCW_WINTER_NABNUTS_HOUSE, 0x83, 0x1B);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x02, MAP_3F_RBB_CAPTAINS_CABIN, 0x84, 0x1C);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x03, MAP_2C_MMM_BATHROOM, 0x85, 0x1D);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x04, MAP_12_GV_GOBIS_VALLEY, 0x86, 0x1E);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x05, MAP_7_TTC_TREASURE_TROVE_COVE, 0x87, 0x1F);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x06, MAP_1D_MMM_CELLAR, 0x88, 0x20);
    __maCastle_showUnlockedSnSCode(secret_cheat_code_index, 0x07, MAP_7F_FP_WOZZAS_CAVE, 0x89, 0x21);
    if (secret_cheat_code->id >= VOLATILE_FLAG_CHEAT_OFFSET)
    {
        func_8030E58C(SFX_2B_BULL_MOO_1, 1.5f);
        volatileFlag_set(VOLATILE_FLAG_65_CHEAT_ENTERED, 1);
        volatileFlag_set(volaflag_cheat_id, 1);
    }

    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_6C_SANDCASTLE_PUZZLE_COMPLETE_CC,
        FILEPROG_60_CC_PUZZLE_PIECES_PLACED,
        5,
        3,
        FILEPROG_33_CC_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_6D_SANDCASTLE_PUZZLE_COMPLETE_BGS,
        FILEPROG_63_BGS_PUZZLE_PIECES_PLACED,
        7,
        3,
        FILEPROG_34_BGS_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_6E_SANDCASTLE_PUZZLE_COMPLETE_FP,
        FILEPROG_66_FP_PUZZLE_PIECES_PLACED,
        8,
        4,
        FILEPROG_35_FP_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_6F_SANDCASTLE_PUZZLE_COMPLETE_GV,
        FILEPROG_6A_GV_PUZZLE_PIECES_PLACED,
        9,
        4,
        FILEPROG_36_GV_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_70_SANDCASTLE_PUZZLE_COMPLETE_MMM,
        FILEPROG_6E_MMM_PUZZLE_PIECES_PLACED,
        10,
        4,
        FILEPROG_37_MMM_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_71_SANDCASTLE_PUZZLE_COMPLETE_RBB,
        FILEPROG_72_RBB_PUZZLE_PIECES_PLACED,
        0xC,
        4,
        FILEPROG_38_RBB_OPEN
    );
    __maCastle_setFileProgressForSecretCheatCode(
        0,
        secret_cheat_code_index,
        VOLATILE_FLAG_72_SANDCASTLE_PUZZLE_COMPLETE_CCC,
        FILEPROG_76_CCW_PUZZLE_PIECES_PLACED,
        0xF,
        4,
        FILEPROG_39_CCW_OPEN
    );
    __maCastle_setItemForSecretCheatCode(0, secret_cheat_code_index, VOLATILE_FLAG_94_SANDCASTLE_INFINITE_HEALTH, ITEM_15_HEALTH_TOTAL, 0, 8);
    __maCastle_setItemForSecretCheatCode(0, secret_cheat_code_index, VOLATILE_FLAG_77_SANDCASTLE_SET_HEALTH_TO_MAX, ITEM_14_HEALTH, 0, item_getCount(ITEM_15_HEALTH_TOTAL));
    __maCastle_setItemForSecretCheatCode(0, secret_cheat_code_index, VOLATILE_FLAG_95_SANDCASTLE_INFINTE_MUMBO_TOKENS, ITEM_1C_MUMBO_TOKEN, 0, 99);
    if (volaflag_cheat_id == VOLATILE_FLAG_81_SANDCASTLE_CCC_JIGGY_PODIUM)
    {
        fileProgressFlag_set(FILEPROG_53_CCW_PUZZLE_PODIUM_SWITCH_PRESSED, 1);
        fileProgressFlag_set(FILEPROG_54_CCW_PUZZLE_PODIUM_ACTIVE, 1);
    }
    __maCastle_resetSecretCheatCodeProgress();
}

static void __maCastle_eraseGameplayDialogCallback(ActorMarker *caller, enum asset_e text_id, s32 confirmed)
{
    if (confirmed == 1)
    {
        __maCastle_setNumberOfBannedCheatcodesEntered(3);
        __maCastle_checkSecretCheatCodeIndex(sThirdForbiddenSecretCheatCodeIndex);
        gcdialog_showText(ASSET_FBF_DIALOG_ERASED_SAVE, 0xC, NULL, NULL, NULL, NULL);
        gameFile_clear(func_802C5A30());
        gameFile_8033CFD4(func_802C5A30());
        func_802C5A3C(-1);
        return;
    }
    __maCastle_resetSecretCheatCodeProgress();
}

static void __maCastle_checkIfBannedCheatCodeEntered(s32 secret_cheat_code_index)
{
    s32 i;

    if ((s32)sSecretsCheatCodes[secret_cheat_code_index].id >= VOLATILE_FLAG_CHEAT_OFFSET)
    {
        if (volatileFlag_get(sSecretsCheatCodes[secret_cheat_code_index].id - VOLATILE_FLAG_CHEAT_OFFSET))
        {
            __maCastle_resetSecretCheatCodeProgress();
            return;
        }
        for (i = 0; sBannedCheatCodeRanges[i].minId != 0; i++)
        {
            if ((sSecretsCheatCodes[secret_cheat_code_index].id >= sBannedCheatCodeRanges[i].minId) && (sBannedCheatCodeRanges[i].maxId >= sSecretsCheatCodes[secret_cheat_code_index].id))
            {
                switch (__maCastle_getNumberOfBannedCheatCodesEntered())
                {
                    case 0:
                        __maCastle_setNumberOfBannedCheatcodesEntered(1);
                        __maCastle_checkSecretCheatCodeIndex(secret_cheat_code_index);
                        __maCastle_resetSecretCheatCodeProgress();
                        return;
                    case 1:
                        __maCastle_setNumberOfBannedCheatcodesEntered(2);
                        __maCastle_checkSecretCheatCodeIndex(secret_cheat_code_index);
                        __maCastle_resetSecretCheatCodeProgress();
                        gcdialog_showText(ASSET_FBE_DIALOG_CHEATING_ERASE_SAVE_WARNING, 0xC, NULL, NULL, NULL, NULL);
                        return;
                    case 2:
                        sThirdForbiddenSecretCheatCodeIndex = secret_cheat_code_index;
                        gcdialog_showText(ASSET_E38_DIALOG_CHEATING_ERASE_SAVE_CONFIRMATION, 0xC, NULL, NULL, __maCastle_eraseGameplayDialogCallback, NULL);
                        return;
                }
                return;
            }
        }
    }
    __maCastle_checkSecretCheatCodeIndex(secret_cheat_code_index);
    __maCastle_resetSecretCheatCodeProgress();
}

static bool __maCastle_isFloorTileValidForSecretCheatCode(LetterFloorTile *floor_tile)
{
    SecretCheatCode *var_s0;
    SecretCheatCode *var_v0;
    s32 matched_secret_cheat_codes;
    s32 secret_cheat_code_index;
    s32 matched_secret_cheat_code_2;
    s32 var_v1;

    if ((sLastFloorTileHitCorret == 2) || (__maCastle_getNumberOfBannedCheatCodesEntered() == 3))
    {
        return FALSE;
    }

    if (sLastFloorTileHitCorret == 0)
    {
        matched_secret_cheat_codes = 0;
        // has entered "CHEAT" and is now entering "actual" cheat code
        if (*(sSecretsCheatCodes[0].codeCharacterIdx + sSecretsCheatCodes[0].code) == NULL)
        {
            // go through each secret cheat code
            for (var_v1 = 0; (sSecretsCheatCodes + var_v1)->code != NULL; var_v1++)
            {
                // check whether the floor tile letter is the "expected" character in the current secret cheat code
                if (floor_tile->letter == (sSecretsCheatCodes + var_v1)->code[(sSecretsCheatCodes + var_v1)->codeCharacterIdx])
                {
                    // advance character index
                    (sSecretsCheatCodes + var_v1)->codeCharacterIdx++;
                    matched_secret_cheat_codes += 1;
                }
            }
            // did the letter occur in any secret cheat code?
            if (matched_secret_cheat_codes != 0)
            {
                sLastFloorTileHitCorret = 1;
                __maCastle_setsecretCheatCodeRelatedValue();
                return TRUE;
            }

            sLastFloorTileHitCorret = 2;
            __maCastle_setsecretCheatCodeRelatedValue();
            return FALSE;
        }

        // is entering "CHEAT"?
        if (floor_tile->letter == sSecretsCheatCodes[0].code[sSecretsCheatCodes[0].codeCharacterIdx])
        {
            func_8030E58C(SFX_2B_BULL_MOO_1, randf2(0.6f, 0.7f));
            sSecretsCheatCodes[0].codeCharacterIdx++;
            __maCastle_setsecretCheatCodeRelatedValue();
            return TRUE;
        }

        sLastFloorTileHitCorret = 2;
        __maCastle_setsecretCheatCodeRelatedValue();
        return FALSE;
    }

    __maCastle_setsecretCheatCodeRelatedValue();
    if (sLastFloorTileHitCorret == 1)
    {
        matched_secret_cheat_code_2 = 0;
        // iterate over all secret cheat codes except the first one
        for (secret_cheat_code_index = 1; (sSecretsCheatCodes + secret_cheat_code_index)->code != 0; secret_cheat_code_index++)
        {
            // is the letter expected at the current cheat codes character index
            if (
                ((sSecretsCheatCodes + secret_cheat_code_index)->codeCharacterIdx != NULL) && 
                (floor_tile->letter == (sSecretsCheatCodes + secret_cheat_code_index)->code[(sSecretsCheatCodes + secret_cheat_code_index)->codeCharacterIdx])
            )
            {
                matched_secret_cheat_code_2 += 1;
                (sSecretsCheatCodes + secret_cheat_code_index)->codeCharacterIdx++;
                __maCastle_setsecretCheatCodeRelatedValue();
                // check if "next" expected character is zero-terminator, if true then cheat entered successfully
                if ((sSecretsCheatCodes + secret_cheat_code_index)->code[(sSecretsCheatCodes + secret_cheat_code_index)->codeCharacterIdx] == '\0')
                {
                    if ((sSecretsCheatCodes + secret_cheat_code_index)->id != NULL)
                    {
                        __maCastle_checkIfBannedCheatCodeEntered(secret_cheat_code_index);
                    }
                    return TRUE;
                }
            }
            else
            {
                // reset progress for current secret cheat code
                (sSecretsCheatCodes + secret_cheat_code_index)->codeCharacterIdx = 0;
                __maCastle_setsecretCheatCodeRelatedValue();
            }
        }
        if (matched_secret_cheat_code_2 == 0)
        {
            sLastFloorTileHitCorret = 2;
            return FALSE;
        }
    }

    return TRUE;
}

static bool __maCastle_isCurrentSecretCheatCodeCharacter0()
{
    return *(u8 *)(sSecretsCheatCodes[0].codeCharacterIdx + (s32)sSecretsCheatCodes[0].code) == 0;
}

bool maCastle_isSecretCheatCodeRelatedValueEqualToScrambledAddressValue()
{
    return __maCastle_scrambleAddressForSecretCheatCode() == sSecretCheatCodeRelatedValue;
}
