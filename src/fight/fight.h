#ifndef _FIGHT_INTERNAL_H_
#define _FIGHT_INTERNAL_H_

enum bossjinjo_e{
    BOSSJINJO_ORANGE = 1,
    BOSSJINJO_GREEN,
    BOSSJINJO_PINK,
    BOSSJINJO_YELLOW,
    BOSSJINJO_JINJONATOR
};

extern ActorInfo chFightFlightPad;
extern ActorInfo chFinalBoss;
extern ActorInfo chBossJinjoOrange;
extern ActorInfo chBossJinjoGreen;
extern ActorInfo chBossJinjoPink;
extern ActorInfo chBossJinjoYellow;
extern ActorInfo chBossJinjoBase;
extern ActorInfo chStoneJinjo;
extern ActorInfo chJinjonatorBase;
extern ActorInfo chSpellBarrier;
extern ActorInfo chSpellFireball;
extern ActorInfo chSpellGreen;
extern ActorInfo chGreenBlast;
extern ActorInfo chJinjonator;
extern ActorInfo chBossShadow;

extern void fight_func_803863F0(void);

extern Actor *chBossShadow_draw(ActorMarker *this, Gfx **gdl, Mtx **mptr, Vtx **vptr);
extern void chBossShadow_update(Actor *this);

#endif
