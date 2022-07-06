#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8025AE50(s32, f32);
extern void func_8028F710(s32, f32);

typedef struct {
    s32 unk0;
}ActorLocal_Grabba;

void func_8038BEA0(Actor *this);

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
    func_8038BEA0, func_80326224, func_80325888, 
    0, 0, 0.0f, 0
};

s32 D_8039117C[3] = {160, 100, 0};


/* .bss */
extern s32 D_80391A80;

/* .code */
void func_8038B960(void){
    func_8025AE50(5000, 3.19f);
}

/* .bss */
extern s32 D_80391A80;

/* .code */
void func_8038B988(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    func_80328B8C(this, 5, 0.01f, 1);
    actor_loopAnimation(this);
    func_802BAFE4(0x13);
    FUNC_8030E624(SFX_8D_BOGGY_OHWW, 1000, 0x398);
    timedFunc_set_0(2.5f, func_8038B960);
    D_80391A80 = this->state;
}

void func_8038BA08(Actor *this){
    func_80328B8C(this, 6, 0.01f, 1);
    actor_loopAnimation(this);
    this->unk100 = NULL;
    D_80391A80 = 3;
    if(func_8028ECAC() == 6)
        func_8028F710(3, 0.0f);

    func_80311480(ASSET_A79_TEXT_GRABBA_DEFEAT, 0xf, this->position, this->marker, func_8038B988, NULL);
    comusic_8025AB44(COMUSIC_57_TURBO_TRAINERS, 7000, 700);
}

s32 func_8038BAA4(Actor *jiggy){
    s32 tmp_v0;
    s32 sp18[3];

    map_get();
    sp18[0] = (s32)jiggy->position_x;
    sp18[1] = (s32)jiggy->position_y;
    sp18[2] = (s32)jiggy->position_z;
    tmp_v0 = func_80307164(sp18, jiggy);
    if( tmp_v0 < 0) 
        return 0;
    else
        return func_80306DBC(tmp_v0) + 1;
    
}

