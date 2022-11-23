#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80324CFC(f32, s32, s32);
extern void func_80386654(f32 arg0, f32 arg1[4], f32 arg2[4]);
extern void func_8038E03C(f32*, u32);
extern Actor *func_80325CAC(ActorMarker*, Gfx**, Mtx**, Vtx **);
bool func_80320C94(f32 [3], f32[3], f32, f32[3], s32, u32);
f32 func_8033229C(ActorMarker *);
void func_8038CED8(f32 [3], s32, f32, f32);
void chbossjinjo_spawnParticles(Actor *, s32, s32, f32);

typedef struct {
    f32 unk0;
}ActorLocal_fight_87A0;

void func_8038F620(Actor *this);

/* .data */
ActorInfo fight_D_80391B00 = {
    MARKER_25C_GRUNTY_SPELL_FIREBALL, ACTOR_389_GRUNTY_SPELL_FIREBALL, ASSET_541_SPRITE_FIREBALL_SPELL_ATTACK,
    0x1, NULL,
    func_8038F620, func_80326224, func_80325888,
    0, 0, 1.0f, 0
};

ActorInfo D_80391B24 = {
    MARKER_280_GRUNTY_SPELL_GREEN_ATTACK, ACTOR_3AA_GRUNTY_SPELL_GREEN_ATTACK, ASSET_6C9_SPRITE_GREEN_SPELL_ATTACK,
    0x1, NULL,
    func_8038F620, func_80326224, func_80325CAC,
    0, 0, 1.0f, 0
};

s32 D_80391B48[3] = {0xBA, 0xBA, 0xBA};
struct42s D_80391B54 = {
    { {-70.0f, 50.0f, -70.0f}, {70.0f, 100.0f, 70.0f}},
    { {-55.0f, 0.0f, -55.0f}, {55.0f, 20.0f, 55.0f}}
};
f32 D_80391B84[4] = {1.0f, 1.0f, 1.0f, 1.0f};
f32 D_80391B94[4] = {0.3f, 0.3f, 0.3f, 1.0f};
s32 D_80391BA4[2] = {1, 9};
f32 D_80391BAC[4] = {4.5f, 4.5f, 4.5f, 4.5f};
f32 D_80391BBC[4] = {0.0f, 0.0f, 1.0f, 1.0f};
f32 D_80391BCC[4] = {0.0f, 0.0f, 0.85f, 1.35f};
f32 D_80391BDC[2] = {0.6f, 0.7f};
f32 D_80391BE4[6] = {-130.0f, 0.0f, -130.0f, 130.0f, 0.0f, 130.0f};
f32 D_80391BFC[4] = {1.1f, 1.1f, 4.0f, 5.4f};

