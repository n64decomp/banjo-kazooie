#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "actor.h"

extern void func_802DABA0(ParticleEmitter *, f32[3], f32, enum asset_e);
extern void modelRender_setAppendageVisibility(s32, s32);
extern void humanoidBaddie_ow(void);

void chgrublinhood_update(Actor *this);
Actor *chgrublinhood_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo chGrublinHood_animations[] = {
    {0x000, 0.0f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK,   4.0f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK,   0.7f},
    {ASSET_245_ANIM_GRUBLIN_HOOD_CHASE,       0.7f},
    {ASSET_244_ANIM_GRUBLIN_HOOD_ALERT,       0.9f},
    {ASSET_246_ANIM_GRUBLIN_HOOD_DIE,         1.6f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK,   1.5f},
    {ASSET_245_ANIM_GRUBLIN_HOOD_CHASE,       0.5f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK,   1.5f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK, 1e+06f},
    {ASSET_243_ANIM_GRUBLIN_HOOD_IDLE_WALK, 1e+06f}
};

ActorInfo chGrublinHood = {
    MARKER_1E2_GRUBLIN_HOOD, ACTOR_375_GRUBLIN_HOOD, ASSET_52C_MODEL_GRUBLIN_HOOD,
    0x1, chGrublinHood_animations,
    chgrublinhood_update, actor_update_func_80326224, chgrublinhood_draw,
    2500, 0, 1.0f, 0
};

/* .code */
void __chgrublinhood_emitHat(ParticleEmitter *pCtrl, Actor *actor, enum asset_e model_id){
    static ParticleSettingsVelocityAccelerationPosition D_8038F9AC = {
        {{-200.0f,   200.0f, -200.0f}, {200.0f,   400.0f, 200.0f}},
        {{   0.0f, -1800.0f,    0.0f}, {  0.0f, -1800.0f,   0.0f}},
        {{ -50.0f,   200.0f,  -50.0f}, { 50.0f,   400.0f,  50.0f}}
    };

    func_802DABA0(pCtrl, actor->position, actor->scale, model_id);
    particleEmitter_setAngularVelocityRange(pCtrl, 
        -600.0f, -600.0f, -600.0f, 
         600.0f,  600.0f,  600.0f
    );
    particleEmitter_setVelocityAccelerationAndPositionRanges(pCtrl, &D_8038F9AC);
    particleEmitter_emitN(pCtrl, 1);
}

void __chgrublinhood_die(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    ParticleEmitter *pCtrl;

    subaddie_set_state_with_direction(actor, 5, 0.0f, 1);
    actor_playAnimationOnce(actor);
    sfx_playFadeShorthandDefault(SFX_C2_GRUBLIN_EGH, 1.0f, 32000, actor->position, 1250, 2500);
    pCtrl = partEmitMgr_newEmitter(1);
    __chgrublinhood_emitHat(pCtrl, actor, ASSET_52D_MODEL_GRUBLIN_HOOD_HAT);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, reinterpret_cast(s32,actor->position_x), reinterpret_cast(s32,actor->position_y), reinterpret_cast(s32,actor->position_z));
    actor_collisionOff(actor);
    actor->has_met_before = TRUE;
}

