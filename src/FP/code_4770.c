#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028F710(s32, f32);


#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AB60.s")

void func_8038ABDC(void){
    comusic_8025AB44(COMUSIC_3A_FP_BOGGY_RACE, 0, 0xFA0);
    func_8025AABC(COMUSIC_3A_FP_BOGGY_RACE);
    func_8025A58C(-1, 4000);
    func_8024BD08(1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AC20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038ADE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AE14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038AEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B00C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B0B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B0F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B1C4.s")

ActorMarker *D_803935BC;

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B268.s")

void func_8038B2C8(ActorMarker *caller, enum asset_e text_id, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B2C8.s")

void func_8038B39C(void){
    if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && func_8028ECAC() == 6){
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
    if(D_803935BC)
        sp2C = marker_getActor(D_803935BC);
    
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

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B7A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B9B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B9BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038B9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038BA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038BC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038BE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038BFA0.s")

bool func_8038BFE8(f32 arg0[3], s32 arg1){
    Actor *actor;

    if(D_803935BC){
        actor = marker_getActor(D_803935BC);
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

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_4770/func_8038C098.s")
