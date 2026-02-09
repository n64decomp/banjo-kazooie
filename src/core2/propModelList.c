#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#define PROP_MODEL_COUNT 0x2A2
#define PROP_SPRITE_COUNT 0x168

extern f32 func_8033A244(f32);

typedef struct{
    BKModelBin *model_bin;
    s32 timestamp;
    f32 scale;
} PropModelData;

typedef struct{
    BKSprite *sprite;
    BKSpriteDisplayData *display;
    s32 timestamp;
    f32 scale;
} PropSpriteData;

BKModelBin *propModelList_getModel(s32 arg0);

/* .data */
s32 D_8036B800 = 0;

/* .bss */
static PropModelData *sPropModelList;
static PropSpriteData *sPropSpriteList;

BKSpriteDisplayData *propModelList_getSpriteDisplayList(s32 arg0);

void propModelList_drawModel(Gfx **gfx, Mtx **mtx, Vtx **vtx, f32 position[3], f32 rotation[3], f32 scale, s32 modelId, Cube* arg7){
    BKModelBin * model;
    
    model = propModelList_getModel(modelId);
    func_8033A244(3700.0f);
    func_8033A28C(1);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    func_8033A1FC();
    modelRender_draw(gfx, mtx, position, rotation, scale, NULL, model);
}

void propModelList_drawSprite(
        Gfx **gfx, Mtx **mtx, Vtx **Vtx,
        f32 position[3], f32 scale, s32 spriteId, Cube *arg6,
        s32 rgb_remove_red, s32 rgb_remove_green, s32 rgb_remove_blue,
        s32 mirrored, s32 frame) {
    f32 scale_f3[3];
    BKSpriteDisplayData *sprite;

    sprite = propModelList_getSpriteDisplayList(spriteId);
    scale_f3[0] = scale;
    scale_f3[1] = scale;
    scale_f3[2] = scale;
    codeAEDA0_setPrimaryColorRGB(0xFF - (rgb_remove_red * 0x10), 0xFF - (rgb_remove_green * 0x10), 0xFF - (rgb_remove_blue * 0x10));
    if (codeBD100_getSpriteType(sprite) & 0xB00) {
        codeAEDA0_setSpriteDrawMode(0xB);
    } else {
        codeAEDA0_setSpriteDrawMode(0xE);
    }
    codeAEDA0_drawSprite(gfx);
    func_80344138(sprite, frame, mirrored, position, scale_f3, gfx, mtx);
    codeAEDA0_postDrawSprite(gfx);
}

BKModelBin *propModelList_getModel(s32 arg0){
    if(sPropModelList[arg0].model_bin == NULL){
        sPropModelList[arg0].model_bin = assetcache_get(MODEL_ASSET_OFFSET + arg0);
    }
    sPropModelList[arg0].timestamp = globalTimer_getTime();
    return sPropModelList[arg0].model_bin;
}

BKModelBin *propModelList_getModelIfActive(s32 arg0){
    return sPropModelList[arg0].model_bin;
}

BKSpriteDisplayData *propModelList_getSpriteDisplayList(s32 arg0)
{
    
    if (((PropSpriteData *)((s32)sPropSpriteList + arg0*sizeof(PropSpriteData)))->sprite == 0){
        ((PropSpriteData *)((s32)sPropSpriteList + arg0*sizeof(PropSpriteData)))->sprite = codeB3A80_getSprite(arg0 + SPRITE_ASSET_OFFSET, &((PropSpriteData *)((s32)sPropSpriteList + arg0*sizeof(PropSpriteData)))->display);
    }
    sPropSpriteList[arg0].timestamp = globalTimer_getTime();
    return sPropSpriteList[arg0].display;
}

BKSprite *propModelList_getSprite(s32 arg0){
    propModelList_getSpriteDisplayList(arg0);
    return sPropSpriteList[arg0].sprite;
}

f32 propModelList_getScale(Prop *arg0){
    if(arg0->isModelProp){
        ModelProp* ModelProp = &arg0->modelProp;
        return sPropModelList[arg0->spriteProp.spriteId].scale;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        return sPropSpriteList[spriteProp->spriteId].scale;
    }
}

void propModelList_setScale(Prop *arg0, f32 arg1){
    if(arg0->isModelProp){
        ModelProp* ModelProp = &arg0->modelProp;
        sPropModelList[arg0->spriteProp.spriteId].scale = (f32)ModelProp->scale*arg1/100.0f;
    }
    else{//L8030A65C
        SpriteProp *spriteProp = &arg0->spriteProp;
        sPropSpriteList[spriteProp->spriteId].scale = (f32)spriteProp->scale*arg1/100.0f;
    }
}

