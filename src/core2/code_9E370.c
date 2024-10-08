#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include <core1/viewport.h>
#include "actor.h"

#include "prop.h"

#define DIST_SQ_VEC3F(v1, v2) ((v1[0] - v2[0])*(v1[0] - v2[0]) + (v1[1] - v2[1])*(v1[1] - v2[1]) + (v1[2] - v2[2])*(v1[2] - v2[2]))

extern f32  ml_vec3f_length(f32[3], f32[3]);
extern bool ml_vec3f_within_distance(f32[3], f32[3], f32);
extern void func_802D7124(Actor *, f32);
extern void func_802EE6CC(f32[3], s32[4], s32[4], s32, f32, f32, s32, s32, s32);


extern void func_8033A244(f32);

f32 func_80257204(f32, f32, f32, f32);
extern Actor *spawnQueue_bundleWithYaw_f32(enum bundle_e bundle_id, s32 x, s32 y, s32 z, s32 yaw);
f32 func_8033229C(ActorMarker *);
f32 player_getYaw(void);
extern void __bundle_spawnFromFirstActor(s32, Actor *);
extern void func_8032B3A0(Actor *, ActorMarker *);
extern void func_8032EE0C(GenFunction_2, s32);
extern void func_8032EE20(void);
extern void __spawnQueue_add_5(GenFunction_5, s32, s32, s32, s32, s32);


void func_8032A6A8(Actor *arg0);
void func_8032ACA8(Actor *arg0);
void func_8032B5C0(ActorMarker *arg0, ActorMarker *arg1, struct5Cs *arg2);
void subaddie_set_state_with_direction(Actor * this, s32 arg1, f32 arg2, s32 arg3);
void func_8032BB88(Actor *this, s32 arg1, s32 arg2);
int  subaddie_playerIsWithinSphere(Actor *this, s32 dist);
extern void func_8033A4A0(enum asset_e mode_id, f32, f32);
extern void func_80338338(s32, s32, s32);
extern void func_803382FC(s32);
extern void func_803382E4(s32);
extern void func_8033687C(Gfx **);
extern void func_80335D30(Gfx **);
extern void func_80344138(s32, s32, s32, f32[3], f32[3], Gfx **, Mtx **);
extern BKVertexList *vtxList_clone(BKVertexList *vtxList);

typedef struct {
    f32 unk0[3];
    s16 unkC;
    s16 unkE;
}Actorlocal_Core2_9E370;

/* .data */
ActorArray *suBaddieActorArray = NULL; //actorArrayPtr
s32 D_8036E564 = 0;
struct5Bs *D_8036E568 = NULL;
s32 D_8036E56C = 0;
void *D_8036E570 = NULL;
u8 D_8036E574 = 0;
u8 D_8036E578 = 0;
u8 D_8036E57C = 0;
f32 D_8036E580[3] = {0.0f, -8.0f, 0.0f};
f32 D_8036E58C[3] = {0.0f, -16.0f, 0.0f};
f32 D_8036E598[4] = {1000.f, 20.0f, 10.5f, 1.0f};



/* .bss */
Actor *suLastBaddie;
s32 D_80383394;
Actor *suBaddieJiggyArray[14]; //array of jiggy actor ptrs


Actor * marker_getActorAndRotation(ActorMarker *marker,f32 rotation[3])
{   Actor *actor = &suBaddieActorArray->data[marker->actrArrayIdx];
    rotation[0] = actor->pitch;
    rotation[1] = actor->yaw;
    rotation[2] = actor->roll;
    return actor;
}

Actor *func_80325340(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    BKModelBin * model_bin =  func_80330DE4(marker);
    if(model_bin && func_8033A12C(model_bin)){
        if(marker->collidable)
            marker_loadModelBin(marker);
    }
    return NULL;
}

void actor_predrawMethod(Actor *this){
    s32 pad4C;
    BKModelBin *sp48;
    bool sp44;
    BKVertexList *sp40;
    f32 sp34[3];
    
    sp48 = marker_loadModelBin(this->marker);
    func_80330534(this);
    if(this->animctrl != NULL){
        animctrl_drawSetup(this->animctrl, this->position, 1);
    }

    if(this->marker->unk20 != NULL){
        sp44 = FALSE;
        if(this->unk148 != NULL){
            animMtxList_setBoned(&this->marker->unk20, model_getAnimationList(sp48), skeletalAnim_getBoneTransformList(this->unk148));
            sp44 = TRUE;
        }//L8032542C
        else if(this->animctrl != NULL && model_getAnimationList(sp48)){
            anim_802897D4(&this->marker->unk20, model_getAnimationList(sp48), animctrl_getAnimPtr(this->animctrl));
            sp44 = TRUE;
        }//L80325474

        if(sp44){
            func_8033A444(this->marker->unk20);
        }
    }//L8032548C

    if(this->alpha_124_19 < 0xFF){
        modelRender_setAlpha(this->alpha_124_19);
    }

    modelRender_setDepthMode(this->depth_mode);
    if(this->marker->unk44 != 0){
        if((s32)this->marker->unk44 == 1){
            func_8033A450(D_8036E568);
        }
        else{
            func_8033A450(this->marker->unk44);
        }
    }

    if(this->unkF4_30){
        sp40 = func_80330C74(this);
        if(this->unk138_29){
            sp34[0] = this->pitch;
            sp34[1] = this->yaw;
            sp34[2] = this->roll;
            func_80333D48(sp40, this->position, sp34, this->scale, 0, model_getVtxList(sp48));
        }//L80325560
        modelRender_setVertexList(sp40);
        this->unkF4_29 = NOT(this->unkF4_29);
    }//L80325594

    if(this->unk130){
        this->unk130(this);
    }

    if(this->unk148 && !this->marker->unk20){
        modelRender_setBoneTransformList(skeletalAnim_getBoneTransformList(this->unk148));
    }

    func_8033056C(this);
    modelRender_setAnimatedTexturesCacheId(actor_getAnimatedTexturesCacheId(this));
}

void func_803255FC(Actor *this) {
    switch (this->unk124_5) {
    default:
        break;

    case 0:
        if (randf() < 0.03) {
            this->unk124_5 = 1;
        }
        break;

    case 1:
        if (this->unk124_3 == 3) {
            this->unk124_5 = 2;
        } else {
            this->unk124_3++;
        }
        break;

    case 2:
        this->unk124_3--;
        if (this->unk124_3 == 0) {
            this->unk124_5 = 0;
        }
        break;
    }
    func_8033A45C(1, this->unk124_3 + 1);
    func_8033A45C(2, this->unk124_3 + 1);
}

void func_80325760(Actor *this) {
    func_8033A45C(1, 4);
    func_8033A45C(2, 4);
}

void actor_postdrawMethod(ActorMarker *marker){
    marker->unk14_21 = TRUE;
}

void func_803257A4(ActorMarker *marker){
    marker->unk14_21 = TRUE;
}

BKModelBin *func_803257B4(ActorMarker *marker) {
    Actor *actor;
    BKModelBin *model_bin;
    BKVertexList *vtx_list;

    actor = marker_getActor(marker);
    if ((actor->unk174 == 0.0f) || (actor->unk178 == 0.0f)) {
        model_bin = (BKModelBin *) assetcache_get(marker->modelId);
        vtx_list = (BKVertexList *)((s32)model_bin + model_bin->vtx_list_offset_10);
        actor->unk174 = (f32) vtx_list->local_norm * actor->scale;
        actor->unk178 = (f32) vtx_list->global_norm * actor->scale;
        assetcache_release(model_bin);
    }
    func_8033A4A0(marker->modelId, actor->unk174, actor->unk178);
    return NULL;
}


Actor *actor_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 sp3C[3];
    Actor *this;

    this = marker_getActorAndRotation(marker, sp3C);
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);
    modelRender_draw(gfx, mtx, this->position, sp3C, this->scale, (this->unk104 != NULL) ? D_8036E580 : NULL, func_803257B4(marker));
    return this;
}

Actor *func_80325934(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this;
    f32 scale[3];
    BKSpriteDisplayData *sp3C;

    this = marker_getActor(marker);
    sp3C = func_80330F30(marker);
    scale[0] = scale[1] = scale[2] = this->scale;
    if (this->unk104 != NULL) {
        this->position[0] -= D_8036E58C[0];
        this->position[1] -= D_8036E58C[1];
        this->position[2] -= D_8036E58C[2];
    }
    func_80338338(0xFF, 0xFF, 0xFF);
    if (this->unk124_11 != 0) {
        func_803382FC(this->alpha_124_19);
        func_803382E4(0xC);
    } else if (func_80344C20(sp3C) & 0xB00) {
        func_803382E4(0xB);
    } else {
        func_803382E4(0xE);
    }
    func_80344C38(&func_803257A4, marker);
    func_80335D30(gfx);
    func_80344138(sp3C, marker->propPtr->unk8_15, marker->propPtr->unk8_5, this->position, scale, gfx, mtx);
    func_8033687C(gfx);
    if (this->unk104 != NULL) {
        this->position[0] = this->position[0] + D_8036E58C[0];
        this->position[1] = this->position[1] + D_8036E58C[1];
        this->position[2] = this->position[2] + D_8036E58C[2];
    }
    return this;
}

Actor *func_80325AE0(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 scale[3];
    f32 rotation[3];
    Actor *this;
    s32 sp40;

    this = marker_getActor(marker);
    sp40 = func_80330F30(marker);
    scale[0] = scale[1] = scale[2] = this->scale;
    rotation[0] = this->pitch;
    rotation[1] = this->yaw;
    rotation[2] = this->roll;
    if (this->unk104 != NULL) {
        this->position[0] -= D_8036E58C[0];
        this->position[1] -= D_8036E58C[1];
        this->position[2] -= D_8036E58C[2];
    }
    func_80338338(0xFF, 0xFF, 0xFF);
    if (this->unk124_11 != 0) {
        func_803382FC(this->alpha_124_19);
        func_803382E4(0xC);
    } else if (func_80344C20(sp40) & 0xB00) {
        func_803382E4(0xB);
    } else {
        func_803382E4(0xE);
    }
    func_80344C38(&func_803257A4, marker);
    func_80335D30(gfx);
    func_80344720(sp40, marker->propPtr->unk8_15, marker->propPtr->unk8_5, this->position, rotation, &scale, gfx, mtx);
    func_8033687C(gfx);
    if (this->unk104 != NULL) {
        this->position[0] = this->position[0] + D_8036E58C[0];
        this->position[1] = this->position[1] + D_8036E58C[1];
        this->position[2] = this->position[2] + D_8036E58C[2];
    }
    return this;
}

