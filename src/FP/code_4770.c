#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F710(s32, f32);

typedef struct {
    ActorMarker *marker;
    f32 position[3];
    f32 unk10;
}Struct_FP_4770;

/* .data */
extern f32 D_80391ED0[3];
extern f32 D_80391EDC;
extern f32 D_80391EE0[3];
extern f32 D_80391EEC;
extern f32 D_80391EF0[3];
extern f32 D_80391EFC;
extern f32 D_80391F00[3];
extern f32 D_80391F0C;
extern f32 D_80391F10[3];
extern f32 D_80391F1C;
extern f32 D_80391F20[3];
extern f32 D_80391F2C[3];
extern f32 D_80391F38[3];

/* .bss */
extern ActorMarker *D_80393590[5];
extern struct {
    u8 unk0;
    // u8 pad1[0x3];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    ActorMarker *unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
}D_803935A8;
extern Struct_FP_4770 D_80392F70[0x27];
extern Struct_FP_4770 D_80393280[0x27];


/* .code */
void func_8038AB60(s32 arg0){
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
    func_8024BD08(1);
}

void func_8038AC20(s32 gate_indx, s32 arg1){
    Actor *a1;
    Actor *a2;
    
    a1 = marker_getActor(D_80392F70[gate_indx].marker);
    a2 = marker_getActor(D_80393280[gate_indx].marker);

    a1->velocity[0] = (f32)arg1;
    a2->velocity[0] = (f32)arg1;
}

//spawn race flag pair
void func_8038AC90(s32 indx, s32 arg1){
    ActorMarker *m1;
    ActorMarker *m2;
    Actor *a1;
    Actor *a2;
    
    m1 = func_8032813C(0x161, D_80392F70[indx].position, 0)->marker;
    m2 = func_8032813C(0x162, D_80393280[indx].position, 0)->marker;
    a1 = marker_getActor(m1);
    a2 = marker_getActor(m2);
    
    a1->unk38_31 = 1;
    a2->unk38_31 = 1;

    a1->unkF4_8 = indx + 1;
    a2->unkF4_8 = indx + 1;

    D_80392F70[indx].marker = a1->marker;
    D_80393280[indx].marker = a2->marker;

    func_8038AC20(indx, arg1);

    a1->unk1C[0] = a2->position_x;
    a1->unk1C[1] = a2->position_y;
    a1->unk1C[2] = a2->position_z;

    if(indx + 1 == 0x27){
        a1->velocity[1] = 1.0f;
        a2->velocity[1] = 1.0f;
    }
}

void func_8038ADE4(s32 indx, s32 arg1){
    func_802C3D3C(func_8038AC90, indx, arg1);
}

void func_8038AE14(s32 indx){
    if(D_80392F70[indx].marker){
        func_80326310(marker_getActor(D_80392F70[indx].marker));
        D_80392F70[indx].marker = NULL;
    }

    if(D_80393280[indx].marker){
        func_80326310(marker_getActor(D_80393280[indx].marker));
        D_80393280[indx].marker = NULL;
    }
}

void func_8038AEA0(void){
    int i;
    for(i = 0; i < 0x27; i++){
        func_8038AE14(i);
    }
}

void func_8038AEE0(s32 indx){
    Actor *sp1C;
    switch(indx){
        case 0:// L8038AF0C
            sp1C = func_8032813C(0x22d, D_80391ED0, D_80391EDC);
            break;

        case 1:// L8038AF38
            sp1C = func_8032813C(0x22e, D_80391EE0, D_80391EEC);
            break;

        case 2:// L8038AF64
            sp1C = func_8032813C(0x22d, D_80391EF0, D_80391EFC);
            break;

        case 3:// L8038AF90
            sp1C = func_8032813C(0x22d, D_80391F00, D_80391F0C);
            break;

        case 4:// L8038AFBC
            sp1C = func_8032813C(0x22d, D_80391F10, D_80391F1C);
            break;
    }
    D_80393590[indx] = sp1C->marker;
}

void func_8038B00C(s32 indx){
    __spawnqueue_add_1(func_8038AEE0, indx);
}

void func_8038B034(void){
    int i;
    for(i = 0; i < 5; i++){
        func_8038B00C(i);
    }
}

void func_8038B074(s32 indx){
    if(D_80393590[indx]){
        marker_despawn(D_80393590[indx]);
        D_80393590[indx] = NULL;
    }
}

void func_8038B0B8(void){
    int i;
    for(i = 0; i < 5; i++){
        func_8038B074(i);
    }
}

void func_8038B0F8(void){
    Actor *trainers = func_8032813C(ACTOR_2C_TURBO_TALON_TRAINERS, D_80391F20, 100);
    trainers->unk10_1 = FALSE;
}

