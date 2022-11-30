#include <ultra64.h>
#include "functions.h"
#include "variables.h"
#include "SnS.h"
#include "save.h"

bool snsToRestoreItems = FALSE;
struct SnsPayload *snsBasePayloadPtr1 = NULL;
struct SnsPayload *snsBasePayloadPtr2 = NULL;
struct SnsPayload *snsBasePayloadPtr3 = NULL;
struct SnsPayload *snsBasePayloadPtr4 = NULL;

/* .bss */
StopNSwop_Data snsParsedKeys;
struct GlobalSave gSaveData;
s32 snsMinKeyToParse;
s32 snsMaxKeyToParse;
s32 snsParsedCurrPos;
u32  snsBackedUpItems;

void sns_init_parsing_params(s32 min, s32 max)
{
    snsMinKeyToParse = min;
    snsMaxKeyToParse = max;
    snsParsedCurrPos = 0;
}

u32 sns_get_next_key_in_range(void)
{
    while (snsParsedCurrPos < SNS_PAYLOAD_DATALEN)
    {
        if (snsParsedKeys[snsParsedCurrPos] >= snsMinKeyToParse
         && snsParsedKeys[snsParsedCurrPos] <= snsMaxKeyToParse)
            return snsParsedKeys[snsParsedCurrPos++];

        snsParsedCurrPos++;
    }

    return 0;
}

void sns_update_global_save_data_checksum(void)
{
    s32 i;

    /**
     * Updates the save data checksum multiple times (?)
     * 
     * Running this multiple times seems to achieve nothing.
     * A debug leftover?
     */
    for (i = 5; i != 0 && func_8033CD0C(&gSaveData); i--)
        ;
}

void sns_save_and_update_global_data(void)
{
    s32 i;

    /**
     * Triggers a save of the global save data to EEPROM,
     * and validates the checksum.
     */

    if (func_8033CA9C(&gSaveData))
    {
        /**
         * Failed, hide the evidence.
         * 
         * Clears the entire global data area.
         */

        gSaveData.sns.uEggYellow = FALSE;
        gSaveData.sns.uEggRed    = FALSE;
        gSaveData.sns.uEggGreen  = FALSE;
        gSaveData.sns.uEggBlue   = FALSE;
        gSaveData.sns.uEggPink   = FALSE;
        gSaveData.sns.uEggCyan   = FALSE;
        gSaveData.sns.uIceKey    = FALSE;

        gSaveData.sns.cEggYellow = FALSE;
        gSaveData.sns.cEggRed    = FALSE;
        gSaveData.sns.cEggGreen  = FALSE;
        gSaveData.sns.cEggBlue   = FALSE;
        gSaveData.sns.cEggPink   = FALSE;
        gSaveData.sns.cEggCyan   = FALSE;
        gSaveData.sns.cIceKey    = FALSE;

        gSaveData.snsw = gSaveData.snsw << SNS_NUM_FLAGS >> SNS_NUM_FLAGS ^ gSaveData.snsw;

        for (i = 0; i < sizeof(gSaveData.UNUSED); i++)
            gSaveData.UNUSED[i] = 0;

        sns_update_global_save_data_checksum();
    }

    sns_unlock_parsed_items();
    sns_update_global_save_data_checksum();
}

/**
 * Scans N64 RDRAM for a valid payload, and if found,
 * parses it for the key values and saves them internally.
 */
void sns_find_and_parse_payload(void)
{
    struct SnsPayload *payload;
    s32 i;

    for (i = 0; i < SNS_PAYLOAD_DATALEN; i++)
        snsParsedKeys[i] = 0;

    payload = snspayload_find_payload_in_ram();

    if (payload)
    {
        snspayload_rewind_incoming();

        i = 0;
        while (i < SNS_PAYLOAD_DATALEN)
        {
            u32 val = snspayload_get_next_key(payload);

            snsParsedKeys[i] = val;

            if (val)
                i++;
            else
                i = SNS_PAYLOAD_DATALEN;
        }
    }
}

void sns_init_base_payloads(void)
{
    snsBasePayloadPtr3 = snspayload_init_new_payload((struct SnsPayload *)0x803FFF00);
    snsBasePayloadPtr4 = snspayload_init_new_payload((struct SnsPayload *)0x803A5C00);
    snsBasePayloadPtr1 = snspayload_init_new_payload((struct SnsPayload *)func_8025484C(0x100));
    snsBasePayloadPtr2 = snspayload_init_new_payload((struct SnsPayload *)func_80254898(0x100));
}

bool sns_get_or_set_key(bool state, struct SnsPayload *payload, s32 key, s32 mode)
{
    if (mode == SNS_MODE_WRITE)
    {
        if (state)
            snspayload_append_key_to_outgoing_payload(payload, key);

        return state;
    }

    if (mode == SNS_MODE_READ)
    {
        /**
         * A VERY roundabout way of simply searching through the
         * parsed values to see if the given key is present.
         * 
         * It feels like a leftover remnant from code written
         * hastily during testing of SnS.
         */

        sns_init_parsing_params(key, key);

        return sns_get_next_key_in_range() ? TRUE : state;
    }

    return FALSE;
}

