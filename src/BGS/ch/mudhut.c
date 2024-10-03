#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "core2/statetimer.h"

/* TODO move declarations to respective headers*/
extern void player_stateTimer_set(enum state_timer_e, f32);
extern f32 player_stateTimer_get(enum state_timer_e);


Actor *spawnQueue_bundle_f32(u32,f32,f32,f32);
void subaddie_set_state(Actor *, u32);

/* local declarations */
Actor *chmudhut_draw(ActorMarker *this, Gfx** gdl, Mtx** mtx, Vtx **vtx);
void func_8038EB4C(ActorMarker *);
void chmudhut_update(Actor *this);

/* .data section */
ActorAnimationInfo D_80390B30[4] = {
    {0, 0.0f},
    {0, 0.0f},
    {ASSET_4E_ANIM_MUDHUT_SMASH, 0.25f},
    {ASSET_4E_ANIM_MUDHUT_SMASH, 1000000.0f}
};

enum bundle_e D_80390B50[6] = {
    BUNDLE_A_BGS_HUT_SHOCKSPRING_PAD,
    BUNDLE_A_BGS_HUT_SHOCKSPRING_PAD,
    BUNDLE_B_BGS_HUT_MUSIC_NOTE,
    BUNDLE_A_BGS_HUT_SHOCKSPRING_PAD,
    BUNDLE_A_BGS_HUT_SHOCKSPRING_PAD,
    BUNDLE_C_BGS_HUT_JIGGY
};

ActorInfo D_80390B68 = {MARKER_D5_BGS_MUD_HUT, ACTOR_C_MUD_HUT, ASSET_7D8_MODEL_MM_HUT_TOP, 0x01, D_80390B30,
    chmudhut_update, func_80326224, chmudhut_draw,
    0, 0, 0.0f, 0
};

/* .code section */
void func_8038EA30(void){
    if((getGameMode() != GAME_MODE_7_ATTRACT_DEMO) && (1.5 < player_stateTimer_get(2)) ){
        player_stateTimer_set(STATE_TIMER_2_LONGLEG, 1.5);
    }
}

void func_8038EA90(void){
    u32 sp1C;
    osPiReadIo(0xD10, &sp1C);
    if(sp1C = (u16)(sp1C-0x400)){
        func_8038EA30();
    }
}

Actor *chmudhut_draw(ActorMarker *this, Gfx** gdl, Mtx** mtx, Vtx **vtx){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    func_8033A45C(1, thisActor->state == 1);
    if(thisActor->state == 3)
        return thisActor;
    
    return actor_draw(this, gdl, mtx, vtx);
}

void func_8038EB4C(ActorMarker *this){
    Actor *thisActor;

    thisActor = marker_getActor(this);
    thisActor = actor_spawnWithYaw_f32(ACTOR_D_WOOD_DEMOLISHED, thisActor->position, NULL);
    thisActor = actor_spawnWithYaw_f32(ACTOR_4D_STEAM_2, thisActor->position, NULL);
    if(this);
}

void chmudhut_update(Actor *this){
    
    f32 diffPos[3];
    f32 plyrPos[3];
    s32 tmp;

    if(func_80334904() == 2){
        if(!this->initialized){
            this->marker->collidable = FALSE;
            this->initialized = TRUE;
        }

        switch(this->state){
            case 1:
                this->marker->propPtr->unk8_3 = 1;
                player_getPosition(plyrPos);
                diffPos[0] = plyrPos[0] - this->position_x;
                diffPos[1] = plyrPos[1] - this->position_y;
                diffPos[2] = plyrPos[2] - this->position_z;
                if( (150.0f < diffPos[1]) 
                    && (player_getActiveHitbox(this->marker) == HITBOX_1_BEAK_BUSTER) 
                    && (func_8028F20C())
                    && (LENGTH_VEC3F(diffPos) < 350.f)
                ){
                    tmp = (s32)( (this->position_y - 600.f)/430.0f);
                    diffPos[0] = this->position_x;
                    diffPos[1] = this->position_y;
                    diffPos[2] = this->position_z;
                    diffPos[1] += 130.0;

                    FUNC_8030E8B4(SFX_5B_HEAVY_STUFF_FALLING, 1.0f, 28000, this->position, 0x12C, 0xBB8);
                    subaddie_set_state(this, 2);
                    this->marker->propPtr->unk8_3 = 0;
                    actor_playAnimationOnce(this);
                    if(tmp == 5){
                        func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
                    }
                    __spawnQueue_add_1((GenFunction_1)func_8038EB4C, reinterpret_cast(s32, this->marker));

                    if (tmp < 5) {
                        __spawnQueue_add_4((GenFunction_4) spawnQueue_bundle_f32, D_80390B50[tmp], reinterpret_cast(s32, diffPos[0]), reinterpret_cast(s32, diffPos[1]), reinterpret_cast(s32, diffPos[2]));
                    }
                    else {
                        jiggy_spawn(JIGGY_23_BGS_HUTS, diffPos);
                    }
                }
                break;
            case 2:
                this->marker->propPtr->unk8_3 = 0;
                if(0.99 < animctrl_getAnimTimer(this->animctrl)){
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
