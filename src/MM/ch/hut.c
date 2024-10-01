/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

/* extern function declarations */

void bundle_setYaw(f32);
void spawnQueue_bundle_f32(s32, s32, s32, s32);

/* public function declarations */
Actor *chhut_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);
void chhut_update(Actor *);

/* .bss */
extern s32 mm_hut_smash_count; //mm_hut_smash_count

/* .data */
enum chhut_state_e {
    HUT_STATE_0_INTACT,
    HUT_STATE_1_DAMAGED,
    HUT_STATE_2_DESTROYED
};

ActorAnimationInfo chhutAnimations[3] = {
    {0,                          0.0f},
    {ASSET_4E_ANIM_MUDHUT_SMASH, 0.25f},
    {ASSET_4E_ANIM_MUDHUT_SMASH, 1000000.0f}
};

/* .code */
Actor *chhut_draw(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *actorPtr = marker_getActor(this);
    s32 is_not_destroyed  = actorPtr->state != HUT_STATE_2_DESTROYED;
    s32 is_intact_or_destroyed  = actorPtr->state == HUT_STATE_0_INTACT || actorPtr->state == HUT_STATE_2_DESTROYED;

    this->propPtr->unk8_3 = is_intact_or_destroyed;
    func_8033A45C(1, is_not_destroyed);
    return actor_draw(this, gfx, mtx, vtx);
}

void __chhut_spawnExplosion(ActorMarker *this) {
    Actor *actorPtr = marker_getActor(this);
    actorPtr = actor_spawnWithYaw_f32(ACTOR_4B_WOOD_EXPLOSION_2, actorPtr->position, 0);
    actor_spawnWithYaw_f32(ACTOR_4D_STEAM_2, actorPtr->position, 0);

    if (this);
}

void chhut_update(Actor *this) {
    static s32 D_803898D8[6] = {0, 1, 2, 3, 6, 4};
    f32 diff_pos[3];
    f32 plyr_pos[3];

    if (func_80334904() != 2) {
        return;
    }

    if (!this->initialized) {
        this->marker->collidable = FALSE;
        this->initialized = TRUE;
    }

    switch (this->state) {
        case HUT_STATE_0_INTACT:
            player_getPosition(plyr_pos);
            diff_pos[0] = plyr_pos[0] - this->position_x;
            diff_pos[1] = plyr_pos[1] - this->position_y;
            diff_pos[2] = plyr_pos[2] - this->position_z;

            if (150.0f < diff_pos[1]
                && player_getActiveHitbox(this->marker) == HITBOX_1_BEAK_BUSTER
                && func_8028F20C()
                && LENGTH_VEC3F(diff_pos) < 350.0f
            ){
                diff_pos[0] = this->position_x;
                diff_pos[1] = this->position_y;
                diff_pos[2] = this->position_z;
                diff_pos[1] += 125.0;

                sfxsource_playHighPriority(SFX_5B_HEAVY_STUFF_FALLING);
                subaddie_set_state(this, HUT_STATE_1_DAMAGED);
                actor_playAnimationOnce(this);
                __spawnQueue_add_1((GenFunction_1) __chhut_spawnExplosion, (s32) this->marker);
                bundle_setYaw(this->yaw);

                if (mm_hut_smash_count < 5) {
                    __spawnQueue_add_4((GenFunction_4)spawnQueue_bundle_f32, D_803898D8[mm_hut_smash_count], *(s32*)(&diff_pos[0]),*(s32*)(&diff_pos[1]),*(s32*)(&diff_pos[2]));
                }
                else {
                    jiggy_spawn(JIGGY_5_MM_HUTS, diff_pos);
                }

                mm_hut_smash_count = (mm_hut_smash_count + 1) % 6;
            }
            break;

        case HUT_STATE_1_DAMAGED:
            if (animctrl_getAnimTimer(this->animctrl) > 0.99) {
                animctrl_setTransitionDuration(this->animctrl, 0.0f);
                subaddie_set_state(this, HUT_STATE_2_DESTROYED);
                this->position_y -= 160.0f;
            }
            break;

        case HUT_STATE_2_DESTROYED:
            break;
    }
}

void mm_resetHuts(void) {
    mm_hut_smash_count = 0;
}

ActorInfo chhutInfo = {
    MARKER_51_MM_HUT, ACTOR_9_MM_HUT, ASSET_7D7_MODEL_MM_HUT,
    0, chhutAnimations,
    chhut_update, func_80326224, chhut_draw,
    0, 0x100, 0.0f, 0
};
