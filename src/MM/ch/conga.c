#include <ultra64.h>
#include "rand.h"
#include "functions.h"
#include "variables.h"

#ifndef MIN
#define MIN(s,t) ((s)<(t)?(s):(t))
#endif

#ifndef MAX
#define MAX(s,t) ((s)<(t)?(t):(s))
#endif

#ifndef SQUARE
#define SQUARE(s) ((s)*(s))
#endif

void func_80328FB0(Actor *, f32);

void func_80328B8C(Actor*, s32, f32, s32);
void func_802C8F70(f32);
void func_80324E88(f32);
Actor *func_8032811C(s32 actor_id, s32 position[3], s32 yaw);
void func_80387F44(void);

void func_803876D0(Actor *);


/* .data */
ActorAnimationInfo chCongaAnimations[9] = {
    {0, 0.0f},
    {ASSET_51_ANIM_CONGA_IDLE, 3.8f},
    {ASSET_52_ANIM_CONGA_OW, 1.0f},
    {ASSET_53_ANIM_CONGA_DEFEAT, 2.0f},
    {ASSET_54_ANIM_CONGA_THROW, 1.4f},
    {ASSET_55_ANIM_CONGA_BEAT_CHEST, 0.4f},
    {ASSET_56_ANIM_CONGA_RAISE_ARMS, 0.9f},
    {0xA2, 1.6f},
    {ASSET_52_ANIM_CONGA_OW, 1.0f}
};

ActorInfo D_80389998 = { 0x7, ACTOR_8_CONGA, model_conga, 1, chCongaAnimations,
    func_803876D0, func_80326224, func_80325888,
    {0x00,0x00,0x03,0x33}, 0.0f, {0,0,0,0}
};


/* code */
int func_80386ED0(Actor * this){
    f32 plyrPos[3];
    f32 tmpz;

    if(map_get() != MAP_2_MM_MUMBOS_MOUNTAIN)
        return 0;

    if(!this->unk10_12)
        return 0;

    player_getPosition(&plyrPos);
    if(plyrPos[1] < 300.0f || 600.0f < plyrPos[1])
        return 0;

    tmpz = plyrPos[2]- 5029.0f;
    if(52900.0f < (plyrPos[0]- -5011.0f)*(plyrPos[0]- -5011.0f) + (plyrPos[2]- 5029.0f)*(plyrPos[2]- 5029.0f))
        return 0;
    
    return 1;
}

void func_80386FB0(Actor *this){
    func_80328C64(this, func_80329784(this));
    func_80328FB0(this, 3.0f);
}

void func_80386FE8(void){
    if( (func_8023DB5C() & 0xF) == 0xB 
        && 0.85 < randf ()
        && !func_803114B0()
    ){
        func_8030E58C(((s32)(randf ()*256.0f) & 1)? SFX_22_KONGA_NOISE_1: SFX_23_KONGA_NOISE_2, 1.0f);
    }
}

void func_8038708C(Actor *this, s32 anim_id){
    func_80328B8C(this, anim_id, 0.0f, 1);
    func_8030E58C(SFX_24_KONGA_NOISE_3, randf2(0.9f, 1.1f));
}

void func_803870D0(Actor *this, ActorMarker *arg1){
    marker_getActor(arg1)->unk100 = this->marker;
}

void func_80387100(ActorMarker *this){
    ActorMarker *m = *(ActorMarker **)&this;
    Actor* actorPtr;
    f32 sp1C[3];

    actorPtr = marker_getActor(m);
    sp1C[0] = actorPtr->position_x;
    sp1C[1] = actorPtr->position_y + 60.0f;
    sp1C[2] = actorPtr->position_z;
    func_802C8F70(0.0f);
    func_80333270(JIGGY_A_MM_CONGA, sp1C, func_803870D0, m);

}

void func_80387168(ActorMarker *this, s32 arg1){
    Actor *actorPtr;

    actorPtr = marker_getActor(this);
    if(actorPtr->conga.unkC == 1){
        if(actorPtr->unk10_12 == 0){
            actorPtr->conga.unkC = 0;
            if(mapSpecificFlags_get(0xA))
                actorPtr->unk38_31++;

            actorPtr->unk10_12 = MIN(actorPtr->unk38_31, 0xA);
            if( actorPtr->unk38_31 == 3 
                && !jiggyscore_isCollected(JIGGY_A_MM_CONGA)
            ){
                func_80328B8C(actorPtr, 8, 0 ,1);
                timed_setCameraToNode(0.0f, 0x10);
                func_80324E38(0.0f, 3);
                func_8030E624(0x665ff884);
                func_8030E624(0x665ff884);
            }
            else if( actorPtr->state != 3
                && actorPtr->state != 8
            ){
                func_8038708C(actorPtr, 2);
                if(actorPtr->unk38_31 == 1){
                    func_80311480(ASSET_B39_TEXT_CONGA_HIT_BY_EGG, 4, actorPtr->position, 0, 0, 0);
                }
            }
        }
    }

}

