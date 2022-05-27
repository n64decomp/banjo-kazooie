#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern int func_8024DB50(f32[3], f32 );
extern void func_802EFF5C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF7C(ParticleEmitter *, f32, f32, f32);
extern void func_802EFF9C(ParticleEmitter *, f32);

void func_80363310(Actor *this);
void func_80363330(Actor *this);

//this may be the inner structs of a prop(?)
typedef struct{
    s16 x;
    s16 y;
    s16 z;
    u16 unk8_7:9;
    u16 pad8_6:7;
}struct_core2_DB010;

/* .data */
extern ActorInfo D_803732E0= {
    0x1F7, 0x1E7, 0, 
    0, NULL, 
    func_80363310, func_80363330, func_80325340,
    {0,0}, 0, 0.0f, {0,0,0,0}
}; 

extern struct40s D_80373304;
// 000E C370:             3E CC CC CD  3F B3 33 33 00 00 00 00
// 000E C380: 00 00 00 00 00 00 00 00  3C 23 D7 0A 40 80 00 00
// 000E C390: 40 80 00 00 3F 00 00 00  3F 33 33 33 40 80 00 00
// 000E C3A0: 41 70 00 00 

extern struct43s D_80373334;
//                        C3 7A 00 00  44 16 00 00 C3 7A 00 00
// 000E C3B0: 43 AF 00 00 44 70 00 00  43 AF 00 00 00 00 00 00
// 000E C3C0: C4 96 00 00 00 00 00 00  00 00 00 00 C4 96 00 00
// 000E C3D0: 00 00 00 00 C2 70 00 00  C1 F0 00 00 C2 70 00 00
// 000E C3E0: 42 70 00 00 41 F0 00 00  42 70 00 00 

extern s32 D_8037337C[3] = {50, 255, 50};

extern struct40s D_80373388;
//                                     3E 99 99 9A 3C F5 C2 8F
// 000E C400: 3F 00 00 00 3F 00 00 00  00 00 00 00 3C 23 D7 0A
// 000E C410: 3F C0 00 00 40 00 00 00  3D 75 C2 8F 3F 33 33 33
// 000E C420: 40 80 00 00 3F 80 00 00  

extern struct42s D_803733B8;
//                                     C0 A0 00 00 42 C8 00 00
// 000E C430: C0 A0 00 00 40 A0 00 00  42 C8 00 00 40 A0 00 00
// 000E C440: C2 70 00 00 00 00 00 00  C2 70 00 00 42 70 00 00
// 000E C450: 40 A0 00 00 42 70 00 00  

extern s32 D_803733E8[3] = {0xb4, 0xe6, 0xff};


extern struct40s D_803733F4;
//                        3F 80 00 00  3F E6 66 66 40 0C CC CD
// 000E C470: 40 2C CC CD 00 00 00 00  3C 23 D7 0A 3F 4C CC CD
// 000E C480: 3F 99 99 9A 3E D1 EB 85  3F 3A E1 48 40 80 00 00
// 000E C490: 41 70 00 00 

extern struct43s D_80373424;
//                        C3 96 00 00  44 16 00 00 C3 96 00 00
// 000E C4A0: 43 96 00 00 44 7A 00 00  43 96 00 00 00 00 00 00
// 000E C4B0: C4 96 00 00 00 00 00 00  00 00 00 00 C4 C8 00 00
// 000E C4C0: 00 00 00 00 C1 20 00 00  00 00 00 00 C1 20 00 00
// 000E C4D0: 41 20 00 00 00 00 00 00  41 20 00 00 

extern struct40s D_8037346C;
//                                                 3E 99 99 9A
// 000E C4E0: 3E CC CC CD 3F 00 00 00  3F 00 00 00 00 00 00 00
// 000E C4F0: 3C 23 D7 0A 3F 4C CC CD  3F 99 99 9A 3F 68 F5 C3
// 000E C500: 3F 7D 70 A4 40 80 00 00  41 90 00 00

