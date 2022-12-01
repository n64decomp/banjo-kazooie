#include <ultra64.h>
#include "functions.h"
#include "variables.h"

void func_80254008(void);
extern void func_80256E24(f32[3], f32, f32, f32, f32, f32);
void assetcache_release(void *); //assetcache_free
extern void ml_vec3f_assign(f32[3], f32, f32, f32);
void func_8033A280(f32);


void func_80292048(s32, f32, f32, f32);
void func_80292090(s32 arg0);
void func_802920FC(f32);
void func_8029217C(f32);
void func_802921C8(s32 arg0);


extern s32 D_80000310;

/* .data */
struct5Bs *D_80363780 = NULL;

/* .bss */
void *D_8037C0E0; //playerModelPtr
s16 D_8037C0E4; //playerModel asset_id
u8  D_8037C0E6;
u8  D_8037C0E7;
u8  D_8037C0E8;
f32 D_8037C0EC;
f32 D_8037C0F0;
f32 D_8037C0F4;
f32 D_8037C0F8;
f32 D_8037C100[3];
f32 D_8037C110[3];
f32 D_8037C120[3];
void (*D_8037C12C)(Gfx **gfx, Mtx **mtx, Vtx **vtx);
f32 D_8037C130[2][4];
struct {
    u8 unk0;
    f32 unk4[3]; 
} D_8037C150;

//public
void playerModel_set(s32 asset_id);

//.data
void func_802919F0(void){
    switch(D_8037C0E7){
        case 2:
            D_8037C0F8 = mlNormalizeAngle(yaw_get() + 180.0f);
            break;
        default:
            D_8037C0F8 = yaw_get();
            break;
        case 3:
            break;
    }
}

void func_80291A60(s32 arg0, f32 arg1[3]){
    func_8034A174(D_80363780, arg0, arg1);
    if(func_802582EC(arg1)){
        _player_getPosition(arg1);
    }
}

int func_80291AAC(s32 arg0, s32 arga, s32 arg2, s32 arg3){
    return 0;
}

void func_80291AC4(int arg0){
    _player_getMarker()->unk14_21 = 1;
}

void func_80291AF0(Gfx **gfx, Mtx **mtx, Vtx **vtx){
    f32 sp5C[3];
    s32 sp50[3];
    f32 plyr_pos[3]; //sp44
    f32 sp38[3];

    if(!D_8037C0E8)
        return;

    func_802919F0();
    D_8037C0F4 = roll_get();
    D_8037C0F0 = pitch_get();
    _player_getPosition(plyr_pos);
    plyr_pos[1] += 2.0f;
    ml_vec3f_assign(sp5C, D_8037C0F0, D_8037C0F8, D_8037C0F4);
    func_8029A47C(sp50);
    ml_vec3f_copy(sp38, D_8037C100);

    plyr_pos[0] += D_8037C120[0];\
    plyr_pos[1] += D_8037C120[1];\
    plyr_pos[2] += D_8037C120[2];

    sp38[0] += D_8037C120[0];\
    sp38[1] += D_8037C120[1];\
    sp38[2] += D_8037C120[2];

    if(D_8037C0E0){
        func_80289F30();
        func_8029DD6C();
        modelRender_setEnvColor(sp50[0], sp50[1], sp50[2], D_8037C0E6);
        func_8033A280(2.0f);
        modelRender_preDraw(func_80291AC4, 0);
        func_8033A450(D_80363780);
        modelRender_setDepthMode(MODEL_RENDER_DEPTH_FULL);
        if(D_8037C150.unk0){
            D_8037C150.unk0 = 0;
            modelRender_draw(gfx, mtx, D_8037C150.unk4, sp5C, D_8037C0EC, sp38, D_8037C0E0);
        }
        else{
            modelRender_draw(gfx, mtx, plyr_pos, sp5C, D_8037C0EC, sp38, D_8037C0E0);
        }
    }//L80291CD4

    if(D_8037C12C){
        D_8037C12C(gfx, mtx, vtx);
    }
}

