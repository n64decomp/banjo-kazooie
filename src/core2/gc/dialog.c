#include <ultra64.h>
#include "core1/core1.h"
#include "functions.h"
#include "variables.h"
#include "dialog.h"

#include "zoombox.h"

extern void func_803114D0(void);
extern int gcdialog_hasCurrentTextId(void);
extern char *dialogBin_get(enum asset_e text_id);

s8 Y_POSITION_MODIFIERS[] = { 1, 0x1E, 0x14, 0xF, 0xB, 8, 6, 4, 3, 2, -1, -1 };
 
/* .bss */
struct {
    char output[0x100];
    u8 *dialog_bin_ptr;
    BKDialog *dialog[2]; // string ptr
    char *string[2]; // current_string
    u8 string_count[2]; // zoombox string_count
    s8 string_cmd[2]; // current_cmd
    u8 string_index[2]; // current_string_index
    struct15s unk11A[2];
    GcZoombox *zoombox[2];
    s16 zoomboxYPosition[2];

    union {
        struct {
            u8 unk128_31;
            u8 state;
            u8 unk128_15;
            u8 active_zoombox: 1; // active_zoombox_index
            u8 unk128_6: 1;
            u8 queueZoomboxYPositionModify: 1;
            u8 zoomboxYPositionIndexDecremented: 1;
            u8 unk128_3: 1;
            u8 pad128_2: 2;
            u8 unk128_0: 1;
            u8 unk12C_31: 2;
            u8 unk12C_29: 2;
            u8 unk12C_27: 2;
            u8 unk12C_25: 2;
            s8 playerHasConfirmed: 8;
            u8 unk12C_15: 4;
            u8 unk12C_11: 4;
            u8 pad12C_7: 8;
        } u8;
        struct {
            u32 unk128_31: 8;
            u32 state: 8;
            u32 unk128_15: 8;
            u32 active_zoombox: 1; // active_zoombox_index
            u32 unk128_6: 1;
            u32 queueZoomboxYPositionModify: 1;
            u32 zoomboxYPositionIndexDecremented: 1;
            u32 unk128_3: 1;
            u32 pad128_2: 2;
            u32 unk128_0: 1;
            u32 unk12C_31: 2;
            u32 unk12C_29: 2;
            u32 unk12C_27: 2;
            u32 unk12C_25: 2;
            s32 playerHasConfirmed: 8;
            u32 unk12C_15: 4;
            u32 unk12C_11: 4;
            u32 pad12C_7: 8;
        };
    };

    s16 currentTextId;
    s8 yPositionModifierIndex;
    u8 pad133[0x1];
    ActorMarker *caller;
    s32 unk138;
    void (* currentCallback)(ActorMarker *, s32, s32);
    void (* unk140)(ActorMarker *, s32, s32);
    s32 (* conditionalCallback)(ActorMarker *, s32, s32);
    struct14s unk148[4];
} g_Dialog;

char D_80382FF8[0x18];

/* .code */
int func_8030EDC0(ActorMarker *caller, s32 arg1) {
    return (arg1 == -1) ? 0 : caller->unk5C == arg1;
}

void gcdialog_init(void) {

    s32 i;
    g_Dialog.dialog_bin_ptr = 0;
    
    for (i = 0; i < 2; i++) {
        g_Dialog.dialog[i] = NULL;
        g_Dialog.string_count[i] = 0;
        g_Dialog.zoombox[i] = NULL;
        g_Dialog.string_index[i] = NULL;
        g_Dialog.string_cmd[i] = -1;
        g_Dialog.string[i] = 0;
        g_Dialog.unk11A[i].unk0_7 = 0;
        g_Dialog.unk11A[i].unk0_5 = 0;
    }

    for (i = 0; i < 4; i++) {
        g_Dialog.unk148[i].unk0 = -1;
        g_Dialog.unk148[i].unk2 = 0;
        g_Dialog.unk148[i].unk10 = NULL;
        g_Dialog.unk148[i].unk14 = 0;
        g_Dialog.unk148[i].unk18 = NULL;
        g_Dialog.unk148[i].unk1C = NULL;
        g_Dialog.unk148[i].unk20 = 0;
        g_Dialog.unk148[i].unk4[0] = g_Dialog.unk148[i].unk4[1] = g_Dialog.unk148[i].unk4[2] = 0;
    }

    g_Dialog.state = DIALOG_STATE_0;
    g_Dialog.unk128_31 = g_Dialog.queueZoomboxYPositionModify = FALSE;
    g_Dialog.unk12C_31 = g_Dialog.unk12C_29 = g_Dialog.unk12C_27 = g_Dialog.unk12C_25 = 0;
    g_Dialog.unk128_15 = g_Dialog.active_zoombox = FALSE;
    g_Dialog.unk128_6 = TRUE; 
    g_Dialog.playerHasConfirmed = -1;
    g_Dialog.unk12C_15 = g_Dialog.unk12C_11 = 0;
    g_Dialog.currentTextId = (s16) -1;
    g_Dialog.caller = NULL;
    g_Dialog.currentCallback = NULL;
    g_Dialog.unk140 = NULL;
    g_Dialog.conditionalCallback = 0;
    g_Dialog.yPositionModifierIndex = 12; // Length of array is 11, so intentionally setting out of bounds
    g_Dialog.unk128_3 = TRUE;
}

