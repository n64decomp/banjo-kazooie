#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "enums.h"
#include "structs.h"
#include "string.h"
#include "rand.h"

#include "prop.h"

#include "core2/core2.h"
#include "ml/mtx.h"
#include "bs_funcs.h"

extern f32 fabsf(f32);
#pragma intrinsic (fabsf)

#define TUPLE_ASSIGN(out, a, b, c) {\
    out[0] = a;\
    out[1] = b;\
    out[2] = c;\
}

#define TUPLE_OP(out, a, op, b) {\
    out##_x = a##_x op b##_x;\
    out##_y = a##_y op b##_y;\
    out##_z = a##_z op b##_z;\
}

void func_80241304(Mtx *m, float x, float y, float z);

void _guMtxIdentF_80245D44(float mf[4][4]); //static should NOT be here

void * malloc(s32 size);
void free(void*);
void* realloc(void* ptr, s32 size);

f32 mlMap_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
float mlNormalizeAngle(float);
f32 max_f(f32, f32);
void copy_vec3f(f32* dst, f32* src);

void func_80258C48(f32 *arg0, f32 *arg1, f32 *arg2);
void func_80258C7C(f32 *arg0, f32 arg1);
void mlScale(f32 *, f32 *, f32);


float gu_sqrtf(float val);

BKSpriteFrame *spriteGetFramePtr(BKSprite *, u32); 

void func_802876CC(AnimCtrl *, f32,f32);
void animctrl_setDuration(AnimCtrl *, f32);
AnimCtrl *player_getAnimCtrlPtr(void);
s32  func_80289FE8(f32);
void func_8028A180(s32 animation, f32 duration);
void func_8028A37C(f32);

s32 player_inWater(void);

ActorMarker *player_getMarker(void);

u32 player_getTransformation(void);

void func_8028E7EC(f32 *arg0);

void _player_getPosition(f32 *dst);
void player_getPosition(f32 *dst);
void player_getRotation(f32 *dst);

void func_80291A60(s32 arg0, f32* arg1);

int button_pressed(s32);
u32 button_held(s32);

void player_setIdealPitch(f32);
f32 player_getPitch(void);
f32 player_getYPosition(void);

void func_80297970(f32);

f32  func_80297AAC(void);

void climbGetBottom(f32 *arg0);

void player_setMovingYaw(f32);

void func_80299BFC(f32);

f32 player_getRoll(void);

f32 player_getYaw(void);
f32 player_getMovingYaw(void);

/* core2/code_13780.c */
void bs_clearState(void);
void bs_setState(s32 state_id);
s32 bs_getPrevState(void);
s32 bs_getState(void);
s32 bs_getNextState(void);
void bs_updateState(void);
s32 bs_checkInterrupt(s32 arg0);
void func_8029A86C(s32 arg0);
s32 bs_getInterruptType(void);

/* vla - variable length array*/
void    vla_clear(VLA *this);
void *  vla_getBegin(VLA *this);
void *  vla_at(VLA *this, u32 n);
s32     vla_getIndex(VLA *this, void *element);
s32     vla_size(VLA *this);
void *  vla_getEnd(VLA *this);
void *  vla_pushBackNew(VLA **thisPtr);
void *  vla_insertNew(VLA **thisPtr, s32 indx);
void    vla_free(VLA *this);
VLA *   vla_new(u32 elemSize, u32 cnt);
void    vla_remove(VLA *this, u32 indx);
void    vla_popBack_n(VLA *this, u32 n);
void    vla_assign(VLA *this, s32 indx, void* value);
VLA *   vla_802ED9E0(VLA *this);


void actor_collisionOff(Actor *);

void *assetcache_get(s32 arg0);

void func_803272F8(s32 *, s32, ActorInfo*, u32);

Actor *marker_getActor(ActorMarker *);

f32 func_8033DD9C(void);
void jiggySpawn(u32 indx, f32* pos);

struct8s *func_802FD320(s32);
void func_802FD330(s32, struct8s *);
void func_802FD33C(s32, struct8s *, Gfx**, Mtx**, s32);
void func_802FD350(s32, struct8s *);