void sns_commit_collected_flags(s32 mode, struct SnsPayload *payload)
{
    gSaveData.sns.cEggYellow = sns_get_or_set_key(gSaveData.sns.cEggYellow, payload, SNS_ITEM_COLLECTED_EggYellow, mode);
    gSaveData.sns.cEggRed    = sns_get_or_set_key(gSaveData.sns.cEggRed,    payload, SNS_ITEM_COLLECTED_EggRed,    mode);
    gSaveData.sns.cEggGreen  = sns_get_or_set_key(gSaveData.sns.cEggGreen,  payload, SNS_ITEM_COLLECTED_EggGreen,  mode);
    gSaveData.sns.cEggBlue   = sns_get_or_set_key(gSaveData.sns.cEggBlue,   payload, SNS_ITEM_COLLECTED_EggBlue,   mode);
    gSaveData.sns.cEggPink   = sns_get_or_set_key(gSaveData.sns.cEggPink,   payload, SNS_ITEM_COLLECTED_EggPink,   mode);
    gSaveData.sns.cEggCyan   = sns_get_or_set_key(gSaveData.sns.cEggCyan,   payload, SNS_ITEM_COLLECTED_EggCyan,   mode);
    gSaveData.sns.cIceKey    = sns_get_or_set_key(gSaveData.sns.cIceKey,    payload, SNS_ITEM_COLLECTED_IceKey,    mode);
}

void sns_commit_unlocked_flags(s32 mode, struct SnsPayload *payload)
{
    gSaveData.sns.uEggYellow = sns_get_or_set_key(gSaveData.sns.uEggYellow, payload, SNS_ITEM_UNLOCKED_EggYellow, mode);
    gSaveData.sns.uEggRed    = sns_get_or_set_key(gSaveData.sns.uEggRed,    payload, SNS_ITEM_UNLOCKED_EggRed,    mode);
    gSaveData.sns.uEggGreen  = sns_get_or_set_key(gSaveData.sns.uEggGreen,  payload, SNS_ITEM_UNLOCKED_EggGreen,  mode);
    gSaveData.sns.uEggBlue   = sns_get_or_set_key(gSaveData.sns.uEggBlue,   payload, SNS_ITEM_UNLOCKED_EggBlue,   mode);
    gSaveData.sns.uEggPink   = sns_get_or_set_key(gSaveData.sns.uEggPink,   payload, SNS_ITEM_UNLOCKED_EggPink,   mode);
    gSaveData.sns.uEggCyan   = sns_get_or_set_key(gSaveData.sns.uEggCyan,   payload, SNS_ITEM_UNLOCKED_EggCyan,   mode);
    gSaveData.sns.uIceKey    = sns_get_or_set_key(gSaveData.sns.uIceKey,    payload, SNS_ITEM_UNLOCKED_IceKey,    mode);
}

void sns_unlock_parsed_items(void)
{
    sns_commit_unlocked_flags(SNS_MODE_READ, NULL);
}

void sns_generate_payload(struct SnsPayload *payload)
{
    snspayload_rewind_outgoing();
    snspayload_append_key_to_outgoing_payload(payload, 1);
    sns_commit_collected_flags(SNS_MODE_WRITE, payload);
    snspayload_finalise_outgoing_payload(payload);
}

/**
 * Writes payload to RAM for another Rareware game
 * to read and parse after swapping cartridges.
 */
void sns_write_payload_over_heap(void)
{
    s32 val2;
    u32 i;

    if (func_8023DB5C() <= 0x3B || snsToRestoreItems)
        return;

    sns_generate_payload(snsBasePayloadPtr2);

    // memcpy
    func_80254630(snsBasePayloadPtr3, snsBasePayloadPtr2, sizeof(*snsBasePayloadPtr2));
    func_80254630(snsBasePayloadPtr4, snsBasePayloadPtr2, sizeof(*snsBasePayloadPtr2));

    for (i = 1; i < 5; i++)
    {
        u32 val1 = func_80254BD0(&val2, i);

        if (val1 && val2 > 0x4000)
        {
            s32 val3 = val1 - 0x400 + val2;

            val1 -= val1 & 0x1FFF;

            for (val1 += 0x2C00; val1 < val3; val1 += 0x2000)
                // memcpy
                func_80254630((void *)val1, snsBasePayloadPtr2, sizeof(*snsBasePayloadPtr2));
        }
    }
}

void sns_stub(void) {}

/**
 * Dev flag: to boot straight to a specific map.
 * 
 * This value is unused in the retail builds, but may have
 * been used in debug builds.
 * 
 * If TRUE, on boot, the game will start in the furnace fun
 * portal room (used for testing furnace fun?)
 * 
 * If FALSE, on boot, the game will start on the file select
 * screen (skips all the logo cutscenes)
 */
bool DEBUG_use_special_bootmap(void)
{
    return FALSE;
}

/**
 * Dev flag: purpose unknown?
 */
bool func_8025B818(void)
{
    return TRUE;
}

