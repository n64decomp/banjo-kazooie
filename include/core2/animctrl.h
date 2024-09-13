#ifndef __ANIM_CTRL_H__
#define __ANIM_CTRL_H__

#include <ultra64.h>
#include "generic.h"
#include "ml/mtx.h"

#ifndef NONMATCHING
#define animctrl_start(this, file, line) _animctrl_start(this, file, line)
#else
#define animctrl_start(this, file, line) _animctrl_start(this, __FILE__, __LINE__)
#endif

enum animctrl_playback_e{
    ANIMCTRL_ONCE = 1,
    ANIMCTRL_LOOP = 2,
    ANIMCTRL_STOPPED = 3,
    ANIMCTRL_SUBRANGE_LOOP = 4
};

typedef struct{
    MtxF mtx_0;
    s32 size_40;
    s32 capacity_44;
    MtxF data[];
}AnimMtxList;

typedef struct animation_s{
    GenFunction_2 matrices;
    s32     unk4;
    u8      unk8;
    u8      unk9;
    s16     animcache_index[3];
    u32     index;
    f32     timer;
    f32     duration;
    u8      reset;
    u8      triple_buffer;
    u8      unk1E;
    u8      unk1F;
} Animation;

typedef struct animctrl_s{
    Animation *animation;
    f32     timer;
    f32     subrange_start;
    f32     subrange_end;
    f32     animation_duration;
    f32     transition_duration;
    float   start;
    s32     index;
    u8      playback_type;
    u8      playback_direction;
    u8      smooth_transition;
    u8      unk23;
    u8      unk24;
    u8      default_start;
    u8      pad26[2];
} AnimCtrl;

typedef struct actorAnimCtrl_s{
    AnimCtrl animctrl;
    Animation animation;
} ActorAnimCtrl;

AnimCtrl *animctrl_new(s32 arg0);
void animctrl_free(AnimCtrl * this);
void animctrl_update(AnimCtrl *this);
AnimCtrl *animctrl_defrag(AnimCtrl *this);
void animctrl_setIndex(AnimCtrl *this, enum asset_e index);
Animation *animctrl_getAnimPtr(AnimCtrl *this);
void func_8028746C(AnimCtrl *this,  void (* arg1)(s32,s32));
void func_8028748C(AnimCtrl *this, s32 arg1);
void animctrl_reset(AnimCtrl *this);
void __animctrl_gotoStart(AnimCtrl *this);
void _animctrl_start(AnimCtrl * this, char *file, s32 line);
void animctrl_setAnimTimer(AnimCtrl *this, f32 timer);
void animctrl_setPlaybackType(AnimCtrl *this, enum animctrl_playback_e arg1);
void animctrl_setDirection(AnimCtrl *this, s32 arg1);
void animctrl_setSmoothTransition(AnimCtrl *this, s32 arg1);
void animctrl_setDuration(AnimCtrl *this, f32 arg1);
void animctrl_setTransitionDuration(AnimCtrl *this, f32 arg1);
void animctrl_setSubRange(AnimCtrl *this, f32 start, f32 end);
void animctrl_getSubRange(AnimCtrl *this, f32 *startPtr, f32 *endPtr);
void animctrl_setStart(AnimCtrl *this, f32 arg1);
void func_80287784(AnimCtrl *this, s32 arg1);
enum asset_e animctrl_getIndex(AnimCtrl *this);
enum animctrl_playback_e animctrl_getPlaybackType(AnimCtrl *this);
s32 animctrl_isPlayedForwards(AnimCtrl *this);
s32 animctrl_isSmoothTransistion(AnimCtrl *this);
f32 animctrl_getDuration(AnimCtrl *this);
f32 animctrl_getTransistionDuration(AnimCtrl *this);
f32 animctrl_getAnimTimer(AnimCtrl *this);
f32 animctrl_getTimer(AnimCtrl *this);
void  animctrl_setTimer(AnimCtrl *this, f32 arg1);
s32  animctrl_8028780C(f32 position[3], s32 arg1);
void animctrl_drawSetup(AnimCtrl *this, f32 *arg1, s32 arg2);
s32 animctrl_isStopped(AnimCtrl *this);
int animctrl_isAt(AnimCtrl *this, f32 arg1);
s32 animctrl_isContiguous(AnimCtrl *this);
#endif
