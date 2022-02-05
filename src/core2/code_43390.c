#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *chtrainers_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chtrainers_update(Actor *this);

/* .data */
extern ActorAnimationInfo D_80366EA0[];
extern ActorInfo D_80366EC0 = { 
    MARKER_38_TURBO_TALON_TRAINERS, ACTOR_2C_TURBO_TALON_TRAINERS, ASSET_367_MODEL_TURBO_TALON_TRAINERS,
    0x0, D_80366EA0,
    chtrainers_update, func_80326224, chtrainers_draw,
    { 0x0, 0x0}, 0, 0.0f, { 0x0, 0x0, 0x0, 0x0}
};

/* .rodata */
extern f64 D_80376470;
extern f64 D_80376478;

/* .code */
Actor *chtrainers_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if( !this->unk10_12 )
        return this;
    return func_80325888(marker, gfx, mtx, vtx);
}


void func_802CA378(Actor *this, bool arg1){
    f32 sp24[3];
    if(ability_isUnlocked(ABILITY_11_TURBO_TALON))
        actor_setOpacity(this, 0xff);
    else
        actor_setOpacity(this, 0x87);

    if( actor_animationIsAt(this, 0.38f)
        || actor_animationIsAt(this, 0.88f)
    ){
        if(arg1)
            FUNC_8030E624(SFX_8_BANJO_LANDING_04, 0xDA, 0x664);
        else
            FUNC_8030E8B4(SFX_8_BANJO_LANDING_04, 0xDA, 0x664, this->position, 600, 1500);
    }

    func_802589E4(sp24, this->velocity[1], 40.0f);
    sp24[1] = 0.0f;
    ml_vec3f_add(this->position, this->unk1C, sp24);
    this->velocity[1] += D_80376470;
    this->yaw = mlNormalizeAngle(this->velocity[1] + D_80376478);
}

void chtrainers_update(Actor *this){
    s32 sp2C = levelSpecificFlags_get(0x1a);
    if(sp2C && this->unkF4_8 != 1){
        return;
    }

    if(!this->initialized){
        this->initialized = TRUE;
        ml_vec3f_copy(this->unk1C, this->position);
        this->velocity[0] = this->yaw;
        this->velocity[1] = 0.0f;
        this->unk10_12 = !func_803203FC(0x1f) && !func_803203FC(0x1);
        func_80328A84(this, 0);
    }

    if(!func_803203FC(0xF) && ability_isUnlocked(ABILITY_11_TURBO_TALON)){
        func_803204E4(0xF, TRUE);
    }

    switch(this->state){
        case 0://L802CA5A8
            if(func_803296D8(this, 2000) || sp2C){
                if( func_80329530(this, 0xfa)
                    && !func_803203FC(0xf)
                    && player_getTransformation() == TRANSFORM_1_BANJO
                ){
                    if(func_80311480(0xda4, 0, NULL, NULL, NULL, NULL)){
                        func_803204E4(0xf, TRUE);
                    }
                }//L802CA620
                func_802CA378(this, sp2C);
            }
            break;

        case 1://L802CA630
            this->velocity[2] -= time_getDelta();
            if(this->velocity[2] <= 0.0f){
                func_80328A84(this, 2);
            }
            break;
        
        case 2://L802CA670
            if(func_8028E80C(3) == 0.0f){
                this->velocity[2] = 1.0f;
                func_80328A84(this, 3);
            }
            break;

        case 3://L802CA6AC
            this->velocity[2] -= time_getDelta();
            if(this->velocity[2] <= 0.0f){
                this->unk10_12 = 1;
                func_80328A84(this, 0);
            }
            break;
    }//L802CA6F8
}

bool chtrainers_802CA708(Actor *this){
    return this->unk10_12 && ability_isUnlocked(ABILITY_11_TURBO_TALON);
}

f32 chtrainers_802CA748(Actor *this){
    return this->velocity[0];
}

void chtrainers_802CA750(Actor *this){
    func_80328A84(this, 1);
    this->velocity[2] = 1.0f;
    this->unk10_12 = 0;
}
