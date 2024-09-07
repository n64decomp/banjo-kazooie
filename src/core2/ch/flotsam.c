#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80309724(f32[3]);

typedef struct {
    f32 unk0;
    f32 unk4;
    ParticleEmitter *pCtrl_8;
    u8 unkC;
    u8 unkD;
    //u8 padE[2];
    f32 unk10[3];
    f32 unk1C[3];
    f32 unk28[3];
    f32 unk34[3];
}ActorLocal_Core2_D50F0;


void    func_8035C8F4(Actor *this);
Actor*  func_8035C71C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo D_80372C80 = { 
    MARKER_C9_FLOTSAM, ACTOR_13B_FLOTSAM, ASSET_401_MODEL_FLOTSAM, 
    0, NULL, 
    func_8035C8F4, NULL, func_8035C71C, 
    0, 0, 1.0f, 0
};

ParticleScaleAndLifetimeRanges D_80372CA4 = {
    {1.0f, 1.2f},
    {1.6f, 2.0f},
    {0.05f, 0.05f},
    {0.3f, 0.5f},
    0.1f, 0.5f
};

struct43s D_80372CCC = {
    {{-5.0f, 10.0f, -5.0f}, {5.0f, 50.0f, 5.0f}}, 
    {{0.0f, 200.0f, 0.0f}, {0.0f, 1000.0f, 0.0f}},
    {{-20.0f, -20.0f, -20.0f}, {20.0f, 20.0f, 20.0f}}
};

