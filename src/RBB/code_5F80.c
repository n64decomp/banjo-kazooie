#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80335684(void *);
extern void func_803253A0(Actor *);
extern void func_80325794(ActorMarker *);
extern void func_8030E394(u8);
extern void func_80326310(Actor *);
extern int func_803342AC(f32 (*)[3], f32(*)[3], f32);
extern void particleEmitter_setModel(ParticleEmitter *, s32);


typedef struct{
    s16 unk0;
    //u8 pad2[2];
    f32 unk4;
    f32 unk8;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    //u8 padF[1];
    f32 unk10;
    f32 unk14;
} Struct_RBB_5F80;

typedef struct{
    Struct_RBB_5F80 *unk0;
    u8 unk4;
    u8 pad5[3];
    f32 unk8[3];
    f32 unk14[3];
    s32 unk20;
    f32 unk24;
    f32 unk28;
} ActorLocal_RBB_5F80;

void func_8038CC9C(Actor *this, s32 new_state);
void func_8038D7E8(ActorMarker *marker, s32 arg1);
Actor *func_8038D638(ActorMarker *marker, Gfx **gdl, Mtx ** mptr, s32 arg3);
void func_8038D8BC(Actor *this);

/* .data */
Struct_RBB_5F80 D_80390B70[4] = {
    {0x281, 1.1f,  1.0f, 0x14, 0x01, 0x5, 0.9f, 0.8f},
    {0x282, 0.75f, 1.0f,  0xF, 0x02, 0x4, 1.1f, 0.9f},
    {0x283, 0.5f,  2.0f,  0xA, 0x02, 0x3, 1.3f, 1.0f},
    {0x284, 0.25f, 2.0f,  0x5, 0x02, 0x2, 1.5f, 1.1f},
};

ActorInfo D_80390BD0 = {
    0x1A1, 0x281, 0x428, 0x0, NULL,
    func_8038D8BC, NULL, func_8038D638,
    0, 0, 0.0f, 0
};

ActorInfo D_80390BF4 = {
    0x1A2, 0x282, 0x428, 0x0, NULL,
    func_8038D8BC, NULL, func_8038D638,
    0, 0, 0.0f, 0
};

ActorInfo D_80390C18 = {
    0x1A3, 0x283, 0x428, 0x0, NULL,
    func_8038D8BC, NULL, func_8038D638,
    0, 0, 0.0f, 0
};

ActorInfo D_80390C3C = {
    0x1A4, 0x284, 0x428, 0x0, NULL,
    func_8038D8BC, NULL, func_8038D638,
    0, 0, 0.0f, 0
};

s32 D_80390C60[3] = {0xDE, 0xA7, 0x71};

struct41s D_80390C6C = {
    { {-200.0f, 200.0f}, {-200.0f, 200.0f}, {500.0f, 200.0f} },
    { {0.0f, -800.0f, 0.0f}, {0.0f, -800.0f, 0.0f} }
};

s32 D_80390C9C[3] = {0xDE, 0xA7, 0x71};

struct43s D_80390CA8 = {
    { {-200.0f, 0.0f}, {-200.0f, 200.0f}, {-50.0f, 200.0f} },
    { {0.0f, 200.0f, 0.0f}, {0.0f, 400.0f, 0.0f} },
    { {-10.0f, -10.0f, -10.0f}, {10.0f, 10.0f, 10.0f} }
};

/* .bss */
s32 pad_80391270[4];
u8 D_80391280;
s32 pad_80391284;
f32 D_80391288[3];

/* .code */
void func_8038C370(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    func_8038CC9C(actor, arg1);
}

