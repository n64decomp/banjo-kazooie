#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_803867BC(Actor *this);

/* .data */
ActorAnimationInfo D_803919F0[] ={
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f}
};

ActorInfo D_80391A10 = {
    MARKER_3B_SCARF_SLED, ACTOR_181_SCARF_SLED, ASSET_352_MODEL_SLED,
    0, D_803919F0,
    NULL,  func_803867BC, func_80325888,
    {0x03, 0xE8}, 0,  0.0f, {0,0,0,0}
};

/* .code */
void func_803863F0(Actor *this, s32 next_state){
    func_80328A84(this, next_state);
    
    if(next_state == 2){
        mapSpecificFlags_set(0xB, TRUE);
        timed_setCameraToNode(0.0f, 0x27);
        timed_playSfx(0.6f, SFX_52_BANJO_YAH_OH, 1.0f, 28000);
        timed_playSfx(1.25f, SFX_31_BANJO_OHHWAAOOO, 1.0f, 28000);

        timed_setCameraToNode(1.5f, 0x26);
        timed_setCameraToNode(2.75f, 0x25);
        timed_playSfx(3.5f, SFX_63_BANJO_UWAAAAOOH, 1.0f, 28000);

        timed_setCameraToNode(3.75f, 0x24);
        timed_playSfx(4.25f, SFX_A7_WOODEN_SWOSH, 1.2f, 18000);
        timed_playSfx(4.45f, SFX_C1_BUZZBOMB_ATTACK, 1.0f, 0x7fff);
        timed_setCameraToNode(4.75f, 0x23);
    }
}

void func_803864F4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor * this = marker_getActor(this_marker);
    
    if(this->state != 1)  return;
    if(player_getTransformation() != TRANSFORM_1_BANJO) return;

    if(func_8028F68C(0x27, this->marker))
        func_803863F0(this, 2);
}

void func_8038655C(Actor *this){
    int tmp_bool;
    int tmp;
    tmp_bool = (mlAbsF(this->position_y - this->velocity_y) < 100.0f);
    tmp = this->unk10_12;
    this->unk10_12 = FALSE;
    if(!tmp_bool){
        if(tmp != 0){
            func_8030E6A4(SFX_19_BANJO_LANDING_08, func_8030E200(this->unk44_31), 0x55f0);
        }
    }
    else{
        if(this->unk44_31 == 0){
            this->unk44_31 = func_8030ED2C(SFX_18_BIGBUTT_SLIDE, 2);
            func_8030E0FC(this->unk44_31, 0.9f, 1.5f, 1.2f);
        }
        this->unk10_12 = TRUE;
        func_8030E2C4(*((u8*)this + 0x44));
    }
}

void func_80386630(Actor *this){
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp24[4][4];

    func_80343DEC(this);
    mapSpecificFlags_set(9, 1);
    func_8038655C(this);
    if(this->unk138_20){

        this->yaw = 0.0f;
        sp64[0] = this->pitch;
        sp64[1] = this->yaw;
        sp64[2] = this->roll;
        mlMtxIdent();
        mlMtxRotYaw(sp64[1]);
        mlMtxRotPitch(sp64[0]);
        func_802513B0(sp24);
        
        sp70[0] = 0.0f;
        sp70[1] = 18.0f;
        sp70[2] = 0.0f;
        func_8025235C(sp70, sp70);
        
        sp70[0] += this->position[0];
        sp70[1] += this->position[1];
        sp70[2] += this->position[2];
        func_8028FAB0(sp70);
        
        sp64[0] = this->pitch;
        sp64[1] = this->yaw;
        sp64[2] = this->roll;
        func_8028FAEC(sp64);
    }//L80386724

    if(1.0 == this->unk48){
        mapSpecificFlags_set(1, TRUE);
        FUNC_8030E624(SFX_103_FLOTSAM_DEATH, 0x3A9, 0x3ff);
        FUNC_8030E624(SFX_11_WOOD_BREAKING_1, 0x30D, 0x332);
        FUNC_8030E624(SFX_D_EGGSHELL_BREAKING, 0x30D, 0x3ff);

        sp7C[0] = -1000.0f;
        sp7C[1] = 1727.0f;
        sp7C[2] = 6218.0f;
        func_8028F490(sp7C);
        marker_despawn(this->marker);
    }//L803867AC
}


void func_803867BC(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, func_803864F4, NULL, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk10_12 = 0;
        ml_vec3f_clear(this->velocity);
        func_803863F0(this, 1);
    }

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(jiggyscore_isCollected(JIGGY_2A_FP_BOGGY_1)){
            marker_despawn(this->marker);
            return;
        }
    }

    this->velocity_x = this->position_x;
    this->velocity_y = func_80309724(this->position);
    this->velocity_z = this->position_z;
    if(this->state == 2){
        func_80386630(this);
    }
}
