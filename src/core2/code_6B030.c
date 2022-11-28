#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s16 D_803A5D00[2][0xF660];


extern f32 func_80257680(f32, f32, f32);
extern void func_80252330(f32, f32, f32);

typedef struct {
    s16 unk0;
    s16 unk2;
}Struct_core2_6B030_1;

typedef struct {
    BKSprite *unk0;
    BKSprite *unk4;
}Struct_core2_6B030_0;

/* .data */
Struct_core2_6B030_0 *D_80368AB0 = NULL;
s16 D_80368AB4 = 0;
s16 D_80368AB8 = 0;

Gfx D_80368AC0[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetCombineLERP(TEXEL1, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_PASS, G_RM_ZB_XLU_SURF2),
    gsSPEndDisplayList()
};

Gfx D_80368B08[] = {
    gsDPPipeSync(),
    gsDPSetCombineLERP(TEXEL0, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, SHADE, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 0, 0x50, 0xF0, 0xFF, 0xFF),
    gsSPEndDisplayList()
};

Struct_core2_6B030_1 D_80368B28[] = {
    {0x704, 0xFFFF},
    {0x705, 0xFFFF}
};

/* .bss */
f32 *D_80380A10;
Mtx D_80380A18;
s32 D_80380A58;

/* .code */
void func_802F1FC0(Struct65s *self, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    f32 temp_f2;
    s16 *temp_addr;
    f32 spDC[3];
    f32 spD0[3];
    s32 temp_t9;
    s32 temp_s3;
    s32 spC4;
    s32 spC0;
    s32 spBC;
    s32 temp_s5;
    s32 width;
    s32 height;

    func_8024C5CC(spDC);
    spD0[0] = self->unk0[0] - spDC[0];
    spD0[1] = self->unk0[1] - spDC[1];
    spD0[2] = self->unk0[2] - spDC[2];
    func_80251BCC(func_8024DD90());
    func_80252330(spD0[0], spD0[1], spD0[2]);
    mlMtxApply(*mtx);
    gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL((*mtx)++), G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    
    temp_f2 = D_80380A10[self->unk26] * (self->unk25 / 255.0f);
    spBC = (s32) ((f32)self->unk20 * (1.0f + temp_f2));
    temp_s5 = (s32) ((f32)self->unk20 * ((1.0f - (self->unk25 / 255.0f)) + ((self->unk25 / 255.0f) - temp_f2)));
    func_80251BCC(&D_80380A18);
    func_8025235C(&spD0, &spD0);
    spD0[0] = (-297.0f * spD0[0]) / spD0[2];
    spD0[1] = (297.0f * spD0[1]) / spD0[2];
    spC4 = (s32) (spD0[0] + (f32) (D_80276588 / 2));
    spC0 = (s32) (spD0[1] + (f32) (D_8027658C / 2));
    if (spC4 < 0) {
        spC4 = 0;
    } else if (D_80276588 - 0x20 < spC4) {
        spC4 = D_80276588 - 0x20;
    }
    if (spC0 < 0) {
        spC0 = 0;
    } else if (D_8027658C - 0x20 < spC0) {
        spC0 = D_8027658C - 0x20;
    }
    
    gSPDisplayList((*gfx)++, D_80368AC0);
    func_80347FC0(gfx, D_80368AB0[1].unk0, 0, 0, 0, 0, 0, NULL, NULL, &width, &height);
    temp_addr = &D_803A5D00[func_8024BD80()][spC0*D_80276588 + (spC4 & 0xFFFC)];
    gDPSetTextureImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80276588, temp_addr);
    gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 9, 0x0080, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync((*gfx)++);
    gDPLoadTile((*gfx)++, G_TX_LOADTILE, 0, 0, 0x008C, 0x007C);
    gDPPipeSync((*gfx)++);
    gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 9, 0x0080, 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize((*gfx)++, 1, ((3 - (spC4 % 4)) + 1 - 1)<< 2, 0, (((3 - (spC4 % 4)) + 0x20) - 1)<<2, 0x007C);
    gSPVertex((*gfx)++, *vtx, 8, 0);
    gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
    func_80349AD0();
    func_80347FC0(gfx, (D_80368AB0 + self->unk22)->unk0, 0, 0, 0, 0, 0, 2, 2, &width, &height);
    if ((D_80368AB0 + self->unk22)->unk4 != NULL) {
        func_80347FC0(gfx, (D_80368AB0 + self->unk22)->unk4, 0, 0x100, 1, 0, 0, 2, 2, &width, &height);
    }
    gSPDisplayList((*gfx)++, D_80368B08);
    gSP2Triangles((*gfx)++, 7, 4, 5, 0, 6, 4, 7, 0);
    func_80349B1C(gfx);
    gDPSetTextureLOD((*gfx)++, G_TL_LOD);
    gSPPopMatrix((*gfx)++, G_MTX_MODELVIEW);
    for(spC0 = 0; spC0 < 2; spC0++){
        for( spC4 = 0; spC4 < 2; spC4++){
            (*vtx)->n.ob[0] = -(spBC >> 1) + spC4*spBC;
            (*vtx)->n.ob[1] = (temp_s5 >> 1) - spC0*temp_s5;
            (*vtx)->n.ob[2] = 0;
            (*vtx)->n.tc[0] = (spC4*0x1F) << 6;
            (*vtx)->n.tc[1] = (spC0*0x1F) << 6;
            (*vtx)->n.n[0] = 0xB4;
            (*vtx)->n.n[1] = 0xF0;
            (*vtx)->n.n[2] = 0xFF;
            (*vtx)->n.a = 0xA0;
            (*vtx)++;
        }
    }

    for(spC0 = 0; spC0 < 2; spC0++){
        for(spC4 = 0; spC4 < 2; spC4++){
            (*vtx)->n.ob[0] = -(spBC >> 1) + spC4*spBC;
            (*vtx)->n.ob[1] = (temp_s5 >> 1) - spC0*temp_s5;
            (*vtx)->n.ob[2] = 0;
            (*vtx)->n.tc[0] = ((spC4 ^ 1)*(width - 1)) << 6;
            (*vtx)->n.tc[1] = (spC0*(height - 1)) << 6;
            (*vtx)->n.n[0] = 0xFF;
            (*vtx)->n.n[1] = 0xFF;
            (*vtx)->n.n[2] = 0xFF;
            (*vtx)->n.a = 0xFF;
            (*vtx)++;
        }
    }
}

