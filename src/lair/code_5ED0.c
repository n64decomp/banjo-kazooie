#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "../core2/gc/zoombox.h"
#include "../core2/code_C9E70.h"
#include "core2/nc/camera.h"


#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

// ? FF question flags
#define FF_QNF_START        (401) // 191
#define FF_QNF_FINAL_TILE   (495) // 1EF
#define FF_QNF_END          (496) // 1F0
#define FF_QNF_CNT          (96)

enum FF_TileType
{
    FFTT_0_NIL,
    FFTT_1_BANJO,
    FFTT_2_PICTURE,
    FFTT_3_MUSIC,
    FFTT_4_MINIGAME,
    FFTT_5_GRUNTY,
    FFTT_6_SKULL,
    FFTT_7_JOKER, // Used In Code
    FFTT_8_JOKER  // Used In Data
};

//this is states not actions
//actions occur when state is changed/set
enum FF_Action 
{
    FFA_0_NIL,
    FFA_1_UNK,
    FFA_2_ON_BOARD_FORGET_MOVES,
    FFA_3_TRIGGER_QUESTION,
    // clearing sound??
    FFA_4_UNK,
    FFA_5_FORGET_MOVES_2,
    FFA_6_TRIGGER_QUESTION_POST_EFFECTS,
    FFA_7_UNK,
    FFA_8_FURNACE_FUN_COMPLETE,
    FFA_9_FURNACE_FUN_POST_COMPLETION
};

enum FF_Picture_Action
{
    FFPA_1_UNK = 1,
    FFPA_2_CLEAR_ZOOMBOX,
    FFPA_3_UNK
};


/* .h */
void ff_setState(enum FF_Action next_state);// ff_set_state
void lair_func_8038C6BC(void);

/* extern */
extern void code_73640_printItemCount(enum item_e);
extern void code_7060_setVoidOutLocation(enum map_e, s32);
extern void quizQuestionAskedBitfield_set(u32, int); // ff_isAsked_flag_set
extern int quizQuestionAskedBitfield_get(u32); // ff_isAsked_flag_get

extern void BKModel_getMeshCenter(BKModel *model, s32 mesh_id, s16 [3]); //! $a2 type unk

extern void ability_setAllLearned(s32);  // set unlocked moves bitfield
extern s32  ability_getAllLearned(void); // get unlocked moves bitfield

extern s32  item_getCount(s32); // item count get
extern void item_adjustByDiffWithoutHud(s32, s32); // item count set

extern void func_8025A55C(s32, s32, s32);

extern void func_80324CFC(f32, s16, s16);

extern void *mapModel_getModel(s32);
extern void  player_setTransformation(s32); // set transformation

//typedef migrated to "inlcude/core2/code_C9E70.h"
extern struct FF_StorageStruct *ffStorage; 

/* .data */

//////////////////////// FURNACE FUN BOARD ////////////////////////
// You read the board bottom left to top right,
// with the first one being the first bk square,
// then going to the first eye square,
// then going to the extra life tile on the bottom left.
//                             191 (Finish?)
// ___ ___ ___ ___ ___ ___ ___ 1EF (Skull Tile)    ___ ___ ___ ___
// 1E3 1E4 1E5 ___ ___ ___ 1E6 1E7 1E8 1E9 1EA 1EB 1EC 1ED 1EE ___
// 1DF ___ 1E0 ___ ___ ___ 1E1 ___ ___ ___ ___ 1E2 ___ ___ ___ ___
// ___ ___ 1D9 1DA 1DB 1DC 1DD ___ ___ ___ ___ 1DE ___ ___ ___ ___
// ___ ___ 1D6 ___ ___ ___ 1D7 ___ ___ ___ ___ 1D8 ___ ___ ___ ___
// ___ ___ 1CD ___ ___ ___ 1CE 1CF 1D0 1D1 1D2 1D3 1D4 1D5 ___ ___
// 1C4 1C5 1C6 1C7 1C8 ___ ___ ___ 1C9 ___ ___ ___ ___ 1CA 1CB 1CC
// 1C0 ___ ___ ___ 1C1 ___ ___ ___ 1C2 ___ ___ ___ ___ 1C3 ___ ___
// 1B5 ___ ___ ___ 1B6 1B7 1B8 1B9 1BA 1BB 1BC 1BD 1BE 1BF ___ ___
// 1AF 1B0 1B1 1B2 1B3 ___ ___ ___ ___ ___ ___ 1B4 ___ ___ ___ ___
// 1AC ___ ___ ___ 1AD ___ ___ ___ ___ ___ ___ 1AE ___ ___ ___ ___
// 1A1 ___ ___ ___ 1A2 1A3 1A4 1A5 1A6 1A7 1A8 1A9 1AA 1AB ___ ___
// ___ ___ ___ ___ ___ 19E ___ ___ 19F ___ ___ ___ ___ 1A0 ___ ___
// ___ ___ ___ ___ ___ 19B ___ ___ 19C ___ ___ ___ ___ 19D ___ ___
// ___ 193 194 195 196 197 198 199 19A ___ ___ ___ ___ ___ ___ ___
// ___ ___ ___ ___ ___ ___ ___ 192 ___ ___ ___ ___ ___ ___ ___ ___
// ___ ___ ___ ___ ___ ___ ___ 0?? (BK TILE)   ___ ___ ___ ___ ___
//                           ENTRANCE

