#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct{
    ActorMarker *jiggy_marker;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    u8 unk10;
} ActorLocal_Napper;

void chnapper_update(Actor *this);
Actor *chnapper_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

/* .data */
ActorInfo chNapper = {  
    MARKER_48_NAPPER, ACTOR_39_NAPPER, ASSET_55E_MODEL_NAPPER, 
    0x0, NULL,
    chnapper_update, chnapper_update, chnapper_draw, 
    0, 0, 0.0f, 0
};

/* .code */
void __chnapper_setState(Actor *this, s32 next_state){
    ActorLocal_Napper *local = (ActorLocal_Napper *)&this->local;
    
    local->jiggy_marker->collidable = TRUE;
    local->unk4 = 0.0f;
    actor_collisionOff(this);
    if(next_state == 1)
        func_80335924(this->unk148, ASSET_A3_ANIM_NAPPER_SLEEPING, 0.2f, 2.5f);
    
    if(next_state == 2){
        func_80335924(this->unk148, ASSET_A4_ANIM_NAPPER_AWAKE, 0.2f, 5.0f);
        actor_collisionOn(this);
        local->jiggy_marker->collidable = FALSE;
        local->unk8 = randf2(2.0f, 6.0f);
    }

    if(next_state == 3){
        func_80335924(this->unk148, 0xA5, 0.2f, 1.5f);
        func_80335A8C(this->unk148, 2);
        func_8030E484(SFX_41_MUMBO_ERGHHH);
    }

    if(next_state == 4){
        func_8030E484(SFX_C_TAKING_FLIGHT_LIFTOFF);
        func_803895B0(0);
    }
    
    if(next_state == 5){
        func_80335924(this->unk148, 0xA6, 2.0f, 4.0f);
        actor_collisionOn(this);
        local->jiggy_marker->collidable = FALSE;
    }

    this->state = next_state;
}

void func_80386ACC(ActorMarker *this_marker, ActorMarker *other_marker){
    Actor *this = marker_getActor(this_marker);

    if(!this->unk138_24){
        if(func_80311480(0xad8, 0, NULL, NULL, NULL, NULL)){
            this->unk138_24 = TRUE;
        }
    }
}

Actor *chnapper_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    ActorLocal_Napper *local = (ActorLocal_Napper *)&this->local;

    if(this->state == 1){
        func_8033A45C(1, TRUE);
        func_8033A45C(2, FALSE);
        func_8033A45C(3, FALSE);
    }
    else {
        func_8033A45C(1, FALSE);
        func_8033A45C(2, (local->unk10) ? TRUE : FALSE);
        func_8033A45C(3, (local->unk10) ? FALSE : TRUE);
    }

    if(this->state == 1){ //set model alpha
        func_8033A410(0x80);
    }
    else{
        func_8033A410(0xdc);
    }

    return func_80325888(marker, gfx, mtx, vtx);
}

void chnapper_update(Actor *this){
    f32 sp74;
    f32 sp70;
    ActorLocal_Napper *local = (ActorLocal_Napper *)&this->local;
    f32 sp68;
    Actor *jiggy;
    f32 sp58[3];
    f32 sp4C[3];
    s32 pad;
    f32 player_position[3];
    f32 sp30[3];

    sp68 = time_getDelta();

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->scale = 0.5f;
        marker_setCollisionScripts(this->marker, func_80386ACC, NULL, NULL);
        local->unk10 = TRUE;
        local->jiggy_marker = NULL;
        local->unk4 = 0.0f;
        local->unk8 = 0.0f;
        local->unkC = 1.0f;
        return;
    }//L80386CBC

    if(this->state == 0){
        jiggy = func_80326EEC(ACTOR_46_JIGGY);
        if(jiggy){
            local->jiggy_marker = jiggy->marker;
            this->position_x = jiggy->position_x;\
            this->position_y = jiggy->position_y;\
            this->position_z = jiggy->position_z;
            this->position_y -= 50.0f;
            __chnapper_setState(this, 1);
        }
        else{
            marker_despawn(this->marker);
        }
        return;
    }

    func_8033568C(this->unk148, &sp70, &sp74);
    local->unk4 += sp68;

    if(this->state != 1){
        local->unkC -= sp68;
        if(local->unkC <= 0.0f){
            local->unk10 = 1 - local->unk10;
            if(local->unk10 == 0){
                local->unkC = randf2(0.1f, 0.2f);
                
            }
            else{
                local->unkC = randf2(1.5f, 5.0f);
            }
        }
    }//L80386DF4

    if(this->state != 4){
        func_8024C5CC(sp58);
        sp4C[0] = this->position_x - sp58[0];
        sp4C[1] = this->position_y - sp58[1];
        sp4C[2] = this->position_z - sp58[2];
        ml_vec3f_set_length(sp4C, 5.0f);
        jiggy = marker_getActor(local->jiggy_marker);
        jiggy->position_x = sp4C[0] + this->position_x;
        jiggy->position_y = sp4C[1] + this->position_y;
        jiggy->position_z = sp4C[2] + this->position_z;
    }//L80386E98

    if(this->state == 1){
        if(sp74 < sp70)
            FUNC_8030E624(SFX_5E_BANJO_PHEWWW,  0.8f, 11000);
        
        if(sp70 < 0.5 && 0.5 <= sp74)
            FUNC_8030E624(SFX_5D_BANJO_RAAOWW, 0.8f, 11000);
        
        if(!func_80389510()){
            __chnapper_setState(this, 2);
        }

        if(func_80389530() || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)){
            __chnapper_setState(this, 3);
        }
    }//L80386F74

    if(this->state == 2 && func_8025773C(&local->unk8, sp68)){
        player_getPosition(player_position);
        sp30[0] = player_position[0] - this->position_x;
        sp30[1] = player_position[1] - this->position_y;
        sp30[2] = player_position[2] - this->position_z;
        if( 0.0f < sp30[2] 
            && gu_sqrtf(sp30[0]*sp30[0] + sp30[1]*sp30[1] + sp30[2]*sp30[2]) < 600.0f
        ){
            __chnapper_setState(this, 5);
        }
        else{//L8038703C
            local->unk8 = randf2(1.0f, 2.0f);
        }
    }//L80387058

    if(this->state == 5){
        if(4.0f <= local->unk4){
            __chnapper_setState(this, 2);
        }

        if(sp70 < 0.35 && 0.35 <= sp74){
            if(!func_803114B0()){
                func_8030E6A4(SFX_3F5_UNKNOWN, randf2(0.9f, 1.1f), 0x7fff);
            }
        }
    }//L803870F8

    if(this->state == 3){
        if(func_80335794(this->unk148) > 0){
            func_80335924(this->unk148, ASSET_A4_ANIM_NAPPER_AWAKE, 1.0f, 5.0f);
            func_80335A8C(this->unk148, 1);
        }

        if(func_80389524())
            __chnapper_setState(this, 4);
    }//L80387154

    if(this->state == 4){
        func_80326224(this);
        if(0.99 <= this->unk48)
            marker_despawn(this->marker);
    }
}