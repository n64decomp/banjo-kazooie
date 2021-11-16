#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chtreasure_update(Actor *this);

/* .data */
ActorAnimationInfo gChTreasureAnim[]={
    {0, 0.0f},
    {ASSET_153_ANIM_BURIED_TREASURE_APPEAR, 2.0f},
    {ASSET_166_ANIM_BURIED_TREASURE_BOUNCE, 0.33f},
    {0, 0.0}
};

ActorInfo gChTreasureInfo = {
    0xDB, ACTOR_F4_BURIED_TREASURE, ASSET_42C_MODEL_BURIED_TREASURE, 
    1, gChTreasureAnim, 
    chtreasure_update, func_80326224, func_80325888,
    {0,0,0,0}, 1.7f, {0,0,0,0}
}; 

/* .code */
void __chtreasure_die(ActorMarker *marker, ActorMarker *otherMarker){
    Actor *this = marker_getActor(marker);
    func_802C3F04(func_802C4140, 0x4C, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, this->position[1]), reinterpret_cast(s32, this->position[2]));
    func_802EE278(this, 3, 0xf, 0x3C, 0.2f, 1.2f);
    func_803115C4(0xA19);
    jiggySpawn(JIGGY_11_TTC_RED_X, this->position);
    marker_despawn(marker);
}

void __chtreasure_updatePosition(Actor *this){
    this->position[0] = this->unk1C[0];\
    this->position[1] = this->unk1C[1];\
    this->position[2] = this->unk1C[2];

    this->position[0] += this->unk5C*cosf(this->unk60);
    this->position[2] += this->unk5C*sinf(this->unk60);
    this->unk60 += 2.0*time_getDelta()*this->unk5C/300.0;
    if(2*M_PI <= this->unk60)
        this->unk60 -= 2*M_PI;
    this->yaw = this->unk60*180.0/M_PI;
}

void chtreasure_update(Actor *this){
    f32 sp3C[3];
    s16 sp34[3];

    if(!this->initialized){
        this->initialized = TRUE;
        if(this->unkF4_8 == 1 && !func_803203FC(0xC1)){
            marker_despawn(this->marker);
            return;
        }
        actor_collisionOff(this);
        this->scale = 0.5f;
        this->unk60 = M_PI/2;
        this->unk5C = 0.0f;
        this->unk1C[0] = this->position[0];
        this->unk1C[1] = this->position[1];
        this->unk1C[2] = this->position[2];
        
        actor_playAnimationOnce(this);
        func_803300A8(this->marker, NULL, NULL, __chtreasure_die);
    }//L8038C214
    __chtreasure_updatePosition(this);
    func_8034A174(this->marker->unk44, 5, sp3C);
    sp34[0] = (s16)sp3C[0];
    sp34[1] = (s16)sp3C[1];
    sp34[2] = (s16)sp3C[2];
    sp34[1] += 50;
    func_802F3BF4(sp34);

    switch(this->state){
        case 1://L8038C29C
            this->unk5C = func_802877D8(this->animctrl) *300.0; //radius of 300.0f
            if(animctrl_isStopped(this->animctrl)){
                actor_loopAnimation(this);
                func_80328AC8(this, 2);
                this->marker->propPtr->unk8_3 = 1;
                actor_collisionOn(this);
                func_8030E878(SFX_3F2_UNKNOWN, randf2(1.2f, 1.3f), 20000, this->position, 200.0f, 1500.0f);
            }
            break;
        case 2://L8038C344
            if(actor_animationIsAt(this, 0.99f)){
                func_8030E878(SFX_3F2_UNKNOWN, randf2(1.2f, 1.3f), 20000, this->position, 200.0f, 1500.0f);

            }
            break;
        case 3:
            break;
    }//L8038C398
}
