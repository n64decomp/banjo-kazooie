#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "prop.h"

void timed_exitStaticCamera(f32);

void timedFunc_set_2(f32, void(*)(s32, s32), s32, s32);

void func_8028E668(f32[3], f32, f32, f32);
extern void __spawnQueue_add_3(GenFunction_3, s32, s32, s32);

void func_8038F6A4(Actor *);

/* .data */
enum chtanktup_leg_e {
    TANKTUP_LEG_FRONT_LEFT,
    TANKTUP_LEG_BACK_LEFT,
    TANKTUP_LEG_FRONT_RIGHT,
    TANKTUP_LEG_BACK_RIGHT
};

ActorAnimationInfo BGS_D_80390C20[] = {
    {0, 0.0f},
    {0x101, 7.5f},
    {0x102, 1.75f},
    {0x107, 1.75f}
};

ActorInfo D_80390C40 = {MARKER_6C_TANKTUP, ACTOR_E8_TANKTUP, ASSET_3EE_TANKTUP, 0x01, BGS_D_80390C20,
    func_8038F6A4, actor_update_func_80326224, actor_draw,
    0, 0x80, 0.0f, 0
};

/* .code */
void func_8038F470(ActorMarker *this, s32 arg1, enum chtanktup_leg_e leg_id){
    Actor* thisActor;
    f32 pad;
    Actor* leg;
    f32 sp18[3];

    thisActor = marker_getActor(this);
    sp18[0] = thisActor->position_x;
    sp18[1] = thisActor->position_y;
    sp18[2] = thisActor->position_z;
    sp18[1] += 50.0f;

    leg = actor_spawnWithYaw_f32(leg_id + ACTOR_E9_TANKTUP_LEG_FL, sp18, (s32)thisActor->yaw);
    subaddie_set_state_with_direction(leg, arg1 + 1, 0, -1);
    leg->unk10_12 = leg_id;
}

void func_8038F51C(Actor *this){
    Actor * spawnPtr;
    spawnPtr = actorArray_findClosestActorFromActorId(this->position, ACTOR_E8_TANKTUP, -1, 0);
    spawnPtr->tanktup.unk0[this->unk10_12] = 1;
    spawnPtr->tanktup.unk10 = 1;
}

s32 func_8038F570(s16 *arg0){
    f32 pos[3];
    Actor * spawnPtr;

    pos[0] = (f32)arg0[0];
    pos[1] = (f32)arg0[1];
    pos[2] = (f32)arg0[2];
    spawnPtr = actorArray_findClosestActorFromActorId(pos, ACTOR_E8_TANKTUP, -1, 0);
    return spawnPtr->state == 3;


}

void func_8038F5E4(ActorMarker *marker, enum asset_e text_id, s32 arg2){
    timed_exitStaticCamera(0.0f);
}

void func_8038F610(Actor *this) {
    f32 sp24[3];

    func_8034A174(this->marker->unk44, 8, sp24);
    if (ml_isNonzero_vec3f(sp24) != 0) {
        func_8028E668(sp24, 200.0f, -600.0f, 300.0f);
    }
    func_8034A174(this->marker->unk44, 7, sp24);
    if (ml_isNonzero_vec3f(sp24) != 0) {
        func_8028E668(sp24, 200.0f, -600.0f, 200.0f);
    }
}


void func_8028F94C(s32, f32[3]);
void func_8028F918(s32);

void func_8038F6A4(Actor *this)
{
  ActorLocal_TanktupBody *local = (ActorLocal_TanktupBody *) (&this->local);
  f32 sp48[3];
  s32 sp44;
  NodeProp *temp_v0;
  if (!this->initialized)
  {
    temp_v0 = nodeprop_findByActorIdAndActorPosition(ACTOR_32B_UNKNOWN, this);
    if (temp_v0 == 0)
    {
      local->unk18[0] = 3672.0f;
      local->unk18[1] = 100.0f;
      local->unk18[2] = 987.0f;
    }
    else
    {
      nodeprop_getPosition(temp_v0, local->unk18);
    }
    this->has_met_before = FALSE;
    this->initialized = TRUE;
  }
  if (!this->volatile_initialized)
  {
    this->volatile_initialized = TRUE;
    this->marker->propPtr->unk8_3 = 1;
    actor_collisionOff(this);
    this->scale = 1.0f;
    for (sp44 = 0; sp44 < 4; sp44++)
    {
      if (local->unk0[sp44] == 0)
      {
        __spawnQueue_add_3((GenFunction_3)func_8038F470, *((s32 *) (&this->marker)), local->unk0[sp44], sp44);
      }
    }

    if (local)
    {
      ;
    }
  }
  switch (this->state)
  {
    case 1:
      func_8038F610(this);
      player_getPosition(sp48);
      if (!this->has_met_before)
    {
      if ((((ml_distance_vec3f(local->unk18, sp48) < 250.0f) && (ml_distance_vec3f(local->unk18, sp48) > 80.0f)) && (!func_8028ECAC())) && (player_getTransformation() == TRANSFORM_1_BANJO))
      {
        gcdialog_showText(0xC7E, 0, 0, 0, 0, 0);
        this->has_met_before = TRUE;
      }
    }
      if (local->unk10)
    {
      subaddie_set_state_with_direction(this, 2, 0.0f, -1);
      local->unk10 = 0;
      sp44 = 0;
        if(&sp44);
      local->unk14 = 1;
      for (; sp44 < 4; sp44++)
      {
        if (local->unk0[sp44] == 0)
        {
          local->unk14 = 0;
        }
      }

      if ((!this->unk138_23) && (!local->unk14))
      {
        if (gcdialog_showText(0xC80, 0, 0, 0, 0, 0))
        {
          this->unk138_23 = 1;
        }
      }
    }
      break;

    case 2:
      func_8038F610(this);
      if (actor_animationIsAt(this, 0.6f) && local->unk14)
    {
      func_8025A6EC(COMUSIC_2D_PUZZLE_SOLVED_FANFARE, 28000);
      func_8028F94C(2, local->unk18);
    }
      if (actor_animationIsAt(this, 0.99f))
    {
      if (!local->unk14)
      {
        subaddie_set_state_with_direction(this, 1, 0.0f, -1);
      }
      else
      {
        subaddie_set_state_with_direction(this, 3, 0.0f, -1);
        actor_playAnimationOnce(this);
      }
    }
      break;

    case 3:
      if (actor_animationIsAt(this, 0.1f) != 0)
    {
      timed_setStaticCameraToNode(0.0f, 0xD);
    }
      if (actor_animationIsAt(this, 0.55f) != 0)
    {
      func_8030E624(0x797FF885U);
    }
      if (actor_animationIsAt(this, 0.4f) != 0)
    {
      f32 sp34[3];
      func_8034A174(this->marker->unk44, 6, sp34);
      bundle_setYaw(this->yaw);
      sp34[1] -= 125.0f;
      jiggy_spawn(JIGGY_26_BGS_TANKTUP, sp34);
    }
      if (actor_animationIsAt(this, 0.9f) != 0)
    {
      func_8028F918(0);
      if (jiggyscore_isCollected(JIGGY_26_BGS_TANKTUP) == 0)
      {
        gcdialog_showText(0xC7F, 0xF, this->position, this->marker, func_8038F5E4, 0);
      }
      else
      {
        func_8038F5E4(this->marker, 0xC7F, -1);
      }
    }
      break;

  }

}

