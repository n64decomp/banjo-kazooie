#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80389484(ActorMarker *, f32);

typedef struct {
    f32 unk0;
}ActorLocal_PortraitChompa;

void func_80388028(Actor *this);
Actor *func_80387AA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_8038BAD0 = { 
    MARKER_254_PORTRAIT_CHOMPA_A, ACTOR_381_PORTRAIT_CHOMPA, ASSET_521_MODEL_PORTRAIT_CHOMPA, 
    0x0, NULL,
    func_80388028, NULL, func_80387AA0,
    0, 0, 0.0f, 0
};

/* .code */
Actor *func_80387AA0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor* actor = marker_getActor(marker);
    if ((actor->state == 0) || (actor->state == 1) || (actor->state == 6) || (actor->state == 2)) {
        return actor;
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_80387B14(Actor *this, s32 next_state){
    ActorLocal_PortraitChompa *local = (ActorLocal_PortraitChompa *) &this->local;
    f32 tmp = 2.5f;
    this->marker->unk14_20 = 0x1d1;

    if(next_state == 1 || next_state == 2){
        func_80335924(this->unk148, 0x23e, 0.0f, 2.5f);
        func_80335A74(this->unk148, 0.99f);
        func_80335A8C(this->unk148, 4);
        if(this->state == 4){
            local->unk0 = randf2(0.5f, 1.0f);
        }
        else{
            local->unk0 = 0.0f;
        }
    }//L80387BD0

    if(this->state == 1 && next_state == 2){
        FUNC_8030E624(SFX_3EF, 0.9f, 32675);
    }

    if(next_state == 3){
        local->unk0 = 0.2f;
    }

    if(next_state == 4){
        this->marker->unk14_20 = MARKER_254_PORTRAIT_CHOMPA_A;
        func_80335924(this->unk148, 0x23e, 0.0f, 2.5f);
        func_80335A8C(this->unk148, 2);
        if(this->unk100){
            func_80389484(this->unk100, tmp + 0.55);
        }
        FUNC_8030E624(SFX_3EF, 1.1f, 25000);
        FUNC_8030E624(SFX_3EF, 1.1f, 25000);
    }//L80387CAC

    if(next_state == 5){
        func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
        actor_collisionOff(this);
    }
    this->state = next_state;
}


void MMM_func_80387CF4(ActorMarker *this_marker, ActorMarker *other_marker) {
    func_8030E6D4(0x1E);
}

void func_80387D1C(ActorMarker* this_marker, ActorMarker *other_marker) {
    Actor *this = marker_getActor(this_marker);
    func_80387B14(this, 5);
}

void func_80387D48(ActorMarker *marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    enum asset_e portrait_id;
    Actor *portrait;

    switch(this->unkF4_8){
        case 0x32:
            portrait_id = ACTOR_382_PORTRAIT_OF_GRUNTY;
            break;
        case 0x33:
            portrait_id = ACTOR_384_PORTRAIT_OF_BLACKEYE;
            break;
        case 0x34:
            portrait_id = ACTOR_385_PORTRAIT_OF_TOWER;
            break;
        case 0x35:
            portrait_id = ACTOR_386_PORTRAIT_OF_TREE_AND_MOON;
            break;
        case 0x36:
            portrait_id = ACTOR_387_PORTRAIT_OF_TEEHEE;
            break;
        case 0x37:
            portrait_id = ACTOR_388_PORTRAIT_OF_MINION;
            break;
        default:
            portrait_id = ACTOR_382_PORTRAIT_OF_GRUNTY;
            break;
    }
    portrait = spawn_child_actor(portrait_id, &this);
    portrait->yaw = this->yaw;
    this->unk100 = portrait->marker;
    portrait->unk10_1 = FALSE;
}

void func_80387DF8(f32 position[3], s32 count, enum asset_e sprite_id) {
    static s32 D_8038BAF4[3] = {0xB4, 0xFF, 0x8C};
    static struct31s D_8038BB00 = {{0.2f, 0.4f}, {1.8f, 2.8f}, {0.0f, 0.15f}, {0.7f, 1.2f}, 0.0f, 0.01f};
    static struct43s D_8038BB28 = {
        {{-150.0f,  250.0f, -150.0f}, {150.0f,  300.0f, 150.0f}},
        {{   0.0f, -600.0f,    0.0f}, {  0.0f, -600.0f,   0.0f}},
        {{ -50.0f,  -50.0f,  -50.0f}, { 50.0f,   50.0f,  50.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    func_802EFFA8(pCtrl, &D_8038BAF4);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8038BB28);
    func_802EFB98(pCtrl, &D_8038BB00);
    particleEmitter_emitN(pCtrl, count);
}

void func_80387E84(f32 position[3], s32 count, enum asset_e model_id) {
    static struct31s D_8038BB70 = {{1.0f, 1.0f}, {1.0f, 1.0f}, {0.0f, 0.0f}, {3.2f, 3.2f}, 0.0f, 0.45f};
    static struct43s D_8038BB98 = {
        {{-90.0f,   300.0f, -90.0f}, {90.0f,   660.0f, 90.0f}},
        {{  0.0f, -1200.0f,   0.0f}, { 0.0f, -1200.0f,  0.0f}},
        {{-50.0f,     0.0f, -50.0f}, {50.0f,    50.0f, 50.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8038BB98);
    func_802EFE24(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EF9F8(pCtrl, 0.4f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    func_802EF9EC(pCtrl, 0x2F, 0x3E80);
    func_802EFA70(pCtrl, 2);
    func_802EFB98(pCtrl, &D_8038BB70);
    particleEmitter_emitN(pCtrl, count);
}

void func_80387F7C(Actor *this){
    f32 sp2C[3];
    f32 sp20[3];

    if(!this->marker->unk14_21) return;

    func_8034A174(this->marker->unk44, 5, sp2C);
    func_8034A174(this->marker->unk44, 6, sp20);
    func_80387E84(sp2C, 1, ASSET_523_MODEL_PORTRAIT_CHOMPA_TEETH);
    func_80387E84(sp2C, 1, ASSET_524_MODEL_PORTRAIT_CHOMPA_HEAD);
    func_80387E84(sp20, 6, ASSET_525_MODEL_PORTRAIT_CHOMPA_PART);
    func_80387DF8(sp2C, 2, ASSET_700_SPRITE_DUST);
    func_80387DF8(sp20, 2, ASSET_700_SPRITE_DUST);
}

void func_80388028(Actor *this){
    ActorLocal_PortraitChompa *local = (ActorLocal_PortraitChompa *) &this->local;
    f32 sp58 = time_getDelta();
    f32 plyr_position[3];
    f32 plyr_dist;
    f32 sp44;
    f32 sp40;

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->unk16C_0 = TRUE;
        marker_setCollisionScripts(this->marker, NULL, MMM_func_80387CF4, func_80387D1C);
        __spawnqueue_add_1(func_80387D48, this->marker);
        func_80387B14(this, (this->state < 5) ? 1 : 6);
    }//L803880B4

    player_getPosition(plyr_position);
    plyr_dist = ml_vec3f_distance(this->position, plyr_position);

    if(this->state == 4)
        actor_collisionOn(this);
    else
        actor_collisionOff(this);
    
    
    if(this->state == 1 && plyr_dist < this->scale*400.0f){
        func_80387B14(this, 2);
    }

    if(this->state == 2){
        if(0.0f < local->unk0){
            local->unk0 -= sp58;
        }
        else if(plyr_dist < this->scale*300.0f){
            func_80387B14(this, 3);
        }
        else if(this->scale*500.0f < plyr_dist){
            func_80387B14(this, 1);
        }
    }//L80388204

    if(this->state == 3){
        if(func_8025773C(&local->unk0, sp58)){
            func_80387B14(this, 4);
        }
    }

    if(this->state == 4){
        func_8033568C(this->unk148, &sp44, &sp40);
        if(sp44 < 0.56 && 0.56 <= sp40){
            this->marker->unk14_20 = 0x1d1;
        }

        if(sp44 < 0.5 && 0.5 <= sp40){
            FUNC_8030E624(SFX_2_CLAW_SWIPE, 0.9f, 32000);
        }

        if( (sp44 < 0.11 && 0.11 <= sp40)
            || (sp44 < 0.32 && 0.32 <= sp40)
            || (sp44 < 0.53 && 0.53 <= sp40)
        ){
            func_8030E6A4(SFX_6D_CROC_BITE, randf2(0.95f, 1.05f), 32000);
        }

        if(sp44 < 0.9 && 0.9 <= sp40){
            func_8030E6D4(SFX_2_CLAW_SWIPE);
        }
        if(func_80335794(this->unk148) > 0){
            func_80387B14(this, 2);
        }
    }

    if(this->state == 5){
        func_8030E6D4(SFX_D7_GRABBA_DEATH);
        func_80387F7C(this);
        func_80387B14(this, 6);
    }

}
