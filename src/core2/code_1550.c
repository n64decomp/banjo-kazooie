#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

typedef struct animation_file_cache_s{
    AnimationFile *ptr;
    u16 exp_timer:15;
    u16 persist:1;
    u8  pad6[2];
}AnimationFileCache;

AnimationFile *animBinCache_get(enum asset_e assest_id);

/* .data */
s16 animBinCache_persistantList[] = {
    ASSET_1_ANIM_BSCROUCH_ENTER,
    ASSET_3_ANIM_BSWALK,
    ASSET_5_ANIM_BSPUNCH,
    ASSET_C_ANIM_BSWALK_RUN,
    ASSET_E_ANIM_BSTURN,
    ASSET_17_ANIM_BSBFLAP,
    ASSET_18_ANIM_BSBFLAP_ENTER,
    ASSET_19_ANIM_BSBPECK_ENTER,
    ASSET_1A_ANIM_BSBPECK,
    ASSET_1C_ANIM_BSBBARGE,
    ASSET_1D_ANIM_BSBBUSTER,
    0
};

/* .bss */
AnimationFileCache animBinCache[0x2CA];

/* .code */
static void __animBinCache_initPersistent(void){
    s16 *phi_v0;

    for( phi_v0 = animBinCache_persistantList; *phi_v0 != 0; phi_v0++){
        animBinCache[*phi_v0].persist = 1;
        
    }
}

static void __animBinCache_loadAll(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(animBinCache[i].persist){
            animBinCache_get(i);
        }
    }
}

AnimationFile *animBinCache_get(enum asset_e asset_id){
    if(animBinCache[asset_id].ptr == NULL){
        animBinCache[asset_id].ptr = (AnimationFile *) assetcache_get(asset_id);
    }
    animBinCache[asset_id].exp_timer = 30;
    return animBinCache[asset_id].ptr;
}

void animBinCache_free(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(animBinCache[i].ptr){
            assetcache_release(animBinCache[i].ptr);
        }
    }
}

void animBinCache_init(void){
    s32 i = 0;
    for(i = 0; i < 0x2CA; i++){
        animBinCache[i].ptr = NULL;
        animBinCache[i].exp_timer = 0;
        animBinCache[i].persist = 0;
    }
    __animBinCache_initPersistent();
    __animBinCache_loadAll();
}

void animBinCache_flushStale(s32 persistant){
    s32 i;
    if(persistant){
        for(i = 0; i < 0x2CA; i++){
            if( (animBinCache[i].ptr != NULL) 
                && (animBinCache[i].persist) 
                && (animBinCache[i].exp_timer < 30)
            ){
                assetcache_release(animBinCache[i].ptr);
                animBinCache[i].ptr = NULL;
                animBinCache[i].persist = 0;
            }
        }
    } else {
        for(i = 0; i < 0x2CA; i++){
            if( (animBinCache[i].ptr != NULL) 
                && !animBinCache[i].persist 
                && (animBinCache[i].exp_timer < 30)
            ){
                assetcache_release(animBinCache[i].ptr);
                animBinCache[i].ptr = NULL;
                if(func_80254BC4(1))
                    break;
            }
        }
    }
}

void animBinCache_update(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if((animBinCache[i].ptr != NULL) && !animBinCache[i].persist){
            if(--animBinCache[i].exp_timer == 0){
                assetcache_release(animBinCache[i].ptr);
                animBinCache[i].ptr = NULL;
            }
        }
    }
}
