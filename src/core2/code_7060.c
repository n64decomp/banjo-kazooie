#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "enums.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028DFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E0B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E4A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E4B0.s")

void func_8028E644(void){
    func_80295B04(); //loadzone_applyCollision
    D_8037BFBA = 0; //player_present
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E6EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E71C.s")

enum hitbox_e player_getActiveHitbox(ActorMarker *marker){
    return func_8028DB14(marker);
}

AnimCtrl *player_getAnimCtrlPtr(void){
    return _player_getAnimCtrlPtr();
}

ActorMarker *player_getMarker(void){
    return _player_getMarker();
}

u32 player_getTransformation(void){
    return _player_getTransformation();
}

void func_8028E7EC(f32 (* arg0)[3]){
    climbGetBottom(arg0);
}

f32 func_8028E80C(s32 arg0){
    return func_80291670(arg0);
}

f32 func_8028E82C(void){
    return func_80294438();
}

void func_8028E84C(f32 arg0[3]){
    func_80294480(arg0);
}

ActorMarker *func_8028E86C(void){
    return func_802948EC();
}

s32 func_8028E88C(void){
    ActorMarker *marker;

    marker = func_802948EC();
    if(marker){
        return marker->unk14_20;
    }
    return 0;
}

enum actor_e func_8028E8C0(void){
    ActorMarker *marker;
    Actor *actor;

    marker = func_802948EC();
    
    if(marker){
        actor = marker_getActor(marker);
        return actor->modelCacheIndex;
    }
    return 0;
}

f32 func_8028E904(void){
    return func_802915D8();
}

f32 func_8028E924(f32 arg0[3], s32 arg1){
    s32 *sp1C;
    
    func_80292284(arg0, arg1);
    func_8028D6F0(&sp1C);
    return (f32) sp1C[arg1];
}

void func_8028E964(f32 arg0[3]){
    func_8028E924(arg0, 0);
}

f32 func_8028E984(void){
    return func_80291604();
}

void player_getPosition(f32 dst[3]){
    _player_getPosition(dst);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028E9C4.s")

void func_8028EB3C(s32 arg0[3]){
    f32 plyr_pos[3];
    player_getPosition(plyr_pos);
    arg0[0] = (s32)plyr_pos[0];
    arg0[1] = (s32)plyr_pos[1];
    arg0[2] = (s32)plyr_pos[2];
}

//player_getYaw
f32 func_8028EBA4(void){
    return yaw_get();
}

f32 func_8028EBC4(void){
    return func_802B6F9C();
}

f32 func_8028EBE4(void){
    return pitch_get();
}

int func_8028EC04(void){
    return func_80298850();
}

void player_getRotation(f32 *dst){
    dst[0] = pitch_get();
    dst[1] = yaw_get();
    dst[2] = roll_get();
}

f32 func_8028EC64(f32 arg0[3]){
    f32 sp1C;
    f32 sp18;
    func_80293D2C(&sp18, &sp1C);
    _player_getPosition(arg0);
    arg0[1] += sp18;
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028ECAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EF08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EF28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EF88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028EFEC.s")

void func_8028F010(enum actor_e actor_id){
    func_8028DF48(actor_id);
}

void func_8028F030(enum actor_e actor_id){
    func_8028DF20(actor_id);
}

void func_8028F050(enum actor_e actor_id){
    func_8028DFB8(actor_id);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F098.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F170.s")

int ability_isUnlocked(enum ability_e uid){
    return ability_hasLearned(uid);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F22C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F2A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F2FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F31C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F364.s")

void ability_unlock(enum ability_e uid){
    func_80295818(uid, TRUE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F3D8.s")

void func_8028F408(f32 arg0[3]){
    func_80297BC4(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F4B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F55C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F66C.s")

void func_8028F68C(s32 arg0, ActorMarker *marker){
    func_80296CA8(marker);
    bs_checkInterrupt(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F7D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F7F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F85C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028F9DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FA14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FA34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FA54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FA74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FAEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FB28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FB88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FBD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FC8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FCAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FCC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FCE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FD30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8028FFF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_80290070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_80290090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_802900B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_802900D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_802900FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_80290108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_80290220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8029026C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_8029028C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_80290298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_7060/func_802903CC.s")
