#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_8024DE1C(f32, f32, f32[3], f32[3]);
extern f32 func_802EC920(BKVertexList *);
extern void func_80253208(Gfx **gdl, s32 x, s32 y, s32 w, s32 h, void *color_buffer);

extern s16 D_803A5D00[2][0xF660];
extern f32 func_802FB0E4(struct8s*);

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x8];
    s32 item_id; //item_id
    s32 model_id; //model_id
    s32 anim_id; //anim_id
    f32 anim_duration; //anim_duration
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C; //scale?
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    BKModelBin *model;
    char value_string[0xC];
    f32 unk68;
    f32 unk6C;
    AnimCtrl *anim_ctrl;
}Struct_core2_79830_0;

Struct_core2_79830_0 D_8036A2B0[] = {
    {   {0}, 0,  {0},
        ITEM_E_JIGGY, ASSET_35F_MODEL_JIGGY, 0, 0.0f,
        136.0f, 236.0f,   0.0f,  0.375f,
         28.0f, -10.0f, 300.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_18_GOLD_BULLIONS, ASSET_3C7_MODEL_GOLD_BULLION, 0, 0.0f,
        224.0f, 226.0f,  10.0f,  0.3f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_19_ORANGE, ASSET_2D2_MODEL_ORANGE, 0, 0.0f,
        224.0f, 226.0f,  25.0f,  0.4f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_1D_GRUMBLIE, ASSET_3F7_MODEL_GRUMBLIE, ASSET_12A_ANIM_GRUMBLIE_IDLE, 0.85f,
        150.0f, -20.0f,   0.0f,  0.4275f,
        200.0f, -10.0f, 100.0f, 10.0f,
         -1.0f,   1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_1E_YUMBLIE, ASSET_3F6_MODEL_YUMBLIE, ASSET_127_ANIM_YUMBLIE_IDLE, 0.85f,
        150.0f, -25.0f,   0.0f,  0.3825f,
        200.0f, -10.0f, 100.0f, 10.0f,
         -1.0f,   1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_1F_GREEN_PRESENT, ASSET_480_MODEL_XMAS_GIFT_GREEN, 0, 0.0f,
        224.0f, 226.0f,  25.0f,  0.23f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_20_BLUE_PRESENT, ASSET_47F_MODEL_XMAS_GIFT_BLUE, 0, 0.0f,
        224.0f, 226.0f,  12.0f,  0.21f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_21_RED_PRESENT, ASSET_481_MODEL_XMAS_GIFT_RED, 0, 0.0f,
        224.0f, 226.0f,  43.0f,  0.2f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_22_CATERPILLAR, ASSET_485_MODEL_CATERPILLAR, ASSET_18E_ANIM_CATERPILLAR_IDLE, 1.0f,
        224.0f, 226.0f,  12.0f,  0.28f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_23_ACORNS, ASSET_48E_MODEL_ACORN, ASSET_25B_ANIM_ACORN_IDLE, 1.0f,
        224.0f, 226.0f,  38.0f,  0.4f,
         32.0f,   0.0f, 100.0f, 20.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_24_TWINKLY_SCORE, ASSET_448_MODEL_TWINKLY_BLUE, ASSET_17C_ANIM_TWINKLY_IDLE, 1.0f,
        134.0f, -32.0f,  0.0f,  0.325f,
         24.0f, -18.0f, 100.0f, 30.0f,
         -1.0f,   1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_26_JIGGY_TOTAL, ASSET_35F_MODEL_JIGGY, 0, 0.0f,
        208.0f, 238.0f,  0.0f,  0.325f,
         29.0f, -10.0f, 300.0f, 15.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        ITEM_2B_UNKNOWN, ASSET_35F_MODEL_JIGGY, 0, 0.0f,
        208.0f, 238.0f,  0.0f,  0.325f,
         29.0f, -10.0f, 300.0f, 15.0f,
         -1.0f,  -1.0f, NULL, {'\0'}, 
          0.0f,   0.0f, NULL
    },
    {   {0}, 0,  {0},
        -1
    }
};

