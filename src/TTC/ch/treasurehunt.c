#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 mapModel_getFloorY(f32[3]);
extern void func_8028F45C(s32, f32[3]);

typedef struct {
    s32 unk0;
} ActorLocal_TreasureHunt;

static void __chTreasurehunt_updateFunc(Actor *this);
static Actor *__chTreasurehunt_animFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

extern u32 chtreasureHunt_puzzleCurrentStep;

/* .data */
static f32 sChTreasurehunt_stepPositions[6][3] = {
    {2904.0f, 2458.0f, -7351.0f},
    {-7007.0f, 2013.0f, 401.0f},
    {-3388.0f, 1519.0f, 5939.0f},
    {1399.0f, 1519.0f, 6126.0f},
    {5953.0f, 1819.0f, 56.0f}, 
    {7667.0f, 717.0f, 1676.0f}
};

static f32 sChTreasurehunt_StepRedXYaws[6] = { 300.0f, 180.0f, 220.0f, 270.0f, 330.0f, 255.0f };
static s32 sChTreasurehunt_StepYaws[6] = { 0x6E, 0xD2, 0x10E, 0x145, 0x14A, 0 };
static s32 sChTreasurehunt_StepActors[6] = {
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_54_RED_QUESTION_MARK,
    ACTOR_46_JIGGY
};

