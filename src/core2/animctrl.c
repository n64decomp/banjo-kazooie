#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/animctrl.h"
#include "animation.h"

extern u32 D_A0000238;

/* .code */
void animctrl_80286F90(AnimCtrl *this){
    Animation *anim;
    f32 duration;

    if(this->smooth_transition){
        anim = animctrl_getAnimPtr(this);
        duration = anim_getDuration(anim);
        if( duration < 1.0f ){
            anim_setDuration(anim, ml_min_f(1.0f, time_getDelta()/animctrl_getTransistionDuration(this) + duration));
        }
    }
}

static void __animctrl_update_looped(AnimCtrl *this){
    Animation *anim;
    f32 delta;
    f32 tmp;

     anim = animctrl_getAnimPtr(this);
     animctrl_80286F90(this);
     this->timer = anim_getTimer(anim);
     delta = time_getDelta() / animctrl_getDuration(this);
     if(this->playback_direction == 0){
         delta = -delta;
     }
     tmp = this->timer + delta;
     if(tmp < 0.0f){
         tmp += 1.0f;
     }
     tmp -= (f32)(s32)tmp;//0.0f to 1.0f
     anim_setTimer(anim, tmp);
}

void func_802870E0(AnimCtrl *this){
    Animation *anim;
    f32 delta;
    f32 tmpf14;
    f32 f_range;
    f32 f_percent;

     anim = animctrl_getAnimPtr(this);
     animctrl_80286F90(this);
     this->timer = anim_getTimer(anim);;
     delta =  time_getDelta() / animctrl_getDuration(this);
     if(this->playback_direction == 0){
         delta = -delta;
     }
     tmpf14 = this->timer + delta;
     if(this->subrange_end <= tmpf14){
         f_range = this->subrange_end - this->subrange_start;
         f_percent = (tmpf14 - this->subrange_start)/f_range;
         tmpf14 = this->subrange_start + (f_percent - (f32)(s32)f_percent)*f_range;
     }
     anim_setTimer(anim, tmpf14);
}

void func_802871A4(AnimCtrl *this){
    Animation *anim;
    f32 phi_f0;
    f32 phi_f2;


    anim = animctrl_getAnimPtr(this);
    animctrl_80286F90(this);
    this->timer = anim_getTimer(anim);
    phi_f2 = time_getDelta() / animctrl_getDuration(this);
    if (this->playback_direction == 0) {
        phi_f2 = -phi_f2;
    }
    phi_f0 = this->timer + phi_f2;


    if (phi_f0 < 0.0f) {
        phi_f0 = 0.0f;
        animctrl_setPlaybackType(this,  ANIMCTRL_STOPPED);

    } else {
        if ((this->subrange_end < phi_f0) || (0.999999 < (f64) phi_f0)) {
            if(this->subrange_end < phi_f0)
                phi_f0 = this->subrange_end;
            if(0.999999 < (f64) phi_f0)
                phi_f0 =  0.9999989867210388f; // D_80373E00
            animctrl_setPlaybackType(this,  ANIMCTRL_STOPPED);
        } else {
            phi_f0 = phi_f0 - (f32) (s32) phi_f0;
        }
    }
    anim_setTimer(anim, phi_f0);
}

AnimCtrl *animctrl_new(s32 arg0){ //new
    ActorAnimCtrl *this;

    this = (ActorAnimCtrl *)malloc( anim_getSize() + 0x28);
    this->animctrl.animation = &this->animation;
    anim_new(&this->animation, 1);
    this->animctrl.playback_type = 0;
    this->animctrl.index = 0;
    this->animctrl.default_start = TRUE;
    this->animctrl.timer = 0.0f;
    this->animctrl.start = 0.0f;
    func_80287784(&this->animctrl, func_8030C77C());
    animctrl_setSubRange(&this->animctrl, 0.0f, 1.0f);
    animctrl_setDuration(&this->animctrl, 2.0f);
    animctrl_setTransitionDuration(&this->animctrl, 0.2f);
    animctrl_setSmoothTransition(&this->animctrl, 1);
    animctrl_setDirection(&this->animctrl, mvmt_dir_forwards);
    return &this->animctrl;
}

void animctrl_free(AnimCtrl * this){ //free
    anim_release(this->animation);
    free(this);
}

void animctrl_update(AnimCtrl *this){//update
    switch (this->playback_type)
    {
    case 0:
        break;
    case ANIMCTRL_ONCE: //once
        func_802871A4(this);
        break;
    case ANIMCTRL_LOOP: //loop
        __animctrl_update_looped(this);
        break;
    case ANIMCTRL_SUBRANGE_LOOP: 
        func_802870E0(this);
        break;
    case ANIMCTRL_STOPPED: //stopped
        animctrl_80286F90(this);
        break;
    }
}

AnimCtrl *animctrl_defrag(AnimCtrl *this){ //realloc
    ActorAnimCtrl *full_struct;
    full_struct = (ActorAnimCtrl *)defrag(this);
    full_struct->animctrl.animation = &full_struct->animation;
    return &full_struct->animctrl;
}

void animctrl_setIndex(AnimCtrl *this, enum asset_e index){
    this->index = index;
}

Animation *animctrl_getAnimPtr(AnimCtrl *this){
    return this->animation;
}

void func_8028746C(AnimCtrl *this,  void (* arg1)(s32,s32)){
    anim_80289790(this->animation, arg1);
}

void func_8028748C(AnimCtrl *this, s32 arg1){
    anim_80289798(this->animation, arg1);
}

