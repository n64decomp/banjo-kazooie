#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern f32 func_8038C288(void);
extern void subaddie_set_state_with_direction(Actor *, s32, f32, s32);
extern void func_80324CFC(f32, s32, s32);
extern void func_802F9E44(s32, f32, f32, f32, f32);
extern void func_80387470(Actor *, f32 [3], f32, f32, f32, f32, f32);
extern void fight_func_8038C0DC(f32[3]);

extern void chbossjinjo_spawnParticles(Actor *, enum asset_e, enum asset_e, f32);

typedef struct{
    f32 unk0;
    f32 unk4;
    f32 unk8[3];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
}ActorLocal_fight_9850;

void chjinjonator_update(Actor *this);

/* .data */

//BBC0
ActorAnimationInfo D_80391FB0[] = {
   {0x000, 00000000},
   {0x275, 1000000.0f},
   {0x275, 3.3f},
   {0x276, 0.67f},
   {0x277, 1.167f},
   {0x27E, 2.5f},
   {0x27F, 4.0f},
   {0x262, 2.0f},
   {0x278, 1.75f},
   {0x27B, 2.25f},
   {0x27C, 0.33f},
   {0x27D, 0.8f},
   {0x280, 0.4f}  
};

ActorInfo chJinjonator = {
    MARKER_285_JINJONATOR, ACTOR_3AC_JINJONATOR, ASSET_551_MODEL_JINJONATOR,
    0x1, D_80391FB0,
    chjinjonator_update, func_80326224, actor_draw,
    0, 0, 1.0f, 0
};

s32 D_8039203C[] = {0xDC, 0x96, 0x82, 0xB4, 0xD2, 0xAA, 0xC8, 0x96, 0xB4};
s32 D_80392060[] = {
    COMUSIC_9A_JINJONATOR_HITS_GRUNTY_A,
    COMUSIC_9B_JINJONATOR_HITS_GRUNTY_B,
    COMUSIC_9C_JINJONATOR_HITS_GRUNTY_C,
    COMUSIC_9D_JINJONATOR_HITS_GRUNTY_D,
    COMUSIC_9E_JINJONATOR_HITS_GRUNTY_E,
    COMUSIC_9F_JINJONATOR_HITS_GRUNTY_F,
    COMUSIC_A0_JINJONATOR_HITS_GRUNTY_G,
    COMUSIC_A1_JINJONATOR_HITS_GRUNTY_H,
    COMUSIC_A2_JINJONATOR_HITS_GRUNTY_I
};

/* .bss */
f32 D_80392920[3];

