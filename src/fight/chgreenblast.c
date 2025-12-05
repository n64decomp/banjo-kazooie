#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "fight.h"

extern Actor *func_80325CAC(ActorMarker *, Gfx **, Mtx **, Vtx**);

ActorInfo chGreenBlast = { MARKER_25D_GREEN_BLAST, ACTOR_38A_GREEN_BLAST, ASSET_6C7_GREEN_BLAST, 1, NULL, chGreenBlast_update, actor_update_func_80326224, chGreenBlast_draw, 0, 0, 1.0f, 0 };

f32 D_80391DE4[4] = {0.6f, 1.0f, 1.0f, 1.0f};
f32 D_80391DF4[4] = {0.3f, 0.3f, 0.3f, 1.0f};
s32 chGreenBlastExplosionStartFrameRange[2] = {1, 9}; 
f32 chGreenBlastExplosionScaleRange[4] = {4.5f, 4.5f, 4.5f, 4.5f};
f32 chGreenBlastExplosionLifetimeRange[4] = {0.0f, 0.0f, 0.85f, 1.35f};
f32 chGreenBlastExplosionFade[2] = {0.6f, 0.7f};
f32 chGreenBlastExplosionPositionRange[6] = {-130.0f, 0.0f, -130.0f, 130.0f, 0.0f, 130.0f}; 
f32 chGreenBlastSmokeLifetime[4] = {1.1f, 1.1f, 4.0f, 5.4f};

