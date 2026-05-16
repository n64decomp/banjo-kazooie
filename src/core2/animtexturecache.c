#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    BKAnimTexture anim_texture_info[4];
    f32 current_frame[4];
}AnimTextureList; //this struct only used when textures are active in RAM

FREE_LIST(AnimTextureList) *sAnimTextureListCache;

bool AnimTextureListCache_tryGetTextureOffset(s32 index, s32 texture_index, s32 *texture_offset) {
    AnimTextureList *item;

    item = (AnimTextureList *) freelist_at(sAnimTextureListCache, index);
    if (item->anim_texture_info[texture_index].frame_size != 0) {
        *texture_offset = (s32) item->current_frame[texture_index] * item->anim_texture_info[texture_index].frame_size;
        return TRUE;
    }

    return FALSE;
}

s32 AnimTextureListCache_newList(void) {
    AnimTextureList *item;
    s32 index;
    int i;

    item = (AnimTextureList *) freelist_next(&sAnimTextureListCache, &index);

    for (i = 0; i < 4; i++) {
        item->anim_texture_info[i].frame_size = 0;
        item->current_frame[i] = 0.0f;
    }

    return index;
}

void AnimTextureListCache_free(void) {
    freelist_free(sAnimTextureListCache);
}

void AnimTextureListCache_init(void) {
    sAnimTextureListCache = (FREE_LIST(AnimTextureList) *) freelist_new(sizeof(AnimTextureList), 2);
}

void AnimTextureListCache_freeList(s32 index) {
    freelist_freeElement(sAnimTextureListCache, index);
}

void AnimTextureListCache_setAnimTextureList(s32 index, BKAnimTextureList *bk_anim_texture_list) {
    AnimTextureList *item;
    s32 i;

    item = (AnimTextureList *) freelist_at(sAnimTextureListCache, index);
    memcpy(item, bk_anim_texture_list, sizeof(BKAnimTextureList));
    for (i = 0; i < 4; i++) {
        item->current_frame[i] = 0.0f;
    }
}

void AnimTextureListCache_update(void) {
    f32 dt;
    s32 j;
    AnimTextureList *j_ptr;
    s32 i;

    dt = time_getDelta();

    for (j = 1; j < freelist_size(sAnimTextureListCache); j++) {
        if (freelist_elementIsAlive(sAnimTextureListCache, j)) {
            j_ptr = (AnimTextureList *) freelist_at(sAnimTextureListCache, j);
            for (i = 0; i < 4; i++) {
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
