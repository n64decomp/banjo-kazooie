#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/zoombox.h"

extern void item_set(enum item_e, s32);
extern void func_8025A55C(s32, s32, s32);

enum gcquiz_state {
    GCQUIZ_STATE_0_INITIAL, //803197F0
    GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX, //80319910
    GCQUIZ_STATE_2_SHOW_PORTRAITS_FOR_QUESTION, //8031994C
    GCQUIZ_STATE_3_UNKNOWN, //80319B78
    GCQUIZ_STATE_4_UNKNOWN, //80319B78
    GCQUIZ_STATE_5_UNKNOWN, //80319B78
    GCQUIZ_STATE_6_SELECT_QUIZ_ANSWER, //80319B84
    GCQUIZ_STATE_7_CHECK_GIVEN_ANSWER, //80319C0C
    GCQUIZ_STATE_8_UNKNOWN, //80319CFC
    GCQUIZ_STATE_9_UNKNOWN, //80319D6C
    GCQUIZ_STATE_A_UNKNOWN //80319D80
};

typedef struct {
    u8 cmd;
    u8 string_size;
} StringBin_Unused;

typedef struct {
    u8 unk0;
    u8 unk1;
} QuizQuestionBin_Unused;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} QuizQuestionBin;

typedef struct{
    s32 answer_options[4][4]; // first dimension = zoombox index, second dimension = value (0-3), third dimension = answer
} QuizQuestionStruct;

typedef struct {
    s8 question_type; // enum ff_question_type_e
    s8 question_index;
    s8 unk2; // always -1?
    u8 quiz_question_time; // is either 0 or 10 (from __code5ED0_getQuizQuestionTime)
    s32 unk4; // always 0
    void (*unk8)(s32, s8); // gets called with unk4 and unk11
    QuizQuestionBin *unkC; //asset_bin
    u8 state;
    s8 unk11;
    s8 selected_answer_index;
    u8 answer_cursor_index;
    u8 unk14; // relevant for state = 9, from 0 to 4?
    u8 answer_cursor_cooldown;
    u8 unk16; // some value for zoombox (gczoombox_func_803184C8)
    u8 unk17; // some value for zoombox (gczoombox_func_803184C8)
    u8 answer_str_counts[4];
    s8 answer_values[4];
    s8 portait_ids[4];
    GcZoombox *zoomboxes[4];
    QuizQuestionStruct quiz_question;
} Struct_Core2_91E10;

static void __gcquiz_advanceStateTo(enum gcquiz_state state);
static void __gcquiz_func_80319E20(s32 portrait_id, s32 state);
static void __gcquiz_closeZoomboxes(void);

#define SELECTABLE_PORTAIT_COUNT 0x2C

static u8 sPortraits[SELECTABLE_PORTAIT_COUNT+1] = {
    NULL,
    ZOOMBOX_SPRITE_11_CHIMPY,
    ZOOMBOX_SPRITE_12_CONGA,
    ZOOMBOX_SPRITE_13_BLUBBER,
    ZOOMBOX_SPRITE_14_NIPPER,
    ZOOMBOX_SPRITE_15_CLANKER,
    ZOOMBOX_SPRITE_16_SNIPPET,
    ZOOMBOX_SPRITE_17_VILE_4,
    ZOOMBOX_SPRITE_18_TIPTUP,
    ZOOMBOX_SPRITE_19_TANKTUP,
    ZOOMBOX_SPRITE_1A_FLIBBIT,
    ZOOMBOX_SPRITE_1B_TRUNKER,
    ZOOMBOX_SPRITE_1C_RUBEE,
    ZOOMBOX_SPRITE_1D_GOBI,
    ZOOMBOX_SPRITE_1E_GRABBA,
    ZOOMBOX_SPRITE_1F_TEEHEE,
    ZOOMBOX_SPRITE_3B_SNACKER,
    ZOOMBOX_SPRITE_3C_ANCIENT_ONE,
    ZOOMBOX_SPRITE_43_BOGGY,
    ZOOMBOX_SPRITE_44_WOZZA,
    ZOOMBOX_SPRITE_5B_CHEATO,
    ZOOMBOX_SPRITE_64_CROC_BANJO,
    ZOOMBOX_SPRITE_35_JUJU,
    ZOOMBOX_SPRITE_34_TERMITE,
    ZOOMBOX_SPRITE_38_LEAKY,
    ZOOMBOX_SPRITE_37_LITTLE_LOCKUP,
    ZOOMBOX_SPRITE_59_BLACK_SNIPPET,
    ZOOMBOX_SPRITE_39_GLOOP,
    ZOOMBOX_SPRITE_40_CROCTUS,
    ZOOMBOX_SPRITE_33_PIRANHA,
    ZOOMBOX_SPRITE_4B_TWINKLY,
    ZOOMBOX_SPRITE_4C_TWINKLY_CHOMPER,
    ZOOMBOX_SPRITE_3F_JINXY,
    ZOOMBOX_SPRITE_45_MOTZHAND,
    ZOOMBOX_SPRITE_5A_LOGGO,
    ZOOMBOX_SPRITE_3E_SNORKEL,
    ZOOMBOX_SPRITE_4E_BOSS_BOOM_BOX,
    ZOOMBOX_SPRITE_50_NABNUT,
    ZOOMBOX_SPRITE_55_ADULT_EEYRIE,
    ZOOMBOX_SPRITE_4D_GNAWTY,
    ZOOMBOX_SPRITE_4F_ZUBBA,
    ZOOMBOX_SPRITE_36_YUMYUM,
    ZOOMBOX_SPRITE_3D_SAND_EEL,
    ZOOMBOX_SPRITE_3A_TIPTUP_CHOIR_MEMBER,
    ZOOMBOX_SPRITE_67_VILE_5,
};

