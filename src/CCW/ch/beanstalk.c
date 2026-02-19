#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
    s16 unk8; // enum file_progress_e
    s16 unkA;
}Struct_CCW_1B20_0;

typedef struct{
    Struct_CCW_1B20_0 *unk0;
}ActorLocal_CCW_1B20;

void func_80387F64(Actor *this, s32 next_state);
Actor *CCW_func_803882F4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80388478(Actor *this);

/* .data */
Struct_CCW_1B20_0 D_8038EC40[4] ={
    {0x173, 4, 0, 0x173, 0x181, 0xE3, 0},
    {0x181, 1, 1, 0x174, 0x182, 0xE4, 0},
    {0x182, 1, 1, 0x175, 0x183, 0xE5, 1},
    {0x183, 1, 1, 0x000, 0x000, 0x00, 0}
};

ActorInfo D_8038EC70 = {
    MARKER_1B0_CCW_BEANSTALK, ACTOR_29D_CCW_BEANSTALK, ASSET_447_MODEL_CCW_BEANSTALK,
    0x0, NULL,
    func_80388478, NULL, CCW_func_803882F4,
    0, 0, 1.0f, 0
};

f32 D_8038EC94[3] = {200.0f,  2120.0f, -5570.0f};

/* .code */
void func_80387F10() {
    jiggy_spawn(JIGGY_4D_CCW_FLOWER, D_8038EC94);
}

void func_80387F38(ActorMarker* marker, s32 arg1) {
    func_80387F64(marker_getActor(marker), arg1);
}

void func_80387F64(Actor *this, s32 next_state){
    ActorLocal_CCW_1B20 *local;
    f32 phi_f22;

    local = (ActorLocal_CCW_1B20 *)&this->local;

    if (next_state == 1) {
        this->marker->propPtr->unk8_3 = local->unk0->unk3;
        skeletalAnim_set(this->unk148, local->unk0->unk0, 0.0f, 5.0f);
        skeletalAnim_setBehavior(this->unk148, local->unk0->unk2);
    }
    if (next_state == 2) {
        if (gsworld_get_map() == MAP_43_CCW_SPRING) {
            coMusicPlayer_playMusic(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
        }
        fileProgressFlag_set(local->unk0->unk8, TRUE);
        skeletalAnim_set(this->unk148, local->unk0->unk4, 0.0f, 6.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_2_ONCE);
        if (gsworld_get_map() == MAP_43_CCW_SPRING) {
            func_80324E38(0.0f, 3);
        }
        timed_setStaticCameraToNode(0.0f, 0);
        for( phi_f22 = 0.0f; phi_f22 <= 1.0f; phi_f22 += 0.1) {
                timed_playSfx(phi_f22 * 5.7, 0x2C, phi_f22 * 0.3 + 0.7, (s32) (32000.0f - phi_f22 * 5000.0f));
        }
        if (local->unk0->unkA != 0) {
            timed_setStaticCameraToNode(6.0f, 1);
            timedFunc_set_0(6.1f, func_80387F10);
            timedFunc_set_2(8.0f, (GenFunction_2)func_80387F38, (s32) this->marker, 3);
        } else {
            if (gsworld_get_map() == MAP_43_CCW_SPRING) {
                timed_exitStaticCamera(7.0f);
                func_80324E38(7.0f, 0);
            }
            timedFunc_set_2(7.0f, (GenFunction_2)func_80387F38, (s32) this->marker, 3);
        }
    }

    if (next_state == 3) {
        this->marker->propPtr->unk8_3 = TRUE;
        skeletalAnim_set(this->unk148, local->unk0->unk6, 0.1f, 5.0f);
        skeletalAnim_setBehavior(this->unk148, SKELETAL_ANIM_1_LOOP);
    }
    this->state = next_state;
}

bool func_80388260(ActorMarker *marker, s32 arg1){
    return marker->unk40_31 != 1;
}

void CCW_func_80388278(ActorMarker *marker, ActorMarker *other_marker) {
    coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
}

void func_803882A4(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    
    if (gsworld_get_map() == MAP_43_CCW_SPRING && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

Actor *CCW_func_803882F4(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    s32 sp18;

    this = marker_getActor(marker);
    if ((this->state == 1) && !fileProgressFlag_get(FILEPROG_E3_CCW_FLOWER_SPRING)) {
        return func_80325340(marker, gfx, mtx, vtx);
    }

    if ((skeletalAnim_getAnimId(this->unk148) == 0x175) && (0.49 <= skeletalAnim_getProgress(this->unk148))) {
        sp18 = 1;
    } else {
        sp18 = 0;
    }
    sp18 = (skeletalAnim_getAnimId(this->unk148) == 0x183)? 1  : sp18;
    func_8033A45C(3, sp18);
    func_8033A45C(4, sp18);
    return actor_draw(marker, gfx, mtx, vtx);
}

void func_803883F4() {
    Actor* actor = actorArray_findActorFromActorId(0x29D);
    if (actor && actor->state == 1) {
        func_80387F64(actor, 2);
    }
}

bool func_80388438() {
    Actor* actor = actorArray_findActorFromActorId(0x29D);
    if (actor && actor->state == 2) {
        return TRUE;
    }
    return FALSE;
}

void func_80388478(Actor *this) {
    ActorLocal_CCW_1B20 *local;

    local = (ActorLocal_CCW_1B20 *)&this->local;
    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        func_803300C0(this->marker, func_80388260);
        marker_setCollisionScripts(this->marker, NULL, CCW_func_80388278, func_803882A4);
        actor_collisionOn(this);
        if (!jiggyscore_isSpawned(JIGGY_4D_CCW_FLOWER)) {
            fileProgressFlag_set(FILEPROG_E5_CCW_FLOWER_AUTUMN, FALSE);
        }
        
        for(local->unk0 = &D_8038EC40[0]; local->unk0 < D_8038EC40 + 3; local->unk0++){
            if(!fileProgressFlag_get(local->unk0->unk8)){
                break;
            }
        }

        if (!fileProgressFlag_get(FILEPROG_E3_CCW_FLOWER_SPRING) && (gsworld_get_map() != MAP_43_CCW_SPRING)) {
            marker_despawn(this->marker);
        }
        else{
            func_80387F64(this, 1);
        }
    }
}
