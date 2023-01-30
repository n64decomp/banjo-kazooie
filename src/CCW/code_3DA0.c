#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorMarker *func_8028E86C(void);
extern void func_8028F7D4(f32, f32);

typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18[3];
    f32 unk24;
} ActorLocal_Caterpillar;

void chcaterpillar_update(Actor *this);
Actor*  chcaterpillar_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chCaterpillar = { 
    MARKER_1B5_CATERPILLAR, ACTOR_2A2_CATERPILLAR, ASSET_485_MODEL_CATERPILLAR, 
    0x0, NULL, 
    chcaterpillar_update, NULL, chcaterpillar_draw, 
    0, 0, 1.0f, 0
};

/* .code */
f32 func_8038A190(Actor *this, f32 *arg1) {
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_80309724(arg1);
    temp_f2 = this->position[1];
    if (((temp_f2 + 50.0f) < temp_f0) || (temp_f0 < (temp_f2 - 50.0f))) {
        return temp_f2;
    }
    return temp_f0;
}

void chcaterpillar_setState(Actor *this, s32 next_state) {
    ActorLocal_Caterpillar *local = (ActorLocal_Caterpillar *)&this->local;

    if (next_state == 1) {
        func_80335924(this->unk148, 0x18D, 0.0f, randf2(1.9f, 2.1f));
    }
    if (next_state == 2) {
        func_8028F7D4(-25.0f, 90.0f);
        func_80335924(this->unk148, 0x18E, 0.2f, 2.0f);
    }
    if (next_state == 3) {
        func_80335924(this->unk148, 0x18E, 0.2f, 2.0f);
        local->unkC[0] = this->position[0];
        local->unkC[1] = this->position[1];
        local->unkC[2] = this->position[2];
        local->unk24 = 0.0f;
    }
    if (next_state == 4) {
        func_8025A6EC(COMUSIC_2B_DING_B, 28000);
        marker_despawn(this->marker);
    }
    if (next_state == 5) {
        actor_collisionOff(this);
    }
    this->state = next_state;
}

Actor*  chcaterpillar_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->state == 5){
        return func_80325340(marker, gfx, mtx, vtx);
    }
    return func_80325888(marker, gfx, mtx, vtx);
}

void chcaterpillar_update(Actor *this){
    bool sp8C;
    ActorLocal_Caterpillar *local = (ActorLocal_Caterpillar *)&this->local;
    f32  sp84;
    enum map_e map_id;
    f32 sp74[3];
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp54[3];
    int i;

    sp8C = func_8028E86C() == this->marker;
    sp84 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        local->unk0[0] = this->position[0];
        local->unk0[1] = this->position[1];
        local->unk0[2] = this->position[2];
        if(sp8C){
            chcaterpillar_setState(this, 2);
        }
        else{//L8038A408
            map_id = map_get();
            if ( !func_8031FF1C(BKPROG_E6_SPRING_EYRIE_HATCHED)
                 || ( map_id == MAP_45_CCW_AUTUMN && !func_8031FF1C(BKPROG_E7_SUMMER_EYRIE_FED))
            ) {
                chcaterpillar_setState(this, 5);
            } else {
                chcaterpillar_setState(this, 1);
            }//L8038A45C
        }
    }//L8038A45C

    if(this->state == 1){
        func_8033568C(this->unk148, &sp64, &sp60);
        player_getPosition(sp74);
        if(ml_distance_vec3f(this->position, local->unk0) < 10.0f){
            for(i = 0; i < 10; i++){
                
                local->unk0[0] = randf2(-300.0f, 300.0f) + this->position_x;
                local->unk0[1] = this->position_y;
                local->unk0[2] = randf2(-300.0f, 300.0f) + this->position_z;
                if( !(ml_distance_vec3f(local->unk0, this->position) < 50.0f) && func_80329210(this, local->unk0))
                    break;
            }//L8038A544
            if(i == 10){
                local->unk0[0] = this->position[0];\
                local->unk0[1] = this->position[1];\
                local->unk0[2] = this->position[2];
            }//L8038A564
            if (i);
            local->unk0[1] = func_8038A190(this, local->unk0);
        }//L8038A570

        if(sp64 <= 0.1 && 0.1 < sp60){
            func_8030E878(SFX_AD_CATERPILLAR_SQUEAK, randf2(0.78f, 0.81f), 0x3a98, this->position, 500.0f, 1500.0f);
        }//L8038A5EC

        if(0.65 < sp60){
            func_80258A4C(this->position, this->yaw - 90.0f, local->unk0, &sp70, &sp6C, &sp68);
            this->yaw += (sp68*100.0f)*sp84;
        }//L8038A668

        if(sp60 <= 0.4){
            sp54[1] = 0.0f;
            sp54[2] = 0.0f;
            sp54[0] = 65.0f;
            ml_vec3f_yaw_rotate_copy(sp54, sp54, this->yaw - 90.0f);
            this->position[0] += sp84*sp54[0];
            this->position[2] += sp84*sp54[2];
            if(this->marker->unk14_21){
                this->position[1] = func_8038A190(this, this->position);
            }
        }//L8038A714

        if(ml_distance_vec3f(this->position, sp74) < 50.0f){
            func_8028F030(ACTOR_2A2_CATERPILLAR);
            if(!func_803203FC(0xb2)){
                func_80311480(0xcc7, 4, NULL, NULL, NULL, NULL);
                func_803204E4(0xb2, TRUE);
            }
            FUNC_8030E8B4(SFX_C5_TWINKLY_POP, 1.0f, 25000, this->position, 0x1f4, 0x9c4);
            marker_despawn(this->marker);
        }
    }//L8038A794

    if(this->state == 2){
        if(this->unk138_21){
            func_8028F010(ACTOR_2A2_CATERPILLAR);
            chcaterpillar_setState(this, 3);
        }
        else if(!sp8C){
            func_8028F050(ACTOR_2A2_CATERPILLAR);
            marker_despawn(this->marker);
        }
    }//L8038A804

    if(this->state == 3){
        func_80389BD8(local->unk18);
        local->unk24 += 3.3333333333333335*sp84;

        local->unk24 = (1.0 < local->unk24) ? 1.0 : local->unk24;
        ml_interpolate_vec3f(this->position, local->unkC, local->unk18, local->unk24);
        
        this->position[1] += 50.0f*sinf(local->unk24*3.141592654);
        if(1.0 == local->unk24){
            chcaterpillar_setState(this, 4);
        }
    }//L8038A8FC
}
