#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_8031FBF8(void);
void func_8031FBA0(void);
void func_803184C8(gczoombox_t *, f32, s32, s32, f32, s32, s32);
extern f32 D_80365DD0[3];
extern s32 D_80365DF4[];
extern s32 D_80365DF8[];
extern s32 D_80365E00;
extern f32 D_80365E04[3];

extern f32 D_80376190;

extern struct {
    s32 unk0;
    s32 unk4;
}D_8037DCE0;
extern s32 D_8037DCE8;
extern s32 D_8037DCEC;
extern gczoombox_t *D_8037DCF0;
extern gczoombox_t *D_8037DCF4;
extern struct {
    f32 unk0[3];
    f32 unkC[3];
} D_8037DCF8;
extern void *D_8037DD28;
extern f32 D_8037DD30;
extern f32 D_8037DD34;

/* .code */
s32 func_802C4360(ActorMarker *marker, Gfx **arg1, Mtx **arg2, s32 arg3){
    s32 sp1C = marker->unk14_20 - 0xe4;
    func_8033A45C(3, sp1C);
    func_8033A45C(1, 1);
    func_8033A45C(4, 1);
    func_8033A45C(9, 1);
    func_8033A45C(5, 0);
    func_8033A45C(8, 0);
    func_8033A45C(6, 0);
    func_8033A45C(7, 0);
    func_8033A45C(0xC, 1);
    func_8033A45C(0xF, 1);
    if(sp1C == D_80365E00){
        func_8033A388(0xFF, 0xFF, 0xFF, 0xFF);
    }
    else{
        func_8033A388(0x64, 0x64, 0x64, 0xFF);
    }
    func_80325888(marker, arg1, arg2, arg3);
}

s32 func_802C4464(ActorMarker *marker, Gfx **arg1, Mtx **arg2, s32 arg3){
    s32 ret_val = func_802C4360(marker, arg1, arg2, arg3);
    if(D_8037DCF4)
        gczoombox_draw(D_8037DCF4, arg1, arg2, arg3);
    if(D_8037DCF0)
        gczoombox_draw(D_8037DCF0, arg1, arg2, arg3);
    return ret_val;
    
}

void func_802C44D0(s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C44D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C44EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C4768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C4AC8.s")

void func_802C4AF0(Actor * this){
    int i;

    if(D_8037DCF0){
        gczoombox_free(D_8037DCF0);
        D_8037DCF0 = NULL;
    }

    if(D_8037DCF4){
        gczoombox_free(D_8037DCF4);
        D_8037DCF4 = NULL;
    }

    for(i = 0; i < 3; i++){
        func_8033CFD4(i);
    }

    if(D_8037DD28){
        func_802F9D38(D_8037DD28);
        D_8037DD28 = NULL;
    }

    comusic_8025AB44(COMUSIC_73_GAMEBOY, 0, 4000);
    func_8025AABC(COMUSIC_73_GAMEBOY);
    func_8025AB00();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C4BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/ch/gameSelect/func_802C4C14.s")

void func_802C5740(Actor * this){
    int i = func_8031B5B0();
    D_8037DCE0.unk0 = D_80365DF4[i];
    D_8037DCE0.unk4 = D_80365DF8[i];

    if(!this->initialized){
        func_8033CE40();
         if(D_8037DCF4 == NULL){
            D_8037DCF4 = gczoombox_new(0xA0, 0xc, 2, 0, NULL);
            gczoombox_open(D_8037DCF4);
            func_803184C8(D_8037DCF4, 30.0f, 5, 2, D_80376190, 0, 0);
        }//L802C57FC

        if(D_8037DCF0 == NULL){
            D_8037DCF0 = gczoombox_new(0xA, 0xd, 2, 1, func_802C44D0);
            func_80318284(D_8037DCF0, 2, &D_8037DCE0);
            gczoombox_open(D_8037DCF0);
            gczoombox_maximize(D_8037DCF0);
        }//L802C5860

        func_803300D8(this->marker, func_802C4AF0);
        D_8037DCEC = 0;
        func_8031FBF8();
        func_8031FBA0();
        D_8037DCE8 = 0;
        D_80365E00 = 0;
        D_8037DCF8.unkC[0] = D_80365DD0[0];
        D_8037DCF8.unkC[1] = D_80365DD0[1];
        D_8037DCF8.unkC[2] = D_80365DD0[2];

        D_8037DCF8.unk0[0] = D_80365E04[0];
        D_8037DCF8.unk0[1] = D_80365E04[1];
        D_8037DCF8.unk0[2] = D_80365E04[2];
        D_8037DD30 = 0.75f;
        D_8037DD34 = func_8038AAB0(&D_80365E04, &D_8037DCE8) ? 20.0 : 0.0;
        actor_collisionOff(this);
        func_8025A6EC(COMUSIC_73_GAMEBOY, 0);
    }//L802C5940
    if(!func_8038AAB0()){
        if(D_8037DCF4)
            func_80316EF4(D_8037DCF4);
        if(D_8037DCF0)
            func_80316EF4(D_8037DCF0);
    }
    func_802C4C14(this);
}

void func_802C5994(void){
    s32 sp1C = level_get();
    s32 t6 = func_803348C0() == MAP_83_CS_GAME_OVER_MACHINE_ROOM;
    s32 a1 = (0 < sp1C && sp1C < 0xd);
    if( a1 || t6)
    {
        if(D_80365E00 != -1 && !func_802E4A08() && func_803348C0() != MAP_91_FILE_SELECT){
            func_8033D17C(D_80365E00);
            func_8033CFD4(D_80365E00);
        }
    }
}

s32 func_802C5A30(void){
    return D_80365E00;
}

void func_802C5A3C(s32 arg0){
    D_80365E00 = arg0;
}

void func_802C5A48(void){
    D_80365E00 = -1;
}