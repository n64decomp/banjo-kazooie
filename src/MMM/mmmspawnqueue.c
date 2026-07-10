#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "actor.h"

#include "core2/dustemitter.h"

extern ActorInfo chShackDoor;
extern ActorInfo chMansionDoor;
extern ActorInfo chCellarHatch;
extern ActorInfo chChuchGateLeftLock;
extern ActorInfo chHedgeGateRightLock1;
extern ActorInfo chHedgeGateRightLock2;
extern ActorInfo chChuchDoor;
extern ActorInfo ch1881BarrelTop;
extern ActorInfo chXBarrelTop;
extern ActorInfo chMMMWindow;
extern ActorInfo chMMMWideWindow;
extern ActorInfo chMMMTallWindow;
extern ActorInfo chDiningDoor;
extern ActorInfo chMMMClockSwitch;
extern ActorInfo chNapper;
extern ActorInfo chCemetaryPot;
extern ActorInfo chMotzhand;
extern ActorInfo chLoggo;
extern ActorInfo chPortraitChompa;
extern ActorInfo chPortraitGrunty;
extern ActorInfo chPortraitBlackeye;
extern ActorInfo chPortraitTower;
extern ActorInfo chPortraitTreeAndMoon;
extern ActorInfo chPortraitTeeHee;
extern ActorInfo chPortraitMinion;

extern ActorInfo D_80367E70;
extern ActorInfo chPurpleTeeHee;

extern void core1_7090_initSfxSource(s32, s32, s32, f32);
extern void func_8025AE0C(s32, f32);
extern void *func_80309B48(f32[3], f32[3], f32[3], u32);

void chMMMBreakableWooden_update(Actor *this);
void chMMMGate_update(Actor *this);
Actor *chMMMGate_draw(ActorMarker *marker, Gfx ** gfx, Mtx **mtx, Vtx **vtx);
void chChurchDoor_update(Actor *this);
void chMMMClockSwitch_update(Actor *this);
void chMMMWoodenDoor_update(Actor *this);
void chXBarrelTop_update(Actor *this);
void chMMMWindow_update(Actor *this);

/* .data */
ActorAnimationInfo D_8038BBE0[] = {
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0xD4, 0.15f},
    {0xD5, 0.5f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f},
    {0x00, 0.0f}
};

