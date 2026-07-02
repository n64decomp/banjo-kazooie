#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void modelAppendages_setKazooiesUpperHalfVisibility(bool);
void modelAppendages_setKazooiesFeetAndShoesVisibility(bool);
void modelAppendages_setKazooiesAssVisibility(bool);
void modelAppendages_setBanjosLeftEyeVisibility(f32);
void modelAppendages_setBanjosRightEyeVisibility(f32);
void modelAppendages_setTurboTrainersVisibility(bool);
void modelAppendages_setWadingBootsVisibility(bool);
void modelAppendages_setSledVisibility(bool);

/* .bss */
f32 showKazooiesUpperHalfModelTimer; // Only used in bFlap
u8  showKazooiesUpperHalfModelNext; // Only used in bFlap
u8  showKazooieAssModel;
u8  showKazooieFeetAndShoesModel;
u8  hideTurboTrainersModel;
u8  showKazooiesUpperHalfModel;
u8  hideWadingBootsModel;
u8  showSledModel;
f32 showBanjosLeftEye;
f32 showBanjosRightEye;

/* .code */
// Kazooie & Bee do not blink
// Wishywashy's eyes blink together
void modelAppendages_loadBlinkingEyes(void){
    s32 is_model_visible;
    switch(baModel_getModelId()){
        case ASSET_34D_MODEL_BANJOKAZOOIE_LOW_POLY: //L8029DC24
        case ASSET_34E_MODEL_BANJOKAZOOIE_HIGH_POLY: //L8029DC24
            is_model_visible = (s32) ml_interpolate_f(showBanjosLeftEye, 1.0f, 8.0f);
            modelRender_setAppendageVisibility(0x1B, is_model_visible);
            modelRender_setAppendageVisibility(0x1D, is_model_visible);
            modelRender_setAppendageVisibility(0x1F, is_model_visible);
            modelRender_setAppendageVisibility(0x21, is_model_visible);
            is_model_visible = (s32) ml_interpolate_f(showBanjosRightEye, 1.0f, 8.0f);
            modelRender_setAppendageVisibility(0x1A, is_model_visible);
            modelRender_setAppendageVisibility(0x1C, is_model_visible);
            modelRender_setAppendageVisibility(0x1E, is_model_visible);
            modelRender_setAppendageVisibility(0x20, is_model_visible);
            break;

        case ASSET_34F_MODEL_BANJO_TERMITE: //L8029DCCC
        case ASSET_359_MODEL_BANJO_WALRUS: //L8029DCCC
        case ASSET_36F_MODEL_BANJO_PUMPKIN: //L8029DCCC
        case ASSET_374_MODEL_BANJO_CROC: //L8029DCCC
            modelRender_setAppendageVisibility(0x1B, (s32) ml_interpolate_f(showBanjosLeftEye, 1.0f, 6.0f));
            modelRender_setAppendageVisibility(0x1A, (s32) ml_interpolate_f(showBanjosRightEye, 1.0f, 6.0f));
            break;

        case ASSET_356_MODEL_BANJO_WISHYWASHY: //L8029DD2C
            modelRender_setAppendageVisibility(1, (s32) ml_interpolate_f(showBanjosRightEye, 1.0f, 4.0f));
            break;
    }
}

