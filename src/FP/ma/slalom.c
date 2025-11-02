#include <ultra64.h>
#include "functions.h"
#include "variables.h"


#include "core2/statetimer.h"
extern void player_stateTimer_set(s32, f32);

#define NUM_BRIDGES 5
#define NUM_GATES 39

typedef struct {
    ActorMarker *marker;
    f32 position[3];
    f32 distGatesSq;
}MaSlalomGate;

typedef enum {
    MA_SLALOM_STATE_0_NONE,
    MA_SLALOM_STATE_1_STARTING,
    MA_SLALOM_STATE_2_RACING,
    MA_SLALOM_STATE_3_WIN,
    MA_SLALOM_STATE_4_LOSE
} MaSlalomState;

/* .data */
f32 D_80391ED0[3] = {-880.0f, 3.0f, 1769.0f};
f32 D_80391EDC = 180.0f;

f32 D_80391EE0[3] = {5187.0f, 428.0f, 854.0f};
f32 D_80391EEC = 194.0f;

f32 D_80391EF0[3] = {-904.0f, -10.0f, -1662.0f};
f32 FP_D_80391EFC = 180.0f;

f32 D_80391F00[3] = {2192.0f, 7.0f, 2901.0f};
f32 D_80391F0C = 85.0f;

f32 D_80391F10[3] = {712.0f, 7.0f, 3036.0f};
f32 D_80391F1C = 284.0f;

f32 D_80391F20[3] = {1605.0f, 658.0f, 5402.0f};
f32 D_80391F2C[3] = {-4454.0f, 1920.0f, -6898.0f};
f32 D_80391F38[3] = {-4451.0f, 1920.0f, -6685.0f};

/* .bss */
static MaSlalomGate meActiveFlags[NUM_GATES];
static MaSlalomGate meDummyFlags[NUM_GATES];
static ActorMarker *meBridgeLinks[NUM_BRIDGES];
static struct {
    u8 state;
    s32 flagCount;
    s32 playerGate;
    s32 boggyGate;
    s32 boggyHasFinished;
    ActorMarker *boggyLink;
    u8 hasBeenTwoBehind;
    u8 hasBeenThreeBehind;
    u8 hasBeenFourBehind;
}Me;


/* .code */
void FP_func_8038AB60(s32 arg0){
    int i;

    func_8028F8F8(0xe, arg0 ^ 1);

    for (i = 0x14; i < 0x23; i++){
        func_8028F8F8(i, arg0);
    }

    for (i = 0x32; i < 0x38; i++){
        func_8028F8F8(i, arg0);
    }
}

void func_8038ABDC(void){
    comusic_8025AB44(COMUSIC_3A_FP_BOGGY_RACE, 0, 4000);
    func_8025AABC(COMUSIC_3A_FP_BOGGY_RACE);
    func_8025A58C(-1, 4000);
    core1_ce60_incOrDecCounter(TRUE);
}

void func_8038AC20(s32 gate_indx, s32 arg1){
    Actor *a1;
    Actor *a2;
    
    a1 = marker_getActor(meActiveFlags[gate_indx].marker);
    a2 = marker_getActor(meDummyFlags[gate_indx].marker);

    a1->velocity[0] = (f32)arg1;
    a2->velocity[0] = (f32)arg1;
}

void __maSlalom_spawnGate(s32 indx, s32 arg1){
    ActorMarker *m1;
    ActorMarker *m2;
    Actor *a1;
    Actor *a2;
    
    m1 = actor_spawnWithYaw_f32(0x161, meActiveFlags[indx].position, 0)->marker;
    m2 = actor_spawnWithYaw_f32(0x162, meDummyFlags[indx].position, 0)->marker;
    a1 = marker_getActor(m1);
    a2 = marker_getActor(m2);
    
    a1->unk38_31 = 1;
    a2->unk38_31 = 1;

    a1->actorTypeSpecificField = indx + 1;
    a2->actorTypeSpecificField = indx + 1;

    meActiveFlags[indx].marker = a1->marker;
    meDummyFlags[indx].marker = a2->marker;

    func_8038AC20(indx, arg1);

    a1->unk1C[0] = a2->position_x;
    a1->unk1C[1] = a2->position_y;
    a1->unk1C[2] = a2->position_z;

    if(indx + 1 == NUM_GATES){
        a1->velocity[1] = 1.0f;
        a2->velocity[1] = 1.0f;
    }
}