Actor *func_80325CAC(ActorMarker *marker, Gfx **gfx, Gfx **mtx, Vtx **vtx) {
    f32 scale[3];
    f32 rotation[3];
    Actor *this;
    s32 sp40;

    this = marker_getActor(marker);
    sp40 = func_80330F30(marker);
    scale[0] = scale[1] = scale[2] = this->scale;
    if (this->unk104 != NULL) {
        this->position[0] -= D_8036E58C[0];
        this->position[1] -= D_8036E58C[1];
        this->position[2] -= D_8036E58C[2];
    }
    viewport_getRotation_vec3f(rotation);
    rotation[2] += this->roll;
    func_80338338(0xFF, 0xFF, 0xFF);
    if (this->unk124_11 != 0) {
        func_803382FC(this->alpha_124_19);
        func_803382E4(0xC);
    } else if ((func_80344C20(sp40) & 0xB00) != 0) {
        func_803382E4(0xB);
    } else {
        func_803382E4(0xE);
    }
    func_80344C38(&func_803257A4, marker);
    func_80335D30(gfx);
    func_80344720(sp40, marker->propPtr->unk8_15, marker->propPtr->unk8_5, this->position, rotation, scale, gfx, mtx);
    
    func_8033687C(gfx);
    if (this->unk104 != NULL) {
        this->position[0] = this->position[0] + D_8036E58C[0];
        this->position[1] = this->position[1] + D_8036E58C[1];
        this->position[2] = this->position[2] + D_8036E58C[2];
    }
    return this;
}

Actor *actor_drawFullDepth(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 rotation[3];
    Actor *this;

    this = marker_getActorAndRotation(marker, rotation);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_preDraw((GenFunction_1)actor_predrawMethod, (s32)this);
    modelRender_postDraw((GenFunction_1)actor_postdrawMethod, (s32)marker);
    modelRender_draw(gfx, mtx, this->position, rotation, this->scale, (this->unk104 != NULL) ?  D_8036E580 : NULL, func_803257B4(marker));
    return this;
}

Actor *func_80325F2C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    func_8033A244(30000.0f);
    func_8033A280(2.0f);
    return actor_drawFullDepth(marker, gfx, mtx, vtx);
}

void func_80325F84(Actor *this){}

void func_80325F8C(void) {
    suBaddieActorArray = NULL;
    D_8036E568 = func_8034A2C8();
    D_8036E56C = func_802EE5E0(0x10);
    D_8036E570 = func_802F2AEC();
    D_8036E574 = 0;
    D_8036E578 = 0;
    D_8036E57C = 0;
}

void func_80325FE8(Actor *this) {
    ActorMarker *marker;
    u8 temp_v0;

    marker = this->marker;
    marker->id = 0;
    if (this->animctrl != NULL) {
        animctrl_free(this->animctrl);
    }
    temp_v0 = this->unk44_31;
    if (temp_v0 != 0) {
        func_8030DA44(temp_v0);
    }
    this->animctrl = NULL;
    this->unk44_31 = 0;

    if (this->unk138_7 != 0) {
        func_8032BB88(this, -1, 8000);
        this->unk138_7 = 0;
    }
    if (marker->actorFreeFunc != NULL) {
       marker->actorFreeFunc(this);
       marker->actorFreeFunc = NULL;
    }
    if ((s32)marker->unk44 < 0) {
        func_8033E7CC(marker);
        func_8034A2A8(marker->unk44);
       marker->unk44 = 0;
    }
    if (marker->unk4C != 0) {
        func_8034BF54(this->marker);
        marker->unk4C = 0;
    }
    if (marker->unk48 != 0) {
        func_8033F784(marker);
        marker->unk48 = 0;
    }
    if (this->unk148 != NULL) {
        skeletalAnim_free(this->unk148);
        this->unk148 = NULL;
    }
    if (marker->unk50 != 0) {
        func_80340690(marker->unk50);
        marker->unk50 = 0;
    }
    func_8032ACA8(this);
}

void actorArray_free(void) {
    Actor *var_s0;

    if (suBaddieActorArray != NULL) {
        for(var_s0 = suBaddieActorArray->data; var_s0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_s0++){
            func_80325FE8(var_s0);
            if (var_s0->marker != NULL) {
                marker_free(var_s0->marker);
            }
            var_s0->marker = NULL;
        }
        free(suBaddieActorArray);
        suBaddieActorArray = NULL;
    }
    func_8034A2A8(D_8036E568);
    D_8036E568 = NULL;
    func_802EE5E8(D_8036E56C);
    D_8036E56C = NULL;
    func_802F2C78(D_8036E570);
    D_8036E570 = NULL;
}

s32 func_80326218(void){
    return D_8036E564;
}

void actor_update_func_80326224(Actor *this){
    func_80343DEC(this);
}

void func_80326244(Actor *this){
    actor_collisionOff(this);
    this->marker->unk2C_1 = 1;
    func_80343DEC(this);
}

s32 func_8032627C(Actor *this){
    return this->alpha_124_19;
}

void actor_setOpacity(Actor *this, s32 alpha){
    this->unk124_11 = 3; //blend mode?
    this->alpha_124_19 = alpha;
}

void func_803262B8(Actor *this){
    this->unk124_11 = 0;
    this->alpha_124_19 = 0xff;
}

void func_803262E4(Actor *this){
    this->alpha_124_19 = 0;
    this->unk124_11 = 1;
}

void func_80326310(Actor *this){
    this->unk124_11 = 2;
}

void func_80326324(Actor *this) {
    if (this->marker->unk2C_2) {
        this->unk1C[1] += time_getDelta();
        if (this->unk1C[0] < this->unk1C[1]) {
            this->unk1C[1] = this->unk1C[0];
        }
        switch (this->unk124_11) {                  /* switch 1; irregular */
            case 1:                                 /* switch 1 */
                this->alpha_124_19 = (this->unk1C[0] != 0.0f) ? (s32)(255.0f *(this->unk1C[1] / this->unk1C[0])) : 0xFF;
                if (255.0 == this->alpha_124_19) {
                    this->unk124_11 = 0;
                }
                break;

            case 2:                                 /* switch 1 */
                this->alpha_124_19 = (this->unk1C[0] != 0.0f) ? (0xFF - (s32) ((this->unk1C[1] / this->unk1C[0]) * 255.0f)) : 0;
                if (this->alpha_124_19 == 0) {
                    this->unk124_11 = 0;
                }
                break;
        }
    } else {
        switch (this->unk124_11) {                        /* irregular */
            case 1:
                this->alpha_124_19 = MIN(255.0,this->alpha_124_19 + 7.0);
                if (255.0 == this->alpha_124_19) {
                    this->unk124_11 = 0;
                }
                break;

            case 2:
                this->alpha_124_19 = MAX(0.0, this->alpha_124_19 - 7.0);
                if (this->alpha_124_19 == 0) {
                    marker_despawn(this->marker);
                }
                break;
            }
    }
}

void func_80326894(Actor *this){
    func_80326324(this);
}

void func_803268B4(void) {
    s32 temp_v1;
    Actor *actor;
    ActorMarker *marker;
    AnimCtrl *anim_ctrl;
    ActorInfo *actor_info;
    s32 position[3];
    s32 rotation[3];
    BKVertexList *temp_v0_3;
    bool sp54;
    s32 temp_s1;
    

    if (suBaddieActorArray != NULL) {
        sp54 = volatileFlag_get(VOLATILE_FLAG_65_CHEAT_ENTERED);
        for(temp_v1 = suBaddieActorArray->cnt - 1; temp_v1 >= 0; temp_v1--){
            actor = &suBaddieActorArray->data[temp_v1];
            actor_info = actor->actor_info;
            marker = actor->marker;
            anim_ctrl = actor->animctrl;
            temp_s1 = actor->actor_info->unk18;
            if (marker->propPtr->unk8_4) {
                if(sp54){
                    if (  actor->actor_info->unk20 && volatileFlag_get( actor->actor_info->unk20)) {
                        marker_despawn(marker);
                    }
                }
                if (!actor->despawn_flag) {
                    if (marker->unk2C_2) {
                        marker->actorUpdate2Func(actor);
                        if (anim_ctrl != NULL) {
                                actor->sound_timer = animctrl_getAnimTimer(anim_ctrl);
                        }
                    } else if (!temp_s1 || (temp_s1 && func_803296D8(actor, temp_s1))) {
                        if ( marker->actorUpdateFunc != NULL) {
                             marker->actorUpdateFunc(actor);
                            if (anim_ctrl != NULL) {
                                    actor->sound_timer = animctrl_getAnimTimer(anim_ctrl);
                            }
                        }
                    }
                    actor->unk124_7 = TRUE;
                    actor->unk138_28 = FALSE;
                    if (anim_ctrl != NULL) {
                        animctrl_update(anim_ctrl);
                    }
                    if (marker->unk4C) {
                        temp_v0_3 = func_80330C74(actor);
                        if (temp_v0_3) {
                            func_8033F7A4(marker, temp_v0_3);
                            func_8034C21C(marker);
                        }
                    }
                    position[0] = (s32) actor->position[0];
                    position[1] = (s32) actor->position[1];
                    position[2] = (s32) actor->position[2];
                    rotation[0] = (s32) actor->pitch;
                    rotation[1] = (s32) actor->yaw;
                    rotation[2] = (s32) actor->roll;
                    func_8032F6A4(position, marker, rotation);
                    if (actor->unk124_11) {
                        func_80326324(actor);
                    }
                    if (actor->unk148) {
                        if (!actor->despawn_flag) {
                            skeletalAnim_update(actor->unk148, time_getDelta(), marker->unk14_21);
                        } else {
                            skeletalAnim_set(actor->unk148, 0, 0.0f, 0.0f);
                        }
                    }
                    if ((actor_info->shadow_scale != 0.0f) && actor->unk124_6 && marker->unk14_21) {
                        func_802D7124(actor, actor_info->shadow_scale);
                    }
                    if (actor->is_bundle) {
                        actor = &suBaddieActorArray->data[temp_v1];
                        bundle_update(actor);
                    }
                }
            }
        }
    }
    if (D_8036E56C != 0) {
        func_802EE5F0(D_8036E56C);
    }
    if (D_8036E570 != 0) {
        func_802F2D8C(D_8036E570);
    }
}

s32 func_80326C18(void){
    return D_80383394;
}

void func_80326C24(s32 arg0){
    D_80383394 = arg0;
}

