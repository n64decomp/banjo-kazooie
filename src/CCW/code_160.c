#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    ActorMarker *unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
}ActorLocal_CCW_160;

void func_803865F4(Actor *this, s32 next_state);
void func_8038687C(Actor *this);

/* .data */
ActorInfo D_8038EBA0 = { 0x1AD, 0x299, 0x443, 0x0, NULL, func_8038687C, NULL, actor_draw, 0, 0, 0.0f, 0};

/* .code */
void CCW_func_80386550(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;


    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    this->unk124_11 = 2;
    this->alpha_124_19 = 0xFF;
    if (local->unk0 != NULL) {
        actor_collisionOn(marker_getActor(local->unk0));
    }
    func_8025A6EC(COMUSIC_3D_JIGGY_SPAWN, 28000);
}

void func_803865C4(ActorMarker* marker, enum asset_e text_id, s32 arg2) {
    func_803865F4(marker_getActor(marker), 3);
}

void func_803865F4(Actor *this, s32 next_state) {
    ActorLocal_CCW_160 *local;

    local = (ActorLocal_CCW_160 *)&this->local;
    local->unkC = 0.0f;
    if (next_state == 2) {
        if (!func_80320454(0xB5, 1)) {
            func_80311480(0xCE2, 4, NULL, this->marker, func_803865C4, NULL);
        } else {
            func_80311480(0xCE3, 4, NULL, NULL, NULL, NULL);
            func_803865F4(this, 3);
            return;
        }
    }

    if (next_state == 3) {
        local->unkC = 0.1f;
        func_8025A58C(0, 4000);
        func_8025A6EC(COMUSIC_4B_CCW_ZUBBA_FIGHT, 30000);
    }

    if (next_state == 4) {
        if (func_803203FC(2)) {
            item_set(ITEM_6_HOURGLASS, FALSE);
            func_803204E4(3, 0);
            func_803204E4(5, 1);
        } else {
            func_80311480(0xCE4, 4, NULL, NULL, NULL, NULL);
            func_8025A58C(-1, 400);
            comusic_8025AB44(COMUSIC_4B_CCW_ZUBBA_FIGHT, 0, 400);
            func_8025AABC(COMUSIC_4B_CCW_ZUBBA_FIGHT);
            func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
            func_80324E38(0.0f, 3);
            timed_setStaticCameraToNode(2.0f, 4);
            timedFunc_set_1(2.0f, (GenFunction_1)CCW_func_80386550, (s32) this->marker);
            timed_exitStaticCamera(4.0f);
            func_80324E38(4.0f, 0);
        }
    }
    this->state = next_state;
}

void func_803867C8(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    local->unk8++;
    local->unk4--;
    if(local->unk8 == 10){
        func_803865F4(this, 4);
    }
}

void func_80386814(ActorMarker *marker){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;
    local->unk4--;
}

void func_80386840(ActorMarker *marker, s32 *score, s32 *total){
    Actor *this;
    ActorLocal_CCW_160 *local;

    this = marker_getActor(marker);
    local = (ActorLocal_CCW_160 *)&this->local;

    *score = local->unk8;
    *total = 10;
}

void func_8038687C(Actor *this) {
    ActorLocal_CCW_160 *local;
    f32 sp88;
    Actor *other;
    f32 sp78[3];
    f32 sp6C[3];
    s32 pad68;
    f32 sp5C[3];
    s32 phi_s0;
    f32 sp4C[3];
    f32 sp40[3];
    s32 phi_v0;
    f32 tmp;

    sp88 = time_getDelta();
    local = (ActorLocal_CCW_160 *)&this->local;
    if(!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        local->unk0 = 1;
        local->unk4 = 0;
        local->unk8 = 0;
        local->unkC = 0.0f;
        if (func_803203FC(2)) {
            this->position_y -= 300.0f;
        }
        func_803865F4(this, 1);
        return;
    }
    if ((s32)local->unk0 == 1) {
        other = actorArray_findActorFromActorId(0x46);
        if(func_803203FC(2)) {
            local->unk0 = NULL;
            if (other != NULL) {
                actor_collisionOff(other);
                other->position[1] -= 300.0f;
            }
        } else if (other != NULL) {
            local->unk0 = other->marker;
            actor_collisionOff(other);
            if (jiggyscore_isCollected(JIGGY_4C_CCW_ZUBBAS) != 0) {
                marker_despawn(local->unk0);
                marker_despawn(this->marker);
            }
        } else {
            marker_despawn(this->marker);
        }
        return;
    }
    
    if (local->unk0 != NULL) {
        other = marker_getActor(local->unk0);
        viewport_get_position_vec3f(sp78);
        sp6C[0] = this->position[0] - sp78[0];
        sp6C[1] = this->position[1] - sp78[1];
        sp6C[2] = this->position[2] - sp78[2];
        sp6C[1] = 0.0f;
        ml_vec3f_set_length(sp6C, 20.0f);
        other->position[0] = this->position[0] + sp6C[0];
        other->position[1] = this->position[1] + sp6C[1];
        other->position[2] = this->position[2] + sp6C[2];
    }
    if (ml_timer_update(&local->unkC, sp88)) {
        if ((local->unk4 < 3) && ((local->unk8 + local->unk4) < 10)) {
            player_getPosition(sp5C);
            for(phi_s0 = 0; phi_s0 < 20; phi_s0++){
                sp4C[0] = randf2(-500.0f, 500.0f);
                sp4C[1] = -100.0f;
                sp4C[2] = randf2(-500.0f, 900.0f);

                if(ml_distance_vec3f(this->position, sp4C) < 400.0f)
                    continue;
                
                tmp = ml_distance_vec3f(sp5C, sp4C);
                phi_v0 = (phi_s0 < 0xA) ?  500 : 200;
                if(tmp < (f32) phi_v0)
                    continue;

                if(func_8024DC04(sp4C[0], 0.0f, sp4C[2]))
                    break;

            }
            __spawnQueue_add_4((GenFunction_4)func_802C4140, 0x29B, reinterpret_cast(s32, sp4C[0]), reinterpret_cast(s32, sp4C[1]), reinterpret_cast(s32, sp4C[2]));
            local->unk4++;
        }
        local->unkC = randf2(0.5 - ((local->unk8 / 10) * 0.4), 1.0 - ((local->unk8 / 10) * 0.8));
    }
    if (this->state == 1) {
        if (func_803203FC(2) && func_803203FC(3)) {
            item_set(ITEM_6_HOURGLASS, 1);
            item_set(ITEM_0_HOURGLASS_TIMER, 1800 - 1);
            func_803865F4(this, 3);
        } else if ((local->unk0 != NULL) && (map_get() == MAP_5A_CCW_SUMMER_ZUBBA_HIVE)) {
            player_getPosition(sp40);
            if ((ml_distance_vec3f(this->position, sp40) < 300.0f) && (player_getTransformation() == TRANSFORM_1_BANJO)) {
                func_803865F4(this, 2);
            }
        }
    }
    if ((this->state == 3) && func_803203FC(2) && item_empty(ITEM_0_HOURGLASS_TIMER)) {
        item_set(ITEM_6_HOURGLASS, 0);
        func_803204E4(3, 0);
        func_803204E4(5, 0);
    }
}