static void freeZoomboxes(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        gczoombox_free(g_Dialog.zoombox[i]);
        g_Dialog.zoombox[i] = NULL;
    }
}

void clearDialogStrings(void) {
    s32 i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < g_Dialog.string_count[i]; j++) {
            g_Dialog.dialog[i][j].str = NULL;
        }
        g_Dialog.string_count[i] = 0;
        free(g_Dialog.dialog[i]);
        g_Dialog.dialog[i] = NULL;
    }

    if (g_Dialog.currentTextId != -1) {
        dialogBin_release(g_Dialog.currentTextId);
    }

    g_Dialog.dialog_bin_ptr = NULL;
}

void clearDialog(void) {
   clearDialogStrings();

   if (g_Dialog.zoombox[DIALOG_TOP] != NULL && !g_Dialog.unk11A[DIALOG_TOP].unk0_7) {
       func_80347A14(1);
   }

   if (!g_Dialog.unk11A[DIALOG_BOTTOM].unk0_7 && !g_Dialog.unk11A[DIALOG_TOP].unk0_7) {
       freeZoomboxes();
   }

   g_Dialog.currentTextId = -1;
   g_Dialog.unk128_15 = 0;
   g_Dialog.unk128_31 = 0;
   g_Dialog.caller = NULL;
   g_Dialog.currentCallback = NULL;
   g_Dialog.unk140 = NULL;
   g_Dialog.conditionalCallback = NULL;
}

void func_8030F1D0(void) {
    if (gcdialog_hasCurrentTextId()) {
        func_8025A55C(-1, 300, 2);
    }

    func_803114D0();
    clearDialog();
    g_Dialog.state = DIALOG_STATE_0;
}

void replaceText(char *next_state, char *arg1, char *arg2, bool arg3, bool arg4) {
    s32 var_v0;
    s32 i;
    s32 j;

    var_v0 = 0;
    for (i = 0; arg1[i] != '\0'; i++) {
        if (arg1[i] == ((arg3) ? 0xE : '~')) {
            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x68;
            }

            for (j = 0; arg2[j] != '\0'; j++) {
                next_state[var_v0++] = arg2[j];
                if (arg4 && !arg3 && arg2[j] == ' ') {
                    next_state[var_v0++] = 0xFD;
                    next_state[var_v0++] = 0x68;
                }
            }

            if (arg4) {
                next_state[var_v0++] = 0xFD;
                next_state[var_v0++] = 0x6C;
            }
        } else {
            next_state[var_v0++] = arg1[i];
        }
    }

    next_state[var_v0] = '\0';
}

void func_8030F338(void) {
    if (g_Dialog.currentCallback != NULL) {
        if (g_Dialog.caller == NULL) {
            g_Dialog.currentCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.playerHasConfirmed);
        } else {
            if (func_8030EDC0(g_Dialog.caller, g_Dialog.unk138)) {
                g_Dialog.currentCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.playerHasConfirmed);
            }
        }
    }

    if (g_Dialog.unk128_31 & 0x8) {
        if ((!func_802E4A08() && !volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) || !g_Dialog.unk128_3) {
            func_8028F918(0);
        }
    } //L8030F3E8

    func_8025A55C(-1, 0x12c, 2);
    clearDialog();
}

void gcdialog_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 i;
    for (i = 0; i < 2; i++) {
        gczoombox_draw(g_Dialog.zoombox[i], gfx, mtx, vtx);
    }
}

void dialog_setState(DialogState next_state) {
    s32 i, j;
    s32 v0 = DIALOG_STATE_6;

    if (v0); // _possibly_ a debug assert that got optimized to an if. Can't remove it though!

    if (g_Dialog.state == v0 && next_state == v0) {
        return;
    }
    
    switch (next_state) {
        case DIALOG_STATE_1:
            for (i = 0; i < 2; i++) {
                if (g_Dialog.zoombox[i] != NULL && g_Dialog.unk11A[i].unk0_7 == 0) {
                    gczoombox_open(g_Dialog.zoombox[i]);
                }
            }
            break;

        case DIALOG_STATE_5:
            for (i = 0; i < 2; i++) {
                if (g_Dialog.zoombox[i] != NULL && g_Dialog.unk11A[i].unk0_7 == 0) {
                    gczoombox_minimize(g_Dialog.zoombox[i]);
                    gczoombox_close(g_Dialog.zoombox[i]);
                }
            }
            break;

        case DIALOG_STATE_6:
            for (i = 0; i < 2; i++) { //L8030F59C
                for (j = g_Dialog.string_index[i]; g_Dialog.dialog[i][j].cmd < -4 || g_Dialog.dialog[i][j].cmd >= 0; j++) {
                    if (g_Dialog.dialog[i][j].cmd == -7 && g_Dialog.unk140) {
                        if (g_Dialog.caller == NULL) {
                            g_Dialog.unk140(g_Dialog.caller, g_Dialog.currentTextId, *g_Dialog.dialog[i][j].str);
                        } else {
                            if (func_8030EDC0(g_Dialog.caller, g_Dialog.unk138)) {
                                g_Dialog.unk140(g_Dialog.caller, g_Dialog.currentTextId, *g_Dialog.dialog[i][j].str);
                            }
                        }
                    }
                }
            }

            g_Dialog.unk12C_25 = 0;
            for (i = 0; i < 2; i++) {
                g_Dialog.unk11A[i].unk0_7 = 0;
                if (g_Dialog.zoombox[i] != NULL) {
                    g_Dialog.unk12C_25 += (u8)func_803188B4(g_Dialog.zoombox[i]);
                }
            }
            break;

        case DIALOG_STATE_7:
            func_8030F338();
            next_state = DIALOG_STATE_0;
            break;

        case DIALOG_STATE_8:
            func_8030F338();
            for (i = 0; i < 2; i++) {
                if (g_Dialog.unk11A[i].unk0_7 == 0) {
                    gczoombox_free(g_Dialog.zoombox[i]);
                    g_Dialog.zoombox[i] = NULL;
                }
            }
            break;

        default:
            break;
    }

    g_Dialog.state = next_state;
}

