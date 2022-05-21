#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

// ? FF question flags
#define FF_QNF_START (401)
#define FF_QNF_END   (496)
#define FF_QNF_CNT   (96)

struct FF_QuestionTypeInfo
{
    s16 startingFlagIdx;
    s16 totalQuestionCount;
};

enum FF_QuestionType
{
    FFQT_0_NORMAL,
    FFQT_1_PICTURE,
    FFQT_2_MUSIC,
    FFQT_3_GRUNTY,
    FFQT_4_MINIGAME
};

enum FF_TileType
{
    FFTT_0_NIL,
    FFTT_1_BANJO,
    FFTT_2_PICTURE,
    FFTT_3_MUSIC,
    FFTT_4_MINIGAME,
    FFTT_5_GRUNTY,
    FFTT_6_SKULL,
    FFTT_7_JOKER
};

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
    FFA_8_FURNACE_FUN_COMPLETE
};

extern struct FF_QuestionTypeInfo FF_QuestionTypeInfoArr[5];

/* .h */

void func_8038D670(s32); // process ff action
void func_8038C6BC(void);

/* extern */

extern void func_803208C0(u32, int); // ff_isAsked_flag_set
extern int func_803207F0(u32); // ff_isAsked_flag_get

extern void func_8034DEB4(void *, f32);

extern void func_8033F220(s32 a0, s32 a1, void *); //! $a2 type unk

extern s32  func_803203FC(s32);  // get volatile flag
extern void func_80295864(s32);  // set unlocked moves bitfield
extern s32  func_802957F0(void); // get unlocked moves bitfield

extern s32  func_80345FA0(s32); // item count get
extern void func_803463F4(s32, s32); // item count set

extern void func_80318614(gczoombox_t *, s32);
extern void func_803183A4(gczoombox_t *, char *);
extern void func_8031841C(gczoombox_t *);
extern void func_803183FC(gczoombox_t *);

extern void func_8025AB44(s32, s32, s32);
extern void func_80250530(s32, u16, f32);

extern void func_8025A55C(s32, s32, s32);

extern void func_80324CFC(f32, s16, s16);
extern void func_803183EC(gczoombox_t *);
extern void func_8031840C(gczoombox_t *);

extern void *func_80309744(s32);
extern void  func_8029A95C(s32); // set transformation

/* .data */

struct FF_StorageStruct_48_sub {
    f32 UNK_00[3];

    f32 UNK_0C;
    f32 UNK_10;

    u32 UNK_14[3];

    u8 UNK_20;
    u8 UNK_21;
    u8 UNK_22;
    u8 UNK_23;
}; // 0x24

// FF: pointer at 0x48 in the generic storage struct
struct FF_StorageStruct_48 {
    /**
     * Judging by how this var is referenced throughout the
     * code, I thought may instead be four standalone vars
     * of the same type, instead of in an array.
     * 
     * But near the end of the file (e.g. in func_8038E968),
     * they're indexed by $a0, so it must be an array...
     */
    struct FF_StorageStruct_48_sub data[4];
}; // 0x90

// FF: generic storage struct
struct FF_StorageStruct {
    /* 00 */ void *UNK_00;
    /* 04 */ void *UNK_04;
    /* 08 */ u16   UNK_08;
    /* 0A */ u8    currFfMode;
    /* 0B */ u8    ffQuestionType;
    /* 0C */ u8    UNK_0C;
    /* 0D */ u8    UNK_0D;
    /* 0E */ s8    UNK_0E;
    /* 0F */ u8    UNK_0F;

    /* 10 */ u8    UNK_10;
    /* 11 */ u8    UNK_11;
    /* 12 */ u8    UNK_12;
    /* 13 */ u8    UNK_13;

    /* 14 */ f32   UNK_14;

    /* 18 */ u8    UNK_18;
    /* 19 */ u8    UNK_19;
    /* 1A */ u8    UNK_1A;
    /* 1B */ u8    UNK_1B;

    // holds moves involved with the FFM glitch
    /* 1C */ u32   unlockedMoves;

    /* 20 */ gczoombox_t *UNK_20;

    /* 24 */ f32   playerPosition[3];

    /* 30 */ f32   playerRotation;