int func_803872EC(void){
    s32 text_id = func_803114C4();

    return text_id == ASSET_B37_TEXT_CONGA_SAFE_UP_HERE
        || text_id == ASSET_B38_TEXT_CONGA_DEFEAT
        || func_803203FC(0x1F)
        || text_id == ASSET_B3B_TEXT_CONGA_ORANGE_PAD_JIGGY
        || text_id == ASSET_B45_TEXT_JIGGY_COLLECT_10
        || text_id == ASSET_B51_TEXT_BOTTLES_HOW_TO_EXIT_LEVEL;
}

void func_80387370(ActorMarker *this, s32 arg1, s32 arg2){
    marker_getActor(this)->velocity_x = 9.0f;
    timed_setCameraToNode(0.0f, 0x11);
    func_80324E88(3.2f);
    func_80324E38(3.2f, 0);
}

void func_803873C8(ActorMarker *congaMarker){
    ActorMarker *m = *(ActorMarker **)&congaMarker; //sp84
    Actor * congaPtr = marker_getActor(m); //sp80
    ActorLocal_Conga *conga_localPtr = (ActorLocal_Conga *)&congaPtr->local; //sp7C
    s32 conga_state = congaPtr->state;
    Actor * orangePtr;
    f32 pad0;
    TUPLE(f32, pos) plyr;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f18;
    f32 iHeight;
    f32 iVelY;

    congaPtr->unk10_12 -= (congaPtr->unk10_12 && ( conga_state == 7));
    func_80387F44();
    congaPtr->unk28 = 2.0f;
    orangePtr = func_8032811C(ACTOR_14_ORANGE_PROJECTILE, conga_localPtr->orangeSpawnPosition, congaPtr->yaw);

    if(orangePtr != NULL){
        player_getPosition(&plyr.pos);
        orangePtr->velocity_x = plyr.pos_x - orangePtr->position_x;
        orangePtr->velocity_y = (60.0)*((conga_state == 7) ? 0.5: 1.0);
        orangePtr->velocity_z = plyr.pos_z - orangePtr->position_z;
        if(SQUARE(plyr.pos_z - m->propPtr->z) + SQUARE(plyr.pos_x - m->propPtr->x) < 40000.0f ){
            temp_f20 = randf2(2.4f, 4.4f); temp_f22 = randf2(2.4f, 4.4f); //f22
            orangePtr->velocity[0] *= (randf() < 0.5)? temp_f20 : -temp_f20;
            orangePtr->velocity[1] = randf2(1.8f, 2.2f) * 60.0;
            orangePtr->velocity[2] *= (randf() < 0.5)? temp_f22 : -temp_f22;
        }

        iHeight = orangePtr->position_y;
        iVelY = orangePtr->velocity_y;
        for(temp_f18 = 0.0f; !(iHeight < plyr.pos_y &&  iVelY < 0.0f); temp_f18++){
            iHeight += (iVelY -= 5.0);
        }
        orangePtr->velocity_x /= temp_f18;
        orangePtr->velocity_z /= temp_f18;
    }
}

