#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/statetimer.h"
extern f32 player_stateTimer_get(enum state_timer_e);

Actor *chwadingboots_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chwadingboots_update(Actor *this);

/* .data */
ActorAnimationInfo D_80367A00[] = {
    {ASSET_67_ANIM_WADINGBOOTS_WALK, 0.7f},
    {ASSET_67_ANIM_WADINGBOOTS_WALK, 0.7f},
    {ASSET_67_ANIM_WADINGBOOTS_WALK, 0.7f},
    {ASSET_67_ANIM_WADINGBOOTS_WALK, 0.7f},
};

ActorInfo D_80367A20 = {
    MARKER_11_WADING_BOOTS, ACTOR_65_WADING_BOOTS, ASSET_366_MODEL_WADING_BOOTS, 
    0x0, D_80367A00, 
    chwadingboots_update, actor_update_func_80326224, chwadingboots_draw, 
    0, 0, 0.0f, 0
};

/* .code */
Actor *chwadingboots_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    
    if(!this->unk10_12) return this;

    return actor_draw(marker, gfx, mtx, vtx);
}

void chwadingboots_update(Actor *this){
    s32 sp2C = levelSpecificFlags_get(LEVEL_FLAG_1A_UNKNOWN);

    if (sp2C && this->actorTypeSpecificField != 1) {
        return;
    }

    if(!this->initialized){
        this->initialized = TRUE;
        this->velocity[0] = this->yaw;
        this->unk10_12 = !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE) && !volatileFlag_get(VOLATILE_FLAG_1);
        subaddie_set_state(this, 0);
    }

    if(!volatileFlag_get(VOLATILE_FLAG_10_HAS_MEET_WADING_BOOTS) && ability_isUnlocked(ABILITY_E_WADING_BOOTS)){
        volatileFlag_set(VOLATILE_FLAG_10_HAS_MEET_WADING_BOOTS, TRUE);
    }

    switch(this->state){
        case 0://L802D6C60
            if(ability_isUnlocked(ABILITY_E_WADING_BOOTS))
                actor_setOpacity(this, 0xff);
            else
                actor_setOpacity(this, 0x87);

            if(actor_animationIsAt(this, 0.25f)){
                if(sp2C){
                    FUNC_8030E624(SFX_3F2_BOING,  1.4f, 23000);
                }
                else{
                    sfx_playFadeShorthandDefault(SFX_3F2_BOING,  1.4f, 23000, this->position, 600, 1500);
                }
            }

            if(volatileFlag_get(VOLATILE_FLAG_10_HAS_MEET_WADING_BOOTS))  break;
            if(!subaddie_playerIsWithinSphereAndActive(this, 250)) break;
            if(player_getTransformation() != TRANSFORM_1_BANJO) break;
            
            if(gcdialog_showDialog(ASSET_DA5_DIALOG_WADINGBOOTS_MEET, 0, NULL, NULL, NULL, NULL)){
                volatileFlag_set(VOLATILE_FLAG_10_HAS_MEET_WADING_BOOTS, TRUE);
            }

            break;

        case 1://L802D6D34
            this->velocity[1] -= time_getDelta();
            if(this->velocity[1] <= 0.0f){
                subaddie_set_state(this, 2);
            }
            break;
        
        case 2://L802D6D74
            if(player_stateTimer_get(STATE_TIMER_2_LONGLEG) == 0.0f){
                this->velocity[1] = 1.5f;
                subaddie_set_state(this, 3);
            }
            break;

        case 3://L802D6DB0
            this->velocity[1] -= time_getDelta();
            if(this->velocity[1] <= 0.0f){
                this->unk10_12 = 1;
                subaddie_set_state(this, 0);
            }
            break;
    }//L802D6DFC
}

bool chwadingboots_802D6E0C(Actor *this){
    return this->unk10_12 && ability_isUnlocked(ABILITY_E_WADING_BOOTS);
}

f32 chwadingboots_802D6E4C(Actor *this){
    return this->velocity[0];
}

void chwadingboots_802D6E54(Actor *this){
    subaddie_set_state(this, 1);
    this->velocity[1] = 1.5f;
    this->unk10_12 = 0;
}