/* .code */
void chjinjonator_80390130(f32 position[3], int count, enum asset_e sprite_id){
    ParticleEmitter *s0 = partEmitMgr_newEmitter(count);
    particleEmitter_setSprite(s0, sprite_id);
    particleEmitter_setStartingFrameRange(s0, 1, 6);
    particleEmitter_setPosition(s0, position);
    particleEmitter_setParticleAccelerationRange(s0, 0.0f, -200.0f, 0.0f, 0.0f, -200.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(s0, -100.0f, -100.0f, -100.0f, 100.0f, 100.0f, 100.0f);
    particleEmitter_setStartingScaleRange(s0, 0.5f, 0.65f);
    particleEmitter_setFinalScaleRange(s0, 0.0f, 0.0f);
    particleEmitter_setSpawnIntervalRange(s0, 0.0f, 0.01f);
    particleEmitter_setParticleLifeTimeRange(s0, 0.65f, 0.85f);
    particleEmitter_setFade(s0, 0.0f, 0.35f);
    func_802EFA78(s0, 1);
    particleEmitter_setDrawMode(s0, 4);
    particleEmitter_emitN(s0, count);
}

void chjinjonator_80390278(Actor *this){
    f32 sp34[3];
    int i;
    for(i = 0; i < 4; i++){
        if(randf() < 0.3){
            func_8034A174(this->marker->unk44, i + 5, sp34);
            chjinjonator_80390130(sp34, 1, ASSET_718_SPRITE_SPARKLE_WHITE_2);
        }
    }
}

void chjinjonator_spawnAttackParticles(Actor *this, s32 arg1){
    s32 sp1C;
    s32 sp18;
    
    switch(arg1){
        case 1:
        case 5:
            sp1C = ASSET_71B_SPRITE_SPARKLE_ORANGE_2;
            sp18 = ASSET_6C5_SPRITE_SMOKE_ORANGE;
            break;
        case 2:
        case 6:
            sp1C = ASSET_719_SPRITE_SPARKLE_GREEN_2;
            sp18 = ASSET_6C3_SPRITE_SMOKE_GREEN;
            break;
        case 3:
        case 7:
            sp1C = ASSET_71A_SPRITE_SPARKLE_PINK_2;
            sp18 = ASSET_6C6_SPRITE_SMOKE_PINK;
            break;
        case 4:
        case 8:
            sp1C = ASSET_717_SPRITE_SPARKLE_YELLOW_2;
            sp18 = ASSET_6C4_SPRITE_SMOKE_YELLOW;
            break;
        case 9:
        case 10:
            sp1C = ASSET_718_SPRITE_SPARKLE_WHITE_2;
            sp18 = ASSET_6C2_SPRITE_SMOKE_WHITE;
            break;
    }
    chbossjinjo_spawnParticles(this, sp1C, sp18, 2.0f);
}

void chjinjonator_803903C4(Actor *this){
    animctrl_setSmoothTransition(this->animctrl, FALSE);
    subaddie_set_state_with_direction(this, 7, 0.001f, 1);
    actor_loopAnimation(this);
}

void chjinjonator_8039040C(Actor *this){
    ActorLocal_fight_9850 *local = (ActorLocal_fight_9850 *)&this->local;
    f32 tick = time_getDelta();
    
    local->unk14 = MIN(1.99, local->unk14 + local->unk18*tick);
    sfxsource_playSfxAtVolume(this->unk44_31, local->unk14);
    if(func_8030E3FC(this->unk44_31) == 0)
        func_8030E2C4(this->unk44_31);
}

void chjinjonator_update(Actor *this){
    ActorLocal_fight_9850 *local = (ActorLocal_fight_9850 *)&this->local;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp4C;
    f32 sp48;


    sp58 = time_getDelta();
    sp54 = animctrl_getDuration(this->animctrl);
    
    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->unk18 = 0.40000000000000013 / (this->lifetime_value +  3.3);
        local->unk14 = 0.7f;
        func_8025A6EC(JINGLE_MENACING_GRUNTILDA_B, 20000);
        func_8025A58C(0, 0x7fff);
        this->unk44_31 = func_8030ED2C(SFX_17A_SHIPHORN, 3);
        sfxsource_setSampleRate(this->unk44_31, 25000);
        sfxsource_playSfxAtVolume(this->unk44_31, local->unk14);
        func_8030E2C4(this->unk44_31);
        local->unk28 = 0xC;
    }//L80390574
    
    if(0.0 < local->unk4){
        local->unk4 -= sp58;
        return;
    }


    switch(this->state){
        case 1: //803905D4
            chjinjonator_8039040C(this);
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            this->lifetime_value -= sp58;
            if(this->lifetime_value < 0.0){
                subaddie_set_state_with_direction(this, 2, 0.001f, 1);
                actor_playAnimationOnce(this);
            }
            break;

        case 2: //80390648
            chjinjonator_8039040C(this);
            if(actor_animationIsAt(this, 0.27f))
                FUNC_8030E624(SFX_D0_GRIMLET_SQUEAK, 0.7f, 29000);

            if(actor_animationIsAt(this, 0.44f)){
                FUNC_8030E624(SFX_176_JINJONATOR_JINJOOO_1, 1.0f, 25000);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 25000);
            }

            if(actor_animationIsAt(this, 0.999f)){
                subaddie_set_state_with_direction(this, 3, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_8030E394(this->unk44_31);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
                local->unk0 = (320.0f - this->position_y) * 0.5;
                func_80324CFC(0.0f, COMUSIC_8C_JINJONATOR_POWERUP, 32000);
            }
            break;

        case 3: //8039073C
            chjinjonator_80390278(this);
            if(this->position_y < 320.0f){
                this->position_y = MIN(320.0f, this->position_y + local->unk0*sp58);
            }//L803907A0

            if(320.0f == this->position_y){
                subaddie_set_state_with_direction(this, 4, 0.001f, 1);
                actor_loopAnimation(this);
                local->unk4 = func_8038C288();
            }
            break;

        case 4: //803907D4
            chjinjonator_80390278(this);
            subaddie_set_state_with_direction(this, 5, 0.001f, 1);
            actor_playAnimationOnce(this);
            break;

        case 5: //80390804
            chjinjonator_80390278(this);
            if(actor_animationIsAt(this, 0.998f)){
                animctrl_setSmoothTransition(this->animctrl, FALSE);
                subaddie_set_state_with_direction(this, 6, 0.0001f, 1);
                actor_loopAnimation(this);
                if(this->unk44_31 == 0){
                    local->unk18 = 0.1f;
                    local->unk14 = 0.4f;
                    this->unk44_31 = func_8030ED2C(0x416, 3);
                    sfxsource_setSampleRate(this->unk44_31, 26000);
                    sfxsource_playSfxAtVolume(this->unk44_31, local->unk14);
                    func_8030E2C4(this->unk44_31);
                }//L803908AC
                local->unk1C = 0.5f;
            }
            break;

        case 6: //803908BC
            this->position[1] = MIN(1e+8f, this->position[1] + 80.0f*sp58);
            animctrl_setDuration(this->animctrl, MAX(0.4, sp54 - (0.5*sp58)));
            chjinjonator_80390278(this);
            if(actor_animationIsAt(this, 0.25f) || actor_animationIsAt(this, 0.75f)){
                FUNC_8030E624(SFX_2_CLAW_SWIPE, local->unk1C, 26000);
                local->unk1C += 0.04;
            }//L80390A4C
            chjinjonator_8039040C(this);
            if(actor_animationIsAt(this, 0.5f)){
                if(--local->unk28 <= 0){
                    chjinjonator_803903C4(this);
                    FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                    func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                    if((u8)this->unk44_31){
                        func_8030E394(this->unk44_31);
                        func_8030DA44(this->unk44_31);
                        this->unk44_31 = 0;
                    }
                    func_80324D2C(0.0f, COMUSIC_8C_JINJONATOR_POWERUP);
                    func_8034A174(this->marker->unk44, 0x1f, this->position);
                    this->velocity[0] = (this->position[0] - this->unk1C[0]) / sp58;
                    this->velocity[1] = (this->position[1] - this->unk1C[1]) / sp58;
                    this->velocity[2] = (this->position[2] - this->unk1C[2]) / sp58;
                }
                
            }//L80390B60
            else{
                func_8034A174(this->marker->unk44, 0x1f, this->unk1C);
            }
            break;
        case 7: //80390B78
            sp50 = local->unk24*0.11 + 1.0;
            chjinjonator_80390278(this);
            fight_func_8038C0DC(local->unk8);
            local->unk8[1] += 100.0f;
            func_80387470(this, local->unk8, sp50*2400.0f, sp50*2400.0f*4.2, 170.0f, sp50*2500.0f, 0.0f);
            break;
        case 8: //80390C48
            if(actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f))
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1.0f, 28000);
            
            if(actor_animationIsAt(this, 0.999f)){
                func_8034A174(this->marker->unk44, 0x1f, this->position);
                chjinjonator_803903C4(this);
                FUNC_8030E8B4(SFX_135_CARTOONY_SPRING, 1.0f, 32000, this->position, 10000, 16000);
                func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, this->position, 5000.0f, 12000.0f);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;

            }

            break;
        
        case 9: //80390D20
            if(actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f))
                FUNC_8030E624(SFX_2_CLAW_SWIPE, 1.0f, 28000);

            
            if(actor_animationIsAt(this, 0.8f)){
                sp4C = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
                func_802F9F80(sp4C, 0.0f, 5.92f, 0.0f);
                func_802F9E44(sp4C, 0.1f, 5.92f, 0.3f, 1.0f);
                func_802FA060(sp4C, 32000, 32000, 0.0f);
            }

            if(actor_animationIsAt(this, 0.999f)){
                subaddie_set_state_with_direction(this, 0xA, 0.001f, 1);
                actor_loopAnimation(this);
                local->unk20 = 0xE;
            }
            break;

        case 10: //80390E1C
            if(actor_animationIsAt(this, 0.999f)){
                local->unk20--;
            }

            if(local->unk20 == 2 && actor_animationIsAt(this, 0.1f)){
                FUNC_8030E624(SFX_176_JINJONATOR_JINJOOO_1, 1.0f, 32000);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 32000);
            }//L80390E90

            if(local->unk20 <= 0){
                s32 text_id;
                subaddie_set_state_with_direction(this, 0xB, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_802BB41C(0);
                text_id = 0x115e + randi2(0,5);
                gcdialog_showText(text_id, 0x20, 0, 0, 0, 0);
            }
            break;
        case 11: //80390EF8
            if(actor_animationIsAt(this, 0.999f)){
                func_8034A174(this->marker->unk44, 0x1f, this->position);
                FUNC_8030E624(SFX_17B_AIRPLANE_FALLING, 1.0f, 32000);
                FUNC_8030E624(SFX_147_GRUNTY_SPELL_ATTACK_2, 1.0f, 32000);
                animctrl_setSmoothTransition(this->animctrl, 0);
                subaddie_set_state_with_direction(this, 0xC, 0.001f, 1);
                actor_playAnimationOnce(this);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;

            }
            break;
        case 12: //80390F7C
            sp48 = local->unk24*0.11 + 1.0;
            chjinjonator_80390278(this);
            fight_func_8038C0DC(local->unk8);
            local->unk8[1] += 100.0f; 
            func_80387470(this, local->unk8, sp48*2400.0f, sp48*2400.0f*4.2, 170.0f, sp48*2500.0f, 0.0f);
            break;
    }//L80391044
    func_8034A174(this->marker->unk44, 0x1f, D_80392920);
}

