#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include <core1/viewport.h>
#include "core2/modelRender.h"

extern BKCollisionTri *func_8028EF48(void);
extern void func_8030E9FC(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, f32 arg4[3], f32 arg5, f32 arg6);
extern void func_8030EA54(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, f32 arg4[3], f32 arg5, f32 arg6);
extern void func_8031CE28(s32, s32, f32);
void timed_exitStaticCamera(f32);
extern int func_802E805C(BKCollisionList *, BKVertexList *, f32[3], s32, f32, s32, s32, s32, s32);
extern void func_80340200(s32, f32[3], s32, f32, s32, s32, BKVertexList *, s32);
extern void func_802E9118(BKCollisionList *, BKVertexList *, f32[3], s32, f32, s32, s32, f32, s32, s32, s32);
extern void func_802E9DD8(BKCollisionList *, BKVertexList *, f32[3], s32, f32, s32, f32, s32, s32);
extern int func_80340020(s32, f32[3], s32, f32, s32, BKVertexList *, f32[3], f32[3]);

extern void boneTransformList_getBoneScale(s32, s32, f32[3]);
extern void boneTransformList_setBoneScale(s32, s32, f32[3]);
extern void func_8033A9A8(s32, s32, f32[3]);
extern void ml_vec3f_normalize(f32[3]);
extern void func_8033A45C(s32, s32);
extern void modelRender_setBoneTransformList(s32);
extern void func_8028FAB0(f32[3]);
extern void baModel_802921D4(f32[3]);

/* .data */
f32 D_80389C00[3] = {5700.0f, 4300.0f, 0.0f};
f32 D_80389C0C[3] = {0.0f,  27.0f, 0.0f};
f32 D_80389C18[3] = {0.0f, -27.0f, 0.0f};
f32 D_80389C24[3] = {4000.0f, 3500.0f, 0.0f};

/* .bss */
struct {
    s32 unk0;
    u8 sfxsourceIdx;
    //u8 pad5[0x3];
    f32 unk8;
    f32 unkC[3];
    s32 unk18;
    BKCollisionList *unk1C;
    u8 unk20;
    u8 unk21;
    //u8 pad22[0x2];
    BKModelBin * unk24;
    f32 unk28[3];
    struct5Bs *unk34;
    f32 unk38;
    f32 unk3C;
    BKVertexList *unk40;
    BKVertexList *unk44;
    u8 unk48;
    u8 unk49;
    //u8 pad4A[2];
    f32 unk4C;
    s32 unk50;
    f32 unk54;
}D_80389FA0;

s32 func_80388360(s32 arg0, s32 arg1, s32 arg2, s32 arg3){
    s32 out_v0;

    out_v0 = func_802E805C(D_80389FA0.unk1C, D_80389FA0.unk40, D_80389FA0.unk28, 0, 1.0f, arg0, arg1, arg2, arg3);
    if(out_v0 && func_8029453C()){
        func_80340200(D_80389FA0.unk18, D_80389FA0.unk28, 0, 1.0f, 0, out_v0, D_80389FA0.unk40, arg1);
    
    }
    return out_v0;
}

