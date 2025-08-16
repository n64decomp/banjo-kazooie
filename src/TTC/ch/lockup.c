#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/dustemitter.h"

#include "lockup.h"

ActorAnimationInfo chLockupAnimations[6] = {
    { NULL, NULL },
    { ASSET_BC_ANIM_LOCKUP, 8000000.0f },
    { ASSET_BC_ANIM_LOCKUP, 4.0f },
    { ASSET_BC_ANIM_LOCKUP, 8000000.0f },
    { ASSET_BC_ANIM_LOCKUP, 1.4f },
    { ASSET_BC_ANIM_LOCKUP, 8000000.0f }
};

ActorInfo chLockupSlow = {
    MARKER_A4_LOCKUP_SLOW, ACTOR_151_LOCKUP_SLOW, ASSET_3D4_MODEL_LOCKUP, 
    1, chLockupAnimations,
    chLockup_update, actor_update_func_80326224, chLockup_draw,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo chLockupMedium = {
    MARKER_F6_LOCKUP_MEDIUM, ACTOR_152_LOCKUP_MEDIUM, ASSET_3D4_MODEL_LOCKUP, 
    1, chLockupAnimations,
    chLockup_update, actor_update_func_80326224, chLockup_draw,
    2500, 0x366, 0.0f, 0
}; 

ActorInfo chLockupFast = {
    MARKER_F7_LOCKUP_FAST, ACTOR_153_LOCKUP_FAST, ASSET_3D4_MODEL_LOCKUP, 
    1, chLockupAnimations,
    chLockup_update, actor_update_func_80326224, chLockup_draw,
    2500, 0x366, 0.0f, 0
}; 

static s32 SMOKE_COLOR[4] = { 120, 120, 120, 120 };
static s32 SMOKE_VELOCITY[3] = { 0, 0, 0 };

static Actor *chLockup_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *actor = marker_getActor(marker);
    func_8033A45C(3, actor->unk38_31);
    func_8033A45C(4, actor->unk38_31);
    actor_draw(marker, gfx, mtx, vtx);
}

static void close(Actor *this) {
    subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSED, 0.2f, 1);
    this->marker->collidable = FALSE;
    this->unk38_31 = 0;
    sfx_playFadeShorthandDefault(SFX_6C_LOCKUP_CLOSING, 1.0f, 32000, this->position, 1250, 2500);
}

static void open(Actor *this) {
    code3040_func_80389468();
    subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_OPENING, 0.2f, 1);
    this->unk38_31 = 1;
    sfx_playFadeShorthandDefault(SFX_6B_LOCKUP_OPENING, 1.0f, 32000, this->position, 1250, 2500);
}

static void chLockup_update(Actor *this) {
    ActorLocal_Lockup *local = (ActorLocal_Lockup *)&this->local;
    s32 cycle_ticks;
    int i;

    // Display "this be Grunty's gold" when getting close for the first time
    if (!this->has_met_before
        && this->actorTypeSpecificField == LOCKUP_WITH_JIGGY_ID
        && !jiggyscore_isCollected(JIGGY_13_TTC_LOCKUP)
        && subaddie_playerIsWithinSphereAndActive(this, 320)
        && !subaddie_playerIsWithinSphereAndActive(this, 160)
        && !player_movementGroup()
        && gcdialog_showDialog(ASSET_A15_DIALOG_TTC_LOCKUP_SPAWNED, 0, NULL, NULL, NULL, NULL)) {

        this->has_met_before = TRUE;
    }

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
    }

    switch (this->state) {
        case CH_LOCKUP_STATE_CLOSED:
            if (!this->initialized) {
                this->marker->propPtr->unk8_3 = TRUE;
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSED, 0.2f, 1);
                this->marker->collidable = FALSE;
                this->unk38_31 = 0;
                this->initialized = TRUE;
            }

            local->closedTicksCounter++;

            cycle_ticks = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? LOCKUP_CYCLE_TICKS_SLOW :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? LOCKUP_CYCLE_TICKS_MEDIUM :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? LOCKUP_CYCLE_TICKS_FAST :
                     LOCKUP_CYCLE_TICKS_DEFAULT;

            if (!(local->closedTicksCounter < cycle_ticks)) {
                local->closedTicksCounter = 0;
                open(this);
            }

            break;

        case CH_LOCKUP_STATE_OPENING:
            if (subaddie_playerIsWithinSphere(this, 400) && func_8028FB48(0x8000000)) {
                func_8028F428(0xA, this->marker);
            }

            if (actor_animationIsAt(this, 0.5f)) {
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_OPEN, 0.5f, 1);
            }

            if (0.15 < anctrl_getAnimTimer(this->anctrl)) {
                this->marker->collidable = TRUE;
            }

            break;

        case CH_LOCKUP_STATE_OPEN:
            local->openTicksCounter++;
            cycle_ticks = (this->modelCacheIndex == ACTOR_151_LOCKUP_SLOW) ? LOCKUP_CYCLE_TICKS_SLOW :
                     (this->modelCacheIndex == ACTOR_152_LOCKUP_MEDIUM) ? LOCKUP_CYCLE_TICKS_MEDIUM :
                     (this->modelCacheIndex == ACTOR_153_LOCKUP_FAST) ? LOCKUP_CYCLE_TICKS_FAST :
                     LOCKUP_CYCLE_TICKS_DEFAULT;
            
            if (!(local->openTicksCounter < cycle_ticks)) {
                local->openTicksCounter = 0;
                subaddie_set_state_with_direction(this, CH_LOCKUP_STATE_CLOSING, 0.5f, 1);
            }

            break;

        case CH_LOCKUP_STATE_CLOSING:
        case CH_LOCKUP_STATE_CLOSING2:
            if (this->marker->unk14_21 && actor_animationIsAt(this, 0.99f)) {
                close(this);

                // Spawn smoke particles
                for (i = 5; i < 0xE; i++) {
                    func_8034A174(this->marker->unk44, i, this->unk1C);
                    dustEmitter_emit(this->unk1C, SMOKE_VELOCITY, SMOKE_COLOR, TRUE, 0.4f, 50.0f, 0xB4, 0xA0, DUST_EMITTER_TYPE_DUST);
                }
            }

            break;
    }
}
