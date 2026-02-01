#ifndef PROP_H
#define PROP_H

#include <ultra64.h>

#include "structs.h"
#include "core2/anctrl.h"
#include "core2/modelRender.h"
#include "core2/skeletalanim.h"

typedef struct sprite_prop_s{
    u32 spriteId:12;
    u32 unk0_19:1;
    u32 rgb_remove_red:3;
    u32 rgb_remove_green:3;
    u32 rgb_remove_blue:3;
    u32 scale:8;
    u32 isMirrored:1;
    u32 pad0_0: 1;
    union
    {
        s16 position[3];
        struct {
            s16 position_x;
            s16 position_y;
            s16 position_z;
        };
    };
    u16 frame: 5;
    u16 unk8_10: 5;
    u16 unk8_5: 1; // other structs use this to determine whether it's mirrored, however for sprites another bit address is used
    u16 isNotFeatherEggOrNote: 1;
    u16 unk8_3: 1; // is initialized?
    u16 isCollisionResolved: 1;
    u16 isModelProp:1; // always false for this struct
    u16 isActorProp:1; // always false for this struct
} SpriteProp;

#define SPRITE_ASSET_OFFSET 0x572

typedef struct model_prop_s{
    union{
        u16 unk0;
        struct{    
            u16 modelId:12;
            u16 pad0_19:4;
        };
    };
    u8 yaw;
    u8 roll;
    union
    {
        s16 position[3];
        struct {
            s16 position_x;
            s16 position_y;
            s16 position_z;
        };
    };
    u8 scale;
    u8 padB_7:2;
    u8 unkB_5:1;
    u8 unkB_4:1;
    u8 unk8_3:1; // is initialized?
    u8 isCollisionResolved:1;
    u8 isModelProp:1; // always true for this struct
    u8 isActorProp:1; // always false for this struct
} ModelProp;

#define MODEL_ASSET_OFFSET 0x2D1

typedef struct actor_prop_s{
    union {
        struct {
            struct actorMarker_s* marker;
            union
            {
                s16 position[3]; // position_
                struct {
                    s16 position_x;
                    s16 position_y;
                    s16 position_z;
                };
            };
            u16 frame:5;
            u16 unk8_10:5;
            u16 isMirrored:1;
            u16 isNotFeatherEggOrNote:1;
            u16 unk8_3:1; // is initialized?
            u16 isCollisionResolved:1;
            u16 isModelProp:1; // always false for this struct
            u16 isActorProp:1; // always true for this struct
        };
        s32 words[3];
    };
} ActorProp;

typedef void(*MarkerCollisionFunc)(struct actorMarker_s *this, struct actorMarker_s *other);
typedef struct actor_s *(*MarkerDrawFunc)(struct actorMarker_s *, Gfx **, Mtx **, Vtx **);
typedef void (*ActorUpdateFunc)(struct actor_s *);
typedef void (*ActorFreeFunc)(struct actor_s *);

typedef struct actorMarker_s{
    ActorProp* propPtr;
    struct cude_s* cubePtr;
    MarkerDrawFunc drawFunc;
    MarkerCollisionFunc collisionFunc; //ow_func
    MarkerCollisionFunc collision2Func;
    u32         yaw:9;
    u32         unk14_22:1;
    u32         unk14_21:1;
    u32         id:10; //  marker id of type marker enum_e
    u32         unk14_10:11; //used in ch/jiggy
    Struct6Cs   *unk18;
    MarkerCollisionFunc dieFunc;
    s32         unk20;
    ActorUpdateFunc actorUpdateFunc;
    s32         commonParticleIndex;
    u32         actrArrayIdx:11; //unk2C
    u32         pitch:9;
    u32         roll:9;
    u32         unk2C_2:1;
    u32         unk2C_1:1;
    u32         collidable:1;
    ActorFreeFunc actorFreeFunc;
    ActorUpdateFunc actorUpdate2Func;
    s16         unk38[3];
    u16         pad3E_15:1;
    u16         modelId:13;
    u16         isBanjoOnTop: TRUE;
    u16         unk3E_0:1; //scaled
    u32         unk40_31:4;
    u32         unk40_27:4;
    u32         unk40_23:1;
    u32         unk40_22:1;
    u32         unk40_21:1;
    u32         unk40_20:1;
    u32         unk40_19:1;
    u32         pad40_18:19;
    struct5Bs * unk44;
    BKModel *   unk48;
    vector(Struct70s) * unk4C;
    s32         unk50;
    void        (*unk54)(struct actorMarker_s *, struct actorMarker_s *, u16*);
    s32         (*unk58)(struct actorMarker_s *, struct actorMarker_s *);
    s32         unk5C;
} ActorMarker;

typedef struct ch_bgs_6730_s{
    u32  unk0;
    u32  unk4;
    s32  unk8;
    s32  unkC;
} ActorLocal_BGS_6730;

typedef struct chtanktupbody_s{
    s32 unk0[4];
    s32 unk10;
    s32 unk14;
    f32 unk18[3];
}ActorLocal_TanktupBody;


