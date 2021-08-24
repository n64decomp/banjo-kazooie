#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F9DC(s32);
extern void func_803253A0(Actor *);
extern void func_8033A2D4(void(*)(Actor *), Actor *);

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

void func_8038A324(Actor *this);
Actor *func_8038A224(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3);

/* .data */
Struct_RBB_3CB0 D_80390720[2] = {
    {{0x0640, 0x324, 0xF6A0}, 0, 3, 0x27},
    {{0xF9C0, 0x324, 0xF6A0}, 0x405, 4, 0x28}
};

ActorInfo D_80390738 = {
    0x186, 0x176, 0x404, 0x0, NULL,
    func_8038A324, NULL, func_8038A224,
    {0, 0, 0, 0}, 0.0f, {0,0,0,0}
};

/* .code */
void func_8038A0A0(Actor *this, s32 arg1){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&this->local;

    if(arg1 == 1)
        if(this->state == 2)
            this->position_y += 40.0f;
    
    if(arg1 == 2){ 
        if(this->state == 1)
            func_8030E6D4(0x90);
        this->position_y -= 40.0f;
        if(this->state == 1){
            levelSpecificFlags_set(local->unk0->unk8, 1);
            func_803228D8();
            timedFunc_set_1(1.1f, (TFQM1)func_8028F9DC, 2);
            timedFunc_set_3(1.1f, (TFQM3)func_802E4078, MAP_31_RBB_RUSTY_BUCKET_BAY, 0, 0);
        }else{
            levelSpecificFlags_set(local->unk0->unkA, 1);
        }
    }//L8038A1A0

    this->state = arg1;
}

void func_8038A1C8(ActorMarker *marker, s32 arg1){
    Actor *actor = marker_getActor(marker);
    if(actor->state == 1){
        func_8038A0A0(actor, 2);
    }
    else if(actor->state == 2){
        func_8038FF40();
    }
}

Actor *func_8038A224(ActorMarker *marker, Gfx **gdl, Mtx **mptr, s32 arg3){
    Actor *actor = marker_getActor(marker);
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&actor->local;

    if(actor->state == 0){
        return actor;
    }

    func_8033A2D4(func_803253A0, actor);
    if(local->unk4){
        func_803391A4(gdl, mptr, &actor->position, NULL, 1.0f, NULL, local->unk4);
    }
    else{
        func_803391A4(gdl, mptr, &actor->position, NULL, 1.0f, NULL, func_80330B1C(marker));
    }
    return actor;
}

void func_8038A2F8(Actor *actor){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&actor->local;
    if(local->unk4)
        assetcache_release(local->unk4);
}

void func_8038A324(Actor *this){
    ActorLocal_RBB_3CB0 *local = (ActorLocal_RBB_3CB0 *)&this->local;
    if(!this->unk16C_4){
        this->marker->propPtr->unk8_3 = 1;
        this->marker->unk30 = func_8038A2F8;
        this->unk16C_4 = 1;
        local->unk0 = &D_80390720[((this->unk78_13 == 2) ? 0:1)];
        if(local->unk0->unk6 == 0)
            local->unk4 = NULL;
        else
            local->unk4 = assetcache_get(local->unk0->unk6);
        func_803300A8(this->marker, NULL, func_8038A1C8, NULL);
        this->position_x = (f32)local->unk0->unk0[0];
        this->position_y = (f32)local->unk0->unk0[1];
        this->position_z = (f32)local->unk0->unk0[2];
        if(levelSpecificFlags_get(local->unk0->unkA))
            func_8038A0A0(this, 2);
        else
            func_8038A0A0(this, 1);
    }//L8038A47C
    if(this->state == 2){
        if( !levelSpecificFlags_get(local->unk0->unkA)
            && !levelSpecificFlags_get(3)
            && !levelSpecificFlags_get(4)
        ){
            func_8038A0A0(this, 1);
        }
    }
}