/* .bss */
Struct_Core2_91E10 *sD_803830E0;

/* .code */
static void __gcquiz_uniquelyRandomizeValuesInPointer(s8 *ptr, u8 min_index, u8 max_index, s32 min_value, s32 max_value){
    s32 i;
    s32 j;
    bool is_unique;

    for (i = min_index; i <= max_index; i++){
        /* assign is_unique random value*/
        do {
            /*assign random value */
            ptr[i] = randi2(min_value, max_value + 1);
            is_unique = TRUE;
            /* test uniqueness */
            for(j = min_index; j < i; j++){
                if (ptr[i] == ptr[j]) {
                    is_unique = FALSE;
                    break;
                }
            }
        } while(is_unique == FALSE);
    }
}

static void __gcquiz_randomizePortaitIds(void) {
    sD_803830E0->portait_ids[0] = 0;
    __gcquiz_uniquelyRandomizeValuesInPointer(sD_803830E0->portait_ids, 1, 3, 1, SELECTABLE_PORTAIT_COUNT);
}

static enum asset_e __gcquiz_get_type_start_id(enum ff_question_type_e question_type) {
    switch(question_type) {
        case FFQT_1_PICTURE: return ASSET_12DB_FF_PICTURE_QUESTION;
        case FFQT_2_SOUND:   return ASSET_13A3_FF_SOUND_QUESTION;
        case FFQT_3_GRUNTY:  return ASSET_1407_FF_GRUNTY_QUESTION;
    }

    return ASSET_1213_FF_QUIZ_QUESTION;
}

static enum asset_e __gcquiz_get_type_end_id(enum ff_question_type_e question_type){
    switch(question_type) {
        case FFQT_1_PICTURE: return ASSET_12ED_FF_PICTURE_QUESTION + 1;
        case FFQT_2_SOUND:   return ASSET_13D5_FF_SOUND_QUESTION + 1;
        case FFQT_3_GRUNTY:  return ASSET_1424_FF_GRUNTY_QUESTION + 1;
    }

    return ASSET_1276_FF_QUIZ_QUESTION + 1;
}


// get correct question index?
static s32 __gcquiz_func_80318F60(enum ff_question_type_e question_type, s32 q_index, s32 arg2) {
    s32 phi_v1;
    s32 phi_a0;

    if (arg2 >= 0) {
        phi_v1 = arg2;
    } else {
        if (question_type == FFQT_3_GRUNTY) {
            phi_a0 = volatileFlag_getN((q_index * 2) + VOLATILE_FLAG_26_FF_GRUNTY_QUESTIONS, 2);
        } else {
            phi_a0 = 0;
        }
        phi_v1 = phi_a0;
    }
    return phi_v1;
}

static bool __gcquiz_isSoundQuestion(enum ff_question_type_e question_type){
    return question_type == FFQT_2_SOUND;
}

static s32 __gcquiz_getZoomboxY(s32 arg0){
    switch(arg0) {
        case 1: return 40;
        case 2: return 80;
        case 3: return 120;
    }

    return 0;
}

