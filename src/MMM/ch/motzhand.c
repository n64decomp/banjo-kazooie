#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    f32 alpha; //motzhand_alpha
    u8 *pattern_ptr;
    u8 unk8; //pattern_id
    u8 unk9; //end_current seq?
    f32 unkC[3];
}ActorLocal_Motzhand;

void chmotzhand_update(Actor *this);
Actor *chMotzhand_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chMotzhand = {
    MARKER_49_MOTZHAND, ACTOR_3A_MOTZHAND, ASSET_88C_MODEL_MOTZHAND,
    0x0, NULL,
    chmotzhand_update, actor_update_func_80326224, chMotzhand_draw,
    0, 0, 0.0f, 0
};

u8 sMotzhandPattern1[] = {7, 14, 13, 9, 17, 0xFF};
u8 sMotzhandPattern2[] = {10, 18, 15, 9, 14, 13, 9, 17, 11, 15, 0xFF};

/* .code */
void func_80387410(f32 dst[3]){
    dst[0] = 0.0f;
    dst[1] = 1500.0f;
    dst[2] = -2400.0f;
}

void chMotzhand_setState(Actor *this, s32 next_state){
    ActorLocal_Motzhand * local = (ActorLocal_Motzhand *) &this->local;

    if(next_state == 1 && this->state == 0){
        skeletalAnim_set(this->unk148, ASSET_A7_ANIM_MOTZHAND_IDLE, 0.0f, 1.8f);
        func_80387410(this->position);
    }

    if(next_state == 2){
        skeletalAnim_set(this->unk148, ASSET_A7_ANIM_MOTZHAND_IDLE, 0.9f, 1.8f);
    }

    if(next_state == 3){
        skeletalAnim_set(this->unk148, ASSET_A8_ANIM_MOTZHAND_PLAY, 0.9f, 1.8f);
    }

    if(next_state == 4){
        local->alpha = 1.0f;
    }

    if(next_state == 5){
        marker_despawn(this->marker);
    }

    this->state = next_state;
}

Actor *chMotzhand_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    ActorLocal_Motzhand * local = (ActorLocal_Motzhand *) &this->local;
    f32 sp3C[3];

    if(this->state == 0 || this->state == 5)
        return this;
    
    modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(this->unk148));
    
    if(this->state == 4){
        modelRender_setAlpha((s32) (local->alpha * 255.0f));
    }
    else{
        modelRender_setAlpha((s32) 255);
    }

    sp3C[0] = sp3C[1] = sp3C[2] = 0.0f;
    sp3C[1] = 180.0f;
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gfx, mtx, this->position, sp3C, 1.0f, NULL, marker_loadModelBin(marker));
    this->marker->unk14_21 = func_8033A170();
    return this;
}


void func_80387654(ActorMarker* marker) {
    Actor* actor = marker_getActor(marker);

    if ((actor->state != 4) && (actor->state != 5)) {
        chMotzhand_setState(actor, 4);
    }
}

bool func_8038769C(ActorMarker *marker) {
    return marker_getActor(marker)->state == 1;
}

// chMotzhand_startPattern
void func_803876C8(ActorMarker *marker, s32 arg1){
    Actor *this = marker_getActor(marker);
    ActorLocal_Motzhand * local = (ActorLocal_Motzhand *) &this->local;
    
    local->unk8 = arg1;
    if(arg1 == TRUE){
        local->pattern_ptr = sMotzhandPattern1;
    }
    else{
        local->pattern_ptr = sMotzhandPattern2;
    }

    chMotzhand_setState(this, 2);
}

void func_80387720(ActorMarker *marker) {
    Actor * this = marker_getActor(marker);
    ActorLocal_Motzhand * local = (ActorLocal_Motzhand *) &this->local;
    local->unk9 = TRUE;
}

void chmotzhand_update(Actor *this){
    ActorLocal_Motzhand * local = (ActorLocal_Motzhand *) &this->local;
    f32 sp48;
    f32 sp3C[3];
    f32 sp30[3];

    sp48 = time_getDelta();

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(jiggyscore_isSpawned(JIGGY_60_MMM_MOTZHAND)){
            marker_despawn(this->marker);
            return;
        }
        local->unk8 = FALSE;
        local->unk9 = FALSE;
        local->unkC[0] = this->position_x;
        local->unkC[1] = this->position_y;
        local->unkC[2] = this->position_z;
        chMotzhand_setState(this, 1);
    }//L803877CC

    if(this->state == 2){
        if(local->unk9){
            while(*local->pattern_ptr != 0xff){
                *local->pattern_ptr++; //find_seq end
            }
            local->unk9 = FALSE;
        }//L80387820

        if(0xff == *local->pattern_ptr){
            func_80387410(sp30);
        }
        else{
            organMinigame_getKeyPosition(*local->pattern_ptr, sp30);
            sp30[0] += local->unkC[0];
            sp30[1] += local->unkC[1];
            sp30[2] += local->unkC[2];
        }//L80387880

        sp3C[0] = sp30[0] - this->position_x;
        sp3C[1] = sp30[1] - this->position_y;
        sp3C[2] = sp30[2] - this->position_z;
        if(LENGTH_VEC3F(sp3C) < 5.0f){
            if(*local->pattern_ptr == 0xff){
                chMotzhand_setState(this, 1);
            }
            else{
                chMotzhand_setState(this, 3);
            }
        }
        else{//L80387930
            ml_vec3f_set_length(sp3C, ((local->unk8 == TRUE) ? 150.0f : 225.0f)*sp48);
            this->position_x = sp3C[0] + this->position_x;
            this->position_y = sp3C[1] + this->position_y;
            this->position_z = sp3C[2] + this->position_z;
        }
    }//L803879A4

    if(this->state == 3){
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            func_80389D9C(*local->pattern_ptr);
            if(local->unk9){
                while(*local->pattern_ptr != 0xff){
                    *local->pattern_ptr++; //find_seq end
                }
                local->unk9 = FALSE;
            }
            else{//L80387A18
                *local->pattern_ptr++;
            }
            chMotzhand_setState(this, 2);
        }
    }//L80387A2C

    if(this->state == 4){
        local->alpha -= 0.25*sp48;
        if(local->alpha  <= 0.0f){
            chMotzhand_setState(this, 5);
        }
    }
}