void func_80291D04(void){
    playerModel_set(func_802985F0());
}

void func_80291D2C(void){
    f32 plyr_pos[3];
    int i;
    for(i = 0; i < 2 ; i++){
        func_80292048(i, 0.0f, 0.0f, 0.0f);
        func_80292078(i, 0.0f);
    }
    D_8037C0E6 = -1;
    D_8037C0E0 = NULL;
    D_8037C0E4 = 0;
    D_8037C12C = 0;
    D_80363780 = func_8034A2C8();
    func_8034A130(D_80363780);
    ml_vec3f_clear(D_8037C100);
    ml_vec3f_clear(D_8037C110);
    ml_vec3f_clear(D_8037C120);
    D_8037C0F8 = D_8037C0F4 = D_8037C0F0 = 0.0f;
    D_8037C150.unk0 = 0;
    func_802921C8(1);
    func_802920FC(1.0f);
    D_8037C0E7 = 0;
    func_80292090(1);
    if(!func_8028ADB4())
        func_80291D04();
    player_getPosition(plyr_pos);
    func_802C3F04(func_802C4140, 0x17, 
        reinterpret_cast(s32, plyr_pos[0]),
        reinterpret_cast(s32, plyr_pos[1]),
        reinterpret_cast(s32, plyr_pos[2])
    );
}

void func_80291E88(void){
    assetcache_release(D_8037C0E0);
    D_8037C0E0 = NULL;
    D_8037C0E4 = 0;
    func_8034A2A8(D_80363780);
    D_80363780 = NULL;
}

void func_80291ECC(void){
    f32 sp1C;
    f32 temp_f0;

    sp1C = D_8037C110[1] - D_8037C100[1];
    temp_f0 = mlAbsF(sp1C);
    if( temp_f0 < 0.01){
        D_8037C100[1] = D_8037C110[1];
    }
    else{
        if(5.0f < temp_f0){
            temp_f0 = 1.0f;
        }
        if(0.0f < sp1C){
            D_8037C100[1] += temp_f0;
        }
        else{
            D_8037C100[1] -= temp_f0; 
        }
        {//L80291F7C
            _player_getMarker()->unk14_21 = 0;
        }
    }
}

BKModelBin *func_80291FA0(void){
    return D_8037C0E0;
}

enum asset_e func_80291FAC(void){
    return D_8037C0E4;
}

void func_80291FB8(s32 arg0){
    D_8037C0E6 = arg0;
}

void playerModel_set(s32 asset_id){
    if(asset_id != D_8037C0E4){
        if(D_8037C0E0){
            func_80254008();
            assetcache_release(D_8037C0E0);
            D_8037C0E0 = NULL;
        }
        D_8037C0E4 = asset_id;
        if(D_8037C0E4)
            D_8037C0E0 = assetcache_get(D_8037C0E4);
    }
}

void func_80292048(s32 arg0, f32 arg1, f32 arg2, f32 arg3){
    D_8037C130[arg0][2] = arg1;
    D_8037C130[arg0][3] = arg2;
    D_8037C130[arg0][1] = arg3;
}

void func_80292078(s32 arg0, f32 arg1){
    D_8037C130[arg0][0] = arg1; 
}

void func_80292090(s32 arg0){
    if(arg0 != D_8037C0E7){
        if(arg0 == 2 || 2 == D_8037C0E7){
            yaw_setIdeal(mlNormalizeAngle(yaw_get() + 180.0f));
            yaw_applyIdeal();
        }
    }
    D_8037C0E7 = arg0;
}

void func_802920FC(f32 arg0){
    if(D_80000310 + -0x17D7){
        arg0 = arg0*0.25;
    }
    D_8037C0EC = arg0;
}

void func_80292134(f32 arg0){
   D_8037C0F8 = mlNormalizeAngle(arg0);
}

void func_80292158(f32 arg0){
    D_8037C100[1] = arg0;
    func_8029217C(arg0);
}

void func_8029217C(f32 arg0){
    D_8037C110[1] = arg0;
}