int func_8038BB24(Actor *this){
    if(func_80329530(this, 1560) && !func_80329530(this, 1380)){
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

    grabba->unk100 = jiggy->marker;
    grabba_local->unk0 = grabba->unk100->unk5C;
    jiggy->unk10_1 = TRUE;
    grabba->unk1C[2] = (f32)func_8038BAA4(jiggy);
    if(jiggyscore_isCollected((s32)grabba->unk1C[2])){
        func_8038C748();
        marker_despawn(grabba->marker);
    }
}

void func_8038BBFC(ParticleEmitter *pCtrl, f32 position[3], s32 cnt){
    func_802EFFA8(pCtrl, D_8039117C);
    func_802EF9E4(pCtrl, 0x96);
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    func_802EFA5C(pCtrl, 0.0f, 0.01f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, position);
}

void func_8038BC7C(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitList_pushNew(cnt);
    func_8038BBFC(pCtrl, position, cnt);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -60.0f,  0.0f, -60.0f,
         60.0f, 30.0f,  60.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -250.0f, 10.0f, -250.0f,
         250.0f, 110.0f, 250.0f
    );
    func_802EFB70(pCtrl, 0.1f, 0.5f);
    func_802EFB84(pCtrl, 2.0f, 2.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 0.5f, 1.4f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038BD8C(f32 position[3], s32 cnt){
    ParticleEmitter *pCtrl = partEmitList_pushNew(cnt);
    func_8038BBFC(pCtrl, position, cnt);
    particleEmitter_setParticleSpawnPositionRange(pCtrl,
        -40.0f,  0.0f, -40.0f,
         40.0f, 30.0f,  40.0f
    );
    particleEmitter_setParticleVelocityRange(pCtrl,
        -100.0f, 20.0f, -100.0f,
         100.0f, 60.0f, 100.0f
    );
    func_802EFB70(pCtrl, 0.1f, 0.5f);
    func_802EFB84(pCtrl, 1.2, 1.6f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 0.5f, 1.4f);
    particleEmitter_emitN(pCtrl, cnt);
}

void func_8038BEA0(Actor *this){
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

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if(this->unk44_31 == 0){
            this->unk44_31 = func_8030D90C();
            func_8030DA80(this->unk44_31, SFX_3EC_CCW_DOOR_OPENING);
            func_8030DD14(this->unk44_31, 2);
            func_8030DBB4(this->unk44_31, 0.1f);
            func_8030DABC(this->unk44_31, 32000);
        }
        if(this->unk100 == NULL){
            this->unk100 = func_8032B16C(JIGGY_3E_GV_GRABBA);
            local->unk0 =  this->unk100 != NULL ? this->unk100->unk5C : NULL;
        }
        func_80328B8C(this, this->state, 0.01f, 1);
        this->unk58_0 = FALSE;
        this->marker->propPtr->unk8_3 = FALSE;
    }//L8038BFF4

    if(actor_playerIsWithinDist(this, 4000) || this->state == 5){
        this->unk58_0 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        switch(this->state){
            case 1: //L8038C064
                this->unk58_0 = FALSE;
                this->marker->propPtr->unk8_3 = FALSE;
                if(func_8038BB24(this)){
                    func_80328B8C(this, 2, 0.01f, 1);
                    actor_playAnimationOnce(this);
                    this->unk38_31 = 0;
                    D_80391A80 = this->state;
                    func_802BB3DC(0, 14.0f, 0.92f);
                    func_802C3F04((GenMethod_4)func_802C4140, 0x11f, 
                        reinterpret_cast(s32, this->position_x), reinterpret_cast(s32, this->position_y), reinterpret_cast(s32, this->position_z)
                    );
                }
                break;

            case 2: //L8038C108
                if(actor_animationIsAt(this, 0.69f)){
                    func_80328B8C(this, 3, 0.01f, 1);
                    actor_loopAnimation(this);
                    D_80391A80 = this->state;
                    if(this->unk100){
                        this->unk100->collidable = TRUE;
                    }
                }
                else{
                    if(animctrl_getAnimTimer(this->animctrl) < 0.55){
                        func_8030E2C4(this->unk44_31);
                        if(randf() < 0.6){
                            func_8038BC7C(this->position, 0xA);
                        }
                    }
                }
                break;

            case 3: //L8038C1CC
                if(this->unk100 && this->unk100->unk5C != local->unk0){
                    func_8038BA08(this);
                }
                else if(this->unk38_31 >= 0xC){
                    func_80328B8C(this, 4, 0.01f, 1);
                    actor_playAnimationOnce(this);
                    D_80391A80 = this->state;
                    func_802BB3DC(0, 12.0f, 0.92f);
                }
                else if(func_80329530(this, 600)){
                    if(func_8028ECAC() == 6){
                        this->unk38_31++;
                    }
                    else{
                        this->unk38_31 += 4;
                    }
                }
                else{
                    if(!this->unk138_24){
                        if(func_80311480(ASSET_A78_TEXT_GRABBA_MEET, 0, NULL, NULL, NULL, NULL)){
                            this->unk138_24 = TRUE;
                        }
                    }
                }
                break;

            case 4: //L8038C304
                if(this->unk100 && this->unk100->unk5C != local->unk0){
                    func_8038BA08(this);
                }
                else if(actor_animationIsAt(this, 0.89f)){
                    func_80328B8C(this, 1, 0.01f, 1);
                    actor_loopAnimation(this);
                    D_80391A80 = this->state;
                }
                else{
                    if(0.35 < animctrl_getAnimTimer(this->animctrl)){
                        func_8030E2C4(this->unk44_31);
                        if(randf() < 0.6){
                            func_8038BC7C(this->position, 5);
                        }
                    }

                    if(actor_animationIsAt(this, 0.4f)){
                        if(this->unk100){
                            this->unk100->collidable = FALSE;
                            func_8030E878(SFX_3F5_UNKNOWN, randf2(0.95f, 1.05f), 32000, this->position, 1250.0f, 2500.0f);
                        }

                        if(!this->unk138_23){
                            if(func_80311480(ASSET_A7A_TEXT_GRABBA_TOO_FAST, 0, NULL, NULL, NULL, NULL)){
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
                    func_8030E2C4(this->unk44_31);
                    this->position_y -= 7.0;
                    if(func_8023DB5C() & 1){
                        sp38[0] = this->position_x;
                        sp38[1] = this->position_y;
                        sp38[2] = this->position_z;
                        sp38[1] = this->unk1C[1];
                        func_8038BD8C(sp38, 1);
                    }
                }
                break;

        }//L8038C528
        if(this->unk100 && this->unk100->unk5C == local->unk0){
            Actor *tmp_v0;
            tmp_v0 = func_80329980(this);
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

s32 func_8038C5BC(void){
    return D_80391A80;
}