/* .code */
void func_8035C080(Actor *this, s32 next_state){
    f32 i;
    ActorLocal_Core2_D50F0 *local = (ActorLocal_Core2_D50F0 *)&this->local; //sp60
    f32 sp64[3];
    f32 sp60;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    s32 sp38;

    local->unk0 = 0.0f;
    local->unkD = next_state;
    
    if(next_state == 1){
        skeletalAnim_set(this->unk148, 0, 0.0f, 0.0f);
        this->yaw = local->unk34[0];
    }
    if( next_state == 3
        || next_state == 4
        || next_state == 7
        || next_state == 6
    ){
        skeletalAnim_set(this->unk148, ASSET_132_ANIM_FLOTSAM_MOVE, 0.1f, 0.7f);
        local->unk10[0] = this->position_x;
        local->unk10[1] = this->position_y;
        local->unk10[2] = this->position_z;
        actor_collisionOn(this);
        if(next_state == 3){
            player_getPosition(sp54);
        }
        else if(next_state == 4){//L8035C15C
            sp54[0] = local->unk28[0];\
            sp54[1] = local->unk28[1];\
            sp54[2] = local->unk28[2];
        }
        else if(next_state == 6){//L8035C180
            func_8030E6D4(SFX_1D_HITTING_AN_ENEMY_1);
            actor_collisionOff(this);
            player_getPosition(sp48);
            sp3C[0] = this->position_x - sp48[0];
            sp3C[1] = this->position_y - sp48[1];\
            sp3C[2] = this->position_z - sp48[2];\
            sp3C[1] = 0.0f;
            ml_vec3f_set_length(sp3C, 150.0f);
            sp54[0] = sp3C[0] + this->position_x;\
            sp54[1] = sp3C[1] + this->position_y;\
            sp54[2] = sp3C[2] + this->position_z;
            sp54[1] = local->unk4;
        }
        else{//L8035C228
            sp54[0] = this->position_x;\
            sp54[1] = this->position_y;\
            sp54[2] = this->position_z;
        } //L8035C240
        sp64[0] = sp54[0] - this->position_x;\
        sp64[1] = sp54[1] - this->position_y;\
        sp64[2] = sp54[2] - this->position_z;
        sp64[1] = 0.0f;
        sp60 = gu_sqrtf(sp64[0]*sp64[0] + sp64[1]*sp64[1] + sp64[2]*sp64[2]);

        if(next_state == 4 && sp60 <= 250.0f){
            local->unk1C[0] = sp54[0];\
            local->unk1C[1] = sp54[1];\
            local->unk1C[2] = sp54[2];
            next_state = 5;
        }
        else{//L8035C2DC
            if(this->state == 2){
                if(300.0f < sp60){
                    ml_vec3f_set_length(sp64, 300.0f);
                }
            }
            else{
                if(150.0f < sp60){
                    ml_vec3f_set_length(sp64, 150.0f);
                }
            }////L8035C344
            for(i = 1; 0.025 < i; i -= 0.05){//L8035C378
                local->unk1C[0] = sp64[0] *i + this->position_x; 
                local->unk1C[1] = local->unk4;
                local->unk1C[2] = sp64[2] *i + this->position_z; 
                if(func_80329210(this, local->unk1C)){
                    next_state = 5;
                    break;
                }
            }
        }//L8035C3F8

        if(next_state == 5){
            func_8030E878(0x3f2, randf2(1, 1.2f), 0x7530, this->position, 100.0f, 10000.0f);
            local->unk34[1] = this->yaw;
            if(sp60 <= 250.0f){
                local->unk34[2] = local->unk34[0];
            }
            else if(local->unk34[0] < local->unk34[1]){//L8035C47C
                local->unk34[2] = local->unk34[0] - 20.0f;
            }
            else{//L8035C4B0
                local->unk34[2] = local->unk34[0] + 20.0f;
            }
        }
        else if(next_state == 3){//L8035C4C0
            if(ml_distance_vec3f(local->unk28, this->position) < 10.0f){
                func_8035C080(this, 1);
                return;
            }
            else{
                func_8035C080(this, 4);
                return;
            }
        }
        else if(next_state == 4){//L8035C514
            local->unk1C[0] = sp54[0];
            local->unk1C[1] = sp54[1];
            local->unk1C[2] = sp54[2];
            next_state = 5;
        }
        else if(next_state == 7){//L8035C540
            func_8035C080(this, 4);
            return;
        }
    }//L8035C560

    if(next_state == 8){
        actor_collisionOff(this);
        FUNC_8030E624(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 25000);
        timed_playSfx(0.2f, SFX_103_FLOTSAM_DEATH, 1.0f, 32000);
        sp38 = func_802F9AA8(SFX_104_PROPELLER_NOISE);
        func_802F9DB8(sp38, 1.0f, 1.3f, 0.05f);
        func_802F9EC4(sp38, this->position, 0x5dc, 0x9c4);
        func_802F9F80(sp38, 0.0f, 2.0f, 2.0f);
        func_802FA060(sp38, 0x6590, 0x6d60, 500.0f);
        skeletalAnim_set(this->unk148, ASSET_189_ANIM_FLOTSAM_DIE, 0.1f, 4.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        local->pCtrl_8 = particleEmitter_new(20);
        particleEmitter_setSprite(local->pCtrl_8, ASSET_70E_SPRITE_SMOKE_2);
        particleEmitter_setStartingFrameRange(local->pCtrl_8, 0, 7);
        particleEmitter_setPosition(local->pCtrl_8, this->position);
        particleEmitter_setPositionVelocityAndAccelerationRanges(local->pCtrl_8, &D_80372CCC);
        particleEmitter_setScaleAndLifetimeRanges(local->pCtrl_8, &D_80372CA4);
        particleEmitter_setSpawnInterval(local->pCtrl_8, 4);
    }//L8035C698

    this->state = next_state;

}

void func_8035C6C4(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_8035C080(this, 6);
}

void func_8035C6F0(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);
    func_8035C080(this, 8);
}

