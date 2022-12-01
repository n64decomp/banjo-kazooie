#ifndef _PLAYER_MODEL_H_
#define _PLAYER_MODEL_H_

enum player_model_direction_e {
    PLAYER_MODEL_DIR_BANJO = 1,
    PLAYER_MODEL_DIR_KAZOOIE = 2,
    PLAYER_MODEL_DIR_GLOBAL = 3
};

void playerModel_80292048(s32, f32, f32, f32);
void playerModel_setDirection(enum player_model_direction_e arg0);
void playerModel_setScale(f32);
void playerModel_8029217C(f32);
void playerModel_setVisible(s32 arg0);

#endif