extern struct43s D_8037349C;
//                                                 C3 48 00 00
// 000E C510: 44 61 00 00 C3 48 00 00  43 48 00 00 44 AF 00 00
// 000E C520: 43 48 00 00 00 00 00 00  C4 E1 00 00 00 00 00 00
// 000E C530: 00 00 00 00 C5 16 00 00  00 00 00 00 C1 20 00 00
// 000E C540: C1 A0 00 00 C1 20 00 00  41 20 00 00 C1 A0 00 00
// 000E C550: 41 20 00 00 

extern struct40s D_803734E4;
//                        40 4C CC CD  40 59 99 9A 00 00 00 00
// 000E C560: 00 00 00 00 00 00 00 00  3C 23 D7 0A 40 00 00 00
// 000E C570: 40 00 00 00 00 00 00 00  3E 99 99 9A 40 80 00 00
// 000E C580: 41 70 00 00 C4 6D 80 00  44 48 00 00 C3 7A 00 00
// 000E C590: C4 09 80 00 44 AA 00 00  42 48 00 00 C4 2F 00 00
// 000E C5A0: C4 D4 80 00 00 00 00 00  C4 61 00 00 C4 D4 80 00
// 000E C5B0: 00 00 00 00 C2 70 00 00  00 00 00 00 C2 70 00 00
// 000E C5C0: 42 70 00 00 41 F0 00 00  42 70 00 00 40 40 00 00
// 000E C5D0: 40 59 99 9A 00 00 00 00  00 00 00 00 00 00 00 00
// 000E C5E0: 3C 23 D7 0A 40 80 00 00  40 80 00 00 00 00 00 00
// 000E C5F0: 3E 99 99 9A 40 80 00 00  41 70 00 00 C3 E1 00 00
// 000E C600: 44 16 00 00 C2 48 00 00  C3 16 00 00 44 89 80 00
// 000E C610: 42 48 00 00 C4 2F 00 00  C4 D4 80 00 00 00 00 00
// 000E C620: C4 48 00 00 C4 D4 80 00  00 00 00 00 C2 70 00 00
// 000E C630: 00 00 00 00 C2 70 00 00  42 70 00 00 41 F0 00 00
// 000E C640: 42 70 00 00 3F 8C CC CD  3F 8C CC CD 40 89 99 9A
// 000E C650: 40 89 99 9A 00 00 00 00  3D 4C CC CD 3E 99 99 9A
// 000E C660: 3F 00 00 00 3D 75 C2 8F  3E 99 99 9A 40 80 00 00
// 000E C670: 3F 80 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E C680: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E C690: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E C6A0: 00 00 00 00 00 00 00 0A  00 00 00 FF 00 00 00 0A
// 000E C6B0: 40 00 00 00 40 00 00 00  40 40 00 00 40 60 00 00
// 000E C6C0: 00 00 00 00 3C 23 D7 0A  40 00 00 00 40 20 00 00
// 000E C6D0: 3D CC CC CD 3E CC CC CD  40 80 00 00 3F 80 00 00
// 000E C6E0: 00 00 00 00 42 20 00 00  00 00 00 00 00 00 00 00
// 000E C6F0: 42 B4 00 00 00 00 00 00  C3 C8 00 00 00 00 00 00
// 000E C700: C3 C8 00 00 43 C8 00 00  00 00 00 00 43 C8 00 00
// 000E C710: 00 00 00 FF 00 00 00 FF  00 00 00 FF 3C 23 D7 0A
// 000E C720: 3C 23 D7 0A 3F C0 00 00  3F CC CC CD 3D 4C CC CD
// 000E C730: 3F 33 33 33 3F 33 33 33  3F A6 66 66 3D CC CC CD
// 000E C740: 3F 4C CC CD 40 80 00 00  41 C8 00 00 3F 33 33 33
// 000E C750: 3F 66 66 66 3E CC CC CD  3F 00 00 00 00 00 00 00
// 000E C760: 3C 23 D7 0A 3F 4C CC CD  3F 80 00 00 3E 19 99 9A
// 000E C770: 3E 99 99 9A 00 00 00 00  3F 80 00 00 C1 20 00 00
// 000E C780: C1 20 00 00 C1 20 00 00  41 20 00 00 41 20 00 00
// 000E C790: 41 20 00 00 00 00 00 00  41 F0 00 00 00 00 00 00
// 000E C7A0: 00 00 00 00 41 F0 00 00  00 00 00 00 3D 4C CC CD
// 000E C7B0: 3D CC CC CD 3D CC CC CD  3E 4C CC CD 00 00 00 00
// 000E C7C0: 3C 23 D7 0A 3F B3 33 33  3F C0 00 00 3C 23 D7 0A
// 000E C7D0: 3F 33 33 33 00 00 00 00  3F 80 00 00 C0 A0 00 00
// 000E C7E0: C0 A0 00 00 C0 A0 00 00  40 A0 00 00 40 A0 00 00
// 000E C7F0: 40 A0 00 00 00 00 00 00  C2 48 00 00 00 00 00 00
// 000E C800: 00 00 00 00 C2 B4 00 00  00 00 00 00 C1 F0 00 00
// 000E C810: 41 F0 00 00 C1 F0 00 00  41 F0 00 00 42 70 00 00
// 000E C820: 41 F0 00 00 00 00 00 FF  00 00 00 FF 00 00 00 00
// 000E C830: 3D CC CC CD 3E 99 99 9A  3F 19 99 9A 3F 33 33 33
// 000E C840: 00 00 00 00 3C 23 D7 0A  3E 99 99 9A 3E CC CC CD
// 000E C850: 3C 23 D7 0A 3E 99 99 9A  40 80 00 00 41 80 00 00
// 000E C860: C4 16 00 00 C4 16 00 00  C4 16 00 00 44 16 00 00
// 000E C870: 44 16 00 00 44 16 00 00  00 00 00 00 41 F0 00 00
// 000E C880: 00 00 00 00 00 00 00 00  41 F0 00 00 00 00 00 00



