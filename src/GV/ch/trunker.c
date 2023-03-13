#include <ultra64.h>
#include "functions.h"
#include "variables.h"


void chTrucker_update(Actor *this);
Actor *chTrucker_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chTrunker = { 
    MARKER_C0_TRUNKER, ACTOR_132_TRUNKER, ASSET_3DF_MODEL_TRUNKER, 
    0, NULL, 
    chTrucker_update, NULL, chTrucker_draw, 
    0, 0x599, 2.0f, 0
};

/* .code */
void __chTrucker_setState(Actor *this, s32 next_state){
    this->state = next_state;
    if(this->state == 1){
        skeletalAnim_set(this->unk148, ASSET_FE_ANIM_TRUCKER_SHORT, 0.1f, 2.5f);
    }

    if(this->state == 2){
        skeletalAnim_set(this->unk148, ASSET_FF_ANIM_TRUCKER_GROW, 0.1f, 2.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }

    if(this->state == 3){
        skeletalAnim_set(this->unk148, ASSET_FF_ANIM_TRUCKER_GROW, 0.0f, 2.5f);
        skeletalAnim_setProgress(this->unk148, 0.999f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }
}

Actor *chTrucker_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    f32 sp38[3];
    f32 sp2C[3];
    
    if(this->state == 0) return this;

    this = actor_draw(this_marker, gfx, mtx, vtx);
    sp38[0] = this->position_x - 150.0f;
    sp38[1] = this->position_y + 2.0f;
    sp38[2] = this->position_z - 170.0f;
    sp2C[0] = this->pitch;
    sp2C[1] = this->yaw + 220.0f;
    sp2C[2] = this->roll;
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
    modelRender_draw(gfx, mtx, sp38, sp2C, 1.0f, NULL, func_8030A428(3));
    return this;
}


void chTrucker_update(Actor *this){
    ActorMarker *marker = this->marker;
    s32 sp28 = 0;
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        mapSpecificFlags_set(0xC, FALSE);
        if(jiggyscore_isSpawned(JIGGY_45_GV_GOBI_2) && !func_803203FC(1)){
            __chTrucker_setState(this, 3);
        }
        else{//L803891CC
            __chTrucker_setState(this, 1);
        }
    }//L803891D8
    if( this->state == 1
        && !this->unk138_24
        && func_80329530(this, 250)
        && !func_80329530(this, 80)
        && func_8028F2A0()
    ){
        func_80311480(ASSET_A71_TEXT_TRUNKER_MEET, 0xe, this->position, NULL, NULL, NULL);
        this->unk138_24 = 1;
    }//L80389254

    if(this->state == 1 && mapSpecificFlags_get(0xC)){
        sp28 = 2;
    }

    if(this->state == 2 && skeletalAnim_getLoopCount(this->unk148) > 0){
        sp28 = 3;
    }

    if(sp28)
        __chTrucker_setState(this, sp28);
}