    /* 34 */ u8    UNK_34;
    /* 35 */ u8    UNK_35;
    /* 36 */ u8    UNK_36;
    /* 37 */ u8    UNK_37;

    /* 38 */ u8    UNK_38;
    /* 39 */ u8    UNK_39;
    /* 3A */ u8    UNK_3A;
    /* 3B */ u8    UNK_3B;

    /* 3C */ u16   UNK_3C[5];

    /* 46 */ u8    UNK_46;
    /* 47 */ u8    UNK_47;

    /* 48 */ struct FF_StorageStruct_48 *UNK_48;
}; // 0x4C

extern struct FF_StorageStruct *D_8037DCB8;



extern struct {
    u8 UNK_00;
    u8 UNK_01;
    s16 UNK_02;

    s16 UNK_04;
    u8 UNK_06;
    u8 UNK_07;

    f32 UNK_08;
} D_80394354[]; // unk size

// ?
extern struct {
    s16 UNK_00;
    s16 UNK_01;
} D_803945B8[];

// ?
extern struct {
    s16 UNK_00;
    s16 UNK_01;
} D_803945D0[];

/* .rodata */

extern f32 D_80395100; //! 0.45f
extern f32 D_80395104; //! 0.95f

extern f64 D_80395178; //! 0.333
extern f64 D_80395180; //! 0.666

extern f32 D_80395188; //! 2.2f

// char *debugStr_quiz_longText = "THIS IS A SLIGHTLY LONGER PIECE OF TEXT FOR THE QUIZ DIALOGS!";
extern char debugStr_quiz_longText[];


// FF: get total number of questions per type
s16 func_8038C2C0(enum FF_QuestionType type)
{
    return FF_QuestionTypeInfoArr[type].totalQuestionCount;
}

// FF: clear isAsked flags for current question type
void func_8038C2D4(enum FF_QuestionType type)
{
    s32 i;

    for (i = 0; i < FF_QuestionTypeInfoArr[type].totalQuestionCount; i++)
        func_803208C0(FF_QuestionTypeInfoArr[type].startingFlagIdx + i, FALSE);
}

// FF: set isAsked flag for type and question
void func_8038C338(enum FF_QuestionType type, s32 questionIdx, int val)
{
    func_803208C0(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx, val);
}

// FF: get isAsked flag for type and question
int func_8038C370(enum FF_QuestionType type, s32 questionIdx)
{
    return func_803207F0(FF_QuestionTypeInfoArr[type].startingFlagIdx + questionIdx);
}

struct UNK_80393760 {
    /* 00 */ s16 UNK_00[4];

    /* 08 */ u8 UNK_08;
    /* 09 */ u8 UNK_09;
    /* 0A */ u8 UNK_0A;
    /* 0B */ u8 UNK_0B;

    /* 0C */ u8 UNK_0C[3];
    /* 0F */ u8 UNK_0F;

    /* 10 */ f32 UNK_10;

    /* 14 */ u8 UNK_14;
    /* 15 */ u8 UNK_15;
    /* 16 */ u8 UNK_16;
    /* 17 */ u8 UNK_17;

    /* 18 */ u8 UNK_18;
    /* 19 */ u8 UNK_19;
    /* 1A */ u8 UNK_1A;
    /* 1B */ u8 UNK_1B;

    /* 1C */ u8 UNK_1C;
    /* 1D */ u8 UNK_1D;
    /* 1E */ u8 UNK_1E;
    /* 1F */ u8 UNK_1F;
}; // 0x20

extern struct UNK_80393760 D_80393760[FF_QNF_CNT - 1];

// i love stupid shit like this. these 3 lines of C compile into 150 lines of asm for type handling
void func_8038C3A0(u32 a0, struct UNK_80393760 *a1, struct UNK_80393760 *a2, struct UNK_80393760 *a3)
{
    a2->UNK_0C[0] = a1->UNK_0C[0] * a3->UNK_10;
    a2->UNK_0C[1] = a1->UNK_0C[1] * a3->UNK_10;
    a2->UNK_0C[2] = a1->UNK_0C[2] * a3->UNK_10;
}

