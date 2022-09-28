#include <ultra64.h>
#include "functions.h"
#include "variables.h"



extern void func_802DABA0(ParticleEmitter *, f32[3], f32, enum asset_e);
extern void func_8033A45C(s32, s32);
extern void func_802DB548(void);

enum ccw_season_e
{
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER
};

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC_31:3;
    u32 unkC_28:1;
    u32 season:28;
    s16 unk10;
    s16 unk12;
    f32 unk14;
    u8 pad18[0x18];
    void (*unk30)(void);
    void (*unk34)(ActorMarker *, s32);
    u8 pad38[4];
    f32 unk3C;
} ActorLocal_CCW_8050;

void func_8038E964(Actor *this);
Actor *func_8038E56C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_8038F930[] = {
    {0x000, 0.0f},
    {0x243, 4.0f},
    {0x243, 0.7f},
    {0x245, 0.7f},
    {0x244, 0.9f},
    {0x246, 1.6f},
    {0x243, 1.5f},
    {0x245, 0.5f},
    {0x243, 1.5f},
    {0x243, 1e+06f},
    {0x243, 1e+06f}
};

ActorInfo D_8038F988 = {
    MARKER_1E2_GRUBLIN_HOOD, ACTOR_375_GRUBLIN_HOOD, ASSET_52C_MODEL_GRUBLIN_HOOD,
    0x1, D_8038F930,
    func_8038E964, func_80326224, func_8038E56C,
    2500, 0, 1.0f, 0
};

/* .code */
void func_8038E440(ParticleEmitter *pCtrl, Actor *actor, enum asset_e model_id){
    static struct43s D_8038F9AC = {
        {{-200.0f,   200.0f, -200.0f}, {200.0f,   400.0f, 200.0f}},
        {{   0.0f, -1800.0f,    0.0f}, {  0.0f, -1800.0f,   0.0f}},
        {{ -50.0f,   200.0f,  -50.0f}, { 50.0f,   400.0f,  50.0f}}
    };

    func_802DABA0(pCtrl, actor->position, actor->scale, model_id);
    func_802EFE24(pCtrl, 
        -600.0f, -600.0f, -600.0f, 
         600.0f,  600.0f,  600.0f
    );
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8038F9AC);
    particleEmitter_emitN(pCtrl, 1);
}

void func_8038E4C0(ActorMarker* marker, s32 arg1) {
    Actor* actor = marker_getActor(marker);
    ParticleEmitter *pCtrl;

    func_80328B8C(actor, 5, 0.0f, 1);
    actor_playAnimationOnce(actor);
    FUNC_8030E8B4(SFX_C2_GRUBLIN_EGH, 1.0f, 32000, actor->position, 1250, 2500);
    pCtrl = partEmitList_pushNew(1);
    func_8038E440(pCtrl, actor, ASSET_52D_MODEL_GRUBLIN_HOOD_HAT);
    func_802C3F04((GenMethod_4)func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32,actor->position_x), reinterpret_cast(s32,actor->position_y), reinterpret_cast(s32,actor->position_z));
    actor_collisionOff(actor);
    actor->unk138_24 = 1;
}