void newZoomboxCallback(GcZoomboxSprite portrait_id, s32 state) {
    s32 temp_a0;
    s32 temp_v0;

    switch (state) {
        case 1: //L8030F790
            g_Dialog.unk12C_31++;
            break;
        
        case 3: //L8030F7BC
            dialog_setState(DIALOG_STATE_2);
            break;

        case 4: //L8030F7CC
            if (g_Dialog.state == DIALOG_STATE_6) {
                g_Dialog.unk12C_25--;
                if (g_Dialog.unk12C_25 == 0) {
                    temp_a0 = ((g_Dialog.unk11A[0].unk0_7) ? 1 : 0);
                    temp_v0 = ((g_Dialog.unk11A[1].unk0_7) ? 1 : 0);
                    dialog_setState((temp_v0 + temp_a0) ? DIALOG_STATE_8 : DIALOG_STATE_5);
                } //L8030F980
                break;
            }

            temp_v0 = ((g_Dialog.unk11A[0].unk0_7) ? 1 : 0) + ((g_Dialog.unk11A[1].unk0_7) ? 1 : 0);
            if (temp_v0 > (s32)g_Dialog.unk12C_29) {
                g_Dialog.unk12C_29++;
                if (g_Dialog.unk128_15 == g_Dialog.unk12C_29 + g_Dialog.unk12C_27) {
                    dialog_setState(DIALOG_STATE_8);
                }
            }
            break;

        case 6: //L8030F8FC
            g_Dialog.unk12C_27++;
            if (g_Dialog.unk12C_27 == g_Dialog.unk128_15) {
                dialog_setState(DIALOG_STATE_7);
            } //L8030F964

            if (g_Dialog.unk128_15 == g_Dialog.unk12C_29 + g_Dialog.unk12C_27) {
                dialog_setState(DIALOG_STATE_8);
            }

            break;
    } //L8030F984
}

#define CMD(i) (g_Dialog.dialog[g_Dialog.u8.active_zoombox] + i)
#define CMD2(i) (&g_Dialog.dialog[g_Dialog.u8.active_zoombox][i])

