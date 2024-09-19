/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
f32 mapModel_getFloorY(f32 *);

/* public functions */
void chorange_update(Actor *this);
Actor *chorange_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);

/* .data */
enum chorange_state_e {
    ORANGE_STATE_1_FALLING = 1,
    ORANGE_STATE_2_LANDED
};

ActorInfo chorangeInfo = {
    MARKER_C_ORANGE_PROJECTILE, ACTOR_14_ORANGE_PROJECTILE, ASSET_2D2_MODEL_ORANGE,
    1, NULL,
    chorange_update, func_80326224, chorange_draw,
    0, 0, 0.6f, 0
};

f32 D_803899F4[3] = {0.0f, -8.0f, 0.0f};
f32 D_80389A00[3] = {0.0f, 0.0f, 0.0f};

/* .code */
void __chorange_collisionCallback(ActorMarker *marker, ActorMarker *other_marker) {
    if (!func_8028F22C() &&
        !mapSpecificFlags_get(MM_SPECIFIC_FLAG_8_HIT_WITH_ORANGE) &&
        func_80311480(ASSET_B3A_TEXT_CONGA_HITS_PLAYER, 0, 0, 0, NULL, NULL)) {

        mapSpecificFlags_set(MM_SPECIFIC_FLAG_8_HIT_WITH_ORANGE, TRUE);
    }

    if (marker);
}

void chorange_update(Actor *this) {
    f32 floor_position_y;
    f32 velocity_y;

    if (!this->initialized) {
        this->marker->unk2C_1 = 1;
        marker_setCollisionScripts(this->marker, NULL, __chorange_collisionCallback, NULL);
    }

    switch (this->state) {
        case ORANGE_STATE_1_FALLING:
            this->position_x += this->velocity_x;
            velocity_y = this->velocity_y - 5.0;
            this->velocity_y = velocity_y;
            this->position_y += velocity_y;
            this->position_z += this->velocity_z;

            floor_position_y = mapModel_getFloorY(this->position);

            if (this->position_y < floor_position_y) {
                this->position_y = floor_position_y;
                this->unk1C_y = floor_position_y;
                func_8030E6D4(SFX_2F_ORANGE_SPLAT);

                this->actor_specific_1_f = 1.0f;
                this->lifetime_value = 340.0f;
                this->state = ORANGE_STATE_2_LANDED;
            }
            break;

        case ORANGE_STATE_2_LANDED:
            if (this->lifetime_value < 324.0) {
                this->marker->collidable = FALSE;
            }

            this->lifetime_value -= 4.0;

            if (this->lifetime_value < 4.0) {
                marker_despawn(this->marker);
            }
            break;
    }
}

Actor *chorange_draw(ActorMarker *this, Gfx **dl, Mtx **mptr, Vtx **vtx) {
    Actor *actorPtr = actor_drawFullDepth(this, dl, mptr, vtx);
    f32 sp60[3] = D_803899F4;
    f32 rotation[3] = D_80389A00;
    f32 position[3];

    if (actorPtr->state == ORANGE_STATE_2_LANDED) {
        position[0] = actorPtr->position_x;
        position[1] = actorPtr->unk1C_y + 3.0f;
        position[2] = actorPtr->position_z;

        modelRender_setAlpha((s32) MIN(255.0f, actorPtr->lifetime_value));
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(dl, mptr, position, rotation, actorPtr->actor_specific_1_f, sp60, func_8030A428(0x18));
        actorPtr->position_y -= 1.9;

        if (actorPtr->actor_specific_1_f < 2.428) {
            actorPtr->actor_specific_1_f += 0.1;
        }
    }

    return actorPtr;
}
