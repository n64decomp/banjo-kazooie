#include <ultra64.h>
#include "functions.h"
#include "variables.h"


extern u8 D_80370338[];
extern u32 D_80383634;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803355F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_8033567C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_8033568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803356A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_8033579C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803358B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335A80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80335D30.s")

void func_8033687C( Gfx **glp )
 {
     /* Turn off texturing */
     gDPPipeSync((*glp)++);
     if (D_80370338[0] == 0) {
        gDPSetColorDither((*glp)++, 0);
        D_80370338[0] = 1;
     }

     if(D_80383634 == 0x0E){
         gDPSetAlphaCompare((*glp)++, G_AC_NONE);
     }
 }

void func_80336904(Gfx **glp, Mtx *mptr, BKSprite *sp, u32 frame){
    func_80336924(glp, mptr, sp, frame, 0);
}

// extern u32 D_80383638;
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80336924.s")
//  func_80336924(Gfx **glp, Mtx *mptr, BKSprite *sp, u32 frame, u32 arg4){
// //     s32 sp_type;
//     BKSpriteFrame *framePtr;
//     BKSpriteTextureBlock *chunkPtr;
//     u32 chunk_block;
//     u32 chkDataSize;
//     u32 chunkSize;
//     u16* palPtr;
//     s32 i;

//     func_80349AD0();
  
//     if (sp->type & 0x1) {
//         chkDataSize = 1;
//     } else if (sp->type & 0x4) {
//         chkDataSize = 2;
//     } else if (sp->type & 0x40){
//         chkDataSize = 2;
//     } else if (sp->type & 0x100){
//         chkDataSize = 2;
//     } else if (sp->type & 0x400) {
//         chkDataSize = 4;
//     } else if (sp->type & 0x800){
//         chkDataSize = 8;
//     }
  
//     func_80335D30(glp);
//     if(D_80383638 || (sp->type & 4)){
//         gDPPipelineMode((*glp)++, G_PM_1PRIMITIVE);
//     }

//     framePtr = spriteGetFramePtr(sp, frame);

//     chunkPtr = ((u32) (framePtr + 1));
//     if (sp->type & 0x1) { //CI4
//         gDPSetTextureLUT((*glp)++, G_TT_NONE);
//         gDPLoadTLUT_pal16((*glp)++, 0, ((u32) (framePtr + 1) + 0xF));
//         chunkPtr = ((u32)chunkPtr + 0x20);
//     } else if (sp->type & 0x4) {//CI8
//         gDPSetTextureLUT((*glp)++, G_TT_RGBA16);
//         palPtr = ((u32) (framePtr + 1) + 0xF) & ~7;
//         gDPLoadTLUT_pal256((*glp)++, 0, palPtr);
//         chunkPtr = ((u32)palPtr + 0x200);
//     }

//     if(arg4){
//         gSPVertex((*glp)++, 0, 0, 0, mptr);
//     }else{
//         gSPVertex((*glp)++, 0, 0, 0, 0);
//     }

//     for(i = 0; i < framePtr->chunkCnt; i++){
//         // temp_ra = phi_t2->unk6;
//         // temp_t8_3 = (phi_t2 + 0xF) & ~7;
//         // sp1A8 = temp_t8_3;
//         // temp_a0_3 = arg2->unk2;
//         // temp_s3 = phi_s2 * 2;
//         // sp44 = temp_s3 + 4;
//         // sp48 = temp_s3 + 6;
//         // temp_fp = temp_s3 + 2;
//         chunk_block = (((u32) (chunkPtr + 1) + 0xF) & 0xFFFFFFF8);
//         if (sp->type & 0x400) { //RGBA16
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_RGBA, G_IM_SIZ_16b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);

//         } else if (sp->type & 0x800) { //RGBA32
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_RGBA, G_IM_SIZ_32b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);

//         } else if (sp->type & 1) { //CI4
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_CI, G_IM_SIZ_16b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
//         } else if (sp->type & 4) { //CI8
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_CI, G_IM_SIZ_16b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);

