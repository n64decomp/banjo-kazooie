#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct chleafboat_s{
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24[3];
    f32 unk30[3];
    f32 unk3C[3];
    f32 unk48[3];
    f32 unk54[3];
    f32 unk60[3];
    f32 unk6C;
} ActorLocal_Leafboat;

void chLeafBoat_update(Actor *this);
Actor *chLeafBoat_draw(ActorMarker *this, Gfx** gdl, Mtx** mtx, Vtx **Vtx);


/* .data section */
u8 D_80390DA0[6] = {0, 0, 0, 1, 1, 1};

ActorInfo gChLeafBoat = {MARKER_DA_LEAF_BOAT, ACTOR_F1_LEAF_BOAT, ASSET_30D_MODEL_LEAF_BOAT, 
    0x01, NULL,
    chLeafBoat_update, chLeafBoat_update, chLeafBoat_draw,
    0, 0, 0.0f, 0
};


/* .code section */
Actor *chLeafBoat_draw(ActorMarker *this, Gfx** gdl, Mtx** mtx, Vtx **vtx){
    Actor * thisActor;

    thisActor = marker_getActor(this);
    if((thisActor->unk1C_x != 0.0f) && (0x80 < thisActor->alpha_124_19)){
        thisActor = actor_draw(this, gdl, mtx, vtx);
    }
    return thisActor;
}

void func_8038FD88(ActorMarker *this, ActorMarker *other){
    this->isBanjoOnTop = 1;
}

