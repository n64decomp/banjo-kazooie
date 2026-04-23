#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "core2/modelRender.h"

Actor *chMrVile_draw(ActorMarker*, Gfx **, Mtx **, Vtx **);
void chMrVile_update(Actor *);
void chMrVile_attackPlayer(ActorMarker *);
extern bool func_80320C94(f32[3], f32[3], f32, f32[3], s32, u32);

extern bool chMrVileMinigame_findClosestPiece(ActorMarker *, f32[3], f32, f32[3]);

typedef struct chmrvile_s{
    u8 playerWithinRange; // can be 2 for some reason?
    // u8  pad1[0x3];
    BKModelBin *yumblieModel;
    ActorMarker *game_marker;
    u8  action;
    // u8  padD[0x3];
    f32 movementSpeed;
    f32 eatingTimer;
    f32 target_position[3];
    f32 animationSpeed;
    f32 rotation[3];
} ActorLocal_MrVile;

/* .data */
ActorInfo gChVile = {
    MARKER_C8_MR_VILE, ACTOR_13A_MR_VILE, ASSET_373_MODEL_MR_VILE,
    0x00, NULL,
    chMrVile_update, NULL, chMrVile_draw,
    0, 0, 0.0f, 0
};
                            // ROUND NUM   XX |  1  |  2  |  3  |  4  |   5  |  6  |
f32 chMrVileRubberbandingMultiplier[7] = {0.0f, 0.8f, 0.9f, 1.0f, 0.9f, 0.95f, 1.0f};

enum chMrVileState {
    CH_MR_VILE_STATE_1_IDLE_STILL = 1,
    CH_MR_VILE_STATE_2_TALKING,
    CH_MR_VILE_STATE_3_MINIGAME,
    CH_MR_VILE_STATE_4_ATTACK_PLAYER,
    CH_MR_VILE_STATE_5_IDLE_WALKING,
    CH_MR_VILE_STATE_6_RUN_FROM_PLAYER
};

enum chMrVileAction {
    CH_MR_VILE_ACTION_100_NOT_INIT = 100,
    CH_MR_VILE_ACTION_101_IDLE,
    CH_MR_VILE_ACTION_102_WALK,
    CH_MR_VILE_ACTION_103_BITE,
    CH_MR_VILE_ACTION_104_BURP
};

#define MR_VILE_BITE_PLAYER_DISTANCE   200.0f

/* .code */
void func_8038B9F0(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4) {
    f32 sp64[3];
    f32 pad60;
    f32 sp54[3];
    f32 pad50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 var_f0;

    sp44[0] = arg0[0];
    sp44[1] = arg0[1] + arg2;
    sp44[2] = arg0[2];

    sp38[0] = arg1[0];
    sp38[1] = arg1[1] + arg2;
    sp38[2] = arg1[2];

    sp2C[0] = sp38[0];
    sp2C[1] = sp38[1];
    sp2C[2] = sp38[2];
    if (func_80320C94(sp44, sp38, arg3, sp54, 3, arg4)) {
        sp64[0] = sp38[0] - sp2C[0];
        sp64[1] = sp38[1] - sp2C[1];
        sp64[2] = sp38[2] - sp2C[2];
        var_f0 = sp54[0]*sp64[0] + sp54[1]*sp64[1] + sp54[2]*sp64[2];
        if (var_f0 < 1.0f) {
            var_f0 = 1.0f;
        }
        ml_vec3f_set_length(sp54, var_f0);
        arg1[0] = arg1[0] + sp54[0];
        arg1[1] = arg1[1] + sp54[1];
        arg1[2] = arg1[2] + sp54[2];
    }
}

void chMrVile_attackPlayer(ActorMarker * arg0){
    Actor *this;
    ActorLocal_MrVile *local;

    this = marker_getActor(arg0);
    local = (ActorLocal_MrVile *)&this->local;
    if(chMrVileMinigame_getDialogIndex(local->game_marker) >= 3){
        item_set(ITEM_14_HEALTH, 0);
        func_8028F66C(BS_INTR_F);
    }
    else{
        item_dec(ITEM_14_HEALTH);
        func_8028F590(4, arg0);
    }
}

