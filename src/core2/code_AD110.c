#include <ultra64.h>
#include "functions.h"
#include "variables.h"

//these funtions include references to overlay functions
extern void func_802DC528(s32, s32);
extern void func_802DC560(s32, s32);
extern void func_802DC748(s32, s32);
extern void func_802DC780(s32, s32);
extern void func_802DCD78(s32, s32);
extern void func_802DCDC0(s32, s32);
extern void func_8031D06C(s32, s32);
extern void func_8031D09C(s32, s32);
extern void func_8031D11C(s32, s32);
extern void func_8031D140(s32, s32);
extern void func_8031D164(s32, s32);
extern void func_8031D188(s32, s32);
extern void func_8031D1AC(s32, s32);
extern void func_8031D1D0(s32, s32);
extern void func_8031D1F4(s32, s32);
extern void func_8031DD10(s32, s32);
extern void func_8031DD44(s32, s32);
extern void func_8031DE2C(s32, s32);
extern void func_8031DE50(s32, s32);
extern void func_8031E818(s32, s32);
extern void func_8031E83C(s32, s32);
extern void func_8031E860(s32, s32);
extern void func_8031E884(s32, s32);
extern void func_8031E8A8(s32, s32);
extern void func_8031E8CC(s32, s32);
extern void func_8031E8F0(s32, s32);
extern void func_8031E914(s32, s32);
extern void func_8031E938(s32, s32);
extern void func_8031EA7C(s32, s32);
extern void func_8031EAA0(s32, s32);
extern void func_8031EAC4(s32, s32);
extern void func_8031EAE8(s32, s32);
extern void func_8031EC98(s32, s32);
extern void func_8031ECBC(s32, s32);
extern void func_8031ECE0(s32, s32);
extern void func_8031ED04(s32, s32);
extern void func_8031ED28(s32, s32);
extern void func_8031ED4C(s32, s32);
extern void func_8031ED70(s32, s32);
extern void func_8031ED94(s32, s32);
extern void func_8031EDB8(s32, s32);
extern void func_8031EDDC(s32, s32);
extern void func_8031EE00(s32, s32);
extern void func_8031EE24(s32, s32);
extern void func_8031EEFC(s32, s32);
extern void func_8031EF20(s32, s32);
extern void func_8031EF44(s32, s32);
extern void func_8031EF68(s32, s32);
extern void func_8031EF8C(s32, s32);
extern void func_8031EFB0(s32, s32);
extern void func_8031EFD4(s32, s32);
extern void func_8031EFF8(s32, s32);
extern void func_8031F01C(s32, s32);
extern void func_8031F040(s32, s32);
extern void func_8031F064(s32, s32);
extern void func_8031F088(s32, s32);
extern void func_8031F0AC(s32, s32);
extern void func_8031F13C(s32, s32);
extern void func_8031F160(s32, s32);
extern void func_8031F57C(s32, s32);
extern void func_8031F5A0(s32, s32);
extern void func_80334430(s32, s32);
extern void func_80363388(s32, s32);
extern void func_80386744(s32, s32);
extern void func_80388BEC(s32, s32);
extern void func_80388C00(s32, s32);
extern void func_80388C28(s32, s32);
extern void func_80388C50(s32, s32);
extern void CC_func_80388C78(s32, s32);
extern void func_8038A0E4(s32, s32);
extern void func_8038A150(s32, s32);
extern void func_8038F10C(s32, s32);
extern void func_8038F130(s32, s32);

