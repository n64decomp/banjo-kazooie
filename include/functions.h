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

#define NOT(boolean) ((boolean) ^ 1)

#define TUPLE_ASSIGN(out, a, b, c) {\
    out[0] = a;\
    out[1] = b;\
    out[2] = c;\
}

#define TUPLE_COPY(dst, src) {\
    dst[0] = src[0];\
    dst[1] = src[1];\
    dst[2] = src[2];\
}

#define v3Copy(dst, src) {\
    dst[0] = src[0];\
    dst[1] = src[1];\
    dst[2] = src[2];\
}

#define TUPLE_OP(out, a, op, b) {\
    out##_x = a##_x op b##_x;\
    out##_y = a##_y op b##_y;\
    out##_z = a##_z op b##_z;\
}

#define FUNC_8030E624(sfx_e, b, c) func_8030E624(\
    _SHIFTL(c, 21, 11) | _SHIFTL(b, 11, 10) | _SHIFTL(sfx_e, 0, 11)\
)

#define FUNC_8030E8B4(sfx_e, b, c, d, e, f) func_8030E8B4(\
    _SHIFTL(c, 21, 11) | _SHIFTL(b, 11, 10) | _SHIFTL(sfx_e, 0, 11), \
    d, \
    _SHIFTL(f, 16, 16) | _SHIFTL(e, 0, 16) \
)
void func_80241304(Mtx *m, float x, float y, float z);

void _guMtxIdentF_80245D44(float mf[4][4]); //static should NOT be here

void * malloc(s32 size);
void free(void*);
void *realloc(void* ptr, s32 size);