void maSlalom_spawnGate(s32 indx, s32 arg1){
    __spawnQueue_add_2((GenFunction_2)__maSlalom_spawnGate, indx, arg1);
}

void __maSlalom_despawnGate(s32 indx){
    if(meActiveFlags[indx].marker){
        func_80326310(marker_getActor(meActiveFlags[indx].marker));
        meActiveFlags[indx].marker = NULL;
    }

    if(meDummyFlags[indx].marker){
        func_80326310(marker_getActor(meDummyFlags[indx].marker));
        meDummyFlags[indx].marker = NULL;
    }
}

void __maSlalom_despawnAllGates(void){
    int i;
    for(i = 0; i < NUM_GATES; i++){
        __maSlalom_despawnGate(i);
    }
}

void __maSlalom_spawnBridge(s32 indx){
    Actor *sp1C;
    switch(indx){
        case 0:// L8038AF0C
            sp1C = actor_spawnWithYaw_f32(0x22d, D_80391ED0, D_80391EDC);
            break;

        case 1:// L8038AF38
            sp1C = actor_spawnWithYaw_f32(0x22e, D_80391EE0, D_80391EEC);
            break;

        case 2:// L8038AF64
            sp1C = actor_spawnWithYaw_f32(0x22d, D_80391EF0, FP_D_80391EFC);
            break;

        case 3:// L8038AF90
            sp1C = actor_spawnWithYaw_f32(0x22d, D_80391F00, D_80391F0C);
            break;

        case 4:// L8038AFBC
            sp1C = actor_spawnWithYaw_f32(0x22d, D_80391F10, D_80391F1C);
            break;
    }
    meBridgeLinks[indx] = sp1C->marker;
}

void maSlalom_spawnBridge(s32 indx){
    __spawnQueue_add_1((GenFunction_1)__maSlalom_spawnBridge, indx);
}

void maSlalom_spawnAllBridges(void){
    int i;
    for(i = 0; i < NUM_BRIDGES; i++){
        maSlalom_spawnBridge(i);
    }
}

void __maSlalom_despawnBridge(s32 indx){
    if(meBridgeLinks[indx]){
        marker_despawn(meBridgeLinks[indx]);
        meBridgeLinks[indx] = NULL;
    }
}

void __maSlalom_despawnAllBridges(void){
    int i;
    for(i = 0; i < NUM_BRIDGES; i++){
        __maSlalom_despawnBridge(i);
    }
}

void __maSlalom_spawnTrainers(void){
    Actor *trainers = actor_spawnWithYaw_f32(ACTOR_2C_TURBO_TALON_TRAINERS, D_80391F20, 100);
    trainers->unk10_1 = FALSE;
}

void __maSlalom_spawnJiggy(enum jiggy_e jiggy_id){
    if(jiggy_id == JIGGY_2C_FP_BOGGY_3 && !jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        jiggy_spawn(jiggy_id, D_80391F38);
    }
    else{
        jiggy_spawn(jiggy_id, D_80391F2C);
    }
}

void __maSlalom_8038B190(void){
    func_8028F66C(BS_INTR_2B);
    mapSpecificFlags_set(4, FALSE);
    func_8028F918(0);
}

void __maSlalom_clearState(void){
    Me.state = MA_SLALOM_STATE_0_NONE;
}

void __maSlalom_winDialogCallback(enum jiggy_e jiggy_id){
    timed_setStaticCameraToNode(0.0f, 3);
    timedFunc_set_0(0.0f, __maSlalom_despawnAllGates);
    timedFunc_set_0(0.0f, __maSlalom_despawnAllBridges);
    timedFunc_set_1(0.1f, (GenFunction_1) __maSlalom_spawnJiggy, jiggy_id);
    timedFunc_set_0(5.0f, __maSlalom_8038B190);
    timedFunc_set_0(5.0f, __maSlalom_clearState);
    timed_exitStaticCamera(5.0f);
    
}