extern s32 D_80373514;

extern s32 D_8037355C;

extern s32 D_8037358C;

extern s32 D_803735D4;

extern struct42s D_80373604;

extern s32 D_80373634;

extern s32 D_80373640;

extern struct42s D_80373670;

extern s32 D_803736A0[3];

extern struct40s D_803736AC;

extern s32 D_803736DC;

extern struct42s D_8037370C;

extern s32 D_8037373C;

extern s32 D_8037376C;

extern s32 D_803737B4;

extern s32 D_803737C0;

extern struct42s D_803737F0;


extern s32 D_80373820[3] = {130, 155, 40};
extern struct40s D_8037382C;
//                                                 40 53 33 33
// 000E C8A0: 40 53 33 33 40 90 00 00  40 96 66 66 00 00 00 00
// 000E C8B0: 3C 23 D7 0A 3F E6 66 66  40 4C CC CD 3E 9E B8 52
// 000E C8C0: 3F 3A E1 48 40 80 00 00  41 30 00 00 

extern struct43s D_8037385C;
//                                                 C3 48 00 00
// 000E C8D0: 42 F0 00 00 C3 48 00 00  43 48 00 00 43 02 00 00
// 000E C8E0: 43 48 00 00 00 00 00 00  C2 C8 00 00 00 00 00 00
// 000E C8F0: 00 00 00 00 C2 C8 00 00  00 00 00 00 C1 F0 00 00
// 000E C900: 00 00 00 00 C1 F0 00 00  41 F0 00 00 00 00 00 00
// 000E C910: 41 F0 00 00 

