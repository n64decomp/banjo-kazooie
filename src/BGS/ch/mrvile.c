#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void func_80335A24(void *, u32, f32, f32);
void set_model_render_mode(u32);
Actor *chvile_draw(ActorMarker*, Gfx **, Mtx **, Vtx **);
void chvile_update(Actor *);
void func_8038BB40(ActorMarker *);
extern void func_80335A80(void *, f32);
extern bool func_80320C94(f32[3], f32[3], f32, f32[3], s32, u32);

extern bool func_8038AA2C(ActorMarker *, f32[3], f32, f32[3]);


typedef struct chmrvile_s{
    u8 unk0;
    // u8  pad1[0x3];
    BKModelBin *unk4; //yumblie_model
    ActorMarker *unk8; //game_marker
    u8  unkC;
    u8  padD[0x3];
    f32 unk10; //movement_speed
    f32 unk14; //yumblie_eating_timer
    f32 unk18[3]; //target_position
    f32 unk24;
    f32 unk28[3]; //target_rotation?
} ActorLocal_MrVile;

/* .data */
ActorInfo D_80390A70 = {0xC8, 0x13A, 0x373, 0x00, NULL,
    chvile_update, NULL, chvile_draw,
    {0,0}, 0, 0.0f, {0,0,0,0}
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
    if(func_8038A9E0(local->unk8) >= 3){
        item_set(ITEM_14_HEALTH, 0);
        func_8028F66C(0xF);
    }
    else{
        item_dec(ITEM_14_HEALTH);
        func_8028F590(4, arg0);
    }
}

void func_8038BBA0(Actor *this, s32 arg1){
    ActorLocal_MrVile *local;
    
    local = (ActorLocal_MrVile *)&this->local;
    local->unk14 = 0.0f;
    if(arg1 == 0x65){
        local->unk24 = 0.0f;
        local->unk28[0] = local->unk28[1] = local->unk28[2] = 0.0f;
        func_80335924(this->unk148, 0xe1, 0.10000000149f, 1.0f); //0xe1 = croc_idle
    }
    if(arg1 == 0x66){
        if(local->unk24 < 100.0f){
            local->unk24 = 100.0f;
        };
        func_80335A24(this->unk148, 0xe0, 0.1f, 0.5f); //0xe1 = croc_walk
    }
    if(arg1 == 0x67){
        func_80335A24(this->unk148, 0x124, 0.1f, 0.5f); //0x124 = croc_munch
        if(this->state == 4){
            timed_playSfx(0.31f, 0x4C, 0.90f, 0x61A8);
            timedFunc_set_1(0.31f, func_8038BB40, this->marker);
        }
        else{
            timed_playSfx(0.31f, 0x4C, 0.90f, 0x61A8);
            timed_playSfx(0.81f, 0x4C, 0.93f, 0x61A8);
            timed_playSfx(1.31f, 0x4C, 0.91f, 0x61A8);
        }
    }
    if(arg1 == 0x68){
        local->unk14 = 1.0f;
        timed_playSfx(randf2(1.2f, 1.3f), SFX_97_BLUBBER_BURPS, randf2(0.8f, 1.1f), randi2(25000, 32000));
    }
    local->unkC = arg1; 
}

void func_8038BD84(Actor *this){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    local->unkC = 0x64;
    local->unk10 = 0.0f;
    local->unk14 = 0.0f;
    local->unk24 = 0.0f;
    local->unk18[0] = 0.0f;
    local->unk18[1] = 0.0f;
    local->unk18[2] = 0.0f;
    local->unk28[0] = 0.0f;
    local->unk28[1] = 0.0f; 
    local->unk28[2] = 0.0f;
    func_8038BBA0(this, 0x65);
}

void func_8038BDD4(Actor *this) {
    ActorLocal_MrVile *local;
    f32 sp60[3];
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp44[3];
    f32 temp_f0_3;

    local = (ActorLocal_MrVile *)&this->local;
    sp5C = time_getDelta();
    sp60[0] = this->position[0];
    sp60[1] = this->position[1];
    sp60[2] = this->position[2];
    func_8025773C(&local->unk14, sp5C);
    if ((local->unkC == 0x66) || (local->unkC == 0x67) || (local->unkC == 0x68)) {
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
        func_80258A4C(this->position, this->yaw - 90.0f, local->unk18, &sp58, &sp54, &sp50);
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
        func_8038B9F0(&sp60, this->position, 90.0f, 70.0f, 0);
    }
}

void func_8038C0C8(Actor * this, u32 arg1){
    ActorLocal_MrVile *local;

    local = (ActorLocal_MrVile *)&this->local;
    if(arg1 == 1)
        func_8038BBA0(this, 0x65);

    if(arg1 == 2)
        func_8038BBA0(this, 0x65);

    if(arg1 == 3)
        func_8038BBA0(this, 0x66);

    if(arg1 == 4)
        func_8038BBA0(this, 0x66);

    if(arg1 == 5){
        local->unk18[0] = local->unk18[1] = local->unk18[2] = 0.0f;
        func_8038BBA0(this, 0x66);
    }

    if(arg1 == 6){
        local->unk18[0] = local->unk18[1] = local->unk18[2] = 0.0f;
        local->unk24 = 300.0f;
        func_8038BBA0(this, 0x66);
    }

    this->state = arg1; 
}

Actor *chvile_draw(ActorMarker *marker, Gfx **gfx, Mtx** mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_MrVile *local;
    f32 sp34[3];
    

    this = func_80325888(marker, gfx, mtx, vtx);
    local = (ActorLocal_MrVile *)&this->local;
    if (
        (local->unkC == 0x68) &&
        (local->unk14 > 0.0f) 
        && (this->marker->unk14_21)
    ) {
        func_8034A174(func_80329934(), 5, &sp34);
        sp34[1] -= 30.0f;
        set_model_render_mode(1);
        func_803391A4(gfx, mtx, &sp34, 0, local->unk14, 0, local->unk4);
    }
    return this;
}

