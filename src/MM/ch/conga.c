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
Actor *func_8032811C(s32 actor_id, s32* position, s32 yaw);
void func_80387F44(void);

void func_803876D0(Actor *);


/* .data */
ActorAnimationInfo chCongaAnimations[9] = {
    {0, 0.0f},
    {anim_conga_idle, 3.8f},
    {anim_conga_ow, 1.0f},
    {ASSET_53_ANIM_CONGA_DEFEAT, 2.0f},
    {0x54, 1.4f},
    {ASSET_55_ANIM_CONGA_BEAT_CHEST, 0.4f},
    {anim_conga_raise_arms, 0.9f},
    {0xA2, 1.6f},
    {anim_conga_ow, 1.0f}
};

ActorInfo D_80389998 = { 0x7, actor_conga, model_conga, 1, chCongaAnimations,
    func_803876D0, func_80326224, func_80325888,
    {0x00,0x00,0x03,0x33}, 0.0f, {0,0,0,0}
};


/*.rodata */
extern f32 D_80389B60;
extern f32 D_80389B64;
extern f32 D_80389B68;
extern f64 D_80389B70;
extern f32 D_80389B78;
extern f32 D_80389B7C;
extern f32 D_80389B80;
extern f32 D_80389B84;
extern f32 D_80389B88;
extern f32 D_80389B8C;
extern f32 D_80389B90;
extern f32 D_80389B94;
extern f32 D_80389B98;
extern f32 D_80389B9C;

extern f64 D_80389BC0;
extern f32 D_80389BC8;


/* code */
int func_80386ED0(Actor * this){
    f32 plyrPos[3];
    f32 tmpz;

    if(func_803348C0() != MAP_2_MM_MUMBOS_MOUNTAIN)
        return 0;

    if(!this->unk10_12)
        return 0;

    player_getPosition(&plyrPos);
    if(plyrPos[1] < 300.0f || 600.0f < plyrPos[1])
        return 0;

    tmpz = plyrPos[2]- D_80389B60;
    if(D_80389B68 < (plyrPos[0]- D_80389B64)*(plyrPos[0]- D_80389B64) + (plyrPos[2]- D_80389B60)*(plyrPos[2]- D_80389B60))
        return 0;
    
    return 1;
}

void func_80386FB0(Actor *this){
    func_80328C64(this, func_80329784(this));
    func_80328FB0(this, 3.0f);
}

void func_80386FE8(void){
    if( (func_8023DB5C() & 0xF) == 0xB 
        && D_80389B70 < randf ()
        && !func_803114B0()
    ){
        func_8030E58C(((s32)(randf ()*256.0f) & 1)? 0x22: 0x23, 1.0f);
    }
}

void func_8038708C(Actor *this, s32 anim_id){
    func_80328B8C(this, anim_id, 0.0f, 1);
    func_8030E58C(0x24, randf2(D_80389B78, D_80389B7C));
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
    func_80333270(0xA, sp1C, func_803870D0, m);

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
                && !jiggyscore_isCollected(0xA)
            ){
                func_80328B8C(actorPtr, 8, 0 ,1);
                func_80324E60(0.0f, 0x10);
                func_80324E38(0.0f, 3);
                func_8030E624(0x665ff884);
                func_8030E624(0x665ff884);
            }
            else if( actorPtr->state != 3
                && actorPtr->state != 8
            ){
                func_8038708C(actorPtr, 2);
                if(actorPtr->unk38_31 == 1){
                    func_80311480(text_conga_hit_by_egg, 4, actorPtr->position, 0, 0, 0);
                }
            }
        }
    }

}

int func_803872EC(void){
    s32 text_id = func_803114C4();

    return text_id == text_conga_safe_up_here
        || text_id == text_conga_defeat
        || func_803203FC(0x1F)
        || text_id == text_conga_orange_pad_jiggy
        || text_id == text_jiggy_collect_10
        || text_id == text_bottles_how_to_exit_level;
}

void func_80387370(ActorMarker *this, s32 arg1, s32 arg2){
    marker_getActor(this)->velocity_x = 9.0f;
    func_80324E60(0.0f, 0x11);
    func_80324E88(D_80389B80);
    func_80324E38(D_80389B84, 0);
}

