#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    s16 map_id;
    s16 unk2;
    s16 unk4;
    s16 unk6;
}Struct_CCW_2270_0;

typedef struct{
    Struct_CCW_2270_0 *unk0;
    Struct80s *unk4;
    BKModelBin *spit_model;
}ActorLocal_chGobiCCW;

void CCW_func_8038868C(Actor *this, s32 next_state);
Actor *chGobiCCW_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chGobiCCW_update(Actor *this);

/* .data */
Struct_CCW_2270_0 D_8038ECD0[] = {
    {MAP_44_CCW_SUMMER, 0xCDE, 0xCDF, 0x000},
    {MAP_45_CCW_AUTUMN, 0x000, 0x000, 0xCE0},
    0
};

ActorInfo D_8038ECE8 = { 
    MARKER_1B1_CCW_GOBI, ACTOR_29E_CCW_GOBI, ASSET_3E0_MODEL_GOBI,
    0x0, NULL,
    chGobiCCW_update, chGobiCCW_update, chGobiCCW_draw,
    0, 0, 1.0f, 0
};

/* .code */
void CCW_func_80388660(ActorMarker* marker, s32 arg1) {
    CCW_func_8038868C(marker_getActor(marker), arg1);
}

void CCW_func_8038868C(Actor *this, s32 next_state) {
    ActorLocal_chGobiCCW *local;

    local = (ActorLocal_chGobiCCW*)&this->local;

    if (next_state == 1) {
        func_80335924(this->unk148, ASSET_F4_ANIM_GOBI_IDLE, 0.5f, 12.0f);
    }
    if (next_state == 2) {
        if (local->unk0->unk4 != 0) {
            func_80311480(local->unk0->unk4, 4, NULL, NULL, NULL, NULL);
        }
        func_80335924(this->unk148, ASSET_FC_ANIM_GOBI_SPITTING, 0.2f, 3.0f);
        func_80335A8C(this->unk148, 2);
        func_80335924(local->unk4, ASSET_100_ANIM_GOBI_SPIT, 0.0f, 3.0f);
        func_80335A8C(local->unk4, 2);
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.0f, (map_get() == MAP_44_CCW_SUMMER) ? 1 : 2);
        timed_playSfx(0.05f, SFX_84_GOBI_CRYING, 1.1f, 32000);
        timed_playSfx(0.8f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(1.4f, SFX_4B_GULPING, 0.8f, 28000);
        timed_playSfx(2.0f, SFX_4B_GULPING, 0.8f, 28000);
        timedFunc_set_2(3.2f, (GenMethod_2) CCW_func_80388660, (s32) this->marker, 3);
    }
    if (next_state == 3) {
        func_803883F4();
    }
    if (next_state == 4) {
        func_80335924(this->unk148, ASSET_176_ANIM_GOBI_YAWN, 0.5f, 4.0f);
        func_80335A8C(this->unk148, 2);
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
    }
    if (next_state == 5) {
        if (local->unk0->unk6 != 0) {
            func_80311480((s32) local->unk0->unk6, 4, NULL, NULL, NULL, NULL);
        }
        func_80335924(this->unk148, ASSET_FD_ANIM_GOBI2_GETTING_UP, 0.23f, 0.5f);
        timed_setCameraToNode(0.0f, 3);
    }
    if (next_state == 6) {
        func_80335924(this->unk148, ASSET_F8_ANIM_GOBI_RUNNING, 0.1f, 0.71f);
        func_80335A8C(this->unk148, 1);
    }
    if (next_state == 7) {
        func_80324E88(0.0f);
        func_80324E38(0.0f, 0);
        marker_despawn(this->marker);
    }
    
    this->state = next_state;
}

void func_8038894C(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        actor_collisionOff(actor);
        timedFunc_set_2(0.5f, (GenMethod_2)CCW_func_80388660, (s32)actor->marker, 2);
    }
}

