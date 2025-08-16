#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include "core2/anim/sprite.h"
#include <core2/file.h>
#include "core2/particle.h"

/* .data */
extern u8 D_80370250 = 0;

/* .bss */
struct {
    s32 unk0;
    s32 map_4;
    s32 unk8;
}D_803835D0;
s32 D_803835DC;
u32 D_803835E0;

/* public */
void func_80335110(s32);
void func_80335128(s32);
void func_80335140(enum map_e);
void func_8033520C(s32);

/* .code */
void func_80334540(Gfx** gdl, Mtx **mptr, Vtx **vptr) {
    f32 sp44;
    f32 sp40;

    if (D_803835E0 == 0) {
        drawRectangle2D(gdl, 0, 0, gFramebufferWidth, gFramebufferHeight, 0, 0, 0);
        func_802BBD2C(&sp44, &sp40);
        viewport_setNearAndFar(sp44, sp40);
        viewport_setRenderViewportAndPerspectiveMatrix(gdl, mptr);
        return;
    }
    if (func_80320708() == 0) {
        eeprom_writeBlocks(0, 0, 0x80BC7230, EEPROM_MAXBLOCKS);
    }
    spawnQueue_unlock();
    sky_draw(gdl, mptr, vptr);
    func_802BBD2C(&sp44, &sp40);
    viewport_setNearAndFar(sp44, sp40);
    viewport_setRenderViewportAndPerspectiveMatrix(gdl, mptr);
    if (mapModel_has_xlu_bin() != 0) {
        mapModel_opa_draw(gdl, mptr, vptr);
        if (game_is_frozen() == 0) {
            func_80322E64(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            player_draw(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            func_80302C94(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            jiggylist_draw(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            func_803500D8(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            func_802F2ED0(func_8032994C(), gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            partEmitMgr_drawPass0(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            mapModel_xlu_draw(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            func_8032D3D8(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            partEmitMgr_drawPass1(gdl, mptr, vptr);
        }
        if (game_is_frozen() == 0) {
            func_8034F6F0(gdl, mptr, vptr);
        }
        func_802D520C(gdl, mptr, vptr);
    } else {
        mapModel_opa_draw(gdl, mptr, vptr);
        func_80322E64(gdl, mptr, vptr);
        func_8034F6F0(gdl, mptr, vptr);
        player_draw(gdl, mptr, vptr);
        func_80302C94(gdl, mptr, vptr);
        func_8032D3D8(gdl, mptr, vptr);
        jiggylist_draw(gdl, mptr, vptr);
        func_803500D8(gdl, mptr, vptr);
        func_802F2ED0(func_8032994C(), gdl, mptr, vptr);
        func_802D520C(gdl, mptr, vptr);
        partEmitMgr_draw(gdl, mptr, vptr);
    }
    if (game_is_frozen() == 0) {
        func_80350818(gdl, mptr, vptr);
    }
    if (game_is_frozen() == 0) {
        func_802BBD0C(gdl, mptr, vptr);
    }
    spawnQueue_lock();
}

void func_803348B0(s32 arg0, s32 arg1, s32 arg2){
}

enum map_e map_get(void){
    return D_803835D0.map_4;
}

s32 exit_get(){
    return D_803835D0.unk8;
}

void func_803348D8(s32 arg0) {
    transitionToMap(D_803835D0.map_4, arg0, 1);
}

s32 func_80334904(){
    return D_803835D0.unk0;
}

void func_80334E1C(s32);

void func_80334910(void) {
    func_80255A14();
    func_80334E1C(3);
    func_8034F734();
    func_803500E8();
    func_80350BC8();
    func_8030F1D0();
    gcparade_free();//null
    func_80322F7C();
    func_803518E8();
    func_802D48F0();
    func_803224FC();
    func_8028E644();
    func_80322F5C();
    func_80341A54();
    spawnQueue_free();
    func_802F53D0();
    func_802FAC3C();
    bundle_free();
    commonParticle_freeAllParticles();
    func_8033FA24();
    func_80344C80();
    animsprite_terminate();
    animBinCache_free();
    func_802BC10C();
    ncCameraNodeList_free();
    pem_freeDependencies();
    pem_freeAll();
    partEmitMgr_free();
    func_802F7CE0();
    func_8031F9E0();
    func_80323100();
    cubeList_free();
    func_8031B710();
    mapModel_free();
    propModelList_free();
    lighting_free();
    sky_free();
    func_8034C8D8();
    func_80323238();
    func_803343AC();
    func_803308A0();
    func_8032AEB4();
    func_8033297C();
    func_803231E8();
    func_80320B7C();
    func_802BAF20();
    code7AF80_freeTotalCounts();
    func_80332A38();
    if (func_802E4A08() == 0) {
        itemPrint_free();
    }
    dialogBin_terminate();
    func_802986D0();
    if (func_80322914() == 0) {
        func_8024F7C4(func_803226E8(D_803835D0.map_4));
    }
    core1_7090_release();
    AnimTextureListCache_free();
    func_80322FDC();
    func_8033BD6C();
    func_80255198();//heap_flush_free_queue
    animCache_flushAll();
}

void func_80334B20(enum map_e map, s32 arg1, s32 arg2) {
    D_803835D0.unk0 = 3;
    D_803835D0.map_4 = map;
    D_803835D0.unk8 = arg1;
    overlay_init();
    func_80335110(1);
    func_80335128(1);
    func_802D2CB8();
    core1_7090_alloc();
    if (map_get() == MAP_8E_GL_FURNACE_FUN) {
        func_8038E7C4();
    }
    if (func_80322914() == 0) {
        func_8024F764(func_803226E8(D_803835D0.map_4));
    }
    func_80320B84();
    AnimTextureListCache_init();
    func_8034C97C();
    func_8030A078();
    func_8031B718();
    func_80298700();
    if (func_802E4A08() == 0) {
        itemPrint_init();
    }
    dialogBin_initialize();
    spawnQueue_malloc();
    func_803329AC();
    func_80350BFC();
    func_80323190();
    func_80332894();
    func_803305AC();
    func_8031F9E8();
    func_80323230();
    commonParticleType_init();
    animBinCache_init();
    animsprite_init();
    func_80344C50();
    func_8033F9C0();
    ncCameraNodeList_init();
    func_802BC044();
    partEmitMgr_init();
    pem_setAllInactive();
    pem_initDependencies();
    func_802F7D30();
    propModelList_init();
    lighting_init();
    sky_reset();
    func_803343D0();
    cubeList_init();
    func_802FA69C();
    commonParticle_init();
    if (arg2 == 0) {
        func_80335140(map);
    }
    func_80305990(0);
    func_8030C740();
    gcdialog_init();
    mapSpecificFlags_clearAll();
    func_803411B0();
    spawnQueue_reset();
    func_80322FBC();
    func_8028E4B0();
    func_80322F9C();
    func_80323120();
    func_803223AC();
    bundle_reset();
    func_8034F774();
    func_80350174();
    gcparade_init();
    func_80351998();
    func_802BC2CC(D_803835D0.unk8);
    func_802D63D4();
    func_80255A04();
    func_802D6948();
    if (func_802E4A08() == 0) {
        func_802F5188();
    }
    if (map != MAP_1F_CS_START_RAREWARE) {
        func_8024F150();
    }
}

void func_80334DC0(void) {
    func_80334910();
    func_80334B20(D_803835D0.map_4, D_803835D0.unk8, 1);
}

void func_80334DF8(void) {
    func_8033520C(D_803835D0.map_4);
}

void func_80334E1C(s32 arg0) {
    func_80254008();
    func_802BC21C(D_803835D0.unk0, arg0);
    func_8028F7F4(D_803835D0.unk0, arg0);
    func_8030D8A8(D_803835D0.unk0, arg0);
    func_803045CC(D_803835D0.unk0, arg0);
    func_80323140(D_803835D0.unk0, arg0);
    func_80351A1C(D_803835D0.unk0, arg0);
    func_803225B0(D_803835D0.unk0, arg0);
    func_80323098(D_803835D0.unk0, arg0);
    func_802F0E80(D_803835D0.unk0, arg0);
    commonParticle_setActive(D_803835D0.unk0, arg0);
    D_803835D0.unk0 = arg0;
}

s32 func_80334ECC(void) {
    s32 phi_v1;
    s32 phi_v0;

    func_80356734();
    func_802D5628();
    itemPrint_update();
    if (getGameMode() != GAME_MODE_4_PAUSED) {
        func_802F7E54();
    }
    if (D_803835DC == 0) {
        return 1;
    } else {
        func_802BAF40();
        func_8032AA9C();
        func_80323170();
        func_80351C48();
        func_80330FF4();
        func_8028E71C();
        phi_v0 = globalTimer_getTime();
        if (D_80370250) {
            phi_v1 = 0xF;
        } else {
            phi_v1 = 0x1F;
        }
        if (((phi_v1 & phi_v0) == 3) && (overlayManagergetLoadedId() == OVERLAY_5_BEACH)) {
            if ((maCastle_isSecretCheatCodeRelatedValueEqualToScrambledAddressValue() == FALSE) || (D_80370250 != 0)) {
                D_80370250 = (u8)1;
                for (phi_v0 = 0; phi_v0 != 0x8F0D180; phi_v0++){
                }
            }
        }
        commonParticle_update();
        pem_updateAll();
        animCache_update();
        animBinCache_update();
        ncCamera_update();
        func_803045D8();
        func_80332E08();
        func_803465E4();
        func_8031B790();
        func_8034C9D4();
        propModelList_flush(1);
        sky_update();
        partEmitMgr_update();
        func_8034F918();
        func_80350250();
        if (mapSpecificFlags_validateCRC1() == 0) {
            func_8028FCBC();
        }
        AnimTextureListCache_update();
        func_80350CA4();
        dialogBin_update();
        func_80310D2C();
        gcparade_update();
        overlay_update();
        func_80321924();
        func_80334428();
        cutscenetrigger_update();
        func_802D2CDC();
        func_803306C8(1);
        func_8032AD7C(1);
        func_80322490();
        if (map_getLevel(D_803835D0.map_4) == LEVEL_D_CUTSCENE) {
            func_802C79C4();
        }
        func_8032AABC();
        sns_stub();
        return 1;
    }
}

void func_80335110(s32 arg0){
    D_803835DC = arg0;
}

s32 func_8033511C(){
    return D_803835DC;
}

void func_80335128(s32 arg0){
    D_803835E0 = arg0;
}

s32 func_80335134(){
    return D_803835E0;
}

void func_80335140(enum map_e map_id) {
    File *fp;

    func_80254008();
    fp = file_openMap(map_id); //LevelSetupFile_Open
    while (file_isNextByteExpected(fp, 0) == 0) {
        if (file_isNextByteExpected(fp, 2)) {
            
        } else if (file_isNextByteExpected(fp, 1)) {
            cubeList_fromFile(fp);
        } else if (file_isNextByteExpected(fp, 3)) {
            ncCameraNodeList_fromFile(fp);
        } else if (file_isNextByteExpected(fp, 4)) {
            lightingVectorList_fromFile(fp);
        }
    }

    file_close(fp); //file close
}

void func_8033520C(s32 arg0) { }
