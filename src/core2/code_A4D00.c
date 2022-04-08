#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "structs.h"

Prop *func_80303F7C(s32, f32, s32, s32);
s32 func_8032D9C0(Cube*, Prop*);
void func_80332B2C(ActorMarker * arg0);
s32 func_803058C0(f32);
void func_80305CD8(s32, s32);
void func_80330104(Cube*);
ActorMarker * func_80332A60(void);
extern void func_8032F3D4(s32 [3], ActorMarker *, s32);
extern void func_8030A350(Gfx **, Mtx **, Vtx **, f32[3], f32, s32, Cube*,s32 ,s32, s32, s32, s32);  
extern void func_8030A2D0(Gfx **, Mtx **, Vtx **, f32[3], f32[3], f32, s32, Cube*);

typedef union{
    struct{
        u32 pad31: 27;
        u32 unk4: 1;
        u32 pad3: 1;
        u32 unk2: 1;
        u32 unk1: 1;
        u32 unk0: 1;
    };
    u32 word;
} tmp_bitfield;

s32 func_80320DB0(f32[3], f32, f32[3], u32);
extern void func_80320EB0(ActorMarker *, f32, s32);
extern void func_80320ED8(ActorMarker *, f32, s32);
f32 func_8033229C(ActorMarker *marker);
void func_8032CD60(Prop *);
void func_8033A244(f32);
void func_8032F64C(f32 *pos, ActorMarker * marker);
/* .data */
extern s32 D_8036E7B0;

/* .rodata */
extern f32 D_80378EA0;
extern f32 D_80378EA4;

/* .bss */
extern f32 D_803833D8[3];
extern ModelCache *modelCache; //model pointer array pointer
extern u32 D_80383444;
extern int D_80383448;
vector(ActorMarker *) *D_80383550;
vector(ActorMarker *) *D_80383554;

/* .code */
bool func_8032BC90(Actor *actor, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp44[3];
    bool sp40;
    s32 phi_v0;
    f32 sp30[3];

    sp40 = actor->marker->propPtr->unk8_3;
    func_8028E964(sp30);

    actor->marker->propPtr->unk8_3 = 0;
    phi_v0 = func_80320B98(&sp30, actor->position, &sp44, actor->unk154);
    if (phi_v0 == 0) {
        phi_v0 = func_80320DB0(actor->position, func_8033229C(actor->marker), &sp44, actor->unk154);
    }

    actor->marker->propPtr->unk8_3 = sp40;
    return (phi_v0)? 1 : 0;
}

void func_8032BD64(f32 arg0[3]){
    ml_vec3f_copy(arg0, D_803833D8);
}

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

extern int func_802E74A0(f32[3], f32, s32, s32);
extern f32 func_802EC920(BKVertexList *);
extern void func_802C39D4(void);
extern bool func_80340020(s32, f32[3], f32[3], f32, s32, BKVertexList *, f32[3], f32[3]);
extern void func_80340200(s32, f32[3], f32[3], f32, s32, s32, BKVertexList *, s32);

extern f64 D_80378EB0;


extern s32 D_80383410;
extern ActorMarker *D_8038341C;
extern s32 D_80383420;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CB50.s")
// extern s32 D_80383450[];

// void func_8032CB50(Cube *cube, s32 arg1) {
//     s32 sp4C[3];
//     // ? *temp_a0;
//     s32 temp_a1;
//     s32 temp_a1_2;
//     s32 temp_a2;
//     s32 temp_a2_2;
//     s32 temp_t6;
//     s32 temp_t7;
//     s32 temp_v0;
//     s32 temp_v0_2;
//     u32 temp_t2;
//     u32 temp_t4;
//     u32 temp_t5;
//     void *temp_v1;
//     Prop *phi_v1;
//     // ? *phi_a0;
//     u32 phi_t2;
//     Prop *phi_a3;
//     Prop *phi_t0;
//     s32 *phi_a0_2;
//     u32 phi_a3_2;
//     Prop *phi_v1_2;
//     u32 phi_a3_3;
//     u32 phi_t1;
//     u32 phi_a3_4;
//     u32 phi_t0_2;
//     s32 i;
//     Prop tmp;