//         } else if (sp->type & 0x100) {
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_CI, G_IM_SIZ_16b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
//         } else if (sp->type & 0x40) {
//             gDPLoadTextureBlock((*glp)++, chunk_block, G_IM_FMT_I, G_IM_SIZ_8b, 
//                 chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
//         }
//         gSP1Triangle((*glp)++,0,1,2,0);
// //         temp_a2 = *arg0;
// //         temp_v1_69 = temp_s3 & 0xFF;
// //         *arg0 = (void *) (temp_a2 + 8);
// //         if (phi_s2 == 0) {
// //             temp_t9 = sp48 & 0xFF;
// //             phi_a0_7 = (temp_v1_69 << 0x10) | ((temp_fp & 0xFF) << 8) | temp_t9;
// //             phi_v1_3 = temp_v1_69;
// //             phi_a1 = temp_t9;
// //         } else {
// //             if (phi_s2 == 1) {
// //                 temp_t6 = sp48 & 0xFF;
// //                 temp_v1_70 = temp_s3 & 0xFF;
// //                 phi_t1_8 = ((temp_fp & 0xFF) << 0x10) | (temp_t6 << 8) | temp_v1_70;
// //                 phi_v1_3 = temp_v1_70;
// //                 phi_a1 = temp_t6;
// //             } else {
// //                 temp_t8_5 = sp48 & 0xFF;
// //                 temp_v1_71 = temp_s3 & 0xFF;
// //                 phi_t1_8 = (temp_t8_5 << 0x10) | (temp_v1_71 << 8) | (temp_fp & 0xFF);
// //                 phi_v1_3 = temp_v1_71;
// //                 phi_a1 = temp_t8_5;
// //             }
// //             phi_a0_7 = phi_t1_8;
// //         }
// //         temp_a2->unk0 = (s32) (phi_a0_7 | 0xB1000000);
// //         if (phi_s2 == 0) {
// //             temp_a2->unk4 = (s32) ((phi_v1_3 << 0x10) | (phi_a1 << 8) | (sp44 & 0xFF));
// //         } else {
// //             if (phi_s2 == 1) {
// //                 phi_a0_8 = (phi_a1 << 0x10) | ((sp44 & 0xFF) << 8) | phi_v1_3;
// //             } else {
// //                 phi_a0_8 = ((sp44 & 0xFF) << 0x10) | (phi_v1_3 << 8) | phi_a1;
// //             }
// //             temp_a2->unk4 = phi_a0_8;
// //         }
// //         temp_a2_2 = phi_t2->unk0 - temp_v0->unk0;
// //         temp_f0 = (f32) D_80383640 / (f32) temp_v0->unk4;
// //         phi_t1_7 = temp_v0->unk2 - phi_t2->unk2;
// //         phi_t0 = 0;
// // loop_95:
// //         temp_a1 = ((temp_ra << 6) * phi_t0) - 0x20;
// //         temp_f4 = (s32) ((f32) phi_t1_7 * ((f32) D_80383644 / (f32) temp_v0->unk6));
// //         temp_t3 = phi_t3 - 1;
// //         temp_lo = (phi_t2->unk4 - 1) * 0;
// //         phi_a3 = phi_a3_4;
// //         phi_lo = temp_lo;
// //         phi_v1_4 = 0;
// //         phi_a3_2 = phi_a3_4;
// //         phi_lo_2 = temp_lo;
// //         phi_v1_5 = 0;
// //         if (temp_t3 != 0) {
// // loop_96:
// //             phi_a3->unk2 = (s16) temp_f4;
// //             phi_a3->unk4 = (u16)0;
// //             temp_a3_2 = phi_a3 + 0x10;
// //             temp_a3_2->unk-10 = (s16) (s32) ((f32) (phi_lo + temp_a2_2) * temp_f0);
// //             temp_a3_2->unk-6 = temp_a1;
// //             temp_a3_2->unk-4 = 0x7F80;
// //             temp_v1_72 = phi_v1_4 + 1;
// //             temp_a3_2->unk-8 = (s16) (((phi_t2->unk4 << 6) * phi_v1_4) - 0x20);
// //             temp_lo_2 = (phi_t2->unk4 - 1) * temp_v1_72;
// //             phi_a3 = temp_a3_2;
// //             phi_lo = temp_lo_2;
// //             phi_v1_4 = temp_v1_72;
// //             phi_a3_2 = temp_a3_2;
// //             phi_lo_2 = temp_lo_2;
// //             phi_v1_5 = temp_v1_72;
// //             if (temp_v1_72 != temp_t3) {
// //                 goto loop_96;
// //             }
// //         }
// //         phi_a3_2->unk2 = (s16) temp_f4;
// //         phi_a3_2->unk4 = (u16)0;
// //         temp_t3_2 = temp_t3 + 1;
// //         temp_a3_3 = phi_a3_2 + 0x10;
// //         temp_a3_3->unk-10 = (s16) (s32) ((f32) (phi_lo_2 + temp_a2_2) * temp_f0);
// //         temp_a3_3->unk-6 = temp_a1;
// //         temp_a3_3->unk-4 = 0x7F80;
// //         temp_a3_3->unk-8 = (s16) (((phi_t2->unk4 << 6) * phi_v1_5) - 0x20);
// //         temp_t0 = phi_t0 + 1;
// //         phi_t3 = temp_t3_2;
// //         phi_t1_7 = (phi_t1_7 - temp_ra) + 1;
// //         phi_t0 = temp_t0;
// //         phi_a3_4 = temp_a3_3;
// //         if (temp_t0 != temp_t3_2) {
// //             goto loop_95;
// //         }
// //         temp_s2_2 = phi_s2 + 4;
// //         phi_s2_3 = temp_s2_2;
// //         if (temp_s2_2 == 0x10) {
// //             if (arg4 != 0) {
// //                 sp1B4->unk0 = 0x40040FF;
// //                 sp1B4->unk4 = (s32) ((arg4 << 0x18) + (sp1B0 - sp184));
// //             } else {
// //                 sp1B4->unk0 = 0x40040FF;
// //                 sp1B4->unk4 = sp1B0;
// //             }
// //             temp_v1_73 = *arg0;
// //             sp1B0 = temp_a3_3;
// //             sp1B4 = temp_v1_73;
//              if (arg4 != 0) {
// //                 *arg0 = (void *) (temp_v1_73 + 8);
// //                 temp_v1_73->unk0 = 0x400FFFF;
// //                 temp_v1_73->unk4 = (void *) ((arg4 << 0x18) + (temp_a3_3 - sp184));
// //                 phi_s2_3 = 0;
//              } else {
// //                 *arg0 = (void *) (temp_v1_73 + 8);
// //                 temp_v1_73->unk0 = 0x400FFFF;
// //                 temp_v1_73->unk4 = temp_a3_3;
// //                 phi_s2_3 = 0;
//              }
// //         }
//            chunkSize = chunkPtr->w * chunkPtr->h * chkDataSize;
//            chunkPtr = chunk_block + chunkSize/2;
//     }

//     gDPPipeSync((*glp)++);
//     if((sp->type & 0x1) || (sp->type & 0x1)){
//         gDPSetTextureLUT((*glp)++, G_TT_NONE);
//     }
//     gDPPipelineMode((*glp)++, G_MDSFT_BLENDMASK);
//     func_8033687C(glp);
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80337B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803380A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803380F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803381B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803382B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803382D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803382E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803382F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_803382FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_8033831C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_80338370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AE5D0/func_8033837C.s")