static s32 __gcquiz_func_80319004(s32 arg0){
    return arg0 == 0 ? 3 : 2;     
}

static s32 __gcquiz_return0(s32 arg0){
    return 0;
}

static bool __gcquiz_isZero(s32 arg0){
    return arg0 != 0 ? FALSE : TRUE;
}

static f32 __gcquiz_animation_duration(s32 arg0){
    return 0.4f;
}

void gcquiz_init() {
    s32 i;

    sD_803830E0 = malloc(sizeof(Struct_Core2_91E10));
    sD_803830E0->unkC = malloc(0x400);
    sD_803830E0->unk16 = 0x14U;
    sD_803830E0->unk17 = 0x1E;
    sD_803830E0->portait_ids[0] = 0;
    sD_803830E0->zoomboxes[0] = gczoombox_new(__gcquiz_getZoomboxY(0), 0, __gcquiz_func_80319004(0), __gcquiz_return0(0), __gcquiz_func_80319E20);
    gczoombox_func_803184C8(sD_803830E0->zoomboxes[0], (f32)sD_803830E0->unk16, 5, 2, __gcquiz_animation_duration(0), __gcquiz_isZero(0), 0);
    for(i = 1; i < 4; i++){
        sD_803830E0->portait_ids[i] = 0;
        sD_803830E0->zoomboxes[i] = NULL;
    }
    __gcquiz_advanceStateTo(GCQUIZ_STATE_0_INITIAL);
}

void gcquiz_free() {
    s32 i;

    if (sD_803830E0 != NULL) {
        free(sD_803830E0->unkC);
        sD_803830E0->unkC = NULL;
        for(i = 0; i < 4; i++){
            gczoombox_free(sD_803830E0->zoomboxes[i]);
            sD_803830E0->zoomboxes[i] = NULL;
        }
        free(sD_803830E0);
        sD_803830E0 = NULL;
    }
}

void gcquiz_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 i;

    if (sD_803830E0 != NULL) {
        for(i = 0; i < 4; i++){
            gczoombox_draw(sD_803830E0->zoomboxes[i], gfx, mtx, vtx);
        }
    }
}

// randomize quiz question?
static bool __gcquiz_func_803192A4(enum ff_question_type_e q_type, s32 q_index, s32 arg2) {
    char *char_iter;
    enum asset_e quiz_question_index;
    s32 temp_s2;
    s32 str_cnt;
    s32 phi_v1;
    s32 zoombox_text_index;
    s32 phi_a1;
    s32 quiz_question_bin_unk0;
    s32 quiz_question_bin_unk1;
    s32 quiz_question_bin_unk2;
    s32 first_answer_cmd;
    s32 second_answer_cmd;
    s32 third_answer_cmd;
    s32 cmd;
    s32 option_text;

    quiz_question_index = __gcquiz_get_type_start_id(q_type) + q_index;
    if (gcquiz_isNotInInitialState()) {
        return FALSE;
    }

    // not in asset cache?
    if (code_B3A80_func_8033BDAC(quiz_question_index, sD_803830E0->unkC, 0x400) == 0) {
        free(sD_803830E0->unkC);
        sD_803830E0->unkC = (QuizQuestionBin *) assetcache_get(quiz_question_index);
    }

    char_iter = sD_803830E0->unkC;
    quiz_question_bin_unk0 = *(char_iter++); // NEXT
    quiz_question_bin_unk1 = *(char_iter++); // NEXT
    quiz_question_bin_unk2 = *(char_iter++); // NEXT
    first_answer_cmd = ((quiz_question_bin_unk1 >= 2) ? __gcquiz_func_80318F60(q_type, q_index, arg2) : 0) + 1;
    // is sound question or quiz_question_bin_unk2 == 0
    if (((quiz_question_bin_unk2 == 0) || (__gcquiz_isSoundQuestion(q_type) != FALSE)) != FALSE) {
        do {
            second_answer_cmd = randi2(0, quiz_question_bin_unk1 + quiz_question_bin_unk2) + 1;
        } while (second_answer_cmd == first_answer_cmd);
        do {
            third_answer_cmd = randi2(0, quiz_question_bin_unk1 + quiz_question_bin_unk2) + 1;
        } while (third_answer_cmd == first_answer_cmd || third_answer_cmd == second_answer_cmd);
    } else {
        second_answer_cmd = randi2(0, quiz_question_bin_unk2) + quiz_question_bin_unk1 + 1;
        do {
            third_answer_cmd = randi2(0, quiz_question_bin_unk2) + quiz_question_bin_unk1 + 1;
        } while (third_answer_cmd == second_answer_cmd);
    }
        
    char_iter += 2*code94620_func_8031B5B0(); // SKIP
    phi_v1 = *(char_iter++); // NEXT
    phi_v1 += (*(char_iter++) << 8);
    char_iter = (s32)sD_803830E0->unkC + phi_v1;
    str_cnt = *(char_iter++); // NEXT char_iter = 5
    
    for(phi_a1 = 0; phi_a1 < 4; phi_a1++){
        sD_803830E0->answer_str_counts[phi_a1] = 0;
    }

    
    for(phi_a1 = 0; phi_a1 < str_cnt; phi_a1++){
        // cmd = 0x80 - 0x83
        cmd = *(char_iter++); // NEXT char_iter = 6
        option_text = *(char_iter++); // NEXT char_iter = 7
        cmd -= 0x80;

        if ((cmd == 0) || (cmd == first_answer_cmd) || (cmd == second_answer_cmd) || (cmd == third_answer_cmd)) {
            if (cmd == 0) { // grunty
                zoombox_text_index = 0;
            } else if (cmd == first_answer_cmd) { // first answer
                zoombox_text_index = 1;
            } else if (cmd == second_answer_cmd) { // second answer
                zoombox_text_index = 2;
            } else if (cmd == third_answer_cmd) { // third answer
                zoombox_text_index = 3;
            } else{
                zoombox_text_index = zoombox_text_index;
            }
        
            sD_803830E0->quiz_question.answer_options[zoombox_text_index][sD_803830E0->answer_str_counts[zoombox_text_index]++] = char_iter;
        }
        char_iter += option_text; // SKIP
    }
    return TRUE;
}

