#ifndef __ANIM_CTRL_H__
#define __ANIM_CTRL_H__

#include <ultra64.h>

#ifndef NONMATCHING
#define func_802875AC(this, file, line) _func_802875AC(this, file, line)
#else
#define func_802875AC(this, file, line) _func_802875AC(this, __FILE__, __LINE__)
#endif

enum animctrl_playback_e{
    ANIMCTRL_ONCE = 1,
    ANIMCTRL_LOOP = 2,
    ANIMCTRL_STOPPED = 3,
    ANIMCTRL_SUBRANGE_LOOP = 4
};


typedef struct animation_s{
    void (* matrices)(s32, s32);
    s32     unk4;
    u8      unk8;
    u8      unk9;
    s16     unkA;
    s16     unkC;
    s16     unkE;
    u32     index;
    f32     timer;
    f32     duration;
    u8      unk1C;
    u8      unk1D;
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
    float   unk18;
    s32     index;
    u8      playback_type;
    u8      playback_direction;
    u8      smooth_transition;
    u8      unk23;
    u8      unk24;
    u8      unk25;
    u8      pad26[2];
} AnimCtrl;

typedef struct actorAnimCtrl_s{
    AnimCtrl animctrl;
    Animation animation;
} ActorAnimCtrl;

AnimCtrl *animctrl_new(s32 arg0);
void animctrl_free(AnimCtrl * this);
void animctrl_update(AnimCtrl *this);
AnimCtrl *func_80287434(AnimCtrl *this);
void animctrl_setIndex(AnimCtrl *this, enum asset_e index);
Animation *animctrl_getAnimPtr(AnimCtrl *this);
void func_8028746C(AnimCtrl *this,  void (* arg1)(s32,s32));
void func_8028748C(AnimCtrl *this, s32 arg1);
void animctrl_reset(AnimCtrl *this);
void func_8028752C(AnimCtrl *this);
void _func_802875AC(AnimCtrl * this, char *file, s32 line);
void func_8028764C(AnimCtrl *this, f32 timer);
void animctrl_setPlaybackType(AnimCtrl *this, enum animctrl_playback_e arg1);
void animctrl_setDirection(AnimCtrl *this, s32 arg1);
void animctrl_setSmoothTransition(AnimCtrl *this, s32 arg1);
void animctrl_setDuration(AnimCtrl *this, f32 arg1);
void animctrl_setTransitionDuration(AnimCtrl *this, f32 arg1);
void animctrl_setSubRange(AnimCtrl *this, f32 start, f32 end);
void animctrl_getSubRange(AnimCtrl *this, f32 *startPtr, f32 *endPtr);
void func_8028774C(AnimCtrl *this, f32 arg1);
void func_80287784(AnimCtrl *this, s32 arg1);
enum asset_e animctrl_getIndex(AnimCtrl *this);
enum animctrl_playback_e animctrl_getPlaybackType(AnimCtrl *this);
s32 animctrl_isPlayedForwards(AnimCtrl *this);
s32 animctrl_isSmoothTransistion(AnimCtrl *this);
f32 animctrl_getDuration(AnimCtrl *this);
f32 animctrl_getTransistionDuration(AnimCtrl *this);
f32 func_802877D8(AnimCtrl *this);
f32 func_802877F8(AnimCtrl *this);
void  func_80287800(AnimCtrl *this, f32 arg1);
s32  func_8028780C(AnimCtrl *this, s32 arg1);
s32 func_8028781C(AnimCtrl *this, f32 *arg1, s32 arg2);
s32 animctrl_isStopped(AnimCtrl *this);
int animctrl_isAt(AnimCtrl *this, f32 arg1);
s32 animctrl_isContiguous(AnimCtrl *this);
#endif