extern s32 D_803738A4[3] = {91, 142, 0};
extern struct40s D_803738B0;
// 000E C920: 3E 4C CC CD 3F 66 66 66  3E CC CC CD 3F 66 66 66
// 000E C930: 00 00 00 00 3C 23 D7 0A  3F E6 66 66 40 86 66 66
// 000E C940: 3E 9E B8 52 3F 3A E1 48  40 80 00 00 41 50 00 00

extern struct43s D_803738E0;
// 000E C950: C3 C8 00 00 44 02 00 00  C3 C8 00 00 43 C8 00 00
// 000E C960: 44 3B 80 00 43 C8 00 00  00 00 00 00 C4 96 00 00
// 000E C970: 00 00 00 00 00 00 00 00  C4 C8 00 00 00 00 00 00
// 000E C980: C1 F0 00 00 00 00 00 00  C1 F0 00 00 41 F0 00 00
// 000E C990: 00 00 00 00 41 F0 00 00 

extern s32 D_80373928[3] = {0, 255, 0};
extern struct40s D_80373934;
                    //    3F B3 33 33  3F F3 33 33 40 19 99 9A
// 000E C9B0: 40 39 99 9A 00 00 00 00  40 4C CC CD 41 0C CC CD
// 000E C9C0: 41 13 33 33 3E 9E B8 52  3F 3A E1 48 40 80 00 00
// 000E C9D0: 41 50 00 00 

extern struct43s D_80373964;
//                        C2 70 00 00  42 C8 00 00 C2 70 00 00
// 000E C9E0: 42 70 00 00 43 2A 00 00  42 70 00 00 00 00 00 00
// 000E C9F0: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CA00: 00 00 00 00 C1 F0 00 00  00 00 00 00 C1 F0 00 00
// 000E CA10: 41 F0 00 00 00 00 00 00  41 F0 00 00

extern s32 D_803739AC[3] = {255, 255, 255};
extern struct40s D_803739B8;
//                                     3E 4C CC CD 3F 66 66 66
// 000E CA30: 3E 99 99 9A 3E CC CC CD  00 00 00 00 3E 4C CC CD
// 000E CA40: 3F 80 00 00 3F 99 99 9A  3E 9E B8 52 3F 3A E1 48
// 000E CA50: 40 80 00 00 41 50 00 00  

extern struct43s D_803739E8;
//                                     C4 16 00 00 00 00 00 00
// 000E CA60: C4 16 00 00 44 16 00 00  00 00 00 00 44 16 00 00
// 000E CA70: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CA80: 00 00 00 00 00 00 00 00  00 00 00 00 42 20 00 00
// 000E CA90: 00 00 00 00 00 00 00 00  42 20 00 00 00 00 00 00

extern s32 D_80373A30[3] = {255, 255, 255};
extern struct40s D_80373A3C;
//                                                 3F C0 00 00
// 000E CAB0: 3F CC CC CD 40 20 00 00  40 39 99 9A 00 00 00 00
// 000E CAC0: 3C 23 D7 0A 40 00 00 00  40 20 00 00 3D CC CC CD
// 000E CAD0: 3E CC CC CD 40 80 00 00  3F 80 00 00 

extern struct43s D_80373A6C;
//                                                 00 00 00 00
// 000E CAE0: 42 20 00 00 00 00 00 00  00 00 00 00 42 B4 00 00
// 000E CAF0: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CB00: 00 00 00 00 00 00 00 00  00 00 00 00 C0 A0 00 00
// 000E CB10: 00 00 00 00 C0 A0 00 00  40 A0 00 00 00 00 00 00
// 000E CB20: 40 A0 00 00


extern s32 D_80373AB4[3] = {30, 30, 30};
extern struct40s D_80373AC0;
// 000E CB30: 40 40 00 00 40 59 99 9A  40 79 99 9A 40 83 33 33
// 000E CB40: 00 00 00 00 3C 23 D7 0A  40 00 00 00 40 20 00 00
// 000E CB50: 3E 99 99 9A 3F 00 00 00  40 80 00 00 3F 80 00 00