void __gcquiz_openZoomboxAndMaximizeWithStringsAt(s32 zoombox_index) {
    gczoombox_open(sD_803830E0->zoomboxes[zoombox_index]);
    gczoombox_maximize(sD_803830E0->zoomboxes[zoombox_index]);
    gczoombox_setStrings(
        sD_803830E0->zoomboxes[zoombox_index],
        sD_803830E0->answer_str_counts[sD_803830E0->answer_values[zoombox_index]],
        sD_803830E0->quiz_question.answer_options[sD_803830E0->answer_values[zoombox_index]]
    );
}

void __gcquiz_set_box_highlight(s32 index, bool arg1){
    gczoombox_highlight(sD_803830E0->zoomboxes[index], arg1);
    gczoombox_func_80318C48(sD_803830E0->zoomboxes[index], arg1);
}

static void __gcquiz_advanceStateTo(enum gcquiz_state state){
    s32 i;
    s32 j;

    switch(state){
        case GCQUIZ_STATE_0_INITIAL:
            sD_803830E0->question_type = 0;
            sD_803830E0->question_index = 0;
            sD_803830E0->quiz_question_time = 0;
            sD_803830E0->unk8 = NULL;
            sD_803830E0->selected_answer_index = -1;
            sD_803830E0->unk14 = 0;
            sD_803830E0->unk11 = -2;
            gczoombox_func_803184C8(sD_803830E0->zoomboxes[0], (f32) sD_803830E0->unk16, 5, 2, __gcquiz_animation_duration(0), __gcquiz_isZero(0), 0);
            gczoombox_setUnk13ATo0(sD_803830E0->zoomboxes[0]);
            gczoombox_highlight(sD_803830E0->zoomboxes[0], TRUE);
            for(i = 0; i < 4; i++){
                sD_803830E0->answer_values[i] = -1;
                for(j = 0; j < 4; j++){
                    sD_803830E0->quiz_question.answer_options[i][j] = NULL;
                }
            }
            break;

        case GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX:
            gczoombox_open(sD_803830E0->zoomboxes[0]);
            gczoombox_maximize(sD_803830E0->zoomboxes[0]);
            gczoombox_setStrings(sD_803830E0->zoomboxes[0], sD_803830E0->answer_str_counts[0], sD_803830E0->quiz_question.answer_options[0]);
            break;

        case GCQUIZ_STATE_2_SHOW_PORTRAITS_FOR_QUESTION:
            if (sD_803830E0->question_type != -1) {
                __gcquiz_randomizePortaitIds();
                for(i = 1; i < 4; i++){
                    sD_803830E0->zoomboxes[i] = gczoombox_new(__gcquiz_getZoomboxY(i), sPortraits[sD_803830E0->portait_ids[i]], __gcquiz_func_80319004(i), __gcquiz_return0(i), __gcquiz_func_80319E20);
                    gczoombox_func_803184C8(sD_803830E0->zoomboxes[i], (f32)sD_803830E0->unk17, 5, 2, __gcquiz_animation_duration(i), __gcquiz_isZero(i), 0);
                }
            } else {
                for(i = 1; i < 4; i++){
                    sD_803830E0->zoomboxes[i] = gczoombox_new(__gcquiz_getZoomboxY(i), sD_803830E0->portait_ids[i], 1, __gcquiz_return0(i), __gcquiz_func_80319E20);
                    gczoombox_func_803184C8(sD_803830E0->zoomboxes[i], (f32)sD_803830E0->unk17, 5, 2, __gcquiz_animation_duration(i), __gcquiz_isZero(i), 0);
                }
            }
            timedFunc_set_1(0.0f, __gcquiz_advanceStateTo, GCQUIZ_STATE_3_UNKNOWN);
            timedFunc_set_1(0.0f, __gcquiz_openZoomboxAndMaximizeWithStringsAt, 1);
            timedFunc_set_1(0.2f, __gcquiz_openZoomboxAndMaximizeWithStringsAt, 2);
            timedFunc_set_1(0.4f, __gcquiz_openZoomboxAndMaximizeWithStringsAt, 3);
            break;

        case GCQUIZ_STATE_3_UNKNOWN: 
        case GCQUIZ_STATE_4_UNKNOWN: 
        case GCQUIZ_STATE_5_UNKNOWN: 
            break;

        case GCQUIZ_STATE_6_SELECT_QUIZ_ANSWER:
            item_set(ITEM_0_HOURGLASS_TIMER, sD_803830E0->quiz_question_time * 60 - 1);
            item_set(ITEM_6_HOURGLASS, TRUE);
            sD_803830E0->answer_cursor_cooldown = 0;
            sD_803830E0->answer_cursor_index = 1U;

            for (i = 1; i < 4; i++) {
                __gcquiz_set_box_highlight(i, BOOL(i == sD_803830E0->answer_cursor_index));
            }

            break;

        case GCQUIZ_STATE_7_CHECK_GIVEN_ANSWER:
            if (sD_803830E0->question_type != -1) {
                 sD_803830E0->unk11 = (sD_803830E0->selected_answer_index == -1)                   ? -1
                                   : (sD_803830E0->answer_values[sD_803830E0->selected_answer_index] == 1) ? 1
                                   : 0;
            } else {
                sD_803830E0->unk11 = (s8) sD_803830E0->selected_answer_index;
            }
            if (sD_803830E0->selected_answer_index != -1) {
                for(i = 1; i < 4; i++){
                    if (i != sD_803830E0->selected_answer_index) {
                        gczoombox_minimize(sD_803830E0->zoomboxes[i]);
                        gczoombox_close(sD_803830E0->zoomboxes[i]);
                    } else {
                        gczoombox_func_80318C48(sD_803830E0->zoomboxes[i], FALSE);
                    }
                }
            }
            timedFunc_set_1(1.0f, __gcquiz_advanceStateTo, GCQUIZ_STATE_8_UNKNOWN);
            item_set(ITEM_6_HOURGLASS, FALSE);
            break;

        case GCQUIZ_STATE_8_UNKNOWN:
            if (sD_803830E0->question_type != -1) {
                comusic_playTrack((sD_803830E0->unk11 == 1)? COMUSIC_2B_DING_B : COMUSIC_2C_BUZZER);
            } else {
                comusic_playTrack(COMUSIC_2B_DING_B);
            }
            timedFunc_set_1(1.0f, __gcquiz_advanceStateTo, GCQUIZ_STATE_9_UNKNOWN);
            break;

        case GCQUIZ_STATE_9_UNKNOWN:
            __gcquiz_closeZoomboxes();
            break;

        case GCQUIZ_STATE_A_UNKNOWN:
            if (sD_803830E0->unk8 != NULL) {
                sD_803830E0->unk8(sD_803830E0->unk4, sD_803830E0->unk11);
            }
            for(i = 1; i < 4; i++){
                gczoombox_free(sD_803830E0->zoomboxes[i]);
                sD_803830E0->zoomboxes[i] = NULL;
            }
            func_8025A55C(-1, 500, 10);
            break;
            
        default:
            break;
    }
    sD_803830E0->state = state;
}

