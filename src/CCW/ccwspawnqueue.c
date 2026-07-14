#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "actor.h"

extern void chMMMBreakableWooden_update(Actor *);
extern void func_802D3D74(Actor *);
extern void func_80325F84(Actor *);


extern ActorInfo chZubbaDoorSummer;
extern ActorInfo chZubbaDoorAutumn;
extern ActorInfo chZubbaHoneyLump;
extern ActorInfo chZubba;
extern ActorInfo chZubbaDocile;
extern ActorInfo chCCWBeanstalk;
extern ActorInfo chDeadBeanstalk;
extern ActorInfo chCCWGobi;
extern ActorInfo chEyrieEgg;
extern ActorInfo chEyrieBaby;
extern ActorInfo chCaterpillar;
extern ActorInfo chEyrieAdult;
extern ActorInfo chCutsceneAdultEyrie;
extern ActorInfo chSnoreZ;
extern ActorInfo chCCWSpringSwitchDoor;
extern ActorInfo chCCWSummerSwitchDoor;
extern ActorInfo chCCWAutumnSwitchDoor;
extern ActorInfo chCCWWinterSwitchDoor;
extern ActorInfo chCCWSpringSwitch;
extern ActorInfo chCCWSummerSwitch;
extern ActorInfo chCCWAutumnSwitch;
extern ActorInfo chCCWWinterSwitch;
extern ActorInfo chNabnutSpring;
extern ActorInfo chNabnutBellyFull;
extern ActorInfo chAutumnOutdoorNabnut;
extern ActorInfo chMoundOfAcorns;
extern ActorInfo chPinkSquirrel;
extern ActorInfo chNabnutBedsheets;
extern ActorInfo chNabnutBed;
extern ActorInfo chNabnut;
extern ActorInfo chNabnutAutumnEatingAcorns;
extern ActorInfo chCarriedAcorn;
extern ActorInfo chGnawtySwimming;
extern ActorInfo chGnawtySummer;
extern ActorInfo chIndoorsGnawty;
extern ActorInfo chGnawtyBoulder;
extern ActorInfo chSnarebear;
extern ActorInfo chDeadSnarebear;
extern ActorInfo chNabnutWindowSpring;
extern ActorInfo chNabnutWindowSummer;
extern ActorInfo chNabnutWindowAutumn;
extern ActorInfo chNabnutWindowWinter;
extern ActorInfo chGrublinHood;
extern ActorInfo gChVacationTextTrigger;
extern ActorInfo chCCWWhipcrackRoomDoor;
extern ActorInfo chNabnutDoor;
extern ActorInfo D_8038F888;
extern ActorInfo chCCWMumbosHut;
extern ActorInfo chGnawtysDen;
extern ActorInfo chGnawtysBed;
extern ActorInfo chGnawtysShelves;

void code_76C0_ccwGnawtysStuffUpdate(Actor *this);
void code_76C0_ccwWhipcrackRoomDoorUpdate(Actor *this);

/* .data */

#if VERSION == VERSION_PAL
Actor* cc_pal_unk_draw(ActorMarker *, Gfx **, Mtx **, Vtx **);
#endif

