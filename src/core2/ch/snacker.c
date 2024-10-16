#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "snacker.h"

extern f32 ml_distanceSquared_vec3f(f32 [3], f32 [3]);
extern f32 func_80309B24(f32[3]);
extern void func_80328FF0(Actor *, f32);
extern void mapSpecificFlags_setN(s32, s32, s32);

typedef enum {
    CH_SNACKER_OPA_0_APPEAR,
    CH_SNACKER_OPA_1_ACTIVE,
    CH_SNACKER_OPA_2_FADE
} ChSnackerOpacityState;

typedef enum {
    CH_SNACKER_STATE_1 = 1,
    CH_SNACKER_STATE_2,
    CH_SNACKER_STATE_3,
    CH_SNACKER_STATE_4,
    CH_SNACKER_STATE_5_EATING,
    CH_SNACKER_STATE_6,
    CH_SNACKER_STATE_7,
    CH_SNACKER_STATE_8_HURT,
    CH_SNACKER_STATE_9_DEAD
} ChSnackerState;

typedef struct {
    s32 ctl; //ChSnackerControl
    s32 opa; //opacity
    f32 unk8;
}ChSnackerLocal;

void chsnacker_update(Actor *this);

/* .data */
ActorAnimationInfo sChSnackerAnimations[] ={
    {0x000, 0.0f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 2.0f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 1.0f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 0.4f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 0.4f},
    {ASSET_154_ANIM_SNACKER_EATING,  1.1f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 0.4f},
    {ASSET_78_ANIM_SNACKER_SWIMMING, 1.0f},
    {ASSET_273_ANIM_SNACKER_HURT,    0.53f},
    {ASSET_274_ANIM_SNACKER_DIE,     1.09f}
};

