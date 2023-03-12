#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    AnimTexture anim_texture_info[4];
    f32 current_frame[4];
}AnimTextureList; //this struct only used when textures are active in RAM

/* .bss */
FREE_LIST(AnimTextureList) *AnimTextureListCache;

/* .code */
bool AnimTextureListCache_tryGetTextureOffset(s32 list_index, s32 texture_index, s32 *current_frame) {
    AnimTextureList * temp_v0;

    temp_v0 = (AnimTextureList *)freelist_at(AnimTextureListCache, list_index);
    if (temp_v0->anim_texture_info[texture_index].frame_size != 0) {
        *current_frame = (s32)temp_v0->current_frame[texture_index] * temp_v0->anim_texture_info[texture_index].frame_size;
        return TRUE;
    }
    return FALSE;
}

s32 AnimTextureListCache_newList(void){
    AnimTextureList *phi_v0;
    s32 index;
    s32 i;

    phi_v0 = (AnimTextureList *)freelist_next(&AnimTextureListCache, &index);
    for(i = 0; i < 4; i++){
        phi_v0->anim_texture_info[i].frame_size = 0;
        phi_v0->current_frame[i] = 0.0f;
    }
    return index;
}

void AnimTextureListCache_free(void){
    freelist_free(AnimTextureListCache);
}

void AnimTextureListCache_init(void){
    AnimTextureListCache = (FREE_LIST(AnimTextureList) *)freelist_new(sizeof(AnimTextureList), 2);
}

void AnimTextureListCache_freeList(s32 arg0){
    freelist_freeElement(AnimTextureListCache, arg0);
}

void AnimTextureListCache_at(s32 arg0, AnimTexture arg1[4]){
    AnimTextureList * sp1C;
    s32 i;


    sp1C = (AnimTextureList *) freelist_at(AnimTextureListCache, arg0);
    memcpy(sp1C, arg1, 0x20);
    for(i = 0; i < 4; i++){
        sp1C->current_frame[i] = 0.0f;
    }
}

void AnimTextureListCache_update(void) {
    f32 dt;
    s32 j;
    AnimTextureList *j_ptr;
    s32 i;

    dt = time_getDelta();
    for(j = 1; j <freelist_size(AnimTextureListCache); j++){
        if (freelist_elementIsAlive(AnimTextureListCache, j)) {
            j_ptr = (AnimTextureList *)freelist_at(AnimTextureListCache, j);
            for(i = 0; i < 4; i++){
                if (j_ptr->anim_texture_info[i].frame_size != 0) {
                    j_ptr->current_frame[i] += (j_ptr->anim_texture_info[i].frame_rate * dt);
                    if ((s32) j_ptr->current_frame[i] >= j_ptr->anim_texture_info[i].frame_cnt) {
                        j_ptr->current_frame[i] -= j_ptr->anim_texture_info[i].frame_cnt;
                    }
                }
            }
        }
    }
}
