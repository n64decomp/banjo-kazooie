#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "core2/modelRender.h"

void func_80335A24(void *, u32, f32, f32);
Actor *chvile_draw(ActorMarker*, Gfx **, Mtx **, Vtx **);
void chvile_update(Actor *);
void func_8038BB40(ActorMarker *);
extern void func_80335A80(void *, f32);
extern bool func_80320C94(f32[3], f32[3], f32, f32[3], s32, u32);

extern bool chvilegame_find_closest_piece(ActorMarker *, f32[3], f32, f32[3]);

typedef struct chmrvile_s{
    u8 unk0;
    // u8  pad1[0x3];
    BKModelBin *unk4; //yumblie_model
    ActorMarker *game_marker; //game_marker
    u8  unkC;
    // u8  padD[0x3];
    f32 unk10; //movement_speed
    f32 unk14; //yumblie_eating_timer
    f32 target_position[3]; //target_position
    f32 unk24;
    f32 unk28[3]; //target_rotation?
} ActorLocal_MrVile;

/* .data */
ActorInfo D_80390A70 = {MARKER_C8_MR_VILE, ACTOR_13A_MR_VILE, ASSET_373_MODEL_MR_VILE, 0x00, NULL,
    chvile_update, NULL, chvile_draw,
    0, 0, 0.0f, 0
};

f32 D_80390A94[7] = {0.0f, 0.8f, 0.9f, 1.0f, 0.9f, 0.95f, 1.0f};

/* .code */
void func_8038B9F0(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3, s32 arg4) {
    f32 sp64[3];
    f32 pad60;
    f32 sp54[3];
    f32 pad50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 var_f0;

    sp44[0] = arg0[0];
    sp44[1] = arg0[1] + arg2;
    sp44[2] = arg0[2];

    sp38[0] = arg1[0];
    sp38[1] = arg1[1] + arg2;
    sp38[2] = arg1[2];

    sp2C[0] = sp38[0];
    sp2C[1] = sp38[1];
    sp2C[2] = sp38[2];
    if (func_80320C94(sp44, sp38, arg3, sp54, 3, arg4)) {
        sp64[0] = sp38[0] - sp2C[0];
        sp64[1] = sp38[1] - sp2C[1];
        sp64[2] = sp38[2] - sp2C[2];
        var_f0 = sp54[0]*sp64[0] + sp54[1]*sp64[1] + sp54[2]*sp64[2];
        if (var_f0 < 1.0f) {
            var_f0 = 1.0f;
        }
        ml_vec3f_set_length(sp54, var_f0);
        arg1[0] = arg1[0] + sp54[0];
        arg1[1] = arg1[1] + sp54[1];
        arg1[2] = arg1[2] + sp54[2];
    }
}

void func_8038BB40(ActorMarker * arg0){
    Actor *this;
    ActorLocal_MrVile *local;

    this = marker_getActor(arg0);
    local = (ActorLocal_MrVile *)&this->local;
    if(func_8038A9E0(local->game_marker) >= 3){
        item_set(ITEM_14_HEALTH, 0);
        func_8028F66C(BS_INTR_F);
    }
    else{
        item_dec(ITEM_14_HEALTH);
        func_8028F590(4, arg0);
    }
}

void BGS_func_8038BBA0(Actor *this, s32 arg1){
    ActorLocal_MrVile *local;
    
    local = (ActorLocal_MrVile *)&this->local;
    local->unk14 = 0.0f;
    if(arg1 == 101){
        local->unk24 = 0.0f;
        local->unk28[0] = local->unk28[1] = local->unk28[2] = 0.0f;
        func_80335924(this->unk148, 0xe1, 0.10000000149f, 1.0f); //0xe1 = croc_idle
    }
    if(arg1 == 102){
        if(local->unk24 < 100.0f){
            local->unk24 = 100.0f;
        };
        func_80335A24(this->unk148, 0xe0, 0.1f, 0.5f); //0xe1 = croc_walk
    }
    if(arg1 == 103){
        func_80335A24(this->unk148, 0x124, 0.1f, 0.5f); //0x124 = croc_munch
        if(this->state == 4){
            timed_playSfx(0.31f, SFX_4C_LIP_SMACK, 0.90f, 25000);
            timedFunc_set_1(0.31f, (GenMethod_1)func_8038BB40, reinterpret_cast(s32, this->marker));
        }
        else{
            timed_playSfx(0.31f, SFX_4C_LIP_SMACK, 0.90f, 25000);
            timed_playSfx(0.81f, SFX_4C_LIP_SMACK, 0.93f, 25000);
            timed_playSfx(1.31f, SFX_4C_LIP_SMACK, 0.91f, 25000);
        }
    }
    if(arg1 == 104){
        local->unk14 = 1.0f;
        timed_playSfx(randf2(1.2f, 1.3f), SFX_97_BLUBBER_BURPS, randf2(0.8f, 1.1f), randi2(25000, 32000));
    }
    local->unkC = arg1; 
}

