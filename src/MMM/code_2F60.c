#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* public functions */
Actor *chPortrait_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chPortrait_update(Actor *this);

/* .data */
enum chPortrait_state_e {
    PORTRAIT_STATE_1_IDLE = 1,
    PORTRAIT_STATE_2_BROKEN
};

ActorAnimationInfo D_8038BE30[] = {
    {0x000, 0.0f},
    {0x23F, 10000000.0f},
    {0x23F, 2.0f},
};

ActorInfo D_8038BE48 = {
    MARKER_255_PORTRAIT_OF_GRUNTY, ACTOR_382_PORTRAIT_OF_GRUNTY, ASSET_522_MODEL_PORTRAIT_OF_GRUNTY,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BE6C = {
    MARKER_257_PORTRAIT_OF_BLACKEYE, ACTOR_384_PORTRAIT_OF_BLACKEYE, ASSET_527_MODEL_PORTRAIT_OF_BLACKEYE,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BE90 = {
    MARKER_258_PORTRAIT_OF_TOWER, ACTOR_385_PORTRAIT_OF_TOWER, ASSET_528_MODEL_PORTRAIT_OF_TOWER,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BEB4 = {
    MARKER_259_PORTRAIT_OF_TREE_AND_MOON, ACTOR_386_PORTRAIT_OF_TREE_AND_MOON, ASSET_529_MODEL_PORTRAIT_OF_TREE_AND_MOON,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BED8 = {
    MARKER_25A_PORTRAIT_OF_TEEHEE, ACTOR_387_PORTRAIT_OF_TEEHEE, ASSET_52A_MODEL_PORTRAIT_OF_TEEHEE,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

ActorInfo D_8038BEFC = {
    MARKER_25B_PORTRAIT_OF_MINION, ACTOR_388_PORTRAIT_OF_MINION, ASSET_52B_MODEL_PORTRAIT_OF_MINION,
    0x1, D_8038BE30,
    chPortrait_update, actor_update_func_80326224, chPortrait_draw,
    0, 0, 0.0f, 0
};

/* .code */
Actor *chPortrait_draw(ActorMarker *marker, Gfx **graphics, Mtx **matrix, Vtx **vertex) {
    func_8033A45C(3, marker_getActor(marker)->unk38_31);
    return actor_draw(marker, graphics, matrix, vertex);
}

void chPortrait_update(Actor *this) {
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;

        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->unk38_31 = 2;
    }

    switch (this->state) {
        case PORTRAIT_STATE_1_IDLE:
            anctrl_setAnimTimer(this->anctrl, 0.0f);
            break;

        case PORTRAIT_STATE_2_BROKEN:
            if (actor_animationIsAt(this, 0.999f)) {
                subaddie_set_state_with_direction(this, PORTRAIT_STATE_1_IDLE, 0.001f, 0);
                actor_playAnimationOnce(this);
                this->unk38_31 = 2;
            }
            break;
    }
}

void chPortrait_break(ActorMarker *marker, f32 anim_duration) {
    Actor *this = marker_getActor(marker);

    subaddie_set_state_with_direction(this, PORTRAIT_STATE_2_BROKEN, 0.001f, 1);
    actor_playAnimationOnce(this);
    anctrl_setDuration(this->anctrl, anim_duration);
    this->unk38_31 = 1;
    sfx_playFadeShorthandDefault(SFX_129_SWOOSH, 1.0f, 32000, this->position, 1000, 2000);
}
