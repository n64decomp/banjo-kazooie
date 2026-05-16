#include <ultra64.h>
#include "model.h"

void *textureList_getDataPtr(BKTextureList *this) {
    return (void *) &this->texture_infos[this->count];
}

s32 textureInfo_getBitDepth(BKTextureInfo *this) {
    if (this->type & BK_TEXTURE_INFO_TYPE_CI4_BIT) {
        return 4;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_CI8_BIT) {
        return 8;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_RGBA16_BIT) {
        return 16;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_RGBA32_BIT) {
        return 32;
    }

    return 0;
}

s32 textureInfo_getType(BKTextureInfo *this) {
    return this->type;
}

s32 textureInfo_getPaletteSize(BKTextureInfo *this) {
    if (this->type & BK_TEXTURE_INFO_TYPE_CI4_BIT) {
        return 32;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_CI8_BIT) {
        return 512;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_RGBA16_BIT) {
        return 0;
    }

    if (this->type & BK_TEXTURE_INFO_TYPE_RGBA32_BIT) {
        return 0;
    }

    return 0;
}

s32 textureInfo_getOffset(BKTextureInfo *this) {
    return this->offset;
}

s32 textureInfo_getTextureSize(BKTextureInfo *this) {
    s32 palette_size = textureInfo_getPaletteSize(this);
    s32 pixel_size = textureInfo_getBitDepth(this);

    return (s32) pixel_size * this->width * this->height / 8 + palette_size;
}

BKTextureInfo *textureList_getTextureInfo(BKTextureList *this, s32 index) {
    return &this->texture_infos[index];
}
