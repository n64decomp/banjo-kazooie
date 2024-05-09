#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"


void func_8023E00C(enum map_e);
void func_8023DFF0(s32);


s32 D_80275610 = 0;
s32 D_80275614 = 0;
u32 D_80275618 = 0;
u32 D_8027561C[] = {
    0x9, 0x4, 0xA, 0x3, 0xB, 0x2, 0xC, 0x5, 0x0, 
    0x1, 0x6, 0xD,  -1
};
u32 D_80275650 = 0xAD019D3C; //SM_DATA_CRC_1
u32 D_80275654 = 0xD381B72F; //SM_DATA_CRC_2
char D_80275658[] = "HjunkDire:218755";


/* .bss */
u32 D_8027A130;
u8  pad_8027A138[0x400];
u64 D_8027A538;
u8  pad_8027A540[0x17F8];
OSThread s_MainThread;
s32      D_8027BEE8;
s32      D_8027BEEC;
u64      D_8027BEF0;

extern u8 core2_TEXT_START[];

extern u16 D_803A5D00[2][0x1ECC0/2];

void func_8023DA20(s32 arg0){ 
    bzero(&D_8027A130, core2_TEXT_START - (u8*)&D_8027A130);
    osWriteBackDCacheAll();
    sns_find_and_parse_payload();
    osInitialize();
    func_80240BE0();
}

void func_8023DA74(void){
    func_8033BD6C();
    func_80255198(); //heap_flush_free_queue
}

void func_8023DA9C(s32 arg0){
    func_80254008();
    func_8024C428();
    if (D_8027A130 == 4){
        func_802E3580();
    }
    if (D_8027A130 == 3){
        func_802E4170();
    }
    func_8023DA74();
    D_8027A130 = arg0;
    if (D_8027A130 == 3){
        func_802E4214(D_8027BEE8);
    }
    if (D_8027A130 == 4){
        func_802E35D0();
    }
    func_80255CD8();
}

u32 func_8023DB4C(u32 arg0){
    return D_80275618 & arg0;
}

s32 func_8023DB5C(void){
    return D_80275618;
}

void func_8023DB68(void){
    D_80275618 = 0;
}

s32 func_8023DB74(void){
    return (DEBUG_use_special_bootmap())? MAP_80_GL_FF_ENTRANCE : MAP_91_FILE_SELECT;
}

s32 func_8023DBA4(void){
    return MAP_1F_CS_START_RAREWARE;
}

void func_8023DBAC(void){
    func_8023E00C(func_8023DBA4());
    func_8023DFF0(3);
}

void func_8023DBDC(void){
    func_8023E00C(func_8023DB74());
    func_8023DFF0(3);
}

void core1_init(void){
    func_80255C30();
    func_8023E00C(func_8023DBA4());
    rarezip_init(); //initialize decompressor's huft table
    func_8024BE30();
    overlayManagerloadCore2();
    D_8027BEF0 = D_8027A538;
    heap_init();
    func_80254028();
    func_8025AFB0();
    func_8033EF58();
    assetCache_init();
    pfsManager_init();
    rumbleManager_init();
    audioManager_init();
    func_8025425C();
    ml_init();
    gctransition_reset();
    D_8027A130 = 0;
    D_80275618 = 0;
    func_8023DA9C(3);
}

void func_8023DCDC(void){
    D_80275618++;
}

void func_8023DCF4(void){
    D_80275618--;
}

void mainLoop(void){
    s32 x, y;
    s32 r, g, b, a;
    u16 tmp;
    u16 rgba;
    s32 offset;

    if((func_8023DB5C() & 0x7f) == 0x11)
        sns_write_payload_over_heap();
    func_8023DA74();

    if(D_8027A130 != 3 || getGameMode() != GAME_MODE_4_PAUSED)
        func_8023DCDC();
    
    if(!D_8027BEEC)
        pfsManager_update();
    D_8027BEEC = 0;
    rumbleManager_80250C08();

    if(!mapSpecificFlags_validateCRC1()){
        write_file_blocks(0, 0, 0x80397AD0, 0x40);
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
                func_802E3F8C(0);
            spawnQueue_flush();
            break;
    }//L8023DE34

    if(D_80275610){
        func_8023DA9C(D_80275610 - 1);
        D_80275610 = 0;
    }//L8023DE54
    if( !func_8032056C()
        || !levelSpecificFlags_validateCRC1()
        || !func_80320240()
    ){
        s32 offset;
        //render weird CRC failure image
        for(y= 0x1e; y < framebuffer_height - 0x1e; y++){//L8023DEB4
            for(x = 0x14; x < 0xeb; x++){
                tmp = ((8 * func_8023DB5C()) + ((x*x) + (y*y)));
                
                r = _SHIFTL(x>>3, 11, 5);
                g = _SHIFTL(y>>3, 6, 5);
                b = _SHIFTL(tmp>>3, 1, 5);
                a = 1;
                
                rgba = b | r | g | a;
                
                offset = ((framebuffer_width - 0xFF) / 2) + x + (y*framebuffer_width);
                D_803A5D00[0][offset] = (s32) rgba;
                D_803A5D00[1][offset] = (s32) rgba;
            }
        }
    }//L8023DF70
}

void __mainMethod(void *arg0){ 
    core1_init();
    sns_write_payload_over_heap();
    while(1){ //main loop
        mainLoop();
    }
}

void func_8023DFF0(s32 arg0){
    D_80275610 = arg0 + 1;
}

s32 func_8023E000(void){
    return D_8027A130;
}

void func_8023E00C(enum map_e map_id){
    D_8027BEE8 = map_id;
}

void mainThread_create(void){
    // 5th argument should be a pointer to the end of an array, but the start is unknown
    // D_8027A538 is not the right symbol, but the end of the array is the important port and this is the closest symbol currently
    osCreateThread(&s_MainThread, 6, __mainMethod, NULL, ((u8*)&D_8027A538) + 0x1800, 0x14);
}

OSThread *mainThread_get(void){
    return &s_MainThread;
}

void func_8023E06C(void){
    D_8027BEEC = 1;
}
