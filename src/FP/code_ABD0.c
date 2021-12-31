#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"
#include "SnS.h"

extern ActorInfo D_80367FE0;

extern ActorInfo D_80391A10;
extern ActorInfo D_80391A60;
extern ActorInfo D_80391AB0;
extern ActorInfo D_80391B50;
extern ActorInfo D_80391BB0;
extern ActorInfo D_80391C18;
extern ActorInfo D_80391C58;
extern ActorInfo D_80391CE8;
extern ActorInfo D_80391E08;
extern ActorInfo D_80391E2C;
extern ActorInfo D_80391E50;
extern ActorInfo D_80391F88;
extern ActorInfo D_80391FAC;
extern ActorInfo D_80391FD0;
extern ActorInfo D_80391FF4;
extern ActorInfo D_803920E8;
extern ActorInfo D_803923D0;
extern ActorInfo D_80392420;
extern ActorInfo D_80392470;
extern ActorInfo D_803924B0;
extern ActorInfo D_803924D4;
extern ActorInfo D_803924F8;
extern ActorInfo D_80392588;
extern ActorInfo D_80392628;
extern ActorInfo D_80392690;
extern ActorInfo D_803926C0;
extern ActorInfo D_80392700;
extern ActorInfo D_80392730;
extern ActorInfo D_80392840;
extern ActorInfo D_803928E0;
extern ActorInfo D_80392904;
extern ActorInfo D_80392928;
extern ActorInfo D_8039294C;
extern ActorInfo D_80392970;
extern ActorInfo D_80392994;
extern ActorInfo D_803929B8;
extern ActorInfo D_803929DC;
extern ActorInfo D_80392A00;
extern ActorInfo D_80392A24;
extern ActorInfo D_80392A48;
extern ActorInfo D_80392A6C;
extern ActorInfo D_80392A90;
extern ActorInfo D_80392AB4;
extern ActorInfo D_80392AD8;
extern ActorInfo D_80392AFC;
extern ActorInfo D_80392B20;
extern ActorInfo D_80392B44;

extern f32 D_80392B68[3];


#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_ABD0/func_80390FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_ABD0/func_80391040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_ABD0/func_80391180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_ABD0/func_80391254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_ABD0/func_803912EC.s")

void func_80391324(void)
{
      spawnableActorList_add(&D_80391AB0, actor_new, 0X600);
      spawnableActorList_add(&D_80391BB0, actor_new, 0X2A);
      spawnableActorList_add(&D_80391C18, actor_new, 0X180084);
      spawnableActorList_add(&D_80391C58, actor_new, 0X180084);
      spawnableActorList_add(&D_80391CE8, actor_new, 0X2002E);
      spawnableActorList_add(&D_80391E08, actor_new, 0X100);
      spawnableActorList_add(&D_80391E2C, actor_new, 0X100);
      spawnableActorList_add(&D_80391E50, actor_new, 0X100);
      spawnableActorList_add(&D_80391F88, actor_new, 0X2100C);
      spawnableActorList_add(&D_80391FAC, actor_new, 0X2100C);
      spawnableActorList_add(&D_80391FD0, actor_new, 0X2100C);
      spawnableActorList_add(&D_80391FF4, actor_new, 0X2100C);
      spawnableActorList_add(&D_803920E8, actor_new, 0X408);
      spawnableActorList_add(&D_803923D0, actor_new, 0X100006C);
      spawnableActorList_add(&D_80391B50, actor_new, 0X20400);
      spawnableActorList_add(&D_80392420, actor_new, 4);
      spawnableActorList_add(&D_80392470, actor_new, 0X444);
      spawnableActorList_add(&D_803924B0, actor_new, 8);
      spawnableActorList_add(&D_803924D4, actor_new, 8);
      spawnableActorList_add(&D_803924F8, actor_new, 8);
      spawnableActorList_add(&D_80391A10, actor_new, 0);
      spawnableActorList_add(&D_80391A60, actor_new, 0X20);
      spawnableActorList_add(&D_80392588, actor_new, 0X80108);
      spawnableActorList_add(&D_80392628, actor_new, 0X44);
      spawnableActorList_add(&D_80392690, actor_new, 0XA8);
      spawnableActorList_add(&D_803926C0, actor_new, 0X8000400);
      spawnableActorList_add(&D_80392700, actor_new, 0X108);
      spawnableActorList_add(&D_80392840, actor_new, 0);
      spawnableActorList_add(&D_80392730, actor_new, 0X20000);
      spawnableActorList_add(&D_80367FE0, actor_new, 0);
      spawnableActorList_add(&D_803928E0, actor_new, 0X40);
      spawnableActorList_add(&D_80392904, actor_new, 0X40);
      spawnableActorList_add(&D_80392928, actor_new, 0X40);
      spawnableActorList_add(&D_8039294C, actor_new, 0X40);
      spawnableActorList_add(&D_80392B20, actor_new, 0X400);
      spawnableActorList_add(&D_80392B44, actor_new, 0X400);
      spawnableActorList_add(&D_80392970, actor_new, 0X400);
      spawnableActorList_add(&D_80392994, actor_new, 0X400);
      spawnableActorList_add(&D_803929B8, actor_new, 0X404);
      spawnableActorList_add(&D_803929DC, actor_new, 0X404);
      spawnableActorList_add(&D_80392A00, actor_new, 0X404);
      spawnableActorList_add(&D_80392A24, actor_new, 0X20004);
      spawnableActorList_add(&D_80392A48, actor_new, 4);
      spawnableActorList_add(&D_80392A6C, actor_new, 0X20004);
      spawnableActorList_add(&D_80392A90, actor_new, 0X20004);
      spawnableActorList_add(&D_80392AB4, actor_new, 0X400);
      spawnableActorList_add(&D_80392AD8, actor_new, 0X400);
      spawnableActorList_add(&D_80392AFC, actor_new, 0X400);
}


void func_80391744(Actor *this, Actor* other){
      f32 sp34[3] = D_80392B68;
      f32 sp28[3];
      void *sp24;
      f32 tmp_f0;

      sp24 = func_80304C38(0x22A, this);
      tmp_f0 = (f32)func_80304DA8(sp24);
      other->yaw = tmp_f0;
      this->yaw = tmp_f0;
      ml_vec3f_yaw_rotate_copy(sp28, sp34, tmp_f0);
      func_80304D68(sp24, sp34);
      this->position_x = sp34[0] - sp28[0];
      this->position_z = sp34[2] - sp28[2];

      other->position_x = sp34[0] + sp28[0];
      other->position_z = sp34[2] + sp28[2];
}

void func_8039180C(Actor *this){
      ActorMarker *sp24;

      if(!this->initialized){
            sp24 = func_80326EEC(0x254);
            if(sns_get_item_state(SNS_ITEM_ICE_KEY, 1) == 1){
                  marker_despawn(this->marker);
            }
            else{
                  func_802D3D74(this);
                  func_80391744(this, sp24);
                  this->initialized = TRUE;
            }
      }
}

void func_80391894(Actor *this){
      func_802D3D74(this);
}
