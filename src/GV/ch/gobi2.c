#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    u8 pad0[4];
    SkeletalAnimation  *unk4;
    BKModelBin *unk8;
}ActorLocal_Gobi2;

void chGobi2_setState(Actor *this, s32 next_state);
void chGobi2_update(Actor *this);
Actor *chGobi2_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chGobi2 = { MARKER_BF_GOBI_2, ACTOR_131_GOBI_2, ASSET_3E0_MODEL_GOBI, 
    0x0, NULL, 
    NULL, chGobi2_update, chGobi2_draw, 
    0, 0x533, 0.0f, 0
};

/* .bss */
u8 D_80391A50;

/* .code */
void GV_func_80387960(void){
    static f32 D_80390CD4[3] = {1475.0f, 442.0f, 8870.0f};
    func_8028F490(D_80390CD4);
}

void func_80387984(ActorMarker *this){
    mapSpecificFlags_set(0xC, 1);
}

void __chGobi2_spawnJIggy(void){
    static f32 jiggy_position[3] = {1150.0f, 1150.0f, 9200.0f};
    jiggy_spawn(JIGGY_45_GV_GOBI_2, jiggy_position);
}

void func_803879D4(ActorMarker *this_marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, this_marker));
    chGobi2_setState(this, 4);
}

void GV_func_80387A00(ActorMarker *this_marker){
    Actor *this = marker_getActor(reinterpret_cast(ActorMarker *, this_marker));
    chGobi2_setState(this, 7);
}

void func_80387A2C(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    timed_setStaticCameraToNode(0.0f, 0xC);
    timedFunc_set_1(0.5f, (GenFunction_1) func_80387984, reinterpret_cast(s32, caller));
    timed_playSfx(0.5f, SFX_2C_PULLING_NOISE, 0.9f, 32000);
    timed_playSfx(1.8f, SFX_2C_PULLING_NOISE, 1.0f, 32000);
    timed_playSfx(2.5f, SFX_2C_PULLING_NOISE, 1.1f, 32000);
    timed_setStaticCameraToNode(3.0f, 0xd);
    timedFunc_set_0(3.5f, __chGobi2_spawnJIggy);
    timed_exitStaticCamera(6.0f);
    timedFunc_set_1(6.0f, (GenFunction_1) GV_func_80387A00, reinterpret_cast(s32, caller));
    func_80324E38(6.0f, 0);
}

