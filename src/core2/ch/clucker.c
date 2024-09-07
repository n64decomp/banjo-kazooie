#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8033A45C(s32, s32);

typedef struct{
    u8 unk0;
    // u8 pad1[3];
    f32 unk4;
} ActorLocal_Clucker;

Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8035765C(Actor *this);

/* .data */
extern ActorInfo D_80372870 = { 
    MARKER_1B2_CLUCKER_A, ACTOR_29F_CLUCKER, ASSET_482_MODEL_CLUCKER, 
    0, NULL, 
    func_8035765C, NULL, func_803575B8,
    0, 0, 0.0f, 0
};

/* .code */
void __clucker_setDeathCutsceneCamera(Actor *this){
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    sp1C[0] = 50.0f;
    sp1C[1] = 200.0f;
    sp1C[2] = 300.0f;
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, this->yaw);

    sp34[0] = sp1C[0] + this->position_x;
    sp34[1] = sp1C[1] + this->position_y;
    sp34[2] = sp1C[2] + this->position_z;
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, 10.0f);

    sp34[0] += 3.0f*sp1C[0];
    sp34[1] += 3.0f*sp1C[1];
    sp34[2] += 3.0f*sp1C[2];

    sp28[0] = -50.0f;
    sp28[1] = this->yaw + 20.0f;
    sp28[2] = 0.0f;
    ncStaticCamera_setPositionAndRotation(sp34, sp28);
}

void func_80357264(Actor *this, s32 next_state){
    ActorLocal_Clucker *local  = (ActorLocal_Clucker *)&this->local;
    f32 sp38;
    s32 pad34;

    this->marker->id = MARKER_1D0_CLUCKER_B;
    actor_collisionOff(this);
    if(next_state == 1 || next_state == 2){
        skeletalAnim_set(this->unk148, ASSET_184_ANIM_CLUCKER_ATTACK_SHORT, 0.0f, 2.5f);
        skeletalAnim_setProgress(this->unk148, 0.99f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_4_STOPPED);
        if(this->state == 4){
            if(local->unk0 == 2){
                local->unk4 = randf2(0.5f, 0.75f);
            }
            else{//L8035732C
                local->unk4 = randf2(0.25f, 0.35f);
            }//L8035734C
        }
        else{//L80357358
            local->unk4 = 0.0f;
        }
    }//L80357368

    if(this->state == 1 && next_state == 2)
        local->unk0 = -1;

    if(next_state == 3)
        local->unk4 = 0.2f;

    if(next_state == 4){
        this->marker->id = MARKER_1B2_CLUCKER_A;
        actor_collisionOn(this);
        local->unk0 = (local->unk0 + 1) % 3; 
        if(local->unk0 < 2)
            skeletalAnim_set(this->unk148, ASSET_184_ANIM_CLUCKER_ATTACK_SHORT, 0.0f, randf2( 0.6f, 1.0f));
        else
            skeletalAnim_set(this->unk148, ASSET_185_ANIM_CLUCKER_ATTACK_LONG, 0.0f, randf2( 2.3f, 2.7f));
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        func_8030E6A4(SFX_4A_CLUCKER_AHH, randf2(0.85f, 0.95f), 32000);
    }

    if(next_state == 5){
        if(!levelSpecificFlags_get(0x14)
            && !( actorArray_findClosestActorFromActorId(this->position, 0x318, -1, &sp38) && ( sp38 < 250.0f))
        ){
            levelSpecificFlags_set(0x14, TRUE);
            func_80324E38(0.0f, 3);
            __clucker_setDeathCutsceneCamera(this);
            timed_exitStaticCamera(2.0f);
            func_80324E38(2.0f, 0);
        }//L80357518
        func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
        skeletalAnim_set(this->unk148, ASSET_186_ANIM_CLUCKER_DIE, 0.05f, 2.0f);
    }//L80357540

    this->state = next_state;
}

void func_80357564(ActorMarker *this_marker, ActorMarker *other_marker){
    func_8030E6D4(SFX_1E_HITTING_AN_ENEMY_2);
}

void func_8035758C(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_80357264(this, 5);
}

Actor *func_803575B8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);

    func_8033A45C(3, (this->state == 5)? 1 : 0);
    func_8033A45C(4, (this->state == 0 || this->state == 1 || this->state == 6)? 0 : 1);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_8035765C(Actor *this){
    f32 sp5C[3];
    f32 sp58;
    ActorLocal_Clucker *local  = (ActorLocal_Clucker *)&this->local;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;

    sp50 = time_getDelta();
    if( !this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->unk16C_0 = TRUE;
        if(this->state != 6){
            marker_setCollisionScripts(this->marker, NULL, func_80357564, func_8035758C);
            local->unk0 = 0xff;
            func_80357264(this, 1);
        }
        else{//L803576E0
            func_80357264(this, 6);
        }
    }//L803576EC

    player_getPosition(sp5C);
    sp58 = ml_distance_vec3f(this->position, sp5C);
    if(this->state == 1){
        if(sp58 < this->scale*800.0f){
            func_80357264(this, 2);
        }
    }//L80357758

    if(this->state == 2){
        if(0.0f < local->unk4){
            local->unk4 -= sp50;
        }
        else if(sp58 < this->scale*600.0f){
            func_80357264(this, 3);
        }
        else if(this->scale*1000.0f < sp58){//L803577DC
            func_80357264(this, 1);
        }
    }//L80357808

    if(this->state == 3){
        if(ml_timer_update(&local->unk4, sp50)){
            func_80357264(this, 4);
        }
    }

    if(this->state == 4){
        skeletalAnim_getProgressRange(this->unk148, &sp4C, &sp48);
        if(skeletalAnim_getAnimId(this->unk148) == 0x185){
            if(sp4C < 0.58 && 0.58 <= sp48){
                this->marker->id = MARKER_1D0_CLUCKER_B;
            }
            if(sp4C < 0.05 && 0.05 <= sp48){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 0.9f, 32000);
            }
            if( (sp4C < 0.11 && 0.11 <= sp48)
                || (sp4C < 0.32 && 0.32 <= sp48)
                || (sp4C < 0.53 && 0.53 <= sp48)
            ){
                func_8030E6A4(SFX_80_YUMYUM_CLACK, randf2(0.75f, 0.95f), 32700);
            }
            if(sp4C < 0.9 && 0.9 <= sp48){
                func_8030E6D4(SFX_2_CLAW_SWIPE);
            }
        }
        else{//L803579F0
            if(sp4C < 0.63 && 0.63 <= sp48){
                this->marker->id = MARKER_1D0_CLUCKER_B;
            }
            if(sp4C < 0.1 && 0.1 <= sp48){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 0.9f, 32000);
            }
            if(sp4C < 0.5 && 0.5 <= sp48){
                func_8030E6A4(SFX_80_YUMYUM_CLACK, randf2(0.75f, 0.95f), 32700);
            }
            if(sp4C < 0.9 && 0.9 <= sp48){
                func_8030E6D4(SFX_2_CLAW_SWIPE);
            }
        }//L80357B30
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            func_80357264(this, 2);
        }
    }//L80357B48

    if(this->state == 5){
        skeletalAnim_getProgressRange(this->unk148, &sp44, &sp40);
        if(sp44 < 0.1 && 0.1 <= sp40){
            func_8030E6A4(SFX_68_CLUCKER_AAEEGHH, randf2(1.0f, 1.1f), 32000);
        }

        if(sp44 < 0.7 && 0.7 <= sp40){
            func_8030E6D4(SFX_61_CARTOONY_FALL);
        }
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            func_80357264(this, 6);
        }
    }
}
