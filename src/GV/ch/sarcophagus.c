#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802EE6CC(f32[3], s32[4], s32[4], s32, f32, f32, s32, s32, s32);


void chSarcophagus_update(Actor *this);
void chSarcophagus_updateSNS(Actor *this);

/* .data */
ActorAnimationInfo chSarcophagusAnimations[] = {
    {0x00, 0.0f},
    {ASSET_CD_ANIM_SARCOPHAGUS_OPEN, 8000000.0f},
    {ASSET_CD_ANIM_SARCOPHAGUS_OPEN, 2.5f},
    {ASSET_CD_ANIM_SARCOPHAGUS_OPEN, 8000000.0f},
    {ASSET_CD_ANIM_SARCOPHAGUS_OPEN, 1.6f},
    {ASSET_CD_ANIM_SARCOPHAGUS_OPEN, 4.5f},
};

ActorInfo chSarcophagus = { MARKER_A8_GV_MAZE_SARCOPHAGUS, ACTOR_11A_GV_MAZE_SARCOPHAGUS, ASSET_33D_MODEL_SARCOPHAGUS, 
    0x1, chSarcophagusAnimations, 
    chSarcophagus_update, actor_update_func_80326224, actor_draw, 
    2500, 0, 0.0f, 0
};

ActorInfo chSNSSarcophagus = { MARKER_23B_GV_SNS_SARCOPHAGUS, ACTOR_244_GV_SNS_SARCOPHAGUS, ASSET_33D_MODEL_SARCOPHAGUS, 
    0x1, chSarcophagusAnimations, 
    chSarcophagus_updateSNS, actor_update_func_80326224, actor_draw, 
    0, 0, 0.0f, 0
};

s32 D_80390E78[4] = {0xff, 0xd0, 0x5d, 0xb4};
s32 D_80390E88[4] = {0, 0, 0, 0};

/* .code */
void GV_func_803894B0(Actor *this){
    this->marker->propPtr->unk8_3 = TRUE;
    actor_collisionOff(this);
    subaddie_set_state_with_direction(this, 1, 0.01f, 1);
    this->unk38_31 = 0;
    this->initialized = TRUE;
}

void func_80389518(Actor *this){
    func_802EE6CC(this->unk1C, D_80390E88, D_80390E78, 0, 
        0.55f, 50.0f, 0xDC, 0x168, 0
    );
}

int func_8038957C(Actor *this){
    f32 f0;
    
    f0 = this->yaw - func_80329784(this);
    if(180.0f <= f0)
        f0 -= 360;
    else if(f0 < -180.0f) 
        f0 += 360;

    if(f0 <= 0.0f && -180.0f <= f0){
        return 1;
    }
    return 0;
}

void chSarcophagus_update(Actor *this){
    int i;

    switch(this->state){
        case 1: //L80389680
            if(!this->initialized){
                GV_func_803894B0(this);
            }
            if(func_80329530(this, 500) && func_8038957C(this)){
                subaddie_set_state_with_direction(this, 2, 0.01f, 1);
                FUNC_8030E8B4(SFX_6B_LOCKUP_OPENING, 1.0f, 32000, this->position, 1250, 2500);
                FUNC_8030E8B4(SFX_3F6_RUBBING, 1.0f, 32000, this->position, 1250, 2500);

            }
            break;

        case 2: //L8038970C
            if( this->unk38_31 == 0 
                && actor_animationIsAt(this, 0.1f)
                && !jiggyscore_isCollected(JIGGY_41_GV_MAZE)
            ){
                func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 0x7fff);
                this->unk38_31 = 1;
            }
            if(actor_animationIsAt(this, 0.5f)){
                subaddie_set_state_with_direction(this, 3, 0.5f, 1);
            }
            break;

        case 3: //L80389788
            if(!func_80329530(this, 700)){
                subaddie_set_state_with_direction(this, 4, 0.5f, 1);
                FUNC_8030E8B4(SFX_6B_LOCKUP_OPENING, 1.0f, 32000, this->position, 1250, 2500);
                FUNC_8030E8B4(SFX_3F6_RUBBING, 1.0f, 32000, this->position, 1250, 2500);
            }
            break;
        case 4: //L803897E4
            if(actor_animationIsAt(this, 0.9f) && this->marker->unk14_21){
                i = 6;
                do{
                    func_8034A174((struct5Bs*)this->marker->unk44, i, this->unk1C);
                    func_80389518(this);
                    i++;
                }while(i < 17);
            }

            if(actor_animationIsAt(this, 0.99f)){
                subaddie_set_state_with_direction(this, 1, 0.01f, 1);
            }
            else if(actor_animationIsAt(this, 0.9f)){
                FUNC_8030E8B4(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 32000, this->position, 1250, 2500);
            }
            break;
    }//L803898A8
}

void chSarcophagus_updateSNS(Actor *this){
    if(!this->initialized){
        GV_func_803894B0(this);
        if(fileProgressFlag_get(FILEPROG_A4_GV_SNS_SARCOPHAGUS_OPEN))
            subaddie_set_state_with_direction(this, 3, 0.5f, 1);
        this->unk1C[0] = 0.0f;
    }

    switch(this->state){
        case 1://L80389934
            if(this->unk1C[0] != 0.0f){
                this->unk1C[0] -= 1.0f;
                if(this->unk1C[0] == 0.0f){
                    subaddie_set_state_with_direction(this, 5, 0.01f, 1);
                    FUNC_8030E8B4(SFX_6B_LOCKUP_OPENING, 0.5f, 32000, this->position, 1250, 2500);
                    FUNC_8030E8B4(SFX_3F6_RUBBING, 0.5f, 32000, this->position, 1250, 2500);
                }
            }
            else{//L803899C0
                if(fileProgressFlag_get(FILEPROG_A3_GV_SNS_SWITCH_PRESSED)){
                    this->unk1C[0] = 33.0f;
                }
            }
            break;
        case 5://L803899DC
            if(actor_animationIsAt(this, 0.5f)){
                subaddie_set_state_with_direction(this, 3, 0.5f, 1);
                FUNC_8030E624(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 25000);
            }
            break;
    }//L80389A0C
}
