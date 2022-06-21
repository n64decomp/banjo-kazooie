#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

extern f32 func_8038BE20(f32 arg0[3]);

typedef struct {
    ParticleEmitter *unk0;
    ParticleEmitter *unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8  unk18;
    u8  unk19;
}ActorLocal_FP_2350;

typedef struct {
    s32 unk0;
    s32 actor_id;
}Struct_FP_2350;

Actor *func_80388740(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80388D70(ActorMarker *caller, enum asset_e text_id, s32 arg2);
void func_80388EE8(ParticleEmitter *pCtrl);
void func_80388F4C(Actor *this);
void func_803896FC(Actor *this);

/* .data */
ActorAnimationInfo D_80391C80[] = {
    {0x000, 0.0f},
    {0x150, 0.6f},
    {0x150, 0.6f},
    {0x150, 0.6f},
    {0x150, 0.6f},
    {0x179, 2.3f},
    {0x17A, 1.3f},
    {0x17B, 2.0f},
    {0x150, 1.0f},
    {0x1AA, 4.3f},
    {0x1AB, 4.3f},
    {0x150, 1.0f},
    {0x150, 0.6f}
};

ActorInfo D_80391CE8 = { 0x97, ACTOR_C8_BOGGY_2, ASSET_38A_MODEL_BOGGY_1, 
    0x1, D_80391C80, 
    func_80388F4C, func_803896FC, func_80388740, 
    0, 0, 1.4f, 0
};
f32 D_80391D0C[3] = {1842.0f, 658.0f, 5758.0f};
f32 D_80391D18[3] = {1463.0f, 635.0f, 5193.0f};
s32 D_80391D24[3] = {0xc8, 0xc8, 0xe6};
struct31s D_80391D30 = {
    {0.2f, 0.4f},
    {1.2f, 1.6f},
    {0.0f, 0.001f},
    {0.3f, 0.45f},
    0.0f, 0.01f
};

struct42s D_80391D58 = {
    {{-10.0f, 10.0f}, {-10.0f, 10.0f}, {240.0f, 10.0f}},
    {{0.0f, 0.0f, 0.0f}, {0.0f, 20.0f, 0.0f}}
};

f32 D_80391D88[3] = { 1592.0f, 673.0f, 5895.0f};
f32 D_80391D94[3] = {0.0f, 0.0f, 0.0f};
s32 D_80391DA0[3] = {0x5F5, 0x292, 0x1539};
s32 D_80391DAC[3] = {-0x11F8, 0x637, -0x1816};
Struct_FP_2350 D_80391DB8[7]={
    {0x361, 0x35D},
    {0x365, 0x35D},
    {0x362, 0x360},
    {0x366, 0x35D},
    {0x37B, 0x35D},
    {0x363, 0x35F},
    {0x364, 0x35E}
};

f64 D_80392CB8;

s32 D_80392F20[3];

/* .code */
Actor *func_80388740(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    ActorLocal_FP_2350 * local = (ActorLocal_FP_2350 *) &this->local;
    f32 sp2C[3];

    func_8033A45C(1, 1);
    func_8033A45C(3, 1);
    this = func_80325888(marker, gfx, mtx, vtx);
    if(this->unk16C_4 && marker->unk14_21){
        if( this->state == 4
            || this->state == 5
            || this->state == 6
            || this->state == 8
        ){
            if(this->unk4C != 0.0f && (func_8023DB5C() & 1)){
                if(-2.0 < this->roll){
                    func_8034A174(func_80329934(), 6, sp2C);
                    particleEmitter_setPosition(local->unk0, sp2C);
                    particleEmitter_emitN(local->unk0, 1);
                }

                if(this->roll < 2.0){
                    func_8034A174(func_80329934(), 7, sp2C);
                    particleEmitter_setPosition(local->unk4, sp2C);
                    particleEmitter_emitN(local->unk4, 1);
                }
            }
        }//L803888D4
    }
    return this;
}

void func_803888E4(Actor *this){
    func_80328B8C(this, 0xC, 0.0001f, 1);
    if(!jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2)){
        if(mapSpecificFlags_get(5)){
            func_80324DBC(0.1f, 0xc06, 0x2a, D_80391D18, this->marker, func_80388D70, NULL);
        }
        else{//L80388964
            func_80324DBC(0.1f, 0xc03, 0x2a, D_80391D18, this->marker, func_80388D70, NULL);
        }
    }
    else{//L803889A0
        func_8028F490(D_80391D0C);
        if(mapSpecificFlags_get(6)){
            func_80324DBC(0.1f, 0xc29, 0x2a, D_80391D18, this->marker, func_80388D70, NULL);
        }
        else{
            func_80324DBC(0.1f, 0xc28, 0x2a, D_80391D18, this->marker, func_80388D70, NULL);
        }
    }//L80388A30
    mapSpecificFlags_set(5, TRUE);
    func_8038B9C8();
}

