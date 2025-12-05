#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef enum  {
    BA_LOOKAT_STATE_0_NONE,
    BA_LOOKAT_STATE_1_UNKNOWN,
    BA_LOOKAT_STATE_2_UNKNOWN,
    BA_LOOKAT_STATE_3_UNKNOWN,
    BA_LOOKAT_STATE_4_UNKNOWN,
} BaLookAtState;

typedef struct{
    u8 state;
    u8 lookat;
    f32 position[3]; // position
}BaLookAt;

/* .bss */
BaLookAt s_lookat_stack[8];
u8 s_length;
u8 s_lookat_state;

/* .code */
int balookat_try_get_position(f32 arg0[3]){
    if(!s_lookat_stack[s_length - 1].lookat)
        return 0;

    ml_vec3f_copy(arg0, s_lookat_stack[s_length - 1].position);
    return 1;
}

BaLookAtState balookat_getState(void){
    if(!s_length){
        return 0;
    }
    return s_lookat_stack[s_length - 1].state;
}

void balookat_init(void){
    s_lookat_state = 0;
    s_length = 0;
}

void balookat_pop(void){
    if(s_length){
        s_length--;
        if(s_length == 0){
            baiFrame_startWithValue(1.2f);
            s_lookat_state = 0;
        }
    }
}

void balookat_push(BaLookAtState state){
    s_lookat_stack[s_length].state = state;
    s_lookat_stack[s_length].lookat = FALSE;
    ml_vec3f_clear(s_lookat_stack[s_length].position);
    s_length++;
}

void balookat_set_position(f32 position[3]){
    s_lookat_stack[s_length-1].lookat = TRUE;
    ml_vec3f_copy(s_lookat_stack[s_length-1].position, position);
}

void balookat_update_state(BaLookAtState state){
    int val = 0;
    switch(state){
        case 1:
            if(bs_checkInterrupt(BS_INTR_1E) == 2)
                val = 1;
            break;
        case 2:
            if(bs_checkInterrupt(BS_INTR_1C) == 2)
                val = 1;
            break;
        case 3:
            if(bs_checkInterrupt(BS_INTR_1D) == 2)
                val = 1;
            break;
        case 4:
            if(bs_checkInterrupt(BS_INTR_25) == 2)
                val = 1;
            break;
        default:
            val = 1;
            break;
    }
    if(val)
        s_lookat_state = state;
}

void balookat_end(void){
    if(s_length != 0)
        s_lookat_state = 0;
}

void balookat_update(void){
    s32 tmp;
    if(s_length){
        tmp = s_lookat_stack[s_length-1].state;
        if(s_lookat_state != tmp){
            balookat_update_state(tmp);
        }
    }
}
