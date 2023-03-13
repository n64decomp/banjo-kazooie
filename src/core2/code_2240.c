#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

//function declarations
void anim_setIndex(Animation *this, enum asset_e arg1);
void anim_drawSetup(Animation *this);
void animationFile_getBoneTransformList(s32, f32, s32);
void boneTransformList_interpolate(s32, s32, s32, f32);

//function definitions
static void __anim_resetTransform(Animation *this, s32 arg1){
    s32 *tmp;
    if(animCache_getBoneTransformList(this->animcache_index[arg1], &tmp) == 0){
        boneTransformList_reset(tmp);
    }; 
}

void __anim_resetCurrentTransform(Animation *this){
    __anim_resetTransform(this, this->unk8);
}

void __anim_resetTargetTransform(Animation *this){
    __anim_resetTransform(this, 2);
}

s32 __anim_transformInUse(Animation *this, s32 arg1){
    return animCache_inUse(this->animcache_index[arg1]);
}

s32 __anim_currentTransformInUse(Animation *this){
    return __anim_transformInUse(this, this->unk8);
}

s32 __anim_startTransformInUse(Animation *this){
    return __anim_transformInUse(this, (this->unk8 != 0)? 0: 1);
}

BoneTransformList *anim_getTransform(Animation *this, s32 index){
    BoneTransformList *tmp;
    animCache_getBoneTransformList(this->animcache_index[index], &tmp);
    return tmp;
}

BoneTransformList *animcache_getCurrentTransform(Animation *this){
    return anim_getTransform(this, this->unk8);
}

BoneTransformList *anim_getStartTransform(Animation *this){
    return anim_getTransform(this, (this->unk8 != 0)? 0: 1);
}

BoneTransformList *anim_getTargetTransform(Animation *this){
    return anim_getTransform(this, 2);
}

void __anim_update_doubleBuffer(Animation *this){
    if(this->reset == 1 && __anim_currentTransformInUse(this)){
        this->unk8 = (this->unk8)? 0 : 1; //swap current transform and start transfrom
    }
    this->reset = 0;
    if( this->duration < 1.0f && __anim_startTransformInUse(this)){
        animationFile_getBoneTransformList(animBinCache_get(this->index), this->timer, animcache_getCurrentTransform(this));
        boneTransformList_interpolate(animcache_getCurrentTransform(this), anim_getStartTransform(this), animcache_getCurrentTransform(this), this->duration);
    }
    else{
        animationFile_getBoneTransformList(animBinCache_get(this->index), this->timer, animcache_getCurrentTransform(this));
    }

}

void __anim_update_tripleBuffer(Animation *this){
    if(this->reset == 1 && this->unk1E == 0){
        //smooth a current Xfrom become startXform
        if(__anim_currentTransformInUse(this)){
            this->unk8 = (this->unk8)? 0 : 1;//swap current transform and start transfrom
            __anim_resetTargetTransform(this);
        }
    }
    else{
        //not smooth
        if(this->reset == 2)
            __anim_resetCurrentTransform(this);
    }
    this->reset = 0;
    if( this->duration < 1.0f && __anim_startTransformInUse(this) && !this->unk1E){
        animationFile_getBoneTransformList(animBinCache_get(this->index), this->timer, anim_getTargetTransform(this));
        boneTransformList_interpolate(animcache_getCurrentTransform(this), anim_getStartTransform(this), anim_getTargetTransform(this), this->duration);
    }
    else{
        animationFile_getBoneTransformList(animBinCache_get(this->index), this->timer, animcache_getCurrentTransform(this));
        if(this->unk1E && this->index)
            this->unk1E = 0;
    }

}

void anim_update(Animation *this){
    if(this->triple_buffer == 1){
        __anim_update_tripleBuffer(this);
    }
    else{
        __anim_update_doubleBuffer(this);
    }
    if(this->matrices){
        (*(this->matrices))(animcache_getCurrentTransform(this), this->unk4);
    }
    anim_drawSetup(this);
}


void anim_resetSmooth(Animation *this){
    this->reset = 1;
}

size_t anim_getSize(void){
    return sizeof(Animation);
}

enum asset_e anim_getIndex(Animation *this){
    return this->index;
}

f32  anim_getTimer(Animation *this){
    return this->timer;
}

f32  anim_getDuration(Animation *this){
    return this->duration;
}

void anim_release(Animation *this){
    animCache_release(this->animcache_index[0]);
    animCache_release(this->animcache_index[1]);
    if(this->triple_buffer == 1){
        animCache_release(this->animcache_index[2]);
    }
}

void anim_new(Animation *this, bool triple_buffer){
    this->triple_buffer = triple_buffer;
    anim_setIndex(this,0);
    anim_setTimer(this, 0.0f);
    anim_setDuration(this, 1.0f);
    anim_80289790(this, NULL);
    this->reset = 0;
    this->unk1E = 1;
    this->unk8 = 0;
    this->animcache_index[0] = animCache_getNew();
    this->animcache_index[1] = animCache_getNew();
    if(this->triple_buffer == 1){
        this->animcache_index[2] = animCache_getNew(); //target_bone_transform_list
    }
}

void anim_setIndex(Animation *this, enum asset_e arg1){
    this->index = arg1;
}

void anim_setTimer(Animation *this, f32 arg1){
    this->timer = arg1;
}

void anim_80289790(Animation *this, void (*arg1)(s32, s32)){
    this->matrices = arg1;
}

void anim_80289798(Animation *this, s32 arg1){
    this->unk4 = arg1;
}

void anim_drawSetup(Animation *this){
    modelRender_setBoneTransformList(animcache_getCurrentTransform(this));
}

void anim_setDuration(Animation *this, f32 arg1){
    this->duration = arg1;
}

void anim_802897D4(AnimMtxList *this, BKAnimationList *arg0, Animation *dst){
    animMtxList_setBoned(this, arg0, animcache_getCurrentTransform(dst));
}

void anim_resetNow(Animation *this){
    this->reset = 2;
}