// This includes Kazooie, the shoes, and the sled
void modelAppendages_loadAppendage(void) {
    bool is_model_visible;

    modelRender_func_8033A1FC();
    switch (baModel_getModelId()) {
        case ASSET_34D_MODEL_BANJOKAZOOIE_LOW_POLY:
        case ASSET_34E_MODEL_BANJOKAZOOIE_HIGH_POLY:
            /* Kazooie's Upper Half */
            modelRender_setAppendageVisibility(0x1, showKazooiesUpperHalfModel);
            modelRender_setAppendageVisibility(0x9, showKazooiesUpperHalfModel);
            modelRender_setAppendageVisibility(0xC, showKazooiesUpperHalfModel);
            modelRender_setAppendageVisibility(0xF, showKazooiesUpperHalfModel);
            /* Kazooie's Legs & Shoes */
            modelRender_setAppendageVisibility(0x2, showKazooieFeetAndShoesModel);
            modelRender_setAppendageVisibility(0xA, showKazooieFeetAndShoesModel);
            modelRender_setAppendageVisibility(0xD, showKazooieFeetAndShoesModel);
            modelRender_setAppendageVisibility(0x10, showKazooieFeetAndShoesModel);
            /* Kazooie's Ass */
            modelRender_setAppendageVisibility(0x8, showKazooieAssModel);
            modelRender_setAppendageVisibility(0xB, showKazooieAssModel);
            modelRender_setAppendageVisibility(0xE, showKazooieAssModel);
            modelRender_setAppendageVisibility(0x11, showKazooieAssModel);
            /* Turbo Talon Trainer */
            is_model_visible = hideTurboTrainersModel + 1;
            modelRender_setAppendageVisibility(0x12, is_model_visible);
            modelRender_setAppendageVisibility(0x14, is_model_visible);
            modelRender_setAppendageVisibility(0x16, is_model_visible);
            modelRender_setAppendageVisibility(0x18, is_model_visible);
            modelRender_setAppendageVisibility(0x13, is_model_visible);
            modelRender_setAppendageVisibility(0x15, is_model_visible);
            modelRender_setAppendageVisibility(0x17, is_model_visible);
            modelRender_setAppendageVisibility(0x19, is_model_visible);
            /* Wading Boots */
            is_model_visible = hideWadingBootsModel + 1;
            modelRender_setAppendageVisibility(0x22, is_model_visible);
            modelRender_setAppendageVisibility(0x24, is_model_visible);
            modelRender_setAppendageVisibility(0x26, is_model_visible);
            modelRender_setAppendageVisibility(0x28, is_model_visible);
            modelRender_setAppendageVisibility(0x23, is_model_visible);
            modelRender_setAppendageVisibility(0x25, is_model_visible);
            modelRender_setAppendageVisibility(0x27, is_model_visible);
            modelRender_setAppendageVisibility(0x29, is_model_visible);
            break;
        case ASSET_359_MODEL_BANJO_WALRUS:
            /* Sled */
            modelRender_setAppendageVisibility(0x3, showSledModel);
            break;
        case ASSET_374_MODEL_BANJO_CROC:
            /* Turbo Talon Trainer */
            is_model_visible = hideTurboTrainersModel + 1;
            modelRender_setAppendageVisibility(0x4, is_model_visible);
            modelRender_setAppendageVisibility(0x5, is_model_visible);
            modelRender_setAppendageVisibility(0x6, is_model_visible);
            modelRender_setAppendageVisibility(0x7, is_model_visible);
            break;
    }
    modelAppendages_loadBlinkingEyes();
}

bool modelAppendages_showKazooiesAss(void){
    return showKazooieAssModel;
}

bool modelAppendages_showKazooiesFeetAndShoes(void){
    return showKazooieFeetAndShoesModel;
}

bool modelAppendages_showKazooiesUpperHalf(void){
    return showKazooiesUpperHalfModel;
}

f32 modelAppendages_showBanjosLeftEye(void){
    return showBanjosLeftEye;
}

f32 modelAppendages_showBanjosRightEye(void){
    return showBanjosRightEye;
}

bool modelAppendages_hideTurboTrainers(void){
    return hideTurboTrainersModel;
}

bool modelAppendages_hideWadingBoots(void){
    return hideWadingBootsModel;
}

void modelAppendages_reset(void) {
    modelAppendages_setKazooiesUpperHalfVisibility(FALSE);
    modelAppendages_setKazooiesFeetAndShoesVisibility(FALSE);
    modelAppendages_setKazooiesAssVisibility(FALSE);
    modelAppendages_setBanjosLeftEyeVisibility(0.0f);
    modelAppendages_setBanjosRightEyeVisibility(0.0f);
    modelAppendages_setTurboTrainersVisibility(FALSE);
    modelAppendages_setWadingBootsVisibility(FALSE);
    modelAppendages_setSledVisibility(FALSE);
}

void modelAppendages_setKazooiesAssVisibility(bool show_model){
    showKazooieAssModel = show_model;
}

void modelAppendages_setKazooiesFeetAndShoesVisibility(bool show_model){
    showKazooieFeetAndShoesModel = show_model;
}

void modelAppendages_setKazooiesUpperHalfVisibility(bool show_model) {
    modelAppendages_setKazooiesUpperHalfVisibilityAndTimer(show_model, 0.0f);
}

// Timer only set in bFlap
void modelAppendages_setKazooiesUpperHalfVisibilityAndTimer(bool show_model, f32 timer) {
    showKazooiesUpperHalfModelTimer = timer;
    showKazooiesUpperHalfModelNext = show_model;
    if (timer == 0.0f) {
        showKazooiesUpperHalfModel = show_model;
    }
}

void modelAppendages_setBanjosLeftEyeVisibility(f32 show_model){
    showBanjosLeftEye = show_model;
}

void modelAppendages_setBanjosRightEyeVisibility(f32 show_model){
    showBanjosRightEye = show_model;
}

void modelAppendages_setTurboTrainersVisibility(bool hide_model){
    hideTurboTrainersModel = hide_model;
}

void modelAppendages_setSledVisibility(bool show_model){
    showSledModel = show_model;
}

void modelAppendages_setWadingBootsVisibility(bool hide_model){
    hideWadingBootsModel = hide_model;
}

void modelAppendages_kazooiesUpperHalfVisibilityTimer(void) {
    if (showKazooiesUpperHalfModelTimer != 0.0f) {
        showKazooiesUpperHalfModelTimer -= time_getDelta();
        if (showKazooiesUpperHalfModelTimer <= 0.0f) {
            showKazooiesUpperHalfModel = showKazooiesUpperHalfModelNext;
        }
    }
}
