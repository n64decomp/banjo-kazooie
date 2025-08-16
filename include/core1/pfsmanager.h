#ifndef BANJO_KAZOOIE_CORE1_PFSMANAGER_H
#define BANJO_KAZOOIE_CORE1_PFSMANAGER_H

typedef struct pfs_manager_face_buttons_s {
    bool button_a;
    bool button_b;
    bool button_c_left;
    bool button_c_up;
    bool button_c_down;
    bool button_c_right;
} PfsManagerFaceButtons;

typedef struct pfs_manager_side_buttons_s {
    bool button_z;
    bool button_l;
    bool button_r;
} PfsManagerSideButtons;

typedef struct pfs_manager_controller_data {
    union { s32 face_button[6]; PfsManagerFaceButtons face_button2; };
    union { s32 side_button[3]; PfsManagerSideButtons side_button2; };
    s32 unk24[4];
    s32 start_button;
} PfsManagerControllerData;

typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    f32 unk8[2];
    f32 joystick[2];
}Struct_core1_10A00_1;

f32 func_8024E420(s32 arg0, s32 arg1, s32 arg2);
void controller_copyFaceButtons(s32 controller_index, s32 dst[6]);
void pfsManager_getFirstControllerFaceButtonState(s32 controller_index, s32 dst[6]);
s32 func_8024E5E8(s32 arg0, s32 arg1);
s32 controller_copySideButtons(s32 controller_index, s32 dst[3]);
s32 func_8024E640(s32 controller_index, s32 dst[3]);
f32 func_8024E668(s32 controller_index);
s32 controller_getStartButton(s32 controller_index);
s32 func_8024E698(s32 controller_index);
void func_8024E6E0(s32 controller_index, s32 dst[4]);
void controller_getJoystick(s32 controller_index, f32 dst[2]);
void pfsManager_update(void);
void pfsManager_readData();
void pfsManager_entry(void *arg);
void pfsManager_init(void);
bool pfsManager_contErr(void);
void func_8024F150(void);
void func_8024F180(void);
void pfsManager_getStartReadData(void);
void func_8024F1F0(void);
void func_8024F224(void);
void func_8024F2E4(s32 arg0, Struct_core1_10A00_1 *arg1);
void func_8024F328(s32 controller_index, s32 arg1);
OSMesgQueue * pfsManager_getFrameReplyQ(void);
OSMesgQueue *pfsManager_getFrameMesgQ(void);
void func_8024F35C(s32 arg0);
bool pfsManager_isBusy(void);
int func_8024F3C4(int arg0);
OSContPad *func_8024F3F4(void);
void func_8024F400(void);
void func_8024F450(void);
void func_8024F4AC(void);

#endif