typedef struct actor_anim_info_s{
    u32     index;
    f32     duration;
} ActorAnimationInfo;

typedef struct jinjo_s{
    s32     unk0;
    s32     unk4;
    s32     unk8;
    s32     unkC;
}ActorLocal_Jinjo;

typedef struct ch_sm_4070{
    s32 dialog_id;
}ActorLocal_SM_4070;

typedef struct actor_s{
    ActorMarker* marker;
    TUPLE(f32,position);
    u32 state:6; /* unk10_31*/
    u32 unk10_25:7;
    u32 unk10_18:6;
    u32 unk10_12:4; // number of defeated enemies in SM attack tutorial
    u32 unk10_8:1;
    u32 unk10_7:1;
    u32 unk10_6:2;
    u32 unk10_4:1;
    u32 unk10_3:2;
    u32 unk10_1:1;
    u32 is_bundle:1;
    AnimCtrl *anctrl;
    ActorAnimationInfo *unk18;
    TUPLE(f32, unk1C); // actor position? // used as "home" for chbat
    f32 actor_specific_1_f; //used in cheggs
    TUPLE(f32, velocity);
    u32  unk38_31:10; // hit count for jinjo base in fight
    u32  unk38_21:9;
    u32  unk38_13:9;
    u32  stored_anctrl_playbackType_:3; //anctrlPlaybackType
    u32  unk38_0:1;
    u32 unk3C;
    s32 unk40;
    u32 unk44_31:8; // sfxsource idx
    u32 modelCacheIndex:10; //modelCacheIndex
    s32 unk44_14:10;
    u32 despawn_flag:1;
    u32 unk44_2:1; // is set, when actors created inside Cube?
    u32 unk44_1:1; // only used by blubber?
    u32 unk44_0:1; // unused
    f32 unk48; //used in chlmonkey (chimpy)
    f32 unk4C;
    /* 0x50 */ f32 yaw; //0x50
    f32 unk54; //0x54
    u32 anctrl_asset_id: 15; // animation asset id (enum asset_id)
    u32 stored_anctrl_index: 14; //anctrlAnimIndex;
    u32 unk58_2: 1;
    u32 unk58_1: 1;
    u32 unk58_0: 1;
    f32 unk5C;
    f32 lifetime_value; // actor lifetime?
    f32 yaw_ideal; //0x64
    f32 pitch;//0x68
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    u32 unk78_31:9;
    u32 unk78_22:9;
    u32 secondaryId:12; //default_spawn_yaw? This seems to be a different ID to differentiate actors that are the same- IE orange switches or tolls
    u32 stored_anctrl_forwards:1; //animCtrlDirection
    u32 stored_anctrl_smoothTransistion:1; //animCtrlSmoothTransition
    union
    { //DON'T DO THIS JUST DEFINE STATICLY IN ch/ FILE AND CAST FROM &Actor->local
        ActorLocal_BGS_6730 bgs_6730;
        ActorLocal_TanktupBody tanktup;
        ActorLocal_Jinjo jinjo;
        ActorLocal_SM_4070 sm_4070;
        u8  local[1];
        struct{ 
            u8  unk7C[0x40];
            u8  unkBC[0x30];
        };
        
    };
    //u8  padAC[0x44];
    f32 stored_anctrl_timer; // animCtrlTimer
    f32 stored_anctrl_duration; //animCtrlDuration
    u32 unkF4_31:1;
    u32 unkF4_30:1; // has something to do with vertices
    u32 unkF4_29:1;
    u32 unkF4_28:1; //saved marker->propPtr->unk8_3
    u32 unkF4_27:1; //saved marker->propPtr->unk8_2
    u32 unkF4_26:1; //saved marker->unk2C_1
    u32 stored_marker_collidable:1; //saved marker->collidable
    u32 unkF4_24:2;
    u32 unkF4_22:1;
    u32 initialized:1; //unkF4_21;
    u32 unkF4_20:12;
    u32 actorTypeSpecificField:9; /* jinjo id in final fight.
                    *  Is used to determine file progress related stuff, can also be a file_progress_e
                    *  Also related to jigsaw pictures, as an id for each
                    */
    f32 stored_anctrl_subrangeMin; //animCtrl_SubRangeStart
    f32 stored_anctrl_subrangeMax; //animCtrl_SubRangeEnd
    ActorMarker *partnerActor; // child actor marker ? Calling this "partner" since it seems to relate to actors that are "paired" and not necessarily parent/child
    ActorMarker *unk104;
    Struct62s *unk108;
    // void ( *unk108)(struct actorMarker_s *, s32); //saved from marker->collisionFunc
    s32 unk10C; //saved marker->unk10
    f32 roll;//110
    f32 sound_timer;
    TUPLE(f32, spawn_position); //0x118
    u32 unk124_31:12; // only used by GV Jinxy Head 2
    u32 alpha_124_19:8;
    u32 unk124_11:2; //blend_mode? 
    u32 depth_mode:2; //render_mode (passed to modelRender_setDepthMode())
    u32 unk124_7:1;
    u32 unk124_6:1;
    u32 unk124_5:2;
    u32 unk124_3:3;
    u32 unk124_0:1; //read in bsbbuster func 
    f32 scale;
    /* 0x12C */ struct actor_info_s *actor_info;
    void (* unk130)(struct actor_s *);
    vector(AnSeqElement) **unk134; //vector<AnSeqElement> //saved marker->dieFunc
    u32 unk138_31:1;
    u32 unk138_30:1;
    u32 unk138_29:1;
    u32 unk138_28:1;
    u32 unk138_27:2;
    u32 unk138_25:1;
    u32 has_met_before:1;
    u32 unk138_23:1;
    u32 unk138_22:1;
    u32 unk138_21:1;
    u32 unk138_20:1;
    u32 unk138_19:10; //saved maker->id
    u32 unk138_9:1;
    u32 unk138_8:1; // set to one by ACTOR_FLAG_UNKNOWN_18, which no actor seems to use
    u32 unk138_7:4;
    u32 unk138_3:4;
    ActorFreeFunc backupFreeFunc; // saved marker->actorFreeFunc
    f32 unk140;
    f32 unk144;
    SkeletalAnimation *unk148;
    void *unk14C[2];
    // void *unk150;
    u32 unk154;
    ParticleEmitter *unk158[2];
    void *unk160; //saved marker->unk54
    u8  unk164[0x2];
    u8  unk166;
    s8  pad167[0x1];
    s32 unk168; //saved marker->unk58
    u32  unk16C_31:27; //saved s1->marker->unk5C
    u32  volatile_initialized:1; // the difference between this flag and initialized is that it is reset in actors_appendToSavestate
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
    s16     markerId;
    s16     actorId;
    s16     modelId;
    s16     startAnimation;
    ActorAnimationInfo*   animations;
    void    (* update_func)(Actor *);
    void    (* update2_func)(Actor *);
    Actor*  (* draw_func)(ActorMarker *, Gfx **, Mtx **, Vtx **);
    u16     unk18;
    u16     draw_distance;
    f32     shadow_scale;
    u16     unk20;
    //u8     pad22[2];
} ActorInfo;