void func_803876D0(Actor *this){
    f32 tmp_f4;
    s32 sp40;
    s32 sp3C;

    this->marker->propPtr->unk8_3 = (func_803250DC(this))?1:0;
    if(!this->initialized){
        this->conga.unkC = 1;
        this->unk16C_0 = 1;
        this->initialized = 1;
        this->velocity_x = 0.0f;
        this->unk28 = 0.0f;
        sp40 = func_80304C38(0x150, this);
        this->conga.unk1C = func_80304D3C(sp40);
        func_80304D4C(sp40, &this->conga.unk10);
    }
    if(0.0f == this->unk28){
        this->unk28 = (func_80326CCC(0x36))? 2.0f: 1.0f;
    }
    if(0.0f != this->velocity_x){
        this->velocity_x -= 1.0f; 
        if(0.0f == this->velocity_x){
            func_802C3C88(func_80387100, this->marker);
        }
    }
    func_803300A8(this->marker, 0, 0, func_80387168);
    if( !func_80329530(this, 2100)
        && this->state != 2
        && this->state != 8
    ){
        if(this->state > 3 && this->state < 8){
            actor_loopAnimation(this);
            func_80328B8C(this, 1, 0.76f, 1);
        }
        return;
    }

    sp3C = func_80329530(this, 1000);
    if( func_8032A9E4(this->conga.unk10, this->conga.unk18, this->conga.unk1C) 
        && !this->unk138_23
        && func_80311480(ASSET_B37_TEXT_CONGA_SAFE_UP_HERE, 0, 0, 0, 0, 0)
    ){
        this->unk138_23 = 1;
        mapSpecificFlags_set(0xA, 1);
    }//L803878F8

    if( sp3C && !this->unk138_24){
        if(func_80311480((player_getTransformation()== TRANSFORM_2_TERMITE) ? ASSET_B3E_TEXT_CONGA_MEET_AS_TERMITE : ASSET_B3C_TEXT_CONGA_MEET, 0, this->position, 0,0,0)){
            this->unk138_24 = 1;
        }
    } //L80387968

    switch(this->state){
        case 1://80387990
            actor_loopAnimation(this);
            func_80386FB0(this);
            func_80386FE8();
            if(actor_animationIsAt(this, 0.0f) || actor_animationIsAt(this, 0.45f)){
                if(randf() < 0.2){
                    animctrl_setDirection(this->animctrl, animctrl_isPlayedForwards(this->animctrl)?0:1);
                };
            }//L80387A18
            if(actor_animationIsAt(this, 0.66f)){
                func_80328BD4(this, 6, 0, 1, 0.38f);
            }
            if( sp3C
                && func_8028ECAC() != 1
                && !func_80386ED0(this)
                && func_803250DC()
                && !func_8032A9E4(this->conga.unk10, this->conga.unk18, this->conga.unk1C)
                && !func_803872EC()
            ){
                func_80328B8C(this, 4, 0.0f, 1);
            }//L80387AC0
            if( func_8028ECAC() != 1
                && func_80386ED0(this)
                && this->unk38_31 != 0
                && !func_803872EC()
            ){
                func_80328B8C(this, 7, 0.0f, 1);
            }
            break;

        case 6: //L80387B24
            this->conga.unkC = 1;
            actor_playAnimationOnce(this);
            func_80386FE8();
            if( animctrl_isPlayedForwards(this->animctrl) == TRUE
                && actor_animationIsAt(this, 0.0f)
            ){
                func_80328B8C(this, 5, 0.0f, 1);
            }
            else if( !animctrl_isPlayedForwards(this->animctrl)
                && actor_animationIsAt(this, 0.001f)
            ){
                func_80328B8C(this, 1, 0.76f, 1);
            }
            break;

        case 5: //L80387BC0
            this->conga.unkC = 1;
            actor_loopAnimation(this);
            func_80386FE8();
            if( actor_animationIsAt(this, 0.99f)){
                func_80328BD4(this, 6, 0.999f, 0, sp3C ? 1.0 : 0.4);
            }//L80387C30
            if( actor_animationIsAt(this, 0.9f)
                || actor_animationIsAt(this, 0.4f)
            ){
                func_8030E6D4(SFX_3FB_UNKNOWN);
            }
            break;

        case 4: //L80387C74
            if(actor_animationIsAt(this, 0.6f)){
                func_8030E58C(SFX_2_CLAW_SWIPE, 0.7f);
            }
            func_80386FB0(this);
            if( !sp3C
                || func_8028F108()
                || func_80386ED0(this)
                || !func_803250DC()
                || func_803872EC()
            ){
                func_80328B8C(this, 1, 0.0f, 1);
            }
            break;

        case 2: //L80387D0C
            actor_playAnimationOnce(this);
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 1, 0.0f, 1);
            }
            break;

        case 8: //L80387D4C
            actor_playAnimationOnce(this);
            if(actor_animationIsAt(this, 0.99f)){
                func_80328B8C(this, 3, 0.0f, 1);
                func_80311480(ASSET_B38_TEXT_CONGA_DEFEAT, 0xe, this->position, this->marker, func_80387370, NULL);
            }
            break;

        case 3: //L80387DB8
            actor_loopAnimation(this);
            if(jiggyscore_isCollected(JIGGY_A_MM_CONGA)){
                func_80328B8C(this, 1, 0.0f, 1);
            }
            break;

        case 7: //L80387DF0
            if(this->unk10_12 == 0){
                if(actor_animationIsAt(this, 0.97f)){
                    this->conga.unkC = 1;
                    func_80328B8C(this, 6, 0.0f, 1);
                }
            }
            break;
    }//L80387E38
    if( (this->state == 4 && actor_animationIsAt(this, 0.56f))
        || (this->state == 7 && actor_animationIsAt(this, 0.468f))
    ){
        func_8034A1B4(this->marker->unk44, 5, &this->local);
        func_802C3C88(func_803873C8, this->marker); //spawn orange
    }
}
