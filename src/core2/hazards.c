#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/timer.h"
#include "core2/statetimer.h"
#include "ba/iFrame.h"

extern BKCollisionTri *func_8029463C(void);

/* .bss */
u8 hazardSfxId;
u8 frozenEffectsState;
u8 swampEffectsState;
f32 playerPosition[3];
f32 effectTimer;

/*.code */
bool isOnFloor(void) {
    return floor_isCurrentFloorunk59() && floor_getCurrentFloorYPosition() > playerPosition_getY();
}

void freeHazardSfxId(void) {
    sfxsource_freeSfxsourceByIndex(hazardSfxId);
}

void hazards_reset(void) {
    baflag_clear(BA_FLAG_13_TOUCHING_DANGEROUS_GROUND);
    hazardSfxId = sfxsource_createSfxsourceAndReturnIndex();
    swampEffectsState = 0;
}

void triggerFrozenHazardEffects(void) {
    basfx_80299E48();
    sfxSource_triggerCallbackByIndex(hazardSfxId);
    sfxsource_setSfxId(hazardSfxId, SFX_14D_BANJO_FREEZING);
    sfxsource_setSampleRate(hazardSfxId, 30000);
    sfxsource_playSfxAtVolume(hazardSfxId, 1.2f);
    sfxSource_setunk43_7ByIndex(hazardSfxId, 3);
    sfxSource_func_8030E2C4(hazardSfxId);

    frozenEffectsState = 2;
    effectTimer = 1.0f;
}

void triggerHotHazardEffects(void) {
    sfxSource_triggerCallbackByIndex(hazardSfxId);
    sfxsource_setSfxId(hazardSfxId, SFX_B0_SIZZLING_NOISE);
    sfxsource_setSampleRate(hazardSfxId, 32000);
    sfxsource_playSfxAtVolume(hazardSfxId, randf2(0.7f, 0.8f));
    sfxSource_setunk43_7ByIndex(hazardSfxId, 3);
    sfxSource_func_8030E2C4(hazardSfxId);
}

void spawnPiranhaParticles(void) {
    f32 player_position[3];

    player_getPosition(player_position);
    actor_spawnWithYaw_f32(ACTOR_188_PIRANHA_WATER_PARTICLES, player_position, (s32)yaw_get());
}

void triggerSwampHazardEffects(void) {
    __spawnQueue_add_0(&spawnPiranhaParticles);
    FUNC_8030E624(SFX_A_BANJO_LANDING_05, 1.0f, 28000);
    sfxSource_triggerCallbackByIndex(hazardSfxId);
    sfxsource_setSfxId(hazardSfxId, SFX_6D_CROC_BITE);
    sfxsource_setSampleRate(hazardSfxId, 22000);
    sfxSource_setunk43_7ByIndex(hazardSfxId, 3);

    player_getPosition(playerPosition);
    playerPosition[1] = floor_getCurrentFloorYPosition();

    swampEffectsState = 4;
    effectTimer = 0.0f;
}

void triggerHazardEffects(void) {
    switch (gsworld_get_map()) {
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
        case MAP_3C_RBB_KITCHEN:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_8E_GL_FURNACE_FUN:
            triggerHotHazardEffects();
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_7F_FP_WOZZAS_CAVE:
            triggerFrozenHazardEffects();
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_72_GL_BGS_LOBBY:
            triggerSwampHazardEffects();
            break;
    }
}

void updateFrozenEffects(void) {
    if (frozenEffectsState == 0) {
        return;
    }

    if ((isOnFloor() == 0) && (func_8028F2FC() == 0) && (func_8030E3FC(hazardSfxId) != 0)) {
        sfxSource_triggerCallbackByIndex(hazardSfxId);
        frozenEffectsState = 0;
        return;
    }

    effectTimer = ml_max_f(0.0f, effectTimer - time_getDelta());

    if (effectTimer != 0.0f) {
        return;
    }

    if (frozenEffectsState == 1) { // Seems to never be able to trigger
        triggerFrozenHazardEffects();
    } else if (frozenEffectsState == 2) {
        sfxSource_triggerCallbackByIndex(hazardSfxId);
        sfxsource_setSfxId(hazardSfxId, SFX_134_FREEZING_SHIVER);
        sfxsource_setSampleRate(hazardSfxId, 20000);
        sfxsource_playSfxAtVolume(hazardSfxId, 1.2f);
        sfxSource_setunk43_7ByIndex(hazardSfxId, 3);
        sfxSource_func_8030E2C4(hazardSfxId);
        frozenEffectsState = 2;
        effectTimer = 1.5f;
    }
}