void dialog_update(void) {
    s32 i;
    s32 spA8;
    s32 controller_face_buttons[6];
    s32 controller_side_buttons[3];
    s32 ret;
    s32 sp7C;
    s32 padding[4];
    char *sp4C[8];

    ret = -1;

    if (g_Dialog.u8.unk128_31 & 0x80) {
        pfsManager_getFirstControllerFaceButtonState(0, controller_face_buttons);
        func_8024E640(0, controller_side_buttons);
    } else {
        controller_copyFaceButtons(0, controller_face_buttons);
        controller_copySideButtons(0, controller_side_buttons);
    }

    switch (g_Dialog.state) {    
        case DIALOG_STATE_1:
            for (spA8 = 0, i = 0; i < 2; i++) {
                if (g_Dialog.zoombox[i] == NULL) {
                    spA8++;
                }
            }

            if (spA8 == 2) {
                dialog_setState(DIALOG_STATE_7);
            } else if (g_Dialog.u8.unk12C_31 == g_Dialog.u8.unk128_15) {
                g_Dialog.u8.unk12C_31 = 0;
                dialog_setState(DIALOG_STATE_2);
            }
            break;
    
        case DIALOG_STATE_2:
            if (g_Dialog.zoombox[g_Dialog.u8.active_zoombox] == NULL || func_80318BEC(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]) || g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_5) {
                g_Dialog.u8.active_zoombox ^= 1;
            } else {
                g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] = CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->cmd;
                g_Dialog.string[g_Dialog.u8.active_zoombox] = CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str;
    
                switch (g_Dialog.string_cmd[g_Dialog.u8.active_zoombox]) {
                    case -2:
                        if (g_Dialog.string_index[g_Dialog.u8.active_zoombox] == 0) {
                            g_Dialog.u8.unk12C_29++;
                        }
                        gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 1;
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_5 = 1;
                        g_Dialog.u8.active_zoombox ^= 1;
                        g_Dialog.unk128_6 = TRUE;
                        break;
        
                    case -1: // Choice
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 2;
                        dialog_setState(DIALOG_WAITING_FOR_PLAYER_CHOICE);
                        break;
        
                    case -4: // Close
                        gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        gczoombox_close(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 0;
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_5 = 1;
                        g_Dialog.u8.active_zoombox ^= 1;
                        g_Dialog.unk128_6 = TRUE;
                        break;
        
                    case -7: // Trigger
                        if (g_Dialog.unk140 != NULL) {
                            if (g_Dialog.caller == NULL) {
                                g_Dialog.unk140(g_Dialog.caller, g_Dialog.currentTextId, *g_Dialog.string[g_Dialog.u8.active_zoombox]);
                            } else if (func_8030EDC0(g_Dialog.caller, g_Dialog.unk138)) {
                                g_Dialog.unk140(g_Dialog.caller, g_Dialog.currentTextId, *g_Dialog.string[g_Dialog.u8.active_zoombox]);
                            }
                        }
                        g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                        break;
        
                    case -9: // Substitute integer
                    case -8: // Conditional text
                        do {
                            g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                            g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] = CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->cmd;
                        } while (g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] == -8 || g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] == -9);
                        break;
        
                    case -6: // Conditional minimize
                        for(spA8 = g_Dialog.string_index[g_Dialog.u8.active_zoombox]; CMD2(spA8)->cmd < -4; spA8++);
        
                        if (CMD2(spA8)->cmd >= 0) {
                            gczoombox_loadSprite(g_Dialog.zoombox[g_Dialog.u8.active_zoombox], CMD2(spA8)->cmd + 0xC);
                        }

                        if (g_Dialog.string_index[g_Dialog.u8.active_zoombox]) {
                            gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        }

                        if (!g_Dialog.string_index[g_Dialog.u8.active_zoombox] && g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 == 2) {
                            gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        }

                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 0;
                        g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                        g_Dialog.u8.active_zoombox ^= 1;
                        g_Dialog.unk128_6 = TRUE;
                        break;
        
                    case -5:
                        gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 0;
                        g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                        g_Dialog.u8.active_zoombox ^= 1;
                        g_Dialog.unk128_6 = TRUE;
                        break;
        
                    case -3:
                        g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 = 0;
                        dialog_setState(DIALOG_WAITING_FOR_PLAYER_CHOICE);
                        break;
        
                    default:
                        if (!gczoombox_strlen(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str)) {
                            g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                        } else {
                            if (CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox] + 1)->cmd == -8) {
                                // Conditional text - use callback to determine if text should be shown
                                if (g_Dialog.conditionalCallback != NULL) {
                                    sp7C = 1;
        
                                    if (g_Dialog.caller == NULL) {
                                        ret = g_Dialog.conditionalCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.string_index[g_Dialog.u8.active_zoombox]);
                                    } else if (func_8030EDC0(g_Dialog.caller, g_Dialog.unk138)) {
                                        ret = g_Dialog.conditionalCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.string_index[g_Dialog.u8.active_zoombox]);
                                    }
        
                                    if (ret < 0) {
                                        ret = -1 - ret;
                                        sp7C = 0;
                                    }
        
                                    if (ret >= 0 && CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox] + ret + 1)->cmd == -8) {
                                        strlen(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox] + ret + 1)->str);
                                        strlen(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str);
        
                                        replaceText(
                                                g_Dialog.output,
                                                CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str,
                                                CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox] + ret + 1)->str,
                                                func_8031B604(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str),
                                                sp7C
                                                );
                                    } else {
                                        ret = -1;
                                    }
                                }
                            } else if (CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox] + 1)->cmd == -9) {
                                // Integer substitution - use callback to determine integer value
                                // (used for player's note count in some messages)
                                if (g_Dialog.conditionalCallback != NULL) {
                                    // static char D_80382FF8[24];
        
                                    D_80382FF8[0] = '\0';
        
                                    if (g_Dialog.caller == NULL) {
                                        ret = g_Dialog.conditionalCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.string_index[g_Dialog.u8.active_zoombox]);
                                    } else if (func_8030EDC0(g_Dialog.caller, g_Dialog.unk138)) {
                                        ret = g_Dialog.conditionalCallback(g_Dialog.caller, g_Dialog.currentTextId, g_Dialog.string_index[g_Dialog.u8.active_zoombox]);
                                    }
        
                                    strIToA(D_80382FF8, ret);
                                    strlen(D_80382FF8);
                                    strlen(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str);
        
                                    replaceText(
                                            g_Dialog.output,
                                            CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str,
                                            D_80382FF8,
                                            func_8031B604(CMD(g_Dialog.string_index[g_Dialog.u8.active_zoombox])->str),
                                            0
                                            );
                                }
                            }
        
                            if (gczoombox_loadSprite(g_Dialog.zoombox[g_Dialog.u8.active_zoombox], g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] + 12)) {
                                gczoombox_minimize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                                g_Dialog.unk128_6 = TRUE;
                            }
        
                            if (g_Dialog.unk128_6) {
                                gczoombox_maximize(g_Dialog.zoombox[g_Dialog.u8.active_zoombox]);
                                g_Dialog.unk128_6 = FALSE;
                            }
        
                            if (ret == -1) {
                                for (spA8 = g_Dialog.string_index[g_Dialog.u8.active_zoombox]; CMD(spA8)->cmd == g_Dialog.string_cmd[g_Dialog.u8.active_zoombox] && spA8 - g_Dialog.string_index[g_Dialog.u8.active_zoombox] < 8; spA8++) {
                                    sp4C[spA8 - g_Dialog.string_index[g_Dialog.u8.active_zoombox]] = CMD(spA8)->str;
                                }
        
                                gczoombox_setStrings(g_Dialog.zoombox[g_Dialog.u8.active_zoombox], spA8 - g_Dialog.string_index[g_Dialog.u8.active_zoombox], sp4C);
                                g_Dialog.string_index[g_Dialog.u8.active_zoombox] = spA8;
                            } else {
                                func_803183A4(g_Dialog.zoombox[g_Dialog.u8.active_zoombox], g_Dialog.output);
                                g_Dialog.string_index[g_Dialog.u8.active_zoombox]++;
                            }
        
                            dialog_setState(DIALOG_STATE_3);
                        }

                        break;
                }
            }
            break;

        case DIALOG_STATE_3:
            if ((g_Dialog.u8.unk128_31 & 1) && controller_face_buttons[FACE_BUTTON(BUTTON_B)] == 1u) {
                dialog_setState(DIALOG_STATE_6);
                break;
            }
    
            if (g_Dialog.u8.unk128_31 & 0x80) {
                break;
            }
    
            if (NOT((g_Dialog.u8.unk128_31 & 0x80) ? func_8024E5E8(0, 4) : func_8024E5E8(0, 3))) {
                break;
            }
    
            dialog_setState(DIALOG_STATE_6);
            break;

        case DIALOG_WAITING_FOR_PLAYER_CHOICE:
            if (controller_face_buttons[FACE_BUTTON(BUTTON_A)] == 1) {
                g_Dialog.u8.playerHasConfirmed = 1;
            } else if (controller_face_buttons[FACE_BUTTON(BUTTON_B)] == 1) {
                g_Dialog.u8.playerHasConfirmed = 0;
            }

            if (g_Dialog.u8.playerHasConfirmed != -1) {
                dialog_setState(g_Dialog.unk11A[g_Dialog.u8.active_zoombox].unk0_7 ? DIALOG_STATE_8 : DIALOG_STATE_5);
            }
            break;

        case DIALOG_STATE_7:
        case DIALOG_STATE_8:
            dialog_setState(DIALOG_STATE_0);
            break;
    }

    for (i = 0; i < 2; i++) {
        gczoombox_update(g_Dialog.zoombox[i]);
    }
}

