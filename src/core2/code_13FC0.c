#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_8024DDD8(f32[3], f32);
extern void func_8024E71C(s32, f32*);
extern f32 ml_acosf(f32);
extern f32 func_8028EBA4(void);
extern void particleEmitter_setSphericalParticleVelocityRange(ParticleEmitter *this, f32 pitch_min, f32 yaw_min, f32 radial_min, f32 pitch_max, f32 yaw_max, f32 radial_max);
ParticleEmitter * func_802EDD8C(f32[3], f32, f32);
extern void func_80354030(f32[3], f32);
extern void func_80354380(f32[3], f32);
extern void func_80356074(f32[3], f32[3], f32, f32);
extern void func_80292864(f32, f32);

/* .bss */
struct {
    f32 unk0;
    s32 unk4;
    f32 unk8[5];
    f32 unk1C[2];
    f32 unk24;
    f32 unk28;
    s32 unk2C;
    s32 unk30;
    u8  unk34;
} D_8037D1A0;

/*.code */
f32 func_8029AF50(f32 arg0, f32 arg1, f32 arg2){
    return (arg0 - arg1)/(arg2 - arg1);
}

void func_8029AF68(void) {
    s32 i;

    if (D_8037D1A0.unk28 <= D_8037D1A0.unk8[0]) {
        D_8037D1A0.unk4 = 0;
        D_8037D1A0.unk0 = 0.0f;
        return;
    }

    if ((D_8037D1A0.unk8[0] < D_8037D1A0.unk28) && (D_8037D1A0.unk28 <= D_8037D1A0.unk8[1])) {
        D_8037D1A0.unk4 = 1;
        D_8037D1A0.unk0 = func_8029AF50(D_8037D1A0.unk28, D_8037D1A0.unk8[0], D_8037D1A0.unk8[1]);
        return;
    }
    if ((D_8037D1A0.unk8[1] < D_8037D1A0.unk28) && (D_8037D1A0.unk28 <= D_8037D1A0.unk8[2])) {
        D_8037D1A0.unk4 = 2;
        D_8037D1A0.unk0 = func_8029AF50(D_8037D1A0.unk28, D_8037D1A0.unk8[1], D_8037D1A0.unk8[2]);
        return;
    }
    if ((D_8037D1A0.unk8[2] < D_8037D1A0.unk28) && (D_8037D1A0.unk28 <= D_8037D1A0.unk8[3])) {
        D_8037D1A0.unk4 = 3;
        D_8037D1A0.unk0 = func_8029AF50(D_8037D1A0.unk28, D_8037D1A0.unk8[2], D_8037D1A0.unk8[3]);
        return;
    }
    if ((D_8037D1A0.unk8[3] < D_8037D1A0.unk28) && (D_8037D1A0.unk28 <= D_8037D1A0.unk8[4])) {
        D_8037D1A0.unk4 = 4;
        D_8037D1A0.unk0 = func_8029AF50(D_8037D1A0.unk28, D_8037D1A0.unk8[3], D_8037D1A0.unk8[4]);
        return;
    }
}

void func_8029B0C0(void) {
    func_8029B324(0, 0.12f);
    func_8029B324(1, 0.2f);
    func_8029B324(2, 0.5f);
    func_8029B324(3, 0.75f);
    func_8029B324(4, 1.0f);
}

void func_8029B11C(void) {
    D_8037D1A0.unk1C[0] = D_8037D1A0.unk1C[1] = D_8037D1A0.unk28 = D_8037D1A0.unk24 = D_8037D1A0.unk0 = 0.0f;
    D_8037D1A0.unk34 = 0;
    D_8037D1A0.unk30 = 0;
    D_8037D1A0.unk2C = 0;
    D_8037D1A0.unk4 = 0;
    func_8029B0C0();
}

void func_8029B174(void) {
    func_8024E71C(0, &D_8037D1A0.unk1C);
    if (D_8037D1A0.unk34) {
        D_8037D1A0.unk1C[0] = D_8037D1A0.unk1C[1] = 0.0f;
    }
    D_8037D1A0.unk28 = gu_sqrtf(D_8037D1A0.unk1C[0]*D_8037D1A0.unk1C[0] + D_8037D1A0.unk1C[1]*D_8037D1A0.unk1C[1]);
    if (D_8037D1A0.unk28 != 0.0f) {
        D_8037D1A0.unk2C = 0;
        D_8037D1A0.unk30 = (s32) (D_8037D1A0.unk30 + 1);
        D_8037D1A0.unk24 = ml_acosf(D_8037D1A0.unk1C[1] / D_8037D1A0.unk28);
        if (D_8037D1A0.unk1C[0] < 0.0f) {
            D_8037D1A0.unk24 = (f32) (180.0f - D_8037D1A0.unk24);
        }
        if (D_8037D1A0.unk1C[1] < 0.0f) {
            D_8037D1A0.unk24 = (f32) (360.0f - D_8037D1A0.unk24);
        }
    } else {
        D_8037D1A0.unk30 = 0;
        D_8037D1A0.unk2C = (s32) (D_8037D1A0.unk2C + 1);
    }
    if (D_8037D1A0.unk28 > 1.0) {
        D_8037D1A0.unk28 = 1.0f;
    }
    func_8029AF68();
}


f32 func_8029B2D0(void){
    return D_8037D1A0.unk1C[0];
}

f32 func_8029B2DC(void){
    return D_8037D1A0.unk1C[1];
}

f32 func_8029B2E8(void){
    return D_8037D1A0.unk28;
}

f32 func_8029B2F4(void){
    return D_8037D1A0.unk24;
}

s32 func_8029B300(void){
    return D_8037D1A0.unk4;
}

f32 func_8029B30C(void){
    return D_8037D1A0.unk0;
}

void func_8029B318(bool arg0){
    D_8037D1A0.unk34 = arg0;
}

void func_8029B324(s32 arg0, f32 arg1){
    D_8037D1A0.unk8[arg0] = arg1;
}

f32 func_8029B33C(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    return func_8024DDD8(sp1C, func_8029B2F4());
}

s32 func_8029B370(void){
    return D_8037D1A0.unk30;
}

s32 func_8029B37C(void){
    return D_8037D1A0.unk2C;
}

bool func_8029B388(void){
    return D_8037D1A0.unk30 == 1;
}

bool func_8029B39C(void){
    return D_8037D1A0.unk2C == 1;
}
