#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 map;
    s16 meetBeforeJiggyDialog;
    s16 meetAfterJiggyDialog;
} CH_Indoors_Gnawty_Dialogs;

typedef struct{
    CH_Indoors_Gnawty_Dialogs *dialogs;
} ActorLocal_chIndoorsGnawty;

void chIndoorsGnawty_update(Actor *this);
Actor *chIndoorsGnawty_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);

/* .data */
CH_Indoors_Gnawty_Dialogs chIndoorsGnawtyDialogs[] = {
    {
        MAP_45_CCW_AUTUMN,
        VER_SELECT(ASSET_CD2_DIALOG_GNAWTY_MEET_FALL_INSIDE, 0x9E7, 0, 0),
        NULL
    },
    {
        MAP_46_CCW_WINTER,
        VER_SELECT(ASSET_CD4_DIALOG_GNAWTY_MEET_WINTER_INSIDE_JIGGY, 0x09E9, 0, 0),
        VER_SELECT(ASSET_CD5_DIALOG_GNAWTY_MEET_WINTER_INSIDE_AFTER_JIGGY, 0x09EA, 0, 0)
    },
    NULL
};

ActorInfo chIndoorsGnawty = { 
    MARKER_1CE_INDOOR_GNAWTY, ACTOR_31A_INDOORS_GNAWTY, ASSET_48F_MODEL_GNAWTY,
    0x0, NULL,
    chIndoorsGnawty_update, NULL, chIndoorsGnawty_draw,
    0, 0, 2.2f, 0
};

enum chIndoorsGnawty_State_e {
    CH_INDOOR_GNAWTY_STATE_0_NOT_INIT,
    CH_INDOOR_GNAWTY_STATE_1_IDLE
};

/* .code */
void chIndoorsGnawty_setNextState(Actor *this, s32 next_state) {
    if (next_state == CH_INDOOR_GNAWTY_STATE_1_IDLE) {
        skeletalAnim_set(this->unk148, ASSET_1A6_ANIM_GNAWTY_IDLE, 0.2f, 5.5f);
    }
    
    this->state = next_state;
}

Actor *chIndoorsGnawty_draw(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx) {
    if (levelSpecificFlags_get(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED) == FALSE) {
        return func_80325340(marker, gfx, mtx, vtx);
    }

    return actor_draw(marker, gfx, mtx, vtx);
}

void chIndoorsGnawty_update(Actor *this) {
    ActorLocal_chIndoorsGnawty *local;
    f32 plyr_pos[3];

    local = (ActorLocal_chIndoorsGnawty *)&this->local;
    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        local->dialogs = chIndoorsGnawtyDialogs;
        while (local->dialogs->map != NULL && gsworld_getMap() != local->dialogs->map) {
            local->dialogs++;
        }

        chIndoorsGnawty_setNextState(this, CH_INDOOR_GNAWTY_STATE_1_IDLE);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
            levelSpecificFlags_set(LEVEL_FLAG_25_CCW_GNAWTY_JIGGY_COLLECTED, TRUE);
        }
        return;
    } 
    
    if(!this->has_met_before){
        player_getPosition(plyr_pos);
        if (ml_vec3f_distance(this->position, plyr_pos) < 600.0f) {
            if (!jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY)) {
                gcdialog_showDialog(local->dialogs->meetBeforeJiggyDialog, 4, NULL, NULL, NULL, NULL);
            } else {
                if (local->dialogs->meetAfterJiggyDialog) {
                    gcdialog_showDialog(local->dialogs->meetAfterJiggyDialog, 4, NULL, NULL, NULL, NULL);
                }
            }
            this->has_met_before = TRUE;
        }
    }
    
}
