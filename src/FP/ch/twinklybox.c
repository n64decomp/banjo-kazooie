#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CD8(f32);
extern Actor *func_8032813C(enum actor_e, f32[3], s32);

Actor *FP_func_8038CED0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038D6C8(Actor *this);

/* .data */
ActorAnimationInfo D_803920C0[] ={
    {0x000, 0.0f},
    {0x16D, 10000000.0f},
    {0x237, 2.0f},
    {0x16D, 0.8f},
    {0x16D, 0.8f}
};

ActorInfo D_803920E8 = { 0x204, 0x336, 0x442,
    0x1, D_803920C0,
    func_8038D6C8, func_80326224, FP_func_8038CED0,
    0, 0, 0.0f, 0
};

/* .code */
Actor *FP_func_8038CED0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if( func_8038BFA0() || fileProgressFlag_get(FILEPROG_13_COMPLETED_TWINKLIES_MINIGAME) ){
        if(0.0f == this->velocity[1])
            return this;
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8038CF54(f32 position[3], s32 count, enum asset_e model_id){
    static ParticleScaleAndLifetimeRanges D_8039210C = {
        { 0.4f,  0.8f },
        {-1.0f, -1.0f },
        { 0.0f,  0.02f},
        { 1.8f,  2.2f },
        0.0f,  
        0.7f
    };
    static struct43s D_80392134 = {
        {{-200.0f, 200.0f, -200.0f}, {200.0f, 400.0f, 200.0f}},
        {{   0.0f, -800.0f,    0.0f}, {  0.0f, -800.0f,   0.0f}},
        {{-100.0f,    0.0f, -100.0f}, {100.0f,  100.0f, 100.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80392134);
    particleEmitter_setAngularVelocityRange(pCtrl,
        100.0f, 100.0f, 100.0f,
        200.0f, 200.0f, 200.0f
    );
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8039210C);
    func_802EF9F8(pCtrl, 0.6f);
    func_802EFA18(pCtrl, 3);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038D01C(f32 position[3], s32 count, enum asset_e sprite_id){
    static ParticleScaleAndLifetimeRanges D_8039217C = {
        {0.8f, 1.2f },
        {1.4f, 2.0f },
        {0.0f, 0.01f},
        {1.2f, 1.8f },
        0.0f,
        0.01f
    };
    static s32 D_803921A4[3] = { 0xDC, 0xDC, 0xE6};
    static struct43s D_803921B0 = {
        {{-200.0f, 0.0f, -200.0f}, {200.0f, 200.0f, 200.0f}},
        {{  0.0f, -10.0f,   0.0f}, { 0.0f, -10.0f,  0.0f}},
        {{-50.0f,   0.0f, -50.0f}, {50.0f, 200.0f, 50.0f}}
    };

    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setRGB(pCtrl, D_803921A4);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_803921B0);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_8039217C);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038D0A8(f32 position[3], s32 count, enum asset_e model_id){
    static ParticleScaleAndLifetimeRanges D_803921F8 = {
        { 0.2f,  0.3f },
        {-1.0f, -1.0f },
        { 0.0f,  0.02f},
        { 2.0f,  2.5f },
        0.0f, 0.3f
    };

    static struct43s D_80392220 = {
        {{-300.0f, 400.0f, -300.0f}, {300.0f, 800.0f, 300.0f}},
        {{  0.0f, -800.0f,  0.0f}, { 0.0f, -800.0f,  0.0f}},
        {{-80.0f,  80.0f, -80.0f}, {80.0f,   80.0f, 80.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80392220);
    particleEmitter_setAngularVelocityRange(pCtrl,
        200.0f, 200.0f, 200.0f,
        300.0f, 300.0f, 300.0f
    );
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_803921F8);
    func_802EF9F8(pCtrl, 0.2f);
    func_802EFA18(pCtrl, 2);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038D170(f32 position[3], s32 count, enum asset_e sprite_id){
    static ParticleScaleAndLifetimeRanges D_80392268 ={
        { 0.4f,  0.6f },
        {-1.0f, -1.0f },
        { 0.0f,  0.02f},
        { 2.0f,  2.5f },
        0.0f,
        0.3f
    };
    static struct43s D_80392290 = {
        {{-300.0f, 400.0f, -300.0f}, {300.0f, 800.0f, 300.0f}},
        {{  0.0f, -800.0f,   0.0f}, { 0.0f, -800.0f,  0.0f}},
        {{-80.0f,   80.0f, -80.0f}, {80.0f,   80.0f, 80.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80392290);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_80392268);
    func_802EF9F8(pCtrl, 0.2f);
    func_802EFA18(pCtrl, 2);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038D208(f32 position[3], s32 count, enum asset_e sprite_id){
    static ParticleScaleAndLifetimeRanges D_803922D8 = {
        {0.5f, 0.7f },
        {1.4f, 1.7f },
        {0.0f, 0.01f},
        {0.6f, 0.9f },
        0.0f, 0.01f
    };
    static s32 D_80392300[3] = { 0xDC, 0xDC, 0xE6};
    static struct43s D_8039230C = {
        {{-100.0f, 0.0f, -100.0f}, {100.0f, 100.0f, 100.0f}},
        {{0.0f, -10.0f, 0.0f}, {0.0f, -10.0f, 0.0f}},
        {{-80.0f, 0.0f, -80.0f}, {50.0f, 200.0f, 80.0f}}
};
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setRGB(pCtrl, D_80392300);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8039230C);
    particleEmitter_setScaleAndLifetimeRanges(pCtrl, &D_803922D8);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038D294(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    func_8038CF54(this->position, 12, ASSET_4D4_MODEL_TWINKLY_BOX_PAPER_SHARD);
    func_8038D01C(this->position, 12, ASSET_700_SPRITE_DUST);
    this->velocity[1] = 0.0f;
    FUNC_8030E8B4(SFX_30_MAGIC_POOF, 1.0f, 32000, this->position, 1000, 3500);
    func_80311480(0xc13, 0, NULL, NULL, NULL, NULL);
}

void func_8038D324(Actor *this){
    int i;

    func_8038D0A8(this->position, 24, ASSET_4D4_MODEL_TWINKLY_BOX_PAPER_SHARD);
    for(i = 0; i < 24; i++){
        func_8038D170(this->position, 1, ASSET_710_SPRITE_SPARKLE_PURPLE + randi2(0, 10));
    }
    func_8038D208(this->position, 8, ASSET_700_SPRITE_DUST);
    FUNC_8030E624(SFX_30_MAGIC_POOF, 1.0f, 32000);
}

void func_8038D3B0(Actor *arg0){
    item_set(ITEM_6_HOURGLASS, FALSE);
}

void func_8038D3D8(void){
    comusic_8025AB44(COMUSIC_68_TWINKLY_MINIGAME, 0, 4000);
    func_8025AABC(COMUSIC_68_TWINKLY_MINIGAME);
    func_8025A58C(-1, 4000);
    func_8024BD08(1);
}

void func_8038D41C(ActorMarker *marker){
    static f32 D_80392354[3] = {-4165.0f, 73.0f, 4483.0f};
    static f32 D_80392360[3] = {-4292.0f, 73.0f, 5054.0f};
    s32 pad[2];
    ActorMarker *_marker = reinterpret_cast(ActorMarker *, marker);
    Actor *actor;
    
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392354, 170);
    actor->unk100 = _marker;
    actor = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392360, 170);
    actor->unk100 = _marker;
    if(pad[0]);
}

void func_8038D474(ActorMarker *marker){
    static enum actor_e D_8039236C[4] = {
        ACTOR_332_TWINKLY_BLUE,
        ACTOR_333_TWINKLY_GREEN,
        ACTOR_334_TWINKLY_ORANGE, 
        ACTOR_335_TWINKLY_RED,
        
    };
    Actor *actor  = marker_getActor(reinterpret_cast(ActorMarker*, marker));
    Actor *child;
    s32 pad;

    if((s32)actor->unk1C[0] >= 3){
        actor->unk1C[0] = -1.0f;
    }
    actor->unk1C[0] += 1.0;
    child = spawn_child_actor(D_8039236C[(s32)actor->unk1C[0]], &actor);
    child->unk100 = actor->marker;
}

void func_8038D51C(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    
    item_set(ITEM_6_HOURGLASS, FALSE);
    fileProgressFlag_set(FILEPROG_13_COMPLETED_TWINKLIES_MINIGAME, TRUE);
    FUNC_8030E624(SFX_416, 0.8f, 32000);
    func_8028F8F8(7, 0);
    this->unk1C[1] = 1.0f;
    timed_exitStaticCamera(1.7f);
    func_80324E38(1.7f, 0);
    timedFunc_set_1(2.3f, (GenFunction_1)func_8038D294, (s32)this->marker);
    this->velocity[1] = 1.0f;
}

void func_8038D5C8(ActorMarker *this_marker, ActorMarker *other_marker){
    static f32 D_8039237C[3] = {-3940.0f, 69.0f, 3570.0f};

    Actor *this = marker_getActor(this_marker);

    if(this->state == 1 || this->state == 2){
        actor_collisionOff(this);
        timed_setStaticCameraToNode(0.0f, 0xa);
        func_80324CD8(0.1f);
        func_8028F784(1);
        func_8028F490(D_8039237C);
        func_8028F8F8(7, 1);
        this->unk1C[1] = 0.0f;
        func_8025A6EC(COMUSIC_68_TWINKLY_MINIGAME, 25000);
        func_8025A58C(0, 4000);
        func_8024BD08(0);
        this->unk1C[2] = 428571.0f;
        func_8025AEA0(0x68, (s32)this->unk1C[2]);
        subaddie_set_state_with_direction(this, 3, 0.001f, 1);
        actor_playAnimationOnce(this);
        this->velocity[0] = 1.0f;
    }//L8038D6B8
}

void func_8038D6C8(Actor *this){
    f32 sp24;
    bool sp20;
    
    sp24 = time_getDelta();
    mapSpecificFlags_set(0xd, (this->state != 1 && this->state != 2) ? TRUE : FALSE);
    
    if(func_8038BFA0() || fileProgressFlag_get(FILEPROG_13_COMPLETED_TWINKLIES_MINIGAME)){
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOff(this);
        func_8028F8F8(7, FALSE);
        return;
    }


    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOn(this);

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        marker_setFreeMethod(this->marker, func_8038D3B0);
        marker_setCollisionScripts(this->marker, NULL, func_8038D5C8, NULL);
        this->unk38_31 = 0;
        this->unk1C[1] = 0.0f;
        this->velocity[0] = 0.0f;
        this->velocity[1] = 0.0f;
        this->unk1C[0] = -1.0f;
        func_8028F8F8(7, FALSE);
        if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE) && gcparade_8031B4F4() == -1){
            subaddie_set_state_with_direction(this, 3, 0.001f, 1);
            actor_playAnimationOnce(this);
            this->velocity[0] = 1.0f;
        }
    }//L8038D844

    if(volatileFlag_get(VOLATILE_FLAG_C1_IN_FINAL_CHARACTER_PARADE)){
        this->velocity[0] = 1.0f;
    }

    switch (this->state)
    {
    case 1: //L8038D89C
        if(!func_80329530(this, 800))
            break;

        if(!(globalTimer_getTime() & 1))
            subaddie_set_state_with_direction(this, 2, 0.001f, 1);
        else
            subaddie_set_state_with_direction(this, 2, 0.999f, 0);

        actor_playAnimationOnce(this);
        this->velocity[2] = randf2(1.4f, 2.0f);

        break;
    
    case 2: //L8038D91C
        sp20 = animctrl_isPlayedForwards(this->animctrl);
        animctrl_setDuration(this->animctrl, this->velocity[2]);
        if( ( sp20 == TRUE && actor_animationIsAt(this, 0.999f) )
            || ( sp20 == FALSE && actor_animationIsAt(this, 0.001f) )
        ){
            subaddie_set_state_with_direction(this, 1, 0.001f, 0);
            actor_playAnimationOnce(this);
            break;
        }

        if( actor_animationIsAt(this, 0.02f)
            || actor_animationIsAt(this, 0.15f)
            || actor_animationIsAt(this, 0.28f)
            || actor_animationIsAt(this, 0.63f)
            || actor_animationIsAt(this, 0.81f)
        ){
            FUNC_8030E8B4(SFX_98_DEAF_THUD, 1.0f, 32000, this->position, 400, 2000);
        }
        break;

    case 3: //L8038DA24
        if(actor_animationIsAt(this, 0.3f))
            func_8038D324(this);
        
        if(actor_animationIsAt(this, 0.999f))
            __spawnQueue_add_1((GenFunction_1)func_8038D474, (s32)this->marker);
        
        if(this->velocity[0] != 0.0f)
            break;

        timed_exitStaticCamera(0.0f);
        func_8028F784(0);
        subaddie_set_state_with_direction(this, 4, 0.999f, 1);
        actor_playAnimationOnce(this);
        item_set(ITEM_0_HOURGLASS_TIMER, 80*60 - 1);
        item_set(ITEM_6_HOURGLASS, TRUE);
        this->unk38_31 = 0xA;
        item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
        __spawnQueue_add_1((GenFunction_1)func_8038D41C, (s32)this->marker);
        this->unk60 = 0.0f;
        func_80347A14(0);
        func_802FAD64(ITEM_14_HEALTH);
        break;
    
    case 4: //L8038DB18
        this->unk1C[2] += (sp24*-195238.0f)/80.0f;
        if(this->unk1C[2] < 233333.0f)
            this->unk1C[2] = 233333.0f;

        func_8025AEA0(COMUSIC_68_TWINKLY_MINIGAME, (s32)this->unk1C[2]);
        if(item_getCount(ITEM_24_TWINKLY_SCORE) == 0){
            subaddie_set_state_with_direction(this, 1, 0.001f, 1);
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_8038D3D8();
            func_80324E38(0.0f, 3);
            timedFunc_set_1(1.3f, (GenFunction_1)func_8038D51C, (s32)this->marker);
            timed_setStaticCameraToNode(0.9f, 0xC);
            item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
            func_80347A14(1);
            break;
        }

        if(item_empty(ITEM_6_HOURGLASS)){
            subaddie_set_state_with_direction(this, 1, 0.001f, 0);
            actor_playAnimationOnce(this);
            this->unk38_31 = 0;
            item_set(ITEM_6_HOURGLASS, FALSE);
            func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
            func_8028F8F8(7, FALSE);
            this->unk1C[1] = 1.0f;
            func_8038D3D8();
            func_80347A14(1);
            break;
        }


        if(0.96 < animctrl_getAnimTimer(this->animctrl)){
            if(this->unk60 <= 0.0){
                __spawnQueue_add_1((GenFunction_1)func_8038D474, (s32)this->marker);
                this->unk60 = 2.9f;
            }
            else{
                this->unk60 -= sp24;
            }
            item_set(ITEM_24_TWINKLY_SCORE, this->unk38_31);
        }
        break;
    }
}

bool func_8038DD14(void){
    return mapSpecificFlags_get(0xD);
}

bool func_8038DD34(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    if(func_80329530(this, 800))
        return TRUE;
    return FALSE;
}
