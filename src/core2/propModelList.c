#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern f32 func_8033A244(f32);

typedef struct{
    BKModelBin *model_bin;
    s32 timestamp;
    f32 scale;
}propModelListModel;

typedef struct{
    BKSprite *sprite;
    BKSpriteDisplayData *display;
    s32 timestamp;
    f32 scale;
}propModelListSprite;

BKModelBin *propModelList_getModel(s32 arg0);

/* .data */
s32 D_8036B800 = 0;

/* .bss */
static propModelListModel *sPropModelList;
static propModelListSprite *sPropSpriteList;

BKSpriteDisplayData *propModelList_getSpriteDisplayList(s32 arg0);

void propModelList_drawModel(Gfx **gfx, Mtx **mtx, Vtx **vtx, f32 position[3], f32 rotation[3], f32 scale, s32 model_index, Cube* arg7){
    BKModelBin * model;
    
    model = propModelList_getModel(model_index);
    func_8033A244(3700.0f);
    func_8033A28C(1);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    func_8033A1FC();
    modelRender_draw(gfx, mtx, position, rotation, scale, NULL, model);
}

void propModelList_drawSprite(Gfx **gfx, Mtx **mtx, Vtx **Vtx, f32 position[3], f32 scale, s32 sprite_index, Cube *arg6, s32 r, s32 b, s32 g, s32 mirrored, s32 frame) {
    f32 scale_f3[3];
    BKSpriteDisplayData *sprite;

    sprite = propModelList_getSpriteDisplayList(sprite_index);
    scale_f3[0] = scale;
    scale_f3[1] = scale;
    scale_f3[2] = scale;
    func_80338338(0xFF - (r * 0x10), 0xFF - (b * 0x10), 0xFF - (g * 0x10));
    if (func_80344C20(sprite) & 0xB00) {
        func_803382E4(0xB);
    } else {
        func_803382E4(0xE);
    }
    func_80335D30(gfx);
    func_80344138(sprite, frame, mirrored, position, scale_f3, gfx, mtx);
    func_8033687C(gfx);
}

BKModelBin *propModelList_getModel(s32 arg0){
    if(sPropModelList[arg0].model_bin == NULL){
        sPropModelList[arg0].model_bin = assetcache_get(0x2d1 + arg0);
    }
    sPropModelList[arg0].timestamp = globalTimer_getTime();
    return sPropModelList[arg0].model_bin;
}

BKModelBin *propModelList_getModelIfActive(s32 arg0){
    return sPropModelList[arg0].model_bin;
}

BKSpriteDisplayData *propModelList_getSpriteDisplayList(s32 arg0)
{
    
    if (((propModelListSprite *)((s32)sPropSpriteList + arg0*sizeof(propModelListSprite)))->sprite == 0){
        ((propModelListSprite *)((s32)sPropSpriteList + arg0*sizeof(propModelListSprite)))->sprite = func_8033B6C4(arg0 + 0x572, &((propModelListSprite *)((s32)sPropSpriteList + arg0*sizeof(propModelListSprite)))->display);
    }
    sPropSpriteList[arg0].timestamp = globalTimer_getTime();
    return sPropSpriteList[arg0].display;
}

BKSprite *propModelList_getSprite(s32 arg0){
    propModelList_getSpriteDisplayList(arg0);
    return sPropSpriteList[arg0].sprite;
}

f32 propModelList_getScale(Prop *arg0){
    if(arg0->is_3d){
        ModelProp* ModelProp = &arg0->modelProp;
        return sPropModelList[arg0->spriteProp.sprite_index].scale;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        return sPropSpriteList[spriteProp->sprite_index].scale;
    }
}

void propModelList_setScale(Prop *arg0, f32 arg1){
    if(arg0->is_3d){
        ModelProp* ModelProp = &arg0->modelProp;
        sPropModelList[arg0->spriteProp.sprite_index].scale = (f32)ModelProp->scale*arg1/100.0f;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        sPropSpriteList[spriteProp->sprite_index].scale = (f32)spriteProp->scale*arg1/100.0f;
    }
}

void propModelList_free(void){
    propModelListModel* iPtr;
    propModelListSprite* jPtr;

    for(iPtr = sPropModelList; iPtr < &sPropModelList[0x2A2]; iPtr++){
        if(iPtr->model_bin){
            assetcache_release(iPtr->model_bin);
        }
    }
    for(jPtr = sPropSpriteList; jPtr < &sPropSpriteList[0x168]; jPtr++){
        if(jPtr->sprite){
            func_8033B338(&jPtr->sprite, &jPtr->display);
        }
    }
    free(sPropModelList);
    sPropModelList = NULL;
    free(sPropSpriteList);
    sPropSpriteList = NULL;
}

