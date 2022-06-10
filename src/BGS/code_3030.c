#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32  func_80256AB4(f32, f32, f32, f32);
extern void func_802FDCB8(s32);


typedef struct {
    s32 unk0;
    f32 position[3];
    ActorMarker *marker; //yumblie ptr;
}Struct_BGS_3030_0;

typedef struct {
    u8 unk0;
    // u8 pad1[3];
    vector(Struct_BGS_3030_0) *unk4;
    BKModelBin *unk8;
    u8 unkC;
    u8 unkD;
    u8 player_score;
    u8 vile_score;
    f32 unk10;
    ActorMarker *unk14;
}ActorLocal_BGS_3030;

void func_8038AD94(Actor *this);
/* .data */
ActorInfo D_80390960 = {0xC6, 0x138, 0, 0, NULL, func_8038AD94, NULL, func_80325340, {0, 0}, 0, 0.0f, {0,0,0,0}};
enum asset_e D_80390984[] = {    0, 0xC66, 0xC68, 0xC6A, 0xC92, 0xC93, 0xC94,    0};
enum asset_e D_803909A4[] = {    0, 0xC67, 0xC69,     0, 0xC95, 0xC96, 0xC97};
enum asset_e D_803909C0[] = {    0, 0xC6E, 0xC6F,     0, 0xC95, 0xC96, 0xC97};
enum asset_e D_803909DC[] = {0xC65, 0xC65, 0xC65, 0xC8F,     0,     0,     0};
enum asset_e D_803909F8[] = {0xC64,     0,     0, 0xC8E,     0,     0,     0,    0}; 
enum asset_e D_80390A18[] = {0xC6D, 0xC70, 0xC71, 0xC8E,     0,     0,     0,    0};

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_803895D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389668.s")


