#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chwadingboots_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chwadingboots_update(Actor *this);

/* .data */
extern ActorAnimationInfo D_80367A00[];
extern ActorInfo D_80367A20 = {
    MARKER_11_WADING_BOOTS, ACTOR_65_WADING_BOOTS, ASSET_366_MODEL_WADING_BOOTS, 
    0x0, D_80367A00, 
    chwadingboots_update, func_80326224, chwadingboots_draw, 
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .code */
Actor *chwadingboots_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    
    if(!this->unk10_12) return this;

    return func_80325888(marker, gfx, mtx, vtx);
}

void chwadingboots_update(Actor *this){
    s32 sp2C = levelSpecificFlags_get(0x1a);
    if(sp2C && this->unkF4_8 != 1){
        return;
    }

    if(!this->initialized){
        this->initialized = TRUE;
        this->velocity[0] = this->yaw;
        this->unk10_12 = !func_803203FC(0x1f) && !func_803203FC(0x1);
        func_80328A84(this, 0);
    }

    if(!func_803203FC(0x10) && ability_isUnlocked(ABILITY_E_WADING_BOOTS)){
        func_803204E4(0x10, TRUE);
    }

    switch(this->state){
        case 0://L802D6C60
            if(ability_isUnlocked(ABILITY_E_WADING_BOOTS))
                actor_setOpacity(this, 0xff);
            else
                actor_setOpacity(this, 0x87);

            if(actor_animationIsAt(this, 0.25f)){
                if(sp2C){
                    FUNC_8030E624(SFX_3F2_UNKNOWN, 0x2CE, 0x598);
                }
                else{
                    FUNC_8030E8B4(SFX_3F2_UNKNOWN, 0x2CE, 0x598, this->position, 600, 1500);
                }
            }

            if(func_803203FC(0x10))  break;
            if(!func_80329530(this, 0xfa)) break;
            if(player_getTransformation() != TRANSFORM_1_BANJO) break;
            
            if(func_80311480(0xda5, 0, NULL, NULL, NULL, NULL)){
                func_803204E4(0x10, TRUE);
            }

            break;

        case 1://L802D6D34
            this->velocity[1] -= time_getDelta();
            if(this->velocity[1] <= 0.0f){
                func_80328A84(this, 2);
            }
            break;
        
        case 2://L802D6D74
            if(func_8028E80C(2) == 0.0f){
                this->velocity[1] = 1.5f;
                func_80328A84(this, 3);
            }
            break;

        case 3://L802D6DB0
            this->velocity[1] -= time_getDelta();
            if(this->velocity[1] <= 0.0f){
                this->unk10_12 = 1;
                func_80328A84(this, 0);
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
    func_80328A84(this, 1);
    this->velocity[1] = 1.5f;
    this->unk10_12 = 0;
}
