#ifndef PROP_H
#define PROP_H

#include <ultra64.h>

#include "structs.h"

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
    u32 pad8_2:1;
    u32 unk8_1:1;
    u32 unk8_0:1;
    //u8 padC;
} ActorProp;

typedef struct actorMarker_s{
    ActorProp*  propPtr;
    struct cude_s*     cubePtr;
    u8          pad8[0x4];
    void       ( *unkC)(struct actorMarker_s *, s32);
    u8          pad10[0x4];
    u32         yaw:9;
    u32         pad14_22:1;
    u32         unk14_21:1;
    u32         unk14_20:10; //contains jingo_id for chjinjo
    u32         pad14_19:11;
    u32         unk18;
    u8          unk1C[0x10];
    u32         actrArrayIdx:11; //unk2C
    u32         pitch:9;
    u32         roll:9;
    u32         unk2C_2:1;
    u32         unk2C_1:1;
    u32         collidable:1;
    void        (*unk30)(struct actorMarker_s *);
    u8          pad34[0x8];
    u32         pad3C_31:17;
    u32         modelId:13;
    u32         unk3C_1:1;
    u32         pad3C_0:1;
    u32         pad40_31:8;
    u32         unk40_23:1;
    u32         pad40_22:23;
    u32         unk44;
    u8          pad48[0x14];
    s32         unk5C;
} ActorMarker;



/*typedef struct mtx_array{
    u32 count;
    u32 size;
    float mtx[];
} MtxArray;*/

typedef struct animation_s{
    void (* matrices)(s32, s32);
    s32     unk4;
    u8      unk8;
    u8      unk9;
    s16     unkA;
    s16     unkC;
    s16     unkE;
    u32     index;
    f32     timer;
    f32     duration;
    u8      unk1C;
    u8      unk1D;
    u8      unk1E;
    u8      unk1F;
} Animation;

typedef struct movement_s{
    Animation *animation;
    f32     timer;
    f32     duration_min;
    f32     duration_max;
    f32     animation_timer;
    f32     transition_timer;
    float     unk18;
    s32     index;
    u8      playback_type;
    u8      playback_direction;
    u8      unk22;
    u8      unk23;
    u8      unk24;
    u8      unk25;
    u8      pad26[2];
} Movement;

typedef struct actorMovement_s{
    Movement movement;
    Animation animation;
} ActorMovement;

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
}ActorLocal_fight_180;

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
    u32 pad10_8:4;
    u32 unk10_4:4;
    u32 pad10_0:1;
    ActorMovement *movement;
    ActorAnimationInfo *unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28; //used in cheggs
    TUPLE(f32, velocity);
    u32  unk38_31:10;
    u32  pad38_21:21;
    u32  unk38_0:1;
    u8  pad3C[0x8];
    u32 unk44_31:8;
    u32 modelCacheIndex:10; //modelCacheIndex
    s32 unk44_4:10;
    u32 despawn_flag:1;
    s32 pad44_0:3;
    f32 unk48; //used in chlmonkey (chimpy)
    u8  pad4c[0x4];
    f32 yaw; //0x50
    f32 unk54; //0x54
    u8  pad58[0x8];//0x58, 0x5C, 0x60
    f32 unk60; //0x60
    f32 yaw_moving; //0x64
    f32 pitch;//0x68
    f32 unk6C;
    u8  pad70[0xC];
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
        ActorLocal_fight_180 fight_180;
        ActorLocal_SM_4070 sm_4070;
        u8  local[1];
        u8  pad7C[0x70];
        
    };
    //u8  padAC[0x44];
    u8  padEC[0x8];
    u32 unkF4_31:10;
    u32 initialized:1; //unkF4_21;
    u32 unkF4_20:12;
    u32 unkF4_8:9;
    u8  padF8[0x8];
    ActorMarker *unk100;
    ActorMarker *unk104;
    u8  pad108[8];
    f32 roll;//110
    f32 sound_timer;
    f32 spawn_position_x;
    f32 spawn_position_y;
    f32 spawn_position_z;//120
    u32 pad124_31:12;
    u32  unk124_19:8;
    u32  pad124_11:2;
    u32  unk124_9:2;
    u32  pad124_7:1;
    u32  unk124_6:1;
    u32  pad124_5:6;
    f32 scale;
    u8  pad12C[0x8];
    vector(struct2s) **unk134; //vector<struct2s>
    u32 unk138_31:1;
    u32 unk138_30:6;
    u32 unk138_24:1;
    u32 unk138_23:1;
    u32 pad138_23:23;
    u8  pad13C[0xC];
    void *unk148;
    void *unk14C;
    void *unk150;
    u8  pad14C[0x18];
    u32  pad16C_31:27;
    u32  unk16C_4:1;
    u32  pad16C_3:3;
    u32  unk16C_0:1;
    u8  pad170[0x10];
} Actor;



typedef struct actor_info_s{
    u16     unk0;
    s16     actorId;
    u16     modelId;
    u16     startAnimation;
    ActorAnimationInfo*   animations;
    void    (* update_func)(Actor *);
    void    (* unk14)(Actor *);
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
    s32 unk4;
    Actor data[]; //variable size array
}ActorArray;

#endif
