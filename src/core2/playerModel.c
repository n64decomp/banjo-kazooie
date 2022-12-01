#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "core2/playerModel.h"

void func_80254008(void);
extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
void assetcache_release(void *); //assetcache_free
extern void ml_vec3f_assign(f32[3], f32, f32, f32);
void func_8033A280(f32);

extern s32 osCicId;

/* .data */
struct5Bs *D_80363780 = NULL;

/* .bss */
void *playerModelBin; //playerModelPtr
s16 playerModelId; //playerModel asset_id
u8  playerModelEnvAlpha;
u8  playerModelDirection;
u8  playerModelIsVisible;
f32 playerModelScale;
f32 playerModelPitch;
f32 playerModelRoll;
f32 playerModelYaw;
f32 D_8037C100[3];
f32 D_8037C110[3];
f32 playerModelDisplacement[3];
void (*playerModelPostDrawMethod)(Gfx **gfx, Mtx **mtx, Vtx **vtx);
f32 D_8037C130[2][4];
struct {
    u8 unk0;
    f32 unk4[3]; 
} D_8037C150;

//public
void playerModel_set(enum asset_e asset_id);

//.data
static void _playerModel_updateModelYaw(void){
    switch(playerModelDirection){
        case PLAYER_MODEL_DIR_KAZOOIE:
            playerModelYaw = mlNormalizeAngle(yaw_get() + 180.0f);
            break;
        default:
            playerModelYaw = yaw_get();
            break;
        case PLAYER_MODEL_DIR_GLOBAL:
            break;
    }
}

void playerModel_80291A50(s32 arg0, f32 arg1[3]){
    func_8034A174(D_80363780, arg0, arg1);
    if(func_802582EC(arg1)){
        _player_getPosition(arg1);
    }
}

int playerModel_80291AAC(s32 arg0, s32 arga, s32 arg2, s32 arg3){
    return 0;
}

static void _playerModel_preDraw(int arg0){
    _player_getMarker()->unk14_21 = 1;
}

void playerModel_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 rotation[3];
    s32 env_color[3];
    f32 plyr_pos[3]; //sp44
    f32 sp38[3];

    if(!playerModelIsVisible)
        return;

    _playerModel_updateModelYaw();
    playerModelRoll = roll_get();
    playerModelPitch = pitch_get();
    _player_getPosition(plyr_pos);
    plyr_pos[1] += 2.0f;
    ml_vec3f_assign(rotation, playerModelPitch, playerModelYaw, playerModelRoll);
    func_8029A47C(env_color);
    ml_vec3f_copy(sp38, D_8037C100);

    plyr_pos[0] += playerModelDisplacement[0];\
    plyr_pos[1] += playerModelDisplacement[1];\
    plyr_pos[2] += playerModelDisplacement[2];

    sp38[0] += playerModelDisplacement[0];\
    sp38[1] += playerModelDisplacement[1];\
    sp38[2] += playerModelDisplacement[2];

    if(playerModelBin){
        func_80289F30();
        func_8029DD6C();
        modelRender_setEnvColor(env_color[0], env_color[1], env_color[2], playerModelEnvAlpha);
        func_8033A280(2.0f);
        modelRender_preDraw((GenMethod_1)_playerModel_preDraw, 0);
        func_8033A450(D_80363780);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        if(D_8037C150.unk0){
            D_8037C150.unk0 = 0;
            modelRender_draw(gfx, mtx, D_8037C150.unk4, rotation, playerModelScale, sp38, playerModelBin);
        }
        else{
            modelRender_draw(gfx, mtx, plyr_pos, rotation, playerModelScale, sp38, playerModelBin);
        }
    }//L80291CD4

    if(playerModelPostDrawMethod){
        playerModelPostDrawMethod(gfx, mtx, vtx);
    }
}

void playerModel_updateModel(void){
    playerModel_set(func_802985F0());
}