void func_80388428(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5){
    func_802E9118(D_80389FA0.unk1C, D_80389FA0.unk40, D_80389FA0.unk28, 0, 1.0f, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_803884A8(s32 arg0, f32 arg1, s32 arg2, s32 arg3){
    func_802E9DD8(D_80389FA0.unk1C, D_80389FA0.unk40, D_80389FA0.unk28, 0, 1.0f, arg0, arg1, arg2, arg3);
}

void func_80388518(s32 arg0){
    s32 sp24;
    if(D_80389FA0.unk21 == 2){
        func_8030E394(D_80389FA0.sfxsourceIdx);
        func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.6f, 20000);
        func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.8f, 20000);
        func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 0.9f, 20000);
        func_8030E760(SFX_7F_HEAVYDOOR_SLAM, 1.0f, 20000);
    }//L80388594
    sp24 = D_80389FA0.unk21;
    D_80389FA0.unk21 = arg0;
    D_80389FA0.unk38 = 0.0f;
    if(D_80389FA0.unk21 == 1){
        skeletalAnim_set(D_80389FA0.unk0, ASSET_C3_ANIM_CLANKER_IDLE, 0.0f, 10.0f);
    }
    if(D_80389FA0.unk21 == 2){
        func_8030DD90(D_80389FA0.sfxsourceIdx, 0);
        sfxsource_playSfxAtVolume(D_80389FA0.sfxsourceIdx, 1.0f);
        sfxsource_setSfxId(D_80389FA0.sfxsourceIdx, SFX_7D_ANCHOR_LIFTING);
        func_8030DD14(D_80389FA0.sfxsourceIdx, 3);
        sfxsource_setSampleRate(D_80389FA0.sfxsourceIdx, 27000);
        func_8030E2C4(D_80389FA0.sfxsourceIdx);
    }

    if(D_80389FA0.unk21 == 3){
        if(sp24 != 2){
            skeletalAnim_set(D_80389FA0.unk0, ASSET_C3_ANIM_CLANKER_IDLE, 0.0f, 10.0f);
        }
        D_80389FA0.unk28[1] = 1100.0f;
    }
}

void func_80388664(void) {
    jiggy_spawn(JIGGY_17_CC_CLANKER_RAISED, D_80389C00);
}

void CC_func_8038868C(void) {
    func_80324E38(0, 3);
    timed_setStaticCameraToNode(0, 0);
    timed_setStaticCameraToNode(5.5f, 1);
    timed_setStaticCameraToNode(7.0f, 2);
    timed_setStaticCameraToNode(12.5f, 3);
    timedFunc_set_0(13.0f, &func_80388664);
    timed_setStaticCameraToNode(16.0f, 1);
    if (jiggyscore_isCollected(JIGGY_17_CC_CLANKER_RAISED) == 0) {
        func_80324DBC(18.0f, 0xD2C, 4, NULL, NULL, NULL, 0);
    }
    timed_exitStaticCamera(18.0f);
    func_80324E38(18.0f, 0);
}


void CC_func_80388760(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    BKVertexList *tmp_v0;
    s32 s1;
    f32 spA4[3];
    f32 sp98[3];
    int i;
    s32 tmp_s0;
    f32 sp84[3];
    s32 pad80;
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    

    if(D_80389FA0.unk21 == 0)
        return;
    
    viewport_getPosition_vec3f(sp98);
        
    if(sp98[0] <  -2600.0f || 11600.0f < sp98[0])
        return;

    s1 = skeletalAnim_getBoneTransformList(D_80389FA0.unk0);
    boneTransformList_getBoneScale(s1, 0x40, sp84);
    for( i = 0; i < 3; i++){
        sp84[i] = sp84[i] + (1.3 - sp84[i])*D_80389FA0.unk8;
    }

    boneTransformList_setBoneScale(s1, 0x40, sp84);

    if(D_80389FA0.unk21 == 1){
        func_8033A9A8(s1, 0x44, D_80389C0C);
        func_8033A9A8(s1, 0x45, D_80389C0C);
        func_8033A9A8(s1, 0x46, D_80389C0C);

        func_8033A9A8(s1, 0x47, D_80389C18);
        func_8033A9A8(s1, 0x48, D_80389C18);
        func_8033A9A8(s1, 0x49, D_80389C18);
    }

    player_getPosition(spA4);

    for(i = 0; i < 2; i++){//L803888FC
        func_8034A174(D_80389FA0.unk34, (i == 0) ? 0x10 : 0xf, sp74);
        sp68[0] = spA4[0] - sp74[0];
        sp68[1] = spA4[1] - sp74[1];
        sp68[2] = spA4[2] - sp74[2];
        ml_vec3f_normalize(sp68);

        sp5C[0] = 0.0f;
        sp5C[1] = sp68[2]*45.0f;
        sp5C[2] = -sp68[1]*45.0f;
        func_8033A9A8(s1, (i == 0)?0x42:0x43, sp5C);
    }
    tmp_v0 = D_80389FA0.unk40;
    D_80389FA0.unk40 = D_80389FA0.unk44;
    D_80389FA0.unk44 = tmp_v0;

    func_8033A45C(1, (D_80389FA0.unk21 == 3) ? 1 : 0);
    tmp_s0 = (sp98[0] < 100.0f)? 0 : 1;
    func_8033A45C(2, 1);
    func_8033A45C(3, 1);
    func_8033A45C(4, tmp_s0);
    func_8033A45C(5, tmp_s0);
    func_8033A45C(6, tmp_s0);
    func_8033A45C(7, tmp_s0);
    func_8033A45C(8, tmp_s0);
    if(tmp_s0){
        tmp_s0 = (s32)(D_80389FA0.unk4C*3.99 + 1.0);
        func_8033A45C(2, tmp_s0);
        func_8033A45C(3, tmp_s0);
    }
    modelRender_setBoneTransformList(s1);
    func_8033A450(D_80389FA0.unk34);
    modelRender_setVertexList(D_80389FA0.unk40);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gfx, mtx, D_80389FA0.unk28, NULL, 1.0f, NULL, D_80389FA0.unk24);
    if(func_80340020(D_80389FA0.unk18, D_80389FA0.unk28, 0, 1.0f, 0, D_80389FA0.unk40, spA4, spA4)){
        func_8028FAB0(spA4);
        baModel_802921D4(spA4);
    }
}

