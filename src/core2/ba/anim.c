#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/ba/anim.h"
#include "core2/ba/physics.h"


extern f32 func_802E4B38(void);
extern f32 ml_mapRange_f(f32, f32, f32, f32, f32);

void baanim_80289F30(void);

#define BAANIM_BIGHEAD 0x4
#define BAANIM_SMALLHEAD 0x8
#define BAANIM_LONGBODY 0x10
#define BAANIM_BIGKAZOOIEHEAD 0x20
#define BAANIM_BIGWINGS 0x40
#define BAANIM_WISHYWASHY 0x80

/* .data */
f32 D_803635E0[3] = {0.0f, 5.0f, 0.0f};
s32 D_803635EC[7] = { //bottles bonus modification
    BAANIM_BIGHEAD, 
    0x2 | 0x1, 
    BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD, 
    BAANIM_LONGBODY | BAANIM_SMALLHEAD, 
    BAANIM_LONGBODY | BAANIM_SMALLHEAD | 0x2 | 0x1,
    BAANIM_BIGWINGS | BAANIM_BIGKAZOOIEHEAD | BAANIM_BIGHEAD | 0x2 | 0x1, 
    BAANIM_WISHYWASHY
};

/* .bss */
AnimCtrl *playerAnimCtrl;
s32 baAnimState;
f32 baAnimMinDuration;
f32 baAnimMaxDuration;
struct {
    f32 velocity_min; //velocity_min
    f32 velocity_max; //velocity_max
    f32 duration_min; //duration_min
    f32 duration_max; //duration_max
    f32 duration_scale; //duration_scale
    u8  scalable_duration; //scalable_duration
}baAnimScale;
void (*baAnimModifyFunction)(s32, s32);

/* .code */
void __baanim_setUpdateType(enum baanim_update_type_e arg0){
    baAnimState = arg0;
}

void __baanim_update_scaleToHorizontalVelocity(void) {
    f32 velocity[3];
    f32 temp_f12;
    f32 scale;
    
    scale = (baAnimScale.scalable_duration != 0) ? baAnimScale.duration_scale : 1.0f;
    baphysics_get_velocity(velocity);
    temp_f12 = ml_mapRange_f(gu_sqrtf(velocity[0]*velocity[0] + velocity[2] * velocity[2]), baAnimScale.velocity_min, baAnimScale.velocity_max, baAnimScale.duration_min * scale, baAnimScale.duration_max * scale);
    animctrl_setDuration(playerAnimCtrl, ml_clamp_f(temp_f12, baAnimMinDuration, baAnimMaxDuration));
    animctrl_update(playerAnimCtrl);
}

void __baanim_update_scaleToVerticalVelocity(void) {
    animctrl_setDuration(playerAnimCtrl, ml_clamp_f(ml_mapRange_f(mlAbsF(baphysics_get_vertical_velocity()), baAnimScale.velocity_min, baAnimScale.velocity_max, baAnimScale.duration_min, baAnimScale.duration_max), baAnimMinDuration, baAnimMaxDuration));
    animctrl_update(playerAnimCtrl);
}


void __baanim_oscillateScale(f32 dst[3], f32 x, f32 min, f32 osc_size) {
    s32 phi_s0;

    for(phi_s0 = 0; phi_s0 < 3; phi_s0++){
        dst[phi_s0] = min + osc_size*(0.5 + 0.5 * sinf((2.0*BAD_PI)*func_80257A44(x + (2.0 * ((f32) phi_s0 / 3.0)), 2.0f)));
    };
}