void func_80388A50(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;

    func_80328B8C(this, 2, 0.0001f, 1);
    timed_setCameraToNode(0.0f, 4);
    local->unk18 = 0;
}

void func_80388A94(Actor *this){
    func_80388A50(this);
    if(mapSpecificFlags_get(6)){
        func_80311480(0xc0a, 0xe, this->position, this->marker, func_80388D70, NULL);
    }
    else{
        func_80311480(0xc09, 0xe, this->position, this->marker, func_80388D70, NULL);
    }
}

void func_80388B18(Actor *this, u8 arg1){
    if(arg1 == TRUE){
        if(player_getTransformation() == TRANSFORM_4_WALRUS){
            func_80388A50(this);
            if(mapSpecificFlags_get(5)){
                func_80311480(0xc05, 0xf, this->position, this->marker, func_80388D70, NULL);
            }
            else{
                func_80311480(0xc02, 0xf, this->position, this->marker, func_80388D70, NULL);
            }
        }
        else{//L80388BB8
            if(!func_803203FC(0xb3)){
                if(func_80311480(0xc01, 0xe, this->position, this->marker, func_80388D70, NULL)){
                    func_803204E4(0xb3, TRUE);
                    func_80388A50(this);
                }
            }
        }
    }
    else{//L80388C08
        if(player_getTransformation() == TRANSFORM_4_WALRUS){
            if(!func_803203FC(0xb4)){
                if(func_80311480(0xc08, 0xe, this->position, this->marker, func_80388D70, NULL)){
                    func_803204E4(0xb4, TRUE);
                    func_80388A50(this);
                }
            }
        }
        else{
            func_80388A94(this);
        }
    }
}

void func_80388C88(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;

    this->unk10_12 = 0;
    local->unk18 = 1;
}

bool func_80388CA0(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;
    u32 sp20;

    if(func_8028ECAC() != 0 && func_8028ECAC() != 8)
        return FALSE;

    if( !func_80329530(this, 1100) ){
        local->unk18 = TRUE;
    }

    sp20 = this->unk10_12;
    this->unk10_12 = func_80329530(this, 0x1C2);
    return (sp20 == 0 && this->unk10_12 && local->unk18);
}

void func_80388D70(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;

    func_80324E88(0.0f);
    switch(text_id){
        case 0xc03:
        case 0xc06:
        case 0xc28:
        case 0xc29://L80388DC4
            func_8025A6EC(COMUSIC_3A_FP_BOGGY_RACE, 25000);
            func_8025A58C(0, 4000);
            func_8024BD08(0);
            func_802BE720();
            local->unk0 = partEmitList_pushNew(16);
            local->unk4 = partEmitList_pushNew(16);
            func_80388EE8(local->unk0);
            func_80388EE8(local->unk4);
            func_80328B8C(this, 4, 0.0001f, 1);
            local->unk14 = (local->unk19 == 2) ? 1.0f : 0.0f;
            this->marker->unk40_23 = TRUE;
            break;
        default://L80388E78
            switch(arg2){
                case 1:
                    func_803888E4(this);
                    mapSpecificFlags_set(6, TRUE);
                    break;
                case 0:
                    func_80328B8C(this, 1, 0.0001f, 1);
                    break;
                default:
                    func_80328B8C(this, 1, 0.0001f, 1);
                    break;
            }
            break;
    }
}