void __maSlalom_loseDialogCallback(void){
    timed_exitStaticCamera(0.0f);
    timedFunc_set_0(0.0f, __maSlalom_despawnAllGates);
    timedFunc_set_0(0.0f, __maSlalom_despawnAllBridges);
    func_8028FA14(gsworld_get_map(), 0x11);
    func_8028F66C(BS_INTR_2A);
}

void maSlalom_dialogCallback(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *pntBoggy;
    if(Me.boggyLink){
        pntBoggy = marker_getActor(Me.boggyLink);
    }
    
    switch(text_id){
        case ASSET_C04_DIALOG_BOGGY_SLED_WALRUS_MISS: //8038B318
            __maSlalom_loseDialogCallback();
            break;

        case ASSET_C07_DIALOG_BOGGY_SLED_WALRUS_COMPLETE: //8038B328
            __maSlalom_winDialogCallback(JIGGY_30_FP_BOGGY_2);
            break;

        case ASSET_C0B_DIALOG_BOGGY_SLED_BEAR_MISS: //8038B338
            __maSlalom_loseDialogCallback();
            break;

        case ASSET_C0D_DIALOG_BOGGY_SLED_BEAR_COMPLETE: //8038B348
            __maSlalom_winDialogCallback(JIGGY_2C_FP_BOGGY_3);
            break;

        case ASSET_C10_DIALOG_BOGGY_SLED_EITHER_GIVE_UP: //8038B358
            func_8038ABDC();
            func_8028FA14(gsworld_get_map(), 0x11);
            func_8028F66C(BS_INTR_2A);
            timedFunc_set_0(0.0f, __maSlalom_clearState);
            break;
    }//L8038B38C
}

void maSlalom_win(void){
    if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && player_movementGroup() == BSGROUP_6_TURBO_TALON_TRAINERS){
        player_stateTimer_set(STATE_TIMER_3_TURBO_TALON, 2.0f);
    }
    func_8028F918(1);
    coMusicPlayer_playMusic(COMUSIC_3B_MINIGAME_VICTORY, 28000);
    FP_func_8038AB60(0);
    func_8038ABDC();
    timed_setStaticCameraToNode(0.0f, 1);
}

void maSlalom_lose(void){
    Actor *pntBoggy;
    
    func_8028F918(2);
    if(Me.boggyLink)
        pntBoggy = marker_getActor(Me.boggyLink);
    
    pntBoggy->unk38_31 = 1;
    coMusicPlayer_playMusic(COMUSIC_3C_MINIGAME_LOSS, 28000);
    FP_func_8038AB60(0);
    func_8038ABDC();
    if(!jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        timed_setStaticCameraToNode(0.0f, 1);
        timed_playSfx(1.0f, SFX_8C_BOGGY_WAHEY, 1.0f, 32000);
        func_80324DBC(2.0f, ASSET_C04_DIALOG_BOGGY_SLED_WALRUS_MISS, 0x2b, pntBoggy->position, NULL, maSlalom_dialogCallback, NULL);
    }//L8038B4E0
    else{
        timed_setStaticCameraToNode(0.0f, 1);
        timed_playSfx(1.0f, SFX_8C_BOGGY_WAHEY, 1.0f, 32000);
        func_80324DBC(2.0f, ASSET_C0B_DIALOG_BOGGY_SLED_BEAR_MISS, 0x2b, pntBoggy->position, NULL, maSlalom_dialogCallback, NULL);

    }
}

