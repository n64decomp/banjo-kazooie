#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

extern void controller_getJoystick(s32, f32*);
extern f32 player_getYaw(void);
extern void particleEmitter_setSphericalParticleVelocityRange(ParticleEmitter *this, f32 pitch_min, f32 yaw_min, f32 radial_min, f32 pitch_max, f32 yaw_max, f32 radial_max);
ParticleEmitter * func_802EDD8C(f32[3], f32, f32);
extern void func_80354030(f32[3], f32);
extern void func_80356074(f32[3], f32[3], f32, f32);
extern void func_80292864(f32, f32);

/* .bss */
struct {
    f32 zone_position;
    s32 zone;
    f32 zone_markers[5];
    f32 value[2];
    f32 angle;
    f32 distance;
    s32 zeroed_count;
    s32 nonzero_count;
    u8  locked_at_zero;
} bastick;

/*.code */
f32 bastick_calculateZonePosition(f32 arg0, f32 arg1, f32 arg2){
    return (arg0 - arg1)/(arg2 - arg1);
}

void bastick_updateZone(void) {
    s32 i;

    if (bastick.distance <= bastick.zone_markers[0]) {
        bastick.zone = 0;
        bastick.zone_position = 0.0f;
        return;
    }

    if ((bastick.zone_markers[0] < bastick.distance) && (bastick.distance <= bastick.zone_markers[1])) {
        bastick.zone = 1;
        bastick.zone_position = bastick_calculateZonePosition(bastick.distance, bastick.zone_markers[0], bastick.zone_markers[1]);
        return;
    }
    if ((bastick.zone_markers[1] < bastick.distance) && (bastick.distance <= bastick.zone_markers[2])) {
        bastick.zone = 2;
        bastick.zone_position = bastick_calculateZonePosition(bastick.distance, bastick.zone_markers[1], bastick.zone_markers[2]);
        return;
    }
    if ((bastick.zone_markers[2] < bastick.distance) && (bastick.distance <= bastick.zone_markers[3])) {
        bastick.zone = 3;
        bastick.zone_position = bastick_calculateZonePosition(bastick.distance, bastick.zone_markers[2], bastick.zone_markers[3]);
        return;
    }
    if ((bastick.zone_markers[3] < bastick.distance) && (bastick.distance <= bastick.zone_markers[4])) {
        bastick.zone = 4;
        bastick.zone_position = bastick_calculateZonePosition(bastick.distance, bastick.zone_markers[3], bastick.zone_markers[4]);
        return;
    }
}

void bastick_resetZones(void) {
    bastick_setZoneMax(0, 0.12f);
    bastick_setZoneMax(1, 0.2f);
    bastick_setZoneMax(2, 0.5f);
    bastick_setZoneMax(3, 0.75f);
    bastick_setZoneMax(4, 1.0f);
}

void bastick_reset(void) {
    bastick.value[0] = bastick.value[1] = bastick.distance = bastick.angle = bastick.zone_position = 0.0f;
    bastick.locked_at_zero = 0;
    bastick.nonzero_count = 0;
    bastick.zeroed_count = 0;
    bastick.zone = 0;
    bastick_resetZones();
}

void bastick_update(void) {
    controller_getJoystick(0, (f32*)&bastick.value);
    if (bastick.locked_at_zero) {
        bastick.value[0] = bastick.value[1] = 0.0f;
    }
    bastick.distance = gu_sqrtf(bastick.value[0]*bastick.value[0] + bastick.value[1]*bastick.value[1]);
    if (bastick.distance != 0.0f) {
        bastick.zeroed_count = 0;
        bastick.nonzero_count = (s32) (bastick.nonzero_count + 1);
        bastick.angle = ml_acosf(bastick.value[1] / bastick.distance);
        if (bastick.value[0] < 0.0f) {
            bastick.angle = (f32) (180.0f - bastick.angle);
        }
        if (bastick.value[1] < 0.0f) {
            bastick.angle = (f32) (360.0f - bastick.angle);
        }
    } else {
        bastick.nonzero_count = 0;
        bastick.zeroed_count = (s32) (bastick.zeroed_count + 1);
    }
    if (bastick.distance > 1.0) {
        bastick.distance = 1.0f;
    }
    bastick_updateZone();
}


f32 bastick_getX(void){
    return bastick.value[0];
}

f32 bastick_getY(void){
    return bastick.value[1];
}

f32 bastick_distance(void){
    return bastick.distance;
}

f32 bastick_getAngle(void){
    return bastick.angle;
}

s32 bastick_getZone(void){
    return bastick.zone;
}

f32 bastick_getZonePosition(void){
    return bastick.zone_position;
}

void bastick_lockAtzero(bool arg0){
    bastick.locked_at_zero = arg0;
}

void bastick_setZoneMax(s32 zone_id, f32 value){
    bastick.zone_markers[zone_id] = value;
}

f32 bastick_getAngleRelativeToBanjo(void){
    f32 sp1C[3];

    playerPosition_get(sp1C);
    return viewport_adjustAngleToRight(sp1C, bastick_getAngle());
}

s32 bastick_getNonzeroCount(void){
    return bastick.nonzero_count;
}

s32 bastick_getCenteredCount(void){
    return bastick.zeroed_count;
}

bool bastick_newlyActive(void){
    return bastick.nonzero_count == 1;
}

bool bastick_newlyCentered(void){
    return bastick.zeroed_count == 1;
}
