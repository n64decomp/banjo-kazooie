#include <rcp.h>
#include "controller.h"
#include "siint.h"

static void __osPackEepReadData(u8 address);
extern OSPifRam __osEepPifRam; // todo bss
s32 osEepromRead(OSMesgQueue *mq, u8 address, u8 *buffer)
{
	s32 ret;
	int i;
	u16 type;
	u8 *ptr;
	OSContStatus sdata;
	__OSContEepromFormat eepromformat;
	ret = 0;
	i = 0;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	__osSiGetAccess();
	ret = __osEepStatus(mq, &sdata);
	type = sdata.type & (CONT_EEPROM | CONT_EEP16K);

	if (ret != 0)
	{
		__osSiRelAccess();
		return CONT_NO_RESPONSE_ERROR;
	}
	switch (type)
	{
	case CONT_EEPROM:
		if (address > EEPROM_MAXBLOCKS)
		{
			__osSiRelAccess();
			return -1;
		}

		break;
	case CONT_EEPROM | CONT_EEP16K:
		if (address > EEP16K_MAXBLOCKS) //not technically possible
		{
			__osSiRelAccess();
			return -1;
		}
		break;
	default:
		__osSiRelAccess();
		return CONT_NO_RESPONSE_ERROR;
		break;
	}
	while (sdata.status & CONT_EEPROM_BUSY)
	{
		__osEepStatus(mq, &sdata);
	}
	__osPackEepReadData(address);
	ret = __osSiRawStartDma(OS_WRITE, &__osEepPifRam); //send command to pif
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++) {
        __osEepPifRam.ramarray[i] = 0xFF;
    }
    __osEepPifRam.pifstatus = 0;
	ret = __osSiRawStartDma(OS_READ, &__osEepPifRam); //recv response
	__osContLastCmd = CONT_CMD_READ_EEPROM;
	osRecvMesg(mq, NULL, OS_MESG_BLOCK);
	for (i = 0; i < 4; i++) //skip the first 4 bytes
	{
		ptr++;
	}
	eepromformat = *(__OSContEepromFormat *)ptr;

	ret = CHNL_ERR(eepromformat);

	if (ret == 0)
		for (i = 0; i < ARRLEN(eepromformat.data); i++)
			*buffer++ = eepromformat.data[i];

	__osSiRelAccess();
	return ret;
}

static void __osPackEepReadData(u8 address)
{
	u8 *ptr;
	__OSContEepromFormat eepromformat;
	int i;
	ptr = (u8 *)&__osEepPifRam.ramarray;
	for (i = 0; i < ARRLEN(__osEepPifRam.ramarray) + 1; i++)
	{
		__osEepPifRam.ramarray[i] = CONT_CMD_NOP;
	}
	__osEepPifRam.pifstatus = CONT_CMD_EXE;

	eepromformat.txsize = CONT_CMD_READ_EEPROM_TX;
	eepromformat.rxsize = CONT_CMD_READ_EEPROM_RX;
	eepromformat.cmd = CONT_CMD_READ_EEPROM;
	eepromformat.address = address;
	for (i = 0; i < ARRLEN(eepromformat.data); i++)
	{
		eepromformat.data[i] = 0;
	}
	for (i = 0; i < 4; i++) //skip the first 4 bytes
	{
		*ptr++ = 0;
	}
	*(__OSContEepromFormat *)(ptr) = eepromformat;
	ptr += sizeof(__OSContEepromFormat);
	ptr[0] = CONT_CMD_END;
}