void maSlalom_update(void){
    Actor *pntBoggy;
    int i;
    f32 f2;
    f32 f0;

    switch(Me.state){
        case MA_SLALOM_STATE_1_STARTING: //L8038B57C
            if(Me.flagCount < 2*NUM_GATES) break;

            for(i = 0; i < NUM_GATES; i++){
                if(i < (NUM_GATES - 1)){
                    f0 = meActiveFlags[i+1].position[2] - meActiveFlags[i].position[2];
                    f2 = meActiveFlags[i+1].position[0] - meActiveFlags[i].position[0];
                    meActiveFlags[i].distGatesSq = f0*f0 + f2*f2;
                }
                if(meActiveFlags[NUM_GATES - 1].distGatesSq < meActiveFlags[i].distGatesSq)
                    meActiveFlags[NUM_GATES - 1].distGatesSq = meActiveFlags[i].distGatesSq;
            }
            __maSlalom_despawnAllGates();
            Me.state = MA_SLALOM_STATE_0_NONE;
            break;

        case MA_SLALOM_STATE_2_RACING: //L8038B61C
            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && player_movementGroup() == BSGROUP_6_TURBO_TALON_TRAINERS){
                player_stateTimer_set(STATE_TIMER_3_TURBO_TALON, 20.0f);
            }

            if(meActiveFlags[NUM_GATES - 1].marker == NULL) break;

            if(3.0f == marker_getActor(meActiveFlags[NUM_GATES - 1].marker)->velocity[0]){
                maSlalom_win();
                Me.state = MA_SLALOM_STATE_3_WIN;
                break;
            }
            
            if(Me.boggyHasFinished){
                maSlalom_lose();
                Me.state = MA_SLALOM_STATE_4_LOSE;
            }
            break;

        case MA_SLALOM_STATE_3_WIN: //L8038B6C4
            if(Me.boggyLink){
                pntBoggy = marker_getActor(Me.boggyLink);
            }
            pntBoggy->unk38_31 = 2;
            timed_playSfx(1.0f, SFX_8D_BOGGY_OHWW, 1.0f, 32000);
            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) || jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2)){
                func_80324DBC(2.0f, ASSET_C0D_DIALOG_BOGGY_SLED_BEAR_COMPLETE, 0x2a, pntBoggy->position, NULL, maSlalom_dialogCallback, NULL);
            }
            else{
                func_80324DBC(2.0f, ASSET_C07_DIALOG_BOGGY_SLED_WALRUS_COMPLETE, 0x22, pntBoggy->position, NULL, maSlalom_dialogCallback, NULL);
            }
            Me.state = MA_SLALOM_STATE_4_LOSE;
            break;
    }//L8038B794
}

void maSlalom_init(void){
    int i;

    FP_func_8038AB60(0);

    if(gsworld_get_map() != MAP_27_FP_FREEZEEZY_PEAK || jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
        Me.state = MA_SLALOM_STATE_0_NONE;
        return;
    }

    Me.state = MA_SLALOM_STATE_1_STARTING;
    Me.boggyLink = NULL;
    Me.flagCount = 0;
    Me.playerGate = -1;
    Me.boggyGate = -1;
    Me.boggyHasFinished = 0;
    Me.hasBeenTwoBehind = 0;
    Me.hasBeenThreeBehind = 0;
    Me.hasBeenFourBehind = 0;

    for(i = 0; i < NUM_GATES; i++){
        meActiveFlags[i].marker = NULL;
        meDummyFlags[i].marker = NULL;
        meActiveFlags[i].position[0] = meActiveFlags[i].position[1] = meActiveFlags[i].position[2] = 0.0f;
        meDummyFlags[i].position[0] = meDummyFlags[i].position[1] = meDummyFlags[i].position[2] = 0.0f;
        meActiveFlags[i].distGatesSq = 0.0f;
        meDummyFlags[i].distGatesSq = 0.0f;
    }
    for(i = 0; i < NUM_BRIDGES; i++){
        meBridgeLinks[i] = NULL;
    }
}

void maSlalom_end(){}

void maSlalom_linkActiveFlag(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 num;
    
    num = actor->actorTypeSpecificField - 1;
    if(num < NUM_GATES){
        meActiveFlags[num].marker = actor->marker;
        meActiveFlags[num].position[0] = actor->position[0];
        meActiveFlags[num].position[1] = actor->position[1];
        meActiveFlags[num].position[2] = actor->position[2];
        Me.flagCount++;
    }//L8038B920
}

