#include <ultra64.h>
#include "functions.h"
#include "variables.h"

Struct5Es * func_80309B48(f32[3], f32[3], f32[3], u32);

/* .bss */
extern struct{
    u8 unk0;
    u8 unk1;
    u8 unk2;
} D_8038C4E0;

/* .code */
s32 func_80389510() {
    return D_8038C4E0.unk1 == 1;
}

u8 func_80389524() {
    return D_8038C4E0.unk0;
}

u8 func_80389530() {
    return D_8038C4E0.unk2;
}

void func_8038953C() {
    return;
}

void func_80389544(void){
    D_8038C4E0.unk0 = 0;
    D_8038C4E0.unk2 = 0;
    if(map_get() == MAP_26_MMM_NAPPERS_ROOM){
        if(jiggyscore_isCollected(JIGGY_5D_MMM_NAPPER)){
            D_8038C4E0.unk1 = 2;
        }
        else{
            D_8038C4E0.unk1 = 1;
        }
    }
    else{
        D_8038C4E0.unk1 = 0;
    }

}

void func_803895B0(s32 arg0) {
    if (arg0 != 0) {
        D_8038C4E0.unk1 = 1;
        return;
    }
    D_8038C4E0.unk1 = 2;
}

void func_803895D8(ActorMarker *caller, enum asset_e text_id, s32 arg2) {
    if (text_id == 0xAD7) {
        timed_playSfx(0.1f, SFX_3F5_UNKNOWN, 1.0f, 30000);
        func_80324E88(1.5f);
        func_80324E38(1.5f, 0);
        return;
    }
    D_8038C4E0.unk0 = 1;
    func_80324E88(1.5f);
    func_80324E38(1.5f, 0);
}

void func_8038966C(void){
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    BKCollisionTri *tmp_v0;

    if(D_8038C4E0.unk1 == 0) return;

    if( !D_8038C4E0.unk2
        && D_8038C4E0.unk1 == 1
        && jiggyscore_isCollected(JIGGY_5D_MMM_NAPPER)
    ){
        D_8038C4E0.unk2 = TRUE;
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.2f, 1);
        func_80324DBC(0.2f, 0xad9, 6, NULL, NULL, func_803895D8, NULL);
    }//L80389700

    if(D_8038C4E0.unk1 != 1) 
        return;

    player_getPosition(sp54);

    sp48[0] = sp54[0];
    sp3C[0] = sp54[0];

    sp48[1] = sp54[1] + 10.0f;
    sp3C[1] = sp54[1] - 10.0f;

    sp48[2] = sp54[2];
    sp3C[2] = sp54[2];

    tmp_v0 = func_80309B48(sp48, sp3C, sp30, 0);

    if(tmp_v0 != NULL){
        if((s32)(tmp_v0->unk8 << 4) < 0){
            FUNC_8030E624(SFX_6B_LOCKUP_OPENING, 0x3FF, 0x598);
            D_8038C4E0.unk1 = 2;
            if(!levelSpecificFlags_get(0x1b)){
                func_80324E38(0.0f, 3);
                timed_setCameraToNode(0.0f, 0);
                func_80324DBC(0.0f, 0xad7, 6, NULL, NULL, func_803895D8, NULL);
                levelSpecificFlags_set(0x1b, TRUE);
            }
        }
    }
}
