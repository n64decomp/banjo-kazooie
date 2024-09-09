#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8028E82C(void);

Actor *func_802CA7BC(ActorMarker *, Gfx **, Mtx **, Vtx **);
void func_802CA92C(Actor *this);

/* .data */
ActorInfo D_80366EF0 = { 
    MARKER_32_PLAYER_SHADOW, ACTOR_17_PLAYER_SHADOW, ASSET_3BF_MODEL_PLAYER_SHADOW, 
    0x1, 0x0, 
    func_802CA92C, func_80326224, func_802CA7BC, 
    0, 0, 0.0f, 0
};

/* .code */
void func_802CA790(Actor *this){
    modelRender_setAlpha(0xff);
    modelRender_setDepthMode(MODEL_RENDER_DEPTH_COMPARE);
}

Actor *func_802CA7BC(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this;
    f32 sp60;
    f32 sp54[3];
    f32 rotation[3];
    f32 sp44;
    f32 sp40;
    f32 sp34[3];
    
    sp60 = (player_getWaterState() == BSWATERGROUP_2_UNDERWATER) ? 8.0f : 4.0f;
    this = marker_getActor(marker);
    if( !func_8028F070()
        || !func_8028F150()
        || !func_8028F2DC()
    ){
        return this;
    }

    player_getPosition(sp54);
    sp40 = func_8028E82C();
    func_8028E84C(sp34);
    this->position_x = sp54[0];
    this->position_y = sp40 + sp60;
    this->position_z = sp54[2];

    func_80258108(sp34, &this->yaw, &this->pitch);

    rotation[0] = this->pitch;
    rotation[1] = this->yaw;
    rotation[2] = this->roll;
    sp44 = ml_map_f(sp54[1] - sp40, 0.0f, 300.0f, 0.43f, 0.28f);
    modelRender_preDraw((GenFunction_1)func_802CA790, (s32)this);
    modelRender_draw(gfx, mtx, this->position, rotation, sp44, NULL, marker_loadModelBin(marker));
    return this;
}


void func_802CA92C(Actor *this){
    f32 sp34[3];
    f32 sp28[3];
    this->marker->collidable = FALSE;
    player_getPosition(this->position);
    viewport_getPosition_vec3f(sp34);
    ml_vec3f_diff_copy(sp28, sp34, this->position);
    ml_vec3f_set_length_copy(sp28, sp28, 180.0f);
    this->position_x += sp28[0];
    this->position_y += sp28[1];
    this->position_z += sp28[2];
}