/* .code */
void *fxcommon3score_new(enum item_e item_id){
    Struct_core2_79830_0 *i_ptr;

    for(i_ptr = &D_8036A2B0[0]; i_ptr->item_id != -1; i_ptr++){
        if(i_ptr->item_id == item_id){
            i_ptr->unk14 = i_ptr->unk50;
            return i_ptr;
        }
    }
    return NULL;
}

void fxcommon3score_update(enum item_e arg0, void *arg1) {
    Struct_core2_79830_0 *a1 = (Struct_core2_79830_0 *)arg1;
    f32 pad28;
    f32 sp24;
    f32 sp20;

    sp24 = ((a1 - &D_8036A2B0[0]) & 1) ? -1.0f : 1.0f;
    sp20 = time_getDelta();
    switch (func_802FB0D4(a1)) {
    case 1:
        if (a1->model == NULL) {
            a1->model = assetcache_get(a1->model_id);
        }
        if ((a1->anim_id != 0) && (a1->anim_ctrl == NULL)) {
            a1->anim_ctrl = animctrl_new(0);
            animctrl_reset(a1->anim_ctrl);
            animctrl_setIndex(a1->anim_ctrl, (enum asset_e) a1->anim_id);
            animctrl_setDuration(a1->anim_ctrl, a1->anim_duration);
            func_802875AC(a1->anim_ctrl, "fxcommon3score.c", 0x74);
        }
        /* fallthrough */
    case 2:
    case 3:
        a1->unk68 += sp24 * sp20 * a1->unk48;
        if ( a1->anim_ctrl != NULL) {
            animctrl_update( a1->anim_ctrl);
        }
        break;
    case 0:
        fxcommon3score_free(arg0, a1);
        break;
    }
}

void fxcommon3score_draw(enum item_e item_id, void *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Struct_core2_79830_0 *a1 = (Struct_core2_79830_0 *)arg1;
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp40;
    f32 sp3C;
    
    sp40 = func_802FB0E4(arg1)*a1->unk54 + a1->unk34;
    if(a1->model != NULL && func_802FB0D4(arg1)){
        a1->value_string[0] = '\0';
        strIToA(a1->value_string, itemPrint_getValue(item_id));
        print_bold_spaced(a1->unk30 + a1->unk40, sp40 + a1->unk44, a1->value_string);
        sp3C = func_8024DE1C(a1->unk30, sp40, sp5C, sp68);

        sp44[0] = 0.0f;
        sp44[1] = a1->unk38;
        sp44[2] = 0.0f;

        sp50[0] = 0.0f;
        sp50[1] = a1->unk68;
        sp50[2] = 0.0f;
        func_8033A308(sp50);
        if(getGameMode() != GAME_MODE_4_PAUSED){
            modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        }
        sp68[0] += a1->unk4C;
        if(a1->unk6C == 0.0f){
            a1->unk6C = 1.1*(func_802EC920(func_8033A148(a1->model)) * a1->unk3C);
        }
        func_80253208(gfx, a1->unk30 - a1->unk6C, sp40 - a1->unk6C, 2*a1->unk6C, 2*a1->unk6C, D_803A5D00[func_8024BDA0()]);
        if(a1->anim_ctrl != NULL){
            func_8028781C(a1->anim_ctrl, sp5C, 1);
        }
        modelRender_draw(gfx, mtx, sp5C, sp68, a1->unk3C*sp3C, sp44, a1->model);
    }//L80300BA4
}

void fxcommon3score_free(enum item_e item_id, void *arg1){
    Struct_core2_79830_0 *a1 = (Struct_core2_79830_0 *)arg1;
    if(a1->anim_ctrl != NULL){
        animctrl_free(a1->anim_ctrl);
        a1->anim_ctrl = NULL;
    }

    if(a1->model != NULL){
        func_8033BD4C(a1->model);
        a1->model = NULL;
        a1->unk6C = 0.0f;
    }
}
