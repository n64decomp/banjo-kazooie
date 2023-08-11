#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8035644C(s32);

typedef struct {
    s32 unk0;
}ActorLocal_Core2_59A80;

void func_802E0B10(Actor *this);
s32 func_802E0CB0(Actor *this);

/* .data */
 ActorInfo D_803685A0 = { 
    MARKER_39_MUMBO_TOKEN, ACTOR_2D_MUMBO_TOKEN, ASSET_41A_SPRITE_MUMBO_TOKEN,
    0, NULL, 
    func_802E0B10, func_80326224, func_80325934,
    2000, 0, 0.0f, 0
};

/* .bss */
s32 D_8037E610;

/* .code */
void chMumboToken_collect(ActorMarker *marker, ActorMarker *other_marker){
    Actor *this;
    
    this = marker_getActor(marker);
    mumboscore_set(func_802E0CB0(this), TRUE);
    func_8030E760(0x401, 1.0f, 0x7fff);
    timedFunc_set_1(0.75f, func_8035644C, FILEPROG_4_MUMBO_TOKEN_TEXT);
    fxSparkle_mumboToken(&marker->propPtr->x);
    item_inc(ITEM_1C_MUMBO_TOKEN);
    marker_despawn(marker);
    
}

s32 func_802E0A90(Actor *this){
    s32 id;
    s32 pos[3];

    map_get();
    pos[0] = (s32)this->position[0];
    pos[1] = (s32)this->position[1];
    pos[2] = (s32)this->position[2];
    id = func_80307164(pos);
    if(id < 0){
        return 0;
    }
    else{
        return func_80306DBC(id) - 199;
    }
}

void func_802E0B10(Actor *this){
    ActorLocal_Core2_59A80 *local;
    f32 sp28[3];

    local = (ActorLocal_Core2_59A80 *)&this->local;
    if(!this->initialized){
        this->initialized = TRUE;
        if(local->unk0 == NULL){
            if(!this->unk44_2){
                local->unk0 = D_8037E610;
            }
            else{
                local->unk0 = func_802E0A90(this);
            }
        }
        if( mumboscore_get(local->unk0)
            || func_803203FC(1)
            || func_803203FC(2)
            || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)
        ){
            marker_despawn(this->marker);
            return;
        }
    }//L802E0BD4

    if(!func_8032BBE8(this)){
        marker_setCollisionScripts(this->marker, chMumboToken_collect, NULL, NULL);
    }

    if(this->marker->unk14_21 && randf() < 0.1){
        sp28[0] = this->position[0] + randf2(-30.0f, 30.0f);
        sp28[1] = this->position[1] + randf2(25.0f, 55.0f);
        sp28[2] = this->position[2] + randf2(-30.0f, 30.0f);
        func_803525A0(sp28);
    }
}

s32 func_802E0CB0(Actor *this){
    ActorLocal_Core2_59A80 *local;
    f32 sp28[3];

    local = (ActorLocal_Core2_59A80 *)&this->local;
    return local->unk0;
}

void func_802E0CB8(s32 mumbo_token_id){
    D_8037E610 = mumbo_token_id;
}