void func_80388EE8(ParticleEmitter *pCtrl){
    particleEmitter_setSprite(pCtrl, ASSET_700_SPRITE_DUST);
    func_802EFFA8(pCtrl, D_80391D24);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_80391D58);
    func_802EFB98(pCtrl, &D_80391D30);
    func_802F0D54(pCtrl);
}

void func_80388F4C(Actor *this){}

void func_80388F54(ActorMarker *marker){
    Actor *other  = func_80328230(ACTOR_C8_BOGGY_2, D_80391D88, D_80391D94);
    func_80343DEC(other);
}

void func_80388F90(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;

    func_8030DB04(this->unk44_31, 32000, this->position, 1000.0f, 4000.0f);
    func_8030DBB4(this->unk44_31, local->unk8);
    func_8030E2C4(this->unk44_31);
}

bool func_80388FE8(Actor *this, f32 arg1, f32 arg2){
    if(arg2 < 0.0f && 0.0f < arg1){
        func_8030E878(SFX_8D_BOGGY_OHWW, randf2(1.04f, 1.12f), 32000, this->position, 600.0f, 1200.0f);
        return TRUE;
    }
    else if( 0.0f < arg2 && arg1 < 0.0f){
        func_8030E878(SFX_F9_GRUNTLING_NOISE_1, randf2(1.04f, 1.12f), 32000, this->position, 600.0f, 1200.0f);
        return TRUE;
    }
    return FALSE;
}

void func_803890DC(Actor *this, u8 arg1){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;

    f32 yaw_to_target;
    f32 yaw;
    f32 f16;
    f32 prev_roll;
    f32 dyaw;

    yaw_to_target = (this->unk1C[0]  < 180.0f) ? this->unk1C[0] : this->unk1C[0] - 360.0f;
    yaw = (this->yaw  < 180.0f) ? this->yaw : this->yaw - 360.0f;

    prev_roll = this->roll;
    f16 = (arg1 == 2) ? 1100.0f : 780.0f;
    dyaw = yaw - yaw_to_target;
    dyaw = (180.0f < dyaw) ? 360.0f - dyaw 
        : (dyaw < -180.0f) ? 360.0f + dyaw 
        : dyaw;

    this->roll += (2.0*dyaw)*(this->unk4C / f16);

    this->roll = (26.0f < this->roll)  ?  26.0f
               : (this->roll < -26.0f) ? -26.0f
               : this->roll;

    this->roll += (this->roll < 0.0f) ?  1.8 
                : (0.0f < this->roll) ? -1.8 
                : 0.0;
                
    if(local->unk10 == 0.0){
        if(this->state != 9 && this->state != 10 && this->state != 11){
            if( (23.0f < this->roll && prev_roll < 23.0f)
                || (this->roll < -23.0f && -23.0f < prev_roll)
            ){//L8038933C
                func_8030E878(SFX_8C_BOGGY_WAHEY, randf2(1.04f, 1.12f), 32000, this->position, 600.0f, 1500.0f);
                local->unk10 = 1.5f;
            }//L80389394
        }
    }//L80389398

    if(this->roll <= 1.8 && -1.8 <= this->roll){
        this->roll = 0.0f;
    }
}

void func_803893E4(Actor *this, f32 arg1, u8 arg2){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    if((u8)arg2 != 2){
        sp30 = 575.0f;
        sp2C = 780.0f;
        sp28 = 1.7f;
    }
    else{
        sp30 = 700.0f;
        sp2C = 1100.0f;
        sp28 = 2.3f;
    }

    func_80343DEC(this);
    if(this->state == 7){
        this->unk4C += ((f32)D_80392F20[1] - this->position_y)*0.02;
    }
    else{
        this->unk4C += ((f32)D_80392F20[1] - this->position_y)*0.03 + sp28*func_8038BE20(this->position);
    }

    if(this->unk4C < sp30){
        this->unk4C = sp30;
    }
    if(sp2C < this->unk4C){
        this->unk4C = sp2C;
    }

    if((u8)arg2 == 2 && func_8028ECAC() != 6){
        this->unk4C = 1200.0f;
    }

    local->unk8 = ((this->unk4C - sp30)/(sp2C - sp30))*(0.6000000000000001) + 0.7;
    func_803890DC(this, (u8)(arg2));
}

