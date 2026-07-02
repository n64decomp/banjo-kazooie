#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

Actor *func_8038C380(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx);
void func_8038C41C(Actor *this);

/* .data */

ActorInfo chMoundOfAcorns = {
    MARKER_1C6_MOUND_OF_ACORNS, ACTOR_310_NABNUT_HOUSE_PILE_OF_ACORNS, ASSET_501_MODEL_MOUND_OF_ACORNS,
    0x0, NULL,
    func_8038C41C, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chPinkSquirrel = {
    MARKER_1C7_PINK_SQUIRREL, ACTOR_311_PINK_SQUIRREL, ASSET_462_MODEL_PINK_SQUIRREL,
    0x0, NULL,
    func_8038C41C, NULL, func_8038C380,
    0, 0, 0.0f, 0
};

ActorInfo chNabnutBedsheets = {
    MARKER_1C8_NABNUT_BEDSHEETS, ACTOR_312_NABNUT_BEDSHEETS, ASSET_463_MODEL_NABNUT_BEDSHEETS,
    0x0, NULL,
    func_8038C41C, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chNabnutBed = {
    MARKER_1C9_NABNUT_BED, ACTOR_313_NABNUT_BED, ASSET_464_MODEL_NABNUT_BED,
    0x0, NULL,
    func_8038C41C, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chNabnut = {
    MARKER_1CA_NABNUT, ACTOR_314_NABNUT_IN_AUTUMN_HOUSE, ASSET_502_MODEL_NABNUT,
    0x0, NULL,
    func_8038C41C, NULL, actor_draw,
    0, 0, 2.0f, 0
};

ActorInfo chNabnutAutumnEatingAcorns = {
    MARKER_1CB_NABNUT_EATING_ACORNS, ACTOR_315_NABNUT_EATING_ACORNS, ASSET_48D_MODEL_NABNUT_EATING_ACORNS,
    0x0, NULL, func_8038C41C,
    NULL, func_8038C380,
    0, 0, 0.0f, 0
};

enum code_5BF0_state_e {
    CODE_5BF0_STATE_0_NOT_INIT,
    CODE_5BF0_STATE_1_CCW_AUTUMN_AFTER_ACORN_JIGGY,
    CODE_5BF0_STATE_2_CCW_WINTER_OR_NO_ACORN_JIGGY
};

/* .code */
void func_8038BFE0(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(SFX_5D_BANJO_RAAOWW, randf2(1.0f, 1.1f), (s32)randf2(21000.0f, 22000.0f), sp2C->position, 500.0f, 2500.0f);
}

void func_8038C064(ActorMarker* marker) {
    Actor* sp2C = marker_getActor(marker);
    func_8030E878(SFX_5E_BANJO_PHEWWW, randf2(1.0f, 1.1f), (s32)randf2(21000.0f, 22000.0f), sp2C->position, 500.0f, 2500.0f);
}

void func_8038C0E8(ActorMarker* marker) {
    Actor* sp24 = marker_getActor(marker);
    f32 sp20 = randf2(0.9f, 1.1f);

    func_8030E878(SFX_81_UUU, sp20, (s32)randf2(10000.0f, 31000.0f), sp24->position, 500.0f, 2500.0f);
}

void code_5BF0_setState(Actor *this, s32 next_state) {
    Actor *other;

    if (next_state == CODE_5BF0_STATE_1_CCW_AUTUMN_AFTER_ACORN_JIGGY) {
        this->position[1] -= 300.0f;
    }

    if (this->state == CODE_5BF0_STATE_1_CCW_AUTUMN_AFTER_ACORN_JIGGY) {
        this->position[1] += 300.0f;
    }

    if (next_state == CODE_5BF0_STATE_2_CCW_WINTER_OR_NO_ACORN_JIGGY) {
        if (this->marker->id == MARKER_1CA_NABNUT) {
            skeletalAnim_set(this->unk148, ASSET_22E_ANIM_NABNUT_STAND, 0.2f, 3.53f);
            skeletalAnim_setCallback_1(this->unk148, 0.1f, (GenFunction_1)func_8038C0E8, (s32)this->marker);
        }
        if (this->marker->id == MARKER_1C7_PINK_SQUIRREL) {
            skeletalAnim_set(this->unk148, ASSET_230_ANIM_PINK_SQUIRREL_UNK, 0.2f, 4.0f);
        }
        if (this->marker->id == MARKER_1CB_NABNUT_EATING_ACORNS) {
            skeletalAnim_set(this->unk148, ASSET_1A2_ANIM_NABNUT_SLEEP, 0.2f, 4.0f);
            skeletalAnim_setCallback_1(this->unk148, 0.3f, (GenFunction_1)func_8038BFE0, (s32)this->marker);
            skeletalAnim_setCallback_1(this->unk148, 0.65f, (GenFunction_1)func_8038C064, (s32)this->marker);
        }
        if (this->marker->id == MARKER_1C8_NABNUT_BEDSHEETS) {
            skeletalAnim_set(this->unk148, ASSET_231_ANIM_NABNUT_BEDSHEETS_UNK, 0.2f, 4.0f);
        }
        if ((this->marker->id == MARKER_1C7_PINK_SQUIRREL)
            || (this->marker->id == MARKER_1CB_NABNUT_EATING_ACORNS)
            || (this->marker->id == MARKER_1C8_NABNUT_BEDSHEETS))
        {
            other = actorArray_findActorFromActorId(ACTOR_313_NABNUT_BED);
            if (other != 0) {
                this->position[0] = other->position[0];
                this->position[1] = other->position[1];
                this->position[2] = other->position[2];
                this->pitch = other->pitch;
                this->yaw = other->yaw;
                this->roll = other->roll;
            }
        }
    }
    this->state = next_state;
}

Actor *func_8038C380(ActorMarker* marker, Gfx** gfx, Mtx** mtx, Vtx** vtx) {
    modelRender_setAppendageVisibility(3, 0);
    modelRender_setAppendageVisibility(4, 0);
    modelRender_setAppendageVisibility(5, 0);
    modelRender_setAppendageVisibility(6, 1);
    modelRender_setAppendageVisibility(7, 0);
    modelRender_setAppendageVisibility(8, 0);
    modelRender_setAppendageVisibility(9, 0);
    modelRender_setAppendageVisibility(0xA, 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038C41C(Actor *this) {
    f32 player_position[3];

    if (!this->volatile_initialized) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->volatile_initialized = TRUE;
        this->has_met_before = FALSE;
        return;
    }

    if (this->state == CODE_5BF0_STATE_0_NOT_INIT) {
        if( gsworld_getMap() == MAP_60_CCW_AUTUMN_NABNUTS_HOUSE
            && !jiggyscore_isSpawned(JIGGY_4A_CCW_NABNUT) 
            && (this->marker->id == MARKER_1C6_MOUND_OF_ACORNS
                || this->marker->id == MARKER_1CA_NABNUT)
        ){
            code_5BF0_setState(this, CODE_5BF0_STATE_1_CCW_AUTUMN_AFTER_ACORN_JIGGY);
        } else {
            code_5BF0_setState(this, CODE_5BF0_STATE_2_CCW_WINTER_OR_NO_ACORN_JIGGY);
        }
    }

    if ((this->marker->id == MARKER_1CA_NABNUT)
        && (this->state != CODE_5BF0_STATE_1_CCW_AUTUMN_AFTER_ACORN_JIGGY))
    {
        func_8028E668(this->position, 300.0f, -50.0f, 120.0f);
    }

    if ((this->marker->id == MARKER_1CB_NABNUT_EATING_ACORNS)
        && (this->state == CODE_5BF0_STATE_2_CCW_WINTER_OR_NO_ACORN_JIGGY))
    {
        player_getPosition(player_position);
        if (!this->has_met_before && (ml_vec3f_distance(this->position, player_position) < 400.0f)) {
            this->has_met_before = TRUE;
            gcdialog_showDialog(ASSET_CCD_DIALOG_NABNUT_MEET_WINTER, 0, NULL, NULL, NULL, NULL);
        }
    }
}