void playerModel_reset(void){
    f32 plyr_pos[3];
    int i;
    for(i = 0; i < 2 ; i++){
        playerModel_80292048(i, 0.0f, 0.0f, 0.0f);
        playerModel_80292078(i, 0.0f);
    }
    playerModelEnvAlpha = 0xFF;
    playerModelBin = NULL;
    playerModelId = 0;
    playerModelPostDrawMethod = NULL;
    D_80363780 = func_8034A2C8();
    func_8034A130(D_80363780);
    ml_vec3f_clear(D_8037C100);
    ml_vec3f_clear(D_8037C110);
    ml_vec3f_clear(playerModelDisplacement);
    playerModelYaw = playerModelRoll = playerModelPitch = 0.0f;
    D_8037C150.unk0 = 0;
    playerModel_setVisible(TRUE);
    playerModel_setScale(1.0f);
    playerModelDirection = 0;
    playerModel_setDirection(PLAYER_MODEL_DIR_BANJO);
    if(!func_8028ADB4())
        playerModel_updateModel();
    player_getPosition(plyr_pos);
    func_802C3F04((GenMethod_4)func_802C4140, 
        ACTOR_17_PLAYER_SHADOW, 
        reinterpret_cast(s32, plyr_pos[0]), 
        reinterpret_cast(s32, plyr_pos[1]), 
        reinterpret_cast(s32, plyr_pos[2])
    );
}

void playerModel_free(void){
    assetcache_release(playerModelBin);
    playerModelBin = NULL;
    playerModelId = 0;
    func_8034A2A8(D_80363780);
    D_80363780 = NULL;
}

void playerModel_update(void){
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
            _player_getMarker()->unk14_21 = 0;
        }
    }
}

BKModelBin *playerModel_getModelBin(void){
    return playerModelBin;
}

enum asset_e playerModel_getModelId(void){
    return playerModelId;
}

void playerModel_setEnvAlpha(s32 alpha){
    playerModelEnvAlpha = alpha;
}

void playerModel_set(enum asset_e asset_id){
    if(asset_id != playerModelId){
        if(playerModelBin){
            func_80254008();
            assetcache_release(playerModelBin);
            playerModelBin = NULL;
        }
        playerModelId = asset_id;
        if(playerModelId)
            playerModelBin = assetcache_get(playerModelId);
    }
}

void playerModel_80292048(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_8037C130[arg0][2] = arg1;
    D_8037C130[arg0][3] = arg2;
    D_8037C130[arg0][1] = arg3;
}

void playerModel_80292078(s32 arg0, f32 arg1){
    D_8037C130[arg0][0] = arg1; 
}

void playerModel_setDirection(enum player_model_direction_e direction){
    if(direction != playerModelDirection){
        if(direction == PLAYER_MODEL_DIR_KAZOOIE || PLAYER_MODEL_DIR_KAZOOIE == playerModelDirection){
            //flip model
            yaw_setIdeal(mlNormalizeAngle(yaw_get() + 180.0f));
            yaw_applyIdeal();
        }
    }
    playerModelDirection = direction;
}

void playerModel_setScale(f32 scale){
    if(osCicId + -6103){
        scale = scale*0.25;
    }
    playerModelScale = scale;
}

void playerModel_setYaw(f32 angleDegrees){
   playerModelYaw = mlNormalizeAngle(angleDegrees);
}

void playerModel_80292158(f32 arg0){
    D_8037C100[1] = arg0;
    playerModel_8029217C(arg0);
}

void playerModel_8029217C(f32 arg0){
    D_8037C110[1] = arg0;
}

void playerModel_setPostDraw(void (*draw_func)(Gfx **gfx, Mtx **mtx, Vtx **vtx)){
    playerModelPostDrawMethod = draw_func;
}

void playerModel_setDisplacement(f32 arg0[3]){
    ml_vec3f_copy(playerModelDisplacement, arg0);
}

void playerModel_setYDisplacement(f32 arg0){
    playerModelDisplacement[1] = arg0;
}