void *func_8038C5B8(s32 a0)
{
    struct UNK_80393760 *ptr;

    s32 v0;

    if (!a0)
        return NULL;

    v0  = FF_QNF_START;
    ptr = D_80393760;

    while (v0 < a0)
    {
        v0++;
        ptr++;
    }

    return ptr;
}

void func_8038C610(s32 a0)
{
    func_8034DEB4(func_8034C528(a0 + 200), -3000);
}

void func_8038C640(s32 a0, struct UNK_80393760 *a1)
{
    s32 i;

    for (i = 0; i < ARRLEN(a1->UNK_00); i++)
        if (a1->UNK_00[i])
            func_8038C610(a1->UNK_00[i]);

    a1->UNK_09 = 1;

    func_803208C0(a0 - FF_QNF_CNT, TRUE);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_5ED0/func_8038C6BC.s")
#else
// very close, potential saved double reg issues with .rodata
void func_8038C6BC(void)
{
    s32 s1, s3;

    struct UNK_80393760 *ptr;

    f32 ft1 = D_80395100;
    f32 ft2;

    s3 = 1;

    // TODO: fix single line fakematch after migrating .rodata
    ft2 = D_80395104; ptr = D_80393760; for (s1 = FF_QNF_START; s1 != FF_QNF_END; s1++, ptr++)
    {
        ptr->UNK_09 = func_803207F0(s1 - FF_QNF_CNT) ? 1 : 0;

        if (ptr->UNK_09 == s3)
        {
            ptr->UNK_10 = ft2;
            func_8038C640(s1, ptr);
        }
        else
        {
            ptr->UNK_10 = ft1;
        }

        func_8033F220(D_8037DCB8->UNK_00, s1, &ptr->UNK_0A);
    }
}
#endif

void func_8038C7A0(u32 a0, struct UNK_80393760 *a1, struct UNK_80393760 *a2, struct UNK_80393760 *a3)
{
    a2->UNK_0C[0] = a1->UNK_0C[0] * D_8037DCB8->UNK_14;
    a2->UNK_0C[1] = a1->UNK_0C[1] * D_8037DCB8->UNK_14;
    a2->UNK_0C[2] = a1->UNK_0C[2] * D_8037DCB8->UNK_14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_5ED0/func_8038C9D0.s")

void func_8038CC10(void)
{
    if (D_8037DCB8->UNK_18)
        return;

    D_8037DCB8->UNK_18 = func_8030ED2C(0x1C, 3);
    func_8030DD90(D_8037DCB8->UNK_18, 0);
    func_8030DABC(D_8037DCB8->UNK_18, 32760);
    func_8030DBB4(D_8037DCB8->UNK_18, 0.7f);
    func_8030E2C4(D_8037DCB8->UNK_18);
}

void func_8038CC9C(void)
{
    if (!D_8037DCB8->UNK_18)
        return;

    func_8030E394(D_8037DCB8->UNK_18);
    func_8030DA44(D_8037DCB8->UNK_18);
    D_8037DCB8->UNK_18 = 0;
}

void func_8038CCEC(void)
{
    free(D_8037DCB8->UNK_48);
    D_8037DCB8->UNK_48 = NULL;

    free(D_8037DCB8);
    D_8037DCB8 = NULL;

    func_80319190();
    func_80320818();
    func_802C5994();
}

void func_8038CD48(void)
{
    if (D_8037DCB8 == NULL)
        return;

    /**
     * //! EXPLOIT: FFM (Furnace Fun Moves)
     * Sets moves upon entering SM or MM from the Lair, FF asm code stays
     * latent until then
     */
    func_80295864(D_8037DCB8->unlockedMoves);

    D_8037DCB8->UNK_00 = NULL;

    gczoombox_free(D_8037DCB8->UNK_20);
    D_8037DCB8->UNK_20 = NULL;

    if (D_8037DCB8->UNK_18)
        func_8038CC9C();

    if (!func_803203FC(1) && !func_803203FC(2))
        func_803204E4(0, FALSE);

    if (!func_803203FC(0))
        func_8038CCEC();
}

void func_8038CE00(void)
{
    func_802BBC58(1);
    func_802BAE20(0);
}

void func_8038CE28(void)
{
    s32 i;

    func_80319050();
    D_8037DCB8 = malloc(sizeof(struct FF_StorageStruct));
    func_80320840();

    // dump currently unlocked moves to storage
    D_8037DCB8->unlockedMoves = func_802957F0();

    for (i = 0; i < ARRLEN(D_8037DCB8->UNK_3C); i++)
        D_8037DCB8->UNK_3C[i] = 0;

    // set joker card count to 0
    func_803463F4(0x27, func_80345FA0(0x27) * -1);

    D_8037DCB8->UNK_08     = 0;
    D_8037DCB8->UNK_04     = NULL;
    D_8037DCB8->UNK_20     = NULL;
    D_8037DCB8->UNK_14     = 1.f;
    D_8037DCB8->UNK_18     = 0;
    D_8037DCB8->currFfMode = 1;
    D_8037DCB8->UNK_48     = malloc(0x90);

    func_8038BC24();
}

void func_8038CF18(void)
{
    s32 i;

    struct FF_StorageStruct_48_sub *ptr;

    if (map_get() != MAP_8E_GL_FURNACE_FUN)
        return;

    D_8037DCB8->UNK_00 = func_80309744(0);
    D_8037DCB8->UNK_11 = 0;

    if (func_803203FC(2) && !func_803203FC(4))
    {
        func_80320818();
        func_80320840();

        for (i = 0; i < ARRLEN(D_8037DCB8->UNK_3C); i++)
            D_8037DCB8->UNK_3C[i] = 0;

        // set joker card count to 0
        func_803463F4(0x27, func_80345FA0(0x27) * -1);
    }

    func_8038C6BC();

    ptr = D_8037DCB8->UNK_48->data;

#if 0
    for (i = 0; i < ARRLEN(D_8037DCB8->UNK_48->data); i++)
        ptr[i].UNK_20 = 0;
#else
    // FIXME: weird
    ptr[1].UNK_20 = 0;
    ptr[2].UNK_20 = 0;
    ptr += 3;
    ptr[0].UNK_20 = 0;
    ptr[-3].UNK_20 = 0;
#endif

    func_8029A95C(TRANSFORM_1_BANJO);

    func_80347A14(0);

    if (func_803203FC(1))
    {
        levelSpecificFlags_clear();
        func_8038CE00();
        func_8038D670(FFA_4_UNK);
    }
    else
    {
        if (func_803203FC(2))
        {
            levelSpecificFlags_clear();
            func_8038D670(FFA_5_FORGET_MOVES_2);
        }
        else
        {
            if (func_8031FF1C(BKPROG_A6_FURNACE_FUN_COMPLETE))
                func_8038D670(FFA_8_FURNACE_FUN_COMPLETE);
            else
                func_8038D670(FFA_1_UNK);
        }
    }
}

s32 func_8038D0AC(s32 questionType, s32 a1)
{
    // :morphone: tf
    return 10;
}

void func_8038D0BC(s32 a0, s32 a1)
{
    if (a1 == 2)
    {
        func_80318614(D_8037DCB8->UNK_20, 1);
        // "THIS IS A SLIGHTLY LONGER PIECE OF TEXT FOR THE QUIZ DIALOGS!
        func_803183A4(D_8037DCB8->UNK_20, debugStr_quiz_longText);
    }

    if (a1 == 3)
    {
        func_80318614(D_8037DCB8->UNK_20, 0);
        func_8031841C(D_8037DCB8->UNK_20);
        func_803183FC(D_8037DCB8->UNK_20);
    }

    if (a1 == 6)
    {
        func_8038D670(FFA_4_UNK);
    }
}

void func_8038D16C(s32 a0, u16 a1)
{
    func_8025A6EC(a0, 0);
    func_8025AB44(a0, 28000, 500);
    func_80250530(func_8025ADD4(a0), a1, 0);
}

void func_8038D1BC(void)
{
    func_8025A55C(-1, 500, 9);
}

void func_8038D1E4(void)
{
    f32 cleanupDelay = -1.f;

    func_8025A55C(0, 500, 9);

    switch (D_80394354[D_8037DCB8->UNK_0C].UNK_00)
    {
        case 0:
        {
            timed_playSfx(
                1.f,
                D_80394354[D_8037DCB8->UNK_0C].UNK_02,
                D_80394354[D_8037DCB8->UNK_0C].UNK_08,
                D_80394354[D_8037DCB8->UNK_0C].UNK_04
            );

            cleanupDelay = 2.5f;

            break;
        }
        case 2:
        {
            D_8037DCB8->UNK_20 = gczoombox_new(
                -100,
                D_80394354[D_8037DCB8->UNK_0C].UNK_02,
                0, 0, func_8038D0BC
            );
            func_80318614(D_8037DCB8->UNK_20, 0);
            func_803183EC(D_8037DCB8->UNK_20);
            func_8031840C(D_8037DCB8->UNK_20);

            break;
        }
        case 1:
        {
            func_80324CFC(
                1.f,
                D_80394354[D_8037DCB8->UNK_0C].UNK_02,
                D_80394354[D_8037DCB8->UNK_0C].UNK_04
            );

            cleanupDelay = D_80394354[D_8037DCB8->UNK_0C].UNK_08;

            break;
        }
        case 3:
        {
            timedFunc_set_2(
                0.5f, func_8038D16C,
                D_80394354[D_8037DCB8->UNK_0C].UNK_02,
                D_80394354[D_8037DCB8->UNK_0C].UNK_04
            );

            cleanupDelay = D_80394354[D_8037DCB8->UNK_0C].UNK_08;

            break;
        }
    }

    if (cleanupDelay > 0.0) // f64
        timedFunc_set_1(cleanupDelay, func_8038D670, FFA_4_UNK);
}

void func_8038D394(void)
{
    D_8037DCB8->UNK_12 = 1;
    func_802D5058(
        D_803945D0[D_8037DCB8->UNK_0C].UNK_00,
        D_803945D0[D_8037DCB8->UNK_0C].UNK_01,
        D_8037DCB8->UNK_0D >= 9
    );
}

void func_8038D3F0(s32 a0, s32 a1)
{
    if (a1 == -2)
    {
        D_8037DCB8->UNK_12 = 0;

        if (D_8037DCB8->ffQuestionType == FFQT_2_MUSIC)
            func_8038D1E4();
        else if (D_8037DCB8->ffQuestionType == FFQT_1_PICTURE)
            func_8038D394();
        else
            func_8038D670(FFA_4_UNK);
    }
    else
    {
        D_8037DCB8->UNK_0F = a1;
        func_8038D670(FFA_6_TRIGGER_QUESTION_POST_EFFECTS);
    }
}

void func_8038D48C(void)
{
    func_8028F918(0);
    func_802BAE4C();
    func_802BC280();
}

void func_8038D4BC(void)
{
    func_803204E4(2, TRUE);
    func_802E4A70();

    // restore moves after a delay
    timedFunc_set_1(0.25f,
        func_80295864,
        D_8037DCB8->unlockedMoves
    );

    // trigger warp after a delay
    timedFunc_set_3(0.25f,
        func_802E4078,
        D_803945B8[D_8037DCB8->UNK_0C].UNK_00,
        D_803945B8[D_8037DCB8->UNK_0C].UNK_01,
        1
    );
}

void func_8038D548(s32 a0)
{
    s32 s0;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++)
        func_8038C610(s0);

    if (a0)
        func_8038C610(296);
}

void func_8038D5A0(void)
{
    s32 s0;
    struct UNK_80393760 *ptr = D_80393760;

    for (s0 = FF_QNF_START; s0 != FF_QNF_END; s0++, ptr++)
    {
        func_8038C610(s0);

        ptr->UNK_09 = 1;

        func_803208C0(s0 - FF_QNF_CNT, TRUE);
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
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_5ED0/func_8038D670.s")

// FF: get question type
#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_5ED0/func_8038DCD4.s")
#else
//! needs .rodata for switch
enum FF_QuestionType func_8038DCD4(enum FF_TileType tile)
{
    switch (tile)
    {
        case FFTT_1_BANJO:    return FFQT_0_NORMAL;
        case FFTT_2_PICTURE:  return FFQT_1_PICTURE;
        case FFTT_3_MUSIC:    return FFQT_2_MUSIC;
        case FFTT_4_MINIGAME: return FFQT_4_MINIGAME;
        case FFTT_5_GRUNTY:   return FFQT_3_GRUNTY;
        default: // joker/skull squares
        {
            f32 rng = randf();

            if      (rng < 0.5)                  return FFQT_0_NORMAL;  // 50% chance
            else if (rng < /* 0.7 */ D_80395168) return FFQT_1_PICTURE; // 20% chance of killing the run
            else if (rng < /* 0.9 */ D_80395170) return FFQT_2_MUSIC;   // 20% chance
            else                                 return FFQT_3_GRUNTY;  // 10% chance
        }
    }
}
#endif

// FF: choose level (enum level_e) for picture question (?)
s32 func_8038DDAC(void)
{
    f32 rng = randf();

    if      (rng < /* 0.333 */ D_80395178) return randi2(0, 4);
    else if (rng < /* 0.666 */ D_80395180) return randi2(0, 4) + 4;
    else                                   return randi2(0, 4) + 8;
}

// FF: prepare random unasked question for type
void func_8038DE34(enum FF_QuestionType type)
{
    s32 randQuestionIdx;
    s32 rand;
    s32 tmp;

    D_8037DCB8->UNK_0E = -1;

    if (type == FFQT_0_NORMAL
     || type == FFQT_3_GRUNTY
     || type == FFQT_4_MINIGAME
     || type == FFQT_2_MUSIC)
    {
        /**
         * Handle normal questions, fetch from specific question pool
         */

        do
        {
            // Generate random question index in the valid range for the type
            randQuestionIdx = randi2(0, func_8038C2C0(type));

            // Try again if question already asked
        } while (func_8038C370(type, randQuestionIdx));

        // Save to storage struct
        D_8037DCB8->UNK_0C = randQuestionIdx;
        D_8037DCB8->UNK_0D = D_8037DCB8->UNK_0C;
    }
    else if (type == FFQT_1_PICTURE)
    {
        /**
         * Handle picture question (choosing a level, then choosing a pre-set angle within it)
         */

        D_8037DCB8->UNK_0D = D_8037DCB8->UNK_0C;

        do
        {
            rand = randi2(0, 10);
            tmp  = rand * 0xC;

            if (rand == 9)
            {
                D_8037DCB8->UNK_0C = randi2(0, 10) + tmp;
                D_8037DCB8->UNK_0D = D_8037DCB8->UNK_0C - tmp + 9;
            }
            else
            {
                D_8037DCB8->UNK_0C = func_8038DDAC() + tmp;
                D_8037DCB8->UNK_0D = D_8037DCB8->UNK_0C / 0xC;
            }

            // Try again if question already asked
        } while (func_8038C370(type, D_8037DCB8->UNK_0C));
    }
}

// FF: play timer square sounds
void func_8038DFBC(void)
{
    if (D_8037DCB8->UNK_18)
        return;

    timed_playSfx(0.f,   0x2A, 0.5f, 32760);
    timed_playSfx(0.25f, 0x51, 0.5f, 32760);
    timed_playSfx(0.5f,  0x2A, 0.5f, 32760);
    timed_playSfx(0.75f, 0x51, 0.5f, 32760);

    timedFunc_set_0(1.f,        func_8038CC10);
    timedFunc_set_0(D_80395188, func_8038CC9C);
}

void func_8038E070(void)
{
    func_8028F85C(&D_8037DCB8->playerPosition);
    func_8028F8A4(&D_8037DCB8->playerRotation);
    func_8028F918(2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/lair/code_5ED0/func_8038E0B0.s")

void func_8038E768(Gfx **dl, Mtx **m, Vtx **v)
{
    if (map_get() != MAP_8E_GL_FURNACE_FUN)
        return;

    func_80319214(dl, m, v);
    gczoombox_draw(D_8037DCB8->UNK_20, dl, m, v);
}

void func_8038E7C4(void)
{
    if (func_803203FC(0))
        return;

    func_8038CE28();
    func_803204E4(0, TRUE);
}

/**
 * // TODO: Fix this so it doesn't look like it was written while writhing in epileptic shock
 */
s32 func_8038E800(void)
{
    struct FF_StorageStruct_48_sub *ptr = D_8037DCB8->UNK_48->data;

#if 0
    //! doesn't match!
    {
        s32 i, j;

        for (i = 0; i < ARRLEN(D_8037DCB8->UNK_48->data); i++, ptr++)
        {
            if (ptr->UNK_20 == 0)
            {
                ptr->UNK_20 = 1;

                for (j = 0; j < ARRLEN(ptr->UNK_14); j++)
                    ptr->UNK_14[j] = 0xFF;

                for (j = 0; j < ARRLEN(ptr->UNK_00); j++)
                    ptr->UNK_00[j] = 0;

                ptr->UNK_0C = 500;
                ptr->UNK_10 = 1000;

                return i;
            }
        }
    }
#else
    //! why does a loop not match but this bs does? grant kirkhope pls

    if (ptr->UNK_20 == 0)
    {
        ptr->UNK_14[0] = 0xFF;

        ptr->UNK_0C    = 500;

        ptr->UNK_14[1] = 0xFF;
        ptr->UNK_14[2] = 0xFF;

        ptr->UNK_20    = 1;

        ptr->UNK_00[2] = 0;
        ptr->UNK_00[1] = 0;
        ptr->UNK_00[0] = 0;

        ptr->UNK_10    = 1000;

        return 0;
    }

    ptr++;

    if (ptr->UNK_20 == 0)
    {
        ptr->UNK_0C    = 500;

        ptr->UNK_20    = 1;

        ptr->UNK_14[0] = 0xFF;
        ptr->UNK_14[1] = 0xFF;
        ptr->UNK_14[2] = 0xFF;

        ptr->UNK_00[2] = 0;
        ptr->UNK_00[1] = 0;
        ptr->UNK_00[0] = 0;

        ptr->UNK_10    = 1000;

        return 1;
    }

    ptr++;

    if (ptr->UNK_20 == 0)
    {
        ptr->UNK_0C    = 500;

        ptr->UNK_20    = 1;

        ptr->UNK_14[0] = 0xFF;
        ptr->UNK_14[1] = 0xFF;
        ptr->UNK_14[2] = 0xFF;

        ptr->UNK_00[2] = 0;
        ptr->UNK_00[1] = 0;
        ptr->UNK_00[0] = 0;

        ptr->UNK_10    = 1000;

        return 2;
    }

    ptr++;

    if (ptr->UNK_20 == 0)
    {
        ptr->UNK_20    = 1;

        ptr->UNK_14[0] = 0xFF;
        ptr->UNK_14[1] = 0xFF;

        //! real match! yea just kidding
        do {ptr->UNK_14[2] = 0xFF; ptr->UNK_00[2] = 0; ptr->UNK_00[1] = 0; ptr->UNK_00[0] = 0; ptr->UNK_0C = 500;
            ptr->UNK_10 = 1000;
        } while (0);

        return 3;
    }
#endif

    return -1;
}

void func_8038E968(s32 idx)
{
    if (D_8037DCB8 != NULL && D_8037DCB8->UNK_48 != NULL && idx >= 0)
        D_8037DCB8->UNK_48->data[idx].UNK_20 = 0;
}

void func_8038E9A4(s32 idx, f32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->UNK_48 != NULL && idx >= 0)
    {
        D_8037DCB8->UNK_48->data[idx].UNK_00[0] = a1[0];
        D_8037DCB8->UNK_48->data[idx].UNK_00[1] = a1[1];
        D_8037DCB8->UNK_48->data[idx].UNK_00[2] = a1[2];
    }
}

void func_8038EA10(s32 idx, f32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->UNK_48 != NULL && idx >= 0)
    {
        D_8037DCB8->UNK_48->data[idx].UNK_0C = a1[0];
        D_8037DCB8->UNK_48->data[idx].UNK_10 = a1[1];
    }
}

void func_8038EA68(s32 idx, s32 a1[3])
{
    if (D_8037DCB8 != NULL && D_8037DCB8->UNK_48 != NULL && idx >= 0)
    {
        D_8037DCB8->UNK_48->data[idx].UNK_14[0] = a1[0];
        D_8037DCB8->UNK_48->data[idx].UNK_14[1] = a1[1];
        D_8037DCB8->UNK_48->data[idx].UNK_14[2] = a1[2];
    }
}
