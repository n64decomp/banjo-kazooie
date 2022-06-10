#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8038C288(void);
extern void func_80328B8C(Actor *, s32, f32, s32);
extern void func_80324CFC(f32, s32, s32);
extern void func_802F9E44(s32, f32, f32, f32, f32);
extern void func_80387470(Actor *, f32 (*)[3], f32, f32, f32, f32, f32);
extern void func_8038C0DC(f32[3]);

extern void func_8038C5F0(Actor *, enum asset_e, enum asset_e, f32);

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

void func_8039049C(Actor *this);

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

ActorInfo D_80392018 = {
    0x285, 0x3AC, 0x551, 0x1, D_80391FB0,
    func_8039049C, func_80326224, func_80325888,
    {0, 0}, 0, 1.0f, {0,0,0,0}
};

s32 D_8039203C[] = {0xDC, 0x96, 0x82, 0xB4, 0xD2, 0xAA, 0xC8, 0x96, 0xB4};
s32 D_80392060[] = {0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2};


/* .rodata */
extern f64 D_80392650;
extern f64 D_80392658;
extern f64 D_80392660;
extern f32 D_80392668;


extern f32 D_803926A0;
extern f32 D_803926A4;
extern f32 D_803926A8;
extern f64 D_803926B0;
extern f64 D_803926B8;
extern f64 D_803926C0;
extern f32 D_803926C8;
extern f32 D_803926CC;
extern f32 D_803926D0;
extern f64 D_803926D8;
extern f64 D_803926E0;
extern f32 D_803926E8;
extern f32 D_803926EC;
extern f32 D_803926F0;
extern f32 D_803926F4;
extern f32 D_803926F8;
extern f64 D_80392700;
extern f64 D_80392708;
extern f32 D_80392710;

extern f64 D_80392718;
    /* 
0000 C2B0: 3D CC CC CD 3E CC CC CD  4C BE BC 20 00 00 00 00
0000 C2C0: 3F D9 99 99 99 99 99 9A  44 7F C0 00 00 00 00 00
0000 C2D0: 3F A4 7A E1 47 AE 14 7B  3D CC CC CD 45 9C 40 00
0000 C2E0: 46 3B 80 00 00 00 00 00  3F BC 28 F5 C2 8F 5C 29
0000 C2F0: 40 10 CC CC CC CC CC CD  45 1C 40 00 3D CC CC CD
0000 C300: 45 9C 40 00 46 3B 80 00  3F 28 F5 C3 00 00 00 00
0000 C310: 3F BC 28 F5 C2 8F 5C 29  40 10 CC CC CC CC CC CD
0000 C320: 45 1C 40 00 00 00 00 00  3F BC 28 F5 C2 8F 5C 29
0000 C330: 40 53 33 33 40 93 D7 0A  00 00 00 00 00 00 00 00
*/

/* .bss */
extern f32 D_80392720;
extern f32 D_80392724;
extern vec3f D_80392920;

/* .code */
void func_80390130(f32 position[3], int count, enum asset_e sprite_id){
    ParticleEmitter *s0 = partEmitList_pushNew(count);
    particleEmitter_setSprite(s0, sprite_id);
    particleEmitter_setStartingFrameRange(s0, 1, 6);
    particleEmitter_setPosition(s0, position);
    particleEmitter_setParticleAccelerationRange(s0, 0.0f, -200.0f, 0.0f, 0.0f, -200.0f, 0.0f);
    particleEmitter_setParticleVelocityRange(s0, -100.0f, -100.0f, -100.0f, 100.0f, 100.0f, 100.0f);
    func_802EFB70(s0, 0.5f, 0.65f);
    func_802EFB84(s0, 0.0f, 0.0f);
    particleEmitter_setSpawnIntervalRange(s0, 0.0f, 0.01f);
    func_802EFEC0(s0, 0.65f, 0.85f);
    func_802EFA5C(s0, 0.0f, 0.35f);
    func_802EFA78(s0, 1);
    func_802EFA70(s0, 4);
    particleEmitter_emitN(s0, count);
}

