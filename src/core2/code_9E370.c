#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

#define DIST_SQ_VEC3F(v1, v2) ((v1[0] - v2[0])*(v1[0] - v2[0]) + (v1[1] - v2[1])*(v1[1] - v2[1]) + (v1[2] - v2[2])*(v1[2] - v2[2]))

extern f32  func_80258708(f32[3], f32[3]);
extern bool func_80259384(f32[3], f32[3], f32);
extern void func_802D7124(Actor *, f32);
extern void func_802EE6CC(f32[3], s32[4], s32[4], s32, f32, f32, s32, s32, s32);


extern void func_8033A244(f32);
extern void func_8033A410(s32);

f32 func_80257204(f32, f32, f32, f32);
extern Actor *func_802C4260(enum actor_id, s32 x, s32 y, s32 z, s32 yaw);
f32 func_8033229C(ActorMarker *);
f32 func_8028EBA4(void);
extern void func_8032FFF4(ActorMarker *, ActorMarker *, s32);
extern void func_802C9334(s32, Actor *);
extern void func_8032B3A0(Actor *, ActorMarker *);
extern void func_8032EE0C(GenMethod_2, s32);
extern void func_8032EE20(void);
extern void func_802C4014(GenMethod_5, s32, s32, s32, s32, s32);


void func_8032A6A8(Actor *arg0);
void func_8032ACA8(Actor *arg0);
void func_8032B5C0(ActorMarker *arg0, ActorMarker *arg1, struct5Cs *arg2);
void func_80328B8C(Actor * this, s32 arg1, f32 arg2, s32 arg3);
void func_8032BB88(Actor *this, s32 arg1, s32 arg2);
int  subaddie_playerIsWithinSphere(Actor *this, s32 dist);
extern void func_8033A4A0(enum asset_e mode_id, f32, f32);
extern void func_80338338(s32, s32, s32);
extern void func_803382FC(s32);
extern void func_803382E4(s32);
extern void func_8033687C(Gfx **);
extern void func_80335D30(Gfx **);
extern void func_80344138(s32, s32, s32, f32[3], f32[3], Gfx **, Mtx **);

typedef struct {
    f32 unk0[3];
    s16 unkC;
    s16 unkE;
}Actorlocal_Core2_9E370;

/* .data */
extern ActorArray *D_8036E560; //actorArrayPtr
extern s32 D_8036E564;
extern s32 D_8036E568;
extern s32 D_8036E56C;
extern void *D_8036E570;
extern  u8 D_8036E574;
extern  u8 D_8036E578;
extern  u8 D_8036E57C;
extern f32 D_8036E580;
extern f32 D_8036E58C[3];
extern f32 D_8036E598[6];
extern s32 D_8036E5B0[4];
extern s32 D_8036E5C0[4];


/* .rodata */
extern f32 D_80378E50;
extern f64 D_80378E58;
extern f64 D_80378E60;
extern f64 D_80378E68;

/* .bss */
Actor *D_80383390;
s32 D_80383394;
Actor *D_80383398[14]; //array of jiggy actor ptrs


//marker_getActorAndRotation
Actor * func_80325300(ActorMarker *marker,f32 rotation[3])
{   Actor *actor = &D_8036E560->data[marker->actrArrayIdx];
    rotation[0] = actor->pitch;
    rotation[1] = actor->yaw;
    rotation[2] = actor->roll;
    return actor;
}

Actor *func_80325340(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    BKModelBin * model_bin =  func_80330DE4(marker);
    if(model_bin && func_8033A12C(model_bin)){
        if(marker->collidable)
            func_80330B1C(marker);
    }
    return NULL;
}

void func_803253A0(Actor *this){
    s32 pad;
    BKModelBin *sp48;
    bool sp44;
    BKVertexList *sp40;
    f32 sp34[3];
    
    sp48 = func_80330B1C(this->marker);
    func_80330534(this);
    if(this->animctrl != NULL){
        func_8028781C(this->animctrl, this->position, 1);
    }

    if(this->marker->unk20 != NULL){
        sp44 = FALSE;
        if(this->unk148 != NULL){
            func_802EA1A8(&this->marker->unk20, func_8033A0D4(sp48), func_803356A0(this->unk148));
            sp44 = TRUE;
        }//L8032542C
        else if(this->animctrl != NULL && func_8033A0D4(sp48)){
            anim_802897D4(&this->marker->unk20, func_8033A0D4(sp48), animctrl_getAnimPtr(this->animctrl));
            sp44 = TRUE;
        }//L80325474

        if(sp44){
            func_8033A444(this->marker->unk20);
        }
    }//L8032548C

    if(this->alpha_124_19 < 0xFF){
        func_8033A410(this->alpha_124_19);
    }

    set_model_render_mode(this->unk124_9);
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
            func_80333D48(sp40, this->position, sp34, this->scale, 0, func_8033A148(sp48));
        }//L80325560
        func_8033A4C0(sp40);
        this->unkF4_29 = NOT(this->unkF4_29);
    }//L80325594

    if(this->unk130){
        this->unk130(this);
    }

    if(this->unk148 && !this->marker->unk20){
        func_8033A238(func_803356A0(this->unk148));
    }

    func_8033056C(this);
    func_8033A494(func_80330C48(this));
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

void func_80325794(ActorMarker *marker){
    marker->unk14_21 = TRUE;
}

void func_803257A4(ActorMarker *marker){
    marker->unk14_21 = TRUE;
}

bool func_803257B4(ActorMarker *marker) {
    Actor *actor;
    BKModelBin *model_bin;
    BKVertexList *vtx_list;

    actor = marker_getActor(marker);
    if ((actor->unk174 == 0.0f) || (actor->unk178 == 0.0f)) {
        model_bin = (BKModelBin *) assetcache_get(marker->modelId);
        vtx_list = (BKVertexList *)((s32)model_bin + model_bin->vtx_list_offset_10);
        actor->unk174 = (f32) vtx_list->unk12 * actor->scale;
        actor->unk178 = (f32) vtx_list->unk16 * actor->scale;
        assetcache_release(model_bin);
    }
    func_8033A4A0(marker->modelId, actor->unk174, actor->unk178);
    return FALSE;
}


