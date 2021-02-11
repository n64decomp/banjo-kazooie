#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"

void func_803272F8(s32 *, s32, ActorInfo*, u32);

extern ActorInfo D_80390804;
extern ActorInfo D_80390690;
extern ActorInfo D_803906F8;
extern ActorInfo D_8039071C;
extern ActorInfo D_80390740;
extern ActorInfo D_80390764;
extern ActorInfo D_80390788;
extern ActorInfo D_80390B68;
extern ActorInfo D_80390C40;
extern ActorInfo D_80390C88;
extern ActorInfo D_80390CC8;
extern ActorInfo D_80390D08;
extern ActorInfo D_80390D48;
extern ActorInfo D_80390AB0;
extern ActorInfo D_80390AE0;
extern ActorInfo D_80390960;
extern ActorInfo D_80390A40;
extern ActorInfo D_80390A70;
extern ActorInfo D_80390830;
extern ActorInfo D_80390880;
extern ActorInfo D_803908A4;
extern ActorInfo D_803908C8;
extern ActorInfo D_803908EC;
extern ActorInfo D_80390910;
extern ActorInfo D_80390934;
extern ActorInfo D_80390DA8;
extern ActorInfo D_80390D70;
extern ActorInfo D_80390BD8;
extern ActorInfo D_80390BFC;

void bgs_func_8038F1E0(void){//bgs_updateSpawnableActors
    func_803053E8(&D_80390804, func_803272F8, 0x00000088);//croctus
    func_803053E8(&D_80390690, func_803272F8, 0x020108A1); //flibbit
    func_803053E8(&D_803906F8, func_803272F8, 0x400); //pink_egg_largest
    func_803053E8(&D_8039071C, func_803272F8, 0x400); //pink_egg_large
    func_803053E8(&D_80390740, func_803272F8, 0x400); //pink_egg_medium
    func_803053E8(&D_80390764, func_803272F8, 0x400); //pink_egg_small
    func_803053E8(&D_80390788, func_803272F8, 0x400); //pink_egg_smallest
    func_803053E8(&D_80390B68, func_803272F8, 0); //mudhut_top
    func_803053E8(&D_80390C40, func_803272F8, 0x4000548);//tanktup
    func_803053E8(&D_80390C88, func_803272F8, 0x400042c);//tanktup_leg
    func_803053E8(&D_80390CC8, func_803272F8, 0x400042c);//tanktup_leg
    func_803053E8(&D_80390D08, func_803272F8, 0x400042c);//tanktup_leg
    func_803053E8(&D_80390D48, func_803272F8, 0x400042c);//tanktup_leg
    func_803053E8(&D_80390AB0, func_803272F8, 0x81);
    func_803053E8(&D_80390AE0, func_803272F8, 0x20108a1); //yellow_flibbit
    func_803053E8(&D_80390960, func_803272F8, 0);
    func_803053E8(&D_80390A40, func_803272F8, 0x880); //yumblie
    func_803053E8(&D_80390A70, func_803272F8, 0x9a2); //mr. vile
    func_803053E8(&D_80390830, func_803272F8, 0x888); //tiptup
    func_803053E8(&D_80390880, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_803908A4, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_803908C8, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_803908EC, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_80390910, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_80390934, func_803272F8, 0x9a8); //tiptup_chiorMember
    func_803053E8(&D_80390DA8, func_803272F8, 0x4000); //leafboat
    func_803053E8(&D_80390D70, func_803272F8, 0x580); //bigAlligator
    func_803053E8(&D_80390BD8, func_803272F8, 8); //green_jiggy_switch
    func_803053E8(&D_80390BFC, func_803272F8, 8); //green_jiggy_switch
}


