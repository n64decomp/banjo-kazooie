#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* extern functions */
void func_80326224(Actor *);
void func_80329904(ActorMarker *, s32, void *);
extern void func_802EFA20(ParticleEmitter *, f32, f32);


/* public functions */
void func_80386768(Actor *);

/* .data */
ActorInfo chorangepadInfo = { MARKER_66_ORANGE_PAD, ACTOR_57_ORANGE_PAD, ASSET_2EB_MODEL_ORANGE_PAD, 
    0, NULL,
    func_80386768, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/*.code */
void MM_func_803863F0(s32 x, s32 y, s32 z){
    f32 pos[3];

    TUPLE_ASSIGN(pos, x, y, z);
    
    jiggy_spawn(JIGGY_8_MM_ORANGE_PADS, pos);
}

void func_80386444(ActorMarker *arg0){
    f32 orange_pad_distance;
    Actor *orange_pad;
    f32 sp44[3];
    ParticleEmitter *s0;
    s32 temp_a0;

    sp44[0] = arg0->propPtr->x;
    sp44[1] = arg0->propPtr->y;
    sp44[2] = arg0->propPtr->z;
    orange_pad = actorArray_findClosestActorFromActorId(sp44, ACTOR_57_ORANGE_PAD, 1, &orange_pad_distance);
    

    if(orange_pad && !(500.0f < orange_pad_distance)){
        orange_pad->state = 1;
        if(actorArray_findClosestActorFromActorId(sp44, ACTOR_57_ORANGE_PAD, 1, &orange_pad_distance)){
            func_8025A6EC(COMUSIC_2B_DING_B, 22000);
        }else{
            temp_a0 = (orange_pad->unk78_13 == 0x106) ? 0x10 
                    : (orange_pad->unk78_13 == 0x76)  ? 0xf 
                    : 0xe;

            func_802BAFE4(temp_a0);
            sp44[1] += 50.0f;
            timedFunc_set_3(0.6f, (GenFunction_3) MM_func_803863F0, (s32)sp44[0], (s32)sp44[1], (s32)sp44[2]);
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
            if(!jiggyscore_isCollected(JIGGY_8_MM_ORANGE_PADS)){
                func_80311480(0xB3B, 4, NULL, NULL, NULL, NULL);
            }
        }// L803865D8

        //emmit sparkles
        s0 = partEmitMgr_newEmitter(30);
        particleEmitter_setPosition(s0, orange_pad->position);
        particleEmitter_setModel(s0, 0x89f);
        func_802EFB70(s0, 0.09f, 0.19f);
        func_802EFB84(s0, 0.0f, 0.0f);

        particleEmitter_setParticleVelocityRange(s0,
            -200.0f, 500.0f, -200.0f,
            200.0f, 700.0f, 200.0f
        );

        particleEmitter_setParticleAccelerationRange(s0, 
            0.0f, -1200.0f, 0.0f,
            0.0f, -1200.0f, 0.0f
        );

        particleEmitter_setAngularVelocityRange(s0, 
            -600.0f, -600.0f, -600.0f,
            600.0f, 600.0f, 600.0f
        );
        particleEmitter_setSpawnIntervalRange(s0, 0.0f, 0.01f);
        particleEmitter_setParticleLifeTimeRange(s0, 4.0f, 4.0f);
        func_802EF9F8(s0, 0.01f);
        func_802EFA18(s0, 3);
        func_802EFA20(s0, 1.0f, 1.3f);
        particleEmitter_emitN(s0, 30);
    }
}

void func_80386744(s32 arg0, ActorMarker *arg1) {
    func_80386444(arg1);
}

void func_80386768(Actor * this){
    Actor *sp3C;
    f32 pad;
    f32 sp34;
    

    if(!this->initialized){
        this->marker->propPtr->unk8_3 = 1;
        actor_collisionOff(this);
        this->initialized = 1;
    }//L803867B0

    if(!this->unk16C_4){
        this->unk100 = actorArray_findClosestActorFromActorId(this->position, 8,-1, &sp34)->marker;
        this->unk16C_4 = 1;
    }//L803867E0

    if(this->unk100){
        sp3C = marker_getActor(this->unk100);
    }

    if( func_80329530(this, 0x28)
        && !func_8028ECAC()
        && !mapSpecificFlags_get(6)
        && sp3C->state != 3
    ){
        if(func_80311480(0xb3d, 0, NULL, NULL, NULL, NULL))
            mapSpecificFlags_set(6,1);
    }

    if(this->state == 1){
            if(this->unk60 < 72.0f){
                func_8033E73C(this->marker, 5, func_80329904);
                func_8033E3F0(9, this->marker->unk14_21);
            }
            this->unk60 = MIN(255.0, this->unk60 + 7.0);

            if(255.0 == this->unk60){
                marker_despawn(this->marker);
            }
    }else{
    }//L80386928

    actor_setOpacity(this, 0xFF - (s32)this->unk60);
}//*/