void func_8038B130(enum jiggy_e jiggy_id){
    if(jiggy_id == JIGGY_2C_FP_BOGGY_3 && !jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        jiggySpawn(jiggy_id, D_80391F38);
    }
    else{
        jiggySpawn(jiggy_id, D_80391F2C);
    }
}

void func_8038B190(void){
    func_8028F66C(BS_INTR_2B);
    mapSpecificFlags_set(4, FALSE);
    func_8028F918(0);
}

void func_8038B1C4(void){
    D_803935A8.unk0 = 0;
}

void func_8038B1D0(enum jiggy_e jiggy_id){
    timed_setCameraToNode(0.0f, 3);
    timedFunc_set_0(0.0f, func_8038AEA0);
    timedFunc_set_0(0.0f, func_8038B0B8);
    timedFunc_set_1(0.1f, (GenMethod_1) func_8038B130, jiggy_id);
    timedFunc_set_0(5.0f, func_8038B190);
    timedFunc_set_0(5.0f, func_8038B1C4);
    func_80324E88(5.0f);
    
}

void func_8038B268(void){
    func_80324E88(0.0f);
    timedFunc_set_0(0.0f, func_8038AEA0);
    timedFunc_set_0(0.0f, func_8038B0B8);
    func_8028FA14(map_get(), 0x11);
    func_8028F66C(BS_INTR_2A);
}

void func_8038B2C8(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *actor;
    if(D_803935A8.unk14){
        actor = marker_getActor(D_803935A8.unk14);
    }
    
    switch(text_id){
        case 0xc04: //8038B318
            func_8038B268();
            break;

        case 0xc07: //8038B328
            func_8038B1D0(JIGGY_30_FP_BOGGY_2);
            break;

        case 0xc0b: //8038B338
            func_8038B268();
            break;

        case 0xc0d: //8038B348
            func_8038B1D0(JIGGY_2C_FP_BOGGY_3);
            break;

        case 0xc10: //8038B358
            func_8038ABDC();
            func_8028FA14(map_get(), 0x11);
            func_8028F66C(BS_INTR_2A);
            timedFunc_set_0(0.0f, func_8038B1C4);
            break;
    }//L8038B38C
}

void func_8038B39C(void){
    if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && func_8028ECAC() == BSGROUP_6_TURBO_TALON_TRAINERS){
        func_8028F710(3, 2.0f);
    }
    func_8028F918(1);
    func_8025A6EC(COMUSIC_3B_MINIGAME_VICTORY, 28000);
    func_8038AB60(0);
    func_8038ABDC();
    timed_setCameraToNode(0.0f, 1);
}

void func_8038B410(void){
    Actor *sp2C;
    
    func_8028F918(2);
    if(D_803935A8.unk14)
        sp2C = marker_getActor(D_803935A8.unk14);
    
    sp2C->unk38_31 = 1;
    func_8025A6EC(COMUSIC_3C_MINIGAME_LOSS, 28000);
    func_8038AB60(0);
    func_8038ABDC();
    if(!jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        timed_setCameraToNode(0.0f, 1);
        timed_playSfx(1.0f, SFX_8C_BOGGY_WAHEY, 1.0f, 32000);
        func_80324DBC(2.0f, 0xC04, 0x2b, sp2C->position, NULL, func_8038B2C8, NULL);
    }//L8038B4E0
    else{
        timed_setCameraToNode(0.0f, 1);
        timed_playSfx(1.0f, SFX_8C_BOGGY_WAHEY, 1.0f, 32000);
        func_80324DBC(2.0f, 0xC0b, 0x2b, sp2C->position, NULL, func_8038B2C8, NULL);

    }
}

