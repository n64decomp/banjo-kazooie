#ifndef PROP_H
#define PROP_H

#include <ultra64.h>

#include "structs.h"
#include "core2/animctrl.h"

enum ch_id{
    ch_id_bigbutt = 4
};

typedef struct sprite_prop_s{
    u8 pad0[0xC];
} SpriteProp;

typedef struct prop_prop_s{
    u8 pad0[0xC];
} PropProp;

typedef struct actor_prop_s{
    struct actorMarker_s* marker;
    s16 x;
    s16 y;
    s32 z:16;
    u32 pad8_15:11;
    u32 unk8_4:1;
    u32 unk8_3:1;
    u32 unk8_2:1;
    u32 unk8_1:1;
    u32 unk8_0:1;
    //u8 padC;
} ActorProp;

typedef struct actorMarker_s{
    ActorProp*  propPtr;
    struct cude_s*     cubePtr;
    s32         unk8;
    void       ( *unkC)(struct actorMarker_s *, s32);
    s32         unk10;
    u32         yaw:9;
    u32         pad14_22:1;
    u32         unk14_21:1;
    u32         unk14_20:10; //contains jingo_id for chjinjo
    u32         pad14_19:11;
    u32         unk18;
    s32         unk1C;
    s32         unk20;
    s32         unk24;
    s32         unk28;
    u32         actrArrayIdx:11; //unk2C
    u32         pitch:9;
    u32         roll:9;
    u32         unk2C_2:1;
    u32         unk2C_1:1;
    u32         collidable:1;
    void        (*unk30)(struct actorMarker_s *);
    s32         unk34;
    u16         unk38;
    u16         unk3A;
    u32         unk3C_31:16;
    u32         pad3C_23:1;
    u32         modelId:13;
    u32         unk3C_1:1;
    u32         unk3C_0:1;
    u32         unk40_31:4;
    u32         pad40_27:1;
    u32         unk40_26:3;
    u32         unk40_23:1;
    u32         unk40_22:1;
    u32         unk40_21:1;
    u32         unk40_20:1;
    u32         unk40_19:1;
    u32         pad40_18:19;
    u32         unk44;
    s32         unk48;
    s32         unk4C;
    s32         unk50;
    s32         unk54;
    s32         unk58;
    s32         unk5C;
} ActorMarker;


typedef struct chmrvile_s{
    u8  pad0[0x4];
    u32 unk4;
    void *unk8;
    u8  unkC;
    u8  padD[0x7];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} ActorLocal_MrVile;

typedef struct chpinkegg_s{
    u32 unk0;
    u32 unk4;
} ActorLocal_PinkEgg;

typedef struct chyumblie_s{
    f32 unk0;
    u8  unk4;
    u8  pad7[3];
    f32 unk8;
    u32 unkC;
} ActorLocal_Yumblie;

typedef struct ch_bgs_2270_s{
    u32 unk0;
    vector(struct7s) *unk4;
    u8  unk8;
    u8  unk9;
    u8  unkA;
    u8  unkB;
    f32  unkC;
} ActorLocal_BGS_2270;

typedef struct ch_bgs_6730_s{
    u32  unk0;
    u32  unk4;
    s32  unk8;
    s32  unkC;
} ActorLocal_BGS_6730;

typedef struct chflibbit_s{
    u8  pad0;
    u8  unk1;
    s16 unk2[3];
    s16 unk8[3];
}ActorLocal_Flibbit;

typedef struct chtanktupbody_s{
    s32 unk0[4];
    s32 unk10;
}ActorLocal_TanktupBody;

typedef struct chleafboat_s{
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
    f32 unk60;
    f32 unk64;
    f32 unk68;
    f32 unk6C;
} ActorLocal_Leafboat;

typedef struct chjiggy_s{
    u32 unk0;
    u32 index;
} ActorLocal_Jiggy;

typedef struct actor_anim_info_s{
    u32     index;
    f32     duration;
} ActorAnimationInfo;

typedef struct chgrublin_s{
    f32     unk0;
    f32     unk4;
    u8      unk8;
    u8      unk9;
    u8      unkA;
    u8      unkB;
    u32     unkC_31:3;
    u32     unkC_28:1;
    u32     padC_27:28;
    s16     unk10;
    s16     unk12;
    f32     unk14; //90
    u8      unk18[0x18];
    s32     unk30;
    void    (*unk34)(ActorMarker *, s32);
}ActorLocal_Grublin;

