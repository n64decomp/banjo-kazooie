#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern s32 D_80276588;
extern s32 D_8027658C;

extern BKSprite * D_8036A910;
extern BKSprite * D_8036A914;
extern Gfx D_8036A918[];

extern f32 D_80377480;

extern f32 D_80381EFC;
extern s32 D_80381F00;
extern f32 D_80381F04;
extern f32 D_80381F08[];
extern struct8s D_80381F30;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80300C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80300C70.s")

struct8s *func_80300CD8(s32 item_id){
    func_80300C10();
    D_80381EFC = D_80377480;
    return &D_80381F30;
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80300D0C.s")
#else
void func_80300D0C(enum item_e item_id, struct8s *arg1, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    int i; 
    int tmp_v1;
    s32 spEC;
    s32 spE8;
    int tmp_v0;
    f32 f18;
    f32 f14;
    f32 f20;
    s32 spD4 = 0;
    s32 s6;

    if(D_8036A910 == NULL) return;

    gSPDisplayList((*gfx)++, D_8036A918);
    func_80347FC0(gfx, D_8036A910, 0, 0, 0, 0, 0, 2, 2, &spEC, &spE8);
    func_8024C7B8(gfx, mtx);
    //loop over each honeycomb piece
    for(i = D_80381F00-1; i >= 0; i--){//L80300E40
        if(i != 0 && (i + 1 != D_80381F00 || D_80381F00 & 1)
        ){
            if(i & 1){
                s6 = i +1;
            }
            else{
                s6 = i -1;
            }
        }
        else{//L80300E84
            s6 = i;
        }
        gDPPipeSync((*gfx)++);
        if(i < D_80381F04){
            if( 8.0f < i && i < D_80381F04 - 8.0f){
                if(!spD4){
                    func_80347FC0(gfx, D_8036A914, 0, 0, 0, 0, 0, 2, 2, &spEC, &spE8);
                    spD4 = TRUE;
                }
            }//L80300F38
            gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        else{//L80300F58
           gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0x78); 
        }
        f20 = i*0xd + (96.0f - (f32)D_80276588/2);
        f14 = (f32)D_8027658C/2 - func_802FB0E4(arg1);
        f14 = (f14 - D_80381F08[s6]) - -48.0f;
        f14 = (i & 1) ? f14 + 5.75 : f14 - 5.75;
        gSPVertex((*gfx)++, *vtx, 4, 0);
        for(tmp_v1 = 0; tmp_v1 < 2; tmp_v1++){//L8030101C
            for(tmp_v0 = 0; tmp_v0 < 2; tmp_v0++){//L80301030
                f18 = spEC * D_80381EFC*tmp_v0 - spEC * D_80381EFC/2;
                f18 += f20;
                f18 *= 4.0f;
                (*vtx)->v.ob[0] = f18;

                f18 = spE8 * D_80381EFC/2 - spE8 * D_80381EFC*tmp_v1;
                f18 += f14;
                f18 *= 4.0f;
                (*vtx)->v.ob[1] = f18;
                (*vtx)->v.ob[2] = -0x14;
                (*vtx)->v.tc[0] =  ((spEC - 1) *tmp_v0) << 6;
                (*vtx)->v.tc[1] =  ((spE8 - 1) *tmp_v1) << 6;
                (*vtx)++;
            }
        }
        gSP1Quadrangle((*gfx)++, 0, 1, 3, 2, 0);
    }
    gDPPipeSync((*gfx)++);
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
    func_8024C904(gfx, mtx);
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_803012B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_803012F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301348.s")

//BREAK???

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_803016F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_8030179C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_803017D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301D24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_79C80/func_80301DE4.s")
