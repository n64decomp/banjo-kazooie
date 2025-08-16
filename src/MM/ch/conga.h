enum conga_state_s {
    CONGA_STATE_IDLE                = 1,
    CONGA_STATE_HIT                 = 2,
    CONGA_STATE_MOPEY               = 3, // After defeat, waiting for Banjo to collect the jiggy
    CONGA_STATE_TARGET_GROUND       = 4,
    CONGA_STATE_BEAT_CHEST          = 5,
    CONGA_STATE_BEAT_CHEST_STOP     = 6, // Though depending on the animation, he'll go back to beating his chest
    CONGA_STATE_TARGET_BANJO        = 7, // Targeting Banjo when he's at eye level
    CONGA_STATE_ROAR                = 8  // When Conga is defeated
};