extern void func_8031EE48(s32, s32);
extern void func_8031EE6C(s32, s32);
extern void func_8031EE90(s32, s32);
extern void func_8031EED8(s32, s32);
extern void func_8031EEB4(s32, s32);
extern void func_8031EB0C(s32, s32);
extern void func_8031EB30(s32, s32);
extern void func_8031EB54(s32, s32);
extern void func_8031EB78(s32, s32);
extern void func_8031D27C(s32, s32);
extern void func_8031D2F4(s32, s32);
extern void func_8031D2B4(s32, s32);
extern void func_8031D218(s32, s32);
extern void func_8031D23C(s32, s32);
extern void func_8031D334(s32, s32);
extern void func_8031D358(s32, s32);
extern void func_8031D37C(s32, s32);
extern void func_8031D3A0(s32, s32);
extern void func_8031D3C4(s32, s32);
extern void func_8031DCC8(s32, s32);
extern void func_8031DCEC(s32, s32);
extern void func_8031D3E8(s32, s32);
extern void func_8031D40C(s32, s32);
extern void func_8031D430(s32, s32);
extern void func_8031D454(s32, s32);
extern void func_8031D478(s32, s32);
extern void func_8031D49C(s32, s32);
extern void func_8031D4C0(s32, s32);
extern void func_8031D4E4(s32, s32);
extern void func_8031D628(s32, s32);
extern void func_8031D508(s32, s32);
extern void func_8031D52C(s32, s32);
extern void func_8031F0D0(s32, s32);
extern void func_8031FAB4(s32, s32);
extern void func_8031D598(s32, s32);
extern void func_8031D5BC(s32, s32);
extern void func_8031FA6C(s32, s32);
extern void func_8031FA90(s32, s32);
extern void func_8031D670(s32, s32);
extern void func_8031D694(s32, s32);
extern void func_8031D6B8(s32, s32);
extern void func_8031D6DC(s32, s32);
extern void func_8031DAE0(s32, s32);
extern void func_8031DA84(s32, s32);
extern void func_8031DC10(s32, s32);
extern void func_8031DC68(s32, s32);
extern void func_8031D700(s32, s32);
extern void func_8031D724(s32, s32);
extern void func_8031D748(s32, s32);
extern void func_8031D76C(s32, s32);
extern void func_8031D790(s32, s32);
extern void func_8031D7B4(s32, s32);
extern void func_8031D7D8(s32, s32);
extern void func_8031D7FC(s32, s32);
extern void func_8031D820(s32, s32);
extern void func_8031D844(s32, s32);
extern void func_8031D868(s32, s32);
extern void func_8031D88C(s32, s32);
extern void func_8031D8B0(s32, s32);
extern void func_8031D8D4(s32, s32);
extern void func_8031D8F8(s32, s32);
extern void func_8031D91C(s32, s32);
extern void func_8031D940(s32, s32);
extern void func_8031D964(s32, s32);
extern void func_8031D988(s32, s32);
extern void func_8031D9AC(s32, s32);
extern void func_8031D9D0(s32, s32);
extern void func_8031D9F4(s32, s32);
extern void func_8031DA18(s32, s32);
extern void func_8031DA3C(s32, s32);
extern void func_8031DA60(s32, s32);
extern void func_8031DB88(s32, s32);
extern void func_8031DD78(s32, s32);
extern void func_8031DD9C(s32, s32);
extern void func_8031DDC0(s32, s32);
extern void func_8031DDE4(s32, s32);
extern void func_8031DE08(s32, s32);
extern void func_8031DE74(s32, s32);
extern void func_8031DE98(s32, s32);
extern void func_8031DEBC(s32, s32);
extern void func_8031DF04(s32, s32);
extern void func_8031DF28(s32, s32);
extern void func_8031DF4C(s32, s32);
extern void func_8031DEE0(s32, s32);
extern void func_8031DF70(s32, s32);
extern void func_8031DF94(s32, s32);
extern void func_8031DFB8(s32, s32);
extern void func_8031DFDC(s32, s32);
extern void func_8031E000(s32, s32);
extern void func_8031E024(s32, s32);
extern void func_8031E048(s32, s32);
extern void func_8031E06C(s32, s32);
extern void func_8031E090(s32, s32);
extern void func_8031E0B4(s32, s32);
extern void func_8031E0D8(s32, s32);
extern void func_8031E0FC(s32, s32);
extern void func_8031E120(s32, s32);
extern void func_8031E144(s32, s32);
extern void func_8031E168(s32, s32);
extern void func_8031E18C(s32, s32);
extern void func_8031E1B0(s32, s32);
extern void func_8031E1D4(s32, s32);
extern void func_8031E2B8(s32, s32);
extern void func_8031E2E0(s32, s32);
extern void func_8031E308(s32, s32);
extern void func_8031E32C(s32, s32);
extern void func_8031E350(s32, s32);
extern void func_8031E374(s32, s32);
extern void func_8031E398(s32, s32);
extern void func_8031E3BC(s32, s32);
extern void func_8031E3E0(s32, s32);
extern void func_8031E404(s32, s32);
extern void func_8031E428(s32, s32);
extern void func_8031E44C(s32, s32);
extern void func_8031E470(s32, s32);
extern void func_8031E494(s32, s32);
extern void func_8031E4B8(s32, s32);
extern void func_8031E4DC(s32, s32);
extern void func_8031E500(s32, s32);
extern void func_8031E524(s32, s32);
extern void func_8031E548(s32, s32);
extern void func_8031E56C(s32, s32);
extern void func_8031E590(s32, s32);
extern void func_8031E5B4(s32, s32);
extern void func_8031E5D8(s32, s32);
extern void func_8031E5FC(s32, s32);
extern void func_8031E620(s32, s32);
extern void func_8031E644(s32, s32);
extern void func_8031E668(s32, s32);
extern void func_8031E68C(s32, s32);
extern void func_8031E6B0(s32, s32);
extern void func_8031E6D4(s32, s32);
extern void func_8031E6F8(s32, s32);
extern void func_8031E71C(s32, s32);
extern void func_8031E740(s32, s32);
extern void func_8031E764(s32, s32);
extern void func_8031E788(s32, s32);
extern void func_8031E7AC(s32, s32);
extern void func_8031E7D0(s32, s32);
extern void func_8031E7F4(s32, s32);
extern void func_8031E9EC(s32, s32);
extern void func_8031EA10(s32, s32);
extern void func_8031EA34(s32, s32);
extern void func_8031EA58(s32, s32);
extern void func_8031E95C(s32, s32);
extern void func_8031E980(s32, s32);
extern void func_8031E9A4(s32, s32);
extern void func_8031E9C8(s32, s32);
extern void func_8031EB9C(s32, s32);
extern void func_8031EBC0(s32, s32);
extern void func_8031EBE4(s32, s32);
extern void func_8031EC08(s32, s32);
extern void func_8031EC2C(s32, s32);
extern void func_8031EC50(s32, s32);
extern void func_8031EC74(s32, s32);
extern void func_8031F0F4(s32, s32);
extern void func_8031F118(s32, s32);
extern void func_8031F184(s32, s32);
extern void func_8031FA00(s32, s32);
extern void func_8031F558(s32, s32);
extern void func_8031F314(s32, s32);
extern void func_8031F2CC(s32, s32);
extern void func_8031F2F0(s32, s32);
extern void func_8031F25C(s32, s32);
extern void func_8031F294(s32, s32);
extern void func_8031F214(s32, s32);
extern void func_8031F238(s32, s32);
extern void func_8031F1A8(s32, s32);
extern void func_8031F1CC(s32, s32);
extern void func_8031F1F0(s32, s32);
extern void func_8031F338(s32, s32);
extern void func_8031F35C(s32, s32);
extern void func_8031F380(s32, s32);
extern void func_8031F3A4(s32, s32);
extern void func_8031F3C8(s32, s32);
extern void func_8031F3EC(s32, s32);
extern void func_8031F410(s32, s32);
extern void func_8031F520(s32, s32);
extern void func_8031F4E8(s32, s32);
extern void func_8031F434(s32, s32);
extern void func_8031F458(s32, s32);
extern void func_8031F47C(s32, s32);
extern void func_8031F4A0(s32, s32);
extern void func_8031F4C4(s32, s32);
extern void func_8031F5C4(s32, s32);
extern void func_8031F5E8(s32, s32);
extern void func_8031FB6C(s32, s32);
extern void func_8031F60C(s32, s32);
extern void func_8031F630(s32, s32);
extern void func_8031F654(s32, s32);
extern void func_8031F678(s32, s32);
extern void func_8031F69C(s32, s32);
extern void func_8031F6C0(s32, s32);
extern void func_8031F6E4(s32, s32);
extern void func_8031F708(s32, s32);
extern void func_8031F72C(s32, s32);
extern void func_8031F764(s32, s32);
extern void func_8031F79C(s32, s32);
extern void func_8031F7D4(s32, s32);
extern void func_8031F878(s32, s32);
extern void func_8031F8C0(s32, s32);
extern void func_8031F8E4(s32, s32);
extern void func_8031F908(s32, s32);
extern void func_8031F92C(s32, s32);
extern void func_8031F950(s32, s32);
extern void func_8031F974(s32, s32);
extern void func_8031F998(s32, s32);
extern void func_8031F9BC(s32, s32);
extern void func_8031FA24(s32, s32);
extern void func_8031FA48(s32, s32);
extern void func_8031FB14(s32, s32);

