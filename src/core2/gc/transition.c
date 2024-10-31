#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "gc/gctransition.h"

void anctrl_setAnimTimer(AnimCtrl*, f32);
void func_8025AC20(s32, s32, s32, f32, char*, s32);

typedef enum {
    TRANSITION_ID_1_BLACK_IN = 1,
    TRANSITION_ID_2_BLACK_OUT,
    TRANSITION_ID_3_CIRCLE_IN,
    TRANSITION_ID_4_CIRCLE_OUT,
    TRANSITION_ID_5_JIGGY_IN,
    TRANSITION_ID_6_JIGGY_OUT,
    TRANSITION_ID_7,
    TRANSITION_ID_8_WHITE_IN,
    TRANSITION_ID_9_WHITE_OUT,
    TRANSITION_ID_A_WITCH_HEAD_OUT,
    TRANSITION_ID_B_CIRCLE_IN_FAST,
    TRANSITION_ID_C_CIRCLE_OUT_FAST,
    TRANSITION_ID_D,
    TRANSITION_ID_E_CIRCLE_IN_SLOW,
    TRANSITION_ID_F_CIRCLE_OUT_SLOW,
    TRANSITION_ID_10_FALLING_PIECES_IN,
    TRANSITION_ID_11_FALLING_PIECES_OUT,
    TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,
    TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW,
    TRANSITION_ID_14_CIRCLE_IN_SUPER_SLOW,
    TRANSITION_ID_15_CIRCLE_OUT_SUPER_SLOW
} TransitionId;

typedef enum {
    TRANSITION_STATE_0_NONE,
    TRANSITION_STATE_1_LOADING,
    TRANSITION_STATE_2_BLACK_IN,
    TRANSITION_STATE_3_BLACK_OUT,
    TRANSITION_STATE_4_FADE_IN,
    TRANSITION_STATE_5_FADE_OUT,
    TRANSITION_STATE_6_LOADING_WHITE,
    TRANSITION_STATE_7_WHITE_IN,
    TRANSITION_STATE_8_WHITE_OUT
} TransitionState;

typedef struct {
    u8 uid;
    u8 state;
    u8 next_state;
    // u8 pad3[1];
    f32 duration;
    s32 model_index;
    s32 anim_index;
    f32 scale;
}TransitionInfo;

typedef struct {
    u8 map_indx;
    u8 in_index;
    u8 out_index;
}MapTransitionInfo;

