#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern ActorMarker *bacarry_getMarkerWithExtraSteps(void);
extern void func_8028F7D4(f32, f32);

typedef struct {
    f32 position[3];
    f32 unkC[3]; // some kind of distance
    f32 unk18[3]; // something time related
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

enum chCaterpillar_State_e {
    CH_CATERPILLAR_STATE_0_NOT_INIT,
    CH_CATERPILLAR_STATE_1_PULL_OUT,
    CH_CATERPILLAR_STATE_2_HOLDING,
    CH_CATERPILLAR_STATE_3_TOSS,
    CH_CATERPILLAR_STATE_4_GIVEN_TO_EEYRIE,
    CH_CATERPILLAR_STATE_5_DESPAWN
};

/* .code */
f32 func_8038A190(Actor *this, f32 *arg1) {
    f32 floor_y_position;
    f32 caterpillar_y_position;

    floor_y_position = mapModel_getFloorY(arg1);
    caterpillar_y_position = this->position[1];
    if (((caterpillar_y_position + 50.0f) < floor_y_position)
        || (floor_y_position < (caterpillar_y_position - 50.0f)))
    {
        return caterpillar_y_position;
    }
    return floor_y_position;
}

void chcaterpillar_setState(Actor *this, s32 next_state) {
    ActorLocal_Caterpillar *local = (ActorLocal_Caterpillar *)&this->local;

    if (next_state == CH_CATERPILLAR_STATE_1_PULL_OUT) {
        skeletalAnim_set(this->unk148, ASSET_18D_ANIM_CATERPILLAR_UNK, 0.0f, randf2(1.9f, 2.1f));
    }
    if (next_state == CH_CATERPILLAR_STATE_2_HOLDING) {
        func_8028F7D4(-25.0f, 90.0f);
        skeletalAnim_set(this->unk148, ASSET_18E_ANIM_CATERPILLAR_IDLE, 0.2f, 2.0f);
    }
    if (next_state == CH_CATERPILLAR_STATE_3_TOSS) {
        skeletalAnim_set(this->unk148, ASSET_18E_ANIM_CATERPILLAR_IDLE, 0.2f, 2.0f);
        local->unkC[0] = this->position[0];
        local->unkC[1] = this->position[1];
        local->unkC[2] = this->position[2];
        local->unk24 = 0.0f;
    }
    if (next_state == CH_CATERPILLAR_STATE_4_GIVEN_TO_EEYRIE) {
        coMusicPlayer_playMusic(COMUSIC_2B_DING_B, 28000);
        marker_despawn(this->marker);
    }
    if (next_state == CH_CATERPILLAR_STATE_5_DESPAWN) {
        actor_collisionOff(this);
    }
    this->state = next_state;
}

Actor*  chcaterpillar_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    if(this->state == CH_CATERPILLAR_STATE_5_DESPAWN){
        return func_80325340(marker, gfx, mtx, vtx);
    }
    return actor_draw(marker, gfx, mtx, vtx);
}

