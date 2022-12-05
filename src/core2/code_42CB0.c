#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80329904(ActorMarker*, s32, f32*);

typedef struct{
    s32 uid;
    s32 unk4;
}ActorLocal_EmptyHoneycomb;

void func_802C9E70(Actor *this);

/* .data */
ActorInfo D_80366C80 = { MARKER_53_EMPTY_HONEYCOMB, ACTOR_47_EMPTY_HONEYCOMB, ASSET_361_MODEL_EMPTY_HONEYCOMB, 
    0, NULL, 
    func_802C9E70, func_80326224, func_80325888, 
    0, 0, 0.8f, 0
};

ActorInfo D_80366CA4 = { MARKER_55_HONEYCOMB, ACTOR_50_HONEYCOMB, ASSET_363_MODEL_HONEYCOMB, 
    0, NULL, 
    func_802C9E70, func_80326224, func_80325888, 
    0, 0, 0.8f, 0
};

/* .bss */
enum honeycomb_e D_8037DDC0;
array(s32) *     D_8037DDC4;
s32              D_8037DDC8;
u32 D_8037DDCC;
s32 D_8037DDD0;

/* .code */
enum honeycomb_e func_802C9C40(Actor *this){
    s32 tmp_a0;
    s32 sp18[3];

    if(map_get() == MAP_2_MM_MUMBOS_MOUNTAIN){
        if (2500.0f < this->position_y) 
            return HONEYCOMB_2_MM_JUJU;
        else
            return HONEYCOMB_1_MM_HILL;
    }
    
    sp18[0] = (s32)this->position_x;
    sp18[1] = (s32)this->position_y;
    sp18[2] = (s32)this->position_z;

    tmp_a0 = func_80307164(sp18);
    if(tmp_a0 < 0)
        return 0;

    return func_80306DBC(tmp_a0) - 0x63;
}

void func_802C9CF4(Actor *this){
    ActorLocal_EmptyHoneycomb *local = (ActorLocal_EmptyHoneycomb *)&this->local;

    D_8037DDC8--;
    func_802EDCDC(D_8037DDC4, local->uid);
    D_8037DDCC &= ~(1 << local->uid);
    if(D_8037DDC8 == 0){
        array_free(D_8037DDC4);
        D_8037DDC4 = NULL;
    }
}

void func_802C9D80(void){
    int i;
    ActorMarker **i_marker_ptr;
    ActorMarker *i_marker;
    Actor *i_actor;
    ActorLocal_EmptyHoneycomb *i_local;
    u32 s2;
    ActorMarker *s5;
    s5 = NULL;
    s2 = 0xFFFFFFFF;
    for(i = 1; i < array_size(D_8037DDC4); i++){
        if(D_8037DDCC & (1 << i)){
            i_marker_ptr = (ActorMarker **)array_at(D_8037DDC4, i);
            i_marker = *i_marker_ptr;
            i_actor = marker_getActor(i_marker);
            i_local = (ActorLocal_EmptyHoneycomb *)&i_actor->local;
            if(i_local->unk4 < s2 && !i_actor->despawn_flag){
                s2 = i_local->unk4;
                s5 = i_marker;
            }
        }
    }
    func_802F373C(&s5->propPtr->x);
    marker_despawn(s5);
}

void func_802C9E70(Actor *this){
    ActorLocal_EmptyHoneycomb *local = (ActorLocal_EmptyHoneycomb *)&this->local;
    ActorMarker **tmp_v0;
    int i;

    if(!this->initialized){
        this->unk60 = (randf() < 0.5) ? 200.0 : -200.0;
        this->initialized = TRUE;
        if( this->marker->unk14_20 == MARKER_53_EMPTY_HONEYCOMB){
            if(local->uid == 0)
                local->uid = (!this->unk44_2)? D_8037DDC0 : func_802C9C40(this);
            if( honeycombscore_get(local->uid)
                || func_803203FC(1)
                || func_803203FC(2)
            ){
                marker_despawn(this->marker);
                return;
            }
        }
    }//L802C9F9C

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        if( this->marker->unk14_20 == MARKER_55_HONEYCOMB
            && !this->unk44_2
        ){
            marker_setFreeMethod(this->marker, func_802C9CF4);
            D_8037DDC8++;
            if(D_8037DDC4 == NULL){
                D_8037DDC4 = (array(s32) *) array_new(sizeof(s32), 10);
            }
            else if(D_8037DDC8 >= 11){
                func_802C9D80();
            }
            tmp_v0 = (ActorMarker **)func_802EDAA4(&D_8037DDC4, this->local);
            *tmp_v0 = this->marker;
            D_8037DDCC |= 1 << local->uid;
            local->unk4 = D_8037DDD0;
            D_8037DDD0++;
        }
    }//L802CA098

    if(map_get() == MAP_27_FP_FREEZEEZY_PEAK){
        if(func_8038BFA0()){
            this->unk58_0 = FALSE;
            actor_collisionOff(this);
            return;
        }
        else{
            this->unk58_0 = TRUE;
            actor_collisionOn(this);
        }
    }

    this->yaw += time_getDelta()*this->unk60;
    if(360.0f <= this->yaw) this->yaw -= 360.0f;
    if(this->yaw < 0.0f)    this->yaw += 360.0f;

    for(i = 0; i < 4; i++){
        if(randf() < 0.03){
            func_8033E73C(this->marker, i+5, func_80329904);
            func_8033E3F0(8, this->marker->unk14_21);
        }
    }
}

enum honeycomb_e func_802CA1C4(Actor *this){
    ActorLocal_EmptyHoneycomb *local = (ActorLocal_EmptyHoneycomb *)&this->local;
    return local->uid;
}

void func_802CA1CC(enum honeycomb_e id){
    D_8037DDC0 = id;
}