ActorInfo gChTreasurehuntRedArrow = {
    MARKER_62_RED_ARROW, ACTOR_53_RED_ARROW, ASSET_3E9_MODEL_RED_ARROW, 
    0, NULL, 
    __chTreasurehunt_updateFunc, actor_update_func_80326224, __chTreasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

ActorInfo gChTreasurehuntRedQuestionMark = {
    MARKER_63_RED_QUESTION_MARK, ACTOR_54_RED_QUESTION_MARK, ASSET_3EB_MODEL_RED_QUESTION_MARK, 
    0, NULL, 
    __chTreasurehunt_updateFunc, actor_update_func_80326224, __chTreasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

ActorInfo gChTreasurehuntRedX = {
    MARKER_64_RED_X, ACTOR_55_RED_X, ASSET_3EA_MODEL_RED_X, 
    0, NULL, 
    __chTreasurehunt_updateFunc, actor_update_func_80326224, __chTreasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

static s32 sChTreasurehuntParticleRGB[3] = {160, 120, 20};

ParticleScaleAndLifetimeRanges CH_TREASUREHUNT_PARTICLE_SCALE_AND_LIFETIME_RANGES = {
    {1.1f, 1.5f}, 
    {4.0f, 4.6f}, 
    {0.0f, 0.01f}, 
    {0.5f, 1.0f},
    0.0f, 0.01f
};

ParticleSettingsVelocityPosition CH_TREASUREHUNT_VELOCITY_RANGES = {
    {{-230.0f, 30.0f, -230.0f}, {230.0f, 110.0f, 230.0f}},
    {{-60.0f, 0.0f, -60.0f}, {60.0f, 30.0f, 60.0f}},
};

/* .code */
static bool __chTreasurehunt_isActiveHitboxBeakBusterHitbox(void) {
    enum comusic_e comusic_id;
    s32 music_volume;

    if (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) {
        comusic_id = COMUSIC_2B_DING_B;
        music_volume = 28000;
        if (chtreasureHunt_puzzleCurrentStep == 5) {
            comusic_id = COMUSIC_2D_PUZZLE_SOLVED_FANFARE;
            music_volume = 0x7FFF;
        }
        coMusicPlayer_playMusic(comusic_id, music_volume);
        return TRUE;
    }
    return FALSE;
}

static void __chTreasurehunt_spawnRedXForNextStep(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;

    actor = actor_spawnWithYaw_f32(ACTOR_55_RED_X, sChTreasurehunt_stepPositions[chtreasureHunt_puzzleCurrentStep], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = sChTreasurehunt_StepRedXYaws[chtreasureHunt_puzzleCurrentStep];
    local->unk0 = chtreasureHunt_puzzleCurrentStep;
    actor->lifetime_value = 0.0f;
    actor->state = 0;
}

static void __chTreasurehunt_spawnActorForNextStep(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;

    actor = actor_spawnWithYaw_f32((sChTreasurehunt_StepActors - 1)[chtreasureHunt_puzzleCurrentStep], sChTreasurehunt_stepPositions[chtreasureHunt_puzzleCurrentStep - 1], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = sChTreasurehunt_StepYaws[chtreasureHunt_puzzleCurrentStep - 1];
    local->unk0 = chtreasureHunt_puzzleCurrentStep;
    actor->lifetime_value = 0.0f;
    actor->state = 0;
}

static void __chTreasurehunt_checkStepProgress(s32 currentStep){
    if(chtreasureHunt_puzzleCurrentStep == currentStep && __chTreasurehunt_isActiveHitboxBeakBusterHitbox()){
        if(currentStep == 0 && !jiggyscore_isCollected(JIGGY_11_TTC_RED_X)){
            gcdialog_showDialog(ASSET_A18_DIALOG_TREASUREHUNT_FOLLOW_CLUES, 4, NULL, NULL, NULL, NULL);
        }
        else if(currentStep == 4){
            gcdialog_showDialog(ASSET_A19_DIALOG_TREASUREHUNT_SECOND_STEP, 4, NULL, NULL, NULL, NULL);
        }

        chtreasureHunt_puzzleCurrentStep++;
        __spawnQueue_add_0(__chTreasurehunt_spawnActorForNextStep);
        __spawnQueue_add_0(__chTreasurehunt_spawnRedXForNextStep);
    }
}

void chTreasurehunt_checkStepProgress0(NodeProp *this, ActorMarker *arg1){\
    __chTreasurehunt_checkStepProgress(0);
}

void chTreasurehunt_checkStepProgress1(NodeProp *this, ActorMarker *arg1){\
    __chTreasurehunt_checkStepProgress(1);
}

void chTreasurehunt_checkStepProgress2(NodeProp *this, ActorMarker *arg1){\
    __chTreasurehunt_checkStepProgress(2);
}

void chTreasurehunt_checkStepProgress3(NodeProp *this, ActorMarker *arg1){\
    __chTreasurehunt_checkStepProgress(3);
}

void chTreasurehunt_checkStepProgress4(NodeProp *this, ActorMarker *arg1){\
    __chTreasurehunt_checkStepProgress(4);
}

void chTreasurehunt_checkStepProgress5(NodeProp *this, ActorMarker *arg1){
    static ParticleEmitter *particleEmitter;
    static f32 particleTargetPosition[3];

    if(chtreasureHunt_puzzleCurrentStep == 5 && __chTreasurehunt_isActiveHitboxBeakBusterHitbox()){
        particleTargetPosition[0] = (f32)this->position_x;
        particleTargetPosition[1] = (f32)this->position_y;
        particleTargetPosition[2] = (f32)this->position_z;
        particleTargetPosition[1] =  mapModel_getFloorY(particleTargetPosition);
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0xF4, reinterpret_cast(s32, particleTargetPosition[0]), reinterpret_cast(s32, particleTargetPosition[1]), reinterpret_cast(s32, particleTargetPosition[2]));
        particleEmitter = partEmitMgr_newEmitter(3);
        particleEmitter_setRGB(particleEmitter, sChTreasurehuntParticleRGB);
        particleEmitter_setSprite(particleEmitter, ASSET_700_SPRITE_DUST);
        particleEmitter_setStartingFrameRange(particleEmitter, 0, 7);
        particleEmitter_setPosition(particleEmitter, particleTargetPosition);
        particleEmitter_setPositionAndVelocityRanges(particleEmitter, &CH_TREASUREHUNT_VELOCITY_RANGES);
        particleEmitter_setScaleAndLifetimeRanges(particleEmitter, &CH_TREASUREHUNT_PARTICLE_SCALE_AND_LIFETIME_RANGES);
        particleEmitter_emitN(particleEmitter, 5);
        particleTargetPosition[2] += 300.0f;
        gcpausemenu_80314AC8(0);
        timedFunc_set_2(0.1f, (GenFunction_2) func_8028F45C, 9, (s32)&particleTargetPosition);
        timedFunc_set_1(0.1f, (GenFunction_1) gcpausemenu_80314AC8, 1);
        gcdialog_showDialog(ASSET_A17_DIALOG_BURIED_TREASURE_SPAWNED, 4, NULL, NULL, NULL, NULL);
        chtreasureHunt_puzzleCurrentStep++;
    }
}

void chTreasurehunt_resetProgress(void){
    chtreasureHunt_puzzleCurrentStep = 0;
}

static void __chTreasurehunt_updateFunc(Actor *this){
    f32 tick = time_getDelta();
    ActorLocal_TreasureHunt *local = (ActorLocal_TreasureHunt*)&this->local;
    f64 tmp_f12;

    if(!this->initialized){
        actor_collisionOff(this);
        this->marker->collidable = FALSE;
        this->initialized = TRUE;
    }

    switch(this->state){
        case 0:
            this->lifetime_value = MIN(255.0, this->lifetime_value + tick*150.0);
            if(255.0 == this->lifetime_value){
                this->state = 1;
            }
            break;
        case 1:
            if(local->unk0 < chtreasureHunt_puzzleCurrentStep){
                this->state = 2;
            }
            break;
        case 2:
            this->lifetime_value = MAX(0.0, this->lifetime_value - tick*((this->marker->modelId == ASSET_3EA_MODEL_RED_X)? 200.0 : 150.0));
            if(0.0 == this->lifetime_value)
                marker_despawn(this->marker);
            break;
    }
    actor_setOpacity(this, (s32)this->lifetime_value);
    this->depth_mode = 2;
}

static Actor *__chTreasurehunt_animFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    Actor *actor;

    actor = marker_getActorAndRotation(marker, sp4C);
    switch(marker->modelId){
        case ASSET_3E9_MODEL_RED_ARROW:
            sp3C = 1.0f;
            sp38 = 8.0f;
            break;
        case ASSET_3EB_MODEL_RED_QUESTION_MARK:
            sp3C = 1.0f;
            sp38 = 8.0f;
            break;
        case ASSET_3EA_MODEL_RED_X:
            sp3C = (((ActorLocal_TreasureHunt *)&actor->local)->unk0 == 5) ? 0.8f : 0.4f;
            sp38 = 4.0f;
            break;
    }
    sp40[0] = actor->position[0];
    sp40[1] = actor->position[1] + sp38;
    sp40[2] = actor->position[2];

    suSetSpriteScale(actor, sp3C);
    modelRender_preDraw(actor_predrawMethod, actor);
    modelRender_draw(gfx, mtx, sp40, sp4C, sp3C, NULL, marker_loadModelBin(marker));
    return actor;
}
