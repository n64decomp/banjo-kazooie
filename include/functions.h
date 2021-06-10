#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ultra64.h>

#include "enums.h"
#include "structs.h"
#include "string.h"
#include "rand.h"

#include "prop.h"

#include "core1/core1.h"
#include "core2/core2.h"

#include "ml.h"
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
void *realloc(void* ptr, s32 size);

f32 ml_map_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
float mlNormalizeAngle(float);
f32 max_f(f32, f32);
void ml_vec3f_copy(f32 (* dst)[3], f32 (* src)[3]);

void ml_vec3f_add(f32 (* arg0)[3], f32 (* arg1)[3], f32 (* arg2)[3]);
void ml_vec3f_scale(f32 (* arg0)[3], f32 scale);
void ml_vec3f_scale_copy(f32 (* dst)[3], f32 (* src)[3], f32 scale);

float gu_sqrtf(float val);

BKSpriteFrame *spriteGetFramePtr(BKSprite *, u32); 

s32  func_80289FE8(f32);
void func_8028A180(s32 animation, f32 duration);
void func_8028A37C(f32);

s32 player_inWater(void);

ActorMarker *player_getMarker(void);

u32 player_getTransformation(void);

void func_8028E7EC(f32 (* arg0)[3]);

void _player_getPosition(f32 (* dst)[3]);
void player_getPosition(f32 (* dst)[3]);
void player_getRotation(f32 *dst);

void func_80291A60(s32 arg0, f32* arg1);

int button_pressed(s32);
u32 button_held(s32);

void pitch_setIdeal(f32);
f32 pitch_get(void);
f32 player_getYPosition(void);

void func_80297970(f32);

f32  func_80297AAC(void);

void climbGetBottom(f32 (* dst)[3]);

void yaw_setIdeal(f32);

void func_80299BFC(f32);

f32 roll_get(void);

f32 yaw_get(void);
f32 yaw_getIdeal(void);

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

