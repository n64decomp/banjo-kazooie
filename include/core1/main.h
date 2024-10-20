#ifndef BANJO_KAZOOIE_CORE1_MAIN_H
#define BANJO_KAZOOIE_CORE1_MAIN_H

void func_8023DA20(s32 arg0);
void func_8023DA74(void);
void func_8023DA9C(s32 arg0);
u32 globalTimer_getTimeMasked(u32 mask);
//s32 globalTimer_getTime(void);
void globalTimer_reset(void);
enum map_e getSpecialBootMap(void);
enum map_e getDefaultBootMap(void);
void func_8023DBAC(void);
void func_8023DBDC(void);
void core1_init(void);
void globalTimer_incTimer(void);
void globalTimer_decTimer(void);
void mainLoop(void);
void mainThread_entry(void *arg);
void func_8023DFF0(s32 arg0);
s32 func_8023E000(void);
void setBootMap(enum map_e map_id);
void mainThread_create(void);
OSThread *mainThread_get(void);
void disableInput_set(void);

#endif
