#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void chBeehive_update(Actor *this);

enum chBeehive_state {
    CHBEEHIVE_STATE_0_UNKNOWN,
    CHBEEHIVE_STATE_1_IDLE,
    CHBEEHIVE_STATE_2_DIE
};

ActorAnimationInfo chBeehiveAnimations[] ={
    {0x000, 0.0f},
    {ASSET_165_ANIM_BEEHIVE_IDLE,   0.65f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     0.5f},
    {ASSET_65_ANIM_BEEHIVE_DIE,     1000000.0f},
};

ActorInfo chBeehive = {MARKER_50_BEEHIVE, ACTOR_12_BEEHIVE, ASSET_364_MODEL_BEEHIVE, 
    1, chBeehiveAnimations, 
    chBeehive_update, actor_update_func_80326224, actor_draw,
    0, 0x333, 0.0f, 0
}; 

void chBeehive_die(ActorMarker *this, ActorMarker *other){
    Actor *actor = marker_getActor(this);
    sfx_playFadeShorthandDefault(SFX_11_WOOD_BREAKING_1, 1.0f, 28000, actor->position, 300, 3000);
    sfx_playFadeShorthandDefault(SFX_D_EGGSHELL_BREAKING, 1.0f, 28000, actor->position, 300, 3000);
    subaddie_set_state(actor, CHBEEHIVE_STATE_2_DIE);
    actor_playAnimationOnce(actor);
    this->collidable = FALSE;
    actor->unk138_27 = 3;
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4C_STEAM, reinterpret_cast(s32, actor->position[0]), reinterpret_cast(s32, actor->position[1]), reinterpret_cast(s32, actor->position[2]));
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, ACTOR_4A_WOOD_EXPLOSION, reinterpret_cast(s32, actor->position[0]), reinterpret_cast(s32, actor->position[1]), reinterpret_cast(s32, actor->position[2]));
    actor->marker->propPtr->unk8_3 = 0;
    func_803115C4(ASSET_D96_DIALOG_BEEHIVE_MEET);
    func_803115C4(ASSET_DA6_DIALOG_BEEHIVE_WITH_BEES);
}

void chBeehive_update(Actor *this){
    if(!this->volatile_initialized){
        marker_setCollisionScripts(this->marker, NULL, NULL, chBeehive_die);
        this->marker->propPtr->unk8_3 = 1;
        this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
        this->volatile_initialized = TRUE;
        this->unk38_0 = volatileFlag_get(VOLATILE_FLAG_1)| volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE);
    }//L802CE960
    if(gsworld_get_map() == MAP_27_FP_FREEZEEZY_PEAK){
        if(maSlalom_isActive()){
            this->unk58_0 = 0;
            return;
        }
        this->unk58_0 = 1;
    }

    switch(this->state)
    {
        case CHBEEHIVE_STATE_1_IDLE:
            if( !fileProgressFlag_get(FILEPROG_D_BEEHIVE_TEXT)
                && subaddie_playerIsWithinCylinder(this, 250, 300)
            ){
                if(player_movementGroup() == BSGROUP_0_NONE || player_movementGroup() == BSGROUP_8_TROT){
                    if( player_getTransformation() == TRANSFORM_1_BANJO
                        && gcdialog_showDialog(ASSET_D96_DIALOG_BEEHIVE_MEET, 0, NULL, NULL, NULL, 0)
                    ){
                        fileProgressFlag_set(FILEPROG_D_BEEHIVE_TEXT, 1);
                    }
                }
            }
            
            if( actor_animationIsAt(this, 0.45f)
                || actor_animationIsAt(this, 0.55f)
                || actor_animationIsAt(this, 0.6f)
            ){
                if(!this->unk38_0){
                    sfxSource_triggerCallbackByIndex(this->unk44_31);
                    sfxsource_setSfxId(this->unk44_31, SFX_67_BEEHIVE_CLONK);
                    sfxsource_setSampleRate(this->unk44_31, 12000);
                    sfxsource_playSfxAtVolume(this->unk44_31, (anctrl_getAnimTimer(this->anctrl) + 0.9) - 0.4);
                    sfxsource_set_position(this->unk44_31, this->position);
                    sfxsource_set_fade_distances(this->unk44_31, 300.0f, 1500.0f);
                    sfxSource_setunk43_7ByIndex(this->unk44_31, 3);
                    sfxSource_func_8030E2C4(this->unk44_31);
                }
            }
            break;

        case CHBEEHIVE_STATE_2_DIE:
            if(anctrl_isStopped(this->anctrl)) {
                func_80326310(this);
            }
            break;
    }
}
