#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802C4218(s32, s32, s32, s32);
extern f32 func_80257204(f32, f32, f32, f32);
extern ActorProp * func_80320EB0(ActorMarker *, f32, s32);

void chClam_update(Actor *this);

/* .data */
ActorAnimationInfo chClamAnimations[] = {
    {0x00, 0.0f},
    {ASSET_AA_ANIM_CLAM_IDLE, 2.0f},
    {ASSET_24_ANIM_CLAM_HOP,  1.0f},
    {ASSET_AB_ANIM_CLAM_EAT,  0.6f}
};

ActorInfo chClam = { 
    MARKER_15_CLAM, ACTOR_69_CLAM, ASSET_351_MODEL_CLAM,
    0x1, chClamAnimations,
    chClam_update, func_80326224, actor_draw, 
    4500, 0x366, 1.6f, 0
};


/* .code */
void __chClam_func_803863F0(enum sfx_e sfx_id, f32 arg1, s32 arg2, f32 position[3], f32 arg4, f32 arg5){
    if(func_803114B0()){
        arg2 -= 10000;
        if(arg2 < 0)
            arg2 = 0;
    }
    func_8030E878(sfx_id, arg1, arg2, position, arg4, arg5);
}

void __chClam_func_80386454(Actor *this){
    subaddie_set_state_with_direction(this, 1, 0.01f, 1);
    actor_loopAnimation(this);
    animctrl_setDuration(this->animctrl, randf2(1.9f, 2.1f));
}

bool __chClam_updateTarget(Actor *this, f32 arg1) {
    f32 egg_dist;
    f32 red_feather_dist;
    f32 pad;
    Actor *red_feather;
    Actor *egg;
    f32 phi_f2;
    f32 target_position[3];
    s32 sp38;

    red_feather = actorArray_findClosestActorFromActorId(this->position, ACTOR_52_BLUE_EGG, -1, &egg_dist);
    egg = actorArray_findClosestActorFromActorId(this->position, ACTOR_129_RED_FEATHER, -1, &red_feather_dist);
    sp38 = 0;
    if( (red_feather_dist < egg_dist) 
        && (red_feather_dist < 16000.0f) 
        && (egg != 0)
        && func_80307258(egg->position, this->unk10_25 - 1, this->unk10_18 - 1) != -1
    ) {
            target_position[0] = egg->position[0];
            target_position[1] = egg->position[1];
            target_position[2] = egg->position[2];
            phi_f2 = red_feather_dist;
    }
    else if(
        (egg_dist < red_feather_dist) 
        && (egg_dist < 16000.0f) 
        && (red_feather != 0)
        && func_80307258(red_feather->position, this->unk10_25 - 1, this->unk10_18 - 1) != -1
    ){
            target_position[0] = red_feather->position[0];
            target_position[1] = red_feather->position[1];
            target_position[2] = red_feather->position[2];
            phi_f2 = egg_dist;
    }
    else if ((func_80329530(this, 1200) != 0) && (func_803292E0(this) != 0)) {
        phi_f2 = gu_sqrtf((f32) func_8032970C(this));
        player_getPosition(target_position);
        sp38 = 1;
    }
    else{
        return FALSE;
    }

    this->unk28 = phi_f2 / arg1;
    this->yaw_ideal = func_80257204(this->position[0], this->position[2], target_position[0], target_position[2]);
    if ((func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) ? 0 : 0x11) < this->unk28) {
        this->unk28 = (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) != 0) ? 0.0f : 17.0f;
    } else if (sp38 == 0) {
        __chClam_func_803863F0(SFX_AE_YUMYUM_TALKING, randf2(0.9f, 1.0f), 22000, this->position, 500.0f, 2000.0f);
    }
    return TRUE;

}

bool __chClam_rotateTowardTarget(Actor *this, s32 arg1) {
    f32 temp_f0_2;
    s32 position;
    s32 sp2C;

    if(this->unk10_25 == 0) return FALSE;


    animctrl_setDuration(this->animctrl, 1.0f);
    sp2C = (s32) ((f64) (60.0f / (f32) func_8033DD90()) * 0.5);
    if ((this->unk1C[0] != 0.0f) || !__chClam_updateTarget(this, sp2C)) {
        if (((f64) animctrl_getAnimTimer(this->animctrl) < 0.1) && ((f64) randf() < 0.5)) {
            if (this->unk1C[0] != 0.0f) {
                arg1 *= 2;
                this->unk28 = (f32) randi2(0, 0.5*(func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) ? 0 : 0x11));
                this->yaw_ideal += (f32) randi2(-arg1, arg1);
            } else if ((f64) randf() < 0.4) {
                this->unk28 = 0.0f;
                this->yaw_ideal += (f32) randi2(-arg1, arg1);
            } else {
                this->unk28 = (f32) randi2(0.33 * (func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) ? 0 : 0x11), func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE) ? 0 : 0x11);
                this->yaw_ideal = this->yaw;
            }
            this->unk1C[0] = 0.0f;
        }
        else{
            this->unk1C[0] = 0.0f;
            return FALSE;
        }
    }
    temp_f0_2 = this->unk28 * sp2C;
    this->velocity[1] = ((f32)(0.3*temp_f0_2) / sp2C) - (f32) ((s32) (sp2C * -5) / 2);
    if (func_80329078(this, this->yaw_ideal, temp_f0_2)) {
        return TRUE;
    }
    this->unk1C[0] = 1.0f;
    this->unk28 = 0.0f;
    this->yaw_ideal = this->yaw;
    return FALSE;
}