void func_802F2740(Struct64s *arg0) {
    s32 i;
    Struct65s *i_ptr;
    Struct65s *end_ptr;

    i = 0;
    while (i < arg0->unk4 - 1) {
        i_ptr = &arg0->unk0[i];
        if (!(i_ptr->unk23 & 1)) {
            // if struct no longer active, 
            end_ptr = &arg0->unk0[arg0->unk4 - 1];
            if (i_ptr != end_ptr) {
                //if current indx not last index
                // copy end object to this position and reduce size (dropping this)
                memcpy(i_ptr, end_ptr, sizeof(Struct65s));
            } else {
                //else increment current index
                i++;
            }
            arg0->unk4 = arg0->unk4 - 1;


            if (arg0->unk4 != 0) {
                //if not empty, shrink struct
                arg0->unk0 = (Struct65s *)realloc(arg0->unk0, arg0->unk4 * sizeof(Struct65s));
            } else {
                //else (if empty) free struct
                free(arg0->unk0);
                arg0->unk0 = NULL;
            }
        } else {
            //else (index still active)
            //move to next
            i++;
        }
    }
}

void func_802F283C(Struct65s *arg0) {
    f32 sp1C;
    s32 sp18;

    sp1C = time_getDelta();
    sp18 = (s32) (200.0f * sp1C + 1.0f);
    arg0->unk0[0] +=  arg0->unk14[0] / 3.0f;
    arg0->unk0[1] +=  arg0->unk14[1] / 3.0f;
    arg0->unk0[2] +=  arg0->unk14[2] / 3.0f;
    if (arg0->unk14[0] != arg0->unk1A[0]) {
        arg0->unk14[0] += (arg0->unk14[0] < arg0->unk1A[0]) ? sp18 : -sp18;
    }
    if (arg0->unk14[1] != arg0->unk1A[1]) {
        arg0->unk14[1] += (arg0->unk14[1] < arg0->unk1A[1]) ? sp18 : -sp18;
    }
    if (arg0->unk14[2] != arg0->unk1A[2]) {
        arg0->unk14[2] += (arg0->unk14[2] < arg0->unk1A[2]) ? sp18 : -sp18;
    }

    if (arg0->unk24 <= 0) {
        arg0->unk24 = (s8) ((randf() * 5.0f) + 2.0f);
        arg0->unk1A[0] = (s16) ((randf() * 10.0f) + -5.0f);
        arg0->unk1A[2] = (s16) ((randf() * 10.0f) + -5.0f);
    } else {
        arg0->unk24 -= sp18;
    }

    if (arg0->unk20 != arg0->unk21) {
        arg0->unk20 += (arg0->unk20 < arg0->unk21) ? sp18 : -sp18;
    }
    arg0->unk26 += ((f32) (arg0->unk27 * 4) * sp1C);
}

void *func_802F2AEC(void) {
    u32 var_s1;
    Struct64s *temp_v0;


    if (D_80368AB4 == 0) {
        D_80368AB0 = malloc(0x10);
        if (D_80368AB0 == NULL) {
            return NULL;
        }

        for(var_s1 = 0; var_s1 < 2; var_s1++){
            if (D_80368B28[var_s1].unk0 >= 0) {
                (D_80368AB0 + var_s1)->unk0 = assetcache_get(D_80368B28[var_s1].unk0);
            } else {
                (D_80368AB0 + var_s1)->unk0 = NULL;
            }

            if (D_80368B28[var_s1].unk2 >= 0) {
                (D_80368AB0 + var_s1)->unk4 = assetcache_get(D_80368B28[var_s1].unk2);
            } else {
                (D_80368AB0 + var_s1)->unk4 = 0;
            }
        }

        D_80380A10 = (f32 *)malloc(0x100*sizeof(f32));
        for(var_s1 = 0; var_s1 < 0x100; var_s1++){
            D_80380A10[var_s1] = 0.0f;
        };
    }
    D_80368AB4++;
    temp_v0 = malloc(8);
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_v0->unk0 = 0;
    temp_v0->unk4 = 0;
    D_80380A58 = heap_get_size() - func_8025496C();
    return temp_v0;
}