extern Furnace_Fun_Board FF_BoardTable[FF_QNF_CNT - 1] = {
    {{    0,     0, 0x192,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // Start
    {{    0,     0, 0x199,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 192
    {{    0,     0,     0, 0x194}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 193
    {{    0, 0x193,     0, 0x195}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 194
    {{    0, 0x194,     0, 0x196}, FFTT_8_JOKER,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 195
    {{    0, 0x195,     0, 0x197}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 196
    {{    0, 0x196, 0x19B, 0x198}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 197
    {{    0, 0x197,     0, 0x199}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 198
    {{0x192, 0x198,     0, 0x19A}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 199
    {{    0, 0x199, 0x19C,     0}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19A
    {{0x197,     0, 0x19E,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19B
    {{0x19A,     0, 0x19F,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19C
    {{    0,     0, 0x1A0,     0}, FFTT_8_JOKER,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19D
    {{0x19B,     0, 0x1A3,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19E
    {{0x19C,     0, 0x1A6,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 19F
    {{0x19D,     0, 0x1AB,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A0
    {{    0,     0, 0x1AC,     0}, FFTT_8_JOKER,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A1
    {{    0,     0, 0x1AD, 0x1A3}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A2
    {{0x19E, 0x1A2,     0, 0x1A4}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A3
    {{    0, 0x1A3,     0, 0x1A5}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A4
    {{    0, 0x1A4,     0, 0x1A6}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A5
    {{0x19F, 0x1A5,     0, 0x1A7}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A6
    {{    0, 0x1A6,     0, 0x1A8}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A7
    {{    0, 0x1A7,     0, 0x1A9}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A8
    {{    0, 0x1A8, 0x1AE, 0x1AA}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1A9
    {{    0, 0x1A9,     0, 0x1AB}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AA
    {{0x1A0, 0x1AA,     0,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AB
    {{0x1A1,     0, 0x1AF,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AC
    {{0x1A2,     0, 0x1B3,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AD
    {{0x1A9,     0, 0x1B4,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AE
    {{0x1AC,     0, 0x1B5, 0x1B0}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1AF
    {{    0, 0x1AF,     0, 0x1B1}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B0
    {{    0, 0x1B0,     0, 0x1B2}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B1
    {{    0, 0x1B1,     0, 0x1B3}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B2
    {{0x1AD, 0x1B2, 0x1B6,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B3
    {{0x1AE,     0, 0x1BD,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B4
    {{0x1AF,     0, 0x1C0,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B5
    {{0x1B3,     0, 0x1C1, 0x1B7}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B6
    {{    0, 0x1B6,     0, 0x1B8}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B7
    {{    0, 0x1B7,     0, 0x1B9}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B8
    {{    0, 0x1B8,     0, 0x1BA}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1B9
    {{    0, 0x1B9, 0x1C2, 0x1BB}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BA
    {{    0, 0x1BA,     0, 0x1BC}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BB
    {{    0, 0x1BB,     0, 0x1BD}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BC
    {{0x1B4, 0x1BC,     0, 0x1BE}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BD
    {{    0, 0x1BD,     0, 0x1BF}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BE
    {{    0, 0x1BE, 0x1C3,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1BF
    {{0x1B5,     0, 0x1C4,     0}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C0
    {{0x1B6,     0, 0x1C8,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C1
    {{0x1BA,     0, 0x1C9,     0}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C2
    {{0x1BF,     0, 0x1CA,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C3
    {{0x1C0,     0,     0, 0x1C5}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C4
    {{    0, 0x1C4,     0, 0x1C6}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C5
    {{    0, 0x1C5, 0x1CD, 0x1C7}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C6
    {{    0, 0x1C6,     0, 0x1C8}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C7
    {{0x1C1, 0x1C7,     0,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C8
    {{0x1C2,     0, 0x1D0,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1C9
    {{0x1C3,     0, 0x1D5, 0x1CB}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CA
    {{    0, 0x1CA,     0, 0x1CC}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CB
    {{    0, 0x1CB,     0,     0}, FFTT_8_JOKER,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CC
    {{0x1C6,     0, 0x1D6,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CD
    {{    0,     0, 0x1D7, 0x1CF}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CE
    {{    0, 0x1CE,     0, 0x1D0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1CF
    {{0x1C9, 0x1CF,     0, 0x1D1}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D0
    {{    0, 0x1D0,     0, 0x1D2}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D1
    {{    0, 0x1D1,     0, 0x1D3}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D2
    {{    0, 0x1D2, 0x1D8, 0x1D4}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D3
    {{    0, 0x1D3,     0, 0x1D5}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D4
    {{0x1CA, 0x1D4,     0,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D5
    {{0x1CD,     0, 0x1D9,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D6
    {{0x1CE,     0, 0x1DD,     0}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D7
    {{0x1D3,     0, 0x1DE,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D8
    {{0x1D6,     0, 0x1E0, 0x1DA}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1D9
    {{    0, 0x1D9,     0, 0x1DB}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DA
    {{    0, 0x1DA,     0, 0x1DC}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DB
    {{    0, 0x1DB,     0, 0x1DD}, FFTT_3_MUSIC,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DC
    {{0x1D7, 0x1DC, 0x1E1,     0}, FFTT_4_MINIGAME, 0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DD
    {{0x1D8,     0, 0x1E2,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DE
    {{    0,     0, 0x1E3,     0}, FFTT_8_JOKER,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1DF
    {{0x1D9,     0, 0x1E5,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E0
    {{0x1DD,     0, 0x1E6,     0}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E1
    {{0x1DE,     0, 0x1EB,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E2
    {{0x1DF,     0,     0, 0x1E4}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E3
    {{    0, 0x1E3,     0, 0x1E5}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E4
    {{0x1E0, 0x1E4,     0,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E5
    {{0x1E1,     0,     0, 0x1E7}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E6
    {{    0, 0x1E6, 0x1EF, 0x1E8}, FFTT_5_GRUNTY,   0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E7
    {{    0, 0x1E7,     0, 0x1E9}, FFTT_1_BANJO,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E8
    {{    0, 0x1E8,     0, 0x1EA}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1E9
    {{    0, 0x1E9,     0, 0x1EB}, FFTT_2_PICTURE,  0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1EA
    {{0x1E2, 0x1EA,     0, 0x1EC}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1EB
    {{    0, 0x1EB,     0, 0x1ED}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1EC
    {{    0, 0x1EC,     0, 0x1EE}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1ED
    {{    0, 0x1ED,     0,     0}, FFTT_0_NIL,      0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, // 1EE
    {{0x1E7,     0, 0x191,     0}, FFTT_6_SKULL,    0, 0, {0, 0, 0}, 0.0f, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}  // 1EF
};

#define BK_QUESITON_COUNT      100
#define PICTURE_QUESITON_COUNT 118
#define SOUND_QUESITON_COUNT    51
#define GRUNTY_QUESTION_COUNT   30
#define MINIGAME_COUNT           6

struct {
    s16 startingFlagIdx;
    s16 totalQuestionCount;
} FF_QuestionTypeInfoArr[5] = {
    { // BK Question
        0,
        BK_QUESITON_COUNT
    },
    { // Picture Question
        BK_QUESITON_COUNT,
        PICTURE_QUESITON_COUNT
    },
    { // Music/Sound Question
        BK_QUESITON_COUNT + PICTURE_QUESITON_COUNT,
        SOUND_QUESITON_COUNT
    },
    { // Grunty Question
        BK_QUESITON_COUNT + PICTURE_QUESITON_COUNT + SOUND_QUESITON_COUNT,
        GRUNTY_QUESTION_COUNT
    },
    {  // Minigame
        BK_QUESITON_COUNT + PICTURE_QUESITON_COUNT + SOUND_QUESITON_COUNT + GRUNTY_QUESTION_COUNT,
        MINIGAME_COUNT
    }
};

enum FF_SOUND_QUESTION_TYPE
{
    FFSQT_0_UNK,
    FFSQT_1_COLLECT_OR_INTERACT,
    FFSQT_2_NPC_VOICE,
    FFSQT_3_LEVEL_MUSIC,
};

struct {
    u8 unk0;
    s16 soundId;
    s16 volume;
    f32 cleanupDelay;
} FF_SoundQuestionTable[] = {
    {FFSQT_0_UNK,                 0x401 /*SFX_401_*/,                      32000,  1.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_C_EGG_COLLECTED,                0x7FFF,  3.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_B_RED_FEATHER_COLLECTED,         32000,  3.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_15_EXTRA_LIFE_COLLECTED,         32000,  3.5f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_16_HONEYCOMB_COLLECTED,         0x7FFF,  3.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_9_NOTE_COLLECTED,                32000,  3.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_14_GOLD_FEATHER_COLLECTED,      0x7FFF,  3.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_17_EMPTY_HONEYCOMB_COLLECTED,   0x7FFF,  3.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_1D_GOBI,                      0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_15_CLANKER,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_1B_TRUNKER,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_17_VILE_4,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_13_BLUBBER,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_10_MUMBO_1,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_12_CONGA,                     0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_F_BOTTLES,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_11_CHIMPY,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_18_TIPTUP,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_1C_RUBEE,                     0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_1F_TEEHEE,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_3E_SNORKEL,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_41_GRUNTILDA_3,               0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_43_BOGGY,                     0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_44_WOZZA,                     0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_50_NABNUT,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_51_POLAR_BEAR_CUBS,           0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_55_ADULT_EEYRIE,              0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_57_BRENTILDA,                 0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_58_TOOTY_3,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_5A_LOGGO,                     0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_14_NIPPER,                    0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_19_TANKTUP,                   0,  0.0f},
    {FFSQT_2_NPC_VOICE,           ZOOMBOX_SPRITE_20_JINJO_YELLOW,              0,  0.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_57_TURBO_TRAINERS,               32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_58_WADING_BOOTS,                 32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_25_USING_GOLD_FEATHERS,          32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_5A_FP_IGLOO_SAD,                 32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_44_CCW_NABNUT,                   32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_41_MUMBOS_HUT,                   32000, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_2_MM,                           0x103F, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_5_TTC_VACATION_VERSION,         0x60FF, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_1C_CC_ALTERNATIVE,              0x407F, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_6_BGS,                          0x6F4F, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_20_GV_ALTERNATIVE,              0x67FE, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_F_MMM_ALTERNATIVE,              0xCFFF, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_3_FP_TWINKLIES_TALKING,         0x43FF, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_2F_CCW_HUBROOM,                 0x0007, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_33_RBB_ALTERNATIVE,             0x71BF, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_4B_CCW_ZUBBA_FIGHT,              32000, 10.0f},
    {FFSQT_1_COLLECT_OR_INTERACT, COMUSIC_6B_FP_ALTERNATIVE,               32000, 10.0f},
    {FFSQT_3_LEVEL_MUSIC,         COMUSIC_5_TTC_VACATION_VERSION,         0x7800, 10.0f},
};

extern struct {
    s16 map;
    s16 exit;
} FF_MinigameTable[] = {
    {MAP_3A_RBB_BOSS_BOOM_BOX,     2},
    {MAP_10_BGS_MR_VILE,           2},
    {MAP_13_GV_MEMORY_GAME,        2},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE, 3},
    {MAP_11_BGS_TIPTUP,            2},
    {MAP_A_TTC_SANDCASTLE,         2}
};

// Section can either be level or NPC
#define PICTURE_QUESTIONS_SECTION_COUNT             10
#define PICTURE_QUESTIONS_PER_LEVEL_COUNT           12
#define PICTURE_QUESTION_WHO_IS_THIS_SECTION_INDEX   9
#define PICTURE_QUESTIONS_WHO_IS_THIS_COUNT         10

extern struct {
    s16 mapId;
    s16 cameraId;
} FF_PictureQuestionTable[] = {
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x1B},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x1E},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x20},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x25},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x1C},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x21},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x22},
    {MAP_C_MM_TICKERS_TOWER,          0x08},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x23},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x24},
    {MAP_C_MM_TICKERS_TOWER,          0x06},
    {MAP_C_MM_TICKERS_TOWER,          0x07},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x16},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x18},
    {MAP_5_TTC_BLUBBERS_SHIP,         0x02},
    {MAP_A_TTC_SANDCASTLE,            0x03},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x0E},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x19},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x1A},
    {MAP_A_TTC_SANDCASTLE,            0x02},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x0F},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x14},
    {MAP_6_TTC_NIPPERS_SHELL,         0x02},
    {MAP_5_TTC_BLUBBERS_SHIP,         0x03},
    {MAP_B_CC_CLANKERS_CAVERN,        0x0D},
    {MAP_21_CC_WITCH_SWITCH_ROOM,     0x04},
    {MAP_21_CC_WITCH_SWITCH_ROOM,     0x05},
    {MAP_22_CC_INSIDE_CLANKER,        0x07},
    {MAP_B_CC_CLANKERS_CAVERN,        0x09},
    {MAP_B_CC_CLANKERS_CAVERN,        0x0A},
    {MAP_B_CC_CLANKERS_CAVERN,        0x10},
    {MAP_22_CC_INSIDE_CLANKER,        0x06},
    {MAP_B_CC_CLANKERS_CAVERN,        0x0E},
    {MAP_B_CC_CLANKERS_CAVERN,        0x11},
    {MAP_B_CC_CLANKERS_CAVERN,        0x0F},
    {MAP_22_CC_INSIDE_CLANKER,        0x08},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x13},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x15},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x16},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x17},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x14},
    {MAP_11_BGS_TIPTUP,               0x05},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x18},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x19},
    {MAP_11_BGS_TIPTUP,               0x06},
    {MAP_11_BGS_TIPTUP,               0x07},
    {MAP_10_BGS_MR_VILE,              0x04},
    {MAP_D_BGS_BUBBLEGLOOP_SWAMP,     0x1A},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x38},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x3B},
    {MAP_41_FP_BOGGYS_IGLOO,          0x04},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x38},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x2F},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x39},
    {MAP_7F_FP_WOZZAS_CAVE,           0x04},
    {MAP_53_FP_CHRISTMAS_TREE,        0x09},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x30},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x3A},
    {MAP_53_FP_CHRISTMAS_TREE,        0x0A},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x30},
    {MAP_12_GV_GOBIS_VALLEY,          0x25},
    {MAP_12_GV_GOBIS_VALLEY,          0x2A},
    {MAP_13_GV_MEMORY_GAME,           0x01},
    {MAP_16_GV_RUBEES_CHAMBER,        0x03},
    {MAP_12_GV_GOBIS_VALLEY,          0x26},
    {MAP_12_GV_GOBIS_VALLEY,          0x2B},
    {MAP_12_GV_GOBIS_VALLEY,          0x2C},
    {MAP_14_GV_SANDYBUTTS_MAZE,       0x0C},
    {MAP_14_GV_SANDYBUTTS_MAZE,       0x0D},
    {MAP_14_GV_SANDYBUTTS_MAZE,       0x0E},
    {MAP_15_GV_WATER_PYRAMID,         0x03},
    {MAP_12_GV_GOBIS_VALLEY,          0x2D},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  0x1F},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  0x20},
    {MAP_1D_MMM_CELLAR,               0x08},
    {MAP_1C_MMM_CHURCH,               0x03},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  0x1D},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  0x1B},
    {MAP_1B_MMM_MAD_MONSTER_MANSION,  0x1E},
    {MAP_2B_MMM_SECRET_CHURCH_ROOM,   0x02},
    {MAP_26_MMM_NAPPERS_ROOM,         0x03},
    {MAP_26_MMM_NAPPERS_ROOM,         0x05},
    {MAP_1C_MMM_CHURCH,               0x04},
    {MAP_8D_MMM_INSIDE_LOGGO,         0x01},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x20},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x22},
    {MAP_34_RBB_ENGINE_ROOM,          0x09},
    {MAP_3C_RBB_KITCHEN,              0x04},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x12},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x15},
    {MAP_3C_RBB_KITCHEN,              0x03},
    {MAP_3B_RBB_STORAGE_ROOM,         0x04},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x21},
    {MAP_31_RBB_RUSTY_BUCKET_BAY,     0x23},
    {MAP_34_RBB_ENGINE_ROOM,          0x0F},
    {MAP_8B_RBB_ANCHOR_ROOM,          0x03},
    {MAP_45_CCW_AUTUMN,               0x0D},
    {MAP_44_CCW_SUMMER,               0x08},
    {MAP_5A_CCW_SUMMER_ZUBBA_HIVE,    0x05},
    {MAP_43_CCW_SPRING,               0x05},
    {MAP_45_CCW_AUTUMN,               0x05},
    {MAP_46_CCW_WINTER,               0x02},
    {MAP_44_CCW_SUMMER,               0x0A},
    {MAP_40_CCW_HUB,                  0x05},
    {MAP_46_CCW_WINTER,               0x07},
    {MAP_44_CCW_SUMMER,               0x09},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE, 0x02},
    {MAP_45_CCW_AUTUMN,               0x0E},
    {MAP_12_GV_GOBIS_VALLEY,          0x27},
    {MAP_E_MM_MUMBOS_SKULL,           0x02},
    {MAP_5F_CCW_SUMMER_NABNUTS_HOUSE, 0x01},
    {MAP_2_MM_MUMBOS_MOUNTAIN,        0x1D},
    {MAP_B_CC_CLANKERS_CAVERN,        0x1D},
    {MAP_10_BGS_MR_VILE,              0x03},
    {MAP_12_GV_GOBIS_VALLEY,          0x28},
    {MAP_7_TTC_TREASURE_TROVE_COVE,   0x10},
    {MAP_27_FP_FREEZEEZY_PEAK,        0x31},
    {MAP_1_SM_SPIRAL_MOUNTAIN,        0x13}
};

/* .code */
// FF: get total number of questions per type
s16 ff_getNumOfQuestionType(enum ff_question_type_e type)
{
    return FF_QuestionTypeInfoArr[type].totalQuestionCount;
}

// FF: clear isAsked flags for current question type
void ff_clearAlreadyAskedQuestions(enum ff_question_type_e type)
{
    s32 question_index;

    for (question_index = 0; question_index < FF_QuestionTypeInfoArr[type].totalQuestionCount; question_index++)
        quizQuestionAskedBitfield_set(FF_QuestionTypeInfoArr[type].startingFlagIdx + question_index, FALSE);
}

// FF: set isAsked flag for type and question
void ff_setQuestionAsAskedAlready(enum ff_question_type_e type, s32 questionIdx, int val)
{
    quizQuestionAskedBitfield_set(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx, val);
}

// FF: get isAsked flag for type and question
bool ff_hasQuestionBeenAskedAlready(enum ff_question_type_e type, s32 questionIdx)
{
    return quizQuestionAskedBitfield_get(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx);
}

// i love stupid shit like this. these 3 lines of C compile into 150 lines of asm for type handling
void func_8038C3A0(u32 a0, BKVtxRef *a1, Vtx *a2, Furnace_Fun_Board *a3)
{
    a2->v.cn[0] = a1->v.v.cn[0] * a3->unk10;
    a2->v.cn[1] = a1->v.v.cn[1] * a3->unk10;
    a2->v.cn[2] = a1->v.v.cn[2] * a3->unk10;
}

void *ff_getCurrentBoardTile(s32 a0)
{
    Furnace_Fun_Board *ptr;

    s32 v0;

    if (!a0)
        return NULL;

    v0  = FF_QNF_START;
    ptr = FF_BoardTable;

    while (v0 < a0)
    {
        v0++;
        ptr++;
    }

    return ptr;
}

void lair_func_8038C610(s32 a0)
{
    func_8034DEB4(func_8034C528(a0 + 200), -3000);
}

void lair_func_8038C640(s32 a0, Furnace_Fun_Board *ff_board_ptr)
{
    s32 i;

    for (i = 0; i < ARRLEN(ff_board_ptr->adjacentTiles); i++)
        if (ff_board_ptr->adjacentTiles[i])
            lair_func_8038C610(ff_board_ptr->adjacentTiles[i]);

    ff_board_ptr->unk9 = 1;

    quizQuestionAskedBitfield_set(a0 - FF_QNF_CNT, TRUE);
}

void lair_func_8038C6BC(void)
{
    s32 s1, s3;

    Furnace_Fun_Board *ff_board_ptr;

    s3 = 1;

    for (ff_board_ptr = FF_BoardTable, s1 = FF_QNF_START; s1 != FF_QNF_END; s1++, ff_board_ptr++)
    {
        ff_board_ptr->unk9 = quizQuestionAskedBitfield_get(s1 - FF_QNF_CNT) ? 1 : 0;

        if (ff_board_ptr->unk9 == s3)
        {
            ff_board_ptr->unk10 = 0.95f;
            lair_func_8038C640(s1, ff_board_ptr);
        }
        else
        {
            ff_board_ptr->unk10 = 0.45f;
        }

        BKModel_getMeshCenter(ffStorage->unk0, s1, &ff_board_ptr->unkA);
    }
}

void func_8038C7A0(u32 a0, BKVtxRef *a1, Vtx *a2, Furnace_Fun_Board *a3)
{
    a2->v.cn[0] = a1->v.v.cn[0] * ffStorage->unk14;
    a2->v.cn[1] = a1->v.v.cn[1] * ffStorage->unk14;
    a2->v.cn[2] = a1->v.v.cn[2] * ffStorage->unk14;
}

void func_8038C9D0(void) {
    u8 temp_v0;
    Furnace_Fun_Board *ff_board_ptr;
    s32 current_tile_id;

    for(ff_board_ptr = FF_BoardTable, current_tile_id = FF_QNF_START; current_tile_id < FF_QNF_END; current_tile_id++){
        if ((ff_board_ptr->unk9 == 0) && (0.45 < ff_board_ptr->unk10)) {
            ff_board_ptr->unk10 = MAX(ff_board_ptr->unk10 - 0.05, 0.45);
        } else if ((ff_board_ptr->unk9 != 0) && (ff_board_ptr->unk10 < 0.95)) {
            ff_board_ptr->unk10 = MIN(ff_board_ptr->unk10 + 0.05, 0.95);
        }
        BKModel_transformMesh(ffStorage->unk0, current_tile_id, func_8038C3A0, (s32) ff_board_ptr);
        ff_board_ptr++;
    }

    BKModel_transformMesh(ffStorage->unk0, 0x1F1, func_8038C7A0, (s32) ff_board_ptr);
    if ( !((ffStorage->currFfMode != FFA_3_TRIGGER_QUESTION) && (ffStorage->currFfMode != FFA_4_UNK)) 
         && (0.5 < ffStorage->unk14)
    ) {
        ffStorage->unk14 = MAX(ffStorage->unk14 - 0.01 , 0.5);
    }
    else if ((ffStorage->currFfMode != FFA_3_TRIGGER_QUESTION) && (ffStorage->currFfMode != FFA_4_UNK) 
        &&(ffStorage->unk14 < 1.0)
    ){
        ffStorage->unk14 = MIN(ffStorage->unk14 + 0.01 , 1.0);
    }
}

void func_8038CC10(void)
{
    if (ffStorage->UNK_18)
        return;

    ffStorage->UNK_18 = func_8030ED2C(SFX_1C_ALARMCLOCK, 3);
    func_8030DD90(ffStorage->UNK_18, 0);
    sfxsource_setSampleRate(ffStorage->UNK_18, 32760);
    sfxsource_playSfxAtVolume(ffStorage->UNK_18, 0.7f);
    sfxSource_func_8030E2C4(ffStorage->UNK_18);
}

void lair_func_8038CC9C(void)
{
    if (!ffStorage->UNK_18)
        return;

    sfxSource_triggerCallbackByIndex(ffStorage->UNK_18);
    sfxsource_freeSfxsourceByIndex(ffStorage->UNK_18);
    ffStorage->UNK_18 = 0;
}

void func_8038CCEC(void)
{
    free(ffStorage->unk48);
    ffStorage->unk48 = NULL;

    free(ffStorage);
    ffStorage = NULL;

    gcquiz_free();
    quizQuestionAskedBitfield_free();
    gameSelect_saveAndExit();
}

void lair_func_8038CD48(void)
{
    if (ffStorage == NULL)
        return;

    /**
     * //! EXPLOIT: FFM (Furnace Fun Moves)
     * Sets moves upon entering SM or MM from the Lair,
     * FF asm code stays latent until then
     */
    ability_setAllLearned(ffStorage->unlockedMoves);

    ffStorage->unk0 = NULL;

    gczoombox_free(ffStorage->zoombox);
    ffStorage->zoombox = NULL;

    if (ffStorage->UNK_18)
        lair_func_8038CC9C();

    if (!volatileFlag_get(VOLATILE_FLAG_1) && !volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        volatileFlag_set(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ, FALSE);

    if (!volatileFlag_get(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ))
        func_8038CCEC();
}

void func_8038CE00(void)
{
    camera_setType(CAMERA_TYPE_1_UNKNOWN);
    ncStaticCamera_setToNode(0);
}

void ff_setup(void)
{
    s32 i;

    gcquiz_init();
    ffStorage = malloc(sizeof(struct FF_StorageStruct));
    quizQuestionAskedBitfield_init();

    // dump currently unlocked moves to storage
    ffStorage->unlockedMoves = ability_getAllLearned();

    for (i = 0; i < ARRLEN(ffStorage->unk3C); i++)
        ffStorage->unk3C[i] = 0;

    // set joker card count to 0
    item_adjustByDiffWithoutHud(ITEM_27_JOKER_CARD, item_getCount(ITEM_27_JOKER_CARD) * -1);

    ffStorage->currentTileId             = 0;
    ffStorage->currentBoardTile = NULL;
    ffStorage->zoombox          = NULL;
    ffStorage->unk14            = 1.f;
    ffStorage->UNK_18           = 0;
    ffStorage->currFfMode       = 1;
    ffStorage->unk48            = malloc(0x90);

    gzquiz_initGruntyQuestions();
}

void ff_init(void)
{
    s32 i;

    struct FF_StorageStruct_48_sub *ptr;

    if (gsworld_getMap() != MAP_8E_GL_FURNACE_FUN)
        return;

    ffStorage->unk0 = mapModel_getModel(0);
    ffStorage->unk11 = 0;

    if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME) && !volatileFlag_get(VOLATILE_FLAG_4))
    {
        quizQuestionAskedBitfield_free();
        quizQuestionAskedBitfield_init();

        for (i = 0; i < ARRLEN(ffStorage->unk3C); i++)
            ffStorage->unk3C[i] = 0;

        // set joker card count to 0
        item_adjustByDiffWithoutHud(ITEM_27_JOKER_CARD, item_getCount(ITEM_27_JOKER_CARD) * -1);
    }

    lair_func_8038C6BC();

    ptr = ffStorage->unk48->data;

#if 0
    for (i = 0; i < ARRLEN(ffStorage->unk48->data); i++)
        ptr[i].unk20 = 0;
#else
    // FIXME: weird
    ptr[1].unk20 = 0;
    ptr[2].unk20 = 0;
    ptr += 3;
    ptr[0].unk20 = 0;
    ptr[-3].unk20 = 0;
#endif

    player_setTransformation(TRANSFORM_1_BANJO);

    func_80347A14(0); // D_80386038++

    if (volatileFlag_get(VOLATILE_FLAG_1))
    {
        levelSpecificFlags_clear();
        func_8038CE00();
        ff_setState(FFA_4_UNK);
    }
    else
    {
        if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME))
        {
            levelSpecificFlags_clear();
            ff_setState(FFA_5_FORGET_MOVES_2);
        }
        else
        {
            if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE))
                ff_setState(FFA_8_FURNACE_FUN_COMPLETE);
            else
                ff_setState(FFA_1_UNK);
        }
    }
}

static s32 __code5ED0_getQuizQuestionTime(s32 questionType, s32 questionTableIndex)
{
    return 10;
}

void func_8038D0BC(s32 a0, s32 a1)
{
    if (a1 == 2)
    {
        func_80318614(ffStorage->zoombox, 1);
        func_803183A4(ffStorage->zoombox, "THIS IS A SLIGHTLY LONGER PIECE OF TEXT FOR THE QUIZ DIALOGS!");
    }

    if (a1 == 3)
    {
        func_80318614(ffStorage->zoombox, 0);
        gczoombox_minimize(ffStorage->zoombox);
        gczoombox_close(ffStorage->zoombox);
    }

    if (a1 == 6)
    {
        ff_setState(FFA_4_UNK);
    }
}

void func_8038D16C(s32 music_id, u16 a1)
{
    coMusicPlayer_playMusic(music_id, 0);
    comusic_8025AB44(music_id, 28000, 500);
    func_80250530(func_8025ADD4(music_id), a1, 0);
}

void func_8038D1BC(void)
{
    func_8025A55C(-1, 500, 9);
}

void ff_getSoundQuestionSound(void)
{
    f32 cleanupDelay = -1.f;
    func_8025A55C(0, 500, 9);
    switch (FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].unk0)
    {
        case FFSQT_0_UNK:
        {
            timed_playSfx(
                1.f,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].cleanupDelay,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].volume
            );
            cleanupDelay = 2.5f;
            break;
        }
        case FFSQT_2_NPC_VOICE:
        {
            ffStorage->zoombox = gczoombox_new(
                -100,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId,
                0, 0, func_8038D0BC
            );
            func_80318614(ffStorage->zoombox, 0);
            gczoombox_open(ffStorage->zoombox);
            gczoombox_maximize(ffStorage->zoombox);
            break;
        }
        case FFSQT_1_COLLECT_OR_INTERACT:
        {
            func_80324CFC(
                1.f,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].volume
            );
            cleanupDelay = FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].cleanupDelay;
            break;
        }
        case FFSQT_3_LEVEL_MUSIC:
        {
            timedFunc_set_2(
                0.5f, (GenFunction_2)func_8038D16C,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId,
                FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].volume
            );
            cleanupDelay = FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].cleanupDelay;
            break;
        }
    }

    if (cleanupDelay > 0.0) // f64
        timedFunc_set_1(cleanupDelay, (GenFunction_1)ff_setState, FFA_4_UNK);
}

void ff_getPictureQuestionImage(void)
{
    ffStorage->unk12 = 1;
    func_getCameraViewFromLevel(
        FF_PictureQuestionTable[ffStorage->questionTypeTableIndex].mapId,
        FF_PictureQuestionTable[ffStorage->questionTypeTableIndex].cameraId,
        ffStorage->questionAssetIndex >= 9
    );
}

void func_8038D3F0(s32 a0, s32 a1)
{
    if (a1 == -2)
    {
        ffStorage->unk12 = 0;

        if (ffStorage->ffQuestionType == FFQT_2_SOUND)
            ff_getSoundQuestionSound();
        else if (ffStorage->ffQuestionType == FFQT_1_PICTURE)
            ff_getPictureQuestionImage();
        else
            ff_setState(FFA_4_UNK);
    }
    else
    {
        ffStorage->unkF = a1;
        ff_setState(FFA_6_TRIGGER_QUESTION_POST_EFFECTS);
    }
}

void func_8038D48C(void)
{
    func_8028F918(0);
    ncStaticCamera_exit();
    func_802BC280();
}

void ff_setupMinigame(void)
{
    volatileFlag_set(VOLATILE_FLAG_2_FF_IN_MINIGAME, TRUE);
    func_802E4A70();

    // restore moves after a delay
    timedFunc_set_1(0.25f,
        ability_setAllLearned,
        ffStorage->unlockedMoves
    );

    // trigger warp after a delay
    timedFunc_set_3(0.25f,
        (GenFunction_3)transitionToMap,
        FF_MinigameTable[ffStorage->questionTypeTableIndex].map,
        FF_MinigameTable[ffStorage->questionTypeTableIndex].exit,
        1
    );
}

void func_8038D548(s32 a0)
{
    s32 s0;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++)
        lair_func_8038C610(s0);

    if (a0)
        lair_func_8038C610(296);
}

void func_8038D5A0(void)
{
    s32 s0;
    Furnace_Fun_Board *ptr = FF_BoardTable;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++, ptr++)
    {
        lair_func_8038C610(s0);

        ptr->unk9 = 1;

        quizQuestionAskedBitfield_set(s0 - FF_QNF_CNT, TRUE);
    }
}

s32 func_8038D60C(s32 a0)
{
    switch (a0)
    {
        // question bypass/replacement??

        case 405: return 400;
        case 413: return 401;
        case 417: return 402;
        case 460: return 403;
        case 479: return 404;
        default:
            return -1;
    }
}

// FF: process ff action
void ff_setState(enum FF_Action next_state) {
    s32 pad3C;
    f32 sp30[3];

    switch(next_state){
        case FFA_1_UNK: //L8038D6A0
            if ((ffStorage->currFfMode != FFA_5_FORGET_MOVES_2) && (ffStorage->currFfMode != FFA_1_UNK)) {
                func_802FAD64(ITEM_14_HEALTH);
                func_802FAD64(ITEM_16_LIFE);
            }
            func_802FAD64(ITEM_27_JOKER_CARD);
            ffStorage->unkF = -2;
            ability_setAllLearned(ffStorage->unlockedMoves);
            func_80347A14(1); // D_80386038--
            break;

        case FFA_2_ON_BOARD_FORGET_MOVES: //L8038D70C
            ability_setAllLearned(0);
            break;

        case FFA_3_TRIGGER_QUESTION: //L8038D720
            func_802FAD64(ITEM_14_HEALTH);
            func_802FAD64(ITEM_16_LIFE);
            ffStorage->unk12 = 1;
            func_8030E6D4(SFX_12C_FF_QUESTION_START);
            func_8028F918(2);
            if (ffStorage->ffQuestionType != FFQT_4_MINIGAME) {
                func_8038CE00();
                gcquiz_showQuestion(
                    ffStorage->ffQuestionType,
                    ffStorage->questionAssetIndex,
                    ffStorage->unkE,
                    __code5ED0_getQuizQuestionTime(ffStorage->ffQuestionType, ffStorage->questionTypeTableIndex),
                    0,
                    &func_8038D3F0);
            } else {
                ff_setupMinigame();
            }
            break;

        case FFA_4_UNK: //L8038D7CC
            if (ffStorage->ffQuestionType == FFQT_2_SOUND) {
                switch(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].unk0){
                    case FFPA_3_UNK:
                        comusic_8025AB44(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId, 0, 0x1F4);
                        func_8025AABC(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId);
                        timedFunc_set_0(1.5f, func_8038D1BC);
                        break;
                    case FFPA_1_UNK: //L8038D870
                         if (func_8025AD7C(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId)) {
                            comusic_8025AB44(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId, 0, 0x1F4);
                            timedFunc_set_0(1.5f, func_8038D1BC);
                        } else {
                            func_8025A55C(-1, 0x1F4, 9);
                        }
                        func_8025AABC(FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].soundId);
                        break;
                    case FFPA_2_CLEAR_ZOOMBOX: //L8038D908
                        gczoombox_free(ffStorage->zoombox);
                        ffStorage->zoombox = 0;
                    default:
                        func_8025A55C(-1, 0x1F4, 9);
                        break;
                }//L8038D91C
            }
            gcquiz_func_8031A48C();
            break;

        case FFA_6_TRIGGER_QUESTION_POST_EFFECTS: //L8038D940
            func_8038D48C();
            if (ffStorage->unkF == 1) {
                lair_func_8038C640(ffStorage->currentTileId, ffStorage->currentBoardTile);
                ff_setQuestionAsAskedAlready(ffStorage->ffQuestionType, ffStorage->questionTypeTableIndex, 1);
                ffStorage->unk3C[ffStorage->ffQuestionType]++;
                if (ff_getNumOfQuestionType(ffStorage->ffQuestionType) == ffStorage->unk3C[ffStorage->ffQuestionType]) {
                    ffStorage->unk3C[ffStorage->ffQuestionType] = 0;
                    ff_clearAlreadyAskedQuestions(ffStorage->ffQuestionType);
                }
                if (
                    ((s32) ffStorage->currentBoardTile->tileType >= FFTT_7_JOKER) &&
                    (quizQuestionAskedBitfield_get(func_8038D60C(ffStorage->currentTileId)) == 0)
                )
                {
                    item_adjustByDiffWithHud(ITEM_27_JOKER_CARD, ffStorage->currentBoardTile->tileType - 6);
                    quizQuestionAskedBitfield_set(func_8038D60C(ffStorage->currentTileId), TRUE);
                    progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A8_FF_GOT_JOKER);
                }
                if (ffStorage->currentTileId != FF_QNF_FINAL_TILE) {
                    gcsfx_playWithPitch(SFX_126_AUDIENCE_BOOING, 1.0f, 0x7FF8);
                    if (ffStorage->currentBoardTile->tileType == FFTT_5_GRUNTY) {
                        progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A2_FF_GRUNTY_ANSWER_RIGHT);
                    }
                    if (volatileFlag_get(VOLATILE_FLAG_A0_FF_FIRST_ANSWER_RIGHT)) {
                        progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A1_FF_NEXT_ANSWER_RIGHT);
                    }
                    progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A0_FF_FIRST_ANSWER_RIGHT);
                }
            } else {
                if (ffStorage->currentBoardTile->tileType == FFTT_6_SKULL) {
                    gcpausemenu_80314AC8(0);
                    if (func_80305248(sp30, 0x377, ffStorage->playerPosition)) {
                        func_8038D548(1);
                        func_8028F5F8(sp30);
                    } else {
                        func_8038D548(0);
                        func_8028F66C(BS_INTR_13_FF_DEATH_SQUARE);
                    }
                    func_8030E6D4(SFX_125_AUDIENCE_CHEERING_2);
                } else {
                    if (ffStorage->unkF != -2) {
                        if (item_getCount(ITEM_14_HEALTH) == 1) {
                            func_8038D548(0);
                        }
                        func_8028F530(0xD);
                    }
                    func_8030E6D4(SFX_124_AUDIENCE_CHEERING_1);
                }
                if (ffStorage->currentBoardTile->tileType >= FFTT_7_JOKER) { // FFTT_7_JOKER or FFTT_8_JOKER
                    quizQuestionAskedBitfield_set(func_8038D60C(ffStorage->currentTileId), TRUE);
                    lair_func_8038C640(ffStorage->currentTileId, ffStorage->currentBoardTile);
                }
                if (volatileFlag_get(VOLATILE_FLAG_A3_FF_FIRST_ANSWER_WRONG)) {
                    progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A4_FF_NEXT_ANSWER_WRONG);
                }
                progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A3_FF_FIRST_ANSWER_WRONG);
            }
            break;

        case FFA_5_FORGET_MOVES_2: //L8038DBEC
            ability_setAllLearned(0);
            break;

        case FFA_8_FURNACE_FUN_COMPLETE: //L8038DC00
            if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE) == 0) {
                func_8025A55C(0, 0x1388, 0xB);
                func_8025AB00();
                comusic_playTrack(JINGLE_DOOR_OF_GRUNTY_OPENED);
                fileProgressFlag_set(FILEPROG_A6_FURNACE_FUN_COMPLETE, TRUE);
                volatileFlag_set(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ, FALSE);
                volatileFlag_set(VOLATILE_FLAG_A6_FF_FOUND_HONEYCOMB, TRUE);
                volatileFlag_set(VOLATILE_FLAG_A7_FF_FOUND_EXTRALIFE, TRUE);
                next_state = FFA_9_FURNACE_FUN_POST_COMPLETION;
                mapSpecificFlags_set(0xA, TRUE);
                func_8028F918(2);
                func_80347A14(0); // D_80386038++
            }
            func_8038D5A0();
            ability_setAllLearned(ffStorage->unlockedMoves);
            func_80347A14(1); // D_80386038--
            func_802FAD64(ITEM_27_JOKER_CARD);
            break;
        default:
            break;

    }
    ffStorage->currFfMode = next_state;
    if(ffStorage);
}

// FF: get question type
enum ff_question_type_e ff_getQuestionType(enum FF_TileType tile)
{
    switch (tile)
    {
        case FFTT_1_BANJO:    return FFQT_0_TEXT;
        case FFTT_2_PICTURE:  return FFQT_1_PICTURE;
        case FFTT_3_MUSIC:    return FFQT_2_SOUND;
        case FFTT_4_MINIGAME: return FFQT_4_MINIGAME;
        case FFTT_5_GRUNTY:   return FFQT_3_GRUNTY;
        default: // joker/skull squares
        {
            f32 rng = randf();

            if      (rng < 0.5)                return FFQT_0_TEXT;    // 50% chance
            else if (rng < 0.7)                return FFQT_1_PICTURE; // 20% chance of killing the run
            else if (rng < 0.8999999999999999) return FFQT_2_SOUND;   // 20% chance
            else                               return FFQT_3_GRUNTY;  // 10% chance
        }
    }
}

// FF: choose level (enum level_e) for picture question (?)
s32 ff_getPictureQuestionLevel(void)
{
    f32 rng = randf();

    if      (rng < 0.333333) return randi2(0, 4);
    else if (rng < 0.666666) return randi2(0, 4) + 4;
    else                     return randi2(0, 4) + 8; 
}

// FF: prepare random unasked question for type
void ff_prepareNextQuestion(enum ff_question_type_e type)
{
    s32 randQuestionIdx;
    s32 picture_question_section_index;
    s32 picture_question_section_start;

    ffStorage->unkE = -1;

    if (type == FFQT_0_TEXT
     || type == FFQT_3_GRUNTY
     || type == FFQT_4_MINIGAME
     || type == FFQT_2_SOUND)
    {
        /**
         * Handle normal questions, fetch from specific question pool
         */

        do
        {
            // Generate random question index in the valid range for the type
            randQuestionIdx = randi2(0, ff_getNumOfQuestionType(type));

            // Try again if question already asked
        } while (ff_hasQuestionBeenAskedAlready(type, randQuestionIdx));

        // Save to storage struct
        ffStorage->questionTypeTableIndex = randQuestionIdx;
        ffStorage->questionAssetIndex = ffStorage->questionTypeTableIndex;
    }
    else if (type == FFQT_1_PICTURE)
    {
        /**
         * Handle picture question (choosing a level, then choosing a pre-set angle within it)
         */

        ffStorage->questionAssetIndex = ffStorage->questionTypeTableIndex;

        do
        {
            picture_question_section_index = randi2(0, PICTURE_QUESTIONS_SECTION_COUNT);
            picture_question_section_start = picture_question_section_index * PICTURE_QUESTIONS_PER_LEVEL_COUNT;

            // "Who Is This" Question
            if (picture_question_section_index == PICTURE_QUESTION_WHO_IS_THIS_SECTION_INDEX)
            {
                ffStorage->questionTypeTableIndex = randi2(0, PICTURE_QUESTIONS_WHO_IS_THIS_COUNT) + picture_question_section_start;
                ffStorage->questionAssetIndex = ffStorage->questionTypeTableIndex - picture_question_section_start + 9;
            }
            // "Which Level Is This" Question
            else
            {
                ffStorage->questionTypeTableIndex = ff_getPictureQuestionLevel() + picture_question_section_start;
                ffStorage->questionAssetIndex = ffStorage->questionTypeTableIndex / PICTURE_QUESTIONS_PER_LEVEL_COUNT;
            }

            // Try again if question already asked
        } while (ff_hasQuestionBeenAskedAlready(type, ffStorage->questionTypeTableIndex));
    }
}

// FF: play timer square sounds
void ff_playTimerTileSounds(void)
{
    if (ffStorage->UNK_18)
        return;

    timed_playSfx(0.f,   0x2A, 0.5f, 32760);
    timed_playSfx(0.25f, 0x51, 0.5f, 32760);
    timed_playSfx(0.5f,  0x2A, 0.5f, 32760);
    timed_playSfx(0.75f, 0x51, 0.5f, 32760);

    timedFunc_set_0(1.0f, func_8038CC10);
    timedFunc_set_0(2.2f, lair_func_8038CC9C);
}

void func_8038E070(void)
{
    func_8028F85C(&ffStorage->playerPosition);
    player_setRotation(&ffStorage->playerRotation);
    func_8028F918(2);
}

void lair_func_8038E0B0(void) {
    s32 buttons[6];
    s32 ff_tile_id;
    s32 joystick[2];
    s32 ff_tile_type;
    s32 ff_progress_flag;

    if( (gsworld_getMap() == MAP_8E_GL_FURNACE_FUN) 
        && (ffStorage != NULL) 
        && (ffStorage->unk0 != NULL)
    ){
        gcquiz_func_80319EA4();
        func_8038C9D0();
        controller_copyFaceButtons(0, buttons);
        controller_copySideButtons(0, joystick);
        if (ffStorage->currFfMode < 3) {
            player_getPosition(ffStorage->playerPosition);
            ff_tile_id = func_8033F3E8(ffStorage->unk0, ffStorage->playerPosition, FF_QNF_START, FF_QNF_END);
            if ((ff_tile_id != ffStorage->currentTileId) && (ffStorage->currentTileId != 0)) {
                if (ffStorage->currentBoardTile->unk9 == 2) {
                    ffStorage->currentBoardTile->unk9 = 0U;
                }
            }
            ffStorage->currentTileId = ff_tile_id;
            ffStorage->currentBoardTile = ff_getCurrentBoardTile(ffStorage->currentTileId);
        }
        // If you see FFTT_8_JOKER in the table, use FFTT_7_JOKER instead
        ff_tile_type = MIN((ffStorage->currentTileId != 0) ? ffStorage->currentBoardTile->tileType : -1, FFTT_7_JOKER);
        if ((ffStorage->currentTileId != 0) && (ffStorage->currentBoardTile->unk9 == 0) && func_8028F20C()) {
            ffStorage->currentBoardTile->unk9 = 2;
            if (ffStorage->unk11) {
                switch(ff_tile_type){
                    case FFTT_6_SKULL://L8038E26C
                        comusic_playTrack(COMUSIC_7B_STEP_ON_SKULL_TILE);
                        break;

                    case FFTT_5_GRUNTY://L8038E280
                        comusic_playTrack(COMUSIC_7C_STEP_ON_GRUNTY_TILE);
                        break;

                    case FFTT_1_BANJO://L8038E294
                        comusic_playTrack(COMUSIC_7D_STEP_ON_BK_TILE);
                        break;

                    case FFTT_7_JOKER://L8038E2A8
                        comusic_playTrack(COMUSIC_7E_STEP_ON_MINIGAME_TILE);
                        break;

                    case FFTT_3_MUSIC://L8038E2BC
                        comusic_playTrack(COMUSIC_7F_STEP_ON_JOKER_TILE);
                        break;

                    case FFTT_2_PICTURE://L8038E2D0
                        func_8030E6D4(SFX_144_DOUBLE_CAMERA_CLICK);
                        break;

                    case FFTT_4_MINIGAME://L8038E2E4
                        ff_playTimerTileSounds();
                        break;
                }
                ffStorage->unk11 = FALSE;
            }
        } else {
            ffStorage->unk11 = TRUE;
        }
        
        if ((ffStorage->currFfMode >= 2) && (ffStorage->currFfMode < 8) 
            && (item_getCount(ITEM_27_JOKER_CARD) != 0)
        ) {
            code_73640_printItemCount(ITEM_27_JOKER_CARD);
        }
        code_7060_setVoidOutLocation(MAP_8E_GL_FURNACE_FUN, 2);
        switch(ffStorage->currFfMode){
            case 1://L8038E388
                if(ffStorage->currentTileId != 0){
                    func_80347A14(0); // D_80386038++
                    ff_setState(FFA_2_ON_BOARD_FORGET_MOVES);
                }
                break;

            case 2://L8038E3AC
                if (ffStorage->currentTileId == 0) {
                    ff_setState(FFA_1_UNK);
                    break;
                }
                code_73640_printItemCount(ITEM_14_HEALTH);
                code_73640_printItemCount(ITEM_16_LIFE);
                if (ff_tile_type != FFTT_0_NIL) {
                    ff_progress_flag = ff_tile_type - 1 + FILEPROG_55_FF_BK_SQUARE_INSTRUCTIONS;
                    if (!fileProgressFlag_get(ff_progress_flag) && gcdialog_showDialog(ff_tile_type + 0x101E, 0, NULL, NULL, NULL, NULL)) {
                        fileProgressFlag_set(ff_progress_flag, TRUE);
                    }
                    if ((ff_tile_type == FFTT_6_SKULL) && (item_getCount(ITEM_16_LIFE) == 1)) {
                        progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_AB_LAST_LIFE_ON_SKULL);
                    } else if (item_getCount(ITEM_14_HEALTH) == 1) {
                        progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_AA_FF_LOW_HEALTH);
                    }
                    if ((ffStorage->currentBoardTile->unk9 == 2) && (player_movementGroup() == BSGROUP_0_NONE)) {
                        if (func_8028EFEC() && (buttons[FACE_BUTTON(BUTTON_A)] == 1)) {
                            func_803114D0();
                            player_getRotation(ffStorage->playerRotation);
                            ffStorage->ffQuestionType = ff_getQuestionType(ff_tile_type);
                            ff_prepareNextQuestion(ffStorage->ffQuestionType);
                            ff_setState(FFA_3_TRIGGER_QUESTION);
                            return;
                        }
                        if (func_8028EFC8() && (buttons[FACE_BUTTON(BUTTON_B)] == 1)) {
                            if ((item_getCount(ITEM_27_JOKER_CARD) > 0) && (ff_progress_flag < FILEPROG_5B_FF_JOKER_SQUARE_INSTRUCTIONS)) {
                                lair_func_8038C640(ffStorage->currentTileId, ffStorage->currentBoardTile);
                                item_dec(ITEM_27_JOKER_CARD);
                                func_8030E6D4(SFX_3EA_BANJO_GUH_HUH);
                                progressDialog_setAndTriggerDialog_4(VOLATILE_FLAG_A9_FF_USED_JOKER);
                                if (ffStorage->currentTileId == FF_QNF_FINAL_TILE) {
                                    ff_setState(FFA_8_FURNACE_FUN_COMPLETE);
                                }
                            } else {
                                comusic_playTrack(COMUSIC_2C_BUZZER);
                            }
                        }
                    }
                } else {
                    if (ffStorage->currentBoardTile->unk9 == 2) {
                        lair_func_8038C640(ffStorage->currentTileId, ffStorage->currentBoardTile);
                    }
                }
                break;

            case 3://L8038E5C8
                if ((ffStorage->ffQuestionType == FFQT_2_SOUND) && FF_SoundQuestionTable[ffStorage->questionTypeTableIndex].unk0 == 2){
                    gczoombox_update(ffStorage->zoombox);
                }
                if ((ffStorage->unk12 == 0) && func_8028EFC8() && (buttons[FACE_BUTTON(BUTTON_B)] == 1)) {
                    func_80324C58();
                    ff_setState(FFA_4_UNK);
                }
                break;

            case 4://L8038E64C
                if (volatileFlag_get(VOLATILE_FLAG_1)) {
                    volatileFlag_set(VOLATILE_FLAG_1, 0);
                    func_8038E070();
                    func_8025A55C(6000, 500, 0xA);
                }
                break;

            case 5://L8038E684
                if (volatileFlag_get(VOLATILE_FLAG_2_FF_IN_MINIGAME)) {
                    if (volatileFlag_get(VOLATILE_FLAG_4)) {
                        func_8038E070();
                        ffStorage->unkF = volatileFlag_get(VOLATILE_FLAG_5_FF_MINIGAME_WON);
                        ff_setState(FFA_6_TRIGGER_QUESTION_POST_EFFECTS);
                    } else {
                        ff_setState(FFA_1_UNK);
                    }
                    volatileFlag_set(VOLATILE_FLAG_2_FF_IN_MINIGAME, FALSE);
                    volatileFlag_set(VOLATILE_FLAG_4, FALSE);
                }
                break;

            case 6://L8038E6F8
                if ((ffStorage->currentTileId == FF_QNF_FINAL_TILE) && ( ffStorage->unkF == 1)) {
                    ff_setState(FFA_8_FURNACE_FUN_COMPLETE);
                }
                else{
                    ff_setState(FFA_2_ON_BOARD_FORGET_MOVES);
                }
                break;

            case 9://L8038E738
                if (!func_8025AD7C(0x78)) {
                    mapSpecificFlags_set(6, TRUE);
                    ff_setState(FFA_0_NIL);
                }
                break;
        }
    }
}

void lair_func_8038E768(Gfx **dl, Mtx **m, Vtx **v)
{
    if (gsworld_getMap() != MAP_8E_GL_FURNACE_FUN)
        return;

    gcquiz_draw(dl, m, v);
    gczoombox_draw(ffStorage->zoombox, dl, m, v);
}

void func_8038E7C4(void)
{
    if (volatileFlag_get(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ))
        return;

    ff_setup();
    volatileFlag_set(VOLATILE_FLAG_0_IN_FURNACE_FUN_QUIZ, TRUE);
}

/**
 * // TODO: Fix this so it doesn't look like it was written while writhing in epileptic shock
 */
s32 func_8038E800(void)
{
    struct FF_StorageStruct_48_sub *ptr = ffStorage->unk48->data;

#if 0
    //! doesn't match!
    {
        s32 i, j;

        for (i = 0; i < ARRLEN(ffStorage->unk48->data); i++, ptr++)
        {
            if (ptr->unk20 == 0)
            {
                ptr->unk20 = 1;

                for (j = 0; j < ARRLEN(ptr->unk14); j++)
                    ptr->unk14[j] = 0xFF;

                for (j = 0; j < ARRLEN(ptr->unk0); j++)
                    ptr->unk0[j] = 0;

                ptr->unkC = 500;
                ptr->UNK_10 = 1000;

                return i;
            }
        }
    }
#else
    //! why does a loop not match but this bs does? grant kirkhope pls

    if (ptr->unk20 == 0)
    {
        ptr->unk14[0] = 0xFF;

        ptr->unkC    = 500;

        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk20    = 1;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 0;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unkC    = 500;

        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 1;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unkC    = 500;

        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;
        ptr->unk14[2] = 0xFF;

        ptr->unk0[2] = 0;
        ptr->unk0[1] = 0;
        ptr->unk0[0] = 0;

        ptr->UNK_10    = 1000;

        return 2;
    }

    ptr++;

    if (ptr->unk20 == 0)
    {
        ptr->unk20    = 1;

        ptr->unk14[0] = 0xFF;
        ptr->unk14[1] = 0xFF;

        //! real match! yea just kidding
        do {ptr->unk14[2] = 0xFF; ptr->unk0[2] = 0; ptr->unk0[1] = 0; ptr->unk0[0] = 0; ptr->unkC = 500;
            ptr->UNK_10 = 1000;
        } while (0);

        return 3;
    }
#endif

    return -1;
}

void func_8038E968(s32 idx)
{
    if (ffStorage != NULL && ffStorage->unk48 != NULL && idx >= 0)
        ffStorage->unk48->data[idx].unk20 = 0;
}

void func_8038E9A4(s32 idx, f32 a1[3])
{
    if (ffStorage != NULL && ffStorage->unk48 != NULL && idx >= 0)
    {
        ffStorage->unk48->data[idx].unk0[0] = a1[0];
        ffStorage->unk48->data[idx].unk0[1] = a1[1];
        ffStorage->unk48->data[idx].unk0[2] = a1[2];
    }
}

void func_8038EA10(s32 idx, f32 a1[3])
{
    if (ffStorage != NULL && ffStorage->unk48 != NULL && idx >= 0)
    {
        ffStorage->unk48->data[idx].unkC = a1[0];
        ffStorage->unk48->data[idx].UNK_10 = a1[1];
    }
}

void func_8038EA68(s32 idx, s32 a1[3])
{
    if (ffStorage != NULL && ffStorage->unk48 != NULL && idx >= 0)
    {
        ffStorage->unk48->data[idx].unk14[0] = a1[0];
        ffStorage->unk48->data[idx].unk14[1] = a1[1];
        ffStorage->unk48->data[idx].unk14[2] = a1[2];
    }
}
