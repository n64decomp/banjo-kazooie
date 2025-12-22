#include "PRinternal/macros.h"
#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PRinternal/controller.h"
#include "PRinternal/siint.h"

static void __osPackEepWriteData(u8 address, u8 *buffer);
s32 osEepromWrite(OSMesgQueue* mq, u8 address, u8* buffer) {
    s32 ret = 0;
#if BUILD_VERSION < VERSION_J
    int i;
#endif
    u16 type;
    u8* ptr = (u8*)&__osEepPifRam.ramarray;
    __OSContEepromFormat eepromformat;
    OSContStatus sdata;
#if BUILD_VERSION >= VERSION_L
    u8 temp[8];
#endif

    __osSiGetAccess();
    ret = __osEepStatus(mq, &sdata);
#if BUILD_VERSION < VERSION_J
    ret = __osEepStatus(mq, &sdata); // Duplicate that was removed in 2.0J
#endif

    type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

#if BUILD_VERSION >= VERSION_J
    if (ret == 0) {
        switch (type) {
            case CONT_EEPROM:
                if (address >= EEPROM_MAXBLOCKS) {
                    ret = CONT_RANGE_ERROR;
                }
                break;
            case CONT_EEPROM | CONT_EEP16K:
                if (address >= EEP16K_MAXBLOCKS) {
                    // not technically possible
                    ret = CONT_RANGE_ERROR;
                }
#if BUILD_VERSION >= VERSION_L
                else if (__osEepromRead16K) {
                    __osEepromRead16K = 0;
                    __osSiRelAccess();
                    osEepromRead(mq, (address ^ 1), temp);
                    __osSiGetAccess();
                }
#endif
                break;
            default:
                ret = CONT_NO_RESPONSE_ERROR;
        }
    }

    if (ret != 0) {
        __osSiRelAccess();
        return ret;
    }
#else
    if (ret != 0) {
        __osSiRelAccess();
        return CONT_NO_RESPONSE_ERROR;
    } else {
        switch (type) {
            case CONT_EEPROM:
                if (address > EEPROM_MAXBLOCKS) {
                    __osSiRelAccess();
                    return -1;
                }

                break;
            case CONT_EEPROM | CONT_EEP16K:
                if (address > EEP16K_MAXBLOCKS) {
                    // not technically possible
                    __osSiRelAccess();
                    return -1;
                }
                break;
            default:
                __osSiRelAccess();
                return CONT_NO_RESPONSE_ERROR;
        }
    }
#endif

    while (sdata.status & CONT_EEPROM_BUSY) {
        __osEepStatus(mq, &sdata);
    }

    __osPackEepWriteData(address, buffer);
    ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam); //send command to pif
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
#ifdef BKDIFFS
    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) {
        __osEepPifRam.ramarray[i] = 0xFF;
    }
    __osEepPifRam.pifstatus = 0;
#endif
    ret = __osSiRawStartDma(OS_READ, &__osEepPifRam); //recv response
    __osContLastCmd = CONT_CMD_WRITE_EEPROM;
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    // skip the first 4 bytes
#if BUILD_VERSION >= VERSION_J
    ptr += 4;
#else
    for (i = 0; i < 4; i++) {
        ptr++;
    }
#endif

    eepromformat = *(__OSContEepromFormat *)ptr;

    ret = CHNL_ERR(eepromformat);

    __osSiRelAccess();
    return ret;
}

static void __osPackEepWriteData(u8 address, u8* buffer) {
    u8* ptr = (u8*)&__osEepPifRam.ramarray;
    __OSContEepromFormat eepromformat;
    int i;

#if BUILD_VERSION < VERSION_J
#ifdef BKDIFFS
	for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) {
#else
    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray); i++) {
#endif
        __osEepPifRam.ramarray[i] = CONT_CMD_NOP;
    }
#endif
    __osEepPifRam.pifstatus = CONT_CMD_EXE;

    eepromformat.txsize = CONT_CMD_WRITE_EEPROM_TX;
    eepromformat.rxsize = CONT_CMD_WRITE_EEPROM_RX;
    eepromformat.cmd = CONT_CMD_WRITE_EEPROM;
    eepromformat.address = address;

    for (i = 0; i < ARRLEN(eepromformat.data); i++) {
        eepromformat.data[i] = *buffer++;
    }

    for (i = 0; i < MAXCONTROLLERS; i++) {
        *ptr++ = 0;
    }

    *(__OSContEepromFormat *)(ptr) = eepromformat;
    ptr += sizeof(__OSContEepromFormat);
    ptr[0] = CONT_CMD_END;
}

s32 __osEepStatus(OSMesgQueue* mq, OSContStatus* data) {
    s32 ret = 0;
    int i;
    u8* ptr = (u8*)__osEepPifRam.ramarray;
    __OSContRequesFormat requestformat;

#ifdef BKDIFFS
	for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) {
#else
    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray); i++) {
#endif
        __osEepPifRam.ramarray[i] = 0;
    }

    __osEepPifRam.pifstatus = CONT_CMD_EXE;
    ptr = (u8 *)__osEepPifRam.ramarray;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        *ptr++ = CONT_CMD_REQUEST_STATUS;
    }

    requestformat.dummy = CONT_CMD_NOP;
    requestformat.txsize = CONT_CMD_REQUEST_STATUS_TX;
    requestformat.rxsize = CONT_CMD_REQUEST_STATUS_RX;
    requestformat.cmd = CONT_CMD_REQUEST_STATUS;
    requestformat.typeh = CONT_CMD_NOP;
    requestformat.typel = CONT_CMD_NOP;
    requestformat.status = CONT_CMD_NOP;
    requestformat.dummy1 = CONT_CMD_NOP;
    *(__OSContRequesFormat *)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormat);
    *ptr = CONT_CMD_END;

    ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
#if BUILD_VERSION >= VERSION_J
    __osContLastCmd = CONT_CMD_END;
#else
    __osContLastCmd = CONT_CMD_REQUEST_STATUS;
#endif
    ret = __osSiRawStartDma(OS_READ, &__osEepPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    if (ret != 0) {
        return ret;
    }

    ptr = (u8 *)&__osEepPifRam;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        *ptr++ = 0;
    }

    requestformat = *(__OSContRequesFormat *)ptr;
    data->errno = CHNL_ERR(requestformat);
    data->type = (requestformat.typel << 8) | requestformat.typeh;
    data->status = requestformat.status;

    if (data->errno != 0) {
        return data->errno;
    }

    return 0;
}
