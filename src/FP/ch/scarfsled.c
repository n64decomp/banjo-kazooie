#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "ml/mtx.h"

void chScarfSled_update(Actor *this);

/* .data */
ActorAnimationInfo chScarfSledAnimations[] ={
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f},
    {ASSET_1A1_ANIM_SLED, 1.0f}
};

ActorInfo chScarfSled = {
    MARKER_3B_SCARF_SLED, ACTOR_181_SCARF_SLED, ASSET_352_MODEL_SLED,
    0, chScarfSledAnimations,
    NULL,  chScarfSled_update, actor_draw,
    1000, 0,  0.0f, 0
};

/* .code */
void __chScarfSled_setState(Actor *this, s32 next_state){
    subaddie_set_state(this, next_state);
    
    if(next_state == 2){
        mapSpecificFlags_set(0xB, TRUE);
        timed_setStaticCameraToNode(0.0f, 0x27);
        timed_playSfx(0.6f, SFX_52_BANJO_YAH_OH, 1.0f, 28000);
        timed_playSfx(1.25f, SFX_31_BANJO_OHHWAAOOO, 1.0f, 28000);

        timed_setStaticCameraToNode(1.5f, 0x26);
        timed_setStaticCameraToNode(2.75f, 0x25);
        timed_playSfx(3.5f, SFX_63_BANJO_UWAAAAOOH, 1.0f, 28000);

        timed_setStaticCameraToNode(3.75f, 0x24);
        timed_playSfx(4.25f, SFX_A7_WOODEN_SWOSH, 1.2f, 18000);
        timed_playSfx(4.45f, SFX_C1_BUZZBOMB_ATTACK, 1.0f, 0x7fff);
        timed_setStaticCameraToNode(4.75f, 0x23);
    }
}

void __chScarfSled_touch(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor * this = marker_getActor(this_marker);
    
    if(this->state != 1)  return;
    if(player_getTransformation() != TRANSFORM_1_BANJO) return;

    if(func_8028F68C(BS_INTR_27_BANJO_SLED, this->marker))
        __chScarfSled_setState(this, 2);
}

void __chScarfSled_func_8038655C(Actor *this){
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

void __chScarfSled_func_80386630(Actor *this){
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    MtxF sp24;

    func_80343DEC(this);
    mapSpecificFlags_set(9, 1);
    __chScarfSled_func_8038655C(this);
    if(this->unk138_20){

        this->yaw = 0.0f;
        sp64[0] = this->pitch;
        sp64[1] = this->yaw;
        sp64[2] = this->roll;
        mlMtxIdent();
        mlMtxRotYaw(sp64[1]);
        mlMtxRotPitch(sp64[0]);
        mlMtxGet(&sp24);
        
        sp70[0] = 0.0f;
        sp70[1] = 18.0f;
        sp70[2] = 0.0f;
        mlMtx_apply_vec3f(sp70, sp70);
        
        sp70[0] += this->position[0];
        sp70[1] += this->position[1];
        sp70[2] += this->position[2];
        func_8028FAB0(sp70);
        
        sp64[0] = this->pitch;
        sp64[1] = this->yaw;
        sp64[2] = this->roll;
        player_setIdealRotation(sp64);
    }//L80386724

    if(1.0 == this->unk48){
        mapSpecificFlags_set(1, TRUE);
        FUNC_8030E624(SFX_103_FLOTSAM_DEATH, 1.0f, 30000);
        FUNC_8030E624(SFX_11_WOOD_BREAKING_1, 0.8f, 25000);
        FUNC_8030E624(SFX_D_EGGSHELL_BREAKING, 1.0f, 25000);

        sp7C[0] = -1000.0f;
        sp7C[1] = 1727.0f;
        sp7C[2] = 6218.0f;
        func_8028F490(sp7C);
        marker_despawn(this->marker);
    }//L803867AC
}

void chScarfSled_update(Actor *this){
    if(!this->initialized){
        this->initialized = TRUE;
        marker_setCollisionScripts(this->marker, __chScarfSled_touch, NULL, NULL);
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk10_12 = 0;
        ml_vec3f_clear(this->velocity);
        __chScarfSled_setState(this, 1);
    }

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(jiggyscore_isCollected(JIGGY_2A_FP_BOGGY_1)){
            marker_despawn(this->marker);
            return;
        }
    }

    this->velocity_x = this->position_x;
    this->velocity_y = mapModel_getFloorY(this->position);
    this->velocity_z = this->position_z;
    if(this->state == 2){
        __chScarfSled_func_80386630(this);
    }
}
