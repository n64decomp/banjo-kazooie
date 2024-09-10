/*!!!DONE!!!*/
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#ifndef MIN
#define MIN(s,t) ((s < t)?(s):(t))
#endif

#ifndef ORANGE_FALLING_STATE
#define ORANGE_FALLING_STATE 1
#endif

#ifndef ORANGE_LANDED_STATE
#define ORANGE_LANDED_STATE 2
#endif

/* extern functions */
f32 func_80309724(f32*);

/* public functions */
void    MM_func_80387FF4(Actor *this);
Actor*  func_80388188(ActorMarker *, Gfx **, Mtx**, Vtx**);

/* .data */
ActorInfo chorangeInfo = { MARKER_C_ORANGE_PROJECTILE, ACTOR_14_ORANGE_PROJECTILE, ASSET_2D2_MODEL_ORANGE,
    1, NULL,
    MM_func_80387FF4, func_80326224, func_80388188,
    0, 0, 0.6f, 0
};

f32 D_803899F4[3] = {0.0f,-8.0f, 0.0f};
f32 D_80389A00[3] = {0.0f, 0.0f, 0.0f};

void func_80387F90(ActorMarker *arg0, ActorMarker *other_marker){
    if( !func_8028F22C(arg0)
        && !mapSpecificFlags_get(mapflag_mm_main_hit_with_orange)
        && func_80311480(ASSET_B3A_TEXT_CONGA_HITS_PLAYER, 0, 0, 0, NULL, NULL)
    ){
        mapSpecificFlags_set(mapflag_mm_main_hit_with_orange, 1);
    }

    if(arg0);
}

void MM_func_80387FF4(Actor * this){
    f32 ground_position_y;
    f32 velocity_y;

    if(!this->initialized){
        this->marker->unk2C_1 = 1;
        marker_setCollisionScripts(this->marker, NULL, func_80387F90, NULL);
    }
    switch(this->state){
        case ORANGE_FALLING_STATE:
            this->position_x += this->velocity_x;
            velocity_y = this->velocity_y - 5.0;
            this->velocity_y = velocity_y;
            this->position_y += velocity_y;
            this->position_z += this->velocity_z;

            ground_position_y = func_80309724(this->position);

            if(this->position_y < ground_position_y){
                this->position_y = ground_position_y;
                this->unk1C_y = ground_position_y;
                func_8030E6D4(SFX_2F_ORANGE_SPLAT);

                this->unk28 = 1.0f;
                this->unk60 = 340.0f;
                this->state = 2;
            }
            break;
        case ORANGE_LANDED_STATE:
            if(this->unk60 < 324.0){
                this->marker->collidable = FALSE;
            }
            this->unk60 -= 4.0;
            if(this->unk60 < 4.0){
                marker_despawn(this->marker);
            }
            break;
    }
}

Actor *func_80388188(ActorMarker *this, Gfx **dl, Mtx **mptr, Vtx **vtx){
    Actor* actorPtr = actor_drawFullDepth(this, dl, mptr, vtx);
    f32 sp60[3] = D_803899F4;
    f32 rotation[3] = D_80389A00;
    f32 position[3];

    if(actorPtr->state == 2){
        position[0] = actorPtr->position_x;
        position[1] = actorPtr->unk1C_y + 3.0f;
        position[2] = actorPtr->position_z;
        modelRender_setAlpha( (s32) MIN(255.0f, actorPtr->unk60) );
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(dl, mptr, position, rotation, actorPtr->unk28, sp60, func_8030A428(0x18));
        actorPtr->position_y -= 1.9;
        if(actorPtr->unk28 < 2.428){
            actorPtr->unk28 += 0.1;
        }
    }
    return actorPtr;
}