void func_8038B544(void){
    Actor *sp2C;
    int i;
    f32 f2;
    f32 f0;

    switch(D_803935A8.unk0){
        case 1: //L8038B57C
            if(D_803935A8.unk4 < 0x4e) break;

            for(i = 0; i < 0x27; i++){
                if(i < 0x26){
                    f0 = D_80392F70[i+1].position[2] - D_80392F70[i].position[2];
                    f2 = D_80392F70[i+1].position[0] - D_80392F70[i].position[0];
                    D_80392F70[i].unk10 = f0*f0 + f2*f2;
                }
                if(D_80392F70[0x26].unk10 < D_80392F70[i].unk10)
                    D_80392F70[0x26].unk10 = D_80392F70[i].unk10;
            }
            func_8038AEA0();
            D_803935A8.unk0 = NULL;
            break;

        case 2: //L8038B61C
            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && func_8028ECAC() == BSGROUP_6_TURBO_TALON_TRAINERS){
                func_8028F710(3, 20.0f);
            }

            if(D_80392F70[0x26].marker == NULL) break;

            if(3.0f == marker_getActor(D_80392F70[0x26].marker)->velocity[0]){
                func_8038B39C();
                D_803935A8.unk0 = 3;
                break;
            }
            
            if(D_803935A8.unk10){
                func_8038B410();
                D_803935A8.unk0 = 4;
            }
            break;

        case 3: //L8038B6C4
            if(D_803935A8.unk14){
                sp2C = marker_getActor(D_803935A8.unk14);
            }
            sp2C->unk38_31 = 2;
            timed_playSfx(1.0f, SFX_8D_BOGGY_OHWW, 1.0f, 32000);
            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) || jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2)){
                func_80324DBC(2.0f, 0xc0d, 0x2a, sp2C->position, NULL, func_8038B2C8, NULL);
            }
            else{
                func_80324DBC(2.0f, 0xc07, 0x22, sp2C->position, NULL, func_8038B2C8, NULL);
            }
            D_803935A8.unk0 = 4;
            break;
    }//L8038B794
}

void func_8038B7A4(void){
    int i;

    func_8038AB60(0);

    if(map_get() != MAP_27_FP_FREEZEEZY_PEAK || jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
        D_803935A8.unk0 = 0;
        return;
    }

    D_803935A8.unk0 = 1;
    D_803935A8.unk14 = NULL;
    D_803935A8.unk4 = 0;
    D_803935A8.unk8 = -1;
    D_803935A8.unkC = -1;
    D_803935A8.unk10 = 0;
    D_803935A8.unk18 = 0;
    D_803935A8.unk19 = 0;
    D_803935A8.unk1A = 0;

    for(i = 0; i < 0x27; i++){
        D_80392F70[i].marker = NULL;
        D_80393280[i].marker = NULL;
        D_80392F70[i].position[0] = D_80392F70[i].position[1] = D_80392F70[i].position[2] = 0.0f;
        D_80393280[i].position[0] = D_80393280[i].position[1] = D_80393280[i].position[2] = 0.0f;
        D_80392F70[i].unk10 = 0.0f;
        D_80393280[i].unk10 = 0.0f;
    }
    for(i = 0; i < 5; i++){
        D_80393590[i] = NULL;
    }
}

void func_8038B8A8(){}

void func_8038B8B0(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 tmp_a0;
    
    tmp_a0 = actor->unkF4_8 - 1;
    if(tmp_a0 < 0x27){
        D_80392F70[tmp_a0].marker = actor->marker;
        D_80392F70[tmp_a0].position[0] = actor->position[0];
        D_80392F70[tmp_a0].position[1] = actor->position[1];
        D_80392F70[tmp_a0].position[2] = actor->position[2];
        D_803935A8.unk4++;
    }//L8038B920
}

void func_8038B930(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    s32 tmp_a0;
    
    tmp_a0 = actor->unkF4_8 - 1;
    if(tmp_a0 < 0x27){
        D_80393280[tmp_a0].marker = actor->marker;
        D_80393280[tmp_a0].position[0] = actor->position[0];
        D_80393280[tmp_a0].position[1] = actor->position[1];
        D_80393280[tmp_a0].position[2] = actor->position[2];
        D_803935A8.unk4++;
    }//L8038B9A0
}

void func_8038B9B0(ActorMarker *marker){
    D_803935A8.unk14 = marker;
}

void func_8038B9BC(void){
    D_803935A8.unk14 = NULL;
}

void func_8038B9C8(void){
    int i;

    func_8038ADE4(0, 1);
    for(i = 1; i < 4; i++){
        func_8038ADE4(i, 2);
    }
    func_8038ADE4(0x26, 2);
    func_8038B034();
    if(jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2) || jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
        func_802C3BF8(func_8038B0F8);
    }

    D_803935A8.unk8 = -1;
    D_803935A8.unkC = -1;
    D_803935A8.unk10 = 0;
    D_803935A8.unk18 = 0;
    D_803935A8.unk19 = 0;
    D_803935A8.unk1A = 0;
    func_8038AB60(1);
    D_803935A8.unk0 = 2;
}