typedef struct actor_spawn_s{
    ActorInfo   *infoPtr;
    Actor *(*spawnFunc)(s32[3], s32, ActorInfo*, u32);
    s32         unk8;
} ActorSpawn;

typedef union prop_s
{
    ActorProp   actorProp;
    SpriteProp  spriteProp;
    ModelProp    modelProp;
    struct{
        u32 pad0;
        union
        {
            s16 position[3];
            struct {
                s16 position_x;
                s16 position_y;
                s16 position_z;
            };
        };
        s16 pad8_15:10;
        u16 isMirrored:1;
        u16 isNotFeatherEggOrNote:1;
        u16 unk8_3:1; // is initialized?
        u16 isCollisionResolved:1;
        u16 isModelProp:1;
        u16 isActorProp:1;
    };
} Prop;

typedef struct {
    union
    {
        s16 position[3];
        struct {
            s16 position_x;
            s16 position_y;
            s16 position_z;
        };
    };
    u16 selector_or_radius:9; // selector / volume / diameter?
    u16 category:6;
    u16 bit0:1;
    u16 actorId;
    u8 markerId;
    u8 padB;
    u32 yaw:9;
    u32 scale:23;
    u32 unk10_31:12; // unk10_31 and unk10_19 seem to be related
    u32 unk10_19:12; // unk10_31 and unk10_19 seem to be related
    u32 pad10_7:1;
    u32 unk10_6:1; // isInitialized flag?
    u32 pad10_5:4;
    u32 unk10_0:2; // is only for used in func_803303B8
} NodeProp; // size = 20 (0x14) bytes

typedef struct {
    u8 pad0[0x4];
    u32 pad4_31:14;
    u32 unk4_17:2;  // only ever gets 0 written to it
    u32 pad4_15:8;
    u32 pad4_7:7;
    u32 unk4_0:1; // if this and unkC_0 is false then unk10_4 and unk4_17 are set to 0 
    u8 pad8[0x4];
    u32 padC_31:31;
    u32 unkC_0:1; // if this and unk4_0 is false then unk10_4 and unk4_17 are set to 0 
    u32 pad10_31:27;
    u32 unk10_4:4; // only ever gets 0 written to it
    u32 pad10_0:1; 
} OtherNode; //can be inplace of NodeProp (see code7AF80_initCubeFromFile) size: 12 (0xC) bytes

typedef struct cude_s{
    s32 x:5;
    s32 y:5;
    s32 z:5;
    u32 prop1Cnt:6;
    u32 prop2Cnt:6;
    u32 unk0_4:5; //node_prop_count
    NodeProp *prop1Ptr;
    Prop *prop2Ptr;
}Cube;

typedef struct actor_array{
    s32 cnt;
    s32 max_cnt;
    Actor data[]; //variable size array
}ActorArray;

typedef struct {
    u32 cnt;
    Actor *actor_save_state[];
}ActorListSaveState;

#endif