void maSlalom_linkDummyFlag(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 num;
    
    num = actor->actorTypeSpecificField - 1;
    if(num < NUM_GATES){
        meDummyFlags[num].marker = actor->marker;
        meDummyFlags[num].position[0] = actor->position[0];
        meDummyFlags[num].position[1] = actor->position[1];
        meDummyFlags[num].position[2] = actor->position[2];
        Me.flagCount++;
    }//L8038B9A0
}

void maSlalom_linkBoggy(ActorMarker *marker){
    Me.boggyLink = marker;
}

void maSlalom_unlinkBoggy(void){
    Me.boggyLink = NULL;
}

void maSlalom_start(void){
    int i;

    maSlalom_spawnGate(0, 1);
    for(i = 1; i < 4; i++){
        maSlalom_spawnGate(i, 2);
    }
    maSlalom_spawnGate(NUM_GATES - 1, 2);
    maSlalom_spawnAllBridges();
    if(jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2) || jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        __spawnQueue_add_0(__maSlalom_spawnTrainers);
    }

    Me.playerGate = -1;
    Me.boggyGate = -1;
    Me.boggyHasFinished = 0;
    Me.hasBeenTwoBehind = 0;
    Me.hasBeenThreeBehind = 0;
    Me.hasBeenFourBehind = 0;
    FP_func_8038AB60(1);
    Me.state = MA_SLALOM_STATE_2_RACING;
}

void maSlalom_setPlayerGate(s32 gate_num){

    Me.playerGate = --gate_num;
    func_8038AC20(gate_num, 3);
    if(gate_num + 1 < NUM_GATES){
        func_8038AC20(gate_num + 1, 1);
    }

    // make sure next 4 gates are spawned
    if(gate_num + 4 < (NUM_GATES - 1)){
        maSlalom_spawnGate(gate_num + 4, 2);
    }

    // despawn old gate
    if(gate_num >= 2){
        __maSlalom_despawnGate(gate_num - 2);
    }

    if(gate_num + 4 < 11){
        func_8028F8F8(20, 1);
        func_8028F8F8(20, 1);
        func_8028F8F8(21, 1);
        func_8028F8F8(22, 1);
        func_8028F8F8(30, 0);
    }
    else{
        func_8028F8F8(20, 0);
        func_8028F8F8(21, 0);
        func_8028F8F8(22, 0);
        func_8028F8F8(30, 1);
    }

    switch(Me.boggyGate - Me.playerGate){
        case 3:
            func_8025AEA0(0x3a, 266666);
            break;
        case 2:
            func_8025AEA0(0x3a, 300000);
            break;
        case 4:
            break;
        default:
            func_8025AEA0(0x3a, 333333);
            break;


    }
}

void maSlalom_setBoggyGate(s32 gate_num){

    if(Me.boggyGate - Me.playerGate < 4 || 0x23 < Me.boggyGate){
        if(Me.boggyLink) 
            marker_getActor(Me.boggyLink);

        if(func_8038A1A0(Me.boggyLink))
            return;

        Me.boggyGate = gate_num-1;
        if(Me.boggyGate >= NUM_GATES - 1){
            Me.boggyHasFinished = 1;
            return;
        }

        if(Me.state == MA_SLALOM_STATE_3_WIN)    return;
        if(Me.state == MA_SLALOM_STATE_4_LOSE)    return;
        if(Me.boggyGate >= 0x25) return;

        switch(Me.boggyGate - Me.playerGate){
            case 4:
                if(Me.hasBeenFourBehind)
                        break;
                Me.hasBeenFourBehind = TRUE;
                FP_func_8038AB60(0);
                if(!player_isDead()){
                    func_8028F918(2);
                    gcdialog_showDialog(ASSET_C10_DIALOG_BOGGY_SLED_EITHER_GIVE_UP, 0x20, NULL, NULL, maSlalom_dialogCallback, NULL);
                }//L8038BD40
                Me.state = MA_SLALOM_STATE_4_LOSE;
                break;

            case 3:
                if(!Me.hasBeenThreeBehind && !player_isDead()){
                    Me.hasBeenThreeBehind = 1;
                    gcdialog_showDialog(ASSET_C0F_DIALOG_BOGGY_SLED_EITHER_TAUNT_2, 0x20, NULL, NULL, NULL, NULL);
                }//L8038BD94
                func_8025AEA0(0x3a, 0x411aa);
                break;
            
            case 2:
                if(!Me.hasBeenTwoBehind && !player_isDead()){
                    Me.hasBeenTwoBehind = 1;
                    gcdialog_showDialog(ASSET_C0E_DIALOG_BOGGY_SLED_EITHER_TAUNT_1, 0x20, NULL, NULL, NULL, NULL);
                }//L8038BDF0
                func_8025AEA0(0x3a, 0x493e0);
                break;

            default:
                func_8025AEA0(0x3a, 0x51615);
                break;
        }
    }
}