void func_80390278(Actor *this){
    f32 sp34[3];
    int i;
    for(i = 0; i < 4; i++){
        if(randf() < 0.3){
            func_8034A174(this->marker->unk44, i + 5, &sp34);
            func_80390130(&sp34, 1, ASSET_718_SPRITE_SPARKLE_WHITE_2);
        }
    }
}

void func_80390318(Actor *this, s32 arg1){
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
    func_8038C5F0(this, sp1C, sp18, 2.0f);
}

void func_803903C4(Actor *this){
    animctrl_setSmoothTransition(this->animctrl, FALSE);
    func_80328B8C(this, 7, 0.001f, 1);
    actor_loopAnimation(this);
}

void func_8039040C(Actor *this){
    ActorLocal_fight_9850 *local = (ActorLocal_fight_9850 *)&this->local;
    f32 tick = time_getDelta();
    
    local->unk14 = MIN(1.99, local->unk14 + local->unk18*tick);
    func_8030DBB4(this->unk44_31, local->unk14);
    if(func_8030E3FC(this->unk44_31) == 0)
        func_8030E2C4(this->unk44_31);
}

void func_8039049C(Actor *this){
    ActorLocal_fight_9850 *local = (ActorLocal_fight_9850 *)&this->local;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    s32 sp4C;
    f32 sp48;


    sp58 = time_getDelta();
    sp54 = animctrl_getDuration(this->animctrl);
    
    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        local->unk18 = 0.40000000000000013 / (this->unk60 +  3.3);
        local->unk14 = 0.7f;
        func_8025A6EC(JINGLE_MENACING_GRUNTILDA_B, 20000);
        func_8025A58C(0, 0x7fff);
        this->unk44_31 = func_8030ED2C(SFX_17A_SHIPHORN, 3);
        func_8030DABC(this->unk44_31, 25000);
        func_8030DBB4(this->unk44_31, local->unk14);
        func_8030E2C4(this->unk44_31);
        local->unk28 = 0xC;
    }//L80390574
    
    if(0.0 < local->unk4){
        local->unk4 -= sp58;
        return;
    }


    switch(this->state){
        case 1: //803905D4
            func_8039040C(this);
            func_8028764C(this->animctrl, 0.0f);
            this->unk60 -= sp58;
            if(this->unk60 < 0.0){
                func_80328B8C(this, 2, 0.001f, 1);
                actor_playAnimationOnce(this);
            }
            break;

        case 2: //80390648
            func_8039040C(this);
            if(actor_animationIsAt(this, 0.27f))
                func_8030E624(0x599C50D0);

            if(actor_animationIsAt(this, 0.44f)){
                func_8030E624(0x7FF86976);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 25000);
            }

            if(actor_animationIsAt(this, 0.999f)){
                func_80328B8C(this, 3, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_8030E394(this->unk44_31);
                func_8030DA44(this->unk44_31);
                this->unk44_31 = 0;
                local->unk0 = (320.0f - this->position_y) * 0.5;
                func_80324CFC(0.0f, 0x8c, 0x7d00);
            }
            break;

        case 3: //8039073C
            func_80390278(this);
            if(this->position_y < 320.0f){
                this->position_y = MIN(320.0f, this->position_y + local->unk0*sp58);
            }//L803907A0

            if(320.0f == this->position_y){
                func_80328B8C(this, 4, 0.001f, 1);
                actor_loopAnimation(this);
                local->unk4 = func_8038C288();
            }
            break;

        case 4: //803907D4
            func_80390278(this);
            func_80328B8C(this, 5, 0.001f, 1);
            actor_playAnimationOnce(this);
            break;

        case 5: //80390804
            func_80390278(this);
            if(actor_animationIsAt(this, 0.998f)){
                animctrl_setSmoothTransition(this->animctrl, FALSE);
                func_80328B8C(this, 6, 0.0001f, 1);
                actor_loopAnimation(this);
                if(this->unk44_31 == 0){
                    local->unk18 = 0.1f;
                    local->unk14 = 0.4f;
                    this->unk44_31 = func_8030ED2C(0x416, 3);
                    func_8030DABC(this->unk44_31, 26000);
                    func_8030DBB4(this->unk44_31, local->unk14);
                    func_8030E2C4(this->unk44_31);
                }//L803908AC
                local->unk1C = 0.5f;
            }
            break;

        case 6: //803908BC
            this->position[1] = MIN(1e+8f, this->position[1] + 80.0f*sp58);
            animctrl_setDuration(this->animctrl, MAX(0.4, sp54 - (0.5*sp58)));
            func_80390278(this);
            if(actor_animationIsAt(this, 0.25f) || actor_animationIsAt(this, 0.75f)){
                func_8030E624(_SHIFTL(local->unk1C * 1023.0f,21, 11) + 0x196002);
                local->unk1C += 0.04;
            }//L80390A4C
            func_8039040C(this);
            if(actor_animationIsAt(this, 0.5f)){
                if(--local->unk28 <= 0){
                func_803903C4(this);
                func_8030E8B4(0x7fff4135, &this->position, 0x3e802710);
                func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, &this->position, 5000.0f, 12000.0f);
                if((u8)this->unk44_31){
                    func_8030E394(this->unk44_31);
                    func_8030DA44(this->unk44_31);
                    this->unk44_31 = 0;
                }
                func_80324D2C(0.0f, COMUSIC_8C_JINJONATOR_POWERUP);
                func_8034A174(this->marker->unk44, 0x1f, &this->position);
                this->velocity[0] = (this->position[0] - this->unk1C[0]) / sp58;
                this->velocity[1] = (this->position[1] - this->unk1C[1]) / sp58;
                this->velocity[2] = (this->position[2] - this->unk1C[2]) / sp58;
                }
                
            }//L80390B60
            else{
                func_8034A174(this->marker->unk44, 0x1f, &this->unk1C);
            }
            break;
        case 7: //80390B78
            sp50 = local->unk24*0.11 + 1.0;
            func_80390278(this);
            func_8038C0DC(&local->unk8);
            local->unk8[1] += 100.0f;
            func_80387470(this, &local->unk8, sp50*2400.0f, sp50*2400.0f*4.2, 170.0f, sp50*2500.0f, 0.0f);
            break;
        case 8: //80390C48
            if(actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f))
                func_8030E624(0x7ffb5802);
            
            if(actor_animationIsAt(this, 0.999f)){
                func_8034A174(this->marker->unk44, 0x1f, &this->position);
                func_803903C4(this);
                func_8030E8B4(0x7fff4135, &this->position, 0x3E802710);
                func_80324D54(0.1f, SFX_C1_BUZZBOMB_ATTACK, 0.85f, 32000, &this->position, 5000.0f, 12000.0f);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;

            }

            break;
        
        case 9: //80390D20
            if(actor_animationIsAt(this, 0.16f) || actor_animationIsAt(this, 0.47f))
                func_8030E624(0x7ffb5802);
            
            if(actor_animationIsAt(this, 0.8f)){
                sp4C = func_802F9AA8(SFX_141_MECHANICAL_WINCH);
                func_802F9F80(sp4C, 0.0f, 5.92f, 0.0f);
                func_802F9E44(sp4C, 0.1f, 5.92f, 0.3f, 1.0f);
                func_802FA060(sp4C, 32000, 32000, 0.0f);
            }

            if(actor_animationIsAt(this, 0.999f)){
                func_80328B8C(this, 0xA, 0.001f, 1);
                actor_loopAnimation(this);
                local->unk20 = 0xE;
            }
            break;

        case 10: //80390E1C
            if(actor_animationIsAt(this, 0.999f)){
                local->unk20--;
            }

            if(local->unk20 == 2 && actor_animationIsAt(this, 0.1f)){
                func_8030E624(0x7fff4176);
                timed_playSfx(0.66f, SFX_176_JINJONATOR_JINJOOO_1, 0.9f, 32000);
            }//L80390E90

            if(local->unk20 <= 0){
                s32 text_id;
                func_80328B8C(this, 0xB, 0.001f, 1);
                actor_playAnimationOnce(this);
                func_802BB41C(0);
                text_id = 0x115e + randi2(0,5);
                func_80311480(text_id, 0x20, 0, 0, 0, 0);
            }
            break;
        case 11: //80390EF8
            if(actor_animationIsAt(this, 0.999f)){
                func_8034A174(this->marker->unk44, 0x1f, &this->position);
                func_8030E624(0x7fff417b);
                func_8030E624(0x7fff4147);
                animctrl_setSmoothTransition(this->animctrl, 0);
                func_80328B8C(this, 0xC, 0.001f, 1);
                actor_playAnimationOnce(this);
                this->velocity[2] = 0.0f;
                this->velocity[1] = 0.0f;
                this->velocity[0] = 0.0f;

            }
            break;
        case 12: //80390F7C
            sp48 = local->unk24*0.11 + 1.0;
            func_80390278(this);
            func_8038C0DC(&local->unk8);
            local->unk8[1] += 100.0f; 
            func_80387470(this, &local->unk8, sp48*2400.0f, sp48*2400.0f*4.2, 170.0f, sp48*2500.0f, 0.0f);
            break;
    }//L80391044
    func_8034A174(this->marker->unk44, 0x1f, &D_80392920);
}

