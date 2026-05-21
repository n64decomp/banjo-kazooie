#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chZubbaDoor_update(Actor *this);

ActorInfo chZubbaDoorSummer = {
    MARKER_1AC_ZUBBA_DOOR, ACTOR_298_ZUBBA_DOOR_SUMMER, ASSET_444_MODEL_CCW_ZUBBA_DOOR,
    0x0, NULL,
    chZubbaDoor_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chZubbaDoorAutumn = {
    MARKER_1AC_ZUBBA_DOOR, ACTOR_29A_ZUBBA_DOOR_AUTUMN, ASSET_445_MODEL_CCW_ZUBBA_DOOR,
    0x0, NULL,
    chZubbaDoor_update, NULL, actor_draw,
    0, 0, 0.0f, 0
};

enum chZubbaDoor_State_e {
    CH_ZUBBA_DOOR_STATE_0_NOT_INIT,
    CH_ZUBBA_DOOR_STATE_1_IDLE,
    CH_ZUBBA_DOOR_STATE_2_DESPAWN
};

/* .code */
void chZubbaDoor_setState(Actor *this, s32 next_state){
    if(next_state == CH_ZUBBA_DOOR_STATE_2_DESPAWN){
        sfx_playFadeShorthandDefault(SFX_2F_ORANGE_SPLAT, 1.0f, 32000, this->position, 500, 3000);
        levelSpecificFlags_set(LEVEL_FLAG_10_CCW_BREAK_ZUBBA_DOOR, TRUE);
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void chZubbaDoor_die(ActorMarker* marker, ActorMarker *arg1) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == CH_ZUBBA_DOOR_STATE_1_IDLE
        && gsworld_getMap() == MAP_44_CCW_SUMMER)
    {
        chZubbaDoor_setState(actor, CH_ZUBBA_DOOR_STATE_2_DESPAWN);
    }
}

void chZubbaDoor_update(Actor *this){
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, chZubbaDoor_die);
        chZubbaDoor_setState(this, CH_ZUBBA_DOOR_STATE_1_IDLE);

        if (levelSpecificFlags_get(LEVEL_FLAG_10_CCW_BREAK_ZUBBA_DOOR)) {
            marker_despawn(this->marker);
        }
    }
}
