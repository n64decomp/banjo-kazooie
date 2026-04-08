#include <ultra64.h>
#include "boot/rarezip.h"

struct huft_s *D_80007270; // rarezip_huft
extern struct huft_s gGlobalHuffTable;

static u32 rarezip_uncompress_file_internal(u8 *in, u8 *out, struct huft_s *huft);
static u32 rarezip_uncompress_file_and_update_pointers_internal(u8 **in, u8 **out, struct huft_s *huft);

/// @brief Returns the uncompressed file size from the file header
/// @param file Pointer to the compressed file
/// @return Uncompressed file size in bytes
u32 rarezip_get_uncompressed_size(u8 *file) {
    return *((u32 *) (file + 2));
}

/// @brief Initializes the Rarezip Huff table
void rarezip_init(void) {
    D_80007270 = &gGlobalHuffTable;
}

/// @brief Uncompresses a Rarezip file in memory (public function)
/// @param in Pointer to the compressed file
/// @param out Pointer to the output buffer for the decompressed file
/// @return Uncompressed file size in bytes
u32 rarezip_uncompress_file(u8 *in, u8 *out) {
    return rarezip_uncompress_file_internal(in, out, D_80007270);
}

/// @brief Uncompresses a Rarezip file in memory and updates file and buffer pointers (public function)
/// @param in Pointer to the compressed file
/// @param out Pointer to the output buffer for the decompressed file
void rarezip_uncompress_file_and_update_pointers(u8 **in, u8 **out) {
    rarezip_uncompress_file_and_update_pointers_internal(in, out, D_80007270);
}

/// @brief Possible debug function
void rarezip_debug(void) {}

/// @brief Uncompresses a Rarezip file in memory (internal function)
/// @param in Pointer to the compressed file
/// @param out Pointer to the output buffer for the decompressed file
/// @param huft Pointer to the Huff table
/// @return Uncompressed file size in bytes
static u32 rarezip_uncompress_file_internal(u8 *in, u8 *out, struct huft_s *huft) {
    inflate_inbuf = in;
    inflate_slide = out;
    inflate_huft = huft;
    inflate_inbuf += 6; //skip 6 byte bk header 
    inflate_wp = 0;
    inflate_inptr = 0;
    
    inflate();

    return inflate_wp;
}

/// @brief Uncompresses a Rarezip file in memory and updates file and buffer pointers (public function)
/// @param in Pointer to the compressed file
/// @param out Pointer to the output buffer for the decompressed file
/// @param huft Pointer to the Huff table
/// @return Uncompressed file size in bytes
static u32 rarezip_uncompress_file_and_update_pointers_internal(u8 **in, u8 **out, struct huft_s *huft) {
    u32 size = rarezip_uncompress_file_internal(*in, *out, huft);
    *out += inflate_wp;
    *out = ((u32)(*out) & 0xF) ? (u8 *) ((u32)(*out) & ~0xF) + 0x10 : *out;
    *in += inflate_inptr + 6;
    return size;
}