void loadDialogStrings(s32 text_id) {
    s32 i, j;
    u8 *txt;
    s32 _v0;
    char ch;
    s32 len;

    txt = g_Dialog.dialog_bin_ptr = dialogBin_get(text_id);
    
    for (i = 0; i < 2; i++) {
        g_Dialog.string_count[i] = *(txt++);
        g_Dialog.dialog[i] = (BKDialog *) malloc(g_Dialog.string_count[i] * sizeof(BKDialog));
        for (j = 0; j < g_Dialog.string_count[i]; j++) {
            // Step 1: Get the cmd / chat head from the dialog asset
            ch = *(txt++);
            // Low cmds correspond to specific commands for a dialog box instead of a chat head 
            if (ch > 0 && ch < 0x20) {
                // Swap it to negative: See DIALOG_STATE_2 above
                _v0 = -ch;
            } else {
                _v0 = (ch >= 0x80)? ch - 0x80 : ch;
            }
            
            g_Dialog.dialog[i][j].cmd = _v0;

            // Step 2: Get the speaking text
            len = *(txt);
            txt++;
            g_Dialog.dialog[i][j].str = txt;
            txt += len; 
        }
    }
}

s32 getYPositionForZoombox(s32 dialogPosition) {
    return (dialogPosition) ? 0 // Top Dialog
        : 0xA0; // Bottom Dialog
}

bool isDialogTop(s32 dialogIterator) {
    return dialogIterator ? TRUE : FALSE;
}