f32 ml_map_f(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
float mlNormalizeAngle(float);
f32 max_f(f32, f32);
f32 min_f(f32, f32);
void ml_vec3f_copy(f32 dst[3], f32 src[3]);

void ml_vec3f_add(f32 dst[3], f32 src1[3], f32 src2[3]);
void ml_vec3f_scale(f32 vec[3], f32 scale);
void ml_vec3f_scale_copy(f32 dst[3], f32 src[3], f32 scale);

float gu_sqrtf(float val);

BKSpriteFrame *spriteGetFramePtr(BKSprite *, u32); 

bool  baanim_isAt(f32);
void func_8028A180(enum asset_e anim_id, f32 duration);
void func_8028A37C(f32);

int player_inWater(void);

ActorMarker *_player_getMarker(void);

u32 player_getTransformation(void);

void func_8028E7EC(f32 (* arg0)[3]);

void _player_getPosition(f32 dst[3]);
void player_getPosition(f32 dst[3]);
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
void    vector_clear(VLA *this);
void *  vector_getBegin(VLA *this);
void *  vector_at(VLA *this, u32 n);
s32     vector_getIndex(VLA *this, void *element);
s32     vector_size(VLA *this);
void *  vector_getEnd(VLA *this);
void *  vector_pushBackNew(VLA **thisPtr);
void *  vector_insertNew(VLA **thisPtr, s32 indx);
void    vector_free(VLA *this);
VLA *   vector_new(u32 elemSize, u32 cnt);
void    vector_remove(VLA *this, u32 indx);
void    vector_popBack_n(VLA *this, u32 n);
void    vector_assign(VLA *this, s32 indx, void* value);
VLA *   vector_defrag(VLA *this);


void actor_collisionOff(Actor *);

void *assetcache_get(s32 arg0);

Actor *actor_new(s32 (*position)[3], s32 yaw, ActorInfo *actorInfo, u32 flags);
Actor *func_802C8A54(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8AA8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8AF8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8B4C(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8BA8(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);
Actor *func_802C8C04(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags);

Actor *marker_getActor(ActorMarker *);

f32 time_getDelta(void);
void jiggySpawn(u32 indx, f32 pos[3]);

struct8s *func_802FD320(s32);
void func_802FD330(s32, struct8s *);
void func_802FD33C(enum item_e arg0, struct8s *arg1, Gfx **arg2, Mtx **arg3, Vtx **arg4);
void func_802FD350(s32, struct8s *);

struct8s *func_802FD7B0(s32);
void func_802FD80C(s32, struct8s *);
void func_802FDAF4(enum item_e, struct8s *, Gfx**, Mtx**, Vtx **);
void func_802FDC80(enum item_e, struct8s *);

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
void func_80300D0C(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80300C70(s32, struct8s *);


struct8s *func_8030179C(s32);
void func_80301DE4(s32, struct8s *);
void func_803017D0(s32, struct8s *, Gfx**, Mtx**, s32);
void func_80301754(s32, struct8s *);




void marker_despawn(ActorMarker *marker);

Actor * spawn_child_actor(enum actor_e id, Actor ** parent);


void func_80324D2C(f32, enum comusic_e);
void func_80324DBC(f32 time, enum asset_e, s32, f32 position[3], ActorMarker *caller, void (*)(ActorMarker *, s32, s32), void(*)(ActorMarker *));
void particleEmitter_setSprite(ParticleEmitter *, enum asset_e);
void particleEmitter_setPosition(ParticleEmitter *, f32[3]);
ParticleEmitter *partEmitList_pushNew(u32);
void func_802BB3DC(s32, f32, f32);
void func_802C3F04(void (* arg0)(void), s32, s32, s32, s32);
Actor *func_802C4140(enum actor_e actor_id, s32 x, s32 y, s32 z);
void func_8030DA44(u8);


void func_802EF3F4(ParticleEmitter *, f32[3], f32[3], s32);
void particleEmitter_setParticleAccelerationRange(ParticleEmitter *, f32, f32, f32, f32, f32, f32);
void func_802EF9F8(ParticleEmitter *, f32);
void func_802EFA18(ParticleEmitter *, s32);
void func_802EFA5C(ParticleEmitter *, f32, f32);
void func_802EFA70(ParticleEmitter *, s32);
void particleEmitter_setStartingFrameRange(ParticleEmitter *this, s32 arg1, s32 arg2);
void particleEmitter_setParticleFramerateRange(ParticleEmitter *, f32, f32);
void particleEmitter_setParticleSpawnPositionRange(ParticleEmitter *, f32, f32, f32, f32, f32, f32);
void func_802EFB70(ParticleEmitter *, f32, f32);
void func_802EFB84(ParticleEmitter *, f32, f32);
void func_802EFB98(ParticleEmitter *, struct31s *);
void particleEmitter_setVelocityAndAccelerationRanges(ParticleEmitter *, struct41s *);
void particleEmitter_setPositionAndVelocityRanges(ParticleEmitter *this, struct42s *arg1);
void func_802EFE24(ParticleEmitter *, f32, f32, f32, f32, f32, f32);
void particleEmitter_setSpawnIntervalRange(ParticleEmitter *, f32, f32);
void func_802EFEC0(ParticleEmitter *, f32, f32);
void particleEmitter_setParticleVelocityRange(ParticleEmitter *, f32, f32, f32, f32, f32, f32);
void func_802EFF50(ParticleEmitter *, f32);
void func_802EFFA8(ParticleEmitter *this, s32 arg1[3]);
void particleEmitter_setSpawnInterval(ParticleEmitter *, f32);

int  func_8024DC04(f32, f32, f32);
void func_8024E3A8(f32 (*)[3], f32);
OSMesgQueue *func_8024F344(void);

void ml_vec3f_clear(f32 dst[3]);
void ml_vec3f_roll_rotate_copy(f32[3], f32[3], f32);
void func_80250D94(f32, f32, f32);
void func_80256E24(f32[3], f32, f32, f32, f32, f32);
void func_8025727C(f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 *o1, f32 *o2);
f32  func_80257A44(f32, f32);
f32  func_80257C48(f32, f32, f32);
f32  func_80257D30(f32, f32, f32, f32, f32);
int  func_80257F18(f32 src[3], f32 target[3], f32 *yaw);
bool func_8025801C(f32[3], f32*);

f32  mlAbsF(f32);
f32  mlClamp_f(f32, f32, f32);
f32  func_802588B0(f32, f32);
void func_802589E4(f32 dst[3], f32 yaw, f32 length);
f32  mlDiffDegF(f32, f32);

void func_8025A6EC(enum comusic_e, s32);
void func_8025A70C(enum comusic_e);
void comusic_8025AB44(enum comusic_e comusic_id, s32 arg1, s32 arg2);

f32  cosf(f32);

struct54s * func_80287CA8(void);
void func_80287F50(struct54s *, struct53s *, s32);
void func_80287FD0(struct54s *, f32);
void func_80287F7C(struct54s *arg0, s32 arg1);
void func_80287F98(struct54s *arg0, s32 arg1);
void func_80287FDC(struct54s *arg0, s32 arg1);

void func_80289EA8(f32, f32);


void func_8028A010(enum asset_e anim_id, f32 duration);
void func_8028A100(enum asset_e anim_id, f32, f32);
void func_8028A1F4(enum asset_e anim_id, f32 duration, f32 arg2);
void func_8028A274(enum asset_e, f32);
void func_8028A3B8(f32, f32);
int  func_8028AED4(f32*, f32);
void func_8028E668(f32[3], f32, f32, f32);
f32  func_8028E80C(s32);
bool func_8028F364(f32[3], f32, f32, enum actor_e actor_id, Actor**);
void func_8028FA54(f32[3]);

f32  func_802915D8(void);
f32  func_80291604(void);
f32  func_80291670(s32);
f32  func_80291684(s32);
int  func_80291698(s32);
int  func_80291700(s32, f32);
void func_802917E4(s32, f32);

void func_80292078(s32, f32);
void func_80292158(f32);
f32  func_80292230(void);


void func_802927E0(f32, f32);
void func_80292974(f32, f32, f32);
void func_80292900(f32, f32);

void func_80292E80(s32, f32);
void func_80293350(void);
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
f32  func_80297A70(void);
f32  func_80297A7C(void);
f32  func_80297AB8(void);
f32  func_80297AF0(void);
void gravity_set(f32);
void func_80297B64(f32);
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
void yaw_applyIdeal(void);
void func_80299234(f32, f32);
void func_80299254(f32);
void func_8029932C(f32);
void func_80299594(s32, f32);
void func_80299628(s32);
void func_80299650(f32, f32);
void func_80299B58(f32, f32);
void func_80299CF4(enum sfx_e, f32, s32);
void func_80299D2C(enum sfx_e, f32, s32);
void func_80289EC8(f32, f32, f32, f32);
void func_80289EF8(f32);
f32  func_8029A900(void);
f32  func_8029A90C(void);
void func_8029A968(f32);
void func_8029A980(s32);
void func_8029A974(f32);
void func_8029AD28(f32, s32);
f32  func_8029B2DC(void);
f32  func_8029B2E8(void);
f32  func_8029B30C(void);
void func_8029B324(s32, f32);
f32  func_8029B33C(void);
f32  func_8029B41C(void);
ParticleEmitter *func_8029B950(f32[3],f32);
void func_8029C3E8(f32, f32);
void func_8029CF48(s32, s32, f32);
f32  func_8029DFC8(void);
f32  func_8029DFD4(void);
void func_8029E090(bool, f32);
void func_8029E0C4(f32);
void func_8029E0D0(f32);
void func_8029E180(s32, f32);
void func_8029E3C0(s32, f32);
f32  func_8029E270(s32);
void func_802BD8A4(f32, f32, f32);
f32  func_802BD8D4(void);
void func_802BE244(f32, f32);
void func_802BE230(f32, f32);
void func_802BF2C0(f32);
f32  func_802B6F9C(void);

void func_802C1B20(f32);
int  func_802C1DB0(f32);

void func_802D6264(f32, enum map_e, s32, s32, s32, enum bkprog_e);

Actor *func_802DC7E0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

void func_802EFA20(ParticleEmitter *, f32, f32);


ParticleEmitter *func_802F0D74(ParticleEmitter *);
ParticleEmitter *func_802F4094(f32[3], f32);


extern s32 func_802F9AA8(enum sfx_e);


Actor * func_803055E0(enum actor_e id, s32 pos[3], s32 arg2, s32 arg3, s32 arg4);
f32  func_80309724(f32[3]);
u8   func_8030D90C(void);
void func_8030DA80(u8 indx, enum sfx_e uid);
void func_8030DBB4(u8, f32);
void func_8030DD14(u8, int);
void func_8030DF68(u8, f32[3]);
void func_8030DFF0(u8, s32);
void func_8030E04C(u8, f32, f32, f32);
void func_8030E0FC(u8, f32, f32, f32);
f32  func_8030E200(u8);
void func_8030E2C4(u8);
void func_8030E394(u8 indx);
void func_8030E484(enum sfx_e uid);
void func_8030E4E4(enum sfx_e uid);
void func_8030E510(enum sfx_e uid, s32 arg1);
void func_8030E540(enum sfx_e uid);
void func_8030E560(enum sfx_e uid, s32 arg1);
void func_8030E58C(enum sfx_e uid, f32 arg1);
void func_8030E5F4(enum sfx_e uid, f32 arg1);
void func_8030E624(u32);
void func_8030E6A4(enum sfx_e uid, f32 arg1, s32 arg2);
void func_8030E6D4(enum sfx_e uid);
void func_8030E704(enum sfx_e uid);
void func_8030E760(enum sfx_e uid, f32 arg1, s32 arg2);
void func_8030E878(enum sfx_e uid, f32 arg1, u32 arg2, f32 arg3[3], f32 arg4, f32 arg5);
void func_8030E8B4(u32,f32 [3], u32);
void func_8030E988(enum sfx_e uid, f32 arg1, u32 arg2, f32 (*arg3)[3], f32 arg4, f32 arg5);
void func_8030E9C4(enum sfx_e uid, f32 arg1, u32 arg2, f32 (*arg3)[3], f32 arg4, f32 arg5);
void func_8030EAAC(enum sfx_e uid, f32 arg1, s32 arg2, s32 arg3);
void func_8030EB00(enum sfx_e uid, f32, f32);
void func_8030EB88(enum sfx_e uid, f32 arg1, f32 arg2);
void func_8030EBC8(enum sfx_e uid, f32 arg1, f32 arg2, s32 arg3, s32 arg4);
void func_8030EC20(enum sfx_e uid, f32 arg1, f32 arg2, u32 arg3, u32 arg4);
u8 func_8030ED2C(enum sfx_e uid, s32 arg1);

Actor *func_80325300(ActorMarker *marker, f32 rotation[3]);
Actor *func_80325934(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
Actor *func_80325E78(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);

void func_80326244(Actor *);

void func_8032728C(f32[3], f32, s32, int(*)(Actor *));

int  func_8032863C(AnimCtrl *, f32, f32);
int  func_80328A2C(Actor *, f32, s32, f32);
void func_80328A84(Actor *, u32);
int  func_80328B38(Actor *, s32, f32);
void func_80328B8C(Actor * this, s32 myAnimId, f32 arg2, s32 direction);
int  func_80328BD4(Actor *, s32, f32, s32, f32 );
void func_80328CEC(Actor *, s32, s32, s32);
void func_80328FB0(Actor *, f32);
int  func_80329030(Actor *, s32);
int  func_80329078(Actor *, s32, s32);
int  func_80329480(Actor *);
s32  func_80329784(Actor *);
void func_80329878(Actor *, f32);

void func_80320044(s32, s32, s32);
void func_803300D8(ActorMarker *, void (*)(Actor *));
void marker_setCollisionScripts(ActorMarker *this, MarkerCollisionFunc ow_func, MarkerCollisionFunc arg2, MarkerCollisionFunc die_func);
BKModelBin *func_80330B1C(ActorMarker *marker);
f32  func_80335684(void *);
void func_8033568C(void *, f32 *, f32*);
void func_80335800(void *, f32, void (*)(ActorMarker *), ActorMarker *);
void func_80335924(void *, enum asset_e anim_id, f32, f32);
void func_80335A74(void *, f32);
extern void func_80335A94(void *, f32, s32);
int  func_803391A4(Gfx**, Mtx**, f32 [3], f32[3], f32, f32*, BKModelBin*);
void func_8033A280(f32);

void func_80346C10(enum bs_e *retVal, enum bs_e fail_state, enum bs_e success_state, enum item_e item_id, int use_item);
void func_80347A14(s32);
void func_8034A174(struct5Bs *this, s32 indx,f32 dst[3]);
void func_8034DC08(Struct6Ds *, f32[3], f32[3], f32, s32);
void func_8034DDF0(Struct6Ds *arg0, f32 arg1[3], f32 arg2[3], f32 arg3, s32 arg4);
void func_8034DE60(Struct6Ds *, f32, f32, f32, s32);
void func_8034DFB0(Struct6Ds *arg0, s32 arg1[4], s32 arg2[4], f32 arg3);
void func_8034E1A4(Struct6Ds *arg0, enum sfx_e, f32, f32);
void func_8034E71C(Struct73s *arg0, s32 arg1, f32 arg2);
void func_8034E78C(Struct73s *arg0, s32 arg1, f32 arg2);
void func_8034E7B8(Struct73s *, s32, f32, s32, f32);

void func_80352CF4(f32 *, f32 *, f32, f32);



AnimCtrl *_player_getAnimCtrlPtr(void);
void _get_velocity(f32 (*dst)[3]);
void player_setYPosition(f32);

NodeProp *func_80304C38(s32 arg0, Actor *arg1);
Actor *func_80326D68(f32[3], s32, s32, f32 *);
Actor *func_80329980(Actor *);
 
 /* used in RBB */
void ml_vec3f_pitch_rotate_copy(f32 dst[3], f32 src[3], f32 pitch);
int func_8025773C(f32 *arg0, f32 arg1);
Actor *func_80325888(ActorMarker *, Gfx**, Mtx**, Vtx **);

Actor *func_80325340(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_8032AA58(Actor *, f32);
void func_80324E38(f32, s32);
void timed_playSfx(f32, enum sfx_e, f32, s32);
f32 func_80256064(f32 [3], f32 [3]);
void timed_setCameraToNode(f32, s32);
void func_80324E88(f32);
int actor_animationIsAt(Actor*, f32);

void func_80250E94(f32, f32, f32, f32, f32, f32);


void func_802C8F70(f32);
void func_802F9DB8(s32, f32, f32, f32);
void func_802F9F80(s32, f32, f32, f32);
void func_802FA060(s32, s32, s32, f32);
Actor *func_80326EEC(s32);
f32 func_8038A6B8(ActorMarker *);
void func_80255FE4(f32 [3], f32 [3], f32 [3], f32);
void func_8030DEB4(u8, f32, f32);
void func_8030DB04(u8, s32, f32(*)[3], f32, f32);
void func_80258A4C(f32 [3], f32, f32 [3], f32 *, f32 *, f32 *);


void func_802E4078(enum map_e map, s32 exit, s32 transition);
void levelSpecificFlags_set(s32, s32);
void func_803228D8(void);

void func_803253A0(Actor *);
void mapSpecificFlags_set(s32, s32);

struct0 *func_8031B9D8(void);

extern int  func_80259808(f32);
void actor_playAnimationOnce(Actor *);
void actor_loopAnimation(Actor *);

/* used in fight */
void func_80326224(Actor *this);

void func_802F9FD0(s32, f32, f32, f32);
void func_80324D54(f32, enum sfx_e, f32, s32, f32 (*)[3], f32, f32);

void glcrc_calc_checksum(void *start, void *end, u32 *checksum);
f32 climbGetBottomY(void);
f32 climbGetTopY(void);
void func_802596AC(f32 a0[3], f32 a1[3], f32 a2[3], f32 a3[3]);

void func_8024E55C(s32, void *);
void func_802C3C88(void (*)(s32), s32);
void func_802FAD64(enum item_e);
void func_80304D68(s16 *, f32[3]);
bool func_80311480(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, enum asset_e, s32), void(*arg5)(ActorMarker *, enum asset_e, s32));
void ability_unlock(enum ability_e);

extern void func_802EE278(Actor *, s32, s32, s32, f32, f32);
extern void func_802F3BF4(s16[3]);
extern void actor_collisionOn(Actor *);
extern void func_80328AC8(Actor *, s32);

#endif