void chMrVile_setAction(Actor *this, s32 action){
    ActorLocal_MrVile *local;
    
    local = (ActorLocal_MrVile *)&this->local;
    local->eatingTimer = 0.0f;
    if(action == CH_MR_VILE_ACTION_101_IDLE){
        local->animationSpeed = 0.0f;
        local->rotation[0] = local->rotation[1] = local->rotation[2] = 0.0f;
        skeletalAnim_set(this->unk148, ASSET_E1_ANIM_BSCROC_IDLE, 0.10000000149f, 1.0f);
    }
    if(action == CH_MR_VILE_ACTION_102_WALK){
        if(local->animationSpeed < 100.0f){
            local->animationSpeed = 100.0f;
        };
        skeletalAnim_swap(this->unk148, ASSET_E0_ANIM_BSCROC_WALK, 0.1f, 0.5f);
    }
    if(action == CH_MR_VILE_ACTION_103_BITE){
        skeletalAnim_swap(this->unk148, ASSET_124_ANIM_VILE_BITE, 0.1f, 0.5f);
        if(this->state == CH_MR_VILE_STATE_4_ATTACK_PLAYER){
            timed_playSfx(0.31f, SFX_4C_LIP_SMACK, 0.90f, 25000);
            timedFunc_set_1(0.31f, (GenFunction_1)chMrVile_attackPlayer, reinterpret_cast(s32, this->marker));
        }
        else{
            timed_playSfx(0.31f, SFX_4C_LIP_SMACK, 0.90f, 25000);
            timed_playSfx(0.81f, SFX_4C_LIP_SMACK, 0.93f, 25000);
            timed_playSfx(1.31f, SFX_4C_LIP_SMACK, 0.91f, 25000);
        }
    }
    if(action == CH_MR_VILE_ACTION_104_BURP){
        local->eatingTimer = 1.0f;
        timed_playSfx(randf2(1.2f, 1.3f), SFX_97_BLUBBER_BURPS, randf2(0.8f, 1.1f), randi2(25000, 32000));
    }
    local->action = action; 
}

void func_8038BD84(Actor *this){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    local->action = CH_MR_VILE_ACTION_100_NOT_INIT;
    local->movementSpeed = 0.0f;
    local->eatingTimer = 0.0f;
    local->animationSpeed = 0.0f;
    local->target_position[0] = 0.0f;
    local->target_position[1] = 0.0f;
    local->target_position[2] = 0.0f;
    local->rotation[0] = 0.0f;
    local->rotation[1] = 0.0f; 
    local->rotation[2] = 0.0f;
    chMrVile_setAction(this, CH_MR_VILE_ACTION_101_IDLE);
}

void func_8038BDD4(Actor *this) {
    ActorLocal_MrVile *local;
    f32 start_position[3];
    f32 time_delta;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];
    f32 floor_y_position;

    local = (ActorLocal_MrVile *)&this->local;
    time_delta = time_getDelta();
    start_position[0] = this->position[0];
    start_position[1] = this->position[1];
    start_position[2] = this->position[2];
    ml_timer_update(&local->eatingTimer, time_delta);
    if ((local->action == CH_MR_VILE_ACTION_102_WALK)
        || (local->action == CH_MR_VILE_ACTION_103_BITE)
        || (local->action == CH_MR_VILE_ACTION_104_BURP))
    {
        sp44[0] = 0.0f;
        sp44[1] = 0.0f;
        sp44[2] = local->animationSpeed * time_delta;
        ml_vec3f_yaw_rotate_copy(sp44, sp44, this->yaw);
        this->position[0] = this->position[0] + sp44[0];
        this->position[1] = this->position[1] + sp44[1];
        this->position[2] = this->position[2] + sp44[2];
        this->pitch += local->rotation[0] * time_delta;
        this->yaw   += local->rotation[1] * time_delta;
        this->roll  += local->rotation[2] * time_delta;
        func_80258A4C(this->position, this->yaw - 90.0f, local->target_position, &sp58, &sp54, &sp50);
        if ((sp54 > 0.0f) && (sp58 > 200.0f)) {
            local->animationSpeed += 100.0f * time_delta;
        }
        if ((sp54 < 0.0f) && (sp58 > 100.0f)) {
            local->animationSpeed -= 100.0f * time_delta;
        }

        // 10.0f < local->movementSpeed < local->animationSpeed
        local->animationSpeed = (local->animationSpeed < 10.0f) ?
                            10.0f : (local->movementSpeed < local->animationSpeed) ?
                                local->movementSpeed : local->animationSpeed;
        skeletalAnim_setDuration(this->unk148, (200.0f / local->animationSpeed) * 0.5);
        local->rotation[1] = sp50 * 200.0f;
        floor_y_position = mapModel_getFloorY(this->position);
        if (floor_y_position > 125.0f) {
            this->position[1] = 125.0f;
        } else if (floor_y_position > 80.0f) {
            this->position[1] = floor_y_position;
        } else {
            this->position[1] = 0.0f;
        }
    }
    if (this->position[1] > 100.0f) {
        func_8038B9F0(start_position, this->position, 90.0f, 70.0f, 0);
    }
}