void __baanim_applyBottlesBonus(s32 arg0, s32 arg1) {
    f32 scale[3];
    f32 sp28;
    s32 phi_s0;
    static s32 D_8037BF4C;
 

    sp28 = func_802E4B38();
    if (func_803203FC(UNKFLAGS1_78_SANDCASTLE_NO_BONUS) == 0) {
        D_8037BF4C = 0;
    } else {
        for(phi_s0 = 0; phi_s0 < 7; phi_s0++){
            if (func_803203FC(phi_s0 + UNKFLAGS1_97_SANDCASTLE_BOTTLES_BONUS_1)) {
                D_8037BF4C = D_803635EC[phi_s0];
            }
        }
    }
    if ((D_8037BF4C & 1)) {//either big hands or big feet
        __baanim_oscillateScale(scale, sp28, 2.0f, 1.0f);
        boneTransformList_setBoneScale(arg0, 6, scale);
        boneTransformList_setBoneScale(arg0, 0x14, scale);
    }
    if (D_8037BF4C & 2) {//either big hands or big feet
        __baanim_oscillateScale(scale, sp28, 2.0f, 1.0f);
        boneTransformList_setBoneScale(arg0, 0x10, scale);
        boneTransformList_setBoneScale(arg0, 0x1E, scale);
    }
    if (D_8037BF4C & BAANIM_BIGHEAD) {
        __baanim_oscillateScale(scale, sp28, 2.0f, 1.0f);
        boneTransformList_setBoneScale(arg0, 0x12, scale);
    }
    if (D_8037BF4C & BAANIM_SMALLHEAD) {
        __baanim_oscillateScale(scale, sp28, 0.2f, 0.5f);
        boneTransformList_setBoneScale(arg0, 0x12, scale);
    }
    if (D_8037BF4C & BAANIM_LONGBODY) {
        func_8033A968(arg0, 1, &D_803635E0);
    }
    if (D_8037BF4C & BAANIM_BIGKAZOOIEHEAD) {
        __baanim_oscillateScale(scale, sp28, 2.0f, 1.0f);
        boneTransformList_setBoneScale(arg0, 0x6C, scale);
    }
    if (D_8037BF4C & BAANIM_BIGWINGS) {
        __baanim_oscillateScale(scale, sp28, 2.0f, 1.0f);
        boneTransformList_setBoneScale(arg0, 0x64, scale);
        boneTransformList_setBoneScale(arg0, 0x67, scale);
    }
    if (map_get() == MAP_A_TTC_SANDCASTLE) {
        if ((D_8037BF4C & BAANIM_WISHYWASHY) && (player_getTransformation() != TRANSFORM_7_WISHWASHY)) {
            func_8028FB88(TRANSFORM_7_WISHWASHY);
        }
        if (!(D_8037BF4C & BAANIM_WISHYWASHY) && (player_getTransformation() == TRANSFORM_7_WISHWASHY)) {
            func_8028FB88(TRANSFORM_1_BANJO);
        }
    }
    if (baAnimModifyFunction != NULL) {
        baAnimModifyFunction(arg0, arg1);
    }
}

void baAnim_init(void){
    playerAnimCtrl = animctrl_new(1);
    func_80287784(playerAnimCtrl, 0);
    animctrl_setSmoothTransition(playerAnimCtrl, FALSE);
    func_8028746C(playerAnimCtrl, __baanim_applyBottlesBonus);
    baAnimModifyFunction = NULL;
    baanim_80289F30();
    baAnimState = BAANIM_UPDATE_0_NONE;
    __baanim_setUpdateType(BAANIM_UPDATE_1_NORMAL);
    baanim_setDurationRange(0.01f, 100.0f);
    baanim_setVelocityMapRanges(0.0f, 1000.0f, 0.1f, 10.0f);
    baAnimScale.scalable_duration = 0;
    baAnimScale.duration_scale = 1.0f;
}

void baAnim_free(void){
    animctrl_free(playerAnimCtrl);
}

void baAnim_update(void){
    switch(baAnimState){
        case BAANIM_UPDATE_2_SCALE_HORZ:
            __baanim_update_scaleToHorizontalVelocity();
            break;
        
        case BAANIM_UPDATE_3_SCALE_VERT:
            __baanim_update_scaleToVerticalVelocity();
            break;

        case BAANIM_UPDATE_1_NORMAL:
            animctrl_update(playerAnimCtrl);
            break;

        case BAANIM_UPDATE_0_NONE:
            break;
    }
}

