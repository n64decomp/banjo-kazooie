#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/ba/model.h"
#include "core2/ba/physics.h"

void func_80254008(void);
void assetcache_release(void *); //assetcache_free
void func_8033A280(f32);

extern s32 osCicId;

/* .data */
struct5Bs *D_80363780 = NULL;

/* .bss */
void *baModelBin; //baModelPtr
s16 baModelId; //baModel asset_id
u8  baModelEnvAlpha;
u8  baModelDirection;
u8  baModelIsVisible;
f32 baModelScale;
f32 baModelPitch;
f32 baModelRoll;
f32 baModelYaw;
f32 D_8037C100[3];
f32 D_8037C110[3];
f32 baModelDisplacement[3];
void (*baModelPostDrawMethod)(Gfx **gfx, Mtx **mtx, Vtx **vtx);
f32 D_8037C130[2][4];
struct {
    u8 unk0;
    f32 unk4[3]; 
} D_8037C150;

//public
void baModel_set(enum asset_e asset_id);

//.data
static void _baModel_updateModelYaw(void){
    switch(baModelDirection){
        case PLAYER_MODEL_DIR_KAZOOIE:
            baModelYaw = mlNormalizeAngle(yaw_get() + 180.0f);
            break;
        default:
            baModelYaw = yaw_get();
            break;
        case PLAYER_MODEL_DIR_GLOBAL:
            break;
    }
}

void baModel_80291A50(s32 arg0, f32 dst[3]){
    func_8034A174(D_80363780, arg0, dst);
    if(ml_isZero_vec3f(dst)){
        playerPosition_get(dst);
    }
}

Actor *baModel_80291AAC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    return NULL;
}

static void _baModel_preDraw(int arg0){
    baMarker_get()->unk14_21 = 1;
}

void baModel_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 rotation[3];
    s32 env_color[3];
    f32 plyr_pos[3]; //sp44
    f32 sp38[3];

    if(!baModelIsVisible)
        return;

    _baModel_updateModelYaw();
    baModelRoll = roll_get();
    baModelPitch = pitch_get();
    playerPosition_get(plyr_pos);
    plyr_pos[1] += 2.0f;
    ml_vec3f_assign(rotation, baModelPitch, baModelYaw, baModelRoll);
    func_8029A47C(env_color);
    ml_vec3f_copy(sp38, D_8037C100);

    plyr_pos[0] += baModelDisplacement[0];\
    plyr_pos[1] += baModelDisplacement[1];\
    plyr_pos[2] += baModelDisplacement[2];

    sp38[0] += baModelDisplacement[0];\
    sp38[1] += baModelDisplacement[1];\
    sp38[2] += baModelDisplacement[2];

    if(baModelBin){
        baanim_80289F30();
        func_8029DD6C();
        modelRender_setEnvColor(env_color[0], env_color[1], env_color[2], baModelEnvAlpha);
        func_8033A280(2.0f);
        modelRender_preDraw((GenFunction_1)_baModel_preDraw, 0);
        func_8033A450(D_80363780);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        if(D_8037C150.unk0){
            D_8037C150.unk0 = 0;
            modelRender_draw(gfx, mtx, D_8037C150.unk4, rotation, baModelScale, sp38, baModelBin);
        }
        else{
            modelRender_draw(gfx, mtx, plyr_pos, rotation, baModelScale, sp38, baModelBin);
        }
    }//L80291CD4

    if(baModelPostDrawMethod){
        baModelPostDrawMethod(gfx, mtx, vtx);
    }
}

void baModel_updateModel(void){
    baModel_set(func_802985F0());
}