void chLeafBoat_update(Actor *this){
    f32 sp64[3];
    f32 player_position[3];
    ActorLocal_Leafboat *local;
    u8 tmp[6] = D_80390DA0;
    f32 pad0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    local = (ActorLocal_Leafboat *)&this->local;
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_8038FD88, NULL, NULL);
        local->unk6C = randf2(80.0f, 100.0f);
        this->unk1C[0] = this->unk1C[1] = this->unk1C[2] = 0.0f;
        local->unk0[0] = local->unk0[1] = local->unk0[2] = 0.0f;
        local->unkC[0] = local->unkC[1] = local->unkC[2] = 0.0f;
        local->unk18[0] = local->unk18[1] = local->unk18[2] = 0.0f;
        local->unk24[0] = local->unk24[1] = local->unk24[2] = 0.0f;
        local->unk30[0] = local->unk30[1] = local->unk30[2] = 0.0f;
        local->unk3C[0] = local->unk3C[1] = local->unk3C[2] = 0.0f;
        local->unk48[0] = local->unk48[1] = local->unk48[2] = 0.0f;
        local->unk54[0] = this->position_x;
        local->unk54[1] = this->position_y;
        local->unk54[2] = this->position_z;
        local->unk60[0] = this->pitch;
        local->unk60[1] = this->yaw;
        local->unk60[2] = this->roll;
        this->lifetime_value = 0.0f;
        this->velocity_x = 0.0f;
        this->unk10_12 = 0;
    }

    this->position_x = local->unk54[0];
    this->position_y = local->unk54[1];
    this->position_z = local->unk54[2];
    this->pitch = local->unk60[0];
    this->yaw   = local->unk60[1];
    this->roll  = local->unk60[2];
    switch(this->state){
        case 1:
            if(this->marker->unk2C_2)
                actor_update_func_80326224(this);
            this->marker->propPtr->unk8_3 = 1;
            this->unk1C[0] = 1.0f;
            this->alpha_124_19 = 0xff;
            if(this->unk54 != 0.0f){
                subaddie_set_state(this, 2);
            }
            break;

        case 2:
            if(this->marker->unk2C_2)
                actor_update_func_80326224(this);
                
            this->marker->propPtr->unk8_3 = 1;
            this->unk1C[0] = 1.0f;
            if(15.0f <= this->velocity_x){
                subaddie_set_state(this, 3);
                this->velocity_x = 0.0f;
            }
            else{
                if(!tmp[((s32)this->velocity_x)%6])
                    this->alpha_124_19 -= 0x55;
                else
                    this->alpha_124_19 += 0x55;
                this->velocity_x = this->velocity_x + 1.0f;
            }

            break;
        case 3:
            if (this->marker->unk2C_2) {
                actor_update_func_80326224(this);
            }
            this->marker->propPtr->unk8_3 = FALSE;
            this->unk1C[0] = 0.0f;
            this->alpha_124_19 = 0;
            if (this->unk54 == 0.0f) {
                subaddie_set_state(this, 4);
            }
            break;

        case 4:
            this->marker->propPtr->unk8_3 = 1;
            this->unk1C[0] = 1.0f;
            if (this->velocity[0] >= 15.0f) {
                subaddie_set_state(this, 1);
                this->velocity[0] = 0.0f;
            } else {
                if(tmp[5-(((s32)this->velocity_x)%6)]) {
                    this->alpha_124_19 += 0x55;
                } else {
                    this->alpha_124_19 -= 0x55;
                }
                this->velocity[0] += 1.0f;
            }
            break;
    }

    local->unk54[0] = this->position_x;
    local->unk54[1] = this->position_y;
    local->unk54[2] = this->position_z;
    local->unk60[0] = this->pitch;
    local->unk60[1] = this->yaw;
    local->unk60[2] = this->roll;
    this->lifetime_value += time_getDelta();
    playerPosition_get(player_position);
    if( func_80294660() == 0x100
        && func_8028F20C()
        && this->marker->isBanjoOnTop
    ){
        sp44 = local->unk54[0] - player_position[0];
        sp40 = local->unk54[2] - player_position[2];
        sp3C = cosf((local->unk60[1] * M_PI) / 180.0);
        sp38 = sinf((local->unk60[1] * M_PI) / 180.0);
        local->unkC[0] = -((sp44 * sp38) + (sp40 * sp3C)) / 8;
        local->unkC[2] = ((sp44 * sp3C) - (sp40 * sp38)) / 8;
        if(this->unk10_12){
            if(local->unk24[1] < -20.0f){
                local->unk30[1] = -7.0f;
            }
        }
        else{
            local->unk30[1] = -32.0f;
        }
        this->unk10_12 = 1;
    } else {
        local->unkC[0] = local->unkC[1] = local->unkC[2] = 0.0f;
        if(!this->unk10_12){
            if(local->unk24[1] > 5.0f){
                local->unk30[1] = 0.0f;
            }
        }
        else{
            local->unk30[1] = 10.0f;
        }
        this->unk10_12 = 0;
    }
    this->marker->isBanjoOnTop = 0;

    local->unk18[1] = 10 * sinf((((this->lifetime_value * local->unk6C) / 180.0) * BAD_PI));
    this->unk1C[0] =   4.5  * cosf((((this->lifetime_value * local->unk6C) / 180.0) * BAD_PI));
    this->unk1C[1] =   2*sinf((((this->lifetime_value * local->unk6C) / 180.0) * BAD_PI));
    sp64[0] = local->unk3C[0] + local->unk24[0];
    sp64[1] = local->unk3C[1] + local->unk24[1];
    sp64[2] = local->unk3C[2] + local->unk24[2];

    sp64[0] = sp64[0] + local->unk18[0];
    sp64[1] = sp64[1] + local->unk18[1];
    sp64[2] = sp64[2] + local->unk18[2];

    this->position[0] = this->position[0] + sp64[0];
    this->position[1] = this->position[1] + sp64[1];
    this->position[2] = this->position[2] + sp64[2];

    local->unk0[2]  += (local->unkC[2] - local->unk0[2]) * 0.075;
    local->unk0[0]  += (local->unkC[0] - local->unk0[0]) * 0.075;
    local->unk24[1] += (local->unk30[1] - local->unk24[1]) * 0.2;
    sp64[0] = local->unk48[0] + this->unk1C[0];
    sp64[1] = local->unk48[1] + this->unk1C[1];
    sp64[2] = local->unk48[2] + this->unk1C[2];
    sp64[0] = sp64[0] + local->unk0[0];
    sp64[1] = sp64[1] + local->unk0[1];
    sp64[2] = sp64[2] + local->unk0[2];
    this->pitch += sp64[0];
    this->yaw   += sp64[1];
    this->roll  += sp64[2];
}