struct8s *func_802FD7B0(s32);
void func_802FD80C(s32, struct8s *);
void func_802FDAF4(s32, struct8s *, Gfx**, Mtx**, s32);
void func_802FDC80(s32, struct8s *);

struct8s *func_802FDE2C(s32);
void func_802FE844(s32, struct8s *);
void func_802FDEE0(s32, struct8s *, Gfx**, Mtx**, s32*);
void func_802FDDC4(s32, struct8s *);

struct8s *func_802FF090(s32);
void func_802FFA50(s32, struct8s *);
void func_802FF3B8(s32, struct8s *, Gfx**, Mtx**, s32);
void func_802FF358(s32, struct8s *);

struct8s *func_802FFE4C(s32);
void func_803005BC(s32, struct8s *);
void func_802FFF34(s32, struct8s *, Gfx**, Mtx**, s32);
void func_802FFED4(s32, struct8s *);

struct8s *func_803007C0(s32);
void func_8030081C(s32, struct8s *);
void func_80300974(s32, struct8s *, Gfx**, Mtx**, s32);
void func_80300BB4(s32, struct8s *);

struct8s *func_80300CD8(s32);
void func_80301348(s32, struct8s *);
void func_80300D0C(s32, struct8s *, Gfx**, Mtx**, s32);
void func_80300C70(s32, struct8s *);

struct8s *func_8030179C(s32);
void func_80301DE4(s32, struct8s *);
void func_803017D0(s32, struct8s *, Gfx**, Mtx**, s32);
void func_80301754(s32, struct8s *);

void marker_despawn(ActorMarker *marker);

Actor *func_8032818C(s32, Actor**);


void func_80324D2C(f32, s32);
void func_802EF950(Actor *, s32);
void func_802EFB54(Actor *, f32*);
Actor *func_802F0BD0(u32);
void func_802BB3DC(s32, f32, f32);
void func_802C3F04(void (* arg0)(void), s32, s32, s32, s32);
void func_802C4140();
void func_8030DA44(u8);
void func_802EFB1C(Actor *, f32, f32, f32, f32, f32, f32);
void func_802EF9AC(Actor *, f32, f32, f32, f32, f32, f32);
void func_802EFED4(Actor *, f32, f32, f32, f32, f32, f32);
void func_802EFE24(Actor *, f32, f32, f32, f32, f32, f32);
void func_802EFB70(Actor *, f32, f32);
void func_802EFB84(Actor *, f32, f32);
void func_802EF9F8(Actor *, f32);
void func_802EFE5C(Actor *, f32, f32);
void func_802EFEC0(Actor *, f32, f32);
void func_802EFA5C(Actor *, f32, f32);
void func_802EFA9C(Actor *, f32, f32);
void func_802EFA18(Actor *, s32);

OSMesgQueue *func_8024F344(void);

f32  func_80258964(f32);
void func_802589E4(f32 *, f32, f32);
f32  func_802591D8(f32, f32);

int func_802878E8(AnimCtrl *, f32);


void func_802876C0(AnimCtrl *this, f32 arg1);
void func_8028774C(AnimCtrl *, f32);
f32  func_802877D8(AnimCtrl *);
void func_8028A1F4(s32, f32, f32);
void func_802927E0(f32, f32);
void func_80292E80(s32, f32);
f32  func_80294438(void);
void func_8029797C(f32);
void func_802979A0(f32);
void func_802979AC(f32, f32);
f32  func_80297A64(void);
f32  func_80297A7C(void);
f32  func_80297AB8(void);
void func_80297BEC(f32);
void func_80297FB0(f32, f32);
void func_80298CE0(f32);
void func_802991D8(f32);
void func_80299234(f32, f32);
void func_8029932C(f32);
void func_80299B58(f32, f32);
void func_8028A010(s32, f32);
void func_8029AD28(f32, s32);
f32  func_8029B2E8(void);
f32  func_8029B33C(void);
f32  func_8029B41C(void);
void func_8029E3C0(s32, f32);
f32  func_8029E270(s32);
void func_802BF2C0(f32);
void func_8030EBC8(s32, f32, f32, s32, s32);

void func_80352CF4(f32 *, f32 *, f32, f32);

#endif