void chGobi2_setState(Actor *this, s32 next_state){
    static f32 D_80390CEC[3] = {1145.0f, 443.0f, 9197.0f};

    ActorLocal_Gobi2 *local = (ActorLocal_Gobi2 *)&this->local;

    if(next_state == 1)
        actor_collisionOff(this);

    if(this->state == 1)
        actor_collisionOn(this);

    if(next_state == 2){
        this->marker->propPtr->unk8_3 = TRUE;
        skeletalAnim_set(this->unk148, ASSET_F4_ANIM_GOBI_IDLE, 0.5f, 12.0f);
    }

    if(next_state == 3){
        timedFunc_set_0(0.05f, GV_func_80387960);
        timed_playSfx(0.05f, SFX_84_GOBI_CRYING, 1.1f, 32000);
        func_80324E38(0.051f, 1);
        timedFunc_set_1(0.06f, (GenFunction_1)func_803879D4, reinterpret_cast(s32, this->marker));
        timed_setStaticCameraToNode(0.86f, 0xb);
        timed_playSfx(0.8f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(1.4f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(2.0f, SFX_4B_GULPING, 0.8f, 28000);
        func_80324DBC(3.0f, ASSET_A72_TEXT_TRUNKER_HELPED, 0x2A, D_80390CEC, this->marker, func_80387A2C, NULL);
    }//L80387C94

    if(next_state == 4){
        skeletalAnim_set(this->unk148, ASSET_FC_ANIM_GOBI_SPITTING, 0.2f, 3.0f);
        skeletalAnim_set(local->unk4, ASSET_100_ANIM_GOBI_SPIT, 0.0f, 3.0f);
    }

    if(next_state == 5){
        skeletalAnim_set(this->unk148, ASSET_FD_ANIM_GOBI2_GETTING_UP, 0.43f, 0.5f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
    }

    if(next_state == 6){
        skeletalAnim_set(this->unk148, ASSET_F8_ANIM_GOBI_RUNNING, 0.4f, 0.71f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }

    if(next_state == 7){
        marker_despawn(this->marker);
    }

    if(next_state == 8){
        FUNC_8030E8B4(SFX_84_GOBI_CRYING, 0.9f, 20000, this->position, 1500, 2500);
        skeletalAnim_set(this->unk148, ASSET_242_ANIM_GOBI_RELAXING, 0.2f, 0.5f);
    }

    this->state = next_state;
}

Actor *chGobi2_draw(ActorMarker *this_marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(this_marker);
    ActorLocal_Gobi2 *local = (ActorLocal_Gobi2 *)&this->local;
    f32 sp3C[3];

    if(this->state == 0 || this->state == 1){
        return this;
    }

    if(this->state == 6)
        func_8033A280(2.0f);

    sp3C[0] = this->pitch;
    sp3C[1] = this->yaw;
    sp3C[2] = this->roll;
    modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(this->unk148));
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_draw(gfx, mtx, this->position, sp3C, 1.0f, NULL, func_80330B1C(this_marker));

    if(this->state == 4){
        modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(local->unk4));
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_draw(gfx, mtx, this->position, sp3C, 1.0f, NULL, local->unk8);
    }
    return this;
}


void __chGobi2_80387EFC(Actor *this){
    ActorLocal_Gobi2 *local = (ActorLocal_Gobi2 *)&this->local;

    chGobi2_setState(this, 0);
    skeletalAnim_free(local->unk4);
    assetcache_release(local->unk8);

}

void __chGobi2_ow(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    enum hitbox_e hitbox;
    hitbox = player_getActiveHitbox(NULL);
    if(hitbox  == HITBOX_1_BEAK_BUSTER)
        D_80391A50 = TRUE;
    else if(hitbox == HITBOX_A_FAST_FALLING){
        this->unk1C[0] = 1.0f;
    }
}

void chGobi2_update(Actor *this){
    ActorMarker *sp34;
    ActorLocal_Gobi2 *local = (ActorLocal_Gobi2 *)&this->local;
    f32 sp2C;

    sp34 = this->marker;
    sp2C = time_getDelta();
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, __chGobi2_ow, NULL, NULL);
        sp34->unk30 = __chGobi2_80387EFC;
        local->unk4 = skeletalAnim_new();
        local->unk8 = (BKModelBin*) assetcache_get(ASSET_3F3_MODEL_GOBI_SPIT);
        D_80391A50 = 0;
        this->unk1C[0] = 0.0f;
        this->unk1C[1] = 0.0f;
        chGobi2_setState(this, 1);
        if(jiggyscore_isSpawned(JIGGY_45_GV_GOBI_2))
            marker_despawn(this->marker);
        return;
    }//L80388060

    if(this->state == 1){
        if(jiggyscore_isCollected(JIGGY_44_GV_GOBI_1))
            chGobi2_setState(this, 2);
    }

    if(this->state == 2){
        if(this->unk1C[0] != 0.0f && this->unk1C[1] == 0){
            chGobi2_setState(this, 8);
        }
        else if(D_80391A50){
            chGobi2_setState(this, 3);
        }
    }//L80388114

    if(this->state == 2){
        if(!this->unk138_24){
            if(func_80329530(this, 0xFA) && !func_80329530(this, 0x50)){
                if(func_8028F2A0()){
                    if(func_80311480(ASSET_A75_TEXT_GOBI2_MEET, 0, this->position, NULL, NULL, NULL))
                        this->unk138_24 = TRUE;
                }
            }
        }
    }//L80388194

    if(this->state == 4){
        skeletalAnim_update(local->unk4, sp2C, 1);
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chGobi2_setState(this, 5);
        }
    }

    if(this->state == 5){
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chGobi2_setState(this, 6);
        }
    }

    if(this->state == 6){
        func_80326224(this);
    }

    if(this->state == 8){
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            chGobi2_setState(this, 2);
        }
    }
    D_80391A50 = FALSE;
    this->unk1C[1] = this->unk1C[0];
    this->unk1C[0] = 0.0f;
}
