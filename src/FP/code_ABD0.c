#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "prop.h"
#include "SnS.h"
#include "actor.h"

extern ActorInfo D_80367FE0;

extern ActorInfo chScarfSled;
extern ActorInfo chRaceSled;
extern ActorInfo FP_D_80391AB0;
extern ActorInfo chXmasTree;
extern ActorInfo D_80391BB0;
extern ActorInfo D_80391C18;
extern ActorInfo D_80391C58;
extern ActorInfo D_80391CE8;
extern ActorInfo D_80391E08;
extern ActorInfo FP_D_80391E2C;
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
extern ActorInfo FP_D_80392840;

void func_80391040(Actor *this);
void func_80391180(Actor *this);
void FP_func_80391254(Actor *this);
void func_803912EC(Actor *this);
void func_8039180C(Actor *this);
void func_80391894(Actor *this);

/* .data */
ActorInfo FP_D_803928E0 = { 0x247, 0x355, 0x4E5, 0x0, NULL, func_80391040, actor_update_func_80326224, actor_draw, 3000, 0, 0.0f, 0};
ActorInfo D_80392904 = { 0x248, 0x356, 0x4E6, 0x0, NULL, func_80391040, actor_update_func_80326224, actor_draw, 3000, 0, 0.0f, 0};
ActorInfo D_80392928 = { 0x249, 0x357, 0x4E7, 0x0, NULL, func_80391040, actor_update_func_80326224, actor_draw, 3000, 0, 0.0f, 0};
ActorInfo D_8039294C = { 0x24A, 0x358, 0x4E8, 0x0, NULL, func_80391040, actor_update_func_80326224, actor_draw, 3000, 0, 0.0f, 0};
ActorInfo D_80392970 = { 0x21F, 0x22B, 0x4C4, 0x1, NULL, func_80391180, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392994 = { 0x220, 0x22C, 0x4C5, 0x1, NULL, func_80391180, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_803929B8 = { 0x221, 0x22D, 0x4C6, 0x1, NULL, FP_func_80391254, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_803929DC = { 0x222, 0x22E, 0x4C6, 0x1, NULL, FP_func_80391254, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392A00 = { 0x223, 0x22F, 0x4C6, 0x1, NULL, FP_func_80391254, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392A24 = { 0x24B, 0x35D, 0x4E9, 0x1, NULL, func_803912EC, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392A48 = { 0x24C, 0x35E, 0x4EC, 0x1, NULL, func_803912EC, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392A6C = { 0x24D, 0x35F, 0x4EA, 0x1, NULL, func_803912EC, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392A90 = { 0x24E, 0x360, 0x4EB, 0x1, NULL, func_803912EC, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392AB4 = { 0x23D, 0x253, 0x512, 0x1, NULL, func_8039180C, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392AD8 = { 0x23E, 0x254, 0x513, 0x1, NULL, func_80391894, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392AFC = { 0x286, 0x3AE, 0x55B, 0x1, NULL, func_80391180, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392B20 = { 0x21D, 0x229, 0x4C3, 0x1, NULL, func_80391180, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};
ActorInfo D_80392B44 = { 0x289, 0x3B0, 0x56A, 0x1, NULL, func_80391180, actor_update_func_80326224, actor_drawFullDepth, 0, 0, 0.0f, 0};

/* .code */
int func_80390FC0(void){
      f32 sp1C[3];

      player_getVelocity(sp1C);

      if ( 0.0 == sp1C[0] && -1.0 == sp1C[1] && 0.0 == sp1C[2])
            return 0;
      return 1;
}

void func_80391040(Actor *this){
      f32 sp34[3];
      s32 a1;
      s32 sp2C;
      if(!this->volatile_initialized){
            this->volatile_initialized = TRUE;
            actor_collisionOff(this);
            this->marker->propPtr->unk8_3 = TRUE;
      }

      if( !this->marker->unk14_21 ) return;
      if( !func_80390FC0() )        return;
      if( globalTimer_getTime() & 7 )     return;

      if(randf() < 0.5){
            a1 = 8;
            switch(this->marker->id){
                  case 0x247://L80391128
                        sp2C = 0x710;
                        break;

                  case 0x248://L80391130
                        sp2C = 0x711;
                        break;

                  case 0x249://L80391138
                        sp2C = 0x712;
                        break;

                  case 0x24A://L80391140
                        sp2C = 0x711;
                        a1 = 6;
                        break;

                  default:
                        sp2C = 0x711;
                        break;
            }
            func_8034A174(this->marker->unk44, randi2(0,a1) + 5, sp34);
            func_802DC110(sp34, sp2C);
      }
}

void func_80391180(Actor *this){
      if(!this->volatile_initialized){
            this->volatile_initialized = TRUE;
            this->marker->propPtr->unk8_3 = TRUE;
            actor_collisionOff(this);
      }
      this->unk58_0 = func_8038DD14() ? 0 : 1;

      if(this->marker->id == 0x21F){
            this->marker->unk40_22 = subaddie_playerIsWithinSphere(this, 2000) ? 1 : 0;
      }
}

void FP_func_80391254(Actor *this){
      func_802D3D74(this);
      if(!this->volatile_initialized){
            this->volatile_initialized = TRUE;
            if(this->marker->id ==  0x221 || this->marker->id == 0x223){
                  this->pitch = 3.0f;
            }
            if(this->marker->id == 0x222){
                  this->pitch = 2.0f;
            }
      }
}

void func_803912EC(Actor *this){
      func_802D3D74(this);
      if(mapSpecificFlags_get(0xC)){
            marker_despawn(this->marker);
      }

}

void FP_func_80391324(void)
{
      spawnableActorList_add(&FP_D_80391AB0, actor_new, ACTOR_FLAG_UNKNOWN_9 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80391BB0, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5);
      spawnableActorList_add(&D_80391C18, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_19 | ACTOR_FLAG_UNKNOWN_20);
      spawnableActorList_add(&D_80391C58, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_7 | ACTOR_FLAG_UNKNOWN_19 | ACTOR_FLAG_UNKNOWN_20);
      spawnableActorList_add(&D_80391CE8, actor_new, ACTOR_FLAG_UNKNOWN_1 | ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80391E08, actor_new, ACTOR_FLAG_UNKNOWN_8);
      spawnableActorList_add(&FP_D_80391E2C, actor_new, ACTOR_FLAG_UNKNOWN_8);
      spawnableActorList_add(&D_80391E50, actor_new, ACTOR_FLAG_UNKNOWN_8);
      spawnableActorList_add(&D_80391F88, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80391FAC, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80391FD0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80391FF4, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_12 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_803920E8, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_803923D0, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_24);
      spawnableActorList_add(&chXmasTree, actor_new, ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80392420, actor_new, ACTOR_FLAG_UNKNOWN_2);
      spawnableActorList_add(&D_80392470, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_803924B0, actor_new, ACTOR_FLAG_UNKNOWN_3);
      spawnableActorList_add(&D_803924D4, actor_new, ACTOR_FLAG_UNKNOWN_3);
      spawnableActorList_add(&D_803924F8, actor_new, ACTOR_FLAG_UNKNOWN_3);
      spawnableActorList_add(&chScarfSled, actor_new, ACTOR_FLAG_NONE);
      spawnableActorList_add(&chRaceSled, actor_new, ACTOR_FLAG_UNKNOWN_5);
      spawnableActorList_add(&D_80392588, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8 | ACTOR_FLAG_UNKNOWN_19);
      spawnableActorList_add(&D_80392628, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_6);
      spawnableActorList_add(&D_80392690, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_5 | ACTOR_FLAG_UNKNOWN_7);
      spawnableActorList_add(&D_803926C0, actor_new, ACTOR_FLAG_UNKNOWN_10 | ACTOR_FLAG_UNKNOWN_27);
      spawnableActorList_add(&D_80392700, actor_new, ACTOR_FLAG_UNKNOWN_3 | ACTOR_FLAG_UNKNOWN_8);
      spawnableActorList_add(&FP_D_80392840, actor_new, ACTOR_FLAG_NONE);
      spawnableActorList_add(&D_80392730, actor_new, ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80367FE0, actor_new, ACTOR_FLAG_NONE);
      spawnableActorList_add(&FP_D_803928E0, actor_new, ACTOR_FLAG_UNKNOWN_6);
      spawnableActorList_add(&D_80392904, actor_new, ACTOR_FLAG_UNKNOWN_6);
      spawnableActorList_add(&D_80392928, actor_new, ACTOR_FLAG_UNKNOWN_6);
      spawnableActorList_add(&D_8039294C, actor_new, ACTOR_FLAG_UNKNOWN_6);
      spawnableActorList_add(&D_80392B20, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392B44, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392970, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392994, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_803929B8, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_803929DC, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392A00, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392A24, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80392A48, actor_new, ACTOR_FLAG_UNKNOWN_2);
      spawnableActorList_add(&D_80392A6C, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80392A90, actor_new, ACTOR_FLAG_UNKNOWN_2 | ACTOR_FLAG_UNKNOWN_17);
      spawnableActorList_add(&D_80392AB4, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392AD8, actor_new, ACTOR_FLAG_UNKNOWN_10);
      spawnableActorList_add(&D_80392AFC, actor_new, ACTOR_FLAG_UNKNOWN_10);
}


void func_80391744(Actor *this, Actor* other){
      f32 sp34[3] = {0.0f, 0.0f, 0.0f};
      f32 sp28[3];
      void *sp24;
      f32 tmp_f0;

      sp24 = func_80304C38(0x22A, this);
      tmp_f0 = (f32)func_80304DA8(sp24);
      other->yaw = tmp_f0;
      this->yaw = tmp_f0;
      ml_vec3f_yaw_rotate_copy(sp28, sp34, tmp_f0);
      nodeprop_getPosition(sp24, sp34);
      this->position_x = sp34[0] - sp28[0];
      this->position_z = sp34[2] - sp28[2];

      other->position_x = sp34[0] + sp28[0];
      other->position_z = sp34[2] + sp28[2];
}

void func_8039180C(Actor *this){
      Actor *sp24;

      if(!this->initialized){
            sp24 = actorArray_findActorFromActorId(0x254);
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
