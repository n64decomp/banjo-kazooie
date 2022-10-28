#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80309724(f32[3]);
extern void func_8028F45C(s32, f32[3]);

typedef struct {
    s32 unk0;
}ActorLocal_TreasureHunt;

void TTC_func_80389E90(Actor *this);
Actor *func_8038A0D0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

extern u32 D_8037DCB4;

/* .data */
f32 D_8038C820[6][3] = {
    {2904.0f, 2458.0f, -7351.0f},
    {-7007.0f, 2013.0f, 401.0f},
    {-3388.0f, 1519.0f, 5939.0f},
    {1399.0f, 1519.0f, 6126.0f},
    {5953.0f, 1819.0f, 56.0f}, 
    {7667.0f, 717.0f, 1676.0f}
};

f32 D_8038C868[6] = { 300.0f, 180.0f, 220.0f, 270.0f, 330.0f, 255.0f};
s32 D_8038C880[6] = {0x6E, 0xD2, 0x10E, 0x145, 0x14A, 0};
s32 D_8038C898[6] = {
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_53_RED_ARROW,
    ACTOR_54_RED_QUESTION_MARK,
    0x46
}; //enum actor_e

ActorInfo D_8038C8B0 = {
    MARKER_62_RED_ARROW, ACTOR_53_RED_ARROW, ASSET_3E9_MODEL_RED_ARROW, 
    0, NULL, 
    TTC_func_80389E90, func_80326224, func_8038A0D0,
    0, 0x400, 0.0f, 0
}; 

ActorInfo D_8038C8D4 = {
    MARKER_63_RED_QUESTION_MARK, ACTOR_54_RED_QUESTION_MARK, ASSET_3EB_MODEL_RED_QUESTION_MARK, 
    0, NULL, 
    TTC_func_80389E90, func_80326224, func_8038A0D0,
    0, 0x400, 0.0f, 0
}; 

ActorInfo D_8038C8F8 = {
    MARKER_64_RED_X, ACTOR_55_RED_X, ASSET_3EA_MODEL_RED_X, 
    0, NULL, 
    TTC_func_80389E90, func_80326224, func_8038A0D0,
    0, 0x400, 0.0f, 0
}; 

s32 D_8038C91C[3] = {160, 120, 20};
struct31s D_8038C928 = {
    {1.1f, 1.5f}, 
    {4.0f, 4.6f}, 
    {0.0f, 0.01f}, 
    {0.5f, 1.0f},
    0.0f, 0.01f
};

struct42s D_8038C950 = {
    {{-230.0f, 30.0f, -230.0f}, {230.0f, 110.0f, 230.0f}},
    {{-60.0f, 0.0f, -60.0f}, {60.0f, 30.0f, 60.0f}},
};

/* .code */
bool TTC_func_803899C0(void) {
    enum comusic_e phi_a0;
    s32 phi_a1;

    if (player_getActiveHitbox(0) == HITBOX_1_BEAK_BUSTER) {
        phi_a0 = COMUSIC_2B_DING_B;
        phi_a1 = 28000;
        if (D_8037DCB4 == 5) {
            phi_a0 = COMUSIC_2D_PUZZLE_SOLVED_FANFARE;
            phi_a1 = 0x7FFF;
        }
        func_8025A6EC(phi_a0, phi_a1);
        return TRUE;
    }
    return FALSE;
}

