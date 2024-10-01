#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "model.h"

extern void func_80252C08(f32[3],f32[3], f32, f32[3]);
extern void func_80252CC4(f32[3],s32, f32, s32);
extern f32  func_802560D0(f32[3], f32[3], f32[3]);
extern f32  vtxList_getGlobalNorm(BKVertexList *);
extern void points_to_boundingBoxWithMargin(f32 arg0[3], f32 arg1[3], f32 margin, f32 min[3], f32 max[3]);

#define ABS_F(s) (((s) >= 0.0f) ? (s) : -(s))

typedef struct {
    f32 edgeAB[3]; 
    f32 edgeAC[3]; 
    f32 normal[3];
    BKCollisionTri *tri_ptr;
    f32 tri_coord[3][3];
}Struct_core2_5FD90_0;


/* .bss */
struct { 
    BKCollisionGeo *unk0[100];
    BKCollisionGeo **unk190;
}D_8037E910;
f32 D_8037EAA8[3][3];
Struct_core2_5FD90_0 D_8037EAD0[100];

/* .code */
void func_802E6D20(BKCollisionTri *arg0, BKVertexList *vtx_list) {
    Vtx *vtx;
    Vtx *i_vtx;
    s32 i;

    vtx = (Vtx *)(vtx_list + 1);
    
    if (arg0 == NULL) 
        return;

    for(i = 0; i < 3; i++){
        i_vtx = vtx + arg0->unk0[i];
        D_8037EAA8[i][0] = (f32) i_vtx->v.ob[0];
        D_8037EAA8[i][1] = (f32) i_vtx->v.ob[1];
        D_8037EAA8[i][2] = (f32) i_vtx->v.ob[2];
    }
    
}