void loadAndCreateDialogs(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5) {
    s32 i, j;

    s32 temp_a2;

    loadDialogStrings(text_id);
    g_Dialog.unk12C_29 = 0;
    g_Dialog.unk12C_31 = (g_Dialog.unk12C_25 = g_Dialog.unk12C_29);
    g_Dialog.unk12C_27 = g_Dialog.unk12C_31;
    g_Dialog.unk128_15 = g_Dialog.unk12C_27;

    for (i = 0; i < 2; i++) { //L80310774
        j = 0;
        temp_a2 = g_Dialog.dialog[i][0].cmd;
        while (g_Dialog.dialog[i][j].cmd < -4 && j < g_Dialog.string_count[i]) {
            j++; 
        };

        g_Dialog.string_cmd[i] = temp_a2;
        //L803107C4
        g_Dialog.string[i] = g_Dialog.dialog[i]->str;
        g_Dialog.string_index[i] = 0;
        g_Dialog.zoomboxYPosition[i] = getYPositionForZoombox(i);
        g_Dialog.unk11A[i].unk0_5 = 0;

        if (g_Dialog.dialog[i][j].cmd >= 0) {
            if (!g_Dialog.unk11A[i].unk0_7) {
                g_Dialog.zoombox[i] =  gczoombox_new(g_Dialog.zoomboxYPosition[i], g_Dialog.dialog[i][j].cmd + 0xC, 0, isDialogTop(i), (void *)newZoomboxCallback);
                if (i == DIALOG_TOP) {
                    func_80347A14(0);
                }
            } else { //L80310860
                 g_Dialog.unk12C_31++; 
            } //L80310880
            g_Dialog.unk128_15++;
        } else { //L80310890
            if (g_Dialog.dialog[i][j].cmd < -2) {
                if (g_Dialog.unk11A[i].unk0_7) {
                    gczoombox_close(g_Dialog.zoombox[i]);
                    g_Dialog.unk128_15++;
                } else {
                    g_Dialog.zoombox[i] = NULL;
                }
                g_Dialog.unk11A[i].unk0_7 = 0;
            } else { //L803108D8
                if (g_Dialog.unk11A[i].unk0_7) {
                    g_Dialog.unk128_15++;
                    g_Dialog.unk12C_31++;
                }
            }
        } //L80310910
    }
    g_Dialog.currentTextId = text_id;
    g_Dialog.unk128_31 = arg1;
    if (g_Dialog.string_cmd[DIALOG_BOTTOM] < 0) {
        g_Dialog.active_zoombox = DIALOG_BOTTOM;
    } else { //L80310950
        g_Dialog.active_zoombox = DIALOG_TOP;
    } //L8031095C
    g_Dialog.unk128_6 = 1;
    g_Dialog.playerHasConfirmed = ((func_802E4A08() || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) && g_Dialog.unk128_3) ? 1 : -1;
    g_Dialog.caller = marker;
    g_Dialog.currentCallback = callback;
    g_Dialog.unk140 = arg4;
    g_Dialog.conditionalCallback = (void *)arg5;
    g_Dialog.unk138 = (marker != NULL) ? ((marker->unk5C)? marker->unk5C : -1) : 0;
    dialog_setState(((func_802E4A08() || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) && g_Dialog.unk128_3) ? 6 : 1);
    //L803109EC
}

void func_80310A5C(s32 next_state, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    f32 box_background_animation_duration = 0.4f;

    for (i = 0; i < 2; i++) {
        if (g_Dialog.zoombox[i]) {
            gczoombox_func_803184C8(g_Dialog.zoombox[i], arg2, next_state, arg1, box_background_animation_duration, arg3, arg4);
        }
    }
}

void func_80310B1C(s32 text_id, s32 arg1, ActorMarker *marker, void(*callback)(ActorMarker *, s32, s32), void(*arg4)(ActorMarker *, s32, s32), s32 arg5) {
    loadAndCreateDialogs(text_id, arg1, marker, callback, arg4, arg5);

    // Is the player at the final boss and is the text not an entering quote?
    if (map_get() == MAP_90_GL_BATTLEMENTS && ASSET_10EC_DIALOG_FINALBOSS_ENTERING_6 < text_id) {
        func_80310A5C(3, 4, 0x1e, arg1 & 2, arg1 & 0x80);
		return;
    }

    func_80310A5C(5, 2, 0xF, arg1 & 2, arg1 & 0x80);
}

void func_80310BB4(s32 next_state, s32 arg1, s32 arg2) {
    func_80310A5C(arg1, arg2, next_state, g_Dialog.unk128_31 & 2, g_Dialog.unk128_31 & 0x80);
}

void updateDialogYPositions(void) {
    s32 y_position_change;

    if (g_Dialog.zoomboxYPositionIndexDecremented) {
        g_Dialog.yPositionModifierIndex++;
        y_position_change = Y_POSITION_MODIFIERS[g_Dialog.yPositionModifierIndex];
        if (g_Dialog.zoombox[DIALOG_BOTTOM] != NULL) {
            g_Dialog.zoomboxYPosition[DIALOG_BOTTOM] -= y_position_change;
            func_80318B7C(g_Dialog.zoombox[DIALOG_BOTTOM], g_Dialog.zoomboxYPosition[DIALOG_BOTTOM]);
        }
        
        if (g_Dialog.zoombox[DIALOG_TOP] != NULL) {
            g_Dialog.zoomboxYPosition[DIALOG_TOP] += y_position_change;
            func_80318B7C(g_Dialog.zoombox[DIALOG_TOP], g_Dialog.zoomboxYPosition[DIALOG_TOP]);
        }

        if (g_Dialog.yPositionModifierIndex == 12) {
            g_Dialog.queueZoomboxYPositionModify = FALSE;
        }
    } else {
        g_Dialog.yPositionModifierIndex--;
        y_position_change = Y_POSITION_MODIFIERS[g_Dialog.yPositionModifierIndex];
        if (g_Dialog.zoombox[DIALOG_BOTTOM] != NULL) {
            g_Dialog.zoomboxYPosition[DIALOG_BOTTOM] += y_position_change;
            func_80318B7C(g_Dialog.zoombox[DIALOG_BOTTOM], g_Dialog.zoomboxYPosition[DIALOG_BOTTOM]);
        }

        if (g_Dialog.zoombox[DIALOG_TOP] != NULL) {
            g_Dialog.zoomboxYPosition[DIALOG_TOP] -= y_position_change;
            func_80318B7C(g_Dialog.zoombox[DIALOG_TOP], g_Dialog.zoomboxYPosition[DIALOG_TOP]);
        }

        if (g_Dialog.yPositionModifierIndex == 0) {
            g_Dialog.queueZoomboxYPositionModify = FALSE;
        }
    }
}

