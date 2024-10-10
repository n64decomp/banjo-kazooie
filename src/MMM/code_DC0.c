#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* public functions */
void chFlowerpot_update(Actor *this);

/* .data */
enum chFlowerpot_state_e {
    FLOWER_POT_STATE_1_IDLE = 1,
    FLOWER_POT_STATE_2_FLOWERED
};

ActorAnimationInfo D_8038BA50[] = {
    {0x00,                     0.0f},
    {ASSET_A9_ANIM_FLOWER_POT, 2.0f},
    {ASSET_A9_ANIM_FLOWER_POT, 2.0f}
};

ActorInfo D_8038BA68 = {
    MARKER_34_CEMETARY_POT, ACTOR_25_CEMETARY_POT, ASSET_3AE_MODEL_GRAVE_FLOWER_POT,
    0x1, D_8038BA50,
    chFlowerpot_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
s32 chFlowerpot_getRemaining(void) {
    return levelSpecificFlags_getN(0x39, 3);
}

void chFlowerpot_setRemaining(s32 arg0) {
    levelSpecificFlags_setN(0x39, arg0, 3);
}

void MMM_func_803871FC(Actor *this) {
    switch (this->state) {
        case FLOWER_POT_STATE_1_IDLE:
            func_8033A45C(3, FALSE);
            break;

        case FLOWER_POT_STATE_2_FLOWERED:
            func_8033A45C(3, TRUE);
            break;
    }

    func_803255FC(this);
}

void chFlowerpot_reset() {
    chFlowerpot_setRemaining(5);
}

void chFlowerpot_update(Actor *this) {
    this->marker->propPtr->unk8_3 = TRUE;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->unk130 = MMM_func_803871FC;
    }

    switch (this->state) {
        case FLOWER_POT_STATE_1_IDLE:
            animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
            break;

        case FLOWER_POT_STATE_2_FLOWERED:
            if (actor_animationIsAt(this, 0.2f)) {
                FUNC_8030E8B4(SFX_12F_THAAANK_YOOOUUU, 1.0f, 30000, this->position, 300, 2000);
            }
            break;
    }
}

bool chFlowerpot_eggCollision(ActorMarker *marker) {
    Actor *actor = marker_getActor(marker);
    f32 position[3];
    s32 remaining;

    if (actor->state == FLOWER_POT_STATE_2_FLOWERED) {
        return FALSE;
    }

    subaddie_set_state(actor, FLOWER_POT_STATE_2_FLOWERED);
    animctrl_setPlaybackType(actor->animctrl, ANIMCTRL_ONCE);
    remaining = chFlowerpot_getRemaining();

    if (remaining != 0) {
        remaining--;

        if (remaining == 0) {
            ml_vec3f_copy(position, actor->position);
            position[1] += 80.0f;

            comusic_playTrack(COMUSIC_2D_PUZZLE_SOLVED_FANFARE);
            jiggy_spawn(JIGGY_63_MMM_FLOWER_POTS, position);
        }
        else {
            comusic_playTrack(COMUSIC_2B_DING_B);
        }
    }

    chFlowerpot_setRemaining(remaining);
    return TRUE;
}
