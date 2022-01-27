#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define _HorzDist3v(v1, v2) ((v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[2]-v2[2])*(v1[2]-v2[2]))
extern void func_802D729C(Actor *, f32);
extern f32 func_80257204(f32, f32, f32, f32);

void chicecube_update(Actor *this);
Actor *chicecube_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorAnimationInfo D_80372B50[] = {
    {0x000, 0.0f},
    {ASSET_233_ANIM_ICECUBE, 999999.0f},
    {ASSET_233_ANIM_ICECUBE, 1.2f},
    {ASSET_233_ANIM_ICECUBE, 999999.0f},
    {ASSET_233_ANIM_ICECUBE, 999999.0f},
    {ASSET_233_ANIM_ICECUBE, 1.2f}
};

ActorInfo D_80372B80 = {
    0x250, 0x37D, ASSET_504_MODEL_ICECUBE, 
    1, D_80372B50, 
    chicecube_update, func_80326224, chicecube_draw,
    {0,0}, 0, 0.0f, {0,0,0,0}
}; 

ActorInfo D_80372BA4 = {
    0x25F, 0x3A0, ASSET_504_MODEL_ICECUBE, 
    1, D_80372B50, 
    chicecube_update, func_80326224, chicecube_draw,
    {0,0}, 0, 0.0f, {0,0,0,0}
}; 

s32 D_80372BC8[3] = {220, 220, 230};
s32 D_80372BD4[3] = {200, 200, 255};

/*.code */
Actor *chicecube_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor = marker_getActor(marker);
    func_8033A45C(3, actor->unk38_31);
    actor = func_80325888(marker, gfx, mtx, vtx);
    return actor;
}

int func_80359DF4(Actor *this, s32 arg1){
    if(func_80329530(this, arg1) && func_803292E0(this))
        return 1;
    return 0;
}

int func_80359E38(Actor *this, s32 arg1, s32 arg2){
    int sp1C = 0;
    if(arg1 < this->alpha_124_19 + arg2){
        this->alpha_124_19 = arg1;
        sp1C = 1;
    }
    else{
        this->alpha_124_19 += arg2;
    }
    actor_setOpacity(this, this->alpha_124_19);
    return sp1C;
}

int func_80359EBC(Actor *this, s32 arg1, s32 arg2){
    int sp1C = 0;
    if((this->alpha_124_19 - arg2) < arg1){
        this->alpha_124_19 = arg1;
        sp1C = 1;
    }
    else{
        this->alpha_124_19 -= arg2;
    }
    actor_setOpacity(this, this->alpha_124_19);
    return sp1C;
}

int func_80359F40(Actor *this, f32 arg1[3]){
    f32 sp24;
    f32 sp20;
    
    sp24 = func_80257204(this->position[0], this->position[2], arg1[0], arg1[2]);
    if((func_8023DB5C() & 0xF) == 4){
        this->velocity[2] = (f32)randi2(-45, 45);
    }
    sp20 = this->yaw;
    sp24 += this->velocity[2];
    this->yaw = sp24;
    if(func_80329030(this, 0)){
        this->yaw = sp20;
        return 1;
    }
    else{
        this->yaw = sp20;
        return 0;
    }
}

int func_80359FEC(f32 arg0[3], f32 arg1[3], s32 arg2){
    if(_HorzDist3v(arg0, arg1) < arg2*arg2)
        return 1;
    return 0;
}