void chMrVile_setState(Actor * this, s32 next_state){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    if(next_state == CH_MR_VILE_STATE_1_IDLE_STILL)
        chMrVile_setAction(this, CH_MR_VILE_ACTION_101_IDLE);

    if(next_state == CH_MR_VILE_STATE_2_TALKING)
        chMrVile_setAction(this, CH_MR_VILE_ACTION_101_IDLE);

    if(next_state == CH_MR_VILE_STATE_3_MINIGAME)
        chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);

    if(next_state == CH_MR_VILE_STATE_4_ATTACK_PLAYER)
        chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);

    if(next_state == CH_MR_VILE_STATE_5_IDLE_WALKING){
        local->target_position[0] = local->target_position[1] = local->target_position[2] = 0.0f;
        chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);
    }

    if(next_state == CH_MR_VILE_STATE_6_RUN_FROM_PLAYER){
        local->target_position[0] = local->target_position[1] = local->target_position[2] = 0.0f;
        local->animationSpeed = 300.0f;
        chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);
    }

    this->state = next_state; 
}

Actor *chMrVile_draw(ActorMarker *marker, Gfx **gfx, Mtx** mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_MrVile *local;
    f32 position[3];
    

    this = actor_draw(marker, gfx, mtx, vtx);
    local = (ActorLocal_MrVile *)&this->local;
    if (
        (local->action == CH_MR_VILE_ACTION_104_BURP) &&
        (local->eatingTimer > 0.0f) 
        && (this->marker->unk14_21)
    ) {
        func_8034A174(func_80329934(), 5, position);
        position[1] -= 30.0f;
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(gfx, mtx, position, 0, local->eatingTimer, 0, local->yumblieModel);
    }
    return this;
}

f32 *chMrVile_getPostion(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    return this->position;
}

bool chMrVile_playerWithinRange(ActorMarker *marker) {
    f32 player_position[3];
    Actor *this;
    ActorLocal_MrVile *local;

    this = marker_getActor(marker);
    local = (ActorLocal_MrVile *)&this->local;
    player_getPosition(player_position);
    if (this->state == CH_MR_VILE_STATE_6_RUN_FROM_PLAYER) {
        return ml_vec3f_distance(this->position, player_position) < 150.0f;
    }
    return local->playerWithinRange == 1;
}


bool chMrVile_isInitialIdle(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    return this->state == CH_MR_VILE_STATE_1_IDLE_STILL;
}

void chMrVile_free(Actor *this){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    assetcache_release(local->yumblieModel);
}

void chMrVile_setStateAttackPlayer(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    chMrVile_setState(this, CH_MR_VILE_STATE_4_ATTACK_PLAYER);
}

void chMrVile_setStateTalkToPlayer(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    chMrVile_setState(this, CH_MR_VILE_STATE_2_TALKING);
}

void chMrVile_setStatePlayMinigame(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    chMrVile_setState(this, CH_MR_VILE_STATE_3_MINIGAME);
}

void chMrVile_setStateIdleWalking(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    chMrVile_setState(this, CH_MR_VILE_STATE_5_IDLE_WALKING);
}

void chMrVile_setStateRunFromPlayer(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    chMrVile_setState(this, CH_MR_VILE_STATE_6_RUN_FROM_PLAYER);
}

void chMrVile_setInitialIdleStill(ActorMarker *arg0){
    chMrVile_setState(marker_getActor(arg0), CH_MR_VILE_STATE_1_IDLE_STILL);
}

