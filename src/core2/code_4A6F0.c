#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80256E24(f32 [3], f32, f32, f32, f32, f32);
extern void func_802EE6CC(f32[3], f32[3], s32[4], s32, f32, f32, s32, s32, s32);
extern void func_803255FC(Actor *);
extern void func_80325760(Actor *);


Actor *chMumbo_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chMumbo_update(Actor *this);

/* .data */
ActorAnimationInfo D_80367490[] = {
    {0, 0.0f}, 
    {0x6A, 2.6f},
    {0x6B, 1.33f}, 
    {0x6C, 6.67f},
    {0x6C, 6.67f}, 
    {0x6D, 7.5f},
    {0x6E, 0.67f}, 
    {0x16E, 8.0f},
    {0x17F, 2.0f}, 
    {0x180, 0.7f},
};

ActorInfo D_803674E0 = { 
    0x6, 0x7, 0x3C6, 
    0x1, D_80367490, 
    chMumbo_update, func_80326224, chMumbo_draw, 
    0, 0, 0.0f, 0
};
s32 D_80367504[3] = {0.0f, 0.0f, 0.0f};
f32 D_80367510[3] = {1.0f, 0.0f, 2.0f};
s32 D_8036751C[4] = {100, 100, 30, 100};

/* .bss */
u8 D_8037DDF0;
u8 D_8037DDF1;
u8 D_8037DDF2;
u8 D_8037DDF3;

/* .code */
static bool __chMumbo_actorExists(enum actor_e actorId) {
    f32 var[3];

    if (nodeProp_findPositionFromActorId(actorId, var) != 0) {
        return TRUE;
    }
    return FALSE;
}

enum transformation_e func_802D16AC(void) {
    s32 ret = TRANSFORM_2_TERMITE;

    __chMumbo_actorExists(0x1F);
    if (__chMumbo_actorExists(0x20)) {
        ret = TRANSFORM_3_PUMPKIN;
    }
    if (__chMumbo_actorExists(0x21)) {
        ret = TRANSFORM_5_CROC;
    }
    if (__chMumbo_actorExists(0x22)) {
        ret = TRANSFORM_4_WALRUS;
    }
    if (__chMumbo_actorExists(0x23)) {
        ret = TRANSFORM_6_BEE;
    }
    return ret;
}

void chmumbo_func_802D1724(void){
    D_8037DDF0 = func_802D16AC();
}

static s32 __transformation_getCost(enum transformation_e trans_id){
    switch(trans_id){
        case TRANSFORM_2_TERMITE:
            return 5;
        case TRANSFORM_5_CROC:
            return 10;
        case TRANSFORM_4_WALRUS:
            return 15;
        case TRANSFORM_3_PUMPKIN:
            return 20;
        case TRANSFORM_6_BEE:
            return 25;
    }
    return 0;
}


static enum bkprog_e __bkProgId_from_transformationId(enum transformation_e trans_id){
    return (trans_id - TRANSFORM_2_TERMITE) + BKPROG_90_PAID_TERMITE_COST;
}

bool chMumbo_withinHorzDistToPlayer(s32 x, s32 z, s32 dist) {
    s32 player_position[3];

    player_getPosition_s32(player_position);
    return (x - player_position[0]) * (x - player_position[0]) + (z - player_position[2]) * (z - player_position[2]) < dist * dist;
}


bool chMumbo_func_802D181C(s32 arg0) {
    s32 search_start_cube[3] = D_80367504;
    return (cubeList_findNodePropByActorId(arg0, search_start_cube))? TRUE : FALSE;
}

void chMumbo_func_802D186C(Actor *this) {
    if (this->unk44_31 == 0) {
        this->unk44_31 = func_8030ED2C(SFX_5F_MUMBO_BUGABUGOW_MUFFLED, 3);
        sfxsource_setSampleRate(this->unk44_31, 0x7FFF);
    }
}

void chMumbo_func_802D18B4(Actor *this) {
    bool player_is_within_range;

    if (map_get() == MAP_7A_GL_CRYPT) {
        player_is_within_range = chMumbo_withinHorzDistToPlayer(1107, 0, 188);
    } else {
        player_is_within_range = chMumbo_withinHorzDistToPlayer(0, -107, 188);
    }
    if(player_is_within_range || func_803203FC(1) || func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)){
        func_80328AC8(this, 2);
        if( !func_8031FF1C(BKPROG_11_HAS_MET_MUMBO)
            || (!func_8031FF1C(BKPROG_DC_HAS_HAD_ENOUGH_TOKENS_BEFORE) && this->unk38_0)
        ) {
            func_8028F918(2);
        }
    }
}