void func_803873C8(ActorMarker *congaMarker);
#ifdef NONMATCHING
void func_803873C8(ActorMarker *congaMarker){
    Actor * congaPtr = marker_getActor(congaMarker);
    ActorLocal_Conga *conga_localPtr;
    s32 conga_state;
    Actor * orangePtr;
    TUPLE(f32, pos) plyr;
    f32 temp_f22;
    f32 temp_f20;
    f32 temp_f18;
    f32 iHeight;
    f32 iVelY;

    conga_localPtr = &congaPtr->conga;
    congaPtr->unk10_12 -= (congaPtr->unk10_12 && ( (conga_state = congaPtr->unk10_31) == 7));
    func_80387F44();
    congaPtr->unk28 = 2.0f;
    orangePtr = func_8032811C(actor_orange_projectile, conga_localPtr->orangeSpawnPosition, congaPtr->yaw);

    if(orangePtr != NULL){
        player_getPosition(&plyr.pos);
        orangePtr->velocity_x = plyr.pos_x - orangePtr->position_x;
        orangePtr->velocity_y = (60.0)*((conga_state == 7) ? 0.5: 1.0);
        orangePtr->velocity_z = plyr.pos_z - orangePtr->position_z;
        if(SQUARE(plyr.pos_z - congaMarker->propPtr->z) + SQUARE(plyr.pos_x - congaMarker->propPtr->x) < 40000.0f ){
            temp_f20 = randf2(2.4f, 4.4f); //f20
            temp_f22 = randf2(2.4f, 4.4f); //f22
            orangePtr->velocity_x *= (randf() < 0.5)? temp_f20 : -temp_f20;
            orangePtr->velocity_y = randf2(1.8f, 2.2f) * 60.0;
            orangePtr->velocity_z *= (randf() < 0.5)? temp_f22 : -temp_f22;
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
#else
#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/conga/func_803873C8.s")
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/MM/ch/conga/func_803876D0.s")
#else
void func_803876D0(Actor *this){
    s32 sp40;
    s32 sp3C;
    s32 sp38;

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
    if( !func_80329530(this, 0x834)
        && this->state != 2
        && this->state != 8
        && this->state > 3
    ){
        if(this->state < 8){
            actor_loopAnimation(this);
            func_80328B8C(this, 1, 0.76f, 1);
        }
        return;
    }

    sp3C = func_80329530(this, 0x3E8);
    if( func_8032A9E4(this->conga.unk10, this->conga.unk18, this->conga.unk1C) 
        && this->unk138_24 < 0
        && func_80311480(text_conga_safe_up_here, 0, 0, 0, 0, 0)
    ){
        this->unk138_24 = 1;
        mapSpecificFlags_set(0xA, 1);
    }//L803878F8

    if( sp3C && !this->unk138_24){
        sp38 = (player_getTransformation()== TRANSFORM_2_TERMITE) ? text_conga_meet_as_termite : text_conga_meet;
        func_80311480(sp38, 0, this->position, 0,0,0);
        this->unk138_24 = 1;
    } //L80387968

    switch(this->state){
        case 1:
            actor_loopAnimation(this);
            func_80386FB0(this);
            func_80386FE8();
            if(actor_animationIsAt(this, 0) || actor_animationIsAt(this, 0.45f)){
                if(randf() < D_80389BC0){
                    animctrl_setDirection(this->animctrl, (this->animctrl, 0.65625f)?0:1);
                };
            }//L80387A18
            if(actor_animationIsAt(this, 0.66f)){

                func_80328BD4(this, 6, 0, 1, D_80389BC8);
            }
            if( sp3C
                && func_8028ECAC() != 1
                && func_80386ED0(this)
                && func_803250DC()
                && !func_8032A9E4(this->conga.unk10, this->conga.unk18, this->conga.unk1C)
                && !func_803872EC()
            ){
                func_80328B8C(this, 0, 4, 1);
            }
            if( func_8028ECAC() != 1
                && func_80386ED0(this)
                && this->unk38_31 != 0
            ){
                func_80328B8C(this, 7, 0, 1);
            }
            break;
        case 2:
            break;
    }//L80387E38
    if(this->state == 4){

    }
    func_802C3C88(func_803873C8, this->marker); //spawn orange
}
#endif