Actor *func_8038E56C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_CCW_8050 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_8050 *)&this->local;
    func_8033A45C(3,  (local->season == SUMMER) ? 1 : 2);
    func_8033A45C(4,  (local->season == SUMMER) ? 1 : 2);
    func_8033A45C(5,   (local->season < AUTUMN) ? 1 : 2);
    func_8033A45C(6,   (local->season < AUTUMN) ? 1 : 2);
    func_8033A45C(7,   (local->season < AUTUMN) ? 1 : 2);
    func_8033A45C(8,   (local->season < AUTUMN) ? 1 : 2);
    func_8033A45C(9,  (local->season == SUMMER) ? 1 : 0);
    func_8033A45C(10,  (local->season < AUTUMN) ? 0 : (local->season == AUTUMN) ? 1 : 2);
    func_8033A45C(11,  (local->season < AUTUMN) ? 0 : (local->season == AUTUMN) ? 1 : 2);
    func_8033A45C(12, (local->season == WINTER) ? 2 : 1);
    func_8033A45C(13, (local->season == WINTER) ? 1 : 0);
    func_8033A45C(14,      (this->unk138_24)? 0 : 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038E868(Actor *this){
    ActorLocal_CCW_8050 *local = (ActorLocal_CCW_8050 *)&this->local;


    local->unk8 = 6;
    local->unk9 = 0xC;
    local->unkA = 0x10;
    local->unkB = 8;
    local->unkC_31 = 1;
    local->unk10 = 0x29;
    local->unk12 = 25000;
    local->unkC_28 = 1;
    local->unk30 = func_802DB548;
    local->unk34 = func_8038E4C0;
    local->unk0 = 5.0f;
    local->unk4 = 8.0f;
    local->unk14 = 1.0f;
    local->unk3C = 1.5f;
}

enum ccw_season_e func_8038E8FC(Actor *this){
    switch(map_get()){
        case MAP_43_CCW_SPRING: //// 8038E930
        case MAP_4A_CCW_SPRING_MUMBOS_SKULL:// 8038E930
        case MAP_5B_CCW_SPRING_ZUBBA_HIVE:// 8038E930
        case MAP_5E_CCW_SPRING_NABNUTS_HOUSE:// 8038E930
        case MAP_65_CCW_SPRING_WHIPCRACK_ROOM:// 8038E930
            return SPRING;

        case MAP_44_CCW_SUMMER:// 8038E938
        case MAP_4B_CCW_SUMMER_MUMBOS_SKULL:// 8038E938
        case MAP_5A_CCW_SUMMER_ZUBBA_HIVE:// 8038E938
        case MAP_5F_CCW_SUMMER_NABNUTS_HOUSE:// 8038E938
        case MAP_66_CCW_SUMMER_WHIPCRACK_ROOM:// 8038E938
            return SUMMER;
        
        case MAP_45_CCW_AUTUMN:// 8038E940
        case MAP_4C_CCW_AUTUMN_MUMBOS_SKULL:// 8038E940
        case MAP_5C_CCW_AUTUMN_ZUBBA_HIVE:// 8038E940
        case MAP_60_CCW_AUTUMN_NABNUTS_HOUSE:// 8038E940
        case MAP_63_CCW_AUTUMN_NABNUTS_WATER_SUPPLY:// 8038E940
        case MAP_67_CCW_AUTUMN_WHIPCRACK_ROOM:// 8038E940
            return AUTUMN;
        
        case MAP_46_CCW_WINTER:// 8038E948
        case MAP_4D_CCW_WINTER_MUMBOS_SKULL:// 8038E948
        case MAP_61_CCW_WINTER_NABNUTS_HOUSE:// 8038E948
        case MAP_62_CCW_WINTER_HONEYCOMB_ROOM:// 8038E948
        case MAP_64_CCW_WINTER_NABNUTS_WATER_SUPPLY:// 8038E948
        case MAP_68_CCW_WINTER_WHIPCRACK_ROOM:// 8038E948
            return WINTER;
        
        default:
            return SPRING;
        
    }
}

void func_8038E964(Actor *this) {
    ActorLocal_CCW_8050 *local;
    f32 temp_a0;
    
    local = (ActorLocal_CCW_8050 *)&this->local;

    if (!this->unk16C_4) {
        func_8038E868(this);
        local->season = func_8038E8FC(this);
    }

    if(local->season < 4){
        func_802DB5A0(this);
        if (this->state == 5) {
            if (actor_animationIsAt(this, 0.18f)) {
                FUNC_8030E8B4(SFX_2_CLAW_SWIPE, 1.0f, 28000, this->position, 1250, 2500);
            }
            if (actor_animationIsAt(this, 0.7f)) {
                FUNC_8030E8B4(SFX_1F_HITTING_AN_ENEMY_3, 1.0f, 28000, this->position, 1250, 2500);
            }
        }
    }
}
