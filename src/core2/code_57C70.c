#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_80325794(ActorMarker *);
extern void func_802DD080(Gfx **, Mtx **);
extern void func_80311714(s32);

Actor *func_802DEC00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_802DEE1C(Actor *this);

/* .data */
ActorAnimationInfo D_80368300[] ={
    {0x000, 0.0f},
    {0x2C7, 0.6f},
    {0x2C6, 3.0f},
    {0x2C8, 0.6f},
    {0x2C8, 0.6f},
    {0x2C6, 9e+09},
};

f32 D_80368330[3] = {0.0f, 0.0f, 0.0f};

ActorInfo D_8036833C = { 
    0x294, 0x19B, 0x56D, 
    0x1, D_80368300, 
    func_802DEE1C, func_80326224, func_802DEC00, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DFE0;
enum level_e D_8037DFE4;
BKModelBin *D_8037DFE8;
f32 D_8037DFF0[3];

/* .code */
Actor *func_802DEC00(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp58[3];
    f32 sp4C[3];
    void *sp48;


    this = marker_getActor(marker);
    sp48 = func_8030C704();

    if ((sp48 == 0) || (getGameMode() != GAME_MODE_A_SNS_PICTURE))
        return this;

    func_802DD080(gfx, mtx);
    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 50.0f;

    sp4C[0] = 0.0f;
    sp4C[1] = 0.0f;
    sp4C[2] = 0.0f;

    D_8037DFF0[0] = 0.0f;
    D_8037DFF0[1] = 270.0f;
    D_8037DFF0[2] = 0.0f;
    set_model_render_mode(1);
    func_803391A4(gfx, mtx, sp58, NULL, 1.0f, sp4C, D_8037DFE8);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    func_80253190(gfx);
    gSPSegment((*gfx)++, 0x04, osVirtualToPhysical(sp48));
    func_8033A2D4(func_803253A0, this);
    func_8033A2E8(func_80325794, marker);
    func_803391A4(gfx, mtx, this->position, NULL, 4.5f, &sp4C, func_80330B1C(marker));
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    gDPSetColorDither((*gfx)++, G_CD_MAGICSQ);
    func_802DD158(gfx, mtx);
    return this;
}

void func_802DEDDC(Actor *this){
    D_8037DFE0 = NULL;
    if(D_8037DFE8 != NULL){
        assetcache_release(D_8037DFE8);
        D_8037DFE8 = NULL;
    }
}


void func_802DEE1C(Actor *this) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 sp38;

    if (!this->initialized) {
        this->initialized = TRUE;
        actor_collisionOff(this);
        func_803300D8(this->marker, func_802DEDDC);
        actor_playAnimationOnce(this);
        if (D_8037DFE8 == NULL) {
            D_8037DFE8 = assetcache_get(0x56E);
        }
        sp4C = map_getLevel(map_get());
        sp44 = sp4C == D_8037DFE4;
        if (sp44) {
            func_80328B8C(this, 2, 0.0f, 1);
            actor_loopAnimation(this);
        }
        switch(sp4C){
            case LEVEL_2_TREASURE_TROVE_COVE:
                sp48 = sp44 + 0xE39;
                break;

            case LEVEL_5_FREEZEEZY_PEAK:
                sp48 = sp44 + 0xE3B;
                break;

            case LEVEL_7_GOBIS_VALLEY:
            default:
                sp48 = sp44 + 0xE3D;
                break;
        }
        sp38 = (f32) ((f64) (sp44 + 1) * 0.75);
        timedFunc_set_1(sp38, func_80311714, 0);
        func_80324DBC(sp38, sp48, 0x80, NULL, NULL, NULL, NULL);
        timedFunc_set_1(sp38, func_80311714, 1);
        D_8037DFE4 = sp4C;
    }
    switch(this->state){
        case 1:
            if (animctrl_isStopped(this->animctrl)) {
                func_80328B8C(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 3:
            if(animctrl_isStopped(this->animctrl)) {
                func_803204E4(0xC3, 1);
                this->state = 4;
            }
            break;

        case 2:
            if(gctransition_8030BDC0()) {
                func_80328B8C(this, 5, 0.0f, 1);
            }
            break;

        case 4:
            break;

        case 5:
            break;
    }
    func_803228D8();
}

void func_802DF04C(void){
    Actor *this;
    if(D_8037DFE0 == NULL){
        this = func_8032813C(0x19B, D_80368330, 0);
        D_8037DFE0 = this->marker;
    }
}

void func_802DF090(s32 arg0, s32 arg1){
    if(D_8037DFE0 == NULL){
        func_802C3BF8(func_802DF04C);
    }
}

void func_802DF0C8(void) {
    Actor *sp1C;

    sp1C = marker_getActor(D_8037DFE0);
    if (sp1C->state != 3) {
        func_80328B8C(sp1C, 3, 0.0f, 1);
        actor_playAnimationOnce(sp1C);
    }
}

void func_802DF11C(s32 arg0, s32 arg1){
    if(D_8037DFE0 != NULL){
        func_80326310(marker_getActor(D_8037DFE0));
    }
}
