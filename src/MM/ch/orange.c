/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef MIN
#define MIN(s,t) ((s < t)?(s):(t))
#endif

/* extern functions */
void func_80326224(Actor *);
f32 func_80309724(f32*);
Actor *func_80325E78(ActorMarker *);

/* public functions */
void    func_80387FF4(Actor *this);
Actor*  func_80388188(ActorMarker *, Gfx **, Mtx**);

/* .data */
ActorInfo chorangeInfo = { 0xC, actor_orange_projectile, model_orange, 1, NULL,
    func_80387FF4, func_80326224, func_80388188,
    {0,0,0,0}, 0.6f, {0,0,0,0}
};

f32 D_803899F4[3] = {0.0f,-8.0f, 0.0f};
f32 D_80389A00[3] = {0.0f, 0.0f, 0.0f};

void func_80387F90(ActorMarker *arg0, s32 arg1){
    if( !func_8028F22C(arg0) 
        && !mapSpecificFlags_get(mapflag_mm_main_hit_with_orange)
        && func_80311480(text_conga_hits_player, 0, 0, 0, NULL, NULL)
    ){
        mapSpecificFlags_set(mapflag_mm_main_hit_with_orange, 1);
    }

    if(arg0);
}

void func_80387FF4(Actor * this){
    f32 temp_f2;
    f32 temp_f0;

    if(!this->initialized){
        this->marker->unk2C_1 = 1;
        func_803300A8(this->marker, NULL, func_80387F90, NULL);
    }
    switch(this->unk10_31){
        case 1://L80388060
            this->position_x += this->velocity_x;
            temp_f0 = this->velocity_y - 5.0;
            this->velocity_y = temp_f0;
            this->position_y += temp_f0;
            this->position_z += this->velocity_z;
            
            
            temp_f2 = func_80309724(this->position);
            if(this->position_y < temp_f2){
                this->position_y = temp_f2;
                this->unk1C_y = temp_f2;
                func_8030E6D4(0x2F);
                
                this->unk28 = 1.0f;
                this->unk60 = 340.0f;
                this->unk10_31 = 2;
            }
            break;
        case 2://L8038810C
            if(this->unk60 < 324.0){
                this->marker->collidable = 0;
            }
            this->unk60 -= 4.0;
            if(this->unk60 < 4.0){
                marker_despawn(this->marker);
            }
            break;
    }
}

Actor *func_80388188(ActorMarker *this, Gfx **dl, Mtx **mptr){
    Actor* actorPtr = func_80325E78(this);
    f32 sp60[3] = D_803899F4;
    f32 sp54[3] = D_80389A00;
    f32 sp48[3];

    if(actorPtr->unk10_31 == 2){
        sp48[0] = actorPtr->position_x;
        sp48[1] = actorPtr->unk1C_y + 3.0f;
        sp48[2] = actorPtr->position_z;
        func_8033A410( (s32) MIN(255.0f, actorPtr->unk60) );
        func_8033A4CC(1);
        func_803391A4(dl, mptr, sp48, sp54, actorPtr->unk28, sp60, func_8030A428(0x18));
        actorPtr->position_y -= 1.9;
        if(actorPtr->unk28 < 2.428){
            actorPtr->unk28 += 0.1;
        }
    }
    return actorPtr;
}
