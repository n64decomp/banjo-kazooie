#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void actor_postdrawMethod(ActorMarker *);
extern void chBottlesBonus_func_802DD080(Gfx **, Mtx **);
extern void func_80311714(s32);

Actor *chMumbosHandWithPicture_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void chMumbosHandWithPicture_update(Actor *this);

/* .data */
ActorAnimationInfo chMumbosHandWithPictureAnimations[] ={
    {0x000, 0.0f},
    {ASSET_2C7_ANIM_MUMBOS_HAND_WITH_PICTURE, 0.6f},
    {ASSET_2C6_ANIM_MUMBOS_HAND_WITH_PICTURE, 3.0f},
    {ASSET_2C8_ANIM_MUMBOS_HAND_WITH_PICTURE, 0.6f},
    {ASSET_2C8_ANIM_MUMBOS_HAND_WITH_PICTURE, 0.6f},
    {ASSET_2C6_ANIM_MUMBOS_HAND_WITH_PICTURE, 9e+09},
};

f32 D_80368330[3] = {0.0f, 0.0f, 0.0f};

ActorInfo chMumbosHandWithPicture = {
    MARKER_294_MUMBOS_HAND_WITH_PICTURE, ACTOR_19B_MUMBOS_HAND_WITH_PICTURE, ASSET_56D_MUMBOS_HAND_WITH_PICTURE, 
    0x1, chMumbosHandWithPictureAnimations, 
    chMumbosHandWithPicture_update, actor_update_func_80326224, chMumbosHandWithPicture_draw, 
    0, 0, 0.0f, 0
};

/* .bss */
ActorMarker *D_8037DFE0;
enum level_e D_8037DFE4;
BKModelBin *D_8037DFE8;
f32 D_8037DFF0[3];

/* .code */
Actor *chMumbosHandWithPicture_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp58[3];
    f32 sp4C[3];
    void *sp48;


    this = marker_getActor(marker);
    sp48 = func_8030C704();

    if ((sp48 == 0) || (getGameMode() != GAME_MODE_A_SNS_PICTURE))
        return this;

    chBottlesBonus_func_802DD080(gfx, mtx);
    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 50.0f;

    sp4C[0] = 0.0f;
    sp4C[1] = 0.0f;
    sp4C[2] = 0.0f;

    D_8037DFF0[0] = 0.0f;
    D_8037DFF0[1] = 270.0f;
    D_8037DFF0[2] = 0.0f;
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    modelRender_draw(gfx, mtx, sp58, NULL, 1.0f, sp4C, D_8037DFE8);
    gDPSetColorDither((*gfx)++, G_CD_DISABLE);
    func_80253190(gfx);
    gSPSegment((*gfx)++, 0x04, osVirtualToPhysical(sp48));
    modelRender_setPreDrawCallback((GenFunction_1)actor_predrawMethod,  (s32)this);
    modelRender_setPostDrawCallback((GenFunction_1)actor_postdrawMethod, (s32)marker);
    modelRender_draw(gfx, mtx, this->position, NULL, 4.5f, sp4C, marker_loadModelBin(marker));
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    gDPSetColorDither((*gfx)++, G_CD_MAGICSQ);
    chBottlesBonus_func_802DD158(gfx, mtx);
    return this;
}

void func_802DEDDC(Actor *this){
    D_8037DFE0 = NULL;
    if(D_8037DFE8 != NULL){
        assetcache_release(D_8037DFE8);
        D_8037DFE8 = NULL;
    }
}


void chMumbosHandWithPicture_update(Actor *this) {
    enum level_e level_id_1;
    enum asset_e text_id;
    enum level_e level_id_2;
    f32 time;

    if (!this->initialized) {
        this->initialized = TRUE;
        actor_collisionOff(this);
        marker_setFreeMethod(this->marker, func_802DEDDC);
        actor_playAnimationOnce(this);
        if (D_8037DFE8 == NULL) {
            D_8037DFE8 = assetcache_get(ASSET_56E_HAMMERHEAD_BEACH_SCENERY);
        }
        level_id_1 = map_getLevel(gsworld_getMap());
        level_id_2 = level_id_1 == D_8037DFE4;
        if (level_id_2) {
            subaddie_set_state_with_direction(this, 2, 0.0f, 1);
            actor_loopAnimation(this);
        }
        switch(level_id_1){
            case LEVEL_2_TREASURE_TROVE_COVE:
                text_id = level_id_2 + 0xE39; // 0xE3B
                break;

            case LEVEL_5_FREEZEEZY_PEAK:
                text_id = level_id_2 + 0xE3B; // 0xE40
                break;

            case LEVEL_7_GOBIS_VALLEY:
            default:
                text_id = level_id_2 + 0xE3D; // 0xE44
                break;
        }
        time = (f32) ((f64) (level_id_2 + 1) * 0.75);
        timedFunc_set_1(time, func_80311714, 0);
        func_80324DBC(time, text_id, 0x80, NULL, NULL, NULL, NULL);
        timedFunc_set_1(time, func_80311714, 1);
        D_8037DFE4 = level_id_1;
    }
    switch(this->state){
        case 1:
            if (anctrl_isStopped(this->anctrl)) {
                subaddie_set_state_with_direction(this, 2, 0.0f, 1);
                actor_loopAnimation(this);
            }
            break;

        case 3:
            if(anctrl_isStopped(this->anctrl)) {
                volatileFlag_set(VOLATILE_FLAG_C3, 1);
                this->state = 4;
            }
            break;

        case 2:
            if(gctransition_8030BDC0()) {
                subaddie_set_state_with_direction(this, 5, 0.0f, 1);
            }
            break;

        case 4:
            break;

        case 5:
            break;
    }
    musicKeepsPlaying();
}

void func_802DF04C(void){
    Actor *this;
    if(D_8037DFE0 == NULL){
        this = actor_spawnWithYaw_f32(0x19B, D_80368330, 0);
        D_8037DFE0 = this->marker;
    }
}

void func_802DF090(s32 arg0, s32 arg1){
    if(D_8037DFE0 == NULL){
        __spawnQueue_add_0(func_802DF04C);
    }
}

void func_802DF0C8(void) {
    Actor *sp1C;

    sp1C = marker_getActor(D_8037DFE0);
    if (sp1C->state != 3) {
        subaddie_set_state_with_direction(sp1C, 3, 0.0f, 1);
        actor_playAnimationOnce(sp1C);
    }
}

void func_802DF11C(s32 arg0, s32 arg1){
    if(D_8037DFE0 != NULL){
        func_80326310(marker_getActor(D_8037DFE0));
    }
}
