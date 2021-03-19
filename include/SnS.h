#ifndef __SNS_H__
#define __SNS_H__
#include <ultra64.h>

typedef struct SnS_Payload_s{
    u32 catch;
    u32 packet[0x1D];
    u32 checksum[2];
}SnSPayload;

void SnSPayload_rewind(void);

#endif