Actor*  func_8035C71C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker); //sp64
    ActorLocal_Core2_D50F0 *local = (ActorLocal_Core2_D50F0 *)&this->local; //sp60
    s32 sp5C;
    s32 pad58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    if(this->state == 0) return this;

    if(this->state == 8){
        sp5C = skeletalAnim_getBoneTransformList(this->unk148);
        if(sp5C){
            sp40[0] = 0.0f;
            sp40[1] = 0.0f;
            sp40[2] = local->unk0 * -2200.0f;
            func_80345C78(sp4C, sp40);
            func_8033A8F0(sp5C, 3, sp4C);
            sp34[0] = 1.0  - local->unk0*0.5;
            sp34[1] = 1.0  - local->unk0*0.5;
            sp34[2] = 1.0  - local->unk0*0.5;
            boneTransformList_setBoneScale(sp5C, 3, sp34);
        }
    }

    if(local->pCtrl_8){
        func_8033A450(func_80329934());
    }
    
    actor_draw(marker, gfx, mtx, vtx);

    if(local->pCtrl_8 && this->marker->unk14_21){
        func_8034A174(func_80329934(), 5, sp28);
        particleEmitter_setPosition(local->pCtrl_8, sp28);
        particleEmitter_draw(local->pCtrl_8, gfx, mtx, vtx);
    }
    return this;
}

void func_8035C8C8(Actor *this){
    ActorLocal_Core2_D50F0 *local = (ActorLocal_Core2_D50F0 *)&this->local;

    if(local->pCtrl_8)
        particleEmitter_free(local->pCtrl_8);
}

void func_8035C8F4(Actor *this){
    f32 plyr_pos[3];
    f32 sp40[3];
    f32 sp3C;
    ActorLocal_Core2_D50F0 *local = (ActorLocal_Core2_D50F0 *)&this->local;
    f32 sp34;

    sp34 = time_getDelta();
    if(this->state == 0){
        this->marker->unk14_21 = FALSE;
        this->marker->unk30 = func_8035C8C8;
        marker_setCollisionScripts(this->marker, func_8035C6C4, func_8035C6C4, func_8035C6F0);
        local->unk4 = func_80309724(this->position);
        local->pCtrl_8 = NULL;
        local->unk34[0] = this->yaw;
        local->unk34[2] = local->unk34[1] = local->unk34[0];
        local->unk28[0] = this->position_x;
        local->unk28[1] = this->position_y;
        local->unk28[2] = this->position_z;
        func_8035C080(this, 1);
    }//L8035C9AC

    player_getPosition(plyr_pos);
    sp40[0] = plyr_pos[0] - this->position_x;
    sp40[1] = plyr_pos[1] - this->position_y;
    sp40[2] = plyr_pos[2] - this->position_z;
    sp3C = gu_sqrtf(sp40[0]*sp40[0] + sp40[1]*sp40[1] + sp40[2]*sp40[2]);
    if(local->pCtrl_8){
        particleEmitter_update(local->pCtrl_8);
    }

    if(this->state == 1){
        if( sp3C < 800.0f 
            && func_80329210(this, plyr_pos)
            && plyr_pos[1] < this->position_y + 100.0f
        ){
            func_8035C080(this, 3);
        }
    }//L8035CA80

    if(this->state == 5){
        local->unk0 += 1.9047619047619049*sp34;
        if(1.0f <= local->unk0)
            local->unk0 = 1.0f;
        ml_interpolate_vec3f(this->position, local->unk10, local->unk1C, local->unk0);
        this->position_y += 100.0f*sinf(local->unk0*3.141592654);
        this->yaw = local->unk0*(local->unk34[2] - local->unk34[1]) + local->unk34[1];
        if(skeletalAnim_getLoopCount(this->unk148) > 0){
            if(ml_distance_vec3f(this->position, local->unk28) < 10.0f){
                func_8035C080(this, 1);
            }
            else if(local->unkC > 0){//L8035CB8C
                local->unkC--;
                if(local->unkC > 0){
                    func_8035C080(this, 7);
                }
                else{
                    func_8035C080(this, 2);
                }
            }
            else{
                func_8035C080(this, 2);
            }
        }
    }//L8035CBD4

    if(this->state == 2){
        if(sp3C < 800.0f){
            func_8035C080(this, 3);
        }
        else{
            func_8035C080(this, 4);
        }
    }//L8035CC38

    if(this->state == 8){
        local->unk0 += 0.25*sp34;
        if(skeletalAnim_getLoopCount(this->unk148) > 0)
            marker_despawn(this->marker);
    }
}
