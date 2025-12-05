#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/anctrl.h"
#include "animation.h"

/* .code */
void anctrl_80286F90(AnimCtrl *this){
    Animation *anim;
    f32 duration;

    if(this->smooth_transition){
        anim = anctrl_getAnimPtr(this);
        duration = anim_getDuration(anim);
        if( duration < 1.0f ){
            anim_setDuration(anim, ml_min_f(1.0f, time_getDelta()/anctrl_getTransistionDuration(this) + duration));
        }
    }
}

static void __anctrl_update_looped(AnimCtrl *this){
    Animation *anim;
    f32 delta;
    f32 tmp;

     anim = anctrl_getAnimPtr(this);
     anctrl_80286F90(this);
     this->timer = anim_getTimer(anim);
     delta = time_getDelta() / anctrl_getDuration(this);
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

     anim = anctrl_getAnimPtr(this);
     anctrl_80286F90(this);
     this->timer = anim_getTimer(anim);;
     delta =  time_getDelta() / anctrl_getDuration(this);
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


    anim = anctrl_getAnimPtr(this);
    anctrl_80286F90(this);
    this->timer = anim_getTimer(anim);
    phi_f2 = time_getDelta() / anctrl_getDuration(this);
    if (this->playback_direction == 0) {
        phi_f2 = -phi_f2;
    }
    phi_f0 = this->timer + phi_f2;


    if (phi_f0 < 0.0f) {
        phi_f0 = 0.0f;
        anctrl_setPlaybackType(this,  ANIMCTRL_STOPPED);

    } else {
        if ((this->subrange_end < phi_f0) || (0.999999 < (f64) phi_f0)) {
            if(this->subrange_end < phi_f0)
                phi_f0 = this->subrange_end;
            if(0.999999 < (f64) phi_f0)
                phi_f0 =  0.9999989867210388f; // D_80373E00
            anctrl_setPlaybackType(this,  ANIMCTRL_STOPPED);
        } else {
            phi_f0 = phi_f0 - (f32) (s32) phi_f0;
        }
    }
    anim_setTimer(anim, phi_f0);
}

AnimCtrl *anctrl_new(s32 arg0){ //new
    ActorAnimCtrl *this;

    this = (ActorAnimCtrl *)malloc( anim_getSize() + 0x28);
    this->anctrl.animation = &this->animation;
    anim_new(&this->animation, 1);
    this->anctrl.playback_type = 0;
    this->anctrl.index = 0;
    this->anctrl.default_start = TRUE;
    this->anctrl.timer = 0.0f;
    this->anctrl.start = 0.0f;
    func_80287784(&this->anctrl, func_8030C77C());
    anctrl_setSubRange(&this->anctrl, 0.0f, 1.0f);
    anctrl_setDuration(&this->anctrl, 2.0f);
    anctrl_setTransitionDuration(&this->anctrl, 0.2f);
    anctrl_setSmoothTransition(&this->anctrl, 1);
    anctrl_setDirection(&this->anctrl, mvmt_dir_forwards);
    return &this->anctrl;
}

void anctrl_free(AnimCtrl * this){ //free
    anim_release(this->animation);
    free(this);
}

void anctrl_update(AnimCtrl *this){//update
    switch (this->playback_type)
    {
    case 0:
        break;
    case ANIMCTRL_ONCE: //once
        func_802871A4(this);
        break;
    case ANIMCTRL_LOOP: //loop
        __anctrl_update_looped(this);
        break;
    case ANIMCTRL_SUBRANGE_LOOP: 
        func_802870E0(this);
        break;
    case ANIMCTRL_STOPPED: //stopped
        anctrl_80286F90(this);
        break;
    }
}

AnimCtrl *anctrl_defrag(AnimCtrl *this){ //realloc
    ActorAnimCtrl *full_struct;
    full_struct = (ActorAnimCtrl *)defrag(this);
    full_struct->anctrl.animation = &full_struct->animation;
    return &full_struct->anctrl;
}

void anctrl_setIndex(AnimCtrl *this, enum asset_e index){
    this->index = index;
}

Animation *anctrl_getAnimPtr(AnimCtrl *this){
    return this->animation;
}

void func_8028746C(AnimCtrl *this,  void (* arg1)(s32,s32)){
    anim_80289790(this->animation, arg1);
}

void func_8028748C(AnimCtrl *this, s32 arg1){
    anim_80289798(this->animation, arg1);
}