/* .data */
TransitionInfo D_8036C150[0x16]= {
    {TRANSITION_ID_1_BLACK_IN,               TRANSITION_STATE_2_BLACK_IN,  TRANSITION_STATE_0_NONE,          0.1f, 0, 0, 0.0f},
    {TRANSITION_ID_2_BLACK_OUT,              TRANSITION_STATE_3_BLACK_OUT, TRANSITION_STATE_1_LOADING,       0.1f, 0, 0, 0.0f},
    {TRANSITION_ID_3_CIRCLE_IN,              TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          0.5f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_4_CIRCLE_OUT,             TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       0.5f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_5_JIGGY_IN,               TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          2.5f, ASSET_7D0_MODEL_TRANSITION_JIGGY,   0,  3.5f},
    {TRANSITION_ID_6_JIGGY_OUT,              TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       0.9f, ASSET_7D0_MODEL_TRANSITION_JIGGY,   0,  3.5f},
    {TRANSITION_ID_7,                        TRANSITION_STATE_0_NONE,      TRANSITION_STATE_0_NONE,          0.0f, 0, 0, 0.0f},
    {TRANSITION_ID_8_WHITE_IN,               TRANSITION_STATE_7_WHITE_IN,  TRANSITION_STATE_0_NONE,          1.1f, 0, 0, 0.0f},
    {TRANSITION_ID_9_WHITE_OUT,              TRANSITION_STATE_8_WHITE_OUT, TRANSITION_STATE_6_LOADING_WHITE, 0.7f, 0, 0, 0.0f},
    {TRANSITION_ID_A_WITCH_HEAD_OUT,         TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       3.5f, ASSET_7D4_MODEL_TRANSITION_WITCH,   0,  3.7f},
    {TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          0.3f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_C_CIRCLE_OUT_FAST,        TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       0.3f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_D,                        TRANSITION_STATE_2_BLACK_IN,  TRANSITION_STATE_0_NONE,          0.6f, 0, 0, 0.0f},
    {TRANSITION_ID_E_CIRCLE_IN_SLOW,         TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_F_CIRCLE_OUT_SLOW,        TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_10_FALLING_PIECES_IN,     TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          2.5f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {TRANSITION_ID_11_FALLING_PIECES_OUT,    TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       2.0f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          1.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW, TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       1.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_14_CIRCLE_IN_SUPER_SLOW,  TRANSITION_STATE_5_FADE_OUT,  TRANSITION_STATE_1_LOADING,       2.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_15_CIRCLE_OUT_SUPER_SLOW, TRANSITION_STATE_4_FADE_IN,   TRANSITION_STATE_0_NONE,          2.2f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    0
};

TransitionInfo D_8036C308[0xC] = {
    {TRANSITION_ID_A_WITCH_HEAD_OUT,        TRANSITION_STATE_5_FADE_OUT,     TRANSITION_STATE_1_LOADING,         3.5f, ASSET_7D4_MODEL_TRANSITION_WITCH, 0, 3.7f},
    {TRANSITION_ID_10_FALLING_PIECES_IN,    TRANSITION_STATE_4_FADE_IN,      TRANSITION_STATE_0_NONE,            2.5f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {TRANSITION_ID_11_FALLING_PIECES_OUT,   TRANSITION_STATE_5_FADE_OUT,     TRANSITION_STATE_1_LOADING,         2.0f, ASSET_467_MODEL_TRANSITION_FALLING_JIGGIES, ASSET_1F5_ANIM_TRANSITION_FALLING_JIGGIES, 0.269645989f},
    {TRANSITION_ID_6_JIGGY_OUT,             TRANSITION_STATE_5_FADE_OUT,     TRANSITION_STATE_1_LOADING,         0.9f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0, 3.5f},
    {TRANSITION_ID_5_JIGGY_IN,              TRANSITION_STATE_4_FADE_IN,      TRANSITION_STATE_0_NONE,            2.5f, ASSET_7D0_MODEL_TRANSITION_JIGGY, 0, 3.5f},
    {TRANSITION_ID_9_WHITE_OUT,             TRANSITION_STATE_8_WHITE_OUT,    TRANSITION_STATE_6_LOADING_WHITE,   0.7f, 0, 0, 0.0f},
    {TRANSITION_ID_8_WHITE_IN,              TRANSITION_STATE_7_WHITE_IN,     TRANSITION_STATE_0_NONE,            0.7f, 0, 0, 0.0f},
    {TRANSITION_ID_E_CIRCLE_IN_SLOW,        TRANSITION_STATE_4_FADE_IN,      TRANSITION_STATE_0_NONE,            1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_F_CIRCLE_OUT_SLOW,       TRANSITION_STATE_5_FADE_OUT,     TRANSITION_STATE_1_LOADING,         1.0f, ASSET_7CF_MODEL_TRANSITION_UNKNOWN, 0, 25.0f},
    {TRANSITION_ID_7,                       TRANSITION_STATE_0_NONE,         TRANSITION_STATE_0_NONE,            0.0f, 0, 0, 0.0f},
    {TRANSITION_ID_8_WHITE_IN,              TRANSITION_STATE_7_WHITE_IN,     TRANSITION_STATE_0_NONE,            1.1f, 0, 0, 0.0f},
    {TRANSITION_ID_9_WHITE_OUT,             TRANSITION_STATE_8_WHITE_OUT,    TRANSITION_STATE_6_LOADING_WHITE,   1.5f, 0, 0, 0.0f}
};

MapTransitionInfo D_8036C3F8[0x18] = {
    {MAP_20_CS_END_NOT_100,                 TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_1F_CS_START_RAREWARE,              TRANSITION_ID_15_CIRCLE_OUT_SUPER_SLOW, TRANSITION_ID_9_WHITE_OUT},
    {MAP_1E_CS_START_NINTENDO,              TRANSITION_ID_8_WHITE_IN,               TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_7D_CS_SPIRAL_MOUNTAIN_1,           TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_7E_CS_SPIRAL_MOUNTAIN_2,           TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_85_CS_SPIRAL_MOUNTAIN_3,           TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_86_CS_SPIRAL_MOUNTAIN_4,           TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_87_CS_SPIRAL_MOUNTAIN_5,           TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_88_CS_SPIRAL_MOUNTAIN_6,           TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_94_CS_INTRO_SPIRAL_7,              TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_95_CS_END_ALL_100,                 TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_98_CS_END_SPIRAL_MOUNTAIN_1,       TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_A_WITCH_HEAD_OUT},
    {MAP_99_CS_END_SPIRAL_MOUNTAIN_2,       TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_A_WITCH_HEAD_OUT},
    {MAP_7B_CS_INTRO_GL_DINGPOT_1,          TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_81_CS_INTRO_GL_DINGPOT_2,          TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_82_CS_ENTERING_GL_MACHINE_ROOM,    TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_A_WITCH_HEAD_OUT},
    {MAP_83_CS_GAME_OVER_MACHINE_ROOM,      TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_84_CS_UNUSED_MACHINE_ROOM,         TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_7C_CS_INTRO_BANJOS_HOUSE_1,        TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_C_CIRCLE_OUT_FAST},
    {MAP_89_CS_INTRO_BANJOS_HOUSE_2,        TRANSITION_ID_B_CIRCLE_IN_FAST,         TRANSITION_ID_A_WITCH_HEAD_OUT},
    {MAP_8A_CS_INTRO_BANJOS_HOUSE_3,        TRANSITION_ID_1_BLACK_IN,               TRANSITION_ID_2_BLACK_OUT},
    {MAP_96_CS_END_BEACH_1,                 TRANSITION_ID_12_CIRCLE_IN_EXTRA_SLOW,  TRANSITION_ID_13_CIRCLE_OUT_EXTRA_SLOW},
    {MAP_97_CS_END_BEACH_2,                 TRANSITION_ID_8_WHITE_IN,               TRANSITION_ID_14_CIRCLE_IN_SUPER_SLOW},
    {0,                                     TRANSITION_ID_5_JIGGY_IN,               TRANSITION_ID_6_JIGGY_OUT}
};
f32 D_8036C440 = 63.6026115f;
f32 D_8036C444 = 500.0f;


/* .bss */
struct{
    s32 unk0; //times drawn?
    TransitionInfo *transistion_info;
    u8 state;
    //u8 pad9[3]; //not needed
    void * model_ptr; //asset_ptr
    f32 rotation;
    f32 timer;
    AnimCtrl *anctrl;
    s32 substate; //times update called?
} s_current_transition;

/* .code */
TransitionInfo *_gctranstion_8030B400(s32 arg0){
    TransitionInfo * i;
    for(i = D_8036C150; i->uid != 0; i++){
        if(i->uid == arg0)
            return i;
    }
    return NULL;
}

MapTransitionInfo *_gctranstion_get_map_transition_info(s32 map_indx){
    MapTransitionInfo * i;
    for(i = D_8036C3F8; i->map_indx != 0; i++){
        if(i->map_indx == map_indx)
            return i;
    }
    return i;
}

void _gctranstion_changeState(s32 state, TransitionInfo *desc){
    if(s_current_transition.model_ptr != NULL){
        func_8033BD20(&s_current_transition.model_ptr);
    }

    if(s_current_transition.anctrl != NULL){
        anctrl_free(s_current_transition.anctrl);
        s_current_transition.anctrl = NULL;
    }
    
    s_current_transition.unk0 = 0;
    s_current_transition.transistion_info = desc;
    s_current_transition.state = state;
    s_current_transition.timer = 0.0f;
    
    //Loading screen model??
    if(state == TRANSITION_STATE_1_LOADING)
        s_current_transition.model_ptr = assetcache_get(0x7D2); //scene transition black
    else if(state == TRANSITION_STATE_6_LOADING_WHITE)
        s_current_transition.model_ptr = assetcache_get(0x7D3);  //scene transition white
    else if(desc != NULL && desc->model_index != 0)
        s_current_transition.model_ptr = assetcache_get(desc->model_index);

    //load transistion animation
    if(desc != NULL && desc->anim_index != NULL){
        s_current_transition.anctrl = anctrl_new(0);
        anctrl_reset(s_current_transition.anctrl);
        anctrl_setIndex(s_current_transition.anctrl, desc->anim_index);
        anctrl_setDuration(s_current_transition.anctrl, desc->duration);
        anctrl_setPlaybackType(s_current_transition.anctrl,  ANIMCTRL_ONCE);
        if(state == TRANSITION_STATE_5_FADE_OUT){
            anctrl_setDirection(s_current_transition.anctrl, 0);
            func_8028F7C8(1); //player_noControl(true)
            func_80335110(0); //objects_update(false)
        }
        else{
            osViBlack(1);
            anctrl_setAnimTimer(s_current_transition.anctrl, 0.25f); //set animation timer
        }
        anctrl_start(s_current_transition.anctrl, "gctransition.c", 0x125); 
    }

    if(state == TRANSITION_STATE_4_FADE_IN){
        if(func_802D4608()==0){
            comusic_playTrack(COMUSIC_4E_IN_TRANSITION);
            func_8025AC20(COMUSIC_4E_IN_TRANSITION, 0, 1000, 0.4f, "gctransition.c", 0x12d);
            func_8025AABC(COMUSIC_4E_IN_TRANSITION);
        }
    }//L8030B67C
    else if(state == TRANSITION_STATE_5_FADE_OUT){
        if(s_current_transition.transistion_info->uid == 0xA){
            func_8030E704(SFX_EB_GRUNTY_LAUGH_2);
        }
        else{
            if(func_802D4608() == 0){
                comusic_playTrack(COMUSIC_4F_OUT_TRANSITION);
                func_8025AC20(COMUSIC_4F_OUT_TRANSITION, 0, 1000, 0.2f, "gctransition.c", 0x13a);
                func_8025AABC(COMUSIC_4F_OUT_TRANSITION);
            }
        }
    }
    else if(state == TRANSITION_STATE_0_NONE){
        func_80335128(1);
        func_80335110(1);
        if(func_8028F070())
            func_8028F7C8(0);
    }
    s_current_transition.substate = 0;
}  

void gctransition_defrag(void){
    if(s_current_transition.model_ptr != NULL)
        s_current_transition.model_ptr = defrag_asset(s_current_transition.model_ptr);
}

void gctransition_draw(Gfx **gdl, Mtx **mptr, Vtx **vptr){
    f32 vp_position[3];
    f32 vp_rotation[3];
    f32 percentage;
    f32 sp58[3];
    f32 scale;

    s_current_transition.unk0++;
    if(s_current_transition.state == 0)
        return;

    viewport_backupState();
    if(s_current_transition.anctrl != NULL){
        vp_position[0] = 0.0f;
        vp_position[1] = 0.0f;
        vp_position[2] = 350.0f;
    }else{
        vp_position[0] = 0.0f;
        vp_position[1] = 0.0f;
        vp_position[2] = 300.0f;
    }

    vp_rotation[0] = 0.0f;
    vp_rotation[1] = 0.0f;
    vp_rotation[2] = 0.0f;
    viewport_setNearAndFar(D_8036C440, D_8036C444);
    viewport_setPosition_vec3f(vp_position); //viewport_getPosition_vec3f
    viewport_setRotation_vec3f(vp_rotation); //viewport_getRotation_vec3f
    viewport_update(); //camera_updateNormal
    viewport_setRenderViewportAndPerspectiveMatrix(gdl, mptr);


    sp58[0] = 0.0f;
    sp58[1] = 0.0f;
    sp58[2] = 0.0f;
    if(s_current_transition.anctrl != NULL){
        gDPSetTextureFilter((*gdl)++, G_TF_POINT);
        gDPSetColorDither((*gdl)++, G_CD_DISABLE);
        anctrl_drawSetup(s_current_transition.anctrl, sp58, 1);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
    }

    //complex animation (from animation bin file)
    if(s_current_transition.state == 1 || s_current_transition.state == 6){
        modelRender_draw(gdl, mptr, sp58, vp_rotation, 1.0f, 0, s_current_transition.model_ptr);
        if(s_current_transition.anctrl != NULL){
            gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
            gDPSetColorDither((*gdl)++, G_CD_MAGICSQ);
        }
        return;
    }


    percentage = s_current_transition.timer/(s_current_transition.transistion_info->duration);
    if(s_current_transition.state == TRANSITION_STATE_4_FADE_IN){
        //rotate and zoom in
        if(s_current_transition.transistion_info->uid == 0x10){
            scale = s_current_transition.transistion_info->scale;
            
        }
        else{
            vp_rotation[2] = s_current_transition.rotation - 90.0f*percentage;
            scale = percentage*s_current_transition.transistion_info->scale + 0.1;
        }
        modelRender_draw(gdl, mptr, sp58, vp_rotation, scale, 0, s_current_transition.model_ptr);
    }
    else if(s_current_transition.state == TRANSITION_STATE_5_FADE_OUT){//L8030B9EC
        switch (s_current_transition.transistion_info->uid)
        {
            default:
                //rotate and zoom out
                vp_rotation[2] = s_current_transition.rotation - 90.0f*percentage;
                scale = (1.0f - percentage)*s_current_transition.transistion_info->scale + 0.1;
                break;
            case 0x11:
                //static
                scale = s_current_transition.transistion_info->scale;
                break;
            case 0xA:
                //zoom out only
                vp_rotation[2] = 0.0f;
                scale = (1.0f - func_80257618(percentage))*s_current_transition.transistion_info->scale + 0.1;
                break;
        }
        if(!(s_current_transition.substate < 3) || s_current_transition.transistion_info->uid != 0x11){
            modelRender_draw(gdl, mptr, sp58, vp_rotation, scale, 0, s_current_transition.model_ptr);
        }
        else{
            modelRender_reset();
        }

    }
    else if(s_current_transition.state == TRANSITION_STATE_2_BLACK_IN){//L8030BAF4
        //fade in black (i.e. get less black)
        gcbound_reset();
        gcbound_alpha((1.0f - percentage)*255.0f + 0.5);
        gcbound_color(0,0,0);
        gcbound_draw(gdl);
    }
    else if(s_current_transition.state == TRANSITION_STATE_3_BLACK_OUT){//L8030BB6C
        //fade out black (i.e. get more black)
        gcbound_reset();
        gcbound_alpha(percentage*255.0f + 0.5);
        gcbound_color(0,0,0);
        gcbound_draw(gdl);
    }
    else if(s_current_transition.state == TRANSITION_STATE_7_WHITE_IN){//L8030BBD8
        //fade in white (i.e. get less white)
        percentage = (percentage <= 0.5)? 1.0 : 1.0 - (percentage-0.5)/0.5;
        gcbound_reset();
        gcbound_alpha(percentage*255.0f + 0.5);
        gcbound_color(0xff,0xff,0xff);
        gcbound_draw(gdl);
    }
    else if(s_current_transition.state == TRANSITION_STATE_8_WHITE_OUT){//L8030BC8C
        //fade out white (i.e. get more white)
        gcbound_reset();
        gcbound_alpha(percentage*255.0f + 0.5);
        gcbound_color(0xff,0xff,0xff);
        gcbound_draw(gdl);
    }//L8030BD00
    else{
        
    }
    if(s_current_transition.anctrl != NULL){
        gDPSetTextureFilter((*gdl)++, G_TF_BILERP);
    }
    viewport_restoreState();
    viewport_setRenderViewportAndPerspectiveMatrix(gdl, mptr);
    
}

void gctransition_8030BD4C(void){
    MapTransitionInfo *tmp_10s;
    TransitionInfo *tmp_a1;
    tmp_10s = _gctranstion_get_map_transition_info(map_get());
    tmp_a1 = _gctranstion_8030B400(tmp_10s->in_index);
   _gctranstion_changeState(tmp_a1->state, tmp_a1);
}

f32 gctransition_8030BD88(void){
    return 300.0f;
}

int gctransition_done(void){
    return s_current_transition.state == TRANSITION_STATE_0_NONE;
}

int gctransition_active(void){
    return s_current_transition.state != TRANSITION_STATE_0_NONE;
}

int gctransition_8030BDC0(void){
    return ( s_current_transition.state == TRANSITION_STATE_3_BLACK_OUT)
    || (( s_current_transition.state == TRANSITION_STATE_1_LOADING) && (s_current_transition.unk0 < 2))
    || ( s_current_transition.state == TRANSITION_STATE_5_FADE_OUT)
    || ( s_current_transition.state == TRANSITION_STATE_8_WHITE_OUT)
    || (( s_current_transition.state == TRANSITION_STATE_6_LOADING_WHITE) && (s_current_transition.unk0 < 2));
}

void gctransition_8030BE3C(void){
    _gctranstion_changeState(0, NULL);
}

void gctransition_8030BE60(void){
    TransitionInfo *tmp_a1;
    tmp_a1 = _gctranstion_8030B400(_gctranstion_get_map_transition_info(map_get())->out_index);
   func_8030C180();
   _gctranstion_changeState(tmp_a1->state, tmp_a1);
}

void gctransition_8030BEA4(s32 arg0){
    _gctranstion_changeState(D_8036C308[arg0].state, &D_8036C308[arg0]);
}

void gctransition_reset(void){
    s_current_transition.transistion_info = NULL;
    s_current_transition.state = TRANSITION_STATE_0_NONE;
    s_current_transition.model_ptr = NULL;
    s_current_transition.rotation = 0.0f;
    _gctranstion_changeState(0,0);
}

void gctransition_update(void){
    f32 dt;
    f32 tmp;
    

    dt = time_getDelta();
    if(s_current_transition.transistion_info == NULL)
        return;
    
    if(s_current_transition.anctrl != NULL){
        anctrl_update(s_current_transition.anctrl);
        if(s_current_transition.state == TRANSITION_STATE_4_FADE_IN){
            switch(s_current_transition.substate){
                case 0:
                    break;
                case 1:
                    func_8028F7C8(1);
                    func_80335110(0);
                    break;
                case 2:
                    func_80335128(0);
                    break;
                case 3:
                    func_802FEF48(s_current_transition.model_ptr); //framebuffer to model texture list
                    break;
                case 4:
                    osViBlack(0);
                    break;
                default:
                   s_current_transition.timer += dt;
                   break;
            }
        }
        else{//L8030BFEC
            switch(s_current_transition.substate){
                default:
                    s_current_transition.timer += dt;
                    break;
                case 0:
                case 1:
                    break;
                case 2:
                    func_80335128(0); 
                    func_802FEF48(s_current_transition.model_ptr); //framebuffer to model texture list
                    break;
                
            }
            
        }
    }
    else{//L8030C034
        s_current_transition.timer += dt;
    }
    if(s_current_transition.transistion_info->duration < s_current_transition.timer
        || (s_current_transition.anctrl!= NULL && anctrl_isStopped(s_current_transition.anctrl))
    ){
        s_current_transition.timer = s_current_transition.transistion_info->duration;
        //update next transition rotation
        if(s_current_transition.state == TRANSITION_STATE_4_FADE_IN || s_current_transition.state == TRANSITION_STATE_5_FADE_OUT){
            s_current_transition.rotation -= 90.0f;
            if (s_current_transition.rotation < -360.0f)
                s_current_transition.rotation += 360.0f;
            if (360.0f < s_current_transition.rotation)
                s_current_transition.rotation -= 360.0f;
        }//L8030C104
        _gctranstion_changeState(s_current_transition.transistion_info->next_state, 0);
        if(s_current_transition.state == TRANSITION_STATE_4_FADE_IN)
            func_8030C180();

        if(s_current_transition.anctrl != NULL)
            func_80334ECC();
    }
    s_current_transition.substate++;
}