//BREAK???============
bool func_80389810(f32 arg0[3]) {
    if (func_8028ECAC() != 7) {
        return FALSE;
    }
    func_8028E9C4(2, arg0);
    return TRUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389850.s")

void func_80389B48(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    if(arg2 == 1){
        func_8038A068(this, 4);
    }
    else{
        func_8038A068(this, 3);
    }
}

void func_80389B98(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_8038A068(this, 1);
}

void func_80389BC8(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_8038A068(this, 5);
}

void func_80389BF8(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    Actor *this;
    ActorLocal_BGS_3030 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    func_80324E88(0.0f);
    func_80324E38(0.0f, 0);
    local->unkC--;
    func_8038A068(this, 7);
}

void func_80389C58(ActorMarker *marker) {
    Actor *this;
    ActorLocal_BGS_3030 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    func_80389850(this, 0);
    func_80311480(D_80390984[local->unkC], 0xF, func_8038C284(local->unk14), this->marker, func_80389BF8, NULL);
}

void func_80389CD8(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_80324E88(0.0f);
    func_80324E38(0.0f, 0);
    func_8038A068(this, 5);
}

void func_80389D20(ActorMarker *marker) {
    Actor *this;
    ActorLocal_BGS_3030 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    func_80389850(this, 0);
    if (local->unkC == local->unkD) {
        func_80311480(D_803909A4[local->unkC], 0xF, func_8038C284(local->unk14), this->marker, func_80389CD8, NULL);
    } else {
        func_80311480(D_803909C0[local->unkC], 0xF, func_8038C284(local->unk14), this->marker, func_80389CD8, NULL);
    }
    func_80347A14(0);
}

void func_80389DF8(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_80324E88(0.0f);
    func_80324E38(0.0f, 0);
    func_8038A068(this, 1);
}

void func_80389E40(ActorMarker *marker) {
    Actor *this;
    ActorLocal_BGS_3030 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;

    func_80389850(this, 1);
    func_80311480(0xC6B, 0xF, func_8038C284(local->unk14), this->marker, func_80389DF8, NULL);
}

void func_80389EAC(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;
    ActorLocal_BGS_3030 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    func_80324E88(0.0f);
    func_80324E38(0.0f, 0);
    local->unkC = 3;
    func_8038A068(this, 1);
}

void func_80389F08(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_80389F08.s")

void func_8038A044(void){
    func_8025A58C(-1, 400);
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/BGS/code_3030/func_8038A068.s")
#else
void func_8038A068(Actor *this, s32 next_state) {
    ActorLocal_BGS_3030 *local;

    local = (ActorLocal_BGS_3030 *)&this->local;
    mapSpecificFlags_set(6, FALSE);
    if (next_state == 1) {
        if (local->unk14 != NULL) {
            func_8038C408(local->unk14);
        }
    }
    if (next_state == 2) {
        func_8038C3B0(local->unk14);
        if (local->unkC == 3) {
            if (local->unkD >= 4) {
                func_80311480(0xC91, 0xE, func_8038C284(local->unk14), this->marker, func_80389B48, NULL);
            } else {
                func_80311480((local->unkC == local->unkD) ? 0xC8D : 0xC90, 0xE, func_8038C284(local->unk14), this->marker, func_80389B48, NULL);
            }
        } else {
            func_80311480((local->unkC == local->unkD) ? 0xC63 : 0xC6C, 0xE, func_8038C284(local->unk14), this->marker, func_80389B48, NULL);
        }
    }
    if (next_state == 3) {
        func_80311480(D_803909DC[local->unkC], 4, func_8038C284(local->unk14), this->marker, func_80389B98, NULL);
    }
    if (next_state == 4) {
        if (local->unkC == local->unkD) {
            func_80311480(D_803909F8[local->unkC], ((D_803909F8[local->unkC] == 0xC8E) ? 1 : 0) | 0xE, func_8038C284(local->unk14), this->marker, func_80389BC8, NULL);
        } else {
            func_80311480(D_80390A18[local->unkC], 0xF , func_8038C284(local->unk14), this->marker, func_80389BC8, NULL);
        }
        func_80347A14(0);
    }
    if (next_state == 5) {
        local->unkC++;
        if (local->unkD < local->unkC) {
            local->unkD = local->unkC;
        }
        if (local->unkC == 7) {
            func_8038C434(local->unk14);
        } else {
            local->unk0 = 0;
            local->player_score = 0;
            local->vile_score = 0;
            if (func_803203FC(2) != 0) {
                local->unk10 = 5.0f;
            } else {
                local->unk10 = 10.0f;
            }
            item_set(ITEM_0_HOURGLASS_TIMER, 3600-1);
            item_set(ITEM_6_HOURGLASS, TRUE);
            mapSpecificFlags_set(6, TRUE);
            func_8038C3DC(local->unk14);
            func_8025A58C(0, 4000);
            timedFunc_set_2(1.0f, func_8025A6EC, COMUSIC_55_BGS_MR_VILE, 28000);
        }
    }
    if (this->state == 5) {
        if (local->unkC != 7) {
            item_set(6, 0, this);
            if ((next_state != 6) && (next_state != 8) && (next_state != 9)) {
                func_8038A044();
            }
        }
        func_8038C460(local->unk14);
        func_80347A14(1);
    }
    if (next_state == 6) {
        func_8038C3B0(local->unk14);
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, func_8025A6EC, COMUSIC_3C_MINIGAME_LOSS, 28000);
        timedFunc_set_0(4.0f, func_8038A044);
        timedFunc_set_1(4.0f, func_80389C58, (s32) this->marker);
    }
    if (next_state == 8) {
        func_8038C3B0(local->unk14);
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, func_8025A6EC, COMUSIC_3B_MINIGAME_VICTORY, 28000);
        timedFunc_set_0(3.0f, func_8038A044);
        timedFunc_set_1(3.0f, func_80389D20, (s32) this->marker);
    }
    if (next_state == 9) {
        func_8038C3B0(local->unk14);
        func_80324E38(0.0f, 3);
        timedFunc_set_2(1.0f, func_8025A6EC, COMUSIC_3B_MINIGAME_VICTORY, 28000);
        timedFunc_set_0(3.0f, func_8038A044);
        timedFunc_set_1(3.0f, func_80389E40, (s32) this->marker);
    }
    if (next_state == 0xA) {
        func_8038C3B0(local->unk14);
        func_80324E38(0.5f, 3);
        timedFunc_set_2(1.0f, func_8025A6EC, COMUSIC_3B_MINIGAME_VICTORY, 28000);
        timedFunc_set_1(3.0f, func_80389F08, (s32) this->marker);
    }
    if (next_state == 7) {
        func_8038C384(local->unk14);
    }
    this->state = next_state;
}
#endif

void func_8038A6AC(Actor *this) {
    ActorLocal_BGS_3030 *local;
    s32 sp50;
    s32 temp_t6;
    volatile f32 sp48;
    f32 sp44;
    Struct_BGS_3030_0 *begin;
    Struct_BGS_3030_0 *end;
    Struct_BGS_3030_0 *i_ptr;


    local = (ActorLocal_BGS_3030 *)&this->local;

    begin = (Struct_BGS_3030_0 *)vector_getBegin(local->unk4);
    end = (Struct_BGS_3030_0 *) vector_getEnd(local->unk4);
    if ((end != begin) && func_80389810(&sp44)){
        sp48 = 0.0f;
        for(i_ptr = begin; i_ptr < end; i_ptr++){
            if ((func_80256064(i_ptr->position, &sp44) < 65.25) && (func_8038B4E4(i_ptr->marker) != 0)) {
                sp50 = ((local->unk0 != 0) && (i_ptr->unk0 != 0)) || (((local->unk0 == 0) && i_ptr->unk0 == 0));
                if (sp50 != 0) {
                    local->player_score++;
                    if (local->player_score == 35) {
                        item_inc(ITEM_16_LIFE);
                        func_8025A6EC(COMUSIC_15_EXTRA_LIFE_COLLECTED, 0x7FF8);
                    }
                    timedFunc_set_1(0.0f, func_802FDCB8, 0x1A);
                    timedFunc_set_1(0.5f, func_802FDCB8, 0x1A);
                    timedFunc_set_1(1.0f, func_802FDCB8, 0x1A);
                }
                func_8028F6B8(0x17, (i_ptr->unk0 != 0) ? 0x3F7 : 0x3F6);
                if (sp50 == 0) {
                    func_8028F66C(0x18);
                }
                func_8038B684(i_ptr->marker);
                return;
            }
        }
    }
}

bool func_8038A86C(ActorMarker *marker, f32 position[3]) {
    Actor *this;
    ActorLocal_BGS_3030 *local;
    Struct_BGS_3030_0 *begin;
    Struct_BGS_3030_0 *end;
    Struct_BGS_3030_0 *i_ptr;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    if (this->state != 5){
        return 0;
    }
    begin = vector_getBegin(local->unk4);
    end = vector_getEnd(local->unk4);
    for(i_ptr = begin; i_ptr < end; i_ptr++){
        if ((func_80256064(i_ptr->position, position) < 50.0f) && func_8038B684(i_ptr->marker)) {
            local->vile_score++;
            timedFunc_set_1(0.0f, func_802FDCB8, 0x1B);
            timedFunc_set_1(0.5f, func_802FDCB8, 0x1B);
            timedFunc_set_1(1.0f, func_802FDCB8, 0x1B);
            return TRUE;
        }
    }
    return FALSE;
}

BKModelBin *func_8038A994(ActorMarker *marker){
    Actor *this;
    ActorLocal_BGS_3030 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    return local->unk8;
}

s32 func_8038A9B8(ActorMarker *marker){
    Actor *this;
    ActorLocal_BGS_3030 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    return vector_size(local->unk4);
}

s32 func_8038A9E0(ActorMarker *marker){
    Actor *this;
    ActorLocal_BGS_3030 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    return local->unkC;
}

s32 func_8038AA04(ActorMarker *marker){
    Actor *this;
    ActorLocal_BGS_3030 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    return local->vile_score - local->player_score;
}

bool func_8038AA2C(ActorMarker *marker, f32 position[0], f32 yaw, f32 arg3[3]) {
    f32 sp94[3];
    f32 sp88[3];
    Actor *this;
    ActorLocal_BGS_3030 *local;
    Struct_BGS_3030_0 *var_s2;
    Struct_BGS_3030_0 *begin;
    Struct_BGS_3030_0 *end;
    Struct_BGS_3030_0 *i_ptr;
    f32 temp_f20;
    f32 temp_f2;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    sp88[0] = 0.0f;
    sp88[1] = 0.0f;
    sp88[2] = 100.0f;
    ml_vec3f_yaw_rotate_copy(sp88, sp88, yaw);
    var_s2 = NULL;
    begin = (Struct_BGS_3030_0 *) vector_getBegin(local->unk4);
    end = (Struct_BGS_3030_0 *) vector_getEnd(local->unk4);
    for(i_ptr = begin; i_ptr < end; i_ptr++){
        if (((local->unk0 != 0) && (i_ptr->unk0 != 0)) || ((local->unk0 == 0) && (i_ptr->unk0 == 0))){
            sp94[0] = i_ptr->position[0] - position[0];
            sp94[1] = i_ptr->position[1] - position[1];
            sp94[2] = i_ptr->position[2] - position[2];
            temp_f20 = func_80256064(i_ptr->position, position);
            temp_f2 = func_80256AB4(sp88[0], sp88[2], sp94[0], sp94[2]);
            if( (temp_f20 > 300.0f) 
                || ((-0.8 < temp_f2) && (temp_f2 < 0.8) && ((sp94[0]*sp88[0] + sp94[1]*sp88[1] + sp94[2]*sp88[2]) >= 0.0f))
            ) {
                if ((var_s2 == NULL) || (temp_f20 < func_80256064(position, var_s2->position))){
                    var_s2 = i_ptr;
                }
            }
        }
    }
    if (var_s2 != NULL) {
        arg3[0] = var_s2->position[0];
        arg3[1] = var_s2->position[1];
        arg3[2] = var_s2->position[2];
        return TRUE;
    }
    return FALSE;
}

void func_8038AC54(ActorMarker *marker, ActorMarker *other_marker, f32 position[3], s32 arg3){
    Actor *this;
    ActorLocal_BGS_3030 *local;
    Struct_BGS_3030_0 *temp_v0;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    temp_v0 = (Struct_BGS_3030_0 *)vector_pushBackNew(&local->unk4);
    temp_v0->unk0 = arg3;
    temp_v0->marker = other_marker;
    temp_v0->position[0] = position[0];
    temp_v0->position[1] = position[1];
    temp_v0->position[2] = position[2];
    temp_v0->position[1] = 0.0f;
}

void func_8038ACB8(Actor *this){
    ActorLocal_BGS_3030 *local;

    local = (ActorLocal_BGS_3030 *)&this->local;
    func_8038A068(this, 0);
    vector_free(local->unk4);
    assetcache_release(local->unk8);
}

void func_8038ACFC(ActorMarker *marker, ActorMarker *other_marker) {
    Actor *this;
    ActorLocal_BGS_3030 *local;
    Struct_BGS_3030_0 *begin;
    Struct_BGS_3030_0 *end;
    Struct_BGS_3030_0 *i_ptr;

    this = marker_getActor(marker);
    local = (ActorLocal_BGS_3030 *)&this->local;
    begin = (Struct_BGS_3030_0 *)vector_getBegin(local->unk4);
    end = (Struct_BGS_3030_0 *)vector_getEnd(local->unk4);
    for(i_ptr = begin; i_ptr < end; i_ptr++){
        if (other_marker == i_ptr->marker) {
            vector_remove(local->unk4, i_ptr - begin);
            return;
        }
    }
}

void func_8038AD94(Actor *this) {
    ActorLocal_BGS_3030 *local;
    f32 sp50;
    f32 sp4C;
    u8 temp_v0;
    s32 sp30[6];
    s32 sp2C;

    sp50 = time_getDelta();
    local = (ActorLocal_BGS_3030 *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->unk30 = &func_8038ACB8;
        local->unk4 = vector_new(sizeof(Struct_BGS_3030_0), 0x20);
        local->unk8 = assetcache_get(0x3F7);
        local->unkC = 0;
        local->unk14 = 0;
        if (this->state == 0) {
            local->unkD = 0;
        } else {
            this->state = 0;
        }
        if (jiggyscore_isSpawned(JIGGY_28_BGS_MR_VILE) != 0) {
            local->unkC = 3;
            local->unkD = 3;
        }
        if (func_803203FC(2) != 0) {
            local->unkC = 2;
            local->unkD = 3;
        }
        func_8038A068(this, 1);
        return;
    }
    if (local->unk14 == NULL) {
        local->unk14 = func_80326D68(this->position, 0x13A, -1, &sp4C)->marker;
    }
    if (this->state == 1) {
        if (func_803203FC(2)) {
            if (func_803203FC(3)) {
                func_8038A068(this, 5);
            }
        } else if (func_8038C2A8(local->unk14)) {
            func_8038A068(this, 2);
        }
    }
    if (this->state == 5) {
        if (local->unkC == 7) {
            func_8024E55C(0, sp30);
            if ((sp30[BUTTON_Z] > 0) && func_8038C2A8(local->unk14)) {
                func_8038A068(this, 0xA);
            }
        } else {
            func_8038A6AC(this);
            if ((local->unkC == 3) || (local->unkC == 6)) {
                if (func_8025773C(&local->unk10, sp50)) {
                    local->unk0 = !local->unk0;
                    if (func_803203FC(2)) {
                        local->unk10 = 5.0f;
                    } else {
                        local->unk10 = 10.0f;
                    }
                }
                if (local->unk10 > 3.5) {
                    if (local->unk0 != 0) {
                        func_803463D4(0x1D, 0);
                    } else {
                        func_803463D4(0x1E, 0);
                    }
                }
            }
            sp2C = item_getCount(ITEM_1A_PLAYER_VILE_SCORE);
            item_set(ITEM_1A_PLAYER_VILE_SCORE, local->player_score);
            item_set(ITEM_1B_VILE_VILE_SCORE, local->vile_score);
            if ((sp2C != 0) && (local->player_score == 0)) {
                func_802FA5D0();
            }
            if (item_empty(ITEM_6_HOURGLASS)) {
                if (func_803203FC(2)) {
                    func_803204E4(3, 0);
                    func_803204E4(5, ( local->vile_score < local->player_score) ? TRUE : FALSE);
                    func_8038A068(this, 1);
                } else if (local->vile_score < local->player_score) {
                    if (local->unkC == 3) {
                        func_8038A068(this, 9);
                    } else {
                        func_8038A068(this, 8);
                    }
                } else {
                    func_8038A068(this, 6);
                }
            }
        }
    }
    if ((this->state == 7) && (func_8038C338(local->unk14) != 0)) {
        func_8038A068(this, 1);
    }
}
