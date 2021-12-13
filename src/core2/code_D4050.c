#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
    f32 unk4;
} ActorLocal_Core2_D4050;

void func_8035B900(Actor *this);
void func_8035BD48(Actor *this);

/* .data */
ActorAnimationInfo D_80372BE0[] ={
    {0x00, 0.0f},
    {ASSET_9E_ANIM_TEEHEE_IDLE, 2.0f},
    {ASSET_9F_ANIM_TEEHEE_ALERTED, 1.5f},
    {ASSET_AC_ANIM_TEEHEE_CHASE, 1.0f},
    {ASSET_9E_ANIM_TEEHEE_IDLE, 2.0f},
    {ASSET_9E_ANIM_TEEHEE_IDLE, 2.0f},
    {ASSET_2AB_ANIM_TEEHEE_DIE, 1.0f}
};

ActorInfo D_80372C18 = { //TEEHEE
    0x99, ACTOR_CA_TEEHEE, ASSET_3CB_MODEL_TEEHEE, 
    0x1, D_80372BE0, 
    func_8035B900, func_80326224, func_80325888, 
    { 0x19, 0x64, 0x0, 0x0}, 0.9f, { 0x0, 0x0, 0x0, 0x0}
};

ActorInfo D_80372C3C = { //PURPLE_TEEHEE (inside tumblar)
    0x296, ACTOR_3C1_PURPLE_TEEHEE, ASSET_564_MODEL_PURPLE_TEEHEE, 
    0x1, D_80372BE0, 
    func_8035B900, func_8035BD48, func_80325888, 
    { 0x19, 0x64, 0x0, 0x0}, 0.9f, { 0x0, 0x0, 0x0, 0x0}
};

s32 D_80372C60[3] = {0x46, 0xFE, 0x46};

s32 D_80372C6C[3] = {0xFE, 0x46, 0xFE};

