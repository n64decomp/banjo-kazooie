#include "PR/os_internal.h"
#include "PR/rcp.h"
#include "PR/rdb.h"

// not included in final rom, but __osThreadSave is here for some reason
OSThread __osThreadSave;

extern OSThread *__osRunningThread;
extern u32 __osRdb_IP6_Empty;

#ifndef _FINALROM

static u8 buffer[12];
static u32 numChars = 0;

static u32 string_to_u32(u8* s) {
    u32 k;

    k = ((s[0] & 0xFF) << 0x18);
    k |= ((s[1] & 0xFF) << 0x10);
    k |= ((s[2] & 0xFF) << 0x8);
    k |= (s[3] & 0xFF);

    return k;
}

static void send_packet(u8* s, u32 n) {
    rdbPacket packet;
    u32 i;

    packet.type = 0xC;
    packet.length = n;

    for (i = 0; i < n; i++) {
        packet.buf[i] = s[i];
    }
    *(vu32*)RDB_BASE_REG = *(u32*)&packet;
}

static void clear_IP6(void) {
    while (!(__osGetCause() & CAUSE_IP6)) {
        ;
    }
    *(vu32*)RDB_READ_INTR_REG = 0;

    while (__osGetCause() & CAUSE_IP6) {
        ;
    }
}

static void send(u8* s, u32 n) {
    u32 ct;
    u32 i = 0;
    u32 getLastIP6;

    if (!__osRdb_IP6_Empty) {
        clear_IP6();
        getLastIP6 = FALSE;
    } else {
        getLastIP6 = TRUE;
    }
    while (n != 0) {
        ct = (n < 3) ? n : 3;
        send_packet(s + i, ct);
        n -= ct;
        i += ct;
        if (n != 0) {
            clear_IP6();
        }
    }
    if (getLastIP6) {
        clear_IP6();
    }
}

void kdebugserver(rdbPacket packet) {
    u32 i;
    u32 length;
    u8* addr;

    for (i = 0; i < 3; i++) {
        buffer[numChars++] = packet.buf[i];
    }

    if (buffer[0] == 2) {
        send((char*)&__osRunningThread->context, sizeof(__OSThreadContext));
        numChars = 0;
    } else if (numChars >= 9 && buffer[0] == 1) {
        addr = string_to_u32(&buffer[1]);
        length = string_to_u32(&buffer[5]);
        send(addr, length);
        numChars = 0;
    }
}

#endif