void propModelList_free(void){
    PropModelData* iPtr;
    PropSpriteData* jPtr;

    for(iPtr = sPropModelList; iPtr < &sPropModelList[PROP_MODEL_COUNT]; iPtr++){
        if(iPtr->model_bin){
            assetcache_release(iPtr->model_bin);
        }
    }
    for(jPtr = sPropSpriteList; jPtr < &sPropSpriteList[PROP_SPRITE_COUNT]; jPtr++){
        if(jPtr->sprite){
            codeB3A80_releaseSprite(&jPtr->sprite, &jPtr->display);
        }
    }
    free(sPropModelList);
    sPropModelList = NULL;
    free(sPropSpriteList);
    sPropSpriteList = NULL;
}

void propModelList_init(void){//init
    PropModelData* iPtr;
    PropSpriteData* jPtr;

    sPropModelList = (PropModelData *)malloc(PROP_MODEL_COUNT * sizeof(PropModelData));
    sPropSpriteList = (PropSpriteData *)malloc(PROP_SPRITE_COUNT * sizeof(PropSpriteData));
    D_8036B800 = 0;
    for(iPtr = sPropModelList; iPtr < &sPropModelList[PROP_MODEL_COUNT]; iPtr++){
        iPtr->model_bin = NULL;
        iPtr->scale = 0.0f;
    }
    for(jPtr = sPropSpriteList; jPtr < &sPropSpriteList[PROP_SPRITE_COUNT]; jPtr++){
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
    PropModelData *model_entry;
    PropSpriteData *sprite_entry;

    oldest_active_time = globalTimer_getTime() - func_80255B08(level);
    for(var_s0 = 0;
        (sPropModelList != NULL) && (var_s0 < ((level == 1) ? 0x28 : PROP_MODEL_COUNT - 1));
        var_s0++, D_8036B804 = (D_8036B804 >= PROP_MODEL_COUNT - 1)? 0: D_8036B804 + 1)
    {
        model_entry = (PropModelData*)((u32)sPropModelList + sizeof(PropModelData)*D_8036B804);
        if ((model_entry->model_bin != NULL) && ((model_entry->timestamp < oldest_active_time) || (level == 3))){
            assetcache_release(model_entry->model_bin);
            model_entry->model_bin = NULL;
            if( (level != 1) && (func_80254BC4(1))){
                return;
            }
        }
    }

    for(var_s0 = 0;
        (sPropSpriteList != NULL) && (var_s0 < ((level == 1) ? 0x28 : PROP_SPRITE_COUNT - 1));
        var_s0++, D_8036B808 = (D_8036B808 >= PROP_SPRITE_COUNT - 1)? 0: D_8036B808 + 1)
    {
        sprite_entry = (PropSpriteData*)((u32)sPropSpriteList + sizeof(PropSpriteData)*D_8036B808);
        if ((sprite_entry->sprite != 0) &&
            ((sprite_entry->timestamp < oldest_active_time) ||
            (level == 3)))
        {
            codeB3A80_releaseSprite(&sprite_entry->sprite, &sprite_entry->display);
            if( (level != 1) && (func_80254BC4(1))){
                return;
            }
        }
    }
}

void propModelList_defrag(void) {
    BKModelBin *temp_a0;
    s32 phi_s2;

    sPropSpriteList = (PropSpriteData *) defrag(sPropSpriteList);
    sPropModelList = (PropModelData *) defrag(sPropModelList);
    if (!func_802559A0() && !func_80255AE4() && sPropModelList != NULL) {
        for(phi_s2 = 0x14; (phi_s2 != 0) && !func_80255AE4(); phi_s2--){
            D_8036B800++;
            if (D_8036B800 >= PROP_MODEL_COUNT) {
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
    PropSpriteData *sprite_entry;
    s32 phi_s2;
    PropModelData *model_entry;

    for(sprite_entry = sPropSpriteList; sprite_entry < sPropSpriteList + 360; sprite_entry++){
        if (sprite_entry->sprite != NULL) {
            temp_t7 = sprite_entry - sPropSpriteList;
            codeB3A80_releaseSprite(&sprite_entry->sprite, &sprite_entry->display);
            phi_s2 = temp_t7 *sizeof(PropSpriteData);
            *(BKSprite **)((s32)sPropSpriteList + phi_s2) = codeB3A80_getSprite(temp_t7 + SPRITE_ASSET_OFFSET,  (BKSpriteDisplayData **)((s32)sPropSpriteList + phi_s2 + 4));
        }
    }
    
    for(model_entry = sPropModelList; model_entry < sPropModelList + 674; model_entry++){
        if(model_entry->model_bin != NULL){
            model_list_index = model_entry - sPropModelList;
            assetcache_release(model_entry->model_bin);
            sPropModelList[model_list_index].model_bin = (BKModelBin *) assetcache_get(model_list_index + MODEL_ASSET_OFFSET);
        }
    }
}
