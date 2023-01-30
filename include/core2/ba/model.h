#ifndef _PLAYER_MODEL_H_
#define _PLAYER_MODEL_H_

enum player_model_direction_e {
    PLAYER_MODEL_DIR_BANJO = 1,
    PLAYER_MODEL_DIR_KAZOOIE = 2,
    PLAYER_MODEL_DIR_GLOBAL = 3
};

void baModel_80292048(s32, f32, f32, f32);
void baModel_setDirection(enum player_model_direction_e arg0);
void baModel_setScale(f32);
void baModel_setYDisplacement(f32);
void baModel_8029217C(f32);
void baModel_setVisible(s32 arg0);

#endif