extern void func_802C1674(s32, s32);
extern void func_802C169C(s32, s32);
extern void TTC_func_80389BFC(s32, s32);
extern void func_80389C24(s32, s32);
extern void func_80389C4C(s32, s32);
extern void func_80389C74(s32, s32);
extern void func_80389C9C(s32, s32);
extern void func_80389CC4(s32, s32);
extern void func_802D2B94(s32, s32);
extern void func_802D2C24(s32, s32);
extern void func_8033443C(s32, s32);


typedef struct {
    f32 unk0[3];
    f32 unkC[3];
    f32 unk18;
    u8 unk1C;
    u8 pad1D[3];
}Struct_core2_AD110_0;

typedef void (*Method_core2_AD110)(s32, s32);

/* .data */
Method_core2_AD110 D_8036F980[] = {
    func_80388BEC, func_80334430, func_80386744, func_80386744,
    func_80386744, func_8031DE2C, func_8031DE50, func_8038F10C,
    func_8038F130, func_8031E83C, func_8031E818, func_8031E938,
    func_8031E860, func_8031E884, func_8031E8A8, func_8031E8CC,
    func_8031E8F0, func_8031E914, func_8031EA7C, func_8031EAA0,
    func_8031EAC4, func_8031EAE8, func_8031D11C, func_8031D140,
    func_8031D164, func_8031D188, func_8031D1AC, func_8031D1D0,
    func_8031D1F4, func_8031D09C, func_8031D06C, func_80334430,
    func_80334430, func_80334430, func_8031F13C, func_8031F160,
    func_8031F0AC, func_8031F088, func_8031F064, func_8031F01C,
    func_8031F040, func_8031EC98, func_8031ECBC, func_8031ECE0,
    func_8031ED04, func_8031ED28, func_8031ED4C, func_80388C00,
    func_80388C28, func_80388C50, CC_func_80388C78, func_80334430,
    func_80334430, func_80334430, func_802DC748, func_802DC780,
    func_8031F57C, func_8031F5A0, func_8031EFD4, func_8031EFF8,
    func_8031EF8C, func_8031EFB0, func_8031EF68, func_8031EF44,
    func_8031ED70, func_8031ED94, func_8031EDB8, func_8031EDDC,
    func_8031EE00, func_8031EE24, func_8031DD10, func_8031DD44,
    func_80363388, func_8038A0E4, func_8038A150, func_80334430,
    func_802DCD78, func_802DCDC0, func_802DC528, func_802DC560,
    func_8031EF20, func_8031EEFC, func_80334430, func_8031EED8,
    func_8031EEB4, func_8031EE90, func_8031EE6C, func_8031EE48,
    func_8031EB0C, func_8031EB30, func_8031EB54, func_8031EB78,
    func_8031D27C, func_8031D2F4, func_8031D2B4, func_8031D218,
    func_8031D23C, func_8031D334, func_8031D358, func_8031D37C,
    func_8031D3A0, func_8031D3C4, func_8031DCC8, func_8031DCEC,
    func_8031D3E8, func_8031D40C, func_8031D430, func_8031D454,
    func_8031D478, func_8031D49C, func_8031D4C0, func_8031D4E4,
    func_8031D628, func_8031D508, func_8031D52C, func_8031F0D0,
    func_8031FAB4, func_8031D598, func_8031D5BC, func_8031FA6C,
    func_8031FA90, func_8031D670, func_8031D694, func_8031D6B8,
    func_8031D6DC, func_8031DAE0, func_8031DA84, func_8031DC10,
    func_8031DC68, func_8031D700, func_8031D724, func_8031D748,
    func_8031D76C, func_8031D790, func_8031D7B4, func_8031D7D8,
    func_8031D7FC, func_8031D820, func_8031D844, func_8031D868,
    func_8031D88C, func_8031D8B0, func_8031D8D4, func_8031D8F8,
    func_8031D91C, func_8031D940, func_8031D964, func_8031D988,
    func_8031D9AC, func_8031D9D0, func_8031D9F4, func_8031DA18,
    func_8031DA3C, func_8031DA60, func_8031DB88, func_8031DD78,
    func_8031DD9C, func_8031DDC0, func_8031DDE4, func_8031DE08,
    func_8031DE74, func_8031DE98, func_8031DEBC, func_8031DF04,
    func_8031DF28, func_8031DF4C, func_8031DEE0, func_8031DF70,
    func_8031DF94, func_8031DFB8, func_8031DFDC, func_8031E000,
    func_8031E024, func_8031E048, func_8031E06C, func_8031E090,
    func_8031E0B4, func_8031E0D8, func_8031E0FC, func_8031E120,
    func_8031E144, func_8031E168, func_8031E18C, func_8031E1B0,
    func_8031E1D4, func_8031E2B8, func_8031E2E0, func_8031E308,
    func_8031E32C, func_8031E350, func_8031E374, func_8031E398,
    func_8031E3BC, func_8031E3E0, func_8031E404, func_8031E428,
    func_8031E44C, func_8031E470, func_8031E494, func_8031E4B8,
    func_8031E4DC, func_8031E500, func_8031E524, func_8031E548,
    func_8031E56C, func_8031E590, func_8031E5B4, func_8031E5D8,
    func_8031E5FC, func_8031E620, func_8031E644, func_8031E668,
    func_8031E68C, func_8031E6B0, func_8031E6D4, func_8031E6F8,
    func_8031E71C, func_8031E740, func_8031E764, func_8031E788,
    func_8031E7AC, func_8031E7D0, func_8031E7F4, func_8031E9EC,
    func_8031EA10, func_8031EA34, func_8031EA58, func_8031E95C,
    func_8031E980, func_8031E9A4, func_8031E9C8, func_8031EB9C,
    func_8031EBC0, func_8031EBE4, func_80334430, func_8031EC08,
    func_8031EC2C, func_8031EC50, func_8031EC74, func_8031F0F4,
    func_8031F118, func_8031F184, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430, func_80334430,
    func_80334430, func_8031FA00, func_8031F558, func_8031F314,
    func_8031F2CC, func_8031F2F0, func_8031F25C, func_8031F294,
    func_8031F214, func_8031F238, func_8031F1A8, func_8031F1CC,
    func_8031F1F0, func_8031F338, func_8031F35C, func_8031F380,
    func_8031F3A4, func_8031F3C8, func_8031F3EC, func_8031F410,
    func_8031F520, func_8031F4E8, func_8031F434, func_8031F458,
    func_8031F47C, func_8031F4A0, func_8031F4C4, func_8031F5C4,
    func_8031F5E8, func_8031FB6C, func_8031F60C, func_8031F630,
    func_8031F654, func_8031F678, func_8031F69C, func_8031F6C0,
    func_8031F6E4, func_8031F708, func_8031F72C, func_8031F764,
    func_8031F79C, func_8031F7D4, func_8031F878, func_8031F8C0,
    func_8031F8E4, func_8031F908, func_8031F92C, func_8031F950,
    func_8031F974, func_8031F998, func_8031F9BC, func_8031FA24,
    func_8031FA48, func_8031FB14, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430, func_80334430,
    func_80334430, func_80334430, func_80334430,
};

