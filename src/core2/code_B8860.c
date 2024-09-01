#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void mlMtxRotatePYR(f32, f32, f32);
extern void func_80252330(f32, f32, f32);
extern void mlMtxApply(Mtx *);

typedef struct {
    BKSprite *sprite_0;
    f32 unk4[3];
    f32 unk10[3];
    f32 unk1C;
    s16 unk20[2];
    u8 color[3];
    u8  unk27;
    u32 frame_28_31:8;
    u32 unk28_23:2;
    u32 unk28_21:8;
    u32 unk28_13:1;
    u32 unk28_12:1;
    u32 pad28_11:12;
} Struct_B8860_0s;

void func_8033FE6C(u8 arg0, f32 arg1);
f32 func_8033FE9C(u8 arg0);
void func_8033FB64(u8 arg0);

/* .bss */
Struct_B8860_0s D_80385000[0x32];

/* .code */
void func_8033F7F0(u8 arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Struct_B8860_0s *sp54;
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];

    sp54 = &D_80385000[arg0];
    if(sp54->unk28_23 != 1){
        ml_vec3f_copy(sp48,  sp54->unk4);
        sp48[1] += (sp54->unk1C*sp54->unk20[1])/100.0;
        viewport_get_position_vec3f(sp3C);
        ml_vec3f_diff_copy(sp30, sp48, sp3C);
        if(sp54->unk28_12){
            mlMtxSet(func_8024DD90());
        }
        else{
            mlMtxIdent();
        }
        mlMtxRotatePYR(sp54->unk10[0], sp54->unk10[1], sp54->unk10[2]);
        func_80252330(sp30[0], sp30[1], sp30[2]);
        mlMtxApply(*mtx);
        gSPMatrix((*gfx)++, OS_PHYSICAL_TO_K0((*mtx)++), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_803382E4(sp54->unk28_21);
        func_80338338(sp54->color[0], sp54->color[1],sp54->color[2]);
        func_803382FC(sp54->unk27);
        func_80338308(sp54->unk20[0], sp54->unk20[1]);
        func_8033837C(1);
        func_80338370();
        spriteRender_draw(gfx, vtx, sp54->sprite_0, sp54->frame_28_31);
        gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    }
}

void func_8033F9C0(void){
    int i;
    for(i = 1; i < 0x32; i++){
        D_80385000[i].unk28_13 = 0;
    }
}

void func_8033FA24(void){
    int i;
    for(i = 1; i < 0x32; i++){
        if(D_80385000[i].unk28_13){
            func_8033FB64(i);
        }
    }
}

u8 func_8033FA84(void){
    int i;
    for(i = 1; i < 0x32; i++){
        if(!D_80385000[i].unk28_13){
            ml_vec3f_clear(D_80385000[i].unk4);
            ml_vec3f_clear(D_80385000[i].unk10);
            D_80385000[i].frame_28_31 = 0;
            D_80385000[i].unk28_13 = TRUE;
            D_80385000[i].unk28_23 = 0;
            D_80385000[i].unk28_21 = 0xb;
            D_80385000[i].sprite_0 = NULL;
            D_80385000[i].unk28_12 = TRUE;
            D_80385000[i].unk20[0] = 100;
            D_80385000[i].unk20[1] = 100;
            D_80385000[i].color[0] = 0xff;
            D_80385000[i].color[1] = 0xff;
            D_80385000[i].color[2] = 0xff;
            D_80385000[i].unk27 = 0xff;
            D_80385000[i].unk1C = 0.0f;
            return i;
        }
    }
    return 0;
}

void func_8033FB64(u8 arg0){
    if(D_80385000[arg0].sprite_0){
        func_8033BD4C(D_80385000[arg0].sprite_0);
    }
    D_80385000[arg0].sprite_0 = NULL;
    D_80385000[arg0].unk28_13 = 0;
}

void projectile_setSprite(u8 arg0, enum asset_e arg1){
    if(D_80385000[arg0].sprite_0){
        func_8033BD4C(D_80385000[arg0].sprite_0);
    }
    D_80385000[arg0].sprite_0 = assetcache_get(arg1);
}

void func_8033FC34(u8 arg0, s32 arg1){
    D_80385000[arg0].unk27 = arg1;
}

void func_8033FC60(u8 arg0, s32 r, s32 g, s32 b){
    D_80385000[arg0].color[0] = r;
    D_80385000[arg0].color[1] = g;
    D_80385000[arg0].color[2] = b;
}

void func_8033FC98(u8 arg0, s32 arg1){
    D_80385000[arg0].unk28_23 = arg1;
}

void func_8033FCD8(u8 arg0, s32 arg1){
    D_80385000[arg0].unk28_21 = arg1;
}

void func_8033FD20(u8 arg0, s32 arg1){
    D_80385000[arg0].unk28_12 = arg1;
}

s32 func_8033FD64(u8 arg0){
    return D_80385000[arg0].unk28_23;
}

//projectile?_setRotation
void func_8033FD98(u8 arg0, f32 arg1[3]){
    ml_vec3f_copy(D_80385000[arg0].unk10, arg1);
}

//projectile?_getRotation
void func_8033FDE0(u8 arg0, f32 arg1[3]){
    ml_vec3f_copy(arg1, D_80385000[arg0].unk10);
}

void func_8033FE2C(u8 arg0, f32 arg1){
    func_8033FE6C(arg0, mlNormalizeAngle(func_8033FE9C(arg0) + arg1));
}

//projectile?_setRoll
void func_8033FE6C(u8 arg0, f32 arg1){
    D_80385000[arg0].unk10[2] = arg1;
}

//projectile?_getRoll
f32 func_8033FE9C(u8 arg0){
    return D_80385000[arg0].unk10[2];
}

void projectile_setPosition(u8 arg0, f32 arg1[3]){
    ml_vec3f_copy(D_80385000[arg0].unk4, arg1);
}

void projectile_getPosition(u8 arg0, f32 arg1[3]){
    ml_vec3f_copy(arg1, D_80385000[arg0].unk4);
}

void func_8033FF5C(u8 arg0, f32 arg1){
    D_80385000[arg0].unk1C = arg1;
}

f32 func_8033FF8C(u8 arg0){
    return D_80385000[arg0].unk1C;
}

void func_8033FFB8(u8 arg0, s32 frame){
    D_80385000[arg0].frame_28_31 = frame;
}

void func_8033FFE4(u8 arg0, s32 arg1, s32 arg2){
    D_80385000[arg0].unk20[0] = arg1;
    D_80385000[arg0].unk20[1] = arg2;
}