Actor *func_80325888(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 sp3C[3];
    Actor *this;

    this = func_80325300(marker, sp3C);
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, marker);
    func_803391A4(gfx, mtx, this->position, sp3C, this->scale, (this->unk104 != NULL) ? &D_8036E580 : NULL, func_803257B4(marker));
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
    func_8024C764(rotation);
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

Actor *func_80325E78(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 rotation[3];
    Actor *this;

    this = func_80325300(marker, rotation);
    set_model_render_mode(1);
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, marker);
    func_803391A4(gfx, mtx, this->position, rotation, this->scale, (this->unk104 != NULL) ?  &D_8036E580 : NULL, func_803257B4(marker));
    return this;
}

Actor *func_80325F2C(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    func_8033A244(30000.0f);
    func_8033A280(2.0f);
    return func_80325E78(marker, gfx, mtx, vtx);
}

void func_80325F84(Actor *this){}

void func_80325F8C(void) {
    D_8036E560 = NULL;
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
    marker->unk14_20 = 0;
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
    if (marker->unk30 != NULL) {
       marker->unk30(this);
       marker->unk30 = NULL;
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
        func_80335874(this->unk148);
        this->unk148 = NULL;
    }
    if (marker->unk50 != 0) {
        func_80340690(marker->unk50);
        marker->unk50 = 0;
    }
    func_8032ACA8(this);
}

