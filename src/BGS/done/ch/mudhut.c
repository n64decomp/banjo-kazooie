#include <ultra64.h>
#include "functions.h"
#include "variables.h"

/* TODO move declarations to respective headers*/
Actor *func_8032813C(u32, f32 *, f32*);
void func_8028F710(u32, f32);

void func_802C4218(u32,f32,f32,f32);
void func_8030E8B4(u32,f32*, u32);
void func_80328A84(Actor *, u32);

/* local declarations */
Actor *func_8038EAD0(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3);
void func_8038EB4C(ActorMarker *);
void func_8038EB8C(Actor *this);

/* .data section */
ActorAnimationInfo D_80390B30[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {anim_mudhut_smashing, 0.25f},
    {anim_mudhut_smashing, 1000000.0f}
};

extern u32 D_80390B50[6] = {0xA, 0xA, 0xB, 0xA, 0xA, 0xC
};

ActorInfo D_80390B68 = {0xD5, ACTOR_C_MUD_HUT, model_mudhut_top, 0x01, D_80390B30,
    func_8038EB8C, func_80326224, func_8038EAD0,
    {0,0,0,0}, 0.0f, {0,0,0,0}
};

/* .code section */
void func_8038EA30(void){
    if((getGameMode() != GAME_MODE_7_ATTRACT_DEMO) && (1.5 < func_8028E80C(2)) ){
        func_8028F710(2, 1.5);
    }
}

void func_8038EA90(void){
    u32 sp1C;
    osPiReadIo(0xD10, &sp1C);
    if(sp1C = (u16)(sp1C-0x400)){
        func_8038EA30();
    }
}

Actor *func_8038EAD0(ActorMarker *this, Gfx** gdl, Mtx** mtx, u32 arg3){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    func_8033A45C(1, thisActor->state == 1);
    if(thisActor->state == 3)
        return thisActor;
    
    return func_80325888(this, gdl, mtx, arg3);
}

void func_8038EB4C(ActorMarker *this){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    thisActor = func_8032813C(ACTOR_D_WOOD_DEMOLISHED, thisActor->position, NULL);
    thisActor = func_8032813C(ACTOR_4D_STEAM_2, thisActor->position, NULL);
    if(this);
}

void func_8038EB8C(Actor *this){
    
    f32 diffPos[3];
    f32 plyrPos[3];
    s32 tmp;

    if(func_80334904() == 2){
        if(!this->initialized){
            this->marker->collidable = 0;
            this->initialized = 1;
        }

        switch(this->state){
            case 1:
                this->marker->propPtr->unk8_3 = 1;
                player_getPosition(&plyrPos);
                diffPos[0] = plyrPos[0] - this->position_x;
                diffPos[1] = plyrPos[1] - this->position_y;
                diffPos[2] = plyrPos[2] - this->position_z;
                if( (150.0f < diffPos[1]) 
                    && (player_getActiveHitbox(this->marker) == HITBOX_1_BEAK_BUSTER) 
                    && (func_8028F20C())
                    && (gu_sqrtf(diffPos[0]*diffPos[0] + diffPos[1]*diffPos[1] + diffPos[2]*diffPos[2]) < 350.f)
                ){
                    tmp = (s32)( (this->position_y - 600.f)/430.0f);
                    diffPos[0] = this->position_x;
                    diffPos[1] = this->position_y;
                    diffPos[2] = this->position_z;
                    diffPos[1] += 130.0;

                    FUNC_8030E8B4(SFX_5B_HEAVY_STUFF_FALLING, 875, 0x3ff, this->position, 0x12C, 0xBB8);
                    func_80328A84(this, 2);
                    this->marker->propPtr->unk8_3 = 0;
                    actor_playAnimationOnce(this);
                    if(tmp == 5){
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                    }
                    func_802C3C88(func_8038EB4C, this->marker);
                    if(tmp < 5){
                        func_802C3F04(func_802C4218,D_80390B50[tmp], ((u32 *)diffPos)[0], ((u32 *)diffPos)[1], ((u32 *)diffPos)[2]);
                    } else {
                        jiggySpawn(JIGGY_23_BGS_HUTS, diffPos);
                    }
                }
                break;
            case 2:
                this->marker->propPtr->unk8_3 = 0;
                if(0.99 < func_802877D8(this->animctrl)){
                    this->state = 3;
                }
                break;
            case 3:
                this->marker->propPtr->unk8_3 = 0;
                break;
        }
    }
    else{

    }
}