Actor *chGobiCCW_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    ActorLocal_chGobiCCW *local;
    f32 sp2C[3];

    this = marker_getActor(marker);
    local = (ActorLocal_chGobiCCW*)&this->local;

    if (this->state == 2) {
        sp2C[0] = this->pitch;
        sp2C[1] = this->yaw;
        sp2C[2] = this->roll;

        func_8033A238(func_803356A0(local->unk4, local));
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
        modelRender_draw(gfx, mtx, this->position, sp2C, 1.0f, NULL, local->spit_model);
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

void chGobiCCW_free(Actor *this){
    ActorLocal_chGobiCCW *local = (ActorLocal_chGobiCCW*)&this->local;

    func_80335874(local->unk4);
    assetcache_release(local->spit_model);
}

void chGobiCCW_update(Actor *this) {
    ActorLocal_chGobiCCW *local;
    f32 sp48[3];
    f32 sp44;
    f32 sp40;

    local = (ActorLocal_chGobiCCW*)&this->local;
    if (!this->unk16C_4) {
        this->unk16C_4 = TRUE;
        this->marker->propPtr->unk8_3 = TRUE;
        this->marker->unk30 = chGobiCCW_free;
        this->unk138_24 = FALSE;
        local->unk4 = func_803358B4();
        local->spit_model = assetcache_get(ASSET_3F3_MODEL_GOBI_SPIT);
        marker_setCollisionScripts(this->marker, 0, func_8038894C, 0);
        if(!jiggyscore_isSpawned(JIGGY_4D_CCW_FLOWER)) {
            func_80320004(0xE5, 0);
        }
        local->unk0 = &D_8038ECD0[0];
        while((local->unk0->map_id != 0) && (map_get() != local->unk0->map_id)) {
            local->unk0++;
        }

        if( (map_get() == MAP_44_CCW_SUMMER) && func_8031FF1C(0xE3) && !func_8031FF1C(0xE4)) {
            CCW_func_8038868C(this, 1);
        } else if( (map_get() == MAP_45_CCW_AUTUMN) && func_8031FF1C(0xE4) && !func_8031FF1C(0xE5) ) {
            CCW_func_8038868C(this, 1);
        } else{
            marker_despawn(this->marker);
        }
        return;
    }
    if(this->state == 1){
        if (!this->unk138_24) {
            player_getPosition(sp48);
            if (ml_distance_vec3f(this->position, sp48) < 600.0f) {
                if (local->unk0->unk2 != 0) {
                    func_80311480((s32) local->unk0->unk2, 4, NULL, NULL, NULL, NULL);
                }
                this->unk138_24 = TRUE;
            }
        }
    }

    if (this->state == 2) {
        func_80335A94(local->unk4, time_getDelta(), 1);
    }

    if(this->state == 3){
        if (!func_80388438()) {
            if (map_get() == MAP_44_CCW_SUMMER) {
                CCW_func_8038868C(this, 4);
            } else {
                CCW_func_8038868C(this, 5);
            }
        }
    }

    if (this->state == 4) {
        if ((func_8033567C(this->unk148) == ASSET_176_ANIM_GOBI_YAWN) && (func_80335794(this->unk148) > 0)) {
            func_80335924(this->unk148, ASSET_177_ANIM_GOBI_SLEEP, 0.1f, 4.0f);
            func_80335A8C(this->unk148, 1);
        }
        if (func_8033567C(this->unk148) == ASSET_177_ANIM_GOBI_SLEEP) {
            func_8033568C(this->unk148, &sp44, &sp40);
            if ((sp44 < 0.1) && (0.1 <= (f64) sp40)) {
                FUNC_8030E8B4(SFX_5E_BANJO_PHEWWW, 0.8f, 15000, this->position, 500, 1500);
            }
            if ((sp44 < 0.8) && (0.8 <= (f64) sp40)) {
                FUNC_8030E8B4(SFX_5D_BANJO_RAAOWW, 0.8f, 15000, this->position, 500, 1500);

            }
        }
    }

    if (this->state == 5){
        if(func_80335794(this->unk148) > 0) {
            CCW_func_8038868C(this, 6);
        }
    }

    if (this->state == 6) {
        func_80326224(this);
        if (0.99 < (f64) this->unk48) {
            CCW_func_8038868C(this, 7);
        }
    }
}

