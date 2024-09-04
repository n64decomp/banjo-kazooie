#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80328748(AnimCtrl *, f32, f32);
extern void func_8028F94C(s32, f32[3]);
extern void func_80324CFC(f32, enum comusic_e, s32);
extern void func_803289EC(Actor *, f32, s32);
extern void func_80326310(Actor *);
extern void actor_setOpacity(Actor *, s32);
extern void __spawnQueue_add_2(void (*)(s32, s32), s32, s32);
extern void func_802BAFE4(s32 arg0);



void func_80387D18(ActorMarker *, u32);
Actor *func_8038860C(ActorMarker *, Gfx**, Mtx **, Vtx**);
void func_80387FD4(Actor *this);

/* .data */
s16 D_803907B0[4] = {0x15, 0x16, 0x17, 0x18};
ActorMarker *bgs_D_803907B8[5] = {NULL};
ActorAnimationInfo D_803907CC[] = {
    {0x000, 0.0f},
    {0x14B, 3.3e+7f},
    {0x14B, 1.4f},
    {0x14B, 3.3e+7f},
    {0x14B, 1.4f},
    {0x14B, 2.0f},
    {0x14B, 2.0f}
};
ActorInfo D_80390804 ={MARKER_FC_CROCTUS, ACTOR_1FA_CROCTUS, ASSET_425_MODEL_CROCTUS,
    1, D_803907CC,
    func_80387FD4, func_80326224, func_8038860C,
    0, 0, 0.0f, 0
};

/* .code */
void func_80387C90(Actor *arg0){
    animctrl_setDuration(arg0->animctrl, 0.4 + 0.9999999999999999 * ((f32)(5 - arg0->unkF4_8) * 0.25));
}

void func_80387D18(ActorMarker * arg0, u32 arg1){
    Actor* this;
    Actor* nextActPtr;

    this = marker_getActor(arg0);
    nextActPtr = spawn_child_actor(0x6A, &this);
    nextActPtr->state = 2;
    nextActPtr->unkF4_8 = 0x8C;
    nextActPtr->unk60 = 3.0f;
    nextActPtr->unk38_31 = arg1;
    if(arg0);
}

void *func_80387D90(ActorMarker * arg0){
    ActorMarker *marker;
    Actor* this;
    f32 spawnPos[3];

    marker = reinterpret_cast(ActorMarker *, arg0);
    this = marker_getActor(marker);
    spawnPos[0] = this->position_x;
    spawnPos[1] = this->position_y;
    spawnPos[2] = this->position_z;
    marker->propPtr->unk8_3 = 0;
    func_802BAFE4(0x19);
    jiggy_spawn(JIGGY_22_CROCTUS, spawnPos);
    func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 0x7FFF);
}

void func_80387E00(s32 arg0){
    ActorMarker *marker = reinterpret_cast(ActorMarker *, arg0);
    Actor * this = marker_getActor(marker);

    func_803262E4(this);
    __spawnQueue_add_2((GenFunction_2)func_80387D18, reinterpret_cast(s32, marker), 0x1E);
}

void func_80387E40(ActorMarker * arg0){
    Actor *thisActor = marker_getActor(arg0);
    func_80326310(thisActor);
    if(arg0);
}

void func_80387E68(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this;

    if(text_id == 0xC86){
        this = marker_getActor(caller);
        timed_playSfx(0.4f, SFX_C9_PAUSEMENU_ENTER, 1.0f, 32000);
        timed_playSfx(1.4f, SFX_C9_PAUSEMENU_ENTER, 1.0f, 32000);
        func_80324CFC(0.4f, COMUSIC_43_ENTER_LEVEL_GLITTER, 22000);
        func_80324D2C(4.5f, COMUSIC_43_ENTER_LEVEL_GLITTER);
        subaddie_set_state_with_direction(this, 5, 0.79f, 1);
        func_80326310(this);
        bgs_D_803907B8[this->unkF4_8]->propPtr->unk8_4 = TRUE;
        timedFunc_set_1(1.1f, (GenFunction_1)func_80387E00, reinterpret_cast(s32, bgs_D_803907B8[this->unkF4_8]));
        timed_setStaticCameraToNode(0.8f, 9);
        func_80324DBC(3.4f, 0xC87, 0xE, NULL, NULL, func_80387E68, NULL);
        __spawnQueue_add_2((GenFunction_2) func_80387D18, reinterpret_cast(s32, this->marker), 0x46);
    }
    else{
        timed_exitStaticCamera(0.0f);
        func_8028F918(0);
    }
}

