#ifndef __SNS_H__
#define __SNS_H__
#include <ultra64.h>

/**
 * sns sets
 */
// Flag set used when collecting an already-unlocked Stop 'n' Swop item in-game
#define SNS_COLLECTED (0)
// Flag set used when making a Stop 'n' Swop item visible and collectable in-game
#define SNS_UNLOCKED  (1)

/**
 * sns mode (read FROM other game, or write TO other game)
 */
#define SNS_MODE_READ  (0)
#define SNS_MODE_WRITE (1)

/**
 * sns item keys
 */
#define SNS_ITEM_COLLECTED_EggYellow (0x100)
#define SNS_ITEM_COLLECTED_EggRed    (0x101)
#define SNS_ITEM_COLLECTED_EggGreen  (0x102)
#define SNS_ITEM_COLLECTED_EggBlue   (0x103)
#define SNS_ITEM_COLLECTED_EggPink   (0x104)
#define SNS_ITEM_COLLECTED_EggCyan   (0x105)
#define SNS_ITEM_COLLECTED_IceKey    (0x106)
/* 0x107 unknown */
#define SNS_ITEM_UNLOCKED_EggYellow  (0x108)
#define SNS_ITEM_UNLOCKED_EggRed     (0x109)
#define SNS_ITEM_UNLOCKED_EggGreen   (0x10A)
#define SNS_ITEM_UNLOCKED_EggBlue    (0x10B)
#define SNS_ITEM_UNLOCKED_EggPink    (0x10C)
#define SNS_ITEM_UNLOCKED_EggCyan    (0x10D)
#define SNS_ITEM_UNLOCKED_IceKey     (0x10E)

#define SNS_NUM_FLAGS (14)

#define SNS_PAYLOAD_DATALEN (0x1C)
#define SNS_HEADER_MAGIC    (('2B1K' << 2 | 3)) /* 0xC908C52F */

typedef int bool;

enum StopNSwop_Item {
    SNS_ITEM_NULL,

    SNS_ITEM_EGG_YELLOW,
    SNS_ITEM_EGG_RED,
    SNS_ITEM_EGG_GREEN,
    SNS_ITEM_EGG_BLUE,
    SNS_ITEM_EGG_PINK,
    SNS_ITEM_EGG_CYAN,
    SNS_ITEM_ICE_KEY,

    SNS_ITEM_length
};

struct StopNSwop_Bitfield {
    /* Flags to record that the item is UNLOCKED and can be collected */
    u32 uEggYellow  : 1;
    u32 uEggRed     : 1;
    u32 uEggGreen   : 1;
    u32 uEggBlue    : 1;
    u32 uEggPink    : 1;
    u32 uEggCyan    : 1;
    u32 uIceKey     : 1;

    /* Flags to record that the item was COLLECTED */
    u32 cEggYellow : 1;
    u32 cEggRed    : 1;
    u32 cEggGreen  : 1;
    u32 cEggBlue   : 1;
    u32 cEggPink   : 1;
    u32 cEggCyan   : 1;
    u32 cIceKey    : 1;

    u32 : 18;
};

typedef u32 StopNSwop_Data[SNS_PAYLOAD_DATALEN];

struct SnsPayload {
    u32            magic;
    StopNSwop_Data data;
    u32            pad;
    u32            checksum[2];
};

struct GlobalSave {
    union {
        struct StopNSwop_Bitfield sns;
        u32                       snsw;
    };
    u8  UNUSED[0x18];
    u32 crc;
};

/**
 * Global save data area.
 * 
 * It's saved to the cartridge in a special area at
 * the end of the EEPROM which is shared by all
 * three in-game save slots.
 * 
 * Only the first two bytes are ever used in the
 * game, and it's for saving the Stop 'n' Swop items.
 */
extern struct GlobalSave gSaveData;

/**
 * An array of keys that were read in from a payload
 * at boot.
 */
extern StopNSwop_Data snsParsedKeys;

extern s32 snsMinKeyToParse;
extern s32 snsMaxKeyToParse;
extern s32 snsParsedCurrPos;

extern bool snsToRestoreItems;
extern u32  snsBackedUpItems;

// the 4 base areas that outgoing payloads are written to
extern struct SnsPayload *snsBasePayloadPtr1;
extern struct SnsPayload *snsBasePayloadPtr2;
extern struct SnsPayload *snsBasePayloadPtr3;
extern struct SnsPayload *snsBasePayloadPtr4;

struct SnsPayload *snspayload_find_payload_in_ram      (void);
struct SnsPayload *snspayload_init_new_payload         (struct SnsPayload *payload);

void sns_unlock_parsed_items                           (void);
void sns_stub                                          (void);

void snspayload_append_key_to_outgoing_payload         (struct SnsPayload *payload, s32 key);
void snspayload_calc_checksum                          (struct SnsPayload *payload);

#endif