extern struct43s D_80373AF0;
// 000E CB60: 42 C8 00 00 42 20 00 00  42 C8 00 00 42 C8 00 00
// 000E CB70: 42 B4 00 00 42 C8 00 00  00 00 00 00 00 00 00 00
// 000E CB80: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CB90: C0 A0 00 00 00 00 00 00  C0 A0 00 00 40 A0 00 00
// 000E CBA0: 00 00 00 00 40 A0 00 00

extern s32 D_80373B38[3] = {130, 130, 130};
extern struct40s D_80373B44;
//                        40 00 00 00  40 19 99 9A 40 79 99 9A
// 000E CBC0: 40 83 33 33 00 00 00 00  3C 23 D7 0A 40 00 00 00
// 000E CBD0: 40 20 00 00 3E 4C CC CD  3F 33 33 33 40 80 00 00
// 000E CBE0: 3F 80 00 00 

extern struct43s D_80373B74;
//                        42 C8 00 00  42 20 00 00 42 C8 00 00
// 000E CBF0: 42 C8 00 00 42 B4 00 00  42 C8 00 00 00 00 00 00
// 000E CC00: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CC10: 00 00 00 00 C0 A0 00 00  00 00 00 00 C0 A0 00 00
// 000E CC20: 40 A0 00 00 00 00 00 00  40 A0 00 00  

extern s32 D_80373BBC[3] = {0xff, 0xff, 0xff};
extern struct40s D_80373BC8;
//                                     3F 00 00 00 3F 19 99 9A
// 000E CC40: 3F C0 00 00 3F F3 33 33  00 00 00 00 3C 23 D7 0A
// 000E CC50: 40 80 00 00 40 90 00 00  3D CC CC CD 3F 4C CC CD
// 000E CC60: 00 00 00 00 3F 80 00 00  

extern struct43s D_80373BF8;
//                                     00 00 00 00 42 20 00 00
// 000E CC70: 00 00 00 00 00 00 00 00  42 B4 00 00 00 00 00 00
// 000E CC80: 00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CC90: 00 00 00 00 00 00 00 00  C0 A0 00 00 00 00 00 00
// 000E CCA0: C0 A0 00 00 40 A0 00 00  00 00 00 00 40 A0 00 00

extern s32 D_80373C40[3] = {160, 170, 170};
extern struct40s D_80373C4C;
//                                                 40 20 00 00
// 000E CCC0: 40 26 66 66 40 60 00 00  40 79 99 9A 00 00 00 00
// 000E CCD0: 3C 23 D7 0A 3E 99 99 9A  3F 00 00 00 3D CC CC CD
// 000E CCE0: 3F 4C CC CD 40 80 00 00  3F 80 00 00 

extern struct43s D_80373C7C;
//                                                 C2 70 00 00
// 000E CCF0: C2 70 00 00 C2 70 00 00  42 70 00 00 42 70 00 00
// 000E CD00: 42 70 00 00 00 00 00 00  00 00 00 00 00 00 00 00
// 000E CD10: 00 00 00 00 00 00 00 00  00 00 00 00 C2 48 00 00
// 000E CD20: C2 48 00 00 C2 48 00 00  42 48 00 00 42 48 00 00
// 000E CD30: 42 48 00 00 

extern s32 D_80373CC4[] = {90, 90, 90};
extern struct40s D_80373CD0;
// 3FC00000 3FCCCCCD 40200000 4039999A
// 00000000 3C23D70A 3E99999A 3F000000
// 3DCCCCCD 3F4CCCCD 40800000 3F800000

extern struct43s D_80373D00 = {
    {{-60.0f, -60.0f}, {-60.0f, 60.0f}, {60.0f, 60.0f}},
    {{0.0f, -0.0f, -0.0f}, {-0.0f, -0.0f, -0.0f}},
    {{-50.0f, -50.0f, -50.0f}, {50.0f, 50.0f, 50.0f}}
};