void func_803895E0(void){
    int i;
    s16 *s0;
    f32 sp64[3];
    Actor *actor;
    f32 f20;
    f32 f22;
    f32 f8;

    for (i = 0; i< 7; i++){
        s0 = (i < 3) 
            ? func_803049CC(D_80391DB8[i].unk0, D_80391DA0) 
            : func_803049CC(D_80391DB8[i].unk0, D_80391DAC);

        func_80304D68(s0, sp64);
        f20 = (f32)func_80304DA8(s0);
        f8 = (f32)func_80304DB8(s0);
        f22 = f8*0.01;
        actor = func_8032813C(D_80391DB8[i].actor_id, sp64, (s32)f20);
        actor->scale = f22;
    }
}

void func_803896FC(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;
    f32 sp58;
    f32 sp54;
    s32 sp3C[6];
    
    sp58 = func_8038BE20(this->position);
    sp54 = time_getDelta();
    func_8024E55C(0, sp3C);
    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->unk40_23 = FALSE;
        this->marker->propPtr->unk8_3 = FALSE;
        this->marker->unk2C_1 = TRUE;
        this->unk44_31 = func_8030ED2C(SFX_18_BIGBUTT_SLIDE, 2);
        D_80392F20[0] = this->position_x;
        D_80392F20[1] = this->position_y;
        D_80392F20[2] = this->position_z;
        this->unk1C[0] = this->yaw;
        local->unk0 = NULL;
        local->unk4 = NULL;
       local->unk8 = 0.0f;
       local->unkC = 0.0f;
       local->unk10 = 0.0f;
       local->unk8 = 1.0f;
        func_8038B9B0(this->marker);
        this->unk38_31 = 0;
        func_80388C88(this);
        func_802C3BF8(func_803895E0);
        if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
            local->unk19 = 2;
            this->unk4C = 900.0f;
        }
        else if(jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2)){
            local->unk19 = 1;
            this->unk38_31 = 2;
            this->unk4C = 600.0f;
            func_80328B8C(this, 11, 0.0001f, 1);
        }
        else{
            local->unk19  = 1;
            this->unk4C = 600.0f;
            mapSpecificFlags_set(4, TRUE);
        }
    }//L803898CC

    func_8028E668(this->position, 200.0f, -200.0f, 140.0f);
    if(!func_8038A1A0(this->marker)){
        switch(this->unk38_31){
            case 1://L80389920
                func_80328B8C(this, 9, 0.0001f, 1);
                break;
            case 2://L80389938
                func_80328B8C(this, 10, 0.0001f, 1);
                break;
        }
    }//L80389950

    if(0.0 <local->unk10 - sp54)
       local->unk10 =local->unk10 - sp54;
    else
       local->unk10 = 0.0f;

    switch(this->state){
        case 1:// L803899B8
            if(func_80388CA0(this)){
                func_80388B18(this, local->unk19);
            }//L803899DC
            else if(!jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && func_8028ECAC() == 12){
                func_803888E4(this);
            }
            else if( func_80329530(this, 0x1C2)
                && !func_8028ECAC()
                && func_8028F20C()
                && func_8028EFC8()
                && sp3C[1] == 1
                && !func_803114B0()
            ){
                if( local->unk19 == 1 
                    && player_getTransformation() != TRANSFORM_4_WALRUS
                    && func_803203FC(0xb3)
                ){
                    func_80311480(0xC01, 0xf, this->position, this->marker, func_80388D70, NULL);
                }
                else if( local->unk19 == 2){
                    if( player_getTransformation() == TRANSFORM_4_WALRUS
                        && func_803203FC(0xb4)
                    ){
                        func_80311480(0xC08, 0xf, this->position, this->marker, func_80388D70, NULL);
                    }
                    else if( player_getTransformation() != TRANSFORM_4_WALRUS){
                        func_80388A94(this);
                    }
                }
            }
            break;

        case 4:// L80389B50
            if(0.0 < local->unk14){
                local->unk14 -= sp54;
            }
            else{
                local->unk14 = 0.0f;
                if( randf() < 0.02 && sp58 < 0.0){
                    if(randf() < 0.5)
                        func_80328B8C(this, 5, 0.0001f, 1);
                    else
                        func_80328B8C(this, 6, 0.0001f, 1);
                }//L80389C18

                func_803893E4(this, sp58, local->unk19);
                func_80388F90(this);
                if(0.0 ==local->unk10 && func_80388FE8(this, sp58,local->unkC)){
                   local->unk10 = 1.5f;
                }
            }//L80389C78
            break;

        case 5:// L80389C80
        case 6:// L80389C80
            if(actor_animationIsAt(this, 0.9999f) || sp58 >= 0.0){
                func_80328B8C(this, 4, 0.0001f, 1);
            }//L80389CC8
            
            func_803893E4(this, sp58, local->unk19);
            func_80388F90(this);
            if(0.0 == local->unk10 && func_80388FE8(this, sp58, local->unkC)){
                local->unk10 = 1.5f;
            }
            break;

        case 7:// L80389D34
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 4, 0.0001f, 1);
            }//L80389D60
            func_803893E4(this, sp58, local->unk19);
            func_80388F90(this);
            break;

        case 8:// L80389D84
            func_80343DEC(this);
            if(this->unk4C < 740.0f){
                this->unk4C += 10.0f;
            }
            else if(740.0f < this->unk4C) {
                this->unk4C -= 10.0f;
            }
            func_803890DC(this, local->unk19);
            func_80388F90(this);
            if(0.0 == local->unk10 && func_80388FE8(this, sp58, local->unkC)){
                local->unk10 = 1.5f;
            }

            break;

        case 9:// L80389E48
            func_803893E4(this, sp58, local->unk19);
            if(this->unk48 < 0.99999999999){
                func_80388F90(this);
            }
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 11, 0.0001f, 1);
            }
            break;

        case 10:// L80389EB4
            func_803893E4(this, sp58, local->unk19);
            if(this->unk48 < 0.99999999999){
                func_80388F90(this);
            }

            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 11, 0.0001f, 1);
            }
            break;

        case 11:// L80389F20
            func_803890DC(this, local->unk19);
            
            if(!actor_playerIsWithinDist(this, 2000)
                && !this->marker->unk14_21
            ){
                switch(local->unk19){
                    case 1: //L80389F78
                        if(this->unk38_31 == 2){
                            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
                                func_802C3C88(func_80388F54, this->marker);
                                func_8038B9BC();
                                marker_despawn(this->marker);
                            }
                        }
                        else{
                            func_8038B9BC();
                            marker_despawn(this->marker);
                        }

                        break;

                    case 2: //L80389FDC
                        if(this->unk38_31 == 2){
                            if(jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
                                func_8038B9BC();
                                marker_despawn(this->marker);
                                mapSpecificFlags_set(0xC, TRUE);
                            }
                        }
                        else{
                            func_8038B9BC();
                            marker_despawn(this->marker);
                        }
                        break;
                }
            }
            break;
    }//L8038A034

    D_80392F20[0] = (s32)this->position[0];
    D_80392F20[1] = (s32)this->position[1];
    D_80392F20[2] = (s32)this->position[2];
    this->unk1C[0] = this->yaw;
    local->unkC = sp58;
}

void func_8038A09C(f32 arg0[3]){
    arg0[0] = (f32)D_80392F20[0];
    arg0[1] = (f32)D_80392F20[1];
    arg0[2] = (f32)D_80392F20[2];
}

void func_8038A0E4(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor){
        if(actor->state != 7){
            func_80328B8C(actor, 7, 0.0001f, 1);
        }
        else{
            func_80328B8C(actor, 4, 0.0001f, 1);
        }
    };
}

void func_8038A150(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor && actor->state != 8){
        func_80328B8C(actor, 8, 0.0001f, 1);
    };
}

bool func_8038A1A0(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    switch (actor->state){
        case 9:
        case 10:
        case 11:
            return TRUE;
        default:
            return FALSE;
    }
}