void func_80387FD4(Actor *this){
    int j;

    if(!this->unk16C_4){
        if(jiggyscore_isCollected(JIGGY_22_CROCTUS)){
            marker_despawn(this->marker);
            return;
        }
        this->unk16C_4 = TRUE;
        if(bgs_D_803907B8[this->unkF4_8 - 1] == 0){
            bgs_D_803907B8[this->unkF4_8 - 1] = this->marker;
            for(j = this->unkF4_8; j < 6; j++){
                if(bgs_D_803907B8[j] != NULL){
                    bgs_D_803907B8[j]->propPtr->unk8_4 = FALSE;
                    actor_setOpacity(marker_getActor(bgs_D_803907B8[j]), 0);
                }
            }//L803880C8
            
            for( j = this->unkF4_8 - 2; j >= 0 && bgs_D_803907B8[j] == NULL; j--);

            
            if(j >= 0){
                this->marker->propPtr->unk8_4 = FALSE;
                actor_setOpacity(this, 0);
            }
            this->marker->propPtr->unk8_3 = TRUE;
        }//L80388144
        func_803289EC(this, 0.0f, 1);
        this->unk60 = 0.0f;
        return;
    }//L80388160

    if(this->unk38_31){
        if ((this->state != 5) && (this->state != 6)) {
            func_8025A6EC(COMUSIC_2B_DING_B, 28000); //TODO ISSUE HERE
            if (this->unkF4_8 == 1) {
                func_8028F94C(2, this->position);
                func_80311480(0xC86, 0xE, this->position, this->marker, func_80387E68, NULL);
                subaddie_set_state_with_direction(this, 6, 0.79f, 1);
            } else {
                timed_playSfx(0.4f, SFX_C9_PAUSEMENU_ENTER, 1.0f, 32000); //0.4f
                timed_playSfx(1.4f, SFX_C9_PAUSEMENU_ENTER, 1.0f, 32000); //1.4f
                func_80324CFC(0.4f, COMUSIC_43_ENTER_LEVEL_GLITTER, 22000);
                func_80324D2C(4.5f, COMUSIC_43_ENTER_LEVEL_GLITTER);
                subaddie_set_state_with_direction(this, 5, 0.79f, 1);
                if (this->unkF4_8 == 5) {
                    timedFunc_set_1(0.9f, (GenFunction_1) func_80387E40, (s32) this->marker);
                } else {
                    func_80326310(this);
                }
                if (this->unkF4_8 < 5) {
                    bgs_D_803907B8[this->unkF4_8]->propPtr->unk8_4 = TRUE;
                    timedFunc_set_1(1.1f, (GenFunction_1)func_80387E00, reinterpret_cast(s32, bgs_D_803907B8[this->unkF4_8]));
                    func_802BAFE4(D_803907B0[this->unkF4_8-1]);
                } else {
                    timedFunc_set_1(0.8f, (GenFunction_1)func_80387D90, (s32) this->marker);
                }
                __spawnQueue_add_2((GenFunction_2)func_80387D18, reinterpret_cast(s32, this->marker), 0x46);
            }
        }
    }//L80388348

    switch(this->state){
    case 1:// L80388370
        this->unk60 += time_getDelta();
        if(0.7 <= this->unk60){
            subaddie_set_state_with_direction(this, 2, 0.0f, 1);
            func_80387C90(this);
            this->unk60 = 0.0f;
            func_80324D54(0.1f, SFX_D0_GRIMLET_SQUEAK, 1.0f, 0x7530, this->position, 0.0f, 1800.0f);
        }
        break;

    case 2:// L80388400
        if(actor_animationIsAt(this, 0.62f)){
            subaddie_set_state_with_direction(this, 3, 0.62f, 1);
        }
        break;

    case 3:// L80388434
        this->unk60 += time_getDelta();
        if( this->unk60 >= 0.13 + 0.7/4 * (5 - this->unkF4_8)){
            subaddie_set_state_with_direction(this, 4, 0.62f, 1);
            func_80387C90(this);
            this->unk60 = 0.0f;
            func_80324D54(0.3f, 0x406, 1.0f, 0x55f0, this->position, 0.0f, 1800.0f);
        }
        break;

    case 4:// L8038850C
        if(actor_animationIsAt(this, 0.0f)){
            subaddie_set_state_with_direction(this, 1, 0.0f, 1);
        }
        break;

    case 5:// L80388538
        func_80328748(this->animctrl, 0.79f, 0.97f);
        if( actor_animationIsAt(this, 0.84f) 
            && !animctrl_isPlayedForwards(this->animctrl)
            && func_802BB270()
        ){
            func_8030E6A4(SFX_C8_CRUNCH, randf2(0.93f, 1.07f), 22000);
        }
        break;

    case 6:// L803885B0
        func_80328748(this->animctrl, 0.79f, 0.97f);

        break;
    }
}

void BGS_func_803885DC(void){
    s32 i;
    for(i = 0; i<5; i++)
        bgs_D_803907B8[i] = 0;
}

Actor *func_8038860C(ActorMarker *this, Gfx** gdl, Mtx ** mptr, Vtx **vtx){
    Actor *thisActor; 
    thisActor = marker_getActor(this);
    func_8033A45C(1, thisActor->unkF4_8);
    return actor_draw(this, gdl, mptr, vtx);
}