void __chClam_particalEmitterInit(ParticleEmitter *pCtrl, f32 position[3]){
    particleEmitter_setPosition(pCtrl, position);
    func_802EF9F8(pCtrl, 0.7f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 0.8f, 1.0f);
    particleEmitter_setSfx(pCtrl, SFX_1F_HITTING_AN_ENEMY_3, 10000);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 3.5f, 3.5f);
    particleEmitter_setFade(pCtrl, 0.0f, 0.65f);
    particleEmitter_setDrawMode(pCtrl, 2);
}

void __chClam_emitLargeShellParticles(f32 position[3], s32 count){
    static struct41s D_8038C3F4 = {
        {{-50.0f,   750.0f, -50.0f}, {120.0f,   900.0f, 120.0f}},
        {{  0.0f, -1800.0f,   0.0f}, {  0.0f, -1800.0f,   0.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    __chClam_particalEmitterInit(pCtrl, position);
    particleEmitter_setModel(pCtrl, ASSET_37C_MODEL_CLAM_LARGE_SHELL_PIECE);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C3F4);
    particleEmitter_setAngularVelocityRange(pCtrl, -600.0f, -600.0f, -600.0f, 600.0f, 600.0f, 600.0f);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_emitN(pCtrl, count);
}

void __chClam_emitEyeParticles(f32 position[3], s32 count){
    static struct41s D_8038C424 = {
        {{-80.0f,   400.0f, -80.0f}, {160.0f,   860.0f, 160.0f}},
        {{  0.0f, -1400.0f,   0.0f}, {  0.0f, -1400.0f,   0.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    __chClam_particalEmitterInit(pCtrl, position);
    particleEmitter_setModel(pCtrl, ASSET_37D_MODEL_CLAM_EYE);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C424);
    particleEmitter_setAngularVelocityRange(pCtrl, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB70(pCtrl, 1.0f, 1.0f);
    particleEmitter_emitN(pCtrl, count);
}

void __chClam_emitSmallShellParticles(f32 position[3], s32 count){
    static struct41s D_8038C454 = {
        {{-200.0f,  850.0f, -200.0f}, {400.0f,  1000.0f, 400.0f}},
        {{  0.0f, -1800.0f,    0.0f}, {  0.0f, -1800.0f,   0.0f}}
    };
    ParticleEmitter *pCtrl;

    pCtrl = partEmitMgr_newEmitter(count);
    __chClam_particalEmitterInit(pCtrl, position);
    particleEmitter_setModel(pCtrl, ASSET_37E_MODEL_CLAM_SMALL_SHELL_PIECE);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C454);
    particleEmitter_setAngularVelocityRange(pCtrl, -800.0f, -800.0f, -800.0f, 800.0f, 800.0f, 800.0f);
    func_802EFB70(pCtrl, 0.5f, 0.8f);
    particleEmitter_emitN(pCtrl, count);
}

void __chClam_emitEatencollectibleParticles(f32 position[3], enum asset_e sprite_id, s32 count){
    static struct31s D_8038C484 = {
    {0.2f,  0.35f},
    {0.0f,  0.0f},
    {0.0f,  0.01f},
    {0.45f, 0.45f},
     0.0f,  0.5f
    };

    static struct41s D_8038C4AC = {
        {{-340.0f,   100.0f, -340.0f}, {340.0f,   250.0f, 340.0f}},
        {{   0.0f, -1200.0f,    0.0f}, {  0.0f, -1200.0f, 0.0f}}
    };

    ParticleEmitter *pCtrl;
    
    pCtrl = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(pCtrl, sprite_id);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setVelocityAndAccelerationRanges(pCtrl, &D_8038C4AC);
    func_802EFB98(pCtrl, &D_8038C484);
    particleEmitter_emitN(pCtrl, count);
}

void __chClam_takeDamage(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this;

    this = marker_getActor(this_marker);
    this->marker->collidable = FALSE;
    this->unk138_27 = TRUE;
    __chClam_func_803863F0(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 26000, this->position, 1500.0f, 2000.0f);
    __chClam_func_803863F0(SFX_115_BUZZBOMB_DEATH, 1.2f, 26000, this->position, 1500.0f, 2000.0f);
    __chClam_emitLargeShellParticles(this->position, 2);
    __chClam_emitEyeParticles(this->position, 2);
    __chClam_emitSmallShellParticles(this->position, 0xC);
    func_803115C4(0xa14);
    marker_despawn(this->marker);
}

void __chClam_playerDropsItem(s32 index, enum item_e item_id){
    f32 position[3];

    player_getPosition(position);
    func_802C8F70(randf2(0.0f, 359.0f));
    __spawnQueue_add_4((GenFunction_4)func_802C4218, index, reinterpret_cast(s32, position[0]), reinterpret_cast(s32, position[1]), reinterpret_cast(s32, position[2]));
    item_dec(item_id);
}

void __chClam_attackOther(ActorMarker *this_marker, ActorMarker *other_marker){
    
    if(func_80297C6C() == 3) return;

    if( !mapSpecificFlags_get(5) && func_80311480(0xA14, 0, NULL, NULL, NULL, NULL)){
        mapSpecificFlags_set(5, TRUE);
    }

    if(item_getCount(ITEM_D_EGGS) != 0)
        __chClam_playerDropsItem(0xe, ITEM_D_EGGS);

    if(item_getCount(ITEM_F_RED_FEATHER) != 0)
        __chClam_playerDropsItem(0xf, ITEM_F_RED_FEATHER);
}

void chClam_update(Actor *this){
    ActorProp *sp4C = func_80320EB0(this->marker, 30.0f, 1);
    f32 sp48;
    s32 sp44;
    f32 sp38[3];

    if(!this->initialized){
        this->initialized = TRUE;
        animctrl_setDuration(this->animctrl, 2.0f);
    }

    if(!this->unk16C_4){
        this->unk16C_4 =  TRUE;
        marker_setCollisionScripts(this->marker, NULL, __chClam_attackOther, __chClam_takeDamage);
    }

    if(this->state != 3){
        sp48 = func_80309724(this->position);
        if(sp4C != NULL){
            sp44 = sp4C->marker->unk14_20;
        }

        if(sp44 == MARKER_60_BLUE_EGG_COLLECTIBLE || sp44 == MARKER_B5_RED_FEATHER_COLLECTIBLE){
            if(this->position_y <= sp48 + 15.0f && sp48 - 15.0f <= this->position_y){
                this->position_y = sp48;
                this->unk38_31 = sp44;
                subaddie_set_state_with_direction(this, 3, 0.01f, 1);
                actor_loopAnimation(this);
                this->velocity_x = 0.0f;
                animctrl_setDuration(this->animctrl, 0.6f);
                marker_despawn(sp4C->marker);
            }
        }//L80387140
    }//L80387144

    switch(this->state){
        case 1://L80387170
            if(__chClam_rotateTowardTarget(this, 140)){
                subaddie_set_state_with_direction(this, 2, 0.01f, 1);
                actor_playAnimationOnce(this);
                animctrl_setDuration(this->animctrl, 1.0f);
                __chClam_func_803863F0(SFX_3F2_UNKNOWN, randf2(1.0f, 1.1f), 22000, this->position, 1500.0f, 2000.0f);
            }
            else{
                animctrl_setDuration(this->animctrl, 2.0f);
            }
            break;
            
        case 2://L8038720C
            this->position_y += this->velocity_y;
            this->velocity_y += -5.0f;
            if(actor_animationIsAt(this, 0.63f)){
                __chClam_func_803863F0(SFX_80_YUMYUM_CLACK, 1.0f, 20000, this->position, 1500.0f, 2000.0f);
            }

            if(this->position_y <= sp48){
                this->position_y = sp48;
                if(actor_animationIsAt(this, 0.99f) || 0.98 < animctrl_getAnimTimer(this->animctrl)){
                    __chClam_func_80386454(this);
                }
            }
            else{//L803872D4
                if(!func_80329054(this, 0)){
                    this->unk1C[0] = 1.0f;
                }
            }
            break;

        case 3://L803872F0
            if(actor_animationIsAt(this, 0.99f)){
                this->velocity_x += 1.0f;
            }

            if(3.0f <= this->velocity_x){
                __chClam_func_80386454(this);
                break;
            }

            if(actor_animationIsAt(this, 0.8f) && 2.0f == this->velocity_x){
                __chClam_func_803863F0(SFX_4B_GULPING, randf2(0.8f, 0.9f), 22000, this->position, 700.0f, 2000.0f);
                break;
            }//L803873C4

            if(!actor_animationIsAt(this, 0.01f)) break;

            if(!this->marker->unk14_21) break;

            __chClam_func_803863F0(SFX_4C_LIP_SMACK, 1.0f, 20000, this->position, 500.0f, 2000.0f);
            func_8034A174(this->marker->unk44, 5, sp38);

            switch(this->unk38_31){
                case MARKER_60_BLUE_EGG_COLLECTIBLE:
                    __chClam_emitEatencollectibleParticles(sp38, ASSET_718_SPRITE_SPARKLE_WHITE_2, 8);
                    break;
                case MARKER_B5_RED_FEATHER_COLLECTIBLE:
                    __chClam_emitEatencollectibleParticles(sp38, ASSET_715_SPRITE_SPARKLE_RED, 8);
                    break;
            }
            break;
    }
    func_80328FB0(this, 5.0f);
}