void baModel_reset(void){
    f32 plyr_pos[3];
    int i;
    for(i = 0; i < 2 ; i++){
        baModel_80292048(i, 0.0f, 0.0f, 0.0f);
        baModel_80292078(i, 0.0f);
    }
    baModelEnvAlpha = 0xFF;
    baModelBin = NULL;
    baModelId = 0;
    baModelPostDrawMethod = NULL;
    D_80363780 = func_8034A2C8();
    func_8034A130(D_80363780);
    ml_vec3f_clear(D_8037C100);
    ml_vec3f_clear(D_8037C110);
    ml_vec3f_clear(baModelDisplacement);
    baModelYaw = baModelRoll = baModelPitch = 0.0f;
    D_8037C150.unk0 = 0;
    baModel_setVisible(TRUE);
    baModel_setScale(1.0f);
    baModelDirection = 0;
    baModel_setDirection(PLAYER_MODEL_DIR_BANJO);
    if(!func_8028ADB4())
        baModel_updateModel();
    player_getPosition(plyr_pos);
    __spawnQueue_add_4((GenFunction_4)spawnQueue_actor_f32,
        ACTOR_17_PLAYER_SHADOW, 
        reinterpret_cast(s32, plyr_pos[0]), 
        reinterpret_cast(s32, plyr_pos[1]), 
        reinterpret_cast(s32, plyr_pos[2])
    );
}

void baModel_free(void){
    assetcache_release(baModelBin);
    baModelBin = NULL;
    baModelId = 0;
    func_8034A2A8(D_80363780);
    D_80363780 = NULL;
}

void baModel_update(void){
    f32 sp1C;
    f32 temp_f0;

    sp1C = D_8037C110[1] - D_8037C100[1];
    temp_f0 = mlAbsF(sp1C);
    if( temp_f0 < 0.01){
        D_8037C100[1] = D_8037C110[1];
    }
    else{
        if(5.0f < temp_f0){
            temp_f0 = 1.0f;
        }
        if(0.0f < sp1C){
            D_8037C100[1] += temp_f0;
        }
        else{
            D_8037C100[1] -= temp_f0; 
        }
        {//L80291F7C
            baMarker_get()->unk14_21 = 0;
        }
    }
}

BKModelBin *baModel_getModelBin(void){
    return baModelBin;
}

enum asset_e baModel_getModelId(void){
    return baModelId;
}

void baModel_setEnvAlpha(s32 alpha){
    baModelEnvAlpha = alpha;
}

void baModel_set(enum asset_e asset_id){
    if(asset_id != baModelId){
        if(baModelBin){
            func_80254008();
            assetcache_release(baModelBin);
            baModelBin = NULL;
        }
        baModelId = asset_id;
        if(baModelId)
            baModelBin = assetcache_get(baModelId);
    }
}

void baModel_80292048(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_8037C130[arg0][2] = arg1;
    D_8037C130[arg0][3] = arg2;
    D_8037C130[arg0][1] = arg3;
}

void baModel_80292078(s32 arg0, f32 arg1){
    D_8037C130[arg0][0] = arg1; 
}

void baModel_setDirection(enum player_model_direction_e direction){
    if(direction != baModelDirection){
        if(direction == PLAYER_MODEL_DIR_KAZOOIE || PLAYER_MODEL_DIR_KAZOOIE == baModelDirection){
            //flip model
            yaw_setIdeal(mlNormalizeAngle(yaw_get() + 180.0f));
            yaw_applyIdeal();
        }
    }
    baModelDirection = direction;
}

void baModel_setScale(f32 scale){
    if(osCicId + -6103){
        scale = scale*0.25;
    }
    baModelScale = scale;
}

void baModel_setYaw(f32 angleDegrees){
   baModelYaw = mlNormalizeAngle(angleDegrees);
}

void baModel_80292158(f32 arg0){
    D_8037C100[1] = arg0;
    baModel_8029217C(arg0);
}

void baModel_8029217C(f32 arg0){
    D_8037C110[1] = arg0;
}

void baModel_setPostDraw(void (*draw_func)(Gfx **gfx, Mtx **mtx, Vtx **vtx)){
    baModelPostDrawMethod = draw_func;
}

void baModel_setDisplacement(f32 arg0[3]){
    ml_vec3f_copy(baModelDisplacement, arg0);
}