void func_80391070(ActorMarker *marker, s32 arg1, s32 arg2) {
    Actor *temp_s0;
    ActorLocal_fight_9850 *local;
    s32 pad;

    temp_s0 = marker_getActor(marker);
    local = (ActorLocal_fight_9850 *)&temp_s0->local;
    
    func_8025A6EC(D_80392060[arg1-1], 20000);

    func_80390318(temp_s0, arg1);
    func_8030E8B4(0x7FFF401B, temp_s0->position, 0x196403E8);
    temp_s0->velocity[2] = 0.0f;
    temp_s0->velocity[1] = 0.0f;
    temp_s0->velocity[0] = 0.0f;
    
    temp_s0->yaw = (f32)D_8039203C[arg1-1];
    if (arg2 != 0) {
        temp_s0->yaw = (f32) (temp_s0->yaw + 180.0f);
    }
    local->unk24 = arg1;
    animctrl_setSmoothTransition(temp_s0->animctrl, 1);
    actor_playAnimationOnce(temp_s0);
    if (&D_8039203C[arg1] >= D_80392060) {
        func_80328B8C(temp_s0, 9, 0.001f, 1);
        return;
    }
    func_80328B8C(temp_s0, 8, 0.001f, 1);
    animctrl_setDuration(temp_s0->animctrl, (f32) (1.75 - 0.11 * local->unk24));
}

void func_803911F8(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    func_80390318(actor, 0xa);
    marker_despawn(actor->marker);
}

f32 func_80391234(void){
    return 3.3f;
}

f32 func_80391240(void){
    return 2.0;
}

f32 func_80391250(void){
    return 4.62f;
}

s32 func_8039125C(ActorMarker *marker){
    u32 state = (u32) (marker_getActor(marker))->state;
    if (state == 0x7 || state == 0xC) {
        return 1;
    }
    return 0;
}

void func_8039129C(vec3f *arg0) {
    arg0->x = (f32) D_80392920.x;
    arg0->y = (f32) D_80392920.y;
    arg0->z = (f32) D_80392920.z;
}