//     if (cube->prop2Cnt < 2U)
//         return;
//     if (arg1 == 0) {
//         func_8024C5F0(sp4C);
//     } else {
//         sp4C[0] = 0;
//         sp4C[1] = 0;
//         sp4C[2] = 0;
//     }
//     phi_v1 = cube->prop2Ptr;
//     phi_t2 = 0U;
//     phi_t1 = cube->prop2Cnt;
//     for(phi_t2 = 0; phi_t2 < cube->prop2Cnt; phi_t2++){
//         temp_v0 = cube->prop2Ptr[phi_t2].actorProp.x - sp4C[0];
//         temp_a1 = cube->prop2Ptr[phi_t2].actorProp.y - sp4C[1];
//         temp_a2 = cube->prop2Ptr[phi_t2].actorProp.z - sp4C[2];
//         D_80383450[phi_t2] = temp_v0*temp_v0 + temp_a1*temp_a1 + temp_a2*temp_a2;
//     }
//     phi_a3 = cube->prop2Ptr;
//     phi_t0 = &cube->prop2Ptr[cube->prop2Cnt - 1];
//     do {
//         phi_a3_2 = 0U;
// //     phi_t0_2 = phi_t0;
//         for(phi_v1_2 = phi_a3; phi_v1_2 < phi_t0; phi_v1_2++){
//             phi_a0_2 = &D_80383450[phi_v1_2 - cube->prop2Ptr];
//             temp_a1_2 = phi_a0_2[0];
//             temp_a2_2 = phi_a0_2[1];
// //             phi_a3_4 = phi_a3_2;
// //             phi_a3_4 = phi_a3_2;
//             if (phi_a0_2[0] < phi_a0_2[1]) {
//                 phi_t0 =  phi_v1_2 + 1;
//                 if (phi_a3_2 != 0) {
//                     phi_t0_2 = (u32) phi_v1_2;
//                 } else {
//                     phi_a3_2 = phi_v1_2 - 1;
//                     if (phi_v1_2 == cube->prop2Ptr) {
//                         phi_a3_4 = (u32) phi_v1_2;
//                     }
//                 }
//                 phi_a0_2[0] = temp_a2_2;
//                 phi_a0_2[0] = temp_a1_2;

//                 tmp = phi_v1_2[0];
//                 phi_v1_2[0] = phi_v1_2[1];
//                 phi_v1_2[1] = tmp;
//             }
// //             temp_v1 = phi_v1_2 + 0xC;
// //             phi_a0_2 += 4;
// //             phi_a3_2 = phi_a3_4;
// //             phi_v1_2 = temp_v1;
// //             phi_a3_3 = phi_a3_4;
// //             phi_t0 = phi_t0_2;
//         }

//         phi_a3 = phi_a3_3;
//     } while (phi_a3_3 != 0);
//     func_80330104(cube);
// }


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032CD60.s")
// void func_8032CD60(Prop *prop){
//     s32 tmp_v0;
//     if(prop->markerFlag){
//         tmp_v0 = func_80330F50(prop->actorProp.marker);
//     }
//     else{
//         tmp_v0 = func_8030A55C(prop->propProp.unk0_31);
//     }

//     if(tmp_v0 == 0) return;

// }

void func_8032D120(Cube *cube){
    if(cube->prop2Cnt >= 2)
        func_8032CB50(cube, 1);
}

void func_8032D158(Cube *cube){
    if(cube->prop2Cnt >= 2)
        func_8032CB50(cube, 0);
}

void __marker_draw(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *actor;
    u32 draw_dist;
    f32 draw_dist_f;
    f32 percentage;
    if(!this->unk3E_0){
        this->unk8(this, gfx, mtx, vtx);
        return;
    }
    actor =  marker_getActor(this);
    func_8033A28C(actor->unk58_2);
    if( actor->unk58_2 && !this->unk40_23 && !this->unk40_21 && !D_8036E7B0){
        func_8033A244(D_80378EA0);
    }
    
    if(actor->unk124_7 && !actor->despawn_flag && actor->unk58_0){
        draw_dist = actor->actor_info->draw_distance;
        if(draw_dist != 0){
            percentage = (f32)draw_dist*(1/(f64)0x400);
        }
        else if(this->unk40_21){
            percentage = 2.0f;
        }
        else{
            percentage = 1.0f;
        }
        func_8033A280(percentage);
        this->unk8(this, gfx, mtx, vtx);
    }//L8032D300
    func_8033A244(D_80378EA4);
    func_8033A280(1.0f);
}

void func_8032D330(void){
    D_80383550 = vector_new(sizeof(ActorMarker *),2);
    D_80383554 = vector_new(sizeof(u32),2);
}

void func_8032D36C(void){
    vector_free(D_80383550);
    D_80383550 = NULL;
    vector_free(D_80383554);
    D_80383554 = NULL;
}

void func_8032D3A8(void){
    vector_clear(D_80383550);
    vector_clear(D_80383554);
}

void func_8032D3D8(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < vector_size(D_80383550); i++){
       __marker_draw(*(u32*) vector_at(D_80383550, i), gdl, mptr, vptr);
    }
}

void func_8032D474(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    int i;
    for(i = 0; i < vector_size(D_80383554); i++){
       __marker_draw(*(u32*) vector_at(D_80383554, i), gdl, mptr, vptr);
    }
}