void chMrVile_update(Actor *this) {
    f32 player_position[3];
    f32 distance_from_player;
    f32 temp_a0; // unused
    bool next_target_exists;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    s32 score_diff;
    s32 random_position_count;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    ActorLocal_MrVile *local;
    f32 random_position[3];

    local = (ActorLocal_MrVile *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->actorFreeFunc = chMrVile_free;
        local->playerWithinRange = 0;
        local->yumblieModel = assetcache_get(ASSET_3F6_MODEL_YUMBLIE);
        local->game_marker = NULL;
        func_8038BD84(this);
        chMrVile_setState(this, CH_MR_VILE_STATE_1_IDLE_STILL);
        return;
    }
    if (local->game_marker == NULL) {
        local->game_marker = actorArray_findClosestActorFromActorId(this->position, 0x138, -1, &distance_from_player)->marker;
    }
    player_getPosition(player_position);
    distance_from_player = ml_vec3f_distance(this->position, player_position);
    if (distance_from_player <= 300.0f) {
        local->playerWithinRange =  (local->playerWithinRange == 0) ? 1 : 2;
    } else if (distance_from_player > 300.0f) {
        local->playerWithinRange = 0U;
    }
    if (this->state == CH_MR_VILE_STATE_2_TALKING) {
        func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp84, &sp80, &sp7C);
        if (((sp84 > 50.0f) && (0.05 < sp7C)) || (sp7C < -0.05)) {
            this->yaw += sp7C * 20.0f;
        } else {
            chMrVile_setState(this, CH_MR_VILE_STATE_1_IDLE_STILL);
        }
    }
    if (this->state == CH_MR_VILE_STATE_3_MINIGAME) {
        next_target_exists = chMrVileMinigame_findClosestPiece(local->game_marker, this->position, this->yaw, local->target_position) && mapSpecificFlags_get(BGS_SPECIFIC_FLAG_6_MR_VILE);
        if (!next_target_exists) {
            local->target_position[0] = 0.0f;
            local->target_position[1] = 0.0f;
            local->target_position[2] = 0.0f;
        }
        if (local->game_marker != NULL) {
            score_diff = chMrVileMinigame_getScoreDifference(local->game_marker);
            if (score_diff >= 2) {
                local->movementSpeed = 200.0f;
            } else if (score_diff >= 0) {
                local->movementSpeed = 310.0f;
            } else if (score_diff >= -2) {
                local->movementSpeed = 350.0f;
            } else {
                local->movementSpeed = 450.0f;
            }
            local->movementSpeed *= chMrVileRubberbandingMultiplier[chMrVileMinigame_getDialogIndex(local->game_marker)];
        }
        if (chMrVileMinigame_getDialogIndex(local->game_marker) < 7) {
            func_80258A4C(this->position, this->yaw - 90.0f, local->target_position, &sp70, &sp6C, &sp68);
            if (local->action == CH_MR_VILE_ACTION_102_WALK) {
                if ((-0.8 < sp68) && (sp68 < 0.8) && (sp70 <= 150.0f) && next_target_exists) {
                    chMrVile_setAction(this, CH_MR_VILE_ACTION_103_BITE);
                }
            }
            if (local->action == CH_MR_VILE_ACTION_103_BITE) {
                if (sp70 <= 50.0f) {
                    if (chMrVileMinigame_mrVileConsumePiece(local->game_marker, local->target_position)) {
                        chMrVile_setAction(this, CH_MR_VILE_ACTION_104_BURP);
                    } else {
                        chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);
                    }
                } else if (skeletalAnim_getLoopCount(this->unk148) >= 3) {
                    chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);
                }
            }
            if ((local->action == CH_MR_VILE_ACTION_104_BURP)
                && (skeletalAnim_getLoopCount(this->unk148) >= 3))
            {
                chMrVile_setAction(this, CH_MR_VILE_ACTION_102_WALK);
            }
        }
    }
    if (this->state == CH_MR_VILE_STATE_4_ATTACK_PLAYER) {
        player_getPosition(local->target_position);
        local->movementSpeed = 500.0f;
        if ((local->action == CH_MR_VILE_ACTION_102_WALK)
            && (ml_vec3f_distance(this->position, local->target_position) < MR_VILE_BITE_PLAYER_DISTANCE))
        {
            chMrVile_setAction(this, CH_MR_VILE_ACTION_103_BITE);
        }
        if ((local->action == CH_MR_VILE_ACTION_103_BITE)
            && (skeletalAnim_getLoopCount(this->unk148) >= 2))
        {
            chMrVile_setState(this, CH_MR_VILE_STATE_1_IDLE_STILL);
        }
    }
    if (this->state == CH_MR_VILE_STATE_5_IDLE_WALKING) {
        local->movementSpeed = 200.0f;
        if (ml_vec3f_distance(this->position, local->target_position) < 100.0f) {
            local->target_position[0] = randf2(-500.0f, 500.0f);
            local->target_position[1] = 0.0f;
            local->target_position[2] = randf2(-500.0f, 500.0f);
        }
    }
    if ((this->state == CH_MR_VILE_STATE_6_RUN_FROM_PLAYER)){
        local->movementSpeed = 400.0f;
        if((ml_vec3f_distance(this->position, local->target_position) < 100.0f)
            || (ml_vec3f_distance(player_position, local->target_position) < 300.0f))
        {
            for(random_position_count = 0; random_position_count < 10; random_position_count++){
                random_position[0] = randf2(-500.0f, 500.0f);
                random_position[1] = 0.0f;
                random_position[2] = randf2(-500.0f, 500.0f);
                if ((random_position_count == 0)
                    || (ml_vec3f_distance(player_position, random_position) > ml_vec3f_distance(player_position, local->target_position)))
                {
                    local->target_position[0] = random_position[0];
                    local->target_position[1] = random_position[1];
                    local->target_position[2] = random_position[2];
                }
            };
        }
    }
    func_8038BDD4(this);
    if (this->state != CH_MR_VILE_STATE_4_ATTACK_PLAYER) {
        func_8028E668(this->position, 100.0f, -50.0f, 120.0f);
    }
}