f32 D_80391C0C[6] = {-20.0f, 0.0f, -20.0f, 20.0f, 40.0f, 20.0f};
f32 D_80391C24[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391C3C[6] = {-420.0f, 410.0f, -420.0f, 480.0f, 860.0f, 480.0f};
f32 D_80391C54[4] = {0.35f, 0.65f, 0.0f, 0.0f};
f32 D_80391C64[4] = {0.0f, 0.01f, 2.0f, 2.3f};
f32 D_80391C74[2] = {0.0f, 0.35f};

f32 D_80391C7C[6] = {0.0f, 50.0f, 0.0f, 0.0f, 50.0f, 0.0f};
f32 D_80391C94[4] = {0.0f, 0.0f, 0.0f, 0.0f}; 
f32 D_80391CA4[4] = {0.0f, 0.0f, 0.0f, 0.0f}; 
f32 D_80391CB4[2] = {0.0f, 0.0f}; 
f32 D_80391CBC[4] = {0.0f, 0.0f, 0.2f, 0.25f};
f32 D_80391DCC[2] = {2.3f, 2.5f};
f32 D_80391DD4[6] = {0.0f, 0.0f, 0.34f, 0.34f, 0.7f, 0.8f};

s32 D_80391CEC[2] = {2, 0xf};
f32 D_80391CF4[4] = {2.0f, 2.0f, 0.4f, 0.4f};
f32 D_80391D04[4] = {0.0f, 0.0f, 0.24f, 0.24f};
f32 D_80391D14[2] = {0.1f, 0.2f};
f32 D_80391D1C[4] = {0.0f, 0.0f, 0.44f, 0.44f};
f32 D_80391D2C[2] = {0.4f, 0.5f};
f32 D_80391D34[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

f32 D_80391D4C[6] = {-50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f};
f32 D_80391D64[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 D_80391D7C[6] = {-260.0f, -260.0f, -260.0f, 260.0f, 260.0f, 260.0f};
f32 fight_D_80391D94[4] = {0.15f, 0.3f, 0.0f, 0.0f}; 
f32 D_80391DA4[4] = {0.0f, 0.01f, 0.7f, 0.8f}; 
f32 D_80391DB4[2] = {0.0f, 0.65f}; 

/* .bss */
// u8 pad[0x180]; //TODO!!!! define other file .bss sections
u8 fight_D_803928E0;
u8 D_803928E1;
u8 D_803928E2;
u8 D_803928E3;
u8 D_803928E4;
u8 D_803928E5;

/* .code */
void func_8038EB90(ActorMarker *arg0, f32 *arg1) {
    Actor *temp_v0;

    temp_v0 = marker_getActor(arg0);
    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->position_y = temp_v0->position_y + 210.0f;
}

void func_8038EBE0(f32 arg0[3], u32 arg1, enum asset_e arg2, f32 arg3[6], f32 arg4[6], f32 arg5[6], f32 arg6[4], f32 arg7[4], f32 arg8[2]) {
    ParticleEmitter *temp_v0 = partEmitList_pushNew(arg1);

    particleEmitter_setSprite(temp_v0, arg2);
    particleEmitter_setStartingFrameRange(temp_v0, 1, 6);
    particleEmitter_setPosition(temp_v0, arg0);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, arg3[0], arg3[1], arg3[2], arg3[3], arg3[4], arg3[5]);
    particleEmitter_setParticleAccelerationRange(temp_v0, arg4[0], arg4[1], arg4[2], arg4[3], arg4[4], arg4[5]);
    particleEmitter_setParticleVelocityRange(temp_v0, arg5[0], arg5[1], arg5[2], arg5[3], arg5[4], arg5[5]);
    func_802EFE24(temp_v0, -300.0f, -300.0f, -300.0f, 300.0f, 300.0f, 300.0f);
    func_802EFB70(temp_v0, arg6[0], arg6[1]);
    func_802EFB84(temp_v0, arg6[2], arg6[3]);
    func_802EF9F8(temp_v0, 0.5f);
    func_802EFA18(temp_v0, 3);
    particleEmitter_setSpawnIntervalRange(temp_v0, arg7[0], arg7[1]);
    func_802EFEC0(temp_v0, arg7[2], arg7[3]);
    func_802EFA5C(temp_v0, arg8[0], arg8[1]);
    func_802EFA78(temp_v0, 1);
    func_802EFA70(temp_v0, 4);
    particleEmitter_emitN(temp_v0, arg1);
}

void func_8038ED9C(f32 arg0[3], u32 arg1, s32 arg2, s32 arg3[2], f32 arg4[6], f32 arg5[4], f32 arg6[4], f32 arg7[2]) {
    ParticleEmitter *temp_v0 = partEmitList_pushNew(arg2);

    particleEmitter_setSprite(temp_v0, arg1);
    particleEmitter_setStartingFrameRange(temp_v0, arg3[0], arg3[1]);
    particleEmitter_setParticleFramerateRange(temp_v0, 8.0f, 8.0f);
    particleEmitter_setPosition(temp_v0, arg0);
    particleEmitter_setParticleSpawnPositionRange(temp_v0, arg4[0], arg4[1], arg4[2], arg4[3], arg4[4], arg4[5]);
    particleEmitter_setParticleVelocityRange(temp_v0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_802EFB70(temp_v0, arg5[0], arg5[1]);
    func_802EFB84(temp_v0, arg5[2], arg5[3]);
    particleEmitter_setSpawnIntervalRange(temp_v0, arg6[0], arg6[1]);
    func_802EFEC0(temp_v0, arg6[2], arg6[3]);
    func_802EFA5C(temp_v0, arg7[0], arg7[1]);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    particleEmitter_emitN(temp_v0, arg2);
}

void func_8038EEFC(f32 arg0[3], u32 arg1, f32 *arg2) {
    ParticleEmitter *temp_v0 = partEmitList_pushNew(arg1);

    particleEmitter_setSprite(temp_v0, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFFA8(temp_v0, D_80391B48);
    func_802EF9E4(temp_v0, 0xEB);
    particleEmitter_setStartingFrameRange(temp_v0, 0, 7);
    particleEmitter_setPosition(temp_v0, arg0);
    particleEmitter_setPositionAndVelocityRanges(temp_v0, &D_80391B54);
    func_802EFB70(temp_v0, 0.1f, 0.2f);
    func_802EFB84(temp_v0, 3.6f, 4.6f);
    particleEmitter_setSpawnIntervalRange(temp_v0, arg2[0], arg2[1]);
    func_802EFEC0(temp_v0, arg2[2], arg2[3]);
    func_802EFA5C(temp_v0, 0.05f, 0.1f);
    func_802EFA70(temp_v0, 0x10);
    func_802EFA78(temp_v0, 1);
    particleEmitter_emitN(temp_v0, arg1);
}

void func_8038F01C(void) {
    func_80386654(1.0f, D_80391B94, D_80391B84);
}

void func_8038F050(void) {
    func_80386654(1.0f, D_80391B84, D_80391B94);
}

void func_8038F084(ActorMarker *marker){
    static f32 D_803928E8[3];
    Actor *actor = marker_getActor(marker);
    ActorLocal_fight_87A0 *local = (ActorLocal_fight_87A0 *)&actor->local;
    
    D_803928E8[0] = actor->position_x;
    D_803928E8[1] = actor->position_y;
    D_803928E8[2] = actor->position_z;
    
    D_803928E8[1] += 120.0f;

    if(actor->state != 2){//L8038F39C
        FUNC_8030E8B4(SFX_148_GRUNTY_SPELL_LANDING, 1.0f, 32000, actor->position, 1000, 3500);
        timedFunc_set_0(0.0f, func_8038F01C);
        timedFunc_set_0(0.3f, func_8038F050);
        actor->unk58_0 = 0;
        actor->scale *=  1.6;
        if(actor->marker->unk14_20 != MARKER_280_GRUNTY_SPELL_GREEN_ATTACK){
            func_8038EBE0(actor->position, 4, ASSET_713_SPRITE_SPARKLE_YELLOW, 
                D_80391C0C, D_80391C24, D_80391C3C,
                D_80391C54, D_80391C64, D_80391C74
            );
            func_8038EBE0(actor->position, 4, ASSET_715_SPRITE_SPARKLE_RED, 
                D_80391C0C, D_80391C24, D_80391C3C,
                D_80391C54, D_80391C64, D_80391C74
            );
            func_8038EEFC(actor->position, 3, D_80391BFC);
            func_8038ED9C(D_803928E8, ASSET_4A0_SPRITE_EXPLOSION, 1, D_80391BA4, D_80391BE4, 
                D_80391BAC,  D_80391BBC, D_80391BDC
            
            );
            D_803928E8[1] -= 50.0f;
            func_8038ED9C(D_803928E8, ASSET_6C1_SPRITE_SMOKE, 2, D_80391BA4, D_80391BE4, 
                D_80391BAC,  D_80391BBC, D_80391BDC
            
            );
        }
        else{//L8038F304
            func_8038EBE0(actor->position, 4, ASSET_713_SPRITE_SPARKLE_YELLOW, 
                D_80391C0C, D_80391C24, D_80391C3C,
                D_80391C54, D_80391BCC, D_80391C74
            );
            func_8038EEFC(actor->position, 3, D_80391BFC);
            func_8038CED8(actor->position, 0x558, 0.15f, 0.5f);
            actor->position_y += 260.0f;
            chbossjinjo_spawnParticles(actor, 0x712, ASSET_6C3_SPRITE_SMOKE_GREEN, 1.6f);
        }
        local->unk0 = 0.66f;
        func_80328A84(actor, 2);
    }//L8038F39C
}

void func_8038F3B4(ActorMarker *marker, ActorMarker *other){
    if( other->unk14_20 == 0x276
        || other->unk14_20 == 0x27A
        || other->unk14_20 == 0x27F
    ) return;

    func_8038F084(marker);
    switch(func_80320424(0x23, 3)){
        case 1: //8038F41C
            if(!fight_D_803928E0 && func_80311480(randi2(0, 5) + 0x10f2, 0, 0, 0, 0, 0))
                fight_D_803928E0 = 1;
            break;
        case 2: //8038F468
            if(!D_803928E1 && func_80311480(randi2(0, 5) + 0x110b, 0, 0, 0, 0, 0))
                D_803928E1 = 1;
            break;
        case 3: //8038F4B4
            if(!D_803928E2 && func_80311480(randi2(0, 5) + 0x1122, 0, 0, 0, 0, 0))
                D_803928E2 = 1;
            break;
        case 4: //8038F500
            if( !D_803928E3 
                && func_8038C2A4()
                && func_80311480(randi2(0, 5) + 0x113b, 0, 0, 0, 0, 0)
            )
                D_803928E3 = 1;
            break; 
        case 5:
            if( !D_803928E4 
                && func_8038C2B0()
                && func_80311480(randi2(0, 5) + 0x1154, 0, 0, 0, 0, 0)
            )
                D_803928E4 = 1;
            break; 
    }//L8038F5B0

}

s32 func_8038F5BC(f32 *arg0, f32 arg1) {
    if (((arg0[0] * arg0[0]) + (arg0[2] * arg0[2])) < arg1) {
        return 1;
    }
    return 0;
}

void func_8038F5F8(Actor *arg0) {
    func_80324D2C(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER);
}

void func_8038F620(Actor *this){
    static f32 D_803928F8[3];
    static f32 D_80392908[3];
    static f32 D_80392914;

    ActorLocal_fight_87A0 * local = (ActorLocal_fight_87A0 *)&this->local;
    f32 sp40 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = 1;
        marker_setCollisionScripts(this->marker, NULL, NULL, func_8038F3B4);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        this->unk60 = 8.0f;
        this->scale = 0.1f;
        if( this->marker->unk14_20 == MARKER_280_GRUNTY_SPELL_GREEN_ATTACK){
            actor_collisionOff(this);
            func_803300D8(this->marker, func_8038F5F8);
            func_80324CFC(0.0f, COMUSIC_43_ENTER_LEVEL_GLITTER, 32000);
            timed_playSfx(0.0f, SFX_113_PAD_APPEARS, 1.0f, 32000);
            timed_playSfx(0.75f, 0x415, 1.0f, 32000);
            timed_playSfx(2.0f, 0x415, 1.0f, 32000);


        }
        else{//L8038F738
            func_80324D54(0.26f, SFX_14F_FIREWORK_WHISTLING, 1.0f, 0x61A8,
                this->position, 1000.0f, 7500.0f
            );

            func_80324D54(0.4f, SFX_14E_SOFT_EXPLOSION, 1.0f, 0x61A8,
                this->position, 500.0f, 4500.0f
            );
        }
    }//L8038F79C
    if(D_803928E5 && this->marker->unk14_20 == MARKER_280_GRUNTY_SPELL_GREEN_ATTACK){
        func_802BAD08(this->position);
    }//L8038F7D4

    switch(this->state){
        case 1://L8038F7F8
            D_80392914 = sp40*1.4;
            this->scale = (this->scale + D_80392914 < 1.0) ? this->scale + D_80392914 : 1.0f;

            switch(this->marker->unk14_20){
                case MARKER_25C_GRUNTY_SPELL_FIREBALL://L8038F8AC
                    func_8038ED9C(this->position, ASSET_4A0_SPRITE_EXPLOSION, 1, 
                        D_80391CEC, D_80391D34, 
                        D_80391CF4, D_80391D04, D_80391D14
                    );
                    break;
                case MARKER_280_GRUNTY_SPELL_GREEN_ATTACK://L8038F8C8
                    func_8038ED9C(this->position, ASSET_6C9_SPRITE_GREEN_SPELL_ATTACK, 1, 
                        D_80391CEC, D_80391D34, 
                        D_80391CF4, D_80391D1C, D_80391D2C
                    );
                    func_8023DB5C();
                    break;
            }//L8038F918
            D_803928F8[0] = this->position[0];
            D_803928F8[1] = this->position[1];
            D_803928F8[2] = this->position[2];

            this->position[0] +=  this->velocity_x*sp40;
            this->position[1] +=  this->velocity_y*sp40;
            this->position[2] +=  this->velocity_z*sp40;

            this->velocity[0] += this->unk1C[0]*sp40;
            this->velocity[1] += this->unk1C[1]*sp40;
            this->velocity[2] += this->unk1C[2]*sp40;

            this->pitch +=  200.0f*sp40;
            this->yaw += 200.0f*sp40;

            if( this->position_y < -2500.0f 
                || 5000.0f < this->position_y
                || !func_8038F5BC(this->position, 100000000.0f)
            ){
                marker_despawn(this->marker);
            }
            else{
                if(this->position_y < 300.0f
                    && func_8038F5BC(this->position, 16000000.0f)
                ){
                    if(func_80320C94(D_803928F8, this->position, func_8033229C(this->marker), D_80392908, 8, 0x40000000)){
                        func_8038F084(this->marker);
                        return;
                    }
                }
            }
            // L8038FABC
            if( this->marker->unk14_20 != MARKER_280_GRUNTY_SPELL_GREEN_ATTACK
                && func_8028F25C()
            ){
                func_8038F084(this->marker);
            }
            else {
                if(0.0 <= this->unk60){
                    this->unk60 -= sp40;
                }else{
                    func_8038F084(this->marker);
                }
            }
            break;
        case 2://L8038FB34
            if(local->unk0 < 0.0){
                marker_despawn(this->marker);
            }else{
                local->unk0 -= sp40;
            }
            break;
    }//L8038FB74
}

void fight_func_8038FB84(ActorMarker *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    Actor *temp_v0 = marker_getActor(arg0);

    temp_v0->position_x = arg1[0];
    temp_v0->position_y = arg1[1];
    temp_v0->position_z = arg1[2];
    temp_v0->velocity_x = arg2[0];
    temp_v0->velocity_y = arg2[1];
    temp_v0->velocity_z = arg2[2];
    temp_v0->unk1C_x = arg3[0];
    temp_v0->unk1C_y = arg3[1];
    temp_v0->unk1C_z = arg3[2];
}

void func_8038FC00(void) {
    fight_D_803928E0 = (u8)0;
    D_803928E1 = (u8)0;
    D_803928E2 = (u8)0;
    D_803928E3 = (u8)0;
    D_803928E4 = (u8)0;
}

void func_8038FC2C(s32 arg0) {
    D_803928E5 = arg0;
}
