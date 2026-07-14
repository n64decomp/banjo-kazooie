#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    s16 unk4;
    f32 unk8;
    s16 unkC;
} Eyrie_Baby_SFX;

typedef struct {
    s16 map_id;
    s16 requiredFileProgress;
    s16 unlocksFileProgress;
    s16 waitingAnimation;
    Eyrie_Baby_SFX *waitingSFX;
    s16 nextStateWhenComplete; // Probably only used for Spring
    s16 yawningAnimation;
    Eyrie_Baby_SFX *yawnSFX;
    s16 goingToSleepAnimation;
    // u8 pad16[2];
    Eyrie_Baby_SFX *goingToSleepSFX;
    s16 sleepingAnimation;
    // u8 pad1E[0x2];
    Eyrie_Baby_SFX *sleepingSFX;
    u8 cameraNode;
    u8 caterpillarRequirement;
    s16 eatingAnimation;
    s16 meetDialog;
    // u8 pad2A[2];
} Eyrie_Baby_Dialog;

typedef struct {
    Eyrie_Baby_Dialog *progression;
    u8 eatenCount;
    //u8 pad5[3];
    Eyrie_Baby_SFX *sfx;
    s32 unkC[3]; // something about player position?
} ActorLocal_CCW_3310;

Actor *chEyrieBaby_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chEyrieBaby_update(Actor *this);

/* .data */
enum cheyriebaby_state_e {
    CH_EYRIE_BABY_STATE_0_NOT_HATCHED,
    CH_EYRIE_BABY_STATE_1_IDLE,
    CH_EYRIE_BABY_STATE_2_YAWNING,
    CH_EYRIE_BABY_STATE_3_GOING_TO_SLEEP,
    CH_EYRIE_BABY_STATE_4_SLEEPING,
    CH_EYRIE_BABY_STATE_5_EATING_CATERPILLARS
};

Eyrie_Baby_SFX chEyrieBabyWaitingSFX[] = {
    {0.11f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.22f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.34f, SFX_4A_CLUCKER_AHH, 1.1f, 25000},
    {0.55f, SFX_2_CLAW_SWIPE,   1.1f, 25000},
    {0.65f, SFX_2_CLAW_SWIPE,   1.0f, 26000},
    {0.77f, SFX_2_CLAW_SWIPE,   1.1f, 25000},
    {0.87f, SFX_2_CLAW_SWIPE,   1.0f, 24000},
    0
};

Eyrie_Baby_SFX chEyrieBabyYawnSFX[] = {
    {0.1f,  SFX_80_YUMYUM_CLACK,  0.9f, 15000},
    {0.25f, SFX_4C_LIP_SMACK,     1.0f, 15000},
    {0.31f, SFX_4C_LIP_SMACK,     0.9f, 15000},
    {0.38f, SFX_4C_LIP_SMACK,     1.0f, 15000},
    {0.48f, SFX_4C_LIP_SMACK,     0.9f, 15000},
    {0.55f, SFX_97_BLUBBER_BURPS, 0.9f, 32700},
    {0.6f , SFX_2C_PULLING_NOISE, 0.7f, 25000},
    {0.73f, SFX_2C_PULLING_NOISE, 0.8f, 27000},
    {0.85f, SFX_2C_PULLING_NOISE, 0.9f, 29000},
    0
};

Eyrie_Baby_SFX chEyrieBabyGoingToSleepSFX[] = {
    {0.2f , SFX_105_EYRIE_YAWN,        1.1f, 25000},
    {0.27f, SFX_105_EYRIE_YAWN,        1.0f, 25000},
    {0.35f, SFX_105_EYRIE_YAWN,        0.9f, 25000},
    {0.6f , SFX_106_EYRIE_LIPSMACK,    1.0f, 25000},
    {0.66f, SFX_106_EYRIE_LIPSMACK,    0.9f, 23000},
    {0.83f, SFX_1D_HITTING_AN_ENEMY_1, 0.7f, 27000},
    0
};

Eyrie_Baby_SFX chEyrieBabySleepingSFX[] = {
    {0.2f , SFX_5D_BANJO_RAAOWW, 1.0f, 25000},
    {0.72f, SFX_5E_BANJO_PHEWWW, 1.0f, 25000},
    0
};

