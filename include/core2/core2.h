#ifndef BANJO_KAZOOIE_CORE2_CORE2_H
#define BANJO_KAZOOIE_CORE2_CORE2_H

#include <ultra64.h>
#include "bool.h"
#include "enums.h"

#include "core2/animationfile.h"
#include "core2/anim/commoncache.h"
#include "core2/abilityprogress.h"
#include "core2/fileprogress.h"
#include "core2/gsworld.h"
#include "core2/leveloverlay.h"
#include "core2/mapsavestate.h"
#include "core2/mapspecificflags.h"
#include "core2/picturebox.h"
#include "core2/playerposition.h"
#include "core2/spawnqueue.h"
#include "core2/vla.h"


#include "core2/animmtxlist.h"
#include "core2/timedfunc.h"

#include "core2/gc/bound.h"
#include "core2/gc/dialog.h"
#include "core2/gc/transition.h"
#include "core2/gc/zoombox.h"

#include "core2/print.h"
#include "core2/anctrl.h"
#include "core2/modelRender.h"
#include "core2/code_C31A0.h"
#include "core2/animtexturecache.h"
#include "core2/fla.h"
#include "core2/model.h"

//void *actors_appendToSavestate(void *savestate_begin_ptr, void *savestate_end_ptr);
void actors_applyFromSavestate(void *savestate_ptr, ActorListSaveState *savestate_actorlist_ptr);

s32 cubeList_getOrSetNextProp2Flags(s32 op);
void cubeList_sort(bool absolute_positon);

void func_80351A04(Struct68s *arg0, s32 arg1);
void func_80351A14(Struct68s *arg0, Struct68DrawMethod arg1);
void func_8035179C_copyPosition(Struct68s* arg0, f32 arg1[3]);
void func_80351814(Struct68s *arg0, f32 arg1[3]);
f32  func_80351830(Struct68s *arg0);


extern void sfxsource_setSampleRate(u8, s32);

void code35520_getDistanceVectors(s32 id, s32 *vec11, s32 *vec12, s32 *vec13, s32 *vec21, s32 *vec22, s32 *vec23, s32 *vec31, s32 *vec32, s32 *vec33);
void code35520_selectTable(void);

s32 getGameMode(void);
BKSpriteTextureBlock *spritemask_getChunk(BKSpriteMask *list, s32 index);

void core2_B6640_calculateLineBoundingBox(f32 start_point[3], f32 end_point[3], f32 margin, f32 min_bounds[3], f32 max_bounds[3]);

#endif
