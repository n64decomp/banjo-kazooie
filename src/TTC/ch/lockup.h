#define LOCKUP_WITH_JIGGY_ID 0xA

#define LOCKUP_CYCLE_TICKS_SLOW 0x1E
#define LOCKUP_CYCLE_TICKS_MEDIUM 0x14
#define LOCKUP_CYCLE_TICKS_FAST 0xA
#define LOCKUP_CYCLE_TICKS_DEFAULT 10000

typedef struct {
    s32 closedTicksCounter;
    s32 openTicksCounter;
} ActorLocal_Lockup;

static Actor *chLockup_draw(ActorMarker *this, Gfx **gfx, Mtx **mtx, Vtx **vtx);
static void chLockup_update(Actor *this);

enum ch_lockup_states_e {
    CH_LOCKUP_STATE_CLOSED   = 1,
    CH_LOCKUP_STATE_OPENING  = 2,
    CH_LOCKUP_STATE_OPEN     = 3,
    CH_LOCKUP_STATE_CLOSING  = 4,
    CH_LOCKUP_STATE_CLOSING2 = 5
};