//actorArray_free()
void func_80326124(void) {
    Actor *var_s0;

    if (D_8036E560 != NULL) {
        for(var_s0 = D_8036E560->data; var_s0 < &D_8036E560->data[D_8036E560->cnt]; var_s0++){
            func_80325FE8(var_s0);
            if (var_s0->marker != NULL) {
                marker_free(var_s0->marker);
            }
            var_s0->marker = NULL;
        }
        free(D_8036E560);
        D_8036E560 = NULL;
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

void func_80326224(Actor *this){
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
    

    if (D_8036E560 != NULL) {
        sp54 = func_803203FC(101);
        for(temp_v1 = D_8036E560->cnt - 1; temp_v1 >= 0; temp_v1--){
            actor = &D_8036E560->data[temp_v1];
            actor_info = actor->actor_info;
            marker = actor->marker;
            anim_ctrl = actor->animctrl;
            temp_s1 = actor->actor_info->unk18;
            if (marker->propPtr->unk8_4) {
                if(sp54){
                    if (  actor->actor_info->unk20 && func_803203FC( actor->actor_info->unk20)) {
                        marker_despawn(marker);
                    }
                }
                if (!actor->despawn_flag) {
                    if (marker->unk2C_2) {
                        ((void (*)(Actor *)) marker->unk34)(actor);
                        if (anim_ctrl != NULL) {
                                actor->sound_timer = animctrl_getAnimTimer(anim_ctrl);
                        }
                    } else if (!temp_s1 || (temp_s1 && func_803296D8(actor, temp_s1))) {
                        if ( marker->unk24 != NULL) {
                             marker->unk24(actor);
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
                            func_80335A94(actor->unk148, time_getDelta(), marker->unk14_21);
                        } else {
                            func_80335924(actor->unk148, 0, 0.0f, 0.0f);
                        }
                    }
                    if ((actor_info->shadow_scale != 0.0f) && actor->unk124_6 && marker->unk14_21) {
                        func_802D7124(actor, actor_info->shadow_scale);
                    }
                    if (actor->unk10_0) {
                        actor = &D_8036E560->data[temp_v1];
                        func_802C96E4(actor);
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

Actor *func_80326C30(enum asset_e model_id) {
    Actor *actor_begin;
    Actor *i_actor;

    actor_begin = D_8036E560->data;
    for(i_actor = actor_begin; (i_actor - actor_begin) < D_8036E560->cnt; i_actor++){
        if ((model_id == i_actor->marker->modelId) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

Actor *func_80326CCC(s32 arg0) {
    Actor *actor_begin;
    Actor *i_actor;

    actor_begin = D_8036E560->data;
    for(i_actor = actor_begin; i_actor - actor_begin < D_8036E560->cnt; i_actor++) {
        if ((arg0 == i_actor->marker->unk14_20) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

/* 
 * find the closest actor to position with actor_id and not in state
 * returns Actor* and distance (last arg)
 */
Actor *func_80326D68(f32 position[3], enum actor_e actor_id, s32 arg2, f32 *min_distance_ptr) {
    Actor *begin;
    Actor *i_actor;
    f32 i_dist;
    f32 min_dist;
    s32 *closest_actor;

    if (D_8036E560 != NULL) {
        begin = D_8036E560->data;
        closest_actor = NULL;
        min_dist = D_80378E50;
        for(i_actor = begin; (i_actor - begin) < D_8036E560->cnt; i_actor++){
            if ( ((actor_id == i_actor->modelCacheIndex) || (actor_id < 0)) 
                 && (arg2 != i_actor->state) 
                 && (i_actor->modelCacheIndex != ACTOR_17_PLAYER_SHADOW) 
                 && (i_actor->modelCacheIndex != 0x108) 
                 && !i_actor->despawn_flag
            ) {
                i_dist = func_80258708(position, i_actor->position);
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

Actor *func_80326EEC(enum actor_e actor_id) {
    Actor *begin;
    Actor *end;
    Actor *i_actor;

    begin = D_8036E560->data;
    end = begin + D_8036E560->cnt;
    for(i_actor = begin; i_actor < end; i_actor++){
        if ((actor_id == i_actor->modelCacheIndex) && !i_actor->despawn_flag) {
            return i_actor;
        }
    }
    return NULL;
}

s32 func_80326F58(enum actor_e actor_id) {
    Actor *begin;
    Actor *end;
    Actor *i_actor;
    s32 var_v1;

    var_v1 = 0;
    begin = D_8036E560->data;
    end = begin + D_8036E560->cnt;
    for(i_actor = begin; i_actor < end; i_actor++){
        if ((actor_id == i_actor->modelCacheIndex) && !i_actor->despawn_flag) {
            var_v1 += 1;
        }
    }
    return var_v1;
}

Actor **func_80326FC0(void) {
    Actor *begin;
    Actor *i_actor;

    s32 var_a1;

    begin = D_8036E560->data;
    for(i_actor = begin, var_a1 = 0; (D_8036E560 != NULL) && ((i_actor - begin) < D_8036E560->cnt); i_actor++){
        if ((i_actor->modelCacheIndex == ACTOR_46_JIGGY) && !i_actor->despawn_flag) {
            D_80383398[var_a1] = i_actor;
            var_a1 += 1;
        }
    }
    D_80383398[var_a1] = NULL;
    return D_80383398;
}

bool func_803270B8(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *), ActorMarker * arg4){
    bool var_s4;
    Actor * start;
    Actor * i_ptr;

    var_s4 = FALSE;
    start = &D_8036E560->data[0];
    for(i_ptr = start; (D_8036E560 != NULL) && (i_ptr - start < D_8036E560->cnt); i_ptr++){
        if( !i_ptr->despawn_flag 
            && i_ptr->marker->collidable 
            && ((arg3 == NULL) || arg3(i_ptr)) 
            && func_80259384(i_ptr->position, arg0, arg1)
        ) {
            if (i_ptr->marker->unk58 == NULL || i_ptr->marker->unk58(i_ptr->marker, arg4)
            ) {
                var_s4 = TRUE;
                if (!func_8033D410(arg4, i_ptr->marker)) {
                    func_8032FFF4(i_ptr->marker, arg4, arg2);
                }
            }
        }
    }
    return var_s4;
}


void func_8032728C(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *)){
    func_803270B8(arg0, arg1, arg2, arg3, _player_getMarker());
}

void func_803272D0(f32 arg0[3], f32 arg1, s32 arg2, int (*arg3)(Actor *)){
    func_803270B8(arg0, arg1, arg2, arg3, NULL);
}

Actor *actor_new(s32 (* position)[3], s32 yaw, ActorInfo* actorInfo, u32 flags){
    ActorAnimationInfo * sp54;
    s32 i;
    f32 sp44[3];
    
    if(D_8036E560 == NULL){
        D_8036E560 = (ActorArray *)malloc(sizeof(ActorArray) + 20*sizeof(Actor));
        D_8036E560->cnt = 0;
        D_8036E560->max_cnt = 20;
    }
    //i = D_8036E560->cnt + 1;
    if(D_8036E560->cnt + 1 > D_8036E560->max_cnt){
        D_8036E560->max_cnt = D_8036E560->cnt + 5;
        D_8036E560 = (ActorArray *)realloc(D_8036E560, sizeof(ActorArray) + D_8036E560->max_cnt*sizeof(Actor));
    }
    ++D_8036E560->cnt;
    D_80383390 = &D_8036E560->data[D_8036E560->cnt - 1];
    D_80383390->actor_info = actorInfo;
    D_80383390->unk10_25 = 0;
    D_80383390->unk10_18 = 0;
    D_80383390->state = actorInfo->startAnimation;
    D_80383390->position_x = (f32)(*position)[0];
    D_80383390->position_y = (f32)(*position)[1];
    D_80383390->position_z = (f32)(*position)[2];
    D_80383390->unkF4_8 = 0;
    D_80383390->yaw = (f32) yaw;
    D_80383390->yaw_moving = (f32) yaw;
    D_80383390->pitch = 0.0f;
    D_80383390->roll = 0.0f;
    D_80383390->unk6C = 0.0f;
    D_80383390->unk28 = 0.0f;
    D_80383390->unk10_12 = 0;
    D_80383390->unk38_0 = 0;
    D_80383390->unk38_31 = 0;
    D_80383390->unk58_0 = 1;
    D_80383390->unk40 = 0;
    D_80383390->unk44_31 = 0;
    D_80383390->despawn_flag = 0;
    D_80383390->unk44_14 = -1;
    D_80383390->unk48 = 0.0f;
    D_80383390->unk4C = 100.0f;
    D_80383390->unk10_1 = 1;
    D_80383390->unkF4_30 = 0;
    D_80383390->unkF4_29 = 0;
    D_80383390->scale = 1.0f;
    D_80383390->unk124_7 = 0;
    D_80383390->unk124_6 = 1;
    D_80383390->modelCacheIndex = actorInfo->actorId;
    D_80383390->unk44_2 = func_80326C18();
    D_80383390->marker = func_8032F9DC(position, actorInfo->draw_func, (func_8033B64C(actorInfo->modelId) == 1) ? 0 : 1,  actorInfo->markerId, (flags & 0x400) ? 1 : 0);
    D_80383390->marker->unk3E_0 = 1;
    D_80383390->unk138_28 = 1;
    D_80383390->unk10_3 = -1;
    D_80383390->unk10_4 = 0;
    D_80383390->unk10_8 = 0;
    D_80383390->unk10_7 = 0;
    D_80383390->unk10_6 = 0;
    D_80383390->unk54 = 0.0f;
    D_80383390->unk58_31 = 0;
    D_80383390->unk5C = 0.0f;
    D_80383390->unkF4_31 = 0;
    D_80383390->unk138_30 = 0;
    D_80383390->unk138_3 = 0;
    D_80383390->unk38_21 = 0;
    D_80383390->unk38_13 = 0;
    D_80383390->unk78_22 = 0;
    D_80383390->unk78_31 = 0;
    D_80383390->unk74 = 0.0f;
    D_80383390->unk70 = 0.0f;
    D_80383390->unkF4_24 = 0;
    D_80383390->unk140 = 0.0f;
    D_80383390->unk144 = 0.0f;
    D_80383390->unk44_1 = 0;
    D_80383390->unk44_0 = 0;
    D_80383390->initialized = FALSE;
    D_80383390->unk16C_4 = 0;
    D_80383390->unk60 = 0.0f;
    D_80383390->unk10_0 = 0;
    D_80383390->unk104 = NULL;
    D_80383390->unk100 = NULL;
    D_80383390->unk158[0] = NULL;
    D_80383390->unk158[1] = NULL;
    D_80383390->unk78_13 = 0;
    D_80383390->unk124_31 = 0;
    D_80383390->unkF4_20 = 0;
    D_80383390->sound_timer = 0.0f;
    func_8032FFD4(D_80383390->marker, D_8036E560->cnt - 1);
    marker_setModelId(D_80383390->marker, actorInfo->modelId);
    func_803300C8(D_80383390->marker, actorInfo->update_func);
    func_803300D0(D_80383390->marker, actorInfo->unk10);
    ml_vec3f_clear(D_80383390->unk1C);
    ml_vec3f_clear(D_80383390->velocity);
    ml_vec3f_clear(D_80383390->spawn_position);
    D_80383390->stored_animctrl_index = 0;
    D_80383390->unk58_2 = 1;
    D_80383390->stored_animctrl_playbackType_ = 0;
    D_80383390->stored_animctrl_forwards = 0;
    D_80383390->stored_animctrl_smoothTransistion = 0;
    D_80383390->stored_animctrl_duration = 0.0f;
    D_80383390->unkEC = 0.0f;
    D_80383390->unk138_19 = 0;
    D_80383390->stored_animctrl_subrangeMin = 0.0f;
    D_80383390->stored_animctrl_subrangeMax = 1.0f;
    D_80383390->unkF4_22 = 0;
    D_80383390->unk58_1 = 0;
    D_80383390->unk138_29 = 0;
    D_80383390->unk18 = actorInfo->animations;
    D_80383390->animctrl = NULL;
    D_80383390->unkEC = 0.0f;
    D_80383390->unk130 = 0;
    D_80383390->unk124_5 = 0;
    D_80383390->unk124_3 = 0;
    D_80383390->unk138_9 = 0;
    D_80383390->unk138_8 = 0;
    D_80383390->unk138_25 = 0;
    D_80383390->unk16C_3 = 0;
    D_80383390->unk16C_2 = 0;
    D_80383390->unk16C_1 = 0;
    D_80383390->unk16C_0 = 0;
    D_80383390->unk17C_31 = 0;
    D_80383390->unk14C[0] = NULL;
    D_80383390->unk14C[1] = NULL;
    D_80383390->unk138_27 = 0;
    D_80383390->unk138_24 = 0;
    D_80383390->unk138_23 = 0;
    D_80383390->unk138_22 = 0;
    D_80383390->unk138_21 = 0;
    D_80383390->unk138_20 = 0;
    D_80383390->unk174 = 0.0f;
    D_80383390->unk178 = 0.0f;
    if( actorInfo->animations){
        sp54 = &D_80383390->unk18[D_80383390->state];
        if(sp54->index != 0){
            D_80383390->animctrl = animctrl_new(0);
            animctrl_reset(D_80383390->animctrl);
            animctrl_setIndex(D_80383390->animctrl, sp54->index);
            animctrl_setDuration(D_80383390->animctrl, sp54->duration);
            func_802875AC(D_80383390->animctrl, "subaddie.c", 0x4A5);
        }
    }//L80327BA8
    D_80383390->unk124_11 = 0;
    D_80383390->alpha_124_19 = 0xff;
    D_80383390->unk124_9 = 1;
    D_80383390->unk124_0 = D_80383390->unk138_31 = 1;
    for(i = 0; i < 0x10; i++){
        ((s32 *)D_80383390->unk7C)[i] = 0;
    }
    for(i = 0; i < 0x0C; i++){
        ((s32 *)D_80383390->unkBC)[i] = 0;
    }
    if(flags & 1){
        D_80383390->unk10_25 = func_80306DDC(position) + 1;
        if(D_80383390->unk10_25 == 0){
            D_80383390->unk10_25 = 0;
        }else{
            sp44[0] = (f32)(*position)[0];
            sp44[1] = (f32)(*position)[1];
            sp44[2] = (f32)(*position)[2];
            D_80383390->unk10_18 = func_80307258(&sp44, D_80383390->unk10_25 - 1, 0) + 1;
        }
    }//L80327D30

    if(flags & 4){
        D_80383390->unk10_1 = 0;
    }

    if(flags & 8){
        D_80383390->unkF4_30 = 1;
    }

    if(flags & 2){
        D_80383390->marker->unk44 = 1;
    }
    else if(flags & 0x40){
        D_80383390->marker->unk44 = func_8034A2C8();
    }

    if(flags & 0x1000){
        func_8033F738(D_80383390->marker);
        func_8034BFF8(D_80383390->marker);
    }

    D_80383390->unk148 = 0;
    if(flags & 0x800){
        D_80383390->unk148 = func_803358B4();
    }

    if(flags & 0x4000){
        D_80383390->marker->unk50 = func_803406B0();
    }

    if(flags & 0x10){
        D_80383390->unk124_31 = -1;
    }

    if(flags & 0x80){
        D_80383390->unkF4_22 = 1;
    }

    if(flags & 0x80000){
        D_80383390->unk58_1 = 1;
    }

    if(flags & 0x100){
        D_80383390->unk130 = func_803255FC;
    }

    if(flags & 0x200){
        D_80383390->marker->unk40_21 = 1;
    }

    if(flags & 0x8000){
        D_80383390->marker->unk40_20 = 1;
    }

    if(flags & 0x20000){
        D_80383390->marker->unk40_22 = 1;
    }

    if(flags & 0x400000){
        D_80383390->marker->unk40_19 = 1;
    }

    if(flags & 0x10000){
        D_80383390->unk138_9 = 1;
    }

    if(flags & 0x40000){
        D_80383390->unk138_8 = 1;
    }

    if(flags & 0x200000){
        D_80383390->unk138_25 = 1;
    }

    if(flags & 0x800000){
        D_80383390->unk16C_3 = 1;
    }

    if(flags & 0x1000000){
        D_80383390->unk16C_2 = 1;
    }

    if(flags & 0x2000000){
        D_80383390->unk16C_1 = 1;
    }

    if(flags & 0x4000000){
        D_80383390->unk17C_31 = 1;
    }

    if(flags & 0x2000){
        D_80383390->unk138_29 = 1;
    }

    if(flags & 0x100000){
        D_80383390->unk58_2 = 0;
    }

    D_80383390->unk154 = 0x005e0000;
    D_80383390->marker->unk54 = func_8032B5C0;

    
    for(i = 0; i < 3; ++i){
        D_80383390->unk164[i] = 0x63;
    }

    D_80383390->unk170 = -10.0f;
    D_80383390->unk138_7 = 0;
    D_80383390->unk3C = flags;
    return D_80383390;
}

static void __actor_free(ActorMarker *arg0, Actor *arg1){
    s32 arrayEnd;

    //copy last actor over actor to delete
    arrayEnd = &D_8036E560->data[D_8036E560->cnt - 1];
    func_80325FE8(arg1);
    if((s32)arg1 != arrayEnd)
        memcpy(arg1, arrayEnd, 0x180); //memcpy
    arg1->marker->actrArrayIdx = arg0->actrArrayIdx;

    //remove last actor from actor array
    D_8036E560->cnt--;

    //shrink actor array capacity
    if(D_8036E560->cnt + 8 <= D_8036E560->max_cnt){
        D_8036E560->max_cnt = D_8036E560->cnt + 4;
        D_8036E560 = (ActorArray *)realloc(D_8036E560, D_8036E560->max_cnt*sizeof(Actor) + sizeof(ActorArray));
    }

    marker_free(arg0);
}

Actor *func_8032811C(enum actor_e id, s32 (* pos)[3], s32 rot){
    return func_803056FC(id, pos, rot);
}

Actor *func_8032813C(enum actor_e id, f32 pos[3], s32 rot){
    s32 sp24[3];
    int i;
    for(i = 0; i< 3; i++){
        sp24[i] = pos[i];
    }
    func_803056FC(id, &sp24, rot);
}

Actor * spawn_child_actor(enum actor_e id, Actor ** parent){
    Actor *child;
    ActorMarker * sp28 =  (*parent)->marker;
    s32 sp1C[3];
    sp1C[0] = (*parent)->position_x;
    sp1C[1] = (*parent)->position_y;
    sp1C[2] = (*parent)->position_z;
    child = func_803056FC(id, sp1C, (*parent)->yaw);
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

Actor *func_803282AC(enum actor_e id, s16 (* pos)[3], s32 yaw){
    s32 sp24[3];
    int i;
    for(i = 0; i< 3; i++){
        sp24[i] = (*pos)[i];
    }
    return func_803056FC(id, &sp24, yaw);
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
            for(i = D_8036E560->cnt-1; i >= 0 ; i--){
                iPtr = &D_8036E560->data[i];
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
    ml_vec3f_yaw_rotate_copy(sp1C, sp1C, arg1 - D_80378E58);

    arg0[0] += sp1C[0]; 
    arg0[1] += sp1C[1]; 
    arg0[2] += sp1C[2]; 
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_80328508.s")
#else
bool func_80328508(Actor * arg0, u32 arg1){
    ActorAnimationInfo *animInfo;

    arg0->state = arg1;
    if(arg0->unk18 == NULL)
        return 0;

    animInfo = &arg0->unk18[arg1];

    if(animInfo->index != NULL){
        if(arg0->animctrl == NULL){
            arg0->animctrl = animctrl_new(0);
            animctrl_reset(arg0->animctrl);
        }
        animctrl_setIndex(arg0->animctrl, animInfo->index);
        animctrl_setDuration(arg0->animctrl, animInfo->duration);
        animctrl_setDirection(arg0->animctrl, mvmt_dir_forwards);
    }
    else {
        if(arg0->animctrl){
            animctrl_setPlaybackType(arg0->animctrl,  ANIMCTRL_STOPPED);
            animctrl_setDirection(arg0->animctrl, mvmt_dir_forwards);
        }
    }
    return 1;

}
#endif

void func_803285E8(Actor *this, f32 arg1, int direction){
    func_8028774C(this->animctrl, arg1);
    if(direction != -1){
        animctrl_setDirection(this->animctrl, direction);
    }
    this->sound_timer = arg1;
}



int func_8032863C(AnimCtrl *anim_ctrl, f32 min, f32 max) {
    f32 timer;
    s32 sp18;

    timer = animctrl_getAnimTimer(anim_ctrl);
    if ((timer < min) || (max <= timer)) {
        return -1;
    }
    sp18 = animctrl_isPlayedForwards(anim_ctrl);
    if( ((sp18 == 0) && (min <= timer) && (timer < (min + D_80378E60))) 
        || ((sp18 == 1) && (timer < max) && ((max - D_80378E68) <= timer))
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

void func_803289EC(Actor *this , f32 arg1, int direction){
    func_803285E8(this, arg1, direction);
    func_802875AC(this->animctrl, "subaddie.c", 0x6b1);
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

void func_80328A84(Actor * arg0, u32 arg1){
    if(func_80328508(arg0, arg1) && arg0->animctrl){
        func_802875AC(arg0->animctrl, "subaddie.c", 0X6CA);
    }
}

void func_80328AC8(Actor * arg0, s32 arg1){
    func_80328B8C(arg0, arg1, 0.0f, 1);
}

void func_80328AEC(Actor * arg0, u32 arg1){
    if(func_80328508(arg0, arg1) && arg0->animctrl){
        animctrl_setPlaybackType(arg0->animctrl,  ANIMCTRL_LOOP);
        func_803289EC(arg0, 0.0f, 1);
    }
}

/* actor - maybe plays actor's animation with set probability */
int func_80328B38(Actor *this, s32 myAnimId, f32 chance){
    if(randf() < chance){
        func_80328A84(this, myAnimId);
        return 1;
    }
    return 0;
}

void func_80328B8C(Actor * this, s32 myAnimId, f32 arg2, s32 direction){
    if(func_80328508(this, myAnimId) && this->animctrl)
        func_803289EC(this, arg2, direction);
}

int func_80328BD4(Actor * this, s32 myAnimId, f32 arg2, s32 arg3, f32 arg4){
    if(randf() < arg4){
        if(func_80328508(this, myAnimId) && this->animctrl){
            func_803285E8(this, arg2, arg3);
            func_802875AC(this->animctrl, "subaddie.c", 0x705);
        }
        return 1;
    }
    return 0;
}

void func_80328C64(Actor * this, int arg1){
    int retVal = arg1;
    while(retVal < 0) retVal += 0x168;
    while(retVal >= 0x168) retVal -= 0x168;
    this->yaw_moving = retVal;
}

void func_80328CA8(Actor *arg0, s32 angle) {
    s32 fixedAngle = angle;
    while (fixedAngle < 0) {
        fixedAngle += 360;
    }
    while (fixedAngle >= 360) {
        fixedAngle -= 360;
    }
    arg0->unk6C = fixedAngle;
}

void func_80328CEC(Actor * this, s32 arg1, s32 min, s32 max){
    f32 f12;
    int abs;
    f12 = (randf() - 0.5)*(max - min)*2;
    abs = (0.0f <= f12) ? min : -min;
    func_80328C64(this, abs + (arg1 + f12));
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

    if ((this->marker->unk14_20 != 0x12) && (this->marker->unk2C_2 == 1) && ((var_f2 >= 50.0f) || (var_f2 < -50.0f))) {
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
    this->yaw = func_80328DCC(this, this->yaw, this->yaw_moving, (s32)arg1);
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

    v1 = this->yaw - this->yaw_moving;
    return ((-3 <= v1) && (v1 <= 3));
}

bool func_803294B4(Actor *this, s32 arg1){
    s32 v1;

    v1 = this->yaw - this->yaw_moving;
    return ((-arg1 <= v1) && (v1 <= arg1));
}

bool func_803294F0(Actor *this, s32 arg1, s32 arg2){
    s32 v1;

    v1 = this->yaw - arg2;
    return ((-arg1 <= v1) && (v1 <= arg1));
}

bool func_80329530(Actor *this, s32 dist){
    if( func_8028F098() 
        && !func_803203FC(0xBF) 
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
    f32 sp18[3];

    func_8028E964(sp24);
    _player_getPosition(sp18);
    sp24[1] = sp18[1];
    return (s32) DIST_SQ_VEC3F(this->position, sp24);
}

s32 func_80329784(Actor *arg0){
    f32 sp1C[3];

    func_8028E964(sp1C);
    return (s32)func_80257204(arg0->position[0], arg0->position[2], sp1C[0], sp1C[2]);
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
    arg0->unk28 -= arg1;
    if(arg0->unk28 < 0.0f){
        arg0->unk28 = 0.0f;
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
    return &(D_8036E560->data[this->actrArrayIdx]);
}

Actor *subaddie_getLinkedActor(Actor *this){
    if(this->unk100 == NULL)
        return NULL;
    return marker_getActor(this->unk100);
}

void func_803299B4(Actor *arg0) {
    s32 position[3];
    s32 rotation[3];

    arg0->marker->unkC = arg0->unk108;
    arg0->marker->unk10 = arg0->unk10C;
    arg0->marker->unk1C = arg0->unk134;
    arg0->marker->unk54 = arg0->unk160;
    arg0->marker->unk58 = arg0->unk168;
    arg0->marker->unk30 = arg0->unk13C;
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
    func_8028774C(this->animctrl, this->unkEC);
    animctrl_setSubRange(this->animctrl, this->stored_animctrl_subrangeMin, this->stored_animctrl_subrangeMax);
    func_802875AC(this->animctrl, "subaddie.c", 0x8fd);
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
   
    if(D_8036E560){
        sp30 = 0;
        for(s1 = D_8036E560->data; s1 < &D_8036E560->data[(u32) D_8036E560->cnt]; s1++){
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
        for(s1 = D_8036E560->data; s1 < &D_8036E560->data[(u32) D_8036E560->cnt]; s1++){
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
                s0->unk16C_4 = 0;
                s0->unk44_31 = 0;
                s0->unk104 = NULL;
                s0->unk100 = NULL;
                s0->unk158[0] = NULL;
                s0->unk158[1] = NULL;
                s0->unk138_19 = s1->marker->unk14_20;
                s0->unk108 = s1->marker->unkC;
                s0->unk10C = s1->marker->unk10;
                s0->unk134 = s1->marker->unk1C;
                s0->unk160 = s1->marker->unk54;
                s0->unk168 = s1->marker->unk58;
                s0->unk13C = s1->marker->unk30;
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
                    s0->unkEC = animctrl_getAnimTimer(s0->animctrl);
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

typedef struct {
    u32 cnt;
    Actor *actor_save_state[];
}ActorListSaveState;

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032A09C.s")
#else
void func_8032A09C(s32 arg0, s32 arg1) {
    ActorListSaveState *var_s1 = (s32)arg1;
    Actor *var_s0;
    u32 var_s2;
    u32 var_s3;
    s32 temp_a0;
    Actor **sp60;
    Actor **sp5C;
    s32 sp50[3];
    Actor *temp_v0_6;


    func_802C3BE8();
    if (D_8036E560 != NULL) {
        func_803283BC();
        var_s3 = 0;
        var_s0 = var_s1->actor_save_state;
        for(var_s2 = var_s1->cnt; var_s2 != 0; var_s2--) {
            if ((var_s0->unk78_13 != 0) && (var_s3 < var_s0->unk78_13)) {
                var_s3 = var_s0->unk78_13;
            }
            var_s0++;
        }
        for(var_s0 = &D_8036E560->data[0]; var_s0 < &D_8036E560->data[D_8036E560->cnt]; var_s0++){
            if ((var_s0->unk78_13 != 0) && (var_s3 < var_s0->unk78_13)) {
                var_s3 = var_s0->unk78_13;
            }
        }

        var_s3++;
        sp60 = malloc(var_s3*sizeof(Actor *));
        sp5C = malloc(var_s3*sizeof(Actor *));
        for (var_s2 = 0; var_s2 < var_s3; var_s2++) {
                    sp60[var_s2] = 0;
                    sp5C[var_s2] = 0;
        }
        var_s0 = var_s1->actor_save_state;
        for(var_s2 = var_s1->cnt; var_s2 != 0; var_s2--) {
            if (var_s0->unk78_13 != 0) {
                sp5C[var_s0->unk78_13] = var_s0;
            }
            var_s0++;
        }
        for(var_s0 = &D_8036E560->data[0]; var_s0 < &D_8036E560->data[D_8036E560->cnt]; var_s0++){
            if ((var_s0->unk78_13 != 0)) {
                sp60[var_s0->unk78_13] = var_s0;
            }
            var_s0++;
        }

        for(var_s2 = 1; var_s2 < var_s3; var_s2++){
            if ((sp60[var_s2] != NULL) && (sp5C[var_s2] != NULL) && !sp5C[var_s2]->unkF4_22) {
                actor_copy(sp5C[var_s2], sp60[var_s2]);
                func_80329B68(sp60[var_s2]);
                func_803299B4(sp60[var_s2]);
            }
        }
        for(var_s2 = 1; var_s2 < var_s3; var_s2++){
            if ((sp60[var_s2] != NULL) && !sp60[var_s2]->unk58_1 && (sp5C[var_s2] == NULL)) {
                marker_despawn(sp60[var_s2]->marker);
                sp60[var_s2] = NULL;
            }
        }

        var_s0 = var_s1->actor_save_state;
        for(var_s2 = var_s1->cnt; var_s2 != 0; var_s2--){
            if (var_s0->unk78_13 == 0) {
                sp50[0] = (s32) var_s0->position[0];
                sp50[1] = (s32) var_s0->position[1];
                sp50[2] = (s32) var_s0->position[2];
                temp_v0_6 = func_8032811C(var_s0->modelCacheIndex, sp50, (s32) var_s0->yaw);
                actor_copy(var_s0, temp_v0_6);
                func_80329B68(temp_v0_6);
                func_803299B4(temp_v0_6);
                if(temp_v0_6);
            }
            var_s0++;
        }
        func_803283D4();
        free(sp60);
        free(sp5C);
    }
    func_802C3BDC();
}
#endif

void func_8032A5F8(void) {
    Actor *var_s0;

    if (D_8036E560 != NULL) {
        for(var_s0 = &D_8036E560->data[0]; var_s0 < &D_8036E560->data[D_8036E560->cnt]; var_s0++){
            if (var_s0->unk124_31 == 0xfff) {
                var_s0->unk124_31 = 0;
                func_8032A6A8(var_s0);
            }
        }
    }
}

void func_8032A6A8(Actor *arg0) {
    f32 var_f0;
    f32 var_f2;
    Actor *var_v0;


    if (arg0->unk44_14 != -1) {
        var_f0 = 1.0f;
        for(var_v0 = &D_8036E560->data[0]; var_v0 < &D_8036E560->data[D_8036E560->cnt]; var_v0++){
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

Actor *func_8032A7AC(Actor *arg0) {
    Actor *var_a0;

    if (arg0->unk124_31 != 0) {
        if (D_8036E560 != NULL) {
            for(var_a0 = &D_8036E560->data[0]; var_a0 < &D_8036E560->data[D_8036E560->cnt]; var_a0++){
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
    sp24 = func_80304C38(arg1, arg0);
    if (sp24 != NULL) {
        sp1C->unkC = func_80304DA8(sp24);
        nodeprop_getPosition(sp24, sp1C->unk0);
        sp1C->unkE = func_80341EC4(sp1C);
    }
}

void func_8032A88C(Actor *arg0) {
    Actorlocal_Core2_9E370 *sp20;

    sp20 = &arg0->local;
    arg0->yaw_moving = (f32) func_803297C8(arg0, sp20->unk0);
    func_80328FB0(arg0, 6.0f);
    func_80329030(arg0, 0);
    if ((((arg0->position[0] - sp20->unk0[0]) * (arg0->position[0] - sp20->unk0[0])) + ((arg0->position[2] - sp20->unk0[2]) * (arg0->position[2] - sp20->unk0[2]))) <= 144.0f) {
        arg0->unk44_14 = sp20->unkE;
        arg0->unk48 = 0.0f;
        arg0->marker->unk2C_2 = TRUE;
    }
}

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

    func_8028EB3C(sp1C);
    return ((arg0 - sp1C[0])*(arg0 - sp1C[0]) + (arg1 - sp1C[2])*(arg1 - sp1C[2])) < (arg2 * arg2);
}

//actor_setScale
void func_8032AA58(Actor *this, f32 arg1){
    this->scale = arg1;
    this->marker->unk14_10 = 0;
}

void actor_collisionOff(Actor* this){
    this->marker->collidable = 0;
}

void actor_collisionOn(Actor* this){
    this->marker->collidable = 1;
}

void func_8032AA9C(void){
    func_802C3BDC();
}

void func_8032AABC(void){
    Actor *i_ptr;
    Actor *start = &D_8036E560->data[0];
    u32 i;
    u32 cnt;
    
    func_802C3BE8();


    if(D_8036E560 != NULL){    
        cnt =  D_8036E560->cnt;
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
                        arg0->unk14C[0] = vtxList_clone(func_8033A148(func_80330DE4(marker)));
                        break;
                    case 1:
                        arg0->unk14C[1] = (arg0->unk17C_31) ? func_8033A148(func_80330DE4(marker))
                                        : vtxList_clone(func_8033A148(func_80330DE4(marker)));
                        break;
                }
            }
        }
    }

    if (marker->unk20 == NULL && arg0->unk3C & 0x20) {
        marker->unk20 = func_802EA154();
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
        func_802EA134(sp30->unk20);
        sp30->unk20 = 0;
    }
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AD7C.s")
#else
extern s32 D_8036E5A8;
void func_8032AD7C(s32 arg0) {
    s32 var_s0;
    

    if (D_8036E560 != NULL) {
        if (D_8036E5A8 >= D_8036E560->cnt) {
            D_8036E5A8 = 0;
        }
        for(var_s0 = 0; var_s0 < (arg0 == 1) ? 0xF : D_8036E560->cnt; var_s0++){
            if (func_80330E28(&D_8036E560->data[D_8036E5A8]) == NULL) {
                func_8032ACA8(&D_8036E560->data[D_8036E5A8]);
            }
            D_8036E5A8++;
            D_8036E5A8 %= D_8036E560->cnt;
        }
    }
}
#endif

void func_8032AEB4(void) {
    Actor *temp_s2;
    Actor *var_s0;

    temp_s2 = &D_8036E560->data[0];
    for(var_s0 = temp_s2; (D_8036E560 != NULL) && ((var_s0 - temp_s2) != D_8036E560->cnt); var_s0++){
        func_8032ACA8(var_s0);
    }
}


#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_9E370/func_8032AF94.s")
#else
extern s32 D_8036E5AC;
void func_8032AF94(void) {
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
    Actor *temp_s0;
    void *temp_s0_2;

    if (D_8036E560 != NULL) {
        for(var_s1 = 0; var_s1 < 8; var_s1++){
            D_8036E5AC++;
            if (D_8036E5AC >= D_8036E560->cnt) {
                D_8036E5AC = 0;
            }
            temp_s0 = &D_8036E560->data[D_8036E5AC];

            if ((s32)temp_s0->marker->unk44 < 0) {
                temp_s0->marker->unk44 = func_8034A348(temp_s0->marker->unk44);
            }

            if (temp_s0->unk158[0] != NULL) {
                temp_s0->unk158[0] = func_802F0D74(temp_s0->unk158[0]);
            }

            if (temp_s0->unk158[1] != NULL) {
                temp_s0->unk158[1] = func_802F0D74(temp_s0->unk158[1]);
            }

            if (temp_s0->animctrl != NULL) {
                temp_s0->animctrl = animctrl_defrag(temp_s0->animctrl);
            }

            if (temp_s0->marker->unk20 != NULL) {
                temp_s0->marker->unk20 = func_802EA374(temp_s0->marker->unk20);
            }

            if (temp_s0->unk148 != NULL) {
                temp_s0->unk148 = (Struct80s*)defrag(temp_s0->unk148);
            }

            if (temp_s0->marker->unk50 != NULL) {
                temp_s0->marker->unk50 = func_803406D4(temp_s0->marker->unk50);
            }

            if (temp_s0->marker->unk14_20 == 0x217) {
                func_802CEB60(temp_s0);
            }
        }
        D_8036E560 = (ActorArray *) defrag(D_8036E560);
    }

    if (D_8036E568 != 0) {
        D_8036E568 = func_8034A348(D_8036E568);
    }

    if (D_8036E570 != 0) {
        D_8036E570 = func_802F3364(D_8036E570);
    }
}
#endif

ActorMarker *func_8032B16C(enum jiggy_e jiggy_id) {
    Actor *temp_s3;
    Actor *var_s0;

    if (D_8036E560 != NULL) {
        temp_s3 = &D_8036E560->data[0];
        for(var_s0 = temp_s3; (var_s0 - temp_s3) < D_8036E560->cnt; var_s0++){
            if ((var_s0->marker->unk14_20 == MARKER_52_JIGGY) && (func_802C8088(&(var_s0->marker)) == jiggy_id)) {
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
        sp44 = func_8028EBA4();
        if ((s32)this->marker->unk44 < 0) {
            func_8034A174( this->marker->unk44, 0x20, sp38);
        }
        if (((s32)this->marker->unk44 < 0) && ((sp38[0] != 0.0f) || (sp38[1] != 0.0f) || (sp38[2] != 0.0f))) {
            func_802C4014((GenMethod_5)func_802C4260, this->unk138_27 + 0x15, reinterpret_cast(s32,sp38[0]), reinterpret_cast(s32,sp38[1]), reinterpret_cast(s32,sp38[2]), reinterpret_cast(s32,sp44));
            return;
        }
        else{
            sp34 = this->position[1] + 50.0f;
            func_802C4014((GenMethod_5)func_802C4260, this->unk138_27 + 0x15, reinterpret_cast(s32,this->position[0]), reinterpret_cast(s32,sp34), reinterpret_cast(s32,this->position[2]), reinterpret_cast(s32,sp44));
        }
    }
}

bool func_8032B38C(NodeProp *node, s32 arg1){
    return node->unk8 == 0xF7;
}

void func_8032B3A0(Actor *this, ActorMarker *arg1) {
    f32 sp54[3];

    if (arg1 != NULL) {
        sp54[0] = this->position[0];
        sp54[1] = this->position[1] + func_8033229C(this->marker)*((this->unk16C_0) ? 0.5 : 1.0);
        sp54[2] = this->position[2];
        func_802EE6CC(sp54, 0, D_8036E5B0, !this->unk16C_0, 0.75f, 0.0f, 125, 250, 0);
        func_802F3CF8(sp54, !this->unk16C_0, 
            (arg1->unk14_20 == 1) ? 1 
            : (player_getTransformation() == TRANSFORM_5_CROC) ? 2
            : 0
        );
    }
}


void func_8032B4DC(Actor *this, ActorMarker *arg1, s32 arg2) {
    f32 sp3C[3];

    if (arg1 != NULL) {
        func_8034A174(this->marker->unk44, arg2, &sp3C);
        func_802EE6CC(sp3C, NULL, D_8036E5C0, !this->unk16C_0, 0.75f, 0.0f, 125, 250, 0);
        func_802F3CF8(sp3C, !this->unk16C_0, 
            (arg1->unk14_20 == 1) ? 1 
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
    s32 sp64;
    s32 var_v0;
    f32 sp5C;
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
            if ((sp68 != 0) || (arg1->unk14_20 == 0)) {
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
            func_802C8F70(func_80257204(arg0->propPtr->x, arg0->propPtr->z, arg1->propPtr->x, arg1->propPtr->z) + 90.0f);
            D_8036E564 = sp6C;
            if (this->unk138_25) {
                func_802C9334(sp6C + 0x21, this);
            } else {
                if ((this->marker->unk14_20 < 0x1A1) || (this->marker->unk14_20 >= 0x1A5)) {
                    func_802C9334(sp6C + 0x18, this);
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
                    sp5C = func_8028EBA4();
                    sp3C[0] = (s32) this->position[0];
                    sp3C[1] = (s32) this->position[1];
                    sp3C[2] = (s32) this->position[2];
                    if ((s32)arg0->unk44 < 0) {
                        func_8034A174(arg0->unk44, 0x20, sp50);
                    }
                    func_8032EE0C(func_8032B38C, this);
                    if (((s32)arg0->unk44 < 0) && ((sp50[0] != 0.0f) || (sp50[1] != 0.0f) || (sp50[2] != 0.0f))) {
                        func_802C4014(func_802C4260, sp70 + 0x15, reinterpret_cast(s32, sp50[0]), reinterpret_cast(s32, sp50[1]), reinterpret_cast(s32, sp50[2]), reinterpret_cast(s32, sp5C));
                    } else if (this->unk16C_3 && func_803048E0(sp3C, &sp4C, &sp48, 3, (s32) (func_8033229C(arg0) * 4.0f))) {
                        sp50[0] = (f32) sp48->x;
                        sp50[1] = (f32) sp48->y;
                        sp50[2] = (f32) sp48->z;
                        func_802C4014(func_802C4260, sp70 + 0x15, reinterpret_cast(s32, sp50[0]), reinterpret_cast(s32, sp50[1]), reinterpret_cast(s32, sp50[2]), reinterpret_cast(s32, sp5C));
                    } else {
                        sp38 = this->position[1] + func_8033229C(arg0);
                        func_802C4014(func_802C4260, sp70 + 0x15, reinterpret_cast(s32, this->position[0]), reinterpret_cast(s32, sp38), reinterpret_cast(s32, this->position[2]), reinterpret_cast(s32, sp5C));
                    }
                    func_8032EE20();
                }
                func_8032FFF4(arg0, arg1, sp64);
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
    if(this->unk16C_4){
        return TRUE;
    }
    this->unk16C_4 = TRUE;
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