void func_80310D2C(void) {
    struct14s *sp24;
    
    if (g_Dialog.queueZoomboxYPositionModify) {
        updateDialogYPositions();
    }

    if (getGameMode() == GAME_MODE_3_NORMAL || func_802E4A08()) {
        if (g_Dialog.queueZoomboxYPositionModify) {
            return;
        }

        if (!gcdialog_hasCurrentTextId() && (s32)(g_Dialog.unk12C_15) > 0) {
            
            sp24 = g_Dialog.unk148 + g_Dialog.unk12C_11;
            func_80310B1C(sp24->unk0,sp24->unk2, sp24->unk10, sp24->unk18, sp24->unk1C, sp24->unk20);
            
            g_Dialog.unk138 = sp24->unk14;
            func_8025A55C(8000, 300, 2);
            if ((sp24->unk2 & 0x8) && !((func_802E4A08() || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) && g_Dialog.unk128_3)) { //L80310E6C
                func_8028F918(0);
                if (0.0f == sp24->unk4_x
                    && 0.0f == sp24->unk4_y
                    && 0.0f == sp24->unk4_z
                ) {
                    func_8028F918((g_Dialog.string_cmd[1] < 0)? 1 : 3);
                } else { //L80310F00
                    func_8028F94C((g_Dialog.string_cmd[1] < 0)? 1 : 3, sp24->unk4);
                }
            } //L80310F28
            
            g_Dialog.unk12C_11++;
            if (!((s32) g_Dialog.unk12C_11 < 4)) {
                g_Dialog.unk12C_11 = g_Dialog.unk12C_11 - 4;
            }

            g_Dialog.unk12C_15--;
        } else { //L80310F88
            dialog_update();
        } //L80310F98

        if ((g_Dialog.state != DIALOG_STATE_0 && g_Dialog.state != DIALOG_STATE_5 && g_Dialog.state != DIALOG_STATE_7)
            || ((!g_Dialog.state && (g_Dialog.unk11A[0].unk0_7  || g_Dialog.unk11A[1].unk0_7)))
            || g_Dialog.unk12C_15
        ) { //L80310FF0
            if (func_802FADD4(0)) {
                if (item_getCount(ITEM_6_HOURGLASS) != 0) {
                    func_802FACA4(0x28);
                } else {
                    func_802FAD64(ITEM_0_HOURGLASS_TIMER);
                }
            } else {
                if (func_802FADD4(3)) {
                    if (item_getCount(ITEM_3_PROPELLOR_TIMER) != 0) {
                        func_802FACA4(0x28);
                    } else {
                        func_802FAD64(ITEM_3_PROPELLOR_TIMER);
                    }
                }
            }
            //L80311068
            
            if (func_802FBE04()) {
                func_802FACA4(0x2A);
            }

            if (func_802FC390()) {
                func_802FACA4(0x29);
            }
        } else { //L803110A0
            if (func_802FAD9C(0x28)) {
                func_802FAD64(0x28);
            }
            
            if (func_802FAD9C(0x2A)) {
                func_802FAD64(0x2A);
            }
            
            if (func_802FAD9C(0x29)) {
                func_802FAD64(0x29);
            }
        }
    }
}

int func_803110F8(s32 next_state, s32 arg1, s32 arg2, s32 arg3, void (*arg4)(ActorMarker *, enum asset_e, s32)) {
    func_8025A55C(15000, 300, 2);
    gcdialog_showDialogConditional(next_state + 0xe57, 0x84, NULL, NULL, NULL, NULL, arg4);
    func_80310A5C(arg2, arg3, arg1, 0, 0);
    return 1;
}

