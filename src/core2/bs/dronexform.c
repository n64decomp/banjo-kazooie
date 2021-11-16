#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void player_setYPosition(f32);
void func_8024E3A8(f32 (*)[3], f32);
void func_802991FC(void);
void func_802978DC(int);
f32 func_80257A44(f32, f32);
f32 cosf(f32);
f32 func_802588B0(f32, f32);

extern struct41s D_80364BB0;
extern struct41s D_80364BE0;
extern struct41s D_80364C10;
extern struct41s D_80364C40;
extern struct41s D_80364C70;
extern struct41s D_80364CA0;

extern struct {
    ParticleEmitter *unk0;
    ParticleEmitter *unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    u8 unk1C;
    u8 pad1D[0x3];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    u8 unk30;
    u8 unk31; //enum bs_e
    u8 unk32;
} D_8037D470;



void func_802AF7A0(ParticleEmitter *arg0, enum asset_e arg1){
    func_802F0D54(arg0);
    particleEmitter_setSprite(arg0, arg1);
    particleEmitter_setParticleAccelerationRange(arg0, 0.0f, -50.0f, 0.0f, 0.0f, -50.0f, 0.0f);
    func_802EFA5C(arg0, 0.4f, 0.8f);
    func_802EFB84(arg0, 0.03f, 0.03f);
    func_802EFE24(arg0, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    func_802EFEC0(arg0, 0.65f, 0.65f);
    func_802EFF50(arg0, 1.0f);
}

void func_802AF88C(Actor * arg0, f32 arg1, f32 arg2){
    particleEmitter_setParticleVelocityRange(arg0, arg1*30.0f, 10.0f, arg2*30.0f, arg1*30.0f, 10.0f, arg2*30.0f);
    func_802EFB70(arg0, D_8037D470.unk14, D_8037D470.unk14);
}

void func_802AF900(void){
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp30[3];

    player_getPosition(&sp30);
    sp3C = D_8037D470.unk8;
    sp48 = func_80257A44(sp3C, 0.38f);
    sp4C = sp48 * 6.283185308;
    sp40 = sinf(sp4C);
    sp44 = cosf(sp4C);
    sp30[0] += sp40 * D_8037D470.unk18;
    sp30[1] += func_80257C48(func_80257A44(sp3C, 1.14f), 0.0f, 130.0f);
    sp30[2] += sp44 * D_8037D470.unk18;
    func_802AF88C(D_8037D470.unk4, sp40, sp44);
    particleEmitter_setPosition(D_8037D470.unk4, &sp30);
    particleEmitter_emitN(D_8037D470.unk4, 1);

    player_getPosition(&sp30);
    sp4C = (1.0 - func_802588B0(sp48 + 0.5, 1.0f))* 6.283185308;
    sp30[0] -= sinf(sp4C) * D_8037D470.unk18;
    sp30[1] += func_80257C48(func_80257A44(sp3C, 1.14f), 130.0f, 0.0f);
    sp30[2] -= cosf(sp4C) * D_8037D470.unk18;
    func_802AF88C(D_8037D470.unk0, sp40, sp44);
    particleEmitter_setPosition(D_8037D470.unk0, &sp30);
    particleEmitter_emitN(D_8037D470.unk0, 1);
}

void func_802AFADC(void){
    func_802F0C78(D_8037D470.unk4);
    func_802F0C78(D_8037D470.unk0);
}

void func_802AFB0C(void){
    D_8037D470.unk0 = func_802F0BD0(0x32);
    func_802AF7A0(D_8037D470.unk0, ASSET_476_SPRITE_BLUE_GLOW); //blue glow

    D_8037D470.unk4 = func_802F0BD0(0x32);
    func_802AF7A0(D_8037D470.unk4, ASSET_477_SPRITE_YELLOW_GLOW); //orange glow

    D_8037D470.unkC = 1.0f;
    D_8037D470.unk10 = 0.0f;
    D_8037D470.unk8 = 0.0f;
    D_8037D470.unk18 = 55.0f;
    D_8037D470.unk14 = 0.35f;
    D_8037D470.unk1C = 0;
}

void func_802AFB94(f32 arg0){
    D_8037D470.unkC = arg0;
}

void func_802AFBA0(f32 arg0){
    D_8037D470.unk18 = arg0;
}

void func_802AFBAC(f32 arg0){
    D_8037D470.unk14 = arg0;
}

void func_802AFBB8(f32 (* arg0)[3]){
    ParticleEmitter* s0 = func_802F0BD0(1);
    particleEmitter_setSprite(s0, ASSET_6C4_SPRITE_SMOKE_YELLOW); //yellow blast
    func_802EFA5C(s0, 0.7f, 0.8f);
    particleEmitter_setParticleFramerateRange(s0, 12.0f, 12.0f);
    particleEmitter_setPosition(s0, arg0);
    func_802EFB70(s0, 3.2f, 3.2f);
    func_802EFB84(s0, 3.2f, 3.2f);
    func_802EFEC0(s0, 0.8f, 0.8f);
    particleEmitter_emitN(s0, 1);
    
    s0 = func_802F0BD0(1);
    particleEmitter_setSprite(s0, ASSET_6C2_SPRITE_SMOKE_WHITE); //smoke
    func_802EFA5C(s0, 0.1f, 0.8f);
    particleEmitter_setParticleFramerateRange(s0, 15.0f, 15.0f);
    particleEmitter_setPosition(s0, arg0);
    func_802EFB70(s0, 3.0f, 3.0f);
    func_802EFB84(s0, 3.0f, 3.0f);
    func_802EFEC0(s0, 0.65f, 0.65f);
    particleEmitter_emitN(s0, 1);

    s0 = func_802F0BD0(0x11);
    particleEmitter_setSprite(s0, ASSET_713_SPRITE_SPARKLE_YELLOW); //sparkle
    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364BB0);
    func_802EFA5C(s0, 0.0f, 0.6f);
    func_802EFB70(s0, 0.28f, 0.32f);
    func_802EFB84(s0, 0.03f, 0.03f);
    func_802EFE24(s0, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    func_802EFEC0(s0, 2.0f, 2.0f);
    func_802EFF50(s0, 1.0f);
    particleEmitter_setPosition(s0, arg0);
    particleEmitter_emitN(s0, 8);

    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364BE0);
    particleEmitter_emitN(s0, 5);
    
    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364C10);
    func_802EF9F8(s0, 0.4f);
    func_802EFA18(s0, 3);
    particleEmitter_emitN(s0, 4);

    s0 = func_802F0BD0(0x11);
    particleEmitter_setSprite(s0, ASSET_716_SPRITE_SPARKLE_WHITE); //sparkle
    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364C40);
    func_802EFA5C(s0, 0.0f, 0.6f);
    func_802EFB70(s0, 0.28f, 0.32f);
    func_802EFB84(s0, 0.03f, 0.03f);
    func_802EFE24(s0, 0.0f, 0.0f, 300.0f, 0.0f, 0.0f, 300.0f);
    func_802EFEC0(s0, 2.0f, 2.0f);
    func_802EFF50(s0, 1.0f);
    particleEmitter_setPosition(s0, arg0);
    particleEmitter_emitN(s0, 8);
    
    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364C70);
    particleEmitter_emitN(s0, 5);
    
    particleEmitter_setVelocityAndAccelerationRanges(s0, &D_80364CA0);
    func_802EF9F8(s0, 0.4f);
    func_802EFA18(s0, 3);
    particleEmitter_emitN(s0, 4);
}

