#include <ultra64.h>
#include "functions.h"
#include "variables.h"


//textureList_getDataPtr
u8 *func_802EA620(BKTextureList *this){
    return (u8*)this + this->cnt_4*sizeof(BKTextureHeader) + sizeof(BKTextureList);
}

s32 texture_getPixelBitSize(BKTextureHeader *this){
    if(this->type_4 & 1){
        return 4;
    }

    if(this->type_4 & 2){
        return 8;
    }

    if(this->type_4 & 4){
        return 0x10;
    }

    if(this->type_4 & 8){
        return 0x20;
    }
    return 0;
}

s32 func_802EA684(BKTextureHeader *this){
    return this->type_4;
}

s32 texture_getPaletteSize(BKTextureHeader *this){
    if(this->type_4 & 1){
        return 0x20;
    }

    if(this->type_4 & 2){
        return 0x200;
    }

    if(this->type_4 & 4){
        return 0;
    }

    if(this->type_4 & 8){
        return 0;
    }
    return 0;
}

// texture_getOffset
s32 func_802EA6DC(BKTextureHeader *this){
    return this->offset_0;
}

//texture_getSize
s32 func_802EA6E4(BKTextureHeader *this){
    s32 palette_size = texture_getPaletteSize(this);
    s32 pixel_size = texture_getPixelBitSize(this);

    return (s32)pixel_size*this->width_8*this->height_9/8  + palette_size;
}

//textureList_getTexture
BKTextureHeader *func_802EA748(BKTextureList *arg0, s32 indx){
    return (BKTextureHeader *)(arg0 +1) + indx;
}