void func_80388B4C(s32 arg0) {
    func_8034A174(D_80389FA0.unk34, 5, arg0);
}

void func_80388B78(f32 arg0[3], f32 arg1[3]){
    func_8034A174(D_80389FA0.unk34, 7, arg0);
    func_8034A174(D_80389FA0.unk34, 8, arg1);
}

void func_80388BBC(f32 arg0[3], f32 arg1[3]){
    func_8034A174(D_80389FA0.unk34, 9, arg0);
    func_8034A174(D_80389FA0.unk34, 10, arg1);
}

void func_80388C00(s32 arg0, s32 arg1){
    func_8031CD20(arg0, 0xb, 3);
}

void func_80388C28(s32 arg0, s32 arg1){
    func_8031CD20(arg0, 0xb, 4);
}

void func_80388C50(s32 arg0, s32 arg1){
    func_8031CD20(arg0, 0xb, 1);
}

void CC_func_80388C78(s32 arg0, s32 arg1){
    func_8031CD20(arg0, 0xb, 2);
}

int CC_func_80388CA0(void){
    return D_80389FA0.unk21 == 3;
}

void func_80388CB4(void){
    if(D_80389FA0.unk21){
        skeletalAnim_free(D_80389FA0.unk0);
        sfxsource_freeSfxsourceByIndex(D_80389FA0.sfxsourceIdx);
        func_80340690(D_80389FA0.unk18);
        func_8034A2A8(D_80389FA0.unk34);
        if(model_getVtxList(D_80389FA0.unk24) != D_80389FA0.unk40)
            vtxList_free(D_80389FA0.unk40);
        if(model_getVtxList(D_80389FA0.unk24) != D_80389FA0.unk44)
            vtxList_free(D_80389FA0.unk44);
        assetcache_release((void *)D_80389FA0.unk24);
        D_80389FA0.unk34 = NULL;
        D_80389FA0.unk0 = NULL;
        D_80389FA0.unk18 = NULL;
    }
}

