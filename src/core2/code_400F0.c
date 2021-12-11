#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_802BB360(s32, f32);
extern void func_802BB3AC(s32, f32);

typedef struct {
    f32 unk0;
    u8 unk4;
    f32 unk8;
    f32 unkC;
}Struct_Core2_400F0_0;

typedef struct {
    f32 unk0[2];
    f32 unk8[2];
}ActorLocal_Core2_400F0;

void func_802C75A0(Actor *actor, s32 arg1);

/* .data */
Struct_Core2_400F0_0 D_803660F0[] = {
    {2.0f,   1, 1.0f, 0.1f},
    {0.034f, 0, 1.0f, 0.1f},
    {0.1f,   1, 0.0f, 0.1f},
    {0.034f, 0, 0.0f, 0.1f},
    {5.0f,   1, 1.0f, 0.06f},
    {0.034f, 0, 1.0f, 0.06f},
    {0.06f,  1, 0.0f, 0.06f},
    {0.034f, 0, 0.0f, 0.06f},
    {0.2f,   1, 1.0f, 0.09f},
    {0.034f, 0, 1.0f, 0.09f},
    {0.09f,  1, 0.0f, 0.09f},
    {0.034f, 0, 0.0f, 0.09f},
    {1.0f,   1, 1.0f, 0.1f},
    {0.034f, 0, 1.0f, 0.1f},
    {0.1f,   1, 0.0f, 0.1f},
    {0.034f, 0, 0.0f, 0.1f},
    {5.0f,   1, 1.0f, 0.1f},
    {0.034f, 0, 1.0f, 0.1f},
    {0.1f,   1, 0.0f, 0.1f},
    {0.034f, 0, 0.0f, 0.1f},
    {0.0f,   2, 0.0f, 0.0f}
};

Struct_Core2_400F0_0 D_80366240[] ={
    {0.0f,   01, 1.0f, 0.1f},
    {0.034f, 00, 1.0f, 0.1f},
    {0.1f,   01, 0.0f, 0.1f},
    {0.034f, 00, 0.0f, 0.1f},
    {0.0f,   02, 0.0f, 0.0f}
};

/* .code */
void func_802C7080(Actor *actor, s32 arg1, f32 arg2, f32 arg3){
    ActorLocal_Core2_400F0 *local = (ActorLocal_Core2_400F0 *) &actor->local;
    local->unk8[arg1] = arg2;
    if(arg3 != 0.0f){
        actor->unk1C[arg1] = (local->unk8[arg1] - local->unk0[arg1])/arg3;
    }
    else{
        local->unk0[arg1] = local->unk8[arg1];
    }
}

void func_802C70DC(Actor *actor, Struct_Core2_400F0_0 * arg1, s32 arg2){
    f32 tmp_f20;
    Struct_Core2_400F0_0 *s0;

    tmp_f20 = time_getDelta();
    while(0.0f < tmp_f20){
        actor->unk60 -= tmp_f20;
        if(0.0f < actor->unk60)
            break;
        tmp_f20 = mlAbsF(actor->unk60);
        s0 = &arg1[actor->unk154];
        func_802C7080(actor, s0->unk4, s0->unk8, s0->unkC);
        s0++;
        if(s0->unk4 == 2){
            s0 = arg1;
            if(!arg2){
                func_802C75A0(actor, 1);
                return;
            }
            else{//L802C71A4
                actor->unk154 = 0; 
            }
        }
        else {//L802C71B0
            actor->unk154++; 
        }
        //L802C71B8
        actor->unk60 = s0->unk0;
    }//L802C71CC
}

void func_802C71F0(Actor *actor){
    ActorLocal_Core2_400F0 *local = (ActorLocal_Core2_400F0 *) &actor->local;
    switch(actor->modelCacheIndex){
        case 0x8E:
        case 0xAC:
        case 0xB8://L802C7254
            func_8033A45C(0x1, (s32)func_80257C48(local->unk0[0], 1.0f, 6.0f));
            func_8033A45C(0x2, (s32)func_80257C48(local->unk0[1], 1.0f, 6.0f));
            break;

        case 0x195:
        case 0x196:
        case 0x197://L802C72B0
        case 0x2FB://L802C72B4
            func_8033A45C(0x1C, (s32)func_80257C48(local->unk0[0], 1.0f, 8.0f));
            func_8033A45C(0x1D, (s32)func_80257C48(local->unk0[1], 1.0f, 8.0f));
            break;
    }
}

void func_802C7318(Actor *actor){
    ActorLocal_Core2_400F0 *local = (ActorLocal_Core2_400F0 *) &actor->local;
    int i;

    for(i = 0; i < 2; i++){
         actor->unk1C[i] = 0.0f;
         local->unk0[i] = 0.0f;
         local->unk8[i] = 0.0f;
    }
    actor->unk60 = 0.0f;
    actor->unk154 = 0;
    actor->unk124_5 = 0;
    reinterpret_cast(s32, actor->unkBC) = 1;
    switch(actor->modelCacheIndex){
        case 0x195:
        case 0x196:
        case 0x197:
            func_802C75A0(actor, 2);
            break;
    }
}

void func_802C73B0(Actor *actor, ActorLocal_Core2_400F0 *local){
    f32 tmp_f0 = time_getDelta();
    int i;

    for(i = 0; i < 2; i++){
        if(local->unk8[i] != local->unk0[i]){
            local->unk0[i] += actor->unk1C[i]*tmp_f0;

            if( ((0.0f < actor->unk1C[i]) && (local->unk8[i] < local->unk0[i]))
                || ((actor->unk1C[i] < 0.0f) && (local->unk0[i] < local->unk8[i]))
            ){
                local->unk0[i] = local->unk8[i];
            }
        }//L802C7460
    }
}