void func_8035A04C(f32 position[3], s32 cnt, enum asset_e model_id, f32 scale){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);

    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -100.0f*scale, 0.0f, -100.0f*scale, 100.0f*scale, 200.0f*scale, 100.0f*scale);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -1000.0f, 0.0f, 0.0f, -1000.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -400.0f*scale, 450.0f*scale, -400.0f*scale, 400.0f*scale, 600.0f*scale, 400.0f*scale);
    func_802EFE24(pCtrl, 100.0f*scale, 100.0f*scale, 100.0f*scale, 250.0f*scale, 250.0f*scale, 250.0f*scale);
    func_802EFB70(pCtrl, scale*0.2, scale*0.4);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.02f);
    func_802EFEC0(pCtrl, 2.2f, 2.2f);
    func_802EFA5C(pCtrl, 0.0f, 0.3f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8035A228(f32 position[3], s32 cnt, enum asset_e sprite_id, f32 scale){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);

    func_802EFFA8(pCtrl, D_80372BC8);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, -50.0f*scale, 0.0f, -50.0f*scale, 50.0f*scale, 200.0f*scale, 50.0f*scale);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -10.0f, 0.0f, 0.0f, -10.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -280.0f*scale, 0.0f, -280.0f*scale, 280.0f*scale, 280.0f*scale, 280.0f*scale);
    func_802EFB70(pCtrl, scale*0.6, scale*0.8);
    func_802EFB84(pCtrl, scale*1.0, scale*1.4);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 1.2f, 1.8f);
    func_802EFA5C(pCtrl, 0.0f, 0.01f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8035A3F8(f32 position[3], s32 cnt, enum asset_e sprite_id, f32 scale){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);

    func_802EFFA8(pCtrl, D_80372BD4);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setParticleAccelerationRange(pCtrl, 0.0f, -10.0f, 0.0f, 0.0f, -10.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(pCtrl, -60.0f*scale, 0.0f, -60.0f*scale, 60.0f*scale, 60.0f*scale, 60.0f*scale);
    func_802EFB70(pCtrl, scale*0.4, scale*0.6);
    func_802EFB84(pCtrl, scale*0.8, scale*1.2);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 0.5f, 0.7f);
    func_802EFA5C(pCtrl, 0.0f, 0.3f);
    func_802EFA70(pCtrl, 4);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8035A594(f32 position[3], f32 arg1, f32 arg2){
    int i;
    int v0;
    for(i = 60; i != 380; i+=160){
        v0 = i;
        if(i > 360)
            v0 = i - 360;
        
        if(v0 < arg1 && arg2 < v0){
            func_8030E878(SFX_28_RUSTLING_NOISE, randf2(1.6f, 1.7f), 17000, position, 500.0f, 1000.0f);
        }
    }
}

void func_8035A694(Actor *this){
    f32 sp3C;
    f32 sp38;
    s32 tmp_v0;
    f32 sp28[3];

    sp3C = this->yaw;
    sp38 = this->unk28*1.5 + 1.0;
    tmp_v0 = func_8023DB5C();
    this->yaw += sp38;
    if(360.0f < this->yaw)
        this->yaw -= 360.0f;
    if(this->marker->unk14_21 && !(tmp_v0 & 1)){
        func_8034A174(this->marker->unk44, 5, sp28);
        func_8035A3F8(sp28, 1, ASSET_70D_SPRITE_SMOKE_1, this->scale);
    }
    func_8035A594(this->position, this->yaw, sp3C);

}

void __chicecube_spawnHalfCubes(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    Actor *other;
    f32 sp54[3];
    int i;
    f32 pad[1];
    
    sp54[0] = actor->position[0];
    sp54[1] = actor->position[1];
    sp54[2] = actor->position[2];
    sp54[1] += 100.0f;
    for(i = 0; i < 2; i++){//L8035A7FC
        func_802C8F70((i & 1)? actor->yaw : actor->yaw + 180.0f);
        other = func_802C937C(0x21, sp54);
        other->unkF4_8 = 1; //don't spawn more
        other->scale = randf2(0.5f, 0.6f)*actor->scale;
        actor->yaw = randi2(0, 359);
    }
    if(marker);
}

//__chicecube_ow
void __chicecube_ow(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 0x2AF, 0x398, actor->position, 1500, 3000);
    actor->velocity[1] = 0.8f;
    actor->unk28 = 0.0f;
}

//__chicecube_die
void __chicecube_die(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_B6_GLASS_BREAKING_1, 1000, 0x3ff, actor->position, 1500, 4500);
    actor->velocity[1] = 0.0f;
    func_8035A04C(actor->position, 12, ASSET_505_MODEL_ICECUBE_CHUNK, actor->scale);
    func_8035A228(actor->position, 6, ASSET_700_SPRITE_DUST, actor->scale);
    if(actor->unkF4_8 != 1){
        func_802C3C88(__chicecube_spawnHalfCubes, actor->marker);
    }
    marker_despawn(actor->marker);
}

void func_8035A998(Actor *this){
    func_80328B8C(this, 1, 0.0001f, 1);
    actor_playAnimationOnce(this);
    this->unk38_31 = 0;
}

