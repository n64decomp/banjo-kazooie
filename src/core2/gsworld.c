#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"

#include "core2/anim/sprite.h"
#include <core2/file.h>
#include "core2/particle.h"

struct gsworld_data_s {
    s32 unk0; // probably game_mode_e
    enum map_e map;
    s32 exit;
};

static u8 sHackDetected = FALSE; // seems related to some sort of cheatcode hack detection
struct gsworld_data_s sGsWorldData;
static bool sEnableUpdate;
static bool sEnableDraw;

void gsworld_draw(Gfx** gfx, Mtx **mtx, Vtx **vtx) {
    f32 near, far;

    if (!sEnableDraw) {
        drawRectangle2D(gfx, 0, 0, gFramebufferWidth, gFramebufferHeight, 0, 0, 0);
        func_802BBD2C(&near, &far);
        viewport_setNearAndFar(near, far);
        viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);
        return;
    }

    if (!func_80320708()) {
        eeprom_writeBlocks(0, 0, (void *) 0x80BC7230, EEPROM_MAXBLOCKS);
    }

    spawnQueue_unlock();
    sky_draw(gfx, mtx, vtx);
    func_802BBD2C(&near, &far);
    viewport_setNearAndFar(near, far);
    viewport_setRenderViewportAndPerspectiveMatrix(gfx, mtx);

    if (mapModel_has_xlu_bin()) {
        mapModel_opa_draw(gfx, mtx, vtx);
        if (!game_is_frozen()) {
            func_80322E64(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            player_draw(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            func_80302C94(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            jiggylist_draw(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            func_803500D8(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            func_802F2ED0(func_8032994C(), gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            partEmitMgr_drawPass0(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            mapModel_xlu_draw(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            func_8032D3D8(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            partEmitMgr_drawPass1(gfx, mtx, vtx);
        }
        if (!game_is_frozen()) {
            func_8034F6F0(gfx, mtx, vtx);
        }
        func_802D520C(gfx, mtx, vtx);
    } else {
        mapModel_opa_draw(gfx, mtx, vtx);
        func_80322E64(gfx, mtx, vtx);
        func_8034F6F0(gfx, mtx, vtx);
        player_draw(gfx, mtx, vtx);
        func_80302C94(gfx, mtx, vtx);
        func_8032D3D8(gfx, mtx, vtx);
        jiggylist_draw(gfx, mtx, vtx);
        func_803500D8(gfx, mtx, vtx);
        func_802F2ED0(func_8032994C(), gfx, mtx, vtx);
        func_802D520C(gfx, mtx, vtx);
        partEmitMgr_draw(gfx, mtx, vtx);
    }

    if (!game_is_frozen()) {
        func_80350818(gfx, mtx, vtx);
    }

    if (!game_is_frozen()) {
        func_802BBD0C(gfx, mtx, vtx);
    }

    spawnQueue_lock();
}

void gsworld_stub1(s32 arg0, s32 arg1, s32 arg2) {}

enum map_e gsworld_getMap(void) {
    return sGsWorldData.map;
}

s32 gsworld_getExit() {
    return sGsWorldData.exit;
}

void gsworld_transitionToExit(s32 exit) {
    transitionToMap(sGsWorldData.map, exit, 1);
}

s32 gsworld_getUnk0() {
    return sGsWorldData.unk0;
}

void gsworld_free(void) {
    func_80255A14();
    gsworld_setUnk0(3);
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
    print_freeBoldLetterFont();
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
    if (!func_802E4A08()) {
        itemPrint_free();
    }
    dialogBin_terminate();
    func_802986D0();
    if (!func_80322914()) {
        func_8024F7C4(func_803226E8(sGsWorldData.map));
    }
    core1_7090_release();
    AnimTextureListCache_free();
    func_80322FDC();
    func_8033BD6C();
    func_80255198();//heap_flush_free_queue
    animCache_flushAll();
}

void gsworld_set(enum map_e map, s32 exit, bool reload) {
    sGsWorldData.unk0 = 3;
    sGsWorldData.map = map;
    sGsWorldData.exit = exit;
    overlay_init();
    gsworld_setEnableUpdate(TRUE);
    gsworld_setEnableDraw(TRUE);
    func_802D2CB8();
    core1_7090_alloc();
    if (gsworld_getMap() == MAP_8E_GL_FURNACE_FUN) {
        func_8038E7C4();
    }
    if (!func_80322914()) {
        func_8024F764(func_803226E8(sGsWorldData.map));
    }
    func_80320B84();
    AnimTextureListCache_init();
    func_8034C97C();
    func_8030A078();
    func_8031B718();
    func_80298700();
    if (!func_802E4A08()) {
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
    nccamera_init();
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
    if (!reload) {
        gsworld_load(map);
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
    func_802BC2CC(sGsWorldData.exit);
    func_802D63D4();
    func_80255A04();
    func_802D6948();
    if (!func_802E4A08()) {
        print_resetBoldFontTexture();
    }
    if (map != MAP_1F_CS_START_RAREWARE) {
        func_8024F150();
    }
}

void gsworld_reload(void) {
    gsworld_free();
    gsworld_set(sGsWorldData.map, sGsWorldData.exit, TRUE);
}

void gsworld_stub2(void) {
    gsworld_stub3(sGsWorldData.map);
}

void gsworld_setUnk0(s32 value) {
    core1_15B30_sendMesg3ToRenderThread();
    func_802BC21C(sGsWorldData.unk0, value);
    func_8028F7F4(sGsWorldData.unk0, value);
    func_8030D8A8(sGsWorldData.unk0, value);
    func_803045CC(sGsWorldData.unk0, value);
    func_80323140(sGsWorldData.unk0, value);
    func_80351A1C(sGsWorldData.unk0, value);
    func_803225B0(sGsWorldData.unk0, value);
    func_80323098(sGsWorldData.unk0, value);
    func_802F0E80(sGsWorldData.unk0, value);
    commonParticle_setActive(sGsWorldData.unk0, value);
    sGsWorldData.unk0 = value;
}

s32 gsworld_update(void) {
    u32 time_mask, time, delay;

    codeCF5F0_forgetAllAbilitiesExceptClawSwipeIfChecksumsFail();
    func_802D5628();
    itemPrint_update();
    if (getGameMode() != GAME_MODE_4_PAUSED) {
        func_802F7E54();
    }
    if (!sEnableUpdate) {
        return 1;
    } else {
        func_802BAF40();
        func_8032AA9C();
        func_80323170();
        func_80351C48();
        func_80330FF4();
        func_8028E71C();

        time = globalTimer_getTime();
        time_mask = sHackDetected ? 0x0F : 0x1F;
        if (((time_mask & time) == 3) &&
            (overlayManagergetLoadedId() == OVERLAY_5_BEACH) &&
            (!maCastle_isSecretCheatCodeRelatedValueEqualToScrambledAddressValue() || sHackDetected))
        {
            sHackDetected = TRUE;
            for (delay = 0; delay != 150000000; delay++);
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
        if (!mapSpecificFlags_validateCRC1()) {
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
        if (map_getLevel(sGsWorldData.map) == LEVEL_D_CUTSCENE) {
            func_802C79C4();
        }
        func_8032AABC();
        sns_stub();
        return 1;
    }
}

void gsworld_setEnableUpdate(bool value) {
    sEnableUpdate = value;
}

bool gsworld_getEnableUpdate() {
    return sEnableUpdate;
}

void gsworld_setEnableDraw(bool value) {
    sEnableDraw = value;
}

bool gsworld_getEnableDraw() {
    return sEnableDraw;
}

void gsworld_load(enum map_e map_id) {
    File *f;

    core1_15B30_sendMesg3ToRenderThread();

    f = file_openMap(map_id);

    while (!file_isNextByteExpected(f, 0)) {
        if (file_isNextByteExpected(f, 2)) {
            /* NO OP */
        } else if (file_isNextByteExpected(f, 1)) {
            cubeList_fromFile(f);
        } else if (file_isNextByteExpected(f, 3)) {
            ncCameraNodeList_fromFile(f);
        } else if (file_isNextByteExpected(f, 4)) {
            lightingVectorList_fromFile(f);
        }
    }

    file_close(f);
}

void gsworld_stub3(enum map_e map) {}
