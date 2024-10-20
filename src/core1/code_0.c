#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "version.h"
#include "gc/gctransition.h"

#define MAIN_THREAD_STACK_SIZE 0x17F0

#if VERSION == VERSION_PAL
    extern s32 D_80000300;
#endif

s32 D_80275610 = 0;
s32 D_80275614 = 0;
u32 gGlobalTimer = 0;
u32 sDebugVar_8027561C[] = { 0x9, 0x4, 0xA, 0x3, 0xB, 0x2, 0xC, 0x5, 0x0,  0x1, 0x6, 0xD,  -1 }; // never used
u32 D_80275650 = VER_SELECT(0xAD019D3C, 0xA371A8F3, 0, 0); //SM_DATA_CRC_1
u32 D_80275654 = VER_SELECT(0xD381B72F, 0xD0709154, 0, 0); //SM_DATA_CRC_2
char sDebugVar_80275658[] = VER_SELECT("HjunkDire:218755", "HjunkDire:300875", "HjunkDire:", "HjunkDire:");

/* .bss */
u32 D_8027A130;
u8 pad_8027A138[0x400];
u64 sDebugVar_8027A538; // never used
u64 sDebugVar_8027A540; // never used
u8 sMainThreadStack[MAIN_THREAD_STACK_SIZE]; // The real size of the stack is unclear yet, maybe there are some out-optimized debug variables below the stack
OSThread sMainThread;
s32 gBootMap;
static bool sDisableInput;
static u64 sDebugVar_8027BEF0; // never used

extern u8 core2_TEXT_START[];

void func_8023DA20(s32 arg0){ 
    bzero(&D_8027A130, core2_TEXT_START - (u8*)&D_8027A130);
    osWriteBackDCacheAll();
    sns_find_and_parse_payload();
    osInitialize();
    initThread_create();
}

void func_8023DA74(void){
    func_8033BD6C();
    func_80255198(); //heap_flush_free_queue
}

void func_8023DA9C(s32 arg0){
    func_80254008();
    viMgr_clearFramebuffers();
    if (D_8027A130 == 4){
        func_802E3580();
    }
    if (D_8027A130 == 3){
        func_802E4170();
    }
    func_8023DA74();
    D_8027A130 = arg0;
    if (D_8027A130 == 3){
        func_802E4214(gBootMap);
    }
    if (D_8027A130 == 4){
        dummy_func_802E35D0();
    }
    ucode_stub1();
}

u32 globalTimer_getTimeMasked(u32 mask){
    return gGlobalTimer & mask;
}

s32 globalTimer_getTime(void){
    return gGlobalTimer;
}

void globalTimer_reset(void){
    gGlobalTimer = 0;
}

enum map_e getSpecialBootMap(void){
    return (DEBUG_use_special_bootmap())? MAP_80_GL_FF_ENTRANCE : MAP_91_FILE_SELECT;
}

enum map_e getDefaultBootMap(void){
    return MAP_1F_CS_START_RAREWARE;
}

void func_8023DBAC(void){
    setBootMap(getDefaultBootMap());
    func_8023DFF0(3);
}

void func_8023DBDC(void){
    setBootMap(getSpecialBootMap());
    func_8023DFF0(3);
}

void core1_init(void) {
#if VERSION == VERSION_PAL
     osTvType = 0;
#endif
    ucode_load();
    setBootMap(getDefaultBootMap());
    rarezip_init(); //initialize decompressor's huft table
    viMgr_init();
    overlayManagerloadCore2();
    sDebugVar_8027BEF0 = sDebugVar_8027A538;
    heap_init();
    func_80254028();
    dummy_func_8025AFB0();
    allocUnusedBlock();
    assetCache_init();
    pfsManager_init();
    rumbleManager_init();
    audioManager_init();
    graphicsCache_init();
    ml_init();
    gctransition_reset();
    D_8027A130 = 0;
    gGlobalTimer = 0;
    func_8023DA9C(3);
}

void globalTimer_incTimer(void){
    gGlobalTimer++;
}

void globalTimer_decTimer(void){
    gGlobalTimer--;
}

void mainLoop(void){
    s32 x, y;
    s32 r, g, b, a;
    u16 tmp;
    u16 rgba;
    s32 offset;

    if((globalTimer_getTime() & 0x7f) == 0x11)
        sns_write_payload_over_heap();
    func_8023DA74();

    if(D_8027A130 != 3 || getGameMode() != GAME_MODE_4_PAUSED)
        globalTimer_incTimer();
    
    if (!sDisableInput)
        pfsManager_update();
    sDisableInput = FALSE;

    rumbleManager_80250C08();

    if(!mapSpecificFlags_validateCRC1()){
        eeprom_writeBlocks(0, 0, 0x80397AD0, 0x40);
    }

    switch(D_8027A130){
        case 4:
            func_802E35D8();
            break;
        case 3:
            func_80255524();
            func_80255ACC();
            spawnQueue_func_802C3A18();
            if(func_802E4424())
                game_draw(0);
            spawnQueue_flush();
            break;
    }//L8023DE34

    if(D_80275610){
        func_8023DA9C(D_80275610 - 1);
        D_80275610 = 0;
    }//L8023DE54
    if( !func_8032056C()
        || !levelSpecificFlags_validateCRC1()
        || !dummy_func_80320240()
    ){
        s32 offset;
        //render weird CRC failure image
        for(y= 0x1e; y < gFramebufferHeight - 0x1e; y++){//L8023DEB4
            for(x = 0x14; x < 0xeb; x++){
                tmp = ((8 * globalTimer_getTime()) + ((x*x) + (y*y)));
                
                r = _SHIFTL(x>>3, 11, 5);
                g = _SHIFTL(y>>3, 6, 5);
                b = _SHIFTL(tmp>>3, 1, 5);
                a = 1;
                
                rgba = b | r | g | a;
                
                offset = ((gFramebufferWidth - 0xFF) / 2) + x + (y*gFramebufferWidth);
                gFramebuffers[0][offset] = (s32) rgba;
                gFramebuffers[1][offset] = (s32) rgba;
            }
        }
    }//L8023DF70
}

void mainThread_entry(void *arg) { 
    core1_init();
    sns_write_payload_over_heap();

    while (1) {
        mainLoop();
    }
}

void func_8023DFF0(s32 arg0){
    D_80275610 = arg0 + 1;
}

s32 func_8023E000(void){
    return D_8027A130;
}

void setBootMap(enum map_e map_id){
    gBootMap = map_id;
}

void mainThread_create(void) {
    osCreateThread(&sMainThread, 6, mainThread_entry, NULL, sMainThreadStack + MAIN_THREAD_STACK_SIZE, 20);
}

OSThread *mainThread_get(void) {
    return &sMainThread;
}

void disableInput_set(void){
    sDisableInput = TRUE;
}