// Unused
ActorInfo chNabnutWindowSpring = {
    MARKER_239_CCW_UNKNOWN_NABNUT_WINDOW, ACTOR_25F_CCW_UNKNOWN_NABNUT_WINDOW, ASSET_4FC_MODEL_CCW_UNKNOWN_NABNUT_WINDOW,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

// Unused
ActorInfo chNabnutWindowSummer = {
    MARKER_236_CCW_UNKNOWN_NABNUT_WINDOW, ACTOR_260_CCW_UNKNOWN_NABNUT_WINDOW, ASSET_4F9_MODEL_CCW_UNKNOWN_NABNUT_WINDOW,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chNabnutWindowAutumn = {
    MARKER_237_CCW_AUTUMN_NABNUT_WINDOW, ACTOR_261_CCW_AUTUMN_NABNUT_WINDOW, ASSET_4FA_MODEL_CCW_AUTUMN_NABNUT_WINDOW,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chNabnutWindowWinter = {
    MARKER_238_CCW_WINTER_NABNUT_WINDOW, ACTOR_262_CCW_WINTER_NABNUT_WINDOW, ASSET_4FB_MODEL_CCW_WINTER_NABNUT_WINDOW,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chNabnutDoor = {
    MARKER_243_NABNUT_DOOR, ACTOR_2E6_NABNUT_DOOR, ASSET_533_MODEL_NABNUT_DOOR,
    0x1, NULL,
    chMMMBreakableWooden_update, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chCCWWhipcrackRoomDoor = {
    MARKER_263_CCW_WHIPCRACK_ROOM_DOOR, ACTOR_2E7_WHIPCRACK_ROOM_DOOR, ASSET_518_MODEL_CCW_WHIPCRACK_ROOM_DOOR,
    0x1, NULL,
    code_76C0_ccwWhipcrackRoomDoorUpdate, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chCCWMumbosHut = {
    MARKER_21E_CCW_MUMBOS_HUT, ACTOR_233_CCW_MUMBOS_HUT, ASSET_3B3_MODEL_CCW_MUMBOS_HUT,
    0x1, NULL,
    func_802D3D74, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chGnawtysDen = {
    MARKER_26B_GNAWTYS_DEN, ACTOR_2DE_GNAWTYS_DEN, ASSET_531_MODEL_GNAWTYS_DEN,
    0x1, NULL,
    code_76C0_ccwGnawtysStuffUpdate, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chGnawtysBed = {
    MARKER_26C_GNAWTYS_BED, ACTOR_2DD_GNAWTYS_BED, ASSET_53E_MODEL_GNAWTY_BED,
    0x1, NULL,
    code_76C0_ccwGnawtysStuffUpdate, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo chGnawtysShelves = {
    MARKER_26D_GNAWTYS_SHELVES, ACTOR_2DC_GNAWTYS_SHELVES, ASSET_53F_MODEL_GNAWTY_SHELVES,
    0x1, NULL,
    code_76C0_ccwGnawtysStuffUpdate, actor_update_func_80326224, VER_SELECT(actor_drawFullDepth, cc_pal_unk_draw, 0, 0),
    0, 0, 0.0f, 0
};

ActorInfo D_8038F888 = {
    MARKER_1CC_CCW_UNKNOWN, ACTOR_318_CCW_UNKNOWN, 0x0,
    0x0, NULL,
    func_80325F84, NULL, func_80325340,
    0, 0, 0.0f, 0
};

/* .code */
void code_76C0_ccwWhipcrackRoomDoorUpdate(Actor *this){
    if(!this->initialized){
        func_802D3CE8(this);
        this->initialized = TRUE;

        if (levelSpecificFlags_get(LEVEL_FLAG_38_CCW_UNKNOWN)) {
            marker_despawn(this->marker);
        }
    }
}

void code_76C0_ccwGnawtysStuffUpdate(Actor *this){
    if(!this->initialized){
        func_802D3D74(this);
        this->initialized = TRUE;
        // Position For Gnawty's Den
        this->position_x = 325.8f;
        this->position_y = 600.0f;
        this->position_z = 0.0f;
    }
}

void CCW_func_8038DB6C(void)
{
    spawnableActorList_add(&chZubbaDoorSummer, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chZubbaDoorAutumn, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chZubbaHoneyLump, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8);
    spawnableActorList_add(&chZubba, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&chZubbaDocile, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chCCWBeanstalk, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chDeadBeanstalk, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chCCWGobi, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chEyrieEgg, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chEyrieBaby, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_14 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chCaterpillar, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chEyrieAdult, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11 | ACTOR_FLAG_UNKNOWN_19);
    spawnableActorList_add(&chCutsceneAdultEyrie, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chSnoreZ, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chCCWSpringSwitchDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chCCWSummerSwitchDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chCCWAutumnSwitchDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chCCWWinterSwitchDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chCCWSpringSwitch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chCCWSummerSwitch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chCCWAutumnSwitch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chCCWWinterSwitch, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chNabnutSpring, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chNabnutBellyFull, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chAutumnOutdoorNabnut, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chMoundOfAcorns, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chPinkSquirrel, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chNabnutBedsheets, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chNabnutBed, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chNabnut, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chNabnutAutumnEatingAcorns, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chCarriedAcorn, actor_new, ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGnawtySwimming, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGnawtySummer, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chIndoorsGnawty, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_11);
    spawnableActorList_add(&chGnawtyBoulder, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chSnarebear, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chDeadSnarebear, actor_new, ACTOR_FLAG_UNKNOWN_3);
    spawnableActorList_add(&chNabnutWindowSpring, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chNabnutWindowSummer, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chNabnutWindowAutumn, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chNabnutWindowWinter, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chGrublinHood, actor_new, ACTOR_FLAG_UNKNOWN_0 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_16 | ACTOR_FLAG_UNKNOWN_25);
    spawnableActorList_add(&gChVacationTextTrigger, actor_new, ACTOR_FLAG_NONE);
    spawnableActorList_add(&chCCWWhipcrackRoomDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chNabnutDoor, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&D_8038F888, actor_new, ACTOR_FLAG_UNKNOWN_7);
    spawnableActorList_add(&chCCWMumbosHut, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chGnawtysDen, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chGnawtysBed, actor_new, ACTOR_FLAG_UNKNOWN_10);
    spawnableActorList_add(&chGnawtysShelves, actor_new, ACTOR_FLAG_UNKNOWN_10);
}