void func_8032D510(Cube *cube, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Prop *iProp;
    int i;
    f32 sp94[3];
    f32 sp88[3];
    tmp_bitfield tmp_v0;
    int iOffset;
    ActorMarker **markerPtr;

    if(cube->prop2Cnt == 0 ) return;

    func_8032CB50(cube, 0);
    iOffset = 0;
    for(i = 0; i < cube->prop2Cnt; i++){//L8032D5A0
        iOffset = i*0xC;
        iProp = ((s32)cube->prop2Ptr + iOffset);
        tmp_v0.word = *(u32 *)((s32)iProp + 0x8);
        if(!tmp_v0.unk4){
        
        }else{
            if(!tmp_v0.unk1){
                func_8032CD60(iProp);
            }
            tmp_v0.word = *(u32 *)((s32)iProp + 0x8);
            if(tmp_v0.unk0){//actorProp;
                if(iProp->actorProp.marker->unk40_22){
                    markerPtr = (ActorMarker **)vector_pushBackNew(&D_80383550);
                    *markerPtr = iProp->actorProp.marker;
                }
                else if(iProp->actorProp.marker->unk40_19){
                    markerPtr = (ActorMarker **)vector_pushBackNew(&D_80383554);
                    *markerPtr = iProp->actorProp.marker;
                }
                else{
                    __marker_draw(iProp->actorProp.marker, gfx, mtx, vtx);
                }//L8032D62C
            }
            else{//L8032D640
                sp94[0] = (f32)iProp->propProp.unk4[0];
                sp94[1] = (f32)iProp->propProp.unk4[1];
                sp94[2] = (f32)iProp->propProp.unk4[2];
                if(iProp->unk8_1){
                    sp88[0] = 0.0f;
                    sp88[1] = (f32)((s32)iProp->propProp.unk0_15*2);
                    sp88[2] = (f32)((s32)iProp->propProp.unk0_7*2);
                    func_8030A2D0(gfx, mtx, vtx, 
                        sp94, sp88, (f32)iProp->propProp.unkA/100.0,
                        iProp->propProp.unk0_31, cube
                    );
                }
                else{//L8032D72C
                    func_8030A350( gfx, mtx, vtx, 
                        sp94, (f32)iProp->spriteProp.unk0_9/100.0, iProp->spriteProp.unk0_31, cube, 
                        iProp->spriteProp.unk0_18, iProp->spriteProp.unk0_15, iProp->spriteProp.unk0_12,
                        iProp->spriteProp.unk0_1, iProp->spriteProp.unk8_15
                    );
                }
            }//L8032D7C4
        }
        iOffset+=0xC;
    }//L8032D7D4
}

ActorProp *func_8032D80C(Cube *cube) {
    ActorProp *sp1C;

    if (cube->prop2Ptr != NULL) {
        cube->prop2Cnt++;
        cube->prop2Ptr = realloc(cube->prop2Ptr, cube->prop2Cnt * sizeof(Prop));
    } else {
        cube->prop2Cnt = 1;
        cube->prop2Ptr = malloc(sizeof(Prop));
    }
    sp1C = &cube->prop2Ptr[cube->prop2Cnt-1];
    sp1C->unk8_0 = FALSE;
    func_80330104(cube);
    return sp1C;
}

NodeProp *func_8032D8F0(Cube *cube) {
    if (cube->prop1Ptr != 0) {
        cube->prop1Cnt++;
        cube->prop1Ptr = realloc(cube->prop1Ptr, cube->prop1Cnt * sizeof(NodeProp));
    } else {
        cube->prop1Cnt = 1;
        cube->prop1Ptr = malloc(sizeof(NodeProp));
    }
    return &cube->prop1Ptr[cube->prop1Cnt - 1];
}

//cube_removeProp
s32 func_8032D9C0(Cube *cube, Prop* prop){
    s32 sp24;
    s32 tmp;

    sp24 = 0;
    if(cube->prop2Cnt != 0){
        sp24 = prop->unk8_1; 
        if(func_80305D14()){
            func_80305CD8(func_803058C0(prop->unk6), -1);
        }
        if((prop - cube->prop2Ptr) < (cube->prop2Cnt - 1)){
            memcpy(prop, prop + 1, (s32)(&cube->prop2Ptr[cube->prop2Cnt-1]) - (s32)(prop));
        }
        cube->prop2Cnt--;
        if(cube->prop2Cnt){
            cube->prop2Ptr = realloc(cube->prop2Ptr, cube->prop2Cnt*sizeof(Prop));
            func_80330104(cube);
        }else{
            free(cube->prop2Ptr);
            cube->prop2Ptr = NULL;
        }
        return sp24;
    }
    return 0;
}

void func_8032DB2C(Cube *cube, NodeProp *arg1) {
    s32 sp24;

    if(cube->prop1Cnt == NULL)
        return;

    sp24 = arg1 - cube->prop1Ptr;
    if (sp24 < cube->prop1Cnt - 1) {
        memcpy(arg1, arg1 + 1, (s32)&cube->prop1Ptr[cube->prop1Cnt] - (s32)arg1 - sizeof(NodeProp));
    }
    if (sp24 < cube->unk0_4) {
        cube->unk0_4--;
    }

    cube->prop1Cnt--;
    if (cube->prop1Cnt != 0) {
        cube->prop1Ptr = realloc(cube->prop1Ptr, cube->prop1Cnt * sizeof(NodeProp));
    }
    else{
        free(cube->prop1Ptr);
        cube->prop1Ptr = NULL;
        cube->unk0_4 = 0;
    }
}

void func_8032DC70(void) {
    NodeProp *sp1C;
    s32 temp_v0;

    sp1C = func_803080C8();
    if (sp1C != NULL) {
        func_8032DB2C(func_80308224(), sp1C);
    }
}

ActorMarker *func_8032DCAC(void){
    return D_8038341C;
}

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