Eyrie_Baby_SFX chEyrieBabyEatingSFX[] = {
    {0.95f, SFX_106_EYRIE_LIPSMACK, 1.0f, 25000},
    0
};

Eyrie_Baby_Dialog chEyrieBabyProgression[] = {
    {
        MAP_43_CCW_SPRING, // Map
        NULL, FILEPROG_E6_SPRING_EYRIE_HATCHED, // File Progress
        NULL, NULL, // Waiting
        CH_EYRIE_BABY_STATE_3_GOING_TO_SLEEP, // Unk
        NULL, NULL, // Yawning
        0x18F, chEyrieBabyGoingToSleepSFX, // Going To Sleep
        0x190, chEyrieBabySleepingSFX, // Sleeping
        0, // Camera Node
        0, // Caterpillar Requirement
        NULL, // Eating Animation
        NULL // Meet Dialog
    },
    {
        MAP_44_CCW_SUMMER, // Map
        FILEPROG_E6_SPRING_EYRIE_HATCHED, FILEPROG_E7_SUMMER_EYRIE_FED, // File Progress
        0x191, chEyrieBabyWaitingSFX, // Waiting
        CH_EYRIE_BABY_STATE_2_YAWNING, // Unk
        0x192, chEyrieBabyYawnSFX, // Yawning
        0x193, chEyrieBabyGoingToSleepSFX, // Going To Sleep
        0x194, chEyrieBabySleepingSFX, // Sleeping
        2, // Camera Node
        5, // Caterpillar Requirement
        0x21A, // Eating Animation
        VER_SELECT(ASSET_CD7_DIALOG_BABY_EYRIE_MEET_SUMMER, 0x09EC, 0, 0) // Meet Dialog
    },
    {
        MAP_45_CCW_AUTUMN, // Map
        FILEPROG_E7_SUMMER_EYRIE_FED, FILEPROG_E8_AUTMN_EYRIE_FED, // File Progress
        0x195, chEyrieBabyWaitingSFX, // Waiting
        CH_EYRIE_BABY_STATE_2_YAWNING, // Unk
        0x196, chEyrieBabyYawnSFX, // Yawning
        0x197, chEyrieBabyGoingToSleepSFX, // Going To Sleep
        0x198, chEyrieBabySleepingSFX, // Sleeping
        4, // Camera Node
        10, // Caterpillar Requirement
        0x21B, // Eating Animation
        VER_SELECT(ASSET_CDA_DIALOG_BABY_EYRIE_MEET_FALL, 0x09EF, 0, 0) // Meet Dialog
    },
    NULL
};

ActorInfo chEyrieBaby = {
    MARKER_1B4_EEYRIE_BABY, ACTOR_2A1_EEYRIE_BABY, ASSET_484_MODEL_EAGLE_BABY,
    0x0, NULL,
    chEyrieBaby_update, NULL, chEyrieBaby_draw,
    0, 0, 0.0f, 0
};

/* .bss */
f32 chEyrieBabyThrowPosition[3];

/* .code */
void func_80389700(ActorMarker *marker, enum asset_e text_id, s32 arg2) {
    timed_exitStaticCamera(0.5f);
    func_80324E38(0.5f, 0);
}

void func_80389740(ActorMarker *marker) {
    Actor *this = marker_getActor(marker);
    if (this->marker->unk14_21) {
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0x30C, reinterpret_cast(s32, chEyrieBabyThrowPosition[0]), reinterpret_cast(s32, chEyrieBabyThrowPosition[1]), reinterpret_cast(s32, chEyrieBabyThrowPosition[2]));
    }
}

void chEyrieBaby_saysMama() {
    func_8030E6D4(SFX_18C_EYRIE_MAMA);
}