void chMumbo_func_802D1970(Actor *this){
    actor_loopAnimation(this);
    chMumbo_func_802D18B4(this);
}

static void __chMumbo_textCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this;

    this = marker_getActor(caller);
    switch(text_id){
        case 0xD8F: //L802D1A04
            func_80311480((this->unk38_0) ? 0xDAA : 0xDAB, 0xe, this->position, this->marker, __chMumbo_textCallback, NULL);
            return;

        case 0xd90: //L802D1A40
            func_80320004(BKPROG_12_HAS_TRANSFORMED_BEFORE, TRUE);
            func_80311480(0xD8F + D_8037DDF0, 4, NULL, NULL, NULL, NULL);
            gcpausemenu_80314AC8(1);
            break;
            
        case 0xdaa: //L802D1A7C /* fall-through */
            func_80320004(BKPROG_DC_HAS_HAD_ENOUGH_TOKENS_BEFORE, TRUE);
        case 0xdab: //L802D1A88
            func_8028F918(0);
            break;

        case 0xdaf: //L802D1A98
            this->unk138_24 = FALSE;
            if(this->unk38_31 != 0){
                func_8025A6EC(COMUSIC_2B_DING_B, 28000);
                func_803463D4(ITEM_1C_MUMBO_TOKEN, -this->unk38_31);
                this->unk38_31 = 0;
            }
            func_80328B8C(this, 5, 0.0f, 1);
            return;

        case 0xdb0: //L802D1AF8
        case 0xdb1: //L802D1AF8
        case 0xdb2: //L802D1AF8
            D_8037DDF0 = this->unk10_12;
            this->unk10_12 = 1;
            if(this->unk38_31){
                func_8025A6EC(COMUSIC_2B_DING_B, 28000);
                func_803463D4(ITEM_1C_MUMBO_TOKEN, -this->unk38_31);
            }
            
        case 0xdae: //L802D1B48
            func_80328B8C(this, 5, 0.0f, 1);
            return;

        default: //L802D1B64
            gcpausemenu_80314AC8(1);
            break;
    }
    func_80328A84(this, 4);
}

void chMumbo_func_802D1B8C(Actor *this, enum transformation_e transform_id) {
    if (this->unk10_12 != 0) {
        func_80311480(func_8031FF44(BK_PROG_BB_MUMBO_MISTAKE_INDEX, 2) + 0xDAF, 0xE, this->position, this->marker, __chMumbo_textCallback, NULL);
        return;
    }
    if (func_8031FF1C(BKPROG_12_HAS_TRANSFORMED_BEFORE)) {
        if (this->velocity[0] == 0.0f) {
            func_80311480(transform_id + 0xD8F, 6, this->position, this->marker, __chMumbo_textCallback, NULL);
            return;
        }
        if (map_get() == MAP_7A_GL_CRYPT && transform_id == TRANSFORM_3_PUMPKIN && !func_8031FF1C(BKPROG_F7_HAS_TRANSFORMED_IN_CRYPT)) {
            func_80311480(0xDAD, 6, this->position, this->marker, __chMumbo_textCallback, NULL);
            func_80320004(BKPROG_F7_HAS_TRANSFORMED_IN_CRYPT, TRUE);
            return;
        }
        gcpausemenu_80314AC8(1);
        func_80328A84(this, 4U);
        return;
    }
    func_80311480(0xD90, 0xE, this->position, this->marker, __chMumbo_textCallback, NULL);
}

