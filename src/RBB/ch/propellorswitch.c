#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F9DC(s32);
extern void actor_predrawMethod(Actor *);

/* typedefs and declarations */
typedef struct {
    s16 unk0[3];
    s16 unk6;
    s16 unk8;
    s16 unkA;
}Struct_RBB_3CB0;

typedef struct {
    Struct_RBB_3CB0 *unk0;
    void *unk4;
}ActorLocal_RBB_3CB0;

void chPropellorSwitch_update(Actor *this);
Actor *chPropellorSwitch_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3);

/* .data */
Struct_RBB_3CB0 D_80390720[2] = {
    {{0x0640, 0x324, 0xF6A0}, 0, 3, 0x27},
    {{0xF9C0, 0x324, 0xF6A0}, 0x405, 4, 0x28}
};

ActorInfo D_80390738 = {
    0x186, 0x176, 0x404, 0x0, NULL,
    chPropellorSwitch_update, NULL, chPropellorSwitch_draw,
    0, 0, 0.0f, 0
};

/* .code */
void __chPropellorSwitch_setState(Actor *this, s32 arg1){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&this->local;

    if(arg1 == 1)
        if(this->state == 2)
            this->position_y += 40.0f;
    
    if(arg1 == 2){ 
        if(this->state == 1)
            func_8030E6D4(SFX_90_SWITCH_PRESS);
        this->position_y -= 40.0f;
        if(this->state == 1){
            levelSpecificFlags_set(local->unk0->unk8, 1);
            func_803228D8();
            timedFunc_set_1(1.1f, (GenFunction_1)func_8028F9DC, 2);
            timedFunc_set_3(1.1f, (GenFunction_3)func_802E4078, MAP_31_RBB_RUSTY_BUCKET_BAY, 0, 0);
        }else{
            levelSpecificFlags_set(local->unk0->unkA, 1);
        }
    }//L8038A1A0

    this->state = arg1;
}

void func_8038A1C8(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1){
        __chPropellorSwitch_setState(actor, 2);
    }
    else if(actor->state == 2){
        rbb_propellorCtrl_start();
    }
}

Actor *chPropellorSwitch_draw(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&actor->local;

    if(actor->state == 0){
        return actor;
    }

    modelRender_preDraw(actor_predrawMethod, actor);
    if(local->unk4){
        modelRender_draw(gdl, mptr, &actor->position, NULL, 1.0f, NULL, local->unk4);
    }
    else{
        modelRender_draw(gdl, mptr, &actor->position, NULL, 1.0f, NULL, marker_loadModelBin(marker));
    }
    return actor;
}

void chPropellorSwitch_free(Actor *actor){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&actor->local;
    if(local->unk4)
        assetcache_release(local->unk4);
}

void chPropellorSwitch_update(Actor *this){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&this->local;
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->marker->unk30 = chPropellorSwitch_free;
        this->unk16C_4 = 1;
        local->unk0 = &D_80390720[((this->unk78_13 == 2) ? 0:1)];
        if(local->unk0->unk6 == 0)
            local->unk4 = NULL;
        else
            local->unk4 = assetcache_get(local->unk0->unk6);
        marker_setCollisionScripts(this->marker, NULL, func_8038A1C8, NULL);
        this->position_x = (f32)local->unk0->unk0[0];
        this->position_y = (f32)local->unk0->unk0[1];
        this->position_z = (f32)local->unk0->unk0[2];
        if(levelSpecificFlags_get(local->unk0->unkA))
            __chPropellorSwitch_setState(this, 2);
        else
            __chPropellorSwitch_setState(this, 1);
    }//L8038A47C
    if(this->state == 2){
        if( !levelSpecificFlags_get(local->unk0->unkA)
            && !levelSpecificFlags_get(3)
            && !levelSpecificFlags_get(4)
        ){
            __chPropellorSwitch_setState(this, 1);
        }
    }
}
