#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 map;
    s16 unk2;
    s16 unk4;
}Struct_CCW_6EC0_0;

typedef struct{
    Struct_CCW_6EC0_0 *unk0;
}ActorLocal_CCW_6EC0;

void func_8038D368(Actor *this);
Actor *func_8038D30C(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);

/* .data */
Struct_CCW_6EC0_0 D_8038F600[] = {
    {MAP_45_CCW_AUTUMN, ASSET_CD2_DIALOG_GNAWTY_MEET_FALL_INSIDE,     0},
    {MAP_46_CCW_WINTER, ASSET_CD4_DIALOG_GNAWTY_MEET_WINTER_INSIDE_JIGGY, ASSET_CD5_DIALOG_GNAWTY_MEET_WINTER_INSIDE_AFTER_JIGGY},
    0
};

ActorInfo D_8038F614 = { 
    0x1CE, 0x31A, 0x48F,
    0x0, NULL,
    func_8038D368, NULL, func_8038D30C,
    0, 0, 2.2f, 0
};

/* .code */
void func_8038D2B0(Actor *this, s32 next_state) {
    if (next_state == 1) {
        skeletalAnim_set(this->unk148, 0x1A6, 0.2f, 5.5f);
    }
    
    this->state = next_state;
}

Actor *func_8038D30C(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx) {
    if (levelSpecificFlags_get(LEVEL_FLAG_25_CCW_UNKNOWN) == FALSE) {
        return func_80325340(marker, gfx, mtx, vtx);
    }

    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038D368(Actor *this) {
    ActorLocal_CCW_6EC0 *local;
    f32 plyr_pos[3];

    local = (ActorLocal_CCW_6EC0 *)&this->local;
    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        local->unk0 = D_8038F600;
        while (local->unk0->map != 0 && gsworld_get_map() != local->unk0->map) {
            local->unk0++;
        }

        func_8038D2B0(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
            levelSpecificFlags_set(LEVEL_FLAG_25_CCW_UNKNOWN, TRUE);
        }
        return;
    } 
    
    if(!this->has_met_before){
        player_getPosition(plyr_pos);
        if (ml_vec3f_distance(this->position, plyr_pos) < 600.0f) {
            if (!jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
                gcdialog_showDialog(local->unk0->unk2, 4, NULL, NULL, NULL, NULL);
            } else {
                if (local->unk0->unk4) {
                    gcdialog_showDialog(local->unk0->unk4, 4, NULL, NULL, NULL, NULL);
                }
            }
            this->has_met_before = TRUE;
        }
    }
    
}