Actor *actorArray_findActorFromModelId(enum asset_e model_id) {
    Actor *actor_begin;
    Actor *i_actor;

    actor_begin = suBaddieActorArray->data;
    for(i_actor = actor_begin; (i_actor - actor_begin) < suBaddieActorArray->cnt; i_actor++){
        if ((model_id == i_actor->marker->modelId) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

Actor *actorArray_findActorFromMarkerId(enum marker_e marker_id) {
    Actor *actor_begin;
    Actor *i_actor;

    actor_begin = suBaddieActorArray->data;
    for(i_actor = actor_begin; i_actor - actor_begin < suBaddieActorArray->cnt; i_actor++) {
        if ((marker_id == i_actor->marker->id) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

/* 
 * find the closest actor to position with actor_id and not in state
 * returns Actor* and distance (last arg)
 */
Actor *actorArray_findClosestActorFromActorId(f32 position[3], enum actor_e actor_id, s32 exclude_state, f32 *min_distance_ptr) {
    Actor *begin;
    Actor *i_actor;
    f32 i_dist;
    f32 min_dist;
    s32 *closest_actor;

    if (suBaddieActorArray != NULL) {
        begin = suBaddieActorArray->data;
        closest_actor = NULL;
        min_dist = 1e+10f;
        for(i_actor = begin; (i_actor - begin) < suBaddieActorArray->cnt; i_actor++){
            if ( ((actor_id == i_actor->modelCacheIndex) || (actor_id < 0)) 
                 && (exclude_state != i_actor->state) 
                 && (i_actor->modelCacheIndex != ACTOR_17_PLAYER_SHADOW) 
                 && (i_actor->modelCacheIndex != 0x108) 
                 && !i_actor->despawn_flag
            ) {
                i_dist = ml_vec3f_length(position, i_actor->position);
                if (i_dist < min_dist) {
                    min_dist = i_dist;
                    closest_actor = i_actor;
                }
            }
        }
        if (min_distance_ptr != NULL) {
            *min_distance_ptr = min_dist;
        }
        return closest_actor;
    }
    return NULL;
}

Actor *actorArray_findActorFromActorId(enum actor_e actor_id) {
    Actor *begin;
    Actor *end;
    Actor *i_actor;

    begin = suBaddieActorArray->data;
    end = begin + suBaddieActorArray->cnt;
    for(i_actor = begin; i_actor < end; i_actor++){
        if ((actor_id == i_actor->modelCacheIndex) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

s32 actorArray_actorCount(enum actor_e actor_id) {
    Actor *begin;
    Actor *end;
    Actor *i_actor;
    s32 var_v1;

    var_v1 = 0;
    begin = suBaddieActorArray->data;
    end = begin + suBaddieActorArray->cnt;
    for(i_actor = begin; i_actor < end; i_actor++){
        if ((actor_id == i_actor->modelCacheIndex) && !i_actor->despawn_flag) {
            var_v1 += 1;
        }
    }
    return var_v1;
}

Actor **actorArray_findJiggyActors(void) {
    Actor *begin;
    Actor *i_actor;

    s32 var_a1;

    begin = suBaddieActorArray->data;
    for(i_actor = begin, var_a1 = 0; (suBaddieActorArray != NULL) && ((i_actor - begin) < suBaddieActorArray->cnt); i_actor++){
        if ((i_actor->modelCacheIndex == ACTOR_46_JIGGY) && !i_actor->despawn_flag) {
            suBaddieJiggyArray[var_a1] = i_actor;
            var_a1 += 1;
        }
    }
    suBaddieJiggyArray[var_a1] = NULL;
    return suBaddieJiggyArray;
}

bool func_803270B8(f32 arg0[3], f32 arg1, enum marker_collision_func_type_e arg2, int (*arg3)(Actor *), ActorMarker * arg4){
    bool var_s4;
    Actor * start;
    Actor * i_ptr;

    var_s4 = FALSE;
    start = &suBaddieActorArray->data[0];
    for(i_ptr = start; (suBaddieActorArray != NULL) && (i_ptr - start < suBaddieActorArray->cnt); i_ptr++){
        if( !i_ptr->despawn_flag 
            && i_ptr->marker->collidable 
            && ((arg3 == NULL) || arg3(i_ptr)) 
            && ml_vec3f_within_distance(i_ptr->position, arg0, arg1)
        ) {
            if (i_ptr->marker->unk58 == NULL || i_ptr->marker->unk58(i_ptr->marker, arg4)
            ) {
                var_s4 = TRUE;
                if (!func_8033D410(arg4, i_ptr->marker)) {
                    marker_callCollisionFunc(i_ptr->marker, arg4, arg2);
                }
            }
        }
    }
    return var_s4;
}


void func_8032728C(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *)){
    func_803270B8(arg0, arg1, arg2, arg3, baMarker_get());
}

void func_803272D0(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *)){
    func_803270B8(arg0, arg1, arg2, arg3, NULL);
}

Actor *actor_new(s32 position[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    ActorAnimationInfo * sp54;
    s32 i;
    f32 sp44[3];
    
    if(suBaddieActorArray == NULL){
        suBaddieActorArray = (ActorArray *)malloc(sizeof(ActorArray) + 20*sizeof(Actor));
        suBaddieActorArray->cnt = 0;
        suBaddieActorArray->max_cnt = 20;
    }
    
    if(suBaddieActorArray->cnt + 1 > suBaddieActorArray->max_cnt){
        suBaddieActorArray->max_cnt = suBaddieActorArray->cnt + 5;
        suBaddieActorArray = (ActorArray *)realloc(suBaddieActorArray, sizeof(ActorArray) + suBaddieActorArray->max_cnt*sizeof(Actor));
    }

    ++suBaddieActorArray->cnt;
    suLastBaddie = &suBaddieActorArray->data[suBaddieActorArray->cnt - 1];

    suLastBaddie->actor_info = actorInfo;
    suLastBaddie->unk10_25 = 0;
    suLastBaddie->unk10_18 = 0;
    suLastBaddie->state = actorInfo->startAnimation;
    suLastBaddie->position_x = (f32)position[0];
    suLastBaddie->position_y = (f32)position[1];
    suLastBaddie->position_z = (f32)position[2];
    suLastBaddie->unkF4_8 = 0;
    suLastBaddie->yaw = (f32) yaw;
    suLastBaddie->yaw_ideal = (f32) yaw;
    suLastBaddie->pitch = 0.0f;
    suLastBaddie->roll = 0.0f;
    suLastBaddie->unk6C = 0.0f;
    suLastBaddie->actor_specific_1_f = 0.0f;
    suLastBaddie->unk10_12 = 0;
    suLastBaddie->unk38_0 = 0;
    suLastBaddie->unk38_31 = 0;
    suLastBaddie->unk58_0 = 1;
    suLastBaddie->unk40 = 0;
    suLastBaddie->unk44_31 = 0;
    suLastBaddie->despawn_flag = 0;
    suLastBaddie->unk44_14 = -1;
    suLastBaddie->unk48 = 0.0f;
    suLastBaddie->unk4C = 100.0f;
    suLastBaddie->unk10_1 = 1;
    suLastBaddie->unkF4_30 = 0;
    suLastBaddie->unkF4_29 = 0;
    suLastBaddie->scale = 1.0f;
    suLastBaddie->unk124_7 = 0;
    suLastBaddie->unk124_6 = 1;
    suLastBaddie->modelCacheIndex = actorInfo->actorId;
    suLastBaddie->unk44_2 = func_80326C18();
    suLastBaddie->marker = marker_init(position, actorInfo->draw_func, (asset_getFlag(actorInfo->modelId) == 1) ? 0 : 1, actorInfo->markerId, (flags & 0x400) ? 1 : 0);
    suLastBaddie->marker->unk3E_0 = 1;
    suLastBaddie->unk138_28 = 1;
    suLastBaddie->unk10_3 = -1;
    suLastBaddie->unk10_4 = 0;
    suLastBaddie->unk10_8 = 0;
    suLastBaddie->unk10_7 = 0;
    suLastBaddie->unk10_6 = 0;
    suLastBaddie->unk54 = 0.0f;
    suLastBaddie->unk58_31 = 0;
    suLastBaddie->unk5C = 0.0f;
    suLastBaddie->unkF4_31 = 0;
    suLastBaddie->unk138_30 = 0;
    suLastBaddie->unk138_3 = 0;
    suLastBaddie->unk38_21 = 0;
    suLastBaddie->unk38_13 = 0;
    suLastBaddie->unk78_22 = 0;
    suLastBaddie->unk78_31 = 0;
    suLastBaddie->unk74 = 0.0f;
    suLastBaddie->unk70 = 0.0f;
    suLastBaddie->unkF4_24 = 0;
    suLastBaddie->unk140 = 0.0f;
    suLastBaddie->unk144 = 0.0f;
    suLastBaddie->unk44_1 = 0;
    suLastBaddie->unk44_0 = 0;
    suLastBaddie->initialized = FALSE;
    suLastBaddie->volatile_initialized = FALSE;
    suLastBaddie->lifetime_value = 0.0f;
    suLastBaddie->is_bundle = FALSE;
    suLastBaddie->unk104 = NULL;
    suLastBaddie->unk100 = NULL;
    suLastBaddie->unk158[0] = NULL;
    suLastBaddie->unk158[1] = NULL;
    suLastBaddie->unk78_13 = 0;
    suLastBaddie->unk124_31 = 0;
    suLastBaddie->unkF4_20 = 0;
    suLastBaddie->sound_timer = 0.0f;
    func_8032FFD4(suLastBaddie->marker, suBaddieActorArray->cnt - 1);
    marker_setModelId(suLastBaddie->marker, actorInfo->modelId);
    marker_setActorUpdateFunc(suLastBaddie->marker, actorInfo->update_func);
    marker_setActorUpdate2Func(suLastBaddie->marker, actorInfo->update2_func);
    ml_vec3f_clear(suLastBaddie->unk1C);
    ml_vec3f_clear(suLastBaddie->velocity);
    ml_vec3f_clear(suLastBaddie->spawn_position);
    suLastBaddie->stored_animctrl_index = 0;
    suLastBaddie->unk58_2 = 1;
    suLastBaddie->stored_animctrl_playbackType_ = 0;
    suLastBaddie->stored_animctrl_forwards = 0;
    suLastBaddie->stored_animctrl_smoothTransistion = 0;
    suLastBaddie->stored_animctrl_duration = 0.0f;
    suLastBaddie->stored_animctrl_timer = 0.0f;
    suLastBaddie->unk138_19 = 0;
    suLastBaddie->stored_animctrl_subrangeMin = 0.0f;
    suLastBaddie->stored_animctrl_subrangeMax = 1.0f;
    suLastBaddie->unkF4_22 = 0;
    suLastBaddie->unk58_1 = 0;
    suLastBaddie->unk138_29 = 0;
    suLastBaddie->unk18 = actorInfo->animations;
    suLastBaddie->animctrl = NULL;
    suLastBaddie->stored_animctrl_timer = 0.0f;
    suLastBaddie->unk130 = 0;
    suLastBaddie->unk124_5 = 0;
    suLastBaddie->unk124_3 = 0;
    suLastBaddie->unk138_9 = 0;
    suLastBaddie->unk138_8 = 0;
    suLastBaddie->unk138_25 = 0;
    suLastBaddie->unk16C_3 = 0;
    suLastBaddie->unk16C_2 = 0;
    suLastBaddie->unk16C_1 = 0;
    suLastBaddie->unk16C_0 = 0;
    suLastBaddie->unk17C_31 = 0;
    suLastBaddie->unk14C[0] = NULL;
    suLastBaddie->unk14C[1] = NULL;
    suLastBaddie->unk138_27 = 0;
    suLastBaddie->has_met_before = FALSE;
    suLastBaddie->unk138_23 = 0;
    suLastBaddie->unk138_22 = 0;
    suLastBaddie->unk138_21 = 0;
    suLastBaddie->unk138_20 = 0;
    suLastBaddie->unk174 = 0.0f;
    suLastBaddie->unk178 = 0.0f;
    if( actorInfo->animations){
        sp54 = &suLastBaddie->unk18[suLastBaddie->state];
        if(sp54->index != 0){
            suLastBaddie->animctrl = animctrl_new(0);
            animctrl_reset(suLastBaddie->animctrl);
            animctrl_setIndex(suLastBaddie->animctrl, sp54->index);
            animctrl_setDuration(suLastBaddie->animctrl, sp54->duration);
            animctrl_start(suLastBaddie->animctrl, "subaddie.c", 0x4A5);
        }
    }//L80327BA8
    suLastBaddie->unk124_11 = 0;
    suLastBaddie->alpha_124_19 = 0xff;
    suLastBaddie->depth_mode = MODEL_RENDER_DEPTH_FULL;
    suLastBaddie->unk124_0 = suLastBaddie->unk138_31 = 1;
    for(i = 0; i < 0x10; i++){
        ((s32 *)suLastBaddie->unk7C)[i] = 0;
    }
    for(i = 0; i < 0x0C; i++){
        ((s32 *)suLastBaddie->unkBC)[i] = 0;
    }
    if(flags & ACTOR_FLAG_UNKNOWN_0){
        suLastBaddie->unk10_25 = func_80306DDC(position) + 1;
        if(suLastBaddie->unk10_25 == 0){
            suLastBaddie->unk10_25 = 0;
        }else{
            sp44[0] = (f32)position[0];
            sp44[1] = (f32)position[1];
            sp44[2] = (f32)position[2];
            suLastBaddie->unk10_18 = func_80307258(&sp44, suLastBaddie->unk10_25 - 1, 0) + 1;
        }
    }//L80327D30

    if(flags & ACTOR_FLAG_UNKNOWN_2){
        suLastBaddie->unk10_1 = 0;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_3){
        suLastBaddie->unkF4_30 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_1){
        suLastBaddie->marker->unk44 = 1;
    }
    else if(flags & ACTOR_FLAG_UNKNOWN_6){
        suLastBaddie->marker->unk44 = func_8034A2C8();
    }

    if(flags & ACTOR_FLAG_UNKNOWN_12){
        func_8033F738(suLastBaddie->marker);
        func_8034BFF8(suLastBaddie->marker);
    }

    suLastBaddie->unk148 = 0;
    if(flags & ACTOR_FLAG_UNKNOWN_11){
        suLastBaddie->unk148 = skeletalAnim_new();
    }

    if(flags & ACTOR_FLAG_UNKNOWN_14){
        suLastBaddie->marker->unk50 = func_803406B0();
    }

    if(flags & ACTOR_FLAG_UNKNOWN_4){
        suLastBaddie->unk124_31 = -1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_7){
        suLastBaddie->unkF4_22 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_19){
        suLastBaddie->unk58_1 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_8){
        suLastBaddie->unk130 = func_803255FC;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_9){
        suLastBaddie->marker->unk40_21 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_15){
        suLastBaddie->marker->unk40_20 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_17){
        suLastBaddie->marker->unk40_22 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_22){
        suLastBaddie->marker->unk40_19 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_16){
        suLastBaddie->unk138_9 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_18){
        suLastBaddie->unk138_8 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_21){
        suLastBaddie->unk138_25 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_23){
        suLastBaddie->unk16C_3 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_24){
        suLastBaddie->unk16C_2 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_25){
        suLastBaddie->unk16C_1 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_26){
        suLastBaddie->unk17C_31 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_13){
        suLastBaddie->unk138_29 = 1;
    }

    if(flags & ACTOR_FLAG_UNKNOWN_20){
        suLastBaddie->unk58_2 = 0;
    }

    suLastBaddie->unk154 = 0x005e0000;
    suLastBaddie->marker->unk54 = func_8032B5C0;

    
    for(i = 0; i < 3; ++i){
        suLastBaddie->unk164[i] = 0x63;
    }

    suLastBaddie->unk170 = -10.0f;
    suLastBaddie->unk138_7 = 0;
    suLastBaddie->unk3C = flags;
    
    return suLastBaddie;
}

static void __actor_free(ActorMarker *arg0, Actor *arg1){
    s32 arrayEnd;

    //copy last actor over actor to delete
    arrayEnd = &suBaddieActorArray->data[suBaddieActorArray->cnt - 1];
    func_80325FE8(arg1);
    if((s32)arg1 != arrayEnd)
        memcpy(arg1, arrayEnd, 0x180); //memcpy
    arg1->marker->actrArrayIdx = arg0->actrArrayIdx;

    //remove last actor from actor array
    suBaddieActorArray->cnt--;

    //shrink actor array capacity
    if(suBaddieActorArray->cnt + 8 <= suBaddieActorArray->max_cnt){
        suBaddieActorArray->max_cnt = suBaddieActorArray->cnt + 4;
        suBaddieActorArray = (ActorArray *)realloc(suBaddieActorArray, suBaddieActorArray->max_cnt*sizeof(Actor) + sizeof(ActorArray));
    }

    marker_free(arg0);
}

Actor *actor_spawnWithYaw_s32(enum actor_e id, s32 (* pos)[3], s32 rot){
    return __actor_spawnWithYaw_s32(id, pos, rot);
}

Actor *actor_spawnWithYaw_f32(enum actor_e id, f32 pos[3], s32 rot){
    s32 pos_float[3];
    int i;

    for(i = 0; i< 3; i++){
        pos_float[i] = pos[i];
    }

    __actor_spawnWithYaw_s32(id, &pos_float, rot);
}

Actor * spawn_child_actor(enum actor_e id, Actor ** parent){
    Actor *child;
    ActorMarker * sp28 =  (*parent)->marker;
    s32 sp1C[3];
    sp1C[0] = (*parent)->position_x;
    sp1C[1] = (*parent)->position_y;
    sp1C[2] = (*parent)->position_z;
    child = __actor_spawnWithYaw_s32(id, sp1C, (*parent)->yaw);
    *parent = marker_getActor(sp28);
    return child;
}

Actor *func_80328230(enum actor_e id, f32 pos[3], f32 rot[3]){
    int i;
    s32 sp30[3];
    Actor *actor;

    for(i = 0; i < 3; i++){
        sp30[i] = (s32)pos[i];
    }
    actor = func_803055E0(id, sp30, (f32) rot[1], 0, 0);
    actor->pitch = rot[0];
    return actor;
}

Actor *actor_spawnWithYaw_s16(enum actor_e id, s16 (* pos)[3], s32 yaw){
    s32 sp24[3];
    int i;

    for(i = 0; i< 3; i++){
        sp24[i] = (*pos)[i];
    }

    return __actor_spawnWithYaw_s32(id, &sp24, yaw);
}

void marker_despawn(ActorMarker *marker){
    Actor * actor = marker_getActor(marker);
    if(D_8036E574){
        actor->despawn_flag = 1;
        D_8036E578++;
        if(actor->unk104 && actor->modelCacheIndex != 0x108){
            marker_getActor(actor->unk104)->despawn_flag = 1;
            marker_getActor(actor->unk104)->unk104 = NULL;
            D_8036E578++;
            actor->unk104 = NULL;
        }
    }
    else{
        __actor_free(marker, actor);
    }
}

void func_803283BC(void){
    D_8036E574 = 1;
    D_8036E578 = 0;
}

//actorArray_flushDespawns
void func_803283D4(void){
    int i;
    Actor *iPtr;
    if(D_8036E574){
        if(D_8036E578)
            for(i = suBaddieActorArray->cnt-1; i >= 0 ; i--){
                iPtr = &suBaddieActorArray->data[i];
                if(iPtr->despawn_flag)
                    __actor_free(iPtr->marker, iPtr);
            }
    }
    D_8036E574 = 0;
    D_8036E578 = 0;

}


void func_80328478(f32 arg0[3], f32 arg1, f32 arg2){
    f32 sp1C[3];
    sp1C[0] = arg2;
    sp1C[1] = 0.0f;
    sp1C[2] = 0.0f;
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, arg1 - 90.0);

    arg0[0] += sp1C[0]; 
    arg0[1] += sp1C[1]; 
    arg0[2] += sp1C[2]; 
}

static bool __subaddie_set_state(Actor *this, s32 state)
{
    ActorAnimationInfo *animInfo;
    s32 index;
    this->state = state;
    if (this->unk18 == 0)
        return FALSE;
    
    animInfo = this->unk18 + state;
    index = animInfo->index;
    if (1);

    if (index != 0){
        if (this->animctrl == NULL){
            this->animctrl = animctrl_new(0);
            animctrl_reset(this->animctrl);
        }
        animctrl_setIndex(this->animctrl, animInfo->index);
        animctrl_setDuration(this->animctrl, animInfo->duration);
        animctrl_setDirection(this->animctrl, mvmt_dir_forwards);
    }
    else if (this->animctrl) {
        animctrl_setPlaybackType(this->animctrl, ANIMCTRL_STOPPED);
        animctrl_setDirection(this->animctrl, mvmt_dir_forwards);
    }
    return TRUE;
}

void func_803285E8(Actor *this, f32 anim_start_position, int direction){
    animctrl_setStart(this->animctrl, anim_start_position);

    if (direction != -1) {
        animctrl_setDirection(this->animctrl, direction);
    }

    this->sound_timer = anim_start_position;
}



int func_8032863C(AnimCtrl *anim_ctrl, f32 min, f32 max) {
    f32 timer;
    s32 sp18;

    timer = animctrl_getAnimTimer(anim_ctrl);
    if ((timer < min) || (max <= timer)) {
        return -1;
    }
    sp18 = animctrl_isPlayedForwards(anim_ctrl);
    if( ((sp18 == 0) && (min <= timer) && (timer < (min + 0.015))) 
        || ((sp18 == 1) && (timer < max) && ((max - 0.015) <= timer))
    ) {
        sp18 = (sp18) ? 0 : 1;
        animctrl_setDirection(anim_ctrl, sp18);
        return sp18 + 2;
    }
    return sp18;
}


s32 func_80328748(AnimCtrl *anim_ctrl, f32 min, f32 max) {
    s32 sp24;
    f32 sp20;

    sp24 = func_8032863C(anim_ctrl, min, max);
    if (sp24 != -1) {
        return sp24;
    }
    sp20 = animctrl_getAnimTimer(anim_ctrl);
    if (animctrl_isPlayedForwards(anim_ctrl) == TRUE) {
        if (max <= sp20) {
            animctrl_setAnimTimer(anim_ctrl, max);
            animctrl_setDirection(anim_ctrl, 0);
            sp24 = 2;
        }
    } else if (sp20 < min) {
        animctrl_setAnimTimer(anim_ctrl, min);
        animctrl_setDirection(anim_ctrl, 1);
        sp24 = 3;
    }
    return sp24;
}

int func_8032881C(Actor *this){
    if(this->animctrl){
        if(animctrl_getPlaybackType(this->animctrl) == ANIMCTRL_ONCE){
            return animctrl_isStopped(this->animctrl);
        }
    }
    return 0;
}

int actor_animationIsAt(Actor *this, f32 arg1){
    f32 f2 = animctrl_getAnimTimer(this->animctrl);
    if(f2 == this->sound_timer){
        return 0;
    }
    else {
        if(animctrl_isPlayedForwards(this->animctrl)){
            if(this->sound_timer < f2){
                return this->sound_timer <= arg1 && arg1 < f2;
            }
            else{//L8032892C
                return this->sound_timer <= arg1 || arg1 < f2;
            }
        }
        else{
            if(f2 < this->sound_timer){
                return arg1 <= this->sound_timer && f2 < arg1;
            }
            else{//L8032892C
                return arg1 <= this->sound_timer || f2 < arg1;
            }
        }
    }
}

void func_803289EC(Actor *this , f32 anim_start_position, int direction){
    func_803285E8(this, anim_start_position, direction);
    animctrl_start(this->animctrl, "subaddie.c", 0x6b1);
}

int func_80328A2C(Actor *this, f32 arg1, s32 direction, f32 probability){
    if(randf() < probability){
        func_803289EC(this, arg1, direction);
        return 1;
    }
    else{
        return 0;
    }
}

void subaddie_set_state(Actor * this, u32 arg1){
    if(__subaddie_set_state(this, arg1) && this->animctrl){
        animctrl_start(this->animctrl, "subaddie.c", 0X6CA);
    }
}

void subaddie_set_state_forward(Actor * this, s32 arg1){
    subaddie_set_state_with_direction(this, arg1, 0.0f, 1);
}

void subaddie_set_state_looped(Actor * this, u32 arg1){
    if(__subaddie_set_state(this, arg1) && this->animctrl){
        animctrl_setPlaybackType(this->animctrl,  ANIMCTRL_LOOP);
        func_803289EC(this, 0.0f, 1);
    }
}

/* actor - maybe plays actor's animation with set probability */
int subaddie_maybe_set_state(Actor *this, s32 myAnimId, f32 chance){
    if(randf() < chance){
        subaddie_set_state(this, myAnimId);
        return 1;
    }
    return 0;
}

void subaddie_set_state_with_direction(Actor * this, s32 myAnimId, f32 anim_start_position, s32 direction){
    if (__subaddie_set_state(this, myAnimId) && this->animctrl) {
        func_803289EC(this, anim_start_position, direction);
    }
}

bool subaddie_maybe_set_state_position_direction(Actor *this, s32 myAnimId, f32 start_position, s32 direction, f32 probability) {
    if (randf() < probability) {
        if (__subaddie_set_state(this, myAnimId) && this->animctrl) {
            func_803285E8(this, start_position, direction);
            animctrl_start(this->animctrl, "subaddie.c", 0x705);
        }
        return TRUE;
    }
    return FALSE;
}

void subaddie_set_ideal_yaw(Actor * this, int arg1){
    int retVal = arg1;
    while(retVal < 0) retVal += 0x168;
    while(retVal >= 0x168) retVal -= 0x168;
    this->yaw_ideal = retVal;
}

void func_80328CA8(Actor *this, s32 angle) {
    s32 fixedAngle = angle;
    while (fixedAngle < 0) {
        fixedAngle += 360;
    }
    while (fixedAngle >= 360) {
        fixedAngle -= 360;
    }
    this->unk6C = fixedAngle;
}

void func_80328CEC(Actor * this, s32 arg1, s32 min, s32 max){
    f32 f12;
    int abs;
    f12 = (randf() - 0.5)*(max - min)*2;
    abs = (0.0f <= f12) ? min : -min;
    subaddie_set_ideal_yaw(this, abs + (arg1 + f12));
}

f32 func_80328DAC(Actor *this){
    return D_8036E598[this->unk10_3];
}

f32 func_80328DCC(Actor *this, f32 angle, f32 angle_ideal, s32 arg3) {
    f32 var_f2;
    s32 var_t16;

    if (angle_ideal == angle) {
        return angle;
    }

    var_f2 = angle_ideal - angle;
    if (var_f2 >= 180.0f) {
        var_f2 -= 360.0f;
    }
    if (var_f2 < -180.0f) {
        var_f2 += 360.0f;
    }

    if ((this->marker->id != 0x12) && (this->marker->unk2C_2 == 1) && ((var_f2 >= 50.0f) || (var_f2 < -50.0f))) {
        return angle_ideal;
    }
    var_f2 = var_f2 / func_80328DAC(this);
    var_t16 = arg3;
    var_f2 = (0.0f < var_f2) ? MIN(var_f2, var_t16) : MAX(var_f2, -arg3) ;

    var_f2 += angle;
    while (var_f2 < 0.0f) {
        var_f2 += 360.0f;
    }
    while (var_f2 >= 360.0f) {
            var_f2 -= 360.0f;
    }
    return var_f2;
}

void func_80328FB0(Actor *this, f32 arg1){
    this->yaw = func_80328DCC(this, this->yaw, this->yaw_ideal, (s32)arg1);
}

void func_80328FF0(Actor *arg0, f32 arg1) {
    arg0->pitch = func_80328DCC(arg0, arg0->pitch, arg0->unk6C, (s32) arg1);
}

int func_80329030(Actor *arg0, s32 arg1) {
    return !func_8032CA80(arg0, arg1);
}

s32 func_80329054(s32 arg0, s32 arg1) {
    return !func_8032CA80(arg0, arg1 + 4);
}

bool func_80329078(Actor *this, s32 arg1, s32 arg2){
    f32 sp1C[3];

    if(this->unk10_25 == 0)
        return TRUE;

    sp1C[0] = this->position[0];
    sp1C[1] = this->position[1];
    sp1C[2] = this->position[2];
    func_80328478(sp1C, arg1, arg2);
    if(func_80307258(sp1C, this->unk10_25 - 1, this->unk10_18 - 1) == -1){
        return FALSE;
    }
    return TRUE;
}

bool func_80329140(Actor *this, s32 arg1, s32 arg2){
    s32 var_v0;
    f32 sp20[3];

    sp20[0] = this->position[0];
    sp20[1] = this->position[1];
    sp20[2] = this->position[2];
    func_80328478(sp20, arg1, arg2);
    var_v0 = func_80309D58(sp20, this->unk10_18);
    if(this->unk10_18 == 0){
        this->unk10_18 = var_v0;
    }
    if(var_v0 == 0){
        if (this->unk10_18 != 0) 
            return FALSE;
    }
    return TRUE;
}

int func_80329210(Actor * arg0, f32 (* arg1)[3]){
    return arg0->unk10_25 < 1 
        || func_80307258(arg1, arg0->unk10_25 - 1, arg0->unk10_18-1) != -1;
}

bool func_80329260(Actor *this, f32 p1[3]){
    s32 var_v0;
    var_v0 = func_80309D58(p1, this->unk10_18);
    if(this->unk10_18 == 0){
        this->unk10_18 = var_v0;
    }
    if(var_v0 == 0 && this->unk10_18 != 0){
        return FALSE;
    }
    return TRUE;
}

bool func_803292E0(Actor *this){
    f32 player_position[3];
    if(this->unk10_25 == 0){
        return 1;
    }

    _player_getPosition(player_position);
    return func_80307258(player_position, this->unk10_25 - 1, this->unk10_18 - 1) != -1;
}

bool func_80329354(Actor *this){
    f32 sp1C[3];

    _player_getPosition(sp1C);
    return func_80329260(this, sp1C);
}

bool func_80329384(Actor *this, f32 arg1){
    f32 sp1C[3];

    if(this->unk10_25 == 0)
        return TRUE;

    _player_getPosition(sp1C);

    return func_80307258(sp1C, this->unk10_25 - 1, this->unk10_18 - 1) != -1
        && (sp1C[1] < (this->position[1] + arg1))
        && ((this->position[1] - arg1) < sp1C[1]);
}

bool func_8032944C(Actor *this){
    s32 v1;
    
    v1 = this->pitch - this->unk6C;
    return ((-3 <= v1) && (v1 <= 3));
}

bool func_80329480(Actor *this){
    s32 v1;

    v1 = this->yaw - this->yaw_ideal;
    return ((-3 <= v1) && (v1 <= 3));
}

bool func_803294B4(Actor *this, s32 arg1){
    s32 v1;

    v1 = this->yaw - this->yaw_ideal;
    return ((-arg1 <= v1) && (v1 <= arg1));
}

bool func_803294F0(Actor *this, s32 arg1, s32 arg2){
    s32 v1;

    v1 = this->yaw - arg2;
    return ((-arg1 <= v1) && (v1 <= arg1));
}

bool func_80329530(Actor *this, s32 dist){
    if( func_8028F098() 
        && !volatileFlag_get(VOLATILE_FLAG_BF) 
        && subaddie_playerIsWithinSphere(this, dist)
    ){
        return TRUE;
    }
    return FALSE;
}

bool subaddie_playerIsWithinSphere(Actor *this, s32 dist){
    f32 sp24[3];
    f32 sp18[3];

    func_8028E964(sp24);
    _player_getPosition(sp18);
    sp24[1] = sp18[1];
    if( ( (this->position_x - sp24[0])*(this->position_x - sp24[0]) 
          + (this->position_y - sp24[1])*(this->position_y - sp24[1])
          + (this->position_z - sp24[2])*(this->position_z - sp24[2]) 
        ) < dist*dist
    ){
        return TRUE;
    }
    return FALSE;
}

bool subaddie_playerIsWithinAsymmetricCylinder(Actor *this, s32 radius, s32 d_upper, s32 d_lower){
    f32 sp1C[3];

    player_getPosition(sp1C);

    if(((this->position[1] + d_upper) < sp1C[1]) || (sp1C[1] < (this->position[1] - d_lower))){
        return FALSE;
    }
    return subaddie_playerIsWithinSphere(this, radius);

}

bool subaddie_playerIsWithinCylinder(Actor *this, s32 radius, s32 d_y){
    return subaddie_playerIsWithinAsymmetricCylinder(this, radius, d_y, d_y);
}

bool func_803296D8(Actor *this, s32 dist){
    if(!this->unk124_7){
        return TRUE;
    }
    else{
        return func_80329530(this, dist);
    }
}

s32 func_8032970C(Actor *this){
    f32 sp24[3];
    f32 plyr_pos[3];

    func_8028E964(sp24);
    _player_getPosition(plyr_pos);
    sp24[1] = plyr_pos[1];
    return (s32) DIST_SQ_VEC3F(this->position, sp24);
}

s32 func_80329784(Actor *this){
    f32 sp1C[3];

    func_8028E964(sp1C);
    return (s32)func_80257204(this->position[0], this->position[2], sp1C[0], sp1C[2]);
}

s32 func_803297C8(Actor *arg0, f32 arg1[3]){
    return (s32)func_80257204(arg0->position[0], arg0->position[2], arg1[0], arg1[2]);
}

void func_803297FC(Actor *arg0, f32 *o1, f32 *o2){
    f32 sp2C[3];

    _player_getPosition(sp2C);
    func_8025727C(
        arg0->position[0], arg0->position[1], arg0->position[2],
        sp2C[0], sp2C[1], sp2C[2],
        o1, o2
    );
    *o1 = 360.0f - *o1;
}

void func_80329878(Actor *arg0, f32 arg1){
    arg0->actor_specific_1_f -= arg1;

    if (arg0->actor_specific_1_f < 0.0f) {
        arg0->actor_specific_1_f = 0.0f;
    }
}

void actor_playAnimationOnce(Actor *this){
    if(this->animctrl)
        animctrl_setPlaybackType(this->animctrl, ANIMCTRL_ONCE);
}

void actor_loopAnimation(Actor *this){
    if(this->animctrl)
        animctrl_setPlaybackType(this->animctrl,  ANIMCTRL_LOOP);
}

s32 func_80329904(ActorMarker *arg0, s32 arg1, f32 *arg2){
    func_8034A174(arg0->unk44, arg1, arg2);
    return arg0->unk14_21;
}

struct5Bs *func_80329934(void){
    return D_8036E568;
}

s32 func_80329940(void){
    return D_8036E56C;
}

Struct64s* func_8032994C(void){
    return D_8036E570;
}

//marker_getActorPtr
Actor *marker_getActor(ActorMarker *this){
    return &(suBaddieActorArray->data[this->actrArrayIdx]);
}

Actor *subaddie_getLinkedActor(Actor *this){
    if(this->unk100 == NULL)
        return NULL;
    return marker_getActor(this->unk100);
}

void func_803299B4(Actor *arg0) {
    s32 position[3];
    s32 rotation[3];

    arg0->marker->collisionFunc = arg0->unk108;
    arg0->marker->collision2Func = arg0->unk10C;
    arg0->marker->dieFunc = arg0->unk134;
    arg0->marker->unk54 = arg0->unk160;
    arg0->marker->unk58 = arg0->unk168;
    arg0->marker->actorFreeFunc = arg0->backupFreeFunc;
    arg0->marker->unk5C = arg0->unk16C_31;
    arg0->marker->propPtr->unk8_3 = arg0->unkF4_28;
    arg0->marker->propPtr->unk8_2 = arg0->unkF4_27;
    arg0->marker->unk2C_1 = arg0->unkF4_26;
    arg0->marker->collidable = arg0->stored_marker_collidable;

    arg0->unk124_7  = FALSE;
    arg0->unk138_7 = 0;
    position[0] = (s32) arg0->position[0];
    position[1] = (s32) arg0->position[1];
    position[2] = (s32) arg0->position[2];
    rotation[0] = (s32) arg0->pitch;
    rotation[1] = (s32) arg0->yaw;
    rotation[2] = (s32) arg0->roll;
    func_8032F6A4(position, arg0->marker, rotation);
}

void func_80329B68(Actor *this){
    if(this->animctrl == NULL)
        return;

    if(this->stored_animctrl_playbackType_){
        animctrl_setPlaybackType(this->animctrl, this->stored_animctrl_playbackType_);
    }
    animctrl_setIndex(this->animctrl, this->stored_animctrl_index);
    animctrl_setDirection(this->animctrl, this->stored_animctrl_forwards);
    animctrl_setSmoothTransition(this->animctrl, this->stored_animctrl_smoothTransistion);
    animctrl_setDuration(this->animctrl, this->stored_animctrl_duration);
    animctrl_setStart(this->animctrl, this->stored_animctrl_timer);
    animctrl_setSubRange(this->animctrl, this->stored_animctrl_subrangeMin, this->stored_animctrl_subrangeMax);
    animctrl_start(this->animctrl, "subaddie.c", 0x8fd);
    animctrl_setTimer(this->animctrl, this->sound_timer);
}

void actor_copy(Actor *dst, Actor *src){
    dst->marker = src->marker;
    dst->animctrl = src->animctrl;
    dst->unk44_14 = src->unk44_14;
    dst->unk148 = src->unk148;
    dst->unk14C[0] = src->unk14C[0];
    dst->unk14C[1] = src->unk14C[1];
    memcpy(src, dst, sizeof(Actor));
}

void *actors_appendToSavestate(void * begin, u32 end){
    void *sp3C = begin;
    Actor* s0;
    Actor* s1;
    u32 sp30; //SavedActorDataSize
    u32 sp2C; //SavedActorDataOffset
   
    if(suBaddieActorArray){
        sp30 = 0;
        for(s1 = suBaddieActorArray->data; s1 < &suBaddieActorArray->data[(u32) suBaddieActorArray->cnt]; s1++){
            if( s1->marker
                && s1->unk10_1 == 1
                && s1->despawn_flag == 0
                && s1->unk40 == 0
            ){
                sp30++;
            }
        }
        sp2C = end - (u32)sp3C;
        sp3C = realloc(sp3C, sp2C + sizeof(u32) + sp30*sizeof(Actor));

        end = (u32)sp3C + sp2C;
        *(u32 *)end = sp30;
        s0 = (Actor *)((u8*)end + sizeof(u32));
        for(s1 = suBaddieActorArray->data; s1 < &suBaddieActorArray->data[(u32) suBaddieActorArray->cnt]; s1++){
            if( s1->marker
                && s1->unk10_1 == 1
                && s1->despawn_flag == 0
                && s1->unk40 == 0
            ){
                memcpy(s0, s1, sizeof(Actor));
                s0->unk40 = 0;
                s0->unk138_28 = 1;
                s0->unk14C[0] =s0->unk14C[1] = NULL;
                // s0->unk14C = NULL;
                s0->unk148 = NULL;
                s0->volatile_initialized = FALSE;
                s0->unk44_31 = 0;
                s0->unk104 = NULL;
                s0->unk100 = NULL;
                s0->unk158[0] = NULL;
                s0->unk158[1] = NULL;
                s0->unk138_19 = s1->marker->id;
                s0->unk108 = s1->marker->collisionFunc;
                s0->unk10C = s1->marker->collision2Func;
                s0->unk134 = s1->marker->dieFunc;
                s0->unk160 = s1->marker->unk54;
                s0->unk168 = s1->marker->unk58;
                s0->backupFreeFunc = s1->marker->actorFreeFunc;
                s0->unk16C_31 = s1->marker->unk5C;
                s0->unkF4_26 = s1->marker->unk2C_1;
                s0->stored_marker_collidable = s1->marker->collidable;
                s0->unkF4_28 = s1->marker->propPtr->unk8_3;
                s0->unkF4_27 = s1->marker->propPtr->unk8_2;
                //80329F94
                if(s0->animctrl){
                    s0->stored_animctrl_index = animctrl_getIndex(s0->animctrl);
                    s0->stored_animctrl_playbackType_ = animctrl_getPlaybackType(s0->animctrl);
                    s0->stored_animctrl_forwards = animctrl_isPlayedForwards(s0->animctrl);
                    s0->stored_animctrl_smoothTransistion = animctrl_isSmoothTransistion(s0->animctrl);
                    s0->stored_animctrl_duration = animctrl_getDuration(s0->animctrl);
                    s0->stored_animctrl_timer = animctrl_getAnimTimer(s0->animctrl);
                    animctrl_getSubRange(s0->animctrl, &s0->stored_animctrl_subrangeMin, &s0->stored_animctrl_subrangeMax);
                }
                s0->animctrl = NULL;
                s0->marker = NULL;
                s0++;
            }
        }
    }
    return sp3C;
}



void func_8032A09C(s32 arg0, ActorListSaveState *arg1) {
    Actor **temp_v1;
    s32 pad;
    Actor *var_s0;
    Actor *temp_v0_6;
    s32 var_s2;
    Actor **sp60;
    Actor **sp5C;
    s32 sp50[3];
    s32 var_s3;
    
    spawnQueue_lock();
    if (suBaddieActorArray != NULL) {
        func_803283BC();
        var_s3 = 0;
        var_s0 = arg1->actor_save_state;
        for(var_s2 = arg1->cnt; var_s2 != 0; var_s2--) {
            if ((var_s0->unk78_13 != 0) && (var_s3 < var_s0->unk78_13)) {
                var_s3 = var_s0->unk78_13;
            }
            var_s0++;
        }
        for(var_s0 = &suBaddieActorArray->data[0]; var_s0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_s0++){
            if ((var_s0->unk78_13 != 0) && (var_s3 < var_s0->unk78_13)) {
                var_s3 = var_s0->unk78_13;
            }
        }

        var_s3++;
        
        sp60 = malloc(var_s3*sizeof(Actor *));
        pad = sp5C + var_s2;
        sp5C = malloc(var_s3*sizeof(Actor *));
        for (var_s2 = 0; var_s2 < var_s3; var_s2++) {
            *(u32*)&sp60[var_s2] = 0; 
            *(u32*)&sp5C[var_s2] = 0;
        }

       
        var_s0 = arg1->actor_save_state;
        for(var_s2 = arg1->cnt; var_s2 != 0; var_s2--) {
            if (var_s0->unk78_13 != 0) {
                sp5C[var_s0->unk78_13] = var_s0;
            }
            var_s0++;
        }
        for(var_s0 = &suBaddieActorArray->data[0]; var_s0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_s0++){
            if ((var_s0->unk78_13 != 0)) {
                sp60[var_s0->unk78_13] = var_s0;
            }
        }

        for(var_s2 = 1; var_s2 < var_s3; var_s2++){
            pad = sp5C + var_s2;       
            temp_v1 = sp60 + var_s2;
            if ((*temp_v1 != NULL) && (*(Actor **)pad != NULL) && !(*(Actor **)pad)->unkF4_22) {
                var_s0 = *(Actor **)pad;
                temp_v0_6 = *temp_v1;
                actor_copy(var_s0, temp_v0_6);
                func_80329B68(temp_v0_6);
                func_803299B4(temp_v0_6);
            }
        }
        for(var_s2 = 1; var_s2 < var_s3; var_s2++){
            pad = sp5C + var_s2;       
            temp_v1 = sp60 + var_s2;       
            if ((*temp_v1 != NULL) && !(*temp_v1)->unk58_1 && (*(Actor **)pad == NULL)) {
                marker_despawn((*temp_v1)->marker);
                *temp_v1 = NULL;
            }
        }

        var_s0 = arg1->actor_save_state;
        for(var_s2 = arg1->cnt; var_s2 != 0; var_s2--){
            if (var_s0->unk78_13 == 0) {
                sp50[0] = (s32) var_s0->position[0];
                sp50[1] = (s32) var_s0->position[1];
                sp50[2] = (s32) var_s0->position[2];
                pad = var_s0->yaw;
                temp_v0_6 = actor_spawnWithYaw_s32(var_s0->modelCacheIndex, (sp50), pad);
                actor_copy(var_s0, temp_v0_6);
                func_80329B68(temp_v0_6);
                func_803299B4(temp_v0_6);
            }
            var_s0++;
        }
        func_803283D4();
        free(sp60);
        free(sp5C);
    }
    spawnQueue_unlock();
}

// only used for GV Jinxy Head 2
void func_8032A5F8(void) {
    Actor *var_s0;

    if (suBaddieActorArray != NULL) {
        for(var_s0 = &suBaddieActorArray->data[0]; var_s0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_s0++){
            if (var_s0->unk124_31 == 0xfff) {
                var_s0->unk124_31 = 0;
                func_8032A6A8(var_s0);
            }
        }
    }
}

// only used by GV Jinxy Head 2
void func_8032A6A8(Actor *arg0) {
    f32 var_f0;
    f32 var_f2;
    Actor *var_v0;


    if (arg0->unk44_14 != -1) {
        var_f0 = 1.0f;
        for(var_v0 = &suBaddieActorArray->data[0]; var_v0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_v0++){
            if ((arg0->unk44_14 == var_v0->unk44_14) && (arg0 != var_v0)) {
                var_f2 = var_v0->unk48;
                if ((var_f2 <= var_f0) && (arg0->unk48 <= var_f2)) {
                    if (var_v0->unk78_13 != 0) {
                        arg0->unk124_31 = var_v0->unk78_13;
                        var_f0 = var_f2;
                    }
                }
            }
        }
    }
}

// only used by GV Jinxy Head 2
Actor *func_8032A7AC(Actor *arg0) {
    Actor *var_a0;

    if (arg0->unk124_31 != 0) {
        if (suBaddieActorArray != NULL) {
            for(var_a0 = &suBaddieActorArray->data[0]; var_a0 < &suBaddieActorArray->data[suBaddieActorArray->cnt]; var_a0++){
                if (arg0->unk124_31 == var_a0->unk78_13) {
                    return var_a0;
                }
            }
        }
    }
    return NULL;
}

void func_8032A82C(Actor *arg0, s32 arg1) {
    NodeProp *sp24;
    Actorlocal_Core2_9E370 *sp1C;

    sp1C = &arg0->local;
    sp24 = nodeprop_findByActorIdAndActorPosition(arg1, arg0);
    if (sp24 != NULL) {
        sp1C->unkC = func_80304DA8(sp24);
        nodeprop_getPosition(sp24, sp1C->unk0);
        sp1C->unkE = func_80341EC4(sp1C);
    }
}

void func_8032A88C(Actor *arg0) {
    Actorlocal_Core2_9E370 *sp20;

    sp20 = &arg0->local;
    arg0->yaw_ideal = (f32) func_803297C8(arg0, sp20->unk0);
    func_80328FB0(arg0, 6.0f);
    func_80329030(arg0, 0);
    if ((((arg0->position[0] - sp20->unk0[0]) * (arg0->position[0] - sp20->unk0[0])) + ((arg0->position[2] - sp20->unk0[2]) * (arg0->position[2] - sp20->unk0[2]))) <= 144.0f) {
        arg0->unk44_14 = sp20->unkE;
        arg0->unk48 = 0.0f;
        arg0->marker->unk2C_2 = TRUE;
    }
}

// only called by blubber
void func_8032A95C(Actor *arg0, s32 arg1, s32 arg2) {
    func_80343F00(arg1, arg0->position);
    arg0->unk44_14 = arg1;
    arg0->unk48 = 0.0f;
    arg0->marker->unk2C_2 = TRUE;
    arg0->unk44_1 = TRUE;
    arg0->unk10_3 = 0;
}

bool func_8032A9E4(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp1C[3];

    player_getPosition_s32(sp1C);
    return ((arg0 - sp1C[0])*(arg0 - sp1C[0]) + (arg1 - sp1C[2])*(arg1 - sp1C[2])) < (arg2 * arg2);
}

//actor_setScale
void func_8032AA58(Actor *this, f32 arg1){
    this->scale = arg1;
    this->marker->unk14_10 = 0;
}

void actor_collisionOff(Actor* this){
    this->marker->collidable = FALSE;
}

void actor_collisionOn(Actor* this){
    this->marker->collidable = TRUE;
}

void func_8032AA9C(void){
    spawnQueue_unlock();
}

void func_8032AABC(void){
    Actor *i_ptr;
    Actor *start = &suBaddieActorArray->data[0];
    u32 i;
    u32 cnt;
    
    spawnQueue_lock();


    if(suBaddieActorArray != NULL){    
        cnt =  suBaddieActorArray->cnt;
        for(i_ptr = start, i = 0; i < cnt; i++, i_ptr++){
            i_ptr->marker->unk14_21 = 0;
        }
    }
}

void func_8032AB84(Actor *arg0) {
    s32 var_s0;
    ActorMarker *marker;

    marker = arg0->marker;
    if(arg0->unkF4_30){
        for(var_s0 = 0; var_s0 < 2; var_s0++){
            if (arg0->unk14C[var_s0] == NULL) {
                switch (var_s0) {                       /* irregular */
                    case 0:
                        arg0->unk14C[0] = vtxList_clone(model_getVtxList(func_80330DE4(marker)));
                        break;
                    case 1:
                        arg0->unk14C[1] = (arg0->unk17C_31) ? model_getVtxList(func_80330DE4(marker))
                                        : vtxList_clone(model_getVtxList(func_80330DE4(marker)));
                        break;
                }
            }
        }
    }

    if (marker->unk20 == NULL && arg0->unk3C & 0x20) {
        marker->unk20 = animMtxList_new();
    }
}

void func_8032ACA8(Actor *arg0) {
    s32 var_s0;
    ActorMarker *sp30;

    sp30 = arg0->marker;
    for(var_s0 = 0; var_s0 < 2; var_s0++){
        if (arg0->unk14C[var_s0] != NULL) {
            switch (var_s0) {                       /* irregular */
                case 0:
                    vtxList_free(arg0->unk14C[0]);
                    break;
                case 1:
                    if (!arg0->unk17C_31) {
                        vtxList_free(arg0->unk14C[1]);
                    }
                    break;
            }
            arg0->unk14C[var_s0] = NULL;
        }
    }

    if (sp30->unk20 != NULL) {
        animMtxList_free(sp30->unk20);
        sp30->unk20 = 0;
    }
}


void func_8032AD7C(s32 arg0) {
    s32 var_s0;
    static s32 D_8036E5A8 = 0;
    

    if (suBaddieActorArray != NULL) {
        if (D_8036E5A8 >= suBaddieActorArray->cnt) {
            D_8036E5A8 = 0;
        }
        for(var_s0 = 0; var_s0 < ((arg0 == 1) ? 0xF : suBaddieActorArray->cnt); var_s0++){
            if (func_80330E28(&suBaddieActorArray->data[D_8036E5A8]) == NULL) {
                func_8032ACA8(&suBaddieActorArray->data[D_8036E5A8]);
            }
            D_8036E5A8 = (D_8036E5A8 + 1) % suBaddieActorArray->cnt;
        }
    }
}

void func_8032AEB4(void) {
    Actor *temp_s2;
    Actor *var_s0;

    temp_s2 = &suBaddieActorArray->data[0];
    for(var_s0 = temp_s2; (suBaddieActorArray != NULL) && ((var_s0 - temp_s2) != suBaddieActorArray->cnt); var_s0++){
        func_8032ACA8(var_s0);
    }
}

void actorArray_defrag(void) {
    AnimCtrl *temp_a0_4;
    ParticleEmitter *temp_a0_2;
    ParticleEmitter *temp_a0_3;
    s32 *temp_a0_6;
    s32 *temp_a1;
    s32 temp_a0;
    s32 temp_a0_5;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_t7;
    s32 var_s1;
    Actor *i_actor;
    void *temp_s0_2;
    static s32 D_8036E5AC = 0;


    if (suBaddieActorArray != NULL) {
        for(var_s1 = 0; var_s1 < 8; var_s1++){
            D_8036E5AC++;
            if (D_8036E5AC >= suBaddieActorArray->cnt) {
                D_8036E5AC = 0;
            }
            i_actor = &suBaddieActorArray->data[D_8036E5AC];

            if ((s32)i_actor->marker->unk44 < 0) {
                i_actor->marker->unk44 = func_8034A348(i_actor->marker->unk44);
            }

            if (i_actor->unk158[0] != NULL) {
                i_actor->unk158[0] = partEmitMgr_defragEmitter(i_actor->unk158[0]);
            }

            if (i_actor->unk158[1] != NULL) {
                i_actor->unk158[1] = partEmitMgr_defragEmitter(i_actor->unk158[1]);
            }

            if (i_actor->animctrl != NULL) {
                i_actor->animctrl = animctrl_defrag(i_actor->animctrl);
            }

            if (i_actor->marker->unk20 != NULL) {
                i_actor->marker->unk20 = animMtxList_defrag(i_actor->marker->unk20);
            }

            if (i_actor->unk148 != NULL) {
                i_actor->unk148 = (SkeletalAnimation*)defrag(i_actor->unk148);
            }

            if (i_actor->marker->unk50 != NULL) {
                i_actor->marker->unk50 = func_803406D4(i_actor->marker->unk50);
            }

            if (i_actor->marker->id == MARKER_217_BEE_SWARM) {
                func_802CEB60(i_actor);
            }
        }
        suBaddieActorArray = (ActorArray *) defrag(suBaddieActorArray);
    }

    if (D_8036E568 != 0) {
        D_8036E568 = func_8034A348(D_8036E568);
    }

    if (D_8036E570 != 0) {
        D_8036E570 = func_802F3364(D_8036E570);
    }
}

ActorMarker *func_8032B16C(enum jiggy_e jiggy_id) {
    Actor *temp_s3;
    Actor *var_s0;

    if (suBaddieActorArray != NULL) {
        temp_s3 = &suBaddieActorArray->data[0];
        for(var_s0 = temp_s3; (var_s0 - temp_s3) < suBaddieActorArray->cnt; var_s0++){
            if ((var_s0->marker->id == MARKER_52_JIGGY) && (chjiggy_getJiggyId(&(var_s0->marker)) == jiggy_id)) {
                return var_s0->marker;
            }
        }
    }
    return NULL;
}

void func_8032B258(Actor *this, enum collision_e arg1) {
    f32 sp44;
    f32 sp38[3];
    f32 sp34;

    if ((arg1 == COLLISION_2_DIE) && this->unk138_27 != 0) {
        sp44 = player_getYaw();
        if ((s32)this->marker->unk44 < 0) {
            func_8034A174( this->marker->unk44, 0x20, sp38);
        }
        if (((s32)this->marker->unk44 < 0) && ((sp38[0] != 0.0f) || (sp38[1] != 0.0f) || (sp38[2] != 0.0f))) {
            __spawnQueue_add_5((GenFunction_5) spawnQueue_bundleWithYaw_f32, this->unk138_27 + BUNDLE_15__JIGGY, reinterpret_cast(s32, sp38[0]), reinterpret_cast(s32, sp38[1]), reinterpret_cast(s32, sp38[2]), reinterpret_cast(s32, sp44));
            return;
        }
        else{
            sp34 = this->position[1] + 50.0f;
            __spawnQueue_add_5((GenFunction_5)spawnQueue_bundleWithYaw_f32, this->unk138_27 + BUNDLE_15__JIGGY, reinterpret_cast(s32,this->position[0]), reinterpret_cast(s32,sp34), reinterpret_cast(s32,this->position[2]), reinterpret_cast(s32,sp44));
        }
    }
}

bool func_8032B38C(NodeProp *node, s32 arg1){
    return node->unk8 == 0xF7;
}

void func_8032B3A0(Actor *this, ActorMarker *arg1) {
    f32 sp54[3];
    static s32 D_8036E5B0[4] = {0xFF, 0xFF, 0xFF, 0xC8};


    if (arg1 != NULL) {
        sp54[0] = this->position[0];
        sp54[1] = this->position[1] + func_8033229C(this->marker)*((this->unk16C_0) ? 0.5 : 1.0);
        sp54[2] = this->position[2];
        func_802EE6CC(sp54, 0, D_8036E5B0, !this->unk16C_0, 0.75f, 0.0f, 125, 250, 0);
        func_802F3CF8(sp54, !this->unk16C_0, 
            (arg1->id == 1) ? 1 
            : (player_getTransformation() == TRANSFORM_5_CROC) ? 2
            : 0
        );
    }
}


void func_8032B4DC(Actor *this, ActorMarker *arg1, s32 arg2) {
    f32 sp3C[3];
    static s32 D_8036E5C0[4] = {0xFF, 0xFF, 0xFF, 0xC8};

    if (arg1 != NULL) {
        func_8034A174(this->marker->unk44, arg2, &sp3C);
        func_802EE6CC(sp3C, NULL, D_8036E5C0, !this->unk16C_0, 0.75f, 0.0f, 125, 250, 0);
        func_802F3CF8(sp3C, !this->unk16C_0, 
            (arg1->id == 1) ? 1 
            : (player_getTransformation() == TRANSFORM_5_CROC) ? 2
            : 0
        );
    }
}

void func_8032B5C0(ActorMarker *arg0, ActorMarker *arg1, struct5Cs *arg2) {
    Actor *this;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    enum marker_collision_func_type_e sp64;
    s32 var_v0;
    f32 player_yaw;
    f32 sp50[3];
    s32 sp4C;
    NodeProp *sp48;
    s32 sp3C[3];
    f32 sp38;
    s32 pad;

    this = marker_getActor(arg0);
    sp70 = func_8033D5B4(arg2);
    sp6C = func_8033D584(arg2);
    sp68 = func_8033D5A4(arg2);
    sp64 = func_8033D574(arg2);
    if (((func_80297C6C() != 3) && func_8028F1E0()) || (func_8033D594(arg2) == 0)) {
        if (sp64 == 0) {
            if ((sp68 != 0) || (arg1->id == 0)) {
                if (sp68 <= 0) {
                    sp68 = 1;
                }
            } else{
                return;
            }
        }

        if (sp68 != 0) {
            var_v0 = MAX(0 , (this->unk164[sp64] - (100 / sp68)));
            if ((this->unk164[sp64] = var_v0) && (sp68 >= 2)) {
                sp6C /= 2;
            }
        }
        if (sp6C != 0) {
            bundle_setYaw(func_80257204(arg0->propPtr->x, arg0->propPtr->z, arg1->propPtr->x, arg1->propPtr->z) + 90.0f);
            D_8036E564 = sp6C;
            if (this->unk138_25) {
                __bundle_spawnFromFirstActor(sp6C + BUNDLE_21__ICECUBE_B, this);
            } else {
                if ((this->marker->id < 0x1A1) || (this->marker->id >= 0x1A5)) {
                    __bundle_spawnFromFirstActor(sp6C + BUNDLE_18__HONEYCOMB, this);
                }
            }
        }
        if (sp68 != 0) {
            if ((sp64 == 2) && this->unk16C_1) {
                func_8032B3A0(this, arg1);
            }
            if ((sp64 == 1) && this->unk16C_2) {
                func_8032B3A0(this, arg1);
            }

            if ((this->unk164[sp64] == 0) || ((sp64 != 0) && this->unk138_9)) {
                if (this->unk164[sp64] != 0) {
                    sp64 -= 1;
                }
                if (sp64 != 2) {
                    this->unk164[sp64] = 0x63;
                }
                if ((sp64 == 2) && (sp70 != 0)) {
                    player_yaw = player_getYaw();
                    sp3C[0] = (s32) this->position[0];
                    sp3C[1] = (s32) this->position[1];
                    sp3C[2] = (s32) this->position[2];
                    if ((s32)arg0->unk44 < 0) {
                        func_8034A174(arg0->unk44, 0x20, sp50);
                    }
                    func_8032EE0C(func_8032B38C, this);
                    if (((s32)arg0->unk44 < 0) && ((sp50[0] != 0.0f) || (sp50[1] != 0.0f) || (sp50[2] != 0.0f))) {
                        __spawnQueue_add_5((GenFunction_5)spawnQueue_bundleWithYaw_f32, sp70 + BUNDLE_15__JIGGY, reinterpret_cast(s32, sp50[0]), reinterpret_cast(s32, sp50[1]), reinterpret_cast(s32, sp50[2]), reinterpret_cast(s32, player_yaw));
                    } else if (this->unk16C_3 && func_803048E0(sp3C, &sp4C, &sp48, 3, (s32) (func_8033229C(arg0) * 4.0f))) {
                        sp50[0] = (f32) sp48->x;
                        sp50[1] = (f32) sp48->y;
                        sp50[2] = (f32) sp48->z;
                        __spawnQueue_add_5((GenFunction_5)spawnQueue_bundleWithYaw_f32, sp70 + BUNDLE_15__JIGGY, reinterpret_cast(s32, sp50[0]), reinterpret_cast(s32, sp50[1]), reinterpret_cast(s32, sp50[2]), reinterpret_cast(s32, player_yaw));
                    } else {
                        sp38 = this->position[1] + func_8033229C(arg0);
                        __spawnQueue_add_5((GenFunction_5)spawnQueue_bundleWithYaw_f32, sp70 + BUNDLE_15__JIGGY, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, sp38), reinterpret_cast(s32, this->position[2]), reinterpret_cast(s32, player_yaw));
                    }
                    func_8032EE20();
                }
                marker_callCollisionFunc(arg0, arg1, sp64);
            }
            if ((sp64 != 0) && (sp6C != 0)) {
                FUNC_8030E8B4(SFX_1D_HITTING_AN_ENEMY_1, 1.0f, 25984, this->position, (s32)((500.0f + func_8033229C(arg0)) * 0.5), (s32)((500.0f + func_8033229C(arg0)) * 5));
            }
        }
    }
}

void func_8032BB88(Actor *this, s32 arg1, s32 arg2){
    s32 sp1C;

    sp1C = this->unk138_7;
    func_8025A4C4(arg1, arg2, &sp1C);
    this->unk138_7 = sp1C;
}

bool func_8032BBE8(Actor *this){
    if(this->volatile_initialized){
        return TRUE;
    }
    this->volatile_initialized = TRUE;
    return FALSE;
}

void func_8032BC18(Actor *this){
    func_80287784(this->animctrl, 0);
}

void func_8032BC3C(Actor *this, f32 arg1){
    this->unk48 = arg1;
    func_80344040(this);
}

void func_8032BC60(Actor *this, s32 arg1, f32 arg2[3]){
    func_8034A174(this->marker->unk44, arg1, arg2);
}
