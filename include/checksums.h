#ifndef BANJO_KAZOOIE_CHECKSUMS_H
#define BANJO_KAZOOIE_CHECKSUMS_H

#include <ultra64.h>

/* The checksums for the boot and core1 segments are stored right after the boot segment in ROM
 */

#define CRC_BOOT_TEXT_CHECKSUM1     0
#define CRC_BOOT_TEXT_CHECKSUM2     4
#define CRC_CORE1_TEXT_CHECKSUM1    8
#define CRC_CORE1_TEXT_CHECKSUM2    12
#define CRC_CORE1_DATA_CHECKSUM1    16
#define CRC_CORE1_DATA_CHECKSUM2    20

extern u8 crc_ROM_START[];

/* Each overlay bss section contains four checksum values, calculated from the rarezip decompressor.
 * These values are written by the overlay loader. They are checked with pre-calculated values for
 * different anti-tampering measurements.
 * The exception is the core1 overlay, which checksums are written to a special place.
 */
struct overlay_checksums_s {
    s32 text_checksum1;
    s32 text_checksum2;
    s32 data_checksum1;
    s32 data_checksum2;
};

extern struct overlay_checksums_s gChecksumsCore1;
extern struct overlay_checksums_s gChecksumsCore2;
extern struct overlay_checksums_s gChecksumsCC; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsGV; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsMMM; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsTTC;
extern struct overlay_checksums_s gChecksumsMM; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsBGS; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsRBB; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsFP; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsSM;
extern struct overlay_checksums_s gChecksumsCutscenes; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsLair; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsFight; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsCCW; // (unused) no anti tampering measurements
extern struct overlay_checksums_s gChecksumsEmptyLvl; // (unused) no anti tampering measurements

/* The pre-calculated checksums are located in random places.
 *
 * The calculation process should be as following (needs to be confirmed!!):
 * 1. At compile time all checksum variables (listed below) are set to zero
 * 2. The text checksums for all overlays (except core1) are calculated and written.
 * 3. The data checksums are calculated in two passes:
 *    3-1. Data checksum 1 is calculated and written for each overlay (except core1).
 *    3-2. Data checksum 2 is calculated and written for each overlay (except core1).
 * 4. The boot and core1 checksums are calculated and written to the CRC section.
 * 
 * Notes:
 * - Checksums 1 sums up every byte
 * - Checksum 2 XORes every byte after it is shifted right by "current checksum 1 AND 0x17"
 *   (This means checksum 2 must be calculated together with checksum 1)
 *   (Step 3-1 discards checksum 2 and step 3-2 discards checksum 1)
 * - Checksums without a correspondending variable are just discarded.
 */

extern s32 D_803727F4; // core2 text checksum 2 (location: core2)
extern s32 D_80276574; // core2 data checksum 2 (location: core1)

extern s32 D_80389BE0; // CC text checksum 1 (location: CC)
extern s32 D_80389BE4; // CC text checksum 2 (location: CC)
extern s32 D_80389BE8; // CC data checksum 1 (location: CC)
extern s32 D_80276570; // CC data checksum 2 (location: core1)

extern s32 D_80390F30; // GV text checksum 1 (location: GV)
extern s32 D_80390F34; // GV text checksum 2 (location: GV)
extern s32 D_80390F38; // GV data checksum 1 (location: GV)
extern s32 D_80275904; // GV data checksum 2 (location: core1)

extern s32 D_8038C300; // MMM text checksum 1 (location: MMM)
extern s32 D_8038C304; // MMM text checksum 2 (location: MMM)
extern s32 D_8038C308; // MMM data checksum 1 (location: MMM)
extern s32 D_80275854; // MMM data checksum 2 (location: core1)

extern s32 D_8038C750; // TTC text checksum 1 (location: TTC)
extern s32 D_8038C754; // TTC text checksum 2 (location: TTC)
extern s32 D_8038C758; // TTC data checksum 1 (location: TTC)
extern s32 D_80276CB0; // TTC data checksum 2 (location: core1)

extern s32 D_803899C0; // MM text checksum 1 (location: MM)
extern s32 D_803899C4; // MM text checksum 2 (location: MM)
extern s32 D_803899C8; // MM data checksum 1 (location: MM)
extern s32 D_80275654; // MM data checksum 2 (location: core1)

extern s32 D_80390B20; // BGS text checksum 1 (location: BGS)
extern s32 D_80390B24; // BGS text checksum 2 (location: BGS)
extern s32 D_80390B28; // BGS data checksum 1 (location: BGS)
extern s32 D_802758F0; // BGS data checksum 2 (location: core1)

extern s32 D_80276CB4; // RBB data checksum 2 (location: core1)

extern s32 D_802758F4; // FP data checksum 2 (location: core1)

extern s32 D_8038AAE0; // SM text checksum 1 (location: SM)
extern s32 D_8038AAE4; // SM text checksum 2 (location: SM)
extern s32 D_8038AAE8; // SM data checksum 1 (location: SM)
extern s32 D_80275650; // SM data checksum 2 (location: core1)

extern s32 D_80275850; // Cutscenes data checksum 2 (location: core1)

extern s32 D_80275900; // Lair data checksum 2 (location: core1)

extern s32 D_80275D34; // Fight data checksum 2 (location: core1)

extern s32 D_80275D30; // CCW data checksum 2 (location: core1)

#endif