void func_80389A1C(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;

    actor = func_8032813C(0x55, D_8038C820[D_8037DCB4], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = D_8038C868[D_8037DCB4];
    local->unk0 = D_8037DCB4;
    actor->unk60 = 0.0f;
    actor->state = 0;
}

void func_80389A9C(void) {
    Actor *actor;
    ActorLocal_TreasureHunt *local;
    s32 actor_id;

    actor = func_8032813C((D_8038C898 - 1)[D_8037DCB4], D_8038C820[D_8037DCB4 - 1], 0);
    local = (ActorLocal_TreasureHunt *)&actor->local;
    actor->yaw = D_8038C880[D_8037DCB4 - 1];
    local->unk0 = D_8037DCB4;
    actor->unk60 = 0.0f;
    actor->state = 0;
}

void func_80389B38(s32 arg0){
    if(D_8037DCB4 == arg0 && TTC_func_803899C0()){
        if(arg0 == 0 && !jiggyscore_isCollected(JIGGY_11_TTC_RED_X)){
            func_80311480(0xA18, 4, NULL, NULL, NULL, NULL);
        }
        else if(arg0 == 4){
            func_80311480(0xA19, 4, NULL, NULL, NULL, NULL);
        }

        D_8037DCB4++;
        func_802C3BF8(func_80389A9C);
        func_802C3BF8(func_80389A1C);
    }
}

void TTC_func_80389BFC(ActorMarker *this, ActorMarker *arg1){\
    func_80389B38(0);
}

void func_80389C24(ActorMarker *this, ActorMarker *arg1){\
    func_80389B38(1);
}

void func_80389C4C(ActorMarker *this, ActorMarker *arg1){\
    func_80389B38(2);
}

void func_80389C74(ActorMarker *this, ActorMarker *arg1){\
    func_80389B38(3);
}

void func_80389C9C(ActorMarker *this, ActorMarker *arg1){\
    func_80389B38(4);
}

void func_80389CC4(s16 arg0[3], s32 arg1){
    static ParticleEmitter *D_8038D700;
    static f32 D_8038D708[3];

    if(D_8037DCB4 == 5 && TTC_func_803899C0()){
        D_8038D708[0] = (f32)arg0[0];
        D_8038D708[1] = (f32)arg0[1];
        D_8038D708[2] = (f32)arg0[2];
        D_8038D708[1] =  func_80309724(D_8038D708);
        func_802C3F04((GenMethod_4)func_802C4140, 0xF4, reinterpret_cast(s32, D_8038D708[0]), reinterpret_cast(s32, D_8038D708[1]), reinterpret_cast(s32, D_8038D708[2]));
        D_8038D700 = partEmitList_pushNew(3);
        func_802EFFA8(D_8038D700, D_8038C91C);
        particleEmitter_setSprite(D_8038D700, ASSET_700_SPRITE_DUST);
        particleEmitter_setStartingFrameRange(D_8038D700, 0, 7);
        particleEmitter_setPosition(D_8038D700, D_8038D708);
        particleEmitter_setPositionAndVelocityRanges(D_8038D700, &D_8038C950);
        func_802EFB98(D_8038D700, &D_8038C928);
        particleEmitter_emitN(D_8038D700, 5);
        D_8038D708[2] += 300.0f;
        gcpausemenu_80314AC8(0);
        timedFunc_set_2(0.1f, (TFQM2) func_8028F45C, 9, (s32)&D_8038D708);
        timedFunc_set_1(0.1f, (GenMethod_1) gcpausemenu_80314AC8, 1);
        func_80311480(ASSET_A17_TEXT_BURIED_TREASURE_SPAWNED, 4, NULL, NULL, NULL, NULL);
        D_8037DCB4++;
    }//L80389E70
}

void func_80389E84(void){
    D_8037DCB4 = 0;
}

void TTC_func_80389E90(Actor *this){
    f32 tick = time_getDelta();
    ActorLocal_TreasureHunt *local = (ActorLocal_TreasureHunt*)&this->local;
    f64 tmp_f12;

    if(!this->initialized){
        actor_collisionOff(this);
        this->marker->collidable = FALSE;
        this->initialized = TRUE;
    }

    switch(this->state){
        case 0://L80389F20
            this->unk60 = MIN(255.0, this->unk60 + tick*150.0);
            if(255.0 == this->unk60){
                this->state = 1;
            }
            break;
        case 1://L80389F94
            if(local->unk0 < D_8037DCB4){
                this->state = 2;
            }
            break;
        case 2://L80389FC4
            this->unk60 = MAX(0.0, this->unk60 - tick*((this->marker->modelId == ASSET_3EA_MODEL_RED_X)? 200.0 : 150.0));
            if(0.0 == this->unk60)
                marker_despawn(this->marker);
            break;
    }//L8038A094
    actor_setOpacity(this, (s32)this->unk60);
    this->unk124_9 = 2;
}

Actor *func_8038A0D0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    f32 sp38;
    Actor *actor;

    actor = func_80325300(marker, sp4C);
    switch(marker->modelId){
        case ASSET_3E9_MODEL_RED_ARROW://L8038A12C
            sp3C = 1.0f;
            sp38 = 8.0f;
            break;
        case ASSET_3EB_MODEL_RED_QUESTION_MARK: //L8038A14C
            sp3C = 1.0f;
            sp38 = 8.0f;
            break;
        case ASSET_3EA_MODEL_RED_X://L8038A164
            sp3C = (((ActorLocal_TreasureHunt *)&actor->local)->unk0 == 5)? 0.8f : 0.4f;
            sp38 = 4.0f;
            break;
    }//L8038A1A0
    sp40[0] = actor->position[0];
    sp40[1] = actor->position[1] + sp38;
    sp40[2] = actor->position[2];

    func_8032AA58(actor, sp3C);
    func_8033A2D4(func_803253A0, actor);
    func_803391A4(gfx, mtx, sp40, sp4C, sp3C, NULL, func_80330B1C(marker));
    return actor;
}
