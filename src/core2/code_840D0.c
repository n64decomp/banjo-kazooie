#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8024CE60(f32, f32);

extern struct48s D_8036BD40[];

extern f32 D_80378440;

struct 
{
    struct48s *unk0;
    BKModel *unk4[3];
    void *unk10[3];
    f32 unk1C;
}D_80382410;

struct48s * func_8030B060(enum map_e map_id){
    struct48s * v1 = D_8036BD40;
    while(v1->map){
        if(map_id == v1->map){
            return v1;
        }
        v1++;
    }
    return v1;
}

void func_8030B0AC(Gfx **arg0, Mtx **arg1, s32 arg2){
    int i;
    f32 sp70[3];
    f32 sp64[3];
    void *iAsset;

    func_8024CE60(5.0f, D_80378440);
    if(D_80382410.unk10[0]){
        func_80254084(arg0, 0, 0, 
            (s32)(f32) D_80276588, (s32)(f32)D_8027658C,
            0, 0, 0
        );
        func_8024C904(arg0, arg1);
        func_8024C5CC(&sp70);
        for(i = 0; i < 3; i++){
            iAsset = D_80382410.unk10[i];
            if(iAsset){
                sp64[0] = 0.0f;
                sp64[1] = D_80382410.unk0->unk4[i].unk8 * D_80382410.unk1C;
                sp64[2] = 0.0f;
                func_803391A4(arg0, arg1, &sp70, &sp64, D_80382410.unk0->unk4[i].unk4, NULL, iAsset);
            }
        }
    }
    else{//L8030B200
        func_80254084(arg0, 0, 0, (s32)(f32) D_80276588, (s32)(f32)D_8027658C, 0, 0, 0);
    }//L8030B254
}

void func_8030B284(void){
    int i;

    for(i = 0; i < 3; i++){
        if(D_80382410.unk4[i]){
            model_free(D_80382410.unk4[i]);
        }

        if(D_80382410.unk10[i]){
            assetcache_release(D_80382410.unk10[i]);
        }
    }
}

void func_8030B2EC(void){
    int i;

    D_80382410.unk0 = func_8030B060(map_get());
    for(i = 0; i< 3; i++){
        D_80382410.unk4[i] = 0;
        D_80382410.unk10[i] = NULL;
        if(D_80382410.unk0->unk4[i].unk0){
            D_80382410.unk10[i] = assetcache_get(D_80382410.unk0->unk4[i].unk0);
            if(func_8033A0B0(D_80382410.unk10[i])){
                D_80382410.unk4[i] = func_8033F5F8(func_8033A0B0(D_80382410.unk10[i]), func_8033A148( D_80382410.unk10[i]));
                func_8034C6DC(D_80382410.unk4[i]);
            }
        }
    }
    D_80382410.unk1C = 0.0f;
}

void func_8030B3C8(void){
    D_80382410.unk1C += time_getDelta();
}