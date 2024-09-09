#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80258640(f32[3], f32[3]);

typedef struct {
    s32 unk0;
} ActorLocal_lair_5640;

void chBrentilda_update(Actor *this);

/* .data */
ActorAnimationInfo chBrentildaAnimations[] ={
    {0, 0.0f},
    {0x26B, 4.0f},
    {0x26C, 4.0f},
    {0x26B, 4.0f},
};
ActorInfo chBrentilda = { 0x1E0, 0x348, 0x539, 0x1, chBrentildaAnimations, chBrentilda_update, func_80326224, actor_draw, 2000, 0, 2.0f, 0};

/* .code */
void func_8038BA30(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;
    s32 phi_v1;

    this = marker_getActor(marker);
    phi_v1 = this->unk10_12*2;
    volatileFlag_getN(VOLATILE_FLAG_20_BEGIN_CHARACTER_PARADE + this->unkF4_8*6 + phi_v1, 2);
}

void lair_func_8038BA88(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    item_set(ITEM_14_HEALTH, item_getCount(ITEM_15_HEALTH_TOTAL));
    fileProgressFlag_set(this->unkF4_8 - 1 + FILEPROG_E9_HEALED_BY_BRENTILDA_1, TRUE);
}

void func_8038BADC(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *this;  

    this = marker_getActor(marker);
    if (text_id == ((ActorLocal_lair_5640 *)&this->local)->unk0 + 2) {
        if (!fileProgressFlag_get(this->unkF4_8 - 1 + FILEPROG_E9_HEALED_BY_BRENTILDA_1)) {
            if (item_getCount(ITEM_14_HEALTH) < item_getCount(ITEM_15_HEALTH_TOTAL)) {
                func_80311480(0x10A2, 0xF, this->position, this->marker, func_8038BADC, lair_func_8038BA88);
                return;
            }
        }
        func_80311480(0xD38, 0xC, this->position, this->marker, func_8038BADC, NULL);
        return;
    }
    subaddie_set_state(this, 1);
}

void func_8038BBC0(Actor *this) {
    if (this->unk38_0) {
        comusic_8025AB44(COMUSIC_7A_BRENTILDA, 0, 10000);
        func_8025AABC(COMUSIC_7A_BRENTILDA);
        func_8032BB88(this, -1, 10000);
        this->unk38_0 = FALSE;
    }
}

void gzquiz_initGruntyQuestions(void) {
    s32 pattern;
    enum volatile_flags_e question_id;
    s32 i;

    if (fileProgressFlag_get(FILEPROG_5C_FF_PATTERN_SET) && !volatileFlag_get(VOLATILE_FLAG_62_FF_GRUNTY_QUESTIONS_INITIALIZED)) {
        rand_seed(fileProgressFlag_getN(FILEPROG_D3_FF_PATTERN, 8));

        for(i = 0; i < func_8031A45C(FFQT_3_GRUNTY); i++){
            question_id = VOLATILE_FLAG_26_FF_GRUNTY_QUESTIONS + 2 * i;
            pattern = randi2(0, 3);

            if (question_id >= 0x61) {
                volatileFlag_setN(VOLATILE_FLAG_26_FF_GRUNTY_QUESTIONS, pattern, 2);
            } else {
                volatileFlag_setN(question_id, pattern, 2);
            }
        }

        volatileFlag_set(VOLATILE_FLAG_62_FF_GRUNTY_QUESTIONS_INITIALIZED, 1);
    }
}


