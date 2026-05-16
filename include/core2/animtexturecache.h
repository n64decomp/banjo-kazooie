#ifndef BANJO_KAZOOIE_CORE2_ANIMTEXTURECACHE_H
#define BANJO_KAZOOIE_CORE2_ANIMTEXTURECACHE_H

#include <ultra64.h>

struct BKAnimTexture;

bool AnimTextureListCache_tryGetTextureOffset(s32 index, s32 texture_index, s32 *texture_offset);
s32 AnimTextureListCache_newList(void);
void AnimTextureListCache_free(void);
void AnimTextureListCache_init(void);
void AnimTextureListCache_freeList(s32 index);
void AnimTextureListCache_setAnimTextureList(s32 index, BKAnimTextureList *bk_anim_texture_list);
void AnimTextureListCache_update(void);

#endif