typedef struct chconga_s{
    TUPLE(s32, orangeSpawnPosition);
    s32     unkC;
    s32     unk10;
    u8      pad14[0x4];
    s32     unk18;
    s32     unk1C;
}ActorLocal_Conga;

typedef struct jinjo_s{
    s32     unk0;
    s32     unk4;
    s32     unk8;
    s32     unkC;
}ActorLocal_Jinjo;

typedef struct juju_hitbox_s{
    u8      pad0[0x4];
    s32     unk4;
    ActorMarker *unk8[4];
    f32     unk18;
}ActorLocal_JujuHitbox;

typedef struct juju_s{
    s32     unk0;
    s32     unk4;
    TUPLE(f32, unk8);
    f32     unk14;
    s32     unk18;
}ActorLocal_Juju;

typedef struct ch_CC_530_s{
    u8     unk0;
    u8     unk1;
}ActorLocal_CC_530;

typedef struct ch_fight_180_s{
    u8 unk0;
    u8 pad1;
    u8 pad2;
    u8 pad3;
    u8 pad4;
    u8 pad5;
    u8 pad6;
    u8 pad7;
    u8 pad8;
    u8 pad9;
    u8 padA;
    u8 padB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
}ActorLocal_fight_180;

typedef struct ch_fight_6E90_s{
    u8 unk0;
}ActorLocal_fight_6E90;

typedef struct ch_fight_7BE0_s{
    s32 unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
}ActorLocal_fight_7BE0;

typedef struct ch_sm_4070{
    s32 unk0;
}ActorLocal_SM_4070;