void updateBurnSfx(void) {
    f32 delta_time;
    s32 sample_rate;

    if (func_8030E3FC(hazardSfxId) == 0) {
        return;
    }

    delta_time = time_getDelta();
    sample_rate = sfxSource_getSampleRate(hazardSfxId) - (s32) (delta_time * 30000.0);

    if (sample_rate <= 0) {
        sfxSource_triggerCallbackByIndex(hazardSfxId);
        return;
    }

    sfxsource_setSampleRate(hazardSfxId, sample_rate);
}

// Interesting to note, this update function plays the sfx while the other ones wait until after Banjo
//     has been damaged.
void updateSwampEffects(void) {
    if (swampEffectsState == 0) {
        return;
    }

    effectTimer = ml_max_f(0.0f, effectTimer - time_getDelta());

    if (effectTimer > 0.0f) {
        return;
    }

    swampEffectsState -= 1;
    effectTimer = randf2(0.12f, 0.22f);
    sfxsource_playSfxAtVolume(hazardSfxId, randf2(0.95f, 1.05f));
    sfxSource_func_8030E2C4(hazardSfxId);
}

void updateHazardEffects(void) {
    switch (gsworld_get_map()) {
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
        case MAP_3C_RBB_KITCHEN:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_8E_GL_FURNACE_FUN:
            updateBurnSfx();
            break;

        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_7F_FP_WOZZAS_CAVE:
            updateFrozenEffects();
            break;

        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_72_GL_BGS_LOBBY:
            updateSwampEffects();
            break;
    }
}

bool isPlayerInHazard(void) {
    f32 player_position[3];

    switch (gsworld_get_map()) {
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
        case MAP_3C_RBB_KITCHEN:
        case MAP_43_CCW_SPRING:
        case MAP_44_CCW_SUMMER:
        case MAP_45_CCW_AUTUMN:
        case MAP_46_CCW_WINTER:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_72_GL_BGS_LOBBY:
        case MAP_8E_GL_FURNACE_FUN:
            return func_80294610(0xE000) && player_isStable();

        case MAP_31_RBB_RUSTY_BUCKET_BAY:
            player_getPosition(player_position);
            return player_inWater() && ml_vec3f_inside_box_f(player_position, -9000.0f, -3000.0f, -3850.0f, -6820.0f, -700.0f, -1620.0f);

        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_7F_FP_WOZZAS_CAVE:
            return player_inWater();
    }

    return FALSE;
}

bool canTakeGroundDamage(void) {
    enum bs_e bs_state;

    bs_state = bs_getState();

    switch (gsworld_get_map()) {
        case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
        case MAP_12_GV_GOBIS_VALLEY:
        case MAP_1B_MMM_MAD_MONSTER_MANSION:
        case MAP_27_FP_FREEZEEZY_PEAK:
        case MAP_31_RBB_RUSTY_BUCKET_BAY:
        case MAP_3C_RBB_KITCHEN:
        case MAP_43_CCW_SPRING:
        case MAP_44_CCW_SUMMER:
        case MAP_45_CCW_AUTUMN:
        case MAP_46_CCW_WINTER:
        case MAP_6E_GL_GV_LOBBY:
        case MAP_72_GL_BGS_LOBBY:
        case MAP_7F_FP_WOZZAS_CAVE:
        case MAP_8E_GL_FURNACE_FUN:
            return isPlayerInHazard() 
                && bsStoredState_getTransformation() == TRANSFORM_1_BANJO
                && stateTimer_isDone(STATE_TIMER_2_LONGLEG)
                && player_movementGroup() != BSGROUP_3_WONDERWING
                && player_movementGroup() != BSGROUP_9_LONG_LEG
                && baflag_isFalse(BA_FLAG_E_TOUCHING_WADING_BOOTS)
                && bs_state != BS_25_LONGLEG_ENTER
                && player_getWaterState() != BSWATERGROUP_2_UNDERWATER
                && func_8028EC04() < 1U
                && baiFrame_getState() != IFRAME_INVICIBLE
                && bs_getState() != BS_3D_FALL_TUMBLING
                && player_isDead() < 1U;
    }

    return FALSE;
}