void func_8038C39C(Actor *this){
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    ParticleEmitter *other = partEmitList_pushNew(local->unk0->unkE);
    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(other, 0.0f, 0.1f);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    func_802EFA70(other, 4);
    particleEmitter_setPosition(other, &this->position);
    func_802EFB70(other, local->unk0->unk4*1, local->unk0->unk4*3.0f);
    func_802EFB84(other, 3.0f*local->unk0->unk4, local->unk0->unk4*7.0f);
    particleEmitter_setParticleSpawnPositionRange(other, 
        local->unk0->unk4*-200.0f, local->unk0->unk4*100.0f, local->unk0->unk4*-200.0f,
        local->unk0->unk4*200.0f, local->unk0->unk4*100.0f, local->unk0->unk4*200.0f
    );
    particleEmitter_setParticleVelocityRange(other, 
        -50.0f, 100.0f, -50.0f,
        50.0f, 200.0f, 50.0f
    );
    func_802EFEC0(other, 0.5f, 1.0f);
    particleEmitter_emitN(other, local->unk0->unkE);
}

void func_8038C538(Actor *this){
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    ParticleEmitter *other = partEmitList_pushNew(3*local->unk0->unkE);
    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(other, 0.1f, 0.3f);
    func_802EFA70(other, 4);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, &this->position);
    func_802EFB70(other, local->unk0->unk4*1, local->unk0->unk4*6.0f);
    func_802EFB84(other, 0.5*local->unk0->unk4, local->unk0->unk4*3.0f);
    particleEmitter_setParticleSpawnPositionRange(other, 
        local->unk0->unk4*-300.0f, local->unk0->unk4*100.0f, local->unk0->unk4*-300.0f,
        local->unk0->unk4*300.0f, local->unk0->unk4*300.0f, local->unk0->unk4*300.0f
    );
    particleEmitter_setParticleVelocityRange(other, 
        -70.0f, 50.0f, -70.0f,
        70.0f, 100.0f, 70.0f
    );
    func_802EFFA8(other, &D_80390C60);
    func_802EFEC0(other, 3.0f, 4.0f);
    particleEmitter_emitN(other, 3*local->unk0->unkE);

}

void func_8038C70C(Actor *this){
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    ParticleEmitter *other = partEmitList_pushNew(0xa);

    func_802EF9F8(other, 0.6f);
    func_802EFA18(other, 3);
    func_802EFA70(other, 4);
    particleEmitter_setModel(other, 0x427);
    particleEmitter_setParticleSpawnPositionRange(other, 
        local->unk0->unk4 * -300.0f, local->unk0->unk4 * 100.0f, local->unk0->unk4 * -300.0f, 
        local->unk0->unk4 * 300.0f, local->unk0->unk4 * 200.0f, local->unk0->unk4 * 300.0f
    );
    particleEmitter_setPosition(other, &this->position);
    func_802EFB70(other, local->unk0->unk4*0.3, local->unk0->unk4*0.8);
    func_802EFE24(other, 
        -600.0f, -600.0f, -600.0f, 
        600.0f, 600.0f, 600.0f
    );
    particleEmitter_setSpawnIntervalRange(other, 0.0f, 0.01f);
    func_802EFEC0(other, 10.0f, 10.0f);
    particleEmitter_setVelocityAndAccelerationRanges(other, &D_80390C6C);
    particleEmitter_emitN(other, 10);

}