void func_8038BD84(Actor *this){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    local->unkC = 100;
    local->unk10 = 0.0f;
    local->unk14 = 0.0f;
    local->unk24 = 0.0f;
    local->target_position[0] = 0.0f;
    local->target_position[1] = 0.0f;
    local->target_position[2] = 0.0f;
    local->unk28[0] = 0.0f;
    local->unk28[1] = 0.0f; 
    local->unk28[2] = 0.0f;
    BGS_func_8038BBA0(this, 101);
}

void func_8038BDD4(Actor *this) {
    ActorLocal_MrVile *local;
    f32 start_position[3];
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];
    f32 temp_f0_3;

    local = (ActorLocal_MrVile *)&this->local;
    sp5C = time_getDelta();
    start_position[0] = this->position[0];
    start_position[1] = this->position[1];
    start_position[2] = this->position[2];
    ml_timer_update(&local->unk14, sp5C);
    if ((local->unkC == 102) || (local->unkC == 103) || (local->unkC == 104)) {
        sp44[0] = 0.0f;
        sp44[1] = 0.0f;
        sp44[2] = local->unk24 * sp5C;
        ml_vec3f_yaw_rotate_copy(sp44, sp44, this->yaw);
        this->position[0] = this->position[0] + sp44[0];
        this->position[1] = this->position[1] + sp44[1];
        this->position[2] = this->position[2] + sp44[2];
        this->pitch += local->unk28[0] * sp5C;
        this->yaw   += local->unk28[1] * sp5C;
        this->roll  += local->unk28[2] * sp5C;
        func_80258A4C(this->position, this->yaw - 90.0f, local->target_position, &sp58, &sp54, &sp50);
        if ((sp54 > 0.0f) && (sp58 > 200.0f)) {
            local->unk24 += 100.0f * sp5C;
        }
        if ((sp54 < 0.0f) && (sp58 > 100.0f)) {
            local->unk24 -= 100.0f * sp5C;
        }

        local->unk24 = (local->unk24 < 10.0f)        ? 10.0f
                     : (local->unk10 < local->unk24) ? local->unk10 
                     : local->unk24;
        func_80335A80(this->unk148, (200.0f / local->unk24) * 0.5);
        local->unk28[1] = sp50 * 200.0f;
        temp_f0_3 = func_80309724(this->position);
        if (temp_f0_3 > 125.0f) {
            this->position[1] = 125.0f;
        } else if (temp_f0_3 > 80.0f) {
            this->position[1] = temp_f0_3;
        } else {
            this->position[1] = 0.0f;
        }
    }
    if (this->position[1] > 100.0f) {
        func_8038B9F0(start_position, this->position, 90.0f, 70.0f, 0);
    }
}

void func_8038C0C8(Actor * this, s32 next_state){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    if(next_state == 1)
        BGS_func_8038BBA0(this, 101);

    if(next_state == 2)
        BGS_func_8038BBA0(this, 101);

    if(next_state == 3)
        BGS_func_8038BBA0(this, 102);

    if(next_state == 4)
        BGS_func_8038BBA0(this, 102);

    if(next_state == 5){
        local->target_position[0] = local->target_position[1] = local->target_position[2] = 0.0f;
        BGS_func_8038BBA0(this, 102);
    }

    if(next_state == 6){
        local->target_position[0] = local->target_position[1] = local->target_position[2] = 0.0f;
        local->unk24 = 300.0f;
        BGS_func_8038BBA0(this, 102);
    }

    this->state = next_state; 
}

Actor *chvile_draw(ActorMarker *marker, Gfx **gfx, Mtx** mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_MrVile *local;
    f32 position[3];
    

    this = func_80325888(marker, gfx, mtx, vtx);
    local = (ActorLocal_MrVile *)&this->local;
    if (
        (local->unkC == 104) &&
        (local->unk14 > 0.0f) 
        && (this->marker->unk14_21)
    ) {
        func_8034A174(func_80329934(), 5, position);
        position[1] -= 30.0f;
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        modelRender_draw(gfx, mtx, position, 0, local->unk14, 0, local->unk4);
    }
    return this;
}

f32 *chVile_getPostion(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    return this->position;
}

bool func_8038C2A8(ActorMarker *marker) {
    f32 player_position[3];
    Actor *this;
    ActorLocal_MrVile *local;

    this = marker_getActor(marker);
    local = (ActorLocal_MrVile *)&this->local;
    player_getPosition(player_position);
    if (this->state == 6) {
        return ml_distance_vec3f(this->position, player_position) < 150.0f;
    }
    return local->unk0 == 1;
}


bool BGS_func_8038C338(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    return this->state == 1;
}

void chvile_free(Actor *this){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    assetcache_release(local->unk4);

}

void func_8038C384(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 4);
}

void func_8038C3B0(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 2);
}

void func_8038C3DC(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 3);
}

void func_8038C408(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 5);
}

void BGS_func_8038C434(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 6);
}