Method_core2_AD110 D_8036FE5C[] ={
    func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C169C, func_802C169C, func_802C169C,
    func_802C169C, func_802C1674, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, TTC_func_80389BFC, func_80389C24, func_80389C4C,
    func_80389C74, func_80389C9C, func_80389CC4, func_802D2B94,
    func_802D2C24, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C, func_8033443C, func_8033443C,
    func_8033443C, func_8033443C
};

/* .bss */
vector(Struct_core2_AD110_0) *D_803835C0;

/* .code */
bool func_803340A0(f32 arg0[3], f32 arg1[3], f32 arg2) {
    f32 sp4C[3];
    f32 sp40[3];
    Struct_core2_AD110_0 *begin_ptr;
    Struct_core2_AD110_0 *i_ptr;
    Struct_core2_AD110_0 *end_ptr;
    s32 i;

    for(i = 0; i < 3; i++){
        if (arg0[i] <= arg1[i]) {
            sp4C[i] = arg0[i] - arg2;
            sp40[i] = arg1[i] + arg2;
        } else {
            sp4C[i] = arg1[i] - arg2;
            sp40[i] = arg0[i] + arg2;
        }
    }

    end_ptr = (Struct_core2_AD110_0 *)vector_getEnd(D_803835C0);
    begin_ptr = (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0);
    for(i_ptr = begin_ptr; i_ptr < end_ptr; i_ptr++) {
        if( (i_ptr->unk1C == 1) 
            && ((!((i_ptr->unk0[0] + i_ptr->unk18) <= sp4C[0])) || !((i_ptr->unkC[0] + i_ptr->unk18) <= sp4C[0]))
            && ((!((i_ptr->unk0[1] + i_ptr->unk18) <= sp4C[1])) || !((i_ptr->unkC[1] + i_ptr->unk18) <= sp4C[1]))
            && ((!((i_ptr->unk0[2] + i_ptr->unk18) <= sp4C[2])) || !((i_ptr->unkC[2] + i_ptr->unk18) <= sp4C[2])) 
            && (!(sp40[0] <= (i_ptr->unk0[0] - i_ptr->unk18)) || !(sp40[0] <= (i_ptr->unkC[0] - i_ptr->unk18))) 
            && (!(sp40[1] <= (i_ptr->unk0[1] - i_ptr->unk18)) || !(sp40[1] <= (i_ptr->unkC[1] - i_ptr->unk18))) 
            && (!(sp40[2] <= (i_ptr->unk0[2] - i_ptr->unk18)) || !(sp40[2] <= (i_ptr->unkC[2] - i_ptr->unk18)))) {
            return FALSE;
        }
    }
    return TRUE;
}