void chBrentilda_update(Actor *this) {
    s32 sp78[6];
    s32 sp74;
    ActorLocal_lair_5640 *local;
    f32 sp64[3];
    f32 temp_f0;
    f32 phi_f2;
    f32 sp50[3];
    s16 sp48[3];


    local = (ActorLocal_lair_5640 *)&this->local;
    if (!this->initialized) {
        marker_setFreeMethod(this->marker, func_8038BBC0);
        actor_collisionOff(this);
        this->unk10_12 = 2;
        if (!fileProgressFlag_get(FILEPROG_5C_FF_PATTERN_SET)) {
            fileProgressFlag_setN(FILEPROG_D3_FF_PATTERN, randi2(0, 0x100), 8);
            fileProgressFlag_set(FILEPROG_5C_FF_PATTERN_SET, TRUE);
        }
        gzquiz_initGruntyQuestions();
        actor_setOpacity(this, 0x40);
        this->initialized = TRUE;
    }

    if (!this->unk16C_4) {
        local->unk0 = this->unkF4_8*3 + 0x1080;
        this->unk16C_4 = TRUE;
    }

    func_8028E668(this->position, 280.0f, -40.0f, 160.0f);
    this->yaw_ideal = (f32) func_80329784(this);
    func_80328FB0(this, 3.0f);
    func_8024E55C(0, sp78);
    player_getPosition(sp64);
    temp_f0 = sp64[1] - this->position[1];
    if ((temp_f0 > -100.0f) && (temp_f0 < 350.0f)) {
        phi_f2 = func_80258640(sp64, this->position);
    } else {
        phi_f2 = 2000.0f;
    }
    if ((phi_f2 < 500.0) && (this->unk38_31  & 1)) {
        func_80329904(this->marker, 0x1F, sp50);
        sp48[0] = (s16)sp50[0];
        sp48[1] = (s16)sp50[1];
        sp48[2] = (s16)sp50[2];
        fxSparkle_brentilda(sp48);
    }
    
    this->unk38_31++;
    switch (this->state) {
    case 1:
        sp74 = func_8032627C(this);
        if (phi_f2 < 500.0) {
            if (sp74 < 0xFF) {
                sp74 = (sp74 + 0xC < 0xFF) ? sp74 + 0xC : 0xFF;
                if (!this->is_first_encounter) {
                    func_8025A70C(COMUSIC_81_ACTIVATING_BRENTILDA);
                    func_80324D2C(1.0f, COMUSIC_81_ACTIVATING_BRENTILDA);
                    this->is_first_encounter = TRUE;
                    this->unk138_23 = FALSE;
                }
            }
        }

        if (500.0 < phi_f2) {
            if (sp74 >= 0x41) {
                sp74 = (sp74 - 0xC >= 0x41) ? sp74 - 0xC : 0x40;
                if (!this->unk138_23) {
                    func_8025A70C(COMUSIC_8B_DEACTIVATE_BRENTILDA);
                    func_80324D2C(1.0f, COMUSIC_8B_DEACTIVATE_BRENTILDA);
                    this->unk138_23 = TRUE;
                    this->is_first_encounter = FALSE;
                }
            }
        }
        actor_setOpacity(this, sp74);
        if (!volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) {
            if ((phi_f2 < 600.0) && !this->unk38_0) {
                comusic_8025AB44(COMUSIC_7A_BRENTILDA, -1, 0x1F4);
                func_8032BB88(this, 0, 0x1F4);
                this->unk38_0 = TRUE;
            }
            if ((600.0 < phi_f2) && this->unk38_0) {
                comusic_8025AB44(COMUSIC_7A_BRENTILDA, 0, 0x1F4);
                func_8025AABC(0x7A);
                func_8032BB88(this, -1, 0x1F4);
                this->unk38_0 = FALSE;
            }
        }
        if( (phi_f2 < 300.0) 
            && (func_8028ECAC() == 0) 
            && func_8028F20C()
            && !func_803114B0()) {
            if (!fileProgressFlag_get(FILEPROG_96_MET_BRENTILDA)) {
                func_80311480(ASSET_10A1_DIALOG_BRENTILDA_MEET, 0xA, this->position, this->marker, func_8038BADC, NULL);
                fileProgressFlag_set(FILEPROG_96_MET_BRENTILDA, TRUE);
                subaddie_set_state(this, 2);
                return;
            }
            if (func_8028EFC8() && (sp78[FACE_BUTTON(BUTTON_B)] == 1)) {
                this->unk10_12++;
                this->unk10_12 %= 3;
                func_80311174(local->unk0 + this->unk10_12, 0xB, this->position, this->marker, func_8038BADC, NULL, func_8038BA30);
                subaddie_set_state(this, 2);
                return;
            }
        } else {
            return;
        }
        break;
    case 2:
        if (actor_animationIsAt(this, 0.999f)) {
            subaddie_set_state(this, 3);
            return;
        }
        break;
    case 3:
        if (actor_animationIsAt(this, 0.999f)) {
            subaddie_set_state(this, 2);
        }
        break;
    }
}