void anctrl_reset(AnimCtrl *this){
    this->playback_type = ANIMCTRL_LOOP;
    this->default_start = TRUE;
    this->timer = 0.0;
    this->start = 0.0;
    anctrl_setSmoothTransition(this, 1);
    anctrl_setSubRange(this, 0.0, 1.0);
    anctrl_setDuration(this, 2.0);
    anctrl_setTransitionDuration(this, 0.2);
    anctrl_setDirection(this, mvmt_dir_forwards);
}

void __anctrl_gotoStart(AnimCtrl *this){
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

void _anctrl_start(AnimCtrl * this, char *file, s32 line){
    if(this->smooth_transition && anim_getIndex(this->animation) != 0){
        anim_resetSmooth(this->animation);
        anim_setIndex(this->animation, this->index);
        __anctrl_gotoStart(this);
        anim_setDuration(this->animation, 0.0f);
    } else{
        anim_resetNow(this->animation);
        anim_setIndex(this->animation, this->index);
        __anctrl_gotoStart(this);
        anim_setDuration(this->animation, 1.0f);
    }
}

void anctrl_setAnimTimer(AnimCtrl *this, f32 timer){
    anim_setTimer(this->animation, timer);
}

void anctrl_setPlaybackType(AnimCtrl *this, enum anctrl_playback_e arg1){
    this->playback_type = arg1;
}

void anctrl_setDirection(AnimCtrl *this, s32 arg1){
    this->playback_direction = arg1;
}

void anctrl_setSmoothTransition(AnimCtrl *this, s32 arg1){
    this->smooth_transition = arg1;
}

void anctrl_setDuration(AnimCtrl *this, f32 arg1){
    if(IO_READ(0x238) - 0x10000003){
        arg1 += 3.0f;
    }
    this->animation_duration = arg1;
}

void anctrl_setTransitionDuration(AnimCtrl *this, f32 arg1){
    this->transition_duration = arg1;
}

void anctrl_setSubRange(AnimCtrl *this, f32 start, f32 end){
    this->subrange_start = start - (f32)(s32)start;
    this->subrange_end = (end != 1.0)? end - (f32)(s32)end : end;

}

void anctrl_getSubRange(AnimCtrl *this, f32 *startPtr, f32 *endPtr){
    *startPtr = this->subrange_start;
    *endPtr = this->subrange_end;
}

void anctrl_setStart(AnimCtrl *this, f32 start_position){
    if(start_position == 1.0)
        start_position = 0.9999989867210388f; // D_80373E18

    this->start = start_position;
    this->default_start = FALSE;
}

void func_80287784(AnimCtrl *this, s32 arg1){
    this->unk23 = arg1;
    this->unk24 = 0;
}

enum asset_e anctrl_getIndex(AnimCtrl *this){
    return anim_getIndex(this->animation);
}

enum anctrl_playback_e anctrl_getPlaybackType(AnimCtrl *this){
    return this->playback_type;
}

s32 anctrl_isPlayedForwards(AnimCtrl *this){
    return this->playback_direction;
}

s32 anctrl_isSmoothTransistion(AnimCtrl *this){
    return this->smooth_transition;
}

f32 anctrl_getDuration(AnimCtrl *this){
    return this->animation_duration;
}

f32 anctrl_getTransistionDuration(AnimCtrl *this){
    return this->transition_duration;
}

f32 anctrl_getAnimTimer(AnimCtrl *this){
    return anim_getTimer(this->animation);
}

f32 anctrl_getTimer(AnimCtrl *this){
    return this->timer;
}

void  anctrl_setTimer(AnimCtrl *this, f32 arg1){
    this->timer = arg1;
}

s32  anctrl_8028780C(f32 position[3], s32 arg1){
    return 0;
}

void anctrl_drawSetup(AnimCtrl *this, f32 *position, s32 arg2){
    s32 map;
    map = gsworld_get_map();
    if( map != MAP_1E_CS_START_NINTENDO 
        && map != MAP_1F_CS_START_RAREWARE
        && map != MAP_20_CS_END_NOT_100 
        && this->unk23 !=0 
        && position != NULL
    ){
        this->unk24 = this->unk24 -1;
        if(this->unk24 == 0xFF){
            this->unk24 = anctrl_8028780C(position, arg2);
        }
        else{
            anim_drawSetup(this->animation);
            return;
        }
    }
    anim_update(this->animation);
}

s32 anctrl_isStopped(AnimCtrl *this){
    return anctrl_getPlaybackType(this) == ANIMCTRL_STOPPED;
}

int anctrl_isAt(AnimCtrl *this, f32 arg1){
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

s32 anctrl_isContiguous(AnimCtrl *this){
    return (s32)this->animation - (s32) this == 0x28;
}