void hazards_update(void) {
    bool can_take_ground_damage;
    BKCollisionTri *collision;
    s32 sp1C;
    s32 sp18;
    
    updateHazardEffects();

    if (gsworld_get_map() == MAP_12_GV_GOBIS_VALLEY) {
        sp18 = 0;
        sp1C = 0;

        collision = func_802946F0();

        if (collision != NULL) {
            sp1C = collision->flags & 0x4000;
        }

        collision = func_8029463C();

        if (collision != NULL) {
            sp18 = (collision->flags & 0x4000) && player_isStable();
        }

        if (sp1C || sp18) {
            baMotor_80250D94(1.0f, 0.5f, 0.4f);
            player_checkHazardInterrupt(0xD);
        }
    }

    can_take_ground_damage = canTakeGroundDamage();
    batimer_decrement(BA_TIMER_HAZARDS);

    if (can_take_ground_damage) {
        if (gsworld_get_map() == MAP_8E_GL_FURNACE_FUN) {
            if (bs_checkInterrupt(BS_INTR_13_FF_DEATH_SQUARE)) {
                triggerHazardEffects();
            }
        } else {
        
            if (batimer_isZero(4)) {
                batimer_set(4, 4.0f);

                if (player_checkHazardInterrupt(0xD)) { // If not invincible, reduces health
                    triggerHazardEffects();
                    baMotor_80250D94(1.0f, 0.5f, 0.4f);
                }

                if (item_empty(ITEM_14_HEALTH)) {
                    bs_checkInterrupt(BS_INTR_13_FF_DEATH_SQUARE);
                }
            }

            switch (gsworld_get_map()) { // Show dialog associated with touching a hazard for the first time
                case MAP_43_CCW_SPRING:
                case MAP_44_CCW_SUMMER:
                case MAP_45_CCW_AUTUMN:
                case MAP_46_CCW_WINTER:
                    progressDialog_showDialogMaskZero(FILEPROG_AA_HAS_TOUCHED_CCW_BRAMBLE_FIELD);
                    break;

                case MAP_D_BGS_BUBBLEGLOOP_SWAMP:
                case MAP_72_GL_BGS_LOBBY:
                    progressDialog_showDialogMaskZero(FILEPROG_F_HAS_TOUCHED_PIRANHA_WATER);
                    break;

                case MAP_3C_RBB_KITCHEN:
                    progressDialog_showDialogMaskZero(FILEPROG_A9_HAS_TOUCHED_RBB_OVEN);
                    break;

                case MAP_12_GV_GOBIS_VALLEY:
                case MAP_6E_GL_GV_LOBBY:
                case MAP_8E_GL_FURNACE_FUN:
                    progressDialog_showDialogMaskZero(FILEPROG_10_HAS_TOUCHED_SAND_EEL_SAND);
                    break;

                case MAP_27_FP_FREEZEEZY_PEAK:
                case MAP_7F_FP_WOZZAS_CAVE:
                    progressDialog_showDialogMaskZero(FILEPROG_14_HAS_TOUCHED_FP_ICY_WATER);
                    break;

                case MAP_1B_MMM_MAD_MONSTER_MANSION:
                    if (!isOnFloor()) {
                        progressDialog_showDialogMaskZero(FILEPROG_86_HAS_TOUCHED_MMM_THORN_HEDGE);
                    }

                    break;
            }
        }

        baflag_set(BA_FLAG_13_TOUCHING_DANGEROUS_GROUND);
    } else {
        baflag_clear(BA_FLAG_13_TOUCHING_DANGEROUS_GROUND);
    }
}
