#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_802CE8D4(Actor *this);

/* .data */
ActorAnimationInfo D_803672C0[] ={
    {0x000, 0.0f},
    {ASSET_165_ANIM_BEEHIVE_IDLE,   0.65f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     0.5f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     1000000.0f},
};

ActorInfo D_803672E0 = {0x50, ACTOR_12_BEEHIVE, ASSET_364_MODEL_BEEHIVE, 
    1, D_803672C0, 
    func_802CE8D4, func_80326224, actor_draw,
    0, 0x333, 0.0f, 0
}; 

/* .code */
void func_802CE7E0(ActorMarker *marker, ActorMarker *other){
    Actor *actor = marker_getActor(marker);
    FUNC_8030E8B4(SFX_11_WOOD_BREAKING_1, 1.0f, 28000, actor->position, 300, 3000);
    FUNC_8030E8B4(SFX_D_EGGSHELL_BREAKING, 1.0f, 28000, actor->position, 300, 3000);
    subaddie_set_state(actor, 2);
    actor_playAnimationOnce(actor);
    marker->collidable = FALSE;
    actor->unk138_27 = 3;
    __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4C_STEAM, reinterpret_cast(s32, actor->position[0]), reinterpret_cast(s32, actor->position[1]), reinterpret_cast(s32, actor->position[2]));
    __spawnQueue_add_4((GenFunction_4)func_802C4140, ACTOR_4A_WOOD_EXPLOSION, reinterpret_cast(s32, actor->position[0]), reinterpret_cast(s32, actor->position[1]), reinterpret_cast(s32, actor->position[2]));
    actor->marker->propPtr->unk8_3 = 0;
    func_803115C4(ASSET_D96_DIALOG_BEEHIVE_MEET);
    func_803115C4(ASSET_DA6_TEXT_BEEHIVE_WITH_BEES);
}

void func_802CE8D4(Actor *this){
    if(!this->unk16C_4){
        marker_setCollisionScripts(this->marker, NULL, NULL, func_802CE7E0);
        this->marker->propPtr->unk8_3 = 1;
        this->unk44_31 = func_8030D90C();
        this->unk16C_4 = 1;
        this->unk38_0 = func_803203FC(1)| func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE);
    }//L802CE960
    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0()){
            this->unk58_0 = 0;
            return;
        }
        this->unk58_0 = 1;
    }//L802CE9A4
    switch(this->state)
    {
    case 1://L802CE9C4
        if( !fileProgressFlag_get(FILEPROG_D_BEEHIVE_TEXT)
            && subaddie_playerIsWithinCylinder(this, 250, 300)
        ){
            if(func_8028ECAC() == 0 || func_8028ECAC() == BSGROUP_8_TROT){
                if( player_getTransformation() == TRANSFORM_1_BANJO
                    && func_80311480(ASSET_D96_DIALOG_BEEHIVE_MEET, 0, NULL, NULL, NULL, 0)
                ){
                    fileProgressFlag_set(FILEPROG_D_BEEHIVE_TEXT, 1);
                }
            }
        }//L802CEA48
        if( actor_animationIsAt(this, 0.45f)
            || actor_animationIsAt(this, 0.55f)
            || actor_animationIsAt(this, 0.6f)
        ){
            if(!this->unk38_0){
                func_8030E394(this->unk44_31);
                sfxsource_setSfxId(this->unk44_31, SFX_67_BEEHIVE_CLONK);
                sfxsource_setSampleRate(this->unk44_31, 12000);
                func_8030DBB4(this->unk44_31, (animctrl_getAnimTimer(this->animctrl) + 0.9) - 0.4);
                sfxsource_set_position(this->unk44_31, this->position);
                sfxsource_set_fade_distances(this->unk44_31, 300.0f, 1500.0f);
                func_8030DD14(this->unk44_31, 3);
                func_8030E2C4(this->unk44_31);
            }
        }//L802CEB48
        break;
    case 2://L802CEB2C
        if(animctrl_isStopped(this->animctrl)){
            func_80326310(this);
        }
        break;
    }//L802CEB48
}

