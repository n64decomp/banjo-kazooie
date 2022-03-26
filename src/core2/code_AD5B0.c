#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80370250;
extern struct {
    s32 unk0;
    s32 map_4;
    s32 unk8;
}D_803835D0;
extern s32 D_803835DC;
extern u32 D_803835E0;

void func_80335110(s32);
void func_80335128(s32);
void func_8024CE60(f32, f32);
void func_80335140(enum map_e);
void func_8033520C(s32);

void func_80334540(Gfx** gdl, Mtx **mptr, Vtx **vptr) {
    f32 sp44;
    f32 sp40;

    if (D_803835E0 == 0) {
        func_80254084(gdl, 0, 0, D_80276588, D_8027658C, 0, 0, 0);
        func_802BBD2C(&sp44, &sp40);
        func_8024CE60(sp44, sp40);
        func_8024C904(gdl, mptr);
        return;
    }
    if (func_80320708() == 0) {
        write_file_blocks(0, 0, 0x80BC7230, EEPROM_MAXBLOCKS);
    }
    func_802C3BDC();
    func_8030B0AC(gdl, mptr, vptr);
    func_802BBD2C(&sp44, &sp40);
    func_8024CE60(sp44, sp40);
    func_8024C904(gdl, mptr);
    if (func_80309F78() != 0) {
        func_803091D4(gdl, mptr, vptr);
        if (func_802E49F0() == 0) {
            func_80322E64(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_8028E6A4(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_80302C94(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_80332F4C(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_803500D8(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_802F2ED0(func_8032994C(), gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_802F0A34(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_80309628(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_8032D3D8(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_802F0AE8(gdl, mptr, vptr);
        }
        if (func_802E49F0() == 0) {
            func_8034F6F0(gdl, mptr, vptr);
        }
        func_802D520C(gdl, mptr, vptr);
    } else {
        func_803091D4(gdl, mptr, vptr);
        func_80322E64(gdl, mptr, vptr);
        func_8034F6F0(gdl, mptr, vptr);
        func_8028E6A4(gdl, mptr, vptr);
        func_80302C94(gdl, mptr, vptr);
        func_8032D3D8(gdl, mptr, vptr);
        func_80332F4C(gdl, mptr, vptr);
        func_803500D8(gdl, mptr, vptr);
        func_802F2ED0(func_8032994C(), gdl, mptr, vptr);
        func_802D520C(gdl, mptr, vptr);
        func_802F0B98(gdl, mptr, vptr);
    }
    if (func_802E49F0() == 0) {
        func_80350818(gdl, mptr, vptr);
    }
    if (func_802E49F0() == 0) {
        func_802BBD0C(gdl, mptr, vptr);
    }
    func_802C3BE8();
}

void func_803348B0(s32 arg0, s32 arg1, s32 arg2){
}

enum map_e map_get(void){
    return D_803835D0.map_4;
}

s32 func_803348CC(){
    return D_803835D0.unk8;
}

void func_803348D8(s32 arg0) {
    func_802E4078(D_803835D0.map_4, arg0, 1);
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
    func_8031B2F0();//null
    func_80322F7C();
    func_803518E8();
    func_802D48F0();
    func_803224FC();
    func_8028E644();
    func_80322F5C();
    func_80341A54();
    func_802C398C();
    func_802F53D0();
    func_802FAC3C();
    func_802C8F68();
    func_8033E184();
    func_8033FA24();
    func_80344C80();
    func_80287D70();
    func_802885E8();
    func_802BC10C();
    func_802B9D80();
    func_802F1388();
    func_802F10A4();
    func_802F0804();
    func_802F7CE0();
    func_8031F9E0();
    func_80323100();
    func_80304010();
    func_8031B710();
    func_80309FF0();
    func_8030A6B0();
    func_80333918();
    func_8030B284();
    func_8034C8D8();
    func_80323238();
    func_803343AC();
    func_803308A0();
    func_8032AEB4();
    func_8033297C();
    func_803231E8();
    func_80320B7C();
    func_802BAF20();
    func_80305BD4();
    func_80332A38();
    if (func_802E4A08() == 0) {
        func_802FAF0C();
    }
    func_8031B664();
    func_802986D0();
    if (func_80322914() == 0) {
        func_8024F7C4(func_803226E8(D_803835D0.map_4));
    }
    func_80244B3C();
    func_80349C8C();
    func_80322FDC();
    func_8033BD6C();
    func_80255198();//heap_flush_free_queue
    func_802881AC();
}

void func_80334B20(enum map_e arg0, s32 arg1, s32 arg2) {
    D_803835D0.unk0 = 3;
    D_803835D0.map_4 = arg0;
    D_803835D0.unk8 = arg1;
    func_80322FE4();
    func_80335110(1);
    func_80335128(1);
    func_802D2CB8();
    func_80244AB0();
    if (map_get() == MAP_8E_GL_FURNACE_FUN) {
        func_8038E7C4();
    }
    if (func_80322914() == 0) {
        func_8024F764(func_803226E8(D_803835D0.map_4));
    }
    func_80320B84();
    func_80349CB0();
    func_8034C97C();
    func_8030A078();
    func_8031B718();
    func_80298700();
    if (func_802E4A08() == 0) {
        func_802FAE4C();
    }
    func_8031B644();
    func_802C2B10();
    func_803329AC();
    func_80350BFC();
    func_80323190();
    func_80332894();
    func_803305AC();
    func_8031F9E8();
    func_80323230();
    func_80352B80();
    func_8028863C();
    func_80287C58();
    func_80344C50();
    func_8033F9C0();
    func_802B9D40();
    func_802BC044();
    func_802F07D8();
    func_802F1104();
    func_802F13E0();
    func_802F7D30();
    func_8030A78C();
    func_8033393C();
    func_8030B2EC();
    func_803343D0();
    func_803040EC();
    func_802FA69C();
    func_8033DEA0();
    if (arg2 == 0) {
        func_80335140(arg0);
    }
    func_80305990(0);
    func_8030C740();
    func_8030EDE8();
    mapSpecificFlags_clearAll();
    func_803411B0();
    func_802C2B5C();
    func_80322FBC();
    func_8028E4B0();
    func_80322F9C();
    func_80323120();
    func_803223AC();
    func_802C8F40();
    func_8034F774();
    func_80350174();
    func_8031B354();
    func_80351998();
    func_802BC2CC(D_803835D0.unk8);
    func_802D63D4();
    func_80255A04();
    func_802D6948();
    if (func_802E4A08() == 0) {
        func_802F5188();
    }
    if (arg0 != 0x1F) {
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
    func_8033EA78(D_803835D0.unk0, arg0);
    D_803835D0.unk0 = arg0;
}

s32 func_80334ECC(void) {
    s32 phi_v1;
    s32 phi_v0;

    func_80356734();
    func_802D5628();
    func_802FA724();
    if (getGameMode() != 4) {
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
        phi_v0 = func_8023DB5C();
        if (D_80370250) {
            phi_v1 = 0xF;
        } else {
            phi_v1 = 0x1F;
        }
        if (((phi_v1 & phi_v0) == 3) && (get_loaded_overlay_id() == OVERLAY_5_BEACH)) {
            if ((ttc_func_8038BF8C() == 0) || (D_80370250 != 0)) {
                D_80370250 = (u8)1;
                for (phi_v0 = 0; phi_v0 != 0x8F0D180; phi_v0++){
                }
            }
        }
        func_8033E1E0();
        func_802F11E8();
        func_80288210();
        func_80288834();
        func_802BC14C();
        func_803045D8();
        func_80332E08();
        func_803465E4();
        func_8031B790();
        func_8034C9D4();
        func_8030A850(1);
        func_8030B3C8();
        func_802F08A0();
        func_8034F918();
        func_80350250();
        if (mapSpecificFlags_validateCRC1() == 0) {
            func_8028FCBC();
        }
        func_80349D60();
        func_80350CA4();
        func_8031B65C();
        func_80310D2C();
        func_8031B0B0();
        overlay_update();
        func_80321924();
        func_80334428();
        func_8031C880();
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
    s32 s0;

    func_80254008();
    s0 = func_8034AB6C(map_id);
    while (func_8034AF98(s0, 0) == 0) {
        if (func_8034AF98(s0, 2)) {
            
        } else if (func_8034AF98(s0, 1)) {
            func_803046A0(s0);
        } else if (func_8034AF98(s0, 3)) {
            func_802BA0AC(s0);
        } else if (func_8034AF98(s0, 4)) {
            func_80333B78(s0);
        }
    }
    func_8034AAB0(s0);
}

void func_8033520C(s32 arg0){
}