void baAnim_defrag(void){
    playerAnimCtrl = animctrl_defrag(playerAnimCtrl);
}

enum baanim_update_type_e baanim_getUpdateType(void){
    return baAnimState;
}

void baanim_setDurationRange(f32 min, f32 max){
    baAnimMinDuration = min;
    baAnimMaxDuration = max;
}

void baanim_setModifyMethod(void (*arg0)(s32, s32)){
    baAnimModifyFunction = arg0;
}

void baanim_setVelocityMapRanges(f32 vel_min, f32 vel_max, f32 dur_slowest, f32 dur_fastest){
    baAnimScale.velocity_min = vel_min;
    baAnimScale.velocity_max = vel_max;
    baAnimScale.duration_min = dur_slowest;
    baAnimScale.duration_max = dur_fastest;
    baAnimScale.scalable_duration = FALSE;
}

void baanim_scaleDuration(f32 arg0){
    baAnimScale.duration_scale = arg0;
    baAnimScale.scalable_duration = TRUE;
}

void baanim_setUpdateType(enum baanim_update_type_e arg0){
    __baanim_setUpdateType(arg0);
}

void baanim_80289F30(void){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    animctrl_drawSetup(playerAnimCtrl, sp1C, 1);
}

AnimCtrl *baanim_getAnimCtrlPtr(void){
    return playerAnimCtrl;
}

f32 baanim_getTimer(void){
    return animctrl_getAnimTimer(playerAnimCtrl);
}

bool baanim_isAnimID(enum asset_e anim_id){
    return animctrl_getIndex(playerAnimCtrl) == anim_id;
}

bool baanim_isStopped(void){
    return animctrl_isStopped(playerAnimCtrl);
}

bool baanim_isAt(f32 time){
    return animctrl_isAt(playerAnimCtrl, time);
}

void baanim_playForDuration_loopSmooth(enum asset_e anim_id, f32 duration){
    animctrl_reset(playerAnimCtrl);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_LOOP);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x188);
}

void baanim_playForDuration_loop(enum asset_e anim_id, f32 duration){
    animctrl_reset(playerAnimCtrl);
    animctrl_setSmoothTransition(playerAnimCtrl, FALSE);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_LOOP);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x193);
}

void baanim_playForDuration_loopStartingAt(enum asset_e anim_id, f32 duration, f32 start_position){
    animctrl_reset(playerAnimCtrl);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setStart(playerAnimCtrl, start_position);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_LOOP);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x19e);
}

void baanim_playForDuration_once(enum asset_e anim_id, f32 duration){
    animctrl_reset(playerAnimCtrl);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x1a8);
}

void baanim_playForDuration_onceStartingAt(enum asset_e anim_id, f32 duration, f32 start_position){
    animctrl_reset(playerAnimCtrl);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setStart(playerAnimCtrl, start_position);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x1b3);
}

void baanim_playForDuration_onceSmooth(enum asset_e anim_id, f32 duration){
    animctrl_reset(playerAnimCtrl);
    animctrl_setSmoothTransition(playerAnimCtrl, FALSE);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x1bd);
}

void baanim_playForDuration_onceSmoothStartingAt(enum asset_e anim_id, f32 duration, f32 start_position){
    animctrl_reset(playerAnimCtrl);
    animctrl_setSmoothTransition(playerAnimCtrl, FALSE);
    animctrl_setIndex(playerAnimCtrl, anim_id);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setStart(playerAnimCtrl, start_position);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
    animctrl_start(playerAnimCtrl, "baanim.c", 0x1c9);
}

void baanim_setEnd(f32 end_position){
    animctrl_setSubRange(playerAnimCtrl, 0.0f, end_position);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
}

void baanim_setEndAndDuration(f32 end_position, f32 duration){
    animctrl_setSubRange(playerAnimCtrl, 0.0f, end_position);
    animctrl_setDuration(playerAnimCtrl, duration);
    animctrl_setPlaybackType(playerAnimCtrl, ANIMCTRL_ONCE);
}