//chvile_get_position
f32 *func_8038C284(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    return this->position;
}

bool func_8038C2A8(ActorMarker *marker) {
    f32 sp24[3];
    Actor *this;
    ActorLocal_MrVile *local;

    this = marker_getActor(marker);
    local = (ActorLocal_MrVile *)&this->local;
    player_getPosition(&sp24);
    if (this->state == 6) {
        return func_80256064(this->position, &sp24) < 150.0f;
    }
    return local->unk0 == 1;
}


bool func_8038C338(ActorMarker *marker){
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

void func_8038C434(ActorMarker *marker){
    Actor *this;

    this = marker_getActor(marker);
    func_8038C0C8(this, 6);
}

void func_8038C460(ActorMarker *arg0){
    func_8038C0C8(marker_getActor(arg0), 1);
}

void chvile_update(Actor *this) {
    ActorLocal_MrVile *local;
    bool var_v1;
    f32 sp94;
    f32 sp90;
    f32 temp_a0;
    f32 temp_f0;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    s32 temp_v0;
    s32 i;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp50;
    f32 sp58[3];

    local = (ActorLocal_MrVile *)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->unk30 = chvile_free;
        local->unk0 = 0;
        local->unk4 = assetcache_get(0x3F6);
        local->unk8 = NULL;
        func_8038BD84(this);
        func_8038C0C8(this, 1);
        return;
    }
    if (local->unk8 == 0) {
        local->unk8 = func_80326D68(this->position, 0x138, -1, &sp90)->marker;
    }
    player_getPosition(&sp94);
    sp90 = func_80256064(this->position, &sp94);
    if (sp90 <= 300.0f) {
        local->unk0 =  (local->unk0 == 0) ? 1 : 2;
    } else if (sp90 > 300.0f) {
        local->unk0 = 0U;
    }
    if (this->state == 2) {
        func_80258A4C(this->position, this->yaw - 90.0f, &sp94, &sp84, &sp80, &sp7C);
        if (((sp84 > 50.0f) && (0.05 < sp7C)) || (sp7C < -0.05)) {
            this->yaw += sp7C * 20.0f;
        } else {
            func_8038C0C8(this, 1);
        }
    }
    if (this->state == 3) {
        var_v1 = func_8038AA2C(local->unk8, this->position, this->yaw, local->unk18) && mapSpecificFlags_get(6);
        if (!var_v1) {
            local->unk18[0] = 0.0f;
            local->unk18[1] = 0.0f;
            local->unk18[2] = 0.0f;
        }
        if (local->unk8 != NULL) {
            temp_v0 = func_8038AA04(local->unk8);
            if (temp_v0 >= 2) {
                local->unk10 = 200.0f;
            } else if (temp_v0 >= 0) {
                local->unk10 = 310.0f;
            } else if (temp_v0 >= -2) {
                local->unk10 = 350.0f;
            } else {
                local->unk10 = 450.0f;
            }
            local->unk10 *= D_80390A94[func_8038A9E0(local->unk8)];
        }
        if (func_8038A9E0(local->unk8) < 7) {
            func_80258A4C(this->position, this->yaw - 90.0f, local->unk18, &sp70, &sp6C, &sp68);
            if (local->unkC == 0x66) {
                if ((-0.8 < sp68) && (sp68 < 0.8) && (sp70 <= 150.0f) && var_v1) {
                    func_8038BBA0(this, 0x67);
                }
            }
            if (local->unkC == 0x67) {
                if (sp70 <= 50.0f) {
                    if (func_8038A86C(local->unk8)) {
                        func_8038BBA0(this, 0x68);
                    } else {
                        func_8038BBA0(this, 0x66);
                    }
                } else if (func_80335794(this->unk148, local->unk18) >= 3) {
                    func_8038BBA0(this, 0x66);
                }
            }
            if ((local->unkC == 0x68) && (func_80335794(this->unk148) >= 3)) {
                func_8038BBA0(this, 0x66);
            }
        }
    }
    if (this->state == 4) {
        player_getPosition(local->unk18);
        local->unk10 = 500.0f;
        if ((local->unkC == 0x66) && (func_80256064(this->position, local->unk18) < 200.0f)) {
            func_8038BBA0(this, 0x67);
        }
        if ((local->unkC == 0x67) && (func_80335794(this->unk148) >= 2)) {
            func_8038C0C8(this, 1);
        }
    }
    if (this->state == 5) {
        local->unk10 = 200.0f;
        if (func_80256064(this->position, local->unk18) < 100.0f) {
            local->unk18[0] = randf2(-500.0f, 500.0f);
            local->unk18[1] = 0.0f;
            local->unk18[2] = randf2(-500.0f, 500.0f);
        }
    }
    if ((this->state == 6)){
        local->unk10 = 400.0f;
        if((func_80256064(this->position, local->unk18) < 100.0f) || (func_80256064(&sp94, local->unk18) < 300.0f)) {
            for(i = 0; i < 10; i++){
                sp58[0] = randf2(-500.0f, 500.0f);
                sp58[1] = 0.0f;
                sp58[2] = randf2(-500.0f, 500.0f);
                if ((i == 0) || (func_80256064(&sp94, &sp58) > func_80256064(&sp94, local->unk18))) {
                    local->unk18[0] = sp58[0];
                    local->unk18[1] = sp58[1];
                    local->unk18[2] = sp58[2];
                }
            };
        }
    }
    func_8038BDD4(this);
    if (this->state != 4) {
        func_8028E668(this->position, 100.0f, -50.0f, 120.0f);
    }
}