void func_802AFFAC(void){
    D_8037D470.unk10 -= time_getDelta();
    while(D_8037D470.unk10 < 0.0f){
        func_802AF900();
        D_8037D470.unk8 += 0.017 * D_8037D470.unkC;
        D_8037D470.unk10 += 0.017;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802B0060.s")


void func_802B014C(void){
    func_80289EBC(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/dronexform/func_802B016C.s")
/* void func_802B016C(void){
    D_8037D470.unk20 = 0.0f;
    D_8037D470.unk28 = 0.0f;
    D_8037D470.unk24 = 1.0f;
    func_80289EBC(func_802B0060);
}//*/

void func_802B01B0(f32 arg0){
   D_8037D470.unk28 = arg0;
}

void func_802B01BC(f32 arg0){
   D_8037D470.unk24 = arg0;
}

void func_802B01C8(void){
   D_8037D470.unk20 += time_getDelta();
}

static void __bsdronexform_setState(int arg0){
    enum asset_e sp34;
    f32 sp30;
    f32 sp24[3];

    D_8037D470.unk32 = arg0;
    switch(arg0){
        case 1:// 802B0230
            D_8037D470.unk1C = 1;
            D_8037D470.unk2C = player_getYPosition();
            func_802AFB94(0.28f);
            func_802AFBA0(180.0f);
            func_802AFBAC(0.04f);
            func_802B01B0(0.05f);
            func_802978DC(7);
            func_8029E3C0(0, 2.8f);
            FUNC_8030E624(SFX_17E_MUMBO_TRANSFORMATION_01, 0x1D4, 0x3FF);
            break; 
        
        case 2:// 802B02A8
            func_8029E3C0(0, 0.5f);
            func_802978DC(0xb);
            break;

        case 3:// 802B02C4
            func_8029E3C0(0, 0.05f);
            break;

        case 4:// 802B02DC
            func_8029E3C0(0, 0.8f);
            break;

        case 5:// 802B02F4
            _player_getPosition(&sp24);
            sp24[1] += 30.0f;
            func_8024E3A8(&sp24, 80.0f);
            func_802AFBB8(&sp24);
            func_8029E3C0(0, 0.1f);
            break;

        case 6: // 802B033C
            func_802BB3DC(2, 80.0f, 0.85f);
            func_8030E6D4(0x147);
            if(D_8037D470.unk30 == 7 || D_8037D470.unk31 == 7){
                yaw_setIdeal(yaw_get() + 180.0f);
                func_802991FC();
            }
            func_8029A95C(func_80294A4C()); //set player transformation
            func_80291D04(); //update player model
            func_8029BD44(&sp34, &sp30);
            func_8028A010(sp34, sp30);
            func_8029E3C0(0, 0.1f);
            break;

        case 7: // 802B03E4
            func_8029E3C0(0, 0.8f);
            break;

        case 8: // 802B03FC
            if(D_8037D470.unk30 == 1 && D_8037D470.unk31 == 1){
                func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
            }
            func_8029E3C0(0, 1.0f);
            break;

        case 9:// 802B0438
            D_8037D470.unk1C = 0;
            func_8029E3C0(0, 0.7f);
            func_802978DC(7);
            break; 
    }
}

void bsdronexform_init(void){
    f32 sp1C;
    enum asset_e sp18;
    func_8029BCAC(&sp18, &sp1C);
    func_8028A010(sp18, sp1C);
    func_8029C7F4(1,1,3,7);
    func_80297A0C(0);
    func_80297930(0);
    pitch_setIdeal(0.0f);
    roll_setIdeal(0.0f);
    func_80294378(6);
    func_802AFB0C();
    func_802B016C();
    D_8037D470.unk31 = func_8029A8F4();
    D_8037D470.unk30 = func_80294A4C();
    func_802933E8(0x1b);
    D_8037D470.unk32 = 0;
    __bsdronexform_setState(1);
}

f32 func_802B051C(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    return ml_map_f(func_8029E270(arg0), arg1, 0.0f, arg2, arg3);
}

void bsdronexform_update(void){
    int sp24;
    if(D_8037D470.unk1C)
        func_802AFFAC();

    func_802B01C8();
    switch(D_8037D470.unk32){
        case 1: 
            sp24 = func_8029E1A8(0);
            player_setYPosition(func_802B051C(0, 2.8f, 0.0f, 90.0f) + D_8037D470.unk2C);
            func_802AFB94(func_802B051C(0, 2.8f, 0.28f, 1.0f));
            func_802AFBA0(func_802B051C(0, 2.8f, 180.0f, 55.0f));
            func_802AFBAC(func_802B051C(0, 2.8f, 0.04f, 0.35f));
            func_802B01BC(func_802B051C(0, 2.8f, 1.0f, 0.8f));
            func_802B01B0(func_802B051C(0, 2.8f, 0.05f, 0.4f));
            func_8031B990(
                (s32)func_802B051C(0, 2.8f, 255.0f, 200.0f),
                (s32)func_802B051C(0, 2.8f, 255.0f, 80.0f),
                (s32)func_802B051C(0, 2.8f, 255.0f, 80.0f)
            );

            if(sp24)
                __bsdronexform_setState(2);

            break;

        case 2:
            sp24 = func_8029E1A8(0);
            func_802B01B0(func_802B051C(0, 0.5f, 0.4f, 0.6f));
            if(sp24)
                __bsdronexform_setState(3);
            break;

        case 3:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.05f, 0.8f, 1.2f));
            if(sp24)
                __bsdronexform_setState(4);
            break;

        case 4:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.8f, 1.2f, 0.09f));
            if(sp24)
                __bsdronexform_setState(5);
            break;

        case 5:
            sp24 = func_8029E1A8(0);
            if(sp24)
                __bsdronexform_setState(6);
            break;

        case 6:
            sp24 = func_8029E1A8(0);
            if(sp24)
                __bsdronexform_setState(7);
            break;

        case 7:
            sp24 = func_8029E1A8(0);
            func_802B01BC(func_802B051C(0, 0.8f, 0.09f, 1.0f));
            if(sp24)
                __bsdronexform_setState(8);
            break;

        case 8:
            func_802AFBAC(func_802B051C(0, 1.0f, 0.35f, 0.03f));
            func_802B01B0(func_802B051C(0, 1.0f, 0.6f, 0.05f));
            func_8031B990(
                (s32)func_802B051C(0, 1.0f, 200.0f, 255.0f),
                (s32)func_802B051C(0, 1.0f, 80.0f, 255.0f),
                (s32)func_802B051C(0, 1.0f, 80.0f, 255.0f)
            );
            if(func_8029E1A8(0)){
                if(player_getTransformation() == TRANSFORM_7_WISHWASHY){
                    bs_setState(0x33);
                }else{
                    __bsdronexform_setState(9);
                }
            }
            break;

        case 9:
            sp24 = func_8029E1A8(0);
            player_setYPosition(func_802B051C(0, 0.7f, 90.0f, 0.0f) + D_8037D470.unk2C);
            if(sp24)
                bs_setState(func_8029BF78());
            break;
        // 802B08AC 8
        // 802B09A4 9
    }
}

void bsdronexform_end(void){
    func_80294378(1);
    func_8031B990(0xff,0xff,0xff);
    func_802AFADC();
    func_802B014C();
    func_80298A64();
    func_802933FC(0x1b);
}

void bsdronexform_interrupt(void){};