void baModel_setYDisplacement(f32 arg0){
    baModelDisplacement[1] = arg0;
}

void baModel_setVisible(s32 arg0){
    baModelIsVisible = arg0;
}

void baModel_802921D4(f32 arg0[3]){
    if(player_getWaterState() == BSWATERGROUP_0_NONE){
        D_8037C150.unk0 = 1;
        TUPLE_COPY(D_8037C150.unk4, arg0)
    }
}

f32 baModel_getYaw(void){
    return baModelYaw;
}

f32 baModel_80292230(void){
    return D_8037C100[1];
}

void baModel_8029223C(f32 arg0[3]){
    baModel_80291A50(8, arg0);
}

void baModel_80292260(f32 arg0[3]){
    baModel_80291A50(7, arg0);
}

void baModel_80292284(f32 arg0[3], s32 arg1){
    f32 sp44[3];
    f32 sp38[3];

    if(baMarker_get()->unk14_21 && baModelIsVisible){
        switch(baModel_getModelId()){
            case ASSET_34D_MODEL_BANJOKAZOOIE_LOW_POLY:
            case ASSET_34E_MODEL_BANJOKAZOOIE_HIGH_POLY:
            case ASSET_34F_MODEL_BANJO_TERMITE: //802922E8
            case ASSET_359_MODEL_BANJO_WALRUS: //802922E8
            case ASSET_362_MODEL_BANJO_BEE:
            case ASSET_36F_MODEL_BANJO_PUMPKIN:
            case ASSET_374_MODEL_BANJO_CROC:
                func_8034A174(D_80363780, arg1 + 1, arg0);
                if(ml_isZero_vec3f(arg0)){
                    playerPosition_get(arg0);
                }
                
                arg0[1] += D_8037C130[arg1][0];
                if(D_8037C130[arg1][1] != 0.0f){
                    func_80256E24(sp44, D_8037C130[arg1][2],  mlNormalizeAngle(yaw_get() + D_8037C130[arg1][3]), 0.0f, 0.0f, D_8037C130[arg1][1]);
                    arg0[0] += sp44[0]; 
                    arg0[1] += sp44[1]; 
                    arg0[2] += sp44[2]; 
                }
                baphysics_get_position_change(sp38);
                arg0[0] = arg0[0] + sp38[0];
                arg0[1] = arg0[1] + sp38[1];
                arg0[2] = arg0[2] + sp38[2];
                break;
            default: ////80292400
                playerPosition_get(arg0);
                break;
        }
    }
    else{//L80292410
        playerPosition_get(arg0);
        if(arg1){
            arg0[1] += 33.0f;
        }
        else{
            arg0[1] += 75.0f;
        }
    }
}

void baModel_getPosition(f32* dst){
    f32 tmp1[3];
    f32 tmp2[3];
    baModel_80291A50(5,tmp1);
    baModel_80291A50(6,tmp2);
    ml_vec3f_add(dst, tmp1, tmp2);
    ml_vec3f_scale(dst, 0.5);
}

void baModel_802924B8(f32 arg0[3]){
    baModel_80291A50(0xA, arg0);
}

enum player_model_direction_e baModel_getDirection(void){
    return baModelDirection;
}

void baModel_802924E8(f32 arg0[3]){
    switch(player_getTransformation()){
        case TRANSFORM_5_CROC:
            baModel_80291A50(5, arg0);
            break;
        case TRANSFORM_4_WALRUS: //L80292520
            baModel_80291A50(0xB, arg0);
            break;
        default: //L80292530
            baModel_80291A50(0x9, arg0);
            break;
    }
}

s32 baModel_isVisible(void){
    return baModelIsVisible;
}

void baModel_80292554(f32 arg0[3]){
    baModel_80291A50(0x9, arg0);
}

void baModel_80292578(f32 arg0[3]){
    baModel_80291A50(0xA, arg0);
}

void baModel_defrag(void){
    if(D_80363780){
        D_80363780 = func_8034A348(D_80363780);
    }
}
