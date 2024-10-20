#ifndef BANJO_KAZOOIE_CORE1_VIMGR_H
#define BANJO_KAZOOIE_CORE1_VIMGR_H

typedef struct struct_1_s{
    OSMesgQueue *messageQueue;
    OSMesg message;
} struct1;

u32 getOtherFramebuffer(void);
s32 viMgr_func_8024BD94(void);
s32 getActiveFramebuffer(void);
void viMgr_func_8024BDAC(OSMesgQueue *mq, OSMesg msg);
void viMgr_init(void);
void viMgr_func_8024BF94(s32 arg0);
s32 viMgr_func_8024BFA0(void);
void viMgr_func_8024BFAC(void);
void viMgr_func_8024BFD8(s32 arg0);
void viMgr_func_8024C1B4(void);
void viMgr_func_8024C1DC(void);
void viMgr_func_8024C1FC(OSMesgQueue *mq, OSMesg msg);
void viMgr_setActiveFramebuffer(s32 arg0);
void viMgr_entry(void *arg0);
void viMgr_setScreenBlack(s32 active);
void viMgr_clearFramebuffers(void);
s32 viMgr_func_8024C4E8(void);
void viMgr_func_8024C4F8(s32 arg0);

#endif