void func_80388D54(void){
    D_80389FA0.unk21 = 0;
    if(map_get() == MAP_B_CC_CLANKERS_CAVERN){
        D_80389FA0.unk0 = skeletalAnim_new();
        D_80389FA0.sfxsourceIdx = sfxsource_createSfxsourceAndReturnIndex();
        D_80389FA0.unk8 = 1.0f;
        D_80389FA0.unk18 = func_803406B0();
        D_80389FA0.unk21 = 0;
        D_80389FA0.unk24 = assetcache_get(ASSET_88E_MODEL_CLANKER_CHAIN);
        D_80389FA0.unk1C = model_getCollisionList(D_80389FA0.unk24);
        D_80389FA0.unk34 = func_8034A2C8();
        D_80389FA0.unk3C = 1.0f;
        D_80389FA0.unk40 = model_getVtxList(D_80389FA0.unk24);
        D_80389FA0.unk44 = vtxList_clone(D_80389FA0.unk40);
        D_80389FA0.unk48 = 0;
        D_80389FA0.unk49 = 0;
        D_80389FA0.unk50 = 0;
        D_80389FA0.unk4C = 0.0f;
        D_80389FA0.unk54 = 1.0f;
        D_80389FA0.unk28[0] = 5500.0f;
        D_80389FA0.unk28[2] = 0.0f;
        D_80389FA0.unk28[1] = 0.0f;
        func_80320B24(func_80388360, func_80388428, func_803884A8);
        if(!nodeProp_findPositionFromActorId(0x3B, D_80389FA0.unkC)){
            D_80389FA0.unkC[0] = 0.0f;
            D_80389FA0.unkC[1] =-1e+06f;
            D_80389FA0.unkC[2] = 0.0f;
        }
        if(jiggyscore_isSpawned(JIGGY_17_CC_CLANKER_RAISED)){
            func_80388518(3);
        }
        else{
            func_80388518(1);
        }
    }
}

void func_80388EA4(void){
    if(D_80389FA0.unk21 == 1){
        func_80388518(2);
    }
}

void func_80388ED4(s32 arg0){
    f32 sp1C[3];
    func_8034A174(D_80389FA0.unk34, 5, sp1C);
    if(arg0 != 0){
        FUNC_8030E8B4(SFX_91_METALLIC_SOUND, 0.7f, 32675, sp1C, 100, 6000);
    }
    else{
        FUNC_8030E8B4(SFX_82_METAL_BREAK, 0.9f, 24000, sp1C, 100, 6000);
    }
    D_80389FA0.unk8 = 1.0f;
}