void collisionList_getIntersecting(BKCollisionList *collision_list, f32 arg1[3], f32 arg2[3], BKCollisionGeo ***arg3, BKCollisionGeo ***arg4) {
    s32 sp3C[3];
    s32 sp30[3];

    s32 i;
    s32 x, y, z;

    if (collision_list->unk12 == 0) {
        D_8037E910.unk190 = &D_8037E910.unk0[0];
        *(D_8037E910.unk190++) = (s32)collision_list + sizeof(BKCollisionList);
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
    else{
        for(i = 0 ;  i < 3; i++){
            if (arg1[i] >= 0.0f) {
                sp3C[i] = (s32) arg1[i] / collision_list->unk12;
            } else {
                sp3C[i] = ((s32) arg1[i] / collision_list->unk12) - 1;
            }

            if (arg2[i] >= 0.0f) {
                sp30[i] = (s32) arg2[i] / collision_list->unk12;
            } else {
                sp30[i] = ((s32) arg2[i] / collision_list->unk12) - 1;
            }

            if (sp3C[i] < collision_list->unk0[i]) {
                sp3C[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp3C[i]) {
                sp3C[i] = collision_list->unk6[i];
            }

            if (sp30[i] < collision_list->unk0[i]) {
                sp30[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp30[i]) {
                sp30[i] = collision_list->unk6[i];
            }

            sp3C[i] -= collision_list->unk0[i];
            sp30[i] -= collision_list->unk0[i];
        }

        D_8037E910.unk190 = &D_8037E910.unk0[0];
        for(z = sp3C[2]; z <= sp30[2]; z++){
            for(y = sp3C[1]; y <= sp30[1]; y++){
                for(x = sp3C[0]; x <= sp30[0]; x++){
                    *(D_8037E910.unk190++) = ((collision_list->unkE * z) + (BKCollisionGeo *)(collision_list + 1))  + x + (y * collision_list->unkC);
                }
            }
        }
        *arg3 = &D_8037E910.unk0[0];
        *arg4 = D_8037E910.unk190;
    }
}

void func_802E70FC(BKCollisionList *collision_list, s32 min[3], s32 max[3], BKCollisionGeo ***begin_geo_ptr, BKCollisionGeo ***end_geo_ptr) {
    s32 sp3C[3];
    s32 sp30[3];

    s32 i;
    s32 x, y, z;

    if (collision_list->unk12 == 0) {
        D_8037E910.unk190 = &D_8037E910.unk0[0];
        *(D_8037E910.unk190++) = (s32)collision_list + sizeof(BKCollisionList);
        *begin_geo_ptr = &D_8037E910.unk0[0];
        *end_geo_ptr = D_8037E910.unk190;
    }
    else{
        for(i = 0 ;  i < 3; i++){
            if (min[i] >= 0) {
                sp3C[i] = (s32) min[i] / collision_list->unk12;
            } else {
                sp3C[i] = ((s32) min[i] / collision_list->unk12) - 1;
            }

            if (max[i] >= 0) {
                sp30[i] = (s32) max[i] / collision_list->unk12;
            } else {
                sp30[i] = ((s32) max[i] / collision_list->unk12) - 1;
            }

            if (sp3C[i] < collision_list->unk0[i]) {
                sp3C[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp3C[i]) {
                sp3C[i] = collision_list->unk6[i];
            }

            if (sp30[i] < collision_list->unk0[i]) {
                sp30[i] = collision_list->unk0[i];
            }
            if (collision_list->unk6[i] < sp30[i]) {
                sp30[i] = collision_list->unk6[i];
            }

            sp3C[i] -= collision_list->unk0[i];
            sp30[i] -= collision_list->unk0[i];
        }

        D_8037E910.unk190 = &D_8037E910.unk0[0];
        
        for(z = sp3C[2]; z <= sp30[2]; z++){
            for(y = sp3C[1]; y <= sp30[1]; y++){
                for(x = sp3C[0]; x <= sp30[0]; x++){
                    *(D_8037E910.unk190++) = ((collision_list->unkE * z) + (BKCollisionGeo *)(collision_list + 1))  + x + (y * collision_list->unkC);
                }
            }
        }
        *begin_geo_ptr = &D_8037E910.unk0[0];
        *end_geo_ptr = D_8037E910.unk190;
    }
}

void func_802E73C8(f32 arg0[3][3]) {
    s32 i;
    for(i = 0; i < 3; i++){
        arg0[i][0] = D_8037EAA8[i][0]; 
        arg0[i][1] = D_8037EAA8[i][1]; 
        arg0[i][2] = D_8037EAA8[i][2]; 

    }
}

s32 func_802E7408(BKCollisionList *collisionList) {
    BKCollisionTri *temp_a1;
    BKCollisionTri *temp_a2;
    BKCollisionTri *phi_a2;
    s32 phi_v1;

    phi_v1 = 0;
    temp_a2 = (collisionList->unk10 * 4) + (s32)collisionList + sizeof(BKCollisionList);
    temp_a1 = (collisionList->unk14 * 0xC) + (s32)temp_a2;
    for(phi_a2 = temp_a2; phi_a2 < temp_a1; phi_a2++){
        if(phi_a2->flags & 0x1E0000){
            phi_v1++;
        }
    }
    return phi_v1;
}

s32 func_802E7468(BKCollisionList *collisionList){
    return collisionList->unk14;
}

void collisionList_getTris(BKCollisionList *collision_list, BKCollisionTri **begin_ptr, BKCollisionTri **end_ptr){
    *begin_ptr = (collision_list->unk10 * 4) + (s32)collision_list + sizeof(BKCollisionList);
    *end_ptr = (collision_list->unk14 * 0xC) + (s32)*begin_ptr;
}


bool func_802E74A0(f32 arg0[3], f32 arg1, f32 arg2[3], f32 arg3[3]) {
    f32 sp24[3];
    f32 sp20;

    if (arg1 <= func_802560D0(arg2, arg3, arg0)) {
        return FALSE;
    }
    sp24[0] = (arg2[0] + arg3[0]) / 2;
    sp24[1] = (arg2[1] + arg3[1]) / 2;
    sp24[2] = (arg2[2] + arg3[2]) / 2;
    sp20 = ml_distance_vec3f(sp24, arg0);
    if ((ml_distance_vec3f(sp24, arg2) + arg1) <= sp20) {
        return FALSE;
    }
    return TRUE;
}

bool func_802E7588(f32 arg0[3], f32 arg1, f32 arg2[3], f32 arg3) {
    return (ml_distance_vec3f(arg0, arg2) < (arg1 + arg3));
}

void calculateBoundsAndDirection(f32 startPoint[3], f32 endPoint[3], s32 minBounds[3], s32 maxBounds[3], f32 directionVector[3]) {
    s32 i;

    for(i = 0; i < 3; i++){
        if (startPoint[i] < endPoint[i]) {
            minBounds[i] = (s32) startPoint[i];
            maxBounds[i] = (s32) endPoint[i];
        }
        else {
            minBounds[i] = (s32) endPoint[i];
            maxBounds[i] = (s32) startPoint[i];
        }

        minBounds[i] += -1;
        maxBounds[i] += 1;
    }

    directionVector[0] = (endPoint[0] - startPoint[0]);
    directionVector[1] = (endPoint[1] - startPoint[1]);
    directionVector[2] = (endPoint[2] - startPoint[2]);
}

BKCollisionTri *func_802E76B0(BKCollisionList *collisionList, BKVertexList *vertexList, f32 startPoint[3], f32 endPoint[3], f32 arg4[3], u32 flagFilter) {
    s32 i;
    s32 j;
    BKCollisionGeo **start_geo;
    BKCollisionGeo **i_geo;
    BKCollisionGeo **end_geo;
    BKCollisionTri *start_tri;
    BKCollisionGeo *temp_v1;
    BKCollisionTri *end_tri;
    BKCollisionTri *i_tri;
    Vtx *vtx_pool;
    Vtx *sp164[3];
    s32 min_bounds[3];
    s32 max_bounds[3];
    f32 direction_vector[3];
    Vtx *temp_a2;
    f32 sp130[3];
    f32 sp124[3];
    f32 sp118[3];
    f32 sp10C[3];
    f32 temp_f0_2;
    f32 spFC[3];
    f32 spF0[3];
    f32 spE4[3];

    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f14_2;
    f32 temp_f20;
    f32 temp_f2_2;
    f32 temp_f2_6;
    f32 spBC[3];

    s32 phi_a0_2;
    f32 pad;
    f32 sp90[3][3];
    BKCollisionTri *result_collision;

    result_collision = NULL;
    temp_f20 = (f32) vertexList->global_norm;
    calculateBoundsAndDirection(startPoint, endPoint, min_bounds, max_bounds, direction_vector);
    for(i = 0; i < 3; i++){
        if ((max_bounds[i] <= -temp_f20) || (temp_f20 <= min_bounds[i])) {
            return NULL;
        }
    }
    func_802E70FC(collisionList, min_bounds, max_bounds, &start_geo, &end_geo);
    for(i_geo = start_geo; i_geo < end_geo; i_geo++){
        start_tri = (BKCollisionTri *)((BKCollisionGeo *)(collisionList + 1) + collisionList->unk10) + (*i_geo)->start_tri_index;
        end_tri = start_tri + (*i_geo)->tri_count;
        for(i_tri = start_tri; i_tri < end_tri; i_tri++){
            vtx_pool = (Vtx*)(vertexList + 1);
            if((i_tri->flags & flagFilter))
                continue;

            sp164[0] = &vtx_pool[i_tri->unk0[0]]; 
            sp164[1] = &vtx_pool[i_tri->unk0[1]]; 
            sp164[2] = &vtx_pool[i_tri->unk0[2]];
            if((sp164[0]->v.ob[0] < min_bounds[0]) && (sp164[1]->v.ob[0] < min_bounds[0]) && (sp164[2]->v.ob[0] < min_bounds[0])) continue;
            if((max_bounds[0] < sp164[0]->v.ob[0]) && (max_bounds[0] < sp164[1]->v.ob[0]) && (max_bounds[0] < sp164[2]->v.ob[0])) continue;
            
            if((sp164[0]->v.ob[2] < min_bounds[2]) && (sp164[1]->v.ob[2] < min_bounds[2]) && (sp164[2]->v.ob[2] < min_bounds[2])) continue;
            if((max_bounds[2] < sp164[0]->v.ob[2]) && (max_bounds[2] < sp164[1]->v.ob[2]) && (max_bounds[2] < sp164[2]->v.ob[2])) continue;
            
            if((sp164[0]->v.ob[1] < min_bounds[1]) && (sp164[1]->v.ob[1] < min_bounds[1]) && (sp164[2]->v.ob[1] < min_bounds[1])) continue;
            if((max_bounds[1] < sp164[0]->v.ob[1]) && (max_bounds[1] < sp164[1]->v.ob[1]) && (max_bounds[1] < sp164[2]->v.ob[1])) continue;

            for(i = 0; i < 3; i++){
                temp_a2 = &vtx_pool[i_tri->unk0[i]];
                for(j = 0; j <3; j++){
                    sp90[i][j] = temp_a2->v.ob[j];
                }
            }
            sp130[0] = sp90[1][0] - sp90[0][0];
            sp130[1] = sp90[1][1] - sp90[0][1];
            sp130[2] = sp90[1][2] - sp90[0][2];

            sp124[0] = sp90[2][0] - sp90[0][0];
            sp124[1] = sp90[2][1] - sp90[0][1];
            sp124[2] = sp90[2][2] - sp90[0][2];

            spBC[0] = (sp130[1] * sp124[2]) - (sp130[2] * sp124[1]);
            spBC[1] = (sp130[2] * sp124[0]) - (sp130[0] * sp124[2]);
            spBC[2] = (sp130[0] * sp124[1]) - (sp130[1] * sp124[0]);
            if( (100000.0f < spBC[0]) || (100000.0f < spBC[1]) || (100000.0f < spBC[2]) 
                || (spBC[0] < -100000.0f) || (spBC[1] < -100000.0f) || (spBC[2] < -100000.0f)
            ) {
                spBC[0] /= 100000.0f;
                spBC[1] /= 100000.0f;
                spBC[2] /= 100000.0f;
            }

            sp118[0] = startPoint[0] - sp90[0][0];
            sp118[1] = startPoint[1] - sp90[0][1];
            sp118[2] = startPoint[2] - sp90[0][2];

            sp10C[0] = endPoint[0] - sp90[0][0];
            sp10C[1] = endPoint[1] - sp90[0][1];
            sp10C[2] = endPoint[2] - sp90[0][2];

            temp_f12_2 = sp118[0]*spBC[0] + sp118[1]*spBC[1] + sp118[2]*spBC[2];
            temp_f2_2 = sp10C[0]*spBC[0] + sp10C[1]*spBC[1] + sp10C[2]*spBC[2];
            pad = temp_f2_2;
            if ((!((temp_f12_2 >= 0.0f) && (pad >= 0.0f))))
            if( !((temp_f12_2 <= 0.0f) && (pad <= 0.0f))) {
                if ((i_tri->flags & 0x10000) && (temp_f12_2 < 0.0f)) {
                    spBC[0] = -spBC[0];
                    spBC[1] = -spBC[1];
                    spBC[2] = -spBC[2];
                }
                
                temp_f12_3 = spBC[0]*direction_vector[0] + spBC[1]*direction_vector[1] + spBC[2]*direction_vector[2];
                pad = (sp90[0][0]*spBC[0] + sp90[0][1]*spBC[1] + sp90[0][2]*spBC[2]);
                if (temp_f12_3 == 0.0f) 
                    continue;
                
                temp_f0_2 = -((spBC[0]*startPoint[0] + spBC[1]*startPoint[1] + spBC[2]*startPoint[2]) - pad)/ temp_f12_3;
                if(temp_f0_2 <= 0.0f || 1.0f <= temp_f0_2)
                    continue;
                
                spFC[0] = startPoint[0] + (direction_vector[0] * temp_f0_2);
                spFC[1] = startPoint[1] + (direction_vector[1] * temp_f0_2);
                spFC[2] = startPoint[2] + (direction_vector[2] * temp_f0_2);

                phi_a0_2 = (ABS_F(spBC[0]) > ABS_F(spBC[1])) ? 0 : 1;
                phi_a0_2 = (ABS_F(spBC[2]) > ABS_F(spBC[phi_a0_2])) ? 2 : phi_a0_2;
                
                spF0[0] = spFC[(phi_a0_2 + 1) % 3] - sp90[0][(phi_a0_2 + 1) % 3];
                spF0[1] = sp130[(phi_a0_2 + 1) % 3];
                spF0[2] = sp124[(phi_a0_2 + 1) % 3];
                
                spE4[0] = spFC[(phi_a0_2 + 2) % 3] - sp90[0][(phi_a0_2 + 2) % 3];
                spE4[1] = sp130[(phi_a0_2 + 2) % 3];
                spE4[2] = sp124[(phi_a0_2 + 2) % 3];
                temp_f14_2 = ((spF0[1] * spE4[2]) - (spE4[1] * spF0[2]));
                
                temp_f12_4 = ((spF0[0] * spE4[2]) - (spE4[0] * spF0[2])) / temp_f14_2;
                if(temp_f12_4 < 0.0f || 1.0f < temp_f12_4) 
                    continue;
                
                temp_f2_6 =  ((spF0[1] * spE4[0]) - (spE4[1] * spF0[0])) / temp_f14_2;
                if(temp_f2_6 < 0.0f || 1.0f < temp_f2_6)   
                    continue;
                
                if(1.0f < (temp_f12_4 + temp_f2_6))        
                    continue;

                result_collision = i_tri;
                endPoint[0] = spFC[0];
                endPoint[1] = spFC[1];
                endPoint[2] = spFC[2];
                ml_vec3f_normalize_copy(arg4, spBC);
                calculateBoundsAndDirection(startPoint, endPoint, min_bounds, max_bounds, direction_vector);
            }
            
        }
    }
    func_802E6D20(result_collision, vertexList);
    return result_collision;
}

int func_802E805C(BKCollisionList *collision_list, BKVertexList *vtxList, f32 arg2[3], f32 arg3[3], f32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8){
    f32 sp44[3];
    f32 sp38[3];
    int sp34;
    int i;

    if(!func_802E74A0(arg2, vtxList->global_norm*arg4, arg5, arg6)){
        return 0;
    }
    else{
        mlMtxIdent();
        func_80252CC4(arg2, arg3, arg4, 0);
        mlMtx_apply_vec3f(sp44, arg5);
        mlMtx_apply_vec3f(sp38, arg6);
        sp34 = func_802E76B0(collision_list, vtxList, sp44, sp38, arg7, arg8);
        if(!sp34){
            return 0;
        }
        else{
            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, NULL);
            mlMtx_apply_vec3f(arg6, sp38);

            mlMtxIdent();
            func_80252C08(NULL, arg3, 1.0f, 0);
            mlMtx_apply_vec3f(arg7, arg7);

            mlMtxIdent();
            func_80252C08(arg2, arg3, arg4, 0);

            for(i = 0; i < 3; i++){
                mlMtx_apply_vec3f(D_8037EAA8[i], D_8037EAA8[i]);
            }

        }
    }
    return sp34;
}

s32 func_802E81CC(BKCollisionList *collisionList, BKVertexList *vertexList, f32 p1[3], f32 p2[3], f32 velocity[3], f32 margin, s32 flagFilter, s32 **activeTriStartPtr, s32 *activeTriEndPtr) {
    BKCollisionGeo **start_geo;
    BKCollisionGeo **i_geo;
    BKCollisionGeo **end_geo;
    f32 spC0[3];
    BKCollisionTri *start_tri;
    BKCollisionTri *end_tri;
    f32 min[3];
    f32 max[3];
    BKCollisionTri *i_tri;
    Vtx *vertex_pool;
    Vtx *i_vtx;
    s32 i;
    s32 j;
    f32 tri_min_coord[3];
    f32 tri_max_coord[3];
    Struct_core2_5FD90_0 *var_s2;
    f32 temp_f0;


    points_to_boundingBoxWithMargin(p1, p2, margin, min, max);
    temp_f0 = vtxList_getGlobalNorm(vertexList);
    for(i = 0; i < 3; i++){
        if ((max[i] <= -temp_f0) || (temp_f0 <= min[i])) {
            return 0;
        }
    }
    collisionList_getIntersecting(collisionList, min, max, &start_geo, &end_geo);
    vertex_pool = vtxList_getVertices(vertexList);
    var_s2 = D_8037EAD0;
    for(i_geo = start_geo; i_geo < end_geo; i_geo++){
        start_tri = (BKCollisionTri *)((BKCollisionGeo *)(collisionList + 1) + collisionList->unk10) + (*i_geo)->start_tri_index;
        end_tri = start_tri + (*i_geo)->tri_count;
        for(i_tri = start_tri; i_tri < end_tri; i_tri++){
            if (!(i_tri->flags & flagFilter)) {
                for(i = 0; i < 3; i++){
                    i_vtx = vertex_pool + i_tri->unk0[i];
                    for(j = 0; j < 3; j++){
                        var_s2->tri_coord[i][j] = i_vtx->v.ob[j];
                    }
                }

                //get min/max bounds of triangle
                tri_min_coord[0] = var_s2->tri_coord[0][0];\
                tri_min_coord[1] = var_s2->tri_coord[0][1];\
                tri_min_coord[2] = var_s2->tri_coord[0][2];
                    
                tri_max_coord[0] = var_s2->tri_coord[0][0];\
                tri_max_coord[1] = var_s2->tri_coord[0][1];\
                tri_max_coord[2] = var_s2->tri_coord[0][2];

                for(i = 1; i < 3; i++){
                    for(j = 0; j < 3; j++){
                        if (var_s2->tri_coord[i][j] < tri_min_coord[j]) {
                            tri_min_coord[j] = var_s2->tri_coord[i][j];
                        }
    
                        if (tri_max_coord[j] < var_s2->tri_coord[i][j]) {
                            tri_max_coord[j] = var_s2->tri_coord[i][j];
                        }
                    }
                }
    
                //check if tri intersects region
                if ((max[0] < tri_min_coord[0]) || (tri_max_coord[0] < min[0])) continue;
                if ((max[1] < tri_min_coord[1]) || (tri_max_coord[1] < min[1])) continue;
                if ((max[2] < tri_min_coord[2]) || (tri_max_coord[2] < min[2])) continue;
    
                //calculate normal of tri
                var_s2->edgeAB[0] = var_s2->tri_coord[1][0] - var_s2->tri_coord[0][0];
                var_s2->edgeAB[1] = var_s2->tri_coord[1][1] - var_s2->tri_coord[0][1];
                var_s2->edgeAB[2] = var_s2->tri_coord[1][2] - var_s2->tri_coord[0][2];
                    
                var_s2->edgeAC[0] = var_s2->tri_coord[2][0] - var_s2->tri_coord[0][0];
                var_s2->edgeAC[1] = var_s2->tri_coord[2][1] - var_s2->tri_coord[0][1];
                var_s2->edgeAC[2] = var_s2->tri_coord[2][2] - var_s2->tri_coord[0][2];
                    
                var_s2->normal[0] = (var_s2->edgeAB[1] * var_s2->edgeAC[2]) - (var_s2->edgeAB[2] * var_s2->edgeAC[1]);
                var_s2->normal[1] = (var_s2->edgeAB[2] * var_s2->edgeAC[0]) - (var_s2->edgeAB[0] * var_s2->edgeAC[2]);
                var_s2->normal[2] = (var_s2->edgeAB[0] * var_s2->edgeAC[1]) - (var_s2->edgeAB[1] * var_s2->edgeAC[0]);
                ml_vec3f_normalize( var_s2->normal);

                if (i_tri->flags & 0x10000) {//invert normal?
                    spC0[0] = p1[0] - var_s2->tri_coord[0][0];
                    spC0[1] = p1[1] - var_s2->tri_coord[0][1];
                    spC0[2] = p1[2] - var_s2->tri_coord[0][2];
                    if (((spC0[0]*var_s2->normal[0]) + (spC0[1]*var_s2->normal[1]) + (spC0[2]*var_s2->normal[2])) < 0.0f) {
                        var_s2->normal[0] = -var_s2->normal[0];\
                        var_s2->normal[1] = -var_s2->normal[1];\
                        var_s2->normal[2] = -var_s2->normal[2];
                    }
                }
                else{
                    if (((var_s2->normal[0]*velocity[0]) + (var_s2->normal[1]*velocity[1]) + (var_s2->normal[2]*velocity[2])) > 0.0f)
                        continue; //velocity is same direction as triangle normal
                }
                //add tri to active tri collisions
                var_s2->tri_ptr = i_tri;
                var_s2++;
                if ((var_s2 - D_8037EAD0) > 100) 
                    break;       
            }
        }
        if ((var_s2 - D_8037EAD0) > 100) 
            break; 
    }
    *activeTriStartPtr = (s32) D_8037EAD0; //activeTriPool
    *activeTriEndPtr = (s32) var_s2; //activeTriPoolEnd
    return var_s2 - D_8037EAD0 > 0; //Count
}

Struct_core2_5FD90_0 *func_802E879C(Struct_core2_5FD90_0 *startTri, Struct_core2_5FD90_0 *endTri, f32 position[3], f32 radius, f32 arg4[3]) {
    s32 i;
    Struct_core2_5FD90_0 *i_tri;
    
    f32 sp144[3][3];
    f32 sp120[3][3];
    
    f32 normal_length;
    f32 temp_f0_3;
    f32 temp_f0_4;

    f32 temp_f12_3;
    f32 temp_f18;
    f32 temp_f22;
    f32 spFC[3];
    f32 spF0[3];
    u32 var_a0;
    s32 var_a1;
    s32 var_a2;
    f32 projected_position[3];
    f32 temp_f2_4;
    Struct_core2_5FD90_0 *spD0;
    f32 temp_f8;
    f32 *var_s0;
    


    spD0 = 0;
    arg4[0] = 0.0f;
    arg4[1] = 0.0f;
    arg4[2] = 0.0f;
    for(i_tri = startTri; i_tri < endTri; i_tri++){
        //project point onto plane of triangle
        sp120[0][0] = position[0] - i_tri->tri_coord[0][0];
        sp120[0][1] = position[1] - i_tri->tri_coord[0][1];
        sp120[0][2] = position[2] - i_tri->tri_coord[0][2];
        temp_f18 = (sp120[0][0] * i_tri->normal[0]) + (sp120[0][1] * i_tri->normal[1]) + (sp120[0][2] * i_tri->normal[2]);
        if ((-(radius - 0.5)>= temp_f18) || ((radius -0.5) <= temp_f18))
            continue;

        temp_f8 = i_tri->normal[0];
        normal_length = (temp_f8 * i_tri->normal[0]) + (i_tri->normal[1] * i_tri->normal[1]) + (i_tri->normal[2] * i_tri->normal[2]);
        if(normal_length == 0.0f)
            continue;
        
        normal_length = -temp_f18 / normal_length;
        projected_position[0] = position[0] + (i_tri->normal[0] * normal_length);
        projected_position[1] = position[1] + (i_tri->normal[1] * normal_length);
        projected_position[2] = position[2] + (i_tri->normal[2] * normal_length);
        
        //check if projected point is inside of triangle
        var_a2 = (ABS_F(i_tri->normal[0]) > ABS_F(i_tri->normal[1])) ? 0 : 1;
        var_a2 = (ABS_F(i_tri->normal[2]) > ABS_F(i_tri->normal[var_a2])) ? 2 : var_a2;

        spFC[0] = projected_position[(var_a2 + 1)%3] - i_tri->tri_coord[0][(var_a2 + 1)%3];
        spFC[1] = i_tri->edgeAB[(var_a2 + 1)%3];
        spFC[2] = i_tri->edgeAC[(var_a2 + 1)%3];

        spF0[0] = projected_position[(var_a2 + 2)%3] - i_tri->tri_coord[0][(var_a2 + 2)%3];
        spF0[1] = i_tri->edgeAB[(var_a2 + 2)%3];
        spF0[2] = i_tri->edgeAC[(var_a2 + 2)%3];

        temp_f2_4 =  (spFC[1] * spF0[2]) - (spF0[1] * spFC[2]);
        temp_f12_3 = ((spFC[0] * spF0[2]) - (spF0[0] * spFC[2]))/temp_f2_4;
        temp_f0_4 =  ((spFC[1] * spF0[0]) - (spF0[1] * spFC[0]))/ temp_f2_4;
        if ((0.0f <= temp_f12_3) && (temp_f12_3 <= 1.0f)
         && (0.0f <= temp_f0_4) && (temp_f0_4 <= 1.0f))
        if ((0 <= 1.0f - (temp_f12_3 + temp_f0_4))) {
            //projected point lies on triangle
            spD0 = i_tri;
            arg4[0] = arg4[0] + i_tri->normal[0];
            arg4[1] = arg4[1] + i_tri->normal[1];
            arg4[2] = arg4[2] + i_tri->normal[2];
            continue;
        }

        //projected point lies outside triangle
        for(i = 0; i < 3; i++){
            sp120[i][0] = position[0] - i_tri->tri_coord[i][0];
            sp120[i][1] = position[1] - i_tri->tri_coord[i][1];
            sp120[i][2] = position[2] - i_tri->tri_coord[i][2];
            if (sp120[i][0]*sp120[i][0] + sp120[i][1]*sp120[i][1] + sp120[i][2]*sp120[i][2] < radius * radius) {
                spD0 = i_tri;
                arg4[0] = arg4[0] + i_tri->normal[0];
                arg4[1] = arg4[1] + i_tri->normal[1];
                arg4[2] = arg4[2] + i_tri->normal[2];
                break;
            }
            
        }
        if(i < 3)
            continue;
                
        for(i = 0; i < 3; i++){
            sp144[i][0] = i_tri->tri_coord[(i + 1) % 3][0] - i_tri->tri_coord[i][0];
            sp144[i][1] = i_tri->tri_coord[(i + 1) % 3][1] - i_tri->tri_coord[i][1];
            sp144[i][2] = i_tri->tri_coord[(i + 1) % 3][2] - i_tri->tri_coord[i][2];
            temp_f22 = sp144[i][0]*sp144[i][0] + sp144[i][1]*sp144[i][1] + sp144[i][2]*sp144[i][2];
            ml_vec3f_normalize(sp144[i]);
            temp_f0_3 = (sp144[i][0]*sp120[i][0]) + (sp144[i][1]*sp120[i][1]) + (sp144[i][2]*sp120[i][2]);
            if ((0.0f <= temp_f0_3) && ((temp_f0_3 * temp_f0_3) <= temp_f22)){
                projected_position[0] = sp120[i][0] - sp144[i][0]*temp_f0_3;
                projected_position[1] = sp120[i][1] - sp144[i][1]*temp_f0_3;
                projected_position[2] = sp120[i][2] - sp144[i][2]*temp_f0_3;
                if(projected_position[0]*projected_position[0] + projected_position[1]*projected_position[1] + projected_position[2]*projected_position[2] < radius * radius){
                    spD0 = i_tri;
                    arg4[0] = arg4[0] + i_tri->normal[0];
                    arg4[1] = arg4[1] + i_tri->normal[1];
                    arg4[2] = arg4[2] + i_tri->normal[2];
                    break;
                }
            } 
        }
    }
    return spD0;
}

BKCollisionTri *func_802E8E88(BKCollisionList *collision_list, BKVertexList *vtx_list, f32 p1[3], f32 p2[3], f32 radius, f32 arg5[3], s32 arg6, s32 flagFilter){
    Struct_core2_5FD90_0 * start_active_tri;
    Struct_core2_5FD90_0 * end_active_tri;
    f32 spB4[3];
    
    f32 temp_f20;
    f32 phi_f22;
    f32 phi_f24;
    s32 phi_s0;

    f32 sp98[3];
    f32 sp8C[3];
    Struct_core2_5FD90_0 *phi_s5;
    Struct_core2_5FD90_0 *phi_v0;
    f32 sp78[3];

    sp78[0] = p2[0] - p1[0];
    sp78[1] = p2[1] - p1[1];
    sp78[2] = p2[2] - p1[2];
    if (!func_802E81CC(collision_list, vtx_list, p1, p2, sp78, (f32) ((f64) radius + 0.5), flagFilter, &start_active_tri, &end_active_tri)) {
        return NULL;
    }
    phi_s5 = func_802E879C(start_active_tri, end_active_tri, p2, radius, sp8C);
    if (phi_s5 == NULL) {
        return NULL;
    }
    arg5[0] = sp8C[0];
    arg5[1] = sp8C[1];
    arg5[2] = sp8C[2];
    spB4[0] = p2[0] - p1[0];
    spB4[1] = p2[1] - p1[1];
    spB4[2] = p2[2] - p1[2];
    p2[0] = p1[0];
    p2[1] = p1[1];
    p2[2] = p1[2];
    phi_f22 = 0.0f;
    phi_f24 = 1.0f;
    for(phi_s0 = 0; phi_s0 < arg6; phi_s0++){
        temp_f20 = (phi_f22 + phi_f24) * 0.5;
        sp98[0] = p1[0] + (spB4[0] * temp_f20);
        sp98[1] = p1[1] + (spB4[1] * temp_f20);
        sp98[2] = p1[2] + (spB4[2] * temp_f20);
        phi_v0 = func_802E879C(start_active_tri, end_active_tri, sp98, radius, sp8C);
        if (phi_v0 != NULL) {
            arg5[0] = sp8C[0];
            arg5[1] = sp8C[1];
            arg5[2] = sp8C[2];
            phi_f24 = temp_f20;
            phi_s5 = phi_v0;
        } else {
            p2[0] = sp98[0];
            p2[1] = sp98[1];
            p2[2] = sp98[2];
            phi_f22 = temp_f20;
        }
    }
    if (phi_s5 == NULL) {
        return NULL;
    }
    ml_vec3f_normalize(arg5);
    func_802E6D20(phi_s5->tri_ptr, vtx_list);
    return phi_s5->tri_ptr;
}

s32 func_802E9118(BKCollisionList * collision_list, BKVertexList *vtx_list, f32 arg2[3], s32 arg3, f32 arg4, f32 arg5[3], f32 arg6[3], f32 arg7, f32 arg8[3], s32 arg9, s32 flagFilter) {
    f32 sp4C[3];
    f32 sp40[3];
    s32 sp3C;
    s32 i;

    if (((f32)vtx_list->global_norm * arg4) <= (ml_distance_vec3f(arg6, arg2) - arg7)) {
        return 0;
    }
    mlMtxIdent();
    func_80252CC4(arg2, arg3, arg4, 0);
    mlMtx_apply_vec3f(&sp4C, arg5);
    mlMtx_apply_vec3f(&sp40, arg6);
    sp3C = func_802E8E88(collision_list, vtx_list, &sp4C, &sp40, arg7 / arg4, arg8, arg9, flagFilter);
    if (sp3C == 0) {
        return 0;
    }
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, 0);
    mlMtx_apply_vec3f(arg6, &sp40);
    mlMtxIdent();
    func_80252C08(NULL, arg3, 1.0f, 0);
    mlMtx_apply_vec3f(arg8, arg8);
    mlMtxIdent();
    func_80252C08(arg2, arg3, arg4, 0);
    for(i = 0; i < 3; i++){
        mlMtx_apply_vec3f(D_8037EAA8[i], D_8037EAA8[i]);
    }
    return sp3C;
}

BKCollisionTri *func_802E92AC(BKCollisionList *collisionList, BKVertexList *vertexList, f32 position[3], f32 radius, f32 arg4[3], s32 flagFilter) {
    BKCollisionGeo **start_geo;
    BKCollisionGeo **i_geo;
    BKCollisionGeo **end_geo;
    s32 i;
    s32 j;
    f32 min[3];
    f32 max[3];
    BKCollisionTri *start_tri;
    BKCollisionTri *i_tri;
    BKCollisionTri *end_tri;
    f32 tri_vtx_coord[3][3];
    Vtx *vtx_pool;
    Vtx *i_vtx;
    f32 min_coord[3];
    f32 max_coord[3];
    BKCollisionGeo *temp_a2;
    f32 tri_edge[3][3];
    f32 sp138[3][3];
    f32 temp_f0_10;
    f32 temp_f0_2;
    f32 temp_f0_6;
    f32 tri_normal[3];
    f32 temp_f0_8;
    f32 temp_f12_2;
    f32 temp_f14_2;
    f32 sp108[3];
    f32 spFC[3];
    f32 temp_f2_3;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 spE4[3];
    f32 projected_position[3];
    f32 temp_f8;
    BKCollisionTri *spD0;
    s32 var_a2;
    s32 var_v1_2;

    for(i = 0; i < 3; i++){
        min[i] = position[i] - (radius + 0.5);
        max[i] = position[i] + (radius + 0.5);
    }

    //check if any vertices are within range;
    temp_f0_2 = vtxList_getGlobalNorm(vertexList);
    for(i = 0; i < 3; i++){
        if((max[i] <= -temp_f0_2)|| temp_f0_2 <= min[i])
            return NULL;
    }

    //iterate over collision geometry intersect range
    spD0 = NULL;
    spE4[0] = spE4[1] = spE4[2] = 0.0f;
    collisionList_getIntersecting(collisionList, min, max, &start_geo, &end_geo);
    vtx_pool = vtxList_getVertices(vertexList);
    for(i_geo = start_geo; i_geo < end_geo; i_geo++){

        //iterate over each triangle in collision geometry
        start_tri = (BKCollisionTri *)((BKCollisionGeo *)(collisionList + 1) + collisionList->unk10) + (*i_geo)->start_tri_index;
        end_tri = start_tri + (*i_geo)->tri_count;
        for(i_tri = start_tri; i_tri < end_tri; i_tri++){
            //filter tri
            if (!(i_tri->flags & flagFilter)){

                //get tri coords
                for(i = 0; i < 3; i++){
                    i_vtx = &vtx_pool[i_tri->unk0[i]];
                    tri_vtx_coord[i][0] = i_vtx->v.ob[0];
                    tri_vtx_coord[i][1] = i_vtx->v.ob[1];
                    tri_vtx_coord[i][2] = i_vtx->v.ob[2];
                }

                //get tri bounding points
                min_coord[0] = tri_vtx_coord[0][0];
                min_coord[1] = tri_vtx_coord[0][1];
                min_coord[2] = tri_vtx_coord[0][2];
    
                max_coord[0] = tri_vtx_coord[0][0];
                max_coord[1] = tri_vtx_coord[0][1];
                max_coord[2] = tri_vtx_coord[0][2];
                for(i = 1; i < 3; i++){
                    for(j = 0; j < 3; j++){
                        if(tri_vtx_coord[i][j] < min_coord[j]){
                            min_coord[j] = tri_vtx_coord[i][j];
                        }
                        if(max_coord[j] < tri_vtx_coord[i][j]){
                            max_coord[j] = tri_vtx_coord[i][j];
                        }
                    }
                }
    
                //check if tri is within collision region
                if ((max[0] < min_coord[0]) || (max_coord[0] < min[0])) continue;
                if ((max[1] < min_coord[1]) || (max_coord[1] < min[1])) continue;
                if ((max[2] < min_coord[2]) || (max_coord[2] < min[2])) continue;
                
                //caluclate normal
                tri_edge[0][0] = tri_vtx_coord[1][0] - tri_vtx_coord[0][0];\
                tri_edge[0][1] = tri_vtx_coord[1][1] - tri_vtx_coord[0][1];\
                tri_edge[0][2] = tri_vtx_coord[1][2] - tri_vtx_coord[0][2];
    
                tri_edge[1][0] = tri_vtx_coord[2][0] - tri_vtx_coord[0][0];
                tri_edge[1][1] = tri_vtx_coord[2][1] - tri_vtx_coord[0][1];
                tri_edge[1][2] = tri_vtx_coord[2][2] - tri_vtx_coord[0][2];
    
                tri_normal[0] = (tri_edge[0][1] * tri_edge[1][2]) - (tri_edge[0][2] * tri_edge[1][1]);
                tri_normal[1] = (tri_edge[0][2] * tri_edge[1][0]) - (tri_edge[0][0] * tri_edge[1][2]);
                tri_normal[2] = (tri_edge[0][0] * tri_edge[1][1]) - (tri_edge[0][1] * tri_edge[1][0]);
                ml_vec3f_normalize(tri_normal);
                    
                if ((tri_normal[0] == 0.0f) && (tri_normal[1] == 0.0f) && (tri_normal[2] == 0.0f)) 
                    continue;
    
                //project point onto triangle?
                sp138[0][0] = position[0] - tri_vtx_coord[0][0];
                sp138[0][1] = position[1] - tri_vtx_coord[0][1];
                sp138[0][2] = position[2] - tri_vtx_coord[0][2];
    
                temp_f12_2 = (sp138[0][0] * tri_normal[0]) + (sp138[0][1] * tri_normal[1]) + (sp138[0][2] * tri_normal[2]);
                if((temp_f12_2 <= -(radius - 0.5)) || ((radius - 0.5) <= temp_f12_2))
                    continue;
    
                temp_f2_3 = (tri_normal[0] * tri_normal[0]) + (tri_normal[1] * tri_normal[1]) + (tri_normal[2]*tri_normal[2]);
                if (temp_f2_3 == 0.0f) 
                    continue;
    
                temp_f0_6 = -temp_f12_2 / temp_f2_3;
                projected_position[0] = position[0] + (tri_normal[0] * temp_f0_6);
                projected_position[1] = position[1] + (tri_normal[1] * temp_f0_6);
                projected_position[2] = position[2] + (tri_normal[2] * temp_f0_6);
    
                //???
                var_a2 = (ABS_F(tri_normal[0]) > ABS_F(tri_normal[1])) ? 0 : 1;
                var_a2 = (ABS_F(tri_normal[2]) > ABS_F(tri_normal[var_a2])) ? 2 : var_a2;
                
                sp108[0] = projected_position[(var_a2 + 1) % 3] - tri_vtx_coord[0][(var_a2 + 1) % 3];
                sp108[1] = tri_edge[0][(var_a2 + 1) % 3];
                sp108[2] = tri_edge[1][(var_a2 + 1) % 3];
    
                spFC[0] = projected_position[(var_a2 + 2) % 3] - tri_vtx_coord[0][(var_a2 + 2) % 3];
                spFC[1] = tri_edge[0][(var_a2 + 2) % 3];
                spFC[2] = tri_edge[1][(var_a2 + 2) % 3];
                
                temp_f14_2 = (sp108[1] * spFC[2]) - (spFC[1] * sp108[2]);
                temp_f2_6 = ((sp108[0] * spFC[2]) - (spFC[0] * sp108[2]))/ temp_f14_2;
                if ((0.0f <= temp_f2_6) && (temp_f2_6 <= 1)){
                    temp_f0_8 = ((sp108[1] * spFC[0]) - (spFC[1] * sp108[0]))/temp_f14_2;
                    if(1)
                    if((0.0f <= temp_f0_8) && ((temp_f0_8 <= 1))){
                        if((temp_f2_6 + temp_f0_8 <= 1)){
                            spD0 = i_tri;
                            spE4[0] = spE4[0] + tri_normal[0];
                            spE4[1] = spE4[1] + tri_normal[1];
                            spE4[2] = spE4[2] + tri_normal[2];
                            continue;
                        }
                    }
                }
    
                for(i = 0; i < 3; i++){
                    sp138[i][0] = position[0] - tri_vtx_coord[i][0];
                    sp138[i][1] = position[1] - tri_vtx_coord[i][1];
                    sp138[i][2] = position[2] - tri_vtx_coord[i][2];
                    if((sp138[i][0] * sp138[i][0]) + (sp138[i][1] * sp138[i][1]) + (sp138[i][2] * sp138[i][2]) < (radius *radius)){
                        spD0 = i_tri;
                        spE4[0] = spE4[0] + tri_normal[0];
                        spE4[1] = spE4[1] + tri_normal[1];
                        spE4[2] = spE4[2] + tri_normal[2];
                        break;
                    }
                }
                
                if(i < 3)
                    continue;
                    
                for(i = 0; i < 3; i++){
                    tri_edge[i][0] = tri_vtx_coord[(i + 1)%3][0] - tri_vtx_coord[i][0];\
                    tri_edge[i][1] = tri_vtx_coord[(i + 1)%3][1] - tri_vtx_coord[i][1];\
                    tri_edge[i][2] = tri_vtx_coord[(i + 1)%3][2] - tri_vtx_coord[i][2];
                    temp_f2_7 = (tri_edge[i][0] * tri_edge[i][0]) + (tri_edge[i][1] * tri_edge[i][1]) + (tri_edge[i][2] * tri_edge[i][2]);
                    ml_vec3f_normalize(tri_edge[i]);
                    temp_f0_10 = (tri_edge[i][0] * sp138[i][0]) + (tri_edge[i][1] * sp138[i][1]) + (tri_edge[i][2] * sp138[i][2]);
                    if ((temp_f0_10 >= 0.0f) && ((temp_f0_10 *temp_f0_10) <= temp_f2_7)){
                        projected_position[0] = sp138[i][0] - (tri_edge[i][0] * temp_f0_10);
                        projected_position[1] = sp138[i][1] - (tri_edge[i][1] * temp_f0_10);
                        projected_position[2] = sp138[i][2] - (tri_edge[i][2] * temp_f0_10);
                        if((projected_position[0] * projected_position[0]) + (projected_position[1] * projected_position[1]) + (projected_position[2] * projected_position[2]) < (radius * radius)) {
                            spD0 = i_tri;
                            spE4[0] = spE4[0] + tri_normal[0];
                            spE4[1] = spE4[1] + tri_normal[1];
                            spE4[2] = spE4[2] + tri_normal[2];
                            break;
                        }
                    } 
                }
                
            }
        }
    }
    if (spD0 != NULL) {
        ml_vec3f_normalize_copy(arg4, spE4);
    }
    func_802E6D20(spD0, vertexList);
    return spD0;
}

s32 func_802E9DD8(BKCollisionList *collisionList, BKVertexList *vtxList, f32 posA[3], f32 *rotA, f32 scaleA, f32 posB[3], f32 radB, f32 arg7[3], s32 arg8) {
    f32 sp34[3];
    s32 sp30;
    s32 i;

    // check if (sphere around vtx's) <= ((distance between origins) - (radius of B))
    if ((vtxList->global_norm * scaleA) <= (ml_distance_vec3f(posB, posA) - radB)) {
        return 0;
    }
    mlMtxIdent();
    func_80252CC4(posA, rotA, scaleA, NULL);
    mlMtx_apply_vec3f(sp34, posB);
    sp30 = func_802E92AC(collisionList, vtxList, &sp34, radB / scaleA, arg7, arg8);
    if (sp30 == 0) {
        return 0;
    }
    mlMtxIdent();
    func_80252C08(posA, rotA, scaleA, NULL);
    mlMtx_apply_vec3f(posB, sp34);
    mlMtxIdent();
    func_80252C08(NULL, rotA, 1.0f, NULL);
    mlMtx_apply_vec3f(arg7, arg7);
    mlMtxIdent();
    func_80252C08(posA, rotA, scaleA, NULL);
    
    for(i = 0; i < 3; i++){
        mlMtx_apply_vec3f(D_8037EAA8[i], D_8037EAA8[i]);
    }
    return sp30;
}