extern struct40s D_80373D48 = {
    { {1.8f, 3.5f}, {1.8f, 3.5f}, {0.0f, 0.01f}, {5.0f, 5.0f}, 0.0f, 0.9f}, 
    4.0f, 
    15.0f 
};

extern struct43s D_80373D78 = {
    {{-450.0f, 700.0f}, {-450.0f, 450.0f}, {1100.0f, 450.0f}},
    {{   0.0f, -900.0f,    0.0f}, {  0.0f, -900.0f,   0.0f}},
    {{-150.0f, -100.0f, -150.0f}, {150.0f,    5.0f, 150.0f}}
};



/* .code */
void func_80361FA0(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xFU);
    particleEmitter_setModel(pCtrl, 0x441);
    particleEmitter_setPosition(pCtrl, arg0);
    func_802EFE24(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    func_802EF9EC(pCtrl, 0x2F, 0x3E80);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373334);
    func_802EFC28(pCtrl, &D_80373304);
    FUNC_8030E624(SFX_7C_CHEBOOF, 0x38A, 0x265);
}

void func_80362084(f32 position[3]) {
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(1U);
    particleEmitter_setSprite(pCtrl, 0x702);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
    func_802EFFA8(pCtrl, &D_8037337C);
    func_802EF9E4(pCtrl, 0xA0);
    particleEmitter_setPosition(pCtrl, position);
    func_802EFF5C(pCtrl, 0.1f, 0.2f, 0.0f);
    func_802EFF7C(pCtrl, 0.0f, 0.25f, 0.0f);
    func_802EFF9C(pCtrl, 0.5f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_803733B8);
    func_802EFC28(pCtrl, &D_80373388);
}


void func_8036215C(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xFU);
    particleEmitter_setSprite(pCtrl, 0x700);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 4);
    func_802EFFA8(pCtrl, &D_803733E8);
    func_802EF9E4(pCtrl, 0x28);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373424);
    func_802EFC28(pCtrl, &D_803733F4);
}

void func_803621F0(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0x12U);
    particleEmitter_setSprite(pCtrl, 0x702);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 5);
    func_802EF9E4(pCtrl, 0xD2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8037349C);
    func_802EFC28(pCtrl, &D_8037346C);
}

void func_80362274(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xFU);
    particleEmitter_setModel(pCtrl, 0x89B);
    particleEmitter_setPosition(pCtrl, arg0);
    func_802EFE24(pCtrl, -400.0f, -200.0f, -400.0f, 400.0f, -400.0f, 400.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373514);
    func_802EFC28(pCtrl, &D_803734E4);
}

void func_8036233C(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xFU);
    particleEmitter_setModel(pCtrl, 0x89A);
    particleEmitter_setPosition(pCtrl, arg0);
    func_802EFE24(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    func_802EF9F8(pCtrl, 0.01f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8037358C);
    func_802EFC28(pCtrl, &D_8037355C);
}

void func_80362404(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(1U);
    particleEmitter_setSprite(pCtrl, 0x6DD);
    particleEmitter_setStartingFrameRange(pCtrl, 2, 2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_80373604);
    func_802EFC28(pCtrl, &D_803735D4);
}

void func_8036247C(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(1U);
    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, &D_80373634);
    func_802EF9E4(pCtrl, 0x64);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_80373670);
    func_802EFC28(pCtrl, &D_80373640);
}

void func_80362510(Actor *actor) {
    ParticleEmitter *pCtrl;
    f32 sp30[3];

    pCtrl = partEmitList_pushNew(0x19U);
    particleEmitter_setSprite(pCtrl, 0x70D);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 5);
    func_802EFFA8(pCtrl, D_803736A0);
    func_802EF9E4(pCtrl, 0x1E);
    particleEmitter_setPosition(pCtrl, actor->position);
    particleEmitter_setParticleSpawnPositionRange(pCtrl, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    sp30[0] = 1000.0f;
    sp30[1] = 100.0f;
    sp30[2] = 0.0f;
    ml_vec3f_roll_rotate_copy(sp30, sp30, actor->roll);
    ml_vec3f_yaw_rotate_copy(&sp30, &sp30, actor->yaw);
    particleEmitter_setParticleVelocityRange(pCtrl, 
        sp30[0] * 0.01, sp30[1] * 0.01, sp30[2] * 0.01, 
        sp30[0] * 0.4, sp30[1] * 0.4, sp30[2] * 0.4
    );
    func_802EFC28(pCtrl, &D_803736AC);
}


