#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32 [3], f32, f32, f32);
extern void func_8028F9DC(s32);
extern void func_803272D0(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *));

void chLeaky_update(Actor *this);

/* .data */
ActorAnimationInfo D_8038C700[] = {
    {0x000, 0.0f},
    {0x239, 2.5f},
    {0x239, 2.5f}
};

ActorInfo D_8038C718 = { 
    MARKER_33_LEAKY,  ACTOR_1E_LEAKY, ASSET_51A_MODEL_LEAKY,
    0x1, D_8038C700,
    chLeaky_update, func_80326224, actor_draw,
    0, 0, 0.0f, 0
};

/* .code */
bool TTC_func_80388F70(Actor *this){
    return this->modelCacheIndex == ACTOR_56_SHRAPNEL;
}

void func_80388F88(void){
    static f32 D_8038C73C[3] = {2500.0f, 250.0f, 4600.0f};
    func_803272D0(D_8038C73C, 2000.0f, 2, TTC_func_80388F70);
}

void chLeaky_update(Actor *this) {
    void *temp_v0_2;

    func_8028E668(this->position, 100.0f, -20.0f, 100.0f);
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        if (levelSpecificFlags_get(5) != 0) {
            levelSpecificFlags_set(5, FALSE);
            timedFunc_set_1(0.5f, (GenFunction_1)func_8025A70C, COMUSIC_2D_PUZZLE_SOLVED_FANFARE);
        }
        if (levelSpecificFlags_get(2) != 0) {
            temp_v0_2 = func_8034C5AC(300);
            if (temp_v0_2 != 0) {
                func_8034E71C(temp_v0_2, -600, 0.0f);
            }
            this->state = 2;
        } else {
            this->state = 1;
        }
    }
    if( this->state == 1 
        && !this->is_first_encounter
        && func_80329530(this, 250) && !func_80329530(this, 160)
        && !func_8028ECAC() 
        && func_80311480(0xA1A, 0, NULL, NULL, NULL, NULL)
    ){
        this->is_first_encounter = TRUE;
    }
    if (func_803114B0() == 0) {
        if (actor_animationIsAt(this, 0.83f)) {
            func_8030E878(0x109, randf2(0.775f, 0.825f), 22000, this->position, 400.0f, 1000.0f);
            return;
        }
        if (actor_animationIsAt(this, 0.01f)) {
            func_8030E878(0x109, randf2(1.025f, 1.075f), 18000, this->position, 400.0f, 1000.0f);
            return;
        }
        if( actor_animationIsAt(this, 0.15f) 
            || actor_animationIsAt(this, 0.34f)
            || actor_animationIsAt(this, 0.53f)
            || actor_animationIsAt(this, 0.66f)
        ){
            func_8030E878(0x109, randf2(1.225f, 1.275f), 14000, this->position, 400.0f, 1000.0f);
        }
    }
}

void __chLeaky_startCutscene(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    Struct73s *temp_v0;
    subaddie_set_state(this, 2);
    temp_v0 = func_8034C5AC(300);
    if(temp_v0 != NULL){
        func_8034E7B8(temp_v0, -600, 4.0f, 2, 10.0f);
    }

    func_80324E38(0.0f, 3);
    timed_setStaticCameraToNode(0.5f, 7);
    timedFunc_set_0(1.0f, func_80388F88);
    func_80324E38(2.5f, 0);
    timedFunc_set_1(2.5f, func_8028F9DC, 2);
    timedFunc_set_3(2.5f, (GenFunction_3)func_802E4078, MAP_A_TTC_SANDCASTLE, 0, 0);
    func_803228D8();
}

bool chLeaky_eggCollision(ActorMarker *marker){
    Actor *this = marker_getActor(marker);
    
    if(levelSpecificFlags_get(2)) 
        return TRUE;

    func_8025A70C(COMUSIC_2B_DING_B);
    this->unk38_31++;
    if(this->unk38_31 < 2)
        return TRUE;

    levelSpecificFlags_set(2, TRUE);
    levelSpecificFlags_set(5, TRUE);
    func_80311480(ASSET_A28_TEXT_LEAKY_DONE, 0x2a, this->position, this->marker, __chLeaky_startCutscene, NULL);
    return TRUE;
}
