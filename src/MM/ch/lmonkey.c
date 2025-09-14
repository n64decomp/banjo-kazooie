#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* external function declarations */
void func_8028E668(f32 *, f32, f32, f32);
int actor_animationIsAt(Actor *, f32);
void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
void timed_exitStaticCamera(f32);
void func_80324E38(f32, s32);
void timed_setStaticCameraToNode(f32, s32);
s32 player_setCarryObjectPoseInHorizontalRadius(f32 *, f32, s32, Actor **);

void func_8028FA34(s32, Actor *);

/* public function declarations */
void chlmonkey_update(Actor *);

/* .data */
enum chlmonkey_state_e {
    LMONKEY_STATE_1_IDLE = 1,
    LMONKEY_STATE_2_JUMPING,
    LMONKEY_STATE_3_WALKING,
    LMONKEY_STATE_4_LEAVING
};

ActorAnimationInfo chlmonkeyAnimations[5] = {
    {0,                         0.0f},
    {ASSET_5C_ANIM_CHIMPY_IDLE, 2.3f},
    {ASSET_5B_ANIM_CHIMPY_JUMP, 0.67f},
    {ASSET_5D_ANIM_CHIMPY_WALK, 0.5f},
    {ASSET_5C_ANIM_CHIMPY_IDLE, 2.3f}
};

ActorInfo chlmonkeyInfo = {
    MARKER_A_CHIMPY, ACTOR_F_CHIMPY, ASSET_35D_MODEL_CHIMPY,
    1, chlmonkeyAnimations,
    NULL, chlmonkey_update, actor_draw,
    2500, 0, 0.8f, 0
};

/* .code */
void __chlmonkey_updateBringOrange(Actor **this_ptr) {
    player_setCarryObjectPoseInHorizontalRadius((*this_ptr)->position, 800.0f, ACTOR_29_ORANGE_COLLECTIBLE, this_ptr);

    if (subaddie_playerIsWithinSphereAndActive(*this_ptr, 345) &&
        bacarry_get_markerId() == MARKER_36_ORANGE_COLLECTIBLE &&
        player_throwCarriedObject()) {

        func_8028FA34(0xc6, *this_ptr);
        (*this_ptr)->has_met_before = TRUE;
        timed_setStaticCameraToNode(1.2f, 0xF);
        func_80324E38(1.2f, 3);
    }

    if (this_ptr);
}

void __chlmonkey_playRandomNoise(Actor *this) {
    f32 scaled_noise_volume;
    f32 random_noise;
    static sNoiseCooldown = 0;

    scaled_noise_volume = ml_map_f(func_8032970C(this), 1000000.0f, 343000000.0f, 18000.0f, 0.0f);
    random_noise = randf();
    sNoiseCooldown--;

    if (sNoiseCooldown < 0 && randf() < 0.2) {
        sNoiseCooldown = 6;
        gcsfx_playWithPitch(((random_noise < 0.5) ? SFX_58_CHIMPY_NOISE_1 : SFX_59_CHIMPY_NOISE_2), randf() * 0.25 + 0.85, scaled_noise_volume);
    }
}

void __chlmonkey_spawnJiggy(s32 x, s32 y, s32 z) {
    f32 pos[3];

    TUPLE_ASSIGN(pos, x, y, z)
    jiggy_spawn(JIGGY_9_MM_CHIMPY, pos);
}

void __chlmonkey_complete(ActorMarker *marker, enum asset_e unused_1, s32 unused_2) {
    Actor *actor = marker_getActor(marker);

    mapSpecificFlags_set(MM_SPECIFIC_FLAG_4_SHAKE, TRUE);
    subaddie_set_state(actor, LMONKEY_STATE_3_WALKING);
    timed_setStaticCameraToNode(2.3f, 0x12);
    timedFunc_set_3(2.9f, __chlmonkey_spawnJiggy, actor->position_x, actor->position_y + 150.0f, actor->position_z);
    timed_exitStaticCamera(4.3f);
    func_80324E38(4.3f, 0);
}

void chlmonkey_update(Actor *this) {
    func_8028E668(this->position, 35.0f, 0.0f, 65.0f);
    actor_collisionOff(this);
    this->marker->propPtr->unk8_3 = 1;

    if (gsworld_get_map() != MAP_2_MM_MUMBOS_MOUNTAIN) {
        func_80343DEC(this);
    }
    else {//L80388630
        if (subaddie_playerIsWithinSphereAndActive(this, 700) && !gcdialog_hasCurrentTextId()) {
            __chlmonkey_playRandomNoise(this);
        }//L8038865C

        switch (this->state) {
            case LMONKEY_STATE_1_IDLE://L80388690
                if (mapSpecificFlags_get(MM_SPECIFIC_FLAG_2_ORANGE_HAS_BEEN_RETURNED)) {
                    subaddie_set_state(this, LMONKEY_STATE_4_LEAVING);

                    if (!jiggyscore_isCollected(JIGGY_9_MM_CHIMPY)) {
                        gcdialog_showDialog(ASSET_B40_DIALOG_CHIMPY_COMPLETE, 0xE, this->position, this->marker, __chlmonkey_complete, NULL);
                    }
                    else {//L803886E8
                        __chlmonkey_complete(this->marker, ASSET_B40_DIALOG_CHIMPY_COMPLETE, -1);
                    }//L80388898
                }
                else {
                    __chlmonkey_updateBringOrange(&this);

                    if (subaddie_playerIsWithinSphereAndActive(this, 345) &&
                        !subaddie_playerIsWithinSphereAndActive(this, 150) &&
                        !item_getCount(ITEM_19_ORANGE) &&
                        !this->has_met_before) {

                        gcdialog_showDialog(ASSET_B3F_DIALOG_CHIMPY_MEET, 0xe, this->position, NULL, NULL, NULL);
                        this->has_met_before = TRUE;
                    }//L80388774

                    actor_loopAnimation(this);
                    subaddie_maybe_set_state_position_direction(this, LMONKEY_STATE_2_JUMPING, 0.0f, -1, 0.02f);
                }
                break;

            case LMONKEY_STATE_2_JUMPING: //L803887A4
                __chlmonkey_updateBringOrange(&this);
                actor_playAnimationOnce(this);

                if (actor_animationIsAt(this, 0.99f)) {
                    subaddie_set_state_with_direction(this, LMONKEY_STATE_1_IDLE, 0.0f, -1);
                }
                break;

            case LMONKEY_STATE_4_LEAVING: //L803887E4
                actor_loopAnimation(this);
                break;

            case LMONKEY_STATE_3_WALKING: //L803887F4
                func_80343DEC(this);
                actor_loopAnimation(this);

                if (0.19 <= this->unk48) {
                    mapSpecificFlags_set(MM_SPECIFIC_FLAG_0_CHIMPY_STUMP_RAISED, TRUE);
                }

                if (0.24 <= this->unk48) {
                    mapSpecificFlags_set(MM_SPECIFIC_FLAG_3_CHIMPY_HAS_LEAVED, TRUE);
                }

                if (0.99 <= this->unk48) {
                    marker_despawn(this->marker);
                }
                break;
        }
    }//L80388898
}