void func_80362680(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(1U);
    particleEmitter_setSprite(pCtrl, 0x45A);
    particleEmitter_setStartingFrameRange(pCtrl, 2, 2);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8037370C);
    func_802EFC28(pCtrl, &D_803736DC);
}

void func_803626F8(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(1U);

    particleEmitter_setSprite(pCtrl, 0x713);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8037376C);
    func_802EFC28(pCtrl, &D_8037373C);
}


void func_80362770(f32 arg0[3]) {
    ParticleEmitter *pCtrl = partEmitList_pushNew(0x10U);

    particleEmitter_setSprite(pCtrl, 0x714);
    particleEmitter_setStartingFrameRange(pCtrl, 7, 8);
    func_802EFFA8(pCtrl, &D_803737B4);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_803737F0);
    func_802EFC28(pCtrl, &D_803737C0);
}

void func_803627F8(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(11);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373820);
    func_802EF9E4(pCtrl, 120);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8037385C);
    func_802EFC28(pCtrl, &D_8037382C);
}

void func_8036288C(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xd);
    particleEmitter_setSprite(pCtrl, ASSET_702_SPRITE_UNKNOWN);
    particleEmitter_setStartingFrameRange(pCtrl, 3, 4);
    func_802EFFA8(pCtrl, D_803738A4);
    func_802EF9E4(pCtrl, 255);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_803738E0);
    func_802EFC28(pCtrl, &D_803738B0);
}

void func_80362920(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xd);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373928);
    func_802EF9E4(pCtrl, 60);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373964);
    func_802EFC28(pCtrl, &D_80373934);
}

void func_803629B4(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xd);
    particleEmitter_setSprite(pCtrl, ASSET_713_SPRITE_SPARKLE_YELLOW);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_803739AC);
    func_802EF9E4(pCtrl, 255);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_803739E8);
    func_802EFC28(pCtrl, &D_803739B8);
}

void func_80362A48(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373A30);
    func_802EF9E4(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373A6C);
    func_802EFC28(pCtrl, &D_80373A3C);
}

void func_80362ADC(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373AB4);
    func_802EF9E4(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373AF0);
    func_802EFC28(pCtrl, &D_80373AC0);
}

void func_80362B70(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373B38);
    func_802EF9E4(pCtrl, 110);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373B74);
    func_802EFC28(pCtrl, &D_80373B44);
}

void func_80362C04(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373BBC);
    func_802EF9E4(pCtrl, 40);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373BF8);
    func_802EFC28(pCtrl, &D_80373BC8);
}

void func_80362C98(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 1, 6);
    func_802EFFA8(pCtrl, D_80373C40);
    func_802EF9E4(pCtrl, 140);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373C7C);
    func_802EFC28(pCtrl, &D_80373C4C);
}

void func_80362D2C(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(1);
    particleEmitter_setSprite(pCtrl, ASSET_70D_SPRITE_SMOKE_1);
    particleEmitter_setStartingFrameRange(pCtrl, 4, 6);
    func_802EFFA8(pCtrl, D_80373CC4);
    func_802EF9E4(pCtrl, 140);
    particleEmitter_setPosition(pCtrl, arg0);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373D00);
    func_802EFC28(pCtrl, &D_80373CD0);
}

