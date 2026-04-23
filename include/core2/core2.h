#ifndef __CORE_2_H__
#define __CORE_2_H__

#include "bool.h"
#include "core2/timedfunc.h"
#include "gc/gc.h"
#include "core2/print.h"
#include "core2/anctrl.h"

//void *actors_appendToSavestate(void *savestate_begin_ptr, void *savestate_end_ptr);
void actors_applyFromSavestate(void *savestate_ptr, ActorListSaveState *savestate_actorlist_ptr);

s32 cubeList_getOrSetNextProp2Flags(s32 op);
void cubeList_sort(bool absolute_positon);

u32 mapSpecificFlags_getAll(void);
void mapSpecificFlags_setAll(u32 flags);

void mapSavestate_init(void);
void mapSavestate_clearAll(void);
void mapSavestate_defrag(void);
void mapSavestate_save(enum map_e map);
void mapSavestate_apply(enum map_e map);

void func_80351A04(Struct68s *arg0, s32 arg1);
void func_80351A14(Struct68s *arg0, Struct68DrawMethod arg1);
void func_8035179C_copyPosition(Struct68s* arg0, f32 arg1[3]);
void func_80351814(Struct68s *arg0, f32 arg1[3]);
f32  func_80351830(Struct68s *arg0);


extern void sfxsource_setSampleRate(u8, s32);

void code35520_getDistanceVectors(s32 id, s32 *vec11, s32 *vec12, s32 *vec13, s32 *vec21, s32 *vec22, s32 *vec23, s32 *vec31, s32 *vec32, s32 *vec33);
void code35520_selectTable(void);

void leveloverlay_drawCallback(Gfx **gfx, Mtx **mtx, Vtx **vtx);
enum overlay_e leveloverlay_getOverlayFromLevel(enum level_e lvl);
void leveloverlay_releaseCallback(bool flag);
void leveloverlay_initCallback(bool flag);
void leveloverlay_releaseCallback_NotFP(void); // calls release callback only, when release flag is not set, which is always the case, except for FP
void leveloverlay_releaseCallback_OnlyFP(void); // calls release callback only, when release flag is set, which is only the case for FP
void leveloverlay_initCallback_OnlyFP(void); // calls release callback only, when init flag is not set, which is only the case for FP
void leveloverlay_initCallback_NotFP(void); // calls release callback only, when init flag is set, which is always the case, except for FP
void leveloverlay_debug(void);
void leveloverlay_init(void);
void leveloverlay_unk14Callback(s32 arg0, s32 arg1);
void leveloverlay_updateCallback(void);

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