void func_8038BA88(s32 arg0){

    D_803935A8.unk8 = --arg0;
    func_8038AC20(arg0, 3);
    if(arg0 + 1 < 39){
        func_8038AC20(arg0 + 1, 1);
    }

    if(arg0 + 4 < 38){
        func_8038ADE4(arg0 + 4, 2);
    }

    if(arg0 >= 2){
        func_8038AE14(arg0 - 2);
    }

    if(arg0 + 4 < 11){
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

    switch(D_803935A8.unkC - D_803935A8.unk8){
        case 3:
            func_8025AEA0(0x3a, 0x411aa);
            break;
        case 2:
            func_8025AEA0(0x3a, 0x493e0);
            break;
        case 4:
            break;
        default:
            func_8025AEA0(0x3a, 0x51615);
            break;


    }
}

void func_8038BC0C(s32 arg0){

    if(D_803935A8.unkC - D_803935A8.unk8 < 4 || 0x23 < D_803935A8.unkC){
        if(D_803935A8.unk14) 
            marker_getActor(D_803935A8.unk14);

        if(func_8038A1A0(D_803935A8.unk14))
            return;

        D_803935A8.unkC = arg0-1;
        if(D_803935A8.unkC >= 0x26){
            D_803935A8.unk10 = 1;
            return;
        }

        if(D_803935A8.unk0 == 3)    return;
        if(D_803935A8.unk0 == 4)    return;
        if(D_803935A8.unkC >= 0x25) return;

        switch(D_803935A8.unkC - D_803935A8.unk8){
            case 4:
                if(D_803935A8.unk1A)
                        break;
                D_803935A8.unk1A = TRUE;
                func_8038AB60(0);
                if(!func_8028F22C()){
                    func_8028F918(2);
                    func_80311480(0xc10, 0x20, NULL, NULL, func_8038B2C8, NULL);
                }//L8038BD40
                D_803935A8.unk0 = 4;
                break;

            case 3:
                if(!D_803935A8.unk19 && !func_8028F22C()){
                    D_803935A8.unk19 = 1;
                    func_80311480(0xc0f, 0x20, NULL, NULL, NULL, NULL);
                }//L8038BD94
                func_8025AEA0(0x3a, 0x411aa);
                break;
            
            case 2:
                if(!D_803935A8.unk18 && !func_8028F22C()){
                    D_803935A8.unk18 = 1;
                    func_80311480(0xc0e, 0x20, NULL, NULL, NULL, NULL);
                }//L8038BDF0
                func_8025AEA0(0x3a, 0x493e0);
                break;

            default:
                func_8025AEA0(0x3a, 0x51615);
                break;
        }
    }
}

f32 func_8038BE20(f32 arg0[3]){
    f32 sp38[4];
    f32 f18;
    f32 sp30;
    f32 sp2C;
    f32 tmp_f12;

    tmp_f12 = (f32)(D_803935A8.unkC - D_803935A8.unk8);
    if(D_803935A8.unk0 != 2 || D_803935A8.unkC < 0 || D_803935A8.unk8 < 0)
        return 0.0f;

    if(tmp_f12 == 0.0f){
        player_getPosition(sp38);

        f18 = D_80392F70[D_803935A8.unkC].unk10;
        if( 0.0 == f18 )
            return 0.5f;

        sp30 = ((arg0[0] - D_80392F70[D_803935A8.unkC].position[0])*(D_80392F70[D_803935A8.unkC+1].position[0] - D_80392F70[D_803935A8.unkC].position[0]) + (arg0[2] - D_80392F70[D_803935A8.unkC].position[2])*(D_80392F70[D_803935A8.unkC+1].position[2] - D_80392F70[D_803935A8.unkC].position[2]))/f18;
        sp2C = ((sp38[0] - D_80392F70[D_803935A8.unkC].position[0])*(D_80392F70[D_803935A8.unkC+1].position[0] - D_80392F70[D_803935A8.unkC].position[0]) + (sp38[2] - D_80392F70[D_803935A8.unkC].position[2])*(D_80392F70[D_803935A8.unkC+1].position[2] - D_80392F70[D_803935A8.unkC].position[2]))/f18;
        return -(sp30 - sp2C);
    }//L8038BF58

    tmp_f12 += (tmp_f12 < 0.0f) ? -0.5 : 0.5;
    return -tmp_f12;
}

bool func_8038BFA0(void){
    if ( D_803935A8.unk0 == 2 
         || D_803935A8.unk0 == 3 
         || D_803935A8.unk0 == 4 
         || D_803935A8.unk1A
    ){
        return TRUE;
    }
    return FALSE;
}

bool func_8038BFE8(f32 arg0[3], s32 arg1){
    Actor *actor;

    if(D_803935A8.unk14){
        actor = marker_getActor(D_803935A8.unk14);
    }
    else{
        return FALSE;
    }

    if( (actor->position[0] - arg0[0])*(actor->position[0] - arg0[0])
        + (actor->position[1] - arg0[1])*(actor->position[1] - arg0[1])
        + (actor->position[2] - arg0[2])*(actor->position[2] - arg0[2]) 
        < arg1*arg1
    ){
        return TRUE;
    }
    return FALSE;
}

s32 func_8038C098(void){
    return D_803935A8.unk10;
}