/**
 * @brief: returns a float between -4.0 and +NUM_GATES based on how many gates
   difference there is between boggy and the player
 */
f32 maSlalom_compareBoggyToPlayer(f32 boggy_position[3]){
    f32 player_position[4];
    f32 f18;
    f32 player_progress;
    f32 boggy_progress;
    f32 gate_diff;

    gate_diff = (f32)(Me.boggyGate - Me.playerGate);
    if(Me.state != MA_SLALOM_STATE_2_RACING || Me.boggyGate < 0 || Me.playerGate < 0)
        return 0.0f;

    if(gate_diff == 0.0f){
        player_getPosition(player_position);

        f18 = meActiveFlags[Me.boggyGate].distGatesSq;
        if( 0.0 == f18 )
            return 0.5f;

        player_progress = ((boggy_position[0] - meActiveFlags[Me.boggyGate].position[0])*(meActiveFlags[Me.boggyGate+1].position[0] - meActiveFlags[Me.boggyGate].position[0]) + (boggy_position[2] - meActiveFlags[Me.boggyGate].position[2])*(meActiveFlags[Me.boggyGate+1].position[2] - meActiveFlags[Me.boggyGate].position[2]))/f18;
        boggy_progress = ((player_position[0] - meActiveFlags[Me.boggyGate].position[0])*(meActiveFlags[Me.boggyGate+1].position[0] - meActiveFlags[Me.boggyGate].position[0]) + (player_position[2] - meActiveFlags[Me.boggyGate].position[2])*(meActiveFlags[Me.boggyGate+1].position[2] - meActiveFlags[Me.boggyGate].position[2]))/f18;
        return -(player_progress - boggy_progress);
    }//L8038BF58

    gate_diff += (gate_diff < 0.0f) ? -0.5 : 0.5;
    return -gate_diff;
}

bool maSlalom_isActive(void){
    if ( Me.state == MA_SLALOM_STATE_2_RACING 
         || Me.state == MA_SLALOM_STATE_3_WIN 
         || Me.state == MA_SLALOM_STATE_4_LOSE 
         || Me.hasBeenFourBehind
    ){
        return TRUE;
    }
    return FALSE;
}

bool maSlolam_WithinRadiusOfBoggy(f32 position[3], s32 radius){
    Actor *pntBoggy;

    // WARNING: (maslalom.c) - You must set a valid radius.

    if(Me.boggyLink){
        pntBoggy = marker_getActor(Me.boggyLink);
    }
    else{
        return FALSE;
    }

    if( (pntBoggy->position[0] - position[0])*(pntBoggy->position[0] - position[0])
        + (pntBoggy->position[1] - position[1])*(pntBoggy->position[1] - position[1])
        + (pntBoggy->position[2] - position[2])*(pntBoggy->position[2] - position[2]) 
        < radius*radius
    ){
        return TRUE;
    }

    return FALSE;
}

s32 maSlalom_boggyHasFinished(void){
    return Me.boggyHasFinished;
}
