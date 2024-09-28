#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 mapModel_getFloorY(f32[3]);
extern void func_8028F45C(s32, f32[3]);

typedef struct {
    s32 unk0;
}ActorLocal_TreasureHunt;

void TTC_Treasurehunt_updateFunc(Actor *this);
Actor *TTC_Treasurehunt_animFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

extern u32 TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP;

/* .data */
f32 TTC_TREASUREHUNT_STEP_POSITIONS[6][3] = {
    {2904.0f, 2458.0f, -7351.0f},
    {-7007.0f, 2013.0f, 401.0f},
    {-3388.0f, 1519.0f, 5939.0f},
    {1399.0f, 1519.0f, 6126.0f},
    {5953.0f, 1819.0f, 56.0f}, 
    {7667.0f, 717.0f, 1676.0f}
};

f32 TTC_TREASUREHUNT_STEP_RED_X_YAWS[6] = { 300.0f, 180.0f, 220.0f, 270.0f, 330.0f, 255.0f };
s32 TTC_TREASUREHUNT_STEP_YAWS[6] = { 0x6E, 0xD2, 0x10E, 0x145, 0x14A, 0 };
s32 TTC_TREASUREHUNT_STEP_ACTORS[6] = {
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_54_RED_QUESTION_MARK,
    ACTOR_46_JIGGY
};

