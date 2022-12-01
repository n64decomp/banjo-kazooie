#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Actor *func_802DC320(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DC67C(Actor *this);

/* .data */
f32 D_80368070[3] = {0.0f, 0.0f, 0.0f};
ActorInfo D_8036807C = { 
    0x17C, 0x19C, 0x56C,
    0x1, NULL, 
    func_802DC67C, func_80326224, func_802DC320, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DE50;

/* .code */
void func_802DC650(Actor * this){
    D_8037DE50 = NULL;
    func_8025A7DC(COMUSIC_AC_GOOD_ENDING);
}

void func_802DC67C(Actor *this){
    if(!this->initialized){

        this->initialized = TRUE;
        this->depth_mode = MODEL_RENDER_DEPTH_NONE;
        func_803262E4(this);
        actor_collisionOff(this);
        func_803300D8(this->marker, func_802DC650);
    }
}

void func_802DC6E4(void) {
    Actor *actor;
    if (D_8037DE50 == 0) {
        actor = func_8032813C(0x19C, D_80368070, 0);
        D_8037DE50 = actor->marker;
        func_8025A58C(0, 5000);
        func_8025AB00();
        func_8025A6EC(COMUSIC_AC_GOOD_ENDING, -1);
    }
}

void func_802DC748(s32 arg0, s32 arg1){
    if(D_8037DE50 == NULL){
        func_802C3BF8(func_802DC6E4);
    }
}

void func_802DC780(s32 arg0, s32 arg1){
    if(D_8037DE50 != NULL){
        comusic_8025AB44(COMUSIC_AC_GOOD_ENDING, 0, 200);
        func_8025AABC(0x31);
        func_80326310(marker_getActor(D_8037DE50));
    }
}