void __gcquiz_func_80319E20(s32 portrait_id, s32 zoombox_state) {
    if (zoombox_state == 3) {
        if (portrait_id == sD_803830E0->portait_ids[0]) {
            if (sD_803830E0->unk8 != NULL) {
                sD_803830E0->unk8(sD_803830E0->unk4, sD_803830E0->unk11);
            }
        } else {
            __gcquiz_advanceStateTo(sD_803830E0->state + 1);
        }
    } else if (zoombox_state == 5) {
        sD_803830E0->unk14++;
    }
}

// handle selection in zoombox?
void gcquiz_func_80319EA4(void) {
    s32 face_button_states[6];
    f32 joystick_states[3];
    s32 phi_s0;
    f32 sp44;

    if(getGameMode() != GAME_MODE_3_NORMAL && func_802E4A08() == FALSE)
        return;
    
    if(sD_803830E0 == NULL)
        return;

    func_8024E55C(0, face_button_states);
    controller_getJoystick(0, joystick_states);
    for(phi_s0 = 0; phi_s0 < 4; phi_s0++){
        gczoombox_update(sD_803830E0->zoomboxes[phi_s0]);
    }

    switch (sD_803830E0->state) {
    case GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX:
        if (func_8028EFC8() && (face_button_states[FACE_BUTTON(BUTTON_B)] == 1)) {
            sp44 = __gcquiz_animation_duration(0);
            gczoombox_func_803184C8(sD_803830E0->zoomboxes[0], 100.0f, 2, 4, sp44, __gcquiz_isZero(0), 0);
            return;
        }
        break;
    case GCQUIZ_STATE_6_SELECT_QUIZ_ANSWER:
        if (sD_803830E0->answer_cursor_cooldown > 0) {
            sD_803830E0->answer_cursor_cooldown--;
        } else {
            if (joystick_states[1] > 0.75) {
                if (sD_803830E0->answer_cursor_index >= 2) {
                    __gcquiz_set_box_highlight(sD_803830E0->answer_cursor_index, FALSE);
                    sD_803830E0->answer_cursor_index--;
                    __gcquiz_set_box_highlight(sD_803830E0->answer_cursor_index, TRUE);
                    gczoombox_func_803160A8(sD_803830E0->zoomboxes[sD_803830E0->answer_cursor_index]);
                    sD_803830E0->answer_cursor_cooldown = 4U;
                }
            } else if (joystick_states[1] < -0.75) {
                if (sD_803830E0->answer_cursor_index < 3) {
                    __gcquiz_set_box_highlight(sD_803830E0->answer_cursor_index, FALSE);
                    sD_803830E0->answer_cursor_index++;
                    __gcquiz_set_box_highlight(sD_803830E0->answer_cursor_index, TRUE);
                    gczoombox_func_803160A8(sD_803830E0->zoomboxes[sD_803830E0->answer_cursor_index]);
                    sD_803830E0->answer_cursor_cooldown = 4U;
                }
            }
        }
        if ((face_button_states[FACE_BUTTON(BUTTON_A)] == 1) || (item_empty(ITEM_0_HOURGLASS_TIMER))) {
            sD_803830E0->selected_answer_index = (u8) sD_803830E0->answer_cursor_index;
        }
        if ((s8) sD_803830E0->selected_answer_index != -1) {
            __gcquiz_advanceStateTo(GCQUIZ_STATE_7_CHECK_GIVEN_ANSWER);
            return;
        }
        break;
    case GCQUIZ_STATE_9_UNKNOWN:
        if (sD_803830E0->unk14 == 4) {
            __gcquiz_advanceStateTo(GCQUIZ_STATE_A_UNKNOWN);
            return;
        }
        break;
    case GCQUIZ_STATE_A_UNKNOWN:
        __gcquiz_advanceStateTo(GCQUIZ_STATE_0_INITIAL);
        break;
    }
}