int gcdialog_showDialogConditional(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, enum asset_e, s32), void(*arg5)(ActorMarker *, enum asset_e, s32), s32 arg6) {
    f32 pad;
    s32 temp_v1;

    if (volatileFlag_get(VOLATILE_FLAG_1) || func_802D686C()) {
        return 0;
    }

    if (!gcdialog_hasCurrentTextId()) {
        func_80310B1C(text_id, arg1, marker, (void *)callback, (void *)arg5, arg6);
        if (arg1 & 8) {
            if (!(func_802E4A08() || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) || !g_Dialog.unk128_3) { //L80311214
                if (pos != NULL) {
                    func_8028F94C(((g_Dialog.string_cmd[1] < 0)? 1 : 3), pos);
                } else { //L8031126C
                    func_8028F918(((g_Dialog.string_cmd[1] < 0)? 1 : 3));
                }
            }
        } //L8031128C
        func_8025A55C(0x1f40, 0x12c, 2);
        return 1;
    } else { //L803112A0
        if (arg1 & 0x20) { 
            if (!(g_Dialog.unk128_31 & 0x80)) {
                func_803114D0();
            } else {
                g_Dialog.unk12C_15 = 0;
                g_Dialog.unk12C_11 = 0;
            }
        } //L803112E8
        if (arg1 & 0x04 || arg1 & 0x20) {
            //L80311300
            temp_v1 = g_Dialog.unk12C_11 + g_Dialog.unk12C_15;
            temp_v1 = (temp_v1 < 4)?temp_v1 : temp_v1 - 4;
            //L80311328
            g_Dialog.unk148[temp_v1].unk0 = text_id;
            g_Dialog.unk148[temp_v1].unk2 = arg1;
            if (pos) {
                g_Dialog.unk148[temp_v1].unk4[0] = pos[0];
                g_Dialog.unk148[temp_v1].unk4[1] = pos[1];
                g_Dialog.unk148[temp_v1].unk4[2] = pos[2];
            } else {
                g_Dialog.unk148[temp_v1].unk4[2] = 0.0f;
                g_Dialog.unk148[temp_v1].unk4[1] = 0.0f;
                g_Dialog.unk148[temp_v1].unk4[0] = 0.0f;
            }
            g_Dialog.unk148[temp_v1].unk10 = marker;
            g_Dialog.unk148[temp_v1].unk14 = (marker != NULL) ? ((marker->unk5C) ? marker->unk5C : -1) : 0;
            g_Dialog.unk148[temp_v1].unk18 = (void *)callback;
            g_Dialog.unk148[temp_v1].unk1C = (void *)arg5;
            g_Dialog.unk148[temp_v1].unk20 = arg6;
            g_Dialog.unk12C_15++;
            if (arg1 & 0x08) {
                if (!(func_802E4A08() || volatileFlag_get(VOLATILE_FLAG_1F_IN_CHARACTER_PARADE)) || !g_Dialog.unk128_3) { //L8031141C
                    if (!func_8028EC04()) {
                        if (pos != NULL) {
                            func_8028F94C(2, pos);
                        } else { //L80311444
                            func_8028F918(2);
                        }
                    } else { //L80311454
                        func_8028F918(func_8028EC04());
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

bool gcdialog_showDialog(s32 text_id, s32 arg1, f32 *pos, ActorMarker *marker, void(*callback)(ActorMarker *, enum asset_e, s32), void(*arg5)(ActorMarker *, enum asset_e, s32)) {
    return gcdialog_showDialogConditional(text_id, arg1, pos, marker, callback, arg5, 0);
}

int gcdialog_hasCurrentTextId(void) {
    // Empty text ids are set to -1
    return (g_Dialog.currentTextId + 1) != 0;
}

int gcdialog_getCurrentTextId(void) {
    return g_Dialog.currentTextId;
}

void func_803114D0(void) {
    s32 i;

    if (gcdialog_hasCurrentTextId()) {
        dialog_setState(DIALOG_STATE_6);
    } else {
        if (g_Dialog.state != DIALOG_STATE_6) {
            g_Dialog.unk12C_25 = 0;
            for (i = 0; i < 2; i++) {
                g_Dialog.unk11A[i].unk0_7 = 0;
                if (g_Dialog.zoombox[i]) {
                    g_Dialog.unk12C_25 += (u8)func_803188B4(g_Dialog.zoombox[i]);
                }
            }
            if (g_Dialog.unk12C_25 != 0) {
                g_Dialog.state = DIALOG_STATE_6;
            }
        }
    } //L80311594

    g_Dialog.unk12C_15 = 0;
    g_Dialog.unk12C_11 = 0;
}


bool func_803115C4(s32 textId) {
    if (gcdialog_getCurrentTextId() != textId) {
        return FALSE;
    }

    dialog_setState(DIALOG_STATE_6);

    return TRUE;
}

void gcdialog_incrementYPositionModifier(void) {
    if (!gcdialog_hasCurrentTextId()) {
        return;
    }

    g_Dialog.queueZoomboxYPositionModify = TRUE;
    g_Dialog.zoomboxYPositionIndexDecremented = FALSE;
    g_Dialog.yPositionModifierIndex++;
}

void gcdialog_decrementYPositionModifier(void) {
    if (!gcdialog_hasCurrentTextId()) {
        return;
    }

    g_Dialog.queueZoomboxYPositionModify = TRUE;
    g_Dialog.zoomboxYPositionIndexDecremented = TRUE;
    g_Dialog.yPositionModifierIndex--;
}

void gcdialog_defrag(void) {
    s32 i;
    
    for (i = 0; i < 2; i++) {
        gczoombox_defrag(g_Dialog.zoombox[i]);
        if (g_Dialog.dialog[i]) {
            g_Dialog.dialog[i] = (BKDialog *)defrag(g_Dialog.dialog[i]);
        }

        if (g_Dialog.zoombox[i] != NULL) {
            g_Dialog.zoombox[i] = (GcZoombox *)defrag(g_Dialog.zoombox[i]);
        }
    }
}

void func_80311714(int next_state){
    g_Dialog.unk128_3 = next_state;
}
