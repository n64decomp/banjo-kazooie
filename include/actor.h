#ifndef ACTOR_H
#define ACTOR_H

#define ACTOR_FLAG_NONE     (0)
#define ACTOR_FLAG_UNKNOWN_0 (1 << 0)   // 0x1
#define ACTOR_FLAG_UNKNOWN_1 (1 << 1)   // 0x2
#define ACTOR_FLAG_UNKNOWN_2 (1 << 2)   // 0x4
#define ACTOR_FLAG_UNKNOWN_3 (1 << 3)   // 0x8
#define ACTOR_FLAG_UNKNOWN_4 (1 << 4)   // 0x10 - only used by GV Jinxy Head 2
#define ACTOR_FLAG_UNKNOWN_5 (1 << 5)   // 0x20
#define ACTOR_FLAG_UNKNOWN_6 (1 << 6)   // 0x40
#define ACTOR_FLAG_UNKNOWN_7 (1 << 7)   // 0x80
#define ACTOR_FLAG_UNKNOWN_8 (1 << 8)   // 0x100
#define ACTOR_FLAG_UNKNOWN_9 (1 << 9)   // 0x200
#define ACTOR_FLAG_UNKNOWN_10 (1 << 10) // 0x400
#define ACTOR_FLAG_UNKNOWN_11 (1 << 11) // 0x800
#define ACTOR_FLAG_UNKNOWN_12 (1 << 12) // 0x1000
#define ACTOR_FLAG_UNKNOWN_13 (1 << 13) // 0x2000
#define ACTOR_FLAG_UNKNOWN_14 (1 << 14) // 0x4000
#define ACTOR_FLAG_UNKNOWN_15 (1 << 15) // 0x8000
#define ACTOR_FLAG_UNKNOWN_16 (1 << 16) // 0x10000
#define ACTOR_FLAG_UNKNOWN_17 (1 << 17) // 0x20000
#define ACTOR_FLAG_UNKNOWN_18 (1 << 18) // 0x40000 - never used?
#define ACTOR_FLAG_UNKNOWN_19 (1 << 19) // 0x80000
#define ACTOR_FLAG_UNKNOWN_20 (1 << 20) // 0x100000
#define ACTOR_FLAG_UNKNOWN_21 (1 << 21) // 0x200000
#define ACTOR_FLAG_UNKNOWN_22 (1 << 22) // 0x400000 - used by overlay texts
#define ACTOR_FLAG_UNKNOWN_23 (1 << 23) // 0x800000
#define ACTOR_FLAG_UNKNOWN_24 (1 << 24) // 0x1000000
#define ACTOR_FLAG_UNKNOWN_25 (1 << 25) // 0x2000000
#define ACTOR_FLAG_UNKNOWN_26 (1 << 26) // 0x4000000
#define ACTOR_FLAG_UNKNOWN_27 (1 << 27) // 0x4000000

// Used for Gruntling, Grublin Hood, Seaman Grublin,
// Mum-Mum, and Limbo.
// Baddie Specific used for Gruntling & Grublin Hood.
//  * Gruntling: Red=2, Blue=1, Black=0
//  * Grublin Hood: Spring=0, Summer=1, Autumn=2, Winter=3
// Invulnerable State only used for Mum-Mum & Limbo.
typedef struct {
    // unk0 thru unk9 used for random wandering?
    f32 unk0; // Min Value For Rand Float?
    f32 unk4; // Max Value For Rand Float?
    u8  unk8; // Min Value For Rand Float?
    u8  unk9; // Max Value For Rand Float?
    u8  unkA;
    u8  unkB;
    u32 yaw:3;
    u32 unkC_28:1; // Always Set To True?
    u32 baddieSpecific:28;
    s16 foundPlayerSfx;
    s16 foundPlayerSampleRate;
    f32 foundPlayerVolume;
    f32 enterInvulnerableStateAnimationTimer; 
    s16 enterInvulnerableStateSfx;
    s16 enterInvulnerableStateSampleRate;
    f32 enterInvulnerableStateVolume;
    f32 exitInvulnerableStateAnimationTimer;
    s16 exitInvulnerableStateSfx;
    s16 exitInvulnerableStateSampleRate;
    f32 exitInvulnerableStateVolume;
    void (*hitFunction)(ActorMarker *, ActorMarker *);
    void (*dieFunction)(ActorMarker *, ActorMarker *);
    s32 globalTimer;
    f32 damageVolume;
} Humanoid_Baddies_Actor;

#endif // ACTOR_H
