#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void explosionRipple_update(Actor *this);

/* .data */
ActorInfo chExplosionRipple = { MARKER_65_SHRAPNEL, ACTOR_F3_EXPLOSION_RIPPLE, 0x0, 0x0, 0x0, explosionRipple_update, actor_update_func_80326224, func_80325340, 0, 0, 0.0f, 0};

/* .code */
void explosionRipple_update(Actor *this) {

    if (!this->initialized) {
        actor_collisionOff(this);
        this->lifetime_value = 0.0f;
        this->pitch = 90.0f;
        fxRipple_802F3554(4, this->position);
        this->initialized = TRUE;
        return;
    }

    this->lifetime_value += time_getDelta();

    if (2.0 < this->lifetime_value) {
        marker_despawn(this->marker);
    }
}
