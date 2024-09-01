#include <ultra64.h>
#include "core2/anim/sprite.h"

#include "functions.h"
#include "variables.h"



/* .bss */
u8 D_80379B90[0x10];
static AnimSprite s_animsprite_list[40];

/* .code */
static void __animsprite_reset_loop(AnimSprite *this){
    this->remaining_time += this->steps[this->current_step].duration*(1.0/30.0)*this->speed_multiplier;
}

static void __animsprite_update_looped(AnimSprite *this){
    this->remaining_time -= time_getDelta();
    while(this->remaining_time <= 0.0f){
        this->current_step++;
        if(this->current_step >= this->step_count)
            this->current_step = 0;
        __animsprite_reset_loop(this);
    }
}

static void __animsprite_update_once(AnimSprite *this){
    this->remaining_time -= time_getDelta();
    while(this->remaining_time <= 0.0f){
        this->current_step++;
        if(this->step_count <= this->current_step){
            this->current_step--;
            this->state = ANIM_SPRITE_STATE_STOPPED;
        }
        __animsprite_reset_loop(this);
    }
}

/**
 * @brief initializes the use of AnimSprite structures
 * 
 */
void animsprite_init(void){
    int i;
    for(i = 0; i < 40; i++){
        s_animsprite_list[i].active = 0;
    }
}

/**
 * @brief Returns pointer to first free AnimSprite slot.
 * Returns NULL if not slots are free
 * 
 * @return AnimSprite* 
 */
AnimSprite * animsprite_new(void){
    int i;
    for(i = 0; i < 40; i++){
        if(!s_animsprite_list[i].active){
            s_animsprite_list[i].active = 1;
            s_animsprite_list[i].current_step = 0;
            s_animsprite_list[i].state = 0;
            s_animsprite_list[i].step_count = 1;
            s_animsprite_list[i].start_step = 0;
            s_animsprite_list[i].steps = 0;
            s_animsprite_list[i].unknown = 1;
            s_animsprite_list[i].remaining_time = 0.0f;
            s_animsprite_list[i].speed_multiplier = 1.0f;
            s_animsprite_list[i].current_frame = 0;
            return &s_animsprite_list[i];
        }
    }
    return NULL;
}

/**
 * @brief Marks AnimSprite as inactive/free
 * 
 * @param this 
 */
void animsprite_free(AnimSprite *this){
    this->active = 0;
}

/**
 * @brief Destructs all AnimSprites
 * 
 */
void animsprite_terminate(void){
    int i;
    for(i = 0; i < 40; i++){
        if(s_animsprite_list[i].active){
            animsprite_free(&s_animsprite_list[i]);
        }
    }
}

/**
 * @brief performs frame update of an AnimSprite
 * 
 * @param this 
 */
void animsprite_update(AnimSprite *this){
    switch(this->state){
        case ANIM_SPRITE_STATE_NONE:
            break;
        case ANIM_SPRITE_STATE_ONCE:
            __animsprite_update_once(this);
            this->current_frame = this->steps[this->current_step].index;
            break;
        case ANIM_SPRITE_STATE_LOOP:
            __animsprite_update_looped(this);
            this->current_frame = this->steps[this->current_step].index;
            break;
        case ANIM_SPRITE_STATE_STOPPED:
            break;
    }
}

/**
 * @brief sets an AnimSprite to default settings
 * 
 * @param this 
 */
void animsprite_default(AnimSprite *this){
    this->current_step = 0;
    this->remaining_time = 0.0f;
    animsprite_set_steps(this, NULL, 1);
    animsprite_set_speed(this, 1.0f);
    animsprite_set_start_step(this, 0);
    animsprite_set_state(this, ANIM_SPRITE_STATE_LOOP);
    animsprite_set_unknown(this, 1);
}

/**
 * @brief starts the lopping of a AnimSprite
 * 
 * @param this 
 */
void animsprite_loop(AnimSprite *this){
    this->current_step = this->start_step;
    __animsprite_reset_loop(this);
}

/**
 * @brief sets the steps of a AnimSprite
 * 
 * @param this pointer to AnimSprite
 * @param step_list pointer to AnimSpriteStep array
 * @param size size of step list in bytes
 */
void animsprite_set_steps(AnimSprite *this, AnimSpriteStep *step_list, s32 size){
    this->steps = step_list;
    this->step_count = size/2;
}

/**
 * @brief sets the state of a AnimSpriteState
 * 
 * @param this 
 * @param arg1 
 */
void animsprite_set_state(AnimSprite *this, AnimSpriteState arg1){
    this->state = arg1;
}

/**
 * @brief sets an unknown bit bit in a AnimSprite
 * 
 * @param this 
 * @return s32 
 * 
 * @note This bit is not used in the final release of Banjo-Kazooie
 */
void animsprite_set_unknown(AnimSprite *this, s32 arg1){
    this->unknown = arg1;
}

/**
 * @brief sets the current frame index of a AnimSprite
 * 
 * @param this
 * @param arg1
 * 
 * @note this only persists if the AnimSprite is stopped
 */
void animsprite_set_frame(AnimSprite *this, s32 arg1){
    this->current_frame = arg1;
}

/**
 * @brief sets the speed multiplier of a AnimSprite
 * 
 * @param this pointer to AnimSprite
 * @param speed speed multiplier to default speed of 1 sprite frame per game
 * frame (30 fps)
 */
void animsprite_set_speed(AnimSprite *this, f32 speed){
    this->speed_multiplier = speed;
}

/**
 * @brief sets the start position of a AnimSprite
 * 
 * @param this 
 * @param step 
 */
void animsprite_set_start_step(AnimSprite *this, s32 step){
    this->start_step = step;
}

/**
 * @brief returns the frame index corresponding to the current step of a 
 * AnimSprite
 * 
 * @param this 
 * @return s32 
 */
s32 animsprite_get_frame(AnimSprite *this){
    return this->current_frame;
}

/**
 * @brief returns the current state of a AnimSprite
 * 
 * @param this 
 * @return AnimSpriteState 
 */
AnimSpriteState animsprite_get_current_state(AnimSprite *this){
    return this->state;
}

/**
 * @brief returns a bit from a AnimSprite
 * 
 * @param this 
 * @return s32 
 * 
 * @note This bit is not used in the final release of Banjo-Kazooie
 */
s32 animsprite_get_unknown(AnimSprite *this){
    return this->unknown;
}

/**
 * @brief returns the speed multiplier applied to a AnimSprite
 * 
 * @param this 
 * @return f32 
 */
f32 animsprite_get_speed(AnimSprite *this){
    return this->speed_multiplier;
}

/**
 * @brief returns true if AnimSprite is stopped
 * 
 * @param this 
 * @return int 
 */
int animsprite_is_stopped(AnimSprite *this){
    return animsprite_get_current_state(this) == 3;
}

/**
 * @brief returns true if AnimSprite is on specified step
 * 
 * @param this 
 * @param frame 
 * @return int 
 */
int animsprite_is_at_step(AnimSprite *this, s32 frame){
    return this->current_step == frame;
}
