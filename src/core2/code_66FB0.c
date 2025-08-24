#include <ultra64.h>
#include "functions.h"
#include "variables.h"
extern void func_802EFF9C(ParticleEmitter *, f32);

/* .data */
s32 D_80368860[] = {
    0x360, 
    0x50E, 
    0x2E7, 
    0x427,
    0x50F, 
    0x510, 
    ASSET_896_MODEL_GOLD_ROCK, 
    0x516,
    0x535, 
    0x536, 
    0x537, 
    0x88F,
    0x89F, 
    0x3AF, 
    0x3A8
};

s32 D_8036889C[] = {
    ASSET_608_UNKNOWN,
    ASSET_702_SPRITE_UNKNOWN,
    ASSET_712_SPRITE_SPARKLE_GREEN,
    ASSET_713_SPRITE_SPARKLE_YELLOW,
    ASSET_717_SPRITE_SPARKLE_YELLOW_2,
    ASSET_710_SPRITE_SPARKLE_PURPLE,
    ASSET_711_SPRITE_SPARKLE_DARK_BLUE,
    ASSET_714_SPRITE_UNKNOWN,
    ASSET_715_SPRITE_SPARKLE_RED,
    ASSET_716_SPRITE_SPARKLE_WHITE,
    ASSET_718_SPRITE_SPARKLE_WHITE_2,
    ASSET_719_SPRITE_SPARKLE_GREEN_2,
    ASSET_71A_SPRITE_SPARKLE_PINK_2,
    ASSET_71B_SPRITE_SPARKLE_ORANGE_2
};

/* .code */
void func_802EDF40(f32 pos[3], s32 arg1, s32 cnt, f32 arg3, f32 arg4, f32 arg5, s32 arg6[3], f32 arg7[3]){
    ParticleEmitter *pCtrl = partEmitMgr_newEmitter(cnt);
    f32 tmp_f0;
    if(arg1 < 0x3e7){
        particleEmitter_setModel(pCtrl, D_80368860[arg1]);
        particleEmitter_setStartingScaleRange(pCtrl, arg3 * 0.6, arg3 * 1.1);
        particleEmitter_setAngularVelocityRange(pCtrl, 400.0f, 400.0f, 400.0f, 800.0f, 800.0f, 800.0f);
    }
    else{//L802EE008
        particleEmitter_setSprite(pCtrl, D_8036889C[arg1 - 0x3e8]);
        if(arg1 == 0x3e9) {
            particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
        }
        else{
            particleEmitter_setStartingFrameRange(pCtrl, 0, 0);
        }
        particleEmitter_setStartingScaleRange(pCtrl, arg3, arg3);
        particleEmitter_setFinalScaleRange(pCtrl, arg3, arg3);
        particleEmitter_setAngularVelocityRange(pCtrl, 0, 0, 0, 0, 0, 0);
        func_802EFF9C(pCtrl, 0);
    }//L802EE0B4
    particleEmitter_setAccelerationRange(pCtrl, 
        0, -800.0f, 0,
        0, -800.0f, 0
    );
    particleEmitter_func_802EF9F8(pCtrl, 0.6f);
    particleEmitter_func_802EFA18(pCtrl, 0);
    particleEmitter_setSpawnPositionRange(pCtrl, 
        -10.0f, -10.0f, -10.0f,
        10.0f, 10.0f, 10.0f
    );
    particleEmitter_setSpawnIntervalRange(pCtrl, 0, 0.01f);
    particleEmitter_setParticleLifeTimeRange(pCtrl, arg5, arg5);
    if(arg7){
        tmp_f0 = arg7[0]*arg4;
        particleEmitter_setParticleVelocityRange(pCtrl,
            -tmp_f0, arg7[1]*arg4, -tmp_f0,
            tmp_f0, arg7[2]*arg4, tmp_f0
        );
    }
    else{
        particleEmitter_setParticleVelocityRange(pCtrl,
            -350.0f*arg4, 350.0f*arg4, -350.0f*arg4, 
            350.0f*arg4, 0*arg4, 350.0f*arg4
        );
    }
    if(arg6){
        particleEmitter_setRGB(pCtrl, arg6);
        particleEmitter_setAlpha(pCtrl, reinterpret_cast(s32, arg6[3]));
    }

    particleEmitter_setPosition(pCtrl, pos);
    particleEmitter_emitN(pCtrl, cnt);

}

void func_802EE238(f32 pos[3], s32 arg1, s32 cnt, f32 arg3, f32 arg4){
    func_802EDF40(pos, arg1, cnt, arg3, arg4, 1.5f, NULL, 0);
}

void func_802EE278(Actor *arg0, s32 arg1, s32 cnt, s32 arg3, f32 arg4, f32 arg5){
    f32 sp2C[3];
    sp2C[0] = arg0->position_x;
    sp2C[1] = arg0->position_y + (f32)arg3;
    sp2C[2] = arg0->position_z;
    func_802EDF40(sp2C, arg1, cnt, arg4, arg5, 1.5f, NULL, 0);
}

void func_802EE2E8(Actor *arg0, s32 arg1, s32 cnt, s32 arg3, f32 arg4, f32 arg5, f32 arg6){
    f32 sp2C[3];
    sp2C[0] = arg0->position_x;
    sp2C[1] = arg0->position_y + (f32)arg3;
    sp2C[2] = arg0->position_z;
    func_802EDF40(sp2C, arg1, cnt, arg4, arg5, arg6, NULL, 0);
}

void func_802EE354(Actor* arg0, s32 arg1, s32 cnt, s32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7[3], s32 arg8, f32 arg9[3]){
    f32 sp2C[3];

    if(arg8){
        func_8034A174(func_80329934(), arg8, sp2C);
        sp2C[1] += (f32)arg3;
    }
    else{
        sp2C[0] = arg0->position_x;
        sp2C[1] = arg0->position_y + (f32)arg3;
        sp2C[2] = arg0->position_z;
    }
    func_802EDF40(sp2C, arg1, cnt, arg4, arg5, arg6, arg7, arg9);
}