void propModelList_init(void){//init
    propModelListModel* iPtr;
    propModelListSprite* jPtr;

    sPropModelList = (propModelListModel *)malloc(0x2A2 * sizeof(propModelListModel));
    sPropSpriteList = (propModelListSprite *)malloc(0x168 * sizeof(propModelListSprite));
    D_8036B800 = 0;
    for(iPtr = sPropModelList; iPtr < &sPropModelList[0x2A2]; iPtr++){
        iPtr->model_bin = NULL;
        iPtr->scale = 0.0f;
    }
    for(jPtr = sPropSpriteList; jPtr < &sPropSpriteList[0x168]; jPtr++){
        jPtr->sprite = NULL;
        jPtr->scale = 0.0f;
    }
}

/**
 * @brief This function flushes old models from the prop model and sprite list.
 * 
 * @param level 1 = checks timestamp of 40 oldest models
 *             2 = checks timestamp of all models
 *             3 = flushes ALL models despites age
 */
void propModelList_flush(s32 level) {
    static s32 D_8036B804 = 0;
    static s32 D_8036B808 = 0;
    s32 oldest_active_time;
    s32 var_s0;
    propModelListModel *sp3C;
    propModelListSprite *temp_a0_2;

    oldest_active_time = globalTimer_getTime() - func_80255B08(level);
    for(var_s0 = 0; (sPropModelList != NULL) && (var_s0 < ((level == 1) ? 0x28 : 0x2A1)); var_s0++, D_8036B804 = (D_8036B804 >= 0x2A1)? 0: D_8036B804 + 1){
        sp3C = (propModelListModel*)((u32)sPropModelList + sizeof(propModelListModel)*D_8036B804);
        if ((sp3C->model_bin != NULL) && ((sp3C->timestamp < oldest_active_time) || (level == 3))){
            assetcache_release(sp3C->model_bin);
            sp3C->model_bin = NULL;
            if( (level != 1) && (func_80254BC4(1))){
                return;
            }
        }
    }

    for(var_s0 = 0; (sPropSpriteList != NULL) && (var_s0 < ((level == 1) ? 0x28 : 0x167)); var_s0++, D_8036B808 = (D_8036B808 >= 0x167)? 0: D_8036B808 + 1){
        temp_a0_2 = (propModelListSprite*)((u32)sPropSpriteList + sizeof(propModelListSprite)*D_8036B808);
        if ((temp_a0_2->sprite != 0) && ((temp_a0_2->timestamp < oldest_active_time) || (level == 3))){
            func_8033B338(&temp_a0_2->sprite, &temp_a0_2->display);
            if( (level != 1) && (func_80254BC4(1))){
                return;
            }
        }
    }
}

void propModelList_defrag(void) {
    BKModelBin *temp_a0;
    s32 phi_s2;

    sPropSpriteList = (propModelListSprite *) defrag(sPropSpriteList);
    sPropModelList = (propModelListModel *) defrag(sPropModelList);
    if (!func_802559A0() && !func_80255AE4() && sPropModelList != NULL) {
        for(phi_s2 = 0x14; (phi_s2 != 0) && !func_80255AE4(); phi_s2--){
            D_8036B800++;
            if (D_8036B800 >= 0x2A2) {
                D_8036B800 = 0;
            }
            temp_a0 = sPropModelList[D_8036B800].model_bin;
            if (temp_a0 != NULL && (func_802546E4(temp_a0) < 0x2AF8)) {
                sPropModelList[D_8036B800].model_bin = func_80255888(sPropModelList[D_8036B800].model_bin);
            }
        }
    }
}

void propModelList_refresh(void) {
    s32 model_list_index;
    s32 temp_t7;
    propModelListSprite *phi_s0;
    s32 phi_s2;
    propModelListModel *phi_s0_2;

    for(phi_s0 = sPropSpriteList; phi_s0 < sPropSpriteList + 360; phi_s0++){
        if (phi_s0->sprite != NULL) {
            temp_t7 = phi_s0 - sPropSpriteList;
            func_8033B338(&phi_s0->sprite, &phi_s0->display);
            phi_s2 = temp_t7 *sizeof(propModelListSprite);
            *(BKSprite **)((s32)sPropSpriteList + phi_s2) = func_8033B6C4(temp_t7 + 0x572,  (BKSpriteDisplayData **)((s32)sPropSpriteList + phi_s2 + 4));
        }
    }
    
    for(phi_s0_2 = sPropModelList; phi_s0_2 < sPropModelList + 674; phi_s0_2++){
        if(phi_s0_2->model_bin != NULL){
            model_list_index = phi_s0_2 - sPropModelList;
            assetcache_release(phi_s0_2->model_bin);
            sPropModelList[model_list_index].model_bin = (BKModelBin *) assetcache_get(model_list_index + 0x2D1);

        }
    }
}