bool gcquiz_func_8031A154(enum ff_question_type_e q_type, s32 q_index, s32 arg2, s32 arg3, s32 arg4, void (*arg5)(s32, s8)) {
    if (__gcquiz_func_803192A4(q_type, q_index, arg2) != FALSE) {
        sD_803830E0->question_type = q_type;
        sD_803830E0->question_index = q_index;
        sD_803830E0->unk2 = arg2;
        sD_803830E0->quiz_question_time = arg3;
        sD_803830E0->unk4 = arg4;
        sD_803830E0->unk8 = arg5;
        item_set(ITEM_6_HOURGLASS, FALSE);
        __gcquiz_uniquelyRandomizeValuesInPointer(sD_803830E0->answer_values, 1, 3, 1, 3);
        func_8025A55C(6000, 500, 10);
        __gcquiz_advanceStateTo(GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX);
        return TRUE;
    }

    return FALSE;
}

// unused but making this static differs checksum
bool __gcquiz_unused(u8 *arg0, s8 *arg1, QuizQuestionStruct *arg2, s32 arg3, void (*arg4)(s32, s8)) {
    s32 temp_v0;
    s8 *temp_a2;
    s8 *temp_s0;
    s8 temp_a1;
    s8 temp_a1_2;
    u8 *phi_t0;
    s32 i;
    s8 *phi_a2;
    s32 *phi_a0;
    s32 phi_v1;
    s32 j;
    s8 *phi_s0;

    if (gcquiz_isNotInInitialState()) {
        return FALSE;
    }

    for(i = 0; i < 4; i++){
        sD_803830E0->portait_ids[i] = arg0[i];
        sD_803830E0->answer_str_counts[i] = arg1[i];
        for(j = 0; j < arg1[i]; j++){
            sD_803830E0->quiz_question.answer_options[i][j] = arg2->answer_options[i][j];
        }
        sD_803830E0->answer_values[i] = i;
    }
    if (sD_803830E0->portait_ids[0] != NULL) {
        gczoombox_loadSprite(sD_803830E0->zoomboxes[0], sD_803830E0->portait_ids[0]);
    }
    sD_803830E0->question_type = -1;
    sD_803830E0->question_index = -1;
    sD_803830E0->unk2 = -1;
    sD_803830E0->quiz_question_time = (s8) arg3;
    sD_803830E0->unk4 = 0;
    sD_803830E0->unk8 = arg4;
    func_8025A55C(6000, 500, 10);
    __gcquiz_advanceStateTo(GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX);
    return TRUE;
}

