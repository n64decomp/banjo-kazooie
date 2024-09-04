#ifndef __BS_INT_H__
#define __BS_INT_H__

#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef void (*bsStateMethod)(void);  

enum bs_interrupt_e {
    BS_INTR_0_NONE,
    BS_INTR_1,
    BS_INTR_2,
    BS_INTR_3,
    BS_INTR_4,
    BS_INTR_5,
    BS_INTR_6,
    BS_INTR_7, //something with carried objects
    BS_INTR_8, //something with carried objects
    BS_INTR_9, //bsbfly??
    BS_INTR_A, //wishy_washy?
    BS_INTR_B,
    BS_INTR_C_CLIMB, //bsclimb?
    BS_INTR_D_SURF,
    BS_INTR_E,
    BS_INTR_F, //gv matching game, mr. vile (lose?)
    BS_INTR_10,
    BS_INTR_11_DROWN,
    BS_INTR_12, //something with carried objects
    BS_INTR_13, //ff death square?
    BS_INTR_14, //gv matching game?, forces jump state
    BS_INTR_15,
    BS_INTR_16_THROW_CARRIED_OBJ, //carry_object_throw_volume
    BS_INTR_17, //eat yumblie?
    BS_INTR_18_CROC_ATE_WRONG, //ate wrong yumblie type?
    BS_INTR_19,
    BS_INTR_1A, //turbo_talon_trainers?
    BS_INTR_1B, //wading_boots
    BS_INTR_1C,
    BS_INTR_1D,
    BS_INTR_1E,
    BS_INTR_1F,
    BS_INTR_20,
    BS_INTR_21,
    BS_INTR_22,
    BS_INTR_23,
    BS_INTR_24,
    BS_INTR_25,
    BS_INTR_26, //bsjig_jiggy
    BS_INTR_27_BANJO_SLED,
    BS_INTR_28, //bs_sled
    BS_INTR_27_WALRUS_SLED, //bs_walrus_sled???
    BS_INTR_2A, //boggy race text?
    BS_INTR_2B, //boggy race?
    BS_INTR_2C,
    BS_INTR_2D,
    BS_INTR_2E,
    BS_INTR_2F_LOGGO, //loggo flush?
    BS_INTR_30,
    BS_INTR_31, //takes damage
    BS_INTR_32,
    BS_INTR_33,
    BS_INTR_34,
    BS_INTR_35, //notedoor?
    BS_INTR_36_DINGPOT, //dingpot
    BS_INTR_37
};

typedef struct bs_state_s{
    bsStateMethod init_func;
    bsStateMethod update_func;
    bsStateMethod end_func;
    bsStateMethod interrupt_func;
} bsState;

typedef struct bs_map_s{
    s32 uid;
    bsState behavior;
} bsMap;

void bsList_clearAll(void);
void bsList_setInitMethod(enum bs_e i, bsStateMethod func);
void bsList_setUpdateMethod(enum bs_e i, bsStateMethod func);
void bsList_setEndMethod(enum bs_e i, bsStateMethod func);
void bsList_setInterruptMethod(enum bs_e i, bsStateMethod func);
bsStateMethod bsList_getInitMethod(enum bs_e i);
bsStateMethod bsList_getUpdateMethod(enum bs_e i);
bsStateMethod bsList_getEndMethod(enum bs_e i);
bsStateMethod bsList_getInterruptMethod(enum bs_e i);
#endif