void CC_func_80388F4C(void){
    f32 sp6C[3];
    f32 sp68 = time_getDelta();
    f32 sp64;
    f32 sp60;
    f32 sp54[3];
    f32 sp48[3];
    BKCollisionTri *tmp_v0;
    f32 pad[3];

    CC_func_80387D4C();
    if(D_80389FA0.unk21 != 0 && func_80334904() == 2){
        player_getPosition(sp6C);
        D_80389FA0.unk20 = (ml_distance_vec3f(sp6C, D_80389FA0.unkC) < 200.0f);

        D_80389FA0.unk38 += sp68;
        sp64 = skeletalAnim_getProgress(D_80389FA0.unk0);
        skeletalAnim_update(D_80389FA0.unk0, sp68, 1);
        sp60 = skeletalAnim_getProgress(D_80389FA0.unk0);
        if(D_80389FA0.unk21 == 3){
            func_8034A174(D_80389FA0.unk34, 5, sp54);
            if(sp60 < sp64){
                FUNC_8030E8B4(SFX_7E_CREAKY_DOOR_OPENING, 0.6f, 32300, sp54, 1000, 5000);
            }//L80389058

            if(sp64 < 0.3 && 0.3 <= sp60){
                FUNC_8030E8B4(SFX_7E_CREAKY_DOOR_OPENING, 0.5f, 32300, sp54, 1000, 5000);
            }
        }//L8038909C

        if(D_80389FA0.unk21 == 2){
            D_80389FA0.unk28[1] += 100.0f*sp68;
        }

        if(0.0f < D_80389FA0.unk8){
            D_80389FA0.unk8  -= sp68/2;
            if(D_80389FA0.unk8 <= 0.0f)
                D_80389FA0.unk8 = 0.0f;
        }

        if(D_80389FA0.unk21 == 1){
            if(D_80389FA0.unk20 && skeletalAnim_getAnimId(D_80389FA0.unk0) != ASSET_C4_ANIM_CLANKER_BITE){
                skeletalAnim_set(D_80389FA0.unk0, ASSET_C4_ANIM_CLANKER_BITE, 1.0f, 10.0f);
                if(!D_80389FA0.unk48){
                    gcdialog_showText(ASSET_D2B_TEXT_UNKNOWN, 0xE, D_80389FA0.unk28, NULL, NULL, NULL);
                    D_80389FA0.unk48 = TRUE;
                }
            }//L8038918C
            
            if(!D_80389FA0.unk20 && skeletalAnim_getAnimId(D_80389FA0.unk0) == ASSET_C4_ANIM_CLANKER_BITE){
                skeletalAnim_set(D_80389FA0.unk0, ASSET_C3_ANIM_CLANKER_IDLE, 1.0f, 10.0f);
            }
        }//L803891BC

        if(D_80389FA0.unk21 == 2){
            func_803114D0();
            if(1100.0f <= D_80389FA0.unk28[1]){
                func_80388518(3);
            }
        }//L803891F8

        if(D_80389FA0.unk21 == 3){
            func_8034A174(D_80389FA0.unk34, 6, sp48);
            if(ml_distance_vec3f(sp48, sp6C) <= 130.0f && sp6C[1] - sp48[1] < 50.0f){
                func_8031D04C(0x21, 1);
            }
        }//L80389260

        if( D_80389FA0.unk21 == 3){
            tmp_v0 = func_8028EF48();
            if( tmp_v0 && !D_80389FA0.unk49
            ){
                if(tmp_v0->flags & 2){
                    func_8031CE28(0x22, 5, 180.0f);
                    D_80389FA0.unk49++;
                }
                else if(tmp_v0->flags & 4){
                    func_8031CE28(0x22, 4, 0.0f);
                    D_80389FA0.unk49++;
                }
            }
        }//L803892DC
        if(ml_timer_update(&D_80389FA0.unk3C, sp68)){
            if(D_80389FA0.unk21 == 3){
                func_8030E9FC(SFX_D0_GRIMLET_SQUEAK, 0.5f, 0.7f, 20000, D_80389C24, 2000.0f, 4000.0f);
            }else{
                func_8030EA54(SFX_D0_GRIMLET_SQUEAK, 0.5f, 0.7f, 20000, D_80389C24, 2000.0f, 4000.0f);
            }//L80389384
            D_80389FA0.unk3C = randf2(3.0f, 6.0f);
        }//L803893A0
        if(D_80389FA0.unk50 == 0){
            if(ml_timer_update(&D_80389FA0.unk54, sp68))
                D_80389FA0.unk50 = 1;
        }

        if(D_80389FA0.unk50){
            D_80389FA0.unk4C += D_80389FA0.unk50 * ((sp68 * 30.0)/4);
            if(1.0f < D_80389FA0.unk4C){
                D_80389FA0.unk50 = -1;
                D_80389FA0.unk4C = 1.0f;
            }
            else if(D_80389FA0.unk4C < 0.0f){
                D_80389FA0.unk50 = 0;
                D_80389FA0.unk4C = 0.0f;
                D_80389FA0.unk54 = randf2(0.1f, 7.0f);
            }
        }
    }//L80389490

}

void func_803894A0(void){
    if(D_80389FA0.unk34)
        D_80389FA0.unk34 = func_8034A348(D_80389FA0.unk34);
    
    if(D_80389FA0.unk0)
        D_80389FA0.unk0 =  defrag(D_80389FA0.unk0);

    if(D_80389FA0.unk18)
        D_80389FA0.unk18 = func_803406D4(D_80389FA0.unk18);
}
