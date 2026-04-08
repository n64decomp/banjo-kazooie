#ifndef __CORE_2_H__
#define __CORE_2_H__

#include "core2/timedfunc.h"
#include "gc/gc.h"
#include "core2/print.h"
#include "core2/anctrl.h"

void func_80351A04(Struct68s *arg0, s32 arg1);
void func_80351A14(Struct68s *arg0, Struct68DrawMethod arg1);
void func_8035179C_copyPosition(Struct68s* arg0, f32 arg1[3]);
void func_80351814(Struct68s *arg0, f32 arg1[3]);
f32  func_80351830(Struct68s *arg0);


extern void sfxsource_setSampleRate(u8, s32);

void gsworld_draw(Gfx** gfx, Mtx **mtx, Vtx **vtx);
void gsworld_stub1(s32 arg0, s32 arg1, s32 arg2);
enum map_e gsworld_getMap(void);
s32 gsworld_getExit();
void gsworld_transitionToExit(s32 exit);
s32 gsworld_getUnk0();
void gsworld_free(void);
void gsworld_set(enum map_e map, s32 exit, bool reload);
void gsworld_reload(void);
void gsworld_stub2(void);
void gsworld_setUnk0(s32 value);
s32 gsworld_update(void);
void gsworld_setEnableUpdate(bool value);
bool gsworld_getEnableUpdate();
void gsworld_setEnableDraw(bool value);
bool gsworld_getEnableDraw();
void gsworld_load(enum map_e map_id);
void gsworld_stub3(enum map_e map);

s32 bitfieldarray_getBit(u8 *array, s32 index);
s32 bitfieldarray_getNBits(u8 *array, s32 offset, s32 count);
void bitfieldarray_setBit(u8 *array, s32 index, s32 set);
void bitfieldarray_setNBits(u8 *array, s32 offset, s32 set, s32 count);

// This is like a std::vector<bool> from C++
struct bitfield_s {
    s32 count;
    s32 data[];
};

struct bitfield_s *bitfield_new(s32 count);
void bitfield_free(struct bitfield_s *this);
void bitfield_setBit(struct bitfield_s *this, s32 index, bool value);
bool bitfield_isBitSet(struct bitfield_s *this, s32 index);
void bitfield_setAll(struct bitfield_s *this, bool value);

void playerPosition_init(void);
void playerPosition_func_8029842C(void);
void playerPosition_func_80298464(f32 position[3]);
void playerPosition_set(f32 position[3]);
void playerPosition_setY(f32 value);
void playerPosition_get(f32 position[3]);
f32 playerPosition_getY(void);
void playerPosition_func_80298504(f32 arg0[3]);
void playerPosition_addY(f32 value);
void playerPosition_getOffset(f32 offset[3]);
void playerPosition_setOffset(f32 offset[3]);
void playerPosition_applyOffset(void);

#endif