void chjinjonator_attack(ActorMarker *marker, s32 hit_count, bool mirrored) {
    Actor *temp_s0;
    ActorLocal_fight_9850 *local;
    s32 pad;

    temp_s0 = marker_getActor(marker);
    local = (ActorLocal_fight_9850 *)&temp_s0->local;
    
    func_8025A6EC(D_80392060[hit_count-1], 20000);

    chjinjonator_spawnAttackParticles(temp_s0, hit_count);
    FUNC_8030E8B4(SFX_1B_EXPLOSION_1, 1.0f, 32000, temp_s0->position, 1000, 6500);

    temp_s0->velocity[2] = 0.0f;
    temp_s0->velocity[1] = 0.0f;
    temp_s0->velocity[0] = 0.0f;
    
    temp_s0->yaw = (f32)D_8039203C[hit_count-1];
    if (mirrored) {
        temp_s0->yaw = (f32) (temp_s0->yaw + 180.0f);
    }
    local->unk24 = hit_count;
    animctrl_setSmoothTransition(temp_s0->animctrl, 1);
    actor_playAnimationOnce(temp_s0);
    if (&D_8039203C[hit_count] >= D_80392060) {
        subaddie_set_state_with_direction(temp_s0, 9, 0.001f, 1);
        return;
    }
    subaddie_set_state_with_direction(temp_s0, 8, 0.001f, 1);
    animctrl_setDuration(temp_s0->animctrl, (f32) (1.75 - 0.11 * local->unk24));
}

void chjinjonator_finalAttack(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    chjinjonator_spawnAttackParticles(actor, 0xa);
    marker_despawn(actor->marker);
}

f32 chjinjonator_80391234(void){
    return 3.3f;
}

f32 chjinjonator_80391240(void){
    return 2.0;
}

f32 chjinjonator_80391250(void){
    return 4.62f;
}

bool chjinjonator_8039125C(ActorMarker *marker){
    u32 state = (u32) (marker_getActor(marker))->state;
    if (state == 0x7 || state == 0xC) {
        return TRUE;
    }
    return FALSE;
}

void chjinjonator_8039129C(f32 arg0[3]) {
    arg0[0] = D_80392920[0];
    arg0[1] = D_80392920[1];
    arg0[2] = D_80392920[2];
}