f32 chGreenBlastDieSparklesPositionRange[6] = {-20.0f, 0.0f, -20.0f, 20.0f, 40.0f, 20.0f};
f32 chGreenBlastDieSparklesAccelerationRange[6] = {0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 chGreenBlastDieSparklesVelocityRange[6] = {-420.0f, 410.0f, -420.0f, 480.0f, 860.0f, 480.0f};
f32 chGreenBlastDieSparklesScaleRange[4] = {0.35f, 0.65f, 0.0f, 0.0f};
f32 chGreenBlastDieSparklesLifetimeRange[4] = {0.0f, 0.01f, 2.0f, 2.3f}; 
f32 chGreenBlastDieSparklesFade[2] = { 0.0f, 0.35f};

f32 chGreenBlast_unused_D_80391ECC[6]  = {0.0f, 50.0f, 0.0f, 0.0f, 50.0f, 0.0f};
f32 chGreenBlast_unused_D_80391EE4[6]  = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
f32 chGreenBlast_unused_D_80391EFC[6]  = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
f32 chGreenBlast_unused_D_80391F14[4]  = {0.2f, 0.25f, 2.3f, 2.5f};
f32 chGreenBlast_unused_D_80391F24[4]  = {0.0f, 0.0f, 0.34f, 0.34f};
f32 chGreenBlast_unused_D_80391F34[2]  = {0.7f, 0.8f};

f32 chGreenBlastSparklesPositionRange[6] = { -50.0f, -50.0f, -50.0f, 50.0f, 50.0f, 50.0f};
f32 chGreenBlastSparklesAccelerationRange[6] = { 0.0f, -1200.0f, 0.0f, 0.0f, -1200.0f, 0.0f};
f32 chGreenBlastSparklesVelocityRange[6] = { -260.0f, -260.0f, -260.0f, 260.0f, 260.0f, 260.0f};
f32 chGreenBlastSparklesScaleRange[4] = {0.15f, 0.3f, 0.0f, 0.0f};
f32 chGreenBlastSparklesLifetimeRange[4] = {0.0f, 0.01f, 0.7f, 0.8f};
f32 chGreenBlastSparklesFade[2] = {0.0f, 0.65f};

Actor *chGreenBlast_draw(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Actor *actor = marker_getActor(marker);
    func_80344C2C(1);
    return func_80325CAC(marker, gfx, mtx, vtx);
}

void chGreenBlast_func_8038FC88(void){
    chfinalboss_func_80386654(1.0f, D_80391DF4, D_80391DE4);
}

void chGreenBlast_func_8038FCBC(void){
    chfinalboss_func_80386654(1.0f, D_80391DE4, D_80391DF4);
}

void chGreenBlast_collisionDie(ActorMarker *marker, ActorMarker *other_marker){
    Actor *actor = marker_getActor(marker);
    f32 explosion_position[3];

    explosion_position[0] = actor->position_x;
    explosion_position[1] = actor->position_y;
    explosion_position[2] = actor->position_z;
    explosion_position[1] += 160.0f;

    sfx_playFadeShorthandDefault(SFX_1B_EXPLOSION_1, 1.0f, 32000, actor->position, 1000, 3500);
    timedFunc_set_0(0.0f, chGreenBlast_func_8038FC88);
    timedFunc_set_0(0.3f, chGreenBlast_func_8038FCBC);

    fight_createSpriteParticles(actor->position, 4, ASSET_710_SPRITE_SPARKLE_PURPLE, chGreenBlastDieSparklesPositionRange, chGreenBlastDieSparklesAccelerationRange, chGreenBlastDieSparklesVelocityRange, chGreenBlastDieSparklesScaleRange, chGreenBlastDieSparklesLifetimeRange, chGreenBlastDieSparklesFade);
    fight_createSpriteParticles(actor->position, 4, ASSET_711_SPRITE_SPARKLE_DARK_BLUE, chGreenBlastDieSparklesPositionRange, chGreenBlastDieSparklesAccelerationRange, chGreenBlastDieSparklesVelocityRange, chGreenBlastDieSparklesScaleRange, chGreenBlastDieSparklesLifetimeRange, chGreenBlastDieSparklesFade);
    fight_createSmokeParticles(actor->position, 3, chGreenBlastSmokeLifetime);
    fight_createAnimatedSpriteParticles(explosion_position, 0x6C8, 3, chGreenBlastExplosionStartFrameRange, chGreenBlastExplosionPositionRange, chGreenBlastExplosionScaleRange, chGreenBlastExplosionLifetimeRange, chGreenBlastExplosionFade);

    marker_despawn(actor->marker);
}

void chGreenBlast_update(Actor *this) {
    f32 delta_time = time_getDelta();
    f32 target_position[3];

    if (!this->volatile_initialized) {
        this->volatile_initialized = TRUE;
        marker_setCollisionScripts(this->marker, NULL, NULL, chGreenBlast_collisionDie);
        this->marker->propPtr->unk8_3 = 0;
        actor_collisionOn(this);
        this->lifetime_value = 10.0f;
        this->scale = (f64)this->scale + this->scale;
    }

    this->roll += 20.0f; 

    if (globalTimer_getTime() % 4 == 1) {
        if (randf() < 0.5) {
            fight_createSpriteParticles(this->position, 4, ASSET_718_SPRITE_SPARKLE_WHITE_2, chGreenBlastSparklesPositionRange, chGreenBlastSparklesAccelerationRange, chGreenBlastSparklesVelocityRange, chGreenBlastSparklesScaleRange, chGreenBlastSparklesLifetimeRange, chGreenBlastSparklesFade);
        } else {
            fight_createSpriteParticles(this->position, 4, ASSET_719_SPRITE_SPARKLE_GREEN_2, chGreenBlastSparklesPositionRange, chGreenBlastSparklesAccelerationRange, chGreenBlastSparklesVelocityRange, chGreenBlastSparklesScaleRange, chGreenBlastSparklesLifetimeRange, chGreenBlastSparklesFade);
        }
    }

    player_getPosition(target_position);
    target_position[1] += 50.0f;
    chfinalboss_func_80387470(this, target_position, this->unk1C[0], this->unk1C[1], 0.0f, 1400.0f, 70.0f);

    if (func_8028F25C()) {
        chGreenBlast_collisionDie(this->marker, 0);
    } else {
        if (0.0 <= this->lifetime_value) {
            this->lifetime_value -= delta_time;
        } else {
            chGreenBlast_collisionDie(this->marker, 0);
        }
    }
}

void chGreenBlast_func_803900DC(ActorMarker *marker, f32 position[3], f32 arg2, f32 arg3) {
    Actor *actor = marker_getActor(marker);

    actor->position_x = position[0];
    actor->position_y = position[1];
    actor->position_z = position[2];
    actor->unk1C[0] = arg2;
    actor->unk1C[1] = arg3;
}
