#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "math.h" // for SQ()

void chVacationTextTrigger_update(Actor* this);

/* .data */

ActorInfo gChVacationTextTrigger = { 
    MARKER_1E3_VACATION_TEXT_TRIGGER, ACTOR_374_VACATION_TEXT_TRIGGER, 0x0,
    0x0, NULL,
    chVacationTextTrigger_update, actor_update_func_80326224, func_80325340, 
    0, 0, 0.0f, 0
};

/* .code */

/**
 * @brief Returns if player is within a specified horizontal radius of the 
 * supplied x,z positions.
 */
static bool __playerIsWithinTrigger(s32 x, s32 z, s32 distance) {
    s32 player_position[3];

    player_getPosition_s32(player_position);
    return (SQ(x - player_position[0]) + SQ(z - player_position[2])) < SQ(distance);
}

void chVacationTextTrigger_update(Actor* this) {
    // Despawn if already triggered
    if (volatileFlag_get(VOLATILE_FLAG_13_HAS_TRIGGERED_MUMBO_VACATION_TEXT)) {
        marker_despawn(this->marker);
        return;
    }

    // Start dialog if player is within trigger
    if (__playerIsWithinTrigger(0, -107, 188) != 0) {
        gcdialog_showText(0xDA9, 4, NULL, NULL, NULL, NULL);
        volatileFlag_set(VOLATILE_FLAG_13_HAS_TRIGGERED_MUMBO_VACATION_TEXT, 1);
    }
}