void func_80362DC0(f32 arg0[3]){
    ParticleEmitter *pCtrl = partEmitList_pushNew(0xF);
    particleEmitter_setModel(pCtrl, ASSET_47B_MODEL_ROCK);
    particleEmitter_setPosition(pCtrl, arg0);
    func_802EFE24(pCtrl, -200.0f, 200.0f, -200.0f, 200.0f, 200.0f, 200.0f);
    func_802EF9F8(pCtrl, 0.4f);
    func_802EFA18(pCtrl, 3);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    func_802EFA70(pCtrl, 2);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80373D78);
    func_802EFC28(pCtrl, &D_80373D48);
}

void func_80362E94(Actor *this){
    f32 tick = time_getDelta();

    switch(this->unkF4_8){
        case 0x3: //L80362ED8
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.2){
                func_80362084(this->position);
            }
            break;
        case 0xa: //L80362F24
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.1){
                func_8036247C(this->position);
            }
            break;
        case 0xc: //L80362F70
            if(func_8024DB50(this->position, 50.0f)){
                if(randf() < 0.4)
                    func_80362680(this->position);
                if(randf() < 0.8)
                    func_803626F8(this->position);
            }
            break;
        case 0x10://L80362FE8
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.1){
                func_80362A48(this->position);
            }
            break;
        case 0x11://L80363034
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.06){
                func_80362ADC(this->position);
            }
            break;
        case 0x12://L80363080
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.06){
                func_80362C04(this->position);
            }
            break;
        case 0x13://L803630CC
            if(func_8024DB50(this->position, 50.0f) && randf() < 0.4){
                func_80362B70(this->position);
            }
            break;
        case 0x14://L80363118
            if(func_8024DB50(this->position, 300.0f)){
                if(randf() < 0.01)
                    func_80362C98(this->position);
                func_80362D2C(this->position);
            }
            break;
        default: //L8036316C
            if(!this->unk16C_4){
                this->unk16C_4 = 1;
                this->unk60 = this->scale*10.0;
            }

            this->unk60 = MAX(0.0, this->unk60 - tick);
            if(0.0f == this->unk60){
                switch(this->unkF4_8){
                    case 2: //L8036325C
                        func_80361FA0(this->position);
                        break;
                    case 7: //L8036326C
                        func_8036215C(this->position);
                        func_803621F0(this->position);
                        break;
                    case 8: //L80363288
                        func_80362274(this->position);
                        func_8036233C(this->position);
                        break;
                    case 0x2A: //L803632A4
                        func_80362510(this);
                        break;
                    case 0x2B: //L803632B4
                        func_803627F8(this->position);
                        func_8036288C(this->position);
                        func_803629B4(this->position);
                        break;
                    case 0x2C: //L803632D8
                        func_80362920(this->position);
                        break;
                    case 0x2D: //L803632E8
                        func_80362DC0(this->position);
                        break;
                }
                marker_despawn(this->marker);
            }
            break;
    }
}

void func_80363310(Actor *this){
    func_80362E94(this);
}

void func_80363330(Actor *this){
    func_80343DEC(this);
    func_80362E94(this);
    if(this->unk48 == 1.0)
        marker_despawn(this->marker);
}

void func_80363388(struct_core2_DB010 *arg0, s32 arg1){
    f32 sp2C[3];
    s32 sp20[3];
    s32 tmp_v0 = func_80330F94(arg0, sp20);
    sp2C[0] = (f32)sp20[0];
    sp2C[1] = (f32)sp20[1];
    sp2C[2] = (f32)sp20[2];
    switch(tmp_v0){
        case 0x29: //L803633F0
            func_80362770(sp2C);
            break;
        case 0x34: //L80363400
            func_80361FA0(sp2C);
            break;
        case 0x35: //L80363410
            func_80362274(sp2C);
            func_8036233C(sp2C);
            break;
        case 0x36: //L80363428
            func_80362404(sp2C);
            break;
        case 0x2A: 
            //case used to force switch to have proper functions
            // could be any unused value(s) between (0x29 and 0x36)
            break;
    }

}