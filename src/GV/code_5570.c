#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8025AE50(s32, f32);

#include "core2/statetimer.h"
extern void player_stateTimer_set(s32, f32);

typedef struct {
    s32 unk0;
}ActorLocal_Grabba;

void GV_func_8038BEA0(Actor *this);

/* .data */
ActorAnimationInfo D_80391120[] ={
    {0x00, 0.0f},
    {ASSET_C5_ANIM_GRABBA_APPEAR,   8000000.0f},
    {ASSET_C5_ANIM_GRABBA_APPEAR,   1.6f},
    {ASSET_C7_ANIM_GRABBA_IDLE,     1.8f},
    {ASSET_C6_ANIM_GRABBA_HIDE,     0.55f},
    {ASSET_C8_ANIM_GRABBA_DEFEATED, 0.8f},
    {ASSET_C7_ANIM_GRABBA_IDLE,     1.8f}
};

ActorInfo D_80391158 = { MARKER_A6_GRABBA, ACTOR_118_GRABBA, ASSET_371_MODEL_GRABBA, 
    0x1, D_80391120, 
    GV_func_8038BEA0, actor_update_func_80326224, actor_draw, 
    0, 0, 0.0f, 0
};

s32 D_8039117C[3] = {160, 100, 0};


/* .bss */
s32 D_80391A80;

/* .code */
void func_8038B960(void){
    func_8025AE50(5000, 3.19f);
}

/* .bss */
extern s32 D_80391A80;

/* .code */
void func_8038B988(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    subaddie_set_state_with_direction(this, 5, 0.01f, 1);
    actor_loopAnimation(this);
    gcStaticCamera_activate(0x13);
    FUNC_8030E624(SFX_8D_BOGGY_OHWW, 0.9f, 32000);
    timedFunc_set_0(2.5f, func_8038B960);
    D_80391A80 = this->state;
}

void func_8038BA08(Actor *this){
    subaddie_set_state_with_direction(this, 6, 0.01f, 1);
    actor_loopAnimation(this);
    this->partnerActor = NULL;
    D_80391A80 = 3;
    if(player_movementGroup() == BSGROUP_6_TURBO_TALON_TRAINERS)
        player_stateTimer_set(STATE_TIMER_3_TURBO_TALON, 0.0f);

    gcdialog_showDialog(ASSET_A79_DIALOG_GRABBA_DEFEAT, 0xf, this->position, this->marker, func_8038B988, NULL);
    comusic_8025AB44(COMUSIC_57_TURBO_TRAINERS, 7000, 700);
}

s32 func_8038BAA4(Actor *jiggy){
    s32 tmp_v0;
    s32 sp18[3];

    gsworld_get_map();
    sp18[0] = (s32)jiggy->position_x;
    sp18[1] = (s32)jiggy->position_y;
    sp18[2] = (s32)jiggy->position_z;
    tmp_v0 = func_80307164(sp18);
    if( tmp_v0 < 0) 
        return 0;
    else
        return func_80306DBC(tmp_v0) + 1;
    
}