Actor *chgrublinhood_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    Humanoid_Baddies_Actor *local;

    this = marker_getActor(marker);
    local = (Humanoid_Baddies_Actor *)&this->local;
    modelRender_setAppendageVisibility(3,  (local->baddieSpecific == CCW_SEASON_1_SUMMER) ? 1 : 2);
    modelRender_setAppendageVisibility(4,  (local->baddieSpecific == CCW_SEASON_1_SUMMER) ? 1 : 2);
    modelRender_setAppendageVisibility(5,  (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(6,  (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(7,  (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(8,  (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(9,  (local->baddieSpecific == CCW_SEASON_1_SUMMER) ? 1 : 0);
    modelRender_setAppendageVisibility(10, (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 0 : (local->baddieSpecific == CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(11, (local->baddieSpecific <  CCW_SEASON_2_AUTUMN) ? 0 : (local->baddieSpecific == CCW_SEASON_2_AUTUMN) ? 1 : 2);
    modelRender_setAppendageVisibility(12, (local->baddieSpecific == CCW_SEASON_3_WINTER) ? 2 : 1);
    modelRender_setAppendageVisibility(13, (local->baddieSpecific == CCW_SEASON_3_WINTER) ? 1 : 0);
    modelRender_setAppendageVisibility(14, (this->has_met_before)? FALSE : TRUE);
    return actor_draw(marker, gfx, mtx, vtx);
}

void __chgrublinhood_initialize(Actor *this){
    Humanoid_Baddies_Actor *local = (Humanoid_Baddies_Actor *)&this->local;

    local->unk8 = 6;
    local->unk9 = 0xC;
    local->unkA = 0x10;
    local->unkB = 8;
    local->yaw = 1;
    local->foundPlayerSfx = SFX_29_GRUBLIN_NYAHAHA;
    local->foundPlayerSampleRate = 25000;
    local->unkC_28 = TRUE;
    local->hitFunction = humanoidBaddie_ow;
    local->dieFunction = __chgrublinhood_die;
    local->unk0 = 5.0f;
    local->unk4 = 8.0f;
    local->foundPlayerVolume = 1.0f;
    local->damageVolume = 1.5f;
}

enum ccw_season_e __get_current_season(Actor *this){
    switch(gsworld_getMap()){
        case MAP_43_CCW_SPRING: //// 8038E930
        case MAP_4A_CCW_SPRING_MUMBOS_SKULL:// 8038E930
        case MAP_5B_CCW_SPRING_ZUBBA_HIVE:// 8038E930
        case MAP_5E_CCW_SPRING_NABNUTS_HOUSE:// 8038E930
        case MAP_65_CCW_SPRING_WHIPCRACK_ROOM:// 8038E930
            return CCW_SEASON_0_SPRING;

        case MAP_44_CCW_SUMMER:// 8038E938
        case MAP_4B_CCW_SUMMER_MUMBOS_SKULL:// 8038E938
        case MAP_5A_CCW_SUMMER_ZUBBA_HIVE:// 8038E938
        case MAP_5F_CCW_SUMMER_NABNUTS_HOUSE:// 8038E938
        case MAP_66_CCW_SUMMER_WHIPCRACK_ROOM:// 8038E938
            return CCW_SEASON_1_SUMMER;
        
        case MAP_45_CCW_AUTUMN:// 8038E940
        case MAP_4C_CCW_AUTUMN_MUMBOS_SKULL:// 8038E940
        case MAP_5C_CCW_AUTUMN_ZUBBA_HIVE:// 8038E940
        case MAP_60_CCW_AUTUMN_NABNUTS_HOUSE:// 8038E940
        case MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY:// 8038E940
        case MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM:// 8038E940
            return CCW_SEASON_2_AUTUMN;
        
        case MAP_46_CCW_WINTER:// 8038E948
        case MAP_4D_CCW_WINTER_MUMBOS_SKULL:// 8038E948
        case MAP_61_CCW_WINTER_NABNUTS_HOUSE:// 8038E948
        case MAP_62_CCW_WINTER_HONEYCOMB_ROOM:// 8038E948
        case MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY:// 8038E948
        case MAP_68_CCW_WINTER_WHIPCRACK_ROOM:// 8038E948
            return CCW_SEASON_3_WINTER;
        
        default:
            return CCW_SEASON_0_SPRING;
    }
}

void chgrublinhood_update(Actor *this) {
    Humanoid_Baddies_Actor *local;
    f32 temp_a0;
    
    local = (Humanoid_Baddies_Actor *)&this->local;

    if (!this->volatile_initialized) {
        __chgrublinhood_initialize(this);
        local->baddieSpecific = __get_current_season(this);
    }

    // This should always be true?
    if(local->baddieSpecific < 4){
        humanoidBaddie_update(this);
        if (this->state == CHHUMANOIDBADDIE_STATE_5_DIE) {
            if (actor_animationIsAt(this, 0.18f)) {
                sfx_playFadeShorthandDefault(SFX_2_CLAW_SWIPE, 1.0f, 28000, this->position, 1250, 2500);
            }
            if (actor_animationIsAt(this, 0.7f)) {
                sfx_playFadeShorthandDefault(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 28000, this->position, 1250, 2500);
            }
        }
    }
}
