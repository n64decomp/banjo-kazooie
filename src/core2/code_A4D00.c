#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

s32 func_8032D9C0(Cube*, Prop*);
void func_80332B2C(ActorMarker * arg0);
s32 func_803058C0(f32);
void func_80305CD8(s32, s32);
void func_80330104(Cube*);
void func_80254608(void *, void *, s32);
ActorMarker * func_80332A60(void);

extern ModelCache *modelCache; //model pointer array pointer
extern u32 D_80383444;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032BC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032BD64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032BD88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C4AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C660.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032C9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D3D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D80C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032D8F0.s")

//cube_removeProp
s32 func_8032D9C0(Cube *this, Prop* prop){
    s32 sp24;
    s32 tmp;

    sp24 = 0;
    if(this->prop2Cnt != 0){
        sp24 = prop->pad8_1; 
        if(func_80305D14()){
            func_80305CD8(func_803058C0(prop->unk6), -1);
        }
        if((prop - this->prop2Ptr) < (this->prop2Cnt - 1)){
            func_80254608(prop, prop + 1, (s32)(&this->prop2Ptr[this->prop2Cnt-1]) - (s32)(prop));
        }
        this->prop2Cnt--;
        if(this->prop2Cnt){
            this->prop2Ptr = realloc(this->prop2Ptr, this->prop2Cnt*sizeof(Prop));
            func_80330104(this);
        }else{
            free(this->prop2Ptr);
            this->prop2Ptr = NULL;
        }
        return sp24;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DB2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DCAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DDD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DE48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DE5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DE8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DEFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DF60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DFA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032DFF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E02C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E07C.s")
// void func_8032E07C(Cube *this){
//     s32 i;
//     Prop *list_end;
//     Prop *cur_ptr;

//     if(this->prop2Ptr){
//         list_end = this->prop2Ptr + this->prop2Cnt;
//         for(cur_ptr = this->prop2Ptr; cur_ptr != list_end; cur_ptr++){
//             if(cur_ptr->markerFlag){
//                 func_80332B2C(cur_ptr->actor.marker);
//             }
//         }
//         free(this->prop2Ptr);
//         this->prop2Ptr = NULL;
//     }
//     if(this->prop1Ptr){
//         free(this->prop1Ptr);
//         this->prop1Ptr = NULL;
//     }
//     this->prop2Cnt = 0;
//     this->prop1Cnt = 0;
//     this->pad0 = 0;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E6CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EA24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F3D4.s")


void func_8032F430(ActorMarker *this){
    func_8032D9C0(this->cubePtr, this->propPtr);
    func_80332B2C(this);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F464.s")

void func_8032F470(s32 *pos, ActorMarker *arg1){
    Cube *cubePtr;

    cubePtr = (arg1->unk40_23)? func_8030364C(): func_80303470(pos);

    if(cubePtr == arg1->cubePtr){
        arg1->propPtr->x = pos[0];
        arg1->propPtr->y = pos[1];
        arg1->propPtr->z = pos[2];
    }
    else{
        func_8032F194(arg1, pos, cubePtr);
    }

    if(arg1->unk2C_1)
        func_80307CA0(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F5B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F5E8.s")

void func_8032F64C(f32 *pos, ActorMarker * marker){
    s32 pos_w[3];

    pos_w[0] = pos[0];
    pos_w[1] = pos[1];
    pos_w[2] = pos[2];
    func_8032F470(pos_w, marker);
}

void func_8032F6A4(s32 *pos, ActorMarker * marker, s32 *rot){
    s32 rot_w[3];
    
    rot_w[0] = (s32)rot[0] % 360;
    if(rot_w[0] < 0)
        rot_w[0] += 360;

    rot_w[1] = (s32)rot[1] % 360;
    if(rot_w[1] < 0)
        rot_w[1] += 360;

    rot_w[2] = (s32)rot[2] % 360;
    if(rot_w[2] < 0)
        rot_w[2] += 360;

    marker->yaw = rot_w[1];
    marker->pitch = rot_w[0];
    marker->roll = rot_w[2];
    func_8032F470(pos, marker);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F7EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F9DC.s")
/*ActorMarker * func_8032F9DC(s32 *pos, void *arg1, int arg2, enum asset_e model_id, int arg4){
    ActorMarker * marker = func_80332A60();
    marker->propPtr = NULL;
    marker->cubePtr = NULL;
    marker->unk8 = arg1;
    marker->unk14_20 ^= marker->unk14_20;
    marker->unk40_23 = arg4;
    func_8032F3D4(pos, marker, arg2);
    marker->actrArrayIdx = 0;
    marker->modelId= model_id;
    marker->unk3C_1 = 0;
    marker->collidable = 0;

    marker->unk40_31 = 3;
    marker->unk40_26 = 0;
    marker->unk40_22 = 0;
    marker->unkC = NULL;
    marker->unk10 = 0;
    marker->unk1C = 0;
    marker->unk54 = 0;
    marker->unk58 = 0;
    marker->unk18 = 0;
    marker->unk24 = 0;
    marker->unk30 = NULL;
    marker->unk28 = 0;
    marker->unk34 = 0;
    marker->unk38 = 0;
    marker->unk3A = 0;
    marker->unk3C_31 = 0;
    marker->unk44 = 0;
    marker->unk20 = 0;
    marker->unk50 = 0;
    marker->unk48 = 0;
    marker->unk4C = 0;
    marker->unk40_20 = 0;
    marker->unk40_31 = 0;
    return marker;
}//*/

ActorMarker * func_8032FB80(f32 *pos, void *arg1, int arg2, enum asset_e model_id, int arg4){
    s32 sp24[3];
    sp24[0] = pos[0];
    sp24[1] = pos[1];
    sp24[2] = pos[2];
    func_8032F9DC(sp24, arg1, arg2, model_id, arg4);
}

ActorMarker * func_8032FBE4(f32 *pos, void *arg1, int arg2, enum asset_e model_id){
    return func_8032FB80(pos, arg1, arg2, model_id, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FC04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FFD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032FFF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300E0.s")

//actorMarker_setModelId
void func_803300E8(ActorMarker *this, s32 modelIndex){
    this->modelId = modelIndex;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803303B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8033056C.s")

//modelCache_Init
void func_803305AC(void){
    s32 i;

    modelCache = (ModelCache *)malloc(0x3D5 * sizeof(ModelCache));
    for(i = 0; i<0x3D5; i++){
        modelCache[i].modelPtr = NULL;
        modelCache[i].unk4 = 0;
        modelCache[i].unk8 = 0;
        modelCache[i].unkC = 0;
    }
    D_80383444 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803306C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803308A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330B10.s")

//ActorMarker_getModelPtr
void *func_80330B1C(ActorMarker *this){
    Actor* thisActor;
    void * model;
    ModelCache *modelInfo;

    if(this->modelId == 0)
        return NULL;

    thisActor = marker_getActor(this);
    if((modelInfo = &modelCache[thisActor->modelCacheIndex])->modelPtr == NULL){
        model = assetcache_get(this->modelId);
        modelInfo->modelPtr = model;
        if(func_8033A110(model)){
            modelInfo->unkC = func_80349C3C();
            func_80349D00(modelInfo->unkC, func_8033A110(modelInfo->modelPtr));
        }
        func_8032ACA8(thisActor);
    }
    func_8032AB84(thisActor);
    if(!this->unk18 && this->propPtr->unk8_1 && modelInfo->modelPtr && func_8033A12C(modelInfo->modelPtr)){
        this->unk18 = func_80330B10();
    }
    modelInfo->unk10 = func_8023DB5C();
    return modelInfo->modelPtr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330DC4.s")

void *func_80330DE4(ActorMarker *this){
    Actor *thisActor = marker_getActor(this);
    return (modelCache + thisActor->modelCacheIndex)->modelPtr;
}

void *func_80330E28(Actor* this){
    return (modelCache + this->modelCacheIndex)->modelPtr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803311D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803319C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803320BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8033229C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803322F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803327A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803327D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8033283C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8033297C.s")

extern ActorMarker *D_8036E7C8;
extern u32 D_8036E804[8];
extern u8 D_80383428[];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803329AC.s")
// void func_803329AC(void){
//     u8 *iPtr;
//     s32 i;
    
//     D_8036E7C8 = (ActorMarker *)malloc(0xE0*sizeof(ActorMarker));
//     // for(i = 0; i < 0xE0/8; i++){
//     //     (&D_80383428)[i] = 0;
//     // }
//     if(iPtr = &D_80383428);
//     do{
//         *(iPtr++) = 0;
//     }while((u32)iPtr < (u32)&D_80383444);
       
//     for(i =0; i<0xE0; i++){
//         D_8036E7C8[i].unk5C = 0;
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332A38.s")


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332B2C.s")
// void func_80332B2C(ActorMarker * arg0){
//     s32 index = ((s32)arg0 - (s32)(D_8036E7C8))/(s32)sizeof(ActorMarker);
//     arg0->unk5C = 0;
    
//     D_80383428[index >> 3] &= D_8036E804[index & 7];
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332B7C.s")