int func_8038BB24(Actor *this){
    if(subaddie_playerIsWithinSphereAndActive(this, 1560) && !subaddie_playerIsWithinSphereAndActive(this, 1380)){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void func_8038BB6C(Actor *jiggy, ActorMarker * grabba_marker)
{
    Actor *grabba;
    ActorLocal_Grabba *grabba_local;
    ActorMarker *tmp = reinterpret_cast(ActorMarker *, grabba_marker);
    grabba = marker_getActor(tmp);
    grabba_local = (ActorLocal_Grabba *)&grabba->local;

    grabba->partnerActor = jiggy->marker;
    grabba_local->unk0 = grabba->partnerActor->unk5C;
    jiggy->unk10_1 = TRUE;
    grabba->unk1C[2] = (f32)func_8038BAA4(jiggy);
    if(jiggyscore_isCollected((s32)grabba->unk1C[2])){
        func_8038C748();
        marker_despawn(grabba->marker);
    }
}

void func_8038BBFC(ParticleEmitter *pCtrl, f32 position[3], s32 cnt){
    particleEmitter_setRGB(pCtrl, D_8039117C);
    particleEmitter_setAlpha(pCtrl, 0x96);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    particleEmitter_setFade(pCtrl, 0.0f, 0.01f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
}

void func_8038BC7C(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    func_8038BBFC(pCtrl, position, cnt);
    particleEmitter_setSpawnPositionRange(pCtrl,
        -60.0f,  0.0f, -60.0f,
         60.0f, 30.0f,  60.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -250.0f, 10.0f, -250.0f,
         250.0f, 110.0f, 250.0f
    );
    particleEmitter_setStartingScaleRange(pCtrl, 0.1f, 0.5f);
    particleEmitter_setFinalScaleRange(pCtrl, 2.0f, 2.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 0.5f, 1.4f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038BD8C(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    func_8038BBFC(pCtrl, position, cnt);
    particleEmitter_setSpawnPositionRange(pCtrl,
        -40.0f,  0.0f, -40.0f,
         40.0f, 30.0f,  40.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -100.0f, 20.0f, -100.0f,
         100.0f, 60.0f, 100.0f
    );
    particleEmitter_setStartingScaleRange(pCtrl, 0.1f, 0.5f);
    particleEmitter_setFinalScaleRange(pCtrl, 1.2, 1.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, 0.5f, 1.4f);
    particleEmitter_emitN(pCtrl, cnt);
}

void GV_func_8038BEA0(Actor *this){
    ActorLocal_Grabba *local = (ActorLocal_Grabba *)&this->local;
    f32 sp38[3];

    if(!this->initialized){
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        actor_collisionOff(this);
        this->unk38_31 = 0;
        this->unk1C[1] = this->position_y;
        D_80391A80 = this->state;
        func_80333270(JIGGY_3E_GV_GRABBA, this->position, func_8038BB6C, this->marker);
    }//L8038BF24

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        if(this->unk44_31 == 0){
            this->unk44_31 = sfxsource_createSfxsourceAndReturnIndex();
            sfxsource_setSfxId(this->unk44_31, SFX_3EC_CCW_DOOR_OPENING);
            sfxSource_setunk43_7ByIndex(this->unk44_31, 2);
            sfxsource_playSfxAtVolume(this->unk44_31, 0.1f);
            sfxsource_setSampleRate(this->unk44_31, 32000);
        }
        if(this->partnerActor == NULL){
            this->partnerActor = func_8032B16C(JIGGY_3E_GV_GRABBA);
            local->unk0 =  this->partnerActor != NULL ? this->partnerActor->unk5C : NULL;
        }
        subaddie_set_state_with_direction(this, this->state, 0.01f, 1);
        this->unk58_0 = FALSE;
        this->marker->propPtr->unk8_3 = FALSE;
    }//L8038BFF4

    if(subaddie_playerIsWithinSphere(this, 4000) || this->state == 5){
        this->unk58_0 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        switch(this->state){
            case 1: //L8038C064
                this->unk58_0 = FALSE;
                this->marker->propPtr->unk8_3 = FALSE;
                if(func_8038BB24(this)){
                    subaddie_set_state_with_direction(this, 2, 0.01f, 1);
                    actor_playAnimationOnce(this);
                    this->unk38_31 = 0;
                    D_80391A80 = this->state;
                    func_802BB3DC(0, 14.0f, 0.92f);
                    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32, 0x11f,
                        reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, this->position_y), reinterpret_cast(s32, this->position_z)
                    );
                }
                break;

            case 2: //L8038C108
                if(actor_animationIsAt(this, 0.69f)){
                    subaddie_set_state_with_direction(this, 3, 0.01f, 1);
                    actor_loopAnimation(this);
                    D_80391A80 = this->state;
                    if(this->partnerActor){
                        this->partnerActor->collidable = TRUE;
                    }
                }
                else{
                    if(anctrl_getAnimTimer(this->anctrl) < 0.55){
                        sfxSource_func_8030E2C4(this->unk44_31);
                        if(randf() < 0.6){
                            func_8038BC7C(this->position, 0xA);
                        }
                    }
                }
                break;

            case 3: //L8038C1CC
                if(this->partnerActor && this->partnerActor->unk5C != local->unk0){
                    func_8038BA08(this);
                }
                else if(this->unk38_31 >= 0xC){
                    subaddie_set_state_with_direction(this, 4, 0.01f, 1);
                    actor_playAnimationOnce(this);
                    D_80391A80 = this->state;
                    func_802BB3DC(0, 12.0f, 0.92f);
                }
                else if(subaddie_playerIsWithinSphereAndActive(this, 600)){
                    if(player_movementGroup() == BSGROUP_6_TURBO_TALON_TRAINERS){
                        this->unk38_31++;
                    }
                    else{
                        this->unk38_31 += 4;
                    }
                }
                else{
                    if(!this->has_met_before){
                        if(gcdialog_showDialog(ASSET_A78_DIALOG_GRABBA_MEET, 0, NULL, NULL, NULL, NULL)){
                            this->has_met_before = TRUE;
                        }
                    }
                }
                break;

            case 4: //L8038C304
                if(this->partnerActor && this->partnerActor->unk5C != local->unk0){
                    func_8038BA08(this);
                }
                else if(actor_animationIsAt(this, 0.89f)){
                    subaddie_set_state_with_direction(this, 1, 0.01f, 1);
                    actor_loopAnimation(this);
                    D_80391A80 = this->state;
                }
                else{
                    if(0.35 < anctrl_getAnimTimer(this->anctrl)){
                        sfxSource_func_8030E2C4(this->unk44_31);
                        if(randf() < 0.6){
                            func_8038BC7C(this->position, 5);
                        }
                    }

                    if(actor_animationIsAt(this, 0.4f)){
                        if(this->partnerActor){
                            this->partnerActor->collidable = FALSE;
                            func_8030E878(SFX_3F5_UNKNOWN, randf2(0.95f, 1.05f), 32000, this->position, 1250.0f, 2500.0f);
                        }

                        if(!this->unk138_23){
                            if(gcdialog_showDialog(ASSET_A7A_DIALOG_GRABBA_TOO_FAST, 0, NULL, NULL, NULL, NULL)){
                                this->unk138_23 = TRUE;
                            }
                        }
                    }

                }
                break;

            case 5: //L8038C488
                if(this->position_y <= this->unk1C[1] - 330.0f){
                    marker_despawn(this->marker);
                    func_8038C748();
                }
                else{
                    sfxSource_func_8030E2C4(this->unk44_31);
                    this->position_y -= 7.0;
                    if(globalTimer_getTime() & 1){
                        sp38[0] = this->position_x;
                        sp38[1] = this->position_y;
                        sp38[2] = this->position_z;
                        sp38[1] = this->unk1C[1];
                        func_8038BD8C(sp38, 1);
                    }
                }
                break;

        }//L8038C528
        if(this->partnerActor && this->partnerActor->unk5C == local->unk0){
            Actor *tmp_v0;
            tmp_v0 = subaddie_getLinkedActor(this);
            if(this->marker->unk14_21){
                func_8034A174(this->marker->unk44, 5, tmp_v0->position);
            }
            else{
                tmp_v0->position_x = this->position_x; 
                tmp_v0->position_y = this->position_y; 
                tmp_v0->position_z = this->position_z; 
                tmp_v0->position_y -= 200.0f; 
            }
        }
    }//L8038C5AC
}

s32 GV_func_8038C5BC(void){
    return D_80391A80;
}
