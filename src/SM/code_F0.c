#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"

extern ActorInfo D_8038AB00;
extern ActorInfo D_8038ABF0;
extern ActorInfo D_8038AC20; //chAttackTutorial
extern ActorInfo D_8038AC78; //chCarrot Slave?
extern ActorInfo D_8038ACE8; //ch onion A
extern ActorInfo D_8038AD58; //ch cauliflower A
extern ActorInfo D_8038AC9C; //chCarrot FreeRange?
extern ActorInfo D_8038AD0C; //ch onion B
extern ActorInfo D_8038AD7C; //ch cauliflower B
extern ActorInfo D_8038AF90; //D_8038AF90 bottles
extern ActorInfo D_8038B0B0; //chJumpTutorial code_4070
extern ActorInfo D_8038B0E0;
extern ActorInfo D_8038B008; //chBanjosBed
extern ActorInfo D_8038B044; //chBanjosChair
extern ActorInfo D_8038B080; //chBanjosStove
extern ActorInfo D_8038AB24;

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_803864E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_803864FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_80386540.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_80386614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_803866CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/SM/code_F0/func_80386780.s")

void func_80386810(void)
{
    func_803053E8(&D_8038AB00,  func_803272F8, 0X2000180);
    func_803053E8(&D_8038ABF0,  func_803272F8, 0X80);
    func_803053E8(&D_8038AC20,  func_803272F8, 0);
    func_803053E8(&D_8038AC78,  func_803272F8, 0X2000121);
    func_803053E8(&D_8038ACE8,  func_803272F8, 0X2000121);
    func_803053E8(&D_8038AD58,  func_803272F8, 0X2200121);
    func_803053E8(&D_8038AC9C,  func_803272F8, 0X2000121);
    func_803053E8(&D_8038AD0C,  func_803272F8, 0X2000121);
    func_803053E8(&D_8038AD7C,  func_803272F8, 0X2200121);
    func_803053E8(&D_8038AF90,  func_803272F8, 0X100);
    func_803053E8(&D_8038B0B0,  func_803272F8, 0);
    func_803053E8(&D_8038B0E0,  func_803272F8, 0);
    func_803053E8(&D_8038B008,  func_803272F8, 0X6C8);
    func_803053E8(&D_8038B044,  func_803272F8, 0X6C8);
    func_803053E8(&D_8038B080,  func_803272F8, 0X6C8);
    func_803053E8(&D_8038AB24,  func_803272F8, 0X400);
}