Actor *actor_new(s32 (* position)[3], s32 yaw, ActorInfo *actorInfo, u32 flags);
Actor *func_802C8A54(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8AA8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8AF8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8B4C(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8BA8(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8C04(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags);

Actor *marker_getActor(ActorMarker *);

f32 func_8033DD9C(void);
void jiggySpawn(u32 indx, f32 (* pos)[3]);

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

Actor * spawn_child_actor(enum actor_e id, Actor ** parent);


void func_80324D2C(f32, enum comusic_e);
void func_802EF950(Actor *, s32);
void func_802EFB54(Actor *, f32 (*)[3]);
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

void func_8024E3A8(f32 (*)[3], f32);
OSMesgQueue *func_8024F344(void);

void ml_vec3f_clear(f32 (* arg0)[3]);
void func_80250D94(f32, f32, f32);
f32  func_80257A44(f32, f32);
f32  func_80257C48(f32, f32, f32);
int func_80257F18(f32 (* arg0)[3], f32 (* arg1)[3], f32 * arg2);

f32  mlAbsF(f32);
f32  mlClamp_f(f32, f32, f32);
f32  func_802588B0(f32, f32);
void ml_radial_to_cartisian(f32 (* dst)[3], f32 yaw, f32 length);
f32  mlDiffDegF(f32, f32);
void func_8025A6EC(enum comusic_e, s32);
void func_8025A70C(enum comusic_e);
void comusic_8025AB44(enum comusic_e comusic_id, s32 arg1, s32 arg2);

f32  cosf(f32);


void func_8028A010(enum asset_e anim_id, f32 duration);
void func_8028A100(enum asset_e anim_id, f32, f32);
void func_8028A1F4(s32, f32, f32);
void func_8028A274(enum asset_e, f32);
void func_8028A3B8(f32, f32);
int  func_8028AED4(f32*, f32);

f32  func_80291670(s32);
f32  func_80291684(s32);
u32 func_80291698(int);
int  func_80291700(s32, f32);
void func_802917E4(s32, f32);

void func_80292078(s32, f32);
void func_80292158(f32);
f32  func_80292230(void);


void func_802927E0(f32, f32);
void func_80292974(f32, f32, f32);
void func_80292900(f32, f32);

void func_80292E80(s32, f32);
void func_80293D48(f32, f32);
f32  func_80294438(void);
f32  func_80294500(void);
void func_80294980(f32 (* arg0)[3]);
f32  get_slope_timer(void);
f32  func_80294A40(void);
void func_80295C08(void (* arg0)(void));
void func_802978DC(int);
void func_80297970(f32);
void func_8029797C(f32);
void player_setYVelocity(f32);
void func_802979AC(f32, f32);
f32  func_80297A64(void);
f32  func_80297A7C(void);
f32  func_80297AB8(void);
f32  func_80297AF0(void);
void gravity_set(f32);
void func_80297BF8(f32);
int  func_80297C04(f32);
void func_80297CCC(f32);
f32  pitch_getIdeal(void);
void pitch_setAngVel(f32, f32);
void func_80298528(f32);
f32  func_802987C4(void);
f32  func_802987D4(void);
f32  func_802987E4(void);
void roll_setIdeal(f32);
void roll_setAngularVelocity(f32, f32);
void yaw_set(f32);
void func_802991FC(void);
void func_80299234(f32, f32);
void func_80299254(f32);
void func_8029932C(f32);
void func_80299594(s32, f32);
void func_80299628(s32);
void func_80299650(f32, f32);
void func_80299B58(f32, f32);
void func_80299CF4(s32, f32, s32);
void func_80289EC8(f32, f32, f32, f32);
void func_80289EF8(f32);
f32  func_8029A900(void);
f32  func_8029A90C(void);
void func_8029A968(f32);
void func_8029A980(s32);
void func_8029A974(f32);
void func_8029AD28(f32, s32);
f32  func_8029B2E8(void);
f32  func_8029B30C(void);
void func_8029B324(s32, f32);
f32  func_8029B33C(void);
f32  func_8029B41C(void);
void func_8029C3E8(f32, f32);
void func_8029CF48(s32, s32, f32);
void func_8029E090(s32, f32);
void func_8029E180(s32, f32);
void func_8029E3C0(s32, f32);
f32  func_8029E270(s32);
void func_802BF2C0(f32);
void func_802EFF50(Actor *, f32);
void func_8030DBB4(s32, f32);
void func_8030E04C(s32, f32, f32, f32);
void func_8030E58C(s32, f32);
void func_8030E5F4(s32, f32);
void func_8030E624(u32);
void func_8030E6D4(int);
void func_8030E760(s32, f32, s32);
void func_8030EB00(s32, f32, f32);
void func_8030EBC8(s32, f32, f32, s32, s32);

void func_8032728C(f32*, f32, s32, s32(*)(Actor *));

void func_803391A4(Gfx**, Mtx**, f32 (*)[3], f32(*)[3], f32, f32*, void*);

void func_80346C10(enum bs_e *retVal, enum bs_e fail_state, enum bs_e success_state, enum item_e item_id, int use_item);

void func_80352CF4(f32 *, f32 *, f32, f32);



AnimCtrl *player_getAnimCtrlPtr(void);
void _get_velocity(f32 (*dst)[3]);
void player_setYPosition(f32);

Actor *func_80304C38(s32 arg0, Actor *arg1);
Actor *func_80326D68(f32 (*)[3], s32, s32, f32 *);
Actor *func_80329980(Actor *);
 
 /* used in RBB */
 void func_8025686C(f32 (* arg0)[3], f32 (* arg1)[3], f32 arg2);
int func_8025773C(f32 *arg0, f32 arg1);
void func_8030E878(s32, f32, s32, f32 (*)[3], f32, f32);
Actor *func_80325888(ActorMarker *, Gfx**, Mtx**, u32);
void func_80335924(void *, s32, f32, f32);

extern Actor *func_80325340(ActorMarker *, Gfx**, Mtx**, u32);
void func_8032AA58(Actor *, f32);
void func_8034DDF0(void *, f32 (*)[3], f32 (*)[3], f32, s32);
void func_80324E38(f32, s32);
void func_8034E1A4(void *, s32, f32, f32);
void func_80324C88(f32, s32, f32, s32);
f32 func_80256064(f32 (*)[3], f32 (*)[3]);
void func_80324E60(f32, s32);
void func_80324E88(f32);
void func_8034DFB0(s32, s32(*)[4], s32(*)[4], f32);
int actor_animationIsAt(Actor*, f32);

void func_80250E94(f32, f32, f32, f32, f32, f32);
void func_802EF3F4(Actor *, f32(*)[3], f32(*)[3], s32);
void func_802EFB98(Actor *, f32(*)[3]);
void func_802EFC84(Actor *, f32(*)[3]);
void func_8034DC08(void *, f32 (*)[3], f32(*)[3], f32, s32);
void func_802C8F70(f32);
void func_802F9DB8(s32, f32, f32, f32);
void func_802F9F80(s32, f32, f32, f32);
void func_802FA060(s32, s32, s32, f32);
Actor *func_80326EEC(s32);
f32 func_8038A6B8(ActorMarker *);
void func_80255FE4(f32 (*)[3], f32 (*)[3], f32 (*)[3], f32);\
void func_8030DEB4(u8, f32, f32);
void func_8030DB04(s32, s32, f32(*)[3], f32, f32);
void func_80258A4C(f32 (*)[3], f32, f32 (*)[3], f32 *, f32 *, f32 *);
void func_8030E6A4(s32, f32, s32);
void func_803300A8(ActorMarker *, void (*)(ActorMarker *, s32), void (*)(ActorMarker *, s32), void (*)(ActorMarker *, s32));
void func_8033568C(void *, f32 *, f32*);
void func_802E4078(enum MAP_E map, s32 exit, s32 transition);
void levelSpecificFlags_set(s32, s32);
void func_8030E988(s32, f32, s32, f32 (*)[3], f32, f32);
void func_803228D8(void);
void func_802EFFC4(Actor *, f32);
void func_803253A0(Actor *);
#endif