/* .code */
void func_8035AFE0(f32 scale, f32 pos[3], s32 cnt, enum asset_e sprite_id, s32 arg4[3]){
    ParticleEmitter *pCtrl = func_802F0BD0(cnt);

    particleEmitter_setSprite(pCtrl, sprite_id);
    func_802EFFA8(pCtrl, arg4);
    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -100.0f*scale, 20.0f*scale, -100.0f*scale,
        100.0f*scale, 200.0f*scale, 100.0f*scale
    );
    particleEmitter_setParticleAccelerationRange(pCtrl,
        0.0f, -10.0f*scale, 0.0f,
        0.0f, -10.0f*scale, 0.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -100.0f*scale, -20.0f*scale, -100.0f*scale,
        100.0f*scale, 100.0f*scale, 100.0f*scale
    );
    func_802EFB70(pCtrl, scale*0.4, scale*0.6);
    func_802EFB84(pCtrl, scale*1.0, scale*1.4);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 1.0f, 1.4f);
    func_802EFA5C(pCtrl, 0.0f, 0.01f);
    func_802EFA70(pCtrl, 0x10);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8035B1CC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    f32 sp30;

    sp30 = this->scale;
    func_8030E878(SFX_121_AWAWAU, 1.3f, 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
    func_8030E878(SFX_30_MAGIC_POOF, 1.0f, 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
    func_80328B8C(this, 6, 0.01f, 1);
    actor_playAnimationOnce(this);
    actor_collisionOff(this);
    func_80326310(this);
    func_8035AFE0(sp30, this->position, 8, ASSET_700_SPRITE_DUST, D_80372C60);
}

void func_8035B2C4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    f32 sp30 = this->scale;
    func_8030E878(SFX_121_AWAWAU, 1.3f, 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
    func_8030E878(SFX_30_MAGIC_POOF, 1.0f, 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
    func_80328B8C(this, 6, 0.01f, 1);
    actor_playAnimationOnce(this);
    actor_collisionOff(this);
    func_8035AFE0(sp30, this->position, 8, ASSET_700_SPRITE_DUST, D_80372C6C);
}

void func_8035B3B4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    this->unk60 = 1.0f;
}

int func_8035B3E4(Actor *this){
    if(func_80329530(this, (s32)(this->scale*600.0f)) && func_803292E0(this))
        return 1;
    return 0;
}

int func_8035B444(Actor *this, f32 arg1){
    int out;
    func_80328FB0(this, arg1);

    if(!func_80329054(this, 2) && func_80329480(this))
        return 0;
    return 1;
}

void func_8035B49C(Actor *this){
    f32 tmp_f2;
    if(this->velocity_x < this->unk1C_x){
        this->velocity_x = (f64)this->velocity_x + this->scale;
    }
    else if(this->unk1C_x < this->velocity_x){
        this->velocity_x = (f64)this->velocity_x - this->scale; 
    }
    this->velocity_z += (this->velocity_y += (0.0f <= this->velocity_z)? -(0.1*this->scale) : 0.1*this->scale);
    this->position_y = this->velocity_z + this->velocity_x;
}

void func_8035B56C(Actor *this){
    f32 sp2C;
    f32 plyr_pos[3];
    
    sp2C = 2*(f64)this->scale;
    player_getPosition(plyr_pos);

    if(this->position_y < plyr_pos[1]){
        if(this->position_y + sp2C < plyr_pos[1]){
            this->position_y = this->position_y + sp2C;
            this->velocity_x += sp2C;
        }
        else{
            this->velocity_x += plyr_pos[1] - this->position_y;
            this->position_y = plyr_pos[1];
        }
    }
    else if(plyr_pos[1] < this->position_y){
        if(plyr_pos[1] < this->position_y - sp2C){
            this->position_y = this->position_y - sp2C;
            this->velocity_x -= sp2C;
        }
        else{
             this->velocity_x -= (this->position_y - plyr_pos[1]);
             this->position_y = plyr_pos[1];
        }
        
    }

}

void func_8035B674(Actor *this){
    ActorLocal_Core2_D4050 *local = (ActorLocal_Core2_D4050 *)&this->local;
    
    func_80328B8C(this, 1, 0.01f, 1);
    actor_loopAnimation(this);
    local->unk0 = randf2(1.0f, 4.5f);
    
}

void func_8035B6CC(Actor *this){
    func_80328B8C(this, 2, 0.01f, 1);
    actor_playAnimationOnce(this);
    this->unk28 = 1.0f;
    func_8030E878(0x3F4, randf2(1.0f, 1.2f), 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
}

void func_8035B75C(Actor *this){
    func_80328B8C(this, 3, 0.01f, 1);
    actor_loopAnimation(this);
    this->unk28 = func_803203FC(0xC1) ? 0.0 : 12.0;
    func_8030E878(0x3F4, randf2(1.0f, 1.2f), 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
}

void func_8035B824(Actor *this){
    ActorLocal_Core2_D4050 *local = (ActorLocal_Core2_D4050 *)&this->local;

    func_80328B8C(this, 4, 0.01f, 1);
    actor_loopAnimation(this);
    func_80328CEC(this, (s32)this->yaw_moving, 0xA, 0x1E);
    this->unk28 = 4.0f;
    local->unk4 = randf2(2.0f, 4.5f);
    

}

void func_8035B8A8(Actor *this){
    func_80328B8C(this, 5, 0.01f, 1);
    actor_loopAnimation(this);
    func_80328CEC(this, (s32)this->yaw_moving, 0xE1, 0x87);
}  

void func_8035B900(Actor *this){
    ActorLocal_Core2_D4050 *local = (ActorLocal_Core2_D4050 *)&this->local;
    s32 sp30 = func_8023DB5C();
    f32 sp2C = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        func_803300A8(this->marker, NULL, func_8035B3B4, func_8035B1CC);
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        this->velocity_z = 0.0f;
        this->unk60 = 0.0f;
        this->unk1C[0] = this->position_y + this->scale*100.0f;
        this->velocity_y = this->scale*2.0;
        this->velocity_x = this->unk1C[0];
        local->unk0 = randf2(1.0f, 4.5f);
        animctrl_setTransitionDuration(this->animctrl, 0.8f);
    }//L8035B9D4
    
    if(0.0 < this->unk60 - sp2C){
        this->unk60 -= sp2C;
    }
    else{//L8035BA08
        switch(this->state){
            case 1: //L8035BA30
                func_8035B49C(this);
                if(func_8035B3E4(this)){
                    func_8035B6CC(this);
                }
                else if(0.0 < local->unk0 - sp2C){
                    local->unk0 = local->unk0 - sp2C;
                }
                else{
                    func_8035B824(this);
                }
                break;
            case 2: //L8035BA98
                this->yaw_moving = func_80329784(this);
                func_8035B444(this, 4.0f);
                if(actor_animationIsAt(this, 0.99f)){
                    func_8035B75C(this);
                }
                break;
            case 3: //L8035BAE0
                func_8035B56C(this);
                if((sp30 & 0x3F) == 7 && randf() < 0.7){
                    func_8030E878(0x3F4, randf2(1.0f, 1.2f), 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
                }//L8035BB6C
                this->yaw_moving = func_80329784(this);
                if(!func_8035B3E4(this) || !func_8035B444(this, 5.0f)){
                    func_8035B674(this);
                }
                break;
            case 4: //L8035BBB0
                func_8035B49C(this);
                if(!func_8035B444(this, 2.0f)){
                    func_8035B8A8(this);
                }
                else if(local->unk4 - sp2C <= 0.0){
                    func_8035B674(this);
                }
                else{
                    local->unk4 = local->unk4 - sp2C;
                }
                break;
            case 5: //L8035BC1C
                func_8035B49C(this);
                func_80328FB0(this, 3.0f);
                if(func_80329480(this)){
                    func_8035B674(this);
                }
                break;
            case 6: //L8035BC48
                break;
        }
    }//L8035BC48
}

int func_8035BC5C(Actor *this, s32 target, s32 delta){
    s32 done = FALSE;
    s32 alpha;
    if(delta < 0){
        if((s32)(this->alpha_124_19 + delta) < target){
            this->alpha_124_19 = target;
            done = TRUE;
        } 

    }
    else{//L8035BCB8
        if(target < this->alpha_124_19 + delta){
            this->alpha_124_19 = target;
            done = TRUE;
        } 
    }
    if(!done){
        this->alpha_124_19 += delta;
    }
    alpha = this->alpha_124_19;
    actor_setOpacity(this, alpha);
    return done;
}

void func_8035BD48(Actor *this){
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        actor_collisionOn(this);
        func_803300A8(this->marker, NULL, func_8035B3B4, func_8035B2C4);
        mapSpecificFlags_set(3, FALSE);
        mapSpecificFlags_set(4, FALSE);
        if(func_803348C0() == MAP_24_MMM_TUMBLARS_SHED){
            if( jiggyscore_80320F7C(JIGGY_62_MMM_TUMBLAR)
                || jiggyscore_isCollected(JIGGY_62_MMM_TUMBLAR)
            ){
                marker_despawn(this->marker);
            }
            else{//L8035BE04
                func_80328B8C(this, 1, 0.01f, 1);
                actor_setOpacity(this, 0);
            }
        }
        else{//L8035BE2C
            func_80328B8C(this, 3, 0.01f, 1);
            actor_setOpacity(this, 0xff);
        }
    }//L8035BE50

    switch(this->state){
        case 1: //L8035BE78
            actor_collisionOff(this);
            if(mapSpecificFlags_getClear(4)){
                marker_despawn(this->marker);
            }
            else if(mapSpecificFlags_getClear(3)){
                func_80328B8C(this, 3, 0.01f, 1);
            }
            break;
        case 3: //L8035BECC
            this->unk58_0 = TRUE;
            actor_collisionOn(this);
            if(mapSpecificFlags_getClear(4)){
                this->unk38_0 = TRUE;
                func_8035B2C4(this->marker, NULL);
            }
            else{//L8035BF14
                if(this->alpha_124_19 == 0xFF || func_8035BC5C(this, 0xff, 0xA)){
                    func_80343DEC(this);
                }

                if((func_8023DB5C() &0x3F) == 7 && randf() < 0.7){
                    func_8030E878(0x3f4, randf2(1.0f, 1.2f), 32000, this->position, this->scale*400.0f, this->scale*1800.0f);
                }
            }
            break;
        case 6: //L8035BFD4
            if(func_8035BC5C(this, 0, -7)){
                this->unk58_0 = FALSE;
                this->unk48 = 0.0f;
                func_80343DEC(this);
                if(this->unk38_0){
                    marker_despawn(this->marker);
                }
                else{
                    func_80328B8C(this, 1, 0.01f, 1);
                    timedFunc_set_2(randf2(5.0f, 10.0f), mapSpecificFlags_set, 3, TRUE);
                }
            }
            break;
    }//L8035C06C
}
