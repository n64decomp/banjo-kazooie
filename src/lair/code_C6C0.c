#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void player_walkToPosition(f32[3], f32, void(*)(ActorMarker *), ActorMarker *);

void func_80392B6C(Actor *this);

/* .data */
ActorInfo D_80394D20 = { 0x29C, 0x3C9, 0x0, 0x0, NULL, func_80392B6C, actor_update_func_80326224, func_80325340, 0, 0, 0.0f, 0};

/* .code */
void func_80392AB0(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    comusic_8025AB44(COMUSIC_A9_TOOTY, 0, 2000);
    func_8025AABC(0xA9);
    gcparade_beginFFParade();
}

void func_80392AF4(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    ncStaticCamera_setToNode(arg2);
}

void func_80392B1C(ActorMarker *marker) {
    func_8028E6EC(0);
    gcdialog_showDialog(0x1040, 8, NULL, marker, func_80392AB0, func_80392AF4);
}

void func_80392B6C(Actor *this) {
    NodeProp* phi_a0;
    s32 sp28;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        if (fileProgressFlag_get(FILEPROG_A6_FURNACE_FUN_COMPLETE)) {
            marker_despawn(this->marker);
            return;
        }
        phi_a0 = nodeprop_findByActorIdAndActorPosition(0x3BE, this);
        if (this == NULL) {
            this->unk1C[0] = -1300.0f;
            this->unk1C[1] = 250.0f;
            this->unk1C[2] = -3422.0f;
        } else {
            nodeprop_getPosition(phi_a0, this->unk1C);
        }
    }
    if (mapSpecificFlags_get(7) != 0) {
        sp28 = ml_vec3f_distance(this->position, this->unk1C) / 350.0;
        comusic_playTrack(COMUSIC_A9_TOOTY);
        mapSpecificFlags_set(7, 0);
        mapSpecificFlags_set(9, 1);
        ncStaticCamera_setToNode(0x10);
        func_8028F918(0);
        func_8028F85C(this->position);
        player_walkToPosition(this->unk1C, (f32) sp28, &func_80392B1C, this->marker);
    }
}