s32 func_803342AC(f32 arg0[3], f32 arg1[3], f32 arg2){
    Struct_core2_AD110_0 * iPtr;
    Struct_core2_AD110_0 * end_ptr;

    if(!func_803340A0(arg0, arg1, arg2))
        return 0;

    end_ptr = (Struct_core2_AD110_0 *)vector_getEnd(D_803835C0);
    for(iPtr = (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0); iPtr < end_ptr; iPtr++){
        if(iPtr->unk1C == 0)
            break;
    }
    if(iPtr == end_ptr){
        iPtr = (Struct_core2_AD110_0 *)vector_pushBackNew(&D_803835C0);
    }
    iPtr->unk1C = 1;

    iPtr->unk0[0] = arg0[0];
    iPtr->unk0[1] = arg0[1];
    iPtr->unk0[2] = arg0[2];

    iPtr->unkC[0] = arg1[0];
    iPtr->unkC[1] = arg1[1];
    iPtr->unkC[2] = arg1[2];

    iPtr->unk18 = arg2;
    return (iPtr - (Struct_core2_AD110_0 *)vector_getBegin(D_803835C0)) + 1;
}


void func_803343AC(void){
    vector_free(D_803835C0);
}

void func_803343D0(void){
    D_803835C0 = vector_new(sizeof(Struct_core2_AD110_0), 2);
}