void func_802C7478(Actor *actor){
    func_802C73B0(actor, &actor->local);
    switch(actor->unk124_5){
        case 2://L802C74C4
            func_802C70DC(actor, &D_803660F0, 1);
            break;
        case 3://L802C74D8
            func_802C70DC(actor, &D_80366240, 0);
            break;
        case 1://L802C74E4
            break;
    }
}

void func_802C74F4(Actor *actor, s32 arg1, f32 arg2){
    f32 tmp_f0;
    switch(reinterpret_cast(s32, actor->unkBC)){
        case 0:
            tmp_f0 = 0.35f;
            break;
        case 2:
            tmp_f0 = 0.09f; 
            break;
        case 1:
        default:
            tmp_f0 = 0.2f; 
            break;
    }
    func_802C7080(actor, arg1, arg2, tmp_f0);
}

void func_802C7568(enum actor_e actor_id, s32 arg1, f32 arg2){
    Actor *actor = func_80326EEC(actor_id);
    if(actor)
        func_802C74F4(actor, arg1, arg2);
}

void func_802C75A0(Actor *actor, s32 arg1){
    actor->unk124_5 = arg1;
    actor->unk154 = 0;
    actor->unk60 = 0.0f;
}

void func_802C75C8(enum actor_e actor_id, s32 arg1){
    Actor *actor = func_80326EEC(actor_id);
    if(actor)
        func_802C75A0(actor, arg1);
}

void func_802C75F8(Actor *actor, s32 arg1){
    reinterpret_cast(s32, actor->unkBC) = arg1;
}

void func_802C7600(enum actor_e actor_id, s32 arg1){
    Actor *actor = func_80326EEC(actor_id);
    if(actor)
        func_802C75F8(actor, arg1);
}

void func_802C7630(enum actor_e actor_id){
    func_802C7600(actor_id, 0);
}

void func_802C7650(enum actor_e actor_id){
    func_802C7600(actor_id, 1);
}

void func_802C7670(enum actor_e actor_id){
    func_802C7600(actor_id, 2);
}

void func_802C7690(enum actor_e actor_id){
    func_802C75C8(actor_id, 1);
    func_802C7568(actor_id, 0, 1.0f);
    func_802C7568(actor_id, 1, 1.0f);
}

void func_802C76D4(enum actor_e actor_id){
    func_802C75C8(actor_id, 1);
    func_802C7568(actor_id, 0, 0.0f);
    func_802C7568(actor_id, 1, 0.0f);
}

void func_802C7718(enum actor_e actor_id){
    func_802C75C8(actor_id, 1);
    func_802C7568(actor_id, 0, 0.5f);
    func_802C7568(actor_id, 1, 0.5f);
}

void func_802C775C(enum actor_e actor_id){
    func_802C75C8(actor_id, 3);
}

void func_802C777C(enum actor_e actor_id){
    func_802C75C8(actor_id, 2);
}

int func_802C779C(s32 arg0){
    switch(arg0){
        case 0x10: // 802C77C8
            func_802C7630(0x8E);
            func_802C7630(0xB8);
            func_802C7630(0x2FB);
            return TRUE;
        case 0x11: // 802C77E8
            func_802C7650(0x8E);
            func_802C7650(0xB8);
            func_802C7650(0x2FB);
            return TRUE;
        case 0x12: // 802C7808
            func_802C7670(0x8E);
            func_802C7670(0xB8);
            func_802C7670(0x2FB);
            return TRUE;
        case 0x13: // 802C7828
            func_802C7690(0x8E);
            func_802C7690(0xB8);
            func_802C7690(0x2FB);
            return TRUE;
        case 0x14: // 802C7848
            func_802C76D4(0x8E);
            func_802C76D4(0xB8);
            func_802C76D4(0x2FB);
            return TRUE;
        case 0x15: // 802C7868
            func_802C7718(0x8E);
            func_802C7718(0xB8);
            func_802C7718(0x2FB);
            return TRUE;
        case 0x16: // 802C7888
            func_802C775C(0x8E);
            func_802C775C(0xB8);
            func_802C775C(0x2FB);
            return TRUE;
        case 0x17: // 802C78A8
            func_802C777C(0x8E);
            func_802C777C(0xB8);
            func_802C777C(0x2FB);
            return TRUE;
        case 0x18: // 802C78C8
            func_802C7630(0xAC);
            return TRUE;
        case 0x19: // 802C78D8
            func_802C7650(0xAC);
            return TRUE;
        case 0x1A: // 802C78E8
            func_802C7670(0xAC);
            return TRUE;
        case 0x1B: // 802C78F8
            func_802C7690(0xAC);
            return TRUE;
        case 0x1C: // 802C7908
            func_802C76D4(0xAC);
            return TRUE;
        case 0x1D: // 802C7918
            func_802C7718(0xAC);
            return TRUE;
        case 0x1E: // 802C7928
            func_802C775C(0xAC);
            return TRUE;
        case 0x1F: // 802C7938
            func_802C777C(0xAC);
            return TRUE;
        case 0xD:  // 802C7948
            func_802BB360(0, 10.0f);
            func_802BB3AC(0, 1.0f);
            func_802BB3C4(0);
            return TRUE;
        case 0xE:  // 802C7970
            func_802BB360(0, 35.0f);
            func_802BB3AC(0, 1.0f);
            func_802BB3C4(0);
            return TRUE;
        case 0xF:  // 802C7998
            func_802BB3AC(0, 0.8f);
            return TRUE;
            break;
    }
    return FALSE;
}




void func_802C79C4(void){
    int i;
    for(i = 0; i < 0x20; i++){
        if(mapSpecificFlags_get(i) && func_802C779C(i)){
            mapSpecificFlags_set(i, FALSE);
        }
    }
}