bool sns_get_item_state(enum StopNSwop_Item item, s32 set)
{
    switch (item)
    {
        case SNS_ITEM_EGG_YELLOW: return set == SNS_COLLECTED ? gSaveData.sns.cEggYellow : gSaveData.sns.uEggYellow;
        case SNS_ITEM_EGG_RED:    return set == SNS_COLLECTED ? gSaveData.sns.cEggRed    : gSaveData.sns.uEggRed;
        case SNS_ITEM_EGG_GREEN:  return set == SNS_COLLECTED ? gSaveData.sns.cEggGreen  : gSaveData.sns.uEggGreen;
        case SNS_ITEM_EGG_BLUE:   return set == SNS_COLLECTED ? gSaveData.sns.cEggBlue   : gSaveData.sns.uEggBlue;
        case SNS_ITEM_EGG_PINK:   return set == SNS_COLLECTED ? gSaveData.sns.cEggPink   : gSaveData.sns.uEggPink;
        case SNS_ITEM_EGG_CYAN:   return set == SNS_COLLECTED ? gSaveData.sns.cEggCyan   : gSaveData.sns.uEggCyan;
        case SNS_ITEM_ICE_KEY:    return set == SNS_COLLECTED ? gSaveData.sns.cIceKey    : gSaveData.sns.uIceKey;
        default:
            return FALSE;
    }
}

void sns_set_item_state(enum StopNSwop_Item item, s32 set, s32 state)
{
    if (set == SNS_COLLECTED)
    {
        switch (item)
        {
            case SNS_ITEM_EGG_YELLOW: gSaveData.sns.cEggYellow = state; return;
            case SNS_ITEM_EGG_RED:    gSaveData.sns.cEggRed    = state; return;
            case SNS_ITEM_EGG_GREEN:  gSaveData.sns.cEggGreen  = state; return;
            case SNS_ITEM_EGG_BLUE:   gSaveData.sns.cEggBlue   = state; return;
            case SNS_ITEM_EGG_PINK:   gSaveData.sns.cEggPink   = state; return;
            case SNS_ITEM_EGG_CYAN:   gSaveData.sns.cEggCyan   = state; return;
            // debug string?
            case SNS_ITEM_ICE_KEY:    gSaveData.sns.cIceKey    = state; if (0); return;
            default:
                return;
        }
    }
    else // SNS_UNLOCKED
    {
        switch (item)
        {
            case SNS_ITEM_EGG_YELLOW: gSaveData.sns.uEggYellow = state; return;
            case SNS_ITEM_EGG_RED:    gSaveData.sns.uEggRed    = state; return;
            case SNS_ITEM_EGG_GREEN:  gSaveData.sns.uEggGreen  = state; return;
            case SNS_ITEM_EGG_BLUE:   gSaveData.sns.uEggBlue   = state; return;
            case SNS_ITEM_EGG_PINK:   gSaveData.sns.uEggPink   = state; return;
            case SNS_ITEM_EGG_CYAN:   gSaveData.sns.uEggCyan   = state; return;
            case SNS_ITEM_ICE_KEY:    gSaveData.sns.uIceKey    = state; return;
            default:
                return;
        }
    }
}

void sns_set_item_and_update_payload(enum StopNSwop_Item item, s32 set, s32 state)
{
    sns_set_item_state(item, set, state);
    sns_update_global_save_data_checksum();
    sns_write_payload_over_heap();
}

/**
 * Used for the cutscene at the end of the game where Mumbo shows
 * you Stop 'n' Swop hints.
 * 
 * Backs up your item flags, then forces them all to be unlocked
 * and not collected, so they can be seen during the hint sequences.
 */
void sns_backup_items_and_unlock_all(void)
{
    u32 i;

    if (snsToRestoreItems)
        return;

    sns_write_payload_over_heap();

    snsToRestoreItems = TRUE;

    // statements on same line for match (why?)
    snsBackedUpItems = 0; for (i = 1; i < SNS_ITEM_length; i++)
    {
        snsBackedUpItems = (sns_get_item_state(i, SNS_UNLOCKED)  ? 1 : 0) + (snsBackedUpItems << 1);
        snsBackedUpItems = (sns_get_item_state(i, SNS_COLLECTED) ? 1 : 0) + (snsBackedUpItems << 1);
        sns_set_item_state(i, SNS_UNLOCKED,  TRUE);
        sns_set_item_state(i, SNS_COLLECTED, FALSE);
    }
}

/**
 * Used when ending the cutscene where Mumbo shows you Stop 'n'
 * Swop hints.
 * 
 * It restores whatever item flags you had before it was triggered.
 */
void sns_restore_backed_up_items(void)
{
    u32 i;

    if (!snsToRestoreItems)
        return;

    for (i = SNS_ITEM_length - 1; i > 0; i--)
    {
        sns_set_item_state(i, SNS_COLLECTED, snsBackedUpItems & 1);
        snsBackedUpItems >>= 1;
        sns_set_item_state(i, SNS_UNLOCKED,  snsBackedUpItems & 1);
        snsBackedUpItems >>= 1;
    }

    snsToRestoreItems = FALSE;
}