void animctrl_reset(AnimCtrl *this){
    this->playback_type = ANIMCTRL_LOOP;
    this->default_start = TRUE;
    this->timer = 0.0;
    this->start = 0.0;
    animctrl_setSmoothTransition(this, 1);
    animctrl_setSubRange(this, 0.0, 1.0);
    animctrl_setDuration(this, 2.0);
    animctrl_setTransitionDuration(this, 0.2);
    animctrl_setDirection(this, mvmt_dir_forwards);
}

void __animctrl_gotoStart(AnimCtrl *this){
    if(this->default_start){
        if(this->playback_direction)
            anim_setTimer(this->animation, 0.0f);
        else
            anim_setTimer(this->animation, 0.99999899f);
    }
    else{
        anim_setTimer(this->animation, this->start);
    }
    this->timer = anim_getTimer(this->animation);
}

void _animctrl_start(AnimCtrl * this, char *file, s32 line){
    if(this->smooth_transition && anim_getIndex(this->animation) != 0){
        anim_resetSmooth(this->animation);
        anim_setIndex(this->animation, this->index);
        __animctrl_gotoStart(this);
        anim_setDuration(this->animation, 0.0f);
    } else{
        anim_resetNow(this->animation);
        anim_setIndex(this->animation, this->index);
        __animctrl_gotoStart(this);
        anim_setDuration(this->animation, 1.0f);
    }
}

void animctrl_setAnimTimer(AnimCtrl *this, f32 timer){
    anim_setTimer(this->animation, timer);
}

void animctrl_setPlaybackType(AnimCtrl *this, enum animctrl_playback_e arg1){
    this->playback_type = arg1;
}

void animctrl_setDirection(AnimCtrl *this, s32 arg1){
    this->playback_direction = arg1;
}

void animctrl_setSmoothTransition(AnimCtrl *this, s32 arg1){
    this->smooth_transition = arg1;
}

void animctrl_setDuration(AnimCtrl *this, f32 arg1){
    if(IO_READ(0x238) - 0x10000003){
        arg1 += 3.0f;
    }
    this->animation_duration = arg1;
}

void animctrl_setTransitionDuration(AnimCtrl *this, f32 arg1){
    this->transition_duration = arg1;
}

void animctrl_setSubRange(AnimCtrl *this, f32 start, f32 end){
    this->subrange_start = start - (f32)(s32)start;
    this->subrange_end = (end != 1.0)? end - (f32)(s32)end : end;

}

void animctrl_getSubRange(AnimCtrl *this, f32 *startPtr, f32 *endPtr){
    *startPtr = this->subrange_start;
    *endPtr = this->subrange_end;
}

void animctrl_setStart(AnimCtrl *this, f32 start_position){
    if(start_position == 1.0)
        start_position = 0.9999989867210388f; // D_80373E18

    this->start = start_position;
    this->default_start = FALSE;
}

void func_80287784(AnimCtrl *this, s32 arg1){
    this->unk23 = arg1;
    this->unk24 = 0;
}

enum asset_e animctrl_getIndex(AnimCtrl *this){
    return anim_getIndex(this->animation);
}

enum animctrl_playback_e animctrl_getPlaybackType(AnimCtrl *this){
    return this->playback_type;
}

s32 animctrl_isPlayedForwards(AnimCtrl *this){
    return this->playback_direction;
}

s32 animctrl_isSmoothTransistion(AnimCtrl *this){
    return this->smooth_transition;
}

f32 animctrl_getDuration(AnimCtrl *this){
    return this->animation_duration;
}

f32 animctrl_getTransistionDuration(AnimCtrl *this){
    return this->transition_duration;
}

f32 animctrl_getAnimTimer(AnimCtrl *this){
    return anim_getTimer(this->animation);
}

f32 animctrl_getTimer(AnimCtrl *this){
    return this->timer;
}

void  animctrl_setTimer(AnimCtrl *this, f32 arg1){
    this->timer = arg1;
}

s32  animctrl_8028780C(f32 position[3], s32 arg1){
    return 0;
}

void animctrl_drawSetup(AnimCtrl *this, f32 *position, s32 arg2){
    s32 map;
    map = map_get();
    if( map != MAP_1E_CS_START_NINTENDO 
        && map != MAP_1F_CS_START_RAREWARE
        && map != MAP_20_CS_END_NOT_100 
        && this->unk23 !=0 
        && position != NULL
    ){
        this->unk24 = this->unk24 -1;
        if(this->unk24 == 0xFF){
            this->unk24 = animctrl_8028780C(position, arg2);
        }
        else{
            anim_drawSetup(this->animation);
            return;
        }
    }
    anim_update(this->animation);
}

s32 animctrl_isStopped(AnimCtrl *this){
    return animctrl_getPlaybackType(this) == ANIMCTRL_STOPPED;
}

int animctrl_isAt(AnimCtrl *this, f32 arg1){
    int retval;
    f32 f0 = anim_getTimer(this->animation); 

    if(f0 == this->timer){
        return 0;
    }
    else{
        if(this->playback_direction != 0){ //forward direction
            if(this->timer < f0){
                return  this->timer <= arg1 && arg1 < f0; //arg1 between last animation time and new animation time
            }else{
                return  this->timer <= arg1 || arg1 < f0; //animation just looped, arg1 outside of loop
            }
        }else{
            if(f0 < this->timer){
                return  arg1 <= this->timer && f0  < arg1;
            }else{
                return  arg1 <= this->timer || f0  < arg1;
            }
        }
    }
    
    return retval;
}

s32 animctrl_isContiguous(AnimCtrl *this){
    return (s32)this->animation - (s32) this == 0x28;
}