void chMumbo_update(Actor *this) {
    s32 face_buttons[6];
    f32 sp4C[3];
    bool sp48;
    bool sp44;
    s32 sp40;
    f32 temp_f12;

    this->unk130 = func_803255FC;
    if( !func_803203FC(1)
        && !func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)
        && map_get() != MAP_7A_GL_CRYPT) {
        func_803463D4(ITEM_1C_MUMBO_TOKEN, 0);
    }
    if(!this->initialized){
        this->initialized = TRUE;
        this->marker->propPtr->unk8_3 = FALSE;
        this->unk60 = 0.0f;
        if (chMumbo_func_802D181C(0x201)) {
            this->unk60 = 1.0f;
            func_80328A84(this, 7U);
        } else if (chMumbo_func_802D181C(0x202)) {
            this->unk60 = 2.0f;
            func_80328A84(this, 8U);
        }
    }

    if(!this->unk16C_4){
        this->unk38_31 = 0;
        if( player_getTransformation() == TRANSFORM_1_BANJO 
            && !func_8031FF1C(__bkProgId_from_transformationId(D_8037DDF0)) 
            && (map_get() != MAP_7A_GL_CRYPT)
        ){
            this->unk38_31 = __transformation_getCost(D_8037DDF0);
        }
        this->unk38_0 = (item_getCount(ITEM_1C_MUMBO_TOKEN) >= this->unk38_31);
        this->unk10_12 = 0;
        this->unk138_24 = 0;
        this->unk16C_4 = TRUE;
    }

    func_80256E24(sp4C, 0.0f, this->yaw, 0.0f, 0.0f, 10.0f);
    sp4C[0] += this->position[0];
    sp4C[1] += this->position[1];
    sp4C[2] += this->position[2];
    func_8028E668(sp4C, 220.0f, -20.0f, 110.0f);
    switch(this->state){
        case 1: //L802D1F2C
            this->unk130 = func_80325760;
            chMumbo_func_802D186C(this);
            if (actor_animationIsAt(this, 0.1f) != 0) {
                FUNC_8030E624(SFX_5D_BANJO_RAAOWW, 1.0f, 6000);
            }
            if (actor_animationIsAt(this, 0.4f) != 0) {
                FUNC_8030E624(SFX_5E_BANJO_PHEWWW, 1.0f, 6000);
            }
            chMumbo_func_802D1970(this);
            break;

        case 2: //L802D1F90
            if (actor_animationIsAt(this, 0.25f) != 0) {
            func_8030E484(0x41);
        }
        actor_playAnimationOnce(this);
            if (actor_animationIsAt(this, 0.999f)) {
                if( !func_8031FF1C(BKPROG_11_HAS_MET_MUMBO) 
                    && !func_803203FC(1) 
                    && !func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)
                ) {
                    func_80328A84(this, 3);
                    func_80311480(0xD8F, 0xE, this->position, this->marker, __chMumbo_textCallback, NULL);
                    func_80320004(BKPROG_11_HAS_MET_MUMBO, TRUE);
                    break;
                }

                if( !func_8031FF1C(BKPROG_DC_HAS_HAD_ENOUGH_TOKENS_BEFORE) 
                    && !func_803203FC(1)
                    && !func_803203FC(UNKFLAGS1_1F_IN_CHARACTER_PARADE)
                    && this->unk38_0
                ){
                    func_80328A84(this, 3);
                    func_80311480(0xDAA, 0xE, this->position, this->marker, __chMumbo_textCallback, NULL);
                    func_80320004(BKPROG_DC_HAS_HAD_ENOUGH_TOKENS_BEFORE, TRUE);
                    break;
                }

                func_80328A84(this, 4);
            }
            break;

        case 3: //L802D20D4
            actor_loopAnimation(this);
            break;

        case 4: //L802D20E4
            actor_loopAnimation(this);
             sp48 = (map_get() == MAP_7A_GL_CRYPT) ? chMumbo_withinHorzDistToPlayer(0x442, 0, 0x3C) :  chMumbo_withinHorzDistToPlayer(0, -0x5A, 0x3C);
            if( sp48 
                && func_8028ECAC() == 0 
                && func_8028F20C()
                && func_8028EFC8()
            ){
                func_8024E55C(0, face_buttons);
                if(face_buttons[FACE_BUTTON(BUTTON_B)] == 1){
                    if (D_8037DDF0 == TRANSFORM_7_WISHWASHY) {
                        this->unk38_31 = 0;
                    } else if (player_getTransformation() == TRANSFORM_1_BANJO && !func_8031FF1C(__bkProgId_from_transformationId(D_8037DDF0)) && map_get() != MAP_7A_GL_CRYPT){
                        this->unk38_31 = __transformation_getCost(D_8037DDF0);
                    }
                    this->unk38_0 =  (D_8037DDF0 == TRANSFORM_7_WISHWASHY) || (item_getCount(ITEM_1C_MUMBO_TOKEN) >= this->unk38_31);
                    if (this->unk38_0) {
                        sp48 = map_get() != MAP_E_MM_MUMBOS_SKULL;
                        sp44 = player_getTransformation() == TRANSFORM_1_BANJO;
                        func_8028F94C(2, this->position);
                        if ( sp44 && map_get() != MAP_7A_GL_CRYPT 
                             && !func_8031FF1C(0xBA) 
                             && randf() < 0.01 
                             && sp48
                        ) {
                            func_80311480(0xDAE, 6, NULL, this->marker, __chMumbo_textCallback, NULL);
                            func_80320004(0xBA, 1);
                            this->unk138_24 = TRUE;
                            func_80328A84(this, 3);
                        } else if (
                            sp44 
                            && map_get() != MAP_7A_GL_CRYPT  
                            && !this->unk138_23 
                            && (sp40 = func_8031FF44(0xBB, 2), sp40 < 3) 
                            && randf() < 0.05 
                            && sp48
                        ){
                            this->unk138_23 = TRUE;
                            this->unk10_12 = D_8037DDF0;
                            D_8037DDF0 = 7;
                            func_80320044(0xBB, ++sp40, 2);
                            func_80328A84(this, 5);
                        } else {
                            if (this->unk38_31) {
                                func_8025A6EC(SFX_2B_BULL_MOO_1, 28000);
                                func_803463D4(ITEM_1C_MUMBO_TOKEN, -this->unk38_31);
                            }
                            func_80328A84(this, 5);
                        }
                        gcpausemenu_80314AC8(0);

                        break;
                    }
                    func_8025A6EC(COMUSIC_2C_BUZZER, 22000);
                    if ((levelSpecificFlags_get(0x3E) == 0) && (func_80311480(0xDAC, 0, NULL, NULL, NULL, NULL) != 0)) {
                        levelSpecificFlags_set(0x3E, 1);
                    }
                }
            }
            break;

        case 5: //L802D2488
            actor_playAnimationOnce(this);
            if (actor_animationIsAt(this, 0.35f)){
                func_8030E2C4(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.56f)) {
                func_8030E394(this->unk44_31);
            }
            if (actor_animationIsAt(this, 0.57f)) {
                func_8030E6D4(1);
                func_8030E6D4(1);
            }
            if (actor_animationIsAt(this, 0.01f)) {
                func_8025A70C(COMUSIC_1D_MUMBO_TRANSFORMATION);
                func_8025A58C(0, 0x3E8);
            }
            if (actor_animationIsAt(this, 0.01f)) {
                
                if ( this->unk138_24 
                     || (this->unk10_12 == 0 
                        && (player_getTransformation() != TRANSFORM_1_BANJO) 
                        && (player_getTransformation() != TRANSFORM_7_WISHWASHY))
                ) {
                    func_8028FB88(TRANSFORM_1_BANJO);
                } else if (func_8028FB88(D_8037DDF0)) {
                    if (D_8037DDF0 != TRANSFORM_7_WISHWASHY) {
                        if (func_8031FF74(__bkProgId_from_transformationId(D_8037DDF0), TRUE)) {
                            this->velocity[0] = 1.0f;
                        }
                        this->unk38_31 = 0;
                    }
                    if (this->unk10_12 == 1) {
                        this->unk10_12 = 0;
                    }
                }
            }
            if (actor_animationIsAt(this, 0.79f)) {
                func_8025A58C(-1, 0x3E8);
            }
            if (actor_animationIsAt(this, 0.999f)) {
                if (!this->unk138_24) {
                    func_8028F918(0);
                }
                func_8025A7DC(COMUSIC_1D_MUMBO_TRANSFORMATION);
                if (player_getTransformation() != TRANSFORM_1_BANJO) {
                    func_80328A84(this, 3);
                    chMumbo_func_802D1B8C(this, D_8037DDF0);
                    break;
                }
                if (this->unk138_24) {
                    func_80328A84(this, 3);
                    func_80311480(0xDAF, 6, NULL, this->marker, __chMumbo_textCallback, NULL);
                    break;
                }
                gcpausemenu_80314AC8(1);
                func_80328A84(this, 4);
            }
            break;

        case 7: //L802D2704
            chMumbo_func_802D186C(this);
            if (func_803203FC(BKPROG_11_HAS_MET_MUMBO) == 0) {
                if (map_get() == MAP_7A_GL_CRYPT) {
                    sp48 = chMumbo_withinHorzDistToPlayer(0x453, 0, 0xBC);
                } else {
                    sp48 = chMumbo_withinHorzDistToPlayer(0, -0x6B, 0xBC);
                }
                if (sp48 != 0) {
                    func_80311480(0xDA7, 7, NULL, NULL, NULL, NULL);
                    func_803204E4(BKPROG_11_HAS_MET_MUMBO, TRUE);
                }
            }
            actor_loopAnimation(this);
            break;

        case 8: //L802D2790
            chMumbo_func_802D186C(this);
            if (func_803203FC(BKPROG_12_HAS_TRANSFORMED_BEFORE) == 0) {
                if (map_get() == MAP_7A_GL_CRYPT) {
                    sp48 = chMumbo_withinHorzDistToPlayer(0x453, 0, 0xBC);
                } else {
                    sp48 = chMumbo_withinHorzDistToPlayer(0, -0x6B, 0xBC);
                }
                if (sp48 != 0) {
                    func_80311480(0xDA8, 7, NULL, NULL, NULL, NULL);
                    func_803204E4(BKPROG_12_HAS_TRANSFORMED_BEFORE, TRUE);
                }
            }
            actor_loopAnimation(this);
            if (actor_animationIsAt(this, 0.99f)) {
                if (randf() < 0.4) {
                    temp_f12 = (randf() - 0.5) * 0.95300000000000007 * 2;
                    this->unk1C[0] = temp_f12 + ((temp_f12 >= 0.0f) ? 0.476 : -0.476);
                    func_80328AEC(this, 9);
                    break;
                }
                if (0.6 < randf()) {
                    animctrl_setDuration(this->animctrl, randf2(0.6f, 1.8f));
                }
            }
            break;
        case 9: //L802D2920
            this->yaw += this->unk1C[0];
            if (actor_animationIsAt(this, 0.99f)) {
                func_80328AEC(this, 8);
            }
            break;
    }
}

