#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802BE720(void);
extern void func_8033A244(f32);
extern void func_8033A280(f32);

extern u8 D_80329904[];

typedef struct chjiggy_s{
    u32 unk0;
    u32 index;
} ActorLocal_Jiggy;

Actor *func_802C41D8(f23, f32, f32);
void func_802C7AF8(u32 x, u32 y, u32 z, u32 arg3);
Actor *func_802C7D0C(ActorMarker *this, Gfx **gdl, Mtx **mptr, u32 arg3);
void func_802C7D98(Actor * arg0);
void func_802C7DC0(Actor *this);
int func_802C8088(Actor *this);



/* .data */
ActorAnimationInfo D_80366290[] = {
    {0, 0.0f},
    {0, 0.0f},
    {0, 0.0f}
};

ActorInfo D_803662A8 = {
    0x52, ACTOR_46_JIGGY, ASSET_35F_MODEL_JIGGY, 
    1, D_80366290, 
    func_802C7DC0, func_802C7D98, func_802C7D0C,
    {0,0,0,0}, 0.9f, {0,0,0,0}
}; 

/* .code */
enum jiggy_e func_802C7A30(Actor *this){
    s32 id;
    s32 sp18[3];
    
    id = func_803348C0();

    sp18[0] = (s32)this->position[0];
    sp18[1] = (s32)this->position[1]; 
    sp18[2] = (s32)this->position[2]; 
    id = func_80307164(sp18);
    if( id < 0){
        return 0;
    }
    else{
        return func_80306DBC(id) + 1;
    }
}

void func_802C7AB0(ActorMarker * arg0, u32 arg1){
    func_8030E6D4(SFX_30_MAGIC_POOF);
    func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 0x7FF8);
    mapSpecificFlags_set(arg1, 1);
    marker_despawn(arg0);
}

void func_802C7AF8(u32 x, u32 y, u32 z, u32 arg3){
    func_802C3F04(func_802C41D8, ACTOR_4C_STEAM, x, y, z);
    func_802C3F04(func_802C41D8, ACTOR_14F_DESTROYED_JIGGY, x, y, z);
    mapSpecificFlags_set(arg3, 1);
}

void func_802C7B6C(u32 arg0){
    mapSpecificFlags_set(arg0, 0);
}

void func_802C7B8C(Actor *this, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6){
    if( !mapSpecificFlags_get(arg1)
        && mapSpecificFlags_get(arg2)
        && item_getCount(ITEM_0_HOURGLASS_TIMER) == 0
    ){
        func_8028FCC8(1);
        actor_collisionOff(this);
        func_802BAFE4(arg3);
        func_80356520(arg6);
        timedFunc_set_4(0.6f, (TFQM4 *)func_802C7AF8, (s32)this->position[0], (s32)this->position[1], (s32)this->position[2], arg4);
        timedFunc_set_2(0.6f, (TFQM2 *)func_802C7AB0, (s32)this->marker, arg5);
        timedFunc_set_0(1.0f, (TFQM0 *)func_802BE720);
        timedFunc_set_1(3.9f, (TFQM1 *)func_802C7B6C, arg4);
        mapSpecificFlags_set(arg1, 1);
    }
}

//chjiggy_updateRotate
void func_802C7CA4(Actor *this){
    f32 delta = func_8033DD9C();
    this->yaw += delta * 230.0f;
    if(360.0f <= this->yaw){
        this->yaw -= 360.0f;
    }
    this->yaw_moving = this->yaw;
}

//chjiggy_draw
Actor *func_802C7D0C(ActorMarker *this, Gfx **gdl, Mtx **mptr, u32 arg3){
    Actor * thisActor = marker_getActor(this);
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&thisActor->local;
    u32 jiggyId;

    if(!local->unk0){
        jiggyId = func_802C8088(thisActor);
        if((jiggyId == JIGGY_1C_CC_RINGS) || (jiggyId == JIGGY_1D_CC_SLOW_SAWBLADES)){
            func_8033A280(10.0f);
            func_8033A244(30000.0f);
        }
        thisActor = func_80325888(this, gdl, mptr, arg3);
    }
    return thisActor;
}

void func_802C7D98(Actor * arg0){
    func_80343DEC(arg0);
    func_802C7CA4(arg0);
}

//chjiggy_update
void func_802C7DC0(Actor *this){
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    int i;

    if(this->marker->unk14_21){
        for(i = 0; i < 4; i++){
            if(randf() < 0.015){
                func_8033E73C(this->marker, i + 5, &D_80329904);
                func_8033E3F0(8, 1);
            }
        }
    }//L802C7E44
    switch(this->state){
        case 1: //L802C7E68
            local->unk0 = 0;
            if(local->index == 0)
                local->index = func_802C7A30(this);
            
            if(jiggyscore_isCollected(local->index)){
                marker_despawn(this->marker);
            }
            else{
                func_80328A84(this, 2);
                switch(func_802C8088(this)){
                    case JIGGY_17_CC_CLANKER_RAISED: //L802C7EF8
                    case JIGGY_49_CCW_EYRIE:// L802C7EF8
                        this->marker->unk40_21 = 1;
                        break;
                    case JIGGY_36_LAIR_TTC_WITCH_SWITCH:// L802C7F0C
                        this->unk44_14 = func_80341F2C(0x20A);
                        this->unk48 = 0.0f;
                        this->unk4C = 300.0f;
                        this->marker->unk2C_2 = 1;
                        this->unk54 = 0.0f;
                        func_80343DEC(this);
                        func_802C7CA4(this);
                        break;
                    case JIGGY_3E_GV_GRABBA:// L802C7F6C
                    case JIGGY_4D_CCW_FLOWER:// L802C7F6C
                        this->unk124_6 = 0;
                        break;
                    case JIGGY_41_GV_MAZE:// L802C7F7C
                        this->marker->unk14_19 = 0x1E;
                        break;
                    case JIGGY_13_TTC_LOCKUP: //L802C7F94
                        this->marker->unk14_19 = 0x28;
                        break;
                }
            }
            break;
        case 2: //L802C7FAC
            func_802C7CA4(this);
            switch(func_802C8088(this)){
                case JIGGY_20_BGS_ELEVATED_WALKWAY: //L802C7FE8
                    func_802C7B8C(this, 4, 3, 0xD, 5, 2, 0xae);
                    break;
                case JIGGY_25_BGS_MAZE://L802C8018
                    func_802C7B8C(this, 0xd, 0xc, 0x1e, 9, 0xb, 0xaf);
                    break;
                case JIGGY_2F_FP_XMAS_TREE://L802C8048
                    if(levelSpecificFlags_get(0x29))
                        actor_collisionOn(this);
                    else
                        actor_collisionOff(this);
                    break;
            }
            break;
    }//L802C8074
}

//chjiggy_getId
int func_802C8088(Actor *this){
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    return local->index;
}


void func_802C8090(Actor * this){
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    local->unk0 = 1;
    actor_collisionOff(this);
}

//chjiggy_setId
void func_802C80B4(Actor *this, u32 id){
    ActorLocal_Jiggy *local = (ActorLocal_Jiggy *)&this->local;
    local->index = id;
}