typedef struct actor_s{
    ActorMarker* marker;
    TUPLE(f32,position);
    u32 unk10_31:6; //current animation state
    u32 unk10_25:7;
    u32 unk10_18:6;
    u32 unk10_12:4;
    u32 unk10_8:1;
    u32 unk10_7:1;
    u32 unk10_6:2;
    u32 unk10_4:1;
    u32 unk10_3:2;
    u32 unk10_1:1;
    u32 unk10_0:1;
    AnimCtrl *animctrl;
    ActorAnimationInfo *unk18;
    TUPLE(f32, unk1C);
    f32 unk28; //used in cheggs
    TUPLE(f32, velocity);
    u32  unk38_31:10;
    u32  unk38_21:9;
    u32  unk38_13:9;
    u32  stored_animctrl_playbackType_:3; //animctrlPlaybackType
    u32  unk38_0:1;
    u32 unk3C;
    s32 unk40;
    u32 unk44_31:8;
    u32 modelCacheIndex:10; //modelCacheIndex
    s32 unk44_14:10;
    u32 despawn_flag:1;
    u32 unk44_2:1;
    u32 unk44_1:1;
    u32 unk44_0:1;
    f32 unk48; //used in chlmonkey (chimpy)
    f32 unk4C;
    /* 0x50 */ f32 yaw; //0x50
    f32 unk54; //0x54
    u32 unk58_31: 15;
    u32 stored_animctrl_index: 14; //animctrlAnimIndex;
    u32 unk58_2: 1;
    u32 unk58_1: 1;
    u32 unk58_0: 1;
    f32 unk5C;
    f32 unk60; //0x60
    f32 yaw_moving; //0x64
    f32 pitch;//0x68
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    u32 unk78_31:9;
    u32 unk78_22:9;
    u32 unk78_13:12;
    u32 stored_animctrl_forwards:1; //animCtrlDirection
    u32 stored_animctrl_smoothTransistion:1; //animCtrlSmoothTransition
    union
    {
        ActorLocal_Jiggy    jiggy;
        ActorLocal_MrVile   mrVile; 
        ActorLocal_PinkEgg  pinkEgg; 
        ActorLocal_Yumblie  yumblie; 
        ActorLocal_Leafboat leafboat;
        ActorLocal_BGS_2270 bgs_2270;
        ActorLocal_BGS_6730 bgs_6730;
        ActorLocal_Flibbit  flibbit;
        ActorLocal_TanktupBody tanktup;
        ActorLocal_Grublin grublin;
        ActorLocal_Conga conga;
        ActorLocal_Jinjo jinjo;
        ActorLocal_JujuHitbox juju_ctl;
        ActorLocal_Juju juju;
        ActorLocal_CC_530 CC_530;
        ActorLocal_fight_180 fight_180;
        ActorLocal_fight_6E90 fight_6E90;
        ActorLocal_fight_7BE0 fight_7BE0;
        ActorLocal_SM_4070 sm_4070;
        u8  local[1];
        struct{ 
            u8  unk7C[0x40];
            u8  unkBC[0x30];
        };
        
    };
    //u8  padAC[0x44];
    f32 unkEC; //animCtrl???
    f32 stored_animctrl_duration; //animCtrlDuration
    u32 unkF4_31:1;
    u32 unkF4_30:1;
    u32 unkF4_29:1;
    u32 unkF4_28:1; //saved marker->propPtr->unk8_3
    u32 unkF4_27:1; //saved marker->propPtr->unk8_2
    u32 unkF4_26:1; //saved marker->unk2C_1
    u32 stored_marker_collidable:1; //saved marker->collidable
    u32 unkF4_24:2;
    u32 unkF4_22:1;
    u32 initialized:1; //unkF4_21;
    u32 unkF4_20:12;
    u32 unkF4_8:9;
    f32 stored_animctrl_subrangeMin; //animCtrl_SubRangeStart
    f32 stored_animctrl_subrangeMax; //animCtrl_SubRangeEnd
    ActorMarker *unk100;
    ActorMarker *unk104;
    void ( *unk108)(struct actorMarker_s *, s32); //saved from marker->unkC
    s32 unk10C; //saved marker->unk10
    f32 roll;//110
    f32 sound_timer;
    TUPLE(f32, spawn_position); //0x118
    u32 unk124_31:12;
    u32 unk124_19:8;
    u32 unk124_11:2;
    u32 unk124_9:2;
    u32 unk124_7:1;
    u32 unk124_6:1;
    u32 unk124_5:2;
    u32 unk124_3:3;
    u32 unk124_0:1; //read in bsbbuster func 
    f32 scale;
    /* 0x12C */ struct actor_info *actor_info;
    void * unk130;
    vector(struct2s) **unk134; //vector<struct2s> //saved marker->unk1C
    u32 unk138_31:1;
    u32 unk138_30:1;
    u32 unk138_29:1;
    u32 unk138_28:1;
    u32 unk138_27:2;
    u32 unk138_25:1;
    u32 unk138_24:1;
    u32 unk138_23:1;
    u32 unk138_22:1;
    u32 unk138_21:1;
    u32 unk138_20:1;
    u32 unk138_19:10; //saved maker->unk14_20
    u32 unk138_9:1;
    u32 unk138_8:1;
    u32 unk138_7:4;
    u32 unk138_3:4;
    void (*unk13C)(struct actorMarker_s *);//saved marker->unk30
    f32 unk140;
    f32 unk144;
    void *unk148;
    void *unk14C;
    void *unk150;
    u32 unk154;
    void *unk158;
    void *unk15C;
    s32 unk160; //saved marker->unk54
    s8  unk164[0x3];
    s8  pad167[0x1];
    s32 unk168; //saved marker->unk58
    u32  unk16C_31:27; //saved s1->marker->unk5C
    u32  unk16C_4:1;
    u32  unk16C_3:1;
    u32  unk16C_2:1;
    u32  unk16C_1:1;
    u32  unk16C_0:1;
    f32 unk170;
    f32 unk174;
    f32 unk178;
    u32 unk17C_31:1;
    u32 pad17C_30:31;
} Actor;



typedef struct actor_info_s{
    s16     unk0;
    s16     actorId;
    s16     modelId;
    s16     startAnimation;
    ActorAnimationInfo*   animations;
    void    (* update_func)(Actor *);
    void    (* unk10)(Actor *);
    Actor*  (* draw_func)(ActorMarker *, Gfx **, Mtx**, u32);
    u8      pad18[4];
    f32     shadow_scale;
    u8      pad20[4];
} ActorInfo;

typedef struct actor_spawn_s{
    ActorInfo   *infoPtr;
    Actor *(*spawnFunc)(f32*, f32*, void*, s32);
    s32         unk8;
} ActorSpawn;

typedef union prop_s
{
    ActorProp   actor;
    SpriteProp  sprite;
    PropProp    prop;
    struct{
        u8 pad0[6];
        s16 unk6;
        s32 pad8_31: 30;
        u32 pad8_1:1;
        s32 markerFlag: 1;
    };
} Prop;


typedef struct cude_s{
    u32 x:5;
    u32 y:5;
    u32 z:5;
    u32 prop1Cnt:6;
    u32 prop2Cnt:6;
    u32 pad0:5;
    Prop *prop1Ptr;
    Prop *prop2Ptr;
}Cube;

typedef struct actor_array{
    s32 cnt;
    s32 max_cnt;
    Actor data[]; //variable size array
}ActorArray;

#endif
