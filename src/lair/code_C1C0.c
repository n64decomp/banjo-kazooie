#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/nc/camera.h"

Actor *func_803925B0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80392700(Actor *this);
void func_80392918(Actor *this);

/* .data */
ActorAnimationInfo D_80394CC0[] = {
    {0x000, 0.0f},
    {0x28B, 8.0f},
    {0x28D, 0.5f},
    {0x2AC, 3.0f},
    {0x2AD, 14.0f},
    {0x28D, 0.5f},
};
ActorInfo D_80394CF0 = { 0x29B, 0x3C5, 0x53D, 0x1, D_80394CC0, func_80392700, func_80392918, func_803925B0, 0, 0, 3.0f, 0};

/* .code */
Actor *func_803925B0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    func_8033A45C(3, 0);
    func_8033A45C(4, 0);
    func_8033A45C(5, 0);
    return actor_draw(marker, gfx, mtx, vtx);
}


void func_80392610(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    if(arg2 == 0xA){
        mapSpecificFlags_set(5, TRUE);
    }
    else{
        mapSpecificFlags_set(5, FALSE);
    }
    ncStaticCamera_setToNode(arg2);
}

void func_80392664(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    camera_setType(CAMERA_TYPE_2_DYNAMIC);
}

void func_80392690(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(marker);
    func_8030E6D4(SFX_EA_GRUNTY_LAUGH_1);
    subaddie_set_state_with_direction(this, 5, 0.0f, 1);
    actor_loopAnimation(this);
    this->yaw_ideal = 79.0f;
    animctrl_setTransitionDuration(this->animctrl, 0.4f);
}

void func_80392700(Actor *this) {
    if (mapSpecificFlags_get(4)) {
        if (fileProgressFlag_get(FILEPROG_F4_ENTER_FF_CUTSCENE)) {
            gcdialog_showText(0x1031, 0xF, this->position, this->marker, func_80392664, func_80392610);
        } else {
            func_802BC280();
            ncStaticCamera_setToNode(0x1F);
            gcdialog_showText(0x102C, 0xE, this->position, this->marker, func_80392664, func_80392610);
            fileProgressFlag_set(FILEPROG_F4_ENTER_FF_CUTSCENE, TRUE);
        }
        mapSpecificFlags_set(4, 0);
    }
    if (mapSpecificFlags_get(6)) {
        comusic_playTrack(COMUSIC_A8_KLUNGO_BY_FALLEN_GRUNTY);
        func_802BC280();
        ncStaticCamera_setToNode(9);
        mapSpecificFlags_set(9, 1);
        func_8028F94C(2, this->position);
        gcdialog_showText(0x103F, 0x2A, this->position, this->marker, func_80392690, func_80392610);
        mapSpecificFlags_set(6, 0);
        subaddie_set_state_with_direction(this, 3, 0.0f, 1);
        actor_playAnimationOnce(this);
    }
    if ((this->state == 3) && (actor_animationIsAt(this, 0.999f) != 0)) {
        subaddie_set_state_with_direction(this, 4, 0.0f, 1);
        actor_loopAnimation(this);
    }
    if (this->state == 5) {
        func_80328FB0(this, 12.0f);
        if (func_80329480(this) != 0) {
            subaddie_set_state_with_direction(this, 5, 0.0f, 1);
            this->marker->unk2C_2 = TRUE;
        }
    }
    this->unk58_0 = !func_8031A3BC();
}


void func_80392918(Actor *this) {
    if (!this->volatile_initialized) {
        if (fileProgressFlag_get(FILEPROG_F4_ENTER_FF_CUTSCENE) && (func_8028E4A4() == 2)) {
            mapSpecificFlags_set(4, 1);
        }
        this->unk4C = 400.0f;
        this->marker->unk2C_2 = FALSE;
        this->volatile_initialized = TRUE;
        if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)) {
            marker_despawn(this->marker);
        }
        return;
    }
    actor_update_func_80326224(this);
    if ((this->unk48 > 0.5) && !this->has_met_before) {
        this->has_met_before = TRUE;
        ncStaticCamera_setToNode(0x1E);
    }
    if ((0.999 < this->unk48) && !this->unk38_0) {
        comusic_8025AB44(COMUSIC_A8_KLUNGO_BY_FALLEN_GRUNTY, 0, 2000);
        func_8025AABC(0xA8);
        this->unk38_0 = TRUE;
        mapSpecificFlags_set(7, TRUE);
        mapSpecificFlags_set(5, TRUE);
    }
    if (this->unk48 == 1.0) {
        marker_despawn(this->marker);
    }

}