ActorInfo gChSnacker = { 
    MARKER_14_SNACKER, ACTOR_68_SNACKER, ASSET_3B0_SNACKER,
    0x1, sChSnackerAnimations,
    chsnacker_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *s_chSnacker_marker;
f32 s_chSnacker_spawnTimer;
f32 s_chSnacker_respawnDelay_s;
s32 s_chSnacker_inRbb;
s32 D_8037E630;

/* .code */
void func_802E0CD0(Actor *this){
    this->actor_specific_1_f = 4.0f;
}

static void __chsnacker_start_dialog(Actor *this) {
    ChSnackerLocal *local = (ChSnackerLocal *)&this->local;
    s32 text_index;

    if (this->unk38_31 != 0) {
        this->unk38_31--;
    }
    else{
        this->actor_specific_1_f = 0.0f;
        if (level_get() == LEVEL_2_TREASURE_TROVE_COVE) {
            text_index = mapSpecificFlags_getN(8, 3);
            if( !this->has_met_before ) {
                if(text_index < 4) {
                    if(gcdialog_showText(0xA1B + text_index, 0, NULL, NULL, NULL, NULL)){
                        text_index++;
                        mapSpecificFlags_setN(8, text_index, 3);
                        this->has_met_before = TRUE;
                    }
                }
            }
        }
        subaddie_set_state_with_direction(this, 3, 0.0f, -1);
    }
}

bool func_802E0DC0(f32 snacker_position[3]){
    f32 player_position[3];
    f32 pad0;

    player_getPosition(player_position);
    return (4000000.0f < ml_distanceSquared_vec3f(player_position, snacker_position))
        || ( (snacker_position[1] - mapModel_getFloorY(snacker_position) < 70.0f) && (func_80309B24(snacker_position) - snacker_position[1] < 70.0f));
}

void func_802E0E88(Actor *this){
    this->actor_specific_1_f = 2.0f;
    subaddie_set_state_with_direction(this, 5, 0.0f, -1);
    actor_playAnimationOnce(this);
}

void func_802E0EC8(void){
    Actor *this;
    ChSnackerLocal *local;

    this = marker_getActor(s_chSnacker_marker);
    local = (ChSnackerLocal *)&this->local;

    actor_collisionOff(this);
    s_chSnacker_marker->propPtr->unk8_3 = FALSE;
    if(local->ctl != CH_SNACKER_OPA_2_FADE){
        func_8032BB88(this, -1, 750);
        comusic_8025AB44(COMUSIC_34_SNACKER_DANGER, 0, 750);
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        local->ctl = CH_SNACKER_OPA_2_FADE;
    }
}

static void __chsnacker_die(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    actor_collisionOff(this);
    FUNC_8030E8B4(SFX_179_GRUNTY_DAMAGE, 0.6f, 32750, this->position, 300, 3000);
    subaddie_set_state_with_direction(this, CH_SNACKER_STATE_9_DEAD, 0.0f, 1);
    actor_playAnimationOnce(this);
}

void func_802E0FC4(Actor *this){
    s_chSnacker_marker = NULL;
    D_8037E630 = this->unk166;
    if(func_8025AD7C(COMUSIC_34_SNACKER_DANGER)){
        func_8025AABC(COMUSIC_34_SNACKER_DANGER);
        func_8025A7DC(COMUSIC_34_SNACKER_DANGER);
    }
}

void func_802E1010(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    subaddie_set_state_with_direction(this, 8, 0.0f, 1);
    actor_playAnimationOnce(this);
}

static void __chsnacker_ow(ActorMarker *marker, ActorMarker *other){
    Actor *this;

    this = marker_getActor(marker);
    if(level_get() == LEVEL_2_TREASURE_TROVE_COVE && !player_isDead()){
        gcdialog_showText(0xA29, 0, NULL, NULL, NULL, NULL);
    }//L802E10A4

    if(this->state == 4){
        if(func_803294F0(this, 80, func_80329784(this))){
            func_802E0E88(this);
        }
    }//L802E10E0
}

f32 func_802E10F0(f32 arg0) {
    if ((arg0 >= 180.0f) && (arg0 < 330.0f)) {
        return 330.0f;
    }
    if ((arg0 < 180.0f) && (arg0 > 30.0f)) {
        return 30.0f;
    }
    return arg0;
}

void chsnacker_update(Actor *this) {
    f32 dt;
    ChSnackerLocal *local;
    SnackerCtlState controller_state;
    f32 player_position[3];
    f32 sp44;
    f32 sp40;
    s32 tmp;

    dt = time_getDelta();
    local = (ChSnackerLocal *)&this->local;

    if (!this->initialized) {
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk138_25 = TRUE;
        this->unk154 = 0x085E0000;
        marker_setCollisionScripts(this->marker, __chsnacker_ow, func_802E1010, __chsnacker_die);
    }
    _player_getPosition(player_position);
    controller_state = snackerctl_get_state();
    
    if(func_802E0DC0(this->position) || ((controller_state != SNACKER_CTL_STATE_1_RBB) && (controller_state != SNACKER_CTL_STATE_2_TTC))) {
        local->unk8 = MIN(3.5, local->unk8 + dt);
        if (local->unk8 == 3.5) {
            func_802E0EC8();
        }
    } else {
        local->unk8 = 0.0f;
    }
    
    switch(this->state){
        case 1: //802E12C8
            if (subaddie_maybe_set_state_position_direction(this, 2, 0.0f, 1, 0.03f) != 0) {
                func_802E0CD0(this);
            }
            __chsnacker_start_dialog(this);
            break;

        case 2: //802E130C
            func_80328FB0(this, 3.0f);
            func_80328FF0(this, 3.0f);
            func_8032CA80(this, (s_chSnacker_inRbb) ? 15 : 9);
            if (func_80329480(this) != 0) {
                func_80328CEC(this, (s32) this->yaw, 0x5A, 0x96);
            }
            subaddie_maybe_set_state_position_direction(this, 1, 0.0f, 1, 0.0075f);
            __chsnacker_start_dialog(this);
            break;

        case 3: //802E13AC
            func_803297FC(this, &sp44, &sp40);
            this->yaw_ideal = sp40;
            this->unk6C = func_802E10F0(sp44);
            func_80328FB0(this, 4.0f);
            func_80328FF0(this, 3.0f);
            if (func_80329480(this)) {
                subaddie_set_state_with_direction(this, 4, 0.0f, 1);
                this->actor_specific_1_f = 9.0f;
            }
            break;

        case 4: //802E1424
            func_803297FC(this, &sp44, &sp40);
            this->yaw_ideal = sp40;
            this->unk6C = func_802E10F0(sp44);
            func_80328FB0(this, this->actor_specific_1_f / 2);
            func_80328FF0(this, this->actor_specific_1_f / 2);
            this->actor_specific_1_f = MIN(50.0, this->actor_specific_1_f + dt);
            func_8032CA80(this, (s_chSnacker_inRbb) ? 15 : 9);
            break;

        case CH_SNACKER_STATE_5_EATING: //802E14F8
            if (actor_animationIsAt(this, 0.25f)) {
                FUNC_8030E8B4(SFX_6D_CROC_BITE, 1.0f, 28000, this->position, 300, 3000);
            }
            if (actor_animationIsAt(this, 0.99f)) {
                func_802E0CD0(this);
                func_80328CEC(this, (s32) this->yaw_ideal, 0x87, 0xAF);
                this->unk38_31 = 0x78;
                subaddie_set_state_with_direction(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            func_8032CA80(this, (s_chSnacker_inRbb) ? 15 : 9);
            break;

        case CH_SNACKER_STATE_8_HURT: //802E15BC
            if (animctrl_isStopped(this->animctrl)) {
                func_802E0CD0(this);
                subaddie_set_state_with_direction(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            break;

        case CH_SNACKER_STATE_9_DEAD: //802E15FC
            if (animctrl_isStopped(this->animctrl)) {
                s_chSnacker_respawnDelay_s = 60.0f;
                D_8037E630 = 0x63;
                func_802E0EC8();
            }
            break;
        default:
            break;
    }//L802E1630

    local = (ChSnackerLocal *)&this->local;
    switch(local->ctl){
        case CH_SNACKER_OPA_0_APPEAR:
            local->opa = MIN(0xFF, local->opa + 8);
            if(local->opa >= 0x81){
                this->marker->collidable = TRUE;
            }
            if (local->opa == 0xFF) {
                local->ctl = CH_SNACKER_OPA_1_ACTIVE;
            }
            break;

        case CH_SNACKER_OPA_1_ACTIVE:
            break;

        case CH_SNACKER_OPA_2_FADE:
            local->opa = MAX(0, local->opa - 8);
            if(local->opa < 0x80){
                this->marker->collidable = FALSE;
            }
            if (local->opa == 0) {
                marker_despawn(this->marker);
            }
            break;
    }

    actor_setOpacity(this, local->opa);
    this->depth_mode = (255.0 == local->opa) ? MODEL_RENDER_DEPTH_FULL : MODEL_RENDER_DEPTH_COMPARE;
}

void chSnacker_initialize(void){
    s_chSnacker_spawnTimer = 0.0f;
    s_chSnacker_respawnDelay_s = 1.0f;
    s_chSnacker_marker = NULL;
    s_chSnacker_inRbb = (level_get() == LEVEL_9_RUSTY_BUCKET_BAY);
    D_8037E630 = 0x63;
}

void chSnacker_spawn(void) {
    Actor *snacker;
    f32 spawn_position[3];
    f32 spawn_angle_rad;
    ChSnackerLocal *local;
    s32 pad;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];


    _player_getPosition(spawn_position);
    if (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) != 0) {
        nodeprop_getPosition(func_80304CAC(0x3CB, spawn_position), spawn_position);
    }
    else{
        spawn_angle_rad = randf2(0.0f, 3.28f);
        spawn_position[0] += 1000.0 * cosf(spawn_angle_rad);
        spawn_position[2] += 1000.0 * sinf(spawn_angle_rad);
        
        sp38[0] = spawn_position[0];
        sp38[1] = spawn_position[1];
        sp38[2] = spawn_position[2];
        sp38[1] += 1000.0f;
        
        sp2C[0] = spawn_position[0];
        sp2C[1] = spawn_position[1];
        sp2C[2] = spawn_position[2];
        sp2C[1] -= 1000.0f;


        if (func_80309B48(sp38, sp2C, sp20, 0xF800FF0F)) {
            spawn_position[1] = sp2C[1] - 60.0f;
        }
        else{
            return;
        }
    }

    snacker = actor_spawnWithYaw_f32(ACTOR_68_SNACKER, spawn_position, 0);
    s_chSnacker_marker = snacker->marker;

    local = (ChSnackerLocal *)&snacker->local;
    snacker->unk166 = (s8) D_8037E630;
    local->ctl = CH_SNACKER_OPA_0_APPEAR;
    local->opa = 0;
    local->unk8 = 0.0f;
    marker_setFreeMethod(s_chSnacker_marker, func_802E0FC4);
    if (func_8032CA80(snacker, s_chSnacker_inRbb ? 0x10 : 0xC)) {
        marker_despawn(s_chSnacker_marker);
        return;
    }
    if (volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) == 0) {
        func_8032BB88(snacker, 5000, 750);
        core1_ce60_incOrDecCounter(FALSE);
        func_8025A6EC(COMUSIC_34_SNACKER_DANGER, 0);
        comusic_8025AB44(COMUSIC_34_SNACKER_DANGER, 0x7FFF, 750);
        core1_ce60_incOrDecCounter(TRUE);
    }
    s_chSnacker_spawnTimer = 0.0f;
    func_8032CA80(snacker, s_chSnacker_inRbb ? 15 : 9);
}

void chsnacker_setControlState(SnackerCtlState control_state) {
    f32 dt;

    dt = time_getDelta();

    if( getGameMode() == GAME_MODE_A_SNS_PICTURE
        || getGameMode() == GAME_MODE_5_UNKNOWN
        || getGameMode() == GAME_MODE_6_FILE_PLAYBACK
    ){ 
        return;
    }
    
    if ((s_chSnacker_marker == NULL)) {
        s_chSnacker_spawnTimer += dt;
        if ((s_chSnacker_respawnDelay_s < s_chSnacker_spawnTimer) && (control_state != SNACKER_CTL_STATE_0_INACTIVE)) {
            __spawnQueue_add_0(chSnacker_spawn);
            s_chSnacker_respawnDelay_s = 1.0f;
        }
    }
}