void playerModel_setVisible(s32 arg0){
    playerModelIsVisible = arg0;
}

void playerModel_802921D4(f32 arg0[3]){
    if(func_8028EE84() == BSWATERGROUP_0_NONE){
        D_8037C150.unk0 = 1;
        D_8037C150.unk4[0] = arg0[0];
        D_8037C150.unk4[1] = arg0[1];
        D_8037C150.unk4[2] = arg0[2];
    }
}

f32 playerModel_getYaw(void){
    return playerModelYaw;
}

f32 playerModel_80292230(void){
    return D_8037C100[1];
}

void playerModel_8029223C(f32 arg0[3]){
    playerModel_80291A50(8, arg0);
}

void playerModel_80292260(f32 arg0[3]){
    playerModel_80291A50(7, arg0);
}

void playerModel_80292284(f32 arg0[3], s32 arg1){
    f32 sp44[3];
    f32 sp38[3];

    if(_player_getMarker()->unk14_21 && playerModelIsVisible){
        switch(playerModel_getModelId()){
            case 0x34D:
            case 0x34E:
            case ASSET_34F_MODEL_BANJO_TERMITE: //802922E8
            case ASSET_359_MODEL_BANJO_WALRUS: //802922E8
            case ASSET_362_MODEL_BANJO_BEE:
            case ASSET_36F_MODEL_BANJO_PUMPKIN:
            case ASSET_374_MODEL_BANJO_CROC:
                func_8034A174(D_80363780, arg1 + 1, arg0);
                if(func_802582EC(arg0)){
                    _player_getPosition(arg0);
                }
                
                arg0[1] += D_8037C130[arg1][0];
                if(D_8037C130[arg1][1] != 0.0f){
                    func_80256E24(sp44, D_8037C130[arg1][2],  mlNormalizeAngle(yaw_get() + D_8037C130[arg1][3]), 0.0f, 0.0f, D_8037C130[arg1][1]);
                    arg0[0] += sp44[0]; 
                    arg0[1] += sp44[1]; 
                    arg0[2] += sp44[2]; 
                }
                func_802976C0(sp38);
                arg0[0] = arg0[0] + sp38[0];
                arg0[1] = arg0[1] + sp38[1];
                arg0[2] = arg0[2] + sp38[2];
                break;
            default: ////80292400
                _player_getPosition(arg0);
                break;
        }
    }
    else{//L80292410
        _player_getPosition(arg0);
        if(arg1){
            arg0[1] += 33.0f;
        }
        else{
            arg0[1] += 75.0f;
        }
    }
}

void playerModel_getPosition(f32* dst){
    f32 tmp1[3];
    f32 tmp2[3];
    playerModel_80291A50(5,tmp1);
    playerModel_80291A50(6,tmp2);
    ml_vec3f_add(dst, tmp1, tmp2);
    ml_vec3f_scale(dst, 0.5);
}

void playerModel_802924B8(f32 arg0[3]){
    playerModel_80291A50(0xA, arg0);
}

enum player_model_direction_e playerModel_getDirection(void){
    return playerModelDirection;
}

void playerModel_802924E8(f32 arg0[3]){
    switch(player_getTransformation()){
        case TRANSFORM_5_CROC:
            playerModel_80291A50(5, arg0);
            break;
        case TRANSFORM_4_WALRUS: //L80292520
            playerModel_80291A50(0xB, arg0);
            break;
        default: //L80292530
            playerModel_80291A50(0x9, arg0);
            break;
    }
}

s32 playerModel_isVisible(void){
    return playerModelIsVisible;
}

void playerModel_80292554(f32 arg0[3]){
    playerModel_80291A50(0x9, arg0);
}

void playerModel_80292578(f32 arg0[3]){
    playerModel_80291A50(0xA, arg0);
}

void playerModel_defrag(void){
    if(D_80363780){
        D_80363780 = func_8034A348(D_80363780);
    }
}