ActorInfo chShackDoor = {
    MARKER_9C_SHACK_DOOR, ACTOR_109_SHACK_DOOR, ASSET_3CD_MODEL_SHACK_DOOR,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chCellarHatch = {
    MARKER_9E_CELLAR_HATCH, ACTOR_10B_CELLAR_HATCH, ASSET_3CF_MODEL_CELLAR_HATCH,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo ch1881BarrelTop = {
    MARKER_9A_1881_BARREL_TOP,  ACTOR_CB_1881_BARREL_TOP, ASSET_3CC_MODEL_1881_BARREL_TOP,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chChuchDoor = {
    MARKER_A2_CHURCH_DOOR, ACTOR_114_CHURCH_DOOR, ASSET_3D3_MODEL_CHURCH_DOOR,
    0x1, NULL,
    chChurchDoor_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chDiningDoor = {
    MARKER_E7_DINING_DOOR, ACTOR_265_DINING_DOOR, ASSET_4DA_MODEL_DINING_DOOR,
    0x1, NULL,
    chMMMWoodenDoor_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chMansionDoor = {
    MARKER_9D_MANSION_DOOR, ACTOR_10A_MANSION_DOOR, ASSET_3CE_MODEL_MANSION_DOOR,
    0x1, NULL,
    chMMMWoodenDoor_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chXBarrelTop = {
    MARKER_D3_X_BARREL_TOP, ACTOR_191_X_BARREL_TOP, ASSET_50B_MODEL_X_BARREL_TOP,
    0x1, NULL,
    chXBarrelTop_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chMMMWindow = {
    MARKER_123_WINDOW, ACTOR_2E8_WINDOW, ASSET_4C0_MODEL_WINDOW,
    0x1, NULL,
    chMMMWindow_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chMMMWideWindow = {
    MARKER_1F2_WIDE_WINDOW, ACTOR_2E9_WIDE_WINDOW, ASSET_4C1_MODEL_WIDE_WINDOW,
    0x1, NULL,
    chMMMWindow_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chMMMTallWindow = {
    MARKER_1F3_TALL_WINDOW, ACTOR_2EA_TALL_WINDOW, ASSET_4C2_MODEL_TALL_WINDOW,
    0x1, NULL,
    chMMMWindow_update, actor_update_func_80326224, actor_drawFullDepth,
    0, 0, 0.0f, 0
};

ActorInfo chMMMClockSwitch = {
    MARKER_FE_MMM_CLOCK_SWITCH, ACTOR_1FD_MMM_CLOCK_SWITCH, ASSET_43D_MODEL_MMM_CLOCK_SWITCH, 
    0x1, D_8038BBE0,
    chMMMClockSwitch_update, actor_update_func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

ActorInfo chChuchGateLeftLock = {
    MARKER_9F_CHURCH_GATE_LEFT_LOCK, ACTOR_10C_CHURCH_GATE_LEFT_LOCK, ASSET_3D0_MODEL_CHURCH_GATE_LEFT_LOCK,
    0x1, NULL,
    chMMMGate_update, actor_update_func_80326224, chMMMGate_draw,
    0, 0, 0.0f, 0
};

ActorInfo chHedgeGateRightLock1 = {
    MARKER_A0_HEDGE_GATE_RIGHT_LOCK_1, ACTOR_10D_HEDGE_GATE_RIGHT_LOCK_1, ASSET_3D1_MODEL_HEDGE_GATE_RIGHT_LOCK_1,
    0x1, NULL,
    chMMMGate_update, actor_update_func_80326224, chMMMGate_draw,
    0, 0, 0.0f, 0
};

ActorInfo chHedgeGateRightLock2 = {
    MARKER_FF_HEDGE_GATE_RIGHT_LOCK_2, ACTOR_1FE_HEDGE_GATE_RIGHT_LOCK_2, ASSET_43E_MODEL_HEDGE_GATE_RIGHT_LOCK_2,
    0x1, NULL,
    chMMMGate_update, actor_update_func_80326224, chMMMGate_draw,
    0, 0, 0.0f, 0
};

s32 D_8038BE20[4] = {0x87, 0x87, 0x87, 0xB4};

/* .code */
f32 MMM_func_80388430(Actor *this, s32 arg1, s32 arg2, f32 arg3) {
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];

    if (this->unk38_31 == 0) {
        this->unk38_31 = 1;
        this->unk1C[1] = 71.0f;
    }
    this->position[arg1] += (f32) (arg2 * 0x13);

    sp34[0] = sp4C[0] = this->position[0];
    sp4C[1] = this->position[1];
    sp34[2] = sp4C[2] = this->position[2];

    this->position[1] += this->unk1C[1];
    this->unk1C[1] -= 8.0;
    sp34[1] = this->position[1] - 400.0f;
    if (this->unk1C[1] < 0.0f) {
        if (func_80309B48(sp4C, sp34, sp40, 0) && (this->position[1] <= sp34[1])) {
            this->position[1] = sp34[1] + 6.0f;
            switch (this->unk38_31) {
            case 1:
                this->unk38_31 = 2;
                this->unk1C[1] = 38.0f;
                break;
            case 2:
                this->unk38_31 = 3;
                this->unk1C[1] = 11.0f;
                break;
            case 3:
                subaddie_set_state(this, 5);
                break;
            }
            func_8030E878(SFX_82_METAL_BREAK, randf2(0.93f, 1.07f), 0x7FF8, this->position, 100.0f, 900.0f);
            this->lifetime_value = 1.0f;
        }
    }
    arg3 += 4.5;
    return (arg3 >= 90.0f) ? 90.0f : arg3;
}

bool func_80388670(ActorMarker * this_marker, ActorMarker * other_marker){
    Actor *this = marker_getActor(this_marker);
    f32 player_position[3];

    player_getPosition(player_position);
    switch(this->marker->id){
        case MARKER_9F_CHURCH_GATE_LEFT_LOCK: //L803886D0
            return (-335.0f < player_position[0] &&  player_position[0] < -200.0f)
                && (-2730.0f < player_position[2] &&  player_position[2] < -2400.0f);

        case MARKER_A0_HEDGE_GATE_RIGHT_LOCK_1: //L80388770
            return (-2915.0f < player_position[0] &&  player_position[0] < -2584.0f)
                && ( -500.0f < player_position[2] &&  player_position[2] < -355.0f);

        case MARKER_FF_HEDGE_GATE_RIGHT_LOCK_2: //L80388810
            return (5470.0f < player_position[0] &&  player_position[0] < 5920.0f)
                && ( -850.0f < player_position[2] &&  player_position[2] < -780.0f);
        
        default:
            return FALSE;
    }
}

void chMMMGate_update(Actor *this){
    func_803300C0(this->marker, func_80388670);
    func_802D3CE8(this);
    this->lifetime_value = 0.0f;
    switch(this->state){
        case 4:
            switch(this->marker->id){
                case 0x9F:
                    this->roll = MMM_func_80388430(this, 0, -1, this->roll);
                    break;
                case 0xa0:
                case 0xff:
                    this->pitch = MMM_func_80388430(this, 2, 1, this->pitch);
                    break;
            }
            break;
        case 5:
            func_80326310(this);
            break;
    }
}

Actor *chMMMGate_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    
    static s32 i;
    Actor *this;
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];

    this = actor_drawFullDepth(marker, gfx, mtx, vtx);
    if (marker->unk14_21 && (this->lifetime_value != 0.0f)) {
        vec3fArray_get_vec3f(marker->unk44, 5, sp84);
        vec3fArray_get_vec3f(marker->unk44, 6, sp78);
        for(i = 0;  i < 8; i++){
            sp6C[0] = sp6C[2] = 0.0f;
            sp6C[1] = randf2(5.0f, 20.0f);
            sp90[0] = sp84[0] + (sp78[0] - sp84[0]) * randf();
            sp90[1] = sp84[1];
            sp90[2] = sp84[2] + (sp78[2] - sp84[2]) * randf();
            dustEmitter_emit(sp90, sp6C, D_8038BE20, 1, 0.3f, 50.0f, 0xB4, randi2(0x82, 0xC8), DUST_EMITTER_TYPE_DUST);
        }
    }
    return this;
}

void func_80388B2C(Actor *this, f32 arg1) {
    
    this->yaw += arg1;

    while ((arg1 > 0.0f) && (this->yaw >= 360.0f)) {
        this->yaw -= 360.0f;
    }

    while ((arg1 < 0.0f) && (this->yaw < 0.0f)) {
        this->yaw += 360.0f;
    }
}

void chChurchDoor_update(Actor *this) {
    f64 phi_f0;

    func_802D3D74(this);
    mapSpecificFlags_set(MMM_SPECIFIC_FLAG_TUMBLAR_BROKEN, BOOL((this->yaw > 260.0f) && (this->yaw < 330.0f)));
    if (!this->volatile_initialized) {
        if (this->yaw != 0.0f) {
            this->lifetime_value = 0.5f;
            subaddie_set_state(this, 7);
            this->unk38_31 = 1;
            this->yaw = 270.0f;
        } else {
            this->unk38_31 = 0;
            this->lifetime_value = 0.0f;
        }
        this->volatile_initialized = TRUE;
    }

    switch (this->state) {
    case 1:
        this->yaw = 0.0f;
        if(mapSpecificFlags_get(MMM_SPECIFIC_FLAG_0_UNKNOWN)) {
            gcStaticCamera_activate(0x21);
            subaddie_set_state(this, 6);
            core1_7090_initSfxSource(0, 0x6A, 0x7FF8, 0.3f);
            mapSpecificFlags_set(MMM_SPECIFIC_FLAG_2_UNKNOWN, FALSE);
            coMusicPlayer_playMusic(COMUSIC_4_MMM_CLOCK_VERSION, -1);
            func_8025AE0C(2000, 3.0f);
        }
        break;

    case 6:
        func_80388B2C(this, - (((this->yaw == 0.0f) || (359.0 < this->yaw)) ? 0.023 : 1.09));
        if ((this->yaw <= 270.0f) && (this->yaw > 260.0f)) {
            subaddie_set_state(this, 7U);
            this->yaw = 270.0f;
            gcsfx_play(0x7F);
            core1_7090_freeSfxSource(0);
            code_4C020_setHourglassTimer(0xE);
            item_set(6, 1);
        }
        break;
    case 7:
        if (this->unk38_31) {
            this->lifetime_value -= time_getDelta();
            if (this->lifetime_value < 0.0f) {
                this->lifetime_value = 0.0f;
            }
        }
        if( (!this->unk38_31 && item_empty(ITEM_0_HOURGLASS_TIMER))
            || ((this->unk38_31) && (this->lifetime_value == 0.0f))
        ) {
            if (!this->unk38_31) {
                gcStaticCamera_activate(0x22);
            } else {
                gcStaticCamera_activate(0x23);
            }
            subaddie_set_state(this, 8);
            core1_7090_initSfxSource(0, 0x6A, 0x7FF8, 0.3f);
        }
        break;
    case 8:
        func_80388B2C(this, 1.3f);
        if ((this->yaw >= 0.0f) && (this->yaw < 10.0f)) {
            subaddie_set_state(this, 1U);
            this->yaw = 0.0f;
            gcsfx_play(SFX_7F_HEAVYDOOR_SLAM);
            mapSpecificFlags_set(MMM_SPECIFIC_FLAG_0_UNKNOWN, FALSE);
            core1_7090_freeSfxSource(0);
            if (!this->unk38_31) {
                coMusicPlayer_playMusic(COMUSIC_3C_MINIGAME_LOSS, 0x7FF8);
                func_8025AE0C(0x7D0, 2.5f);
            }
            this->unk38_31 = 0;
            this->lifetime_value = 0.0f;
            progressDialog_setAndTriggerDialog_0(VOLATILE_FLAG_AD_MMM_CHURCH_DOOR_MISSED);
        }
        break;
    }
}

void chMMMClockSwitch_update(Actor *this) { 
    func_802D4A9C(this,0);
}

void chMMMWoodenDoor_update(Actor *this){
    func_802D3CE8(this);

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;

        if (levelSpecificFlags_get(LEVEL_FLAG_2E_MMM_UNKNOWN)) {
            marker_despawn(this->marker);
        }
    }
}

void chXBarrelTop_update(Actor *this){
    if(!this->initialized && sns_get_item_state(SNS_ITEM_EGG_CYAN, TRUE)){
        marker_despawn(this->marker);
    }
    else{
        func_802D3CE8(this);
    }
}

void chMMMWindow_update(Actor *this) {
    chMMMBreakableWooden_update(this);
    chTumblar_checkMMMChecksums();
}

void MMM_func_803890E0(void){
    spawnableActorList_add(&chShackDoor, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chMansionDoor, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chCellarHatch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chChuchGateLeftLock, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&chHedgeGateRightLock1, actor_new, ACTOR_FLAG_UNKNOWN_6);
    spawnableActorList_add(&chHedgeGateRightLock2, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chChuchDoor, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&ch1881BarrelTop, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chXBarrelTop, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chMMMWindow, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chMMMWideWindow, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chMMMTallWindow, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chDiningDoor, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_15);
    spawnableActorList_add(&chMMMClockSwitch, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chNapper,   actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_12);
    spawnableActorList_add(&chCemetaryPot, actor_new, ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chMotzhand, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_17);
    spawnableActorList_add(&D_80367E70, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chLoggo,    actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chPortraitChompa, actor_new, ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_23 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&chPortraitGrunty, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPortraitBlackeye, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPortraitTower, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPortraitTreeAndMoon, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPortraitTeeHee, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPortraitMinion, actor_new, ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_23);
    spawnableActorList_add(&chPurpleTeeHee, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17 | ACTOR_FLAG_UNKNOWN_19);
}