void BGS_func_8038C460(ActorMarker *arg0){
    func_8038C0C8(marker_getActor(arg0), 1);
}

void chvile_update(Actor *this) {
    f32 player_position[3];
    f32 sp90;
    f32 temp_a0;
    bool var_v1;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    s32 temp_v0;
    s32 i;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    ActorLocal_MrVile *local;
    f32 random_position[3];

    local = (ActorLocal_MrVile *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->unk30 = chvile_free;
        local->unk0 = 0;
        local->unk4 = assetcache_get(0x3F6);
        local->game_marker = NULL;
        func_8038BD84(this);
        func_8038C0C8(this, 1);
        return;
    }
    if (local->game_marker == NULL) {
        local->game_marker = actorArray_findClosestActorFromActorId(this->position, 0x138, -1, &sp90)->marker;
    }
    player_getPosition(player_position);
    sp90 = ml_distance_vec3f(this->position, player_position);
    if (sp90 <= 300.0f) {
        local->unk0 =  (local->unk0 == 0) ? 1 : 2;
    } else if (sp90 > 300.0f) {
        local->unk0 = 0U;
    }
    if (this->state == 2) {
        func_80258A4C(this->position, this->yaw - 90.0f, player_position, &sp84, &sp80, &sp7C);
        if (((sp84 > 50.0f) && (0.05 < sp7C)) || (sp7C < -0.05)) {
            this->yaw += sp7C * 20.0f;
        } else {
            func_8038C0C8(this, 1);
        }
    }
    if (this->state == 3) {
        var_v1 = chvilegame_find_closest_piece(local->game_marker, this->position, this->yaw, local->target_position) && mapSpecificFlags_get(6);
        if (!var_v1) {
            local->target_position[0] = 0.0f;
            local->target_position[1] = 0.0f;
            local->target_position[2] = 0.0f;
        }
        if (local->game_marker != NULL) {
            temp_v0 = chvilegame_get_score_difference(local->game_marker);
            if (temp_v0 >= 2) {
                local->unk10 = 200.0f;
            } else if (temp_v0 >= 0) {
                local->unk10 = 310.0f;
            } else if (temp_v0 >= -2) {
                local->unk10 = 350.0f;
            } else {
                local->unk10 = 450.0f;
            }
            local->unk10 *= D_80390A94[func_8038A9E0(local->game_marker)];
        }
        if (func_8038A9E0(local->game_marker) < 7) {
            func_80258A4C(this->position, this->yaw - 90.0f, local->target_position, &sp70, &sp6C, &sp68);
            if (local->unkC == 102) {
                if ((-0.8 < sp68) && (sp68 < 0.8) && (sp70 <= 150.0f) && var_v1) {
                    BGS_func_8038BBA0(this, 103);
                }
            }
            if (local->unkC == 103) {
                if (sp70 <= 50.0f) {
                    if (chvilegame_cpu_consume_piece(local->game_marker, local->target_position)) {
                        BGS_func_8038BBA0(this, 104);
                    } else {
                        BGS_func_8038BBA0(this, 102);
                    }
                } else if (func_80335794(this->unk148) >= 3) {
                    BGS_func_8038BBA0(this, 102);
                }
            }
            if ((local->unkC == 104) && (func_80335794(this->unk148) >= 3)) {
                BGS_func_8038BBA0(this, 102);
            }
        }
    }
    if (this->state == 4) {
        player_getPosition(local->target_position);
        local->unk10 = 500.0f;
        if ((local->unkC == 102) && (ml_distance_vec3f(this->position, local->target_position) < 200.0f)) {
            BGS_func_8038BBA0(this, 103);
        }
        if ((local->unkC == 103) && (func_80335794(this->unk148) >= 2)) {
            func_8038C0C8(this, 1);
        }
    }
    if (this->state == 5) {
        local->unk10 = 200.0f;
        if (ml_distance_vec3f(this->position, local->target_position) < 100.0f) {
            local->target_position[0] = randf2(-500.0f, 500.0f);
            local->target_position[1] = 0.0f;
            local->target_position[2] = randf2(-500.0f, 500.0f);
        }
    }
    if ((this->state == 6)){
        local->unk10 = 400.0f;
        if((ml_distance_vec3f(this->position, local->target_position) < 100.0f) || (ml_distance_vec3f(player_position, local->target_position) < 300.0f)) {
            for(i = 0; i < 10; i++){
                random_position[0] = randf2(-500.0f, 500.0f);
                random_position[1] = 0.0f;
                random_position[2] = randf2(-500.0f, 500.0f);
                if ((i == 0) || (ml_distance_vec3f(player_position, random_position) > ml_distance_vec3f(player_position, local->target_position))) {
                    local->target_position[0] = random_position[0];
                    local->target_position[1] = random_position[1];
                    local->target_position[2] = random_position[2];
                }
            };
        }
    }
    func_8038BDD4(this);
    if (this->state != 4) {
        func_8028E668(this->position, 100.0f, -50.0f, 120.0f);
    }
}