void func_802F2C78(Struct64s *arg0) {
    s32 var_s1;
    Struct_core2_6B030_0 *i_ptr;


    if (arg0 != NULL) {
        if (arg0->unk0 != NULL) {
            free(arg0->unk0);
        }
        free(arg0);
        D_80368AB4 -= 1;
    }
    if (D_80368AB4 == 0) {
        if(D_80368AB0 != NULL){
            for(var_s1 = 0; var_s1 < 2; var_s1++){
                i_ptr = D_80368AB0 + var_s1;
                if (i_ptr->unk0 != NULL) {
                    assetcache_release(i_ptr->unk0);
                }
                i_ptr = D_80368AB0 + var_s1;
                if (i_ptr->unk4 != NULL) {
                    assetcache_release(i_ptr->unk4);
                }
            }
            free(D_80368AB0);
            D_80368AB0 = NULL;
            D_80368AB8 = 0;
        }

        if (D_80380A10 != NULL) {
            free(D_80380A10);
            D_80380A10 = NULL;
        }
    }
}


void func_802F2D8C(Struct64s *arg0) {
    Struct65s *var_s0;

    if ((arg0 != NULL) && (arg0->unk4 != 0)) {
        D_80380A58 = heap_get_size() - func_8025496C();
        for(var_s0 = arg0->unk0; var_s0 < arg0->unk0 + arg0->unk4; var_s0++){
            if (var_s0->unk23 & 1) {
                if (var_s0->unk10(var_s0->unk0, (f32)var_s0->unk20, var_s0->unkC) == 0) {
                    func_802F283C(var_s0);
                } else {
                    var_s0->unk23 &= ~1;
                }
            }
        }
        func_802F2740(arg0);
    }
}


void func_802F2EC0(Struct65s *arg0){
    arg0->unk23 &= ~1;
}

void func_802F2ED0(Struct64s *arg0, Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    Struct65s *phi_s0;
    f32 sp38[3];

    if (arg0 != NULL && arg0->unk4) {
        func_8024C764(sp38);
        mlMtxIdent();
        mlMtxRotPitch(-sp38[0]);
        mlMtxRotYaw(-sp38[1]);
        func_802513B0(&D_80380A18);
        for(phi_s0 = arg0->unk0; phi_s0 < arg0->unk0 + arg0->unk4; phi_s0++){
            if (phi_s0->unk23 & 1) {
                func_802F1FC0(phi_s0, gfx, mtx, vtx);
            }
        }
    }
}

void func_802F2FCC(Struct64s *arg0, f32 arg1[3], s16 arg2, f32 arg3, ActorMarker *arg4, s32(*arg5)(f32[3], f32, ActorMarker *)){
    Struct65s *var_v0;

    if (arg0 != NULL) {
        if ((arg0->unk4 != 0x20) && (D_80380A58 >= 0x19000)) {
            if ( arg0->unk0 != NULL) {
                var_v0 = (Struct65s *)realloc(arg0->unk0, (arg0->unk4 + 1)*sizeof(Struct65s));
            } else {
                var_v0 = malloc(sizeof(Struct65s));
            }
            if (var_v0 != NULL) {
                arg0->unk0 = var_v0;
                var_v0 += arg0->unk4;
                arg0->unk4++;
                var_v0->unk0[0] = arg1[0];
                var_v0->unk0[1] = arg1[1];
                var_v0->unk0[2] = arg1[2];
                var_v0->unk14[0] = 0;
                var_v0->unk14[1] = 0;
                var_v0->unk14[2] = 0;
                var_v0->unk1A[0] = 0;
                var_v0->unk1A[1] = arg2;
                var_v0->unk1A[2] = 0;
                var_v0->unk20 = 1;
                var_v0->unk21 = (u8) arg3;
                var_v0->unk22 = 0;
                var_v0->unk23 = 1;
                var_v0->unk24 = 0;
                var_v0->unk26 = (u8)(randf() * 255.0f);
                var_v0->unk27 = 0x14;
                var_v0->unk25 = (u8) (func_80257680(1.0f, 50.0f, arg3) * 64.0f);
                var_v0->unkC = arg4;
                var_v0->unk10 = arg5;
            }
        }
    }
}

void func_802F32C4(s32 arg0, f32 arg1[3], f32 arg2, ActorMarker *arg3, void(*arg4)(f32[3], f32, ActorMarker *)){
    func_802F2FCC(arg0, arg1, 8, arg2, arg3, arg4);
}

void func_802F3300(void) {
    if (!func_802559A0()) {
        if (D_80380A10 != NULL) {
            D_80380A10 = defrag(D_80380A10);
        }
        if (D_80368AB0 != NULL) {
            D_80368AB0 = defrag(D_80368AB0);
        }
    }
}

s32 func_802F3364(s32 arg0){
    return arg0;
}