void chcaterpillar_update(Actor *this){
    bool player_is_carrying_caterpillar;
    ActorLocal_Caterpillar *local = (ActorLocal_Caterpillar *)&this->local;
    f32  time_delta;
    enum map_e map_id;
    f32 sp74[3];
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp54[3];
    int i;

    player_is_carrying_caterpillar = bacarry_getMarkerWithExtraSteps() == this->marker;
    time_delta = time_getDelta();

    if(!this->volatile_initialized){
        this->volatile_initialized = TRUE;
        local->position[0] = this->position[0];
        local->position[1] = this->position[1];
        local->position[2] = this->position[2];
        if(player_is_carrying_caterpillar){
            chcaterpillar_setState(this, CH_CATERPILLAR_STATE_2_HOLDING);
        }
        else{//L8038A408
            map_id = gsworld_getMap();
            if ( !fileProgressFlag_get(FILEPROG_E6_SPRING_EYRIE_HATCHED)
                 || ( map_id == MAP_45_CCW_AUTUMN && !fileProgressFlag_get(FILEPROG_E7_SUMMER_EYRIE_FED))
            ) {
                chcaterpillar_setState(this, CH_CATERPILLAR_STATE_5_DESPAWN);
            } else {
                chcaterpillar_setState(this, CH_CATERPILLAR_STATE_1_PULL_OUT);
            }//L8038A45C
        }
    }//L8038A45C

    if(this->state == CH_CATERPILLAR_STATE_1_PULL_OUT){
        skeletalAnim_getProgressRange(this->unk148, &sp64, &sp60);
        player_getPosition(sp74);
        if(ml_vec3f_distance(this->position, local->position) < 10.0f){
            for(i = 0; i < 10; i++){
                
                local->position[0] = randf2(-300.0f, 300.0f) + this->position_x;
                local->position[1] = this->position_y;
                local->position[2] = randf2(-300.0f, 300.0f) + this->position_z;
                if( !(ml_vec3f_distance(local->position, this->position) < 50.0f) && func_80329210(this, local->position))
                    break;
            }//L8038A544
            if(i == 10){
                local->position[0] = this->position[0];\
                local->position[1] = this->position[1];\
                local->position[2] = this->position[2];
            }//L8038A564
            if (i);
            local->position[1] = func_8038A190(this, local->position);
        }//L8038A570

        if(sp64 <= 0.1 && 0.1 < sp60){
            func_8030E878(SFX_AD_CATERPILLAR_SQUEAK, randf2(0.78f, 0.81f), 0x3a98, this->position, 500.0f, 1500.0f);
        }//L8038A5EC

        if(0.65 < sp60){
            func_80258A4C(this->position, this->yaw - 90.0f, local->position, &sp70, &sp6C, &sp68);
            this->yaw += (sp68*100.0f) * time_delta;
        }//L8038A668

        if(sp60 <= 0.4){
            sp54[1] = 0.0f;
            sp54[2] = 0.0f;
            sp54[0] = 65.0f;
            ml_vec3f_yaw_rotate_copy(sp54, sp54, this->yaw - 90.0f);
            this->position[0] += time_delta * sp54[0];
            this->position[2] += time_delta * sp54[2];
            if(this->marker->unk14_21){
                this->position[1] = func_8038A190(this, this->position);
            }
        }//L8038A714

        if(ml_vec3f_distance(this->position, sp74) < 50.0f){
            bacarriedobj_incWithExtraSteps(ACTOR_2A2_CATERPILLAR);
            if(!volatileFlag_get(VOLATILE_FLAG_B2_HAS_COLLECTED_CATERPILLAR)){
                gcdialog_showDialog(VER_SELECT(ASSET_CC7_DIALOG_CATERPILLAR_COLLECT, 0x09DC, 0, 0), 4, NULL, NULL, NULL, NULL);
                volatileFlag_set(VOLATILE_FLAG_B2_HAS_COLLECTED_CATERPILLAR, TRUE);
            }
            sfx_playFadeShorthandDefault(SFX_C5_TWINKLY_POP, 1.0f, 25000, this->position, 0x1f4, 0x9c4);
            marker_despawn(this->marker);
        }
    }//L8038A794

    if(this->state == CH_CATERPILLAR_STATE_2_HOLDING){
        if(this->unk138_21){
            bacarriedobj_decWithExtraSteps(ACTOR_2A2_CATERPILLAR);
            chcaterpillar_setState(this, CH_CATERPILLAR_STATE_3_TOSS);
        }
        else if(!player_is_carrying_caterpillar){
            bacarriedobj_displayOnHudWithExtraSteps(ACTOR_2A2_CATERPILLAR);
            marker_despawn(this->marker);
        }
    }//L8038A804

    if(this->state == CH_CATERPILLAR_STATE_3_TOSS){
        func_80389BD8(local->unk18);
        local->unk24 += 3.3333333333333335 * time_delta;

        local->unk24 = (1.0 < local->unk24) ? 1.0 : local->unk24;
        ml_vec3f_interpolate_fast(this->position, local->unkC, local->unk18, local->unk24);
        
        this->position[1] += 50.0f*sinf(local->unk24 * 3.141592654);
        if(1.0 == local->unk24){
            chcaterpillar_setState(this, CH_CATERPILLAR_STATE_4_GIVEN_TO_EEYRIE);
        }
    }//L8038A8FC
}