void chEyrieBaby_setState(Actor *this, s32 next_state) {
    ActorLocal_CCW_3310 *local;

    local = (ActorLocal_CCW_3310 *)&this->local;
    local->sfx = NULL;
    if (next_state == CH_EYRIE_BABY_STATE_1_IDLE) {
        if (local->progression->waitingAnimation != NULL) {
            skeletalAnim_set(this->unk148, local->progression->waitingAnimation, 0.2f, 6.0f);
            skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        }
        local->sfx = local->progression->waitingSFX;
    }
    if ((this->state == CH_EYRIE_BABY_STATE_1_IDLE)
        && (next_state == CH_EYRIE_BABY_STATE_2_YAWNING)) {
        fileProgressFlag_set(local->progression->unlocksFileProgress, TRUE);
    }
    if (next_state == CH_EYRIE_BABY_STATE_5_EATING_CATERPILLARS) {
        func_8028F784(1);
        skeletalAnim_set(this->unk148, local->progression->eatingAnimation, 0.2f, 2.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        local->sfx = &chEyrieBabyEatingSFX[0];
    }

    if (next_state == CH_EYRIE_BABY_STATE_2_YAWNING) {
        skeletalAnim_set(this->unk148, local->progression->yawningAnimation, 0.2f, 8.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_80324E38(0.5f, 3);
        timed_setStaticCameraToNode(0.5f, local->progression->cameraNode);
        timed_exitStaticCamera(16.5f);
        func_80324E38(16.5f, 0);
        local->sfx = local->progression->yawnSFX;
    }
    if (next_state == CH_EYRIE_BABY_STATE_3_GOING_TO_SLEEP) {
        actor_collisionOff(this);
        skeletalAnim_set(this->unk148, local->progression->goingToSleepAnimation, 0.5f, 8.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        if (local->progression->map_id == MAP_43_CCW_SPRING) {
            gcdialog_showDialog(VER_SELECT(ASSET_CD6_DIALOG_BABY_EYRIE_HATCH, 0x09EB, 0, 0), 4, NULL, NULL, NULL, NULL);
            skeletalAnim_setCallback_0(this->unk148, 0.65f, &chEyrieBaby_saysMama);
        }
        if (local->progression->map_id == MAP_44_CCW_SUMMER) {
            gcdialog_showDialog(VER_SELECT(ASSET_CD9_DIALOG_BABY_EYRIE_COMPLETE_SUMMER, 0x09EE, 0, 0), 4, NULL, NULL, NULL, NULL);
        }
        if (local->progression->map_id == MAP_45_CCW_AUTUMN) {
            gcdialog_showDialog(VER_SELECT(ASSET_CDB_DIALOG_BABY_EYRIE_COMPLETE_FALL, 0x09F0, 0, 0), 4, NULL, NULL, NULL, NULL);
        }
        local->sfx = local->progression->goingToSleepSFX;
    }
    if (next_state == CH_EYRIE_BABY_STATE_4_SLEEPING) {
        func_8028F784(0);
        skeletalAnim_set(this->unk148, local->progression->sleepingAnimation, 0.2f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
        skeletalAnim_setCallback_1(this->unk148, 0.2f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.3f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.4f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.72f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.82f, (GenFunction_1)func_80389740, (s32)this->marker);
        skeletalAnim_setCallback_1(this->unk148, 0.92f, (GenFunction_1)func_80389740, (s32)this->marker);
        local->sfx = local->progression->sleepingSFX;
    }
    this->state = next_state;
}

Actor *chEyrieBaby_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_CCW_3310 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_3310 *)&this->local;
    if( (this->state == CH_EYRIE_BABY_STATE_0_NOT_HATCHED) 
        || ((this->state == CH_EYRIE_BABY_STATE_1_IDLE)
            && (local->progression->waitingAnimation == NULL))
    ) {
        return this;
    }
    modelRender_setAppendageVisibility(3, (this->state == CH_EYRIE_BABY_STATE_4_SLEEPING) ? 2 : 1);
    actor_draw(marker, gfx, mtx, vtx);
    vec3fArray_get_vec3f(func_80329934(), 5, chEyrieBabyThrowPosition);
    return this;
}

void func_80389BD8(f32 dst[3]){
    dst[0] = chEyrieBabyThrowPosition[0];
    dst[1] = chEyrieBabyThrowPosition[1];
    dst[2] = chEyrieBabyThrowPosition[2];
}

void chEyrieBaby_update(Actor *this) {
    Eyrie_Baby_SFX *iPtr;
    ActorLocal_CCW_3310 *local;
    f32 sp5C;
    f32 sp58;
    f32 player_position[3];

    local = (ActorLocal_CCW_3310 *)&this->local;

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->has_met_before = FALSE;
        this->position[0] = -4900.0f;
        this->position[1] = 4619.0f;
        this->position[2] = 0.0f;
        chEyrieBabyThrowPosition[0] = this->position[0];
        chEyrieBabyThrowPosition[1] = this->position[1];
        chEyrieBabyThrowPosition[2] = this->position[2];
        if (this->state == CH_EYRIE_BABY_STATE_0_NOT_HATCHED) {
            local->eatenCount = 0;
        }
        local->progression = &chEyrieBabyProgression[0];
        while(local->progression->map_id != NULL && gsworld_getMap() != local->progression->map_id){
            local->progression++;
        }

        if ((local->progression->requiredFileProgress != NULL)
            && !fileProgressFlag_get(local->progression->requiredFileProgress))
        {
            marker_despawn(this->marker);
        } else if (!fileProgressFlag_get(local->progression->unlocksFileProgress)) {
            chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_1_IDLE);
        } else {
            chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_4_SLEEPING);
        }

        if (jiggyscore_isSpawned(JIGGY_49_CCW_EYRIE) != FALSE) {
            marker_despawn(this->marker);
        }
        return;
    } 

    if (local->sfx) {
        skeletalAnim_getProgressRange(this->unk148, &sp5C, &sp58);
        for(iPtr = local->sfx; iPtr->unk0 > 0.0f; iPtr ++){
            if ((sp5C < iPtr->unk0) && (iPtr->unk0 <= sp58)) {
                func_8030E878((s32) iPtr->unk4, randf2(iPtr->unk8 - 0.05, iPtr->unk8 + 0.05), iPtr->unkC, this->position, 500.0f, 2500.0f);
            }
        }
    }
    if (this->state == CH_EYRIE_BABY_STATE_1_IDLE) {
        player_getPosition(player_position);
        if( !this->has_met_before
            && (local->unkC[2] >= 6500) 
            && (player_position[2] < 6500.0f) 
            && (local->progression->meetDialog != NULL)
        ){
            this->has_met_before = TRUE;
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(0.0f, local->progression->cameraNode);
            func_80324DBC(0.0f, local->progression->meetDialog, 6, NULL, this->marker, func_80389700, NULL);
        }
        local->unkC[0] = (s32) player_position[0];
        local->unkC[1] = (s32) player_position[1];
        local->unkC[2] = (s32) player_position[2];
        if (item_getCount(ITEM_22_CATERPILLAR) == 0) {
            func_8028F784(0);
        }
        if ((local->progression->map_id != MAP_43_CCW_SPRING)
            && ((this->position[0] + 500.0f) < player_position[0]))
        {
            player_setCarryObjectPoseInCylinder(this->position, 1110.0f, 200.0f, ACTOR_2A2_CATERPILLAR, &this);
            if ((local->progression->yawningAnimation != NULL)
                && (carriedObj_getActorId() == ACTOR_2A2_CATERPILLAR)
                && (ml_vec3f_distance(this->position, player_position) < 1010.0f)
                && (player_throwCarriedObject() != 0))
            {
                player_setThrowTargetPosition(chEyrieBabyThrowPosition);
                if ((local->progression->map_id == MAP_44_CCW_SUMMER)
                    && (local->eatenCount == 0))
                {
                    gcdialog_showDialog(VER_SELECT(ASSET_CD8_DIALOG_BABY_EYRIE_CHECK_SUMMER, 0x09ED, 0, 0), 4, NULL, NULL, NULL, NULL);
                }
                local->eatenCount++;
                if (local->eatenCount < local->progression->caterpillarRequirement) {
                    chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_5_EATING_CATERPILLARS);
                } else {
                    chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_2_YAWNING);
                }
            }
        }
        if (fileProgressFlag_get(local->progression->unlocksFileProgress)) {
            chEyrieBaby_setState(this, local->progression->nextStateWhenComplete);
        }
    }
    if ((this->state == CH_EYRIE_BABY_STATE_2_YAWNING)
        && (skeletalAnim_getLoopCount(this->unk148) > 0))
    {
        chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_3_GOING_TO_SLEEP);
    }
    if ((this->state == CH_EYRIE_BABY_STATE_3_GOING_TO_SLEEP)
        && (skeletalAnim_getLoopCount(this->unk148) > 0))
    {
        chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_4_SLEEPING);
    }
    if ((this->state == CH_EYRIE_BABY_STATE_5_EATING_CATERPILLARS)
        && (skeletalAnim_getLoopCount(this->unk148) > 0))
    {
        chEyrieBaby_setState(this, CH_EYRIE_BABY_STATE_1_IDLE);
    }
}