void func_8038C8A8(Actor * this){
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    ParticleEmitter *other = partEmitList_pushNew(5);
    f32 sp24[3];
    

    player_getPosition(&sp24);
    sp24[1] += 50.0f;

    particleEmitter_setSprite(other, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(other, 0.0, 0.5f);
    func_802EFA70(other, 4);
    particleEmitter_setStartingFrameRange(other, 0, 7);
    particleEmitter_setPosition(other, &sp24);
    func_802EFB70(other, local->unk0->unk4*1, local->unk0->unk4*3.0f);
    func_802EFB84(other, local->unk0->unk4*3.0f, local->unk0->unk4*6.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(other, &D_80390CA8);
    func_802EFEC0(other, 1.0f, 2.0f);
    func_802EFFA8(other, &D_80390C9C);
    particleEmitter_emitN(other, 5);
}

void func_8038C9F0(s32 arg0, s32 arg1, s32 arg2){
    Actor *actor = func_80326EEC(0x46);
    if(actor)
        marker_despawn(actor->marker);

    D_80391288[0] = (f32)arg0;
    D_80391288[1] = (f32)(arg1 + 0x28);
    D_80391288[2] = (f32)arg2;
    jiggySpawn(JIGGY_56_RBB_BOSS_BOOM_BOX, &D_80391288);
}

void func_8038CA70(Actor *this, f32(*arg1)[3]){
    f32 tmp_f;
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;

    tmp_f = local->unk0->unk4 * 300.0f;

    if( (*arg1)[0] - tmp_f < -1400.0f)
        (*arg1)[0] = -1400.0f + tmp_f;
    
    if(1400.0f < (*arg1)[0] + tmp_f)
        (*arg1)[0] = 1400.0f - tmp_f;

     if( (*arg1)[2] - tmp_f < -1200.0f)
        (*arg1)[2] = -1200.0f + tmp_f;
    
    if(1200.0f < (*arg1)[2] + tmp_f)
        (*arg1)[2] = 1200.0f - tmp_f;

}

void func_8038CB34(ActorMarker *marker, s32 arg1, s32 arg2){
    comusic_8025AB44(COMUSIC_62_RBB_BOOMBOX, -1, 0x12C);
}

void func_8038CB68(ActorMarker *marker, s32 arg1, s32 arg2){
    Actor *actor = marker_getActor(marker);
    func_80324E88(0.0f);
    func_80324E38(0.0f, 0);
    timedFunc_set_2(0.0f, (TFQM2)func_8038C370, actor->marker, 3);
}

void func_8038CBC0(void){
    Actor * actor = func_80326EEC(0x46);
    if(actor)
        func_802C8090(actor);
}

int func_8038CBF0(Actor *this){
    f32 sp2C[3];
    f32 sp20[3];
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    
    sp2C[0] = local->unk8[0];
    sp2C[1] = local->unk8[1];
    sp2C[2] = local->unk8[2];

    sp20[0] = local->unk14[0];
    sp20[1] = local->unk14[1];
    sp20[2] = local->unk14[2];

    sp2C[1] += 300.0f * local->unk0->unk4;
    sp20[1] += 300.0f * local->unk0->unk4;
    return func_803342AC(&sp2C, &sp20, local->unk0->unk4 * 400.0f);

}

void func_8038CC9C(Actor *this, s32 new_state){
    f32 sp8C[3];
    f32 sp80[3];
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    int i;
    f32 pad;
    f32 sp68[3];
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    
    
    
    player_getPosition(&sp8C);
    
    sp8C[1] = 0.0f;

    sp80[0] = sp8C[0] - this->position_x;
    sp80[1] = sp8C[1] - this->position_y;
    sp80[2] = sp8C[2] - this->position_z;
    if(this->state == 2){
        func_8038CBC0();
    }

    if(this->state == 7){
        actor_collisionOn(this);
    }

    local->unk8[0] = this->position_x;
    local->unk8[1] = this->position_y;
    local->unk8[2] = this->position_z;
    local->unk24 = local->unk28 = this->yaw;
    this->state = new_state;

    if(local->unk20){
        func_803343F8(local->unk20);
        local->unk20 = NULL;
    }
    
    if(this->state == 1){
        func_80335924(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.0f);
        func_80335A8C(this->unk148, 4);
    }

    if(this->state == 2){
        func_8025A58C(0, 0xfa0);
        func_8025A6EC(COMUSIC_62_RBB_BOOMBOX, -1);
        func_8025AABC(COMUSIC_62_RBB_BOOMBOX);
        func_80335924(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.4f);
        func_80335A8C(this->unk148, 2);
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, 0);
        timed_playSfx(0.5f, SFX_3F5_UNKNOWN, 1.0f, 0x7fc6);
        timed_playSfx(1.25f, SFX_6C_LOCKUP_CLOSING, 1.05f, 0x7d00);
        timed_playSfx(1.35f, SFX_6C_LOCKUP_CLOSING, 1.0f, 0x7d00);
        timed_playSfx(1.8f, SFX_6C_LOCKUP_CLOSING, 1.0f, 0x7d00);
        if(func_803203FC(2)){
            item_set(ITEM_6_HOURGLASS, 1);
            item_set(ITEM_0_HOURGLASS_TIMER, 0x1067);
            func_80324E88(2.4f);
            func_80324E38(2.4f, 0);
            timedFunc_set_2(2.4f, (TFQM2)func_8038C370, (s32)this->marker, 3);
        }
        else{//L8038CEFC
            timedFunc_set_3(2.4f, (TFQM3)comusic_8025AB44, COMUSIC_62_RBB_BOOMBOX, 0x1f40, 0x12C);
            func_80324DBC(2.4f, 0xb9e, 4, NULL, this->marker, func_8038CB34, func_8038CB68);
        }
    }//L8038CF60

    if(this->state == 3 || this->state == 4){
        func_8030E878(0x3f2, local->unk0->unk14, 0x6d60, &this->position, 500.0f, 1000.0f);
        func_80335924(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.2f, (1.0/(local->unk0->unk8)*randf2(1.0f, 1.1f)));
        func_80335A8C(this->unk148, 2);
        ml_vec3f_set_length(sp80, (this->state == 4)? -0x32*(2 + func_80326218()) : 300.0f/local->unk0->unk8);
        local->unk14[0] = sp80[0] + this->position_x;
        local->unk14[1] = sp80[1] + this->position_y;
        local->unk14[2] = sp80[2] + this->position_z;
        local->unk14[1] = 0.0f;
        func_8038CA70(this, &local->unk14);
    }//L8038D0B8

    if(this->state == 5){
        actor_collisionOff(this);
        timed_playSfx(0.2f, SFX_D9_WOODEN_CRATE_BREAKING_1, 0.9f, 0x7530);
        func_80335924(this->unk148, ASSET_148_ANIM_BOOMBOX_DIE, 0.2f, 1.0f);
        func_80335A8C(this->unk148, 2);
        ml_vec3f_set_length(sp80, -300.f);
        local->unk14[0] = sp80[0] + this->position_x;
        local->unk14[1] = sp80[1] + this->position_y;
        local->unk14[2] = sp80[2] + this->position_z;
        local->unk14[1] = 0.0f;
        func_8038CA70(this, &local->unk14);
        func_8038C70C(this);
        func_8038C538(this);
    }//L8038D17C

    if(this->state == 6){
        func_80326310(this);
        if(local->unk0->unk0 == 0x284){
            if(++D_80391280 == 8){
                func_8025A58C(-1, 0x190);
                comusic_8025AB44(COMUSIC_62_RBB_BOOMBOX, 0, 0x190);
                func_8025AABC(COMUSIC_62_RBB_BOOMBOX);
                if(func_803203FC(2)){
                    item_set(ITEM_6_HOURGLASS, 0);
                    func_803204E4(3, 0);
                    func_803204E4(5, 1);
                }
                else{//L8038D220
                    timedFunc_set_3(0.0f, (TFQM3)func_8038C9F0,  (s32)this->position_x, (s32)this->position_y, (s32)this->position_z);
                    func_80311480(0xb9f, 4, 0, 0, 0, 0);
                }
            }//L8038D278
        }
        else{//L8038D28C
            sp68[0] = this->position_x + 200.0f*local->unk0->unk4;
            sp68[1] = this->position_y + 80.0f*local->unk0->unk4;
            sp68[2] = this->position_z;
            func_802C3F04(func_802C4140, local->unk0->unk0 + 1,  reinterpret_cast(s32, sp68[0]), reinterpret_cast(s32, sp68[1]), reinterpret_cast(s32, sp68[2]));

            sp68[0] = this->position_x - 200.0f*local->unk0->unk4;
            sp68[1] = this->position_y + 80.0f*local->unk0->unk4;
            sp68[2] = this->position_z;
            func_802C3F04(func_802C4140, local->unk0->unk0 + 1, reinterpret_cast(s32, sp68[0]), reinterpret_cast(s32, sp68[1]), reinterpret_cast(s32, sp68[2]));
        }
    }//L8038D378

    if(this->state == 7){
        actor_collisionOff(this);
        func_803262E4(this);
        func_80335924(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.0f, 1.0f);
        func_80335A8C(this->unk148, 2);
        local->unk8[0] = this->position_x;
        local->unk8[1] = this->position_y;
        local->unk8[2] = this->position_z;

        local->unk14[0] = this->position_x;
        local->unk14[1] = this->position_y;
        local->unk14[2] = this->position_z;
        local->unk20 = func_8038CBF0(this);
    }//L8038D3FC

    if(this->state == 3 || this->state == 4 || this->state == 5){
        local->unk20 = func_8038CBF0(this);
        if( local->unk20 == 0){
            sp64 = local->unk0->unk4*300.0f;
            for(i = 0; i < 10; i++){
                local->unk14[0] = local->unk8[0] + randf2(-sp64, sp64);
                local->unk14[1] = local->unk14[1];
                local->unk14[2] = local->unk8[2] + randf2(-sp64, sp64);
                func_8038CA70(this, &local->unk14);
                local->unk20 = func_8038CBF0(this);
                if(local->unk20)
                    break;
            }
            if(i == 0xa){
                local->unk14[0] = local->unk8[0];
                local->unk14[2] = local->unk8[2];
                local->unk14[1] = 0.0f;
            }
        }
    }//L8038D4DC
    
    if(this->state == 3){
        func_80258A4C(&this->position, this->yaw - 90.0f, &sp8C, &sp60, &sp5C, &sp58);
        if(0.7 < sp58)
            local->unk28 += 90.0f;
        else if(sp58 < -0.7){
            local->unk28 -= 90.0f;
        }
    }
}

void func_8038D590(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    func_8038CC9C(actor, 4);
}

void func_8038D5BC(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &actor->local;

    func_8030E6A4(0x3f5, local->unk0->unk10, 0x4e20);
    func_8038CC9C(actor, 4);
    func_8038C8A8(actor);
}

void func_8038D608(ActorMarker *marker, ActorMarker *other){
    func_8038D7E8(marker, other->unk14_20 == 1);
}

Actor *func_8038D638(ActorMarker *marker, Gfx **gdl, Mtx ** mptr, s32 arg3){
    f32 sp3C[3];
    Actor *actor = func_80325300(marker, &sp3C);
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &actor->local;
    func_8033A45C(1, local->unk0->unkD);
    if(local->unk0->unkD == 1){
        func_8033A45C(2, (actor->state == 4)? 2: 1);
        func_8033A45C(4, (actor->state == 4)? 2: 1);
        func_8033A45C(5, (actor->state == 4)? 2: 1);
    }//L8038D714
    else{
        func_8033A45C(3, (actor->state == 4)? 2: 1);
        func_8033A45C(6, (actor->state == 4)? 2: 1);
        func_8033A45C(7, (actor->state == 4)? 2: 1);
    }
    func_8033A2D4(func_803253A0, actor);
    func_8033A2E8(func_80325794, marker);
    func_803391A4(gdl, mptr, &actor->position, &sp3C, actor->scale, NULL, func_80330B1C(marker));
    
    return actor;
}

void func_8038D7E8(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &actor->local;

    func_8030E8B4(0x7ff3881e, &actor->position, 0x07d003e8);
    func_8030E6A4(SFX_D7_GRABBA_DEATH, local->unk0->unk10, 0x7530);
    local->unk4 += (arg1) ? 1 : 5;
    if(local->unk4 >= local->unk0->unkC)
        func_8038CC9C(actor, 5);
    else{
        func_8038CC9C(actor, 4);
    }

    if(!arg1)
        func_8038C8A8(actor);

}

void func_8038D8B4(Actor *actor){}

void func_8038D8BC(Actor *this){
    f32 sp64[3];
    ActorLocal_RBB_5F80 *local = (ActorLocal_RBB_5F80 *) &this->local;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 tmp_f2;
    f32 pad;
    

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        local->unk0 = &D_80390B70[this->marker->unk14_20 - 0x1A1];
        local->unk4 = 0;
        local->unk20 = 0;
        
        this->marker->propPtr->unk8_3 = 0;
        this->scale = local->unk0->unk4;
        if(local->unk0 == D_80390B70){
            this->yaw = 270.0f;
        }
        marker_setCollisionScripts(this->marker, func_8038D590, func_8038D5BC, func_8038D608);
        func_803300D8(this->marker, func_8038D8B4);
        if(local->unk0->unk0 == 0x281){
            func_8038CC9C(this, 1);
            D_80391280 = 0;
        }
        else{
            func_8038CC9C(this, 7);
        }

        if(jiggyscore_isSpawned(JIGGY_56_RBB_BOSS_BOOM_BOX) && !func_803203FC(2))
            marker_despawn(this->marker);
        
        if(func_803203FC(2))
            func_8038CBC0();

        if(func_803203FC(0x1F)){
            func_8038CBC0();
            func_80335924(this->unk148, ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR, 0.0f, 2.4f);
            func_80335A8C(this->unk148, 2);
            this->state = 2;
        }
        return;
    }

    player_getPosition(&sp64);
    if(this->state == 1){
        if(func_803203FC(2)){
            if(func_803203FC(3)){
                func_8038CC9C(this, 2);
            }
        }
        else{//L8038DAA8
            if(func_80256064(&this->position, &sp64) < 1200.0f){
                func_8038CC9C(this, 2);
            }
        }
    }//L8038DAD8

    if(this->state == 2){
        if(func_8033567C(this->unk148) == ASSET_146_ANIM_BOSS_BOOMBOX_APPEAR && func_80335794(this->unk148) > 0){
            func_80335924(this->unk148, ASSET_147_ANIM_BOOMBOX_MOVE, 0.2, 1.0f);
            func_80335A8C(this->unk148, 1);
        }
    }//L8038DB30

    if( this->state == 2 || this->state == 3 || this->state == 4){
        if(func_8033567C(this->unk148) == ASSET_147_ANIM_BOOMBOX_MOVE){
            func_8033568C(this->unk148, &sp5C, &sp58);
            if(sp5C < 0.6 && 0.6 <= sp58){
                func_8030E878(SFX_6C_LOCKUP_CLOSING, randf2(-0.05f, 0.05f) + local->unk0->unk14, 0x4e20, &this->position, 500.0f, 1000.0f);
            }//L8038DC04
            if(sp5C < 0.1 && 0.1 <= sp58){
                func_8038C39C(this);
            }
        }
    }//L8038DC48

    if(this->state == 3 || this->state == 4){
        if(func_803203FC(2)){
            if(item_empty(ITEM_0_HOURGLASS_TIMER)){
                func_803204E4(3, 0);
                func_803204E4(5, 0);
                func_8038CC9C(this, 8);
            }
        }
        func_8033568C(this->unk148, &sp54, &sp50);
        if(0.1 <= sp50 && sp50 <= 0.6){
            sp4C = (sp50 - 0.1)/0.5;
            func_80255FE4(&this->position, &local->unk8, &local->unk14, sp4C);
            this->yaw = local->unk24 + sp4C*(local->unk28 - local->unk24);
        }

        if(func_80335794(this->unk148) > 0)
            func_8038CC9C(this, 3);
        
    }//L8038DD64

    if(this->state == 5){
        if(func_80335794(this->unk148) > 0){
            func_8038CC9C(this, 6);
        }else{
            tmp_f2 = func_80335684(this->unk148);
            if(tmp_f2 <= 0.3)
                tmp_f2 = tmp_f2/0.3;
            else
                tmp_f2 = 1.0f;
            func_80255FE4(&this->position, &local->unk8, &local->unk14, tmp_f2);
        }
    }//L8038DE10

    if(this->state == 7){
        if(func_80335794(this->unk148) > 0)
            func_8038CC9C(this, 3);
    }
}