// unused but making this static differs checksum
void __gcquiz_unused2(u8 arg0, u8 arg1) {
    if (sD_803830E0 != NULL) {
        sD_803830E0->unk16 = arg0;
        sD_803830E0->unk17 = arg1;
    }
}

bool gcquiz_isNotInInitialState(){
    return (sD_803830E0 != NULL) ? sD_803830E0->state != GCQUIZ_STATE_0_INITIAL: FALSE;
}

static void __gcquiz_closeZoomboxes(){
    s32 i;
    if(sD_803830E0 != NULL){
        for(i = 0; i < 4; i++){
            gczoombox_minimize(sD_803830E0->zoomboxes[i]);
            gczoombox_close(sD_803830E0->zoomboxes[i]);
        }
    }
}

// unused but making this static differs checksum
s32 gcquiz_unused3(){
    return 4;
}

s32 gcquiz_getLastIndexOfQuestionType(enum ff_question_type_e question_type) {
    return __gcquiz_get_type_end_id(question_type) - __gcquiz_get_type_start_id(question_type);
}

void gcquiz_func_8031A48C(void) {
    if ((sD_803830E0 != NULL) && (sD_803830E0->state == GCQUIZ_STATE_1_SHOW_QUESTION_VIA_ZOOMBOX)) {
        __gcquiz_advanceStateTo(GCQUIZ_STATE_2_SHOW_PORTRAITS_FOR_QUESTION);
    }
}

void gcquiz_defrag() {
    s32 i;

    if (sD_803830E0 != NULL) {
        for(i = 0; i < 4; i++){
            gczoombox_defrag(sD_803830E0->zoomboxes[i]);
            sD_803830E0->zoomboxes[i] = (GcZoombox *)defrag(sD_803830E0->zoomboxes[i]);
        }

        if (gcquiz_isNotInInitialState() == FALSE) {
            sD_803830E0->unkC = (QuizQuestionBin *)defrag(sD_803830E0->unkC);
        }
        sD_803830E0 = (Struct_Core2_91E10 *)defrag(sD_803830E0);
    }
}