void func_803343F8(s32 indx){
    Struct_core2_AD110_0 *elem;
    elem = (Struct_core2_AD110_0 *)vector_at(D_803835C0, indx - 1);
    elem->unk1C = 0;
}

void func_80334428(void){}

void func_80334430(s32 arg0, s32 arg1){}

void func_8033443C(s32 arg0, s32 arg1){}

void func_80334448(NodeProp *arg0, ActorMarker *arg1) {
    s32 sp24;

    switch(func_80330F7C(arg0)) {
        case 3: //L80334480
            sp24 = func_8023DB5C();
            if ((func_80330FC4(arg0) + 1) != sp24) {
                D_8036F980[func_80330F8C(arg0)](arg0, arg1);
            }
            func_80330FBC(arg0, sp24);
            break;

        case 4: //L803344E0
            D_8036FE5C[func_80330F8C(arg0)](arg0, arg1);
            break;

        case 0: //L80334508
        case 1: //L80334508
        case 2: //L80334508
        case 5: //L80334508
            break;

    }
}


s32 func_8033451C(s32 arg0){
    return arg0 - 0x16;
}

s32 func_80334524(s32 arg0){
    return arg0 + 0xcc;
}

s32 func_8033452C(s32 arg0){
    return arg0 + 0x19d;
}