void func_8035A9E0(Actor *this){
    func_80328B8C(this, 3, func_802877D8(this->animctrl), 1);
    actor_loopAnimation(this);
    this->unk38_31 = 1;
    this->unk28 = 0.0f;
}

void func_8035AA40(Actor *this){
    func_80328B8C(this, 5, 0.9999f, 0);
    actor_playAnimationOnce(this);
    this->unk38_31 = 1;
}

void chicecube_update(Actor *this){
    f32 sp3C = time_getDelta();
    f32 sp30[3];

    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0()){
            actor_collisionOff(this);
            this->unk58_0 = FALSE;
            return;
        }
        actor_collisionOn(this);
        this->unk58_0 = TRUE;
    }//L8035AAF4
    
    if(!actor_playerIsWithinDist(this, 3000))
        return;

    func_802D729C(this, 3.4 * this->scale);
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_803300A8(this->marker, __chicecube_ow, NULL, __chicecube_die);
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOff(this);
        this->alpha_124_19 = 0x50;
        actor_setOpacity(this, this->alpha_124_19);
        this->unk38_31 = 0;
        this->unk60 = 1.0f;
    }//L8035ABC0
    if(this->unk60 <= 0.0){
        if(-99999.0 != this->unk60){
            this->unk60 = -99999.0f;
            actor_collisionOn(this);
            this->unk1C[0] =this->position[0];
            this->unk1C[1] =this->position[1];
            this->unk1C[2] =this->position[2];
            this->velocity[0] = this->yaw;
        }
    }
    else{//L8035AC3C
        this->unk60 -= sp3C;
    }

    if(0.0 >= this->velocity[1]){
        this->velocity[1] = 0.0f;
    }
    else{
        this->velocity[1] -= sp3C;
        return; 
    }
    switch(this->state){
        case 1: // L8035AC9C
            func_8028764C(this->animctrl, 0.0f);
            if( func_80359DF4(this, 900)
                || (this->unkF4_8 == 2 && func_803203FC(0xC1))
            ){
                func_80328B8C(this, 2, 0.0001f, 1);
                actor_playAnimationOnce(this);
                this->unk38_31 = 0x1;
            }
            break; 
        case 2: // L8035AD10
            if(actor_animationIsAt(this, 0.1f)){
                FUNC_8030E8B4(SFX_112_TINKER_ATTENTION, 0x2CE, 0x531, this->position, 1500, 4500);
            }
            if( func_80359E38(this, 0xff, 0xa)
                && 0.98 < func_802877D8(this->animctrl)
            ){
                func_8035A9E0(this);
            }
            break;
        case 3: // L8035AD88
            func_8028764C(this->animctrl, 0.999f);
            if(this->unk28 + 0.28 < 18.0){
                this->unk28 = this->unk28 + 0.28;
            }
            else{
                this->unk28 = 18.0f;
            }
            func_8035A694(this);
            if(!func_80359DF4(this, 1300)){
                func_80328B8C(this, 4, func_802877D8(this->animctrl), 1);
                actor_loopAnimation(this);
                this->unk38_31 = 1;
            }
            else{
                player_getPosition(sp30);
                if(!func_80359F40(this, sp30)){
                    func_8035A998(this);
                }
            }
            break;
        case 4: // L8035AE64
            func_8028764C(this->animctrl, 0.999f);
            if(this->unk28 - 0.28 > 8.0)
                this->unk28 = this->unk28 - 0.28;
            else
                this->unk28 = 8.0f;
            func_8035A694(this);
            if(func_80359DF4(this, 900)){
                func_8035A9E0(this);
            }
            else if(func_80359FEC(this->position, this->unk1C, 0x14)){//L8035AEEC
                if(func_803294F0(this, 0xa, (s32)this->velocity[0])){
                    func_8035AA40(this);
                }
            }
            else{//L8035AF38
                if(!func_80359F40(this, this->unk1C)){
                    func_8035AA40(this);
                }
            }
            break;
        case 5: // L8035AF58
            if(actor_animationIsAt(this, 0.25f)){
                FUNC_8030E8B4(SFX_112_TINKER_ATTENTION, 0x2CE, 0x531, this->position, 1500, 4500);
            }
            if( func_802877D8(this->animctrl) < 0.1 
                && func_80359EBC(this, 0x50, 0xA)
            ){
                func_8035A998(this);
            }

            break;
    }
    
}