Actor *chMumbo_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *this = marker_getActor(marker);
    Actor *out;
    f32 sp44[3];
    f32 sp38[3] = D_80367510;

    func_8033A45C(4, (this->unk60 == 0.0f));
    func_8033A45C(5, (this->unk60 == 1.0f));
    func_8033A45C(6, (this->unk60 == 0.0f));
    func_8033A45C(7, (this->unk60 == 1.0f));
    func_8033A45C(8, (this->unk60 == 2.0f));
    func_8033A45C(9, 0);
    out = func_80325888(marker, gfx, mtx, vtx);
    if( marker->unk14_21 && out->state == 8){
        if( actor_animationIsAt(out, 0.2f)
            || actor_animationIsAt(out, 0.28f)
            || actor_animationIsAt(out, 0.36f)
         ){
            func_8034A174(func_80329934(), 9, sp44);
            func_802EE6CC(sp44, sp38, D_8036751C, 0, 0.9f, 0.0f, 0x46, 0x14, 0);
        }
    }
    return out;
}

void func_802D2B94(s32 this, s32 arg1){
    s32 xform;
    xform = player_getTransformation();
    if(xform == TRANSFORM_1_BANJO || xform  == TRANSFORM_7_WISHWASHY || D_8037DDF2)
        return;
    
    D_8037DDF2++;
    if(D_8037DDF3)
        return;
    
    func_80311480(func_8031FF74(BKPROG_83_MAGIC_GET_WEAK_TEXT, TRUE) ? 0xf5C: 0xf5b, 0xe, NULL, NULL, NULL, NULL);
}

void func_802D2C24(s32 this, s32 arg1){
    s32 xform;
    xform = player_getTransformation();
    if(xform == TRANSFORM_1_BANJO || xform  == TRANSFORM_7_WISHWASHY || D_8037DDF1)
        return;
    func_80311480(func_8031FF74(BKPROG_84_MAGIC_ALL_GONE_TEXT, TRUE) ? 0xf5e: 0xf5d, 0xe, NULL, NULL, NULL, NULL);
    D_8037DDF1++;
    func_8028FB88(TRANSFORM_1_BANJO);
}

void func_802D2CB8(void){
    D_8037DDF2 = D_8037DDF3 = D_8037DDF1 = 0;
}

void func_802D2CDC(void){
    D_8037DDF3 = D_8037DDF2;
    D_8037DDF2 = 0;
}