ActorInfo TTC_TREASUREHUNT_ACTOR_RED_ARROW = {
    MARKER_62_RED_ARROW, ACTOR_53_RED_ARROW, ASSET_3E9_MODEL_RED_ARROW, 
    0, NULL, 
    TTC_Treasurehunt_updateFunc, func_80326224, TTC_Treasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

ActorInfo TTC_TREASUREHUNT_ACTOR_RED_QUESTION_MARK = {
    MARKER_63_RED_QUESTION_MARK, ACTOR_54_RED_QUESTION_MARK, ASSET_3EB_MODEL_RED_QUESTION_MARK, 
    0, NULL, 
    TTC_Treasurehunt_updateFunc, func_80326224, TTC_Treasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

ActorInfo TTC_TREASUREHUNT_ACTOR_RED_X = {
    MARKER_64_RED_X, ACTOR_55_RED_X, ASSET_3EA_MODEL_RED_X, 
    0, NULL, 
    TTC_Treasurehunt_updateFunc, func_80326224, TTC_Treasurehunt_animFunc,
    0, 0x400, 0.0f, 0
}; 

s32 TTC_TREASUREHUNT_PARTICLE_RGB[3] = {160, 120, 20};

ParticleScaleAndLifetimeRanges TTC_TREASUREHUNT_PARTICLE_SCALE_AND_LIFETIME_RANGES = {
    {1.1f, 1.5f}, 
    {4.0f, 4.6f}, 
    {0.0f, 0.01f}, 
    {0.5f, 1.0f},
    0.0f, 0.01f
};

struct42s TTC_TREASUREHUNT_VELOCITY_RANGES = {
    {{-230.0f, 30.0f, -230.0f}, {230.0f, 110.0f, 230.0f}},
    {{-60.0f, 0.0f, -60.0f}, {60.0f, 30.0f, 60.0f}},
};

/* .code */
bool TTC_Treasurehunt_isActiveHitboxBeakBusterHitbox(void) {
    enum comusic_e comusic_id;
    s32 music_volume;

    if (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) {
        comusic_id = COMUSIC_2B_DING_B;
        music_volume = 28000;
        if (TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP == 5) {
            comusic_id = COMUSIC_2D_PUZZLE_SOLVED_FANFARE;
            music_volume = 0x7FFF;
        }
        func_8025A6EC(comusic_id, music_volume);
        return TRUE;
    }
    return FALSE;
}

void TTC_Treasurehunt_spawnRedXForNextStep(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;

    actor = actor_spawnWithYaw_f32(ACTOR_55_RED_X, TTC_TREASUREHUNT_STEP_POSITIONS[TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = TTC_TREASUREHUNT_STEP_RED_X_YAWS[TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP];
    local->unk0 = TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP;
    actor->lifetime_value = 0.0f;
    actor->state = 0;
}

void TTC_Treasurehunt_spawnActorForNextStep(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;

    actor = actor_spawnWithYaw_f32((TTC_TREASUREHUNT_STEP_ACTORS - 1)[TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP], TTC_TREASUREHUNT_STEP_POSITIONS[TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP - 1], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = TTC_TREASUREHUNT_STEP_YAWS[TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP - 1];
    local->unk0 = TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP;
    actor->lifetime_value = 0.0f;
    actor->state = 0;
}

void TTC_Treasurehunt_checkStepProgress(s32 currentStep){
    if(TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP == currentStep && TTC_Treasurehunt_isActiveHitboxBeakBusterHitbox()){
        if(currentStep == 0 && !jiggyscore_isCollected(JIGGY_11_TTC_RED_X)){
            gcdialog_showText(ASSET_A18_TEXT_TREASUREHUNT_FOLLOW_CLUES, 4, NULL, NULL, NULL, NULL);
        }
        else if(currentStep == 4){
            gcdialog_showText(ASSET_A19_TEXT_TREASUREHUNT_SECOND_STEP, 4, NULL, NULL, NULL, NULL);
        }

        TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP++;
        __spawnQueue_add_0(TTC_Treasurehunt_spawnActorForNextStep);
        __spawnQueue_add_0(TTC_Treasurehunt_spawnRedXForNextStep);
    }
}

void TTC_Treasurehunt_checkStepProgress0(ActorMarker *this, ActorMarker *arg1){\
    TTC_Treasurehunt_checkStepProgress(0);
}

void TTC_Treasurehunt_checkStepProgress1(ActorMarker *this, ActorMarker *arg1){\
    TTC_Treasurehunt_checkStepProgress(1);
}

void TTC_Treasurehunt_checkStepProgress2(ActorMarker *this, ActorMarker *arg1){\
    TTC_Treasurehunt_checkStepProgress(2);
}

void TTC_Treasurehunt_checkStepProgress3(ActorMarker *this, ActorMarker *arg1){\
    TTC_Treasurehunt_checkStepProgress(3);
}

void TTC_Treasurehunt_checkStepProgress4(ActorMarker *this, ActorMarker *arg1){\
    TTC_Treasurehunt_checkStepProgress(4);
}

void TTC_Treasurehunt_checkStepProgress5(s16 arg0[3], s32 arg1){
    static ParticleEmitter *particleEmitter;
    static f32 particleTargetPosition[3];

    if(TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP == 5 && TTC_Treasurehunt_isActiveHitboxBeakBusterHitbox()){
        particleTargetPosition[0] = (f32)arg0[0];
        particleTargetPosition[1] = (f32)arg0[1];
        particleTargetPosition[2] = (f32)arg0[2];
        particleTargetPosition[1] =  mapModel_getFloorY(particleTargetPosition);
        __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0xF4, reinterpret_cast(s32, particleTargetPosition[0]), reinterpret_cast(s32, particleTargetPosition[1]), reinterpret_cast(s32, particleTargetPosition[2]));
        particleEmitter = partEmitMgr_newEmitter(3);
        particleEmitter_setRGB(particleEmitter, TTC_TREASUREHUNT_PARTICLE_RGB);
        particleEmitter_setSprite(particleEmitter, ASSET_700_SPRITE_DUST);
        particleEmitter_setStartingFrameRange(particleEmitter, 0, 7);
        particleEmitter_setPosition(particleEmitter, particleTargetPosition);
        particleEmitter_setPositionAndVelocityRanges(particleEmitter, &TTC_TREASUREHUNT_VELOCITY_RANGES);
        particleEmitter_setScaleAndLifetimeRanges(particleEmitter, &TTC_TREASUREHUNT_PARTICLE_SCALE_AND_LIFETIME_RANGES);
        particleEmitter_emitN(particleEmitter, 5);
        particleTargetPosition[2] += 300.0f;
        gcpausemenu_80314AC8(0);
        timedFunc_set_2(0.1f, (GenFunction_2) func_8028F45C, 9, (s32)&particleTargetPosition);
        timedFunc_set_1(0.1f, (GenFunction_1) gcpausemenu_80314AC8, 1);
        gcdialog_showText(ASSET_A17_TEXT_BURIED_TREASURE_SPAWNED, 4, NULL, NULL, NULL, NULL);
        TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP++;
    }
}

void TTC_Treasurehunt_resetProgress(void){
    TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP = 0;
}

void TTC_Treasurehunt_updateFunc(Actor *this){
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
            if(local->unk0 < TTC_TREASUREHUNT_PUZZLE_CURRENT_STEP){
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

Actor *TTC_Treasurehunt_animFunc(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
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

    func_8032AA58(actor, sp3C);
    modelRender_preDraw(actor_predrawMethod, actor);
    modelRender_draw(gfx, mtx, sp40, sp4C, sp3C, NULL, marker_loadModelBin(marker));
    return actor;
}
