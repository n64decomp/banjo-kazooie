#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "animation.h"

AnimationFile *animcache_get(enum asset_e assest_id);

/* .data */
s16 D_803635C0[] = {0x1, 0x3, 0x5, 0xC, 0xE, 0x17, 0x18, 0x19, 0x1A, 0x1C, 0x1D, 0};

/* .bss */
AnimationCache D_8037A8C0[0x2CA];

/* .code */
void func_802884E0(void){
    s16 *phi_v0;

    for( phi_v0 = D_803635C0; *phi_v0 != 0; phi_v0++){
        D_8037A8C0[*phi_v0].unk4_0 = 1;
        
    }
}

void animcache_loadAll(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk4_0){
            animcache_get(i);
        }
    }
}

AnimationFile *animcache_get(enum asset_e asset_id){
    if(!D_8037A8C0[asset_id].unk0){
        D_8037A8C0[asset_id].unk0 = (AnimationFile *) assetcache_get(asset_id);
    }
    D_8037A8C0[asset_id].unk4_15 = 30;
    return D_8037A8C0[asset_id].unk0;
}

void animcache_free(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk0){
            assetcache_release(D_8037A8C0[i].unk0);
        }
    }
}

void animcache_init(void){
    s32 i = 0;
    for(i = 0; i < 0x2CA; i++){
        D_8037A8C0[i].unk0 = NULL;
        D_8037A8C0[i].unk4_15 = 0;
        D_8037A8C0[i].unk4_0 = 0;
    }
    func_802884E0();
    animcache_loadAll();
}

void func_8028873C(s32 arg0){
    s32 i;
    if(arg0){
        for(i = 0; i < 0x2CA; i++){
            if(D_8037A8C0[i].unk0 && D_8037A8C0[i].unk4_0 && (D_8037A8C0[i].unk4_15 < 30)){
                assetcache_release(D_8037A8C0[i].unk0);
                D_8037A8C0[i].unk0 = NULL;
                D_8037A8C0[i].unk4_0 = 0;
            }
        }
    }
    else{
        for(i = 0; i < 0x2CA; i++){
            if(D_8037A8C0[i].unk0 && !D_8037A8C0[i].unk4_0 && (D_8037A8C0[i].unk4_15 < 30)){
                assetcache_release(D_8037A8C0[i].unk0);
                D_8037A8C0[i].unk0 = NULL;
                if(func_80254BC4(1))
                    break;
            }
        }
    }
}

void func_80288834(void){
    s32 i;
    for(i = 0; i < 0x2CA; i++){
        if(D_8037A8C0[i].unk0 && !D_8037A8C0[i].unk4_0){
            if(--D_8037A8C0[i].unk4_15 == 0){
                assetcache_release(D_8037A8C0[i].unk0);
                D_8037A8C0[i].unk0 = NULL;
            }
        }
    }
}