void cube_free(Cube *cube){
    Prop *iProp;

    if(cube->prop2Ptr){
        for(iProp = cube->prop2Ptr; iProp < cube->prop2Ptr +cube->prop2Cnt; iProp++){
            if(iProp->markerFlag){
                func_80332B2C(iProp->actorProp.marker);
            }
        }
        free(cube->prop2Ptr);
        cube->prop2Ptr = NULL;
    }
    if(cube->prop1Ptr){
        free(cube->prop1Ptr);
        cube->prop1Ptr = NULL;
    }
    cube->prop2Cnt = 0;
    cube->prop1Cnt = 0;
    cube->unk0_4 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E2D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E5A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E6CC.s")

void func_8032E784(Cube *cube, s32 cnt){
    if(cube->prop1Ptr != NULL){
        free(cube->prop1Ptr);
    }
    cube->prop1Cnt = cnt;
    cube->unk0_4 = 0; 
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032E7E8.s")
#else
void func_8032E7E8(NodeProp *node, Cube *cube, s32 cnt) {
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 actor;
    s32 model_cache_ptr;
    u32 temp_t8;
    void *actor_2;
    void *actor_3;
    void *actor_4;
    void *actor_5;
    void *model_cache_ptr_2;
    void *phi_s0;
    NodeProp *iPtr;
    s32 phi_s3;
    s32 phi_s2;
    s32 phi_a0;
    s32 phi_s2_2;
    s32 phi_a0_2;
    void *i;
    void *i_2;
    void *i_3;
    s32 phi_s2_3;
    s32 i;
    s32 val;

    cube->unk0_4 = 0;
    phi_s3 = cnt - 1;
    for(i = 0; i < cnt; i++){
        if( (node[i].unk4_6 == 6) 
            || (node[i].unk4_6 == 8)
            || (node[i].unk4_6 == 7) 
            || (node[i].unk4_6 == 9) 
            || (node[i].unk4_6 == 0xA) 
            || (node[i].unk4_0 == 1)
        ){
            memcpy(&cube->prop1Ptr[phi_s3], &node[i], sizeof(NodeProp));
            phi_s3--;
        } else {
            memcpy(&cube->prop1Ptr[cube->prop1Cnt], &node[i], sizeof(NodeProp));
            cube->unk0_4++;
        }
    }
    free(node);
    
    for(i = 0; i < cnt; i++){
        iPtr = &cube->prop1Ptr[i];
        if(!iPtr->unk4_0){
            iPtr->unk10_6 = TRUE;
        }
    }
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EA24.s")
#else
void func_8032EA24(Struct61s *file_ptr, Cube *cube) {
    u8 sp47;
    u8 sp46;
    s32 sp34;
    s32 sp2C;
    s32 temp_s0_3;
    s32 actor_4;
    s32 actor_5;
    u8 temp_t1;
    NodeProp *temp_a0;
    NodeProp *temp_s0;
    NodeProp *i;
    Prop *i_2;

    cube_free(cube);
    if (func_8034B040(file_ptr, 0xA, sp46)) {
        func_8032E784(cube, sp46);
        cube->prop1Ptr = malloc(sp46 *sizeof(NodeProp));
        temp_s0 = malloc(sp46*sizeof(NodeProp));
        func_8034B080(file_ptr, 0xB, temp_s0, cube->prop1Cnt * sizeof(NodeProp));
        func_8032E7E8(temp_s0, cube, sp46);
    } else if (func_8034B040(file_ptr, 6, sp46)) {
        func_8032E784(cube, sp46);
        cube->prop1Ptr = malloc(sp46 *sizeof(NodeProp));
        temp_s0 = malloc(sp46*sizeof(NodeProp));
        func_8034B080(file_ptr, 7, temp_s0, cube->prop1Cnt * sizeof(NodeProp));
        for(i = temp_s0; i < temp_s0 + sp46; i++){
            if (i->unk4_0 && !i->unkC_0) {
                i->unk4_17 = 0;
                i->unk10_4 = 0;
            }
        }
        func_8032E7E8(temp_s0, cube, sp46);
    }
    if (func_8034B040(file_ptr, 8, &sp47)) {
        temp_s0_3 = func_803203FC(2);
        sp2C = func_803203FC(1);
        sp34 = func_803203FC(0x1F) + sp2C + temp_s0_3;
        if (sp34 != 0) {
            if (func_8031B4CC() != 0) {
                sp34 = 0;
            }
        }
        if (cube->prop2Ptr != 0) {
            free(cube->prop2Ptr);
        }
        cube->prop2Cnt = sp47;
        cube->prop2Ptr = (Prop *) malloc(sp47 * sizeof(Prop));
        func_8034B080(file_ptr, 9, cube->prop2Ptr, cube->prop2Cnt * sizeof(Prop));
        for(i_2 = cube->prop2Ptr; i_2 < cube->prop2Ptr + sp47; i_2++){
            i_2->unk8_4 = 1;
            if(i_2->unk8_1){
                i_2->actorProp.unk8_5 = 0;
            }
            if(sp34){
                if(!i_2->markerFlag && !i_2->unk8_1){
                    switch(i_2->spriteProp.unk0_31 + 0x572){
                        case 0x580:
                        case 0x6D1:
                        case 0x6D6:
                        case 0x6D7:
                            i_2->spriteProp.unk8_4 = 0; 
                            break;
                    }
                }
            }
        }

    }

    if ((cube->prop2Ptr != NULL) && (cube->prop2Cnt == 0)) {
        free(cube->prop2Ptr);
        cube->prop2Ptr = NULL;
    }

    if ((cube->prop1Ptr != NULL) && (cube->prop1Cnt == 0)) {
        free(cube->prop1Ptr);
        cube->prop1Ptr = NULL;
        cube->unk0_4 = 0;
    }
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032EE80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F170.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F194.s")
#else
void func_8032F194(ActorMarker *marker, s32 position[3], Cube *cube) {
    ActorProp sp24;

    ((s32*)&sp24)[2] = ((s32*)marker->propPtr)[2];
    sp24.x = (s16) position[0];
    sp24.y = (s16) position[1];
    sp24.z = (s16) position[2];
    func_8032F21C(cube, position, marker, func_8032D9C0(marker->cubePtr, marker->propPtr));
    ((s32*)marker->propPtr)[1] = ((s32*)&sp24)[1];
    ((s32*)marker->propPtr)[2] = ((s32*)&sp24)[2];
}
#endif

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_8032F21C.s")
#else
void func_8032F21C(Cube *cube, s32 position[3], ActorMarker *marker, bool arg3) {
    ActorProp *sp1C;
    u8 temp_t0;
    u8 temp_t2;
    u8 temp_t6;
    u8 temp_t8;

    sp1C = func_8032D80C(cube);
    sp1C->unk8_0 = TRUE;
    sp1C->x = (s16) position[0];
    sp1C->y = (s16) position[1];
    sp1C->z = (s16) position[2];
    sp1C->marker = marker;
    sp1C->unk8_15 = 0;
    sp1C->unk8_1 = arg3;
    sp1C->unk8_5 = FALSE;

    sp1C->unk8_10 = (func_802E4A08(position)) ? 0xF : (u8)(randf() * 32);
    sp1C->unk8_3 = FALSE;
    sp1C->unk8_2 = FALSE;
    sp1C->unk8_4 = TRUE;
    marker->propPtr = sp1C;
    marker->cubePtr = cube;
    if (func_80305D14()) {
        func_80305CD8(func_803058C0((f32)position[1]), 1);
    }
}
#endif

void func_8032F3D4(s32 arg0[3], ActorMarker *marker, s32 arg2){
    func_8032F21C((marker->unk40_23)? func_8030364C() : func_80303470(arg0), arg0, marker, arg2);
}

void marker_free(ActorMarker *this){
    func_8032D9C0(this->cubePtr, (Prop *)this->propPtr);
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

Prop *func_8032F528(void){
    Prop * prop = func_80303F7C(0, 0, 0, 1);
    if(prop != NULL){
        D_80383448 = TRUE;
    }
    else{
        D_80383448 = FALSE;
    }
    return prop;
}

void func_8032F578(f32 position[3], ActorMarker *marker, f32 arg2, s32 arg3) {
    func_8032F64C(position, marker);
    func_80320ED8(marker, arg2, arg3);
}

void func_8032F5B0(f32 position[3], ActorMarker *marker, f32 arg2, s32 arg3) {
    func_8032F64C(position, marker);
    func_80320EB0(marker, arg2, arg3);
}

void func_8032F5E8(s32 arg0[3], s32 arg1, f32 arg2, s32 arg3) {
    f32 sp1C[3];

    sp1C[0] = arg0[0];
    sp1C[1] = arg0[1];
    sp1C[2] = arg0[2];
    func_8032F5B0(sp1C, arg1, arg2, arg3);
}

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

void func_8032F7EC(f32 position[3], ActorMarker *marker, f32 rotation[3]) {
    marker->yaw  = rotation[1];
    marker->pitch = rotation[0];
    marker->roll = rotation[2];
    func_8032F64C(position, marker);
}

ActorMarker * func_8032F9DC(s32 *pos, MarkerDrawFunc arg1, int arg2, int arg3, int arg4){
    ActorMarker * marker = func_80332A60();
    marker->propPtr = NULL;
    marker->cubePtr = NULL;
    marker->unk8 = arg1;
    marker->unk14_20 = arg3;
    marker->unk40_23 = arg4;
    func_8032F3D4(pos, marker, arg2);
    marker->actrArrayIdx = 0;
    marker->unk14_10 = 0;
    marker->modelId = 0;
    marker->unk3E_1 = 0;
    marker->unk14_22 = 0;
    marker->unk14_21 = 0;
    marker->yaw = 0;
    marker->pitch =  0;
    marker->roll = 0;
    marker->unk2C_2 = 0;
    marker->unk2C_1 = 0;
    marker->collidable = 1;
    marker->unk3E_0 = 0; 
    marker->unk40_22 = 0;
    marker->unk40_19 = 0;
    marker->unk40_21 = 0;
    marker->unkC = NULL;
    marker->unk10 = NULL;
    marker->unk1C = NULL;
    marker->unk54 = NULL;
    marker->unk58 = 0;
    marker->unk18 = 0;
    marker->unk24 = 0;
    marker->unk30 = NULL;
    marker->unk28 = 0;
    marker->unk34 = 0;
    marker->unk38 = 0;
    marker->unk3A = 0;
    marker->unk3C = 0;
    marker->unk44 = 0;
    marker->unk20 = 0;
    marker->unk50 = 0;
    marker->unk48 = 0;
    marker->unk4C = 0;
    marker->unk40_20 = 0;
    marker->unk40_31 = 0;
    return marker;
}

ActorMarker * func_8032FB80(f32 *pos, MarkerDrawFunc arg1, int arg2, enum asset_e model_id, int arg4){
    s32 sp24[3];
    sp24[0] = pos[0];
    sp24[1] = pos[1];
    sp24[2] = pos[2];
    func_8032F9DC(sp24, arg1, arg2, model_id, arg4);
}

ActorMarker * func_8032FBE4(f32 *pos, MarkerDrawFunc arg1, int arg2, enum asset_e model_id){
    return func_8032FB80(pos, arg1, arg2, model_id, 0);
}

void func_8032FC04(ActorMarker *marker, f32 rotation[3]) {
    marker->pitch = rotation[0];
    marker->yaw  = rotation[1];
    marker->roll = rotation[2];
}

void func_8032FDDC(f32 rotation[3], ActorMarker *marker) {
    marker->pitch = rotation[0];
    marker->yaw  = rotation[1];
    marker->roll = rotation[2];
}

int func_8032FFB4(ActorMarker *this, s32 arg1){
    this->unk14_20 = arg1;
}

//marker_setActorArrayIndex
void func_8032FFD4(ActorMarker *this, s32 arg1){
    this->actrArrayIdx = arg1;
}

void func_8032FFEC(ActorMarker *this, s32 arg1){
    this->unk28 = arg1;
}

void func_8032FFF4(ActorMarker *this, ActorMarker *other, s32 type){
    switch(type){
        case 0: //ow
            if(this->unkC)
                this->unkC(this, other); 
            break;
        case 1:
            if(this->unk10)
                this->unk10(this, other);
            break;
        case 2: //die
            if(this->unk1C)
                this->unk1C(this, other);
            break;
    }
}

void func_80330078(ActorMarker *marker){
    if(marker != NULL && marker->unk54 != NULL){
        marker->unk54(marker);
    }
}

//marker_setCollisionMethods
void marker_setCollisionScripts(ActorMarker *this, MarkerCollisionFunc ow_func, MarkerCollisionFunc arg2, MarkerCollisionFunc die_func){
    this->unkC = ow_func;
    this->unk10 = arg2;
    this->unk1C = die_func;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300D8.s")

#define AssetCacheSize 0x3D5

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803300E0.s")

//marker_setModelId
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

    modelCache = (ModelCache *)malloc(AssetCacheSize * sizeof(ModelCache));
    for(i = 0; i<AssetCacheSize; i++){
        modelCache[i].modelPtr = NULL;
        modelCache[i].unk4 = 0;
        modelCache[i].unk8 = 0;
        modelCache[i].unkC = 0;
    }
    D_80383444 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803306C8.s")

extern void *func_802EBAE0(UNK_TYPE(s32), f32 position[3], f32 rotation[3], f32 scale, UNK_TYPE(s32), UNK_TYPE(s32), UNK_TYPE(s32), f32, UNK_TYPE(s32));
BKModelBin *func_80330DE4(ActorMarker *this);

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803308A0.s")
#else
void func_803308A0(void){
    s32 i = 0;
    do{
        if(modelCache[i].modelPtr){
            assetcache_release(modelCache[i].modelPtr);
            modelCache[i].modelPtr = NULL;
        }
        if(modelCache[i].unk4){
            func_8033B388(&modelCache[i].unk4, &modelCache[i].unk8);
        }
        if(modelCache[i].unkC){
            func_80349CD8(modelCache[i].unkC);
            modelCache[i].unkC = NULL;
        }
        i++;
    }while(i < AssetCacheSize);
    free(modelCache);
    modelCache = NULL;
}
#endif

s32 func_80330974(ActorMarker *marker, s32 arg1, f32 arg2, s32 arg3) {
    BKModelBin *model;
    s32 sp58;
    f32 position[3];
    f32 rotation[3];
    f32 scale;


    model = func_80330DE4(marker);
    if (model == NULL) {
       return 0;
    }
    sp58 = func_8033A12C(model);
    position[0] = (f32) marker->propPtr->x;
    position[1] = (f32) marker->propPtr->y;
    position[2] = (f32) marker->propPtr->z;

    rotation[0] = (f32)marker->pitch;
    rotation[1] = (f32)marker->yaw;
    rotation[2] = (f32)marker->roll;

    scale = (marker->unk3E_0) ? marker_getActor(marker)->scale : 1.0f;
    if (func_802EA190(marker->unk20)) {
        return func_802EBAE0(sp58, position, rotation, scale, 0, marker->unk20, arg1, arg2, arg3);
    }
    return 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330B10.s")

//marker_loadModelBin
BKModelBin *func_80330B1C(ActorMarker *this){
    Actor* thisActor;
    BKModelBin * model;
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

s32 func_80330C48(Actor *actor){
    ModelCache *model_cache_ptr = &modelCache[actor->modelCacheIndex];
    return model_cache_ptr->unkC;
}

BKVertexList *func_80330C74(Actor *actor){
    ModelCache *model_cache_ptr;
    model_cache_ptr = &modelCache[actor->modelCacheIndex];
    if(model_cache_ptr->modelPtr == NULL)
        return NULL;

    if(actor->unkF4_30 && actor->unk14C[actor->unkF4_29]){
        return actor->unk14C[actor->unkF4_29];
    }else{
        return func_8033A148(model_cache_ptr->modelPtr);
    }
}

BKVertexList *func_80330CFC(Actor *this, s32 arg1){
    ModelCache *model_cache_ptr;
    model_cache_ptr = &modelCache[this->modelCacheIndex];
    if(model_cache_ptr->modelPtr == NULL){
        func_80330B1C(this->marker);
    }
    if(this->unkF4_30 && this->unk14C[this->unkF4_29 ^ arg1] != NULL)
        return this->unk14C[this->unkF4_29 ^ arg1];
    return func_8033A148(model_cache_ptr->modelPtr);
}

BKVertexList * func_80330DA4(Actor *this){
    return func_80330CFC(this, 0);
}

BKVertexList * func_80330DC4(Actor *this){
    return func_80330CFC(this, 1);
}

BKModelBin *func_80330DE4(ActorMarker *this){
    Actor *thisActor = marker_getActor(this);
    return (modelCache + thisActor->modelCacheIndex)->modelPtr;
}

BKModelBin *func_80330E28(Actor* this){
    return (modelCache + this->modelCacheIndex)->modelPtr;
}

BKSpriteDisplayData *func_80330E54(ActorMarker *marker, BKSprite **sprite_ptr) {
    ModelCache *model_cache_ptr;

    if (marker->modelId == 0) {
        if (*sprite_ptr != NULL) {
            *sprite_ptr = NULL;
        }
        return 0;
    }
    model_cache_ptr = &modelCache[marker_getActor(marker)->modelCacheIndex];
    if (model_cache_ptr->unk4 == 0) {
        model_cache_ptr->unk4 = func_8033B6C4(marker->modelId, &model_cache_ptr->unk8);
    }
    model_cache_ptr->unk10 = func_8023DB5C();
    if (sprite_ptr != NULL) {
        *sprite_ptr = model_cache_ptr->unk4;
    }
    return model_cache_ptr->unk8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F30.s")


BKSprite *func_80330F50(ActorMarker * marker){
    BKSprite *sp1C;
    func_80330E54(marker, &sp1C);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330F94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80330FC4.s")

void func_80330FCC(ActorMarker *marker, s32 arg1[3]){
    arg1[0] = marker->propPtr->x;
    arg1[1] = marker->propPtr->y;
    arg1[2] = marker->propPtr->z;
}

void func_80330FF4(void){
    Actor *phi_s0;
    f32 sp48[3];
    f32 scale[3];

    if(func_80334904() == 1)
        return;
    
    if(D_8038341C != NULL){
        phi_s0 = marker_getActor(D_8038341C);
        player_getPosition(sp48);
        scale[0] = phi_s0->pitch;
        scale[1] = phi_s0->yaw;
        scale[2] = phi_s0->roll;
        func_80340200(D_8038341C->unk50, phi_s0->position, scale, 1.0f, NULL, D_80383420, func_80330DA4(phi_s0), &D_80383410);
    }//L8033108C

    func_802C39D4();
    if(D_8038341C != NULL){
        phi_s0 = marker_getActor(D_8038341C);
        player_getPosition(sp48);
        scale[0] = phi_s0->pitch;\
        scale[1] = phi_s0->yaw;\
        scale[2] = phi_s0->roll;
        if(func_80340020(D_8038341C->unk50, phi_s0->position, scale, 1.0f, NULL, func_80330DC4(phi_s0), sp48, sp48)){
            sp48[1] -= 10.0f;
            func_8028FAB0(sp48);
        }
    }
    if(D_8038341C != NULL){
        D_8038341C = NULL;
    }
    //L80331144
}

bool func_80331158(ActorMarker *arg0, s32 arg1, s32 arg2) {
    Actor *actor;
    u32 temp_a0;

    actor = marker_getActor(arg0);
    if ((actor->unk3C & 0x400) && ((s32)actor->unk3C << 4) >= 0){
        return func_802E74A0(actor->position, actor->unk178 * D_80378EB0, arg1, arg2) == 0;
    }
    return FALSE;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803311D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80331638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803319C0.s")

f32 func_80331D20(BKSprite *sprite) {
    BKSpriteFrame *frame;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 phi_v0;

    if (sprite == 0) {
        return 1.0f;
    }
    frame = spriteGetFramePtr(sprite, 0);
    temp_lo =   (s32) (((frame->unk10 - frame->unkC) + 1) * sprite->unk8) / (s32) frame->w;
    temp_lo_2 = (s32) (((frame->unk12 - frame->unkE) + 1) * sprite->unkA) / (s32) frame->h;
    phi_v0 = (temp_lo_2 < temp_lo) ? temp_lo : temp_lo_2;
    return (phi_v0 <= 0) ? 1 : phi_v0;
}


f32 func_80331E34(u32 *arg0){
    return func_80331D20(func_8030A55C(arg0[0] >> 0x14));
}

f32 func_80331E64(ActorMarker *marker) {
    f32 sp24;

    if (marker->modelId == 0) {
        return 0.0f;
    }
    sp24 = func_80331D20(func_80330F50(marker));
    marker->unk3A = (s16) (sp24 / 2);
    if (marker->unk3E_0) {
        marker->unk3A *= marker_getActor(marker)->scale;
    }
    return sp24;
}


f32 func_80331F1C(u32 *arg0){
    return func_802EC920(func_8033A148(func_8030A428(arg0[0] >> 0x14)));
}

f32 func_80331F54(ActorMarker *marker) {
    f32 sp34;
    f32 sp28[3];
    BKModelBin *model;

    model = func_80330B1C(marker);
    if (model == NULL) {
        return 1.0f;
    }
    func_802EC930(func_8033A148(model), sp28, &sp34);
    if (marker->unk3E_0) {
        sp28[0] = sp28[0] * marker_getActor(marker)->scale;\
        sp28[1] = sp28[1] * marker_getActor(marker)->scale;\
        sp28[2] = sp28[2] * marker_getActor(marker)->scale;
    }
    marker->unk38 = (s16) sp28[0];\
    marker->unk3A = (s16) sp28[1];\
    marker->unk3C = (s16) sp28[2];
    return sp34 * 2;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332050.s")

f32 func_803320BC(ActorProp *prop, f32 (*arg1)(ActorMarker *)) {
    ActorMarker *marker;
    f32 sp18;

    marker = prop->marker;
    sp18 = (f32)marker->unk14_10;
    if (sp18 == 0.0f) {
        sp18 = marker->unk14_10 = arg1(marker) * 0.5;
    }
    if (marker->unk3E_0) {
        sp18 *= marker_getActor(marker)->scale;
    }
    return sp18;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_80332220.s")

f32 func_8033229C(ActorMarker *marker) {
    ActorProp *prop;

    prop = marker->propPtr;
    if (prop->unk8_1) {
        return func_803320BC(prop, func_80331F54);
    }
    else{
        return func_803320BC(prop, func_80331E64);
    }
}

extern u8 *D_8036E7C4;
extern ActorMarker *D_8036E7C8;
extern s16 D_8036E7E0[];
extern s16 D_8036E7FC[];
//extern s32 D_8036E800;
// extern u32 D_8036E804[8];

extern u8 D_80383428[0x1C];

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_A4D00/func_803322F0.s")

void func_80332764(s32 arg0, s32 arg1) {
    u8 *actor;

    D_8036E7C4[arg0 >> 2] |= arg1 << ((arg0 & 3) * 2);
}

void func_80332790(s32 arg0){
    D_8036E7C4[arg0 >> 2] = 0;
}

s32 func_803327A8(s32 arg0) {
    return ((s32) D_8036E7C4[arg0 >> 2] >> ((arg0 & 3) * 2)) & 3;
}

void func_803327D4(s16 *arg0, s32 arg1) {
    s32 i;

    for(i = 0; arg0[i] != -1; i++){
        func_80332764(arg0[i], arg1);
    }
}

void func_8033283C(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    for(i = arg0; i < arg1; i++){
        func_80332764(i, arg2);
    }
}

void func_80332894(void) {
    s32 size;
    s32 i;

    size = 0x579;
    D_8036E7C4 = malloc(size);
    i = 0;
    do{
        D_8036E7C4[i] = 0;
        i++;
    }while(i != size);
    func_8033283C(0x34D, 0x3A6, 3);
    func_8033283C(0x3A6, 0x572, 3);
    func_803327D4(&D_8036E7E0, 1);
    func_803327D4(&D_8036E7FC, 2);
    func_8032D330();
}

void func_8033297C(void){
    free(D_8036E7C4);
    D_8036E7C4 = NULL;
    func_8032D36C();
}

//MarkerList_Init
void func_803329AC(void){
    s32 i;
    
    D_8036E7C8 = (ActorMarker *)malloc(0xE0*sizeof(ActorMarker));

    for( i = 0; i < 0x1C; i++){
        D_80383428[i] = 0;
    }
       
    for(i =0; i<0xE0; i++){
        D_8036E7C8[i].unk5C = 0;
    }
}

void func_80332A38(void){
    free(D_8036E7C8);
    D_8036E7C8 = NULL;
}

//MarkerList_getFreeMarker
ActorMarker * func_80332A60(void){
    static s32 D_8036E800 = 0x387FB;
    int i;
    int j;
    int tmp_a2;
    ActorMarker *marker;

    for(i = 0; i < 0x1C && D_80383428[i] == 0xff; i++);
    if(i == 0x1C)
        return NULL;

    tmp_a2 = 0x80;
    for(j = 0; D_80383428[i] & tmp_a2; j++){tmp_a2 >>= 1;}
    D_80383428[i] |= tmp_a2;
    marker = D_8036E7C8 + 8*i + j;
    marker->unk5C = D_8036E800;
    D_8036E800++;
    return marker;
}

void func_80332B2C(ActorMarker * arg0){
    static s32 D_8036E804[8] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

    s32 index = (arg0 - D_8036E7C8);
    arg0->unk5C = 0;
    D_80383428[index >> 3] =  D_80383428[index >> 3] & D_8036E804[index & 7];
}

void func_80332B7C(void){
    return;
}