void func_80292188(void (*draw_func)(Gfx **gfx, Mtx **mtx, Vtx **vtx)){
    D_8037C12C = draw_func;
}

void func_80292194(f32 arg0[3]){
    ml_vec3f_copy(D_8037C120, arg0);
}

void func_802921BC(f32 arg0){
    D_8037C120[1] = arg0;
}

void func_802921C8(s32 arg0){
    D_8037C0E8 = arg0;
}

void func_802921D4(f32 arg0[3]){
    if(func_8028EE84() == BSWATERGROUP_0_NONE){
        D_8037C150.unk0 = 1;
        D_8037C150.unk4[0] = arg0[0];
        D_8037C150.unk4[1] = arg0[1];
        D_8037C150.unk4[2] = arg0[2];
    }
}

f32 func_80292224(void){
    return D_8037C0F8;
}

f32 func_80292230(void){
    return D_8037C100[1];
}

void func_8029223C(f32 arg0[3]){
    func_80291A60(8, arg0);
}

void func_80292260(f32 arg0[3]){
    func_80291A60(7, arg0);
}

void func_80292284(f32 arg0[3], s32 arg1){
    f32 sp44[3];
    f32 sp38[3];

    if(_player_getMarker()->unk14_21 && D_8037C0E8){
        switch(func_80291FAC()){
            case 0x34D:
            case 0x34E:
            case ASSET_34F_MODEL_BANJO_TERMITE: //802922E8
            case ASSET_359_MODEL_BANJO_WALRUS: //802922E8
            case ASSET_362_MODEL_BANJO_BEE:
            case ASSET_36F_MODEL_BANJO_PUMPKIN:
            case ASSET_374_MODEL_BANJO_CROC:
                func_8034A174(D_80363780, arg1 + 1, arg0);
                if(func_802582EC(arg0)){
                    _player_getPosition(arg0);
                }
                
                arg0[1] += D_8037C130[arg1][0];
                if(D_8037C130[arg1][1] != 0.0f){
                    func_80256E24(sp44, D_8037C130[arg1][2],  mlNormalizeAngle(yaw_get() + D_8037C130[arg1][3]), 0.0f, 0.0f, D_8037C130[arg1][1]);
                    arg0[0] += sp44[0]; 
                    arg0[1] += sp44[1]; 
                    arg0[2] += sp44[2]; 
                }
                func_802976C0(sp38);
                arg0[0] = arg0[0] + sp38[0];
                arg0[1] = arg0[1] + sp38[1];
                arg0[2] = arg0[2] + sp38[2];
                break;
            default: ////80292400
                _player_getPosition(arg0);
                break;
        }
    }
    else{//L80292410
        _player_getPosition(arg0);
        if(arg1){
            arg0[1] += 33.0f;
        }
        else{
            arg0[1] += 75.0f;
        }
    }
}

void banjo_getPosition(f32* dst){
    f32 tmp1[3];
    f32 tmp2[3];
    func_80291A60(5,tmp1);
    func_80291A60(6,tmp2);
    ml_vec3f_add(dst, tmp1, tmp2);
    ml_vec3f_scale(dst, 0.5);
}

void func_802924B8(f32 arg0[3]){
    func_80291A60(0xA, arg0);
}

s32 func_802924DC(void){
    return D_8037C0E7;
}

void func_802924E8(f32 arg0[3]){
    switch(player_getTransformation()){
        case TRANSFORM_5_CROC:
            func_80291A60(5, arg0);
            break;
        case TRANSFORM_4_WALRUS: //L80292520
            func_80291A60(0xB, arg0);
            break;
        default: //L80292530
            func_80291A60(0x9, arg0);
            break;
    }
}

s32 func_80292548(void){
    return D_8037C0E8;
}

void func_80292554(f32 arg0[3]){
    func_80291A60(0x9, arg0);
}

void func_80292578(f32 arg0[3]){
    func_80291A60(0xA, arg0);
}

void func_8029259C(void){
    if(D_80363780){
        D_80363780 = func_8034A348(D_80363780);
    }
}
