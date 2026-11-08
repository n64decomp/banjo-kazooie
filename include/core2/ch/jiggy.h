#ifndef BANJO_KAZOOIE_CORE2_CH_JIGGY_H
#define BANJO_KAZOOIE_CORE2_CH_JIGGY_H

typedef struct chjiggy_s {
    bool isHidden;
    u32 id;
} ActorLocal_Jiggy;

Actor *chjiggy_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **arg3);
void chjiggy_update_2(Actor * arg0);
void chjiggy_update(Actor *this);
enum jiggy_e chjiggy_getJiggyId(Actor *this);

enum jiggy_state_e {
    JIGGY_STATE_1_INIT = 1,
    JIGGY_STATE_2_IDLE = 2
};

#endif
