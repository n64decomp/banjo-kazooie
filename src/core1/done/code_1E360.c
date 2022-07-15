#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"

/**
 * An index used to track the position in the incoming payload
 * we should read the next key from.
 */
extern s32 snsPayloadInCurrPos;

/**
 * An index used to track the position in the outgoing payload
 * it should write the next key to.
 */
extern s32 snsPayloadOutCurrPos;


struct SnsPayload *snspayload_init_new_payload(struct SnsPayload *payload)
{
    u32 i;

    payload->magic = SNS_HEADER_MAGIC;

    for (i = 0; i < SNS_PAYLOAD_DATALEN; i++)
        payload->data[i] = 0;

    payload->pad = 0;

    snspayload_calc_checksum(payload);

    return payload;
}

void snspayload_set_key_at_idx(struct SnsPayload *payload, s32 idx, s32 key)
{
    payload->data[idx] = key;
    snspayload_calc_checksum(payload);
}

void snspayload_calc_checksum(struct SnsPayload *payload)
{
    glcrc_calc_checksum(payload, &payload->checksum, payload->checksum);
}

bool snspayload_validate(struct SnsPayload *payload)
{
    u32 checksum[2];

    glcrc_calc_checksum(payload, payload->checksum, checksum);

    if ((payload->checksum[0] == checksum[0]) && (payload->checksum[1] == checksum[1]))
        return TRUE;

    return FALSE;
}

struct SnsPayload *snspayload_find_payload_in_ram(void)
{
    struct SnsPayload *payload;

    for (payload = (struct SnsPayload *)0x80000000; payload < (struct SnsPayload *)0x80400080; payload++)
        if (payload->magic == SNS_HEADER_MAGIC && snspayload_validate(payload))
            return payload;

    return NULL;
}

s32 snspayload_contains_key(struct SnsPayload *payload, s32 key)
{
    u32 i;

    for (i = 0; i < SNS_PAYLOAD_DATALEN; i++)
        if (payload->data[i] == key)
            return key;

    return 0;
}

s32 snspayload_get_key_in_range(struct SnsPayload *payload, s32 min, s32 max)
{
    s32 i;

    for (i = 0; i < SNS_PAYLOAD_DATALEN; i++)
    {
        if (payload->data[i] < min)
            continue;

        if (payload->data[i] > max)
            continue;

        return payload->data[i];
    }

    return 0;
}

void snspayload_rewind_incoming(void)
{
    snsPayloadInCurrPos = 0;
}

u32 snspayload_get_next_key(struct SnsPayload *payload)
{
    while (snsPayloadInCurrPos < SNS_PAYLOAD_DATALEN)
    {
        if (payload->data[snsPayloadInCurrPos])
            return payload->data[snsPayloadInCurrPos++];

        snsPayloadInCurrPos++;
    }

    return 0;
}

void snspayload_rewind_outgoing(void)
{
    snsPayloadOutCurrPos = 0;
}

void snspayload_append_key_to_outgoing_payload(struct SnsPayload *payload, s32 key)
{
    payload->data[snsPayloadOutCurrPos++] = key;
}

void snspayload_finalise_outgoing_payload(struct SnsPayload *payload)
{
    while (snsPayloadOutCurrPos < SNS_PAYLOAD_DATALEN)
        payload->data[snsPayloadOutCurrPos++] = 0;

    snspayload_calc_checksum(payload);
}

